// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2DraftTeam/UT2DraftTeam.h"
#include "UT2SP_PlayerTradePage.generated.h"

class UGUIButton;

UCLASS()
class AA29_API UUT2SP_PlayerTradePage : public UUT2DraftTeam
{
	GENERATED_BODY()
public:
	UUT2SP_PlayerTradePage();

	UPROPERTY()				FString			MessageTitle;				//var localized FString MessageTitle;
	UPROPERTY()				FString			MessageTradeConfirm;		//var localized FString MessageTradeConfirm;
	UPROPERTY()				FString			MessageTradeInfo;			//var localized FString MessageTradeInfo;
	UPROPERTY()				FString			MessageTradeCancel;			//var localized FString MessageTradeCancel;
	UPROPERTY()				FString			CaptionBack;				//var localized FString CaptionBack;
	UPROPERTY()				FString			MessageTradePicHint;		//var localized FString MessageTradePicHint;
	UPROPERTY()				UGUIButton*		butSwap;					//var GUIButton butSwap;
	UPROPERTY()				FString			TradingPlayerName;			//var FString TradingPlayerName;

	void Created();
	void UpdateDraftable(bool bAffordable);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Initialize(FString PlayerName);
	void BeginConfirm(uint8 bButton);
	void SetPlayer(FString PlayerName);
	bool ButtonClick(UGUIComponent* Sender);
	void SwapConfirm(uint8 bButton);
	void CancelConfirm(uint8 bButton);
	void MyOnChange(UGUIComponent* Sender);
};
