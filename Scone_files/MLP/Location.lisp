;;;*******************************************************
;;;** --------------------------------------------------**
;;;**        BASED ON THE OPENLS SPECIFICATION          **
;;;** Generated from the the Location.ice content       **
;;;** --------------------------------------------------**
;;;** REQUIERED FILES TO BE ASSERTED TO KB:             **
;;;**         Shape.lisp                                **
;;;*******************************************************
	
(in-namespace "events" :include "common")
(in-context {general})

;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)



;; POSITION
(new-type {position} {thing})
(new-type-role {msid} {position} {thing})
(new-type-role {timePosition} {position} {time})
(new-type-role {shapePosition} {position} {shape})




;; LOCATION
(new-type {location data info} {thing})
(new-type-role {srsName} {location data info} {thing})
(new-type {degree} {unit})
(new-type-role {distanceUnit} {location data info} {degree})
(new-type-role {angularUnit} {location data info} {meter})

;; TYPES AND ROLES 
(new-type {DirectoryService} {service})
(new-type {LocationAdmin} {service})
(new-type {LocationListener} {service})

(new-relation {publishes}
	      :a-inst-of {thing}
	      :b-inst-of {thing})

;; ACTIONS AND EVENTS RELATED TO LOCATION
;; DIRECTORY SERVICE FUNCTIONS
(new-event-type {find} '({event})
		:roles
		((:type {soughtThing} {thing})
		 (:type {beingSoughtPosition} {position}))
  :throughout
  ((new-not-statement {soughtThing} {has position} {beingSoughtPosition})))

(new-event-type {findLocation} '({action} {find} {locate})
		:roles
		((:type {soughtPOI} {point of interest}))
  :throughout
  ((the-x-of-y-is-z {agent} {findLocation} {DirectoryService}))
  :before
  ((new-not-statement {soughtPOI} {is located at} {location}))
  :after
  ((new-statement {soughtPOI} {is located at} {location})))

(new-event-type {locateReport} '({action} {report} {locate})
		:roles
		((:type {reportedLocation} {position})
		 (:type {sink} {listener}))
  :throughout
  ((the-x-of-y-is-z {agent} {locateReport} {LocationAdmin})
   (the-x-of-y-is-z {sink} {locateReport} {LocationListener}))
  :before
  ((new-not-statement {sink} {is located at} {reportedLocation})
   (new-not-statement {agent} {publishes} {reportedLocation}))
  :after
  ((new-statement {sink} {is located at} {reportedLocation})
   (new-statement {agent} {publishes} {reportedLocation})))

(new-event-type {watchDevice} '({action} {find} {watch} {locate})
		:roles
		((:type {watchedDevice} {device})
		 (:type {LocationService} {service})
		 (:type {watchedDeviceLocation} {location}))
  :throughout
  ((the-x-of-y-is-z {agent} {watchDevice} {LocationService}))
  :before
  ((new-not-statement {watchedDevice} {is located at} {watchedDeviceLocation}))
  :after
  ((new-statement {watchedDevice} {is located at} {watchedDeviceLocation})
   (the-x-of-y-is-z {deviceLocation} {watchedDevice} {watchedDeviceLocation})))

(new-event-type {watchArea} '({action} {find} {watch} {locate} {identification} {supervise})
		:roles
		((:type {watchedArea} {shape})
		 (:type {incomingDevice} {device}))
		
  :throughout
  ((the-x-of-y-is-z {agent} {watchArea} {LocationService})
   (the-x-of-y-is-z {watchedObject} {watchArea} {watchedArea}))
  :before
  ((new-not-statement {incomingDevice} {is noticed in} {watchedArea}))
  :after
  ((new-statement  {incomingDevice} {is noticed in} {watchedArea})
   (the-x-of-y-is-z {position} {incomingDevice} {watchedDeviceLocation})))
