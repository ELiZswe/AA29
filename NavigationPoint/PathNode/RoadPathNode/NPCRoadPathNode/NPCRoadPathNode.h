// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "NPCRoadPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCRoadPathNode : public ARoadPathNode
{
	GENERATED_BODY()
public:
	ANPCRoadPathNode();

	void DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker);
};
