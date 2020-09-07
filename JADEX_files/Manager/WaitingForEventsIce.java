package jadex.examples.MASCS.Manager;
import java.util.*;
import jadex.runtime.*;
import java.lang.*;
import Ice.*;
import jadex.examples.MASCS.*;
import jadex.examples.MASCS.Manager.*;
/**
 *  This Ice app subscribes to the ''alarm'' channel, where events regarding
 *  the sensor's trigger are being plubished. 
 *  1st. TEST: in order to test this class, the presenceDummy can be used to
 *  check if events plublished at the alarm channerl are correctly handled here.
 */

public class WaitingForEventsIce extends Ice.Application{

    private final IExternalAccess agent;
 public WaitingForEventsIce(final IExternalAccess ag){
	super();
	this.agent = ag;
	new Thread(
		   new Runnable() {
		       public void run() {
			   String[] args= new String[1];
			   args[0]="";
			   int status = main("WaitingForEventsIce", args, "config");
			   
		       }
		   }
		   ).start();
    }

    public int run(String[] args)
    {
	Ice.Properties properties = communicator().getProperties();
	String prop_key = "IceStorm.TopicManager.Proxy";
	String endpoint = properties.getProperty(prop_key);
	
	if(endpoint==null){
	    System.out.println(": property `" + prop_key + "' not set");
	    System.exit(0);
	}
	
	Ice.ObjectPrx base = communicator().stringToProxy(endpoint);
	IceStorm.TopicManagerPrx topicManager = IceStorm.TopicManagerPrxHelper.checkedCast(base);
	if(topicManager == null){
	    System.out.println(": invalid proxy");
	    System.exit(0);
	}

	java.util.Map qos = null;
	
	// create the servant to receive the events
 	Ice.ObjectAdapter adapter = communicator().createObjectAdapter("EventMonitorAdapter");
	System.out.println("WaitingForEventsIce.java: EventMonitorAdapter"+ adapter);
	Ice.Object eventMonitor = new EventsMonitorI(agent); 	

	// Add a Servant for the Ice Object.
	Ice.ObjectPrx proxy = adapter.add(eventMonitor,Ice.Util.stringToIdentity("EventMonitorAdapter")).ice_oneway();
	

	
	IceStorm.TopicPrx topic=null;
	try {
	    topic = topicManager.retrieve("alarms");
	    try{
		topic.subscribeAndGetPublisher(qos, proxy);
	    }
	    catch(IceStorm.AlreadySubscribed ex){
	    }
	    catch(IceStorm.BadQoS ex) {}
		
	}

	catch (IceStorm.NoSuchTopic ex) {
	    try{
		topic = topicManager.create("alarms");
		System.out.println( ": no such topic found, created" );
	    }
	    catch(IceStorm.TopicExists e)
		{
		}
	}

	adapter.activate();
	
	//	shutdownOnInterrupt();
	communicator().waitForShutdown();
	topic.unsubscribe(proxy);
	return 0;
    }    

}
