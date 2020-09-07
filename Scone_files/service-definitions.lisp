;;;*****************************************************************************
;;;** ------------------------------------------------------------------------**
;;;**   SEMANTIC MODEL FOR A SERVICE ORIENTED ARCHITECTURE                    **
;;;** This file is intended to describe the concept of service, device,       **
;;;** actions, objects, properties and the relationships and links established**
;;;** among these entities. This semantic model is consistent with the one    **
;;;** hold by the middleware architecture, and the MAS knowledge of the world **
;;;** ------------------------------------------------------------------------**
;;;*****************************************************************************

(in-context {general})
(in-namespace "events" :include "common")

;; An action is an event that hold two specific roles, the role of the agent
;; performing the action, and the object over which the action might be performed
;; over. 
;; We define the concept of action in this file instead of some other related with
;; the events-kb because this is our own understanding of the concept of action.
;; In previous implementations, actions only considered the agent carrying out the
;; actions, however, intended to support the automatic service composition, we need
;; to model the fact that actions are performed over object, and the agent of the action
;; is a service (or the device providing the service, by extension)


;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)

;; A property is a characteristic attribute possessed by all members of a class.
;; This concept is used to model aspects such as the location of a device, the
;; resolution of a video camera, etc.
(new-type {property} {thing})

;; Anything that was involved in the event belongs to this type-role.
(new-type-role {object involved} {event} {thing})

;; Service refers to the performance of work or duties for a servant, such as in the
;; case of Ambient Intelligence would be the context.
(new-type {service} {thing})
(new-event-type {action} '({event})
		:roles
		((:type {target-of-action} {thing})
		 (:indv {result} {thing}))) ;it represents the object receiving the action

(new-relation {the-opposite-action-of}
	:a-inst-of {action}
	:b-inst-of {action})
		
(new-type-role {performs-action} {service} {action})
(new-type-role {agent-of} {action} {service}) ;; this is the inverse of the service role "performs-action"
(new-type-role {offered-service} {device} {service}) 
(new-type-role {provider-device} {service} {device}) ;;This is the inverse of the device role "offered-service"
(new-type-role {service-property} {service} {property})
(new-type-role {associated-statement} {event} {thing})
(new-type-role {result-of-action} {event} {thing})
(new-type-role {object-of} {event} {thing})

;; A device is a machine used to perform one or more relatively simple tasks.
(new-type {performer} {thing}) ;it appears in planner/actions3.lisp
			       ;and it is used to represent the
			       ;"produces" relationship
(new-union-type {device} '({thing} {performer}))
(new-type-role {deviceLocation} {device} {property})



