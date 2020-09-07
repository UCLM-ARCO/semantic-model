package jadex.examples.MASCS.Manager;

import jadex.runtime.*;

/**
 *  Plan for starting agents and remembering agent identifiers.
 */
public class StarterPlan extends Plan
{
	/**
	 * The body method is called on the
	 * instatiated plan instance from the scheduler.
	 */
	public void body()
	{
		IGoal start = createGoal("start_agents");
		start.getParameterSet("agentinfos").addValues(getParameterSet("agentinfos").getValues());
		dispatchSubgoalAndWait(start);
		getBeliefbase().getBeliefSet("startedagents").addFacts(start.getParameterSet("agentidentifiers").getValues());
	}
}
