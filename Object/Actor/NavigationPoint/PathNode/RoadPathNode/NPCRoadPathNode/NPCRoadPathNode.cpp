// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/NPCRoadPathNode.h"

ANPCRoadPathNode::ANPCRoadPathNode()
{

}

void ANPCRoadPathNode::DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker)
{
	/*
	if (dnpcnDebugNavigationMarker == nullptr)
	{
		if (!bShowMarker)
		{
			return;
		}
		dnpcnDebugNavigationMarker = Spawn('DebugNPCNavigation');
		dnpcnDebugNavigationMarker->HUDText = Self $ "." $ Tag;
	}
	if (dnpcnDebugNavigationMarker != nullptr)
	{
		dnpcnDebugNavigationMarker->SetLocation(Location);
		dnpcnDebugNavigationMarker->bHidden = !bShowMarker;
		if (bShowMarker)
		{
			if (bFinalGoalMarker)
			{
				dnpcnDebugNavigationMarker->SetDrawScale3D(FVector(0.15 0.15 0.15));
				dnpcnDebugNavigationMarker->RotationRate.Yaw = 16384;
			}
			else
			{
				dnpcnDebugNavigationMarker->SetDrawScale3D(FVector(0.075 0.075 0.075));
				dnpcnDebugNavigationMarker->RotationRate.Yaw = 4096;
			}
		}
	}
	*/
}
