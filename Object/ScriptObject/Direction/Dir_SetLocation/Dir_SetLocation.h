// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetLocation.generated.h"

class AAGP_Location;

UCLASS()
class AA29_API UDir_SetLocation : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetLocation();

	UPROPERTY()						AAGP_Location*	_Location;		//var AGP_Gameplay.AGP_Location _Location;
	UPROPERTY()						AActor*			_Actor;			//var Actor _Actor;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
	void SetLocation(AAGP_Location* Location);
	void SetActor(AActor* Actor);
};
