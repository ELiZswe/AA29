// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "ServerBrowser.generated.h"

class UBrowser_Page;

UCLASS(Config = Game)
class AA29_API UServerBrowser : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UServerBrowser();

	UPROPERTY()				UBrowser_Page*	MOTDPage;					//var Browser_Page MOTDPage;
	UPROPERTY()				UBrowser_Page*	DMServerListPage;			//var Browser_Page DMServerListPage;
	UPROPERTY()				UBrowser_Page*	TDMServerListPage;			//var Browser_Page TDMServerListPage;
	UPROPERTY()				UBrowser_Page*	CTFServerListPage;			//var Browser_Page CTFServerListPage;
	UPROPERTY()				UBrowser_Page*	BRServerListPage;			//var Browser_Page BRServerListPage;
	UPROPERTY()				UBrowser_Page*	DomServerListPage;			//var Browser_Page DomServerListPage;
	UPROPERTY()				UBrowser_Page*	CustomServerListPage;		//var Browser_Page CustomServerListPage;
	UPROPERTY()				UBrowser_Page*	FavoritesPage;				//var Browser_Page FavoritesPage;
	UPROPERTY()				UBrowser_Page*	LANPage;					//var Browser_Page LANPage;
	UPROPERTY()				UBrowser_Page*	PrefsPage;					//var Browser_Page PrefsPage;
	UPROPERTY()				UBrowser_Page*	BuddiesPage;				//var Browser_Page BuddiesPage;
	UPROPERTY()				UBrowser_Page*	IRCPage;					//var Browser_Page IRCPage;
	UPROPERTY()				bool			bCreatedQueryTabs;			//var bool bCreatedQueryTabs;
	UPROPERTY()				bool			bCreatedStandardTabs;		//var bool bCreatedStandardTabs;
	UPROPERTY()				FString			MutantTypeName;				//var localized FString MutantTypeName;
	UPROPERTY()				FString			InvasionTypeName;			//var localized FString InvasionTypeName;
	UPROPERTY()				FString			LMSTypeName;				//var localized FString LMSTypeName;
	UPROPERTY()				FString			MutantType;					//var localized FString MutantType;
	UPROPERTY()				FString			InvasionType;				//var localized FString InvasionType;
	UPROPERTY()				FString			LMSType;					//var localized FString LMSType;
	UPROPERTY(config)		bool			bOnlyShowStandard;			//var() config bool bOnlyShowStandard;
	UPROPERTY(config)		bool			bOnlyShowNonPassword;		//var() config bool bOnlyShowNonPassword;
	UPROPERTY(config)		bool			bDontShowFull;				//var() config bool bDontShowFull;
	UPROPERTY(config)		bool			bDontShowEmpty;				//var() config bool bDontShowEmpty;
	UPROPERTY(config)		bool			bDontShowWithBots;			//var() config bool bDontShowWithBots;
	UPROPERTY(config)		FString			DesiredMutator;				//var() config FString DesiredMutator;
	UPROPERTY(config)		FString			DesiredMutator2;			//var() config FString DesiredMutator2;
	UPROPERTY(config)		FString			CustomQuery;				//var() config FString CustomQuery;
	UPROPERTY(config)		int32			MinGamespeed;				//var() config int32 MinGamespeed;
	UPROPERTY(config)		int32			MyNMaxGamespeedewNick;		//var() config int32 MaxGamespeed;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool HaveBonusPack();
	bool HaveCustomGameTypes();
	void MOTDVerified(bool bMSVerified);
	void AddBrowserPage(UBrowser_Page* NewPage);
	void OnAddFavorite(FServerResponseLine Server);
	void InternalOnClose(bool bCanceled);
};
