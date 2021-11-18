// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AdminBase.generated.h"

class AAccessControl;

UCLASS()
class AA29_API UAdminBase : public UObject
{
	GENERATED_BODY()
public:
	UAdminBase();

	UPROPERTY()											FString Msg_EditingMapList;					//var localized string Msg_EditingMapList;
	UPROPERTY()											FString Msg_MapIsNotInRotation;				//var localized string Msg_MapIsNotInRotation;
	UPROPERTY()											FString Msg_MapListRemoved;					//var localized string Msg_MapListRemoved;
	UPROPERTY()											FString Msg_MapListAdded;					//var localized string Msg_MapListAdded;
	UPROPERTY()											FString Msg_ParamNotModified;				//var localized string Msg_ParamNotModified;
	UPROPERTY()											FString Msg_ParamModified;					//var localized string Msg_ParamModified;
	UPROPERTY()											FString Msg_NoParamsFound;					//var localized string Msg_NoParamsFound;
	UPROPERTY()											FString Msg_UnknownParam;					//var localized string Msg_UnknownParam;
	UPROPERTY()											FString Msg_MapNotInRotation;				//var localized string Msg_MapNotInRotation;
	UPROPERTY()											FString Msg_MapIsInRotation;				//var localized string Msg_MapIsInRotation;
	UPROPERTY()											FString Msg_NoMapsFound;					//var localized string Msg_NoMapsFound;
	UPROPERTY()											FString Msg_NoMapInRotation;				//var localized string Msg_NoMapInRotation;
	UPROPERTY()											FString Msg_ChangingMapTo;					//var localized string Msg_ChangingMapTo;
	UPROPERTY()											FString Msg_NextMapNotFound;				//var localized string Msg_NextMapNotFound;
	UPROPERTY()											FString Msg_PlayerKicked;					//var localized string Msg_PlayerKicked;
	UPROPERTY()											FString Msg_SessionBanned;					//var localized string Msg_SessionBanned;
	UPROPERTY()											FString Msg_PlayerBanned;					//var localized string Msg_PlayerBanned;
	UPROPERTY()											FString Msg_RemovedFromList;				//var localized string Msg_RemovedFromList;
	UPROPERTY()											FString Msg_NoMapsRemoved;					//var localized string Msg_NoMapsRemoved;
	UPROPERTY()											FString Msg_AddedMapToList;					//var localized string Msg_AddedMapToList;
	UPROPERTY()											FString Msg_NoMapsAdded;					//var localized string Msg_NoMapsAdded;
	UPROPERTY()											FString Msg_MapRotationList;				//var localized string Msg_MapRotationList;
	UPROPERTY()											FString Msg_AllMapLists;					//var localized string Msg_AllMapLists;
	UPROPERTY()											FString Msg_AllGameMaps;					//var localized string Msg_AllGameMaps;
	UPROPERTY()											FString Msg_PlayerList;						//var localized string Msg_PlayerList;
	UPROPERTY()											AAccessControl* Training;					//var AccessControl Manager;
	UPROPERTY()											bool bAdmin;								//var bool bAdmin;

	void Created();
	void DoLogin(FString UserName, FString Password);
	void DoLogout();
	void DoSwitch(FString URL);
	void GoToNextMap();
	void ShowCurrentMapList();
	void GetMapListNames(FString aGameType);
	void MaplistCommand(FString Cmd, FString Extra);
	void RestartCurrentMap();
	void PlayerList();
	void Kick(FString Cmd, FString Extra);
	void KickBan(FString S);
	void RestartMap();
	void NextMap();
	void Map(FString Cmd);
	void MapList(FString Cmd, FString Extra);
	void Switch(FString URL);
	bool CanPerform(FString priv);
	void FindGameType(FString aGameType);
	void SendComplexMsg(TArray<FString> Arr, FString Title);
	void MaskedCompare(FString SettingName, FString Mask);
	void IsNumeric(FString Param, bool bPositiveOnly);
	void SplitParams(FString Params);
};
