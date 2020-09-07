package jadex.examples.MASCS.Perceptor;
import java.lang.String;
import java.util.*;


public class Planning
{
    static final String server = "localhost";
    static final int port=5000;

    public List getPlan(List P, String A, String O, String R){
	
	List E = new ArrayList();
	List Ob = new ArrayList();
	List p =  new ArrayList<String>();
	//Query to retrieve the device that performs the action A
	String query = "(x-is-the-y-of-what? "+A+"  {performs-action})";
	String answer, e=A, o=O;
	boolean found = false;
	String device = sendToScone(query);
	if(device.equals("NIL")){ //non-doable action
	    query =  "(list-events-causing-x (new-statement "+O+" (car (list-parents(car (list-after "+A+")))) "+R+"))\n";
	    E = getListFrom(sendToScone(query));
	    ListIterator e_i = E.listIterator();
	    while(e_i.hasNext() && !found){
		e = (String)(e_i.next());
		query =  "(x-is-the-y-of-what? "+e+"  {performs-action})\n";
		if((sendToScone(query)).equals("NIL"))
		    e_i.remove();
		else{
		    //Now, lets check which of these actions are
		    //intended to be performed over an object
		    //equivalent to the object in plan O
		    query = "(list-all-x-of-y {object-of} "+e+")\n"; 
		    Ob = getListFrom(sendToScone(query));
		    ListIterator o_i = Ob.listIterator();
		    while(o_i.hasNext() && !found){
			o = (String)(o_i.next()); 
			query = "(can-x-be-a-y? "+o+" "+O+")\n";
			if((sendToScone(query)).equals("T"))
			    found = true;
		    }			
		}
	    }

	    query = "(b-wire (car (list-after "+e+")))"; //IMPORTANT: B-wire of the first statement of the after context is the result
	    getPlan(P, e, o, sendToScone(query));

	}
	else{ //A is a doable action
	    System.out.println("The device is: "+ device);
	    query = "(list-events-preceding"+A+")";
	    E = getListFrom(sendToScone(query));
	    if(E.size() ==0){
		query = "(b-wire (car (list-after "+A+")))";
		p.add(A);
		p.add("{thing}");
		p.add(sendToScone(query));	
		p.add(device);
		P.add(p);
	    }
	    else{
		ListIterator e_i = E.listIterator();
		while(e_i.hasNext()&& !found){
		    e = (String)(e_i.next());
		    query = "(is-x-a-y? "+e+"{action})";
		    if((sendToScone(query)).equals("T")){
			//we get the object-of action and the result
			query = "(list-all-x-of-y {object-of} "+e+")\n"; 
			Ob = getListFrom(sendToScone(query));
			ListIterator o_i = Ob.listIterator();
			while(o_i.hasNext() && !found){
			    o = (String)(o_i.next()); 
			    query = "(can-x-be-a-y? "+o+" "+O+")\n";
			    if((sendToScone(query)).equals("T"))
				found = true;
			}	
		    }
		}
		query = "(b-wire (car (list-after "+A+")))"; //IMPORTANT: B-wire of the first statement of the after context is the result
		p.add(A);
		p.add(o);
		p.add(sendToScone(query));
		p.add(device);
		P.add(p);
		getPlan(P, e, o, sendToScone(query));
	    }
	  	   	
	}
	

	return P;
    }
	 

    public String sendToScone(String query){
	String result = "nil";
	try{
	    SconeClientXML sc = new SconeClientXML(server, port);
	    try{
		 result = sc.evalLisp(query);
		System.out.println(result);
	    }catch(Exception e){
		System.out.println(e);
	    }
	    sc.close();
	}catch(Exception e){
	    System.out.println(e);
	}
	return result;
    }

    public List getListFrom(String answer){
	List result = new ArrayList();
	int index = 0;
	while((index = answer.indexOf('{', index))>0){
	    result.add(answer.substring(index, answer.indexOf('}', index)+1));
	    answer = answer.substring(answer.indexOf('}', index)+1);
	}
	return result;
    }
}
       
   
