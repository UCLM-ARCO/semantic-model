package jadex.examples.MASCS.Manager;

import jadex.examples.MASCS.*;
import jadex.runtime.*;
import jadex.adapter.fipa.*;
import jadex.runtime.IContentCodec;

/**
 *  Plan for sending the Event type to the Perceptor agent
 */
public class SendEventTypePlan extends Plan
{
    /**
     * The body method is called on the
     * instatiated plan instance from the scheduler.
     */ 

    public SendEventTypePlan(){
	System.out.println("Created: "+this);
    }
    
    public void body()
    {	 
	
	/*==========================================*/
	/* Send Event Type instnance to Perceptor.  */
	/*==========================================*/
	 ServiceDescription sd = new ServiceDescription("service_percept", null, null);
	 AgentDescription dfadesc = new AgentDescription();
	 dfadesc.addService(sd);
	 
	 SearchConstraints constraints = new SearchConstraints();
	 constraints.setMaxResults(100);
	 
	 IGoal ft = createGoal("df_search");
	 ft.getParameter("description").setValue(dfadesc);
	 ft.getParameter("constraints").setValue(constraints);
	 dispatchSubgoalAndWait(ft);
	 AgentDescription[] selectors = (AgentDescription[])ft.getParameterSet("result").getValues();
	 
	 if(selectors.length > 0){
	     /*Note that Events.Event class is different from
    	     Event. The first one is created from the slice and the
    	     second from the Ontology. The only way of serializing
    	     object to be sent in a message is that they are classes
    	     of the ontology. Therefore, we have to play with these to
    	     event classes, although they are the same one. It is just
    	     because of a restriction of the Jadex msg */
    	     Events.Event ev[]=(Events.Event[])getBeliefbase().getBeliefSet("eventTypes").getFacts();
	     if(ev.length>0){
		 //An event class is defined each time an alarm has arisen 
		 // ev[0].type = "unauthorisedPresence"; //At the moment, only the type is set
		 //Further works required this class to be obtained from the event channel
		 //ev.setHasASpecification()
		
		 IMessageEvent mevent = createMessageEvent("eventType_inform");
		 AgentIdentifier ai = new AgentIdentifier(selectors[0].getName().getName(), true);
		
		 mevent.getParameterSet(SFipa.RECEIVERS).addValue(ai);

		 System.out.println("SendEventTypePlan.java: event type: "+ ev[0].type );
		 Event evt = new Event();
		 evt.setType(ev[0].type);
		 mevent.setContent(evt);
		 //		 mevent.setContent(ev[0]);
	
		 sendMessage(mevent);
	     }
	     
	 }
	 else
	     System.out.println("SendListOfProxies.java: No se ha encontrado ningún agente");



    }
}
