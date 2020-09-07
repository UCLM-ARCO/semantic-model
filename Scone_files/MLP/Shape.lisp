;;;*******************************************************
;;;** --------------------------------------------------**
;;;**    FROM THE SHAPE ELEMENT DEFINITION (Shape.ice)  **
;;;** This file describes the MLP standard data type    **
;;;** and location functions provided by the "Elcano"   **
;;;** location service (C. Martin & F. Moya)            **
;;;** --------------------------------------------------**
;;;*******************************************************
	
(in-namespace "events" :include "common")
(in-context {general})

;;; This file necessarily contains some forward references.
(setq *defer-unknown-connections* t)


;; POINT AND COORDINATE
(new-type {coordinate X} {number})
(new-type {coordinate Y} {number})
(new-type {coordinate Z} {number})
(new-union-type {coordinate} '({coordinate X} {coordinate Y} {coordinate Z}))
(new-union-type {point} '({coordinate X} {coordinate Y} {coordinate Z}))

;; SHAPES, LINE & BOX
(new-type {shape} {thing})
(new-type-role {center} {shape} {point})
(new-type {line} {thing})
(new-type-role {linePoint} {line} {point} :n 2)
(new-type {box} {shape})
(new-type-role {topLeft} {box} {coordinate})
(new-type-role {bottonRight} {box} {coordinate})
(new-type {linear ring} {shape})
(new-type-role {linearRingPoint} {linear ring} {point}) ;;at least 3 points

;; POLYGON
(new-type {polygon} {shape})
(new-type-role {outerBoundary} {polygon} {linear ring})
(new-type-role {innerBoundary} {polygon} {linear ring})

;; CIRCULAR ARC
(new-type {circular arc area} {polygon})
(new-type-role {circularArcCenter} {circular arc area} {coordinate})
(new-type-role {inRadius} {circular arc area} {number})
(new-type-role {outRadius} {circular arc area} {number})
(new-type-role {startAngle} {circular arc area} {number})
(new-type-role {stoptAngle} {circular arc area} {number})

;; CIRCULAR AREA
(new-type {circular area} {polygon})
(new-type-role {circularCenter} {circular area} {coordinate})
(new-type-role {circularRadius} {circular area} {number})

;; ELLIPTICAL
(new-type {elliptical area} {polygon})
(new-type-role {ellipticalAreaCenter} {elliptical area} {coordinate})
(new-type-role {ellipticalAngle} {elliptical area} {number})
(new-type-role {semiMinor} {elliptical area} {number})
(new-type-role {semiMajor} {elliptical area} {number})