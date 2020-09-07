(in-context {general})
(in-namespace "events" :include "common")

(setq *defer-unknown-connections* t)

(new-type {geographical space} {place})

(new-type {boundary} {thing}) ;it might be a "space" better than a thing?

;; Enclosed space is the general concept describing whatever the
;; type of rooms, enclosed by a doorway, a ceiling, a floor, and
;; four walls
(new-type {enclosed space} {space})
(new-type {closed-space} {enclosed space})
(new-type {open-space} {enclosed space})
(new-type-role {ceiling} {enclosed space} {boundary})
(new-type-role {floor} {enclosed space} {boundary})
(new-type-role {wall} {enclosed space} {boundary} :n 4)
(new-type {wayThrough} {boundary})
(new-type-role {doorway} {enclosed space} {wayThrough})
(new-type-role {windowway} {enclosed space} {wayThrough})


;; Doorways normally count on doors, in order to lock or
;; close the room, or just to bound the limits of the room.
(new-type {movable object} {thing})
(new-type-role {door} {enclosed space} {movable object})
(new-type-role {window} {enclosed space} {movable object})
(new-is-a {window} {windowway})
(new-is-a {door} {doorway})
(new-type {unlock element} {thing})

(new-type {builiding} {enclosed space})
(new-type-role {room} {builiding} {enclosed space})
(new-type-role {corridor} {builiding} {enclosed space})
(new-type {open-room} {room})
(new-type {closed-room} {room})

;; We are modeling the following relationships for the domain
;; of a building.
;; THe {is in} relation is used to describe that an object is
;; located inside a room
(new-relation {is in}
	      :a-inst-of {thing}
	      :b-inst-of {enclosed space}
	      :transitive t)

;; We also identify that a movable object, more likely a door
;; is used in order to close a room, so we model the {close} relation
(new-relation {opens}
	      :a-inst-of {movable object}
	      :b-inst-of {enclosed space}
	      :inverse '(:relation "closes"))
(new-relation {closes}
	      :a-inst-of {movable object}
	      :b-inst-of {enclosed space}
	      :inverse '(:relation "opens"))

(new-relation {connects}
	      :a-inst-of {wayThrough}
	      :b-inst-of {enclosed space}
	      :c-inst-of {enclosed space}
	      :symmetric t
	      :transitive t)

(new-relation {is connected to}
	      :a-inst-of {place}
	      :b-inst-of {place}
	      :symmetric t
	      :transitive t)
(new-relation {unlocks}
	      :a-inst-of {unlock element}
	      :b-inst-of {door})
(new-relation {crosses across} 
	      :a-inst-of {person}
	      :b-inst-of {wayThrough}
	      :transitive t)

;; For compatibility with the MLP
(new-is-a {room} {place})
(new-is-a {place} {shape})
