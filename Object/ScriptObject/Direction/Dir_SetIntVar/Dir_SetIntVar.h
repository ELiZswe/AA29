// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetIntVar.generated.h"

class AAGP_IntVar;

UCLASS()
class AA29_API UDir_SetIntVar : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetIntVar();

	UPROPERTY()						EVar					_Operation;		//var Enum EVar  _Operation;
	UPROPERTY()						AAGP_IntVar*			_IntVar;		//var AGP_Gameplay.AGP_IntVar _IntVar;
	UPROPERTY()						int32					_value;			//var int32 _value;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
