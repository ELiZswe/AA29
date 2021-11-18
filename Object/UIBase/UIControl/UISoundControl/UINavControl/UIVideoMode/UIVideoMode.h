// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIVideoMode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIVideoMode : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIVideoMode();

	UPROPERTY()										UMaterialInstance* _Texture;					//var Texture _Texture;
	UPROPERTY()										bool _bButtonDown2;								//var bool _bButtonDown2;
	UPROPERTY()										TArray<Ft_VideoMode> _tVideoModes;				//var array<t_VideoMode> _tVideoModes;
	UPROPERTY()										int32 _iCurrMode;								//var int _iCurrMode;
	UPROPERTY()										int32 iNumStrings;								//var int iNumStrings;
	UPROPERTY()										TArray<FString> _sStringList;					//var array<String> _sStringList;
	UPROPERTY()										bool _bRefreshed;								//var bool _bRefreshed;
	UPROPERTY()										bool _bShiftDown;								//var bool _bShiftDown;
	UPROPERTY()										bool _bEdit;									//var bool _bEdit;
	UPROPERTY()										int32 _iState;									//var int _iState;
};
