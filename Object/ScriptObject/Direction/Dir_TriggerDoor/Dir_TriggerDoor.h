// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_TriggerDoor.generated.h"

class ADoorTrigger;

UCLASS()
class AA29_API UDir_TriggerDoor : public UDirection
{
	GENERATED_BODY()
public:
	UDir_TriggerDoor();

	UPROPERTY()						ADoorTrigger*	Door;		//var AGP_Gameplay.DoorTrigger Door;
	UPROPERTY()						FName			DoorTag;	//var FName DoorTag;
	UPROPERTY()						bool			bOpen;		//var bool bOpen;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
