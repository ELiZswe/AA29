// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/KeyBindMenu/KeyBindMenu.h"
#include "ControlBinder.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UControlBinder : public UKeyBindMenu
{
	GENERATED_BODY()
public:
	UControlBinder();

	UPROPERTY(EditAnywhere)			TArray<FString>		BindingLabel;				//var localized FString BindingLabel[150];

	void LoadCommands();
	void MapBindings();
	void LoadCustomBindings();
	void AddCustomBindings(TArray<FKeyInfo> KeyData);
	void ClearBindings();
};
