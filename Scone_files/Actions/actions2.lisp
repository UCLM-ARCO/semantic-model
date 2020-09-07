;; Each instance of capturingContextInformation is an event
;; in which an agent capture some information and place it in an
;; storage for later use. (image, temperature, sound, etc.)
(new-event-type {capturingContextInformation} '({event})
	:roles
	((:indv {captureResult} {data})
	 (:indv {feature} {thing}))
  :before
  ((new-not-statement {captureResult} {is noticed in} {feature}))
  :after
  ((new-statement {captureResult} {is noticed in} {feature})))


;; The detect event is similar to the capturingContextInformation, but
;; it is intended to point out an specific feature out of a given
;; context. It is not just constraint to intangible features of the
;; contexts, as it is the capturingContextInformation
(new-event-type {detect} '({event})
	:roles
	((:indv {detectionSource} {thing})
	 (:indv {detectionObject} {thing})) 
 :before
 ((new-not-statement {detectionObject} {is noticed in} {detectionSource}))
 :after
  ((new-statement {detectionObject} {is noticed in} {detectionSource})))


;; cyc comment: Each instance of TakingAPhotograph is an event in
;; which a single still VisualImage is recorded using a
;; StillCamera. Notable specializations include
;; TakingAPhotograph-DigitalCamera and TakingAPhotograph-FilmCamera."  
(new-event-type {recordingImage} '({capturingContextInformation} {action})
  :throughout
  ((the-x-of-y-is-a-z {agent}  {recordingImage} {camera})
   (the-x-of-y-is-a-z {captureResult} {recordingImage} {imageFile})
   (the-x-of-y-is-a-z {feature} {recordingImage} {visual content})))


;; Sounds in an specific contexts are recorded by an audio recording
;; device or a recorder
(new-event-type {recordingSound} '({capturingContextInformation} {action})
  :throughout
  ((the-x-of-y-is-a-z {agent} {recordingSound} {microphone})
   (the-x-of-y-is-a-z {captureResult} {recordingSound} {audioFile})
   (the-x-of-y-is-a-z {feature} {recordingSound} {audio content})))


;; Recording video represents the special action in which visual
;; contents are generated, instead of just one picture as in
;; recordImage
(new-event-type {recordingVideo} '({capturingContextInformation} {action})
  :throughout
  ((the-x-of-y-is-a-z {agent} {recordingVideo} {video camera})
   (the-x-of-y-is-a-z {captureResult} {recordingVideo} {videoFile})
   (the-x-of-y-is-a-z {feature} {recordingVideo} {visual content})))


;; Meassuring the temperature of the context can also be considered as
;; capturingContextInformation, but using a temperature sensor.
(new-event-type {measuringTemperature} '({capturingContextInformation} {action})
  :throughout
  ((the-x-of-y-is-a-z  {agent} {measuringTemperature} {temperature sensor})
   (the-x-of-y-is-a-z {captureResult} {measuringTemperature} {measure})
   (the-x-of-y-is-a-z {feature} {measuringTemperature} {measurable quality}))) ;based on core-kb.lisp

;; Meassuring the noise level of the context can also be considered as
;; capturingContextInformation, but using a temperature sensor.
(new-event-type {measuringNoise} '({capturingContextInformation} {action})
  :throughout
  ((the-x-of-y-is-a-z  {agent} {measuringNoise} {sound sensor})
   (the-x-of-y-is-a-z {captureResult} {measuringNoise} {measure})
   (the-x-of-y-is-a-z {feature} {measuringNoise} {measurable quality}))) ;based on core-kb.lisp

;; Meassuring the noise level of the context can also be considered as
;; capturingContextInformation, but using a temperature sensor.
(new-event-type {measuringDistance} '({capturingContextInformation} {action})
  :throughout
  ((the-x-of-y-is-a-z  {agent} {measuringDistance} {proximity sensor})
   (the-x-of-y-is-a-z {captureResult} {measuringDistance} {measure})
   (the-x-of-y-is-a-z {feature} {measuringDistance} {measurable quality}))) ;based on core-kb.lisp


;; Detecting presence in the context is also an action performed in
;; order to capturingContextInformation
(new-event-type {detectingPresence} '({capturingContextInformation}
				      {detect} {action})
  :throughout
  ((the-x-of-y-is-a-z {detectionSource} {detectingPresence} {enclosed space})
   (the-x-of-y-is-a-z {detectionObject} {detectingPresence} {moving object})
   (the-x-of-y-is-a-z  {agent} {detectingPresence} {presence sensor})
   (the-x-of-y-is-a-z {captureResult} {detectingPresence} {booleanValue})
   (the-x-of-y-is-a-z {feature} {detectingPresence} {moving object})));moving object extracted from move.lisp

;; Detecting light in the context is also an action performed in
;; order to capturingContextInformation
(new-event-type {detectingLight} '({capturingContextInformation}
				   {detect} {action}) 
  :throughout
  ((the-x-of-y-is-a-z {detectionSource} {detectingLight} {enclosed space})
   (the-x-of-y-is-a-z {detectionObject} {detectingLight} {light})
   (the-x-of-y-is-a-z  {agent} {detectingLight} {light sensor})
   (the-x-of-y-is-a-z {captureResult} {detectingLight} {booleanValue})
   (the-x-of-y-is-a-z {feature} {detectingLight} {light})));moving object extracted from move.lisp

;; Detecting a face in an image tries to point out where is the face
;; of the person. 
(new-event-type {detectingFace} '({detect} {action}) 
  :throughout
  ((the-x-of-y-is-z {detectionSource} {detectingFace} {data})
   (the-x-of-y-is-z {detectionObject} {detectingFace} {face})
   (the-x-of-y-is-z {object-of} {detectingFace} {imageFile})
   (the-x-of-y-is-z  {agent} {detectingFace} {faceDetectorSystem}))
  :before
  ((new-statement {data} {is recorded in} {imageFile})) ;;an image is required
  :after
  ((new-statement {detectionObject} {not yet identified as} {person identity})
  (new-statement {face} {is noticed in} {imageFile})))

;;*******************************************************************
;;******************** CAPTURE ACTIONS ******************************
;;*******************************************************************


;; Here we mean capture in the sense of generating the data
;; corresponding to the feature captured.
(new-event-type {capture} '({event})
	:roles
	((:indv {captionSource} {thing})
	 (:indv {captionObject} {thing})
	 (:indv {captionTarget} {data}))
 :throughout
 ((new-statement {captionObject} {is noticed in} {captionSource}))    
 :before
 ((new-not-statement {captionObject} {is recorded in}
		     {captionTarget}))
 :after
  ((new-statement {captionObject} {is recorded in}
		     {captionTarget})))

(new-event-type {capturingImage} '({capture} {action})
 :after
 ((new-statement {imageFile} {is picture of} {thing})))

;; Capturing a biometric feature is required in order to perform a
;; biometric ID. Therefore this action is the parent of the more
;; specific actions such as capturingFace, etc.
(new-event-type {capturingBiometricFeature} '({capture} {action})
  :throughout
  ((the-x-of-y-is-a-z  {captionSource} {capturingBiometricFeature}
		       {body part})
   (the-x-of-y-is-a-z  {captionObject}
		       {capturingBiometricFeature}{biometric feature})
   (the-x-of-y-is-a-z  {captionTarget}  {capturingBiometricFeature}
		       {data})))

(new-event-type {capturingFace} '({capture}{action})
  :throughout
  ((the-x-of-y-is-z  {captionSource} {capturingFace}
		     {person})
   (the-x-of-y-is-z  {captionObject}
		     {capturingFace}{face})
   (the-x-of-y-is-z  {object-of}
		     {capturingFace} {data})
   (the-x-of-y-is-z  {captionTarget} {capturingFace}
		     {imageFile}))
  :before
  ;;((new-statement {person} {is withing range} {camera}))
  ((new-statement {imageFile} {is picture of} {biometric feature}))
  :after
  ((new-statement {face} {is recorded in} {imageFile})
  (new-not-statement {face} {is noticed in} {imageFile})))

(new-event-type {capturingIris} '({capturingBiometricFeature}{action}) 
  :throughout
  ((the-x-of-y-is-z  {captionSource} {capturingIris}
		     {person})
   (the-x-of-y-is-z  {captionObject}
		     {capturingIris}{iris})
   (the-x-of-y-is-z  {captionTarget}  {capturingIris}
		     {imageFile})))

(new-event-type {capturingFingerprint} '({capturingBiometricFeature}{action}) 
  :throughout
  ((the-x-of-y-is-z  {captionSource} {capturingFingerprint}
		     {person})
   (the-x-of-y-is-z  {captionObject}
		     {capturingIris}{fingerprint})
   (the-x-of-y-is-z  {captionTarget}  {capturingFingerprint}
		     {imageFile})))
