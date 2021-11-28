// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "NPCRestStopPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCRestStopPathNode : public ANPCWaypointPathNode
{
	GENERATED_BODY()
public:
	ANPCRestStopPathNode();

	UPROPERTY(EditAnywhere, Category = "NPCRestStop")				FNPCRestStopAnimSequenceSet npcassNPCAnimationToPerform;	//var(NPCRestStop) NPCRestStopPathNode.NPCRestStopAnimSequenceSet npcassNPCAnimationToPerform;
	UPROPERTY(EditAnywhere, Category = "NPCRestStop")				bool bWaitForResumePatrolTrigger;							//var(NPCRestStop) bool bWaitForResumePatrolTrigger;
	UPROPERTY(EditAnywhere, Category = "NPCRestStop")				bool bShouldCrouch;											//var(NPCRestStop) bool bShouldCrouch;
	UPROPERTY(EditAnywhere, Category = "NPCRestStop")				USoundBase* sndSoundToPlay;									//var(NPCRestStop) Sound sndSoundToPlay;
	UPROPERTY(EditAnywhere, Category = "NPCRestStop")				FName nameAnimationToPerform;								//var(NPCRestStop) name nameAnimationToPerform;
	UPROPERTY(EditAnywhere, Category = "NPCRestStop")				float fpTimeToRest;											//var(NPCRestStop) float fpTimeToRest;
};
