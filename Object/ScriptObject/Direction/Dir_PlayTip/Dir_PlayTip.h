// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_PlayTip.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_PlayTip : public UDirection
{
	GENERATED_BODY()
public:
	UDir_PlayTip();

	UPROPERTY()						TArray<FString>		_sTip;				//var FString _sTip[2];
	UPROPERTY()						TArray<FString>		_sCmd;				//var FString _sCmd[4];
	UPROPERTY()						float				_fFadeTime;			//var float _fFadeTime;
	UPROPERTY()						AHumanController*	_HumanController;	//var HumanController _HumanController;

	void Destroyed();
	void DirectionStart();
	FString SubstituteNames(FString startstring);
	FString GetCommandKey(FString cmdname);
	bool ProcessParams();
};
