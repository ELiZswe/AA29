// All the original content belonged to the US Army

#include "HumanController.h"
#include "Containers/UnrealString.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/AI_Primitive/SoldierClass/SoldierClass.h"

#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/CallForSupport/CallForSupport.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Inventory/Weapon/Weapon.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"

#include "Engine/World.h"
#include "AA29/AA2_GameState.h"
#include "AA29/AA2_GameMode.h"
#include "AA29/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/BodyPanel/BodyPanel.h"

#include "AA29/Object/Actor/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"
#include "AA29/CommunicationRequestAdapter/MissionCompleteRequestAdapter/MissionCompleteRequestAdapter.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

#include "GameFramework/PlayerController.h"

#include "AA29/AI_Primitive/SoldierClass/ClassRifleman/ClassRifleman.h"

AHumanController::AHumanController()
{
	
	bAutoSwapFromGrenade				= true;
	bAutoWalkZoom						= true;
	bUseOverlayScopes					= true;
	_tPainOverlay						= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/fx_overlays_pain.fx_overlays_pain"), NULL, LOAD_None, NULL),
	BoundaryEvent						= "Boundary";
	AutoTraceFrequency					= 3;
	//DesiredTeamClassName				= "AGP_Characters.ClassRifleman"
	DesiredTeamClassName				= "ClassRifleman";
	FlashBangDistortion					= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisoriented.WeaponsUS_Grenades_TTSDisoriented"), NULL, LOAD_None, NULL),
	FlashBangDistortionFade				= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisorientedFade.WeaponsUS_Grenades_TTSDisorientedFade"), NULL, LOAD_None, NULL),
	GrenadeDistortion					= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisoriented.WeaponsUS_Grenades_TTSDisoriented"), NULL, LOAD_None, NULL),
	GrenadeDistortionFade				= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisorientedFade.WeaponsUS_Grenades_TTSDisorientedFade"), NULL, LOAD_None, NULL),
	ScopeDetail							= EScopeDetail::SCOPEDETAIL_Low;
	sSavedUserName						= "UserName";
	sSavedUserPassword					= "UserPassword";
	bDontRememberUsernameAndPassword	= true;
	NeedUserPassword					= "You must enter a password for this username";
	WrongUserPassword					= "The password is incorrect for this username";
	NoUserRecord						= "The username you have entered has not been registered.";
	UserIsBanned						= "Sorry, you have been banned from this server";
	ResponseTimeOut						= "Communication Error: Please try again.";
	ServerNotRegistered					= "This server is not registered as an authorized server";
	BetaServer							= "You are not authorized to play on this beta server";
	BadHonorUpdateValue					= "Could not update your honor rating.";
	fMsgDuration						= 10;
	HUDAlpha							= 200;
	HUDColor							= 100;
	bWaitingForPRI						= true;
	bWaitingForVRI						= true;
	RadarZoom							= 2;
	bRadarShowPlayerInfoNames			= true;
	bRadarShowPlayerInfoElevation		= true;
	NoSuicideVelocity					= 50;
	iSpotterPolarRangeSetting			= 600;
	sndESSFoundItemAcknowledgement		= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2AcknowledgeFoundItem.S2AcknowledgeFoundItem"), NULL, LOAD_None, NULL),
	bShowDelayedStartWarningMessage		= true;

	//CheatClass = class'AGP.Cheater'
	//bHumanAim = true;
	//MinHitWall = -0.5;
	//CollisionRadius = 10;
	//CollisionHeight = 10;
	//bNetNotify = true;


	WM_Slot.SetNum(6);


}


// Called when the game starts or when spawned
void AHumanController::BeginPlay()
{
	Super::BeginPlay();

	bPlayerIsReadyToPlay = true;
	if (DesiredTeamClass == nullptr)
	{
		//	DesiredTeamClass = class<SoldierClass>(DynamicLoadObject(DesiredTeamClassName, Class'Class'));
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			DesiredTeamClass = World->SpawnActor<ASoldierClass>(ASoldierClass::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			DesiredTeamClassName = DesiredTeamClass->GetName();
		}
	}


	//if (PlayerReplicationInfo != nullptr)
	//{
	//	PlayerReplicationInfo.sCurrentWeaponClass = "" $ DesiredTeamClass;
	//}
	SetHUDAlpha(HUDAlpha);
	SetHUDColor(HUDColor);
	SetHUDCrosshair(HUDCrosshair);



	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings();
		MyGameSettings->SetScreenResolution(FIntPoint(3840, 2160));
		MyGameSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		MyGameSettings->SetVSyncEnabled(true);
		MyGameSettings->ApplySettings(false);
	}



	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SetWeaponMods();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Max() > 0)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[0]);
	}

	ClientMessage("Test ClientMessage");

	//SaveConfig();

}


void AHumanController::RequestChangeTeam(int32 N)
{
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		PlayerReplicationInfo->DesiredTeam = N;
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && N == 1)
		{
			N = 0;
		}
		Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->RequestChangeTeam(this, N);
	}
}

void AHumanController::DumpServerStats()
{
}

void AHumanController::DumpServerDynamicActors()
{
}

void AHumanController::CheckOutOfBounds()
{
}

void AHumanController::InduceFailure()
{
}

void AHumanController::ResetRend()
{
}

void AHumanController::PostNetBeginPlay()
{
}

void AHumanController::EntryLevelSimulatedScreenplay()
{
}

void AHumanController::ChangeUserName(FString S)
{
	return;
}
void AHumanController::ObfuscatePassword(FString Password)
{
}

void AHumanController::DeobfuscatePassword(FString Password)
{
}

void AHumanController::RestoreSavedUserNameAndPassword()
{
	
	FString DeobfuscatedPassword;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		return;
	}
	/*
	if (DeobfuscatePassword(DeobfuscatedPassword))
	{
		Log(this $ ".RestoreSavedUserNameAndPassword() Restoring user name & password from saved file ");
		UserName = 'HumanController'.Default.sSavedUserName;
		'HumanController'.Default.UserName = StripBadCodes('HumanController'.Default.sSavedUserName);
		'HumanController'.Default.sSavedUserName = StripBadCodes('HumanController'.Default.sSavedUserName);
		UserPassword = DeobfuscatedPassword;
		'HumanController'.Default.UserPassword = DeobfuscatedPassword;
	}
	*/
}
void AHumanController::ServerCheckServerAuthAndPBMode()
{
	if (IsPBEnabled() == 0)
	{
		//GotoState('ServerAuthorizePlayer');
	}
	//ClientSetAuthMode(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer(), Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization(), IsPBEnabled());
}
void AHumanController::ClientSetAuthMode(bool bAuthorizedServer, bool bRequiresAuthorization, int32 aiPBEnabled)
{
	bIsAuthorizedServer = bAuthorizedServer;
	bServerRequiresAuthorization = bRequiresAuthorization;
	if (aiPBEnabled == 1)
	{
		//GotoState('ValidatePB');
	}
	else
	{
		bPBChecked = true;
		//GotoState('ServerAuthorizePlayer');
	}
}

void AHumanController::ClientSetAccessControlKickMessage(FString sMessage)
{
	sKickReason = sMessage;
	//ClientCloseMenu(true);
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessageLong(4, sMessage);
	}
}
void AHumanController::ClientForceGamePlayMode(EGameplayModes newmode)
{
	if (GetMilesOnly())
	{
		if (newmode != EGameplayModes::GM_MILES)
		{
			//ClientOpenMap("entry");
		}
	}
	Cast<AAA2_WorldSettings>(GetWorldSettings())->GamePlayMode = newmode;
}
void AHumanController::ClientSetServerFlags(bool bCheat, bool bDev, bool bBeta, bool bLeased, bool bOfficial, bool bNATO, bool bTournament, bool bUltimateArena, bool bIsAuthorized, bool bRequiresAuthorization, bool bPlayersOnly, bool bFirstPerson, bool bBodies, bool bAllowLocalScores, bool bIsExploreTheArmyServer, bool bAllowForceclassing)
{
	bCheatServer = bCheat;
	bDevMode = bDev;
	bBetaServer = bBeta;
	bLeasedServer = bLeased;
	bOfficialServer = bOfficial;
	bUnofficialServer = !bOfficial;
	bNATOServer = bNATO;
	bTournamentServer = bTournament;
	bUltimateArenaServer = bUltimateArena;
	bIsAuthorizedServer = bIsAuthorized;
	bServerRequiresAuthorization = bRequiresAuthorization;
	bSpectatePlayersOnly = bPlayersOnly;
	bSpectateFirstPersonOnly = bFirstPerson;
	bSpectateBodies = bBodies;
	bAllowScoreShown = bAllowLocalScores;
	bExploreTheArmyServer = bIsExploreTheArmyServer;
	SetDevMode(false);
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer, bDevMode, bBetaServer, bLeasedServer, bOfficialServer, bNATOServer, bTournamentServer, bUltimateArenaServer, bIsAuthorizedServer, bExploreTheArmyServer, bAllowForceclassing);
	}
}
void AHumanController::SetDevMode(bool bNewDevMode)
{
}
void AHumanController::DevMode(bool bSet)
{
	/*
	if (Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().NotifyCheated();
	}
	*/
	if (GetNetMode() == ENetMode::NM_Standalone || bDevMode)
	{
		SetDevMode(bSet);
	}
}
void AHumanController::HideSmoke(bool bDisableRendering)
{
	/*
	local SpriteEmitter seIterator;
	ForEach(Class'SpriteEmitter', seIterator)
	{
		if (seIterator.bCanJavelinSeeThrough)
		{
			seIterator.bDisableRendering = bDisableRendering;
		}
	}
	*/
}

void AHumanController::ServerRequestAuthorization(FString InUserName, FString InEncryptedPassword, FString sLANPlayerName)
{
	
	UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerRequestAuthorization( %s)"), *InUserName);
	InUserName = PlayerReplicationInfo->PlayerName;
	if (bReceivedAuthRequest)
	{
		//ServerSay("Player attempting to re-authorize kicked by the server.", 'AdminSay');
		UE_LOG(LogTemp, Log, TEXT("Invalid user attempt to re-authorize"));
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}
	if (InUserName.Len() == 0 && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		//ServerSay("Player with invalid name kicked by the server.", 'AdminSay');
		UE_LOG(LogTemp, Log, TEXT("Invalid User Name for auth request"));
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}

	//bAuthDisabledForAccount = !Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization();
	
	if (Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		if (!PlayerReplicationInfo->bAdmin || !PlayerReplicationInfo->bOnlySpectator || TournamentIsTournament())
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
			{
				if ((Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyAccount(this, InUserName, true)).Len() > 0)
				{
					//AnnounceNewPlayerJoiningServer(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyAccount(this, InUserName, true) $ " is awaiting account authorization to play.");
				}
				else
				{
					//AnnounceNewPlayerJoiningServer( TEXT("%s is awaiting account authorization to play."), *InUserName);
				}
			}
			else
			{
				//AnnounceNewPlayerJoiningServer(TEXT("%s is awaiting account authorization to play."), *UserName);
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerRequestAuthorization - starting auth process for player"));
		EncryptedPassword = InEncryptedPassword;
		ReceivedAuthRequest();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerRequestAuthorization - unauthorized server - setting player as qualified for all"));
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo->bQualifiedSniper = true;
			PlayerReplicationInfo->bQualifiedAirborne = true;
			PlayerReplicationInfo->bQualifiedRanger = true;
			PlayerReplicationInfo->bQualifiedMedic = true;
			PlayerReplicationInfo->bQualifiedSF = true;
			PlayerReplicationInfo->bQualifiedJavelin = true;
			PlayerReplicationInfo->bQualifiedDriveHMMWV = true;
			PlayerReplicationInfo->bQualifiedUseCROWS = true;
			PlayerReplicationInfo->bQualifiedES2 = true;
		}
		if (PlayerReplicationInfo->bAdmin && PlayerReplicationInfo->bOnlySpectator)
		{
		}
		//Level.Game.Broadcast(Level.Game, UserName $ " is joining the server.");
		//LogFileWrite("DevNet", "Join succeeded for player """ $ UserName $ """:" $ GetPlayerNetworkAddress());
		ReceivedAuthRequest();
		//ClientGotoState('UnauthorizedJoinComplete', 'None');
		//GotoState('UnauthorizedJoinComplete', 'None');
		return;
	}
	
	//ClientSetViewTarget(ViewTarget);
	
}

void AHumanController::ClientSetETA(bool bEnable)
{
	bExploreTheArmyServer = bEnable;
}

void AHumanController::ReceivedAuthRequest()
{
	bReceivedAuthRequest = true;
}

void AHumanController::PostLoginComplete()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT(this $ ".PostLoginComplete() entered"));
	bPostLoginComplete = true;
	if (bReadyForFinishPostLogin)
	{
		AGP_GameInfo(Level.Game).FinishPostLogin(this);
	}
	*/
}

void AHumanController::EvaluateStatus()
{
	//AGP_GameInfo(Level.Game).EvaluatePlayerStatus(this);
}
void AHumanController::ReadyForFinishPostLogin()
{
	/*
	SetCustomTimer(2, False, 'EvaluateStatus');
	bReadyForFinishPostLogin = true;
	if (bPostLoginComplete)
	{
		AGP_GameInfo(Level.Game).FinishPostLogin(this);
	}
	if (GameReplicationInfo.bForceShadowsOff)
	{
		ClientMessage("Player shadows have been disabled by the server administrator");
		NotifyAdminMessage("Player shadows have been disabled by the server administrator");
	}
	*/
}
void AHumanController::NotifyAuthWaiting(bool bWaiting)
{
	if (GetWorld()->IsServer())
	{
		return;
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr && bWaiting)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(6.0f, "Waiting for Authorization","");
	}
	else
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(0.1f, "Authorization Complete","");
	}
}
void AHumanController::ClientChangeName(FString sNewName)
{
	UserName = sNewName;
	iUNC = CalculateUserNameChecksum(sNewName);
}
void AHumanController::ChangeName(FString sNewName)
{
	return;
}
void AHumanController::AnnounceNewPlayerJoiningServer(FString sMsg)
{
	/*
	if (InStr(sMsg, "is awaiting account authorization to play") == -1 && InStr(sMsg, "has entered the server and is waiting for PB authorization.") == -1 && InStr(sMsg, " has successfully joined the server.") == -1)
	{
		return;
	}
	Level.Game.Broadcast(Level.Game, sMsg);
	*/
}

void AHumanController::svp()
{
}

void AHumanController::nvp()
{
}

void AHumanController::ServerSetSystemLanguage(FString Language)
{
	SystemLanguage = Language;
}

void AHumanController::ServerSetUserName(FString sUserName)
{
	return;
	sUserName = StripColorCodes(sUserName);
	
	if (sUserName.Len() > 20)
	{
		sUserName = sUserName.Left(20);
	}
	/*
	ReplaceText(sUserName, " ", "_");
	ReplaceText(sUserName, """", "");
	ReplaceText(sUserName, "¤", "");
	*/

	sUserName = StripBadCodes(sUserName);
	/*
	if (!PlayerReplicationInfo.PlayerName ~= "Recruit")
	{
		UE_LOG(LogTemp, Warning, TEXT("Player name " $ sUserName $ " set in state " $ GetStateName() $ ", current PRi player name: " $ PlayerReplicationInfo.PlayerName));
		if (!PlayerReplicationInfo.PlayerName ~= sUserName)
		{
			Log("Kicking player for changing name twice from """ $ PlayerReplicationInfo.PlayerName $ """ to """ $ sUserName $ """");
			Level.Game.KickByController(this, "CHEATER");
		}
		return;
	}
	*/
	if (PlayerReplicationInfo == nullptr)
	{
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}

	if (GetNetMode() == ENetMode::NM_DedicatedServer && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("User name passed in: "" %s"""), *sUserName);
		if (sUserName.Len() == 0)
		{
			//ServerSay("Player with invalid name kicked by the server.", 'AdminSay');
			UE_LOG(LogTemp, Log, TEXT("Invalid User Name view SetUserName ""%s"", Stage: ""%d"""), *sUserName , StartupStage);
			//Level.Game.KickByController(this, "CHEATER");
			return;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("ServerSetUserName() Setting user name to %s"), *sUserName);
	UserName = sUserName;
	PlayerReplicationInfo->PlayerName = sUserName;
	return;
	
}

void AHumanController::ClientSimulateTrainingComplete()
{
	SimulateTrainingComplete();
}

void AHumanController::SimulateTrainingComplete()
{
	int32 i;
	for (i = 0; i < 33; i++)
	{
		iCompleted[i] = 3;
	}
	iCompleted[5] = 3;
	iCompleted[6] = 3;
	iCompleted[8] = 3;
	iCompleted[10] = 15;
	iCompleted[11] = 3;
	iRifleRangeRating = 40;
	PlayerReplicationInfo->_iTrust = 15;
	UpdateAuthRelatedPRI();
}

void AHumanController::ClientEnableStateChange(bool fEnable)
{
	//EnableStateChange(fEnable);
}

void AHumanController::ChangeMyName(FString sName)
{
	ServerCanPlayerJoin(sName);
	ClientMessage("Name set to " + sName);
}

void AHumanController::ServerCanPlayerJoin(FString sUserName)
{
	bAuthDisabledForAccount = !Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization();
	if (PbCanPlayerJoin())
	{
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerCanPlayerJoin() good PB - server State: %s"), *(GetStateName()));
		bPBChecked = true;
		//GotoState('ServerAuthorizePlayer');
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerCanPlayerJoin() - PB Status: %s"), *GetPBConnectStatus());
		ClientPlayerCanJoin(Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization(), IsPBEnabled());
	}
	
}

void AHumanController::ClientPlayerCanJoin(bool bAuthUsed, int32 iPBEnabledOnServer)
{
	bPBChecked = true;
	if (iPBEnabledOnServer == 1)
	{
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ClientPlayerCanJoin() - PB is enabled!: " $ GetPBConnectStatus()));
		ClientMessage("PB has authenticated and is up to date.");
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController::ClientPlayerCanJoin() - starting authorization process!"));
	if (!bAuthUsed)
	{
		SelectTeam("");
	}
	else
	{
		//GotoState('ServerAuthorizePlayer');
	}
}

void AHumanController::ClientDisconnect(FString Msg)
{
	FString StrAppended;
	UE_LOG(LogTemp, Log, TEXT("User disconnected: %s"), *Msg);
	UE_LOG(LogTemp, Warning, TEXT("HumanController::ClientDisconnect( %s )"), *Msg);
	if (Msg != "")
	{
		StrAppended = "Failed Authorization|" + Msg;
	}
	else
	{
		StrAppended = "Failed Authorization";
	}
	NotifyPBAuthMessage(StrAppended);
}

void AHumanController::NotifyAuthServerOfMPMissionComplete()
{
	/*
	local string ServerIP;
	local DBAuth.MissionCompleteRequestAdapter Adapter;
	UE_LOG(LogTemp, Warning, TEXT("HumanController::NotifyAuthServerOfMPMissionComplete()"));
	if (PlayerReplicationInfo == nullptr)
	{
		Level.Game.KickByController(this, "CHEATER");
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
	{
		return;
	}
	if (!Level.Game.CheatsDisabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::NotifyAuthServerOfMPMissionComplete()	Can't authenticate on a cheat server!"));
		return;
	}
	ServerIP = Class'AuthorizeServerRequestAdapter'.GetServerAuthIP();
	UE_LOG(LogTemp, Warning, TEXT("NotifyAuthServerOfMPMissionComplete" @ UserName @ EncryptedPassword));
	Adapter = Spawn(Class'MissionCompleteRequestAdapter', this);
	Adapter.Request(UserName, FUnload(EncryptedPassword), Level.iTour, Level.iMission, iRifleRangeRating, True, DistributionHistory, ServerIP);
	*/
}
void AHumanController::AuthUpdateExperienceCallback(int32 ResultCode, int32 experience_current, int32 experience_needed, int32 honor_current)
{
	PlayerReplicationInfo->_Experience = experience_current;
	if (PlayerReplicationInfo->bQualifiedViaInstantAction && !PlayerReplicationInfo->bQualifiedBCT)
	{
		if (PlayerReplicationInfo->_iTrust > 20)
		{
			UE_LOG(LogTemp, Log, TEXT("Information: Instant action player %s limited to display of honor 20"), *PlayerReplicationInfo->PlayerName);
			PlayerReplicationInfo->_iTrust = 20;
		}
	}
	PlayerReplicationInfo->_iTrust = honor_current;
}

void AHumanController::LoadUserProfileAndNews()
{
	/*
	if (!Level ~= "Entry.LevelInfo0" && !Level ~= "Entry2.LevelInfo0")
	{
		SetLoginStatus(0, "Cannot load profile now.", "You cannot load your profile while attached to game server.");
		return false;
	}
	if (IsInState('AuthorizingUserLocallyThenGetNews'))
	{
		Log("User already authorizing locally");
		return true;
	}
	iTour = 0;
	GotoState('AuthorizingUserLocallyThenGetNews');
	return true;
	*/
}

void AHumanController::ClientNotifyAuthServerMessage(FString ErrMsg1, FString ErrMsg2, FString ErrURL1, FString ErrURL2)
{
	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s HumanController::ClientNotifyAuthServerMessage Got %s %s %s %s " ), *ObjectName, *ErrMsg1 , *ErrMsg2 , *ErrURL1 , *ErrURL2);
	AuthErrorMessage1 = ErrMsg1;
	AuthErrorMessage2 = ErrMsg2;
	AuthErrorURL1 = ErrURL1;
	AuthErrorURL2 = ErrURL2;
}

void AHumanController::ServerUploadTrustAndExperience(int32 Logout)
{
	/*
	local string s1;
	local int upload_experience;
	local string ServerIP;
	local DBAuth.UpdateTrustAndExperienceRequestAdapter Adapter;
	if (PlayerReplicationInfo == nullptr)
	{
		if (!bReportedLogout)
		{
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerUploadTrustAndExperience()	Got here with no PRI and no logout report"));
		}
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer() && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		s1 = "847";
		ClientMessage("This is an America's Army Explorer Server, while playing here you will not accrue XP/HONOR and will not generate player statistics.");
	}
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() entered, bAuthDisabledForAccount:" $ bAuthDisabledForAccount));
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() entered, Auth enabled:" $ Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization()));
	if (!Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() || bAuthDisabledForAccount)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() Auth disabled for this account or server"));
		return;
	}
	if (Level.IsUnofficialServer() || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer() && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		if (Level.Game.bSendRoundTimeInfo)
		{
			upload_experience = -1;
		}
		else
		{
			return;
		}
	}
	else
	{
		PlayerReplicationInfo.TotalExperience(True);
		upload_experience = PlayerReplicationInfo.GetExperience();
	}
	if (Logout == 1)
	{
		if (bReportedLogout)
		{
			return;
		}
		bReportedLogout = true;
	}
	ServerIP = Class'AuthorizeServerRequestAdapter'.GetServerAuthIP();
	Adapter = Spawn(Class'UpdateTrustAndExperienceRequestAdapter', this);
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() - processing request " @ "ETATracking" @ "Experience:" @ - 1 @ "Logout:" @ Logout == 1 @ "Rounds:" @ PlayerReplicationInfo.GetCumRounds() @ "PlayTime:" @ PlayerReplicationInfo.GetPlayTime() @ "Tour:" @ Level.iTour @ "Mission:" @ Level.iMission @ "ServerIP:" @ ServerIP));
		Adapter.Request("ETATracking", s1 $ "sdk" $ 1, -1, Logout == 1, PlayerReplicationInfo.GetCumRounds(), PlayerReplicationInfo.GetPlayTime(), Level.iTour, Level.iMission, ServerIP);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() - processing request " @ UserName @ EncryptedPassword @ "Experience:" @ upload_experience @ "Logout:" @ Logout == 1 @ "Rounds:" @ PlayerReplicationInfo.GetCumRounds() @ "PlayTime:" @ PlayerReplicationInfo.GetPlayTime() @ "Tour:" @ Level.iTour @ "Mission:" @ Level.iMission @ "ServerIP:" @ ServerIP));
		Adapter.Request(UserName, FUnload(EncryptedPassword), upload_experience, Logout == 1, PlayerReplicationInfo.GetCumRounds(), PlayerReplicationInfo.GetPlayTime(), Level.iTour, Level.iMission, ServerIP);
	}
	if (Logout != 0)
	{
		Level.Game.NotifyReportLogoutStarted();
	}
	*/
}
void AHumanController::ServerUploadStats(int32 Kills, int32 Deaths, int32 ShotsFired, int32 ShotsThatHitAGPPawns, float PlayDuration)
{
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() entered, bOnlySpectator: %s"), PlayerReplicationInfo->bOnlySpectator ? TEXT("true") : TEXT("false"));
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() entered, bAuthDisabledForAccount: %s"), bAuthDisabledForAccount ? TEXT("true") : TEXT("false"));
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() entered, Auth enabled: %s"), Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() ? TEXT("true") : TEXT("false"));
	if (!Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() || bAuthDisabledForAccount)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() Auth disabled for this account or server"));
		return;
	}
	//UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats()" @ UserName @ EncryptedPassword @ "Kills:" $ Kills @ "Deaths:" $ Deaths @ "Shots Fired:" $ ShotsFired @ "Shots That Hit AGPPawns:" $ ShotsThatHitAGPPawns @ "PlayDuration:" $ PlayDuration));
}
void AHumanController::ServerExperienceUpdateAuthorizeComplete(int32 Code)
{
	
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerExperienceUpdateAuthorizeComplete" @ UserName @ Code));
		switch(Code)
		{
			case 1:
				//Level.Game.NotifyReportLogoutFinished();
				return;
			case -1:
				ClientMessage(WrongUserPassword);
				break;
			case -2:
				ClientMessage(NoUserRecord);
				break;
			case -3:
				ClientMessage(UserIsBanned);
				break;
			case -4:
				ClientMessage(ResponseTimeOut);
				break;
			case -5:
				ClientMessage(ServerNotRegistered);
				break;
			case -6:
				ClientMessage(BetaServer);
				break;
			case -7:
				break;
			case -8:
				break;
			default:
				ClientMessage("Error: Unknown");
				break;
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController:ServerExperienceUpdateAuthorizeComplete: Closing Authserver Connection"));
		//Level.Game.NotifyReportLogoutFinished();
	
}
void AHumanController::AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
{
	ClientMessage(sMsg);
}
void AHumanController::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	sAuthClientTransmissionText = sStatus;
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->SetLoginStatus(iStatus, sStatus, sNavMsg);
	}
}
void AHumanController::DisplayVAECompleteMessage()
{
	ClientOpenMenu("AGP_Interface.AAVAEMissionCompletePage", false, "", "");
}
void AHumanController::DisplayMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	ClientOpenMenu("AGP_Interface.AAMissionCompletePage", false, Text, text2);
}
void AHumanController::DisplayMissionCompleteOther(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, FString OtherMenu)
{
	ClientOpenMenu(OtherMenu, false, Text, text2);
}
void AHumanController::DisplayMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	ClientOpenMenu("AGP_Interface.AAMissionCompletePage",false,Text,text2);
}
void AHumanController::DisplayLandNavScore(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8)
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		//Cast<AAGP_HUD>(MyHUD)->OpenLandNavScore(text1, text2, text3, text4, text5, text6, text7, text8, Level.Game.GetScreenplay().bPlayerCheated);
	}
}
void AHumanController::ResetAuthExtraMissionData()
{
	iAuthMissionDataFields = 0;
}
void AHumanController::SetAuthMissionPassFlag(bool bAMissionPass)
{
	bMissionPass = bAMissionPass;
}
bool AHumanController::AddAuthExtraMissionData(FString sMissionData)
{
	UE_LOG(LogTemp, Warning, TEXT("HumanController.AddAuthExtraMissionData() entered with %s"), *sMissionData);
	if (iAuthMissionDataFields < 26)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.AddAuthExtraMissionData() adding data: %s"), *sMissionData);
		asAuthMissionData[iAuthMissionDataFields]=sMissionData;
		iAuthMissionDataFields ++;
		UE_LOG(LogTemp, Warning, TEXT("HumanController.AddAuthExtraMissionData() added data: %s"), *sMissionData);
		return true;
	}
	return false;
}
void AHumanController::MissionCompleted()
{
	/*
	local string sLevelName;
	if (Level.Game.GetScreenplay().bPlayerCheated)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::MissionCompleted()	Cannot Authenticate if you cheated")=;
		ScreenPrint("That don't make no sense at all.");
	}
	sLevelName = Level.GetLevelName();
	SendMissionComplete(Level.GetLevelTour(), Level.GetLevelMission());
	*/
}
void AHumanController::SendMissionComplete(int32 Tour, int32 Mission)
{
	iTour = Tour;
	iMission = Mission;
	iAuthClientTransmissionComplete = 0;
	//EncryptedPassword = FLoad(UserPassword);
	//GotoState('ClientMissionComplete');
}
void AHumanController::ParseMissionString(FString sMissions, bool bNews)
{
	/*
	local int iMissionField;
	local string sTemp;
	local array<String> asMissionFields;
	if (bNews)
	{
		sMissions = sMissions $ Chr(255);
		Split(sMissions, "" $ Chr(255), asMissionFields);
		UE_LOG(LogTemp, Warning, TEXT("News field: " $ iNewsID));
		UE_LOG(LogTemp, Warning, TEXT("New News ID: " $ asMissionFields[34]));
		iNewsID = asMissionFields[34];
		sNewsLine1 = asMissionFields[35];
		sNewsLine2 = asMissionFields[36];
		sNewsLine3 = asMissionFields[37];
		sNewsLine4 = asMissionFields[38];
		UE_LOG(LogTemp, Warning, TEXT("News: " $ sNewsLine1));
		UE_LOG(LogTemp, Warning, TEXT("News: " $ sNewsLine2));
		UE_LOG(LogTemp, Warning, TEXT("News: " $ sNewsLine3));
		UE_LOG(LogTemp, Warning, TEXT("News: " $ sNewsLine4));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Missions data:" $ sMissions));
		sMissions = sMissions $ ",";
		Split(sMissions, ",", asMissionFields);
		for (iMissionField = 0; iMissionField < 33; iMissionField++)
		{
			sTemp = asMissionFields[iMissionField];
			iCompleted[iMissionField] = sTemp;
			Log("Parsed mission: " $ iMissionField $ " value: " $ iCompleted[iMissionField]);
		}
		if (asMissionFields[33] >= 0 && asMissionFields[33] <= 40)
		{
			iRifleRangeRating = asMissionFields[33];
		}
		if (PlayerReplicationInfo == nullptr && GetNetMode() == ENetMode::NM_Standalone)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawning new PRI for single player training mission"));
			PlayerReplicationInfo = Spawn(Class'PlayerReplicationInfo', this);
		}
		if (PlayerReplicationInfo != nullptr)
		{
			if (asMissionFields.Length > 34)
			{
				PlayerReplicationInfo._iTrust = asMissionFields[34];
				PlayerReplicationInfo._bSoldiersCharacter = asMissionFields[35];
				PlayerReplicationInfo._Experience = asMissionFields[36];
				iCDG = asMissionFields[37];
				PlayerReplicationInfo.SetGroup(asMissionFields[37]);
			}
		}
		iUID = asMissionFields[38];
		UpdateAuthRelatedPRI();
	}
	*/
}
void AHumanController::UpdateAuthRelatedPRI()
{
	int32 iMissionIndex;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		if (PlayerReplicationInfo != nullptr)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Setting PRI.AuthUserName to '%s'"));
			PlayerReplicationInfo->AuthUserName = UserName;
			for (iMissionIndex = 0; iMissionIndex < 20; iMissionIndex++)
			{
				UE_LOG(LogTemp, Warning, TEXT("iCompleted[ %d ] = %d"),iMission, iCompleted[iMission]);
			}
			if (iCompleted[1] == 15)
			{
				PlayerReplicationInfo->bQualifiedBCT = true;
			}
			if (iCompleted[5] == 3)
			{
				PlayerReplicationInfo->bQualifiedSniper = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedSniper = false;
			}
			if (iRifleRangeRating < 36)
			{
				PlayerReplicationInfo->bQualifiedSniper = false;
			}
			if (iCompleted[6] == 3)
			{
				PlayerReplicationInfo->bQualifiedAirborne = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedAirborne = false;
			}
			if (iCompleted[8] == 3)
			{
				PlayerReplicationInfo->bQualifiedRanger = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedRanger = false;
			}
			if (iCompleted[10] == 15)
			{
				PlayerReplicationInfo->bQualifiedMedic = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedMedic = false;
			}
			if (iCompleted[11] == 3 && PlayerReplicationInfo->GetHonor() >= 15)
			{
				PlayerReplicationInfo->bQualifiedSF = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedSF = false;
			}
			if ((iCompleted[14] & 1) == 1)
			{
				PlayerReplicationInfo->bQualifiedJavelin = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedJavelin = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("Javelin training flag is: %s"), PlayerReplicationInfo->bQualifiedJavelin ? TEXT("true") : TEXT("false"));
			if ((iCompleted[14] & 8) != 0)
			{
				PlayerReplicationInfo->bQualifiedES2 = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedES2 = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("bQualifiedES2 training flag is: %s"), PlayerReplicationInfo->bQualifiedES2 ? TEXT("true") : TEXT("false"));
			if ((iCompleted[14] & 2) != 0)
			{
				PlayerReplicationInfo->bQualifiedDriveHMMWV = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedDriveHMMWV = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("HMMWV Driver qualified: %s"), PlayerReplicationInfo->bQualifiedDriveHMMWV ? TEXT("true") : TEXT("false"));
			if ((iCompleted[14] & 4) != 0)
			{
				PlayerReplicationInfo->bQualifiedUseCROWS = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedUseCROWS = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("HMMWV CROWS qualified: %s"), PlayerReplicationInfo->bQualifiedUseCROWS ? TEXT("true") : TEXT("false"));
			
			/*
			if (AGP_GameInfo(Level.Game).bAutoAT && !PlayerReplicationInfo->bQualifiedUseCROWS || !PlayerReplicationInfo->bQualifiedDriveHMMWV || !PlayerReplicationInfo->bQualifiedES2 || !PlayerReplicationInfo->bQualifiedJavelin)
			{
				UE_LOG(LogTemp, Warning, TEXT("AT Enabled for user"));
				PlayerReplicationInfo->bQualifiedUseCROWS = true;
				PlayerReplicationInfo->bQualifiedDriveHMMWV = true;
				PlayerReplicationInfo->bQualifiedJavelin = true;
				PlayerReplicationInfo->bQualifiedES2 = true;
			}
			*/
			if (PlayerReplicationInfo->_iTrust < 20 && !PlayerReplicationInfo->bQualifiedBCT)
			{
				PlayerReplicationInfo->bQualifiedAirborne = true;
				PlayerReplicationInfo->bQualifiedRanger = true;
			}
			if (!TournamentIsTournament())
			{
				//UE_LOG(LogTemp, Warning, TEXT("HumanController::UpdateAuthRelatedPRI()  - Testing " $ UserName $ " for PlayerAdmin rights"));
				/*
				if (!PlayerReplicationInfo->bAdmin && Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo) && !Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() || PlayerReplicationInfo->SuperUser())
				{
					if (Level.Game.NumAdmins < Level.Game.MaxAdmins)
					{
						UE_LOG(LogTemp, Warning, TEXT("Player Admin added"));
						PlayerReplicationInfo->bAdmin = true;
						ClientMessage("You are a player administrator on this server.");
						//Level.Game.NumAdmins++;
					}
					else
					{
						PlayerReplicationInfo->bAdmin = false;
						PlayerReplicationInfo->bPlayerAdmin = false;
						UE_LOG(LogTemp, Warning, TEXT("No space for Player Admin"));
						ClientMessage("The Maximum number of administrators are already logged in. You are logged in as a regular player.");
					}
				}
				else
				{
					if (Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo) && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && !PlayerReplicationInfo.SuperUser())
					{
						ClientMessage("You do not have sufficient rights to be a player administrator on this official server.");
						NotifyAdminMessage("You do not have sufficient rights to be a player administrator on this official server.");
					}
				}
				*/
			}
		}
		PlayerReplicationInfo->PostAuthComplete();
	}
}
FString AHumanController::AddField(FString Mission, FString Field)
{
	return Mission + Field + ",";
}
void AHumanController::BitsetToString(int32 Bitset)
{
	/*
	int32 BitIndex;
	FString S;
	for (BitIndex = 0; BitIndex < 32; BitIndex++)
	{
		if (2 * * BitIndex & Bitset != 0)
		{
			S $ = Eval(Len(S) > 0, ", ", "") $ BitIndex;
		}
	}
	return S;
	*/
}
FString AHumanController::GenerateMissionString()
{
	int32 iCounter = 0;
	FString sMissions= "";

	if (PlayerReplicationInfo == nullptr)
	{
		return "";
	}
	/*
	for (iCounter = 0; iCounter < 33; iCounter++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tour " $ iCounter $ " is " $ iCompleted[iCounter] @ "(" $ BitsetToString(iCompleted[iCounter]) $ ")"));
		sMissions = sMissions $ iCompleted[iCounter] $ ",";
	}
	sMissions = sMissions $ iRifleRangeRating $ ",";
	sMissions = AddField(sMissions, PlayerReplicationInfo._iTrust);
	sMissions = AddField(sMissions, "0");
	sMissions = AddField(sMissions, PlayerReplicationInfo._Experience);
	UE_LOG(LogTemp, Warning, TEXT("HumanController::GenerateMissionString() - Experience: " $ PlayerReplicationInfo.GetExperience()));
	sMissions = AddField(sMissions, PlayerReplicationInfo.GetGroup());
	sMissions = AddField(sMissions, iUID);
	*/
	return sMissions;
}

void AHumanController::Shake(float Time, float Intensity)
{
	ClientGlobalCameraScreenShake(Time, 200);
}
void AHumanController::SetAutoLoggedInRunOnce()
{
}
void AHumanController::HasAutoLoggedInRunOnce()
{
}
void AHumanController::SetNightVision(bool Set)
{
}
void AHumanController::ClientGlobalCameraScreenShake(float ShakeTime, float ShakeIntensity)
{
}
void AHumanController::TournamentWarmupClientGameEnded()
{
	if (bPBChecked == false)
	{
		return;
	}
	
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		return;
	}
	//GotoState('GameEnded');
	if (GetPawn() != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->bWantsToProne = false;
		Cast<AAGP_Pawn>(GetPawn())->bWantsToCrouch = false;
	}
	//CleanOutSavedMoves();
}

bool AHumanController::CanFire()
{
	if (bTurn180 != 0)
	{
		bFire = 0;
		bAltFire = 0;
		UE_LOG(LogTemp, Warning, TEXT("Player cannot shoot while turning around"));
		ClientMessage("You are busy and cannot shoot.");
		return false;
	}
	if (bAction != 0)
	{
		bFire = 0;
		bAltFire = 0;
		UE_LOG(LogTemp, Warning, TEXT("Player cannot shoot while busy"));
		ClientMessage("You are busy and cannot shoot.");
		return false;
	}
	/*
	if (GetPawn()!= nullptr && Cast<AAGP_Pawn>(GetPawn())->IsInState('BusyProning'))
	{
		bFire = 0;
		bAltFire = 0;
		ClientMessage("You cannot fire while going prone.");
		return false;
	}
	*/
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->bIsSprinting)
	{
		bFire = 0;
		bAltFire = 0;
		ClientMessage("You cannot fire while sprinting.");
		return false;
	}
	//return Super::CanFire();
	return false;      //FAKE    /ELiZ
}
void AHumanController::TurnAround()
{
	if (bAction != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player cannot turn while busy"));
		return;
	}
	bFire = 0;
	bAltFire = 0;
	TurnAround();
}
void AHumanController::CleanUp()
{
	/*
	local AGP_Pawn p;
	local Emitter E;
	local int i;
	if (Role != 4)
	{
		ForEach AllActors(Class'Emitter', E)
		{
			E.MatchStarting();
		}
	}
	CleanUp();
	CleanOutSavedMoves();
	p = Cast<AAGP_Pawn>(GetPawn());
	if (p != nullptr)
	{
		if (p.Weapon != nullptr)
		{
			p.Weapon.UnZoom();
		}
		p.ResetLean();
		p.CleanupOptics();
		p.LimitRotation(False);
		p.LockMovement(False);
		Pawn.bWantsToProne = false;
		Pawn.bWantsToCrouch = false;
	}
	bNoThrowWeapon = false;
	SetNightVision(False);
	bAction = 0;
	StopFiring();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		LockPlayer(false, false);
	}
	else
	{
		if (GetNetMode() == ENetMode::NM_Standalone && "" $ Level ~= "Entry.LevelInfo0")
		{
			UE_LOG(LogTemp, Warning, TEXT("BeginPlay() for standalone - locking player"));
			LockPlayer(true, true);
		}
	}
	*/
	_GrenadeShakeTime = 0;
	_GrenadeShakeUpdate = 0;
	_GrenadeSoundTime = 0;
	_GrenadeSoundUpdate = 0;
	_GrenadeSoundIntensity = 0;
	_FlashSoundTime = 0;
	_FlashSoundUpdate = 0;
	_FlashSoundIntensity = 0;
	if (_FlashEffect != nullptr)
	{
		_FlashEffect->EndFlash(this);
	}

	/*
	RemoveCameraEffect(_FlashEffect);
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::CleanUp() - Praying for AGP_HUD not to crash! PawnOwner was " $ Cast<AAGP_HUD>(MyHUD)->PawnOwner, true));
		Cast<AAGP_HUD>(MyHUD)->bDrawHUD = false;
		if (_cHUDCommoInfo == nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			_cHUDCommoInfo = HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(False);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	abpobjESSLastSeen = nullptr;
	LastReportableNPC = nullptr;
	i = 0;
	if (i < FoundESSObject.Length)
	{
		FoundESSObject.remove(i, 1);
	}
	*/
}
void AHumanController::CleanupLevel()
{
	/*
	local AGP_Pawn p;
	ForEach DynamicActors('AGP_Pawn', p)
	{
		if (p.IsA('NPC_Ambient'))
		{
			if (p.bDontPossess)
			{
				p.MatchStarting();
			}
		}
		else
		{
			if (p.IsA('NPC_doctor') || p.IsA('NPC_soldier') || p.IsA('NPC_civilian') || p.IsA('NPC_SpecialForces'))
			{
				if (p.bDontPossess)
				{
					p.MatchStarting();
				}
			}
		}
		if (p.IsA('AGP_Vehicle'))
		{
			p.Destroy();
		}
		if (GetNetMode() != ENetMode::NM_Standalone && p.bTearOff)
		{
			p.Destroy();
		}
	}
	Level.DecalSession++;
	*/
}

void AHumanController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	/*
	local int NewLean;
	local int iUserNameCalculatedChecksum;
	if (Pawn != nullptr && Pawn.bIsSprinting)
	{
		bAction = 0;
		bFire = 0;
		bAltFire = 0;
	}
	if (fCD1 && fCD2 && GetNetMode() == ENetMode::NM_Client && bIsAuthorizedServer)
	{
		if (GetWorld()->GetTimeSeconds() - fpCDTime > fpCADelayTime)
		{
			Log("Internal Error - " $ sFailReason);
			UE_LOG(LogTemp, Warning, TEXT("Cheat detection trying method: " $ iCDAction));
			Switch(iCDAction)
			{
					case 0:
						Pawn.Weapon.Zoom();
						Pawn.LimitRotation(True);
						Pawn.LockMovement(True);
						ClientFlashBanged(100, 1, 1);
						ConsoleCommand("quit");
						break;
					case 1:
						ConsoleCommand("disconnect");
						break;
					case 2:
						ConsoleCommand("reconnect");
						break;
					case 3:
					case 4:
					case 5:
						InduceFailure();
						UE_LOG(LogTemp, Warning, TEXT("Cheat detection trying to force crash"));
						break;
					case 6:
						ConsoleCommand("load " $ "leaven" $ "worth" $ ".aao");
						return;
					default:
						InduceFailure();
						break;
			}
		}
	}
	if (Pawn == nullptr)
	{
		PlayerTick(DeltaTime);
	}
	else
	{
		if (bIsAuthorizedServer && GetNetMode() == ENetMode::NM_Client && GetWorld()->GetTimeSeconds() > fLastNameTest)
		{
			fLastNameTest = GetWorld()->GetTimeSeconds() + 2;
			if (Player.Console.Class != "Engine.Console" && Player.Console.Class != "XInterface.ExtendedConsole")
			{
				UE_LOG(LogTemp, Warning, TEXT("Invalid Console Detected: " $ Player.Console.Class));
				fpCADelayTime = Rand(15);
				fpCDTime = GetWorld()->GetTimeSeconds();
				fCD1 = true;
				fCD2 = true;
				sFailReason = "Failure: BC";
				iCDAction = Rand(6);
				return;
			}
			if (!bExploreTheArmyServer && PlayerReplicationInfo != nullptr && iCDG != PlayerReplicationInfo.GetGroup() && iCDG > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Mismatched Group: " $ iCDG $ " vs. current: " $ PlayerReplicationInfo.GetGroup()));
				fpCADelayTime = Rand(30);
				fpCDTime = GetWorld()->GetTimeSeconds();
				fCD1 = true;
				fCD2 = true;
				sFailReason = "Failure: BG";
				iCDAction = Rand(6);
				return;
			}
			if (PlayerReplicationInfo != nullptr)
			{
				if (!bExploreTheArmyServer && Len(PlayerReplicationInfo.PlayerName) != 0 && iUNC != 0)
				{
					iUserNameCalculatedChecksum = CalculateUserNameChecksum(PlayerReplicationInfo.PlayerName);
					if (iUNC != iUserNameCalculatedChecksum)
					{
						UE_LOG(LogTemp, Warning, TEXT("Invalid checksum detected"));
						if (fCD1 == false && fCD2 == false && fpCADelayTime == 0 && fpCDTime == 0)
						{
							fpCADelayTime = Rand(30);
							fpCDTime = GetWorld()->GetTimeSeconds();
							fCD1 = true;
							fCD2 = true;
							sFailReason = "Failure: BN";
							iCDAction = Rand(6);
							return;
						}
						else
						{
							if (fCD1 == false || fCD2 == false || fpCADelayTime == 0 || fpCDTime == 0)
							{
								Log("Internal error: CD1");
								InduceFailure();
							}
						}
					}
				}
			}
		}
		if (bAction != bLastAction)
		{
			bLastAction = bAction;
			ChangeActionStatus(bAction);
		}
		if (!bToggleLean && CanLean() && bLeanRight != bLastLeanRight || bLeanLeft != bLastLeanLeft)
		{
			bLastLeanRight = bLeanRight;
			bLastLeanLeft = bLeanLeft;
			NewLean = 0;
			if (bLeanRight != 0)
			{
				NewLean++;
			}
			if (bLeanLeft != 0)
			{
				NewLean--;
			}
			if (NewLean < 0)
			{
				Pawn.LeanLeft(True);
			}
			else
			{
				if (NewLean == 0)
				{
					Pawn.ResetLean();
				}
				else
				{
					Pawn.LeanRight(True);
				}
			}
		}
		PlayerTick(DeltaTime);
		if (!Level.IsEntry())
		{
			AutoTrace();
		}
	}
	*/
}
float AHumanController::GetSoundDampening()
{
	if (_FlashSoundTime > 0)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("Flashbang Sound Dampening"));
		}
		if (_FlashSoundUpdate < _FlashSoundTime)
		{
			return (0.15 / _FlashSoundIntensity);
		}
	}
	if (_GrenadeSoundTime > 0)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("Grenade Sound Dampening"));
		}
		if (_GrenadeSoundUpdate < _GrenadeSoundTime)
		{
			return (0.15 / _GrenadeSoundIntensity);
		}
	}
	return 1;
}

void AHumanController::CalcSoundDampening()
{
	float ContDamp;
	float WeapDamp;
	float PawnDamp;
	ContDamp = 1;
	WeapDamp = 1;
	PawnDamp = 1;
	ContDamp = GetSoundDampening();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("Sound Dampening= %i" ));
	}
	if (GetPawn() != nullptr)
	{
		//PawnDamp = Cast<AAGP_Pawn>(GetPawn())->GetSoundDampening();
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
		{
			WeapDamp = Cast<AAGP_Pawn>(GetPawn())->Weapon->GetSoundDampening();
		}
	}
	//SoundDampening = FMin(ContDamp, FMin(WeapDamp, PawnDamp));
}

void AHumanController::Timer()
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		CheckOutOfBounds();
		if (bBoundaryTrigger)
		{
			//TriggerEvent(BoundaryEvent, this, Pawn);
			//bBoundaryTrigger = false;
		}
	}
	else
	{
		IdleCheck();
	}
}
void AHumanController::IdleCheck()
{
	/*
	if (GetWorld()->GetTimeSeconds() < NextIdleCheck || Level.Game == nullptr || PlayerReplicationInfo == nullptr || !Level.Game.TestForIdlePlayers(PlayerReplicationInfo))
	{
		return;
	}
	if (bNotIdle || IdleLocation != ViewTarget.Location || IdleRotation != ViewTarget.Rotation)
	{
		IdleLocation = ViewTarget.Location;
		IdleRotation = ViewTarget.Rotation;
		LastMovedTime = GetWorld()->GetTimeSeconds();
		NextIdleCheck = GetWorld()->GetTimeSeconds() + 20;
		bNotIdle = false;
		bIdleWarning = 0;
	}
	else
	{
		if (Level.Game.NotifyIdlePlayer(this, LastMovedTime))
		{
			NextIdleCheck = GetWorld()->GetTimeSeconds() + 3;
		}
		else
		{
			NextIdleCheck = GetWorld()->GetTimeSeconds() + 20;
		}
	}
	*/
}



void AHumanController::SetHUDAlpha(uint8 A)
{
	HUDAlpha = A;
}

void AHumanController::SetHUDColor(uint8 H)
{
	HUDColor = H;
}

void AHumanController::SetHUDCrosshair(uint8 C)
{
	HUDCrosshair = C;
}

void AHumanController::NextCrosshair()
{

}

void AHumanController::SetSkin(FString S)
{
	S = S.ToUpper();
	if (S.FString::Contains("DARK", ESearchCase::CaseSensitive, ESearchDir::FromEnd))
	{
		S = "SKINPREF_African";
	}
	else
	{
		if (S.FString::Contains("MEDIUM", ESearchCase::CaseSensitive, ESearchDir::FromEnd))
		{
			S = "SKINPREF_Latino";
		}
		else
		{
			if (S.FString::Contains("LIGHT", ESearchCase::CaseSensitive, ESearchDir::FromEnd))
			{
				S = "SKINPREF_Caucasian";
			}
			else
			{
				S = "SKINPREF_None";
			}
		}
	}
	SetSkinPreference(S);
}

void AHumanController::TestIdle_Location()
{
	/*
	FVector distFromStart;
	distFromStart = Pawn.Location - StartSpot.GetStartLocation();
	if (distFromStart.Z < 200)
	{
		distFromStart.Z = 0;
	}
	return VSize(distFromStart) < 100;
	*/
}
void AHumanController::TestIdle_Rotation()
{
	/*
	local float DeltaYaw;
	DeltaYaw = Abs(Pawn.Rotation.Yaw - StartSpot.GetStartRotation().Yaw);
	if (DeltaYaw > 32768)
	{
		DeltaYaw = Abs(DeltaYaw - 65536);
	}
	return DeltaYaw < 1024;
	*/
}
bool AHumanController::TestIdle_Weapon()
{
	AWeapon* W;
	AAmmunition* A;
	AAGP_Pawn* P;
	P = Cast<AAGP_Pawn>(GetPawn());
	if (P == nullptr)
	{
		return false;
	}
	W= P->Weapon;
	if (W == nullptr)
	{
		return true;
	}
	if (W->IsA(AThrowWeapon::StaticClass()))
	{
		return false;
	}
	A = Cast<AWeapon>(W)->AmmoType;

	//return A == NULL || A->AmmoAmount == A->Default->AmmoAmount;
	return A == nullptr;   //FAKE ELiZ
}
void AHumanController::IdleCheckPerRound(bool bEndGame)
{
	/*
		if (Level.Game == nullptr)
		{
			return;
		}
		if (Level.Game.GetTimeElapsed() < 20)
		{
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController::IdleCheckPerRound()	" $ this @ Pawn $ " Idle rounds: " $ nIdleRounds $ " bTestedIdleRounds: " $ bTestedIdleRounds));
		if (Pawn != nullptr && ! bTestedIdleRounds)
		{
			if (StartSpot != nullptr && TestIdle_Location() && TestIdle_Rotation() && TestIdle_Weapon())
			{
				nIdleRounds ++;
			}
			else
			{
				nIdleRounds=0;
			}
		}
		if (nIdleRounds > 0)
		{
			Level.Game.NotifyIdlePlayerRounds(this,nIdleRounds,bEndGame);
		}
		bTestedIdleRounds=True;
	*/
}
void AHumanController::PawnDied(APawn* p)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		fpTimePlayedLastRound=AGP_GameInfo(Level.Game).TimeLimit * 60 - GameReplicationInfo.RemainingTime;
	}
	if (_cHUDCommoInfo != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(False);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	IdleCheckPerRound();
	PawnDied(p);
	*/
}
void AHumanController::NotifyImpendingIdleKick(bool bIdleRounds)
{
	if (Cast<AAGP_HUD>(MyHUD) == NULL)
	{
		return;
	}
	if (bIdleRounds)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(20,"IDLE WARNING!","If you are Idle for 1 more round, you will be auto-kicked");
		bIdleWarning=1;
	}
	else
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(4,"IDLE WARNING!","Move or rotate your view to avoid being auto-kicked");
		bIdleWarning=2;
	}
}
void AHumanController::RenderOverlays_Stage1(UCanvas* Canvas)
{
	/*
		if (Pawn == nullptr || Vehicle(Pawn) != nullptr)
		{
			return;
		}
		RenderOverlays(Canvas,True);
	*/
}
void AHumanController::RenderOverlays_Stage2(UCanvas* Canvas)
{
	/*
		local int i;
		local int j;
		local int Alpha;
		local float TimeElapsed;
		local float TimeScale;
		local AGP_Pawn myPawn;
		if (Pawn != nullptr)
		{
			myPawn=Cast<AAGP_Pawn>(GetPawn());
		}
		else
		{
			return;
		}
		RenderOverlays(Canvas,False);
		if (Role == 4 && Level.Game.GetScreenplay() != nullptr)
		{
			Level.Game.GetScreenplay().Draw(Canvas);
		}
		if (myPawn == nullptr && Vehicle(Pawn) != nullptr && Vehicle(Pawn).Driver != nullptr)
		{
			myPawn=AGP_Pawn(Vehicle(Pawn).Driver);
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr && ! Cast<AAGP_HUD>(MyHUD)->bShowMainMenu && Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn()).GetOpticsDevice() != nullptr && Cast<AAGP_Pawn>(GetPawn()).GetOpticsDevice().IsActive())
		{
			Cast<AAGP_Pawn>(GetPawn()).GetOpticsDevice().RenderOverlays(Canvas,False);
		}
		if (prevHealth - 10 > myPawn.Health)
		{
			_fDamageTime=GetWorld()->GetTimeSeconds();
		}
		prevHealth=myPawn.Health;
		if (_fDamageTime != 0)
		{
			if (GetWorld()->GetTimeSeconds() - _fDamageTime > 0.1)
			{
				_fDamageTime=0;
			}
			else
			{
				Canvas->Style=5;
				Canvas->SetPos(0,0);
				Canvas->DrawTile(_tPainOverlay,Canvas->SizeX,Canvas->SizeY,0,0,512,512);
			}
		}
		for (i=0; i<LaserDots.Length; i++)
		{
			TimeElapsed=GetWorld()->GetTimeSeconds() - LaserDots[i].LaserDotTimeStarted;
			if (TimeElapsed > 2)
			{
				if (LaserDots.Length > 1)
				{
					j=i;
					if (j < LaserDots.Length - 1)
					{
						LaserDots[j]=LaserDots[j + 1];
						j ++;
					}
					LaserDots.Length=LaserDots.Length - 1;
					i -= 1;
				}
				else
				{
					LaserDots.Length=0;
				}
			}
			else
			{
				TimeScale=1 - TimeElapsed / 2;
				Alpha=TimeScale * LaserDots[i].LaserDotIntensity * 255;
				if (Alpha > 0)
				{
					Canvas->SetDrawColor(255,255,255,TimeScale * LaserDots[i].LaserDotIntensity * 255);
					Canvas->Style=7;
					Canvas->SetPos(0,0);
					Canvas->DrawTile(LaserDotOverlay,Canvas->SizeX,Canvas->SizeY,0,0,512,512);
				}
			}
		}
		Canvas->Style=Canvas->Default.Style;
	*/
}
FString AHumanController::TwoDigitString(int32 Num)
{
	if (Num < 10 && Num >= 0)
	{
		return "0" + FString::FromInt(Num);
	}
	else
	{
		return FString::FromInt(Num);
	}
}
bool AHumanController::CheckFlashTime()
{
	float deltaT;
	float deltaF;
		
	deltaT= (GetWorld()->GetTimeSeconds()) - fLastFlashTime;
	deltaF=1 / 2 * 2;
	if (deltaT > deltaF * 2)
	{
		fLastFlashTime= GetWorld()->GetTimeSeconds();
		return false;
	}
	else
	{
		if (deltaT > deltaF)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void AHumanController::SetStartupStage(EStartupStage Stage)
{
	StartupStage=Stage;
	if (StartupStage == EStartupStage::STAGE_Starting)
	{
		NotifyStartupStage(false);
	}
	else
	{
		if (StartupStage == EStartupStage::STAGE_MatchInProgress)
		{
			NotifyStartupStage(true);
		}
	}
}
void AHumanController::NotifyStartupStage(bool bfadein)
{
	
	if (bfadein == true && bFlushOnRoundRestart == true)
	{
		//ConsoleCommand("flush");
	}
	DoFade(bfadein,true,1.25f, 0.0f);
	
}
void AHumanController::PlayStartupMessage(UCanvas* Canvas)
{
	Canvas->SetDrawColor(255, 0, 0, 255);
	//Canvas->SetPos(50, 50);
	switch(StartupStage)
	{
	case EStartupStage::STAGE_WaitForEnoughPlayers:
		//Canvas->DrawText("Startup: Waiting for other players before starting match");
		break;
	case EStartupStage::STAGE_WaitForReadyPlayers:
		//Canvas->DrawText("Startup: Waiting for all players to be ready");
		break;
	case EStartupStage::STAGE_Starting:
		//Canvas->DrawText("Startup: Match is starting in a few seconds ...");
		break;
	case EStartupStage::STAGE_Dead:
		//Canvas->DrawText("Startup: YOU ARE DEAD! Waiting for next match to start");
		break;
	case EStartupStage::STAGE_CanRespawn:
		//Canvas->DrawText("Startup: YOU ARE DEAD! Press any key to respawn.");
		break;
	case EStartupStage::STAGE_Spectator:
		//Canvas->DrawText("Startup: Spectator");
		break;
	case EStartupStage::STAGE_Autobalance:
		//Canvas->DrawText("Startup: AutoBalancing has moved you to the other team");
		break;
	case EStartupStage::STAGE_MatchOver:
		//Canvas->DrawText("Startup: Match is over! Preparing for new match");
		break;
	case EStartupStage::STAGE_Connecting:
		//Canvas->DrawText("Startup: Connecting to the game...");
		break;
	case EStartupStage::STAGE_WaitingForNextMatch:
		//Canvas->DrawText("Startup: You must wait for the next match to join the game");
		break;
	case EStartupStage::STAGE_LostConnection:
		//Canvas->DrawText("Startup: Lost Connection");
		break;
	case EStartupStage::STAGE_MatchInProgress:
		//Canvas->DrawText("Startup: Match In Progress - IGNORE THIS!");
		break;
	default:
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::PlayStartupMessage()	Unknown StartupStage " $ StartupStage));
		break;
	}
}

void AHumanController::FlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
	if (bGodMode)
	{
		return;
	}
	if (_FlashEffect != nullptr && VisIntensity != 0)
	{
		_FlashEffect->StartFlash(Duration,VisIntensity,this);
	}
	if (AudIntensity != 0)
	{
		_FlashSoundTime += Duration * AudIntensity * 1.5;
		_FlashSoundUpdate=0;
		_FlashSoundIntensity=AudIntensity;
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientFlashBanged(Duration,VisIntensity,AudIntensity);
	}
}

void AHumanController::ClientFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
	if (bGodMode)
	{
		return;
	}
	if (_FlashEffect != nullptr && VisIntensity != 0)
	{
		_FlashEffect->StartFlash(Duration,VisIntensity,this);
	}
	if (AudIntensity != 0)
	{
		_FlashSoundTime += Duration * AudIntensity * 1.5;
		_FlashSoundUpdate=0;
		_FlashSoundIntensity=AudIntensity;
	}
}

void AHumanController::GrenadeExploded(float Duration, float Intensity)
{
	/*
		if (Level.GamePlayMode == 1)
		{
			Intensity *= 0.5;
		}
		StartScreenShake(Duration * Intensity);
	*/
}

void AHumanController::Grenaded(float Duration, float AudIntensity)
{
	/*
		if (AudIntensity != 0)
		{
			_GrenadeSoundTime += Duration;
			_GrenadeSoundUpdate=0;
			_GrenadeSoundIntensity=AudIntensity;
		}
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			ClientGrenaded(Duration,AudIntensity);
		}
	*/
}

void AHumanController::ClientGrenaded(float Duration, float AudIntensity)
{
	if (AudIntensity != 0)
	{
		_GrenadeSoundTime += Duration;
		_GrenadeSoundUpdate=0;
		_GrenadeSoundIntensity=AudIntensity;
	}
}

void AHumanController::StartScreenShake(float ShakeTime)
{
	/*
		_GrenadeShakeTime=FMax(_GrenadeShakeTime,ShakeTime);
		_GrenadeShakeUpdate=0;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			ClientStartScreenShake(_GrenadeShakeTime);
		}
	*/
}

void AHumanController::ClientStartScreenShake(float ShakeTime)
{
	_GrenadeShakeTime=ShakeTime;
	_GrenadeShakeUpdate=0;
}

void AHumanController::ClientStartViewShake(int32 NewHitShakeAngle, float NewHitShakeOffset, float NewHitShakeMin, float NewHitShakeMax, float NewHitShakeRate)
{
	FRotator ShakeRotator;
	HitShakeVector = FVector(1,0,0);
	ShakeRotator.Pitch = 0;
	ShakeRotator.Yaw = NewHitShakeAngle;
	ShakeRotator.Roll = 0;
	//Normalize(ShakeRotator);
	HitShakeOffset = NewHitShakeOffset;
	HitShakeMin = NewHitShakeMin;
	HitShakeMax = NewHitShakeMax;
	HitShakeRate = NewHitShakeRate;
	//HitShakeVector = HitShakeVector >> ShakeRotator;
}

void AHumanController::PostRender(UCanvas* Canvas)
{
	/*
		local float fFadeTime;
		local int iFadePos;
		local Object.Color OldColor;
		local Object.Color FadeToColor;
		local name Anim;
		local float frame;
		local float Rate;
		if (_bAutoTraceDebug || _bPermaTraceDebug)
		{
			if (_AnimPawn != nullptr)
			{
				Canvas->SetPos(0,0);
				Canvas->DrawText("bWantsToCrouch: " $ _AnimPawn.bWantsToCrouch $ " bIsCrouched: " $ _AnimPawn.bIsCrouched $ " bWantsToProne: " $ _AnimPawn.bWantsToProne $ " bIsProne: " $ _AnimPawn.bIsProne);
				if (_AnimPawn.Attached.Length > 0)
				{
					Canvas->SetPos(0,50);
					Canvas->DrawText("Attached[0]: " $ _AnimPawn.Attached[0]);
				}
				_AnimPawn.GetAnimParams(0,Anim,frame,Rate);
				Canvas->SetPos(0,100);
				Canvas->DrawText("AnimSequence " $ Anim $ " Frame " $ frame $ " Rate " $ Rate $ " Rot:" $ _AnimPawn.Rotation);
				if (_AnimPawn.Controller != nullptr)
				{
					Canvas->SetPos(0,120);
					Canvas->DrawText("Controller Rot:" $ _AnimPawn.Controller.Rotation);
				}
				Canvas->SetPos(0,140);
				Canvas->DrawText("Location: " $ _AnimPawn.Location);
				Canvas->SetPos(0,150);
				Canvas->DrawText("Base: " $ _AnimPawn.Base);
				Canvas->SetPos(0,160);
				Canvas->DrawText("OnLadder " $ _AnimPawn.OnLadder);
				Canvas->SetPos(0,170);
				Canvas->DrawText("Physics " $ _AnimPawn.Physics);
				Canvas->SetPos(0,180);
				Canvas->DrawText("UpperBodyAnim" @ _AnimPawn.UpperBodyAnim @ "FullBodyAnim" @ _AnimPawn.FullBodyAnim);
			}
			Canvas->SetPos(Canvas->SizeX / 2,Canvas->SizeY / 2);
			Canvas->DrawText(_AutoTraceString);
		}
		if (bCheatVerbose)
		{
			PlayStartupMessage(Canvas);
		}
		if (! _bFirstFadeIn)
		{
			if (Level != nullptr && Level.Game != nullptr && Level.Game.GetScreenplay() != nullptr)
			{
				DoFade(True,True,3);
			}
			if (MyHUD != nullptr && MyHUD.PlayerConsole != nullptr)
			{
				MyHUD.PlayerConsole.bNoDrawWorld=False;
			}
			_bFirstFadeIn=True;
		}
		if (_bFade)
		{
			Canvas->bNoSmooth=True;
			fFadeTime=GetWorld()->GetTimeSeconds() - _fFadeStartTime;
			OldColor=Canvas->DrawColor;
			Canvas->SetPos(0,0);
			if (_bFadeBlack)
			{
				FadeToColor.R=0;
				FadeToColor.G=0;
				FadeToColor.B=0;
			}
			else
			{
				FadeToColor.R=255;
				FadeToColor.G=255;
				FadeToColor.B=255;
			}
			fFadeTime=FClamp(fFadeTime / _fFadeTime,0,1);
			if (fFadeTime == 1 && _bFadeIn)
			{
				_bFade=False;
			}
			if (! _bFadeIn)
			{
				iFadePos=255 * fFadeTime;
			}
			else
			{
				iFadePos=255 - 255 * fFadeTime;
			}
			FadeToColor.A=iFadePos * _fFadePercentage;
			Canvas->Style=6;
			Canvas->DrawColor=FadeToColor;
			Canvas->DrawTile(Texture'White',Canvas->SizeX,Canvas->SizeY,0,0,16,16);
			Canvas->DrawColor=OldColor;
			Canvas->bNoSmooth=False;
		}
		Canvas->Style=Canvas->Default.Style;
	*/
}

void AHumanController::SetPlayTips(FString InVal, FString inval2, float ttl)
{
	Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(ttl,InVal,inval2);
}

void AHumanController::CalcFirstPersonView(FVector CameraLocation, FRotator CameraRotation)
{
	/*
		CalcFirstPersonView(CameraLocation,CameraRotation);
		if (IsInState('PlayerRolling') && Pawn.fRollTime > 0)
		{
			CameraRotation.Roll += 65536 * Pawn.Default.fRollTime - Pawn.fRollTime / Pawn.Default.fRollTime * Pawn.iRollDirection;
		}
	*/
}

void AHumanController::CycleZoom()
{
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->Weapon->CycleZoom();
	}
}

void AHumanController::TRUnZoomWeapon()
{
}

void AHumanController::TRZoomWeapon()
{
}

void AHumanController::TRCrouchDown()
{
}

void AHumanController::TRUnCrouch()
{
}

void AHumanController::Zoom()
{
	if (CanUseWeapon(6))
	{
		if (bAutoWalkZoom)
		{
			if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsZoomed())
			{
				Cast<AAGP_Pawn>(GetPawn())->SetWalking(bSavedWalkingState);
			}
			else
			{
				bSavedWalkingState= Cast<AAGP_Pawn>(GetPawn())->bIsWalking;
				Cast<AAGP_Pawn>(GetPawn())->SetWalking(true);
			}
		}
		Cast<AAGP_Pawn>(GetPawn())->Weapon->ToggleZoom();
	}
}

void AHumanController::NV()
{
	if (GetPawn() == nullptr || Cast<AAGP_HUD>(MyHUD) != nullptr && Cast<AAGP_HUD>(MyHUD)->bShowMainMenu == true)
	{
		return;
	}
	/*
	if (Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->_Scope->HasNVMode() && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsZoomed())
	{
		Cast<AAGP_Pawn>(GetPawn())->Weapon->NV();
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->ToggleOptics();
	}
}
void AHumanController::Shadows(FString parm)
{
	/*
		if (parm ~= "none" || parm ~= "off")
		{
			Level.ShadowDetail=SHADOW_None;
			ClientMessage("Shadows disabled.");
		}
		else
		{
			if (parm ~= "blob")
			{
				Level.ShadowDetail=SHADOW_Blob;
				ClientMessage("Using blob shadows.");
			}
			else
			{
				if (parm ~= "detail")
				{
					Level.ShadowDetail=SHADOW_Detail;
					ClientMessage("Using detailed shadows.");
				}
			}
		}
		Level.SaveConfig();
	*/

}
void AHumanController::SetBloom(bool bNewBloomMode)
{
}
void AHumanController::Bloom(FString parm)
{
	if (parm == "0" || parm == "off")
	{
		SetBloom(false);
	}
	else
	{
		SetBloom(true);
	}
}
bool AHumanController::CanLean()
{
	/*
		if (GetPawn() == nullptr || IsInState('PlayerParachuting'))
		{
			return false;
		}
		if (GetLockMovement() || GetLockRotation())
		{
			return false;
		}
	*/
	return Cast<AAGP_Pawn>(GetPawn())->CanLean();
	
}
void AHumanController::ServerWantsToRoll(bool bRollLeft)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		RequestCombatRoll(bRollLeft);
	}
}
void AHumanController::RequestCombatRoll(bool bRollLeft)
{
	if (GetPawn() != nullptr)
	{
		if (bNoRoll)
		{
			return;
		}
		if (! (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && !Cast<AAGP_Pawn>(GetPawn())->CanCombatRoll(false)))
		{
			return;
		}
		if (GetNetMode() == ENetMode::NM_Client)
		{
			ServerWantsToRoll(bRollLeft);
		}
		if (bRollLeft)
		{
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollLeft=true;
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollRight=false;
		}
		else
		{
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollLeft=false;
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollRight=true;
		}
	}
}
void AHumanController::LeanLeft()
{
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->bIsProne)
	{
		RequestCombatRoll(true);
		return;
	}
	if (! CanLean() || ! bToggleLean)
	{
		return;
	}
	Cast<AAGP_Pawn>(GetPawn())->LeanLeft(false);
}
void AHumanController::LeanRight()
{
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->bIsProne)
	{
		RequestCombatRoll(false);
		return;
	}
	if (! CanLean() || ! bToggleLean)
	{
		return;
	}
	Cast<AAGP_Pawn>(GetPawn())->LeanRight(false);
}

void AHumanController::LeanCenter()
{
	if (GetPawn() != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->ResetLean();
	}
}

void AHumanController::ViewShake(float DeltaTime)
{
	/*
		local Object.Rotator ViewRotation;
		local int Delta;
		ViewShake(DeltaTime);
		if (HitShakeRate != 0)
		{
			ViewRotation=Rotation;
			Delta=DeltaTime * HitShakeRate;
			ViewRotation.Pitch += Delta * HitShakeVector.X;
			ViewRotation.Yaw += Delta * HitShakeVector.Y;
			HitShakeOffset += Delta;
			if (HitShakeRate > 0)
			{
				if (HitShakeOffset >= HitShakeMax)
				{
					HitShakeRate *= -0.5;
				}
			}
			else
			{
				if (HitShakeOffset <= HitShakeMin)
				{
					HitShakeRate=0;
				}
			}
			SetRotation(ViewRotation);
		}
	*/
}

void AHumanController::UpdateTimers(float DeltaTime)
{
	
	if (_GrenadeShakeTime > 0)
	{
		_GrenadeShakeTime -= DeltaTime;
		_GrenadeShakeUpdate -= DeltaTime;
		if (_GrenadeShakeUpdate < 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			//_GrenadeShakeUpdate=0.1 + 0.15 * FRand();
		}
	}
		
	if (_FlashSoundTime > 0)
	{
		_FlashSoundTime -= DeltaTime;
		_FlashSoundUpdate -= DeltaTime;
		if (_FlashSoundUpdate < 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			//_FlashSoundUpdate=GetSoundDuration(FlashBangDistortion);
			//ResetSoundDampening();
			if (_FlashSoundUpdate > _FlashSoundTime)
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Flash Sound Intensity= %f"), _FlashSoundIntensity);
				}
				//ViewTarget.PlaySound(FlashBangDistortionFade,0,_FlashSoundIntensity,,,,false);
			}
			else
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Flash Sound Intensity= %f"), _FlashSoundIntensity);
				}
				//ViewTarget.PlaySound(FlashBangDistortion,0,_FlashSoundIntensity,,,,false);
			}
			CalcSoundDampening();
		}
	}
	if (_GrenadeSoundTime > 0)
	{
		_GrenadeSoundTime -= DeltaTime;
		_GrenadeSoundUpdate -= DeltaTime;
		if (_GrenadeSoundUpdate < 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			//_GrenadeSoundUpdate=GetSoundDuration(GrenadeDistortion);
			//ResetSoundDampening();
			if (_GrenadeSoundUpdate > _GrenadeSoundTime)
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Grenade Sound Intensity= %f"), _GrenadeSoundIntensity);
				}
				//ViewTarget.PlaySound(GrenadeDistortionFade,0,_GrenadeSoundIntensity,,,,false);
			}
			else
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Grenade Sound Intensity= %f"), _GrenadeSoundIntensity);
				}
				//ViewTarget->PlaySound(GrenadeDistortion,0,_GrenadeSoundIntensity,,,,false);
			}
			CalcSoundDampening();
		}
	}
}

void AHumanController::Mantle(FVector out_Point, FVector out_Normal)
{
}

void AHumanController::DevBug()
{
	/*
		if (Player.bFullScreen)
		{
			ConsoleCommand("togglefullscreen");
		}
		ConsoleCommand("start http://192.168.0.2/ttweb/intbugreport.html");
	*/
}
bool AHumanController::ClientOpenMenu(FString Menu, bool bDisconnect, FString Msg1, FString Msg2)
{
		//Org:
		bAction=0;
		//bLastAction=0;
		//ChangeActionStatus(bAction);
		//return ClientOpenMenu(Menu,bDisconnect,Msg1,Msg2);

		//Copied from PlayerController:

		//if (bDemoOwner && Menu != DemoMenuClass)
		//{
		//	return false;
		//}
		//bAction = 0;

		//if (!Player.GUIController.OpenMenu(Menu, Msg1, Msg2))
		//{
		//	//UnPressButtons();
		//	return false;
		//}
		if (bDisconnect)
		{
			Player->ConsoleCommand("Disconnect");
			return true;
		}

		return true;

}
void AHumanController::AGPGameMenu()
{
		//ClientCloseMenu(True);
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->ToggleAGPGameMenu();
		}
}
void AHumanController::AGPMainMenu()
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->CloseAllMenus();
	}
	ClientOpenMenu("AGP_Interface.AAIntroMoviePage",false,"","");
}
void AHumanController::AGPLoginMenu()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->CloseAllMenus();
	}
	ClientOpenMenu("AGP_Interface.AAPreLoginPage",false,"","");
}

void AHumanController::AGPSplashScreen()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->CloseAllMenus();
	}
	ClientOpenMenu("AGP_Interface.AAIntroMoviePage",false,"","");
}

void AHumanController::OldMainMenu()
{
	return;
	//ClientCloseMenu(True);
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->ToggleAGPMainMenu();
	}
}

void AHumanController::AGPMissionResults()
{
	ClientOpenMenu("AGP_Interface.AAMissionCompletePage",false,"","");
}

void AHumanController::RadarSetZoom(float Meters)
{
	if (Meters >= 1)
	{
		float test = (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarMapSize / Meters) * 52.200001;
		RadarZoom=FMath::Clamp(test,1.0f,1000.f);
	}
}

void AHumanController::RadarGetZoom()
{
	//return Round(Level.RadarMapSize / RadarZoom * 52.200001);
}

void AHumanController::SAIZoomIn()
{
	//if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo->VehicleReplicationInfo != nullptr)
	//{
	//	return;
	//}
	if (RadarZoomLevelIndex < Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Max() - 1)
	{
		RadarZoomLevelIndex ++;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Max() > RadarZoomLevelIndex)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[RadarZoomLevelIndex]);
	}
}
void AHumanController::SAIZoomOut()
{
		//if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.VehicleReplicationInfo != nullptr)
		//{
		//	return;
		//}
		if (RadarZoomLevelIndex > 0)
		{
			RadarZoomLevelIndex --;
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Max() > RadarZoomLevelIndex)
		{
			RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[RadarZoomLevelIndex]);
		}
}
void AHumanController::ToggleSAIPlayerInfo()
{
	 bRadarShowPlayerInfo = !bRadarShowPlayerInfo;
}
void AHumanController::ToggleSAISize()
{
	bFullsizeRadar = !bFullsizeRadar;
}
void AHumanController::EnemySpotted()
{
	/*
		local bool bOldBlockZeroExtent;
		local Actor Other;
		local Object.Rotator CameraRotation;
		local float MaxTraceLength;
		local FVector StartTrace;
		local FVector EndTrace;
		local FVector HitLocation;
		local FVector HitNormal;
		if (PlayerReplicationInfo.isDead() || GetNetMode() == ENetMode::NM_Standalone || CheckRIFlood() || CheckRIFlood())
		{
			return;
		}
		MaxTraceLength=12000;
		PlayerCalcView(Other,StartTrace,CameraRotation);
		EndTrace=StartTrace + MaxTraceLength *  Vector(CameraRotation);
		bOldBlockZeroExtent=Pawn.bBlockZeroExtentTraces;
		Pawn.bBlockZeroExtentTraces=False;
		Other=Trace(HitLocation,HitNormal,EndTrace,StartTrace,True);
		Pawn.bBlockZeroExtentTraces=bOldBlockZeroExtent;
		if (Other != nullptr)
		{
			CommoRadio();
			CommoSendMessage(4);
			ServerEnemySpotted(HitLocation.X,HitLocation.Y,HitLocation.Z);
			ClientEnemySpotted(HitLocation.X,HitLocation.Y,HitLocation.Z);
		}
	*/
}
void AHumanController::ServerEnemySpotted(float SpottedX, float SpottedY, float SpottedZ)
{
	/*
		local int i;
		Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_CombatEnemyContactTime(GetWorld()->GetTimeSeconds);
		for (i=0; i<PlayerReplicationInfo.Team.NumRequestSlots; i++)
		{
			if (PlayerReplicationInfo.Team.ActualList_Player[i] != nullptr && PlayerReplicationInfo.Team.ActualList_Player[i] != PlayerReplicationInfo)
			{
				HumanController(PlayerReplicationInfo.Team.ActualList_Player[i].Owner).ClientEnemySpotted(SpottedX,SpottedY,SpottedZ);
			}
		}
	*/

}
void AHumanController::ClientEnemySpotted(float SpottedX, float SpottedY, float SpottedZ, float SpotDuration)
{
	/*
		local int i;
		local HumanController.EnemySpottedData SpottedEnemy;
		local bool bFoundEnemy;
		ClearOldEnemiesSpotted();
		Log("ClientEnemySpotted");
		bFoundEnemy=False;
		i=0;
		if (i < EnemiesSpotted.Length)
		{
			if (EnemiesSpotted[i].SpottedLocation.X == SpottedX && EnemiesSpotted[i].SpottedLocation.Y == SpottedY)
			{
				bFoundEnemy=True;
			}
			else
			{
				++ i;
			}
		}
		if (! bFoundEnemy)
		{
			Log("didnt find enemy, adding new one");
			SpottedEnemy.SpottedLocation.X=SpottedX;
			SpottedEnemy.SpottedLocation.Y=SpottedY;
			SpottedEnemy.SpottedLocation.Z=SpottedZ;
			SpottedEnemy.TimeSpottedSeconds=GetWorld()->GetTimeSeconds();
			SpottedEnemy.BlinkStartTime=GetWorld()->GetTimeSeconds();
			SpottedEnemy.BlinkEndTime=SpottedEnemy.BlinkStartTime + 2;
			Log("spot enemy duration=" @ SpotDuration);
			if (SpotDuration == 0)
			{
				SpottedEnemy.LifeSpan=8;
			}
			else
			{
				SpottedEnemy.LifeSpan=SpotDuration;
			}
			EnemiesSpotted[EnemiesSpotted.Length]=SpottedEnemy;
		}
	*/
}
void AHumanController::ClearOldEnemiesSpotted()
{
	/*
		int32 i;
		i=0;
		if (i < EnemiesSpotted.Length)
		{
			if (GetWorld()->GetTimeSeconds() - EnemiesSpotted[i].TimeSpottedSeconds > EnemiesSpotted[i].LifeSpan)
			{
				EnemiesSpotted.remove (i,1);
			}
			else
			{
				++ i;
			}
		}
	*/
}
void AHumanController::ESSObjectSpotted(AAGP_Objective* Objective)
{
	if (Objective != nullptr)
	{
		/*
		Log(Objective $ " was found and reported as a Non Lethal ES2.");
		ServerESSSpotted(Objective.Location.X,Objective.Location.Y,Objective.Location.Z,Objective.isDangerous());
		ClientESSSpotted(Objective.Location.X,Objective.Location.Y,Objective.Location.Z,Objective.isDangerous());
		*/
	}
}
void AHumanController::ServerESSSpotted(float SpottedX, float SpottedY, float SpottedZ, bool bLetal)
{
	/*
		local int i;
		for (i=0; i<PlayerReplicationInfo.Team.NumRequestSlots; i++)
		{
			if (PlayerReplicationInfo.Team.ActualList_Player[i] != nullptr && PlayerReplicationInfo.Team.ActualList_Player[i] != PlayerReplicationInfo)
			{
				HumanController(PlayerReplicationInfo.Team.ActualList_Player[i].Owner).ClientESSSpotted(SpottedX,SpottedY,SpottedZ,bLetal);
			}
		}
	*/
}
void AHumanController::ClientESSSpotted(float SpottedX, float SpottedY, float SpottedZ, bool bLethal)
{
	int32 i;
	FESSObjectData SpottedESSObject;
	bool bFoundES2Object;
	ClearOldNonLethalESSSpotted();
	bFoundES2Object=false;
	i=0;
	if (i < FoundESSObject.Max())
	{
		if (FoundESSObject[i].SpottedLocation.X == SpottedX && FoundESSObject[i].SpottedLocation.Y == SpottedY)
		{
			bFoundES2Object=true;
		}
		else
		{
			++ i;
		}
	}
	if (! bFoundES2Object)
	{
		UE_LOG(LogTemp, Log, TEXT("Adding a spotted ES2 object to the array."));
		SpottedESSObject.SpottedLocation.X=SpottedX;
		SpottedESSObject.SpottedLocation.Y=SpottedY;
		SpottedESSObject.SpottedLocation.Z=SpottedZ;
		SpottedESSObject.TimeSpottedSeconds=GetWorld()->GetTimeSeconds();
		SpottedESSObject.BlinkStartTime=GetWorld()->GetTimeSeconds();
		SpottedESSObject.BlinkEndTime=SpottedESSObject.BlinkStartTime + 2;
		SpottedESSObject.LifeSpan=8;
		SpottedESSObject.bLethal=bLethal;
		FoundESSObject[FoundESSObject.Max()]=SpottedESSObject;
	}
}
void AHumanController::ClearOldNonLethalESSSpotted()
{
	/*
		local int i;
		i=0;
		if (i < FoundESSObject.Length)
		{
			if (GetWorld()->GetTimeSeconds() - FoundESSObject[i].TimeSpottedSeconds > FoundESSObject[i].LifeSpan && ! FoundESSObject[i].bLethal)
			{
				FoundESSObject.remove (i,1);
			}
			else
			{
				++ i;
			}
		}
	*/
}
void AHumanController::ServerPlaySound(USoundBase* ASound)
{
	/*
		local int i;
		for (i=0; i<PlayerReplicationInfo.Team.NumRequestSlots; i++)
		{
			if (PlayerReplicationInfo.Team.ActualList_Player[i] != nullptr && PlayerReplicationInfo.Team.ActualList_Player[i] != PlayerReplicationInfo)
			{
				HumanController(PlayerReplicationInfo.Team.ActualList_Player[i].Owner).ClientPlaySound(ASound);
			}
		}
	*/
}
void AHumanController::Jump(float F)
{
	/*
		if (IsInState('PlayerRolling') || GetLockMovement())
		{
			return;
		}
		if (Pawn.Weapon != nullptr)
		{
			Pawn.Weapon.ForceUnzoom();
		}
		if (Pawn != nullptr)
		{
			Pawn.ResetLean();
			if (Pawn.bIsCrouched || Pawn.bIsProne)
			{
				Pawn.ShouldStand();
				return;
			}
			if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyReloading'))
			{
				return;
			}
			if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyFixingJam'))
			{
				return;
			}
			if (Pawn.LandBob < -0.01)
			{
				return;
			}
			if (Pawn.CanJump())
			{
				Pawn.bMidJump=True;
				Jump(F);
			}
		}
	*/
}

bool AHumanController::HandlePickupQuery(APickup* Item)
{
	return true;
}

void AHumanController::HandlePickup(APickup* pick)
{
}

bool AHumanController::CanSwapHands()
{
	/*
		if (Pawn == nullptr)
		{
			return false;
		}
		if (Pawn.Physics == 2 || Pawn.IsInState('BusyPostureChange'))
		{
			ClientMessage("You cannot swap weapons while you are busy adjusting your position.");
			return false;
		}
		if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusySupporting') || Pawn.Weapon.IsInState('BusyFixingJam') || Pawn.Weapon.IsInState('BusyZooming'))
		{
			return false;
		}
		if (Pawn.bIsSprinting)
		{
			ClientMessage("You cannot swap weapons while sprinting.");
			return false;
		}
		if (bAction != 0)
		{
			ClientMessage("You cannot change weapons while you are busy.");
			return false;
		}
		if (Pawn.Weapon != nullptr && Pawn.Weapon.IsA('Weapon_AT4_Rocket') || Pawn.Weapon.IsA('Weapon_BDM_Rocket'))
		{
			if (! AGP_Weapon(Pawn.Weapon).HasAmmo())
			{
				ClientMessage("Drop the empty weapon and then switch to your primary weapon.");
				return false;
			}
		}
		return Pawn.CanSwapHands();

	*/

	return false;       //FAKE /ELiZ
}
void AHumanController::SwapHands()
{
	/*
		local AGP_Weapon AGPWeap;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			Log("HumanController::SwapHands - CanSwapHands" @ CanSwapHands());
		}
		if (! CanSwapHands())
		{
			return;
		}
		DesiredFOV=DefaultFOV;
		SetFOVAngle(DefaultFOV);
		Cast<AAGP_Pawn>(GetPawn()).StopSprint();
		if (Cast<AAGP_Pawn>(GetPawn()).Weapon != nullptr)
		{
			if (Cast<AAGP_Pawn>(GetPawn()).Weapon.CheckJavelinTube())
			{
				SwapType=1;
				Reload();
				return;
			}
		}
		AGPWeap=AGP_Weapon(Pawn.Weapon);
		if (Role < 4 && AGPWeap != nullptr)
		{
			AGPWeap.bPendingChangeWeapon=True;
			AGPWeap.PendingChangeWeaponTimeStamp=GetWorld()->GetTimeSeconds() + 1.5;
		}
		ServerSwapHands();
	*/
}
void AHumanController::SwapAltShoulder()
{
	/*
		local AGP_Weapon AGPWeap;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			Log("HumanController::AltShoulder - CanSwapHands" @ CanSwapHands());
		}
		if (! CanSwapHands())
		{
			return;
		}
		if (! CanSwapAltShoulder())
		{
			return;
		}
		DesiredFOV=DefaultFOV;
		SetFOVAngle(DefaultFOV);
		Cast<AAGP_Pawn>(GetPawn()).StopSprint();
		AGPWeap=AGP_Weapon(Pawn.Weapon);
		if (Role < 4 && AGPWeap != nullptr)
		{
			AGPWeap.bPendingChangeWeapon=True;
			AGPWeap.PendingChangeWeaponTimeStamp=GetWorld()->GetTimeSeconds() + 1.5;
		}
		ServerSwapAltShoulder();
	*/
}
bool AHumanController::CanSwapAltShoulder()
{
	AWeapon* weap;
	if (Cast<AAGP_Pawn>(GetPawn())->bIsSprinting)
	{
		ClientMessage("You cannot swap weapons while sprinting.");
		return false;
	}
	if (bAction != 0)
	{
		ClientMessage("You cannot change weapons while you are busy.");
		return false;
	}
	weap=Cast<AAGP_Pawn>(GetPawn())->Weapon;
	if (Cast<AAGP_Pawn>(GetPawn())->_InvAltShoulder->isEmpty())
	{
		return false;
	}
	if (! Cast<AAGP_Pawn>(GetPawn())->_InvShoulder->isEmpty() && Cast<AAGP_Weapon>(weap) != nullptr)
	{
		if (Cast<AAGP_Weapon>(weap)->IsA(APistolWeapon::StaticClass()) || Cast<AAGP_Weapon>(weap)->IsA(AWEAPON_Javelin::StaticClass()) || Cast<AAGP_Weapon>(weap)->IsA(AItem_Binoculars::StaticClass()))
		{
			return true;
		}
		if (Cast<AAGP_Weapon>(weap)->_bLarge)
		{
			return false;
		}
	}
	return true;
}

void AHumanController::ServerSwapHands()
{
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHands();
	}
}

void AHumanController::SwapHip()
{
	AAGP_Weapon* AGPWeap;
	if (! CanSwapHands())
	{
		return;
	}
	DesiredFOV=DefaultFOV;
	//SetFOVAngle(DefaultFOV);
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->CheckJavelinTube())
		{
			SwapType=ESwapType::SType_Hip;
			Reload();
			return;
		}
	}
	AGPWeap=Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon);
	if (GetLocalRole() <  4 && AGPWeap != nullptr)
	{
		AGPWeap->bPendingChangeWeapon=true;
		AGPWeap->PendingChangeWeaponTimeStamp=GetWorld()->GetTimeSeconds() + 1.5;
	}
	ServerSwapHip();
}

void AHumanController::ServerSwapHip()
{
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHip();
	}
}

void AHumanController::ServerForceWeaponUnzoom()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Forcing weapon unzoomed and idle"));
		Cast<AAGP_Pawn>(GetPawn())->Weapon->ForceUnzoom(true);
		//Cast<AAGP_Pawn>(GetPawn())->Weapon->GotoState('None');
	}
}

void AHumanController::ServerSwapAltShoulder()
{
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapAltShoulder();
	}
}

void AHumanController::Grenade(uint8 Index)
{
	bool bDelayedGrenade=false;
	if (bFire != 0 || bAltFire != 0)
	{
		ClientMessage("Stop firing to take out a grenade.");
		return;
	}
	if (GetWorld()->GetTimeSeconds() < fpWaitingForDelayedGrenade && fpWaitingForDelayedGrenade - GetWorld()->GetTimeSeconds() < 0.2)
	{
		return;
	}
	
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Index - 1] == 0)
	{
		return;
	}
	
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->Health <= 0)
	{
		return;
	}
	/*
	if (IsInState('PlayerClimbing') || Pawn.Physics == 11 || Cast<AAGP_Pawn>(GetPawn()).GetCurrentVolume() != nullptr && Cast<AAGP_Pawn>(GetPawn()).GetCurrentVolume().IsA('LadderVolume'))
	{
		ClientMessage("You cannot use grenades while climbing a ladder.");
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn())->bIsSprinting)
	{
		ClientMessage("You cannot swap weapons while sprinting.");
		return;
	}
	if (bAction != 0)
	{
		ClientMessage("You cannot change weapons while you are busy.");
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Parachute::StaticClass()))
	{
		ClientMessage("You cannot use a grenade until your parachute is fully off.");
		return;
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon.IsInState('BusyReloading'))
	{
		ClientMessage("You are busy reloading and cannot select a grenade yet.");
		return;
	}
	*/
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon.IsInState('BusySupporting') || Cast<AAGP_Pawn>(GetPawn())->Weapon->IsInState('BusyFixingJam') || Cast<AAGP_Pawn>(GetPawn())->Weapon->IsInState('BusyZooming'))
	{
		ClientMessage("Your weapon is busy and you cannot select a grenade yet.");
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()))
	{
		/*
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsInState('BusyLoweringWeapon'))
		{
			ClientMessage("You cannot select a grenade until your binoculars are all the way down.");
			return;
		}
		*/
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->IsInState('BusyThrowingGrenade') || Cast<AAGP_Pawn>(GetPawn())->IsInState('BusyDrawingBack'))
	{
		ClientMessage("You haven't finished throwing the last grenade.");
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->SetSupported(false);
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsZoomed())
		{
			bDelayedGrenade = true;
			Cast<AAGP_Pawn>(GetPawn())->Weapon->ToggleZoom();
			ServerForceWeaponUnzoom();
			DesiredFOV = DefaultFOV;
			//SetFOVAngle(DefaultFOV);
		}
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Index - 1] != 0)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->CheckJavelinTube())
		{
			switch(Index)
			{
					case 1:
						SwapType = ESwapType::SType_Frag;
						break;
					case 2:
						SwapType = ESwapType::SType_Smoke;
						break;
					case 3:
						SwapType = ESwapType::SType_Flash;
						break;
					case 4:
						SwapType = ESwapType::SType_Incendiary;
						break;
					case 5:
						SwapType = ESwapType::SType_PDM;
						break;
					case 6:
						SwapType = ESwapType::SType_DoorBreacher;
						break;
					case 7:
						SwapType = ESwapType::SType_GreenSmoke;
						break;
					default:
						SwapType = ESwapType::SType_None;
						break;
			}
			Reload();
			return;
		}
		else
		{
			if (bDelayedGrenade)
			{
				switch(Index)
				{
					case 1:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, False, 'GrenadeFrag');
							return;
						}
						break;
					case 2:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, False, 'GrenadeSmoke');
							return;
						}
						break;
					case 3:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, False, 'GrenadeFlash');
							return;
						}
						break;
					case 4:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, False, 'GrenadeIncendiary');
							return;
						}
						break;
					case 5:
						return;
					case 6:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, False, 'DemolitionItem');
							return;
						}
						break;
					case 7:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, False, 'GrenadeSignal');
							return;
						}
						break;
					default:
						break;
				}
			}
		}
	}
	ServerGrenade(Index);
}

void AHumanController::GrenadeFrag()
{
	Grenade(1);
}

void AHumanController::GrenadeSmoke()
{
	Grenade(2);
}

void AHumanController::GrenadeFlash()
{
	Grenade(3);
}

void AHumanController::GrenadeIncendiary()
{
	Grenade(4);
}

void AHumanController::GrenadePDM()
{
}

void AHumanController::DemolitionItem()
{
	Grenade(6);
}

void AHumanController::SignalEnteredPickupZone()
{
}

void AHumanController::GrenadeSignal()
{
	Grenade(7);
}

void AHumanController::binoculars()
{
	if (! CanSwapHands())
	{
		return;
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AWEAPON_Javelin::StaticClass()) || Cast<AAGP_Pawn>(GetPawn())->getHipInventory()->IsA(AWEAPON_Javelin:StaticClass()))
	{
		SwapHip();
		return;
	}
	*/
	ServerBinoculars();
}

void AHumanController::ServerBinoculars()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && !Cast<AAGP_Pawn>(GetPawn())->bHasCLU)
	{
		Cast<AAGP_Pawn>(GetPawn())->GetBinoculars();
	}
}

void AHumanController::Pistol()
{
	if (! CanSwapHands())
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->CheckJavelinTube() && ! Cast<AAGP_Pawn>(GetPawn())->_InvHolster->isEmpty())
		{
			SwapType= ESwapType::SType_Pistol;
			Reload();
			return;
		}
	}
	ServerSwapHolster();
}

void AHumanController::ServerSwapHolster()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHolster();
	}
}

void AHumanController::CommoHand()
{
	CommoMode(ECommoType::COMMOTYPE_Hand);
}

void AHumanController::CommoWhisper()
{
	CommoMode(ECommoType::COMMOTYPE_Hand);
}

void AHumanController::CommoShout()
{
	CommoMode(ECommoType::COMMOTYPE_Shout);
}

void AHumanController::CommoRadio()
{
	CommoMode(ECommoType::COMMOTYPE_Radio);
}

void AHumanController::CommoSquad()
{
	CommoMode(ECommoType::COMMOTYPE_Squad);
}

void AHumanController::CommoGlobal()
{
	CommoMode(ECommoType::COMMOTYPE_Global);
}

void AHumanController::ServerGrenade(uint8 Index)
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->GetGrenade(Index);
	}
}

void AHumanController::ThrowWeapon()
{
	if (Cast<AAGP_Pawn>(GetPawn()) == nullptr || Cast<AAGP_Pawn>(GetPawn())->Weapon == nullptr)
	{
		return;
	}
	if (bAutoWalkZoom)
	{
		Cast<AAGP_Pawn>(GetPawn())->SetWalking(bSavedWalkingState);
	}
	ServerThrowWeapon();
}

void AHumanController::IncreaseRange()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()) && bMortarSpotter)
		{
			if (iSpotterPolarRangeSetting < 1500)
			{
				iSpotterPolarRangeSetting += 10;
			}
		}
		else
		{
			Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->IncreaseElevation();
		}
	}
}

void AHumanController::DecreaseRange()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()) && bMortarSpotter)
		{
			if (iSpotterPolarRangeSetting > 300)
			{
				iSpotterPolarRangeSetting -= 10;
			}
		}
		else
		{
			Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->DecreaseElevation();
		}
	}
}

void AHumanController::ZeroRange()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()) && bMortarSpotter)
		{
			iSpotterPolarRangeSetting=600;
		}
		else
		{
			Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->ZeroElevation();
		}
	}
}

void AHumanController::FastMove()
{
	//Super::FastMove();
	if (Cast<AAGP_Pawn>(GetPawn()) != NULL)
	{
		Cast<AAGP_Pawn>(GetPawn())->CheckInventoryOverload();
	}
}

void AHumanController::ServerThrowWeapon()
{
	if (bNoThrowWeapon || ! CanUseWeapon(7))
	{
		return;
	}
	Cast<AAGP_Pawn>(GetPawn())->SetZoomed(false);
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()))
	{
		if (CanSwapHands())
		{
			ServerBinoculars();
		}
		return;
	}
	else
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(APistolWeapon::StaticClass()))
		{
			if (CanSwapHands())
			{
				ServerSwapHolster();
			}
			return;
		}
	}
	//Cast<AAGP_Pawn>(GetPawn())->TossWeapon(Cast<AAGP_Pawn>(GetPawn())->Velocity +  Vector(Rotation) * 200 + vect(0 0 150));
}
void AHumanController::SetIndex(int32 i)
{
	/*
		local string sFile;
		local string sSection;
		if (i < 0)
		{
			i=0;
		}
		sFile=GetBaseDir() $ "WeaponMods.ini";
		sSection=GetPrivateProfileString(sFile,"WeaponMods","CurrentWeapon");
		SetPrivateProfileInt(i,sFile,sSection,"CurrentIndex");
		SavePrivateProfile(sFile);
		SetWeaponMods();
	*/
}
void AHumanController::SetIndexName(int32 i, FString S)
{
	/*
		local string sFile;
		local string sSection;
		if (i < 0)
		{
			i=0;
		}
		if (S == "")
		{
			S="Set " $ i + 1;
		}
		sFile=GetBaseDir() $ "WeaponMods.ini";
		sSection=GetPrivateProfileString(sFile,"WeaponMods","CurrentWeapon");
		SetPrivateProfileString(S,sFile,sSection,"IndexName(" $ i $ ")");
		SavePrivateProfile(sFile);
	*/
}
void AHumanController::SetWeapon(FString S)
{
	/*
		local string sFile;
		WM_CurrentWeapon=GetLegalWeapon(S);
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
		sFile=GetBaseDir() $ "WeaponMods.ini";
		SetPrivateProfileString(WM_CurrentWeapon,sFile,"WeaponMods","CurrentWeapon");
		SetWeaponMods();
		SaveWeaponMods();
	*/
}
void AHumanController::SetMod(int32 i, FString S)
{
	if (i < 0 || i >= 6)
	{
		return;
	}
	WM_Slot[i]=GetLegalMod(S);
	SaveWeaponMods();
}
void AHumanController::CubePics(uint8 Index)
{
	/*
		local CubeMapMaker C;
		if (Index == 0)
		{
			ForEach AllActors('CubeMapMaker',C)
			{
				C.Begin();
				return;
			}
			C=Spawn('CubeMapMaker',,,Pawn.EyePosition());
			if (C != nullptr)
			{
				Log("HumanController::CubePics(): CubeMapMaker created");
				C.Begin();
				C.DestroyOnFinish(True);
			}
			else
			{
				Log("HumanController::CubePics(): Couldn't spawn CubeMapMaker");
			}
		}
		else
		{
			C=Spawn('CubeMapMaker',,,Pawn.EyePosition());
			if (C != nullptr)
			{
				Log("HumanController::CubePics(): CubeMapMaker created");
				C.Begin(Index);
			}
			else
			{
				Log("HumanController::CubePics(): Couldn't spawn CubeMapMaker");
			}
		}
	*/
}
void AHumanController::GetIndexName(int32 i)
{
	/*
		local string sFile;
		local string sIndexName;
		if (i < 0)
		{
			i=0;
		}
		sFile=GetBaseDir() $ "WeaponMods.ini";
		sIndexName=GetPrivateProfileString(sFile,WM_CurrentWeapon,"IndexName(" $ i $ ")");
		if (sIndexName == "")
		{
			sIndexName="Set " $ i + 1;
		}
		return sIndexName;
	*/
}
void AHumanController::GetCurrentIndexName()
{
	/*
			local string sFile;
			local string sIndexName;
			sFile=GetBaseDir() $ "WeaponMods.ini";
			sIndexName=GetPrivateProfileString(sFile,WM_CurrentWeapon,"IndexName(" $ GetCurrentIndex() $ ")");
			if (sIndexName == "")
			{
				sIndexName="Set " $ GetCurrentIndex() + 1;
			}
			return sIndexName;
	*/

}
void AHumanController::GetLegalWeapon(FString S)
{
	/*
		local class<Weapon>  classW;
		if (S != "")
		{
			if (S != "AGP_Inventory.Weapon_M4A1_Rifle_Mod")
			{
				S="AGP_Inventory.Weapon_M4A1_Rifle_Mod";
			}
			classW=class<Weapon>(DynamicLoadObject(S,Class'Class',True));
			if (classW != nullptr)
			{
				return S;
			}
		}
		return "";
	*/
}
FString AHumanController::GetLegalMod(FString S)
{
	/*
		local class<BaseWeaponMod>  classWM;
		if (S != "")
		{
			classWM=class<BaseWeaponMod>(DynamicLoadObject(S,Class'Class',True));
			if (classWM != nullptr)
			{
				return S;
			}
		}
	*/
	
	return "";
	
}
void AHumanController::GetCurrentIndex()
{
	/*
		local string sFile;
		sFile=GetBaseDir() $ "WeaponMods.ini";
		return GetPrivateProfileInt(sFile,WM_CurrentWeapon,"CurrentIndex");
	*/
}
void AHumanController::GetCurrentMod(int32 Index, int32 Slot)
{
	/*
		local string sFile;
		local string sMod;
		sFile=GetBaseDir() $ "WeaponMods.ini";
		sMod=GetPrivateProfileString(sFile,WM_CurrentWeapon,"Slot_" $ Slot $ "_(" $ Index $ ")");
		return Mid(sMod,Len("AGP_Inventory.WeaponMod_"),Len(sMod));
	*/
}
void AHumanController::SetWeaponMods()
{
	/*
		local string sFile;
		local int Index;
		local string sKey;
		local int i;
		sFile=GetBaseDir() $ "WeaponMods.ini";
		WM_CurrentWeapon=GetPrivateProfileString(sFile,"WeaponMods","CurrentWeapon");
		WM_CurrentWeapon=GetLegalWeapon(WM_CurrentWeapon);
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
		if (WM_CurrentWeapon == "")
		{
			SetPrivateProfileString("",sFile,"WeaponMods","CurrentWeapon");
			SavePrivateProfile(sFile);
			for (i=0; i<6; i++)
			{
				WM_Slot[i]="";
			}
		}
		else
		{
			Index=GetPrivateProfileInt(sFile,WM_CurrentWeapon,"CurrentIndex");
			if (Index < 0)
			{
				Index=0;
				SetIndex(0);
			}
			for (i=0; i<6; i++)
			{
				sKey="Slot_" $ i $ "_(" $ Index $ ")";
				WM_Slot[i]=GetPrivateProfileString(sFile,WM_CurrentWeapon,sKey);
				WM_Slot[i]=GetLegalMod(WM_Slot[i]);
			}
		}
		UploadWeaponMods();
	*/
}
void AHumanController::SaveWeaponMods()
{
	/*
		local string sFile;
		local int Index;
		local string sKey;
		local int i;
		sFile=GetBaseDir() $ "WeaponMods.ini";
		WM_CurrentWeapon=GetLegalWeapon(WM_CurrentWeapon);
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
		if (WM_CurrentWeapon == "")
		{
			SetPrivateProfileString("",sFile,"WeaponMods","CurrentWeapon");
		}
		else
		{
			SetPrivateProfileString(WM_CurrentWeapon,sFile,"WeaponMods","CurrentWeapon");
			Index=GetPrivateProfileInt(sFile,WM_CurrentWeapon,"CurrentIndex");
			if (Index < 0)
			{
				Index=0;
				SetIndex(0);
			}
			for (i=0; i<6; i++)
			{
				sKey="Slot_" $ i $ "_(" $ Index $ ")";
				WM_Slot[i]=GetLegalMod(WM_Slot[i]);
				SetPrivateProfileString(WM_Slot[i],sFile,WM_CurrentWeapon,sKey);
			}
		}
		SavePrivateProfile(sFile);
		UploadWeaponMods();
	*/
}
void AHumanController::UploadWeaponMods()
{
	int32 i;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ServerSetWeaponMods(-1,WM_CurrentWeapon);
		for (i=0; i<6; i++)
		{
			ServerSetWeaponMods(i,WM_Slot[i]);
		}
	}
}
void AHumanController::ServerSetWeaponMods(int32 Slot, FString new_mod)
{
	if (Slot == -1)
	{
		WM_CurrentWeapon=new_mod;
		if (PlayerReplicationInfo != nullptr)
		{
			//PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
	}
	else
	{
		if (Slot >= 0 && Slot < 6)
		{
			WM_Slot[Slot]=new_mod;
		}
	}
}
void AHumanController::SetSkinPreference(FString S)
{
	if (S == "SKINPREF_African")
	{
		ServerSetSkinPreference(ESkinPreference::SKINPREF_African);
	}
	else
	{
		if (S == "SKINPREF_Caucasian")
		{
			ServerSetSkinPreference(ESkinPreference::SKINPREF_Caucasian);
		}
		else
		{
			if (S == "SKINPREF_Latino")
			{
				ServerSetSkinPreference(ESkinPreference::SKINPREF_Latino);
			}
			else
			{
				ServerSetSkinPreference(ESkinPreference::SKINPREF_None);
			}
		}
	}
}

void AHumanController::ServerSetSkinPreference(ESkinPreference newpref)
{
	SkinPreference = newpref;
}
void AHumanController::setFace(FString S)
{
	ServerSetFace(S, true);
}

void AHumanController::SetOpFace(FString S)
{
	ServerSetFace(S, false);
}

void AHumanController::ServerSetFace(FString newface, bool bFriend)
{
	if (bFriend)
	{
		Face = newface;
	}
	else
	{
		OpFace = newface;
	}
}

void AHumanController::ClientResetSpectator()
{
	CleanupLevel();
}

void AHumanController::ClientSetViewTarget2(AActor* Target)
{
	/*
		if (Target == nullptr)
		{
			ServerReSendViewTarget();
			if (IsInState('Spectating'))
			{
				NotifyAdminMessage("Locating this player will take a moment.  Please wait...");
			}
			return;
		}
		SetViewTarget(Target);
	*/

}
void AHumanController::ServerReSendViewTarget()
{
	UE_LOG(LogTemp, Warning, TEXT("Resending View Target to client after moving controller to that location"));
	/*
	SetLocation(ViewTarget.Location);
	SetCustomTimer(0.75, False, 'WaitForPawnToBecomeRelevant');
	*/
}
void AHumanController::WaitForPawnToBecomeRelevant()
{
	UE_LOG(LogTemp, Warning, TEXT("Telling client to try again with view target"));
		/*
		if (ViewTarget == nullptr)
		{
			if (IsInState('Spectating'))
			{
				NotifyAdminMessage("Lost player view, locating next player.  Please wait...");
			}
			ServerNextViewTarget();
			return;
		}
		if (ViewTarget.IsA('Pawn') && Pawn(ViewTarget).Health < 0 && ViewPreference != 3)
		{
			if (IsInState('Spectating'))
			{
				NotifyAdminMessage("Last player died, locating next player.  Please wait...");
			}
			ServerNextViewTarget();
			return;
		}
		ClientSetViewTarget2(ViewTarget);
	*/
}
void AHumanController::GetViewTargetActor(AActor* VT)
{
	/*
		APawn* p;
		p = Cast<APawn>(VT);
		if (p != nullptr && ViewPreference != 3)
		{
			return p->Controller;
		}
		else
		{
			return VT;
		}
	*/
}
void AHumanController::GetNextViewTargetActor(EViewPreference viewpref, AActor* A)
{
	/*
		local Controller C;
		local AGP_Viewpoint V;
		if (viewpref == 3)
		{
			return GetNextViewBody(A);
		}
		if (A == nullptr)
		{
			if (viewpref == 2)
			{
				UE_LOG(LogTemp, Warning, TEXT("HumanController::GetNextViewTargetActor() - returning viewpoints only list"));
				return Level.ViewpointList;
			}
			else
			{
				return Level.ControllerList;
			}
		}
		if (viewpref != 2)
		{
			C=Controller(A);
		}
		if (C != nullptr)
		{
			C=C.nextController;
			if (C != nullptr)
			{
				return C;
			}
			if (viewpref != 1)
			{
				return Level.ViewpointList;
			}
			else
			{
				return Level.ViewpointList;
			}
		}
		if (viewpref != 1)
		{
			V=AGP_Viewpoint(A);
		}
		if (V != nullptr)
		{
			return V.NextViewpoint;
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController::GetNextViewTargetActor() - Don't know what to do with " $ A));
		return nullptr;
	*/
}
void AHumanController::GetNextViewBody(AActor* A)
{
	/*
		local Pawn p;
		local Pawn Prev;
		local bool b_use_next;
		Prev=Pawn(A);
		if (Prev == nullptr)
		{
			b_use_next=True;
		}
		ForEach DynamicActors(Class'Pawn',p)
		{
			if (p.isDead())
			{
				if (b_use_next)
				{
					return p;
				}
				else
				{
					if (p == Prev)
					{
						b_use_next=True;
					}
				}
			}
		}
		return nullptr;
	*/
}
bool AHumanController::IsSpectatePlayersOnly()
{
	if (StartupStage == EStartupStage::STAGE_Authorizing)
	{
		return false;
	}
	/*
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		return false;
	}
	*/
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return bSpectatePlayersOnly;
	}
	else
	{
		//return Level.Game.IsSpectatePlayersOnly();
		return false;		//FAKE    /EliZ
	}
}
bool AHumanController::IsSpectateFirstPersonOnly()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return bSpectateFirstPersonOnly;
	}
	else
	{
		//return Level.Game.IsSpectateFirstPersonOnly();
		return false;		//FAKE    /EliZ
	}
}
bool AHumanController::IsSpectateBodies()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return bSpectateBodies;
	}
	else
	{
		//return Level.Game.IsSpectateBodies();
		return false;		//FAKE    /EliZ
	}
}
bool AHumanController::CanBehindView()
{
	/*
		APawn* p = nullptr;
		if (Super::CanBehindView())
		{
			return true;
		}
		else
		{
			if (! (Level.Game.IsSpectateFirstPersonOnly()))
			{
				if (GetNetMode() == ENetMode::NM_Client && Pawn != nullptr && ! Pawn.isDead() && ! bCheatServer)
				{
					ClientMessage("Behindview is not available on non-cheat servers");
					return false;
				}
				p=Pawn(ViewTarget);
				if (p != nullptr && p.Health > 0)
				{
					return true;
				}
			}
		}
		return false;
	*/
	return false;		//FAKE    /EliZ
}
void AHumanController::ClientSetViewPreference(EViewPreference evpNew)
{
	ViewPreference = evpNew;
}
void AHumanController::ServerSetViewPreference(EViewPreference evpNew)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		/*
		if (GameReplicationInfo.Teams[0].NumAlive() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("no players left alive, using viewpoints"));
			ServerNextViewTarget(2);
			return;
		}
		*/
	}
	else
	{
		/*
		if (GameReplicationInfo.Teams[0].NumAlive() == 0 || GameReplicationInfo.Teams[1].NumAlive() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("No players left alive, using viewpoints only"));
			ServerNextViewTarget(ViewPreference);
			return;
		}
		*/
	}
		
	ViewPreference=evpNew;
	ClientSetViewPreference(ViewPreference);
	//ServerNextViewTarget(ViewPreference);
}
void AHumanController::ServerCycleViewPreference()
{
	/*
	if (IsSpectatePlayersOnly())
	{
		ViewPreference=0;
	}
	Switch(ViewPreference)
	{
		case 0:
		ViewPreference=1;
		ClientSetViewPreference(ViewPreference);
		if (! ViewTarget.IsA('Pawn'))
		{
			ServerNextViewTarget(ViewPreference);
		}
		return;
		case 1:
		ViewPreference=2;
		ClientSetViewPreference(ViewPreference);
		if (ViewTarget == nullptr || ! ViewTarget.IsA('AGP_Viewpoint'))
		{
			ServerNextViewTarget(ViewPreference);
		}
		return;
		case 2:
		if (IsSpectateBodies())
		{
			ViewPreference=3;
			break;
		}
		ViewPreference=0;
	}
	ClientSetViewPreference(ViewPreference);
	ServerNextViewTarget(ViewPreference);
	return;
	case 3:
	ViewPreference=0;
	ClientSetViewPreference(ViewPreference);
	if (! ViewTarget.IsA('Pawn') && Pawn(ViewTarget).Health > 0)
	{
		ServerNextViewTarget(ViewPreference);
	}
	return;
	default:
	*/
}

/* =================================================================================== *
 * AGP function ServerNextViewTarget
 *	Cycle through the list of eligible ViewTargets, filtered by viewpref and try to
 *	set my current viewtarget to the new one.
  * =================================================================================== */
void AHumanController::ServerNextViewTarget(EViewPreference viewpref, bool bprev, bool bForceViewChange, bool fFindFirstPlayerOnlyView)
{
	switch(viewpref)
	{
	case EViewPreference::VIEW_ViewpointsOnly:
		NextViewpointViewTarget(bprev, false);
		break;
	case EViewPreference::VIEW_Bodies:
		NextBodyViewTarget(bprev);
		break;
	case EViewPreference::VIEW_PlayersOnly:
		NextPlayerViewTarget(bprev);
		break;
	case EViewPreference::VIEW_Any:
		/*
		if (ViewTarget == nullptr || ViewTarget->IsA('AGP_Viewpoint'))
		{
			NextViewpointViewTarget(bprev, false);
		}
		else
		{
			NextPlayerViewTarget(bprev);
		}
		*/
		break;
	default:
		break;
	}
	
}

void AHumanController::NextViewpointViewTarget(bool bprev, bool bNoSwitchToPawns)
{
	/*
		local AGP_Viewpoint agpvpIterator;
		local AGP_Viewpoint agpvpLast;
		local AGP_Viewpoint agpvpSelectedView;
		UE_LOG(LogTemp, Warning, TEXT("NextviewpointViewTarget() entered bPrev: " $ bprev $ " NoSwitchToPawns: " $ bNoSwitchToPawns));
		if (ViewTarget == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("NextviewpointViewTarget() - no previous viewpoint, using viewpoint list head"));
			agpvpSelectedView=Level.ViewpointList;
		}
		else
		{
			if (! bprev && ViewTarget.IsA('AGP_Viewpoint') && AGP_Viewpoint(ViewTarget).NextViewpoint != nullptr)
			{
				agpvpSelectedView=AGP_Viewpoint(ViewTarget).NextViewpoint;
			}
			else
			{
				agpvpIterator=Level.ViewpointList;
				if (agpvpIterator != nullptr)
				{
					if (agpvpIterator == ViewTarget)
					{
						if (bprev)
						{
							if (agpvpIterator != Level.ViewpointList)
							{
								agpvpSelectedView=agpvpLast;
							}
						}
						else
						{
							if (agpvpIterator.NextViewpoint != nullptr)
							{
								agpvpSelectedView=agpvpIterator.NextViewpoint;
							}
						}
						else
						{
						}
						else
						{
							agpvpLast=agpvpIterator;
						}
						agpvpIterator=agpvpIterator.NextViewpoint;
					}
				}
			}
		}
		if (agpvpSelectedView == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("NextviewpointViewTarget() - didn't find a viewpoint")=;
			if (ViewPreference == 0 && ! bNoSwitchToPawns)
			{
				UE_LOG(LogTemp, Warning, TEXT("No previous viewpoint, VIEW ANY used, last viewpoint: " $ ViewTarget));
				if (ViewTarget.IsA('AGP_Viewpoint'))
				{
					NextPlayerViewTarget(bprev);
					return;
				}
			}
			if (bprev)
			{
				agpvpSelectedView=agpvpLast;
			}
			else
			{
				agpvpSelectedView=Level.ViewpointList;
			}
		}
		if (agpvpSelectedView == nullptr)
		{
			if (ViewPreference == 2 || bNoSwitchToPawns)
			{
				if (Level.ViewpointList != nullptr)
				{
					agpvpSelectedView=Level.ViewpointList;
				}
				else
				{
					ForEach AllActors(Class'AGP_Viewpoint',agpvpIterator)
					{
						UE_LOG(LogTemp, Warning, TEXT("Iterated through actors and found viewpoint"));
						agpvpSelectedView=agpvpIterator;
					}
				}
				if (agpvpSelectedView == nullptr)
				{
					return;
				}
			}
			else
			{
				NextPlayerViewTarget(False);
				return;
			}
		}
		SetViewTarget(agpvpSelectedView);
		ClientSetViewTarget2(ViewTarget);
	*/
}

void AHumanController::NextPlayerViewTarget(bool bprev)
{
	/*
		local Controller ctrlIterator;
		local Pawn pawnLastViewed;
		local Pawn pawnToView;
		local Pawn pawnLast;
		local Pawn pawnFirstFound;
		local bool bGetNextPawn;
		UE_LOG(LogTemp, Warning, TEXT("NextPlayerViewTarget entered with last view: " $ ViewTarget $ " bPrev: " $ bprev));
		if (! bLostViewTarget && ViewTarget != nullptr && ViewTarget.IsA('Pawn') && Pawn(ViewTarget).Health > 0)
		{
			if (Pawn(ViewTarget).PlayerReplicationInfo != nullptr && Pawn(ViewTarget).PlayerReplicationInfo.bOnlySpectator || Pawn(ViewTarget).PlayerReplicationInfo.bIsSpectator)
			{
				bGetNextPawn=True;
			}
			else
			{
				pawnLastViewed=Pawn(ViewTarget);
			}
		}
		else
		{
			if (ViewTarget.IsA('Pawn') || ! bprev)
			{
				bGetNextPawn=True;
			}
		}
		bLostViewTarget=False;
		ctrlIterator=Level.ControllerList;
		if (ctrlIterator != nullptr)
		{
			if (ctrlIterator == this)
			{
			}
			if (ctrlIterator.Pawn != nullptr && ctrlIterator.Pawn.Health > 0 && ctrlIterator.Pawn.IsA('AGP_Pawn') || ctrlIterator.Pawn.IsA('CROWS_HMMWV') || ctrlIterator.Pawn.IsA('HMMWV_Passenger') && ctrlIterator.IsA('NPCBaseController') || ctrlIterator.IsA('HumanController'))
			{
				if (ctrlIterator.IsA('HumanController'))
				{
					if (HumanController(ctrlIterator).IsInState('Spectating'))
					{
					}
					if (HumanController(ctrlIterator).PlayerReplicationInfo == nullptr)
					{
					}
					if (HumanController(ctrlIterator).PlayerReplicationInfo.bIsSpectator || HumanController(ctrlIterator).PlayerReplicationInfo.bOnlySpectator)
					{
					}
					else
					{
						else
						{
						}
						else
						{
							if (Level.Game.CanSpectate(this,True,ctrlIterator.Pawn))
							{
								if (pawnFirstFound == nullptr)
								{
									UE_LOG(LogTemp, Warning, TEXT("First pawn found that can be spectated: " $ ctrlIterator.Pawn));
									pawnFirstFound=ctrlIterator.Pawn;
								}
								if (bGetNextPawn)
								{
									UE_LOG(LogTemp, Warning, TEXT("Getting pawn from " $ ctrlIterator $ " -> " $ ctrlIterator.Pawn $ "." $ ctrlIterator.Pawn.HUDText));
									pawnToView=ctrlIterator.Pawn;
								}
								else
								{
									if (pawnLastViewed == ctrlIterator.Pawn)
									{
										UE_LOG(LogTemp, Warning, TEXT("Found last pawn view target: " $ ctrlIterator.Pawn));
										if (bprev)
										{
											UE_LOG(LogTemp, Warning, TEXT("Moving backwards, using last view: " $ pawnLast));
											if (pawnLast != nullptr)
											{
												pawnToView=pawnLast;
											}
										}
										else
										{
											bGetNextPawn=True;
											UE_LOG(LogTemp, Warning, TEXT("signalling next pawn is the one "));
										}
									}
									pawnLast=ctrlIterator.Pawn;
								}
							}
						}
					}
				}
				ctrlIterator=ctrlIterator.nextController;
			}
		}
		if (pawnToView == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Didn't find pawn yet"));
			if (ViewPreference == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Didn't find pawn and wants to wrap with ViewAny"));
				if (ViewTarget.IsA('Pawn'))
				{
					NextViewpointViewTarget(bprev,True);
					return;
				}
			}
			if (bprev)
			{
				UE_LOG(LogTemp, Warning, TEXT("Wrapping back to last pawn found"));
				pawnToView=pawnLast;
			}
			else
			{
				if (pawnFirstFound != nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("Wrapping back to first pawn: " $ pawnFirstFound));
					if (pawnFirstFound == nullptr)
					{
						NextViewpointViewTarget(False,True);
						return;
					}
					else
					{
						pawnToView=pawnFirstFound;
					}
				}
			}
		}
		if (pawnToView == nullptr || pawnToView == pawnPlayersDeadBody)
		{
			UE_LOG(LogTemp, Warning, TEXT("No pawns found, switching to viewpoints"));
			NextViewpointViewTarget(bprev,True);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Pawn found, switching view to it: " $ pawnToView $ " -> " $ pawnToView.HUDText));
			if (! IsSpectateFirstPersonOnly())
			{
				bBehindView=True;
			}
			else
			{
				bBehindView=False;
			}
			if (pawnToView.IsA('HMMWV_Passenger'))
			{
				bBehindView=True;
				pawnToView=pawnToView.GetVehicleBase();
			}
			SetViewTarget(pawnToView);
			ClientSetViewTarget2(ViewTarget);
			ClientSetBehindView(bBehindView);
		}
	*/
}

void AHumanController::NextBodyViewTarget(bool bprev)
{
	/*
			local AGP_Pawn agpIterator;
			local Pawn pawnLastViewed;
			local Pawn pawnToView;
			local Pawn pawnLast;
			local Pawn pawnFirstFound;
			local bool bGetNextPawn;
			UE_LOG(LogTemp, Warning, TEXT("NextBodyViewTarget() entered"));
			if (ViewTarget != nullptr && ViewTarget.IsA('Pawn') && Pawn(ViewTarget).Health <= 0)
			{
				pawnLastViewed=Pawn(ViewTarget);
			}
			else
			{
				bGetNextPawn=True;
			}
			ForEach AllActors('AGP_Pawn',agpIterator)
			{
				if (agpIterator.Health <= 0)
				{
					if (Level.Game.CanSpectate(this,True,agpIterator))
					{
						if (pawnFirstFound == nullptr)
						{
							pawnFirstFound=agpIterator;
						}
						if (bGetNextPawn)
						{
							pawnToView=agpIterator;
						}
						else
						{
							if (pawnLastViewed == nullptr)
							{
								pawnToView=agpIterator;
							}
							else
							{
								if (pawnLastViewed == agpIterator)
								{
									if (bprev)
									{
										if (pawnLast != nullptr)
										{
											pawnToView=pawnLast;
										}
									}
									else
									{
										bGetNextPawn=True;
									}
								}
								pawnLast=agpIterator;
							}
						}
					}
				}
			}
			if (pawnToView == nullptr)
			{
				if (bprev)
				{
					pawnToView=pawnLast;
				}
				else
				{
					if (pawnFirstFound != nullptr)
					{
						pawnToView=pawnFirstFound;
					}
				}
			}
			if (pawnToView == nullptr)
			{
				NextViewpointViewTarget(bprev,False);
			}
			else
			{
				SetViewTarget(pawnToView);
				ClientSetViewTarget2(pawnToView);
				if (! IsSpectateFirstPersonOnly())
				{
					bBehindView=True;
				}
				else
				{
					bBehindView=False;
				}
				ClientSetBehindView(bBehindView);
			}
	*/
}

void AHumanController::NotifyLostViewTarget()
{
	bLostViewTarget=true;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		UE_LOG(LogTemp, Log, TEXT("Lost view target!"));
		ServerNotifyLostViewTarget();
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Lost view target"));
	}
}

void AHumanController::ServerNotifyLostViewTarget()
{
	if (StartupStage != EStartupStage::STAGE_Spectator && StartupStage != EStartupStage::STAGE_Authorizing)
	{
		CleanUp();
		//Level.Game.RestartPlayer(this);
	}
	//ServerNextViewTarget();
}
void AHumanController::NotifyPawnDestroyed(APawn* p)
{
	/*
		NotifyPawnDestroyed(p);
		if (ViewTarget == p && p.Role == 2)
		{
			ServerNextViewTarget();
		}
	*/
}
void AHumanController::DebugFlushStats()
{
	ServerDebugFlushStats();
}
void AHumanController::ServerDebugFlushStats()
{
	/*
		if (Role == 4 && GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			if (Level.Game.Stats != nullptr)
			{
				Level.Game.Stats.Aggregate();
				Level.Game.Stats.Store();
			}
		}
	*/
}
void AHumanController::DebugClientDumpPawns()
{
}
void AHumanController::DebugServerDumpPawns()
{
}
void AHumanController::ServerSetViewTarget(AActor* Target)
{
	/*
		if (Target == nullptr)
		{
			Target=Level.ViewpointList;
		}
		SetViewTarget(Target);
		SetRotation(Target.Rotation);
	*/
}
void AHumanController::ServerChangeToSpectatingState()
{
	//GotoState('Spectating');
}
void AHumanController::ServerAdminFreeCam(AActor* OldTarget)
{
	/*
		if (OldTarget == nullptr || ! PlayerReplicationInfo.bAdmin)
		{
			return;
		}
		SetPhysics(0);
		SetCollision(False,False,False);
		bCollideWorld=False;
		SetLocation(OldTarget.Location);
		SetRotation(OldTarget.Rotation);
		SetViewTarget(this);
		ClientSetViewTarget2(ViewTarget);
		ShortClientAdjustPosition(GetWorld()->GetTimeSeconds,GetStateName(),0,Location.X,Location.Y,Location.Z,Rotation.Pitch / 256,this);
	*/
}
void AHumanController::ServerAdminViewPlayer(AActor* NewTarget)
{
	/*
		if (NewTarget == nullptr || ! PlayerReplicationInfo.bAdmin)
		{
			return;
		}
		SetPhysics(0);
		SetCollision(True,False,False);
		bCollideWorld=True;
		SetViewTarget(NewTarget);
		ClientSetViewTarget2(ViewTarget);
	*/
}
void AHumanController::LogTeam()
{
	PlayerReplicationInfo->Team->LogTeamStructure();
}
void AHumanController::ServerLogTeam()
{
	ServerLogTeamStructure();
}
void AHumanController::ServerLogTeamStructure()
{
	PlayerReplicationInfo->Team->LogTeamStructure();
}
void AHumanController::Query()
{
	if(GetNetMode() == ENetMode::NM_Standalone)
	{
		ServerQuery();
	}
	printInfo();
}
bool AHumanController::CanServerQuery()
{
	/*
		if (Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
		{
			return PlayerReplicationInfo->Administrator() || PlayerReplicationInfo->SuperUser();
		}
		else
		{
			return true;
		}
	*/
	return true;
}
void AHumanController::ServerQuery()
{
	if (CanServerQuery())
	{
		printInfo();
	}
}
void AHumanController::printInfo()
{
	/*
		local BaseWeaponAttachment WA;
		local Pickup p;
		local AGP_Weapon W;
		local AGP_Pawn AP;
		local PlayerController PC;
		local PlayerReplicationInfo PRI;
		local AttachmentHandler AH;
		UE_LOG(LogTemp, Warning, TEXT("-------------------- (q) --------------------"));
		UE_LOG(LogTemp, Warning, TEXT("***WEAPONS***"));
		ForEach AllActors('AGP_Weapon',W)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	W:	" $ W @ W.GetStateName() @ W.Base @ W.Owner @ W.Instigator @ W.AmmoType));
		}
		ForEach AllActors('BaseWeaponAttachment',WA)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	WA:	" $ WA @ WA.GetStateName() @ WA.Owner @ WA.Instigator @ WA.Base @ WA.TurretPitch @ WA.TurretYaw));
		}
		ForEach AllActors(Class'Pickup',p)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	P:	" $ p @ p.GetStateName() @ p.Base @ p.AttachmentBone));
		}
		ForEach AllActors('AttachmentHandler',AH)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	AH:	" $ AH @ AH.GetStateName() @ AH.AttachProxy @ AH.Base));
		}
		UE_LOG(LogTemp, Warning, TEXT("***PLAYERS***"));
		ForEach AllActors('AGP_Pawn',AP)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	AP:  " $ AP @ AP.GetStateName() @ AP.Weapon @ AP.getHandsInventory() @ AP.getShoulderInventory()));
		}
		ForEach AllActors(Class'PlayerController',PC)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	PC:   " $ PC @ PC.GetStateName() @ PC.ViewTarget @ PC.RealViewTarget));
		}
		ForEach AllActors(Class'PlayerReplicationInfo',PRI)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	PRI: " $ PRI @ PRI.PlayerName @ PRI.Owner @ PRI.Team @ PRI.Team.TeamIndex @ PRI._Group));
		}
		UE_LOG(LogTemp, Warning, TEXT("***INVENTORIES***"));
		ForEach AllActors('AGP_Pawn',AP)
		{
			UE_LOG(LogTemp, Warning, TEXT("(q)	AP:  " $ AP.GetHumanReadableName()));
			AP.LogInventory();
		}
		UE_LOG(LogTemp, Warning, TEXT("***PICKUPS***"));
		Level.LogPickupList("Query");
		UE_LOG(LogTemp, Warning, TEXT("-------------------- (q) --------------------"));
	*/
}

bool AHumanController::useTriggered(AActor* A)
{
	if (A != nullptr)
	{
		if (A->IsA(AMover::StaticClass()))
		{
			return Cast<AMover>(A)->bUseControl;
		}
	}
	return false;
}
void AHumanController::ChangeActionStatus(uint8 Action)
{
	bAction = Action;
}
void AHumanController::HealSelf()
{
	/*
		if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyReloading') || Pawn.Weapon.IsInState('BusyFixingJam') || Pawn.Weapon.IsZoomed())
		{
			return;
		}
		if (bAction != 0)
		{
			NotifyAdminMessage("You must release your action key to heal yourself.");
			return;
		}
		ServerHealSelf();
	*/
}
void AHumanController::ServerHealSelf()
{
	/*
		if (Pawn.bLockMovement)
		{
			return;
		}
		if (Cast<AAGP_Pawn>(GetPawn()).bHealingInProgress && Cast<AAGP_Pawn>(GetPawn()).Healer != Pawn)
		{
			NotifyAdminMessage("A medic is already healing you.");
			return;
		}
		if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.bQualifiedMedic)
		{
			if (Cast<AAGP_Pawn>(GetPawn()).IsWounded())
			{
				if (Cast<AAGP_Pawn>(GetPawn())._InvSelfHealMedPacks <= 0)
				{
					return;
				}
				if (Pawn.bIsProne || Pawn.bIsCrouched)
				{
					Cast<AAGP_Pawn>(GetPawn()).MedicHealSelf();
				}
				else
				{
					NotifyAdminMessage("To heal yourself safely crouch or go prone and try again.");
				}
			}
		}
	*/
}
void AHumanController::Action()
{
	/*
		local Actor ClientAction;
		local Actor HitActor;
		local FVector StartTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector EndTrace;
		local FVector HitNormal;
		local FVector HitLocation;
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		if (GetNetMode() == ENetMode::NM_Client && Vehicle(Pawn) != nullptr)
		{
			ServerAction(ClientAction);
			return;
		}
		if (GetNetMode() == ENetMode::NM_Client && ! CanTakeAction())
		{
			return;
		}
		ClientAction=_LastGlowActor;
		if (ClientAction == nullptr)
		{
			ClientAction=TryZoomActionTrace();
		}
		if (ClientAction == nullptr)
		{
			GetAxes(Pawn.GetViewRotation(),X,Y,Z);
			StartTrace.X=Pawn.Location.X;
			StartTrace.Y=Pawn.Location.Y;
			StartTrace.Z=Pawn.Location.Z + Pawn.BaseEyeHeight;
			StartTrace += Pawn.CollisionRadius * X;
			EndTrace=StartTrace + 250 * X;
			HitActor=Pawn.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,False);
			if (HitActor != nullptr && HitActor.IsA('blackhawk'))
			{
				ClientAction=HitActor;
			}
		}
		ServerAction(ClientAction);
	*/
}
void AHumanController::CanTakeAction()
{
	/*
		if (Pawn == nullptr || Pawn.bIsSprinting || GetTraceDistance() == 0 || Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyReloading'))
		{
			return false;
		}
		else
		{
			return true;
		}
	*/
}
void AHumanController::getZoomActionDistance()
{
	//return Pawn.GetShortTraceDistance() * Pawn.GetZoomMultiplier() * 16;
}
void AHumanController::getMaxDistance(AActor* Other)
{
	/*
	AAGP_Objective* obj;
	obj = Cast<AAGP_Objective>(other);
	//obj=AGP_Objective(Other);
	if (obj != nullptr && obj->bLongRange)
	{
		return getZoomActionDistance();
	}
	else
	{
		return getMaxDistance(Other);
	}
	*/
}
void AHumanController::ValidateClientActionOn(AActor* Other)
{
	/*
		float max_dist;
		float Distance;
		if (GetWorld()->IsServer())
		{
			Distance=VSize(Pawn.Location - Other.Location);
			max_dist=getMaxDistance(Other);
			if (Distance > max_dist)
			{
				return false;
			}
		}
		return true;
		*/
}
void AHumanController::TryZoomActionTrace()
{
	/*
		local Actor Other;
		local AGP_Objective obj;
		if (Pawn.IsZoomed())
		{
			Other=ManualTrace(getZoomActionDistance());
			obj=AGP_Objective(Other);
			if (obj != nullptr && obj.bLongRange)
			{
				return obj;
			}
		}
		return nullptr;
	*/
}
void AHumanController::TryWeaponTargetTrace()
{
	/*
		local Actor Other;
		local DecoMesh MyDeco;
		Other=ManualTrace(26240);
		MyDeco=DecoMesh(Other);
		if (MyDeco != nullptr)
		{
			return MyDeco;
		}
		return nullptr;
	*/

}
void AHumanController::TryJavelinTargetTrace()
{
	/*
		local FVector StartTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector EndTrace;
		local FVector HitNormal;
		local FVector HitLocation;
		local BaseWeaponAttachment BA;
		local Actor HitActor;
		local Actor TraceFrom;
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		GetAxes(Pawn.GetViewRotation(),X,Y,Z);
		StartTrace.X=Pawn.Location.X;
		StartTrace.Y=Pawn.Location.Y;
		StartTrace.Z=Pawn.Location.Z + Pawn.BaseEyeHeight;
		StartTrace += Pawn.CollisionRadius * X;
		EndTrace=StartTrace + 130000 * X;
		BA=BaseWeaponAttachment(Pawn.Weapon.ThirdPersonActor);
		TraceFrom=BA.GetSource();
		TraceFrom.bUseCollisionStaticMesh=True;
		HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,True);
		TraceFrom.bUseCollisionStaticMesh=False;
		return HitActor;
	*/
}
void AHumanController::ServerAction(AActor* Other)
{
	/*
			if (! CanTakeAction())
			{
				return;
			}
			if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn()).bHealingInProgress && Cast<AAGP_Pawn>(GetPawn()).Healer == Pawn)
			{
				return;
			}
			if (Pawn.Using(Other))
			{
				return;
			}
			if (Other == nullptr)
			{
				Other=ManualTrace(GetTraceDistance());
			}
			if (Other != nullptr && Other.IsA('blackhawk'))
			{
				Log("Trace distance to blackhawk: " $ VSize(Other.Location - Pawn.Location));
				if (VSize(Other.Location - Pawn.Location) < 250)
				{
					Log("BH altitude: " $ NPCBaseHelicopterController(Vehicle(Other).Controller).GetRealAltitude() $ ", event: " $ NPCBaseHelicopterController(Vehicle(Other).Controller).UsedEvent);
					if (NPCBaseHelicopterController(Vehicle(Other).Controller).GetRealAltitude() < 150 && NPCBaseHelicopterController(Vehicle(Other).Controller).UsedEvent != 'None')
					{
						Pawn.TriggerEvent(NPCBaseHelicopterController(Vehicle(Other).Controller).UsedEvent,this,Pawn);
						Log("Trying to activate trigger " $ NPCBaseHelicopterController(Vehicle(Other).Controller).UsedEvent);
					}
				}
				return;
			}
			if (Other != nullptr && ! ValidateClientActionOn(Other))
			{
				Other=None;
			}
			if (Other == nullptr)
			{
				Other=TryZoomActionTrace();
			}
			if (Other != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Found something to activate: " $ Other $ " Pawn's base: " $ Base));
				if (Pawn.Base != nullptr && Pawn.Base.IsA('Mover'))
				{
					UE_LOG(LogTemp, Warning, TEXT("Mover hit, seeing if we're on it (base: " $ Pawn.Base $ ")"));
					if (Other.IsA('DoorTrigger') || Other.IsA('Mover'))
					{
						ClientMessage("You must step back to open this door");
						return;
					}
				}
				if (Other.UsedBy(Pawn))
				{
					return;
				}
			}
			if (Pawn != nullptr)
			{
				SearchForPickup(Pawn.GetShortTraceDistance());
			}
	*/
}

void AHumanController::SearchForPickup(int32 Distance)
{
	/*
		local Pickup p;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector SearchLocation;
		local array<Pickup> PossiblePickups;
		local FVector EyeToPickup;
		local float BestAngle;
		local float CurrentAngle;
		local int i;
		if (! IsZero(Pawn.Velocity) && ! IsInState('PlayerCrawling') && ! IsInState('PlayerCrouching'))
		{
			return false;
		}
		GetAxes(Rotation,X,Y,Z);
		SearchLocation=Pawn.Location + Distance / 2 + Pawn.CollisionRadius * X;
		ForEach RadiusActors(Class'Pickup',p,Distance / 2,SearchLocation)
		{
			if (p == nullptr)
			{
			}
			else
			{
				if (p.ReadyToPickup(0))
				{
					if (p.CanSpawnCopy(Pawn,False))
					{
						PossiblePickups.insert (PossiblePickups.Length,1);
						PossiblePickups[PossiblePickups.Length - 1]=p;
					}
				}
			}
		}
		p=None;
		BestAngle=-2;
		for (i=0; i<PossiblePickups.Length; i++)
		{
			EyeToPickup=Normal(PossiblePickups[i].Location - Pawn.EyePosition());
			CurrentAngle= Vector(Rotation) Dot EyeToPickup;
			if (CurrentAngle > BestAngle)
			{
				p=PossiblePickups[i];
				BestAngle=CurrentAngle;
			}
		}
		if (p != nullptr)
		{
			p.TakeItem(Pawn);
			return true;
		}
		return false;
	*/
}
void AHumanController::ManualTrace(int32 Distance)
{
	/*
		local FVector StartTrace;
		local FVector EndTrace;
		local Object.Rotator CameraRotation;
		local Actor Other;
		local bool bOldBlockZeroExtent;
		PlayerCalcView(Other,StartTrace,CameraRotation);
		EndTrace=StartTrace + Distance *  Vector(CameraRotation);
		bOldBlockZeroExtent=Pawn.bBlockZeroExtentTraces;
		Pawn.bBlockZeroExtentTraces=False;
		Other=ActionTrace(EndTrace,StartTrace);
		Pawn.bBlockZeroExtentTraces=bOldBlockZeroExtent;
		if (bPrintShootDebug)
		{
			return Other;
		}
	*/
}
bool AHumanController::DoHighlight(AActor* A)
{
	if (A->IsA(AMover::StaticClass()))
	{
		return Cast<AMover>(A)->bUseHighlight;
	}
	else
	{
		if (A->IsA(APawn::StaticClass()) || A->IsA(AAGP_UseTrigger::StaticClass()))
		{
			return false;
		}
		else
		{
			if (A->IsA(ABodyPanel::StaticClass()))
			{
				return Cast<ABodyPanel>(A)->bDoHighlight;
			}
		}
	}
	return true;
}
bool AHumanController::RememberActor(AActor* A)
{
	if (A->IsA(APickup::StaticClass()))
	{
		return true;
	}
	else
	{
		if (A->IsA(AMover::StaticClass()))
		{
			return Cast<AMover>(A)->bUseControl;
		}
		else
		{
			
			if (A->IsA(APawn::StaticClass()) || A->IsA(AAGP_UseTrigger::StaticClass()))
			{
				return true;
			}
			else
			{
				if (A->IsA(ABodyPanel::StaticClass()))
				{
					return true;
				}
			}
			
		}
	}
	return false;
}
void AHumanController::getValidActorDistance(AActor* Other)
{
	/*
		if (AGP_Objective(Other) != nullptr)
		{
			if (Other.IsA('AGP_CoopESSObjective'))
			{
				return AGP_Objective(Other).getObserveDistance();
			}
			if (AGP_Objective(Other).bLongRange)
			{
				return Pawn.GetZoomTraceDistance();
			}
			else
			{
				return Pawn.GetShortTraceDistance();
			}
		}
		else
		{
			if (Inventory(Other) != nullptr || Pickup(Other) != nullptr)
			{
				return Pawn.GetShortTraceDistance();
			}
			else
			{
				if (Mover(Other) != nullptr)
				{
					return Pawn.GetShortTraceDistance();
				}
				else
				{
					if (Pawn(Other) != nullptr)
					{
						if (Pawn.IsFriend(Pawn(Other)))
						{
							return Pawn.GetFriendTraceDistance();
						}
						if (Pawn.IsEnemy(Pawn(Other)))
						{
							return Pawn.GetEnemyTraceDistance();
						}
					}
					else
					{
						return GetTraceDistance();
					}
				}
			}
		}
	*/
}
void AHumanController::CanIDActor(AActor* Other, float hit_distance_sq)
{
	/*
		local float max_dist;
		max_dist=getValidActorDistance(Other);
		if (hit_distance_sq > max_dist * max_dist)
		{
			return false;
		}
		return true;
	*/
}
void AHumanController::getValidActorDistanceWeaponTarget(AActor* Other)
{
	/*
			if (AGP_Objective(Other) != nullptr)
			{
				if (Other.IsA('AGP_CoopESSObjective'))
				{
					return AGP_Objective(Other).getObserveDistance();
				}
				if (AGP_Objective(Other).bLongRange)
				{
					return Pawn.GetZoomTraceDistance();
				}
				else
				{
					return Pawn.GetShortTraceDistance();
				}
			}
			else
			{
				if (Inventory(Other) != nullptr || Pickup(Other) != nullptr)
				{
					return Pawn.GetShortTraceDistance();
				}
				else
				{
					if (Mover(Other) != nullptr)
					{
						return Pawn.GetShortTraceDistance() * 16;
					}
					else
					{
						if (Pawn(Other) != nullptr)
						{
						}
						return GetTraceDistance();
					}
				}
			}
	*/

}
void AHumanController::CanIDWeaponTarget(AActor* Other, float hit_distance_sq)
{
	/*
		local float max_dist;
		max_dist=getValidActorDistanceWeaponTarget(Other);
		if (hit_distance_sq > max_dist * max_dist)
		{
			return false;
		}
		return true;
	*/
}
void AHumanController::OverrideActionTrace(AActor* A)
{
	/*
		if (A == nullptr)
		{
			return false;
		}
		else
		{
			if (A.Physics == 14)
			{
				return false;
			}
			else
			{
				if (A.IsA('Pickup'))
				{
					return true;
				}
				else
				{
					if (A.IsA('Pawn'))
					{
						return Pawn(A).PlayerReplicationInfo != nullptr;
					}
					else
					{
						return false;
					}
				}
			}
		}
	*/
}
void AHumanController::ActionTrace(FVector EndTrace, FVector StartTrace, FVector HitLocation)
{
	/*
		local Actor Trace1;
		local Actor Trace2;
		local FVector HitLocation2;
		local FVector HitNormal;
		Trace1=Trace(HitLocation,HitNormal,EndTrace,StartTrace,True);
		if (Trace1 != nullptr)
		{
			if (Trace1.Physics == 14)
			{
				StartTrace=HitLocation;
				Trace2=Trace1.Trace(HitLocation,HitNormal,EndTrace,StartTrace,True);
				Trace1=Trace2;
			}
			if (Trace1 != nullptr && Trace1.IsA('AGP_Objective'))
			{
				StartTrace=HitLocation;
				Trace2=Trace1.Trace(HitLocation2,HitNormal,EndTrace,StartTrace,True);
				if (OverrideActionTrace(Trace2))
				{
					HitLocation=HitLocation2;
					return Trace2;
				}
			}
			return Trace1;
		}
		return nullptr;

	*/
}
void AHumanController::AutoTrace()
{
	/*
		local FVector StartTrace;
		local FVector EndTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector HitLocation;
		local Actor Other;
		local int trace_dist;
		local bool bDeepTrace;
		local float hit_distance_sq;
		if (Pawn == nullptr)
		{
			return;
		}
		trace_dist=GetTraceDistance();
		if (trace_dist == 0)
		{
			return;
		}
		GetAxes(Pawn.GetViewRotation(),X,Y,Z);
		StartTrace=Pawn.EyePosition();
		if (! Pawn.IsA('CROWS_HMMWV'))
		{
			StartTrace += Pawn.CollisionRadius * X;
		}
		EndTrace=StartTrace;
		EndTrace += trace_dist * X;
		Other=ActionTrace(EndTrace,StartTrace,HitLocation);
		if (Other != nullptr)
		{
			if (Other != _LastGlowActor)
			{
				if (_LastGlowActor != nullptr)
				{
					_LastGlowActor.AmbientGlow=_SavedAmbientGlow;
				}
				if (RememberActor(Other))
				{
					_SavedAmbientGlow=Other.AmbientGlow;
					if (DoHighlight(Other))
					{
						Other.AmbientGlow=255;
					}
					_LastGlowActor=Other;
				}
				else
				{
					_LastGlowActor=None;
				}
			}
			if (Other.IsA('Pawn'))
			{
				_AnimPawn=Pawn(Other);
			}
		}
		else
		{
			if (! _bPermaTraceDebug)
			{
				_AnimPawn=None;
			}
			if (_LastGlowActor != nullptr)
			{
				_LastGlowActor.AmbientGlow=_SavedAmbientGlow;
				_LastGlowActor=None;
			}
		}
		AutoTraceCount=AutoTraceCount + 1 % AutoTraceFrequency;
		if (AutoTraceCount == 0)
		{
			if (Other == nullptr)
			{
				EndTrace=StartTrace + Pawn.GetDeepTraceDistance() * X;
				Other=ActionTrace(EndTrace,StartTrace,HitLocation);
				bDeepTrace=True;
			}
			if (Other == nullptr)
			{
				Other=TryZoomActionTrace();
				if (Other != nullptr)
				{
					HitLocation=Other.Location;
				}
			}
			if (Other == nullptr && Pawn.Weapon != nullptr && Pawn.Weapon.bLongTargetTrace)
			{
				Other=TryWeaponTargetTrace();
			}
			if (Other != nullptr)
			{
				if (! Other.IsA('AGP_CoopESSObjective') && bLookingAtZombieObject)
				{
					bLookingAtZombieObject=False;
				}
			}
			if (Vehicle(Pawn) != nullptr)
			{
				Other=ManualTrace(trace_dist * 1.5);
			}
			if (MyHUD != nullptr)
			{
				ClearActorID();
				if (Other != nullptr)
				{
					hit_distance_sq=VSizeSquared(HitLocation - StartTrace);
					if (CanIDWeaponTarget(Other,hit_distance_sq))
					{
						TryToIDWeaponTarget(Other);
					}
					if (CanIDActor(Other,hit_distance_sq))
					{
						TryToIDActor(Other);
						TryToIDPawn(Other,bDeepTrace);
					}
				}
			}
		}
		if (Other == nullptr && Pawn.Weapon != nullptr && Pawn.Weapon.IsZoomed() && Pawn.Weapon.IsA('WEAPON_Javelin'))
		{
			Other=TryJavelinTargetTrace();
			TryToIDJavelinTarget(Other);
		}
	*/
}
void AHumanController::ClearActorID()
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		//HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10))->ActionText="";
		//HUDPlayerID(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(16))->NoTarget();
		//HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10))->SetColorID(0);
		//HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17))->NoTarget();
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->bActiveBreacherTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bActiveDemolitionTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bActiveObjPickupTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bInactiveObjPickupTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bActiveJavelinTarget=false;
	}
}
void AHumanController::TryToIDWeaponTarget(AActor* A)
{
	/*
		local DecoMesh MyDeco;
		local HUDWeaponTarget WeaponTarget;
		local class<DamageType>  MyDamage;
		local Weapon MyWeapon;
		local AGP_ObjectivePickup ObjPickup;
		if (Pawn == nullptr)
		{
			return;
		}
		if (A != nullptr)
		{
			MyDeco=DecoMesh(A);
		}
		if (A.IsA('AGP_CoopESSObjective') && ! AGP_Objective(A).isReportable())
		{
			if (! bLookingAtZombieObject)
			{
				bLookingAtZombieObject=True;
				fTime=GetWorld()->GetTimeSeconds();
			}
			if (bLookingAtZombieObject)
			{
				if (GetWorld()->GetTimeSeconds() - fTime > 1)
				{
					AGP_Objective(A).MakeES2ObjectiveReportable();
					abpobjESSLastSeen=AGP_Objective(A);
					ServerTrackESSObjectSeen(abpobjESSLastSeen);
				}
			}
			if (! AGP_Objective(A).isReportable())
			{
				return;
			}
		}
		if (A.IsA('NPCBaseCivilianController'))
		{
			Log("Setting LastReportAbleNPC as: " $ LastReportableNPC);
			LastReportableNPC=NPCBaseController(A);
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		if (A != nullptr)
		{
			ObjPickup=AGP_ObjectivePickup(A);
		}
		if (A.IsA('AGP_Objective') == true)
		{
			if (! AGP_Objective(A).bDisabled && ! A.IsA('AGP_CarryObjective'))
			{
				if (Cast<AAGP_HUD>(MyHUD) != nullptr)
				{
					WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				}
				if (! A.IsA('AGP_CoopESSObjective'))
				{
					Cast<AAGP_Pawn>(GetPawn()).TargetObjLetter=AGP_Objective(A).HUDLetter;
					WeaponTarget.SetTarget();
					Cast<AAGP_Pawn>(GetPawn()).bActiveObjectiveTarget=True;
				}
				else
				{
					Cast<AAGP_Pawn>(GetPawn()).stTargetDescription=AGP_Objective(A).HUDText;
					WeaponTarget.SetTarget();
					Cast<AAGP_Pawn>(GetPawn()).bActiveCoopESSTarget=True;
				}
			}
		}
		if (ObjPickup != nullptr && ObjPickup.bDisplayTargetingInfo)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
			}
			if (ObjPickup.idTeamOwner == PlayerReplicationInfo.Team.TeamIndex || ObjPickup.idTeamOwner == 255)
			{
				WeaponTarget.SetTarget();
				Cast<AAGP_Pawn>(GetPawn()).bActiveObjPickupTarget=True;
			}
			else
			{
				WeaponTarget.SetTarget();
				Cast<AAGP_Pawn>(GetPawn()).bInactiveObjPickupTarget=True;
			}
		}
		if (MyDeco != nullptr && MyDeco.bDisplayTargetingInfo)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
			}
			if (MyDeco.bBreachable == true)
			{
				WeaponTarget.SetTarget();
				if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
				{
					Cast<AAGP_Pawn>(GetPawn()).bActiveBreacherTarget=True;
				}
			}
			if (Pawn.Weapon != nullptr)
			{
				MyWeapon=Pawn.Weapon;
				if (MyWeapon.IsA('ThrowWeapon'))
				{
					MyDamage=ThrowWeapon(MyWeapon).MyDamageType;
				}
				else
				{
					if (MyWeapon.GetCurrentAmmoType().ProjectileClass != nullptr)
					{
						MyDamage=MyWeapon.GetCurrentAmmoType().ProjectileClass.Default.MyDamageType;
					}
					else
					{
						MyDamage=MyWeapon.GetCurrentAmmoType().MyDamageType;
					}
				}
				if (MyDeco.ShouldDisplayDamageType(MyDamage))
				{
					WeaponTarget.SetTarget();
					Switch(MyDamage.Default.AmmoType)
					{
						case 14:
						if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
						{
							Cast<AAGP_Pawn>(GetPawn()).bActiveDemolitionTarget=True;
						}
						break;
						default:
					}
				}
			}
		}
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::TryToIDJavelinTarget(AActor* A)
{
	/*
		local HUDWeaponTarget WeaponTarget;
		if (Pawn == nullptr || Pawn.Weapon == nullptr)
		{
			return;
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		if (A != nullptr && A.ValidJavelinTarget > 0)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
			}
			WeaponTarget.SetTarget();
			if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
			{
				Cast<AAGP_Pawn>(GetPawn()).bActiveJavelinTarget=True;
			}
		}
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::TryToIDActor(AActor* A)
{
	/*
		local BodyPanel MyBodyPanel;
		local Vehicle MyVehicle;
		local int PositionIndex;
		if (A != nullptr)
		{
			MyBodyPanel=BodyPanel(A);
			if (MyBodyPanel != nullptr)
			{
				if (Cast<AAGP_HUD>(MyHUD) != nullptr)
				{
					MyVehicle=Vehicle(Pawn);
					if (MyVehicle == nullptr)
					{
						Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
						HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=MyBodyPanel.ExteriorHintText;
						Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
					}
					else
					{
						if (MyVehicle.Driver != nullptr && MyVehicle.Driver.Health > 0)
						{
							Switch(MyVehicle.Driver.AttachmentBone)
							{
								case 'B_Sitbone_LF':
								if (MyVehicle.IsA('CROWS_HMMWV'))
								{
									PositionIndex=7;
									break;
								}
								PositionIndex=3;
							}
							case 'B_Sitbone_LB':
							if (MyVehicle.IsA('CROWS_Gunner'))
							{
								PositionIndex=0;
							}
							else
							{
								PositionIndex=4;
							}
							case 'B_Sitbone_RF':
							if (! MyVehicle.IsA('HMMWV_RunningBoardPassenger'))
							{
								PositionIndex=1;
							}
							else
							{
								PositionIndex=5;
							}
							case 'B_Sitbone_RB':
							if (! MyVehicle.IsA('HMMWV_RunningBoardPassenger'))
							{
								PositionIndex=2;
							}
							else
							{
								PositionIndex=6;
							}
							default:
							PositionIndex=-1;
							if (PositionIndex >= 0)
							{
								Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
								HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=MyBodyPanel.PassengerHintText[PositionIndex];
								Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
							}
						}
						else
						{
							HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText="";
						}
					}
					if (Class'GameInfo'.GetKeyBindName("Action",this) != "")
					{
						Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
						HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=Repl(HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText,"%UseKey%",Class'GameInfo'.GetKeyBindName("Action",this));
						Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
					}
				}
			}
			else
			{
				if (GetNetMode() == ENetMode::NM_Client && A.HUDTextTeam.Length > PlayerReplicationInfo.Team.TeamIndex)
				{
					if (Cast<AAGP_HUD>(MyHUD) != nullptr)
					{
						Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
						HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=A.HUDTextTeam[PlayerReplicationInfo.Team.TeamIndex];
						Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
					}
				}
				else
				{
					if (A.IsA('AGP_ESSObjective'))
					{
						if (! AGP_Objective(A).bDisabled)
						{
							if (A.IsA('AGP_CoopESSObjective') && ! AGP_Objective(A).isReportable())
							{
								return false;
							}
							abpobjESSLastSeen=AGP_Objective(A);
							ServerTrackESSObjectSeen(abpobjESSLastSeen);
						}
						else
						{
							return false;
						}
					}
					if (A.IsA('NPCBaseCivilianController'))
					{
						Log("Setting LastReportAbleNPC as: " $ LastReportableNPC);
						LastReportableNPC=NPCBaseController(A);
					}
					if (Cast<AAGP_HUD>(MyHUD) != nullptr)
					{
						Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
						if (! A.IsA('AGP_CoopESSObjective'))
						{
							HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=A.HUDText;
						}
						Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
					}
				}
			}
			return true;
		}
		else
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
				HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText="";
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			}
			return false;
		}
	*/
}
void AHumanController::ServerTrackESSObjectSeen(AAGP_Objective* agpobjSeen)
{
	/*
		int32 iObj;
		for (iObj=0; iObj<aagpobjSeen.Num; iObj++)
		{
			if (aagpobjSeen[iObj] == agpobjSeen)
			{
				return;
			}
		}
		aagpobjSeen.Insert (agpobjSeen, 0)
		//aagpobjSeen.insert (aagpobjSeen.Num,1);
		//aagpobjSeen[0]=agpobjSeen;
		if (Level.Game.Stats != nullptr && PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ESSObjectDiscovered(agpobjSeen.Location);
		}
		*/
}
void AHumanController::TryToIDObjective(AActor* A, bool bDeepTrace)
{
	/*
		local AGP_Objective IDObjective;
		local int color_id;
		local HUDCrosshair CrossHair;
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		if (A.IsA('AGP_Objective'))
		{
			IDObjective=AGP_Objective(A);
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			CrossHair=HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10));
		}
		if (IDObjective != nullptr)
		{
			if (IDObjective.bDisabled)
			{
				color_id=1;
			}
			else
			{
				color_id=2;
			}
			CrossHair.SetColorID(color_id);
		}
		else
		{
			CrossHair.SetColorID(0);
		}
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::TryToIDPawn(AActor* A, bool bDeepTrace)
{
	/*
		local AGP_Pawn IDPawn;
		local int color_id;
		local HUDCrosshair CrossHair;
		local HUDPlayerID PlayerID;
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		if (A != nullptr)
		{
			if (A.IsA('AGP_Pawn'))
			{
				IDPawn=AGP_Pawn(A);
			}
			else
			{
				if (A.IsA('AuxCollisionCylinder'))
				{
					IDPawn=AGP_Pawn(AuxCollisionCylinder(A).Owner);
				}
			}
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			CrossHair=HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10));
			PlayerID=HUDPlayerID(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(16));
		}
		if (IDPawn != nullptr && IDPawn != Pawn)
		{
			if (Pawn.IsFriend(IDPawn))
			{
				color_id=1;
			}
			else
			{
				if (Pawn.IsEnemy(IDPawn))
				{
					if (TournamentIsTournament() || ! bExploreTheArmyServer)
					{
						PlayerID.NoTarget();
						CrossHair.SetColorID(0);
						Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
						return;
					}
					color_id=2;
				}
			}
			PlayerID.SetTarget(IDPawn.PlayerReplicationInfo,color_id,bDeepTrace);
			CrossHair.SetColorID(color_id);
		}
		else
		{
			PlayerID.NoTarget();
			CrossHair.SetColorID(0);
		}
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::NotifyPromotion(bool bFTL, uint8 yFT)
{
	FString Message1;
	FString message2;
	if (TournamentIsTournament())
	{
		return;
	}
	Message1="You have been field promoted to ";
	if (bFTL)
	{
		message2="FireTeam ";
		switch(yFT)
		{
			case 0:
				message2=message2 + "Alpha ";
				break;
			case 1:
				message2=message2 + "Bravo ";
				break;
			case 2:
				message2=message2 + "Charlie ";
				break;
			case 3:
				message2=message2 + "Delta ";
				break;
			default:
				break;
		}
	}
	else
	{
		message2="Squad ";
	}
	message2=message2 + "Leader";
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(3,Message1,message2);
	}
}
void AHumanController::NotifyNoScore(FName Reason)
{
	FString Message1;
	FString message2;
	if (bExploreTheArmyServer)
	{
		return;
	}
	Message1="Scoring for this round will not apply to your Personnel Jacket because ";

	if (Reason == "NoEnemy")
	{
		message2 = "there are no players on the other team";
	}
	else
	{
		if (Reason == "SmallGame")
		{
			message2 = "there were not enough players in the game";
		}
		else
		{
			if (Reason == "ShortGame")
			{
				message2 = "the game did not last long enough";
			}
			else
			{
				if (Reason == "CheatServer")
				{
					message2 = "the game server is running with cheats enabled";
				}
				else
				{
					message2 = "UNKNOWN REASON: " + Reason.ToString();
				}
			}
		}
	}
	if (! TournamentIsTournament())
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(3,Message1,message2);
		}
	}
}
void AHumanController::SetSquadTarget()
{
	/*
		if (! PlayerReplicationInfo.IsSquadLeader())
		{
			return;
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		if (_cHUDCompass == nullptr)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				_cHUDCompass=UIHUDCompass(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(5));
			}
		}
		_cHUDCompass.SetTarget(! _cHUDCompass.IsSettingTarget());
		if (_cHUDCompass.IsSettingTarget())
		{
			ClientMessage("Select the objective to set as your squad's target by pressing the appropriate letter.");
		}
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::ServerSetSquadTarget(int32 iTeamIndex, uint8 objnum)
{
	/*
		if (Level.Game.IsA('AGP_GameInfo'))
		{
			AGP_GameInfo(Level.Game).SetSquadTarget(iTeamIndex,objnum);
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerSetSquadTarget called game.setsquadtarget with" @ objnum));
		}
	*/
}

void AHumanController::CanCommo()
{
	/*
		if (Pawn == nullptr || IsInState('BaseSpectating'))
		{
			return false;
		}
		return Pawn.CanCommo();
	*/
}

void AHumanController::CommoCycle()
{
	/*
		local bool bShowingMessages;
		if (GetNetMode() == ENetMode::NM_Standalone || Pawn == nullptr || Pawn.Health <= 0 || ! CanCommo())
		{
			return;
		}
		if (_cHUDCommoInfo == nullptr)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
				_cHUDCommoInfo=HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			}
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		bShowingMessages=_cHUDCommoInfo.ShowingMessages();
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		if (bShowingMessages)
		{
			if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
			{
				Cast<AAGP_Pawn>(GetPawn()).CommoCycleState();
			}
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(True);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::CommoSendMessage(int32 i)
{
	/*
			local class<CommoLocalMessage>  CommoType;
			if (_cHUDCommoInfo == nullptr)
			{
				if (Cast<AAGP_HUD>(MyHUD) != nullptr)
				{
					Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
					_cHUDCommoInfo=HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				}
			}
			if (i == 0)
			{
				Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
				_cHUDCommoInfo.ShowNextMessageSet();
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				return;
			}
			if (! CanCommo())
			{
				return;
			}
			CommoType=None;
			Switch(Pawn.CommoState)
			{
				case 0:
				CommoType='CommoHandSignal';
				break;
				case 1:
				CommoType='CommoWhisper';
				break;
				case 2:
				CommoType='CommoShout';
				break;
				case 3:
				CommoType='CommoRadio';
				break;
				case 4:
				CommoType='CommoSquad';
				break;
				case 5:
				Player.Console.Talk();
				return;
				break;
				default:
			}
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			_cHUDCommoInfo.ShowMessages(False);
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			if (GetNetMode() == ENetMode::NM_Client)
			{
				Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
				CommoPlayAnim(CommoType,_cHUDCommoInfo.IndexToMessage(i) - 1);
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			}
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			CommoSend(CommoType,_cHUDCommoInfo.IndexToMessage(i) - 1);
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/

}
void AHumanController::CommoMode(ECommoType Type)
{
	/*
		if (GetNetMode() == ENetMode::NM_Standalone || Type == 4 && ! PlayerReplicationInfo.IsSquadLeader() || Type == 4 && PlayerReplicationInfo.bGuerrillaPS || ! CanCommo())
		{
			return;
		}
		if (_cHUDCommoInfo == nullptr)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
				_cHUDCommoInfo=HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			}
		}
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).SetCommoState(Type);
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(True);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();

	*/
}
void AHumanController::CheckRIFlood()
{
	/*
		if (yFloodCount != 255)
		{
			if (GetWorld()->GetTimeSeconds() > tFlood)
			{
				yFloodCount=0;
				tFlood=GetWorld()->GetTimeSeconds() + 5;
			}
			else
			{
				if (yFloodCount > 2)
				{
					tFlood += 0.5;
					if (yFloodCount == 3)
					{
						ClientMessage("Please try again in a few seconds.");
						yFloodCount=4;
					}
					return true;
				}
				else
				{
					yFloodCount ++;
					tFlood += 2;
				}
			}
		}
		return false;
	*/
}
void AHumanController::ReportIn()
{
	/*
		if (PlayerReplicationInfo.isDead())
		{
			return;
		}
		if (CheckRIFlood())
		{
			return;
		}
		ServerReportIn();
	*/
}
void AHumanController::ServerReportIn()
{
	/*
		if (PlayerReplicationInfo.isDead())
		{
			return;
		}
		ServerSay(PlayerReplicationInfo.GetLocationName(),'ReportIn');
	*/
}
void AHumanController::ClientESSNotifyAdminMessage(FString sString)
{
	//NotifyAdminMessage(ReplaceCommandString(sString));
}
void AHumanController::ClientESSConsoleMessage(FString sString)
{
	//ClientMessage(ReplaceCommandString(sString));
}
void AHumanController::SetDelayReport(float NextReportInSeconds)
{
	fLevelTime = GetWorld()->GetTimeSeconds();
	NextReportAllowedIn = NextReportInSeconds;
}
void AHumanController::ESSObjectiveReport()
{
	/*
			local FVector StartTrace;
			local FVector EndTrace;
			local FVector X;
			local FVector Y;
			local FVector Z;
			local FVector HitLocation;
			local Actor Other;
			local int trace_dist;
			local float hit_distance_sq;
			if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo.isDead())
			{
				return;
			}
			Log("ESSObjectiveReport():  Current Level time: " @ GetWorld()->GetTimeSeconds() @ "      fLevelTime: " @ fLevelTime @ "     GetWorld()->GetTimeSeconds() - fLevelTime is : " @ GetWorld()->GetTimeSeconds() - fLevelTime @ "        NextReportAllowedIn :" @ NextReportAllowedIn);
			if (GetWorld()->GetTimeSeconds() - fLevelTime <= NextReportAllowedIn)
			{
				ClientMessage("Wait for radio traffic to clear before trying to report another object");
				return;
			}
			trace_dist=GetTraceDistance();
			GetAxes(Pawn.GetViewRotation(),X,Y,Z);
			StartTrace=Pawn.EyePosition();
			if (! Pawn.IsA('CROWS_HMMWV'))
			{
				StartTrace += Pawn.CollisionRadius * X;
			}
			EndTrace=StartTrace;
			EndTrace=StartTrace + Pawn.GetDeepTraceDistance() * 2 * X;
			Other=ActionTrace(EndTrace,StartTrace,HitLocation);
			if (Other != nullptr)
			{
				hit_distance_sq=VSizeSquared(HitLocation - StartTrace);
				Pawn.ReportCivilianEvent(Pawn(Other),hit_distance_sq,this);
			}
			else
			{
				Log("Trace returned None!!!");
			}
			if (abpobjESSLastSeen == nullptr)
			{
				Log("Other is: " $ Other);
				if (! Other.IsA('AGP_Pawn'))
				{
					ClientMessage("You haven't seen anything odd so there's nothing to report.");
				}
				return;
			}
			if (bNPCReported)
			{
				bNPCReported=False;
			}
			if (GetNetMode() != ENetMode::NM_Standalone && CheckRIFlood())
			{
				return;
			}
			ServerESSObjectiveReport(abpobjESSLastSeen);
	*/
}
void AHumanController::ServerESSObjectiveReport(AAGP_Objective* agpobj)
{
	/*
		local float fpRadioDelay;
		local float fInteractRange;
		local float fRangeFromObject;
		local FlagMeshActor smIter;
		if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo.isDead())
		{
			Log("returning we arnt standalone");
			return;
		}
		if (agpobj == nullptr)
		{
			if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportingErrors();
			}
			ClientMessage("You haven't seen anything odd so there's nothing to report.");
			return;
		}
		if (agpobj.bDisabled)
		{
			if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectUnnecessaryUse();
			}
			return;
		}
		Log("agpobj.bPlayerRadioedObectiveInfo" @ agpobj.bPlayerRadioedObectiveInfo);
		Log("agpobj.fpTimeUntilESSInvestigateRadioCompletes" @ agpobj.fpTimeUntilESSInvestigateRadioCompletes);
		if (agpobj.bPlayerRadioedObectiveInfo || agpobj.fpTimeUntilESSInvestigateRadioCompletes > 0)
		{
			if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectUnnecessaryUse();
			}
			return;
		}
		if (agpobj.IsA('AGP_CoopESSObjective'))
		{
			fInteractRange=agpobj.getReportDistance();
			fRangeFromObject=VSize(Pawn.Location - agpobj.Location);
			if (fRangeFromObject > fInteractRange)
			{
				if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
				{
					Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportingErrors();
				}
				ClientMessage("You're too far away from the " $ agpobj.HUDText $ " to report it.");
				return;
			}
			ESSObjectSpotted(agpobj);
			smIter=agpobj.getFlagReference();
			if (smIter != nullptr)
			{
				smIter.bHidden=False;
			}
			else
			{
				ForEach AllActors('FlagMeshActor',smIter)
				{
					if (smIter.Tag == agpobj.getFlagTag())
					{
						Log("Found the Flag");
						if (smIter.bHidden)
						{
							Log("Now make it visible.");
							smIter.bHidden=False;
						}
					}
				}
			}
			if (agpobj.getReportEventName() != 'None')
			{
				TriggerEvent(agpobj.getReportEventName(),this,Pawn);
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(agpobj,4,this);
				}
			}
		}
		else
		{
			if (agpobj.IsA('AGP_ESSObjective'))
			{
				if (VSize(Pawn.Location - agpobj.Location) > 300)
				{
					Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportingErrors();
					ClientMessage("You're too far away from the " $ agpobj.HUDText $ " to report it.");
					return;
				}
			}
		}
		if (! agpobj.spBeenAccountedFor && EventLab != nullptr)
		{
			if (! agpobj.isDummyTrainingObject())
			{
				EventLab.EL_ES2ObjectFound(agpobj.Score_AssaultPlayer);
			}
			agpobj.spBeenAccountedFor=True;
		}
		if (AGP_GameInfo(Level.Game) != nullptr && ! agpobj.isDummyTrainingObject())
		{
			AGP_GameInfo(Level.Game).ScoreAGPObjective(PlayerReplicationInfo.Team,agpobj,False,PlayerReplicationInfo);
			ClientMessage("For following proper procedures you gained " $ agpobj.Score_AssaultPlayer $ " points.");
		}
		if (! agpobj.IsA('AGP_CoopESSObjective'))
		{
			if (PlayerReplicationInfo.Team != nullptr && PlayerReplicationInfo.Team.TeamIndex == 1)
			{
				agpobj.ObjectiveOnCompass=agpobj.3;
			}
			else
			{
				agpobj.ObjectiveOnCompass=agpobj.2;
			}
		}
		agpobj.bPlayerRadioedObectiveInfo=True;
		agpobj.ctrlrESSReporter=this;
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			ClientMessage(UserName $ " Radios: " $ agpobj.sDiscoveredRadioMessage);
		}
		else
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo.Team.TeamIndex,agpobj.sDiscoveredRadioMessage,'ReportESSObjective');
		}
		if (Level.Game.Stats != nullptr && PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ESSObjectDiscoveryRadioed();
			if (agpobj.bDangerous)
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportedLethal();
			}
			else
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportedNonLethal();
			}
		}
		fpRadioDelay=1.5 + FRand() * 3;
		if (! agpobj.IsA('AGP_CoopESSObjective'))
		{
			SetCustomTimer(fpRadioDelay,False,'ESSRadioResponse');
		}
		else
		{
			stCoopESSFoundItemText=agpobj.getAcknowledgeText();
			sndCoopESSFoundItemSound=agpobj.getAcknowledgeVO();
			SetCustomTimer(fpRadioDelay,False,'CoopESSRadioResponse');
		}
		if (agpobj.IsA('AGP_CoopESSObjective'))
		{
			agpobj.fpTimeUntilESSInvestigateRadioCompletes=GetWorld()->GetTimeSeconds() + agpobj.getDialogLength() + fpRadioDelay;
			SetDelayReport(agpobj.getDialogLength() + fpRadioDelay);
			if (agpobj.isUseOnReport())
			{
				agpobj.AccomplishObjective(Pawn);
			}
		}
		else
		{
			agpobj.fpTimeUntilESSInvestigateRadioCompletes=GetWorld()->GetTimeSeconds() + 8 + fpRadioDelay;
		}
		Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportedNonLethal();
	*/
}
void AHumanController::ESSRadioResponse()
{
	/*
		if (! bDisableES2RadioMessages)
		{
			ClientPlaySound(sndESSFoundItemAcknowledgement);
		}
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			ClientMessage("S2 Radios: This is Sierra Two, roger your unknown object.  Identify the object and report back with your findings.  Exercise extreme caution. Out.");
		}
		else
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo.Team.TeamIndex,"S2 Radios: This is Sierra Two, roger your unknown object.  Identify the object and report back with your findings.  Exercise extreme caution. Out.",'ReportESSObjective');
		}

	*/
}
void AHumanController::CoopESSRadioResponse()
{
	if (! bDisableES2RadioMessages)
	{
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			ClientPlaySound(sndCoopESSFoundItemSound);
		}
		else
		{
			ServerPlaySound(sndCoopESSFoundItemSound);
			ClientPlaySound(sndCoopESSFoundItemSound);
		}
	}
	if (stCoopESSFoundItemText != "")
	{
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			//ClientMessage(stCoopESSFoundItemText);
		}
		else
		{
			//Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo.Team.TeamIndex,stCoopESSFoundItemText,'ReportESSObjective');
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("No text defined by CoopES2Objective"));
	}
}
void AHumanController::ClientESSRadioInvestigateOrder(USoundBase* sndESSObjectiveRadioAcknowledgement)
{
	/*
	if (!bDisableES2RadioMessages)
	{
		ClientPlaySound(sndESSObjectiveRadioAcknowledgement);
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		ClientMessage("S2 Radios: Roger your intel report.  Use this intel to locate and complete this new object.  Sierra Two, out.");
	}
	else
	{
		Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo.Team.TeamIndex, "S2 Radios: Roger your intel report.  Use this intel to locate and complete this new object.  Sierra Two, out.", 'ReportESSObjective');
	}
	*/
}
void AHumanController::ClientCoopESSRadioInvestigateOrder(USoundBase* sndESSRadioAcknowledgement)
{
	/*
		Log("Playing sndESSRadioAcknowledgement: " $ sndESSRadioAcknowledgement);
		if (! bDisableES2RadioMessages)
		{
			if (GetNetMode() == ENetMode::NM_Standalone)
			{
				ClientPlaySound(sndESSRadioAcknowledgement);
			}
			else
			{
				ServerPlaySound(sndESSRadioAcknowledgement);
				ClientPlaySound(sndESSRadioAcknowledgement);
			}
		}
	*/
}
void AHumanController::ClientESSRadioSuccessMessage(USoundBase* sndESSObjectiveCompletionAcknowledgement)
{
	/*
		if (! bDisableES2RadioMessages)
		{
			ClientPlaySound(sndESSObjectiveCompletionAcknowledgement);
		}
	*/
}
void AHumanController::ClientESSPlayIntroduction(USoundBase* sndIntro)
{
	/*
		if (bDisableES2Introduction)
		{
			return;
		}
		if (! bESSIntroPlayed || GameReplicationInfo.RoundsPerMatch == GameReplicationInfo.RemainingRounds)
		{
			bESSIntroPlayed=True;
			ClientPlaySound(sndIntro);
		}
	*/
}
void AHumanController::StartMantle()
{
	/*
		local int EndPosture;
		local FVector Point;
		local FVector Normal;
		local AGP_Pawn p;
		if (IsInState('PlayerCrawling') || IsInState('PlayerCrouching'))
		{
			return false;
		}
		EndPosture=Mantle(Point,Normal);
		if (EndPosture >= 0)
		{
			p=Cast<AAGP_Pawn>(GetPawn());
			if (p != nullptr)
			{
				if (p.Velocity.Z < p.fFallDamageSpd)
				{
					if (Level.debugMantle)
					{
						ScreenPrint("Damage Taken" @ p.fFallDamageSpd - p.Velocity.Z);
					}
					Pawn.TakeDamage(p.fFallDamageSpd - p.Velocity.Z,Pawn,Pawn.Location,vect(0 0 0),'FallDamage');
					if (IsInState('Dead'))
					{
						return true;
					}
				}
				p.StartMantle(EndPosture,Point,Rotation);
			}
			return true;
		}
		return false;
	*/
}
void AHumanController::IsTeammateInjured()
{
	/*
		local int i;
		local TeamInfo Team;
		local PlayerReplicationInfo PRI;
		Team=PlayerReplicationInfo.Team;
		for (i=0; i<Team.Size; i++)
		{
			PRI=Team.TeamList[i];
			if (PRI != PlayerReplicationInfo && PRI.bCallForMedic)
			{
				return true;
			}
		}
		return false;
	*/
}
void AHumanController::CallMedic()
{
	/*
	if (Pawn != nullptr)
	{
		if (Pawn.IsWounded())
		{
			if (GetWorld()->GetTimeSeconds() > tMedicFlood || !PlayerReplicationInfo.bCallForMedic)
			{
				ServerCallMedic();
				CommoSend('CommoShout', 31);
				tMedicFlood = GetWorld()->GetTimeSeconds() + 5;
			}
			else
			{
				tMedicFlood += 0.2;
			}
		}
		else
		{
			if (PlayerReplicationInfo.bIsMedic && IsTeammateInjured())
			{
				if (GetWorld()->GetTimeSeconds() > tMedicFlood)
				{
					CommoSend('CommoShout', 29);
					tMedicFlood = GetWorld()->GetTimeSeconds() + 3;
				}
				else
				{
					tMedicFlood += 0.2;
				}
			}
		}
	}
	*/
}
void AHumanController::ServerCallMedic()
{
	/*
		if (Pawn != nullptr && Pawn.IsWounded())
		{
			PlayerReplicationInfo.bCallForMedic=True;
		}
	*/
}
void AHumanController::Say(FString Msg)
{
	/*
			local name CommoType;
			if (Msg == "")
			{
				return;
			}
			if (CheckRIFlood())
			{
				return;
			}
			if (Cast<AAGP_Pawn>(GetPawn()) == nullptr)
			{
				ServerSay(Msg,'Say');
				return;
			}
			Switch(Cast<AAGP_Pawn>(GetPawn()).CommoState)
			{
				case 0:
				case 1:
				CommoType='Whisper';
				break;
				case 2:
				CommoType='shout';
				break;
				case 3:
				CommoType='Radio';
				break;
				case 4:
				CommoType='Squad';
				break;
				case 5:
				CommoType='Say';
				break;
				default:
			}
			ServerSay(Msg,CommoType);
	*/

}
void AHumanController::TeamSay(FString Msg)
{
	/*
	if (Msg == "")
	{
		return;
	}
	if (CheckRIFlood())
	{
		return;
	}
	ServerSay(Msg, 'TeamSay');
	*/
}
void AHumanController::DevSay(FString Msg)
{
	/*
		if (Msg == "")
		{
			return;
		}
		if (CheckRIFlood())
		{
			return;
		}
		ServerSay(Msg,'DevSay');
	*/
}
void AHumanController::CSay(FString sMsg)
{
	/*
		local Controller C;
		if (sMsg == "")
		{
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captain or Administrators can use Command Chat");
			return;
		}
		if (CheckRIFlood())
		{
			return;
		}
		C=Level.ControllerList;
		if (C != nullptr)
		{
			if (C.IsA('HumanController') && PlayerController(C).PlayerReplicationInfo.bTournamentTeamCaptain || PlayerController(C).PlayerReplicationInfo.bAdmin)
			{
				if (PlayerReplicationInfo.bAdmin)
				{
					HumanController(C).CSayNotify("[admin]" $ PlayerReplicationInfo.PlayerName $ " COMMAND MESSAGE: " $ sMsg);
				}
				else
				{
					if (PlayerReplicationInfo.Team.TeamIndex == 0 || PlayerReplicationInfo.Team.TeamIndex == 1)
					{
						HumanController(C).CSayNotify("[" $ GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex] $ "] " $ PlayerReplicationInfo.PlayerName $ " COMMAND MESSAGE: " $ sMsg);
					}
				}
			}
			C=C.nextController;
		}
	*/

}
void AHumanController::CSayNotify(FString sMsg)
{
	/*
		local Object.Color Color;
		Color.R=247;
		Color.G=151;
		Color.B=82;
		Color.A=0;
		Player.Console.Message(sMsg,20,Color);
	*/
}
void AHumanController::PlayerList()
{
	/*
		local int IDLen;
		local int maxIDLen;
		local int maxTeamLen;
		local string teamstring;
		local byte i;
		local AGP_Scoreboard SB;
		local PlayerReplicationInfo PRI;
		local string PlayerMessage;
		local Object.Color Color;
		SB=AGP_Scoreboard(MyHUD.ScoreBoard);
		Color.R=255;
		Color.G=0;
		Color.B=255;
		Color.A=255;
		SB.UpdatePlayerList();
		maxIDLen=1;
		for (i=0; i<SB.PlayerCount; i++)
		{
			IDLen=Len(SB.GetOrdered(i).PlayerID);
			if (IDLen > maxIDLen)
			{
				maxIDLen=IDLen;
			}
		}
		if (bTournamentServer)
		{
			maxTeamLen=Max(Len(GameReplicationInfo.asTournamentTeamName[0]),Len(GameReplicationInfo.asTournamentTeamName[1]));
		}
		else
		{
			maxTeamLen=Max(Len(Level.TeamName[0]),Len(Level.TeamName[1]));
		}
		maxTeamLen=Max(maxTeamLen,Len("SPECTATOR"));
		Player.Console.Message("---------- PlayerList ----------",20,Color);
		for (i=0; i<SB.PlayerCount; i++)
		{
			PRI=SB.GetOrdered(i);
			if (PRI.bAdmin && PRI.SuperUser() || PRI.bAdmin && PRI.bOnlySpectator && ! TournamentIsTournament())
			{
			}
			PlayerMessage="" $ PRI.PlayerID $ ": ";
			PlayerMessage=AppendSpaces(PlayerMessage,maxIDLen - Len(PRI.PlayerID));
			Switch(PRI.Team.TeamIndex)
			{
				case 0:
				if (bTournamentServer)
				{
					teamstring=GameReplicationInfo.asTournamentTeamName[0];
					break;
				}
				teamstring=Level.TeamName[0];
			}
			case 1:
			if (bTournamentServer)
			{
				teamstring=GameReplicationInfo.asTournamentTeamName[1];
			}
			else
			{
				teamstring=Level.TeamName[1];
			}
			case 255:
			teamstring="SPECTATOR";
			default:
			PlayerMessage=PlayerMessage $ teamstring;
			PlayerMessage=AppendSpaces(PlayerMessage,maxTeamLen - Len(teamstring) + 1);
			PlayerMessage=PlayerMessage $ PRI.GetHumanReadableName();
			Player.Console.Message(PlayerMessage,20,Color);
		}
		Player.Console.Message("--------------------------------------------",20,Color);
	*/
}
void AHumanController::ReasonList()
{
	/*
		local int i;
		local string Reason;
		local Object.Color Color;
		Color.R=255;
		Color.G=0;
		Color.B=255;
		Color.A=255;
		i=5;
		Player.Console.Message("----------------------------------------",20,Color);
		if (True)
		{
			Reason=GetReason(i);
			if (Reason == "")
			{
			}
			Player.Console.Message(i -- $ " " $ Reason,20,Color);
		}
		Player.Console.Message("---------- ReasonList ----------",20,Color);
	*/
}
FString AHumanController::GetReason(int32 i)
{
	/*
	switch(i)
	{
			case 1:
				return "Player is idle";
			case 2:
				return "Player is intentionally violating ROE";
			case 3:
				return "Player has used foul or abusive language";
			case 4:
				return "Player is spamming chat";
			case 5:
				return "Player is camping";
			default:
				return "";
	}
	*/
	return "";
}
FString AHumanController::AppendSpaces(FString append, int32 spaces)
{
	int32 i;
	for (i = 0; i < spaces; i++)
	{
		append = append + " ";
	}
	return append;
}
void AHumanController::MaybeGetPlayerNameFromID(FString PlayerName)
{
	/*
	local int i;
	local int voteid;
	local AGP_Scoreboard SB;
	local string newplayername;
	local PlayerReplicationInfo PRI;
	local string TempName;
	if (PlayerName == "")
	{
		return PlayerName;
	}
	voteid = PlayerName;
	SB = AGP_Scoreboard(MyHUD.ScoreBoard);
	SB.UpdatePlayerList();
	for (i = 0; i < SB.PlayerCount; i++)
	{
		PRI = SB.GetOrdered(i);
		TempName = PRI.GetHumanReadableName();
		if (PlayerName ~= TempName)
		{
			return PlayerName;
		}
		else
		{
			if (PRI.EquivalentName(PlayerName))
			{
				newplayername = TempName;
			}
		}
	}
	if (newplayername != "")
	{
		return newplayername;
	}
	else
	{
		return PlayerName;
	}
	*/
}
void AHumanController::GetPlayerFromID(int32 iPlayerID)
{
	/*
		local Controller C;
		local PlayerController PC;
		C=Level.ControllerList;
		if (C != nullptr)
		{
			PC=PlayerController(C);
			if (PC != nullptr && PC.PlayerReplicationInfo.PlayerID == iPlayerID)
			{
				return PC;
			}
			C=C.nextController;
		}
		PC=None;
		return PC;
	*/
}
void AHumanController::DevKick(FString PlayerName)
{
	/*
	PlayerName = MaybeGetPlayerNameFromID(PlayerName);
	ServerDevKick(PlayerName);
	*/
}
void AHumanController::ServerDevKick(FString PlayerName)
{
	//Level.Game.CheckDevKick(this,PlayerName);
}
void AHumanController::SUToggle()
{
	//PlayerReplicationInfo.SUToggle();
}
void AHumanController::ParseNameAndReason(FString Input, FString PlayerName, int32 iReason)
{
	/*
		local int i;
		local string sReason;
		i=InStr(Input," ");
		if (i == -1)
		{
			PlayerName=Input;
			iReason=0;
		}
		else
		{
			PlayerName=Left(Input,i);
			sReason=Mid(Input,i + 1);
			iReason=sReason;
		}
	*/
}
void AHumanController::votekick(FString Input)
{
	/*
		local string PlayerName;
		local int iReason;
		ParseNameAndReason(Input,PlayerName,iReason);
		PlayerName=MaybeGetPlayerNameFromID(PlayerName);
		if (PlayerName != "" && GetReason(iReason) == "")
		{
			ClientShowVotekickInstructions();
			ClientMessage("You must give a reason.");
		}
		else
		{
			ServerVoteKick(PlayerName,iReason);
		}
	*/
}
void AHumanController::ClientShowVotekickInstructions()
{
	/*
	ReasonList();
	ClientMessage("Example: to kick Idle player 'Fred': 'votekick Fred 1'");
	ClientMessage("REASON_ID must be a number from the list below.");
	ClientMessage("Use PLAYERLIST to view a list of players and player numbers");
	ClientMessage("Use 'votekick [PLAYERNAME or NUMBER] REASON_ID'");
	*/
}
void AHumanController::ServerVoteKick(FString PlayerName, int32 iReason)
{
	/*
		if (PlayerName == "")
		{
			if (! Level.Game.ActiveVote())
			{
				ClientShowVotekickInstructions();
				return;
			}
			Level.Game.CastVote(PlayerReplicationInfo);
		}
		else
		{
			if (iReason == 5)
			{
				Level.Game.InitiateVoteRequest(PlayerReplicationInfo,PlayerReplicationInfo.PlayerName,"Player is complaining about campers");
			}
			else
			{
				Level.Game.InitiateVoteRequest(PlayerReplicationInfo,PlayerName,GetReason(iReason));
			}
		}
	*/
}
void AHumanController::ServerSay(FString Msg, FName Type)
{
	Msg=StripColorCodes(Msg);
	PlayerReplicationInfo->BlinkCharacterOnRadar(2);
	//Level.Game.Broadcast(this,Msg,Type);
}
FString AHumanController::StripBadCodes(FString InString)
{
	InString = InString.Replace(TEXT("£"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("µ"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("¨"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("`"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("§"), TEXT(""), ESearchCase::IgnoreCase);
	return InString;
}
FString AHumanController::StripColorCodes(FString InString)
{
	int32 p;
	InString.FindChar(TCHAR(27), p);
	while (p >= 0)
	{
		InString.RemoveAt(p, 4);
		InString.FindChar(TCHAR(27), p);
	}
	return InString;
}
bool AHumanController::GetLanguageFilter()
{
	return true;
}

FString AHumanController::FilterLanguage(FString S)
{
	return S;
}
FString AHumanController::FilterAlways(FString S)
{
	return S;
}
FString AHumanController::ApplyFilters(FString S)
{
	if (GetLanguageFilter())
	{
		S=FilterLanguage(S);
	}
	S=FilterAlways(S);
	return S;
}
void AHumanController::SubstituteKeyNames(FString S)
{
	/*
		local int Position;
		local int StrLen;
		local int Count;
		local string tmp;
		local string tcmd;
		local string retval;
		local string cmdin;
		local string cmdout;
		local Interactions.EInputKey cmdkey;
		retval="";
		Position=0;
		StrLen=Len(S);
		if (Position < StrLen)
		{
			tmp=Mid(S,Position,1);
			retval=retval $ tmp;
			if (tmp == "<")
			{
				cmdin="";
				for (Position++; Position<StrLen; Position++)
				{
					tcmd=Mid(S,Position,1);
					if (tcmd == ">" || tcmd == " ")
					{
					}
					else
					{
						cmdin=cmdin $ tcmd;
					}
				}
				if (tcmd == ">" && Player.Console.IsValidCommand(cmdin))
				{
					Count=0;
					if (Player.Console.GetCommandKey(cmdin,cmdkey,cmdout,Count))
					{
						if (Count > 0)
						{
							retval=retval $ " or ";
						}
						retval=retval $ Caps(cmdout);
						Count ++;
					}
					if (Count == 0)
					{
						retval=retval $ "no key bound: " $ Caps(cmdin);
					}
					retval=retval $ ">";
				}
				else
				{
					retval=retval $ cmdin;
					if (tcmd == ">" || tcmd == " ")
					{
						retval=retval $ tcmd;
					}
				}
			}
			Position ++;
		}
		return retval;
	*/
}
void AHumanController::old_SelectTeam()
{
	if (! bPBChecked)
	{
		return;
	}
	if (GetNetMode() == ENetMode::NM_Client)
	{
		if (Cast<AAGP_HUD>(MyHUD) != NULL)
		{
			Cast<AAGP_HUD>(MyHUD)->ToggleTeamSelect();
		}
	}
}
void AHumanController::old_ClientTeamSelectMenu(bool bOpen)
{
	/*
		if (! bPBChecked)
		{
			return;
		}
		if (Role == 4)
		{
			return;
		}
		if (PlayerReplicationInfo.bAdmin)
		{
			return;
		}
		if (bOpen)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->OpenTeamSelect();
			}
		}
		else
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->CloseGameMenu();
			}
		}
	*/
}
void AHumanController::ClientTeamSelectMenu(bool bOpen)
{
	/*
		if (Role == 4 || PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.bOnlySpectator)
		{
			return;
		}
		if (! bPBChecked)
		{
			return;
		}
		if (bOpen)
		{
			SelectTeam("Recreate");
		}
	*/
}
void AHumanController::SelectTeam(FString Param2)
{
	
		if (! bPBChecked)
		{
			return;
		}
		if (bTournamentServer)
		{
			/*
			if (! PlayerReplicationInfo.bAdmin)
			{
				ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
			}
			else
			{
				ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Tournament",Param2);
			}
			*/
		}
		else
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
		}
	
}
void AHumanController::OLD_SelectClass()
{
	/*
		if (! bPBChecked)
		{
			return;
		}
		if (GetNetMode() == ENetMode::NM_Client)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->ToggleClassSelect();
			}
		}
	*/
}
void AHumanController::SelectClass(FString Param2)
{
	
	if (! bPBChecked)
	{
		return;
	}
	if (TournamentIsTournament())
	{
		if (CanShowRoster())
		{
			ClientCloseMenu(false,false);
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Roster",Param2);
		}
		else
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
		}
	}
	else
	{
		if (CanShowWeaponClass())
		{
			ClientCloseMenu(false,false);
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Weapon Class",Param2);
		}
		else
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
		}
	}
	
}
bool AHumanController::CanShowRoster()
{
	//return PlayerReplicationInfo.bAdmin || PlayerReplicationInfo.bTournamentTeamCaptain || PlayerReplicationInfo.Team.TeamIndex != 255 || PlayerReplicationInfo.DesiredTeam != 255;
	return true;    //FAKE   /ELiZ
}
bool AHumanController::CanShowWeaponClass()
{
	//return PlayerReplicationInfo != nullptr && PlayerReplicationInfo.Team != nullptr && PlayerReplicationInfo.Team.TeamIndex != 255 || PlayerReplicationInfo.DesiredTeam != 255 && GameReplicationInfo.Teams[PlayerReplicationInfo.DesiredTeam].Size < GameReplicationInfo.Teams[PlayerReplicationInfo.DesiredTeam].MaxSize;
	return true;    //FAKE   /ELiZ
}
void AHumanController::ShowScores(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (Cast<AAA2_GameState>(GetWorld()->GetGameState())->bShouldShowScoreboard || PlayerReplicationInfo->bAdmin || PlayerReplicationInfo->bOnlySpectator)
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Score","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
	else
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
}
void AHumanController::ShowMap(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Map","") == false)
	{
		ClientCloseMenu(false,false);
	}
}
void AHumanController::ShowObjectives(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Map","") == false)
	{
		ClientCloseMenu(false,false);
	}
}
void AHumanController::ShowServerInfo(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (bAllowScoreShown)
	{
		if (bTournamentServer)
		{
			if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Tournament","") == false)
			{
				ClientCloseMenu(false,false);
			}
		}
		else
		{
			if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Server Info","") == false)
			{
				ClientCloseMenu(false,false);
			}
		}
	}
}
void AHumanController::ShowTournament(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (bTournamentServer)
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Tournament","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
	else
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Server Info","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
}
void AHumanController::ShowSurvey(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Survey","") == false)
	{
		ClientCloseMenu(false,false);
	}
}
bool AHumanController::CanShowScores()
{
	return true;
}
void AHumanController::CanSelectTeam()
{
	//return !PlayerReplicationInfo.bAdmin;
}
void AHumanController::CanSelectClass()
{
	//return ! TournamentIsTournament() || TournamentIsTournament() && ! TournamentIsTeamRosterLocked(PlayerReplicationInfo.Team.TeamIndex) || PlayerReplicationInfo.bAdmin;
}
bool AHumanController::CanShowServerInfo()
{
	return true;
}
void AHumanController::ShowMenu()
{
	ClientCloseMenu(true,false);
	ClientOpenMenu("AGP_Interface.AAMainMenu",false,"","");
}
void AHumanController::RequestMedic(bool bMedic)
{
	if (GetNetMode()  == ENetMode::NM_Client)
	{
		
		if (PlayerReplicationInfo->bQualifiedMedic)
		{
			PlayerReplicationInfo->bWantsMedic=bMedic;
		}
		ServerRequestMedic(bMedic);
	}
}
void AHumanController::ServerRequestMedic(bool bMedic)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (PlayerReplicationInfo->bQualifiedMedic)
		{
			PlayerReplicationInfo->bWantsMedic=bMedic;
		}
		else
		{
			PlayerReplicationInfo->bWantsMedic=false;
		}
		ClientNotifyMedic(PlayerReplicationInfo->bWantsMedic);
		PlayerReplicationInfo->Team->TestMedics();
	}
}
void AHumanController::ClientNotifyMedic(bool bMedic)
{
	PlayerReplicationInfo->bWantsMedic=bMedic;
}
void AHumanController::SetPreferredClass(int32 i, bool bAvoidLeader, bool bMedic, int32 prev_i, bool prev_b)
{
	/*
		local TeamInfo Team;
		if (GetNetMode() == ENetMode::NM_Client)
		{
			Team=PlayerReplicationInfo.Team;
			if (i != prev_i)
			{
				Team.NumDesired[i] ++;
				if (prev_i != -1)
				{
					Team.NumDesired[prev_i] --;
				}
			}
			if (bAvoidLeader != prev_b)
			{
				if (bAvoidLeader)
				{
					Team.NumLeadersDesired ++;
				}
				else
				{
					Team.NumLeadersDesired --;
				}
			}
			ServerSetDesiredTeamClass(i,bAvoidLeader,bMedic);
		}
	*/
}
void AHumanController::ClientForceNewClass(FString ClassName)
{
		//ASoldierClass* sclass;
		//FString sclass_name;
		
		if (GetPawn() == NULL)
		{
			return;
		}
		//LockPlayer(False,False);
		
		/*
		Switch(ClassName)
		{
			case "":
			ScreenPrint("Type ""Class X"" where classes are R, AR, G, S, RCT, AK, FT, SL, S24, F, AK74SU, M4A1, SVD, GP, RPK");
			return;
			case "M":
			case "M4A1":
			sclass_name="AGP_Characters.ClassRiflemanM4A1AutoIron";
			break;
			case "M4A1Auto":
			sclass_name="AGP_Characters.ClassRiflemanM4A1Auto";
			break;
			case "AK74SU":
			sclass_name="AGP_Characters.ClassRiflemanAK74SU";
			break;
			case "AR":
			case "AutomaticRifleman":
			sclass_name="AGP_Characters.ClassAutomaticRifleman";
			break;
			case "R":
			case "Rifleman":
			sclass_name="AGP_Characters.ClassRifleman";
			break;
			case "RCT":
			case "Recruit":
			sclass_name="AGP_Characters.ClassRecruit";
			break;
			case "AK":
			case "RiflemanAK":
			sclass_name="AGP_Characters.ClassRiflemanAK";
			break;
			case "G":
			case "Grenadier":
			sclass_name="AGP_Characters.ClassGrenadier";
			break;
			case "S":
			case "Sniper":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniper";
			}
			GOTO JL0609;
			case "S24":
			case "Sniper24":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniper24_US";
			}
			GOTO JL0609;
			case "SVD":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniperSVD";
			}
			GOTO JL0609;
			case "GP":
			sclass_name="AGP_Characters.ClassGrenadierGP30_Op";
			GOTO JL0609;
			case "RPK":
			sclass_name="AGP_Characters.ClassAutomaticRiflemanRPK";
			GOTO JL0609;
			case "Mos":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniperMos";
			}
			GOTO JL0609;
			case "M4M":
			sclass_name="AGP_Characters.ClassRiflemanM4A1Mod";
			GOTO JL0609;
			case "J":
			if (! PlayerReplicationInfo.bQualifiedJavelin)
			{
				sclass_name="AGP_Characters.ClassJavelinTube";
			}
			else
			{
				sclass_name="AGP_Characters.ClassJavelin";
			}
			default:
			ScreenPrint("Unrecognized class " $ ClassName);
			ScreenPrint("Type ""Class X"" where classes are R, AR, G, S, RCT, AK, FT, SL, S24, F, AK74SU, M4A1, SVD, GP, RPK");
			return;
JL0609:
		}
		CleanUp();
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).bForcedWeaponChange=True;
		}
		sclass=class<SoldierClass>(DynamicLoadObject(sclass_name,Class'Class'));
		newTeamClass(sclass);
	*/
}
bool AHumanController::QualifiedFor(AActor*  Desired)
{
	/*
		ASoldierClass* sclass;
		if (Desired == NULL)
		{
			return true;
		}
		sclass=Cast<ASoldierClass>(Desired);
		if (sclass == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("HumanController::QualifiedFor() Unknown class " $ Desired));
			return false;
		}
		if (sclass.Default.nativeWeapon == 4)
		{
			if (bNoSniper)
			{
				return false;
			}
			UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo.bQualifiedSniper:" @ PlayerReplicationInfo.bQualifiedSniper));
			return PlayerReplicationInfo.bQualifiedSniper;
		}
		if (sclass.Default.nativeWeapon == 8)
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo.bQualifiedJavelin:" @ PlayerReplicationInfo.bQualifiedJavelin));
			return PlayerReplicationInfo.bQualifiedJavelin;
		}
		return true;
	*/
	return true;			//Fake ELiZ
}

ASoldierClass* AHumanController::GetDesiredTeamClass()
{
	if (QualifiedFor(DesiredTeamClass))
	{
		return DesiredTeamClass;
	}
	else
	{
		return NULL;
	}
}
void AHumanController::ServerSetDesiredTeamClass(int32 i, bool bAvoidLeader, bool bMedic)
{
	/*
		local TeamInfo MyTeam;
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this,"CHEATER");
			return;
		}
		MyTeam=PlayerReplicationInfo.Team;
		if (MyTeam.IsClassAvailable(i))
		{
			PlayerReplicationInfo.bWantsMedic=bMedic;
			PlayerReplicationInfo.bAvoidLeaderRole=bAvoidLeader;
			PlayerReplicationInfo.bWantsSquadLeader=MyTeam.IsSquadLeader(i);
			PlayerReplicationInfo.bWantsFTLeader=MyTeam.IsFTLeader(i);
			DesiredTeamClass=class<SoldierClass>(MyTeam.GetClass(i));
			if (! QualifiedFor(DesiredTeamClass))
			{
				DesiredTeamClass=None;
			}
			MyTeam.CountDesiredPlayerStarts();
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerSetDesiredTeamClass()	" $ DesiredTeamClass));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerSetDesiredTeamClass()	Tried to set unavailable class " $ this @ i));
		}
	*/
}

void AHumanController::ServerEnablePlayer()
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			PlayerReplicationInfo.bReadyToPlay=True;
		}
	*/
}

void AHumanController::NotifyPendingTeamChange(uint8 NewTeam, bool bForceNotify)
{
	/*
		local string TeamName;
		local string TeamChangeText;
		local string ExtraText;
		if (PlayerReplicationInfo.Team.TeamIndex == NewTeam)
		{
			TeamChangeText="Remaining on";
			if (NewTeam == 255)
			{
				TeamName="Spectator";
			}
			else
			{
				if (TournamentIsTournament())
				{
					if (GameReplicationInfo.asTournamentTeamName[NewTeam] != "")
					{
						TeamName=GameReplicationInfo.asTournamentTeamName[NewTeam];
					}
					else
					{
						TeamName=Level.TeamName[NewTeam];
					}
				}
				else
				{
					TeamName=Level.TeamName[NewTeam];
				}
			}
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(4,TeamChangeText @ TeamName @ ExtraText);
			}
		}
		else
		{
			if (NewTeam == 255)
			{
				TeamName="Spectator";
			}
			else
			{
				if (TournamentIsTournament())
				{
					TeamChangeText="Joining";
					if (GameReplicationInfo.asTournamentTeamName[NewTeam] != "")
					{
						TeamName=GameReplicationInfo.asTournamentTeamName[NewTeam];
					}
					else
					{
						TeamName=Level.TeamName[NewTeam];
					}
				}
				else
				{
					TeamChangeText="Changing to";
					ExtraText="next round ";
					TeamName=Level.TeamName[NewTeam];
				}
			}
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(4,TeamChangeText @ TeamName @ ExtraText);
			}
		}
		PlayerReplicationInfo.DesiredTeam=NewTeam;
	*/
}

void AHumanController::NotifyPBAuthMessage(FString Msg)
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessageLong(8, Msg);
	}
}
void AHumanController::ClientNotifyAdminMessage(FString sMsg)
{
	NotifyAdminMessage(sMsg);
}
void AHumanController::ToggleNotificationMessages()
{
	if(Cast<AAGP_HUD>(MyHUD) !=nullptr)
	{
	Cast<AAGP_HUD>(MyHUD)->bDisableNotificationMessages=!Cast<AAGP_HUD>(MyHUD)->bDisableNotificationMessages;
		if (Cast<AAGP_HUD>(MyHUD)->bDisableNotificationMessages)
		{
			ClientMessage("Centered notification messages disabled.");
		}
		else
		{
			ClientMessage("Centered notification messages enabled");
		}
	}
}
void AHumanController::NotifyAdminMessage(FString Msg)
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessageLong(4,Msg);
	}
}

void AHumanController::LoadJacket()
{
	/*
		local string sFile;
		local string sTemp;
		local string sMissions;
		local string Line;
		local array<String> asJacketParts;
		local string sVersion;
		local int iJacketRifleRangeCheck;
		local int iJacketHonorCheck;
		local int iJacketChecksum;
		local int iJacketSecondaryChecksum;
		local int iField;
		local int i;
		local int iChar;
		local int iCalculatedChecksum;
		UE_LOG(LogTemp, Warning, TEXT("Loading Jacket..."));
		sTemp=GetBaseDir();
		sFile=sFile $ "save\" $ UserName $ ".dat";
		UE_LOG(LogTemp, Warning, TEXT("Loading Profile Jacket file: " $ sFile));
		for (i=0; i<33; i++)
		{
			iCompleted[i]=0;
		}
		if (! FOpen(sFile))
		{
			Log("Failed opening user profile file: " $ sFile);
			return;
		}
		FReadLine(Line);
		FClose();
		Split(Line,",",asJacketParts);
		sVersion=asJacketParts[0];
		if (sVersion != "240")
		{
			Log("Invalid version for user personnel jacket file.");
			return;
		}
		iJacketRifleRangeCheck=asJacketParts[1];
		iJacketHonorCheck=asJacketParts[2];
		iJacketChecksum=asJacketParts[3];
		sMissions="";
		for (iField=4; iField<38; iField++)
		{
			sMissions=sMissions $ asJacketParts[iField] $ ",";
		}
		sMissions=sMissions $ asJacketParts[iField] $ ",";
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo._iTrust=asJacketParts[iField ++];
		}
		else
		{
			iField ++;
		}
		sMissions=sMissions $ asJacketParts[iField ++] $ ",";
		if (PlayerReplicationInfo != nullptr)
		{
			sMissions=sMissions $ asJacketParts[iField] $ ",";
			PlayerReplicationInfo._Experience=asJacketParts[iField ++];
			sMissions=sMissions $ asJacketParts[iField] $ ",";
			PlayerReplicationInfo._Group=asJacketParts[iField ++];
		}
		else
		{
			sMissions=sMissions $ asJacketParts[iField ++] $ ",";
			sMissions=sMissions $ asJacketParts[iField ++] $ ",";
		}
		sMissions=sMissions $ asJacketParts[iField] $ ",";
		iUID=asJacketParts[iField ++];
		iJacketSecondaryChecksum=65535 - asJacketParts[iField];
		iCalculatedChecksum=0;
		for (iChar=0; iChar<Len(sMissions); iChar++)
		{
			iCalculatedChecksum += Asc(Mid(sMissions,iChar,1));
		}
		ParseMissionString(sMissions);
		if (iCalculatedChecksum != iJacketChecksum || iJacketSecondaryChecksum != iJacketChecksum || 755555 - iJacketRifleRangeCheck != iRifleRangeRating || PlayerReplicationInfo != nullptr && 755555 - iJacketHonorCheck != PlayerReplicationInfo.GetHonor())
		{
			Log("Invalid personnel jacket file");
			for (i=0; i<33; i++)
			{
				iCompleted[i]=0;
			}
			iRifleRangeRating=0;
			if (PlayerReplicationInfo != nullptr)
			{
				PlayerReplicationInfo._Experience=0;
				PlayerReplicationInfo._iTrust=0;
			}
			return;
		}
		UpdateAuthRelatedPRI();
	*/
}

void AHumanController::SaveJacket()
{
	/*
		local string sFile;
		local string sTemp;
		local string sMissions;
		local int iChecksum;
		local int iChar;
		if (PlayerReplicationInfo == nullptr || iRifleRangeRating == 0 && PlayerReplicationInfo._Experience != 0 || PlayerReplicationInfo.GetHonor() != 0)
		{
			Log("Invalid values, cannot save Player Jacket");
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("Saving Jacket..."));
		sTemp=GetBaseDir();
		sFile=sFile $ "save\" $ UserName $ ".dat";
		if (! FOpenWrite(sFile))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed opening for write " $ sFile));
			return;
		}
		FWrite("240,");
		FWrite("" $ 755555 - iRifleRangeRating $ ",");
		FWrite("" $ 755555 - PlayerReplicationInfo.GetHonor() $ ",");
		sMissions=GenerateMissionString();
		for (iChar=0; iChar<Len(sMissions); iChar++)
		{
			iChecksum += Asc(Mid(sMissions,iChar,1));
		}
		FWrite("" $ iChecksum $ ",");
		FWrite(sMissions);
		FWrite("" $ 65535 - iChecksum);
		FClose();
	*/
}

void AHumanController::VerifyJacket()
{
	/*
		local int iCurTour;
		local int iCurMission;
		local int iNumTours;
		local int iNumMissions;
		local int iDependency;
		local bool bTourComplete;
		local bool bMissionsComplete;
		local bool bSequential;
		local bool bClearMissions;
		local int iTempMissions;
		UE_LOG(LogTemp, Warning, TEXT("Verifying Jacket..."));
		iNumTours=Level.iNumTours;
		for (iCurTour=0; iCurTour<iNumTours; iCurTour++)
		{
			iTempMissions=0;
			iNumMissions=Level.GetTourMissions(iCurTour);
			iDependency=Level.GetTourDependency(iCurTour);
			bSequential=Level.GetTourIsSequential(iCurTour);
			if (2 ** iCurTour & iCompleted[0] > 0)
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("Tour" @ iCurTour @ "is flagged as completed"));
				}
				if (iDependency != -1)
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("we have a dependency:" @ iDependency));
					}
					if (2 ** iDependency & iCompleted[0] == 0)
					{
						if (Level.debugAuth)
						{
							UE_LOG(LogTemp, Warning, TEXT("dependency not met, clearing"));
						}
						iCompleted[0] -= 2 ** iCurTour;
						iCompleted[iCurTour + 1]=0;
					}
				}
				bMissionsComplete=True;
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("checking missions"));
				}
				for (iCurMission=0; iCurMission<iNumMissions; iCurMission++)
				{
					iTempMissions += 2 ** iCurMission;
					if (2 ** iCurMission & iCompleted[iCurTour + 1] == 0)
					{
						if (Level.debugAuth)
						{
							UE_LOG(LogTemp, Warning, TEXT("missions not complete"));
						}
						bMissionsComplete=False;
					}
				}
				if (! bMissionsComplete)
				{
					if (2 ** iCurTour & iCompleted[0] > 0)
					{
						iCompleted[0] -= 2 ** iCurTour;
					}
				}
				else
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("turning off extra bits iTempMissions is" @ iTempMissions));
					}
					if (iCompleted[iCurTour + 1] != iTempMissions)
					{
						iCompleted[iCurTour + 1]=iTempMissions;
					}
				}
			}
			else
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("Tour" @ iCurTour @ "is NOT flagged as completed"));
				}
				if (iDependency != -1)
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("we have a dependency:" @ iDependency));
					}
					if (2 ** iDependency & iCompleted[0] == 0)
					{
						if (Level.debugAuth)
						{
							UE_LOG(LogTemp, Warning, TEXT("dependency not met, clearing"));
						}
						iCompleted[iCurTour + 1]=0;
					}
				}
				bTourComplete=True;
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("checking missions"));
				}
				for (iCurMission=0; iCurMission<iNumMissions; iCurMission++)
				{
					if (2 ** iCurMission & iCompleted[iCurTour + 1] == 0)
					{
						bTourComplete=False;
					}
					else
					{
						iTempMissions += 2 ** iCurMission;
					}
				}
				if (bTourComplete == true)
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("tour complete"));
					}
					if (2 ** iCurTour & iCompleted[0] == 0)
					{
						iCompleted[0] += 2 ** iCurTour;
					}
				}
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("turning off extra bits iTempMissions is" @ iTempMissions));
				}
				if (iCompleted[iCurTour + 1] != iTempMissions)
				{
					iCompleted[iCurTour + 1]=iTempMissions;
				}
			}
			if (bSequential)
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("this tour is sequential"));
				}
				bClearMissions=False;
				for (iCurMission=0; iCurMission<iNumMissions; iCurMission++)
				{
					if (bClearMissions)
					{
						if (2 ** iCurMission & iCompleted[iCurTour + 1] > 0)
						{
							if (Level.debugAuth)
							{
								UE_LOG(LogTemp, Warning, TEXT("clearing mission" @ iCurMission));
							}
							iCompleted[iCurTour + 1] -= 2 ** iCurMission;
						}
					}
					if (2 ** iCurMission & iCompleted[iCurTour + 1] == 0)
					{
						bClearMissions=True;
						if (Level.debugAuth)
						{
							UE_LOG(LogTemp, Warning, TEXT("clear out rest of missions - iCurMission is" @ iCurMission));
						}
					}
				}
			}
		}
		if (iRifleRangeRating < 36)
		{
			if (iCompleted[0] & 16 == 1)
			{
				iCompleted[0] -= 16;
				iCompleted[5]=0;
			}
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			Level.UpdateAllMissionsStatus(this);
		}
	*/
}

void AHumanController::LimitPawnRotation(bool bLimit, FRotator rRotator)
{
	if (Cast<AAGP_Pawn>(GetPawn()) != NULL)
	{
		Cast<AAGP_Pawn>(GetPawn())->rBaseRotation = Cast<AAGP_Pawn>(GetPawn())->GetViewRotation();
		Cast<AAGP_Pawn>(GetPawn())->rRotationLimits = rRotator;
		Cast<AAGP_Pawn>(GetPawn())->LimitRotation(bLimit);
	}
}
void AHumanController::bind(FString Command)
{
	//PrivateSet("input " $ Command);
}
void AHumanController::QueryServerList()
{
}
void AHumanController::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
}
FString AHumanController::GetServerSection(int32 Index)
{
	return "";
}
void AHumanController::SetServerSetting(int32 Index, FString Value)
{
}
void AHumanController::SetServerSettingReply(int32 Index, FString Value)
{
}
void AHumanController::KickPlayer(FString PlayerName)
{
	if (PlayerReplicationInfo == nullptr || ! PlayerReplicationInfo->bAdmin)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player " + PlayerReplicationInfo.PlayerName + " is not an admin!"));
		return;
	}
	//ConsoleCommand("kick" @ PlayerName);
}
void AHumanController::BanPlayer(FString PlayerName)
{
	if (PlayerReplicationInfo == nullptr || ! PlayerReplicationInfo->bAdmin)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player " $ PlayerReplicationInfo.PlayerName $ " is not an admin!"));
		return;
	}
//ConsoleCommand("kickban" @ PlayerName);
}
void AHumanController::MutePlayer(FString PlayerName)
{
	if (PlayerReplicationInfo == nullptr || ! PlayerReplicationInfo->bAdmin)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player " $ PlayerReplicationInfo.PlayerName $ " is not an admin!"));
		return;
	}
	//ConsoleCommand("mute" @ PlayerName);
}

int32 AHumanController::GetServerSettingsCount()
{
	return 0;
}

FString AHumanController::GetServerKey(int32 Index)
{
	return "";
}
void AHumanController::SetServerKey(int32 Index, FString Key)
{
}
FString AHumanController::GetServerKeyValue(int32 Index)
{
	return "";
}
void AHumanController::SetServerKeyValue(int32 Index, FString Value)
{
}
void AHumanController::RefreshServerInfo(bool bInitialize)
{
}
void AHumanController::LoadPSettings()
{
	/*
		local string sFile;
		local string sTemp;
		local string sString;
		local string sKey;
		local string Line;
		sKey="p";
		sTemp=GetBaseDir();
		sFile=sFile $ "pc.dat";
		sKey=sKey $ "4";
		if (! FOpen(sFile))
		{
			return;
		}
		sKey=sKey $ "r3";
		FReadLine(Line);
		sKey=sKey $ "n7";
		sString=Extract(Line,sKey);
		ParsePC(sString);
		FClose();
	*/
}
void AHumanController::SavePSettings()
{
	/*
		local string sFile;
		local string sTemp;
		local string sMissions;
		local string sKey;
		local int sValue;
		sKey="p";
		sTemp=GetBaseDir();
		sKey=sKey $ "4";
		sFile=sFile $ "pc.dat";
		sKey=sKey $ "r3";
		if (! FOpenWrite(sFile))
		{
			return;
		}
		sValue=GetLanguageFilter() + GetNoBlood() * 2 + GetMilesOnly() * 4 + GetNoSniper() * 8;
		sMissions=sValue $ "," $ ParentPassword $ ",";
		sKey=sKey $ "n7";
		sMissions=Compress(sMissions,sKey);
		FWriteLine(sMissions);
		FClose();
	*/
}
void AHumanController::ParsePC(FString sString)
{
		int32 iCounter;
		int32 iPos = 0;
		FString sTemp;
		FString string0;
		FString string1;
		bool bDone = false;
		int32 iValue = 0;
		FString sChar;
		
		sTemp=sString;
		iCounter=0;
		sChar=",";
		//iPos=InStr(sTemp,sChar);
		
		if (iPos == -1)
		{
			bDone=true;
			if (sTemp != "")
			{
				//iValue=sTemp;
			}
		}
		else
		{
			//string0=Left(sTemp,iPos);
			//string1=Right(sTemp,Len(sTemp) - iPos - 1);
			//if (string0 != "")
			//{
			//	iValue=string0;
			//}
		}
		if (iCounter == 0)
		{
			if ((iValue & 1) == 1)
			{
				//SetLanguageFilter(true);
			}
			else
			{
				//SetLanguageFilter(false);
			}
			if ((iValue & 2) == 2)
			{
				//SetNoBlood(true);
			}
			else
			{
				//SetNoBlood(false);
			}
			if ((iValue & 4) == 4)
			{
				//SetMilesOnly(true);
			}
			else
			{
				//SetMilesOnly(false);
			}
			if ((iValue & 8) == 8)
			{
				//SetNoSniper(true);
			}
			else
			{
				//SetNoSniper(false);
			}
		}
		if (iCounter == 1)
		{
			ParentPassword=string0;
		}
		sTemp=string1;
		iCounter ++;
		//if (bDone)
		//{
		//}


}
void AHumanController::ClientSetPMessage(int32 messID)
{
	if (messID > 0)
	{
		//PrivateSet("LevelInfo PMessage " $ messID);
		if(Cast<AAGP_HUD>(MyHUD) !=nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->PMessage=messID;
		}
	}
}
void AHumanController::ServerSetPC(bool bNS)
{
	bNoSniper = bNS;
}
void AHumanController::LoadServerCommands(FString Filename)
{
	/*
		local string sFile;
		local string sDir;
		local string sCommands;
		local string Line;
		sDir=GetBaseDir();
		if (Filename ~= "")
		{
			sFile=sFile $ "RunServer.bat";
		}
		else
		{
			sFile=sFile $ Filename;
		}
		if (! FOpen(sFile))
		{
			return;
		}
		FReadLine(Line);
		sCommands=Line;
		ParseServerCommands(sCommands);
		FClose();
	*/
}
void AHumanController::SaveServerCommands(FString Filename)
{
	/*
		local string ServerExecutable;
		local string ServerType;
		local string MapName;
		local string LogFile;
		local string INIfile;
		local string sFile;
		local string sDir;
		local string sCommands;
		sDir=GetBaseDir();
		if (Filename ~= "")
		{
			sFile=sFile $ "RunServer.bat";
		}
		else
		{
			sFile=sFile $ Filename;
		}
		if (! FOpenWrite(sFile))
		{
			return;
		}
		sCommands=ServerExecutable @ ServerType @ MapName @ "log=" $ LogFile @ "ini=" $ INIfile;
		FWriteLine(sCommands);
		FClose();
	*/
}
void AHumanController::ParseServerCommands(FString sString)
{
	/*
		local string ServerExecutable;
		local string ServerType;
		local string MapName;
		local string LogFile;
		local string INIfile;
		local int iCounter;
		local int iPos;
		local string sTemp;
		local string string0;
		local string string1;
		local bool bDone;
		local int iValue;
		local string sChar;
		sTemp=sString;
		iCounter=0;
		sChar=" ";
		iPos=InStr(sTemp,sChar);
		if (iPos == -1)
		{
			bDone=True;
			if (sTemp != "")
			{
				iValue=sTemp;
			}
		}
		else
		{
			string0=Left(sTemp,iPos);
			string1=Right(sTemp,Len(sTemp) - iPos - 1);
			if (string0 != "")
			{
				iValue=string0;
			}
		}
		if (iCounter == 0)
		{
			ServerExecutable=string1;
		}
		if (iCounter == 1)
		{
			ServerType=string1;
		}
		if (iCounter == 2)
		{
			MapName=string1;
		}
		if (iCounter == 3)
		{
			LogFile=string1;
		}
		if (iCounter == 4)
		{
			INIfile=string1;
		}
		sTemp=string1;
		iCounter ++;
		if (bDone)
		{
	*/
}
void AHumanController::ServerSetAutoSwapFromGrenade(bool bstatus)
{
	bAutoSwapFromGrenade = bstatus;
}
void AHumanController::ServerSetAutoWalkZoom(bool bstatus)
{
	bAutoWalkZoom = bstatus;
}
void AHumanController::SetTurret(AActor* A)
{
	Turret = Cast<AFixedWeaponAttachment>(A);
	ClientSetTurret(A);
}
void AHumanController::ClientSetTurret(AActor* A)
{
	Turret = Cast<AFixedWeaponAttachment>(A);
}
void AHumanController::SetCamera(AActor* C, UTexture2D* Overlay)
{
	RemoteCamera=C;
	ClientSetCamera(C,Overlay);
}
void AHumanController::ClientSetCamera(AActor* C, UTexture2D* Overlay)
{
	RemoteCamera=C;
	SetCamOverlay(Overlay);
}
void AHumanController::SetCamOverlay(UTexture2D* Overlay)
{
	HUDCamOverlay = Overlay;
}
void AHumanController::ServerAbortViewCam()
{
}
void AHumanController::DisplayLevelLoading()
{
	UE_LOG(LogTemp, Warning, TEXT("HC::DisplayLevelLoading() called"));
	/*
		ClientOpenMenu("AGP_Interface.AAServerLoading",,"","");
		LockPlayer(true,true);

	*/
}

void AHumanController::ClientTriggerCommandPost()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ShowAdminCommandPost();
	}
}

void AHumanController::AdminForceClassAllPlayers(FString WhichClass)
{
	/*
		local Controller ctrlIterator;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			ClientMessage("Force-classing players on a coop server disables scoring for the round.");
			GameReplicationInfo.bTempDisableRoundScoring=True;
		}
		if (! GameReplicationInfo.bAllowForceclassing)
		{
			ClientMessage("doing this will reduce honor scoring to 75% of normal.");
			ClientMessage("in order to perform a global force class.  Note that on official ");
			ClientMessage("You must enable global forceclassing using ""admin ToggleForceclass""");
			return;
		}
		ctrlIterator=Level.ControllerList;
		if (ctrlIterator != nullptr)
		{
			if (ctrlIterator.IsA('HumanController'))
			{
				if (! AdminForceClass(HumanController(ctrlIterator).PlayerReplicationInfo.PlayerName,WhichClass))
				{
				}
			}
			else
			{
				ctrlIterator=ctrlIterator.nextController;
			}
		}
	*/
}
void AHumanController::AdminForceClass(FString Who, FString WhichClass)
{
	/*
		local PlayerController PCToChangeClassOf;
		local Controller C;
		local PlayerController PC;
		local HumanController HC;
		local string str;
		local string sclass_name;
		local class<SoldierClass>  sclass;
		UE_LOG(LogTemp, Warning, TEXT("HumanController::AdminForceClass Attempting to force the class of " $ Who $ " to " $ WhichClass));
		C=Level.ControllerList;
		if (C != nullptr)
		{
			PC=PlayerController(C);
			if (PC != nullptr && PC.PlayerReplicationInfo.PlayerName ~= Who)
			{
				PCToChangeClassOf=PC;
				UE_LOG(LogTemp, Warning, TEXT("HumanController::AdminForceclass Attempting to change class of " $ PC.PlayerReplicationInfo.PlayerName));
			}
			else
			{
				C=C.nextController;
			}
		}
		if (HumanController(PCToChangeClassOf)._FlashSoundTime > 0)
		{
			ClientMessage("Player " $ Who $ " cannot be forceclassed while flashbanged.");
			return true;
		}
		if (PCToChangeClassOf != nullptr && PCToChangeClassOf.Pawn != nullptr)
		{
			HC=HumanController(PCToChangeClassOf);
			if (HC == nullptr)
			{
				ClientMessage("Error: admin forceclass cannot change the class of a non-human player.");
				UE_LOG(LogTemp, Warning, TEXT("Admin::Forceclass Error! Attempting to change the class of non-human PlayerController!"));
				return false;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Admin::Forceclass Changing class of " $ HC $ " to '" $ WhichClass $ "'"));
			}
			if (HC.Pawn != nullptr && HC.Pawn.Weapon != nullptr && HC.Pawn.Weapon.IsZoomed())
			{
				ClientMessage("Unable to forceclass player with weapon zoomed.");
				HC.ClientMessage("Administrator tried to forceclass you but your weapon is zoomed.");
				return true;
			}
			if (HC.Pawn != nullptr && HC.Pawn.Weapon != nullptr && HC.Pawn.Weapon.IsA('Item_Parachute'))
			{
				ClientMessage("Unable to forceclass player wearing a parachute.");
				HC.ClientMessage("Administrator tried to forceclass you but still have a parachute on.");
				return true;
			}
			str="Changing class of player '" $ HC.PlayerReplicationInfo.PlayerName $ "' to '" $ WhichClass $ "'";
			ClientMessage(str);
			HC.ClientForceNewClass(WhichClass);
			if (HC.Pawn != nullptr)
			{
				HC.LockPlayer(False,False);
				Switch(WhichClass)
				{
					case "":
					ScreenPrint("Type ""Class X"" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, RPG9");
					return false;
					case "M":
					case "M4A1":
					sclass_name="AGP_Characters.ClassRiflemanM4A1AutoIron";
					break;
					case "MA":
					case "M4A1Auto":
					sclass_name="AGP_Characters.ClassRiflemanM4A1Auto";
					break;
					case "AR":
					case "AutomaticRifleman":
					sclass_name="AGP_Characters.ClassAutomaticRifleman";
					break;
					case "R":
					case "Rifleman":
					sclass_name="AGP_Characters.ClassRifleman";
					break;
					case "RCT":
					case "Recruit":
					sclass_name="AGP_Characters.ClassRecruit";
					break;
					case "AK":
					case "RiflemanAK":
					sclass_name="AGP_Characters.ClassRiflemanAK";
					break;
					case "AK74SU":
					sclass_name="AGP_Characters.ClassRiflemanAK74SU";
					break;
					case "AK74suReflex":
					sclass_name="AGP_Characters.ClassGuerrillaAK74suReflex";
					break;
					case "RPK":
					sclass_name="AGP_Characters.ClassAutomaticRiflemanRPK";
					break;
					case "M4M":
					sclass_name="AGP_Characters.ClassRiflemanM4A1Mod";
					break;
					case "G":
					case "Grenadier":
					sclass_name="AGP_Characters.ClassGrenadier";
					break;
					case "GP":
					sclass_name="AGP_Characters.ClassGrenadierGP30_Op";
					break;
					case "Mos":
					if (GetNoSniper())
					{
						sclass_name="AGP_Characters.ClassRifleman";
					}
					else
					{
						sclass_name="AGP_Characters.ClassSniperMos";
					}
					case "S":
					case "S82":
					case "Sniper":
					case "Sniper82":
					if (GetNoSniper())
					{
						sclass_name="AGP_Characters.ClassRifleman";
					}
					else
					{
						sclass_name="AGP_Characters.ClassSniper";
					}
					case "S24":
					case "Sniper24":
					if (GetNoSniper())
					{
						sclass_name="AGP_Characters.ClassRifleman";
					}
					else
					{
						sclass_name="AGP_Characters.ClassSniper24_US";
					}
					case "SVD":
					if (GetNoSniper())
					{
						sclass_name="AGP_Characters.ClassRifleman";
					}
					else
					{
						sclass_name="AGP_Characters.ClassSniperSVD";
					}
					case "RPG":
					sclass_name="AGP_Characters.ClassRPG";
					case "AT4":
					sclass_name="AGP_Characters.ClassAT4Rocket";
					case "BDM":
					sclass_name="AGP_Characters.ClassBDMRocket";
					case "M9":
					sclass_name="AGP_Characters.ClassPistol";
					case "SF":
					sclass_name="AGP_Characters.ClassSF";
					case "SFSniper":
					case "SPR":
					if (GetNoSniper())
					{
						sclass_name="AGP_Characters.ClassRifleman";
					}
					else
					{
						sclass_name="AGP_Characters.ClassSFSniper";
					}
					case "PSO":
					case "GuerrillaPSO":
					sclass_name="AGP_Characters.ClassGuerrillaPSO";
					case "V":
					case "VSS":
					case "GuerrillaSniper":
					if (GetNoSniper())
					{
						sclass_name="AGP_Characters.ClassRifleman";
					}
					else
					{
						sclass_name="AGP_Characters.ClassGuerrillaSniper";
					}
					case "GuerrillaAK47su":
					sclass_name="AGP_Characters.ClassGuerrillaAK47su";
					case "GuerrillaRPG":
					sclass_name="AGP_Characters.ClassGuerrillaRPG";
					case "GuerrillaRPK":
					sclass_name="AGP_Characters.ClassGuerrillaRPK";
					case "D":
					sclass_name="AGP_Characters.ClassDemolitions";
					case "J":
					if (! PlayerReplicationInfo.bQualifiedJavelin)
					{
						sclass_name="AGP_Characters.ClassJavelinTube";
					}
					else
					{
						sclass_name="AGP_Characters.ClassJavelin";
					}
					case "JT":
					sclass_name="AGP_Characters.ClassJavelinTube";
					case "RPG9":
					sclass_name="AGP_Characters.ClassGuerrillaRPGNine";
					default:
					ScreenPrint("Unrecognized class " $ WhichClass);
					ScreenPrint("Type ""Class X"" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, J, RPG9");
					return false;
				}
				HC.CleanUp();
				AGP_Pawn(HC.Pawn).bForcedWeaponChange=True;
				sclass=class<SoldierClass>(DynamicLoadObject(sclass_name,Class'Class'));
				HC.newTeamClass(sclass);
				if (Pawn.Weapon != nullptr && Pawn.Weapon.IsA('Item_Parachute'))
				{
					Cast<AAGP_Pawn>(GetPawn()).UpdateParachute(4);
				}
				if (HC == this)
				{
					Level.Game.Broadcast(Level.Game,HC.UserName $ " has forceclassed his own weapon class to " $ WhichClass);
				}
			}
			HC.ClientMessage("Due to server rules, scoring is reduced when force classing is enabled.");
			HC.ClientMessage("Your class choice has been overruled by the Administrator.  ");
		}
		return true;
	*/
}
void AHumanController::ServerAdminCommand(FString Cmd, FString Arg0AsPlayerName, FString Arguments)
{
	/*
		local string Args;
		local int NumArgs;
		local int iPos;
		local string CommandLine;
		local string str;
		local Controller C;
		local PlayerController PC;
		local HumanController HC;
		local bool bMuteAll;
		local bool bEnabled;
		local int NumTourneyCaptains;
		NumArgs=0;
		NumTourneyCaptains=0;
		CommandLine=Arguments;
		Args[0]="";
		Args[1]="";
		Args[2]="";
		Args[3]="";
		Args[4]="";
		Args[5]="";
		Args[6]="";
		Args[7]="";
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this,"CHEATER");
			return;
		}
		if (PlayerReplicationInfo.bAdmin)
		{
			iPos=InStr(CommandLine," ");
			if (iPos > 0)
			{
				Args[NumArgs]=Left(CommandLine,iPos);
				NumArgs += 1;
				CommandLine=Right(CommandLine,Len(CommandLine) - iPos - 1);
			}
			else
			{
				Args[NumArgs]=CommandLine;
				NumArgs += 1;
				CommandLine="";
			}
			if (iPos <= 0 || NumArgs >= 8)
			{
				if (Cmd ~= "RestartMap")
				{
					Level.ServerTravel("?restart",False);
				}
				else
				{
					if (Cmd ~= "CommandPost")
					{
						ClientTriggerCommandPost();
					}
					else
					{
						if (Cmd ~= "Kick")
						{
							if (Args[0] == "" || Args[0] == "?")
							{
								ClientMessage("");
								ClientMessage("You can get the player names or number using ""PlayerList"".");
								ClientMessage("Usage: admin Kick <player name or number>");
							}
							else
							{
								if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
								{
									Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Player: """ $ Arg0AsPlayerName $ """",'AdminKick');
								}
								Level.Game.Kick(Arg0AsPlayerName,"Admin");
								ClientMessage("Player '" $ Arg0AsPlayerName $ "' has been kicked.");
							}
						}
						else
						{
							if (Cmd ~= "ToggleForceclass")
							{
								GameReplicationInfo.bAllowForceclassing=! GameReplicationInfo.bAllowForceclassing;
								if (GameReplicationInfo.bAllowForceclassing)
								{
									GameReplicationInfo.bForceClassUsedInRound=True;
								}
								GameReplicationInfo.SaveConfig();
								C=Level.ControllerList;
								if (C != nullptr)
								{
									if (HumanController(C) != nullptr)
									{
										HumanController(C).ClientUpdateForceclassing(GameReplicationInfo.bAllowForceclassing,True);
									}
									C=C.nextController;
								}
								if (GameReplicationInfo.bAllowForceclassing)
								{
									ClientMessage("is now enabled (and honor scoring reduced to 75% of standard).");
									ClientMessage("Global force classing (""admin forceclass * <class>"")");
								}
								else
								{
									ClientMessage("Global force classing is now disabled and honor will be at 100% for the next round.");
								}
							}
							else
							{
								if (Cmd ~= "KickBan")
								{
									if (Args[0] == "" || Args[0] == "?")
									{
										ClientMessage("");
										ClientMessage("Note that admins and player admins cannot be banned.");
										ClientMessage("To unban a player use 'admin unban <banlist index>'");
										ClientMessage("To view banned players use 'admin BanList'");
										ClientMessage("");
										ClientMessage("Which will ban 'SomePlayer' for one day by name and IP address and kick the player from the server.");
										ClientMessage("Example: admin kickban SomePlayer 1d IP");
										ClientMessage("Usage: admin kickban <playername> [<time[w|d|h|m]> [NAME | IP | MAC | PBGUID]]");
									}
									else
									{
										if (Level.Game.KickBan(this,Arg0AsPlayerName,Args[1],Args[2]))
										{
											ClientMessage("Player '" $ Arg0AsPlayerName $ "' has been kicked & banned.");
										}
										else
										{
											ClientMessage("Unable to kick & ban player '" $ Arg0AsPlayerName $ "'.");
										}
									}
								}
								else
								{
									if (Cmd ~= "Mute")
									{
										if (Args[0] == "" || Args[0] == "?")
										{
											ClientMessage("Player names can be found using the ""PlayerList"" command.");
											ClientMessage("Usage: admin mute <all | playername>");
											return;
										}
										if (Args[0] ~= "all")
										{
											bMuteAll=True;
										}
										else
										{
											bMuteAll=False;
										}
										if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
										{
											Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Options: """ $ Arguments $ """",'AdminMute');
										}
										C=Level.ControllerList;
										if (C != nullptr)
										{
											PC=PlayerController(C);
											if (PC != nullptr)
											{
												if (bMuteAll == false && PC.PlayerReplicationInfo.PlayerName != Arg0AsPlayerName)
												{
												}
												if (PC.PlayerReplicationInfo.SuperUser() || PC.PlayerReplicationInfo.bAdmin)
												{
												}
												Level.Game.ToggleMutedPlayer(PC.PlayerReplicationInfo.PlayerName);
												str="Mute toggled for player '" $ PC.PlayerReplicationInfo.PlayerName $ "'";
												PC.ClientMessage(str);
												ClientMessage(str);
											}
											C=C.nextController;
										}
									}
									else
									{
										if (Cmd ~= "Say")
										{
											if (Args[0] == "")
											{
												ClientMessage("");
												ClientMessage("Usage: admin say <text>");
												return;
											}
											ServerSay(Arguments,'AdminSay');
										}
										else
										{
											if (Cmd ~= "CSay")
											{
												if (Args[0] == "")
												{
													ClientMessage("");
													ClientMessage("Usage: admin csay <text>");
													return;
												}
												ServerSay(Arguments,'CommandChat');
											}
											else
											{
												if (Cmd ~= "Message")
												{
													if (Args[0] == "" || Args[0] == "?")
													{
														ClientMessage("");
														ClientMessage("You must enter some text to display in the popup window.");
														ClientMessage("Usage: admin message <text>");
														return;
													}
													if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.1)
													{
														Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,Arguments,'AdminMessage');
													}
													C=Level.ControllerList;
													if (C != nullptr)
													{
														HC=HumanController(C);
														if (HC != nullptr)
														{
															HC.NotifyAdminMessage(Arguments);
														}
														C=C.nextController;
													}
												}
												else
												{
													if (Cmd ~= "Switch" || Cmd ~= "A_Open" || Cmd ~= "A_Map")
													{
														if (Args[0] == "" || Args[0] == "?")
														{
															ClientMessage("");
															ClientMessage("Do not include the file name extension on the map name.");
															ClientMessage("Usage: admin switch <mapname>");
															return;
														}
														if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
														{
															Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Map: """ $ Args[0] $ """",'AdminSwitchMap');
														}
														Level.ServerTravel(Args[0],False);
													}
													else
													{
														if (Cmd ~= "AdminSet")
														{
															if (IsServerSetting(Args[0],Args[1],Args[2]))
															{
																UE_LOG(LogTemp, Warning, TEXT("Admin command: Arg0: " $ Args[0] $ " Arg1: " $ Args[1] $ " Arg2: " $ Args[2]));
																if (Args[0] ~= "AccessControl" && Args[1] ~= "AdminPassword")
																{
																	ClientMessage("That cannot be set using this command.");
																	return;
																}
																if (Args[0] ~= "AGP_GameMultiPlayer" || Args[0] ~= "AGP_GameTeamObjective" && Args[1] ~= "bRequireAuthorization" && Args[2] ~= "False" && ! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer())
																{
																	Log("User tried to disable authorization on non LAN server.");
																	ClientMessage("You cannot disable authorization for a global server.");
																	NotifyAdminMessage("You cannot disable authorization for a global server.");
																	return;
																}
																PrivateSet(Arguments);
															}
															else
															{
																ClientMessage("");
																ClientMessage("Usage: admin adminset <section> <setting> <value>");
																UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerAdminCommand()	Admin tried illegal or unknown AdminSet(" @ Arguments @ ")"));
															}
														}
														else
														{
															if (Cmd ~= "A_SwitchTeam")
															{
																if (Args[0] == "" || Args[0] == "?")
																{
																	ClientMessage("");
																	ClientMessage("Note that player will switch teams at the start of the next round depending on balance options.");
																	ClientMessage("Player names can be found using ""PlayerList"".");
																	ClientMessage("Usage: admin A_SwitchTeam <player name>");
																	return;
																}
																if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																{
																	Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Player """ $ Arg0AsPlayerName $ """",'AdminSwitchTeam');
																}
																C=Level.ControllerList;
																if (C != nullptr)
																{
																	PC=PlayerController(C);
																	if (PC != nullptr && PC.PlayerReplicationInfo.PlayerName ~= Arg0AsPlayerName)
																	{
																		PC.SwitchTeam();
																	}
																	else
																	{
																		C=C.nextController;
																	}
																}
															}
															else
															{
																if (Cmd ~= "Forceclass")
																{
																	if (NumArgs < 2)
																	{
																		ClientMessage("");
																		ClientMessage("Player names can be found using ""PlayerList"".");
																		ClientMessage("Usage: admin forceclass <playername> <class>");
																	}
																	else
																	{
																		if (Arg0AsPlayerName == "*")
																		{
																			if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																			{
																				Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Player: ""All"" Class: """ $ Args[1] $ """",'AdminForceClassAll');
																			}
																			AdminForceClassAllPlayers(Args[1]);
																		}
																		else
																		{
																			if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																			{
																				Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Player: """ $ Arg0AsPlayerName $ """  Class: """ $ Args[1] $ """",'AdminForceClassPlayer');
																			}
																			if (Level.Game.CheatsDisabled())
																			{
																				ClientMessage("You must enable cheats to forceclass a single player");
																			}
																			else
																			{
																				AdminForceClass(Arg0AsPlayerName,Args[1]);
																			}
																		}
																	}
																}
																else
																{
																	if (Cmd ~= "DeathMessages")
																	{
																		if (Args[0] ~= "on" || Args[0] ~= "true" || Args[0] ~= "1")
																		{
																			bEnabled=True;
																		}
																		else
																		{
																			bEnabled=False;
																		}
																		UE_LOG(LogTemp, Warning, TEXT("Setting DeathMessages to " $ bEnabled));
																		Level.Game.bDeathMessages=bEnabled;
																		Level.Game.SaveConfig();
																		if (Level.Game.bDeathMessages)
																		{
																			ClientMessage("Setting Death Messages to TRUE");
																		}
																		else
																		{
																			ClientMessage("Setting Death Messages to FALSE");
																		}
																	}
																	else
																	{
																		if (Cmd ~= "Score")
																		{
																			bEnabled=Level.Game.SetScoreMode(Args[0]);
																			if (bEnabled)
																			{
																				Level.Game.SaveConfig();
																				Switch(Level.Game.ScoreMode)
																				{
																					case 0:
																					ClientMessage("Setting score mode to SSM_On");
																					break;
																					case 1:
																					ClientMessage("Setting score mode to SSM_Off");
																					break;
																					case 2:
																					ClientMessage("Setting score mode to SSM_Round");
																					break;
																					case 3:
																					ClientMessage("Setting score mode to SSM_Match");
																					break;
																					default:
																				}
																			}
																			else
																			{
																				ClientMessage("Usage: admin score (on | off | round | match)");
																			}
																		}
																		else
																		{
																			if (Cmd ~= "MOTD")
																			{
																				if (Args[0] ~= "this")
																				{
																					if (GameReplicationInfo.MOTDLine1 != "")
																					{
																						ClientMessage("Message of the day: " $ GameReplicationInfo.MOTDLine1);
																					}
																				}
																				else
																				{
																					if (Args[0] ~= "all")
																					{
																						if (GameReplicationInfo.MOTDLine1 != "")
																						{
																							Level.Game.Broadcast(this,"Message of the day: " $ GameReplicationInfo.MOTDLine1);
																						}
																					}
																					else
																					{
																						GameReplicationInfo.MOTDLine1=ApplyFilters(Arguments);
																						ClientMessage("Changing Message Of The Day To: " $ GameReplicationInfo.MOTDLine1);
																						GameReplicationInfo.SaveConfig();
																					}
																				}
																			}
																			else
																			{
																				if (Cmd ~= "ROEKickTimer")
																				{
																					if (Args[0] ~= "true" || Args[0] ~= "1" || Args[0] ~= "on")
																					{
																						Level.Game.SetROEKickTimer(True);
																						ClientMessage("ROE Kick-Timer enabled.");
																					}
																					else
																					{
																						if (Args[0] ~= "false" || Args[0] ~= "0" || Args[0] ~= "off")
																						{
																							Level.Game.SetROEKickTimer(False);
																							ClientMessage("ROE Kick-Timer disabled.");
																						}
																					}
																				}
																				else
																				{
																					if (Cmd ~= "ROEKick")
																					{
																						if (Args[0] ~= "true" || Args[0] ~= "1" || Args[0] ~= "on")
																						{
																							Level.Game.SetROEKick(True);
																							ClientMessage("ROE Kick enabled.");
																						}
																						else
																						{
																							if (Args[0] ~= "false" || Args[0] ~= "0" || Args[0] ~= "off")
																							{
																								Level.Game.SetROEKick(False);
																								ClientMessage("ROE Kick disabled.");
																							}
																						}
																					}
																					else
																					{
																						if (Cmd ~= "ROEKickDead")
																						{
																							if (Args[0] ~= "true" || Args[0] ~= "1" || Args[0] ~= "on")
																							{
																								Level.Game.SetROEKickDead(True);
																								ClientMessage("ROE violations will be punished with death.");
																							}
																							else
																							{
																								if (Args[0] ~= "false" || Args[0] ~= "0" || Args[0] ~= "off")
																								{
																									Level.Game.SetROEKickDead(False);
																									ClientMessage("ROE violations will be punished with kick.");
																								}
																							}
																						}
																						else
																						{
																							if (Cmd ~= "roundsuspend")
																							{
																								if (Args[0] ~= "true" || Args[0] ~= "1" || Args[0] ~= "on")
																								{
																									if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																									{
																										Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"",'AdminSuspendRound');
																									}
																									Level.Game.GameReplicationInfo.SuspendRound(True);
																								}
																								else
																								{
																									if (Args[0] ~= "false" || Args[0] ~= "0" || Args[0] ~= "off")
																									{
																										if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																										{
																											Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"",'AdminResumeRound');
																										}
																										Level.Game.GameReplicationInfo.SuspendRound(False);
																									}
																								}
																							}
																							else
																							{
																								if (Cmd ~= "roundreset")
																								{
																									UE_LOG(LogTemp, Warning, TEXT("roundreset entered for admin"));
																									ClientMessage("Initating round reset");
																									Level.Game.GameReplicationInfo.bRoundIsSuspended=False;
																									Level.Game.GameReplicationInfo.SecsTillRoundResume=0;
																									Level.Game.GameReplicationInfo.RemainingMinute=Level.Game.TimeLimit * 60;
																									Level.Game.GameReplicationInfo.bStopCountDown=True;
																									C=Level.ControllerList;
																									if (C != nullptr)
																									{
																										PC=PlayerController(C);
																										if (PC != nullptr)
																										{
																											PC.ClientMessage("An admin is resetting the round...please wait...");
																											PC.ClientSetTimeRemaining(Level.Game.TimeLimit * 60);
																										}
																										C=C.nextController;
																									}
																									Level.Game.EndGame(None,"Admin Round Reset");
																								}
																								else
																								{
																									if (Cmd ~= "ban")
																									{
																										if (Args[0] == "" || Args[1] == "")
																										{
																											ClientMessage("");
																											ClientMessage("To unban a player use 'admin unban <banlist index>'");
																											ClientMessage("To view banned players use 'admin BanList'");
																											ClientMessage("");
																											ClientMessage("Which will ban 'SomePlayer' for one day by name and IP address.");
																											ClientMessage("Example: admin ban SomePlayer 1d IP");
																											ClientMessage("Usage: admin ban  <playername> <time[w|d|h|m]> <[NAME | IP | MAC | PBGUID]>");
																										}
																										else
																										{
																											Level.Game.Ban(this,Arg0AsPlayerName,Args[1],Args[2]);
																										}
																									}
																									else
																									{
																										if (Cmd ~= "banlist")
																										{
																											if (Len(Args[0]) > 0)
																											{
																												Level.Game.AccessControl.DisplayBanList(this,Args[0]);
																											}
																											else
																											{
																												Level.Game.AccessControl.DisplayBanList(this,0);
																											}
																										}
																										else
																										{
																											if (Cmd ~= "unban")
																											{
																												if (Args[0] == "")
																												{
																													ClientMessage("");
																													ClientMessage("Use 'admin banlist' for list of entries to pick from");
																													ClientMessage("Usage: admin unban <ban_index>");
																												}
																												else
																												{
																													Level.Game.AccessControl.Unban(this,Args[0]);
																												}
																											}
																											else
																											{
																												if (Cmd ~= "Spectate")
																												{
																													if (Args[0] == "" || Args[0] == "?")
																													{
																														ClientMessage("");
																														ClientMessage("Player names can be found using the ""PlayerList"" command.");
																														ClientMessage("Usage: admin spectate <player name>");
																														return;
																													}
																													AdminSpectate(Arg0AsPlayerName);
																												}
																												else
																												{
																													if (Left(Cmd,3) ~= "pb_")
																													{
																														if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																														{
																															Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo,"Command: """ $ Cmd @ Arguments $ """",'AdminPunkBuster');
																														}
																														ConsoleCommand(Cmd @ Arguments);
																														if (Cmd ~= "pb_sv_disable")
																														{
																															ClientMessage("");
																															ClientMessage("You can turn PunkBuster back on with 'admin pb_sv_enable'.");
																															ClientMessage("You will need to stop and restart the server to disable PunkBuster.");
																														}
																													}
																													else
																													{
																														ClientMessage("Unknown admin command: " $ Cmd);
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	*/
}

void AHumanController::AdminSpectate(FString argument)
{
	/*
		local Controller C;
		local Pawn p;
		local bool bFound;
		local string PlayerName;
		local int Team;
		local Controller first;
		local Controller Current;
		local bool bUseNext;
		if (Pawn != nullptr && Pawn.Health > 0 && ! PlayerReplicationInfo.bOnlySpectator)
		{
			ClientMessage("You cannot spectate other players while you are playing.");
			return;
		}
		Team=-1;
		if (TournamentIsTournament())
		{
			if (argument == "team0" || argument == GameReplicationInfo.asTournamentTeamName[0])
			{
				Team=0;
			}
			else
			{
				if (argument == "team1" || argument == GameReplicationInfo.asTournamentTeamName[1])
				{
					Team=1;
				}
				else
				{
					if (argument == "all" || argument == "")
					{
						Team=-1;
					}
					else
					{
						PlayerName=argument;
					}
				}
			}
		}
		else
		{
			if (argument == "team0" || argument == Level.TeamName[0])
			{
				Team=0;
			}
			else
			{
				if (argument == "team1" || argument == Level.TeamName[1])
				{
					Team=1;
				}
				else
				{
					if (argument == "all" || argument == "")
					{
						Team=-1;
					}
					else
					{
						PlayerName=argument;
					}
				}
			}
		}
		if (PlayerName != "")
		{
			C=Level.ControllerList;
			if (C != nullptr)
			{
				if (PlayerName ~= C.PlayerReplicationInfo.GetHumanReadableName())
				{
					bFound=True;
					if (C.Pawn == nullptr)
					{
						ClientMessage("Player(" $ PlayerName $ ") is not currently active");
					}
					else
					{
						else
						{
							if (C.Pawn.Health <= 0)
							{
								ClientMessage("Player(" $ PlayerName $ ") is not currently alive and cannot be viewed");
								return;
							}
							p=C.Pawn;
						}
					}
					C=C.nextController;
				}
			}
			if (! bFound)
			{
				ClientMessage("Player(" $ PlayerName $ ") not found!");
			}
		}
		if (p == nullptr)
		{
			Current=Controller(ViewTargetActor);
			if (Current != nullptr)
			{
				if (Team != Current.PlayerReplicationInfo.Team.TeamIndex)
				{
					Current=None;
				}
			}
			if (Current == nullptr)
			{
				bUseNext=True;
			}
			C=Level.ControllerList;
			if (C != nullptr)
			{
				if (C.Pawn != nullptr && Team == -1 || Team == C.PlayerReplicationInfo.Team.TeamIndex)
				{
					if (bUseNext)
					{
						p=C.Pawn;
					}
					else
					{
						if (first == nullptr)
						{
							first=C;
						}
						if (C == Current)
						{
							bUseNext=True;
						}
					}
					C=C.nextController;
				}
			}
			if (p == nullptr && first != nullptr)
			{
				p=first.Pawn;
			}
		}
		if (p != nullptr)
		{
			SetViewTarget(p);
			ClientSetViewTarget2(p);
		}
		else
		{
			if (Team == -1)
			{
				ClientMessage("No active players to spectate");
			}
			else
			{
				ClientMessage("No active players on team '" @ Team @ "' to spectate");
			}
		}
	*/
}
void AHumanController::IsServerSetting(FString Section, FString Setting, FString Value)
{
	/*
		local int i;
		local int Len;
		if (Section ~= "" || Setting ~= "")
		{
			return false;
		}
		Len=Min(Level.Game.Section.Length,Level.Game.Setting.Length);
		for (i=0; i<Len; i++)
		{
			if (Section ~= Level.Game.Section[i] && Setting ~= Level.Game.Setting[i])
			{
				return true;
			}
		}
		return false;
	*/
}
void AHumanController::Admin(FString CommandLine)
{
	/*
		local string Cmd;
		local string Arg0;
		local int iPos;
		iPos=InStr(CommandLine," ");
		if (iPos <= 0)
		{
			Cmd=CommandLine;
			Arg0="";
			CommandLine="";
		}
		else
		{
			Cmd=Left(CommandLine,iPos);
			CommandLine=Right(CommandLine,Len(CommandLine) - iPos - 1);
			iPos=InStr(CommandLine," ");
			if (iPos <= 0)
			{
				Arg0=CommandLine;
			}
			else
			{
				Arg0=Left(CommandLine,iPos);
			}
		}
		if (Cmd ~= "CommandPost")
		{
			Player.Console.ConsoleClose();
		}
		ServerAdminCommand(Cmd,MaybeGetPlayerNameFromID(Arg0),CommandLine);
	*/
}
void AHumanController::GetAuthUserName()
{
	/*
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			return PlayerReplicationInfo.PlayerName;
		}
		Log(this $ ".GetAuthUserName() - User Name: """ $ UserName $ """, saved: """ $ sSavedUserName $ """");
		if (Len(UserName) == 0 || UserName ~= "UserName")
		{
			UserName=sSavedUserName;
		}
		return UserName;
	*/
}
bool AHumanController::TournamentIsTournament()
{
	bool bResult;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		bResult=bTournamentServer;
	}
	else
	{
		//bResult=Level.Game.TournamentIsTournament();
		bResult = false; // temp set until above row works
	}
	return bResult;
}
void AHumanController::TournamentGetTeamPasswordFor(int32 iTeamIndex)
{
	/*
		if (iTeamIndex == 0 || iTeamIndex == 1)
		{
			return Level.Game.AccessControl.asTeamPasswords[iTeamIndex];
		}
		return "";
	*/
}
void AHumanController::TournamentJoinTeam(int32 iTeamIndex, FString sPassword)
{
	/*
		if (PlayerReplicationInfo.bOnlySpectator && GameReplicationInfo.sTournamentState != "Setup")
		{
			ClientCloseMenu(True);
			NotifyAdminMessage("After Setup, Spectators can not join a team without reconnecting.");
			return;
		}
		if (GameReplicationInfo.sTournamentState == "Complete")
		{
			ClientCloseMenu(True);
			TournamentCaptainAdminMessage("All players must leave the server to allow it to reset the tournament before you can join a team.");
			return;
		}
		PlayerReplicationInfo.DesiredTeam=iTeamIndex;
		TournamentServerJoinTeam(iTeamIndex,sPassword);
	*/
}
void AHumanController::TournamentServerJoinTeam(int32 iTeamIndex, FString sPassword)
{
	/*
		local bool bResult;
		if (Level.Game.TournamentGetTeam(iTeamIndex).Size > Level.Game.TournamentGetMaxTeamSize())
		{
			return;
		}
		if (PlayerReplicationInfo.bOnlySpectator)
		{
			PlayerReplicationInfo.bOnlySpectator=False;
			if (Level.Game.NumSpectators > 1)
			{
				Level.Game.NumSpectators --;
			}
		}
		bResult=Level.Game.TournamentJoinTeam(this,iTeamIndex,sPassword);
		TournamentNotifyPlayerJoinedTeam(iTeamIndex,bResult);
	*/
}
void AHumanController::TournamentNotifyPlayerJoinedTeam(int32 iTeamIndex, bool bResult, bool bAdminAssigned)
{
	/*
		if (! bResult)
		{
			ClientMessage("Bad team password");
			ClientOpenMenu("AGP_Interface.AAGenericMessageBox",,"Invalid Password","This team requires a password to join. Please enter a valid password.");
		}
		else
		{
			if (bAdminAssigned)
			{
				TournamentCaptainAdminMessage("The administrator assigned you to team " $ GameReplicationInfo.asTournamentTeamName[iTeamIndex]);
			}
			else
			{
				ClientMessage("Joined team " $ GameReplicationInfo.asTournamentTeamName[iTeamIndex]);
			}
			SelectClass();
		}

	*/
}
void AHumanController::TournamentJoinSpectatorTeam(int32 iTeamIndex)
{
	//TournamentServerJoinSpectatorTeam(iTeamIndex);
}
void AHumanController::TournamentServerJoinSpectatorTeam(int32 iTeamIndex)
{
	/*
		local bool bResult;
		if (Level.Game.MaxSpectators == 0)
		{
			TournamentNotifyPlayerJoinedSpectatorTeam(iTeamIndex,False,"Spectators are not allowed.");
			return;
		}
		if (Level.Game.NumSpectators >= Level.Game.MaxSpectators)
		{
			TournamentNotifyPlayerJoinedSpectatorTeam(iTeamIndex,False,"All spectating slots are filled.");
			return;
		}
		Level.Game.NumSpectators ++;
		Level.Game.NumPlayers --;
		PlayerReplicationInfo.bOnlySpectator=True;
		bResult=Level.Game.TournamentJoinSpectatorTeam(this,iTeamIndex);
		TournamentNotifyPlayerJoinedSpectatorTeam(iTeamIndex,bResult,"");
	*/
}
void AHumanController::TournamentNotifyPlayerJoinedSpectatorTeam(int32 iTeamIndex, bool bResult, FString sReason)
{
	/*
		if (! bResult)
		{
			NotifyAdminMessage(sReason);
		}
		else
		{
			PlayerReplicationInfo.bOnlySpectator=True;
			ClientMessage("Joined spectators.");
		}
	*/
}
void AHumanController::TournamentAssignClass(FString sPlayerName, int32 iUnitID, int32 iSlot)
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		local bool bGoodAssignment;
		bGoodAssignment=False;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (PC.PlayerReplicationInfo.PlayerName ~= sPlayerName || PC.PlayerReplicationInfo.PlayerID == sPlayerName)
			{
				if (PC.PlayerReplicationInfo.Team.TeamIndex == 255)
				{
					ClientMessage("Spectators cannot be assigned to squad positions.");
					return false;
				}
				PC.PlayerReplicationInfo.SubmitPlayerRequest(iUnitID,iSlot);
				return true;
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		return false;
	*/
}
void AHumanController::TournamentRemoveClass(FString sPlayerName, int32 iUnitID, int32 iSlot)
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		local bool bGoodAssignment;
		bGoodAssignment=False;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (PC.PlayerReplicationInfo.PlayerName ~= sPlayerName || PC.PlayerReplicationInfo.PlayerID == sPlayerName)
			{
				if (PC.PlayerReplicationInfo.Team.TeamIndex == 255)
				{
					ClientMessage("Spectators are not part of squads.");
					return false;
				}
				PC.PlayerReplicationInfo.RemovePlayerRequest(PC.PlayerReplicationInfo);
				return true;
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		return false;
	*/
}
void AHumanController::NotifyTournamentTeamNameUpdated(int32 iTeamIndex, FString sTeamName)
{
	
	if (iTeamIndex > 1 || iTeamIndex < 0)
	{
		return;
	}
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->asTournamentTeamName[iTeamIndex] = sTeamName;
	
}
void AHumanController::TournamentSetTeamName(int32 iTeam, FString sTeamName)
{
	/*
		int32 iOtherTeamIndex;
		if (iTeam > 1 || iTeam < 0)
		{
			return;
		}
		//if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		//{
		//	NotifyAdminMessage("Only Team Captains or Administrators can set team names.");
		//	return;
		//}
		if (Len(sTeamName) == 0)
		{
			NotifyAdminMessage("Your team name must be at least one character long.");
			return;
		}
		if (iTeam == 0)
		{
			iOtherTeamIndex=1;
		}
		else
		{
			iOtherTeamIndex=0;
		}
		if (sTeamName ~= GameReplicationInfo.asTournamentTeamName[iOtherTeamIndex])
		{
			NotifyAdminMessage("That team name has already been chosen.");
			return;
		}
		Level.Game.GameReplicationInfo.SetTournamentTeamName(iTeam,sTeamName);
		Level.Game.TournamentSetTeamName(iTeam,sTeamName);
		Level.Game.SaveConfig();
		TournamentNotifyNewTeamName();
	*/
}
void AHumanController::TournamentServerSetTeamName(int32 iTeam, FString sTeamName)
{
	//Level.Game.TournamentSetTeamName(iTeam, sTeamName);
	//TournamentNotifyNewTeamName();
}
void AHumanController::TournamentNotifyNewTeamName()
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyNewTeamName();
	}
}
void AHumanController::NotifyTeamCaptainRequestStatus(bool bTeamCaptain)
{
}
void AHumanController::TournamentNotifyNewTeamCaptain()
{
	if (MyHUD != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyNewTeamCaptain();
	}
}
bool AHumanController::TournamentAreAllWeaponClassesAvailable()
{
	return Cast<AAA2_GameState>(GetWorld()->GetGameState())->bTournamentOpenAllWeaponClassSlots;
}
void AHumanController::TournamentCaptainLockWeaponClasses(bool fLock)
{
	/*
		local Controller ctrlrScan;
		local string sResponse;
		if (PlayerReplicationInfo.bAdmin)
		{
			GameReplicationInfo.Teams[0].bTournamentTeamRosterLocked=fLock;
			GameReplicationInfo.Teams[1].bTournamentTeamRosterLocked=fLock;
		}
		else
		{
			GameReplicationInfo.Teams[PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=fLock;
			if (GameReplicationInfo.Teams[PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked)
			{
				sResponse="Roster locked for " $ GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex];
			}
			else
			{
				sResponse="Roster no longer locked for " $ GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex];
			}
			ctrlrScan=Level.ControllerList;
			if (ctrlrScan != nullptr)
			{
				if (ctrlrScan.IsA('HumanController'))
				{
					HumanController(ctrlrScan).TeamMessage(None,sResponse,'TMStatus');
					if (ctrlrScan.PlayerReplicationInfo.Team.TeamIndex == PlayerReplicationInfo.Team.TeamIndex)
					{
						if (HumanController(ctrlrScan).MyHUD != nullptr && AGP_HUD(HumanController(ctrlrScan).MyHUD) != nullptr)
						{
							AGP_HUD(HumanController(ctrlrScan).MyHUD).TournamentNotifyNewWeaponClassLockState();
						}
					}
				}
				ctrlrScan=ctrlrScan.nextController;
			}
		}

	*/
}
void AHumanController::TournamentNotifyNewWeaponClassLockState()
{
	if (MyHUD != nullptr && Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyNewWeaponClassLockState();
	}
}
void AHumanController::TournamentTeamReady(bool bReady)
{
	/*
		local Controller ctrlrScan;
		if (! PlayerReplicationInfo.Administrator() && ! PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			if (PlayerReplicationInfo.Team.bTournamentTeamReady)
			{
				PlayerReplicationInfo.Team.bTournamentTeamReady=False;
			}
			ClientMessage("You are not " $ GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex] $ "'s Team Captain and cannot make your roster ready.");
			return;
		}
		if (PlayerReplicationInfo.Administrator())
		{
			Level.Game.TournamentTeamsReady();
			ServerSay("The administrator has made both rosters ready.",'AdminSay');
			return;
		}
		if (PlayerReplicationInfo.Team.bTournamentTeamReady)
		{
			PlayerReplicationInfo.Team.bTournamentTeamReady=False;
			Say("Team " $ GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex] $ " no longer ready.");
		}
		else
		{
			if (! PlayerReplicationInfo.Administrator() && PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				PlayerReplicationInfo.Team.bTournamentTeamReady=True;
				TournamentNotifyMyTeamReady();
				ClientCloseMenu(True);
				Say("Team " $ GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex] $ " ready.");
			}
		}
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			if (ctrlrScan.PlayerReplicationInfo.Team.TeamIndex != PlayerReplicationInfo.Team.TeamIndex && ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				if (ctrlrScan.PlayerReplicationInfo.Team.bTournamentTeamReady)
				{
					if (! PlayerReplicationInfo.Team.bTournamentTeamReady)
					{
						HumanController(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain is no longer ready.");
					}
					else
					{
						TeamMessage(None,"Both Team Captains have signalled they are ready.",'TMStatus');
						Level.Game.TournamentTeamsReady();
					}
					return;
				}
				else
				{
					if (! PlayerReplicationInfo.Team.bTournamentTeamReady)
					{
						HumanController(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain is no longer ready.");
					}
					else
					{
						HumanController(ctrlrScan).TournamentNotifyOtherTeamReady();
						HumanController(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain is ready to continue.");
					}
				}
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		if (PlayerReplicationInfo.Team.bTournamentTeamReady)
		{
			ClientMessage("Your team is ready. Waiting for the other Team Captain to become ready.");
		}
		else
		{
			ClientMessage("Your team is no longer ready.");
		}
	*/
}
void AHumanController::TournamentNotifyMyTeamReady()
{
	/*
		if (MyHUD != nullptr && Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->TournamentNotifyMyTeamReady();
		}
	*/
}
void AHumanController::TournamentNotifyOtherTeamReady()
{
	/*
		if (MyHUD != nullptr && Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->TournamentNotifyOtherTeamReady();
		}

	*/
}
void AHumanController::TournamentAdminReady()
{
	/*
		if (PlayerReplicationInfo.Administrator())
		{
			Level.Game.TournamentTeamsReady();
			ServerSay(" The administrator is continuing the tournament.",'Center');
			return;
		}
	*/
}
void AHumanController::TournamentWarmupJustEnded()
{
	//return GameReplicationInfo.bTournamentWarmupJustEnded;
}
void AHumanController::TournamentIsPasswordRequired(int32 iTeamIndex)
{
	//return GameReplicationInfo.bTournamentWarmupJustEnded;
}
void AHumanController::TournamentAreCaptainsAllowed()
{
	//return GameReplicationInfo.bTournamentTeamCaptainsAllowed;
}
void AHumanController::TournamentAreTeamPasswordsRequired()
{
	//return GameReplicationInfo.bTournamentTeamPasswordsRequired;
}
void AHumanController::TournamentIsTeamCaptainSelected(int32 iTeamNum)
{
	/*
		if (iTeamNum != 255)
		{
			return GameReplicationInfo.Teams[iTeamNum].bTournamentTeamCaptainSelected;
		}
		return false;
	*/
}
void AHumanController::TournamentIsTeamRosterLocked(int32 iTeamNum)
{
	/*
		if (iTeamNum != 255)
		{
			return GameReplicationInfo.Teams[iTeamNum].bTournamentTeamRosterLocked;
		}
		return false;
	*/
}
void AHumanController::TournamentIsTeamReady(int32 iTeamNum)
{
	/*
		if (iTeamNum != 255)
		{
			return GameReplicationInfo.Teams[iTeamNum].bTournamentTeamReady;
		}
		return false;
	*/
}
void AHumanController::TournamentIsOtherTeamCaptainSelected()
{
	/*
		local int iOtherTeamIndex;
		iOtherTeamIndex=255;
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			if (PlayerReplicationInfo.Team.TeamIndex == 0)
			{
				iOtherTeamIndex=1;
			}
			else
			{
				iOtherTeamIndex=0;
			}
		}
		if (iOtherTeamIndex != 255)
		{
			return GameReplicationInfo.Teams[iOtherTeamIndex].bTournamentTeamCaptainSelected;
		}
		return false;
	*/
}
void AHumanController::TournamentIsOtherTeamRosterLocked()
{
	/*
		local int iOtherTeamIndex;
		iOtherTeamIndex=255;
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			if (PlayerReplicationInfo.Team.TeamIndex == 0)
			{
				iOtherTeamIndex=1;
			}
			else
			{
				iOtherTeamIndex=0;
			}
		}
		if (iOtherTeamIndex != 255)
		{
			return GameReplicationInfo.Teams[iOtherTeamIndex].bTournamentTeamRosterLocked;
		}
		return false;
	*/
}
void AHumanController::TournamentIsOtherTeamReady()
{
	/*
		local int iOtherTeamIndex;
		iOtherTeamIndex=255;
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			if (PlayerReplicationInfo.Team.TeamIndex == 0)
			{
				iOtherTeamIndex=1;
			}
			else
			{
				iOtherTeamIndex=0;
			}
		}
		if (iOtherTeamIndex != 255)
		{
			return GameReplicationInfo.Teams[iOtherTeamIndex].bTournamentTeamReady;
		}
		return false;
	*/
}
void AHumanController::TournamentIsMyTeamCaptainSelected()
{
	/*
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			return PlayerReplicationInfo.Team.bTournamentTeamCaptainSelected;
		}
		return false;
	*/
}
void AHumanController::TournamentIsMyTeamRosterLocked()
{
	/*
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			return PlayerReplicationInfo.Team.bTournamentTeamRosterLocked;
		}
		return false;
	*/
}
void AHumanController::TournamentIsMyTeamReady()
{
	/*
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			return PlayerReplicationInfo.Team.bTournamentTeamReady;
		}
		return false;
	*/
}
void AHumanController::GetTeamName(int32 iTeamNum)
{
	/*
		if (iTeamNum != 255)
		{
			if (TournamentIsTournament())
			{
				return GameReplicationInfo.asTournamentTeamName[iTeamNum];
			}
			else
			{
				return Level.TeamName[iTeamNum];
			}
		}
		return "";
	*/
}
void AHumanController::GetOtherTeamName()
{
	/*
		local int iOtherTeamIndex;
		iOtherTeamIndex=255;
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			if (PlayerReplicationInfo.Team.TeamIndex == 0)
			{
				iOtherTeamIndex=1;
			}
			else
			{
				iOtherTeamIndex=0;
			}
		}
		if (iOtherTeamIndex != 255)
		{
			if (TournamentIsTournament())
			{
				return GameReplicationInfo.asTournamentTeamName[iOtherTeamIndex];
			}
			else
			{
				return Level.TeamName[iOtherTeamIndex];
			}
		}
		return "";
	*/
}
void AHumanController::GetMyTeamName()
{
	/*
		if (PlayerReplicationInfo.Team.TeamIndex != 255)
		{
			if (TournamentIsTournament())
			{
				return GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo.Team.TeamIndex];
			}
			else
			{
				return Level.TeamName[PlayerReplicationInfo.Team.TeamIndex];
			}
		}
		return "";
	*/
}
void AHumanController::TournamentAreAllWeaponClassSlotsOpen()
{
	//return GameReplicationInfo.bTournamentOpenAllWeaponClassSlots;
}
void AHumanController::TournamentGetTournamentState()
{
	//return GameReplicationInfo.sTournamentState;
}
void AHumanController::TournamentRequestSwapSides()
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		local int iCaptainsRequestingCount;
		if (PlayerReplicationInfo.bAdmin)
		{
			UE_LOG(LogTemp, Warning, TEXT("Server - TournamentRequestSwapSides() entered"));
			if (! Level.Game.TournamentRequestSwapSides())
			{
				NotifyAdminMessage("Swapping is not allowed at this time.");
			}
			return;
		}
		if (PlayerReplicationInfo.bTournamentTeamSwapRequest && GetWorld()->GetTimeSeconds() < NextSwapAllowed)
		{
			ClientMessage("You have already requested to swap sides at the end of the round. If your swap request is not granted you can try again during the next round.");
			return;
		}
		PlayerReplicationInfo.bTournamentTeamSwapRequest=True;
		NextSwapAllowed=GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
		iCaptainsRequestingCount=1;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (PC.PlayerReplicationInfo.Team.TeamIndex != PlayerReplicationInfo.Team.TeamIndex && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				if (PC.PlayerReplicationInfo.bTournamentTeamSwapRequest)
				{
					iCaptainsRequestingCount ++;
				}
				else
				{
					HumanController(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested to swap sides at the end of the round.");
				}
			}
			else
			{
				ctrlrScan=ctrlrScan.nextController;
			}
		}
		if (iCaptainsRequestingCount < 2)
		{
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("Server - TournamentRequestSwapSides() entered"));
		if (! Level.Game.TournamentRequestSwapSides())
		{
			PlayerReplicationInfo.bTournamentTeamSwapRequest=False;
			Level.Game.TournamentSendTeamCaptainOnlyMessage("Swapping sides is not allowed at this time.");
		}
	*/

}
void AHumanController::TournamentRequestStartWarmup()
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		local int iCaptainsRequestingCount;
		if (PlayerReplicationInfo.bAdmin)
		{
			UE_LOG(LogTemp, Warning, TEXT("Server - TournamentRequestStartWarmup() entered"));
			Level.Game.TournamentRequestWarmup();
			return;
		}
		if (PlayerReplicationInfo.bTournamentWarmupRequest && GetWorld()->GetTimeSeconds() < NextWarmupAllowed)
		{
			ClientMessage("You have already requested the tournament be restarted with a warmup round. If your warmup request is not granted you can try again during the next round.");
			return;
		}
		PlayerReplicationInfo.bTournamentWarmupRequest=True;
		NextWarmupAllowed=GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
		iCaptainsRequestingCount=1;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (PC.PlayerReplicationInfo.Team.TeamIndex != PlayerReplicationInfo.Team.TeamIndex && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				if (PC.PlayerReplicationInfo.bTournamentWarmupRequest)
				{
					iCaptainsRequestingCount ++;
				}
				else
				{
					HumanController(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested to restart with a mission planning round.");
				}
			}
			else
			{
				ctrlrScan=ctrlrScan.nextController;
			}
		}
		if (iCaptainsRequestingCount < 2)
		{
			return;
		}
		Level.Game.TournamentRequestWarmup();
	*/
}

void AHumanController::TournamentRequestPauseTournament()
{
	//TournamentRequestPause(PlayerReplicationInfo);
}

void AHumanController::TournamentRequestPause(AAA2_PlayerState* PRI)
{
	/*
	local Controller ctrlrScan;
	local PlayerController PC;
	if (PRI.bAdmin)
	{
		Level.Game.TournamentRequestPauseTournament();
		ServerSay("The Administrator has paused the tournament after this game completes.", 'AdminSay');
		Return;
	}
	if (!PRI.bTournamentTeamCaptain)
	{
		ClientMessage("You are not the Team Captain and cannot request pauses.");
		Return;
	}
	if (PRI.bTournamentMatchPauseRequest && GetWorld()->GetTimeSeconds() < NextPauseAllowed)
	{
		ClientMessage("You have already requested the tournament to be paused. If your pause request is not granted you can try again during the next round.");
		Return;
	}
	PRI.bTournamentMatchPauseRequest = true;
	NextPauseAllowed = GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
	ctrlrScan = Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		PC = PlayerController(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (PC.PlayerReplicationInfo.Team.TeamIndex != PRI.Team.TeamIndex && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			UE_LOG(LogTemp, Warning, TEXT("Examining other team captain's pause request status"));
			if (PC.PlayerReplicationInfo.bTournamentMatchPauseRequest)
			{
				Level.Game.TournamentRequestPauseTournament();
				TeamMessage(None, "Both team captains have requested the tournament to be paused at the end of this round.", 'TMStatus');
				Return;
			}
			else
			{
				HumanController(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested the tournament be paused at the end of the round.");
			}
		}
		ctrlrScan = ctrlrScan.nextController;
	}
	ClientMessage("You have requested to pause the tournament after this round. Waiting for the other team captain to respond.");
	*/
}



void AHumanController::TournamentResume()
{
	Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentResumeFromPause();
}
void AHumanController::TournamentRestartMatch()
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		local int iCaptainsRequestingCount;
		ClientCloseMenu(True);
		if (PlayerReplicationInfo.bAdmin)
		{
			if (GameReplicationInfo.sTournamentState ~= "Mission Planning")
			{
				Level.Game.TournamentTeamsReady();
			}
			else
			{
				Level.Game.TournamentRequestWarmup();
			}
			return;
		}
		if (PlayerReplicationInfo.bTournamentRestartRequest && GetWorld()->GetTimeSeconds() < NextRestartAllowed)
		{
			ClientMessage("You have already requested the match be restarted. If your restart request is not granted you can try again during the next round.");
			return;
		}
		PlayerReplicationInfo.bTournamentRestartRequest=True;
		NextRestartAllowed=GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
		iCaptainsRequestingCount=0;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (! PC.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
			}
			if (PC.PlayerReplicationInfo.bTournamentRestartRequest)
			{
				iCaptainsRequestingCount ++;
			}
			else
			{
				if (PC != this)
				{
					if (GameReplicationInfo.sTournamentState ~= "Mission Planning")
					{
						HumanController(PC).TournamentCaptainAdminMessage("The other Team Captain has requested the match be started  now.");
					}
					else
					{
						HumanController(PC).TournamentCaptainAdminMessage("The other Team Captain has requested the match be restarted.");
					}
				}
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		if (iCaptainsRequestingCount < 2)
		{
			return;
		}
		if (GameReplicationInfo.sTournamentState ~= "Mission Planning")
		{
			TeamMessage(None,"Both team captains have requested the match be started now.",'TMCenter');
		}
		else
		{
			TeamMessage(None,"Both team captains have requested the match be restarted.",'TMCenter');
		}
		Level.Game.TournamentRequestResetTournament();
	*/
}
void AHumanController::TournamentRestartTournament()
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		local int iCaptainsRequestingCount;
		ClientCloseMenu(True);
		if (PlayerReplicationInfo.bAdmin)
		{
			Level.Game.TournamentRequestResetTournament();
			return;
		}
		if (PlayerReplicationInfo.bTournamentRestartRequest && GetWorld()->GetTimeSeconds() < NextRestartAllowed)
		{
			ClientMessage("You have already requested the match be restarted. If your restart request is not granted you can try again during the next round.");
			return;
		}
		PlayerReplicationInfo.bTournamentRestartTournamentRequest=True;
		NextRestartAllowed=GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
		iCaptainsRequestingCount=0;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (! PC.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
			}
			if (PC.PlayerReplicationInfo.bTournamentRestartTournamentRequest)
			{
				iCaptainsRequestingCount ++;
			}
			else
			{
				if (PC != this)
				{
					HumanController(PC).TournamentCaptainAdminMessage("The other team captain has requested the tournament be restarted.");
				}
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		if (iCaptainsRequestingCount < 2)
		{
			return;
		}
		TeamMessage(None,"Both team captains have requested the tournament be restarted. All players must rejoin the server.",'TMCenter');
		Level.Game.TournamentRequestResetTournament();
	*/
}
void AHumanController::Suicide()
{
	/*
		if (Level.GetTourIsTraining(Level.iTour))
		{
			ConsoleCommand("Reconnect");
			return;
		}
		if (TournamentIsTournament() && GameReplicationInfo.bTournamentInWarmup)
		{
			TournamentTryToSuicidePlayer();
			return;
		}
		if (Vehicle(Pawn) != nullptr && VSize(Pawn.Velocity) > NoSuicideVelocity)
		{
			ClientMessage("You cannot commit suicide while the vehicle is moving.");
		}
		else
		{
			Suicide();
		}
	*/
}
void AHumanController::TournamentClientRunSuicide()
{
	/*
		if (Pawn != nullptr && GetWorld()->GetTimeSeconds() - Pawn.LastStartTime > 1)
		{
			if (Vehicle(Pawn) != nullptr && Vehicle(Pawn).Driver != nullptr)
			{
				Vehicle(Pawn).Driver.KilledBy(Vehicle(Pawn).Driver);
			}
			else
			{
				Pawn.KilledBy(Pawn);
			}
		}
	*/
}
void AHumanController::TournamentTryToSuicidePlayer()
{
	/*
		local Controller ctrlrScan;
		local HumanController hcScan;
		local int iLivePlayersOnPlayersTeam;
		if (PlayerReplicationInfo.Team.TeamIndex == 255)
		{
			return;
		}
		iLivePlayersOnPlayersTeam=0;
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			hcScan=HumanController(ctrlrScan);
			if (hcScan == nullptr || hcScan.Pawn == nullptr)
			{
			}
			if (! hcScan.Pawn.isDead() && hcScan.PlayerReplicationInfo.Team.TeamIndex == PlayerReplicationInfo.Team.TeamIndex)
			{
				iLivePlayersOnPlayersTeam ++;
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		if (iLivePlayersOnPlayersTeam > 1)
		{
			UE_LOG(LogTemp, Warning, TEXT("Just killing player"));
			TournamentClientRunSuicide();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Ending Mission Planning period."));
			ctrlrScan=Level.ControllerList;
			if (ctrlrScan != nullptr)
			{
				hcScan=HumanController(ctrlrScan);
				if (hcScan == nullptr)
				{
				}
				if (hcScan.MyHUD != nullptr && AGP_HUD(hcScan.MyHUD) != nullptr)
				{
					AGP_HUD(hcScan.MyHUD).DisplayCenteredMessage(4,"Mission Planning Period ending because all players on one team have killed themselves.");
				}
				ctrlrScan=ctrlrScan.nextController;
			}
			Level.Game.TournamentEndCurrentRound();
		}
	*/
}
void AHumanController::TournamentTeamList(int32 iTeam)
{
	/*
		local Controller ctrlrScan;
		local PlayerController PC;
		ClientMessage("* indicates Team Captain");
		ClientMessage("");
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (PC.PlayerReplicationInfo.Team.TeamIndex == iTeam)
			{
				if (ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					ClientMessage("*" $ ctrlrScan.PlayerReplicationInfo.PlayerName);
				}
				else
				{
					ClientMessage(ctrlrScan.PlayerReplicationInfo.PlayerName);
				}
			}
			ctrlrScan=ctrlrScan.nextController;
		}
		ClientMessage("-------------------------------------");
		ClientMessage(GameReplicationInfo.asTournamentTeamName[iTeam] $ " Team Roster");
	*/
}
void AHumanController::TournamentOpenResultsFile(FString sBaseFileName, FString Message)
{
	/*
		local string sFileName;
		sFileName=GetBaseDir() $ "\..\TournamentResults\";
		CreateDir(sFileName);
		sFileName=sFileName $ sBaseFileName;
		if (Message != "")
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(10,"The tournament has ended " $ Message $ ".","Tournament results saved to """ $ sBaseFileName $ """.");
				ClientMessage("Tournament has ended " $ Message $ ". Tournament results saved in your ""TournamentResults"" folder as """ $ sBaseFileName $ """.");
			}
		}
		else
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(10,"The tournament has ended.","Tournament results saved to """ $ sBaseFileName $ """.");
				ClientMessage("Tournament has ended.  Tournament results saved in the ""TournamentResults"" folder as """ $ sBaseFileName $ """.");
			}
		}
		FOpenWrite(sFileName);
	*/
}
void AHumanController::TournamentWriteResultsFile(FString sTournamentResults)
{
	/*
		if (Len(sTournamentResults) == 0)
		{
			return;
		}
		FWrite(sTournamentResults);
	*/
}
void AHumanController::TournamentCloseResultsFile()
{
	//FClose();
}
void AHumanController::TMAssignClass(int32 iUnitID, int32 iSlot, FString sPlayerName)
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can assign classes.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && TournamentIsTeamRosterLocked(PlayerReplicationInfo.Team.TeamIndex))
		{
			ClientMessage("The Roster is currently locked.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.PlayerName != sPlayerName)
		{
			ClientMessage("You can only assign yourself.");
			return;
		}
		if (! TournamentAssignClass(sPlayerName,iUnitID,iSlot))
		{
			ScreenPrint("Proper syntax: TMAssignClass [PlayerName] [UnitID 0=SL, 1 = FT Alpha, 2 = FT Bravo, ...] [Slot: 0 = FTL, 1 = Member]");
		}
	*/
}
void AHumanController::TMRemoveClass(int32 iUnitID, int32 iSlot, FString sPlayerName)
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can remove classes.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && TournamentIsTeamRosterLocked(PlayerReplicationInfo.Team.TeamIndex))
		{
			ClientMessage("The Roster is currently locked.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.PlayerName != sPlayerName)
		{
			ClientMessage("You can only remove yourself.");
			return;
		}
		if (! TournamentRemoveClass(sPlayerName,iUnitID,iSlot))
		{
			ScreenPrint("Proper syntax: TMRemoveClass [PlayerName] [UnitID 0=SL, 1 = FT Alpha, 2 = FT Bravo, ...] [Slot: 0 = FTL, 1 = Member]");
		}
	*/
}
void AHumanController::TMSetTeamName(int32 iTeam, FString sTeamName)
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can set team names.");
			return;
		}
		if (iTeam > 1 || iTeam < 0 || Len(sTeamName) == 0)
		{
			ClientMessage("Invalid team index, syntax: TestTournamentSetTeamName [0/1] [TeamName]");
			return;
		}
		TournamentSetTeamName(iTeam,sTeamName);
	*/
}
void AHumanController::TMTeamList(int32 iTeam)
{
	if (! TournamentIsTournament())
	{
		ClientMessage("Not in tournament mode.");
		return;
	}
	TournamentTeamList(iTeam);
}
void AHumanController::TMTeamReady()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains can signal ready.");
			return;
		}
		TournamentTeamReady();
	*/

}
void AHumanController::TMAdminReady()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Admins can signal both teams ready.");
			return;
		}
		TournamentAdminReady();
	*/
}
void AHumanController::TMRequestTeamCaptain()
{
	if (! TournamentIsTournament())
	{
		ClientMessage("Not in tournament mode.");
		return;
	}
	//TournamentRequestTeamCaptain(PlayerReplicationInfo);
}
void AHumanController::TMJoinTeam(int32 iTeam, FString sPassword)
{
	if (! TournamentIsTournament())
	{
		ClientMessage("Not in tournament mode.");
		return;
	}
	TournamentJoinTeam(iTeam,sPassword);
}
void AHumanController::TMPauseTournament()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can pause.");
			return;
		}
		TournamentRequestPause(PlayerReplicationInfo);
	*/
}
void AHumanController::TMResume()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can resume.");
			return;
		}
		TMTeamReady();
	*/
}
void AHumanController::TMSwapSides()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can swap sides.");
			return;
		}
		TournamentRequestSwapSides();
	*/
}
void AHumanController::TMRestartMatch()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can restart a match.");
			return;
		}
		TournamentRestartMatch();
	*/
}
void AHumanController::TMRestartTournament()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can restart tournaments.");
			return;
		}
		TournamentRestartTournament();
	*/
}
void AHumanController::TMRestartMatchWithMissionPlanning()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can restart with mission planning.");
			return;
		}
		TournamentRequestStartWarmup();
	*/
}
void AHumanController::TMHelp()
{
	
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		ClientMessage("");
		ClientMessage("TMAssignClass [FireTeam] [Slot] [PlayerName/PlayerId](fireteam 0 = Squad Leader, 1 - 4 fireteams)");
		ClientMessage("TMJoinTeam [Team index] Password (this will join the team if the password is correct)");
		ClientMessage("TMSwapSides (this will request swapping sides at end of current round)");
		ClientMessage("TMPauseTournament (this will pause the tournament at end of current round)");
		ClientMessage("TMRequestTeamCaptain (this will request that you be made team captain)");
		ClientMessage("TMTeamReady true/false (this will signal your team is ready to continue)");
		ClientMessage("TMSetTeamName [Team index] Name  (this will set the specified team's name)");
		ClientMessage("TMTeamList [Team index] (displays team members, captain with asterisk)");
		ClientMessage("TMRestartMatch - Restart tournament match play (scores only reset - requires both team captains to agree)");
		ClientMessage("TMRestartMatchWithMissionPlanning - Restart tournament match play (scores only reset, mission planning round played - requires both team captains to agree)");
		ClientMessage("TMRestartTournament - Restart tournament (rosters and scores reset - requires both team captains to agree)");
		ClientMessage("");
		ClientMessage("------------------------------------------------------");
		ClientMessage("Comments are included in parenthesis after parameters)");
		ClientMessage("Spaces are not allowed in team or player names (replace spaces with underscores)");
		ClientMessage("TeamID fields use 0 for Team 0 and 1 for Team 1");
		ClientMessage("Available Tournament Related Commands:");
		/*
		if (PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("");
			ClientMessage("TMRestartMatch - Admin wants to restart tournament match play (scores only reset)");
			ClientMessage("TMRestartTournament - Admin wants to restart tournament (rosters and scores reset, players rejoin server)");
			ClientMessage("TMAdminReady - Admin is ready to continue tournament");
			ClientMessage("TMResume - Admin is resuming match immediately from pause or swap mode");
			ClientMessage("--------------------");
			ClientMessage("Tournament Admin-Only Commands:");
		}
		*/
	
}
void AHumanController::RunServer(FString ServerExecutable, FString ServerType, FString MapName, FString LogFile, FString INIfile, bool bShutDown)
{
	/*
		local string FullURL;
		if (ServerExecutable == "")
		{
			ServerExecutable="server";
		}
		else
		{
			if (InStr(ServerExecutable,".exe") == -1)
			{
				ServerExecutable=ServerExecutable;
			}
		}
		if (ServerType == "")
		{
			ServerType="lan";
		}
		if (MapName == "")
		{
			MapName="MOUT_McKenna.aao";
		}
		else
		{
			if (InStr(MapName,".aao") == -1)
			{
				MapName=MapName $ ".aao";
			}
		}
		if (LogFile == "")
		{
			LogFile="server.log";
		}
		else
		{
			if (InStr(LogFile,".log") == -1)
			{
				LogFile=LogFile $ ".log";
			}
		}
		if (INIfile == "")
		{
			INIfile="server.ini";
		}
		else
		{
			if (InStr(INIfile,".ini") == -1)
			{
				INIfile=INIfile $ ".ini";
			}
		}
		FullURL=ServerType @ MapName @ "log=" $ LogFile @ "ini=" $ INIfile;
		ConsoleCommand("launchserver" @ FullURL);
	*/
}
int32 AHumanController::NumSupportStrikesAvailable()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return (S->StrikesAvailable);
	}
	return 0;
}
int32 AHumanController::SupportArrivalTime()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return (S->ArrivalTime);
	}
	return 0;
}
bool AHumanController::IsSupportAvailable()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return S->bAvailable;
	}
	return false;
}
bool AHumanController::IsSupportReady()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return S->bReady;
	}
	return false;
}
bool AHumanController::IsSupportFiring()
{
	
		ACallForSupport* S;
		S=GetSupport();
		if (S != NULL)
		{
			return S->bFiring;
		}
		return false;
	
}
ACallForSupport* AHumanController::GetSupport()
{
	/*
		ACallForSupport* S;
		ForEach DynamicActors('CallForSupport',S)
		{
			if (S.TeamNumber == PlayerReplicationInfo.Team.TeamIndex)
			{
				return S;
			}
		}
		*/
		return NULL;
}
void AHumanController::RequestForSupport()
{
}
void AHumanController::ConfirmReqestForSupport()
{
}
bool AHumanController::CanCallForSupport()
{
		AAGP_Pawn* p;
		AAGP_Weapon* W;
		p = Cast<AAGP_Pawn>(GetPawn());
		if (p != nullptr)
		{
			W=Cast<AAGP_Weapon>(p->Weapon);
		}
		/*
		if (W != nullptr && W->IsA('Item_VIPER') && W->IsInState('LockedOn') && W->IsZoomed())
		{
			return true;
		}
		return false;
		*/
	return false;
}
void AHumanController::CallForSupport(FVector StrikeLocation, FVector StrikeNormal)
{
	ACallForSupport* S;
	if (!CanCallForSupport())
	{
		return;
	}
	S=GetSupport();
	if (S != nullptr)
	{
		if (S->bReady)
		{
		}
		if (S->bAvailable)
		{
			ReportIn();
		}
	}
	ServerCallForSupport(StrikeLocation,StrikeNormal);
}
void AHumanController::ServerCallForSupport(FVector StrikeLocation, FVector StrikeNormal)
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != nullptr)
	{
		S->CheckMark(GetPawn(),StrikeLocation,true);
		S->CallForSupport(this);
	}
}
void AHumanController::SetScopeDetailLevel(FString S)
{
	S = S.ToUpper();
	if (S.FString::Contains("UltraLow", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
	{
		S = "SCOPEDETAIL_VeryLow";
	}
	else
	{
		if (S.FString::Contains("VeryLow", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
		{
			S = "SCOPEDETAIL_VeryLow";
		}
		else
		{
			if (S.FString::Contains("Low", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
			{
				S = "SCOPEDETAIL_Low";
			}
			else
			{
				if (S.FString::Contains("Lower", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
				{
					S = "SCOPEDETAIL_Low";
				}
				else
				{
					if (S.FString::Contains("Normal", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
					{
						S = "SCOPEDETAIL_Normal";
					}
					else
					{
						if (S.FString::Contains("Higher", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
						{
							S = "SCOPEDETAIL_High";
						}
						else
						{	
							if (S.FString::Contains("High", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
							{
								S = "SCOPEDETAIL_High";
							}
							else
							{
								if (S.FString::Contains("VeryHigh", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
								{
									S = "SCOPEDETAIL_High";
								}
								else
								{
									if (S.FString::Contains("UltraHigh", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
									{
										S = "SCOPEDETAIL_High";
									}
									else
									{
										S = "SCOPEDETAIL_High";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	SetScopeDetail(S);
}
FString AHumanController::GetScopeDetailLevel()
{
	if (ScopeDetail == EScopeDetail::SCOPEDETAIL_VeryLow)
	{
		return "VeryLow";
	}
	else
	{
		if (ScopeDetail == EScopeDetail::SCOPEDETAIL_Low)
		{
			return "Low";
		}
		else
		{
			if (ScopeDetail == EScopeDetail::SCOPEDETAIL_Normal)
			{
				return "Normal";
			}
			else
			{
				if (ScopeDetail == EScopeDetail::SCOPEDETAIL_High)
				{
					return "High";
				}
				else
				{
					return "High";
				}
			}
		}
	}
}
void AHumanController::SetScopeDetail(FString S)
{
	if (S == "SCOPEDETAIL_VeryLow")
	{
		ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_VeryLow);
	}
	else
	{
		if (S == "SCOPEDETAIL_Low")
		{
			ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_Low);
		}
		else
		{
			if (S == "SCOPEDETAIL_Normal")
			{
				ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_Normal);
			}
			else
			{
				if (S == "SCOPEDETAIL_High")
				{
					ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_High);
				}
				else
				{
					ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_High);
				}
			}
		}
	}
}
EScopeDetail AHumanController::GetScopeDetail()
{
	return ScopeDetail;
}
void AHumanController::ServerSetScopeDetail(EScopeDetail newDetail)
{
	ScopeDetail=newDetail;
}
void AHumanController::NeedNetNotify()
{
	//return NeedNetNotify() || bWaitingForPRI || bVoiceChatEnabled && bWaitingForVRI;
}
void AHumanController::RunInputCommand(FString Cmd)
{
}
void AHumanController::LoadSRGrammar(FString Grammar)
{
}
void AHumanController::LoadSRBinds(FString Filename, FString OutFilename)
{
}
void AHumanController::SaveSRBinds(FString Filename)
{
}
void AHumanController::GetSRBind(FString Alias)
{
}
void AHumanController::SetSRBind(FString Alias, FString BindPhrase)
{
}
void AHumanController::SetGrammar()
{
	/*
	if (! LoadSRBinds("aaspeech"))
	{
		LoadSRBinds("default","aaspeech");
		SaveSRBinds();
	}
	*/
	LoadSRGrammar("aaspeech");
}
void AHumanController::ResetGrammar()
{
	LoadSRBinds("default","aaspeech");
}
void AHumanController::VoiceCommand(FString RecognizedString, FString RawString)
{
	/*
		local string Command;
		local string argument;
		local string ParseString;
		local string BitBucket;
		local string tmp;
		UE_LOG(LogTemp, Warning, TEXT("Speech Rec: Recognized Commands = " $ RecognizedString));
		UE_LOG(LogTemp, Warning, TEXT("Speech Rex: Raw = " $ RecognizedString));
		if (! Divide(RecognizedString," ",Command,ParseString))
		{
			Command=RecognizedString;
		}
		if (Command != "")
		{
			Switch(Command)
			{
				case "TEAMSAY":
				case "SAY":
				tmp=GetSRBind(Command);
				if (tmp != "")
				{
					Divide(RawString,tmp,BitBucket,argument);
					ConsoleCommand(Command $ argument);
				}
				break;
				default:
				RunInputCommand(Command);
			}
			if (! Divide(ParseString," ",Command,ParseString))
			{
				Command=ParseString;
			}
		}
	*/
}

void AHumanController::PostNetReceive()
{
	/*
		PostNetReceive();
		if (PlayerReplicationInfo != nullptr && bWaitingForPRI)
		{
			bWaitingForPRI=False;
			if (bAutoDemoRec && GetNetMode() == ENetMode::NM_Client && ! bDemoOwner)
			{
				Player.Console.DelayedConsoleCommand("demorec");
			}
		}
		if (VoiceReplicationInfo != nullptr && bWaitingForVRI)
		{
			if (PlayerReplicationInfo != nullptr && ! PlayerReplicationInfo.NeedNetNotify())
			{
				bWaitingForVRI=VoiceReplicationInfo.GetPublicChannelCount(True) == 0;
				if (! bWaitingForVRI)
				{
					VoiceReplicationInfo.SetOwner(this);
					if (bVoiceChatEnabled)
					{
						InitializeVoiceChat();
					}
					else
					{
						DisableVoiceChat();
					}
				}
			}
		}
		bNetNotify=NeedNetNotify();
	*/
}
void AHumanController::AutoJoinVoiceChat()
{
	/*
		local int i;
		local int j;
		local int cnt;
		local string DefaultChannel;
		if (! bVoiceChatEnabled || GetNetMode() != ENetMode::NM_Client && GetNetMode() != ENetMode::NM_ListenServer)
		{
			return;
		}
		if (VoiceReplicationInfo == nullptr)
		{
			return;
		}
		cnt=VoiceReplicationInfo.GetPublicChannelCount(True);
		for (i=0; i<cnt; i++)
		{
			if (AutoJoinMask & 1 << i)
			{
				Join(VoiceReplicationInfo.PublicChannelNames[i],"");
				for (j=RejoinChannels.Length-1; j>=0; j--)
				{
					if (RejoinChannels[j] == VoiceReplicationInfo.PublicChannelNames[i])
					{
						RejoinChannels.remove (j,1);
					}
				}
			}
		}
		for (i=0; i<RejoinChannels.Length; i++)
		{
			Join(RejoinChannels[i],"");
		}
		if (LastActiveChannel != "")
		{
			Speak(LastActiveChannel);
		}
		else
		{
			if (ActiveRoom == nullptr && bEnableInitialChatRoom)
			{
				DefaultChannel=GetDefaultActiveChannel();
				if (DefaultChannel != "")
				{
					Speak(DefaultChannel);
				}
			}
		}
		if (RejoinChannels.Length > 0 || LastActiveChannel != "")
		{
			RejoinChannels.Length=0;
			LastActiveChannel="";
			SaveConfig();
		}
	*/
}
void AHumanController::ServerChatDebug()
{
}
void AHumanController::MatchStarting()
{
	//bLastHealSelfAction=false;
	bHealSelfAction=0;

	//ServerUpdateSelfHealActionState(false);
	ChangeActionStatus(0);
	if (! PlayerReplicationInfo->bAdmin && ! PlayerReplicationInfo->bOnlySpectator)
	{
		//ClientSetBehindView(false);
	}
	ClientCloseMenu(false,false);
	
}
void AHumanController::MatchEnding()
{
	//ClientSetBehindView(false);
	IdleCheckPerRound(true);
	//CleanOutSavedMoves();
}
int32 AHumanController::CalculateUserNameChecksum(FString sUserName)
{
	
		int32 i = 0;
		int32 iTempValue = 0;
		int32 iChecksum = 0;
	/*
		ReplaceText(sUserName," ","_");
		sUserName=Locs(sUserName);
		for (i=0; i<Len(sUserName); i++)
		{
			iTempValue=Asc(Mid(sUserName,i,1));
			iChecksum += iTempValue * i + 1;
		}
	*/
	return iChecksum;
}
void AHumanController::strip(FString str, int32 atleast)
{
	/*
		str=Mid(str,atleast);
		if (Left(str,1) == " ")
		{
			str=strip(str,1);
		}
		return str;
	*/
}
void AHumanController::IsArgument(FString S, FString argument, FString Option)
{
	/*
		local int L;
		L=Len(argument);
		if (Left(S,L) ~= argument)
		{
			Option=strip(S,L);
			return true;
		}
		else
		{
			return false;
		}
	*/
}
void AHumanController::MPCheat(FString cheat)
{
	/*
		local string Option;
		if (_CheatMonitor != nullptr)
		{
			_CheatMonitor.Notify();
		}
		if (EventLab != nullptr)
		{
			Log("Test");
			EventLab.EventLabNotifyCheat();
		}
		if (Level.Game.CheatsDisabled())
		{
			return;
		}
		if (Level.Game.GetScreenplay() != nullptr)
		{
			Level.Game.GetScreenplay().NotifyCheated();
		}
		cheat=Caps(cheat);
		if (Left(cheat,6) == "SILENT")
		{
			cheat=strip(cheat,6);
		}
		else
		{
			Level.Game.Broadcast(this,"Activated a multiplayer cheat: " $ cheat,'cheat');
		}
		if (IsArgument(cheat,"GHOST"))
		{
			MPCheat_EnterGhostMode();
		}
		else
		{
			if (IsArgument(cheat,"WALK"))
			{
				MPCheat_Walk();
			}
			else
			{
				if (IsArgument(cheat,"GOD"))
				{
					MPCheat_God();
				}
				else
				{
					if (IsArgument(cheat,"SUPERGOD"))
					{
						MPCheat_SuperGod();
					}
					else
					{
						if (IsArgument(cheat,"ENDGAME"))
						{
							MPCheat_EndGame();
						}
						else
						{
							if (IsArgument(cheat,"FLOOD"))
							{
								MPCheat_Flood();
							}
							else
							{
								if (IsArgument(cheat,"NVG"))
								{
									MPCheat_NVG();
								}
								else
								{
									if (IsArgument(cheat,"ACTORLIST"))
									{
										MPCheat_ActorList();
									}
									else
									{
										if (IsArgument(cheat,"DACTORLIST"))
										{
											MPCheat_DActorList();
										}
										else
										{
											if (IsArgument(cheat,"BINOC",Option))
											{
												MPCheat_Binoc(Option);
											}
											else
											{
												if (IsArgument(cheat,"MEDIC",Option))
												{
													MPCheat_Medic(Option);
												}
												else
												{
													if (IsArgument(cheat,"PAUSE",Option))
													{
														MPCheat_Pause(Option);
													}
													else
													{
														if (IsArgument(cheat,"SLOMO",Option))
														{
															MPCheat_Slomo(Option);
														}
														else
														{
															if (IsArgument(cheat,"FREECAMERA",Option))
															{
																MPCheat_FreeCamera(Option);
															}
															else
															{
																if (IsArgument(cheat,"BEHINDVIEW",Option))
																{
																	MPCheat_Behindview(Option);
																}
																else
																{
																	if (IsArgument(cheat,"CHANGECLASS",Option))
																	{
																		MPCheat_ChangeClass(Option);
																	}
																	else
																	{
																		if (IsArgument(cheat,"CLASS",Option))
																		{
																			MPCheat_ChangeClass(Option);
																		}
																		else
																		{
																			if (IsArgument(cheat,"PARAMS",Option))
																			{
																				MPCheat_Params(Option);
																			}
																			else
																			{
																				if (IsArgument(cheat,"PLAYERLOCK",Option))
																				{
																					MPCheat_PlayerLock(Option);
																				}
																				else
																				{
																					if (IsArgument(cheat,"SCENEJUMP",Option))
																					{
																						MPCheat_SceneJump(Option);
																					}
																					else
																					{
																						if (IsArgument(cheat,"FOV",Option))
																						{
																							MPCheat_FOV(Option);
																						}
																						else
																						{
																							UE_LOG(LogTemp, Warning, TEXT("HumanController::MPCheat()	Unknown Cheat " $ cheat,true));
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	*/
}
void AHumanController::MPCheat_FOV(float F)
{
	DesiredFOV = FMath::Clamp(F, 1.0f, 170.0f);
}
void AHumanController::MPCheat_ActorList()
{
}
void AHumanController::MPCheat_DActorList()
{
}
void AHumanController::MPCheat_FreeCamera(bool B)
{
	bFreeCamera = B;
	bBehindView = B;
	//ClientSetBehindView(B, true);
}
void AHumanController::MPCheat_Behindview(bool B)
{
	bBehindView = B;
	//ClientSetBehindView(B, false);
}
void AHumanController::MPCheat_PlayerLock(bool B)
{
	//LockPlayer(B,B);
}
void AHumanController::MPCheat_SceneJump(FString SceneName)
{
	/*
	if (Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().SceneJump(SceneName);
	}
	*/
}
void AHumanController::MPCheat_Params(FString Params)
{

	/*
		local string Option;
		if (IsArgument(Params,"DEADGAME",Option))
		{
			AGP_GameInfo(Level.Game).bDeadGame=Option;
		}
		else
		{
			if (IsArgument(Params,"NOINV",Option))
			{
				AGP_GameInfo(Level.Game).bNoInventory=Option;
			}
			else
			{
				if (IsArgument(Params,"NOFADE",Option))
				{
					bCheatNoFade=Option;
				}
				else
				{
					if (IsArgument(Params,"VERBOSE",Option))
					{
						bCheatVerbose=Option;
					}
					else
					{
						if (IsArgument(Params,"SWAP",Option))
						{
							bDebugSwapPickups=Option;
						}
						else
						{
							if (IsArgument(Params,"AIM",Option))
							{
								bPerfectAccuracy=Option;
							}
							else
							{
								if (IsArgument(Params,"AMMO",Option))
								{
									bUnlimitedAmmo=Option;
								}
								else
								{
									if (IsArgument(Params,"PENALTY",Option))
									{
										bNoWeaponPenalty=Option;
									}
									else
									{
										if (IsArgument(Params,"NATIVE",Option))
										{
											bNativeBonus=Option;
										}
										else
										{
											UE_LOG(LogTemp, Warning, TEXT("HumanController::MPCheat_Params() Unknown parameters " $ Params,True));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	*/
}
void AHumanController::MPCheat_Slomo(float t)
{
	/*
		if (t == 0)
		{
			return;
		}
		Level.Game.SetGameSpeed(t);
		Level.Game.SaveConfig();
		Level.Game.GameReplicationInfo.SaveConfig();
	*/
}
void AHumanController::MPCheat_Pause(bool bPause)
{
	/*
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			Level.Game.PauseGame(bPause,this);
		}
	*/
}
void AHumanController::MPCheat_EndGame()
{
	//Level.Game.EndGame(PlayerReplicationInfo,"CheatEndGame");
}
void AHumanController::MPCheat_Flood()
{
	yFloodCount = 255;
}
void AHumanController::MPCheat_NVG()
{
	/*
	local AGP_Pawn myPawn;
	myPawn = Cast<AAGP_Pawn>(GetPawn());
	if (myPawn != nullptr && myPawn._OpticsDevice == nullptr)
	{
		myPawn._OpticsDevice = Spawn(class<BaseOptics>(DynamicLoadObject("AGP_Inventory.NightOpticsDevice", Class'Class')), myPawn);
		myPawn._OpticsDevice.DoAttachStuffWhichShouldBeDoneInInventory();
	}
	*/
}
void AHumanController::MPCheat_Binoc(uint8 new_binoc)
{
	/*
		if (Pawn != nullptr)
		{
			Switch(new_binoc)
			{
				case 0:
				if (Pawn._InvBinoculars == 0)
				{
					Pawn._InvBinoculars=1;
					break;
				}
				Pawn._InvBinoculars=0;
			}
			case 1:
			case 2:
			case 3:
			case 4:
			Pawn._InvBinoculars=new_binoc;
			default:
			ClientMessage("[0=No binocs] [1=M22] [2=M22] [3=Tanker] [4=Newtonian]");
		}
	*/
}
void AHumanController::MPCheat_Medic(int32 new_num_med)
{
	/*
		if (Pawn != nullptr)
		{
			if (new_num_med == 0)
			{
				new_num_med=3;
			}
			Pawn._InvMedPacks=new_num_med;
		}
	*/
}
void AHumanController::MPCheat_SuperGod()
{
		bSuperGodMode=! bSuperGodMode;
		bGodMode=bSuperGodMode;
		if (bSuperGodMode)
		{
			ClientMessage("MultiPlayer SuperGod Mode is on!");
		}
		else
		{
			ClientMessage("MultiPlayer SuperGod Mode is off.");
		}
}
void AHumanController::MPCheat_God()
{
	bGodMode=! bGodMode;
	if (bGodMode)
	{
		ClientMessage("MultiPlayer God Mode is on!");
	}
	else
	{
		bSuperGodMode=false;
		ClientMessage("MultiPlayer God Mode is off.");
	}
}
void AHumanController::MPCheat_EnterGhostMode()
{
	/*
	Pawn.UnderWaterTime = -1;
	ClientMessage("MultiPlayer Ghost Mode!");
	Pawn.SetCollision(False, False, false);
	Pawn.bCollideWorld = false;
	bCheatFlying = true;
	GotoState('PlayerFlying');
	*/
}
void AHumanController::MPCheat_Walk()
{
	/*
		Pawn.UnderWaterTime=0;
		ClientMessage("Walk Mode Restored");
		Pawn.SetCollision(True,True,True);
		Pawn.bCollideWorld=True;
		bCheatFlying=False;
		GotoState('PlayerWalking');
	*/
}
void AHumanController::newTeamClass(ASoldierClass*  sclass)
{
	/*
		local SoldierClass LastClass;
		UE_LOG(LogTemp, Warning, TEXT("newTeamClass(" $ sclass $ ")"));
		if (Role < 4)
		{
			return;
		}
		if (sclass == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Received null new team class."));
			return;
		}
		if (Pawn == nullptr)
		{
			return;
		}
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			LastClass=Cast<AAGP_Pawn>(GetPawn()).TeamClass;
		}
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).TeamClass=Spawn(sclass,Cast<AAGP_Pawn>(GetPawn()));
			UE_LOG(LogTemp, Warning, TEXT("AGP:Cheater::newTeamClass() Spawned " $ Cast<AAGP_Pawn>(GetPawn()).TeamClass));
			Cast<AAGP_Pawn>(GetPawn()).TeamClass.adjustAttributes(LastClass);
			Cast<AAGP_Pawn>(GetPawn()).EmptyInventory(True);
			Cast<AAGP_Pawn>(GetPawn()).TeamClass.addClassInventory(True);
			Cast<AAGP_Pawn>(GetPawn()).TeamClass.addTeamInventory();
		}
		if (Level.Game != nullptr && Level.Game.IsA('AGP_GameInfo'))
		{
			if (AGP_GameInfo(Level.Game).IsClassLegal(sclass))
			{
				PlayerReplicationInfo.sCurrentWeaponClass="" $ sclass;
				DesiredTeamClass=sclass;
			}
		}
		else
		{
			DesiredTeamClass=sclass;
		}
		LastClass.Destroy();
	*/
}

void AHumanController::MPCheat_ChangeClass(FString ClassName)
{
	/*
		local class<SoldierClass>  sclass;
		local string sclass_name;
		if (Pawn == nullptr)
		{
			return;
		}
		if (Level.sLevelName ~= "entry" || Level.sLevelName ~= "entry2")
		{
			return;
		}
		LockPlayer(False,False);
		Switch(ClassName)
		{
			case "":
				ScreenPrint("Type ""Class X"" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, RPG9");
				return;
			case "M":
			case "M4A1":
				sclass_name="AGP_Characters.ClassRiflemanM4A1AutoIron";
				break;
			case "MA":
			case "M4A1Auto":
				sclass_name="AGP_Characters.ClassRiflemanM4A1Auto";
				break;
			case "AR":
			case "AutomaticRifleman":
				sclass_name="AGP_Characters.ClassAutomaticRifleman";
				break;
			case "R":
			case "Rifleman":
				sclass_name="AGP_Characters.ClassRifleman";
				break;
			case "RCT":
			case "Recruit":
				sclass_name="AGP_Characters.ClassRecruit";
				break;
			case "AK":
			case "RiflemanAK":
				sclass_name="AGP_Characters.ClassRiflemanAK";
				break;
			case "AK74SU":
				sclass_name="AGP_Characters.ClassRiflemanAK74SU";
				break;
			case "AK74suReflex":
				sclass_name="AGP_Characters.ClassGuerrillaAK74suReflex";
				break;
			case "RPK":
				sclass_name="AGP_Characters.ClassAutomaticRiflemanRPK";
				break;
			case "M4M":
				sclass_name="AGP_Characters.ClassRiflemanM4A1Mod";
				break;
			case "G":
			case "Grenadier":
				sclass_name="AGP_Characters.ClassGrenadier";
				break;
			case "GP":
				sclass_name="AGP_Characters.ClassGrenadierGP30_Op";
				break;
			case "Mos":
				sclass_name="AGP_Characters.ClassSniperMos";
				break;
			case "S":
			case "S82":
			case "Sniper":
			case "Sniper82":
				sclass_name="AGP_Characters.ClassSniper";
				break;
			case "S24":
			case "Sniper24":
				sclass_name="AGP_Characters.ClassSniper24_US";
				break;
			case "SVD":
				sclass_name="AGP_Characters.ClassSniperSVD";
				break;
			case "RPG":
				sclass_name="AGP_Characters.ClassRPG";
				break;
			case "AT4":
				sclass_name="AGP_Characters.ClassAT4Rocket";
				break;
			case "BDM":
				sclass_name="AGP_Characters.ClassBDMRocket";
				break;
			case "M9":
				sclass_name="AGP_Characters.ClassPistol";
				break;
			case "SF":
				sclass_name="AGP_Characters.ClassSF";
				break;
			case "SFSniper":
			case "SPR":
				sclass_name="AGP_Characters.ClassSFSniper";
				break;
			case "PSO":
			case "GuerrillaPSO":
				sclass_name="AGP_Characters.ClassGuerrillaPSO";
				break;
			case "V":
			case "VSS":
			case "GuerrillaSniper":
				sclass_name="AGP_Characters.ClassGuerrillaSniper";
				break;
			case "GuerrillaAK47su":
				sclass_name="AGP_Characters.ClassGuerrillaAK47su";
				break;
			case "GuerrillaRPG":
				sclass_name="AGP_Characters.ClassGuerrillaRPG";
				break;
			case "GuerrillaRPK":
				sclass_name="AGP_Characters.ClassGuerrillaRPK";
				break;
			case "D":
				sclass_name="AGP_Characters.ClassDemolitions";
				break;
			case "J":
				sclass_name="AGP_Characters.ClassJavelin";
				break;
			case "JT":
				sclass_name="AGP_Characters.ClassJavelinTube";
				break;
			case "RPG9":
				sclass_name="AGP_Characters.ClassGuerrillaRPGNine";
				break;
			default:
				ScreenPrint("Unrecognized class " $ ClassName);
				ScreenPrint("Type ""Class X"" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, J, JT, RPG9");
				return;
		}
		CleanUp();
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).bForcedWeaponChange=True;
		}
		sclass=class<SoldierClass>(DynamicLoadObject(sclass_name,Class'Class'));
		newTeamClass(sclass);
		UE_LOG(LogTemp, Warning, TEXT("HumanController::MPCheat_ChangeClass() " @ Cast<AAGP_Pawn>(GetPawn()).TeamClass));
	*/
}
void AHumanController::ELCheat(FString cheat)
{
	/*
		if (EventLab != nullptr)
		{
			Log("ELCheat TEST");
			EventLab.ActorNotify(this,30,,cheat);
		}
	*/
}

void AHumanController::addDebug(EDebugTag Debug)
{
}

void AHumanController::removeDebug(EDebugTag Debug)
{
}

void AHumanController::toggleDebug(EDebugTag Debug)
{
}

void AHumanController::SToggleDebug(EDebugTag Debug)
{
}

void AHumanController::ServerToggleDebug(EDebugTag Debug)
{
}

void AHumanController::AIDebug()
{
}

void AHumanController::AimDebug()
{
}

void AHumanController::RecoilDebug()
{
}

void AHumanController::FireModeDebug()
{
}

void AHumanController::PostureDebug()
{
}
void AHumanController::GrenadeDebug()
{
}
void AHumanController::MantleDebug()
{
}
void AHumanController::ZoomDebug()
{
}
void AHumanController::HumanAccuracy()
{
}
void AHumanController::TracerDebug()
{
}
void AHumanController::ParachuteDebug()
{
}
void AHumanController::ScreenplayDebug()
{
}
void AHumanController::FallingDebug()
{
}
void AHumanController::MisfireDebug()
{
}
void AHumanController::WeaponStateDebug()
{
}
void AHumanController::PawnStateDebug()
{
}
void AHumanController::ControllerStateDebug()
{
}
void AHumanController::WeaponAccDebug()
{
}
void AHumanController::InventoryDebug()
{
}
void AHumanController::AGPHUD(bool B)
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowHUD=B;
	}
}
void AHumanController::HideObjectives()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowObjectives=!Cast<AAGP_HUD>(MyHUD)->bShowObjectives;
	}
}

void AHumanController::ToggleObjectiveDisplay()
{
	/*
		local AGP_HUD A_HUD;
		local GameReplicationInfo GRI;
		GRI=GameReplicationInfo;
		A_HUD=Cast<AAGP_HUD>(MyHUD);
		bHUDHideObjectives=! bHUDHideObjectives;
		MyHUD.bShowObjectives=! GRI.bHUDHideObjectives && ! bHUDHideObjectives;
		if (A_HUD != nullptr)
		{
			A_HUD.SaveConfig();
		}
		MyHUD.SaveConfig();
	*/
}
void AHumanController::ToggleSAIDisplay()
{
	bHUDHideRadar=! bHUDHideRadar;
}
void AHumanController::HideCompassObjPoints(bool B)
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bHideCompassObjPoints=B;
	}
}
void AHumanController::ToggleDebugCE()
{
}
void AHumanController::Logo()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowLogo =!Cast<AAGP_HUD>(MyHUD)->bShowLogo;
	}
}
void AHumanController::SetTeam(uint8 Index)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		RequestChangeTeam(Index);
		SetSkin(SkinTonePref);
		setFace(Face);
		SetOpFace(OpFace);
	}
}
void AHumanController::Reload()
{
	/*
		if (Pawn != nullptr && ! Pawn.bMidJump)
		{
			if (Pawn.Weapon != nullptr && Pawn.Weapon.IsA('WEAPON_Javelin'))
			{
				if (Pawn.Weapon.IsInState('BusyLoweringWeapon') || Pawn.Weapon.IsInState('BusyRaisingWeapon'))
				{
					return;
				}
			}
			ServerWantsToReload();
		}
	*/
}
void AHumanController::ServerWantsToReload()
{
	/*
		if (! Pawn.Weapon.CanUseWeapon(3))
		{
			return;
		}
		ClientWantsToReload();
	*/
}
void AHumanController::ClientWantsToReload()
{
	Reload();
}
void AHumanController::FixJam()
{
	/*
		if (Pawn != nullptr && ! Pawn.bMidJump)
		{
			FixJam();
		}
	*/
}
void AHumanController::ChangeWpnPosX(float pos)
{
}
void AHumanController::ChangeWpnPosY(float pos)
{
}
void AHumanController::ChangeWpnPosZ(float pos)
{
}
void AHumanController::ChangeWpnScale(float fScale)
{
}
void AHumanController::ChangeWpnFOV(float new_fov)
{
}
void AHumanController::DoFade(bool FadeIn, bool Black, float Time, float percentage)
{
	if (bCheatNoFade)
	{
		return;
	}
	_bFadeBlack = Black;
	_bFadeIn = FadeIn;
	_fFadeTime = Time;
	_fFadeStartTime = GetWorld()->GetTimeSeconds();
	_bFade = true;
	if (percentage == 0)
	{
		_fFadePercentage = 1.0f;
	}
	else
	{
		_fFadePercentage = FMath::Clamp(percentage, 0.0f, 1.0f);
	}
}
void AHumanController::AutoTraceDebug()
{
}
void AHumanController::PermaTraceDebug()
{
}
void AHumanController::DumpControllers()
{
}
bool AHumanController::DebugSwapPickups()
{
	return bDebugSwapPickups;
}
void AHumanController::PrintShoot()
{
}
void AHumanController::ServerPrintShoot()
{
	PrintShoot();
}
void AHumanController::ServerDebugPrintShoot()
{
	
	bPrintShootDebug=! bPrintShootDebug;
	//ScreenPrint("DEBUG PRINTSHOOT" @ bPrintShootDebug);
	
}
void AHumanController::DebugSetDebugIcons(int32 OnOrOff)
{
}
void AHumanController::PanicBullet()
{
}
void AHumanController::PanicCrack()
{
}
void AHumanController::SS()
{
}
void AHumanController::PwnBeta(FString sBetaName)
{
	/*
		if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
		{
			ClientMessage("Unrecognized Command");
			return;
		}
		if (Len(sBetaName) == 0)
		{
			ClientMessage("may be used to tag all beta players.");
			ClientMessage("User PlayerList to view player names. Asterisk ");
			ClientMessage("Usage: PwnBeta <betaname/*>");
			return;
		}
		ServerAttachItem(sBetaName,"AGP_Inventory.Item_Bullseye");
	*/
}
void AHumanController::ServerAttachItem(FString sPlayerName, FString sTheItem)
{
	/*
		local Controller ctrlrScan;
		local Inventory SpawnedItem;
		local PlayerController PC;
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this,"CHEATER");
			return;
		}
		sTheItem="AGP_Inventory.Item_Bullseye";
		if (PlayerReplicationInfo._Group != 20 && PlayerReplicationInfo._Group != 1)
		{
			ClientMessage("Invalid command.");
			ServerSay("Player """ $ UserName $ """ kicked by the server.",'AdminSay');
			Log("ServerAttachItem() CHEAT DETECTED For user name """ $ UserName $ """ using player name of """ $ sPlayerName $ """.");
			Level.Game.KickByController(this,"BADUSERNAME");
			return;
		}
		if (sPlayerName == "*")
		{
			return;
		}
		ctrlrScan=Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			PC=PlayerController(ctrlrScan);
			if (PC == nullptr)
			{
			}
			if (sPlayerName ~= "[Dev]Acekilla" && PC.PlayerReplicationInfo._Group != 1)
			{
				ClientMessage("Invalid command.");
				ServerSay("Player """ $ UserName $ """ kicked by the server.",'AdminSay');
				Log("ServerAttachItem() CHEAT DETECTED For user name """ $ UserName $ """ using player name of """ $ sPlayerName $ """.");
				Level.Game.KickByController(this,"BADUSERNAME");
				return;
			}
			if (PC.PlayerReplicationInfo != nullptr && PC.PlayerReplicationInfo._Group == 4 || sPlayerName ~= "[Dev]Acekilla" && PC.PlayerReplicationInfo.PlayerName ~= sPlayerName || sPlayerName == "*")
			{
				if (HumanController(PC) != nullptr)
				{
					if (AGP_Pawn(PC.Pawn) != nullptr)
					{
						SpawnedItem=AGP_Pawn(PC.Pawn).CreateInventoryFromName(sTheItem);
						if (SpawnedItem != nullptr)
						{
							AGP_Pawn(PC.Pawn).AddInventory(SpawnedItem);
							if (sPlayerName == "*")
							{
								HumanController(PC).NotifyAdminMessage("Man, betas must feel like they're big walking targets when playing the devs!");
							}
							else
							{
								HumanController(PC).NotifyAdminMessage("Man, you must feel like you're a big walking target when playing the devs!");
							}
						}
					}
				}
				if (sPlayerName != "*")
				{
				}
			}
			else
			{
				ctrlrScan=ctrlrScan.nextController;
			}
		}
	*/
}
void AHumanController::ServerRequestBanList()
{
	/*
		local string sBanType;
		local string sBanLength;
		local int i;
		local int secs_until;
		local int weeks;
		local int days;
		local int hours;
		local int minutes;
		local bool bWroteTime;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			if (PlayerReplicationInfo == nullptr)
			{
				Level.Game.KickByController(this,"CHEATER");
				return;
			}
			if (! PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
			{
				Log("Invalid server setting access");
				return;
			}
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
			{
				if (PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
				{
					if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
					{
						Level.Game.KickByController(this,"CHEATER");
						return;
					}
				}
			}
		}
		i=0;
		if (i < Level.Game.AccessControl.BanList.Length && i < 100)
		{
			sBanLength="";
			if (Level.Game.AccessControl.BanList[i].BanEndDate_LoWord > 0 || Level.Game.AccessControl.BanList[i].BanEndDate_HiWord > 0)
			{
				if (Level.Game.AccessControl.CheckTimestampExpired(Level.Game.AccessControl.BanList[i].BanEndDate_LoWord,Level.Game.AccessControl.BanList[i].BanEndDate_HiWord,secs_until))
				{
				}
			}
			else
			{
				else
				{
					secs_until=0;
				}
				Switch(Level.Game.AccessControl.BanList[i].BanType)
				{
					case 3:
					sBanType="(PBGUID)";
					break;
					case 0:
					sBanType="(Player)";
					break;
					case 1:
					sBanType="(IP)";
					break;
					case 2:
					sBanType="(MAC)";
					break;
					default:
				}
				if (secs_until < 60 && secs_until > 0)
				{
					sBanLength=secs_until $ " second";
					if (secs_until > 1)
					{
						sBanLength=sBanLength $ "s";
					}
				}
				else
				{
					if (secs_until == 0)
					{
						sBanLength="eternity";
					}
				}
				weeks=secs_until / 604800;
				secs_until -= weeks * 604800;
				days=secs_until / 86400;
				secs_until -= days * 86400;
				hours=secs_until / 3600;
				secs_until -= hours * 3600;
				minutes=secs_until / 60;
				bWroteTime=False;
				if (weeks > 0)
				{
					sBanLength=weeks $ " week";
					if (weeks > 1)
					{
						sBanLength=sBanLength $ "s";
					}
					bWroteTime=True;
				}
				if (days > 0)
				{
					if (bWroteTime)
					{
						sBanLength=sBanLength $ ", ";
					}
					sBanLength=sBanLength $ days $ " day";
					if (days > 1)
					{
						sBanLength=sBanLength $ "s";
					}
					bWroteTime=True;
				}
				if (hours > 0)
				{
					if (bWroteTime)
					{
						sBanLength=sBanLength $ ", ";
					}
					sBanLength=sBanLength $ hours $ " hour";
					bWroteTime=True;
					if (hours > 1)
					{
						sBanLength=sBanLength $ "s";
					}
					bWroteTime=True;
				}
				if (minutes > 0)
				{
					if (bWroteTime)
					{
						sBanLength=sBanLength $ " and ";
					}
					sBanLength=sBanLength $ minutes $ " minute";
					if (minutes > 1)
					{
						sBanLength=sBanLength $ "s";
					}
					bWroteTime=True;
				}
				sBanLength=sBanLength $ " remaining";
				sBanType=sBanType $ " - " $ sBanLength;
				if (Level.Game.AccessControl.BanList[i].BanType != 0)
				{
					sBanType=sBanType $= " (" $ Level.Game.AccessControl.BanList[i].OriginalUserName $ ")";
				}
				ClientSendBanlistEntry(Level.Game.AccessControl.BanList[i].Banee,sBanType);
			}
			i ++;
		}
	*/
}
void AHumanController::ClientSendBanlistEntry(FString sBanee, FString sBanDetails)
{
	/*
		if (guipCommandPost != nullptr)
		{
			guipCommandPost.NotifyCommandPostPage("Ban List","BanListEntry",sBanee,sBanDetails);
		}
	*/
}
void AHumanController::ClientEnableLocalCheats()
{
		bCheatServer=true;
		
		if (Cast<AAGP_HUD>(MyHUD) != NULL)
		{
			//Org
			//Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer,bDevMode,bBetaServer,bLeasedServer,bOfficialServer,bNATOServer,bTournamentServer,bUltimateArenaServer,bIsAuthorizedServer,bExploreTheArmyServer,GameReplicationInfo.bAllowForceclassing);
			//Without GameReplicationInfo
			Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer, bDevMode, bBetaServer, bLeasedServer, bOfficialServer, bNATOServer, bTournamentServer, bUltimateArenaServer, bIsAuthorizedServer, bExploreTheArmyServer, false);
		}
		ClientMessage("The administrator has enabled ""Multiplayer Cheats"" on this server.");
}
void AHumanController::DisableLocalCheats()
{
	UE_LOG(LogTemp, Log, TEXT("ClientDisableLocalCheats() entered"));
	ClientMessage("The administrator has disabled ""Multiplayer Cheats"" on this server.");
	MPCheat_FreeCamera(false);
	MPCheat_Behindview(false);
	MPCheat_Walk();
	if (bCheatFlying)
	{
		ClientMessage("Walk Mode Restored");
	}
	if (bGodMode)
	{
		MPCheat_God();
		ClientMessage("God mode disabled");
	}
	bUnlimitedAmmo=false;
	bPerfectAccuracy=false;
	bFriendlyFireOff=false;
	bInvisible=false;
	bNoWeaponPenalty=false;
	bNativeBonus=false;
	bCheatServer=false;
	ClientDisableLocalCheats(bCheatServer);
}
void AHumanController::ClientDisableLocalCheats(bool bCheatServerStatus)
{
	bCheatServer=bCheatServerStatus;
	//Org
	//Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer,bDevMode,bBetaServer,bLeasedServer,bOfficialServer,bNATOServer,bTournamentServer,bUltimateArenaServer,bIsAuthorizedServer,bExploreTheArmyServer,GameReplicationInfo.bAllowForceclassing);
	//Without GameReplicationInfo
	Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer, bDevMode, bBetaServer, bLeasedServer, bOfficialServer, bNATOServer, bTournamentServer, bUltimateArenaServer, bIsAuthorizedServer, bExploreTheArmyServer, false);
}
void AHumanController::ClientUpdateForceclassing(bool bAllowForceclassing, bool bShowNotificationMessage)
{
	if (bAllowForceclassing)
	{
		Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer,bDevMode,bBetaServer,bLeasedServer,bOfficialServer,bNATOServer,bTournamentServer,bUltimateArenaServer,bIsAuthorizedServer,bExploreTheArmyServer,bAllowForceclassing);
		if (bShowNotificationMessage)
		{
			NotifyAdminMessage("The administrator has enabled global force classing of weapons with reduced honor.");
		}
	}
	else
	{
		if (bShowNotificationMessage)
		{
			NotifyAdminMessage("The administrator has disabled global force classing of weapons and restored full honor for the next round.");
		}
	}
}

void AHumanController::ServerSetINISetting(FString sINIValue)
{
	/*
			local Controller C;
			local bool bWeaponSlotRulesChanged;
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
			{
				if (PlayerReplicationInfo == nullptr)
				{
					Level.Game.KickByController(this,"CHEATER");
					return;
				}
				if (! PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
				{
					Log("Invalid server setting access");
					return;
				}
				if (PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
				{
					if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
					{
						if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
						{
							Level.Game.KickByController(this,"CHEATER");
							return;
						}
					}
				}
			}
			if (TournamentIsTournament())
			{
				if (InStr(sINIValue,"AGP_GameMultiPlayer bMPCheatsEnabled") != -1)
				{
					Log("Cannot change cheat mode in tournaments");
					return;
				}
			}
			if (InStr(sINIValue,"AGP_GameMultiPlayer bMPCheatsEnabled") != -1)
			{
				Log("cheats enabled flag: " $ ! Level.Game.CheatsDisabled() $ ", value: " $ sINIValue);
			}
			if (InStr(sINIValue,"AGP_GameInfo bOpenAllWeaponClassSlots") != -1)
			{
				if (InStr(sINIValue,"True") != -1)
				{
					if (! AGP_GameInfo(Level.Game).bOpenAllWeaponClassSlots)
					{
						bWeaponSlotRulesChanged=True;
					}
					AGP_GameInfo(Level.Game).bOpenAllWeaponClassSlots=True;
				}
				else
				{
					if (AGP_GameInfo(Level.Game).bOpenAllWeaponClassSlots)
					{
						bWeaponSlotRulesChanged=True;
					}
					AGP_GameInfo(Level.Game).bOpenAllWeaponClassSlots=False;
				}
				Level.Game.GetTeam(0).FindValidFireTeams();
				Level.Game.GetTeam(1).FindValidFireTeams();
			}
			C=Level.ControllerList;
			if (C != nullptr)
			{
				if (C.IsA('HumanController'))
				{
					if (Level.Game.CheatsDisabled() && sINIValue ~= "AGP_GameMultiPlayer bMPCheatsEnabled True")
					{
						HumanController(C).NotifyAdminMessage("The administrator has enabled cheats on this server.");
						HumanController(C).ClientEnableLocalCheats();
					}
					else
					{
						if (! Level.Game.CheatsDisabled() && sINIValue ~= "AGP_GameMultiPlayer bMPCheatsEnabled False")
						{
							HumanController(C).NotifyAdminMessage("The administrator has disabled cheats on this server.");
							HumanController(C).DisableLocalCheats();
						}
					}
					if (! GameReplicationInfo.bForceShadowsOff && sINIValue ~= "GameReplicationInfo bForceShadowsOff True")
					{
						HumanController(C).NotifyAdminMessage("The Administrator has disabled player shadows.");
					}
					else
					{
						if (GameReplicationInfo.bForceShadowsOff && sINIValue ~= "GameReplicationInfo bForceShadowsOff False")
						{
							HumanController(C).NotifyAdminMessage("The Administrator has enabled player shadows.");
						}
					}
					if (bWeaponSlotRulesChanged)
					{
						if (AGP_GameInfo(Level.Game).bOpenAllWeaponClassSlots)
						{
							HumanController(C).NotifyAdminMessage("The Administrator has enabled all weapon slots.");
						}
						else
						{
							HumanController(C).NotifyAdminMessage("The Administrator has restored normal weapon slot rules.");
						}
					}
				}
				C=C.nextController;
			}
			PrivateSet(sINIValue);
	*/

}
void AHumanController::MakeMeAdmin()
{
	//ServerModifyPRI("PlayerReplicationInfo bAdmin true");
}
void AHumanController::CustomCheat(FString sCheat)
{
	//ServerModifyPRI(sCheat);
}
void AHumanController::ChangeAdminPW(FString sNewPW)
{
	//ServerModifyPRI("AccessControl AdminPassword " $ sNewPW);
}
void AHumanController::AddPlayerAdmin(FString sName, FString sPassword)
{
	//ServerModifyPRI("AccessControl aapaPlayerAdmins(0) " $ sName $ "," $ sPassword);
}
void AHumanController::ServerModifyPRI(FString sCommand)
{
	//ServerSetINISetting(sCommand);
}
void AHumanController::ServerRequestINISetting(FString sPanelName, FString sINIVariable)
{
	/*
		local string sINIValue;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			if (PlayerReplicationInfo == nullptr)
			{
				Level.Game.KickByController(this,"CHEATER");
				return;
			}
			if (! PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
			{
				Log("Invalid server setting access");
				return;
			}
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
			{
				if (PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
				{
					if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
					{
						Level.Game.KickByController(this,"CHEATER");
						return;
					}
				}
			}
		}
		if (sINIVariable ~= "AccessControl asTeamPasswords[0]")
		{
			sINIValue=Class'AccessControl'.Default.asTeamPasswords[0];
		}
		else
		{
			if (sINIVariable ~= "AccessControl asTeamPasswords[1]")
			{
				sINIValue=Class'AccessControl'.Default.asTeamPasswords[1];
			}
			else
			{
				if (sINIVariable ~= "AGP_GameTournament asTournamentTeamName[0]")
				{
					sINIValue=Level.Game.TournamentServerINIGetTeamName(0);
				}
				else
				{
					if (sINIVariable ~= "AGP_GameTournament asTournamentTeamName[1]")
					{
						sINIValue=Level.Game.TournamentServerINIGetTeamName(1);
					}
					else
					{
						if (sINIVariable ~= "GameInfo AbsoluteMaxPlayers")
						{
							sINIValue=Level.Game.AbsoluteMaxPlayers;
						}
						else
						{
							sINIValue=ConsoleCommand("get " $ sINIVariable);
						}
					}
				}
			}
		}
		ClientNotifyRequestINISetting(sPanelName,sINIVariable,sINIValue);
	*/
}
void AHumanController::ClientNotifyRequestINISetting(FString sPanelName, FString sINIVariable, FString sINIValue)
{
	/*
		if (guipCommandPost != nullptr)
		{
			guipCommandPost.NotifyCommandPostPage(sPanelName,"INIEntry",sINIVariable,sINIValue);
		}

	*/
}
void AHumanController::ShowAdminCommandPost()
{
	/*
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this,"CHEATER");
			return;
		}
		if (PlayerReplicationInfo.bAdmin)
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu_CommandPost",,"Map","");
		}

	*/
}
void AHumanController::ServerRequestPBSetting(FString sPanelName, FString sPBVariable)
{
	/*
		if (sPBVariable ~= "PBEnabled")
		{
			ClientNotifyRequestINISetting(sPanelName,sPBVariable,"" $ IsPBEnabled());
			return;
		}
	*/
}
void AHumanController::DisplayScore()
{
	ServerDisplayPlayerScore();
}
void AHumanController::ServerDisplayPlayerScore()
{
	//ClientMessage("ROE: " + PlayerReplicationInfo._cumROE);
	//ClientMessage("Kills/Deaths: " + Max(0, PlayerReplicationInfo._cumKills + PlayerReplicationInfo._cumDeaths));
	//ClientMessage("Wins: " + PlayerReplicationInfo._cumWins);
	//ClientMessage("Objectives: " + PlayerReplicationInfo._cumObjectives);
	//ClientMessage("Leadership: " + Max(0, PlayerReplicationInfo._cumLeadership));
	ClientMessage("--------------------------------");
	ClientMessage("Scoring Details");
	//ClientMessage("Current score earned towards the next honor level for this match is: " + PlayerReplicationInfo._cumTotal);
}
void AHumanController::ChangeServerToTournamentMode()
{
}
void AHumanController::ChangeServerToStandardMode()
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this, "CHEATER");
			return;
		}
		if (!PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
		{
			Log("Invalid server setting access");
			return;
		}
		if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			if (PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
			{
				if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
				{
					Level.Game.KickByController(this, "CHEATER");
					return;
				}
			}
		}
	}
	Log("Trying to switch to standard mode");
	PrivateSet("AGP_GameDeathMatch bTournamentMode False");
	Level.ServerTravel("?restart?TM=OFF?GAME=AGP_Gameplay.AGP_GameTeamObjective", false);
	*/
}
void AHumanController::ServerSetTournamentINITeamName(int32 iTeam, FString sTeamName)
{
	/*
	if (PlayerReplicationInfo == nullptr)
	{
		Level.Game.KickByController(this, "CHEATER");
		return;
	}
	Level.Game.TournamentServerINISetTeamName(iTeam, sTeamName);
	Level.Game.SaveConfig();
	*/
}
void AHumanController::ServerUpdateActiveTournamentField(FString sFieldName, FString sValue)
{
}
void AHumanController::ServerSetTournamentINITeamPassword(int32 iTeam, FString sTeamPassword)
{
}
void AHumanController::TournamentCaptainAdminMessage(FString sMsg)
{
	
	FColor Color;
	NotifyAdminMessage(sMsg);
	Color.R = 247;
	Color.G = 151;
	Color.B = 82;
	Color.A = 0;
	//Player.Console.Message(sMsg, 20, Color);
	
}
void AHumanController::TournamentRequestDeadRound()
{
}
void AHumanController::HelpDebug()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	*/

	ClientMessage("");
	ClientMessage("UAVHelp - help with controlling UAV");
	ClientMessage("CallForFireHelp - Help with using mortars");
	ClientMessage("DHHelp - debug helicopter help");
	ClientMessage("DebugMoveToAI <index> - moves to AI");
	ClientMessage("DebugGotoLocation <x> <y> <z> - jumps to specified location");
	ClientMessage("DebugAICombatInfo - dumps some combat info on targeted NPC and adds it to your showdebug info");
	ClientMessage("DebugForceAIAnimState - attempts to override animation state of AI");
	ClientMessage("DebugDumpAIStats - dumps to console current AI settings and spawned counts");
	ClientMessage("DebugDumpServerDynamicActors - dumps all dynamic actors to server log");
	ClientMessage("DebugDumpServerStats - dumps snapshot of server performance stats to server log");
	ClientMessage("DebugToggleDebugLoggingOnTarget <type> - Enables logging for targeted NPC");
	ClientMessage("DebugFocusOnTarget - focuses on NPC being targeted");
	ClientMessage("DebugDisableNPCLogging - disables all NPC logging");
	ClientMessage("DebugServerProfiling - for profiling");
	ClientMessage("----------------------------");
	ClientMessage("Debugging Options:");
	ClientMessage("");
	
}
void AHumanController::HelpPlayerAdmin()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	*/
	ClientMessage("");
	ClientMessage("admin ToggleForceclass - toggles game-wide force-classing on/off");
	ClientMessage("admin score - enable/disable scoreboard");
	ClientMessage("admin adminset [value] - change server settings");
	ClientMessage("admin kick/kickban/ban - kick or manage banned players");
	ClientMessage("admin banlist <starting ban index> - lists bans starting at index specified");
	ClientMessage("admin mute - mute player");
	ClientMessage("admin say - send console message to players");
	ClientMessage("admin Message - send admin message popup to players");
	ClientMessage("admin A_SwitchTeam - change player team");
	ClientMessage("admin switch - change server maps (use ShowMapList to see available maps)");
	ClientMessage("admin spectate - spectate some player");
	ClientMessage("admin forceclass - change player class (use ""*"" for all players)");
	ClientMessage("AdminChangePassword - set admin password");
	
}
void AHumanController::Help()
{
	/*
	ClientMessage("");
	if (GetNetMode() == ENetMode::NM_Standalone || PlayerReplicationInfo != nullptr && PlayerReplicationInfo.bAdmin || Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		ClientMessage("AdminSetNPCToPlayerRatio <n.n> - Sets ratio of AI to players (minimum of 2.0)");
		ClientMessage("AdminSetMaxSoldiers <n> - Sets maximum number of AI Soldiers (minimum of 20)");
		ClientMessage("HelpPlayerAdmin - lists available player admin commands");
	}
	*/
	ClientMessage("CommandCivilian - gives orders to civilian NPCs");
	ClientMessage("ToggleNotificationMessages - Toggles on or off displaying of admin and system popup notification messages");
	ClientMessage("SetConsoleWidth x - sets the percent of the display console expands to");
	ClientMessage("disconnect - disconnect from server");
	ClientMessage("start x.x.x.x - switch to a new server");
	ClientMessage("as player admin (requires server to be configured for this)");
	ClientMessage("start x.x.x.x?PAPassword=<Player Admin Password> - join server ");
	ClientMessage("reconnect - reconnect to this server");
	ClientMessage("quit - exit the game");
	ClientMessage("stat fps - show frame rate");
	ClientMessage("bind <key> <command> - bind a command to a key");
	ClientMessage("DemoRecToggleSound / DemoRecToggleMuzzleFlash - Toggles recording sound and muzzle flash effects during demo recording");
	ClientMessage("ESC - bring up menu");
	ClientMessage("------------------");
	ClientMessage("Common Commands");
	
}
void AHumanController::CallForFireHelp()
{
	
	ClientMessage("CFFEnd - signals end of mission (no repeat possible after this)");
	ClientMessage("CFFRepeat - Request repeat of last fire mission");
	ClientMessage("CFFCheckFire - Request Cease Fire for current fire mission");
	ClientMessage("CFFCancel - Cancels request for fire mission if mission not yet confirmed");
	ClientMessage("CFFFire - Orders execution of fire mission");
	ClientMessage("CFFLeft, CFFRight, CFFReset, CFFAdd, CFFDrop");
	ClientMessage("CFFAdjustFire <Dir> <distance> - Adjusts fire LEFT/RIGHT (direction) or ADD/DROP (for range)");
	ClientMessage("CFFPolarSmoke - With binoculars up and range set via binocular ranging, call for smoke mission");
	ClientMessage("CFFPolarSuppressVehicles - With binoculars up and range set via binocular ranging, call for vehicle suppression mission");
	ClientMessage("CFFPolarSuppressInfantry - With binoculars up and range set via binocular ranging, call for infantry suppression mission");
	ClientMessage("Target types: Infantry, Vehicles    Mission Type: Immediate Smoke (SMOKE)/Immediate Suppression (SUPPRESS)/Training (TRAINING)");
	ClientMessage("CallForFirePolar <Range> <Mission Type> <target type> - initiates call for fire with range in meters, using current direction");
	ClientMessage("CallForFireGrid <grid> <grid> <Mission Type> <target type> - initates call for fire using grid laid on top of map");
	ClientMessage("Fire Support Mission Management.  You must have binoculars to call for support.");
	
}
void AHumanController::FDCOnMap()
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			return true;
		}
	}
	return false;
	*/
}
bool AHumanController::UAVOnMap()
{
	
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return false;
	}
	return false;
	
}
void AHumanController::CFFPolarSuppressInfantry()
{
	//CallForFirePolar(iSpotterPolarRangeSetting, "Suppress", "infantry");
}
void AHumanController::CFFPolarSuppressVehicle()
{
	//CFFPolarSuppressVehicles();
}
void AHumanController::CFFPolarSuppressVehicles()
{
	//CallForFirePolar(iSpotterPolarRangeSetting, "Suppress", "vehicles");
}
void AHumanController::CFFPolarSmoke()
{
	//CallForFirePolar(iSpotterPolarRangeSetting, "Smoke", "infantry");
}
void AHumanController::CallForFirePolar(int32 iDistanceInMeters, FString sMissionType, FString sTargetType)
{
	/*
	local int iDistance;
	local AGP_USMortarTeamFDC agpusmt;
	local AGP_USMortarTeamFDC agpusmtIterator;
	if (!PlayerReplicationInfo.bIsMortarSpotter && GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientMessage("You aren't qualified for the spotter role.");
		return;
	}
	if (GetNetMode() == ENetMode::NM_Standalone && EventLab != nullptr)
	{
		if (bCFFTrainingDisableCFF)
		{
			Log("Training is disabled.");
			return;
		}
		if (bCFFTrainingGridOnly)
		{
			NotifyAdminMessage("You must use the Grid Call For Fire to complete this training.");
			return;
		}
	}
	if (Len(sTargetType) == 0)
	{
		sTargetType = "Infantry";
	}
	Log("Mission type: " $ sMissionType);
	if (Pawn != nullptr && !Pawn.IsA('CROWS_HMMWV') || Pawn.IsA('HMMWV_Passenger'))
	{
		if (Pawn == nullptr || Pawn.Weapon == nullptr || !Pawn.Weapon.IsA('Item_Binoculars'))
		{
			ClientMessage("You must have binoculars or be in the CROWS HMMWV to call in a fire support mission.");
			return;
		}
	}
	iDistance = iDistanceInMeters * 55;
	if (iDistance < 512)
	{
		ClientMessage("Distance too close - that would hurt you!");
		return;
	}
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.bFireMissionInProgress)
			{
				ClientMessage("No fire support assets available.");
				return;
			}
			else
			{
				agpusmt = agpusmtIterator;
			}
	else
	{
	}
		}
	}
	if (agpusmt == nullptr)
	{
		ClientMessage("Command not available");
		return;
	}
	agpusmt.sFOName = agpusmt.sSpotterCallSign;
	Log("Pawn view rotation yaw: " $ Pawn.GetViewRotation().Yaw);
	agpusmt.SetOwner(Pawn);
	agpusmt.rotTargDirection = Pawn.GetViewRotation();
	agpusmt.vSpotterLocation = Pawn.Location;
	agpusmt.fpDistanceToTarget = iDistance;
	agpusmt.sTargetType = sTargetType;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		agpusmt.iTeamID = PlayerReplicationInfo.Team.TeamIndex;
	}
	else
	{
		agpusmt.iTeamID = 0;
	}
	if (bCFFTrainingRoundsOnly)
	{
		sMissionType = "TRAINING";
	}
	agpusmt.StartPolarFireMission(sMissionType, sTargetType);
	*/
}
void AHumanController::CallForFireGrid(int32 iGridX, int32 iGridY, FString sMissionType, FString sTargetType)
{
	/*
	if (!PlayerReplicationInfo.bIsMortarSpotter && GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientMessage("You aren't qualified for the spotter role.");
		return;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		Log("CallForFireGrid during training");
		if (bCFFTrainingDisableCFF)
		{
			Log("CFF disabled during training");
			return;
		}
	}
	if (bCFFTrainingRoundsOnly)
	{
		sMissionType = "TRAINING";
	}
	ServerCallForFireGrid(iGridX - GameReplicationInfo.iSpotterBaseGridX, iGridY - GameReplicationInfo.iSpotterBaseGridY, GameReplicationInfo.iSpotterBaseGridX, GameReplicationInfo.iSpotterBaseGridY, sMissionType, sTargetType);
	*/
}
void AHumanController::RadarMapGridToWorldVector(int32 iGridRow, int32 iGridCol)
{
	/*
	local float fpScale;
	local FVector vTopLeft;
	local FVector vPawnZeroed;
	Log("Grid Col " $ iGridCol $ " Row " $ iGridRow);
	fpScale = Level.RadarMapSize * 2 / 100;
	Log("Scale: " $ fpScale);
	Log("Map Size: " $ Level.RadarMapSize);
	Log("Map Offset X: " $ Level.RadarMapOffset.X $ ", Y: " $ Level.RadarMapOffset.Y);
	vTopLeft.X = Level.RadarMapOffset.X - Level.RadarMapSize;
	vTopLeft.Y = Level.RadarMapOffset.Y - Level.RadarMapSize;
	vTopLeft.Z = 0;
	Log("Map Top-left location X: " $ vTopLeft.X $ ", Y: " $ vTopLeft.Y);
	Log("Grid offset X: " $ iGridCol * fpScale $ " Y: " $ iGridRow * fpScale);
	vTopLeft.X += iGridCol * fpScale;
	vTopLeft.Y += iGridRow * fpScale;
	vTopLeft.Z = 0;
	Log("Calculated UU location X: " $ vTopLeft.X $ ", Y: " $ vTopLeft.Y);
	vPawnZeroed = Pawn.Location;
	vPawnZeroed.Z = 0;
	return vTopLeft;
	*/
}
void AHumanController::ServerCallForFireGrid(int32 iGridX, int32 iGridY, int32 iBaseX, int32 iBaseY, FString sMissionType, FString sTargetType)
{
	/*
	local AGP_USMortarTeamFDC agpusmt;
	local AGP_USMortarTeamFDC agpusmtIterator;
	local FVector vTargetArea;
	vTargetArea = RadarMapGridToWorldVector(iGridX, iGridY);
	vTargetArea.Z = Pawn.Location.Z;
	if (Len(sTargetType) == 0)
	{
		sTargetType = "Infantry";
	}
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.bFireMissionInProgress)
			{
				ClientMessage("No fire support assets available.");
				return;
			}
			else
			{
				agpusmt = agpusmtIterator;
			}
	else
	{
	}
		}
	}
	if (agpusmt == nullptr)
	{
		ClientMessage("Command not available");
		return;
	}
	agpusmt.SetOwner(Pawn);
	agpusmt.sFOName = agpusmt.sSpotterCallSign;
	agpusmt.iGridX = iGridX + iBaseX;
	agpusmt.iGridY = iGridY + iBaseY;
	agpusmt.vTargetArea = vTargetArea;
	agpusmt.vSpotterLocation = Pawn.Location;
	agpusmt.sTargetType = sTargetType;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		agpusmt.iTeamID = PlayerReplicationInfo.Team.TeamIndex;
	}
	else
	{
		agpusmt.iTeamID = 0;
	}
	agpusmt.StartGridFireMission(sMissionType, sTargetType);
	*/
}
void AHumanController::CFFCorrection(float fpDistanceInMeters, FString sMissionType, FString sTargetType)
{
	/*
	local int iDistance;
	local AGP_USMortarTeamFDC agpusmtIterator;
	if (Len(sTargetType) == 0)
	{
		sTargetType = "Enemy Troops";
	}
	else
	{
		sTargetType = "Enemy " $ sTargetType;
	}
	if (sMissionType ~= "SMOKE")
	{
		sMissionType = "Immediate Smoke";
	}
	else
	{
		if (sMissionType ~= "SUPPRESS")
		{
			sMissionType = "Immediate Suppression";
		}
	}
	if (Pawn == nullptr || Pawn.Weapon == nullptr || !Pawn.Weapon.IsA('Item_Binoculars'))
	{
		ClientMessage("You must have binoculars to call in a fire support mission.");
		return;
	}
	iDistance = fpDistanceInMeters * 55;
	if (iDistance < 512)
	{
		ClientMessage("Distance too close - that would hurt you!");
		return;
	}
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
			{
				return;
			}
		}
	}
	*/
}
void AHumanController::CFFFire()
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
			{
				agpusmtIterator.ExecuteAttack();
				return;
			}
		}
	}
	*/
}
void AHumanController::CFFEnd()
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
			{
				agpusmtIterator.EndFireMission();
				return;
			}
		}
	}
	*/
}
void AHumanController::CFFRepeat()
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired >= agpusmtIterator.iMaxRoundsPerMission)
			{
				agpusmtIterator.RepeatMission();
				return;
			}
		}
	}
	*/
}
void AHumanController::CFFLeft()
{
	iSpotterShiftLeftRight--;
}
void AHumanController::CFFRight()
{
	iSpotterShiftLeftRight++;
}
void AHumanController::CFFReset()
{
	iSpotterShiftAddDrop = 0;
	iSpotterShiftLeftRight = 0;
}
void AHumanController::CFFAdd()
{
	iSpotterShiftAddDrop++;
}
void AHumanController::CFFDrop()
{
	iSpotterShiftAddDrop--;
}
void AHumanController::CFFDisplaySpotterTools()
{
	/*
	if (bMortarSpotter && Pawn.Weapon != nullptr && Pawn.Weapon.IsA('Item_Binoculars') && Pawn.Weapon.IsZoomed())
	{
		bCFFShowSpotterToolMenu = !bCFFShowSpotterToolMenu;
		if (bCFFShowSpotterToolMenu)
		{
			LockPlayer(True, true);
			Player.bShowWindowsMouse = true;
		}
		else
		{
			LockPlayer(False, false);
			Player.bShowWindowsMouse = false;
		}
	}
	*/
}
void AHumanController::CFFAdjustFire(FString sDirection, int32 iDistance)
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
			{
				if (sDirection ~= "ADD")
				{
					agpusmtIterator.AdjustFireMissionAim(sDirection, 0, iDistance);
				}
				else
				{
					if (sDirection ~= "DROP")
					{
						agpusmtIterator.AdjustFireMissionAim(sDirection, 0, iDistance * -1);
					}
					else
					{
						if (sDirection ~= "LEFT")
						{
							agpusmtIterator.AdjustFireMissionAim(sDirection, iDistance * -1, 0);
						}
						else
						{
							if (sDirection ~= "RIGHT")
							{
								agpusmtIterator.AdjustFireMissionAim(sDirection, iDistance, 0);
							}
							else
							{
								ClientMessage("That's not a valid Adjust Fire command");
							}
						}
					}
				}
				return;
			}
		}
	}
	*/
}
void AHumanController::CFFCancel()
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
			{
				if (agpusmtIterator.bFireMissionInProgress)
				{
					ClientMessage("Fire support mission already in progress, call ""Cease Fire"" to stop fire support mission");
					return;
				}
				agpusmtIterator.CancelFireMission();
				return;
			}
		}
	}
	*/
}
void AHumanController::CFFCheckFire()
{
	/*
	local AGP_USMortarTeamFDC agpusmtIterator;
	ForEach('AGP_USMortarTeamFDC', agpusmtIterator)
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer && agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex)
		{
		}
		else
		{
			if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
			{
				if (!agpusmtIterator.bFireMissionInProgress)
				{
					ClientMessage("No fire support mission currently firing.");
					return;
				}
				agpusmtIterator.CheckFire();
				return;
			}
		}
	}
	*/
}
void AHumanController::DebugDisableNPCLogging()
{
	/*
	local NPCBaseController npcbcIterator;
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	ForEach AllActors('NPCBaseController', npcbcIterator)
	{
		ClientMessage("Disabling logging on NPC: " $ npcbcIterator);
		npcbcIterator.bDebugPath = false;
		npcbcIterator.bDebugMode = false;
		npcbcIterator.bDebugCombat = false;
	}
	*/
}
void AHumanController::DebugEnableNPCLogging(FString sDebugType, FString sTag)
{
	/*
	local NPCBaseController npcbcIterator;
	local Actor actHit;
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (Len(sDebugType) == 0)
	{
		ClientMessage("If tag left out all NPC's are enabled");
		ClientMessage("Debug types are: Combat, Paths, Standard");
		ClientMessage("Syntax: DebugEnableNPCLogging <Type> [Tag]");
		return;
	}
	actHit = ManualTrace(10000);
	if (actHit != nullptr && actHit.IsA('AGP_Pawn') && AGP_Pawn(actHit).Controller != nullptr && AGP_Pawn(actHit).Controller.IsA('NPCBaseController'))
	{
		ClientMessage("Enabling debugging for targeted NPC: " $ actHit.Tag);
		sTag = actHit.Tag;
	}
	ForEach AllActors('NPCBaseController', npcbcIterator)
	{
		if (Len(sTag) > 0 && sTag != npcbcIterator.Tag)
		{
		}
		else
		{
			ClientMessage("Enabling logging for " $ npcbcIterator);
			if (sDebugType ~= "Paths")
			{
				Log("Paths debugging on for " $ npcbcIterator);
				npcbcIterator.bDebugPath = true;
			}
			if (sDebugType ~= "Standard")
			{
				Log("Standard debugging on for " $ npcbcIterator);
				npcbcIterator.bDebugMode = true;
			}
			if (sDebugType ~= "Combat")
			{
				Log("Combat debugging on for " $ npcbcIterator);
				npcbcIterator.bDebugCombat = true;
			}
		}
	}
	*/
}
void AHumanController::DebugFocusOff()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		ConsoleCommand("focusoff");
	}
	else
	{
		if (DebugGetCheatManager() != nullptr)
		{
			DebugGetCheatManager().FocusOff();
		}
		else
		{
			ClientMessage("Cheat Manager not available for focusoff");
		}
	}
	*/
}
void AHumanController::DebugFocusOnTarget()
{
	/*
	local Actor actHit;
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit = ManualTrace(10000);
	if (actHit == nullptr)
	{
		return;
	}
	if (actHit.IsA('AGP_Pawn'))
	{
		if (DebugGetCheatManager() != nullptr)
		{
			DebugGetCheatManager().FocusOnTargetedPawn(Pawn(actHit));
		}
		else
		{
			ClientMessage("Cheat Manager not available for DebugFocusOnTarget");
		}
	}
	else
	{
		ClientMessage("No pawn found as focus on target");
	}
	*/
}
void AHumanController::DebugToggleDebugLoggingOnTarget(FString sType)
{
	/*
	local Actor actHit;
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit = ManualTrace(10000);
	if (actHit == nullptr)
	{
		return;
	}
	if (actHit.IsA('AGP_Pawn'))
	{
		ClientMessage("Trying to enable """ $ sType $ """ logging for " $ AGP_Pawn(actHit).Controller.Tag);
		DebugEnableNPCLogging(sType, AGP_Pawn(actHit).Controller.Tag);
	}
	else
	{
		ClientMessage("No pawn found for logging toggle");
	}
	*/
}
void AHumanController::DebugCurrentViewTarget()
{
	/*
	ClientMessage("Current view target: " + ViewTarget);
	if (ViewTarget->IsA(APlayerReplicationInfo::StaticClass()))
	{
		ClientMessage("View Target PRI Pawn: " $ PlayerReplicationInfo(ViewTarget).myPawn);
	}
	*/
}
void AHumanController::DebugServerProfiling(FString sProfileCommand)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	Log("PROFILESCRIPT command """ $ sProfileCommand $ """ received.");
	if (sProfileCommand ~= "START" || sProfileCommand ~= "STOP" || sProfileCommand ~= "RESET")
	{
		ConsoleCommand("PROFILESCRIPT " $ sProfileCommand);
		ClientMessage("Profiling command accepted");
	}
	else
	{
		ClientMessage("Profiling generates "".UPROF"" file in System folder.");
		ClientMessage("RESET - reset profiling");
		ClientMessage("STOP - stop profiling");
		ClientMessage("START - start profiling");
		ClientMessage("Invalid syntax: DebugServerProfiling [Cmd]");
	}
	*/
}
void AHumanController::CommandCivilian(FString sCmd)
{
	/*
	local Actor actHit;
	actHit = ManualTrace(1000);
	if (actHit == nullptr)
	{
		return;
	}
	if (actHit.IsA('AGP_Pawn'))
	{
		if (AGP_Pawn(actHit).Controller != nullptr && AGP_Pawn(actHit).Controller.IsA('NPCBaseCivilianController'))
		{
			ClientMessage(NPCBaseCivilianController(AGP_Pawn(actHit).Controller).CommandCivilian(this, sCmd));
		}
	}
	*/
}
void AHumanController::AdminSetNPCToPlayerRatio(float fpRatio)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (fpRatio >= 2)
	{
		AGP_GameInfo(Level.Game).fpMaxNPCToPlayerRatio = fpRatio;
		AGP_GameInfo(Level.Game).SaveConfig();
		ClientMessage("NPC to Player ratio configured at " $ fpRatio);
	}
	else
	{
		ClientMessage("NPC to Player ratio must be at least 1.5 to 1");
	}
	*/
}
void AHumanController::AdminSetMaxSoldiers(int32 iMaxSoldiers)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (iMaxSoldiers >= 20)
	{
		AGP_GameInfo(Level.Game).fpMaxNPCToPlayerRatio = 0;
		AGP_GameInfo(Level.Game).iMaxAINPCsToSpawn = iMaxSoldiers;
		AGP_GameInfo(Level.Game).SaveConfig();
		ClientMessage("NPC to Player ratio reset to zero, Max soldiers set to " $ iMaxSoldiers);
	}
	else
	{
		ClientMessage("Maximum soldiers must be greater than 20");
	}
	*/
}
void AHumanController::DebugDumpAIStats()
{
	/*
	local Controller ctrlIterator;
	local int iLiveNPCs;
	local int iLiveSpotters;
	local int iLiveSoldiers;
	local int iLiveCivilians;
	local int iLiveT62s;
	local int iLiveBMPs;
	local int iLiveBTRs;
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (ctrlIterator.IsA('NPCBasePreCrewedVehicleController'))
		{
			if (NPCBasePreCrewedVehicleController(ctrlIterator).Pawn.IsA('T62A'))
			{
				iLiveT62s++;
			}
			if (NPCBasePreCrewedVehicleController(ctrlIterator).Pawn.IsA('BMP1_APC'))
			{
				iLiveBMPs++;
			}
			if (NPCBasePreCrewedVehicleController(ctrlIterator).Pawn.IsA('BTR80APC'))
			{
				iLiveBTRs++;
			}
		}
		else
		{
			if (ctrlIterator.IsA('NPCBaseController'))
			{
				if (ctrlIterator.Pawn != nullptr && ctrlIterator.Pawn.Health > 0)
				{
					iLiveNPCs++;
					if (ctrlIterator.IsA('NPCMortarSpotterController'))
					{
						iLiveSpotters++;
					}
					else
					{
						if (ctrlIterator.IsA('NPCBaseSoldierController'))
						{
							iLiveSoldiers++;
						}
						else
						{
							if (ctrlIterator.IsA('NPCBaseCivilianController'))
							{
								iLiveCivilians++;
							}
						}
					}
				}
			}
		}
		ctrlIterator = ctrlIterator.nextController;
	}
	ClientMessage("--------------");
	ClientMessage("Live Soldiers: " $ iLiveSoldiers $ "  Live Spotters: " $ iLiveSpotters $ " Live Civs: " $ iLiveCivilians);
	ClientMessage("NPC Spawned, Soldiers: " $ AGP_GameInfo(Level.Game).iNPCsSpawned $ " Spotters: " $ AGP_GameInfo(Level.Game).iNPCSpottersSpawned $ " Civilians: " $ AGP_GameInfo(Level.Game).iCivilianNPCsSpawned);
	ClientMessage("Spawned Vehicles: " $ AGP_GameInfo(Level.Game).iAIVehiclesSpawned $ " BMPs: " $ AGP_GameInfo(Level.Game).iBMPsSpawned $ " BTRs: " $ AGP_GameInfo(Level.Game).iBTRsSpawned $ " T62s: " $ AGP_GameInfo(Level.Game).iT62sSpawned);
	ClientMessage("Max Soldiers: " $ AGP_GameInfo(Level.Game).iMaxAINPCsToSpawn);
	ClientMessage("Max Civilians: " $ AGP_GameInfo(Level.Game).iMaxAICivilianNPCsToSpawn);
	ClientMessage("Max Spotters: " $ AGP_GameInfo(Level.Game).iMaxAISpotterNPCsToSpawn);
	ClientMessage("Max HMMWVs: " $ AGP_GameInfo(Level.Game).iMaxPlayerVehiclesToSpawn);
	ClientMessage("Max BMPs: " $ AGP_GameInfo(Level.Game).iMaxBMPsToSpawn);
	ClientMessage("Max BTRs: " $ AGP_GameInfo(Level.Game).iMaxBTRsToSpawn);
	ClientMessage("Max T62s: " $ AGP_GameInfo(Level.Game).iMaxT62sToSpawn);
	ClientMessage("Max vehicles: " $ AGP_GameInfo(Level.Game).iMaxAIVehiclesToSpawn);
	*/
}
void AHumanController::DebugMoveToAI(FString sIndex)
{
	/*
	local int iCount;
	local int iIndex;
	local Controller ctrlIterator;
	local FVector X;
	local FVector Y;
	local FVector Z;
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (sIndex ~= "Back")
	{
		if (iLastAIViewedIndex > 0)
		{
			iIndex = --iLastAIViewedIndex;
		}
	}
	else
	{
		if (Len(sIndex) == 0)
		{
			iIndex = ++iLastAIViewedIndex;
		}
		else
		{
			iIndex = sIndex;
		}
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (!bGodMode)
	{
		MPCheat_God();
	}
	if (Pawn.bCollideWorld)
	{
		MPCheat_EnterGhostMode();
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr && !Cast<AAGP_HUD>(MyHUD)->bShowCoords)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowCoords = true;
	}
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (ctrlIterator.IsA('NPCBaseController'))
		{
			if (ctrlIterator.Pawn != nullptr && ctrlIterator.Pawn.Health > 0)
			{
				if (iCount++ == iIndex)
				{
					iLastAIViewedIndex = iIndex;
					ClientMessage("Viewing " $ iLastAIViewedIndex $ ": " $ NPCBaseController(ctrlIterator).Pawn.HUDText $ " (" $ ctrlIterator $ "." $ ctrlIterator.Tag $ ")");
					GetAxes(ctrlIterator.Pawn.Rotation, X, Y, Z);
					Pawn.SetLocation(ctrlIterator.Pawn.Location + MakeVect(1, 0, 0) * X * 200);
					Pawn.SetRotation(Normalize(Pawn.Location - ctrlIterator.Pawn.Location));
					return;
				}
			}
		}
		ctrlIterator = ctrlIterator.nextController;
	}
	iLastAIViewedIndex = 0;
	*/
}
void AHumanController::DebugDumpServerDynamicActors()
{
	//ClientMessage("Dumping dynamic actors to log");
	//DumpServerDynamicActors();
}
void AHumanController::DebugDumpServerStats()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	ClientMessage("Setting dump flag");
	DumpServerStats();
	*/
}
void AHumanController::DebugForceAIAnimState()
{
	/*
	local Actor actHit;
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit = ManualTrace(10000);
	if (actHit == nullptr)
	{
		ClientMessage("No NPC hit");
		return;
	}
	if (actHit.IsA('AGP_Pawn'))
	{
		if (AGP_Pawn(actHit).Controller != nullptr && AGP_Pawn(actHit).Controller.IsA('NPCBaseSoldierController'))
		{
			AGP_Pawn(actHit).SetWalking(True);
			AGP_Pawn(actHit).PlayWaiting();
			AGP_Pawn(actHit).ChangeAnimation();
			ClientMessage("Overrode animation state for targeted NPC");
		}
	}
	*/
}
void AHumanController::DebugAICombatInfo(FString sInfoType)
{
	/*
	local Actor actHit;
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit = ManualTrace(10000);
	if (actHit == nullptr)
	{
		if (npcbscDebugging != nullptr)
		{
			npcbscDebugging = None;
			ClientMessage("Disabled NPC debugging information");
		}
		return;
	}
	if (actHit.IsA('AGP_Pawn'))
	{
		if (AGP_Pawn(actHit).Controller != nullptr && AGP_Pawn(actHit).Controller.IsA('NPCBaseSoldierController'))
		{
			npcbscDebugging = NPCBaseSoldierController(AGP_Pawn(actHit).Controller);
			ClientMessage("Target status: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).sTargetingStatus);
			ClientMessage("AICC Last Action: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).sLastCombatAction);
			ClientMessage("AICC Next Action: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).sNextAICCAction);
			ClientMessage("Enemy: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).Enemy);
			ClientMessage("State: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).GetStateName());
			ClientMessage("Last State: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).GetLastStateName());
			ClientMessage("Soldier info: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).Tag);
			ClientMessage("Weapon: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).Pawn.Weapon);
			ClientMessage("Order: " $ NPCBaseSoldierController(AGP_Pawn(actHit).Controller).iNPCCurrentOrders);
			ClientMessage("Movement Anim: " $ AGP_Pawn(actHit).MovementAnims[0]);
			ClientMessage("AnimAction: " $ AGP_Pawn(actHit).AnimAction);
			ClientMessage("Weapon State: " $ AGP_Pawn(actHit).Weapon.GetStateName());
			SetCustomTimer(2, True, 'DebugUpdateNPCDebuggingInfo');
		}
	}
	*/
}
void AHumanController::DebugUpdateNPCDebuggingInfo()
{
	/*
	local string sDebugInfo;
	if (npcbscDebugging != nullptr && npcbscDebugging.Pawn != nullptr)
	{
		if (npcbscDebugging.IsA('NPCMortarSpotterController'))
		{
			sDebugInfo = npcbscDebugging $ "." $ npcbscDebugging.Tag $ " STATE: " $ npcbscDebugging.GetStateName() $ " Anim: " $ npcbscDebugging.Pawn.AnimAction $ " MovementAnims: " $ npcbscDebugging.Pawn.MovementAnims[0] $ " WFM: " $ NPCMortarSpotterController(npcbscDebugging).bWatchingFireMission $ " TLOC: (" $ NPCMortarSpotterController(npcbscDebugging).vCurrentFireMissionLocation.X $ "," $ NPCMortarSpotterController(npcbscDebugging).vCurrentFireMissionLocation.Y $ "," $ NPCMortarSpotterController(npcbscDebugging).vCurrentFireMissionLocation.Z $ ") " $ " PWNSN: " $ NPCMortarSpotterController(npcbscDebugging).pawnLastConsidered $ " TGTD: " $ NPCMortarSpotterController(npcbscDebugging).pawnLastTargeted;
		}
		else
		{
			sDebugInfo = npcbscDebugging $ "." $ npcbscDebugging.Tag $ " in state: " $ npcbscDebugging.GetStateName() $ ", Targeting State: " $ npcbscDebugging.sTargetingStatus $ ", Enemy: " $ npcbscDebugging.Enemy $ ", Last AICC: " $ npcbscDebugging.sLastCombatAction $ ", Next AICC: " $ npcbscDebugging.sNextAICCAction;
		}
		DebugClientUpdateNPCDebuggingInfo(sDebugInfo);
	}
	else
	{
		DebugClientUpdateNPCDebuggingInfo("");
		StopCustomTimer('DebugUpdateNPCDebuggingInfo');
	}
	*/
}
void AHumanController::DebugClientUpdateNPCDebuggingInfo(FString sNewNPCDebuggingInfo)
{
	sNPCDebuggingInfo = sNewNPCDebuggingInfo;
}
void AHumanController::DebugGotoLocation(FString sLocX, FString sLocY, FString sLocZ)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		if (Level.GetTourIsTraining(Level.iTour))
		{
			return;
		}
	}
	if (Len(sLocX) == 0 || Len(sLocY) == 0 || Len(sLocZ) == 0)
	{
		if (!Cast<AAGP_HUD>(MyHUD)->bShowCoords)
		{
			Cast<AAGP_HUD>(MyHUD)->bShowCoords = true;
		}
		ClientMessage("Current location: " $ Pawn.Location);
		ClientMessage("Invalid location entered.  Use syntax: DebugGotoLocation x y z");
		return;
	}
	Log("Setting pawn location to " $ sLocX $ ", " $ sLocY $ ", " $ sLocZ);
	if (Level.Game.CheatsDisabled())
	{
		return;
	}
	if (_CheatMonitor != nullptr)
	{
		_CheatMonitor.Notify();
	}
	if (EventLab != nullptr)
	{
		EventLab.EventLabNotifyCheat();
	}
	if (Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().NotifyCheated();
	}
	if (!bGodMode)
	{
		MPCheat_God();
	}
	if (!IsInState('Flying'))
	{
		MPCheat_EnterGhostMode();
	}
	if (!Cast<AAGP_HUD>(MyHUD)->bShowCoords)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowCoords = true;
	}
	Pawn.SetLocation(MakeVect(sLocX, sLocY, sLocZ));
	*/
}
void AHumanController::ServerRequestStat(FString sStatRequested)
{
	/*
	local string sValue;
	sValue = "" $ AGP_GameInfo(Level.Game).GetStatForPlayer(this, sStatRequested);
	UE_LOG(LogTemp, Warning, TEXT("Retrieved stat " $ sStatRequested $ " value: " $ sValue));
	ClientStatInfo(sStatRequested, sValue);
	*/
}
void AHumanController::ClientStatInfo(FString sStatRequested, FString sStatValue)
{
	/*
	if (guipStats != nullptr)
	{
		guipStats.NotifyStatsPage(sStatRequested, sStatValue);
	}
	*/
}
void AHumanController::DHHelp()
{
	ClientMessage("DHIncreaseRise");
	ClientMessage("DHDecreaseRise");
	ClientMessage("DHResetRise");
	ClientMessage("DHViewHelicopter <tag>");
	ClientMessage("DHViewNormal");
	ClientMessage("DHHover");
	ClientMessage("DHManual");
	ClientMessage("DHForward");
	ClientMessage("DHBackward");
	ClientMessage("DHTestPitch");
	ClientMessage("DHLandHere");
	ClientMessage("DHTakeOff");
	ClientMessage("DHShootDown");
	ClientMessage("DHSetMechanicalFailure <type> <chance> - sets failure of Engine, Rotor, or Cockpit chance (0 - 1.0) in next 2.5 minutes");
	ClientMessage("DHSetFlightSpeed <VeryFast,Fast,Medium,Slow,VerySlow");
	ClientMessage("DHRideHere - attempts to position you in crouched position in helicopter");
	ClientMessage("DHDemoRide - get in and ride blackhawk (if it's landed)");
	ClientMessage("DHVH - view first helicopter");
	ClientMessage("UAVCameraView - puts you in recon camera view of helicopter or UAV");
	ClientMessage("DHNextWaypoint");
}
void AHumanController::DHLandHere()
{
	/*
	local Actor actHeli;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (ViewTarget != nullptr && ViewTarget.IsA('Vehicle'))
	{
		actHeli = ViewTarget;
	}
	else
	{
		actHeli = DHFindViewHelicopter("first");
	}
	if (actHeli != nullptr && actHeli.IsA('Vehicle') && Vehicle(actHeli).Controller.IsA('NPCBaseHelicopterController'))
	{
		NPCBaseHelicopterController(Vehicle(actHeli).Controller).Land(Pawn.Location, this);
		ClientMessage("Heading for landing zone");
	}
	*/
}
void AHumanController::DHNextWaypoint()
{
	/*
	local Actor actHeli;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (ViewTarget != nullptr && ViewTarget.IsA('Vehicle'))
	{
		actHeli = ViewTarget;
	}
	else
	{
		actHeli = DHFindViewHelicopter("first");
	}
	if (actHeli != nullptr && actHeli.IsA('Vehicle') && Vehicle(actHeli).Controller.IsA('NPCBaseHelicopterController'))
	{
		NPCBaseHelicopterController(Vehicle(actHeli).Controller).NextWaypoint();
		ClientMessage("Heading to waypoint set");
	}
	*/
}
void AHumanController::DHPatrol()
{
	/*
	local Actor actHeli;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (ViewTarget != nullptr && ViewTarget.IsA('Vehicle'))
	{
		actHeli = ViewTarget;
	}
	else
	{
		actHeli = DHFindViewHelicopter("first");
	}
	if (actHeli != nullptr && actHeli.IsA('Vehicle') && Vehicle(actHeli).Controller.IsA('NPCBaseHelicopterController'))
	{
		NPCBaseHelicopterController(Vehicle(actHeli).Controller).Patrol();
		ClientMessage("Patrolling");
	}
	*/
}
void AHumanController::DHSetMechanicalFailure(FString sType, float fpChance)
{
	/*
	local Actor actHeli;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (ViewTarget != nullptr && ViewTarget.IsA('Vehicle'))
	{
		actHeli = ViewTarget;
	}
	else
	{
		actHeli = DHFindViewHelicopter("first");
	}
	if (actHeli != nullptr && actHeli.IsA('Vehicle') && Vehicle(actHeli).Controller.IsA('NPCBaseHelicopterController'))
	{
		if (sType ~= "Engine")
		{
			NPCBaseHelicopterController(Vehicle(actHeli).Controller).fpEngineFailureChance = fpChance;
		}
		else
		{
			if (sType ~= "Rotor")
			{
				NPCBaseHelicopterController(Vehicle(actHeli).Controller).fpRotorFailurePossible = fpChance;
			}
			else
			{
				if (sType ~= "Cockpit")
				{
					NPCBaseHelicopterController(Vehicle(actHeli).Controller).fpCockpitFailurePossible = fpChance;
				}
				else
				{
					ClientMessage("Invalid failure type.  Allowed types: Engine, Rotor, Cockpit");
					return;
				}
			}
		}
		ClientMessage("Mechanical failure possibility enabled");
	}
	*/
}
void AHumanController::DHHover()
{
	/*
	local Actor actHeli;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (ViewTarget != nullptr && ViewTarget.IsA('Vehicle'))
	{
		actHeli = ViewTarget;
	}
	else
	{
		actHeli = DHFindViewHelicopter("first");
	}
	if (actHeli != nullptr && actHeli.IsA('Vehicle') && Vehicle(actHeli).Controller.IsA('NPCBaseHelicopterController'))
	{
		NPCBaseHelicopterController(Vehicle(actHeli).Controller).Hover();
		ClientMessage("Hover set");
	}
	*/
}
void AHumanController::DHTakeOff()
{
	/*
	local Actor actHeli;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (ViewTarget != nullptr && ViewTarget.IsA('Vehicle'))
	{
		actHeli = ViewTarget;
	}
	else
	{
		actHeli = DHFindViewHelicopter("first");
	}
	if (actHeli != nullptr && actHeli.IsA('Vehicle') && Vehicle(actHeli).Controller.IsA('NPCBaseHelicopterController'))
	{
		NPCBaseHelicopterController(Vehicle(actHeli).Controller).TakeOff();
		ClientMessage("Hover set");
	}
	*/
}
void AHumanController::DHVH(bool bThirdPersonView)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	/*
	DHViewHelicopter("first", bThirdPersonView);
	*/
}
void AHumanController::UAVCameraView()
{
}
void AHumanController::UAVStart(FString sNPCTag)
{
}
void AHumanController::UAVView(FString sNPCTag, bool bThirdPersonView)
{
}
void AHumanController::UAVFindViewUAV()
{
	//return NULL;
}
void AHumanController::UAVServerHeadForPlayer()
{
}
void AHumanController::UAVServerCircleHere()
{
}
void AHumanController::UAVServerTurnRight()
{
}
void AHumanController::UAVServerTurnLeft()
{
}
void AHumanController::UAVServerClimb()
{
}
void AHumanController::UAVServerDescend()
{
}
void AHumanController::UAVServerSpeedUp()
{
}
void AHumanController::UAVSpawn()
{
}
void AHumanController::UAVLaunch()
{
}
void AHumanController::UAVServerSlowDown()
{
}
void AHumanController::DHViewHelicopter(FString sNPCTag, bool bThirdPersonView)
{
	/*
	local Vehicle vhHelicopter;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	vhHelicopter = DHFindViewHelicopter(sNPCTag);
	if (vhHelicopter != nullptr)
	{
		ClientMessage("Switching view to helicopter " $ vhHelicopter.Tag);
		ClientSetViewTarget2(vhHelicopter);
		if (bThirdPersonView)
		{
			bBehindView = false;
		}
		else
		{
			bBehindView = true;
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->ShowDebug();
		}
	}
	else
	{
		ClientMessage("Unable to find helicopter " $ sNPCTag);
	}
	*/
}
void AHumanController::DHFindViewHelicopter(FString sNPCTag)
{
	/*
	local Controller cIterator;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return nullptr;
	}
	cIterator = Level.ControllerList;
	if (cIterator != nullptr)
	{
		if (cIterator.IsA('NPCBaseHelicopterController'))
		{
			if (cIterator.Pawn != nullptr && cIterator.Pawn.Tag == sNPCTag || sNPCTag ~= "first")
			{
				return Vehicle(cIterator.Pawn);
			}
		}
		cIterator = cIterator.nextController;
	}
	return nullptr;
	*/
}
void AHumanController::DHViewNormal()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	ClientMessage("Restoring view to player controlled pawn");
	if (Pawn != nullptr)
	{
		ClientSetViewTarget2(Pawn);
	}
	*/
}
void AHumanController::ReplaceCommandString(FString Text)
{
	/*
	local int pos1;
	local int pos2;
	local string ActionKey;
	local string TempStr;
	local string FinalStr;
	pos1 = InStr(Text, "<");
	pos2 = InStr(Text, ">");
	if (pos1 < 0 && pos2 < 0)
	{
		return Text;
	}
	if (pos1 >= 0 && pos2 >= 0)
	{
		TempStr = Left(Text, pos1);
		ActionKey = Left(Text, pos2);
		ActionKey = Right(ActionKey, Len(ActionKey) - pos1 + 1);
		TempStr = TempStr $ GetCommandKey(ActionKey);
		Text = Right(Text, Len(Text) - pos2 + 1);
		FinalStr = FinalStr $ TempStr;
		pos1 = InStr(Text, "<");
		pos2 = InStr(Text, ">");
	}
	FinalStr = FinalStr $ Text;
	return FinalStr;
	*/
}
void AHumanController::GetCommandKey(FString cmdname)
{
	/*
	local Console Console;
	local string cmdkeyname;
	local Interactions.EInputKey cmdkey;
	local int Count;
	local string retval;
	Console = Player.Console;
	retval = "<";
	cmdkeyname = "";
	Count = 0;
	if (Console.GetCommandKey(cmdname, cmdkey, cmdkeyname, Count))
	{
		if (Count > 0)
		{
			retval = retval $ " or ";
		}
		retval = retval $ Caps(cmdkeyname);
		Count++;
	}
	if (retval == "")
	{
		return "ERROR!";
	}
	return retval $ ">";
	*/
}
void AHumanController::MaybeDelaySpawn()
{
	/*
	if (AGP_GameInfo(Level.Game).iDelayedRoundStartTimeSeconds > 0 && !Level.bDelayedSpawnNotAllowed)
	{
		ClientGotoState('DelayedStart', 'None');
	}
	*/
}
void AHumanController::MaybeEnterPlayerWalkingState()
{
	/*
	if (GameReplicationInfo.iDelayedStartTimeRemaining <= 0 || Level.bDelayedSpawnNotAllowed)
	{
		GotoState('PlayerWalking', 'None');
	}
	*/
}
void AHumanController::ServerSpamLog()
{
}
void AHumanController::DemoRecToggleSound()
{
	/*
	local Actor A;
	bDemoRecSounds = !bDemoRecSounds;
	ForEach AllActors(Class'Actor', A)
	{
		A.bDemoRecSounds = bDemoRecSounds;
	}
	if (bDemoRecSounds)
	{
		ClientMessage("DemoRec sounds on!");
	}
	else
	{
		ClientMessage("DemoRec sounds off!");
	}
	*/
}
void AHumanController::DemoRecToggleMuzzleFlash()
{
	/*
	local Actor A;
	bDemoRecMuzzleFlash = !bDemoRecMuzzleFlash;
	ForEach AllActors(Class'Actor', A)
	{
		A.bDemoRecMuzzleFlash = bDemoRecMuzzleFlash;
	}
	if (bDemoRecMuzzleFlash)
	{
		ClientMessage("DemoRec muzzle flash on!");
	}
	else
	{
		ClientMessage("DemoRec muzzle flash off!");
	}
	*/
}
void AHumanController::DumpRelevantAI()
{
	ServerDumpRelevantAI();
}
void AHumanController::ServerDumpRelevantAI()
{
	/*
	local Controller ctrlIterator;
	ClientMessage("Dumping net relevant list to server log");
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (NPCBaseController(ctrlIterator) != nullptr)
		{
			Log("Controller " $ ctrlIterator.Tag $ " bNetRelevant: " $ ctrlIterator.Pawn.bNetRelevant);
		}
		ctrlIterator = ctrlIterator.nextController;
	}
	*/
}
void AHumanController::DumpPathList(bool bDumpPaths)
{
	/*
	local NavigationPoint npNavIterator;
	local int iPath;
	local int iCount;
	npNavIterator = Level.NavigationPointList;
	if (npNavIterator != nullptr)
	{
		Log("Nav Point[ " $ iCount ++ $ " ] " $ npNavIterator $ " has these " $ npNavIterator.PathList.Length $ " paths: ");
		if (bDumpPaths)
		{
			for (iPath = 0; iPath < npNavIterator.PathList.Length; iPath++)
			{
				Log("Path[ " $ iPath $ " ] => " $ npNavIterator.PathList[iPath] $ " collision height: " $ npNavIterator.PathList[iPath].CollisionHeight $ " type: " $ npNavIterator.PathList[iPath].reachFlags);
			}
		}
		npNavIterator = npNavIterator.nextNavigationPoint;
	}
	*/
}
void AHumanController::TriggerClientEvent(FName EventName)
{
	//TriggerEvent(EventName, None, None);
}

void AHumanController::StatIncMissionAttempts()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->RoundsStarted;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundStarted();
	After = MyPlayerStats->RoundsStarted;
	UE_LOG(LogTemp, Log, TEXT("MissionAttempts: %d %d"), Before, After);
}

void AHumanController::StatIncMissionFailures()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->RoundsLost;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundLost();
	After = MyPlayerStats->RoundsLost;
	UE_LOG(LogTemp, Log, TEXT("RoundsLost: %d %d"), Before, After);
}

void AHumanController::StatIncMissionSuccesses()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->RoundsWon;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundWon();
	After = MyPlayerStats->RoundsWon;
	UE_LOG(LogTemp, Log, TEXT("RoundsWon: %d %d"), Before, After);
}

void AHumanController::StatIncObjectives()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->CapturedObjective;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CapturedObjective();
	After = MyPlayerStats->CapturedObjective;
	UE_LOG(LogTemp, Log, TEXT("CapturedObjective: %d %d"), Before, After);
}

void AHumanController::StatMissionFailureTime(int32 Time)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionFailureTime;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSMissionProgressTime = Time;
	After = MyPlayerStats->iESSMissionFailureTime;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionFailureTime: %d %d"), Before, After);
}

void AHumanController::StatMissionSuccessTime(int32 Time)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionSuccessTime;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSMissionSuccessTime = Time;
	After = MyPlayerStats->iESSMissionSuccessTime;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionSuccessTime: %d %d"), Before, After);
}

void AHumanController::StatMissionProgressTime(int32 Time)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->TimePlayed;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->TimePlayed = Time;
	After = MyPlayerStats->TimePlayed;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionProgressTime: %d %d"), Before, After);
}

void AHumanController::StatMissionTotalPlayers(int32 TotalPlayers)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionTotalPlayers;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundTotalPlayers(TotalPlayers);
	After = MyPlayerStats->iESSMissionTotalPlayers;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionTotalPlayers: %d %d"), Before, After);
}

void AHumanController::StatMissionPlayersSurviving(int32 PlayersSurviving)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionSurvivingPlayers;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundPlayersSurviving(PlayersSurviving);
	After = MyPlayerStats->iESSMissionSurvivingPlayers;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionSurvivingPlayers: %d %d"), Before, After);
}

void AHumanController::StatIncObjectReported()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectDiscovered;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectDiscovered(Blank);
	After = MyPlayerStats->iESSObjectDiscovered;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectDiscovered: %d %d"), Before, After);
}

void AHumanController::StatIncObjectExaminedByOtherPlayer()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectExaminedByOtherPlayer;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectExaminedByOtherPlayer();
	After = MyPlayerStats->iESSObjectExaminedByOtherPlayer;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectExaminedByOtherPlayer: %d %d"), Before, After);
}

void AHumanController::StatIncObjectDiscoveryRadioed()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectDiscoveryRadioed;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectDiscoveryRadioed();
	After = MyPlayerStats->iESSObjectDiscoveryRadioed;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectDiscoveryRadioed: %d %d"), Before, After);
}

void AHumanController::StatIncNoRadioExaminedObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSNoRadioExaminedObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSNoRadioExaminedObject();
	After = MyPlayerStats->iESSNoRadioExaminedObject;
	UE_LOG(LogTemp, Log, TEXT("iESSNoRadioExaminedObject: %d %d"), Before, After);
}

void AHumanController::StatIncPostRadioExaminedObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPostRadioExaminedObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSPostRadioExaminedObject();
	After = MyPlayerStats->iESSPostRadioExaminedObject;
	UE_LOG(LogTemp, Log, TEXT("iESSPostRadioExaminedObject: %d %d"), Before, After);
}

void AHumanController::StatIncPostRadioLinkedObjectTaken()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPostRadioLinkedObjectTaken;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSPostRadioLinkedObjectTaken();
	After = MyPlayerStats->iESSPostRadioLinkedObjectTaken;
	UE_LOG(LogTemp, Log, TEXT("iESSPostRadioLinkedObjectTaken: %d %d"), Before, After);
}

void AHumanController::StatIncNoRadioLinkedObjectTaken()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSNoRadioLinkedObjectTaken;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSNoRadioLinkedObjectTaken();
	After = MyPlayerStats->iESSNoRadioLinkedObjectTaken;
	UE_LOG(LogTemp, Log, TEXT("iESSNoRadioLinkedObjectTaken: %d %d"), Before, After);
}

void AHumanController::StatIncObjectReportable()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectAvailable;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectAvailable();
	After = MyPlayerStats->iESSObjectAvailable;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectAvailable: %d %d"), Before, After);
}

void AHumanController::StatIncLethalObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportedLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportedLethal();
	After = MyPlayerStats->iESSObjectReportedLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportedLethal: %d %d"), Before, After);
}

void AHumanController::StatIncNonLethalObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportedNonLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportedNonLethal();
	After = MyPlayerStats->iESSObjectReportedNonLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportedNonLethal: %d %d"), Before, After);
}

void AHumanController::StatReportableLethalObjects(int32 NumObjects)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportableLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportableLethal(NumObjects);
	After = MyPlayerStats->iESSObjectReportableLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportableLethal: %d %d"), Before, After);
}

void AHumanController::StatReportableNonLethalObjects(int32 NumObjects)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportableNonLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportableNonLethal(NumObjects);
	After = MyPlayerStats->iESSObjectReportableNonLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportableNonLethal: %d %d"), Before, After);
}

void AHumanController::StatListUnreportedLocations(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectUnreportedLocations;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSObjectUnreportedLocations = List;
	After = MyPlayerStats->iESSObjectUnreportedLocations;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectUnreportedLocations: %s %s"), *Before, *After);
}

void AHumanController::StatIncObjectReportingErrors()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportingErrors;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportingErrors();
	After = MyPlayerStats->iESSObjectReportingErrors;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportingErrors: %d %d"), Before, After);
}

void AHumanController::StatIncObjectUnnecessaryUse()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectUnnecessaryUse;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectUnnecessaryUse();
	After = MyPlayerStats->iESSObjectUnnecessaryUse;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectUnnecessaryUse: %d %d"), Before, After);
}

void AHumanController::StatListObjectDistribution(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectDistribution;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSObjectDistribution = List;
	After = MyPlayerStats->iESSObjectDistribution;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectDistribution: %s %s"), *Before, *After);
}
void AHumanController::StatIncShotsFired()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->ShotsFiredAstRifle;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ShotFiredAssaultRifle();
	After = MyPlayerStats->ShotsFiredAstRifle;
	UE_LOG(LogTemp, Log, TEXT("ShotsFiredAstRifle: %d %d"), Before, After);
}
void AHumanController::StatIncShotsHit()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->HitsAstRifle;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ShotHitAssaultRifle();
	After = MyPlayerStats->HitsAstRifle;
	UE_LOG(LogTemp, Log, TEXT("HitsAstRifle: %d %d"), Before, After);
}
void AHumanController::StatIncHeadshots()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatHeadshots;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatHeadshots();
	After = MyPlayerStats->iESSCombatHeadshots;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatHeadshots: %d %d"), Before, After);
}

void AHumanController::StatTotalDamage(int32 NewDamage)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatTotalDamage;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatTotalDamage(NewDamage);
	After = MyPlayerStats->iESSCombatTotalDamage;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatTotalDamage: %d %d"), Before, After);
}

void AHumanController::StatIncDamageInstances()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatDamageCount;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatDamageCount();
	After = MyPlayerStats->iESSCombatDamageCount;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatDamageCount: %d %d"), Before, After);
}

void AHumanController::StatEnemyContactTime(float Seconds)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatEnemyContactTime;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatEnemyContactTime(Seconds);
	After = MyPlayerStats->iESSCombatEnemyContactTime;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatEnemyContactTime: %d %d"), Before, After);
}

void AHumanController::StatSurvivingAI(int32 NumAIs)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatSurvivingAI;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatSurvivingAI(NumAIs);
	After = MyPlayerStats->iESSCombatSurvivingAI;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatSurvivingAI: %d %d"), Before, After);
}

void AHumanController::StatIncTotalDeaths()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->Deaths;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_Death(Blank);
	After = MyPlayerStats->Deaths;
	UE_LOG(LogTemp,Log, TEXT("Deaths: %d %d"), Before, After);
}

void AHumanController::StatIncDeathByAI()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalDeathsByAI;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalDeathsByAI();
	After = MyPlayerStats->iESSPlayerTotalDeathsByAI;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalDeathsByAI: %d %d"), Before, After);
}

void AHumanController::StatIncDeathByFriendlyFire()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalDeathsByFriendlyFire;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalDeathsByFriendlyFire();
	After = MyPlayerStats->iESSPlayerTotalDeathsByFriendlyFire;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalDeathsByFriendlyFire: %d %d"), Before, After);
}

void AHumanController::StatIncDeathByObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalDeathsByObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalDeathsByObject();
	After = MyPlayerStats->iESSPlayerTotalDeathsByObject;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalDeathsByObject: %d %d"), Before, After);
}

void AHumanController::StatListDeathLocations(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerDeathLocation;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSPlayerDeathLocation = List;
	After = MyPlayerStats->iESSPlayerDeathLocation;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerDeathLocation: %s %s"), *Before, *After);
}

void AHumanController::StatLifeDuration(int32 Duration)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->TimeAlive;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->TimeAlive = Duration;
	After = MyPlayerStats->TimeAlive;
	UE_LOG(LogTemp, Log, TEXT("TimeAlive: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuries()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuries;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuries(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuries;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuries: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuriesByAI()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuriesByAI;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuriesByAI(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuriesByAI;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuriesByAI: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuriesByFriendlyFire()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuriesFriendlyFire;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuriesByFriendlyFire(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuriesFriendlyFire;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuriesFriendlyFire: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuriesByObject()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuriesByObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuriesByObject(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuriesByObject;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuriesByObject: %d %d"), Before, After);
}

void AHumanController::StatListInjuryLocations(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerInjuryLocation;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSPlayerInjuryLocation = List;
	After = MyPlayerStats->iESSPlayerInjuryLocation;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerInjuryLocation: %s %s"), *Before, *After);
}

void AHumanController::StatIncFriendlyFire()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROEFriendlyFireHits;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROEFriendlyFireHits();
	After = MyPlayerStats->iESSROEFriendlyFireHits;
	UE_LOG(LogTemp, Log, TEXT("iESSROEFriendlyFireHits: %d %d"), Before, After);
}

void AHumanController::StatIncFriendlyFireDeaths()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROEFriendlyFireDeaths;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROEFriendlyFireDeaths();
	After = MyPlayerStats->iESSROEFriendlyFireDeaths;
	UE_LOG(LogTemp, Log, TEXT("iESSROEFriendlyFireDeaths: %d %d"), Before, After);
}

void AHumanController::StatIncCivilianHits()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROECivilianHits;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROECivilianHits();
	After = MyPlayerStats->iESSROECivilianHits;
	UE_LOG(LogTemp, Log, TEXT("iESSROECivilianHits: %d %d"), Before, After);
}

void AHumanController::StatIncCivilianDeaths()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROECivilianDeaths;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROECivilianDeaths();
	After = MyPlayerStats->iESSROECivilianDeaths;
	UE_LOG(LogTemp, Log, TEXT("iESSROECivilianDeaths: %d %d"), Before, After);
}

void AHumanController::StatIncCivilianDeathsByIED()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROECivilianDeathsByIED;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROECivilianDeathsByIED();
	After = MyPlayerStats->iESSROECivilianDeathsByIED;
	UE_LOG(LogTemp, Log, TEXT("iESSROECivilianDeathsByIED: %d %d"), Before, After);
}

void AHumanController::LogES2Stats()
{
	StatIncMissionAttempts();
	StatIncMissionFailures();
	StatIncMissionSuccesses();
	StatIncObjectives();
	StatMissionFailureTime(5);
	StatMissionSuccessTime(5);
	StatMissionProgressTime(5);
	StatMissionTotalPlayers(5);
	StatMissionPlayersSurviving(5);
	StatIncObjectReported();
	StatIncObjectExaminedByOtherPlayer();
	StatIncObjectDiscoveryRadioed();
	StatIncNoRadioExaminedObject();
	StatIncPostRadioExaminedObject();
	StatIncPostRadioLinkedObjectTaken();
	StatIncNoRadioLinkedObjectTaken();
	StatIncObjectReportable();
	StatIncLethalObject();
	StatIncNonLethalObject();
	StatReportableLethalObjects(5);
	StatReportableNonLethalObjects(5);
	StatListUnreportedLocations("1 2 3");
	StatIncObjectReportingErrors();
	StatIncObjectUnnecessaryUse();
	StatListObjectDistribution("1 2 3");
	StatIncShotsFired();
	StatIncShotsHit();
	StatIncHeadshots();
	StatTotalDamage(5);
	StatIncDamageInstances();
	StatEnemyContactTime(9.9);
	StatSurvivingAI(5);
	StatIncTotalDeaths();
	StatIncDeathByAI();
	StatIncDeathByFriendlyFire();
	StatIncDeathByObject();
	StatListDeathLocations("1 2 3");
	StatLifeDuration(5);
	StatIncTotalInjuries();
	StatIncTotalInjuriesByAI();
	StatIncTotalInjuriesByFriendlyFire();
	StatIncTotalInjuriesByObject();
	StatListInjuryLocations("1 2 3");
	StatIncFriendlyFire();
	StatIncFriendlyFireDeaths();
	StatIncCivilianHits();
	StatIncCivilianDeaths();
	StatIncCivilianDeathsByIED();
}


void AHumanController::ClientCloseMenu(bool bCloseAll, bool bCancel)
{
	/*
	if (bDemoOwner)
	{
		return;
	}
	if (Player != nullptr)
	{
		if (bCloseAll)
		{
			Player.GUIController.CloseAll(bCancel, true);
		}
		else
		{
			Player.GUIController.CloseMenu(bCancel);
		}
	}
	*/
}


//From Controller:
int32 AHumanController::GetTeamNum()
{
	if (PlayerReplicationInfo == nullptr || PlayerReplicationInfo->Team == nullptr)
	{
		return 255;
	}
	return PlayerReplicationInfo->Team->TeamIndex;
}

void AHumanController::SwitchToBestWeapon()
{
	//float rating;
	if (Cast<AAGP_Pawn>(GetPawn()) == nullptr || Cast<AAGP_Pawn>(GetPawn())->Inventory == nullptr)
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->PendingWeapon == nullptr || Cast<AaAIController>(this) != nullptr)
	{
		//Cast<AAGP_Pawn>(GetPawn())->PendingWeapon = Cast<AAGP_Pawn>(GetPawn())->Inventory->RecommendWeapon(rating);
		if (Cast<AAGP_Pawn>(GetPawn())->PendingWeapon == Cast<AAGP_Pawn>(GetPawn())->Weapon)
		{
			Cast<AAGP_Pawn>(GetPawn())->PendingWeapon = nullptr;
		}
		if (Cast<AAGP_Pawn>(GetPawn())->PendingWeapon == nullptr)
		{
			return;
		}
	}
	//StopFiring();
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon == nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->ChangedWeapon();
	}
	else
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon != Cast<AAGP_Pawn>(GetPawn())->PendingWeapon)
		{
			Cast<AAGP_Pawn>(GetPawn())->Weapon->PutDown();
		}
	}
}
void AHumanController::ClientSwitchToBestWeapon()
{
	SwitchToBestWeapon();
}
void AHumanController::ClientSetWeapon(AWeapon* WeaponClass)
{
	/*
	local Inventory Inv;
	local int Count;
	Inv = Pawn.Inventory;
	if (Inv != nullptr)
	{
		Count++;
		if (Count > 1000)
		{
			Return;
		}
		if (!ClassIsChildOf(Inv.Class, WeaponClass))
		{
		}
		if (Pawn.Weapon == nullptr)
		{
			Pawn.PendingWeapon = Weapon(Inv);
			Pawn.ChangedWeapon();
		}
		else
		{
			if (Pawn.Weapon != Weapon(Inv))
			{
				Pawn.PendingWeapon = Weapon(Inv);
				Pawn.Weapon.PutDown();
			}
		}
		Return;
		Inv = Inv.Inventory;
	}
	*/
}


void AHumanController::WaitForMover(AMover* M)
{
}

//From PlayerController
void AHumanController::ClientSetScoreMode(bool bAllowsLocalScore)
{
	bAllowScoreShown = bAllowsLocalScore;
}

bool AHumanController::GetMilesOnly()
{
	return false;
}

void AHumanController::AddMBSAttributes(TArray<FKeyValuePair> &Attributes)
{
	/*
	local STS2_PlayerStatsInfo MyPlayerStatsInfo;
	local int ShotsTotal;
	local int HitsTotal;
	if (Level.Game.Stats != nullptr && PlayerStatsIndex >= 0)
	{
		MyPlayerStatsInfo = STS2_PlayerStatsInfo(Level.Game.Stats.PlayerStats[PlayerStatsIndex]);
		ShotsTotal = MyPlayerStatsInfo.ShotsFiredGrenade + MyPlayerStatsInfo.ShotsFiredAstRifle + MyPlayerStatsInfo.ShotsFiredPistol + MyPlayerStatsInfo.ShotsFiredMG + MyPlayerStatsInfo.ShotsFiredRocket + MyPlayerStatsInfo.ShotsFiredSprRifle;
		HitsTotal = MyPlayerStatsInfo.HitsGrenade + MyPlayerStatsInfo.HitsAstRifle + MyPlayerStatsInfo.HitsPistol + MyPlayerStatsInfo.HitsMG + MyPlayerStatsInfo.HitsRocket + MyPlayerStatsInfo.HitsSprRifle;
	}
	AddMBSAttributes(Attributes);
	Class'DBMBS'.AddAttribute(Attributes, "spectator", Class'DBMBS'.BoolToIntString(PlayerReplicationInfo.bOnlySpectator));
	Class'DBMBS'.AddAttribute(Attributes, "honor", PlayerReplicationInfo.GetHonor());
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Class'DBMBS'.AddAttribute(Attributes, "class", Cast<AAGP_Pawn>(GetPawn()).TeamClass.GetClassID());
		Class'DBMBS'.AddAttribute(Attributes, "role", Cast<AAGP_Pawn>(GetPawn()).TeamRole);
		if (Pawn.Weapon != nullptr)
		{
			Class'DBMBS'.AddAttribute(Attributes, "currentWeapon", Pawn.Weapon.ItemName);
		}
	}
	Class'DBMBS'.AddAttribute(Attributes, "scoreTotal", PlayerReplicationInfo.Score_Total);
	Class'DBMBS'.AddAttribute(Attributes, "scoreLeadership", PlayerReplicationInfo.Score_Leadership);
	Class'DBMBS'.AddAttribute(Attributes, "scoreObjectives", PlayerReplicationInfo.Score_Objectives);
	Class'DBMBS'.AddAttribute(Attributes, "scoreWins", PlayerReplicationInfo.Score_Wins);
	Class'DBMBS'.AddAttribute(Attributes, "scoreROE", PlayerReplicationInfo.Score_ROE);
	Class'DBMBS'.AddAttribute(Attributes, "scoreDeaths", PlayerReplicationInfo.Score_Deaths);
	Class'DBMBS'.AddAttribute(Attributes, "scoreKills", PlayerReplicationInfo.Score_Kills);
	Class'DBMBS'.AddAttribute(Attributes, "shotsFired", ShotsTotal);
	Class'DBMBS'.AddAttribute(Attributes, "shotsHit", HitsTotal);
	Class'DBMBS'.AddAttribute(Attributes, "team", PlayerReplicationInfo.Team.GetHumanReadableName());
	Class'DBMBS'.AddAttribute(Attributes, "timePlayed", PlayerReplicationInfo.GetPlayTime());
	Class'DBMBS'.AddAttribute(Attributes, "keyboardLocale", SystemLanguage);
	*/
}

void AHumanController::ServerMissionCompleteAuthorizeComplete(int32 Code, FAuthJacket Jacket)
{
	//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerMissionCompleteAuthorizeComplete for " $ UserName $ " = " @ Code @ AuthJacketToString(Jacket)));
	switch(Code)
	{
		case 1:
			//SetFromAuthJacket(Jacket);
			//VerifyJacket();
			//SendAuthJacketToClient(Jacket);
			return;
		case -1:
			ClientMessage(WrongUserPassword);
			break;
		case -2:
			ClientMessage(NoUserRecord);
			break;
		case -3:
			ClientMessage(UserIsBanned);
			break;
		case -4:
			ClientMessage(ResponseTimeOut);
			break;
		case -5:
			ClientMessage(ServerNotRegistered);
			break;
		case -6:
			ClientMessage(BetaServer);
			break;
		case -7:
			//ClientSetPMessage(0);
			break;
		case -8:
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerMissionCompleteAuthorizeComplete AuthServer says we tried to set honor to 0!!!"));
			break;
		default:
			ClientMessage("Unable to record your mission completion (Mission is probably not in auth database yet)");
			break;
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController:ServerMissionCompleteAuthorizeComplete - Done! for %s"), *UserName);
}


void AHumanController::AuthGetJacketCallback(int32 ResultCode, FAuthPersonnelJacket Jacket)
{
	if (ResultCode > 0)
	{
		UserAuthID = Jacket.UserID;
		VerifyJacket();
		SaveJacket();
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->RefreshTourMissionDisplays();
		}
		SetLoginStatus(2, "Transmission Completed", "Click to return to the main menu.");
	}
	else
	{
		//SetLoginStatus(ResultCode, AuthErrorMessage1, AuthErrorMessage2);
	}
}

void AHumanController::CopyAuthExtraMissionDataToAdapter(AMissionCompleteRequestAdapter* Adapter)
{
	int32 ii;
	for (ii = 0; ii < iAuthMissionDataFields; ii++)
	{
		Adapter->AddExtraMissionData(asAuthMissionData[ii]);
	}
}

void AHumanController::TournamentServerCaptainLockWeaponClasses(AAA2_PlayerState* PRI, bool fLock)
{
	//GameReplicationInfo.Teams[PRI.Team.TeamIndex].bTournamentTeamRosterLocked = fLock;
}


void AHumanController::TournamentRequestTeamCaptain(AAA2_PlayerState* PRI)
{
	/*
	local Controller ctrlrScan;
	local string sResponse;
	if (GameReplicationInfo.bTournamentTeamCaptainsAllowed == false)
	{
		ClientMessage("Team Captains are not allowed in this tournament.");
		Return;
	}
	if (PRI.Team.TeamIndex == 255)
	{
		ClientMessage("You must join a team first.");
		Return;
	}
	if (PRI.bTournamentTeamCaptain)
	{
		PRI.bTournamentTeamCaptain = false;
		GameReplicationInfo.Teams[PRI.Team.TeamIndex].bTournamentTeamCaptainSelected = false;
		GameReplicationInfo.Teams[PRI.Team.TeamIndex].bTournamentTeamRosterLocked = false;
		sResponse = PRI.PlayerName $ " is no longer " $ GameReplicationInfo.asTournamentTeamName[PRI.Team.TeamIndex] $ "'s team captain.";
		ctrlrScan = Level.ControllerList;
		if (ctrlrScan != nullptr)
		{
			if (ctrlrScan.IsA('HumanController'))
			{
				HumanController(ctrlrScan).TeamMessage(None, sResponse, 'TMStatus');
				if (ctrlrScan.PlayerReplicationInfo.Team.TeamIndex == PlayerReplicationInfo.Team.TeamIndex)
				{
					if (HumanController(ctrlrScan).MyHUD != nullptr)
					{
						AGP_HUD(HumanController(ctrlrScan).MyHUD).TournamentNotifyNewTeamCaptain();
					}
				}
			}
			ctrlrScan = ctrlrScan.nextController;
		}
		Return;
	}
	ctrlrScan = Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		if (ctrlrScan.IsA('HumanController'))
		{
			if (ctrlrScan.PlayerReplicationInfo.Team.TeamIndex == PRI.Team.TeamIndex)
			{
				if (ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					TeamMessage(None, "" $ ctrlrScan.PlayerReplicationInfo.PlayerName $ " is already team captain.", 'TMCenter');
					Return;
				}
			}
		}
		ctrlrScan = ctrlrScan.nextController;
	}
	PRI.bTournamentTeamCaptain = true;
	GameReplicationInfo.Teams[PRI.Team.TeamIndex].bTournamentTeamCaptainSelected = true;
	sResponse = PRI.PlayerName $ " is now ";
	if (GameReplicationInfo.asTournamentTeamName[PRI.Team.TeamIndex] != "")
	{
		sResponse = sResponse $ GameReplicationInfo.asTournamentTeamName[PRI.Team.TeamIndex];
	}
	else
	{
		sResponse = sResponse $ Level.TeamName[PRI.Team.TeamIndex];
	}
	sResponse = sResponse $ "'s team captain.";
	ctrlrScan = Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		if (ctrlrScan.IsA('HumanController'))
		{
			HumanController(ctrlrScan).TeamMessage(None, sResponse, 'TMStatus');
			if (ctrlrScan.PlayerReplicationInfo.Team.TeamIndex == PlayerReplicationInfo.Team.TeamIndex)
			{
				HumanController(ctrlrScan).TournamentCaptainAdminMessage(sResponse);
				HumanController(ctrlrScan).TournamentNotifyNewTeamCaptain();
			}
		}
		ctrlrScan = ctrlrScan.nextController;
	}
	*/
}



void AHumanController::TournamentServerRequestTeamCaptain(AAA2_PlayerState* PRI)
{
}


void AHumanController::TournamentServerAssignClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlot)
{
	Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentAssignClass(PRI, iUnitID, iSlot);
}
void AHumanController::TournamentServerRemoveClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlot)
{
}
void AHumanController::TournamentServerAdminAssignPlayerToTeam(int32 iTeamIndex, AAA2_PlayerState* PRI)
{
	/*
	local bool bResult;
	local Controller ctrlrScan;
	local HumanController hcPlayerToAssign;
	if (Level.Game.TournamentGetTeam(iTeamIndex).Size > Level.Game.TournamentGetMaxTeamSize())
	{
		Return;
	}
	ctrlrScan = Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		if (PlayerController(ctrlrScan) != nullptr && PlayerController(ctrlrScan).PlayerReplicationInfo == PRI)
		{
			hcPlayerToAssign = HumanController(ctrlrScan);
		}
		else
		{
			ctrlrScan = ctrlrScan.nextController;
		}
	}
	if (hcPlayerToAssign == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("TournamentServerAdminAssignPlayerToTeam() Couldn't find player's controller"));
		Return;
	}
	bResult = Level.Game.TournamentJoinTeam(hcPlayerToAssign, iTeamIndex, TournamentGetTeamPasswordFor(iTeamIndex));
	hcPlayerToAssign.TournamentNotifyPlayerJoinedTeam(iTeamIndex, bResult, true);
	*/
}

/*
* Already exists in PlayerController with different def
void AHumanController::PreClientTravel()
{
	//UE_LOG(LogTemp, Warning, TEXT("HumanController::PreClientTravel() entered"));
	//Super::PreClientTravel();
}
*/

void AHumanController::ServerSendClientNotifyAdminMessage(AAA2_PlayerState* priPlayer, FString sMsg)
{
	/*
	if (GetPlayerFromID(priPlayer->PlayerID) != nullptr)
	{
		Cast<AHumanController>(GetPlayerFromID(priPlayer->PlayerID))->ClientNotifyAdminMessage(sMsg);
	}
	*/
}

void AHumanController::TeamMessage(AAA2_PlayerState* PRI, FString S, FName Type)
{
	/*
	local string ConsoleString;
	local Object.Color Color;
	local string sCleanedPlayerName;
	S = SubstituteKeyNames(S);
	S = ApplyFilters(S);
	UE_LOG(LogTemp, Warning, TEXT("TeamMessage received: " $ S));
	if (AllowTextToSpeech(PRI, Type))
	{
		TextToSpeech(S, TextToSpeechVoiceVolume);
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		ConsoleString = "";
		UE_LOG(LogTemp, Warning, TEXT("HumanController::TeamMessage() - Teammessage with type " $ Type $ ": " $ S));
		if (PRI != nullptr)
		{
			if (Type != 'Event' || Type == 'None')
			{
				UE_LOG(LogTemp, Warning, TEXT("HumanController::TeamMessage() - Teammessage with PRI " $ PRI $ " playername " $ PRI.PlayerName $ " string " $ S $ " type " $ Type));
				sCleanedPlayerName = ApplyFilters(PRI.PlayerName);
				if (PRI.PlayerName ~= sCleanedPlayerName)
				{
					ConsoleString = "" $ PRI.PlayerName;
				}
				else
				{
					ConsoleString = "[" $ sCleanedPlayerName $ "]";
				}
				UE_LOG(LogTemp, Warning, TEXT("HumanController::TeamMessage(" $ PRI $ ", " $ S $ ", " $ Type $ ") - " $ PRI.bAdmin));
				if (PRI.bAdmin)
				{
					Color.R = 0;
					Color.G = 0;
					Color.B = 180;
					Color.A = 255;
					ConsoleString = "[Admin]" @ ConsoleString;
				}
				else
				{
					if (PlayerReplicationInfo.Team.TeamIndex == PRI.Team.TeamIndex)
					{
						Color.R = 0;
						Color.G = 0;
						Color.B = 180;
						Color.A = 255;
						ConsoleString = "[US Army]" @ ConsoleString;
					}
					else
					{
						Color.R = 180;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = "[Enemy]" @ ConsoleString;
					}
				}
			}
			switch(Type)
			{
					case 'AIKiller':
						Color.R = 0;
						Color.G = 0;
						Color.B = 180;
						Color.A = 255;
						break;
					case 'AIKilled':
						Color.R = 255;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						break;
					case 'TMCenter':
					case 'TMStatus':
						Color.R = 255;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = "";
						break;
					case 'AdminSay':
						Color.R = 255;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "ADMIN MESSAGE: ";
						break;
					case 'CommandChat':
						Color.R = 82;
						Color.G = 82;
						Color.B = 159;
						Color.A = 0;
						ConsoleString = ConsoleString @ "COMMAND MESSAGE: ";
						break;
					case 'Say':
					case 'Global':
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						ConsoleString = ConsoleString @ "messaged: ";
						break;
					case 'TeamSay':
						Color.R = 0;
						Color.G = 180;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "team messaged: ";
						break;
					case 'Whisper':
						Color.R = 0;
						Color.G = 180;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "whispered: ";
						break;
					case 'shout':
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						ConsoleString = ConsoleString @ "shouted: ";
						S = Caps(S);
						break;
					case 'Radio':
					case 'Squad':
						Color.R = 0;
						Color.G = 180;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "radioed: ";
						break;
					case 'ReportIn':
						Color.R = 0;
						Color.G = 200;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "reporting in: ";
						break;
					case 'cheat':
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						ConsoleString = ConsoleString @ "cheated: ";
						break;
					case 'ReportESSObjective':
						Color.R = 0;
						Color.G = 200;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "reporting: ";
						break;
					case 'ES2CoopMessage':
						ConsoleString = "";
						Color.R = 255;
						Color.G = 255;
						Color.B = 0;
						Color.A = 255;
						break;
					default:
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						break;
			}
		}
		else
		{
			if (Type == 'TMStatus' || Type == 'TMCenter' || Type == 'AIKilled')
			{
				Color.R = 255;
				Color.G = 0;
				Color.B = 0;
				Color.A = 255;
			}
			else
			{
				if (Type == 'AIKiller')
				{
					Color.R = 0;
					Color.G = 0;
					Color.B = 180;
					Color.A = 255;
				}
			}
		}
		ConsoleString = ConsoleString @ S;
	}
	if (MyHUD != nullptr)
	{
		if (Type == 'Center' || Type == 'TMCenter')
		{
			MyHUD.DisplayCenteredMessageLong(4.5, ConsoleString);
		}
		Player.Console.Message(ConsoleString, 20, Color);
		MyHUD.Message(PRI, S, Type);
	}
	*/
}

/*
* Already exists in PlayerController with different def
void AHumanController::GetViewTarget(AActor* VTA)
{
	local Controller C;
	C = Controller(VTA);
	if (C != nullptr)
	{
		Return C.Pawn;
	}
	else
	{
		Return VTA;
	}
}
*/

/*
* Already exists in PlayerController with different def
void AHumanController::ClientSetViewTarget(AActor* Target)
{
	//Global.leader_1(Target);
}
*/


/*
* Already exists in PlayerController with different def
void AHumanController::ClientReStart(APawn* NewPawn, bool bDontClearLevelParam)
{
	if (!bDontClearLevelParam)
	{
		CleanupLevel();
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->bDrawHUD = true;
		Cast<AAGP_HUD>(MyHUD)->bShowScores = false;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Client Restart Failed."));
	}
	bLostViewTarget = false;
	ClientReStart(NewPawn);
	ClientSetBehindView(False);
	abpobjESSLastSeen = None;
	if (aagpobjSeen.Length > 0)
	{
		aagpobjSeen.remove(0, aagpobjSeen.Length);
	}
	LastReportableNPC = None;
	fpWaitingForDelayedGrenade = 0;
}
*/

/*
* Already exists in PlayerController with different def
void AHumanController::ClientGameEnded()
{
	local int i;
	local array<VoiceChatRoom> Channels;
	if (bVoiceChatEnabled && PlayerReplicationInfo != nullptr && VoiceReplicationInfo != nullptr)
	{
		Channels = VoiceReplicationInfo.GetChannels();
		for (i = 0; i < Channels.Length; i++)
		{
			if (Channels[i] != nullptr && Channels[i].IsMember(PlayerReplicationInfo, true))
			{
				RejoinChannels[RejoinChannels.Length] = Channels[i].GetTitle();
			}
		}
		if (ActiveRoom != nullptr)
		{
			LastActiveChannel = ActiveRoom.GetTitle();
		}
	}
	if (RejoinChannels.Length > 0 || LastActiveChannel != "")
	{
		SaveConfig();
	}
	if (bPBChecked == false)
	{
		Return;
	}
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		Return;
	}
	ClientGameEnded();
	if (Pawn != nullptr)
	{
		Pawn.bWantsToProne = false;
		Pawn.bWantsToCrouch = false;
	}
	CleanOutSavedMoves();
}
*/

void AHumanController::SendAuthJacketToClient(FAuthJacket Jacket)
{
	if (GetNetMode()==ENetMode::NM_Client)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::SendAuthJacketToClient(%s)"), *AuthJacketToString(Jacket));
		//SetFromAuthJacket(Jacket);
		VerifyJacket();
		SaveJacket();
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->RefreshTourMissionDisplays();
		}
	}
}



void AHumanController::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		bPlayerIsReadyToPlay = true;
	}
	if (DesiredTeamClass == nullptr)
	{
		DesiredTeamClass = class<SoldierClass>(DynamicLoadObject(DesiredTeamClassName, Class'Class'));
	}
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo.sCurrentWeaponClass = "" $ DesiredTeamClass;
	}
	SetHUDAlpha(HUDAlpha);
	SetHUDColor(HUDColor);
	SetHUDCrosshair(HUDCrosshair);
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SetWeaponMods();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Length > 0)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[0]);
	}
	*/
}
void AHumanController::PreBeginPlay()
{
	/*
	RestoreSavedUserNameAndPassword();
	Super::PreBeginPlay();
	if (_FlashEffect == nullptr)
	{
		_FlashEffect = new (None) class'CamEffect_FlashBang';
	}
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		SetDevMode(False);
	}
	if (guipCommandPost != nullptr)
	{
		ClientCloseMenu(True);
		guipCommandPost = None;
	}
	*/
}
void AHumanController::Destroyed()
{
	/*
	local int iETACtrlIndex;
	if (GetNetMode() != ENetMode::NM_DedicatedServer && Level.Game != nullptr && Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay()._HumanController = None;
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		SetLoginStatus(0, "", "");
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
		{
			iETACtrlIndex = 0;
			if (iETACtrlIndex < 26)
			{
				if (Level.actrlETAUsedFirstNamePrefixes[iETACtrlIndex] == this)
				{
					Level.actrlETAUsedFirstNamePrefixes[iETACtrlIndex] = None;
				}
				else
				{
					iETACtrlIndex++;
				}
			}
		}
	}
	if (TournamentIsTournament())
	{
		if (PlayerReplicationInfo.bAdmin)
		{
			if (GameReplicationInfo.Teams[0].bTournamentTeamRosterLocked)
			{
				GameReplicationInfo.Teams[0].bTournamentTeamRosterLocked = false;
			}
			if (GameReplicationInfo.Teams[1].bTournamentTeamRosterLocked)
			{
				GameReplicationInfo.Teams[1].bTournamentTeamRosterLocked = false;
			}
		}
		else
		{
			if (PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				GameReplicationInfo.Teams[PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected = false;
				GameReplicationInfo.Teams[PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked = false;
			}
		}
	}
	*/

	Super::Destroyed();
	//_cHUDCommoInfo = nullptr;
	//_cHUDCompass = nullptr;
	_LastGlowActor = nullptr;
	_tPainOverlay = nullptr;
	DesiredTeamClass = nullptr;
	ViewTargetActor = nullptr;
	_FlashEffect = nullptr;
	
	if (sKickReason.Len() > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Player Kicked: %s"),*sKickReason);
	}
}

void AHumanController::SetCheatMonitor(UScriptObject* mon)
{
	if (mon == nullptr)
	{
		_CheatMonitor = nullptr;
	}
	else
	{
		_CheatMonitor = mon;
	}
}

//From Controller
bool AHumanController::ShouldRenderWeapon()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && !Cast<AAGP_Pawn>(GetPawn())->bIsDead)
	{
		return Cast<AAGP_Pawn>(GetPawn())->Weapon->ShouldRenderWeapon();
	}
	return false;
}

//From PlayerController
bool AHumanController::CanUseWeapon(int32 DesiredAction)
{
	if (!ShouldRenderWeapon() || Cast<AAGP_Pawn>(GetPawn()) == nullptr)
	{
		return false;
	}
	return Cast<AAGP_Pawn>(GetPawn())->CanUseWeapon(DesiredAction);
}


//From PlayerController
void AHumanController::ServerUpdateSelfHealActionState(bool bState)
{
	if (bState)
	{
		bHealSelfAction = 1;
	}
	else
	{
		bHealSelfAction = 0;
	}
}

//From PlayerController
void AHumanController::SetFromAuthJacket(FAuthJacket Jacket)
{
	int32 ii=0;
	
	iCompleted[0] = Jacket.ToursCompleted;
	for (ii = 0; ii < 32; ii++)
	{
		//iCompleted[ii + 1] = Jacket.MissionsCompleted[ii];
	}
	iRifleRangeRating = Jacket.MarksmanshipScore;
	if (PlayerReplicationInfo != nullptr)
	{
		//PlayerReplicationInfo._iTrust = Jacket.Honor;
		//PlayerReplicationInfo._Experience = Jacket.Experience;
		//PlayerReplicationInfo.SetGroup(Jacket.Group);
	}
	iUID = Jacket.UID;
	
}

//From PlayerController
FString AHumanController::AuthJacketToString(FAuthJacket Jacket)
{
	FString str="";
	int32 ii=0;
	/*
	str = "ToursCompleted:" @ Jacket.ToursCompleted;
	str @ = "MissionsCompleted: ";
	for (ii = 0; ii < 32; ii++)
	{
		if (ii > 0)
		{
			str $ = ",";
		}
		str $ = Jacket.MissionsCompleted[ii];
	}
	str @ = "MarksmanshipScore:" @ Jacket.MarksmanshipScore;
	str @ = "Honor:" @ Jacket.Honor;
	str @ = "Experience:" @ Jacket.Experience;
	str @ = "Group:" @ Jacket.Group;
	str @ = "UID:" @ Jacket.UID;
	*/
	return str;
}

//From Controller
//native final Function PbCanPlayerJoin ();
bool AHumanController::PbCanPlayerJoin()
{
	return true;			//FAKE   /ELiZ
}

//From PlayerController
//native final Function IsPBEnabled ();
bool AHumanController::IsPBEnabled()
{
	return true;	//FAKE   /ELiZ
}