// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "Browser_RulesList.generated.h"

class UBrowser_ServersList;
class UBrowser_ServerListPageBase;

UCLASS()
class UBrowser_RulesList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UBrowser_RulesList();

	UPROPERTY()			FString							WeaponStayString;				//var localized string WeaponStayString;
	UPROPERTY()			FString							TranslocatorString;				//var localized string TranslocatorString;
	UPROPERTY()			FString							MinPlayersString;				//var localized string MinPlayersString;
	UPROPERTY()			FString							TimeLimitString;				//var localized string TimeLimitString;
	UPROPERTY()			FString							GoalScoreString;				//var localized string GoalScoreString;
	UPROPERTY()			FString							FriendlyFireString;				//var localized string FriendlyFireString;
	UPROPERTY()			FString							PlayersBalanceTeamsString;		//var localized string PlayersBalanceTeamsString;
	UPROPERTY()			FString							BalanceTeamsString;				//var localized string BalanceTeamsString;
	UPROPERTY()			FString							MutatorString;					//var localized string MutatorString;
	UPROPERTY()			FString							GameSpeedString;				//var localized string GameSpeedString;
	UPROPERTY()			FString							GameStatsString;				//var localized string GameStatsString;
	UPROPERTY()			FString							PasswordString;					//var localized string PasswordString;
	UPROPERTY()			FString							AdminEmailString;				//var localized string AdminEmailString;
	UPROPERTY()			FString							AdminNameString;				//var localized string AdminNameString;
	UPROPERTY()			FString							NonDedicatedString;				//var localized string NonDedicatedString;
	UPROPERTY()			FString							DedicatedString;				//var localized string DedicatedString;
	UPROPERTY()			FString							ServerModeString;				//var localized string ServerModeString;
	UPROPERTY()			FString							FalseString;					//var localized string FalseString;
	UPROPERTY()			FString							TrueString;						//var localized string TrueString;
	UPROPERTY()			int32							listitem;						//var int listitem;
	UPROPERTY()			UBrowser_ServersList*			MyServersList;					//var Browser_ServersList MyServersList;
	UPROPERTY()			UBrowser_ServerListPageBase*	MyPage;							//var Browser_ServerListPageBase MyPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	FString LocalizeRules(FString Code);
};
