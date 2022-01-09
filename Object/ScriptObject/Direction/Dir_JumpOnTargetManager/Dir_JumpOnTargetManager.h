// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_JumpOnTargetManager.generated.h"

class ATargetManager;

UCLASS()
class UDir_JumpOnTargetManager : public UDirection
{
	GENERATED_BODY()
public:
	UDir_JumpOnTargetManager();

	UPROPERTY()						ATargetManager*		_TargetManager;		//var AGP_Gameplay.TargetManager _TargetManager;
	UPROPERTY()						int32				_Min;				//var int32 _Min;
	UPROPERTY()						int32				_Max;				//var int32 _Max;
	UPROPERTY()						FName				_JumpScene;			//var FName _JumpScene;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
