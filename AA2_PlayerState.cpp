// All the original content belonged to the US Army

#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/Decoration/Decoration.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/VehicleReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/LinkedReplicationInfo/LinkedReplicationInfo.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/VoicePack/VoicePack.h"
#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Inventory/DummyItem/Item_Bullseye/Item_Bullseye.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_Playerstart/AGP_Playerstart.h"
#include "EngineUtils.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Brush/Volume/CommVolume/CommVolume.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "Engine/Canvas.h"

AAA2_PlayerState::AAA2_PlayerState()
{
	My_Pawn_Inventory = {	AItem_Bullseye::StaticClass()	};
	MyState = "Idle";
}

/*
void AAA2_PlayerState::Set_Weapon(TSubclassOf<AAGP_Weapon> Weapon);
{

}
*/

void AAA2_PlayerState::Set_My_Pawn_Inventory(TArray< TSubclassOf<AInventory>> this_inventory)
{
	My_Pawn_Inventory = this_inventory;
}

TArray< TSubclassOf<AInventory>> AAA2_PlayerState::Get_My_Pawn_Inventory()
{
	return My_Pawn_Inventory;
}

void AAA2_PlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAA2_PlayerState, My_Pawn_Inventory);
	DOREPLIFETIME(AAA2_PlayerState, MyState);
	DOREPLIFETIME(AAA2_PlayerState, TeamID);
	DOREPLIFETIME(AAA2_PlayerState, SpawnClass);
	DOREPLIFETIME(AAA2_PlayerState, CurrentWeapon);
}

void AAA2_PlayerState::PostAuthComplete()
{
}

void AAA2_PlayerState::BlinkCharacterOnRadar(float BlinkDuration)
{
	if(GetWorld()->GetTimeSeconds() > RadarBlinkEndTime)
	{
		RadarBlinkStartTime=GetWorld()->GetTimeSeconds();
	}
	if(GetWorld()->GetTimeSeconds() + BlinkDuration > RadarBlinkEndTime)
	{
		RadarBlinkEndTime=GetWorld()->GetTimeSeconds() + BlinkDuration;
	}
}

TWeakObjectPtr < class AActor > AAA2_PlayerState::GetPlayerStart()
{
	return Cast<AHumanController>(GetOwner())->StartSpot;
}

void AAA2_PlayerState::PostBeginPlay()
{
	//SetTimer(0.75,true);
	if(GetLocalRole() < ENetRole::ROLE_MAX)
	{
		return;
	}
	
	if(GetOwner() != nullptr && GetOwner()->IsA(AaAIController::StaticClass()))
	{
		bBot=true;
	}
	SetStartTime(GetWorld()->GetTimeSeconds());
	_LastTimeUpdate=GetStartTime();
}

void AAA2_PlayerState::PostNetBeginPlay()
{
	AGameReplicationInfo* GRI = nullptr;
	AVoiceChatReplicationInfo* VRI = nullptr;
	/*
	if(Level.GRI != nullptr)
	{
		Level.GRI.AddPRI(this);
	}
	else
	{
		ForEach DynamicActors('GameReplicationInfo',GRI)
		{
			GRI.AddPRI(this);
		}
	}
	ForEach DynamicActors('VoiceChatReplicationInfo',VRI)
	{
		VoiceInfo=VRI;
		GOTO JL0074;
JL0074:
	}
	if(Team != nullptr)
	{
		bTeamNotified=true;
	}
	*/
}

bool AAA2_PlayerState::NeedNetNotify()
{
	return ! (bRegisteredChatRoom || !bNoTeam && Team == nullptr);
}

void AAA2_PlayerState::PostNetReceive()
{
	AActor* A = nullptr;
	APlayerController* PC = nullptr;
	/*
	if(! bTeamNotified && Team != nullptr)
	{
		bTeamNotified=true;
		PC=Level.GetLocalPlayerController();
		ForEach DynamicActors('Actor',A)
		{
			if(Cast<APawn>(A) != nullptr && Pawn(A).PlayerReplicationInfo == this)
			{
				Cast<APawn>(A).NotifyTeamChanged();
				if(PC.PlayerReplicationInfo != Self)
				{
				}
			}
			else
			{
				else
				{
					if(A.bNotifyLocalPlayerTeamReceived && PC.PlayerReplicationInfo == this)
					{
						A.NotifyLocalPlayerTeamReceived();
					}
				}
			}
		}
	}
	if(! bRegisteredChatRoom && VoiceInfo != nullptr && PlayerID != Default.PlayerID && VoiceID != Default.VoiceID)
	{
		bRegisteredChatRoom=true;
		VoiceInfo.AddVoiceChatter(this);
	}
	bNetNotify=NeedNetNotify();
	*/
}

void AAA2_PlayerState::Destroyed()
{
	AGameReplicationInfo* GRI = nullptr;
	/*
	if(Level.GRI != nullptr)
	{
		Level.GRI.RemovePRI(this);
	}
	else
	{
		ForEach DynamicActors('GameReplicationInfo',GRI)
		{
			GRI.RemovePRI(this);
		}
	}
	if(VoiceInfo == nullptr)
	{
		ForEach DynamicActors('VoiceChatReplicationInfo',VoiceInfo)
		{
		}
	}
	if(VoiceInfo != nullptr)
	{
		VoiceInfo.RemoveVoiceChatter(this);
	}
	*/
	Super::Destroyed();
}

void AAA2_PlayerState::SetCharacterVoice(FString S)
{
	AVoicePack* NewVoiceType = nullptr;
	if(GetNetMode() == ENetMode::NM_DedicatedServer && VoiceType != nullptr)
	{
		VoiceTypeName=S;
		return;
	}
	if(S == "")
	{
		VoiceTypeName="";
		return;
	}
	//NewVoiceType=class<VoicePack>(DynamicLoadObject(S,Class'Class'));
	if(NewVoiceType != nullptr)
	{
		VoiceType=NewVoiceType;
		VoiceTypeName=S;
	}
}

void AAA2_PlayerState::SetCharacterName(FString S)
{
	CharacterName=S;
}

void AAA2_PlayerState::Reset()
{
	Super::Reset();
	Score_Total=0;
	Score_Leadership=0;
	Score_Wins=0;
	Score_Objectives=0;
	Score_Deaths=0;
	Score_Kills=0;
	Score_ROE=0;
	HasFlag=nullptr;
	bReadyToPlay=false;
	NumLives=0;
	bOutOfLives=false;
}

void AAA2_PlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(fLastConnectionResponseTime > fLastConnectionResponseTimeLimit)
	{
		//Level.Game.AccessControl.Kick(PlayerName,"Connection lost...",false);
	}
}

FString AAA2_PlayerState::GetHumanReadableName() const
{
	return PlayerName;
}

void AAA2_PlayerState::GetPortrait()
{
}

void AAA2_PlayerState::UpdateCharacter()
{
}

void AAA2_PlayerState::UpdatePlayerLocation()
{
	AVolume* V = nullptr;
	AVolume* Best = nullptr;
	APawn p;
	AController* C = nullptr;
	if(GetNetMode() != ENetMode::NM_Client)
	{
		return;
	}
	/*
	C=Controller(GetOwner());
	if(C != nullptr)
	{
		p=C.Pawn;
	}
	if(p == nullptr)
	{
		PlayerVolume=nullptr;
		PlayerZone=nullptr;
		return;
	}
	if(PlayerZone != p.Region.Zone)
	{
		PlayerZone=p.Region.Zone;
	}
	ForEach p.TouchingActors('Volume',V)
	{
		if(V.LocationName == "")
		{
		}
		else
		{
			if(Best != nullptr && V.LocationPriority <= Best.LocationPriority)
			{
			}
			else
			{
				if(V.Encompasses(p))
				{
					Best=V;
				}
			}
		}
	}
	*/
	if(PlayerVolume != Best)
	{
		PlayerVolume=Best;
	}
}

void AAA2_PlayerState::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	if(Team != nullptr)
	{
		Canvas.DrawText("     PlayerName " + PlayerName + " Team " + Team.GetHumanReadableName() + "(" + Team.TeamIndex + ") has flag " + HasFlag);
	}
	else
	{
		Canvas.DrawText("     PlayerName " + PlayerName + " NO Team");
	}
	if(! bBot)
	{
		YPos += YL;
		Canvas.SetPos(4,YL);
		Canvas.DrawText("               bIsSpec:" + bIsSpectator @ "OnlySpec:" + IsOnlyASpectator() @ "Waiting:" + bWaitingPlayer @ "Ready:" + bReadyToPlay @ "OutOfLives:" + bOutOfLives);
	}
	*/
}

void AAA2_PlayerState::ClientNameChange()
{
	APlayerController* PC = nullptr;
	/*
	ForEach DynamicActors('PlayerController',PC)
	{
		PC.ReceiveLocalizedMessage('GameMessage',2,Self);
	}
	*/
}

void AAA2_PlayerState::SetPlayerName(const FString& S)
{
	OldName=PlayerName;
	PlayerName=S;
	/*
		if(Cast<APlayerController>(GetOwner()) != nullptr)
		{
			Cast<APlayerController>(GetOwner())->PlayerOwnerName=S;
		}
	*/
}

void AAA2_PlayerState::SetWaitingPlayer(bool B)
{
	SetIsSpectator(B);
	bWaitingPlayer=B;
}

void AAA2_PlayerState::SetChatPassword(FString InPassword)
{
	if(PrivateChatRoom != nullptr)
	{
		PrivateChatRoom->SetChannelPassword(InPassword);
	}
}

void AAA2_PlayerState::SetVoiceMemberMask(int32 NewMask)
{
	VoiceMemberMask=NewMask;
}

FString AAA2_PlayerState::GetCallSign()
{
	if(TeamID > 14)
	{
		return "";
	}
	return GetDefault<AGameInfo>()->CallSigns[TeamID];
}

FString AAA2_PlayerState::GetNameCallSign()
{
	if(TeamID > 14)
	{
		return PlayerName;
	}
	return PlayerName + " [" + GetDefault<AGameInfo>()->CallSigns[TeamID] + "]";
}

bool AAA2_PlayerState::ContainedInBox(FBox BBox)
{
	if (LocationX >= BBox.Min.X && LocationX <= BBox.Max.X && LocationY >= BBox.Min.Y && LocationY <= BBox.Max.Y && LocationZ >= BBox.Min.Z && LocationZ <= BBox.Max.Z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AAA2_PlayerState::UpdateCommVolume()
{
	ACommVolume* vol = nullptr;
	ACommVolume* Best = nullptr;
	FBox BBox;
	bool bInBox = false;
	/*
	if(GetNetMode() != ENetMode::NM_Client)
	{
		return;
	}
	ForEach AllActors('CommVolume',vol)
	{
		BBox=vol.GetBoundingBox();
		bInBox=ContainedInBox(BBox);
		if(bInBox == true && vol.BetterThan(Best))
		{
			Best=vol;
		}
	}
	CommVol=Best;
	*/
}

AVolume* AAA2_PlayerState::GetCommVolume()
{
	return CommVol;
}

AAGP_Objective* AAA2_PlayerState::GetNearbyObjective(AVolume* C, bool bDefender)
{
	AZoneInfo* Z = nullptr;
	/*
	if (C == nullptr)
	{
		C = GetCommVolume();
	}
	Z = myPawn.Region.Zone;
	if (C != nullptr && C.BetterThan(Z))
	{
		return C.GetNearbyObjective(bDefender);
	}
	else
	{
		return Z.GetNearbyObjective(bDefender);
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

void AAA2_PlayerState::GetLocationName(AVolume* C)
{
	/*
	if(isDead())
	{
		return "";
	}
	if(C == nullptr)
	{
		C=GetCommVolume();
	}
	if(C != nullptr && PlayerZone == nullptr || C.BetterThan(PlayerZone) && C.LocationName != "")
	{
		LastLocationString=C.LocationName;
		return C.LocationName;
	}
	else
	{
		if(PlayerZone != nullptr && PlayerZone.LocationName != "")
		{
			LastLocationString=PlayerZone.LocationName;
			return PlayerZone.LocationName;
		}
		else
		{
			return LastLocationString;
		}
	}
	*/
}

FString AAA2_PlayerState::GetSquadName()
{
	return SquadName;
}

bool AAA2_PlayerState::EquivalentName(FString Name)
{
	if(Name.Compare(PlayerName,ESearchCase::IgnoreCase))
	{
		return true;
	}
	else
	{
		/*
		if(Name == FString::FromInt(PlayerID))
		{
			return true;
		}
		else
		{
			FString TestName;
			TestName = SquadName + PlayerName;
			if(Name.Compare(TestName, ESearchCase::IgnoreCase) )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		*/
	}
	return false;    //FAKE   /ELiZ
}

void AAA2_PlayerState::NotifyPromotion(bool bFTL, uint8 yFT)
{
	//PlayerController(GetOwner())->NotifyPromotion(bFTL,yFT);
}
void AAA2_PlayerState::NotifyNoScore(FName Reason)
{
	_cumRounds ++;
	//PlayerController(GetOwner())->NotifyNoScore(Reason);
}
void AAA2_PlayerState::NotifyClientMessage(FString Message)
{
	Cast<APlayerController>(GetOwner())->ClientMessage(Message);
}
/*================================================================================== = *
*AGP function CalculateWeight()
* Calculate a weight score for this player.
* ROE is used as a tie - breaker.Float values[0.0, 0.99]
*
*last modified by : cmb
* ================================================================================== = */

void AAA2_PlayerState::CalculateWeight(float maxScore)
{
	float roe_lim;
	float froe;
	float fscore;
	fscore=Score_Total * 100 / maxScore;
	roe_lim = Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GetROELimit();
	froe= (roe_lim + Score_ROE) / roe_lim;
		
	//froe= FMath::Min(froe,0.99);
	if (froe < 0.99f)
	{
		froe = 0.99f;
	}
	_fWeight=froe + _iTrust + fscore;
}
float AAA2_PlayerState::GetWeight()
{
	return _fWeight;
}
int32 AAA2_PlayerState::GetHonor()
{
	return _iTrust;
}

bool AAA2_PlayerState::HasGroupIcon()
{
	if(_Group == 1440 || _Group == 1441 || _Group == 1460)
	{
		return true;
	}
	return _Group > 0 && _Group < 25;
}

uint8 AAA2_PlayerState::GetGroup()
{
	if(_Group == 160)
	{
		return 23;
	}
	if(_Group == 161)
	{
		return 24;
	}
	if(_Group == 180)
	{
		return 12;
	}
	return _Group;
}
void AAA2_PlayerState::SetGroup(uint8 newgroup)
{
	_Group=newgroup;
}
void AAA2_PlayerState::SUToggle()
{
	if(SuperUser(false))
	{
		bSUEnabled=! bSUEnabled;
		//NotifyClientMessage("SuperUser set to " + bSUEnabled);
	}
}
bool AAA2_PlayerState::SuperUser(bool bCheckEnabled)
{
	switch(_Group)
	{
		case 1:		//Dev
		case 2:		//ArmyDev
		case 3:		//HomeLAN
		case 7:		//SCI
		case 20:	//AGA
			if(bCheckEnabled)
			{
				return bSUEnabled;
				break;
			}
			else
			{
				return true;
			}
		default:
			return false;
	}
}
bool AAA2_PlayerState::Administrator()
{
	
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsOfficialServer() && !(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer()))
	{
		if(SuperUser(false))
		{
			return bAdmin;
		}
		else
		{
			return false;
		}
	}
	return bAdmin;
	
}
bool AAA2_PlayerState::IsPlayerAdmin()
{
	return bPlayerAdmin;
}
int32 AAA2_PlayerState::GetExperience()
{
	return _Experience;
}
int32 AAA2_PlayerState::GetCumRounds()
{
	return _cumRounds;
}
float AAA2_PlayerState::GetPlayTime()
{
	return GetWorld()->GetTimeSeconds() - _LastTimeUpdate;
}
void AAA2_PlayerState::GetController()
{
	/*
		return Cast<AController>(GetOwner());
	*/
}
void AAA2_PlayerState::ResetPerRound()
{
	APlayerController* PC = nullptr;
	votekick="";
	bIsMedic=false;
	bCallForMedic=false;
	bGuerrillaPS=false;
	bSpecialForcesPS=false;
	bVIPPS=false;
	/*
		if(Level.Game.Stats != nullptr)
		{
			PC=Cast<APlayerController>(GetOwner());
			if(PC != nullptr && PC.PlayerStatsIndex >= 0)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ScoreChange(Score_Total - _prevTotal);
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ROEChange(Score_ROE - _prevROE);
			}
		}
	*/
	_prevTotal=Score_Total;
	_prevLeadership=Score_Leadership;
	_prevWins=Score_Wins;
	_prevObjectives=Score_Objectives;
	_prevDeaths=Score_Deaths;
	_prevKills=Score_Kills;
	_prevROE=Score_ROE;
}
int32 AAA2_PlayerState::GetRoundScore_Total()
{
	return Score_Total - _prevTotal;
}
int32 AAA2_PlayerState::GetRoundScore_Leadership()
{
	return Score_Leadership - _prevLeadership;
}
int32 AAA2_PlayerState::GetRoundScore_Wins()
{
	return Score_Wins - _prevWins;
}
int32 AAA2_PlayerState::GetRoundScore_Objectives()
{
	return Score_Objectives - _prevObjectives;
}
int32 AAA2_PlayerState::GetRoundScore_Deaths()
{
	return Score_Deaths - _prevDeaths;
}
int32 AAA2_PlayerState::GetRoundScore_Kills()
{
	return Score_Kills - _prevKills;
}
int32 AAA2_PlayerState::GetRoundScore_ROE()
{
	return Score_ROE - _prevROE;
}
void AAA2_PlayerState::ClientNotifyLostMedic()
{
	bLostMedic=true;
}
int32 AAA2_PlayerState::GetGoalScore()
{
	return Score_Wins + Score_Objectives;
}
void AAA2_PlayerState::UpdateScore()
{
	
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	Score_Total=0;
	//Score_Total += FMath::Max(0,Score_Leadership);
	Score_Total += Score_Leadership;
	Score_Total += Score_Wins;
	Score_Total += Score_Objectives;
	//Score_Total += FMath::Max(0,Score_Kills + Score_Deaths);
	Score_Total += Score_Kills + Score_Deaths;
	Score_Total += Score_ROE;
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	----" + GetHumanReadableName() + "----"));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	Leadership  " + Score_Leadership));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	Wins        " + Score_Wins));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	Objectives  " + Score_Objectives));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	Kills       " + Score_Kills));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	Deaths      " + Score_Deaths));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	ROE         " + Score_ROE));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	            ------"));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	TOTAL       " + Score_Total));
	//UE_LOG(LogTemp, Warning, TEXT("PRI::UpdateScore()	------------------"));
}

void AAA2_PlayerState::PScoreKill()
{
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		Score_Kills += 1;
	}
	else
	{
		if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GameReplicationInfo->bForceClassUsedInRound)
		{
			Score_Kills += 5;
		}
		else
		{
			Score_Kills += 10;
		}
	}
	UpdateScore();
}
void AAA2_PlayerState::PScoreAIVehicleKill()
{
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	Score_Kills += 10;
	UpdateScore();
}
void AAA2_PlayerState::PScoreDeath()
{
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		Score_Deaths -= 4;
	}
	else
	{
		Score_Deaths -= 10;
	}
	UpdateScore();
}
void AAA2_PlayerState::PScoreFF(int32 newscore)
{
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	Score_ROE -= newscore;
	Score_Total -= newscore;
}
float AAA2_PlayerState::CheckROE()
{
	return -Score_ROE > Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GetROELimit();
}
void AAA2_PlayerState::ScoreDecoMesh(int32 DestroyPoints)
{
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	if(DestroyPoints != 0 && DestroyPoints < 100)
	{
		Score_Objectives += DestroyPoints;
		Score_Total += DestroyPoints;
	}
	else
	{
		Score_Objectives += 20;
		Score_Total += 20;
	}
}
void AAA2_PlayerState::PScoreObjective(int32 newscore)
{
	if(bWaitingPlayer || Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentIsDeadRound())
	{
		return;
	}
	if(newscore > 250)
	{
		newscore=0;
	}
	Score_Objectives += newscore;
	Score_Total += newscore;
}
void AAA2_PlayerState::ScoreRound(bool bWon)
{
	/*
		if(bWaitingPlayer || Level.Game.TournamentIsDeadRound())
		{
			return;
		}
		_cumRounds ++;
		if(bWon)
		{
			if(Level.Game.GameReplicationInfo.bForceClassUsedInRound)
			{
				Score_Wins += Team.GetWinBonus(! isDead()) * 0.75;
			}
			else
			{
				Score_Wins += Team.GetWinBonus(! isDead());
			}
			if(! isDead())
			{
				if(Level.Game.GameReplicationInfo.bForceClassUsedInRound)
				{
					Score_Leadership += CalculateLeaderScore() * 0.75;
				}
				else
				{
					Score_Leadership += CalculateLeaderScore();
				}
			}
		}
		else
		{
			Score_Leadership -= CalculateLeaderPenalty();
		}
		UpdateScore();
		if(CanScore())
		{
			IncrementCumulativeScores();
		}
	*/
}
float AAA2_PlayerState::GetMultiplier()
{
	float fMultiplier;
	int32 OtherTeamSize;
	OtherTeamSize=Team->GetOtherTeam()->Size;
	fMultiplier=0.25 * Team->NumAlive(false, 0) + 0.25;
	fMultiplier *= OtherTeamSize / Team->Size;
	if(Team->Size != Team->NumAlive(false,0))
	{
		fMultiplier *= 0.7 * Team->NumAlive(false, 0) / Team->Size;
	}
	if (fMultiplier >=  1)
	{
		return 1;
	}
	else
	{
		return fMultiplier;
	}
	
}
int32 AAA2_PlayerState::GetSLBonus()
{
	switch (Team->TeamIndex)
	{
		case 0:
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team0_SquadLeaderBonusPerSurvivor;
		case 1:
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team1_SquadLeaderBonusPerSurvivor;
		default:
			return 0;
	}
}
int32 AAA2_PlayerState::GetFTLBonus()
{
	switch (Team->TeamIndex)
	{
		case 0:
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team0_FTLeaderBonusPerSurvivor;
		case 1:
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team1_FTLeaderBonusPerSurvivor;
		default:
			return 0;
	}
}

int32 AAA2_PlayerState::CalculateLeaderScore()
{
	int32 bonus = 0;
	APlayerStart* PS = nullptr;
	if(IsSquadLeader())
	{
		bonus += Team->NumAlive(false,0) * GetSLBonus();
	}
	else
	{
		if(isTeamLeader())
		{
			bonus += Team->NumAlive(true,FT) * GetFTLBonus();
		}
	}
	if(! isDead() && Team->NumAlive(false, 0) > 3)
	{
		/*
		PS=Cast<APlayerStart>(Cast<AController>(GetOwner())->StartSpot);
		if(PS->bSquadLeader)
		{
			bonus += 20;
		}
		else
		{
			if(PS->bFTLeader)
			{
				bonus += 10;
			}
		}
		*/
	}
	return bonus;
}

void AAA2_PlayerState::CalculateLeaderPenalty()
{
	APlayerStart* PS = nullptr;
	/*
	PS=PlayerStart(Cast<AController>(GetOwner())->StartSpot);
	if(PS.bSquadLeader)
	{
		return 10;
	}
	else
	{
		if(PS.bFTLeader)
		{
			return 5;
		}
	}
	*/
}

void AAA2_PlayerState::IncrementCumulativeScores()
{
	_cumTotal       += GetRoundScore_Total();
	_cumLeadership  += GetRoundScore_Leadership();
	_cumWins        += GetRoundScore_Wins();
	_cumObjectives  += GetRoundScore_Objectives();
	_cumDeaths      += GetRoundScore_Deaths();
	_cumKills       += GetRoundScore_Kills();
	_cumROE         += GetRoundScore_ROE();
}
int32 AAA2_PlayerState::CalculateExperience()
{
	int32 newExperience=0;
	//newExperience += FMath::Max(0,_cumLeadership);
	newExperience += _cumLeadership;
	newExperience += _cumWins;
	newExperience += _cumObjectives;
	//newExperience += FMath::Max(0,_cumKills + _cumDeaths);
	newExperience += _cumKills + _cumDeaths;
	newExperience += _cumROE;
	return newExperience;
}
void AAA2_PlayerState::TotalExperience(bool bShowUserDetail)
{
	/*
		_ExperienceDelta=CalculateExperience();
		_Experience += _ExperienceDelta;
		if(bShowUserDetail)
		{
			if(_ExperienceDelta != 0)
			{
				Cast<APlayerController>(GetOwner())->ClientMessage("ROE: " + _cumROE);
				Cast<APlayerController>(GetOwner())->ClientMessage("Deaths: " + _cumDeaths);
				Cast<APlayerController>(GetOwner())->ClientMessage("Kills: " + _cumKills);
				Cast<APlayerController>(GetOwner())->ClientMessage("Wins: " + _cumWins);
				Cast<APlayerController>(GetOwner())->ClientMessage("Objectives: " + _cumObjectives);
				Cast<APlayerController>(GetOwner())->ClientMessage("Leadership: " + _cumLeadership);
				Cast<APlayerController>(GetOwner())->ClientMessage("--------------------------------");
				Cast<APlayerController>(GetOwner())->ClientMessage("Point Details");
				if(! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
				{
					if(bQualifiedViaInstantAction && _iTrust >= 20)
					{
						if(_ExperienceDelta > 0)
						{
							Cast<APlayerController>(GetOwner())->ClientMessage("If you completed Basic Combat Training your Personnel Jacket would be being updated " + _ExperienceDelta + " points towards the next honor level.");
						}
					}
					else
					{
						if(_ExperienceDelta < 0)
						{
							Cast<APlayerController>(GetOwner())->ClientMessage("Your Personnel Jacket is being updated with the loss of " + _ExperienceDelta + " points.");
						}
						else
						{
							Cast<APlayerController>(GetOwner())->ClientMessage("Your Personnel Jacket is being updated with " + _ExperienceDelta + " points towards the next honor level.");
						}
						if(bQualifiedViaInstantAction)
						{
							Cast<APlayerController>(GetOwner())->ClientMessage("Don't forget to complete your training to completely open up all squad roles and weapons.");
						}
					}
				}
			}
		}
	*/
	_cumTotal=0;
	_cumLeadership=0;
	_cumWins=0;
	_cumObjectives=0;
	_cumDeaths=0;
	_cumKills=0;
	_cumROE=0;
}
void AAA2_PlayerState::ResetScores()
{
	//PlayerController(GetOwner())->ServerUploadTrustAndExperience();
	_cumRounds=0;
	//_LastTimeUpdate=GetWorld()->GetTimeSeconds();
	Score_Total=0;
	Score_Leadership=0;
	Score_Wins=0;
	Score_Objectives=0;
	Score_Deaths=0;
	Score_Kills=0;
	Score_ROE=0;
	votekick="";
}
bool AAA2_PlayerState::hasSoldiersCharacter()
{
	return _bSoldiersCharacter;
}
bool AAA2_PlayerState::IsFriend(AAA2_PlayerState* Other, ATeamInfo* otherTeam)
{
	if(Other != nullptr && Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return true;
	}
	if(Other != nullptr && IsOnlyASpectator())
	{
		if(Other->Team->TeamIndex == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(otherTeam == nullptr && Other != nullptr)
	{
		otherTeam=Other->Team;
	}
	if(Team == nullptr || otherTeam == nullptr)
	{
		return Other == this;
	}
	return Team == otherTeam;
}

bool AAA2_PlayerState::IsEnemy(AAA2_PlayerState* Other, ATeamInfo* otherTeam)
{
	return ! IsFriend(Other,otherTeam);
}

void AAA2_PlayerState::Timer()
{
	AController* ctrlrOwner = nullptr;
	/*
	ctrlrOwner=Controller(GetOwner());
	if(GetNetMode() == ENetMode::NM_DedicatedServer && fpTimeSinceLastPingCalculation > GetWorld()->GetTimeSeconds() || GetWorld()->GetTimeSeconds() - fpTimeSinceLastPingCalculation > 10)
	{
		fpTimeSinceLastPingCalculation=GetWorld()->GetTimeSeconds();
		if(! bBot && ! bReceivedPing)
		{
			if(ctrlrOwner != nullptr)
			{
				Ping=Min(0.25 * ctrlrOwner.ConsoleCommand("GETPING"),255);
			}
		}
	}
	if(myPawn != nullptr)
	{
		LocationX=myPawn.Location.X;
		LocationY=myPawn.Location.Y;
		LocationZ=myPawn.Location.Z;
	}
	else
	{
		if(ctrlrOwner != nullptr && ctrlrOwner.Pawn != nullptr)
		{
			LocationX=ctrlrOwner.Pawn.Location.X;
			LocationY=ctrlrOwner.Pawn.Location.Y;
			LocationZ=ctrlrOwner.Pawn.Location.Z;
		}
	}
	if(GetNetMode() == ENetMode::NM_Client)
	{
		if(ctrlrOwner == nullptr || ctrlrOwner.Pawn == nullptr)
		{
			PlayerVolume=nullptr;
			PlayerZone=nullptr;
			CommVol=nullptr;
		}
		else
		{
			UpdateCommVolume();
			UpdatePlayerLocation();
		}
		if(PlayerVolume != LastPlayerVolume || PlayerZone != LastPlayerZone || CommVol != LastCommVol)
		{
			ServerUpdateVolumeZone(PlayerVolume,PlayerZone,CommVol);
			LastPlayerVolume=PlayerVolume;
			LastPlayerZone=PlayerZone;
			LastCommVol=CommVol;
		}
	}
	UpdatePawnYaw();
	*/
}
/*
void AAA2_PlayerState::ServerUpdateVolumeZone(AVolume* volNewPlayerVolume, AZoneInfo* volNewPlayerZone, AVolume* volNewCommVol)
{
		PlayerVolume=volNewPlayerVolume;
		PlayerZone=volNewPlayerZone;
		CommVol=volNewCommVol;
}
*/
void AAA2_PlayerState::TeamReset()
{
}

FVector AAA2_PlayerState::GetPawnLocation()
{
	FVector loc = FVector(0, 0, 0);
	if (myPawn != nullptr)
	{
		return myPawn->GetActorLocation();
	}
	else
	{
		loc.X = float(LocationX);
		loc.Y = float(LocationY);
		loc.Z = float(LocationZ);
		return loc;
	}
}

void AAA2_PlayerState::GetPawnYaw()
{
	/*
		if(myPawn != nullptr)
		{
			return myPawn.Rotation.Yaw;
		}
		else
		{
			return PawnYaw;
		}
	*/
}
void AAA2_PlayerState::UpdatePawnYaw()
{
	if(myPawn != NULL)
	{
		//PawnYaw=myPawn.Rotation.Yaw;
	}
}
void AAA2_PlayerState::ServerSetMyPawn(APawn* new_pawn)
{
	/*
		myPawn=new_pawn;
		UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo::ServerSetMyPawn()	" + new_pawn));
	*/
}

void AAA2_PlayerState::WaitingForPawn(AAA2_PlayerState* PRI)
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo::WaitingForPawn()	" + this @ PRI));
	if(myPawn != nullptr)
	{
		PRI.FoundWaitingForPawn(myPawn);
	}
	else
	{
		PRI_WaitingForPawn=PRI;
	}
	*/
}

void AAA2_PlayerState::FoundWaitingForPawn(APawn* p)
{
	APlayerController* C = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo::FoundWaitingForPawn()	" + this @ p));
	C=Cast<APlayerController>(GetOwner());
	if(C != nullptr)
	{
		C.FoundWaitingForPawn(p);
	}
	*/
}

APawn* AAA2_PlayerState::GetMyPawn()
{
	return myPawn;
}

bool AAA2_PlayerState::isDead()
{
	return bDead || IsSpectator() || IsOnlyASpectator() || bWaitingPlayer || bOutOfLives;
}

bool AAA2_PlayerState::isSpectator()
{
	return IsSpectator() || IsOnlyASpectator();
}

bool AAA2_PlayerState::IsSquadLeader()
{
	return (GetSquadLeader() == this);
}

bool AAA2_PlayerState::isTeamLeader()
{
	return (GetFTLeader() == this);
}

AAA2_PlayerState* AAA2_PlayerState::GetSquadLeader()
{
	if(Team != NULL)
	{
		return Team->GetSquadLeader(this);
	}
	else
	{
		return this;
	}
}
AAA2_PlayerState* AAA2_PlayerState::GetFTLeader()
{
	if(Team != NULL)
	{
		return Team->GetFTLeader(this);
	}
	else
	{
		return this;
	}
}

void AAA2_PlayerState::SubmitPlayerRequest(int32 UnitID, int32 Index)
{
	Team->SubmitPlayerRequest(this,UnitID,Index);
}

void AAA2_PlayerState::RemovePlayerRequest(AAA2_PlayerState* PRI)
{
	if(Team->TeamIndex == 255)
	{
		PRI->Team->RemovePlayerRequest(PRI);
	}
	else
	{
		Team->RemovePlayerRequest(PRI);
	}
}

bool AAA2_PlayerState::CanScore()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("Verifying scoring rules, temp disable scoring: " + Level.Game.GameReplicationInfo.bTempDisableRoundScoring));
	if(Level.Game.GameReplicationInfo.bTempDisableRoundScoring)
	{
		Cast<APlayerController>(GetOwner())->ClientMessage("Scoring disabled for rounds where forceclassing was used.");
		UE_LOG(LogTemp, Warning, TEXT("Force classing preventing scoring update"));
		return false;
	}
	if(! Level.Game.CheatsDisabled())
	{
		Cast<APlayerController>(GetOwner())->ClientMessage("Scoring disabled for round on cheats enabled server.");
		Log("Cheats preventing scoring update");
		return false;
	}
	if(Team.CheckIf_NoEnemy() || Team.CheckIf_SmallGame())
	{
		return false;
	}
	*/
	return true;
}
