// All the original content belonged to the US Army


#include "AA29/Object/Actor/Patrol/CircularPatrol/CircularPatrol.h"

ACircularPatrol::ACircularPatrol()
{

}

ANavigationPoint* ACircularPatrol::GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot)
{
	/*
	int32 i = 0;
	Log("Patrol:GetNextNode()");
	if (PatrolNodes.Length == 0)
	{
		return None;
	}
	for (i = 0; i < PatrolNodes.Length; i++)
	{
		if (PatrolNodes[i] == CurrentNode)
		{
			if ((++i) == PatrolNodes.Length)
			{
				i = 0;
			}
			return PatrolNodes[i];
		}
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

ANavigationPoint* ACircularPatrol::GetNode(FVector Location, APawn* Bot)
{
	ANavigationPoint* NP = nullptr;
	/*
	int32 i = 0;
	int32 LowMagnitude = 0;
	int32 Magnitude = 0;
	Log("Patrol:GetNode()");
	LowMagnitude = -2147483648;
	Log("Patrol:GetNode():PatrolNodes.Length=" $ string(PatrolNodes.Length));
	if (PatrolNodes.Length == 0)
	{
		return None;
	}
	for (i = 0; i < PatrolNodes.Length; i++)
	{
		Magnitude = int(VSize((Location - PatrolNodes[i].Location)));
		Log("Patrol:GetNode():i=" $ string(i));
		Log("Patrol:GetNode():LowMagnitude=" $ string(LowMagnitude));
		Log("Patrol:GetNode():Magnitude=" $ string(Magnitude));
		if ((NP == None) || (Magnitude < LowMagnitude))
		{
			Log("Patrol:GetNode():SettingMagnitude");
			NP = PatrolNodes[i];
			LowMagnitude = Magnitude;
		}
	}
	Log("Patrol:GetNode():NP=" $ string(NP));
	*/
	return NP;
}