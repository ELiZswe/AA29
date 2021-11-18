// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Action/ActionFlee/ActionFlee.h"

AActionFlee::AActionFlee()
{

}



float AActionFlee::evaluateAction()
{
	float Weight = 0;
	float Distance = 0;
	float loWeight = 0;
	float Radius = 0;
	float dotProd = 0;
	float penalty = 0;
	float Threat = 0;
	float Eval = 0;
	int32 numNodes;

	Radius = 400;
	numNodes = 0;

	/*
	local PathNode Node;
	local AGP.MentalModel mm;
	local Object.Vector meToHim;
	local Object.Vector meToNode;
	mm = getMentalModel();
	loWeight = my_goal._score + 1;
	ForEach RadiusActors(Class'PathNode', Node, Radius)
	{
		numNodes++;
		meToHim = getEnemy().Location - getPawn().Location;
		meToNode = Node.Location - getPawn().Location;
		Threat = mm.totalThreatAssessment(getPawn(), "notional", Node.Location);
		Distance = VSize(meToNode);
		Distance = FClamp(Distance / 400, 1, 100);
		dotProd = Normal(meToHim) Dot Normal(meToNode);
		if (dotProd > 0)
		{
			penalty = 1 + dotProd * 4;
		}
		else
		{
			penalty = 1;
		}
		Weight = Threat * Distance * penalty;
		if (Weight < loWeight)
		{
			loWeight = Weight;
			goalNode = Node;
		}
	}
	Radius *= 2;
	if (numNodes != 0 || Radius > 16000)
	{
		if (numNodes == 0)
		{
			DebugLog(DEBUG_AI, "dnback:: ActionFlee.evaluationAction(); no pathnodes w/in 1000 feet of current position");
			goalNode = None;
		}
		if (loWeight > my_goal._score)
		{
			Return 0;
		}
		else
		{
			Eval = FClamp(my_goal._score - loWeight, 0, 1);
			Return Eval;
		}
	*/
	return 0;      //FAKE  /EliZ
}
void AActionFlee::executeAction()
{
	//UE_LOG(LogTemp, Warning, TEXT("dnback:: ActionFlee.executeAction(); move target is " $ goalNode));
	//Controller.MoveObject = goalNode;
	//Controller.registerNotification(Self);
	//Controller.Flee();
}
