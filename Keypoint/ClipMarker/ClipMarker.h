// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Keypoint.h"
#include "ClipMarker.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClipMarker : public AKeypoint
{
	GENERATED_BODY()
public:
	AClipMarker(const FObjectInitializer& objectInitializer);

	//Texture = Texture'Engine.S_ClipMarker';
	//bEdShouldSnap = true;
};
