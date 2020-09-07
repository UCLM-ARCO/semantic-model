;;;*****************************************************************************
;;;** ------------------------------------------------------------------------**
;;;**      SERVICES AND DEVICES DEPLOYED AT THE sample BUILDING                **
;;;** This file describes the different set of devices and services deployed  **
;;;** in the context of the INDRRA building and its intelligent room.         **
;;;** The types defined here count on the types defined at service-kb.lisp    **
;;;** ------------------------------------------------------------------------**
;;;*****************************************************************************
	
(in-namespace "events" :include "common")
(in-context {general})

;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)


;; Now, we describe the individual set of devices and services deployed
;; along the building and the intelligent room.

;; Starting with the presence sensor
(new-indv {presenceSensor1} {presence sensor})
(new-indv {presenceSensor1Service} {service})
(the-x-of-y-is-z {offered-service} {presenceSensor1} {presenceSensor1Service})
(new-is-a {presenceSensor1Service} {presence-detection-service})
(new-event-type {presence-detection-action} '({action})
		:roles
		((:rename {target-of-action} {moving-person})))
		
(the-x-of-y-is-z {performs-action} {presence-detection-service} {presence-detection-action})

(new-indv {faceRecognitionSystem1} {faceRecognitionSystem})
(new-indv {SimpleRecognizer:default -p 12000} {face-recognition-service})
(the-x-of-y-is-z {offered-service}  {faceRecognitionSystem1} {SimpleRecognizer:default -p 12000})
(the-x-of-y-is-z {provider-device} {SimpleRecognizer:default -p 12000}  {faceRecognitionSystem1})
;(new-is-a  {SimpleRecognizer:default -p 12000} {face-recognition-service})
;(the-x-of-y-is-z {performs-action} {biometric-authentication-service} {biometricAuthentication})
(the-x-of-y-is-z {performs-action}  {SimpleRecognizer:default -p 12000} {faceRecognition})
(the-x-of-y-is-z {agent-of} {faceRecognition} {SimpleRecognizer:default -p 12000})
;(the-x-of-y-is-z {performs-action}  {SimpleRecognizer:default -p 12000} {faceRecognitionAuthenticationAccess})
;(the-x-of-y-is-z {agent-of} {faceRecognitionAuthenticationAccess} {SimpleRecognizer:default -p 12000})
;(the-x-of-y-is-z {performs-action}  {SimpleRecognizer:default -p 12000} {identityIdentification})
;(the-x-of-y-is-z {agent-of} {identityIdentification} {SimpleRecognizer:default -p 12000})
;(the-x-of-y-is-z {performs-action}  {SimpleRecognizer:default -p 12000} {identityIdentificationAccess})
;(the-x-of-y-is-z {agent-of} {identityIdentificationAccess} {SimpleRecognizer:default -p 12000})

(new-indv {faceDectectorSystem1} {faceDetectorSystem})
(new-indv {SimpleDetector:default -p 11000} {face-detection-service})
(the-x-of-y-is-z {offered-service}  {faceDectectorSystem1} {SimpleDetector:default -p 11000})
(the-x-of-y-is-z {provider-device} {SimpleDetector:default -p 11000}  {faceDectectorSystem1})
(the-x-of-y-is-z {performs-action}  {SimpleDetector:default -p 11000} {detectingFace})
(the-x-of-y-is-z {agent-of} {detectingFace} {SimpleDetector:default -p 11000})


(new-indv {lightSensor1} {light sensor})
(new-indv {lightSensor1Service} {service})
(the-x-of-y-is-z {offered-service}  {lightSensor1} {lightSensor1Service})
(the-x-of-y-is-z {provider-device} {lightSensor1Service}  {lightSensor1})
(new-is-a  {lightSensor1Service} {light-detection-service})
(the-x-of-y-is-z {performs-action} {light-detection-service} {detectingLight})


(new-indv {temperatureSensor1} {temperature sensor})
(new-indv {temperatureSensor1Service} {service})
(the-x-of-y-is-z {offered-service}  {temperatureSensor1} {temperatureSensor1Service})
(the-x-of-y-is-z {provider-device} {temperatureSensor1Service}  {temperatureSensor1})
(new-is-a  {temperatureSensor1Service} {temperature-measurement-service})
(the-x-of-y-is-z {performs-action} {temperature-measurement-service} {measuringTemperature})


(new-indv {soundSensor1} {sound sensor})
(new-indv {soundSensor1Service} {service})
(the-x-of-y-is-z {offered-service}  {soundSensor1} {soundSensor1Service})
(the-x-of-y-is-z {provider-device} {soundSensor1Service}  {soundSensor1})
(new-is-a  {soundSensor1Service} {sound-measurement-service})
(the-x-of-y-is-z {performs-action} {sound-measurement-service} {measuringNoise})


(new-indv {proximitySensor1} {proximity sensor})
(new-indv {proximitySensor1Service} {service})
(the-x-of-y-is-z {offered-service}  {proximitySensor1} {proximitySensor1Service})
(the-x-of-y-is-z {provider-device} {proximitySensor1Service}  {proximitySensor1})
(new-is-a  {proximitySensor1Service} {distance-measurement-service})
(the-x-of-y-is-z {performs-action} {distance-measurement-service} {measuringDistance})


(new-indv {doorLock1} {power door lock})
(new-indv {doorLock1Service} {service})
(the-x-of-y-is-z {offered-service}  {doorLock1} {doorLock1Service})
(the-x-of-y-is-z {provider-device} {doorLock1Service}  {doorLock1})
(new-is-a  {doorLock1Service} {actuator-service})
(the-x-of-y-is-z {performs-action} {actuator-service} {openDoorOfRoom})
(the-x-of-y-is-z {performs-action} {actuator-service} {closeDoorOfRoom})
(the-x-of-y-is-z {performs-action} {actuator-service} {openWindow})
(the-x-of-y-is-z {performs-action} {actuator-service} {closeWindow})


(new-indv {screen1} {media server})
(new-indv {screen1Service} {service})
(the-x-of-y-is-z {offered-service}  {screen1} {screen1Service})
(the-x-of-y-is-z {provider-device} {screen1Service}  {screen1})
(new-is-a  {screen1Service} {image-display-service})
(new-is-a  {screen1Service} {media-content-service})
(the-x-of-y-is-z {performs-action} {image-display-service} {displayImage})
(the-x-of-y-is-z {performs-action} {image-display-service} {displayVideo})


(new-indv {speaker1} {media server})
(new-indv {speaker1Service} {service})
(the-x-of-y-is-z {offered-service}  {speaker1} {speaker1Service})
(the-x-of-y-is-z {provider-device} {speaker1Service}  {speaker1})
(new-is-a  {speaker1Service} {audio-display-service})
(new-is-a  {speaker1Service} {media-content-service})
(the-x-of-y-is-z {performs-action} {audio-display-service} {displaySound})


(new-indv {videoCamera1} {video camera})
(new-indv {videoCamera1Service} {image-capture-service})
(the-x-of-y-is-z {offered-service}  {videoCamera1} {videoCamera1Service})
(the-x-of-y-is-z {provider-device} {videoCamera1Service}  {videoCamera1})
(the-x-of-y-is-z {performs-action} {videoCamera1Service} {recordingVideo})
(the-x-of-y-is-z {performs-action} {videoCamera1Service} {capturingFace})

(new-indv {videoCamera2} {video camera})
(new-indv {videoCamera2Service} {service})
(the-x-of-y-is-z {offered-service}  {videoCamera2} {videoCamera1Service})
(the-x-of-y-is-z {provider-device} {videoCamera2Service}  {videoCamera2})
(new-is-a  {videoCamera2Service} {image-capture-service})
(new-is-a  {videoCamera2Service} {media-content-service})
(the-x-of-y-is-z {performs-action} {image-capture-service} {recordingVideo})
(the-x-of-y-is-z {performs-action} {image-capture-service} {recordingImage})

(new-indv {videoCamera3} {video camera})
(new-indv {videoCamera3Service} {service})
(the-x-of-y-is-z {offered-service}  {videoCamera3} {videoCamera3Service})
(the-x-of-y-is-z {provider-device} {videoCamera3Service}  {videoCamera3})
(new-is-a  {videoCamera3Service} {image-capture-service})
(new-is-a  {videoCamera3Service} {media-content-service})
(the-x-of-y-is-z {performs-action} {image-capture-service} {recordingVideo})
(the-x-of-y-is-z {performs-action} {image-capture-service} {recordingImage})


(new-indv {videoCamera4} {video camera})
(new-indv {videoCamera4Service} {service})
(the-x-of-y-is-z {offered-service}  {videoCamera4} {videoCamera4Service})
(the-x-of-y-is-z {provider-device} {videoCamera4Service}  {videoCamera4})
(new-is-a  {videoCamera4Service} {image-capture-service})
(new-is-a  {videoCamera4Service} {media-content-service})
(the-x-of-y-is-z {performs-action} {image-capture-service} {recordingVideo})
(the-x-of-y-is-z {performs-action} {image-capture-service} {recordingImage})


(new-indv {rfidReader1} {authenticatior})
(new-indv {rfidReader1Service} {service})
(the-x-of-y-is-z {offered-service}  {rfidReader1} {rfidReader1Service})
(the-x-of-y-is-z {provider-device} {rfidReader1Service}  {rfidReader1})
(new-is-a  {rfidReader1Service} {electronic-authentication-service})
(new-is-a  {rfidReader1Service} {identification-service})
(the-x-of-y-is-z {performs-action} {electronic-authentication-service} {identityAuthentication})
(the-x-of-y-is-z {performs-action} {electronic-authentication-service} {RFIDidentityAuthentication})
(the-x-of-y-is-z {performs-action} {electronic-authentication-service} {identityAuthenticationAccess})

(new-indv {bluetooth1} {authenticatior})

;; We are identifying the location property for all the devices
;; mainly, we are giving its location, in terms of the room where
;; there are placed.
(new-is-a {location} {shape})
(x-is-a-y-of-z {location} {deviceLocation} {device})
(new-is-a {sample-intelligent-room} {location}) ;Appart from being a room of a building, it is also a location

(x-is-the-y-of-z {sample-intelligent-room} {location} {presenceSensor1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {lightSensor1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {temperatureSensor1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {soundSensor1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {proximitySensor1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {doorLock1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {screen1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {speaker1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {videoCamera1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {videoCamera2})
(x-is-the-y-of-z {sample-intelligent-room} {location} {videoCamera3})
(x-is-the-y-of-z {sample-intelligent-room} {location} {videoCamera4})
(x-is-the-y-of-z {sample-intelligent-room} {location} {rfidReader1})
(x-is-the-y-of-z {sample-intelligent-room} {location} {bluetooth1})



