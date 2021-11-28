// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetPlayerLocation.generated.h"

class AAGP_Location;
class AHumanController;

UCLASS()
class AA29_API UDir_SetPlayerLocation : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetPlayerLocation();

	UPROPERTY()						AAGP_Location*			_Location;				//var AGP_Gameplay.AGP_Location _Location;
	UPROPERTY()						AHumanController*		_HumanController;		//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
