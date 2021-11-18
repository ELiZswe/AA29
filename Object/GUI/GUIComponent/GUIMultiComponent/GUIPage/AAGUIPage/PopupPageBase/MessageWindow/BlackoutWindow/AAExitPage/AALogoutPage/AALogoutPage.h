// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAExitPage/AAExitPage.h"
#include "AALogoutPage.generated.h"

class GUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAALogoutPage : public UAAExitPage
{
	GENERATED_BODY()
public:
	UAALogoutPage();

	UPROPERTY(EditAnywhere)		UGUIButton* LogoutButton;			//var() automated XInterface.GUIButton LogoutButton;
	UPROPERTY(EditAnywhere)		UGUILabel* LogoutDesc;				//var() automated XInterface.GUILabel LogoutDesc;
	UPROPERTY()					FString LoginText;					//var localized FString LoginText;
	UPROPERTY()					FString LogoutText;					//var localized FString LogoutText;
	UPROPERTY()					FString LoginDescriptionText;		//var localized FString LoginDescriptionText;
	UPROPERTY()					FString LogoutDescriptionText;		//var localized FString LogoutDescriptionText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};

