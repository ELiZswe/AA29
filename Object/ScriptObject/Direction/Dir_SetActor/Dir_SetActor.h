// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetActor.generated.h"

UCLASS()
class UDir_SetActor : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetActor();

	UPROPERTY()						int32					_iIndex;		//var int32 _iIndex;
	UPROPERTY()						AActor*					_aActor;		//var Actor _aActor;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
