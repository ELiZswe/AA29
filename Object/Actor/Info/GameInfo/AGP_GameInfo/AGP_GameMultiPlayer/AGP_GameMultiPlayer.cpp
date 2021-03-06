// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameMultiPlayer.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/LocalMessage/AGP_DeathMessage/AGP_DeathMessage.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/SuperAdmin/SuperAdmin.h"

AAGP_GameMultiPlayer::AAGP_GameMultiPlayer()
{
	bRequireAuthorization = true;
	VoteKick_Cooldown = 3;
	MinHonor = 10;
	MaxHonor = 100;
	bDelayedStart = true;
	bMustJoinBeforeStart = true;
	BeaconName = "ArmyOps";
	//DeathMessageClass = AAGP_DeathMessage::StaticClass();
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
	AController* p = nullptr;
	/*
	for (p = Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList; p != nullptr; p = p->nextController)
	{
		if (Cast<AHumanController>(p) != nullptr)
		{
			Cast<AHumanController>(p)->ClientDisableLocalCheats(bMPCheatsEnabled);
			Cast<AHumanController>(p)->ClientUpdateForceclassing(Cast<AAA2_GameState>(GetWorld()->GetGameState())->bAllowForceclassing);
		}
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
	AController* C = nullptr;
	StartupStage=Stage;
	/*
	for (C= Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList; C!=nullptr; C=C->nextController)
	{
		if (Cast<AHumanController>(C) != nullptr)
		{
			if (Cast<AHumanController>(C)->bPBChecked || (Stage == EStartupStage::STAGE_Authorizing))
			{
				Cast<AHumanController>(C)->SetStartupStage(StartupStage);
			}
		}
	}
	*/
}
void AAGP_GameMultiPlayer::PreparePlayerForStartMatch(APlayerController* PC)
{
	/*
	PreparePlayerForStartMatch(PC);
	Cast<AHumanController>(PC).bLatecomer=false;
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

AActor* AAGP_GameMultiPlayer::GetDefaultTeamClass()
{
	FString sclass_name = "";
	float fr = 0;
	fr = FMath::FRand();
	/*
	Log("GameInfo::GetDefaultTeamClass()	Returning a random class" + fr);
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
	return class<Actor>(DynamicLoadObject(sclass_name,Class'Class'));
	*/
	return nullptr;    //FAKE   /EliZ
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

int32 AAGP_GameMultiPlayer::CheckHonor(AController* C)
{
	int32 Honor;
	if (! IsRequireAuthorization())
	{
		return 0;
	}
	if (Cast<AHumanController>(C)->PlayerReplicationInfo->bAdmin || Cast<AHumanController>(C)->PlayerReplicationInfo->SuperUser(false))
	{
		return 0;
	}
	Honor= Cast<AHumanController>(C)->PlayerReplicationInfo->GetHonor();
	if (Honor < MinHonor)
	{
		return -1;
	}
	else
	{
		if (Honor > MaxHonor)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void AAGP_GameMultiPlayer::VerifyLegalGroups()
{
	int32 i = 0;
	/*
	for (i=0; i<LegalGroups.Num(); i++)
	{
		if (LegalGroups[i] == 0)
		{
			LegalGroups->Remove(i,1);
		}
	}
	*/
}

bool AAGP_GameMultiPlayer::CheckGroup(AController* C)
{
	int32 G = 0;
	int32 i = 0;
	if (!IsRequireAuthorization())
	{
		return true;
	}
	/*
	if (C.PlayerReplicationInfo.bAdmin || C.PlayerReplicationInfo.SuperUser())
	{
		UE_LOG(LogTemp, Warning, TEXT("Testing admin's group: " + C.PlayerReplicationInfo._Group));
		UE_LOG(LogTemp, Warning, TEXT("Official server flag: " + Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer()));
		if (C.PlayerReplicationInfo.bAdmin && C.PlayerReplicationInfo.bOnlySpectator && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && ! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && C.PlayerReplicationInfo._Group != 20 && C.PlayerReplicationInfo._Group != 1)
		{
			Log("""" + C.PlayerReplicationInfo.PlayerName + """ attempted to join as admin but isn't in the admin group.");
			return false;
		}
		return true;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
	{
		if (C.PlayerReplicationInfo.GetGroup() == 1 || C.PlayerReplicationInfo.GetGroup() == 4)
		{
			return true;
		}
		if (Cast<AHumanController>(C).bETATrackingUsed)
		{
			return true;
		}
		return false;
	}
	if (LegalGroups.Num() == 0)
	{
		return true;
	}
	G=C.PlayerReplicationInfo.GetGroup();
	for (i=0; i<LegalGroups.Num(); i++)
	{
		if (LegalGroups[i] == G)
		{
			return true;
		}
	}
	*/
	return false;
}

FString AAGP_GameMultiPlayer::GetLegalGroupsString()
{
	int32 i = 0;
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
APlayerController AAGP_GameMultiPlayer::Login(FString Portal, FString Options, FString& Error)
{
	APlayerController NewPlayer;
	NewPlayer=Login(Portal,Options,Error);
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::Login()	" + NewPlayer));
	if (bMustJoinBeforeStart && ! bWaitingToStartMatch)
	{
		Cast<AHumanController>(NewPlayer).bLatecomer=true;
		if (! Level.bAllowLateJoin)
		{
			NewPlayer.PlayerReplicationInfo.bDead=true;
			NewPlayer.PlayerReplicationInfo.bOutOfLives=true;
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
		bAllowLocalScore=true;
	}
	else
	{
		bAllowLocalScore=false;
	}
	HC=Cast<AHumanController>(NewPlayer);
	HC.ClientSetServerFlags(bMPCheatsEnabled,false,Cast<AAA2_WorldSettings>(GetWorldSettings())->IsBetaServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsNATOServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer(),Level.IsUltimateArenaServer(),Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer(),Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization(),IsSpectatePlayersOnly(),IsSpectateFirstPersonOnly(),IsSpectateBodies(),bAllowLocalScore,Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer(),GameReplicationInfo.bAllowForceclassing);
	HC.PostLoginComplete();
	*/
}

bool AAGP_GameMultiPlayer::IsTournamentMode()
{
	return false;
}

void AAGP_GameMultiPlayer::FinishPostLogin(APlayerController* NewPlayer)
{
	AHumanController* HC = nullptr;
	HC = Cast<AHumanController>(NewPlayer);
	/*
	HC.ClientForceGamePlayMode(Level.GamePlayMode);
	if (bWaitingToStartMatch || HC.PlayerReplicationInfo.bOutOfLives)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin() - Trying to call ClientTeamSelectMenu() "));
		EnterSpectatorMode(NewPlayer);
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
		{
			HC.ClientTeamSelectMenu(true);
		}
		if (bWaitingToStartMatch)
		{
			NewPlayer.ClientSetBehindView(false);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin() - Late joins not handled yet!"));
	}
	if (HC.PlayerReplicationInfo.bAdmin && HC.PlayerReplicationInfo.bOnlySpectator)
	{
		if (! HC->IsA(AHumanController::StaticClass()) && ! HC->IsA(ASuperAdmin::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin()	- Unqualified Admin " + NewPlayer @ NewPlayer.PlayerReplicationInfo.GetHumanReadableName()));
			Kick(NewPlayer.PlayerReplicationInfo.PlayerName,"Admin");
		}
	}
	else
	{
		if (NewPlayer.PawnClass != GetDefaultPlayerClass(NewPlayer))
		{
			if (NewPlayer.PawnClass == nullptr)
			{
				NewPlayer.PawnClass=GetDefaultPlayerClass(NewPlayer);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameMultiPlayer::FinishPostLogin()	- Incorrect class " + NewPlayer.PlayerReplicationInfo.GetHumanReadableName() @ NewPlayer.PawnClass));
				Kick(NewPlayer.PlayerReplicationInfo.PlayerName,"Cheater");
			}
		}
	}
	*/
}

void AAGP_GameMultiPlayer::EvaluatePlayerStatus(APlayerController* PC)
{
	/*
	FString sBanFailCode;
	FString sBanErrorMsg;
	FString sInIPAddressSansPort;
	int32 iBanLengthSeconds;
	int32 iPortPos;
	if (AccessControl != nullptr)
	{
		Log("Evaluating incoming player IP: """ + PC.GetPlayerNetworkAddress() + """ PBGUID: " + Level.GetPBGUIDFromIP(PC.GetPlayerNetworkAddress()));
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
						sBanErrorMsg=iBanLengthSeconds / 24 * 3600 + " days";
						iBanLengthSeconds -= 24 * 3600 * iBanLengthSeconds / 24 * 3600;
					}
					if (iBanLengthSeconds > 3600)
					{
						sBanErrorMsg=sBanErrorMsg + iBanLengthSeconds / 3600 + " hours";
						iBanLengthSeconds -= iBanLengthSeconds / 3600 * 3600;
					}
					if (iBanLengthSeconds > 60)
					{
						sBanErrorMsg=sBanErrorMsg + iBanLengthSeconds / 60 + " minutes";
					}
					sBanErrorMsg=PC.PlayerReplicationInfo.PlayerName + " for " + sBanErrorMsg;
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
		UE_LOG(LogTemp, Warning, TEXT("Ban test result """ + sBanErrorMsg + """"));
		if (Len(sBanErrorMsg) > 0)
		{
			Log("Player access rejected due to " + sBanErrorMsg);
			KickByController(PC,sBanErrorMsg);
		}
	}
	*/
}

void AAGP_GameMultiPlayer::Logout(AController* Exiting)
{
	/*
	APlayerController* PC = nullptr;
	if (Level.Game.Stats != nullptr && IsInState('MatchInProgress'))
	{
		PC=Cast<APlayerController>(Exiting);
		if (PC != nullptr && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_Quit();
		}
	}
	if (! Exiting.PlayerReplicationInfo.bAdmin)
	{
		Broadcast(this,HumanController(Exiting).UserName + " has left the server.");
	}
	LogFileWrite("DevNet","Left:" + Cast<AHumanController>(Exiting).UserName);
	if (IsRequireAuthorization())
	{
		if (Cast<AHumanController>(Exiting).bAuthDisabledForAccount)
		{
			Log("Player leaving in special unauthorized player state");
		}
		else
		{
			Log("Player leaving authorized server in authorized state.");
			if (bBinaryAuthProtocol)
			{
			}
			Cast<AHumanController>(Exiting).ServerUploadTrustAndExperience(1);
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
	if (Cast<AHumanController>(aPlayer) != nullptr && ! Cast<AHumanController>(aPlayer).bPBChecked)
	{
		return;
	}
	if (! Level.bAllowLateJoin)
	{
		if (bMustJoinBeforeStart && Cast<AHumanController>(aPlayer).bLatecomer && Cast<AHumanController>(aPlayer).bPBChecked)
		{
			Cast<AHumanController>(aPlayer).SetStartupStage(2);
			return;
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
		if (Kicker.PlayerReplicationInfo == nullptr || Kicker.PlayerReplicationInfo._Group != 1 && Kicker.PlayerReplicationInfo._Group != 2)
		{
			Cast<APlayerController>(Kicker).ClientMessage("You do not have sufficient rights to use ""devkick"".");
			return;
		}
		if (Kicker.PlayerReplicationInfo.SuperUser())
		{
			Kick(PlayerName,"Dev");
		}
	}
	*/
}

bool AAGP_GameMultiPlayer::ActiveVote()
{
	if (VoteKick_Player != "" && GetWorld()->GetTimeSeconds() < VoteKick_Timer)
	{
		return true;
	}
	else
	{
		return false;
	}
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

bool AAGP_GameMultiPlayer::CanInitiateFor(AAA2_PlayerState* PRI_ini, AAA2_PlayerState* PRI_for, FString Reason)
{
	/*
	if (PRI_for->bAdmin)
	{
		return false;
	}
	else
	{
		if (PRI_ini->bAdmin)
		{
			return true;
		}
		else
		{
			if (PRI_ini->Team != PRI_for->Team && ! PRI_for->isDead())
			{
				PRI_ini->NotifyClientMessage("You cannot initiate a votekick on an active opponent.");
				return false;
			}
			else
			{
				if (Reason == AHumanController::StaticClass().GetReason(2) && PRI_for.Score_ROE == 0)
				{
					PRI_ini->NotifyClientMessage(PRI_ini->PlayerName + "has no ROE");
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	*/
	return false;     //FAKE   /EliZ
}

void AAGP_GameMultiPlayer::InitiateVoteRequest(AAA2_PlayerState* PRI, FString PlayerName, FString Reason)
{
	AController* CVote = nullptr;
	int32 players = 0;
	FString Msg = "";
	/*
	if ((!ActiveVote()) && CanInitiate(PRI))
	{
		for (CVote = Level.ControllerList; CVote != nullptr; CVote = CVote.nextController)
		{
			if (CVote->IsA(AaAIController::StaticClass()))
			{
			}
			if (CVote.PlayerReplicationInfo.GetHumanReadableName() ~= PlayerName)
			{
				if (CanInitiateFor(PRI, CVote.PlayerReplicationInfo, Reason))
				{
					VoteKick_PRI = CVote.PlayerReplicationInfo;
					VoteKick_Player = PlayerName;
					VoteKick_Timer = (GetWorld()->GetTimeSeconds() + float(20));
					VoteKick_StartTime = int(GetWorld()->GetTimeSeconds());
				}
			}
			CVote.PlayerReplicationInfo.votekick = "";
			players++;
		}
		if (ActiveVote())
		{
			PRI.tNextVoteAllowed = (GetWorld()->GetTimeSeconds() + (VoteKick_Cooldown * float(60)));
			PRI.votekick = PlayerName;
			Msg = PRI.GetHumanReadableName() + " has initiated a vote to kick " + VoteKick_Player;
			if (Reason != "")
			{
				Msg = Msg + " for this reason: " + Reason;
			}
			Msg = Msg + ". Hit <votekick> to vote yes. [" + FString::FromInt(GetVotesRequired(players)) + "] votes required.";
			Broadcast(this, Msg);
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
			CheckPendingVote("",true);
		}
	}
	*/
}
void AAGP_GameMultiPlayer::VoteKickPlayerLeft()
{
	/*
	Broadcast(this,"The vote to kick " + VoteKick_Player + " has ended because " + VoteKick_Player + " has left the game");
	ClearVote();
	*/
}
void AAGP_GameMultiPlayer::EndVote()
{
	/*
	if (ActiveVote())
	{
		CheckPendingVote("",true);
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
	int32 VoteCount = 0;
	int32 players = 0;
	int32 required = 0;
	AController* CVote = nullptr;
	bool bFound = false;
	/*
	for (CVote = Level.ControllerList; CVote != nullptr; CVote = CVote.nextController)
	{
		if (CVote->IsA(AaAIController::StaticClass()))
		{
		}
		players++;
		if (CVote.PlayerReplicationInfo.votekick ~= VoteKick_Player)
		{
			VoteCount++;
		}
		if (CVote.PlayerReplicationInfo.GetHumanReadableName() ~= VoteKick_Player)
		{
			bFound = true;
		}
	}
	required = GetVotesRequired(players);
	if (new_voter != "")
	{
		Broadcast(this, new_voter + " has added a vote to kick " + VoteKick_Player + ". [" + FString::FromInt(VoteCount) + "/" + FString::FromInt(required) + "]");
	}
	if (VoteCount >= required)
	{
		Kick(VoteKick_Player, "VoteKick");
		ClearVote();
	}
	else
	{
		if (bEndVote)
		{
			Broadcast(this, "The vote to kick " + VoteKick_Player + " has failed. [" + FString::FromInt(VoteCount) + "/" + FString::FromInt(required) + "]");
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
