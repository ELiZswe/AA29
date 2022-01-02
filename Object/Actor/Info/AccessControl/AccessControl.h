// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "AccessControl.generated.h"

class AAA2_PlayerState;

UCLASS()
class AAccessControl : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAccessControl();

	UPROPERTY(globalconfig)		int32							iMinBanChangesToUpdate;				//var globalconfig int iMinBanChangesToUpdate;
	UPROPERTY(globalconfig)		FString							sMasterBanListPassword;				//var globalconfig string sMasterBanListPassword;
	UPROPERTY(globalconfig)		FString							sMasterBanListUserName;				//var globalconfig string sMasterBanListUserName;
	UPROPERTY(globalconfig)		bool							bFallbackToBanNameIfNoPBGUID;		//var globalconfig bool bFallbackToBanNameIfNoPBGUID;
	UPROPERTY(globalconfig)		bool							bUpdateMasterBanListViaFTP;			//var globalconfig bool bUpdateMasterBanListViaFTP;
	UPROPERTY(globalconfig)		bool							bUpdateMasterBanList;				//var globalconfig bool bUpdateMasterBanList;
	UPROPERTY(globalconfig)		bool							bUseNewBanListFormat;				//var globalconfig bool bUseNewBanListFormat;
	UPROPERTY(globalconfig)		FString							asTeamPasswords;					//var globalconfig string asTeamPasswords;
	UPROPERTY(globalconfig)		bool							bAllowMaybeFail;					//var globalconfig bool bAllowMaybeFail;
	UPROPERTY(globalconfig)		bool							bDontKickLastPlayer;				//var globalconfig bool bDontKickLastPlayer;
	UPROPERTY()					TArray<FString>					KickReason;							//var array<String> KickReason;
	UPROPERTY()					TArray<APlayerController*>		KickMe;								//var array<PlayerController> KickMe;
	UPROPERTY()					bool							bKickPending;						//var bool bKickPending;
	UPROPERTY()					bool							bDontAddDefaultAdmin;				//var bool bDontAddDefaultAdmin;
	UPROPERTY()					TArray<FPlayerAdminAccounts>	apaaPlayerAdmins;					//var array<PlayerAdminAccounts> apaaPlayerAdmins;
	UPROPERTY(globalconfig)		TArray<FString>					PlayerAdmin;						//var globalconfig array<String> PlayerAdmin;
	UPROPERTY()					TArray<APlayerController*>		AdminClass;							//var class<PlayerController> AdminClass;
	UPROPERTY()					FString							AdminClassName;						//var string AdminClassName;
	UPROPERTY()					TArray<FBanDescription>			BanList;							//var array<BanDescription> BanList;
	UPROPERTY(globalconfig)		FString							BanListFilename;					//var globalconfig string BanListFilename;
	UPROPERTY()					FString							AdminSpaceFilled;					//var localized string AdminSpaceFilled;
	UPROPERTY()					FString							NameBanned;							//var localized string NameBanned;
	UPROPERTY()					FString							NeedPassword;						//var localized string NeedPassword;
	UPROPERTY()					FString							WrongPassword;						//var localized string WrongPassword;
	UPROPERTY()					FString							IPBanned;							//var localized string IPBanned;
	UPROPERTY()					FString							MACBanned;							//var localized string MACBanned;
	UPROPERTY(globalconfig)		FString							IPPolicies;							//var globalconfig string IPPolicies;
	UPROPERTY(globalconfig)		FString							GamePassword;						//var globalconfig string GamePassword;
	UPROPERTY(globalconfig)		FString							AdminPassword;						//var globalconfig string AdminPassword;
		
	void GetFutureTimestamp(int32 weeks_into_the_future, int32 days_into_the_future, int32 hours_into_the_future, int32 minutes_into_the_future, int32 low_word_result, int32 hi_word_result);
	bool CheckTimestampExpired(int32 low_word_part, int32 high_word_part, int32 secs_until);
	void LoadOldBanList();
	void SaveOldBanList();
	void UpdateOldBanList();
	void VerifyUserOldBanList(FString sPlayerName, FString sIP, FString sIPNoPort, FString sMAC, FString sError, FString sFailCode);
	void BanListInitialize();
	void BanListRetrieveUpdate();
	void BanListSubmitUpdates();
	bool BanListCheckPlayerBanStatus(FString sPlayerName, FString sPBGUID);
	int32 BanListQueryPlayerBanStatus(FString sPlayerName, FString sPBGUID);
	void BanListBanPlayer(APlayerController* PCAdmin, FString sPlayerName, FString sPBGUID, int32 iLength, FString sReason);
	void SignalPlayerQualified(APlayerController* PCAdmin, bool bQualified);
	void PreBeginPlay();
	bool ValidatePlayerAdmin(FString sPlayerName, FString sPassword);
	bool IsAdminPasswordValid(FString sPassword);
	void SetAdminPassword(FString p);
	void SetGamePassword(FString p);
	FString GetGamePassword();
	bool RequiresPassword();
	bool AdminLogin(APlayerController* p, FString Password);
	void PreLogin(FString Options, FString Address, FString Error, FString FailCode, bool bSpectator, bool bAdmin);
	bool CheckIPPolicy(FString Address);
	bool Kick(FString S, FString Reason, bool bMaybeFail);
	void SetupKick(APlayerController* PKick, FString Reason);
	void PrintKickMessage(APlayerController* PKick, int32 i);
	int32 GetKickPenalty(FString Reason);
	void DoKick();
	void Timer();
	bool IsPlayerAdmin(AAA2_PlayerState* PRI);
	bool GameNeedsPassword();
	void UpdateBanPolicies();
	bool AddPBGUIDBan(FString sPBGUID, int32 weeks, int32 days, int32 hours, int32 minutes, FString sPlayerName, APlayerController* PCAdmin);
	bool AddBanee(FString banee_descriptor, FString banee_type_name, int32 weeks_to_ban, int32 days_to_ban, int32 hours_to_ban, int32 minutes_to_ban_for, FString banee_owner);
	void CheckBanPolicy(FString PlayerName, FString PlayerIP, FString PlayerMAC, FString Error, FString FailCode);
	void DisplayBanList(APlayerController* PC, int32 iBanStartIndex);
	FString GetBanLength(int32 iBanItem);
	void Unban(APlayerController* PCAdmin, int32 Index);
	bool BanListLoad();
	bool BanListParseLine(FString S);
	EBanType BanTypeNameToBanType(FString banTypeName);
	FString BanTypeToBanTypeName(EBanType BanType);
	void GetDurationOfRemainingBan(int32 remainingBanInSeconds, int32 weeksToBan, int32 daysToBan, int32 hoursToBan, int32 minutesToBan);
	bool BanListSave();
};
