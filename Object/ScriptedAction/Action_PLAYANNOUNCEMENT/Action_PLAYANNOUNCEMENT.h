// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_PLAYANNOUNCEMENT.generated.h"

class AAnnouncerVoice;
/**
 * 
 */
UCLASS()
class AA29_API UAction_PLAYANNOUNCEMENT : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_PLAYANNOUNCEMENT();

	UPROPERTY()											bool bSoundsPrecached;					//var bool bSoundsPrecached;
	UPROPERTY(EditAnywhere, Category = "Action")		USoundBase* Sound;						//var(Action) Sound Sound;



	bool InitActionFor(UScriptedController* C);
	FName LastMinuteHack_ShipIt(UScriptedController* C);
	FString GetActionString();
	void PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds);


};
