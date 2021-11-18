// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/LockedFloatingWindow.h"
#include "GUICustomPropertyPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUICustomPropertyPage : public ULockedFloatingWindow
{
	GENERATED_BODY()
public:
	UGUICustomPropertyPage();

	UPROPERTY(EditAnywhere)		UGUIComponent*		Owner;			//var() noexport XInterface.GUIComponent Owner;
	UPROPERTY(EditAnywhere)		FPlayInfoData		Item;			//var() noexport PlayInfo.PlayInfoData Item;

	void SetOwner(UGUIComponent* NewOwner);
	UGUIComponent* GetOwner();
	void SetReadOnly(bool bValue);
	bool GetReadOnly();
	void strip(FString& Source, FString Char);
	bool GrabOption(FString Delim, FString& Options, FString& Result);
	void GetKeyValue(FString Pair, FString& Key, FString& Value);
	FString ParseOption(FString Options, FString Delim, FString InKey);

};
