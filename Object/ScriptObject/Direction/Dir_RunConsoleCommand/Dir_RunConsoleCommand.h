// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_RunConsoleCommand.generated.h"

class AHumanController;

UCLASS()
class UDir_RunConsoleCommand : public UDirection
{
	GENERATED_BODY()
public:
	UDir_RunConsoleCommand();

	UPROPERTY()						FString					_sCommand;			//var FString _sCommand;
	UPROPERTY()						AHumanController*		_HumanController;	//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
