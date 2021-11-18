// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/ServerBrowserMCList.h"
#include "AABrowser_RulesList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_RulesList : public UServerBrowserMCList
{
	GENERATED_BODY()
public:
	UAABrowser_RulesList();

	UPROPERTY()			bool		bIsLAN;									//var bool bIsLAN;
	UPROPERTY()			FString		OperatingSystemString;					//var localized string OperatingSystemString;
	UPROPERTY()			FString		MILESString;							//var localized string MILESString;
	UPROPERTY()			FString		TournamentString;						//var localized string TournamentString;
	UPROPERTY()			FString		CheatsString;							//var localized string CheatsString;
	UPROPERTY()			FString		MaxHonorString;							//var localized string MaxHonorString;
	UPROPERTY()			FString		MinHonorString;							//var localized string MinHonorString;
	UPROPERTY()			FString		PunkBusterString;						//var localized string PunkBusterString;
	UPROPERTY()			FString		LocaleString;							//var localized string LocaleString;
	UPROPERTY()			FString		HonorString;							//var localized string HonorString;
	UPROPERTY()			FString		OfficialString;							//var localized string OfficialString;
	UPROPERTY()			FString		MissionTimeRemainingString;				//var localized string MissionTimeRemainingString;
	UPROPERTY()			FString		CurrentRoundString;						//var localized string CurrentRoundString;
	UPROPERTY()			FString		AverageHonorString;						//var localized string AverageHonorString;
	UPROPERTY()			FString		PingString;								//var localized string PingString;
	UPROPERTY()			FString		PlayersString;							//var localized string PlayersString;
	UPROPERTY()			FString		TourString;								//var localized string TourString;
	UPROPERTY()			FString		GametypeString;							//var localized string GametypeString;
	UPROPERTY()			FString		MapNameString;							//var localized string MapNameString;
	UPROPERTY()			FString		AddressString;							//var localized string AddressString;
	UPROPERTY()			FString		HostnameString;							//var localized string HostnameString;

	void OnGetServerRules(int32& ItemIndex, FGameSpyServerItem& ServerItem);
	void Clear();
	FString TwoDigitString(int32 Num);
	void FormatTime(int32 Seconds);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	
};
