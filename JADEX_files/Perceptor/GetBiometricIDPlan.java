package jadex.examples.MASCS.Perceptor;

import java.util.*;
import jadex.runtime.*;
import jadex.examples.MASCS.*;
import Ice.*;
/**
 *  Stack blocks according to the target configuration.
 */

public class GetBiometricIDPlan	extends Plan
{
    //-------- attributes --------
    
    /** The desired target configuration. */

    
    //-------- constructors --------
    
    /**
     *  Create a new plan.
     */
    public GetBiometricIDPlan()
    {

    }
    
    //-------- methods --------
    
    /**
     *  The plan body.
     */
    public String extractString(String s){
	int index = 0;

	if((index = s.indexOf('{', index))>=0)
	    return s.substring(index+1, s.indexOf('}', index));
	else
	    return s;
    }
    

    public void body()
    {
	// p = (P, A, O, R)
	List P = new ArrayList<List>();
	List p = new ArrayList<List>();
	Planning pa = new Planning();
	P = pa.getPlan(P, "{identification}", "{biometric feature}", "{person identity}");
	System.out.println("Plan completo: "+ P);
	int status = 0;
	Ice.Communicator ic = null;
	   
	try {
	    String[] args = {"./client"};
	    ic = Ice.Util.initialize(args);
	    //Ice.ObjectPrx base = ic.stringToProxy("SimpleDetector:default -p 11000");
	    //We start from the last step upwards
	    int s = P.size()-2;
	    String pr = extractString((String)((List)((P.get(s)))).get(3));
	    Ice.ObjectPrx base = ic.stringToProxy(pr);
	    Face.DetectorPrx detector = Face.DetectorPrxHelper.checkedCast(base);
	    if (detector == null)
		throw new Error("Invalid proxy");
	    detector.faceDetector();
	    s = P.size()-3;
	    pr = extractString((String)((List)((P.get(s)))).get(3));
	    base = ic.stringToProxy(pr);
	    Face.RecognizerPrx recognizer = Face.RecognizerPrxHelper.checkedCast(base);
	    System.out.println("Identity is " +recognizer.faceRecognizer());
	    
	} catch (Ice.LocalException e) {
	    e.printStackTrace();
	    status = 1;
	} catch (Exception e) {
	    System.err.println(e.getMessage());

	    status = 1;
	}
    }
    	
}
