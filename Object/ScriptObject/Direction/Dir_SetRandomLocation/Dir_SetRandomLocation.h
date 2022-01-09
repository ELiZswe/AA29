// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetRandomLocation.generated.h"

class AAGP_LocationList;

UCLASS()
class UDir_SetRandomLocation : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetRandomLocation();

	UPROPERTY()						AAGP_LocationList*	_LocationList;		//var AGP_Gameplay.AGP_LocationList _LocationList;
	UPROPERTY()						AActor*				_Actor;				//var Actor _Actor;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
	void SetLocationList(AAGP_LocationList* LocationList);
	void SetActor(AActor* Actor);
};
