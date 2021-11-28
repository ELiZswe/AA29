// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_PlayLSAnim.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDir_PlayLSAnim : public UDirection
{
	GENERATED_BODY()
public:
	UDir_PlayLSAnim();

	UPROPERTY()						AActor*		TargetActor;	//var Actor TargetActor;
	UPROPERTY()						FName		ActorTag;		//var FName ActorTag;
	UPROPERTY()						FName		LSAnimation;	//var FName LSAnimation;
	UPROPERTY()						float		LSVOlume;		//var float LSVOlume;
	UPROPERTY()						float		LSRadius;		//var float LSRadius;
	UPROPERTY()						float		LSPitch;		//var float LSPitch;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
