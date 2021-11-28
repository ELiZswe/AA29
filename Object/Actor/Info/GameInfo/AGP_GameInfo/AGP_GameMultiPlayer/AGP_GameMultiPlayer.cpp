// All the original content belonged to the US Army


#include "AGP_GameMultiPlayer.h"



AAGP_GameMultiPlayer::AAGP_GameMultiPlayer()
{
	bRequireAuthorization = true;
	VoteKick_Cooldown = 3;
	MinHonor = 10;
	MaxHonor = 100;
	bDelayedStart = true;
	bMustJoinBeforeStart = true;
	BeaconName = "ArmyOps";
	//DeathMessageClass = class'AGP_Gameplay.AGP_DeathMessage';
}


void AAGP_GameMultiPlayer::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGP_GameMultiPlayer::BeginPlay()"));

	if(!(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer()))
	
	{
		UE_LOG(LogTemp, Warning, TEXT("IMPORTANT: Global server forcing authorization requirement."));
		bRequireAuthorization=true;
		//Level.Game.SaveConfig();
	}
	
	VerifyLegalGroups();
	VerifyHonorRange();
	Super::BeginPlay();
	AuthorizeServer();
}
void AAGP_GameMultiPlayer::UpdateClientsOfCheatAndForceclassStatus()
{
	/*
	AController* p;
	p= Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList;
	if (p != nullptr)
	{
		if (Cast<AHumanController>(p) != nullptr)
		{
			Cast<AHumanController>(p)->ClientDisableLocalCheats(bMPCheatsEnabled);
			Cast<AHumanController>(p)->ClientUpdateForceclassing(Cast<AAA2_GameState>(GetWorld()->GetGameState())->bAllowForceclassing);
		}
		p=p->nextController;
	}
	*/
}
void AAGP_GameMultiPlayer::AuthorizeServer()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer() && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer())
	{
		bDemoExploreTheArmyMode=true;
		bRequireAuthorization=false;
	}
	Super::AuthorizeServer();
}
void AAGP_GameMultiPlayer::SetStartupStage(EStartupStage Stage)
{
	/*
	local Controller C;
	StartupStage=Stage;
	C=Level.ControllerList;
	if (C != None)
	{
		if (HumanController(C) != None)
		{
			if (HumanController(C).bPBChecked || Stage == 1)
			{
				HumanController(C).SetStartupStage(StartupStage);
			}
		}
		C=C.nextController;
	}
	*/
}
void AAGP_GameMultiPlayer::PreparePlayerForStartMatch(APlayerController* PC)
{
	/*
	PreparePlayerForStartMatch(PC);
	HumanController(PC).bLatecomer=False;
	*/
}
bool AAGP_GameMultiPlayer::IsRequireAuthorization()
{
	return bRequireAuthorization;
}
void AAGP_GameMultiPlayer::SetRequireAuthorization(bool bReqAuth)
{
	if (bRequireAuthorization)
	{
		fAuthNotAvailableLastAuthAttempt=true;
		//NextAuthTime=GetWorld()->GetTimeSeconds() + 60 * 10;
	}
	bRequireAuthorization=bReqAuth;
}
void AAGP_GameMultiPlayer::DisableQualification()
{
	bDisableQualification = true;
}

bool AAGP_GameMultiPlayer::ShouldIgnoreStats()
{
	if (Stats != NULL)
	{
		if (Super::ShouldIgnoreStats() || bMPCheatsEnabled)
		{
			return true;
		}
	}
	return false;
}
bool AAGP_GameMultiPlayer::AllowGameSpeedChange()
{
	return bMPCheatsEnabled;
}
void AAGP_GameMultiPlayer::GetDefaultTeamClass()
{
	/*
	local string sclass_name;
	local float fr;
	fr=FRand();
	Log("GameInfo::GetDefaultTeamClass()	Returning a random class" $ fr);
	if (fr < 0.25)
	{
		sclass_name="AGP_Characters.ClassRifleman";
	}
	else
	{
		if (fr < 0.5)
		{
			sclass_name="AGP_Characters.ClassGrenadier";
		}
		else
		{
			if (fr < 0.75)
			{
				sclass_name="AGP_Characters.ClassAutomaticRifleman";
			}
			else
			{
				if (fr <= 1)
				{
					sclass_name="AGP_Characters.ClassSniper";
				}
				else
				{
					sclass_name="AGP_Characters.ClassRecruit";
				}
			}
		}
	}
	Return class<Actor>(DynamicLoadObject(sclass_name,Class'Class'));
	*/
}
bool AAGP_GameMultiPlayer::CheatsDisabled()
{
	if (bMPCheatsEnabled)
	{
		return false;
	}
	return true;
}
bool AAGP_GameMultiPlayer::IsMultiPlayer()
{
	return true;
}
int32 AAGP_GameMultiPlayer::GetMinHonor()
{
	return MinHonor;
}
int32 AAGP_GameMultiPlayer::GetMaxHonor()
{
	return MaxHonor;
}
void AAGP_GameMultiPlayer::VerifyHonorRange()
{
	MinHonor=FMath::Clamp(MinHonor,1,100);
	MaxHonor=FMath::Clamp(MaxHonor,9,100);
	if (MinHonor > MaxHonor)
	{
		MinHonor=1;
	}
}
void AAGP_GameMultiPlayer::CheckHonor(AController* C)
{
	/*
	local int Honor;
	if (! IsRequireAuthorization())
	{
		Return 0;
	}
	if (C.PlayerReplicationInfo.bAdmin || C.PlayerReplicationInfo.SuperUser())
	{
		Return 0;
	}
	Honor=C.PlayerReplicationInfo.GetHonor();
	if (Honor < MinHonor)
	{
		Return -1;
	}
	else
	{
		if (Honor > MaxHonor)
		{
			Return 1;
		}
		else
		{
			Return 0;
		}
	}
	*/
}
void AAGP_GameMultiPlayer::VerifyLegalGroups()
{
	/*
	int32 i;
	for (i=0; i<LegalGroups.Num(); i++)
	{
		if (LegalGroups[i] == 0)
		{
			LegalGroups.remove (i,1);
		}
	}
	*/
}

void AAGP_GameMultiPlayer::CheckGroup(AController* C)
{
	/*
	local int G;
	local int i;
	if (! IsRequireAuthorization())
	{
		Return True;
	}
	if (C.PlayerReplicationInfo.bAdmin || C.PlayerReplicationInfo.SuperUser())
	{
		UE_LOG(LogTemp, Warning, TEXT("Testing admin's group: " $ C.PlayerReplicationInfo._Group));
		UE_LOG(LogTemp, Warning, TEXT("Official server flag: " $ Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer()));
		if (C.PlayerReplicationInfo.bAdmin && C.PlayerReplicationInfo.bOnlySpectator && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && ! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && C.PlayerReplicationInfo._Group != 20 && C.PlayerReplicationInfo._Group != 1)
		{
			Log("""" $ C.PlayerReplicationInfo.PlayerName $ """ attempted to join as admin but isn't in the admin group.");
			Return False;
		}
		Return True;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
	{
		if (C.PlayerReplicationInfo.GetGroup() == 1 || C.PlayerReplicationInfo.GetGroup() == 4)
		{
			Return True;
		}
		if (HumanController(C).bETATrackingUsed)
		{
			Return True;
		}
		Return False;
	}
	if (LegalGroups.Length == 0)
	{
		Return True;
	}
	G=C.PlayerReplicationInfo.GetGroup();
	for (i=0; i<LegalGroups.Length; i++)
	{
		if (LegalGroups[i] == G)
		{
			Return True;
		}
	}
	Return False;
	*/
}
FString AAGP_GameMultiPlayer::GetLegalGroupsString()
{
	int32 i;
	FString Groups;
	if (LegalGroups.Num() > 0)
	{
		return "ALL";
	}
	else
	{
		Groups=FString::FromInt(LegalGroups[0]);
		for (i=1; i<LegalGroups.Num(); i++)
		{
			Groups=Groups + " " + FString::FromInt(LegalGroups[i]);
		}
		return Groups;
	}
}

/*
APlayerController AAGP_GameMultiPlayer::Login(FString Portal, FString Options, FString Error)
{
	APlayerController NewPlayer;
	NewPlayer=Login(Portal,Options,Error);
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::Login()	" $ NewPlayer));
	if (bMustJoinBeforeStart && ! bWaitingToStartMatch)
	{
		HumanController(NewPlayer).bLatecomer=True;
		if (! Level.bAllowLateJoin)
		{
			NewPlayer.PlayerReplicationInfo.bDead=True;
			NewPlayer.PlayerReplicationInfo.bOutOfLives=True;
		}
	}
	
	return NewPlayer;
}
*/
void AAGP_GameMultiPlayer::PostLogin(APlayerController* NewPlayer)
{
	
	//local AGP.HumanController HC;
	//local bool bAllowLocalScore;
	Super::PostLogin(NewPlayer);
	/*
	if (ScoreMode == 0)
	{
		bAllowLocalScore=True;
	}
	else
	{
		bAllowLocalScore=False;
	}
	HC=HumanController(NewPlayer);
	HC.ClientSetServerFlags(bMPCheatsEnabled,False,Cast<AAA2_WorldSettings>(GetWorldSettings())->IsBetaServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsNATOServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer(),Level.IsUltimateArenaServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer(),Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization(),IsSpectatePlayersOnly(),IsSpectateFirstPersonOnly(),IsSpectateBodies(),bAllowLocalScore,Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer(),GameReplicationInfo.bAllowForceclassing);
	HC.PostLoginComplete();
	*/
}
bool AAGP_GameMultiPlayer::IsTournamentMode()
{
	return false;
}
void AAGP_GameMultiPlayer::FinishPostLogin(APlayerController* NewPlayer)
{
	/*
	local AGP.HumanController HC;
	HC=HumanController(NewPlayer);
	HC.ClientForceGamePlayMode(Level.GamePlayMode);
	if (bWaitingToStartMatch || HC.PlayerReplicationInfo.bOutOfLives)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin() - Trying to call ClientTeamSelectMenu() "));
		EnterSpectatorMode(NewPlayer);
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
		{
			HC.ClientTeamSelectMenu(True);
		}
		if (bWaitingToStartMatch)
		{
			NewPlayer.ClientSetBehindView(False);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin() - Late joins not handled yet!"));
	}
	if (HC.PlayerReplicationInfo.bAdmin && HC.PlayerReplicationInfo.bOnlySpectator)
	{
		if (! HC.IsA('HumanController') && ! HC.IsA('SuperAdmin'))
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin()	- Unqualified Admin " $ NewPlayer @ NewPlayer.PlayerReplicationInfo.GetHumanReadableName()));
			Kick(NewPlayer.PlayerReplicationInfo.PlayerName,"Admin");
		}
	}
	else
	{
		if (NewPlayer.PawnClass != GetDefaultPlayerClass(NewPlayer))
		{
			if (NewPlayer.PawnClass == None)
			{
				NewPlayer.PawnClass=GetDefaultPlayerClass(NewPlayer);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin()	- Incorrect class " $ NewPlayer.PlayerReplicationInfo.GetHumanReadableName() @ NewPlayer.PawnClass));
				Kick(NewPlayer.PlayerReplicationInfo.PlayerName,"Cheater");
			}
		}
	}
	*/
}

void AAGP_GameMultiPlayer::EvaluatePlayerStatus(APlayerController* PC)
{
	/*
	local string sBanFailCode;
	local string sBanErrorMsg;
	local string sInIPAddressSansPort;
	local int iBanLengthSeconds;
	local int iPortPos;
	if (AccessControl != None)
	{
		Log("Evaluating incoming player IP: """ $ PC.GetPlayerNetworkAddress() $ """ PBGUID: " $ Level.GetPBGUIDFromIP(PC.GetPlayerNetworkAddress()));
		if (AccessControl.bUseNewBanListFormat)
		{
			Log("Using new ban list format");
			if (AccessControl.BanListCheckPlayerBanStatus(PC.PlayerReplicationInfo.PlayerName,Level.GetPBGUIDFromIP(PC.GetPlayerNetworkAddress())))
			{
				iBanLengthSeconds=AccessControl.BanListQueryPlayerBanStatus(PC.PlayerReplicationInfo.PlayerName,Level.GetPBGUIDFromIP(PC.GetPlayerNetworkAddress()));
				if (iBanLengthSeconds > 0)
				{
					if (iBanLengthSeconds > 24 * 3600)
					{
						sBanErrorMsg=iBanLengthSeconds / 24 * 3600 $ " days";
						iBanLengthSeconds -= 24 * 3600 * iBanLengthSeconds / 24 * 3600;
					}
					if (iBanLengthSeconds > 3600)
					{
						sBanErrorMsg=sBanErrorMsg $ iBanLengthSeconds / 3600 $ " hours";
						iBanLengthSeconds -= iBanLengthSeconds / 3600 * 3600;
					}
					if (iBanLengthSeconds > 60)
					{
						sBanErrorMsg=sBanErrorMsg $ iBanLengthSeconds / 60 $ " minutes";
					}
					sBanErrorMsg=PC.PlayerReplicationInfo.PlayerName $ " for " $ sBanErrorMsg;
				}
			}
		}
		else
		{
			iPortPos=InStr(PC.GetPlayerNetworkAddress(),":");
			if (iPortPos > 0)
			{
				sInIPAddressSansPort=Left(PC.GetPlayerNetworkAddress(),iPortPos);
			}
			AccessControl.VerifyUserOldBanList(PC.PlayerReplicationInfo.PlayerName,PC.GetPlayerNetworkAddress(),sInIPAddressSansPort,"",sBanErrorMsg,sBanFailCode);
		}
		UE_LOG(LogTemp, Warning, TEXT("Ban test result """ $ sBanErrorMsg $ """"));
		if (Len(sBanErrorMsg) > 0)
		{
			Log("Player access rejected due to " $ sBanErrorMsg);
			KickByController(PC,sBanErrorMsg);
		}
	}
	*/
}

void AAGP_GameMultiPlayer::Logout(AController* Exiting)
{
	/*
	local PlayerController PC;
	if (Level.Game.Stats != None && IsInState('MatchInProgress'))
	{
		PC=PlayerController(Exiting);
		if (PC != None && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_Quit();
		}
	}
	if (! Exiting.PlayerReplicationInfo.bAdmin)
	{
		Broadcast(Self,HumanController(Exiting).UserName $ " has left the server.");
	}
	LogFileWrite("DevNet","Left:" $ HumanController(Exiting).UserName);
	if (IsRequireAuthorization())
	{
		if (HumanController(Exiting).bAuthDisabledForAccount)
		{
			Log("Player leaving in special unauthorized player state");
		}
		else
		{
			Log("Player leaving authorized server in authorized state.");
			if (bBinaryAuthProtocol)
			{
			}
			HumanController(Exiting).ServerUploadTrustAndExperience(1);
		}
	}
	if (Exiting.PlayerReplicationInfo == VoteKick_PRI)
	{
		VoteKickPlayerLeft();
	}
	*/
	Super::Logout(Exiting);
}
void AAGP_GameMultiPlayer::RestartPlayer(AController* aPlayer)
{
	/*
	if (HumanController(aPlayer) != None && ! HumanController(aPlayer).bPBChecked)
	{
		Return;
	}
	if (! Level.bAllowLateJoin)
	{
		if (bMustJoinBeforeStart && HumanController(aPlayer).bLatecomer && HumanController(aPlayer).bPBChecked)
		{
			HumanController(aPlayer).SetStartupStage(2);
			Return;
		}
	}
	*/
	Super::RestartPlayer(aPlayer);
}
void AAGP_GameMultiPlayer::CheckDevKick(AController* Kicker, FString PlayerName)
{
	/*
	if (IsRequireAuthorization())
	{
		if (Kicker.PlayerReplicationInfo == None || Kicker.PlayerReplicationInfo._Group != 1 && Kicker.PlayerReplicationInfo._Group != 2)
		{
			PlayerController(Kicker).ClientMessage("You do not have sufficient rights to use ""devkick"".");
			Return;
		}
		if (Kicker.PlayerReplicationInfo.SuperUser())
		{
			Kick(PlayerName,"Dev");
		}
	}
	*/
}
void AAGP_GameMultiPlayer::ActiveVote()
{
	/*
	if (VoteKick_Player != "" && GetWorld()->GetTimeSeconds() < VoteKick_Timer)
	{
		Return True;
	}
	else
	{
		Return False;
	}
	*/
}
bool AAGP_GameMultiPlayer::CanInitiate(AAA2_PlayerState* PRI)
{
	
	if (PRI->SuperUser(false))
	{
		return true;
	}
	else
	{
		/*
		if (GetWorld()->GetTimeSeconds() < PRI->tNextVoteAllowed)
		{
			PRI->NotifyClientMessage("You cannot initiate another votekick at this time. Please try again in a few minutes.");
			PRI->tNextVoteAllowed += 5;
			return false;
		}
		else
		{
			return true;
		}
		*/
		return false;   //FAKE  /ELiZ
	}
	
}
void AAGP_GameMultiPlayer::CanInitiateFor(AAA2_PlayerState* PRI_ini, AAA2_PlayerState* PRI_for, FString Reason)
{
	/*
	if (PRI_for.bAdmin)
	{
		Return False;
	}
	else
	{
		if (PRI_ini.bAdmin)
		{
			Return True;
		}
		else
		{
			if (PRI_ini.Team != PRI_for.Team && ! PRI_for.isDead())
			{
				PRI_ini.NotifyClientMessage("You cannot initiate a votekick on an active opponent.");
				Return False;
			}
			else
			{
				if (Reason == Class'HumanController'.GetReason(2) && PRI_for.Score_ROE == 0)
				{
					PRI_ini.NotifyClientMessage(PRI_ini.PlayerName @ "has no ROE");
					Return False;
				}
				else
				{
					Return True;
				}
			}
		}
	}
	*/
}
void AAGP_GameMultiPlayer::InitiateVoteRequest(AAA2_PlayerState* PRI, FString PlayerName, FString Reason)
{
	/*
	local Controller CVote;
	local int players;
	local string Msg;
	if (! ActiveVote() && CanInitiate(PRI))
	{
		CVote=Level.ControllerList;
		if (CVote != None)
		{
			if (CVote.IsA('AIController'))
			{
			}
			if (CVote.PlayerReplicationInfo.GetHumanReadableName() ~= PlayerName)
			{
				if (CanInitiateFor(PRI,CVote.PlayerReplicationInfo,Reason))
				{
					VoteKick_PRI=CVote.PlayerReplicationInfo;
					VoteKick_Player=PlayerName;
					VoteKick_Timer=GetWorld()->GetTimeSeconds() + 20;
					VoteKick_StartTime=GetWorld()->GetTimeSeconds();
				}
			}
			CVote.PlayerReplicationInfo.votekick="";
			players ++;
			CVote=CVote.nextController;
		}
		if (ActiveVote())
		{
			PRI.tNextVoteAllowed=GetWorld()->GetTimeSeconds() + VoteKick_Cooldown * 60;
			PRI.votekick=PlayerName;
			Msg=PRI.GetHumanReadableName() $ " has initiated a vote to kick " $ VoteKick_Player;
			if (Reason != "")
			{
				Msg=Msg $ " for this reason: " $ Reason;
			}
			Msg=Msg $ ". Hit <votekick> to vote yes. [" $ GetVotesRequired(players) $ "] votes required.";
			Broadcast(Self,Msg);
		}
	}
	*/
}
void AAGP_GameMultiPlayer::Timer()
{
	Super::Timer();
	/*
	if (VoteKick_Player != "")
	{
		if (GetWorld()->GetTimeSeconds() >= VoteKick_Timer)
		{
			CheckPendingVote("",True);
		}
	}
	*/
}
void AAGP_GameMultiPlayer::VoteKickPlayerLeft()
{
	/*
	Broadcast(Self,"The vote to kick " $ VoteKick_Player $ " has ended because " $ VoteKick_Player $ " has left the game");
	ClearVote();
	*/
}
void AAGP_GameMultiPlayer::EndVote()
{
	/*
	if (ActiveVote())
	{
		CheckPendingVote("",True);
	}
	*/
}
void AAGP_GameMultiPlayer::ClearVote()
{
	VoteKick_Timer=0;
	VoteKick_Player="";
	VoteKick_PRI=nullptr;
}
void AAGP_GameMultiPlayer::CastVote(AAA2_PlayerState* PRI)
{
	/*
	if (ActiveVote())
	{
		if (PRI.votekick != VoteKick_Player && PRI.StartTime <= VoteKick_StartTime)
		{
			PRI.votekick=VoteKick_Player;
			VoteKick_Timer=GetWorld()->GetTimeSeconds() + 20;
			CheckPendingVote(PRI.GetHumanReadableName());
		}
	}
	*/
}
void AAGP_GameMultiPlayer::CheckPendingVote(FString new_voter, bool bEndVote)
{
	/*
	local int VoteCount;
	local int players;
	local int required;
	local Controller CVote;
	local bool bFound;
	CVote=Level.ControllerList;
	if (CVote != None)
	{
		if (CVote.IsA('AIController'))
		{
		}
		players ++;
		if (CVote.PlayerReplicationInfo.votekick ~= VoteKick_Player)
		{
			VoteCount ++;
		}
		if (CVote.PlayerReplicationInfo.GetHumanReadableName() ~= VoteKick_Player)
		{
			bFound=True;
		}
		CVote=CVote.nextController;
	}
	required=GetVotesRequired(players);
	if (new_voter != "")
	{
		Broadcast(Self,new_voter $ " has added a vote to kick " $ VoteKick_Player $ ". [" $ VoteCount $ "/" $ required $ "]");
	}
	if (VoteCount >= required)
	{
		Kick(VoteKick_Player,"VoteKick");
		ClearVote();
	}
	else
	{
		if (bEndVote)
		{
			Broadcast(Self,"The vote to kick " $ VoteKick_Player $ " has failed. [" $ VoteCount $ "/" $ required $ "]");
			ClearVote();
		}
	}
	*/
}
int32 AAGP_GameMultiPlayer::GetVotesRequired(int32 players)
{
	double half_plus_1;
	half_plus_1=players / 2 + 1;
	if (! VoteKick_PRI->isDead() && VoteKick_PRI->Team->NumAlive(false, 0) == 1)
	{
		return FMath::Max(players * 0.75,half_plus_1);
	}
	else
	{
		return half_plus_1;
	}
}