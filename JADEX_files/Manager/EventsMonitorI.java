package jadex.examples.MASCS.Manager;

import jadex.examples.MASCS.*;
import jadex.runtime.*;
import jadex.adapter.fipa.*;
import jadex.runtime.IContentCodec;


class EventsMonitorI extends Events._EventMonitorDisp {
    private final IExternalAccess agent;
    
    public  EventsMonitorI(final IExternalAccess ag){
	this.agent = ag;
    }
    public void report(Events.Event e , Ice.Current __current){

	Events.Event evt = new Events.Event("unauthorisedPresence");
	System.out.println("Event Type: "+ evt.type);
	agent.getBeliefbase().getBeliefSet("eventTypes").addFact(evt);
    }
}
