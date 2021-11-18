// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "GUIEditBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIEditBox : public UGUIButton
{
	GENERATED_BODY()
public:
	UGUIEditBox();

	UPROPERTY()										uint8 OriginalConsoleHotKey;					//var byte OriginalConsoleHotKey;
	UPROPERTY(EditAnywhere)							float DelayTime;								//var() float DelayTime;
	UPROPERTY()										uint8 LastKey;									//var byte LastKey;
	UPROPERTY()										bool bAllSelected;								//var bool bAllSelected;
	UPROPERTY()										int32 LastLength;								//var int LastLength;
	UPROPERTY()										int32 LastCaret;								//var int LastCaret;
	UPROPERTY()										int32 LastSizeX;								//var int LastSizeX;
	UPROPERTY()										int32 FirstVis;									//var int FirstVis;
	UPROPERTY()										int32 CaretPos;									//var int CaretPos;
	UPROPERTY(EditAnywhere)							bool bAlwaysNotify;								//var() bool bAlwaysNotify;
	UPROPERTY(EditAnywhere)							bool bReadOnly;									//var() bool bReadOnly;
	UPROPERTY(EditAnywhere)							int32 BorderOffsets;							//var() int BorderOffsets;
	UPROPERTY(EditAnywhere)							ETextCase TextCase;								//var() GUI.eTextCase TextCase;
	UPROPERTY(EditAnywhere)							int32 MaxWidth;									//var() int MaxWidth;
	UPROPERTY(EditAnywhere)							bool bConvertSpaces;							//var() bool bConvertSpaces;
	UPROPERTY(EditAnywhere)							bool bIncludeSign;								//var() bool bIncludeSign;
	UPROPERTY(EditAnywhere)							bool bFloatOnly;								//var() bool bFloatOnly;
	UPROPERTY(EditAnywhere)							bool bIntOnly;									//var() bool bIntOnly;
	UPROPERTY(EditAnywhere)							bool bMaskText;									//var() bool bMaskText;
	UPROPERTY(EditAnywhere)							FString AllowedCharSet;							//var() string AllowedCharSet;
	UPROPERTY(EditAnywhere)							FString TextStr;								//var() string TextStr;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetText(FString NewText);
	void DeleteChar();
	void InternalOnKeyType(uint8 &Key, FString Unicode);
	void InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta);
	void ConvertIllegal(FString inputstr);
	FString GetText();
	void TextChanged();
	void DisableConsoleHotkey();
	void RestoreConsoleHotkey();
	void LoseFocus(UGUIComponent* Sender);
	void Free();
	void InternalActivate();
	void InternalDeactivate();
};
