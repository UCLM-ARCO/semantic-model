;; Now we define the sample building context. This building is where
;; services and devices have been deployed and where the intelligent 
;; room is located. So we describe the context and the events that
;; might take place in this context

;; We start describing the sample building, from outside

(in-namespace "events" :include "common")
(in-context {general})

(new-indv {sample-building} {builiding})
(new-indv-role {sample-roof} {ceiling} {sample-building})
(new-indv-role {sample-front-wall} {wall} {sample-building}) 
(new-indv-role {sample-back-wall} {wall} {sample-building}) 
(new-indv-role {sample-east-wall} {wall} {sample-building}) 
(new-indv-role {sample-west-wall} {wall} {sample-building})
(new-indv-role {sample-floor} {floor} {sample-building})
(new-indv-role {sample-doorway} {doorway} {sample-building})

(new-indv-role {sample-intelligent-room} {room} {sample-building})
(new-indv-role {sample-intelligent-room-back-wall} {wall} {sample-intelligent-room}) 
(new-indv-role {sample-intelligent-room-front-wall} {wall} {sample-intelligent-room}) 
(new-indv-role {sample-intelligent-room-east-wall} {wall} {sample-intelligent-room}) 
(new-indv-role {sample-intelligent-room-west-wall} {wall} {sample-intelligent-room}) 
(new-indv-role {sample-intelligent-room-floor} {floor} {sample-intelligent-room}) 
(new-indv-role {sample-intelligent-room-doorway} {doorway} {sample-intelligent-room}) 
(new-indv-role {sample-intelligent-room-door} {door} {sample-intelligent-room})

(new-indv-role {sample-corridor} {corridor} {sample-building})


(new-statement {sample-intelligent-room-doorway} {connects} {sample-intelligent-room} :c {sample-corridor})
(new-statement {sample-intelligent-room-door} {closes} {sample-intelligent-room})
