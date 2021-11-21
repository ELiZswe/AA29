// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2MainPage.generated.h"

class UGUITabControl;
class UGUIHeader;
class UGUIFooter;

UCLASS()
class AA29_API UUT2MainPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2MainPage();

	UPROPERTY(EditAnywhere)		UGUITabControl*		c_Tabs;					//var() automated GUITabControl c_Tabs;
	UPROPERTY(EditAnywhere)		UGUIHeader*			t_Header;				//var() automated GUIHeader t_Header;
	UPROPERTY(EditAnywhere)		UGUIFooter*			t_Footer;				//var() automated GUIFooter t_Footer;
	UPROPERTY()					TArray<FString>		PanelClass;				//var TArray<FString> PanelClass;
	UPROPERTY()					TArray<FString>		PanelCaption;			//var localized TArray<FString> PanelCaption;
	UPROPERTY()					TArray<FString>		PanelHint;				//var localized TArray<FString> PanelHint;

	void InitComponent(UGUIController* MyC, UGUIComponent* MyO);
	void InternalOnChange(UGUIComponent* Sender);
};
