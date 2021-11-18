// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_PLAYAMBIENTSOUND.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_PLAYAMBIENTSOUND : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_PLAYAMBIENTSOUND();

	UPROPERTY(EditAnywhere, Category = "Action")		float SoundRadius;						//var(Action) float SoundRadius;
	UPROPERTY(EditAnywhere, Category = "Action")		uint8 SoundPitch;						//var(Action) byte SoundPitch;
	UPROPERTY(EditAnywhere, Category = "Action")		uint8 SoundVolume;						//var(Action) byte SoundVolume;
	UPROPERTY(EditAnywhere, Category = "Action")		USoundBase* AmbientSound;				//var(Action) Sound AmbientSound;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
