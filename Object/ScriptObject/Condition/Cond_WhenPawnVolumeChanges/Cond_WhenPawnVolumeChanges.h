// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenPawnVolumeChanges.generated.h"

class AAGP_Pawn;

UCLASS()
class AA29_API UCond_WhenPawnVolumeChanges : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenPawnVolumeChanges();

	UPROPERTY()										bool bWasInVolume;					//var bool bWasInVolume;
	UPROPERTY()										bool _bEntry;						//var bool _bEntry;
	UPROPERTY()										FName _VolumeTag;					//var name _VolumeTag;
	UPROPERTY()										AAGP_Pawn* _Pawn;					//var AGP.AGP_Pawn _Pawn;
	UPROPERTY()										AActor* _Actor;						//var Actor _Actor;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
	void SetActor(AActor* Actor);
	void SetVolumeTag(FName voltag);
	void SetVolumeNotifyOnEntry(bool Entry);
	void update();
};
