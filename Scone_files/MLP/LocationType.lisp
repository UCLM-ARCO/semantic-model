;;;*******************************************************
;;;** --------------------------------------------------**
;;;**        BASED ON THE OPENLS SPECIFICATION          **
;;;** Generated from the the LocationTypes.ice content  **
;;;** --------------------------------------------------**
;;;** REQUIERED FILES TO BE ASSERTED TO KB:             **
;;;**         Location.lisp                             **
;;;*******************************************************


	
(in-namespace "events" :include "common")
(in-context {general})

;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)


(new-type {address} {thing})

;; A PoI is a "location with a fixed position"
(new-type {point of interest} {point})
(new-type-role {poiAttributes} {point of interest} {thing})
(new-type-role {poiPoint} {point of interest} {point})
(new-type-role {poiAddress} {point of interest} {address})

;(new-complete-split {location-type} '({address} {position} {point of interest}))
(new-type-role {ltype} {location} {location type})
(new-type-role {poi} {location} {point of interest})
(new-type-role {locationAddress} {location} {address})