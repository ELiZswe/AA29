// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIVideoMode.generated.h"

UCLASS()
class UUIVideoMode : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIVideoMode();

	UPROPERTY()										int32					_iState;				//var int _iState;
	UPROPERTY()										bool					_bEdit;					//var bool _bEdit;
	UPROPERTY()										bool					_bShiftDown;			//var bool _bShiftDown;
	UPROPERTY()										bool					_bRefreshed;			//var bool _bRefreshed;
	UPROPERTY()										TArray<FString>			_sStringList;			//var TArray<FString> _sStringList;
	UPROPERTY()										int32					iNumStrings;			//var int iNumStrings;
	UPROPERTY()										int32					_iCurrMode;				//var int _iCurrMode;
	UPROPERTY()										TArray<Ft_VideoMode>	_tVideoModes;			//var array<t_VideoMode> _tVideoModes;
	UPROPERTY()										bool					_bButtonDown2;			//var bool _bButtonDown2;
	UPROPERTY()										UMaterialInstance*		_Texture;				//var Texture _Texture;

	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void AddMode(FString sMode);
	void Refresh();
	void Accept();
	void SetCurrentMode();
	void DumpModes();
	void PrevMode();
	void NextMode();
	void SetTexture(FString Tex);
};
