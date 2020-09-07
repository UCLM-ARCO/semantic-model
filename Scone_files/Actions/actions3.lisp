;;;*******************************************************
;;;** --------------------------------------------------**
;;;**        SOME ACTIONS FOR TESTING THE PLANNER       **
;;;** This file define and describe actions that can be **
;;;** performed by actuators                            **
;;;** REQUIRES: moves.lisp (csahin/events/kb)           **
;;;**           planner.lisp                            **
;;;**           services.lisp                           **
;;;**           actions.lisp                            **
;;;**           actions2.lisp                           **
;;;** --------------------------------------------------**
;;;*******************************************************


;; This set of actions describe all the actions that an agent can
;; perform in order to play a sound or a visual content. It does not
;; describe th meaning of playing a game or a role
(new-event-type {play} '({event})
	:roles
	((:indv {player} {playerDevice})
	 (:type {playingObject} {thing})))


;; Play and display are closely related. Play is in charge of decoding
;; while display transmit the signal
(new-event-type {display} '({event})
	:roles
	((:indv {displayer} {displayerDevice})
	 (:type {displayingObject} {thing})))



;; Play a sound
(new-event-type {playSound} '({play} {action})
  :throughout
  ((the-x-of-y-is-a-z {player} {playSound} {audioPlayer})
   (the-x-of-y-is-a-z {playingObject} {playSound} {audio content})
   (new-statement {player} {status} {on}))
  :before
  ((new-not-statement {player} {produces} {audio content}))
  :after
  ((new-statement {player} {produces} {audio content})))

;; Play a video
(new-event-type {playVideo} '({play} {action})
  :throughout
  ((the-x-of-y-is-a-z {player} {playVideo} {videoPlayer})
   (the-x-of-y-is-a-z {playingObject} {playVideo} {visual content})
   (new-statement {player} {status} {on}))
  :before
  ((new-not-statement {player} {produces} {visual content}))
  :after
  ((new-statement {player} {produces} {visual content})))

;; Play an image (picture)
(new-event-type {playImage} '({play} {action})
  :throughout
  ((the-x-of-y-is-a-z {player} {playImage} {imagePlayer})
   (the-x-of-y-is-a-z {playingObject} {playImage} {visual content})
   (new-statement {player} {status} {on}))
  :before
  ((new-not-statement {player} {produces} {visual content}))
  :after
  ((new-statement {player} {produces} {visual content})))


;; Display an image (picture) you need some sort of screen device
(new-event-type {displayImage} '({display} {action})
  :throughout
  ((the-x-of-y-is-a-z {displayer} {displayImage} {imageDisplayer})
   (the-x-of-y-is-a-z {displayingObject} {displayImage} {visual content})
   (new-statement {displayer} {status} {on}))
  :before
  ((new-not-statement {displayer} {produces} {visual content}))
  :after
  ((new-statement {displayer} {produces} {visual content})))

;; Display video you need some sort of screen device
(new-event-type {displayVideo} '({display} {action})
  :throughout
  ((the-x-of-y-is-a-z {displayer} {displayVideo} {videoDisplayer})
   (the-x-of-y-is-a-z {displayingObject} {displayVideo} {visual content})
   (new-statement {displayer} {status} {on}))
  :before
  ((new-not-statement {displayer} {produces} {visual content}))
  :after
  ((new-statement {displayer} {produces} {visual content})))

;; Display sound (emite)
(new-event-type {displaySound} '({display} {action})
  :throughout
  ((the-x-of-y-is-a-z {displayer} {displaySound} {AudioDisplayer})
   (the-x-of-y-is-a-z {displayingObject} {displaySound} {audio content})
   (new-statement {displayer} {status} {on}))
  :before
  ((new-not-statement {displayer} {produces} {audio content}))
  :after
  ((new-statement {displayer} {produces} {audio content})))



;; This set of actios refers to turning on and off an electrical
;; device. 
(new-event-type {turn} '({event})
	:roles
	((:indv {turningDevice} {device})))

;; Turn on a device. It cannot be turn on if it is already turn on 
(new-event-type {turnOn} '({turn} {action})
  :before
  ((new-statement  {turningDevice} {status} {off}))
  :after
 ((new-statement  {turningDevice} {status} {on})))

;; Turn off a device. It cannot be turn off if it is already turn
;; off. It has to be on so as to be turn it off. 
(new-event-type {turnOff} '({turn} {action})
  :before
  ((new-statement  {turningDevice} {status} {on}))
  :after
  ((new-statement  {turningDevice} {status} {off})))

;; This set of actions are a bit more complex, since they are intended
;; to describe those actions that increase or decrease a specific
;; magnitude of a measurable quality, such as the temperature, the
;; volumen, etc.
(new-event-type {increment} '({event})
	:roles
	((:indv {incrementingMeasure} {measure})
	 (:indv {beforeMeasureValue} {number})
	 (:indv {afterMeasureValue} {number})
	 (:indv {incrementingMax} {number}))
  :throughout
  ((x-is-the-y-of-z {beforeMeasureValue} {measure magnitude}
		    {incrementingMeasure}) 
   (x-is-the-y-of-z {afterMeasureValue} {measure magnitude}
		    {incrementingMeasure}) 
   (new-statement {beforeMeasureValue} {less than}
		  {incrementingMax})
   (new-statement {afterMeasureValue} {less than}
		  {incrementingMax})) 
  :before
  ((new-statement  {beforeMeasureValue} {equal to}
		   {afterMeasureValue}))
  :after
  ((new-statement {beforeMeasureValue} {less than}
		  {afterMeasureValue}))) 
;; Increment volume of an audio displayer device
(new-event-type {incrementVolume} '({action} {increment})
  :throughout
  ((x-is-the-y-of-z {volume} {incrementingMeasure}
  {incrementVolume})))

 ;; Increment the temperature of a room 
 (new-event-type {incrementTemperature} '({action} {increment})
  :throughout
  ((x-is-the-y-of-z {temperature} {incrementingMeasure}
		    {incrementTemperature})))

;; The following set describe the open and close events, and the
;; actions that can be performed over different stuffs, a door, an
;; envelop, a box, etc.
(new-event-type {open} '({event})
        :roles
	((:type {openingObject} {enclosed space})
	 (:type {openingMean} {movable object}))
  :throughout
  ((the-x-of-y-is-a-z {openingMean} {open} {wayThrough})
   (new-statement {openingMean} {closes} {openingObject}))
  :before
  ((new-statement {openingObject} {status} {close}))
  :after
  ((new-statement {openingObject} {status} {open})))
  
;; Open a room, using a door
(new-event-type {openDoorOfRoom} '({open} {action})
  :throughout
  ((the-x-of-y-is-a-z {openingObject} {openDoorOfRoom} {room})
   (the-x-of-y-is-a-z {openingMean} {openDoorOfRoom} {door})))

;; Openning a window of a room or a car or whatever other enclosed
;; space that might have windows
(new-event-type {openWindow}  '({open} {action})
 :throughout
  ((the-x-of-y-is-a-z {openingMean} {openWindow} {window})))

;; CLOSE

(new-event-type {close} '({event})
        :roles
	((:indv {closingObject} {enclosed space})
	 (:indv {closingMean} {movable object}))
  :throughout
  ((the-x-of-y-is-a-z {closingMean} {close} {wayThrough})
   (new-statement {closingMean} {closes} {openingObject}))
  :before
  ((new-statement {closingObject} {status} {open}))
  :after
  ((new-statement {closingObject} {status} {close})))
  
;; Open a room, using a door
(new-event-type {closeDoorOfRoom} '({close} {action})
  :throughout
  ((the-x-of-y-is-a-z {closingObject} {closeDoorOfRoom} {room})
   (the-x-of-y-is-a-z {closingMean} {closeDoorOfRoom} {door})))

;; Openning a window of a room or a car or whatever other enclosed
;; space that might have windows
(new-event-type {closeWindow}  '({close} {action})
 :throughout
  ((the-x-of-y-is-a-z {closingMean} {closeWindow} {window})))
