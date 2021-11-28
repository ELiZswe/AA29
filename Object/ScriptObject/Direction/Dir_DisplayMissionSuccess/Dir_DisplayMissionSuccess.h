// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_DisplayMissionSuccess.generated.h"

class AHumanController;

UCLASS()
class AA29_API UDir_DisplayMissionSuccess : public UDirection
{
	GENERATED_BODY()
public:
	UDir_DisplayMissionSuccess();

	UPROPERTY()						AHumanController*		_HumanController;			//var HumanController _HumanController;
	UPROPERTY()						FString					_sTexture;					//var FString _sTexture;
	UPROPERTY()						FString					_szText;					//var FString _szText;
	UPROPERTY()						FString					_szText2;					//var FString _szText2;
	UPROPERTY()						int32					_iUSize;					//var int32 _iUSize;
	UPROPERTY()						int32					_iVSize;					//var int32 _iVSize;
	UPROPERTY()						int32					_iRenderStyle;				//var int32 _iRenderStyle;
	UPROPERTY()						FName					_nReplayScene;				//var FName _nReplayScene;

	void Destroyed();
	void DirectionStart();
	bool ProcessParams();
};
