// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_JumpOnIntVar.generated.h"

class AAGP_IntVar;

UCLASS()
class UDir_JumpOnIntVar : public UDirection
{
	GENERATED_BODY()
public:
	UDir_JumpOnIntVar();

	UPROPERTY()						AAGP_IntVar*		_IntVar;					//var AGP_Gameplay.AGP_IntVar _IntVar;
	UPROPERTY()						int32				_Min;						//var int32 _Min;
	UPROPERTY()						int32				_Max;						//var int32 _Max;
	UPROPERTY()						FName				_JumpScene;					//var FName _JumpScene;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
