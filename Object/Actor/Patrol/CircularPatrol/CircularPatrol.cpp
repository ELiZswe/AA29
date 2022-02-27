// All the original content belonged to the US Army

#include "AA29/Object/Actor/Patrol/CircularPatrol/CircularPatrol.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"

ACircularPatrol::ACircularPatrol()
{

}

ANavigationPoint* ACircularPatrol::GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot)
{
	/*
	int32 i = 0;
	Log("Patrol:GetNextNode()");
	if (PatrolNodes.Num() == 0)
	{
		return nullptr;
	}
	for (i = 0; i < PatrolNodes.Num(); i++)
	{
		if (PatrolNodes[i] == CurrentNode)
		{
			if ((++i) == PatrolNodes.Num())
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
	Log("Patrol:GetNode():PatrolNodes.Num()=" + FString::FromInt(PatrolNodes.Num()));
	if (PatrolNodes.Num() == 0)
	{
		return nullptr;
	}
	for (i = 0; i < PatrolNodes.Num(); i++)
	{
		Magnitude = int(VSize((Location - PatrolNodes[i].Location)));
		Log("Patrol:GetNode():i=" + FString::FromInt(i));
		Log("Patrol:GetNode():LowMagnitude=" + FString::FromInt(LowMagnitude));
		Log("Patrol:GetNode():Magnitude=" + FString::FromInt(Magnitude));
		if ((NP == nullptr) || (Magnitude < LowMagnitude))
		{
			Log("Patrol:GetNode():SettingMagnitude");
			NP = PatrolNodes[i];
			LowMagnitude = Magnitude;
		}
	}
	Log("Patrol:GetNode():NP=" + FString::FromInt(NP));
	*/
	return NP;
}
