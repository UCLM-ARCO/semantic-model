;;;*******************************************************
;;;** --------------------------------------------------**
;;;**        SOME ACTIONS FOR TESTING THE PLANNER       **
;;;** This file define and describe some of the actions **
;;;** that might take place in the context of a building**
;;;** These actions are used to test the planning algor **
;;;** REQUIRES: moves.lisp (csahin/events/kb)           **
;;;**           planner.lisp                            **
;;;**           services.lisp                           **
;;;** --------------------------------------------------**
;;;*******************************************************


(in-context {general})
(in-namespace "events" :include "common")
;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)

;;; Some roles required for the following events and actions
(new-indv-role {id} {person} {thing})
(new-type {media content} {thing}) ;shouldnt it be partially tang?
(new-type {data} {thing})
(new-type {visual content} {media content})
(new-type {audio content} {media content})
(new-indv-role {volumen} {audio content} {measure})
(new-union-type {imageFile} '({data} {visual content})) ;just a picture
(new-union-type {videoFile} '({data} {visual content})) ;video
(new-union-type {audioFile} '({data} {audio content}))
(new-type {booleanValue} {data})
(new-split-subtypes {booleanValue}
		    '({true} {false}))

;;*****************************************************
;;*********** IDENTIFICATION FEATURES *****************
;;*****************************************************
(new-type {biometric feature} {thing})
(new-indv-role {face} {person} {biometric feature}); does body part exist?
(new-indv-role {iris} {person} {biometric feature});
(new-indv-role {fingerPrint} {person} {biometric feature});
(new-type-role {body part} {person} {thing})
(new-is-a {face} {body part})
(new-is-a {iris} {body part})
(new-is-a {fingerprint} {body part})
(new-type {identity} {thing})
(new-type {proof of identity} {identity})
(new-type {RFID tag} {proof of identity})
(new-indv-role {person identity} {person} {identity})
(new-relation {identified as}
	      :a-inst-of {thing}
	      :b-inst-of {thing})
(new-relation {not yet identified as}
	      :a-inst-of {thing}
	      :b-inst-of {thing})
(new-relation {authenticates}
	      :a-inst-of {thing}
	      :b-inst-of {person identity})
;;FIXME lo dejo por si aparece en algun sitio, para solucionar el problema
;;(new-relation {captures}
(new-relation {is recorded in}
	      :a-inst-of {thing}
	      :b-inst-of {data}) 
(new-relation {is picture of}
	      :a-inst-of {imageFile}
	      :b-inst-of {thing})
(new-relation {has access to}
	      :a-inst-of {person identity}
	      :b-inst-of {enclosed space}) 

(new-relation {is noticed in}
	      :a-inst-of {thing}
	      :b-inst-of {thing}) ;we could be more specific, but we
				  ;want the be noticed source to be
				  ;places, data files, etc.
(new-relation {is withing range}
	      :a-inst-of {thing}
	      :b-inst-of {device})



;; List of statements that are required to describe the following
;; actions and events
(new-relation {produces}
        :a-inst-of {thing} ;with the capability of doing sth 
	:b-inst-of {thing})

(new-relation {greater than}
	:a-inst-of {number}
	:b-inst-of {number})

(new-relation {less than}
	:a-inst-of {number}
	:b-inst-of {number})

(new-relation {equal to}
	:a-inst-of {number}
	:b-inst-of {number})


;;*********************
;; AMBIENT FEATURES
;;*********************
(new-type {ambiental feature} {intangible})
(new-is-a {temperature} {ambiental feature})
(new-type {light} {ambiental feature})
(new-type {noise} {ambiental feature})
(new-type {statusFeature} {thing})
(new-split-subtypes {statusFeature} '({on} {off} {open} {close}))

(new-relation {status}
	:a-inst-of {thing}
	:b-inst-of {statusFeature})



;; cyc comment: A subcollection of PurposefulAction, instances of Identifying are
;; those actions in which something is identified. See also
;; identifiedThing, IdentifyingObjectAsType, identifiedAsType and
;; IdentifyingAsTypeFn.   

(new-event-type {identification} '({event})
	:roles
	((:type {identifiedThing} {thing}))
 :before
 ((new-not-statement {identifiedThing} {identified as} {thing}))

  :after
  ((new-statement {identifiedThing} {identified as} {thing})))

;; Identifying a person using an identification device
(new-event-type {identityIdentification} '({identification} {action})
 
 :throughout
  (   (the-x-of-y-is-a-z {agent}  {identityIdentification}
		      {identificationDevice})
   (the-x-of-y-is-z {identifiedThing} {identityIdentification}
		      {person identity})))

;; Identity authentication access, restrict the access to a specific
;; enclosed space to only those users whose identity have been proof,
;; by means of user name and password, by means of RFID
(new-event-type {identityIdentificationAccess} '({identification}
						 {identityIdentification}
						 {action}) 
 :before      
 ((new-not-statement {identifiedThing} {has access to}
	{enclosed space}))
 :after
 ((new-statement {identifiedThing} {has access to}
	{enclosed space})))


;; cyc comment:"AuthenticationEvent is the collection of events in
;; which some sort of authentication or certification takes place. For
;; example, this includes certifying a person's identity, the
;; authenticity of a document, or the security of a computer login."  
(new-event-type {authentication} '({event})
        :roles
	((:type {authenticationSource} {thing})
	 (:indv {authenticationSubject} {person identity}))
  :before
  ((new-not-statement {authenticationSource} {authenticates}
	{authenticationSubject}))
  :after
  ((new-statement {authenticationSource} {authenticates}
	{authenticationSubject})))


;; cyc comment: a specialization of AuthenticationEvent is a
;; collection of events. Each instance of BiometricAuthenticationEvent
;; is an event in which a BiometricAuthenticationDevice is used to
;; determine whether or not a person has the right to access some
;; individual." 
(new-event-type {biometricAuthentication} '({authentication} {action})
 :throughout
  ((the-x-of-y-is-z {agent}  {biometricAuthentication} {biometricAuthenticationDevice})
   (the-x-of-y-is-z {authenticationSource} {biometricAuthentication}
		      {biometric feature})))


;; Biometric Authentication access restrict access to an enclosed
; space, only to those user authenticated and allowed to entry.
 (new-event-type {biometricAuthenticationAccess}
		 '({biometricAuthentication}{authentication} {action}) 
 :before      
 ((new-not-statement {authenticationSubject} {has access to}
	{enclosed space}))
 :after
 ((new-statement {authenticationSubject} {has access to}
	{enclosed space})))

;; Granting access as a result of an authentification as an allowed person
(new-event-type {identityAuthentication} '({authentication} {action})
 
 :throughout
 ((the-x-of-y-is-a-z {agent}  {identityAuthentication}
		     {identificationDevice})
  (the-x-of-y-is-a-z {authenticationSource} {identityAuthentication}
		     {proof of identity})))

;; Identity authentication access, restrict the access to a specific
;; enclosed space to only those users whose identity have been proof,
;; by means of user name and password, by means of RFID
(new-event-type {identityAuthenticationAccess} '({authentication}
						 {identityAuthentication}
						 {action}) 
 :before      
 ((new-not-statement {authenticationSubject} {has access to}
	{enclosed space}))
 :after
 ((new-statement {authenticationSubject} {has access to}
	{enclosed space})))

;; Granting access by means of an RFID authentication process
(new-event-type {RFIDidentityAuthentication} '({authentication} {action})
 :throughout
 ((the-x-of-y-is-a-z {agent} {RFIDidentityAuthentication} {RFID Reader})
   (the-x-of-y-is-z {authenticationSource} {RFIDidentityAuthentication} {RFID tag})))

 (new-event-type {RFIDidentityAuthenticationAccess} '({authentication}
						      {RFIDidentityAuthentication}
						      {action})
 :before      
 ((new-not-statement {authenticationSubject} {has access to}
	{enclosed space}))
 :after
 ((new-statement {authenticationSubject} {has access to}
	{enclosed space})))

;; We simply consider here the recognition perform over files (audio, video, images, etc.)
(new-event-type {recognition} '({event})
	:roles
	((:type {recognitionSource} {data})
	 (:indv {recognitionSubject} {person identity}))
 :before
 ((new-statement {recognitionSource} {not yet identified as} {recognitionSubject}))
 :after
 ((new-statement {recognitionSource} {identified as} {person identity})))

(new-event-type {faceRecognition} '({recognition} {action}) 
 :throughout
 ((the-x-of-y-is-z {recognitionSource} {faceRecognition} {imageFile})
  (the-x-of-y-is-z {object-of} {faceRecognition} {face})
  (the-x-of-y-is-z {agent} {faceRecognition} {faceRecognitionSystem}))
 :before
 ((new-statement {face} {is noticed in} {recognitionSource}))
)

;; Face recognition as a biometric authentication method
(new-event-type {faceRecognitionAuthentication} '({authentication}
						  {action}) 
 :throughout
 ((the-x-of-y-is-z {authenticationSource}  {faceRecognitionAuthentication} {face})
  (the-x-of-y-is-a-z {agent}  {faceRecognitionAuthentication}
		     {faceRecognitionSystem}))) 

(new-event-type {faceRecognitionAuthenticationAccess}  '({authentication} {faceRecognitionAuthentication}
						  {action}) 

 :before      
 ((new-not-statement {authenticationSubject} {has access to}
	{enclosed space}))
 :after
 ((new-statement {authenticationSubject} {has access to}
	{enclosed space})))
