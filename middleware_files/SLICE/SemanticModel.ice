//-*- mode:idl -*-
module SemanticModel {
  dictionary <string, Object> Properties;

  struct Event {
    Properties theProperties;
  };
  
   interface EventMonitor{
     void report(Event e);
   };

  interface Device{
    void deviceName(string name);
    void setProperties(Properties spec);		
    Properties getProperties();   	    
  };

  sequence<Event>  EventSeq;	    

  interface Service {
   EventSeq performAction(string idAction, Object thg);
   };
};
