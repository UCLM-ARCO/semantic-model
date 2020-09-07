;;;*****************************************************************************
;;;** ------------------------------------------------------------------------**
;;;**               DESCRIPTION AND DEFINITION OF SOME ACTIONS                **
;;;** This file define and describe some of the actions that might take place **
;;;** in the context of a building. These actions are suppossed to support    **
;;;** the planning task.                                                      **
;;;** REQUIRES: moves.lisp (csahin/events/kb)
;;;** ------------------------------------------------------------------------**
;;;*****************************************************************************


(in-context {general})
(in-namespace "events" :include "common")
;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)
;; For our purposes of planning, it is convinient to know which is
;; the action that counteract a given action. This is modeled by
;; means of the "opposite-action-of" relation.
(new-relation {is-opposite-action-of}
	      :a-inst-of {event}
	      :b-inst-of {event}
	      :symmetric t) 


(new-type {identity} {thing})

(new-relation {contains}
	      :a-inst-of {thing}
	      :b-inst-of {thing})
(new-relation {belongs-to}
	      :a-inst-of {thing}
	      :b-inst-of {thing})

(new-indv-role {person identity} {person}
	       {identity})
(new-type {unknown person} {person identity}) ;unknown when the person is not identified
(new-type {known person} {person identity}) ;known also includes an unidentified person
(new-type {identified person} {known person})
(new-type {unidentified person} {known person})

;; To move (a door, for example) so that an opening or passage is
;; covered or obstructed; shut. The "shut space" can be a room or a
;; box, for instance.
(new-event-type {close} '({event})
		:roles
		((:type {closing element} {movable object})
		 (:type {space to close} {enclosed space}))
  :throughout  
  ((new-is-not-a {space to close} {closed-space}))
  :before
  ((new-is-a {space to close} {open-space}))
  :after
  ((new-is-not-a {space to close} {open-space})
   (new-is-a {space to close} {closed-space})))

(new-event-type {close door} '({action} {close} {move an object})
		:roles
		((:type {accessible space} {enclosed space}))
  :throughout 
  ((the-x-of-y-is-a-z {closing element} {close door} {door})
   (the-x-of-y-is-a-z {moving object} {close door} {door}))
  :before
  ((new-statement {door} {connects} {space to close} :c {accessible space}))
  :after
  ((new-not-statement {door} {connects} {space to close} :c {accessible space})))
  
;; Affording unobstructed entrance and exit; not shut or closed.
(new-event-type {open} '({event})
		:roles
		((:type {opening element} {movable object})
		 (:type {unlocker} {unlock element}) ;a key, ID,etc.
		 (:type {shut space} {enclosed space}))
  :throughout 
  ((new-is-a {shut space} {closed-space}))
  :before
  ((new-is-a {shut space} {closed-space}))
  :after
  ((new-is-a {shut space} {open-space})
   (new-is-not-a {shut space} {closed-space})))


(new-event-type {open door} '({action} {open} {move an object})
		:roles
		((:type {unaccessible space} {enclosed space}))
  :throughout 
  ((the-x-of-y-is-a-z {opening element} {open door} {door})
   (the-x-of-y-is-a-z {moving object} {open door}  {door}))
  :before
  ((new-not-statement {door} {connects} {shut space} :c {unaccessible space})
   (new-statement {unlocker} {unlocks} {door}))
  :after
  ((new-statement {door} {connects} {shut space} :c {unaccessible space})))

(new-statement {open} {is-opposite-action-of} {close})
(new-statement {open door} {is-opposite-action-of} {close door})

  
;; To come or go into (a particular place)
(new-event-type {enter} '({event})
		:roles
		((:type {entering space} {enclosed space})
		 (:type {coming from} {enclosed space})
		 (:type {entering way} {doorway})
		 (:indv {accessor} {animate}))
		
 :throughout 
  ((new-is-a {entering space} {open-space})
   (new-statement {entering way} {connects} {coming from} :c {entering space}))
 :before
 ((new-not-statement {accessor} {is in} {entering space}))
 :after
 ((new-statement {accessor} {is in} {entering space})))

;; To go out of or away from
(new-event-type {leave} '({event})
		:roles
		((:type {leaving space} {enclosed space})
		 (:type {going to} {enclosed space})
		 (:type {leaving way} {doorway})
		 (:indv {leaver} {animate}))
 :throughout 
  ((new-is-a {leaving space} {open-space})
   (new-statement {leaving way} {connects} {going to} :c {leaving space}))
 :before
 ((new-statement {leaver} {is in} {leaving space}))
 :after
 ((new-not-statement {leaver} {is in} {leaving space})))

(new-statement {enter} {is-opposite-action-of} {leave})

;;  
(new-type {device status} {property})
(new-indv {on} {device status})
(new-indv {off} {device status})

(new-relation {is}
	      :a-inst-of {device}
	      :b-inst-of {device status}) 

(new-type {media-content} {thing}) ;it should be partially tangible?
(new-type {audio} {media-content})
(new-type {image} {media-content})
(new-type {picture} {media-content})
(new-is-a {picture} {image})

(new-relation {is-recorded-by}
	      :a-inst-of {media-content}
	      :b-inst-of {recorder device})
(new-relation {takes-place-during}
	      :a-inst-of {event}
	      :b-inst-of {time interval})
(new-relation {happens-at}
	      :a-inst-of {event}
	      :b-inst-of {time point})

;;  To register (sound or images) in permanent form by mechanical or electrical means for reproduction.
(new-event-type {record} '({event})
		:roles
		((:type {recorded content} {media-content})
		 (:type {recorder device} {device})
		 (:indv {recording time} {time interval}))
  :throughout
  ((new-statement {recorder device} {is} {on})
   (new-statement {record} {takes-place-during} {recording time}))
  :before
  ((new-not-statement {recorded content} {is-recorded-by} {recorder device}))
  :after
  ((new-statement {recorded content} {is-recorded-by} {recorder device})))

;; To succeed in representing (something elusive) in words, pictures, or music
(new-event-type {capture} '({event} {action})
		:roles
		((:type {capture time} {time point})
		 (:type {captured content} {media content}))
  :throughout
  ((new-statement {recorder device} {is} {on})
   (new-statement {capture} {happens-at} {capture time})
   (x-is-the-y-of-z {recorder device} {agent} {capture}))
  :before
  ((new-not-statement {captured content} {is-recorded-by} {recorder device}))
  :after
  ((new-statement {captured content} {is-recorded-by} {recorder device})))

