;;;*******************************************************
;;;** --------------------------------------------------**
;;;**        SOME ACTIONS FOR TESTING THE PLANNER       **
;;;** This actions are required by the MLP knowledge    **
;;;** --------------------------------------------------**
;;;*******************************************************


(in-context {general})
(in-namespace "events" :include "common")
;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)

;; RELATIONS APPLIED TO ACTIONS
(new-relation {is located at}
	      :a-inst-of {thing}
	      :b-inst-of {location})

(new-relation {has position}
	      :a-inst-of {thing}
	      :b-inst-of {position})
(new-relation {is reported to}
	       :a-inst-of {thing}
	       :b-inst-of {thing})



(new-indv-role {personLocation} {person} {place})
(new-indv-role {objectLocation} {thing} {place})

(new-event-type {locate} '({action} {identification} {recognition})
		:roles
		((:type {locatedObject} {thing}))
  :before
  ((new-not-statement {locatedObject} {is located at} {location}))
  :after
  ((new-statement {locatedObject} {is located at} {location})))

(new-event-type {report} '({event})
		:roles
		((:type {reportedObject} {thing})
		 (:type {reportedChannel} {thing}))
;  :throughout
;  ((the-x-of-y-is-z {agent} {report} {reporter}))		
  :before
  ((new-not-statement {reportedObject} {is reported to} {reportedChannel}))
  :after
  ((new-statement {reportedObject} {is reported to} {reportedChannel})))

(new-event-type {watch} '({event})
		:roles
		((:type {watchedObject} {thing})))

(new-event-type {supervise} '({event})
		:roles
		((:type {supervisedObject} {thing})
		(:type {anomaly} {thing}))
  :before
  ((new-not-statement {anomaly} {is noticed in} {supervisedObject}))
  :after
  ((new-statement {anomaly} {is noticed in} {supervisedObject})))

;; take up by hand, therefore, this action implies a person
;(new-event-type {take up} '({event})
;			 :roles
;			 ((:indv {pickedObject} {thing})
;			  (:indv {picker} {person})
;			  (:indv {takeUpOrigin} {place})
;			  (:indv {takeUpEnd} {place})
;			  )
;  :throughout  	
;  ((new-indv-role {pickedObjectLocation} {pickedObject} {place})
;   (new-indv-role {pickerLocation} {picker} {place})
;   (new-is-a {pickerLocation} {personLocation})
;   (new-is-a {pickedObjectLocation} {objectLocation}))		
;			 :before
;			 ((new-statement {pickedObject} {is located at} {pickedObjectLocation})
;			  (new-statement {picker} {is located at} {pickerLocation})
;			  (the-x-of-y-is-z {takeUpOrigin} {take up} {pickedObjectLocation}))
;			 :after
;			 ((new-statement {pickedObject} {is located at} {takeUpEnd})
;			  (the-x-of-y-is-z {pickedObjectLocation} {pickedObject} {takeUpEnd})
 ; 			  (the-x-of-y-is-z {takeUpEnd} {take up} {pickerLocation})
;   			  (new-eq {pickedObjectLocation} {takeUpEnd})))



;(new-event-type {take up} '({event})
;	:roles
;	((:indv {pickedObject} {thing})
;	(:indv {pickedObjectLocation} {place})
;	(:indv {pickerLocation} {place})
;	(:indv {picker} {person}))
;  :throughout
;  ((the-x-of-y-is-z {agent} {take up} {picker})
;   (the-x-of-y-is-z {personLocation} {picker} {pickerLocation})
;   (the-x-of-y-is-z {pickerLocation} {picker} {personLocation}))			
;  :before
;  ((the-x-of-y-is-z {location} {pickedObject} {pickedObjectLocation})
;   (the-x-of-y-is-z {location} {picker} {pickerLocation}))
;  :after
;  ((the-x-of-y-is-z {location} {pickedObject} {pickerLocation})
;   (the-x-of-y-is-z {location} {picker} {pickerLocation})))
	
