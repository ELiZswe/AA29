// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "NPCRoadPathNode.generated.h"

UCLASS()
class ANPCRoadPathNode : public ARoadPathNode
{
	GENERATED_BODY()
public:
	ANPCRoadPathNode();

	void DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker);
};
