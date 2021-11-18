// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AALoginPage/AALoginPage.h"
#include "AAPostLoginPage.generated.h"

class UGUIButton;
class UGUIContentBox;
class UGUIImage;
class UGUILabel;

UCLASS()
class AA29_API UAAPostLoginPage : public UAALoginPage
{
	GENERATED_BODY()
public:
	UAAPostLoginPage();

	UPROPERTY(EditAnywhere)		UGUIButton*			b_Downloads;						//var() automated XInterface.GUIButton b_Downloads;
	UPROPERTY(EditAnywhere)		UGUIButton*			b_ServerBrowser;					//var() automated XInterface.GUIButton b_ServerBrowser;
	UPROPERTY(EditAnywhere)		UGUIButton*			b_MainMenu;							//var() automated XInterface.GUIButton b_MainMenu;
	UPROPERTY(EditAnywhere)		UGUIContentBox*		guicbPanel;							//var() automated GUIContentBox guicbPanel;
	UPROPERTY(EditAnywhere)		UGUIImage*			i_NMLStatusIcon;					//var() automated XInterface.GUIImage i_NMLStatusIcon;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_NMLStatusText;					//var() automated XInterface.GUILabel l_NMLStatusText;
	UPROPERTY()					bool				bOneTimeDisplay;					//var bool bOneTimeDisplay;
	UPROPERTY()					TArray<FString>		asInstantActionPlayerMessage;		//var TArray<FString> asInstantActionPlayerMessage;
	UPROPERTY()					TArray<FString>		asInstantActionWelcomeMessage;		//var TArray<FString> asInstantActionWelcomeMessage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnPreDraw(UCanvas* C);
	void Opened(UGUIComponent* Sender);
	void SetNonExploreTheArmyMode();
	bool ButtonClick(UGUIComponent* Sender);
};
