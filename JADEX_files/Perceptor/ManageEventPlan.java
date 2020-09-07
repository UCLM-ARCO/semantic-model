package jadex.examples.MASCS.Perceptor;

import jadex.examples.MASCS.*;
import jadex.runtime.*;
import jadex.adapter.fipa.*;
import jadex.runtime.IContentCodec;



/**
 *  Plan for managing the occurrence of an event, of any type
 *  Whenever this agent receives a message with an event, it 
 *  asserted to the beliefbase, and this assertion will trigger the
 *  plan to handle the type of event.
 */
public class ManageEventPlan extends Plan
{
    /**
     * The body method is called on the
     * instatiated plan instance from the scheduler.
     */ 

    public ManageEventPlan(){
	System.out.println("Created: "+this);
    }
    
    public void body()
    {
	/* Assert the event type to the beliefbase */
	IMessageEvent msg = (IMessageEvent)getInitialEvent();
	Event evt = (Event)msg.getContent();
	System.out.println("Se trata de un evento de tipo: "+(String)evt.getType());
	getBeliefbase().getBeliefSet("eventTypes").addFact(evt);	
    }
}
