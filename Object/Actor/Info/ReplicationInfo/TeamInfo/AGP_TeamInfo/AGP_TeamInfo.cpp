// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_Playerstart/AGP_Playerstart.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/PSSet/PSSet.h"

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRifleman.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoIron/ClassRiflemanM4A1AutoIron.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoIron/ClassRiflemanM4A1Auto/ClassRiflemanM4A1Auto.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRiflemanBare/ClassRiflemanBare.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGrenadier/ClassGrenadier.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSniperBase/ClassSniper/ClassSniper.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSniperBase/ClassSniper24_US/ClassSniper24_US.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassAutomaticRifleman/ClassAutomaticRifleman.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeam.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaBase.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassGuerrillaVIPPS/ClassGuerrillaVIPPS.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSF18BPS/ClassSF18BPS.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassVIPPS/ClassVIPPS.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameTournament/AGP_GameTournament.h"

AAGP_TeamInfo::AAGP_TeamInfo()
{
	bDead = true;
	bTeamReady = true;
	LinkUpdateFrequency = 1.5;
	LinkTimerThreshold = 1;
	MaxLinkDistance = 6000;
	MaxIndirectLinkDistance = 6000;
	TracingPlayerIndex = -1;
	PlayerWeight.SetNum(32);
	FTCount.SetNum(5);
	FTEnabled.SetNum(5);
	Temp.SetNum(32);
	RequestList_Player.SetNum(32);
	RequestList_UnitID.SetNum(32);
	RequestList_Index.SetNum(32);
	RequestList_StartSpot.SetNum(32);
	NoRequest.SetNum(32);
	NoRequest_Timer.SetNum(32);
}

void AAGP_TeamInfo::SetupTeam()
{
	CountFireTeams();
	SetupRequestList();
}
void AAGP_TeamInfo::SetupRequestList()
{
	int32 curr;
	int32 i = 0;
	int32 j = 0;
	curr=0;
	GeneratePSList();
	for (i=0; i<5; i++)
	{
		for (j=0; j<FTCount[i]; j++)
		{
			RequestList_UnitID[curr]=i;
			RequestList_Index[curr]=j;
			RequestList_Player[curr] = nullptr;
			RequestList_StartSpot[curr]=GetStartSpot(i,j);
			curr ++;
		}
	}
	NumRequestSlots=curr;
	for (i=curr; i<32; i++)
	{
		RequestList_UnitID[i]=255;
	}
}

void AAGP_TeamInfo::GeneratePSList()
{
	ANavigationPoint* N = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		PS = Cast<AAGP_PlayerStart>(N);
		if (((PS != nullptr) && PS->bEnabled) && (PS->GetTeamID() == TeamIndex))
		{
			AddToPSList(PS);
		}
	}
}

void AAGP_TeamInfo::AddToPSList(AAGP_PlayerStart* Add)
{
	AAGP_PlayerStart* PS = nullptr;
	AAGP_PlayerStart* Prev = nullptr;
	/*
	if (PSList == nullptr)
	{
		PSList = Add;
		PSList->nextPS = nullptr;
		return;
	}
	for (PS = PSList; PS != nullptr; PS = PS->nextPS)
	{
		if (Compare(Add, PS))
		{
			InsertPS(Prev, Add, PS);
			return;
		}
		Prev = PS;
	}
	InsertPS(Prev, Add, nullptr);
	*/
}

void AAGP_TeamInfo::InsertPS(AAGP_PlayerStart* Prev, AAGP_PlayerStart* ins, AAGP_PlayerStart* Next)
{
	if (Prev == nullptr)
	{
		//PSList=ins;
	}
	else
	{
		//Prev->nextPS=Cast<AAGP_PlayerStart>(ins);
	}
	//ins->nextPS= Cast<AAGP_PlayerStart>(Next);
}

bool AAGP_TeamInfo::Compare(AAGP_PlayerStart* PS1, AAGP_PlayerStart* PS2)
{
	EWeaponType Weapon1 = EWeaponType::WEAPON_None;
	EWeaponType Weapon2 = EWeaponType::WEAPON_None;
	/*
	if (PS1.bSquadLeader)
	{
		return true;
	}
	else
	{
		if (PS2.bSquadLeader)
		{
			return false;
		}
	}
	if (PS1.bGuerrilla != PS2.bGuerrilla)
	{
		return ! PS1.bGuerrilla;
	}
	if (PS1.getFT() != PS2.getFT())
	{
		return PS1.getFT() < PS2.getFT();
	}
	else
	{
		if (PS1.bFTLeader)
		{
			return true;
		}
		else
		{
			if (PS2.bFTLeader)
			{
				return false;
			}
		}
		Weapon1=PS1.GetSpawnClass().Default.nativeWeapon;
		Weapon2=PS2.GetSpawnClass().Default.nativeWeapon;
		if (Weapon1 != Weapon2)
		{
			return CompareScore(Weapon1) <= CompareScore(Weapon2);
		}
		else
		{
			return PS1.fBaseScore < PS2.fBaseScore;
		}
	}
	*/
	return false;   //FAKE  /ELiZ
}
int32 AAGP_TeamInfo::CompareScore(EWeaponType W)
{
	switch(W)
	{
		case EWeaponType::WEAPON_Rifle:
			return 10;
		case EWeaponType::WEAPON_Gren:
			return 20;
		case EWeaponType::WEAPON_SAW:
			return 30;
		case EWeaponType::WEAPON_Sniper:
			return 40;
		default:
			return 99;
	}
}
AAGP_PlayerStart* AAGP_TeamInfo::GetStartSpot(uint8 UnitID, uint8 Index)
{
	AAGP_PlayerStart* PS = nullptr;
	uint8 test_index = 0;
	uint8 test_FT = 0;
	/*
	test_FT = uint8((UnitID - 1));
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if (PS.getFT() == test_FT)
		{
			if (Index == test_index)
			{
				return PS;
			}
			else
			{
				test_index++;
			}
		}
	}
	DebugLog(DEBUG_Warn, "Could not find start spot for " @ FString::FromInt(UnitID) @ FString::FromInt(Index) @ FString::FromInt(test_FT));
	*/
	return nullptr;
}

int32 AAGP_TeamInfo::CountAdmins()
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->bAdmin == true)
		{
			Count ++;
		}
	}
	return Count;
}
AAA2_PlayerState* AAGP_TeamInfo::GetAdmin(int32 Index)
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->bAdmin == true)
		{
			if (Count == Index)
			{
				return TeamList[i];
			}
			else
			{
				Count ++;
			}
		}
	}
	return nullptr;
}

int32 AAGP_TeamInfo::CountSpectators()
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->IsOnlyASpectator() == true && TeamList[i]->bAdmin == false)
		{
			Count ++;
		}
	}
	return Count;
}

AAA2_PlayerState* AAGP_TeamInfo::GetSpectator(int32 Index)
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->IsOnlyASpectator() == true && TeamList[i]->bAdmin == false)
		{
			if (Count == Index)
			{
				return TeamList[i];
			}
			else
			{
				Count ++;
			}
		}
	}
	return nullptr;
}

int32 AAGP_TeamInfo::CountUnassigned()
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->bWaitingPlayer && TeamList[i]->bAdmin == false || TeamList[i]->IsOnlyASpectator() == false)
		{
			Count ++;
		}
	}
	return Count;
}

int32 AAGP_TeamInfo::CountAssigned()
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (! TeamList[i]->bWaitingPlayer && TeamList[i]->bAdmin == false || TeamList[i]->IsOnlyASpectator() == false)
		{
			Count ++;
		}
	}
	return Count;
}

AAA2_PlayerState* AAGP_TeamInfo::GetUnassigned(int32 Index)
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->bWaitingPlayer && TeamList[i]->bAdmin == false || TeamList[i]->IsOnlyASpectator() == false)
		{
			if (Count == Index)
			{
				return TeamList[i];
			}
			else
			{
				Count ++;
			}
		}
	}
	return nullptr;
}

AAA2_PlayerState* AAGP_TeamInfo::GetAssigned(int32 Index)
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<Size; i++)
	{
		if (! TeamList[i]->bWaitingPlayer && TeamList[i]->bAdmin == false || TeamList[i]->IsOnlyASpectator() == false)
		{
			if (Count == Index)
			{
				return TeamList[i];
			}
			else
			{
				Count ++;
			}
		}
	}
	return nullptr;
}

AAA2_PlayerState* AAGP_TeamInfo::GetNoRequest(int32 Index)
{
	return NoRequest[Index];
}

int32 AAGP_TeamInfo::GetNoRequestTimer(int32 Index)
{
	return NoRequest_Timer[Index];
}

AAA2_PlayerState* AAGP_TeamInfo::GetPlayerRequest(int32 UnitID, int32 Index)
{
		return RequestList_Player[GetRealIndex(UnitID,Index)];
}

AAGP_PlayerStart* AAGP_TeamInfo::GetPlayerStart(int32 UnitID, int32 Index)
{
	return RequestList_StartSpot[GetRealIndex(UnitID,Index)];
}
AAA2_PlayerState* AAGP_TeamInfo::GetPlayerActual(int32 UnitID, int32 Index)
{
	return ActualList_Player[GetRealIndex(UnitID,Index)];
}
AAA2_PlayerState* AAGP_TeamInfo::GetPlayerPending(int32 UnitID, int32 Index)
{
	return PendingRequests[GetRealIndex(UnitID,Index)].PRI;
}
int32 AAGP_TeamInfo::GetPendingRequestIndex(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<PendingRequests.Max(); i++)
	{
		if (PendingRequests[i].PRI == PRI)
		{
			return i;
		}
	}
	return -1;
}
int32 AAGP_TeamInfo::GetPlayerRequestIndex(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (RequestList_Player[i] == PRI)
		{
			return i;
		}
	}
	return -1;
}
int32 AAGP_TeamInfo::GetPlayerUnitID(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (ActualList_Player[i] == PRI)
		{
			return RequestList_UnitID[i];
		}
	}
	return -1;
}
int32 AAGP_TeamInfo::GetPlayerIndex(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (ActualList_Player[i] == PRI)
		{
			return RequestList_Index[i];
		}
	}
	return -1;
}
int32 AAGP_TeamInfo::CountActivePlayers()
{
	int32 i = 0;
	int32 Count=0;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (ActualList_Player[i] != nullptr)
		{
			Count ++;
		}
	}
	return Count;	
}
bool AAGP_TeamInfo::IsFTEmpty(uint8 UnitID)
{
	int32 i = 0;
	for (i=GetRealIndex(UnitID,0); i<NumRequestSlots; i++)
	{
		if (RequestList_UnitID[i] != UnitID)
		{
			return true;
		}
		else
		{
			if (ActualList_Player[i] != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
int32 AAGP_TeamInfo::GetRealIndex(int32 UnitID, int32 Index)
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (RequestList_UnitID[i] == UnitID && RequestList_Index[i] == Index)
		{
			return i;
		}
	}
	//DebugLog(DEBUG_Warn,"Unable to find UnitID" @ UnitID @ "and Index" @ Index @ "in the RequestList");
	return -1;
}
void AAGP_TeamInfo::SubmitPlayerRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index)
{
	int32 RealIndex;
	if (! CanSelect(PRI))
	{
		SubmitPendingRequest(PRI,UnitID,Index);
		return;
	}
	RealIndex=GetRealIndex(UnitID,Index);
	if (RequestList_Player[RealIndex] != nullptr && RequestList_Player[RealIndex] != PRI)
	{
		PRI->SwapRequest=RealIndex;
		if (ShouldSwap(RequestList_Player[RealIndex],PRI))
		{
			SwapPlayerRequests(RequestList_Player[RealIndex],PRI);
		}
	}
	else
	{
		AssignPlayerRequest(PRI,RealIndex);
	}
}
void AAGP_TeamInfo::AssignPlayerRequest(AAA2_PlayerState*  PRI, int32 Index)
{
	int32 old_index;
	old_index=GetPlayerRequestIndex(PRI);
	ClearPlayerRequests(PRI);
	RequestList_Player[Index]=PRI;
	CheckSwaps(old_index);
	TestMedics();
}
void AAGP_TeamInfo::RemovePlayerRequest(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (RequestList_Player[i] == PRI)
		{
			PRI->SwapRequest=-1;
			AddToNoRequestList(PRI,false);
			RequestList_Player[i]=nullptr;
			return;
		}
	}
}

bool AAGP_TeamInfo::ShouldSwap(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2)
{
	return WantsToSwap(PRI1,PRI2) && WantsToSwap(PRI2,PRI1);
}

bool AAGP_TeamInfo::WantsToSwap(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2)
{
	if (PRI1->SwapRequest != -1 && PRI1->SwapRequest == GetPlayerRequestIndex(PRI2))
	{
		return true;
	}
	return false;
}

void AAGP_TeamInfo::SwapPlayerRequests(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2)
{
	
	int32 i = 0;
	int32 index1 = 0;
	int32 index2 = 0;
	bool bFound1 = false;
	bool bFound2 = false;
	for (i=0; i<NumRequestSlots; i++)
	{
		if (RequestList_Player[i] == PRI1)
		{
			index1=i;
			bFound1=true;
		}
		else
		{
			if (RequestList_Player[i] == PRI2)
			{
				index2=i;
				bFound2=true;
			}
		}
	}
	if (bFound1 && bFound2)
	{
		ClearPlayerRequests(PRI1);
		ClearPlayerRequests(PRI2);
		RequestList_Player[index1]=PRI2;
		RequestList_Player[index2]=PRI1;
		TestMedics();
	}
}

bool AAGP_TeamInfo::CanSelect(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<32; i++)
	{
		if (PRI == NoRequest[i])
		{
			return NoRequest_Timer[i] <= 0;
		}
	}
	return true;
}

void AAGP_TeamInfo::ClearPlayerRequests(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	PRI->SwapRequest=-1;
	RemoveFromNoRequestList(PRI);
	for (i=0; i<NumRequestSlots; i++)
	{
		if (RequestList_Player[i] == PRI)
		{
			RequestList_Player[i]=nullptr;
			return;
		}
	}
}

void AAGP_TeamInfo::CheckSwaps(int32 swap_index)
{
	int32 i = 0;
	AAA2_PlayerState* Swap = nullptr;
	if (swap_index < 0 || swap_index > NumRequestSlots)
	{
		return;
	}
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->SwapRequest == swap_index)
		{
			if (Swap == nullptr || TeamList[i]->GetWeight() > Swap->GetWeight())
			{
				Swap=TeamList[i];
			}
		}
	}
	if (Swap != nullptr)
	{
		AssignPlayerRequest(Swap,swap_index);
	}
}

void AAGP_TeamInfo::AddToNoRequestList(AAA2_PlayerState*  PRI, bool bSortAdd)
{
	int32 i = 0;
	int32 j = 0;
	for (i=0; i<32; i++)
	{
		if (NoRequest[i] == nullptr)
		{
			NoRequest[i]=PRI;
			NoRequest_Timer[i]=ReadyTimer;
			return;
		}
		else
		{
			if (bSortAdd)
			{
				if (BetterThan(PRI,NoRequest[i]))
				{
					for (j=31; j>i; j--)
					{
						NoRequest[j]=NoRequest[j - 1];
					}
					NoRequest[i]=PRI;
					return;
				}
			}
		}
	}
}

bool AAGP_TeamInfo::BetterThan(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2)
{
	return PRI1->GetWeight() > PRI2->GetWeight();
}

/* =================================================================================== *
 * AGP function RemoveFromNoRequestList()
 *	Remove a player from the NoRequestList.
 *	Slide every other player down the list.
 *
 * last modified by: cmb
 * =================================================================================== */

void AAGP_TeamInfo::RemoveFromNoRequestList(AAA2_PlayerState* PRI)
{
	int32 i, j;
	j = 0;
	for (i = 0; i < 32; i++)
	{
		if (NoRequest[i] == PRI)
		{
			NoRequest[i] = nullptr;
		}
		else
		{
			NoRequest[j] = NoRequest[i];
			j++;
		}
	}
	PRI->_fWeight = 0;
}

void AAGP_TeamInfo::FindPSStartIndexes(APSSet* UseSet)
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		RequestList_StartSpot[i]->FindNewStartIndex(UseSet);
	}
}

void AAGP_TeamInfo::AssignStartPoints()
{
	/*
		AAA2_PlayerState* PRI;
		int32 i = 0;
		int32 j = 0;
		for (i=0; i<NumRequestSlots; i++)
		{
			PRI=RequestList_Player[i];
			if (PRI != nullptr)
			{
				if (Cast<AHumanController>(PRI.Owner) != nullptr && ! Cast<AHumanController>(PRI.Owner).bPBChecked)
				{
				}
				Controller(PRI.Owner).StartSpot=RequestList_StartSpot[i];
				RequestList_StartSpot[i].bEnabled=false;
			}
			else
			{
				ActualList_Player[i]=PRI;
			}
		}
		for (i=0; i<Size; i++)
		{
			if (Cast<AController>(TeamList[i].Owner).StartSpot == nullptr)
			{
				if (Cast<AHumanController>(TeamList[i].Owner) != nullptr && ! Cast<AHumanController>(TeamList[i].Owner).bPBChecked)
				{
				}
				j=0;
				if (j < NumRequestSlots)
				{
					if (RequestList_StartSpot[j].bEnabled && IsEnabled(RequestList_UnitID[j]))
					{
						Controller(TeamList[i].Owner).StartSpot=RequestList_StartSpot[j];
						RequestList_StartSpot[j].bEnabled=false;
						ActualList_Player[j]=TeamList[i];
					}
					else
					{
						j ++;
					}
				}
			}
		}
		VerifyVIP();
		AssignMedics();
	*/
}
void AAGP_TeamInfo::VerifyVIP()
{
	int32 i = 0;
	int32 newvip;
	if (bVIP)
	{
		if (ActualList_Player[0] == nullptr)
		{
			newvip=FMath::RandRange(0,Size);
			if (TeamList[newvip] != nullptr)
			{
				//Cast<AController>(TeamList[newvip].Owner)->StartSpot=RequestList_StartSpot[0];
				TeamList[newvip]->bWillBeMedic=false;
			}
			i=0;
			if (i < NumRequestSlots)
			{
				if (ActualList_Player[i] == TeamList[newvip])
				{
					ActualList_Player[i]= nullptr;
				}
				else
				{
					i ++;
				}
			}
			ActualList_Player[0]=TeamList[newvip];
		}
	}
}
void AAGP_TeamInfo::MatchEndReset()
{
	int32 i = 0;
	AHumanController* HC;
	ResetAllRequests();
	SetupTimers();
	for (i=0; i<NumRequestSlots; i++)
	{
		if (ActualList_Player[i] != nullptr)
		{
			HC = Cast<AHumanController>(ActualList_Player[i]->GetOwner());

			if (HC != nullptr && HC->PlayerStatsIndex >= 0)
			{
				HC->PlayerStatsIndex=-1;
			}
		}
	}
}

bool AAGP_TeamInfo::ConfirmReady()
{
	return bTeamReady;
}

void AAGP_TeamInfo::Timer()
{
	int32 subtract = 0;
	int32 i = 0;
	bool bWaiting = false;
	bool bNoRequest = false;

	//Super::Timer();
	/*
	if (ShowScoresTime > 1)
	{
		subtract=1;
		ShowScoresTime --;
	}
	else
	{
		if (ShowScoresTime != 0)
		{
			ShowScoresTime=0;
			if (! Level.Game.IsTournamentMode())
			{
				ShowClassSelectionMenu();
			}
		}
		subtract=Max(NoRequest_Timer[0],1);
	}
	ReadyTimer -= subtract;
	for (i=0; i<32; i++)
	{
		if (NoRequest[i] == nullptr)
		{
			NoRequest_Timer[i]=0;
		}
		else
		{
			bNoRequest=true;
			if (NoRequest_Timer[i] > 0)
			{
				NoRequest_Timer[i]=FMax(0,NoRequest_Timer[i] - subtract);
			}
			if (NoRequest_Timer[i] <= 0)
			{
				CheckPendingRequests(NoRequest[i]);
			}
			else
			{
				bWaiting=true;
			}
		}
	}
	if (! bNoRequest || ! bWaiting && ReadyTimer < 1)
	{
		PendingRequests->Remove(0,PendingRequests.Num());
		bTeamReady=true;
		SetTimer(0,false);
		ReadyTimer=0;
	}
	*/
}
void AAGP_TeamInfo::CheckPendingRequests(AAA2_PlayerState*  PRI)
{
	int32 i = 0;
	for (i=0; i<PendingRequests.Max(); i++)
	{
		if (PendingRequests[i].PRI == PRI)
		{
			SubmitPlayerRequest(PRI,PendingRequests[i].UnitID,PendingRequests[i].Index);
			PendingRequests.RemoveAt(i,1);
			return;
		}
	}
}
void AAGP_TeamInfo::SubmitPendingRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index)
{
	int32 i = 0;
	FsPendingRequest NewRequest;
	for (i=0; i<PendingRequests.Max(); i++)
	{
		if (PendingRequests[i].PRI == PRI)
		{
			PendingRequests[i].UnitID = UnitID;
			PendingRequests[i].Index  = Index;
			return;
		}
	}
	NewRequest.PRI = PRI;
	NewRequest.UnitID = UnitID;
	NewRequest.Index = Index;
	PendingRequests.Add(NewRequest);
}

void AAGP_TeamInfo::ShowClassSelectionMenu()
{
	int32 i = 0;
	/*
	for (i=0; i<Size; i++)
	{
		if (! Level.Game.IsTournamentMode())
		{
			Cast<APlayerController>(TeamList[i].Owner).ClientOpenMenu("ACL_Interface.AAGameMenu",,"Roster");
		}
		else
		{
			Cast<APlayerController>(TeamList[i].Owner).ClientOpenMenu("ACL_Interface.AAGameMenu",,"Weapon Class");
		}
	}
	*/
}

void AAGP_TeamInfo::SetupTimers()
{
	bool bSomeone = false;
	int32 i = 0;
	float fPer = 0;
	int32 iPer = 0;
	fPer=45 / Size;
	//iPer=Min(fPer,8);
	if (Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld()))->ShouldShowScores())
	{
		ShowScoresTime=3;
	}
	else
	{
		/*
		if (!UGameplayStatics::GetGameMode(GetWorld())->IsTournamentMode())
		{
			ShowClassSelectionMenu();
		}
		*/
		ShowScoresTime=0;
	}
	/*
	ReadyTimer=3 + ShowScoresTime;
	for (i=0; i<32; i++)
	{
		if (NoRequest[i] != nullptr)
		{
			bSomeone=true;
			NoRequest_Timer[i]=i * iPer + ShowScoresTime;
			ReadyTimer=Max(ReadyTimer,NoRequest_Timer[i] + 3);
		}
	}
	if (bSomeone)
	{
		bTeamReady=false;
		SetTimer(1,true);
	}
	else
	{
		bTeamReady=true;
	}
	*/
}

void AAGP_TeamInfo::ResetAllRequests()
{
	int32 i = 0;
	for (i=0; i<NumRequestSlots; i++)
	{
		RequestList_Player[i]= nullptr;
	}
	for (i=0; i<32; i++)
	{
		NoRequest[i]=nullptr;
	}
	CalculatePlayerWeights();
	for (i=0; i<Size; i++)
	{
		AddToNoRequestList(TeamList[i],true);
	}
}
void AAGP_TeamInfo::CalculatePlayerWeights()
{
	int32 i = 0;
	float maxScore=0;
	for (i=0; i<Size; i++)
	{
		if (TeamList[i]->Score_Total > maxScore)
		{
			maxScore=TeamList[i]->Score_Total;
		}
	}
	for (i=0; i<Size; i++)
	{
		TeamList[i]->CalculateWeight(maxScore);
	}
}
void AAGP_TeamInfo::MatchStarting()
{
	int32 i = 0;
	//Super::MatchStarting();
	ReadyTimer=0;
	for (i=0; i<32; i++)
	{
		NoRequest_Timer[i]=0;
	}
}
void AAGP_TeamInfo::RecordStartMatch()
{
	/*
		int32 i = 0;
		APlayerController* PC = nullptr;
		if (Level.Game.Stats != nullptr)
		{
			for (i=0; i<NumRequestSlots; i++)
			{
				if (ActualList_Player[i] != nullptr)
				{
					PC=Cast<APlayerController>(ActualList_Player[i].Owner);
					if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundStarted();
						if (ActualList_Player[i].bIsMedic)
						{
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundStartedAsMedic();
						}
						if (ActualList_Player[i].IsSquadLeader())
						{
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundStartedAsSQL();
						}
						else
						{
							if (ActualList_Player[i].isTeamLeader())
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundStartedAsFTL();
							}
							else
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundStartedAsSoldier();
							}
						}
					}
				}
			}
		}
	*/
}

void AAGP_TeamInfo::CountFireTeams()
{
	ANavigationPoint* N = nullptr;
	AAGP_PlayerStart* S = nullptr;
	bool bFoundAny = false;
	TArray<uint8> FTNumL = { 0,0,0,0,0 };
	int32 i = 0;
	MaxSize = 0;
	/*
	for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
	{
		S = AGP_PlayerStart(N);
		if ((S != nullptr) && (S.GetTeamID() == TeamIndex))
		{
			bFoundAny = true;
			MaxSize++;
			if (S->IsA(AClassVIPPS::StaticClass()) || S->IsA(AClassGuerrillaVIPPS::StaticClass()))
			{
				if (bVIP)
				{
					DebugLog(DEBUG_Error, "Don't know how to handle multiple VIPS! " + FString::FromInt(S));
				}
				if (!S.bSquadLeader)
				{
					DebugLog(DEBUG_Error, "Don't know how to handle VIP who is not Squad Leader! " + FString::FromInt(S));
				}
				bVIP = true;
			}
			if (S.FireTeam == 0)
			{
				if (!S.bSquadLeader)
				{
					DebugLog(DEBUG_Warn, "No FireTeam found. Moving to Delta " + FString::FromInt(S));
					S.FireTeam = 4;
				}
			}
			else
			{
				if (S.bFTLeader)
				{
					FTNumL[S.FireTeam] ++;
				}
				if (S.bSquadLeader)
				{
					DebugLog(DEBUG_Warn, "Found FTMember with SquadLeader flag set. Turning flag off " + FString::FromInt(S));
					S.bSquadLeader = false;
				}
			}
			FTCount[S.FireTeam] ++;
		}
	}
	if ((!Level.bCoOpGame) && (TeamIndex == 1))
	{
		if (!bFoundAny)
		{
			DebugLog(DEBUG_Error, "No AGP_PlayerStarts found for team " + FString::FromInt(this) + ".  Add playerstarts or rebuild paths.");
		}
		if (FTCount[0] != 1)
		{
			DebugLog(DEBUG_Error, "Invalid number of Squad Leaders: " @ FString::FromInt(FTCount[0]));
		}
		for (i = 1; i < 5; i++)
		{
			if ((FTCount[i] > 0) && (FTNumL[i] != 1))
			{
				DebugLog(DEBUG_Error, "Invalid number of FireTeam Leaders at" @ FString::FromInt(i) + ":" @ FString::FromInt(FTNumL[i]));
			}
		}
	}
	*/
}

bool AAGP_TeamInfo::IsEnabled(uint8 Team)
{
	return FTEnabled[Team] == 1;
}

void AAGP_TeamInfo::DisableFT(uint8 Team)
{
	FTEnabled[Team]=0;
}

int32 AAGP_TeamInfo::EnableFT(uint8 Team)
{
	FTEnabled[Team]=1;
	return FTCount[Team];
}

void AAGP_TeamInfo::FindValidFireTeams()
{
	int32 i = 0;
	int32 Available;
	int32 ASSIGN_FIRST;
	int32 ASSIGN_SECOND;
	bool bForceAllWeaponClassOn = false;
	if (Cast<AAGP_GameInfo>(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game) != nullptr)
	{
		bForceAllWeaponClassOn=Cast<AAGP_GameInfo>(Cast<AAA2_WorldSettings>(GetWorldSettings())->Game)->bOpenAllWeaponClassSlots;
	}
	if (bForceAllWeaponClassOn || Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->IsTournamentMode() && Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentAreAllWeaponClassesAvailable())
	{
		for (i=0; i<5; i++)
		{
			EnableFT(i);
		}
		return;
	}
	else
	{
		for (i=0; i<5; i++)
		{
			DisableFT(i);
		}
	}
	if (bVIP)
	{
		ASSIGN_FIRST=0;
		ASSIGN_SECOND=1;
	}
	else
	{
		ASSIGN_FIRST=1;
		ASSIGN_SECOND=0;
	}
	Available=EnableFT(ASSIGN_FIRST);
	if (Available < Size)
	{
		Available += EnableFT(ASSIGN_SECOND);
		for (i=2; i<5; i++)
		{
			if (Available >= Size)
			{
			}
			Available += EnableFT(i);
		}
	}
	if (Available < Size)
	{
		//DebugLog(DEBUG_Error,"Not enough PlayerStarts! " @ Available @ Size);
	}
}

void AAGP_TeamInfo::CountAvailablePlayerStarts()
{
	ANavigationPoint* N = nullptr;
	AAGP_PlayerStart* S = nullptr;
	bool bFoundM4Auto = false;
	bool bFoundM4 = false;
	bool bFoundM16 = false;
	bool bFoundM249 = false;
	bool bFoundAny = false;
	int32 i = 0;
	if (bSpectatorTeam)
	{
		return;
	}
	FindValidFireTeams();
	NumLeadersAvailable = 0;
	for (i = 0; i < 7; i++)
	{
		NumAvailable[i] = 0;
	}
	/*
	for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
	{
		S = AGP_PlayerStart(N);
		if (((S != nullptr) && (S.GetTeamID() == TeamIndex)) && IsEnabled(S.FireTeam))
		{
			bFoundAny = true;
			if (S.GetSpawnClass() == AClassRifleman::StaticClass())
			{
				bFoundM16 = true;
			}
			else
			{
				if (S.GetSpawnClass() == AClassRiflemanM4A1AutoIron::StaticClass())
				{
					bFoundM4 = true;
				}
				else
				{
					if (S.GetSpawnClass() == AClassRiflemanM4A1Auto::StaticClass())
					{
						bFoundM4Auto = true;
					}
					else
					{
						if (S.GetSpawnClass() == AClassAutomaticRifleman::StaticClass())
						{
							bFoundM249 = true;
						}
					}
				}
			}
			if (S.bSquadLeader)
			{
				NumAvailable[5] ++;
			}
			else
			{
				if (S.bFTLeader)
				{
					NumAvailable[6] ++;
				}
				else
				{
					if (GetIndex(S.GetSpawnClass()) != -1)
					{
						NumAvailable[GetIndex(S.GetSpawnClass())] ++;
					}
				}
			}
		}
	}
	if (bFoundM16)
	{
		yRifleType = 0;
	}
	else
	{
		if (bFoundM4)
		{
			yRifleType = 1;
		}
		else
		{
			if (bFoundM4Auto)
			{
				yRifleType = 2;
			}
			else
			{
				if (bFoundM249)
				{
					yRifleType = 3;
				}
				else
				{
					yRifleType = uint8(-1);
				}
			}
		}
	}
	if (Size == 1)
	{
		NumLeadersAvailable = 1;
	}
	else
	{
		NumLeadersAvailable = uint8(((Size - NumAvailable[5]) - NumAvailable[6]));
	}
	NumMedicsAvailable = 0;
	for (i = 1; i < 5; i++)
	{
		if (IsEnabled(byte(i)))
		{
			NumMedicsAvailable++;
		}
	}
	if (!bFoundAny)
	{
		DebugLog(DEBUG_Warn, "No AGP_PlayerStarts found.");
		for (i = 0; i < 7; i++)
		{
			NumAvailable[i] = 1;
		}
	}
	*/
}
void AAGP_TeamInfo::DumpAvailablePS()
{
	/*
		int32 X;
		for (X=0; X<7; X++)
		{
			DebugLog(DEBUG_Team,GetClassDisplayName(X));
		}
	*/
}
void AAGP_TeamInfo::CountDesiredPlayerStarts()
{
	int32 i = 0;
	UObject*  Desired;
	AHumanController* HC;

	if (bSpectatorTeam)
	{
		return;
	}
	NumMedicsDesired=0;
	NumLeadersDesired=0;
	for (i=0; i<7; i++)
	{
		NumDesired[i]=0;
	}
	for (i=0; i<Size; i++)
	{
		HC      = Cast<AHumanController>(TeamList[i]->GetOwner());
		Desired = HC->GetDesiredTeamClass();
		if (Desired != nullptr)
		{
			if (GetIndex(Desired) != -1)
			{
				NumDesired[GetIndex(Desired)] ++;
			}
		}
		else
		{
			if (TeamList[i]->bWantsSquadLeader)
			{
				NumDesired[5] ++;
			}
			else
			{
				if (TeamList[i]->bWantsFTLeader)
				{
					NumDesired[6] ++;
				}
			}
		}
		if (TeamList[i]->bWantsMedic)
		{
			NumMedicsDesired ++;
		}
		if (TeamList[i]->bAvoidLeaderRole)
		{
			NumLeadersDesired ++;
		}
	}
	
}
void AAGP_TeamInfo::PrintPSList(FString S)
{
	TSubclassOf<AAGP_PlayerStart> PS;
	if (!(Cast<AAA2_WorldSettings>(GetWorldSettings())->debugThis(EDebugTag::DEBUG_Team)))
	{
		return;
	}
	//DebugLog(DEBUG_Team,"---------------(" + S + ")---------------");
	/*
	for (PS = PSList; PS != nullptr; PS = PS->nextPS)
	{
		if (!PS->bEnabled)
		{
		}
		//DebugLog(DEBUG_Team, "PSList:	" + FString::FromInt(PS) @ FString::FromInt(PS.bSquadLeader) @ FString::FromInt(PS.bFTLeader) @ FString::FromInt(PS.fBaseScore));
	}
	*/
	//DebugLog(DEBUG_Team,"---------------(" + S + ")---------------");
	
}

void AAGP_TeamInfo::OLD_GeneratePSList()
{
	ANavigationPoint* N = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	CountAvailablePlayerStarts();
	nSLeaders = 0;
	nFTLeaders = 0;
	PSList = nullptr;
	/*
	for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
	{
		PS = AGP_PlayerStart(N);
		if ((((PS != nullptr) && PS.bEnabled) && (PS.GetTeamID() == TeamIndex)) && IsEnabled(PS.FireTeam))
		{
			if (PS.bSquadLeader)
			{
				nSLeaders++;
			}
			else
			{
				if (PS.bFTLeader)
				{
					nFTLeaders++;
				}
			}
			AddToPSList(PS);
		}
	}
	*/
}

void AAGP_TeamInfo::OLD_AddToPSList(AAGP_PlayerStart* Add)
{
	AAGP_PlayerStart* PS = nullptr;
	AAGP_PlayerStart* Prev = nullptr;
	/*
	if (PSList == nullptr)
	{
		PSList = Add;
		PSList.nextPS = nullptr;
		return;
	}
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if (PS.fBaseScore < Add.fBaseScore)
		{
			InsertPS(Prev, Add, PS);
			return;
		}
		Prev = PS;
	}
	InsertPS(Prev, Add, nullptr);
	*/
}

void AAGP_TeamInfo::OLD_InsertPS(AAGP_PlayerStart* Prev, AAGP_PlayerStart* ins, AAGP_PlayerStart* Next)
{
	if (Prev == nullptr)
	{
		//PSList= Cast<AAGP_PlayerStart>(ins);
	}
	else
	{
		//Prev->nextPS = ins;
	}
	//ins->nextPS = Next;
}
void AAGP_TeamInfo::PrintTeamList(FString S)
{
	/*
		int32 i = 0;
		if (! Level.debugThis(21))
		{
			return;
		}
		DebugLog(DEBUG_Team,"xxxxxxxxxxxxxxx(" + S + ")xxxxxxxxxxxxxxx");
		for (i=0; i<tsize; i++)
		{
			DebugLog(DEBUG_Team,"TeamList:	" + Temp[i].GetHumanReadableName() @ Temp[i].GetWeight());
		}
		DebugLog(DEBUG_Team,"xxxxxxxxxxxxxxx(" + S + ")xxxxxxxxxxxxxxx");
	*/
}
void AAGP_TeamInfo::SortPlayerList()
{
	/*
		AAA2_PlayerState* Swap;
		int32 i = 0;
		int32 j = 0;
		for (i=0; i<Size; i++)
		{
			for (j=i+1; j<Size; j++)
			{
				if (TeamList[i].GetWeight() > TeamList[j].GetWeight())
				{
					Swap=TeamList[i];
					TeamList[i]=TeamList[j];
					TeamList[j]=Swap;
				}
			}
		}
		if (! Level.debugThis(21))
		{
			return;
		}
		DebugLog(DEBUG_Team,"ooooooooooooooo(Sorted)ooooooooooooooo");
		for (i=0; i<Size; i++)
		{
			DebugLog(DEBUG_Team,"TeamList:	" + TeamList[i].GetHumanReadableName() @ TeamList[i].GetWeight());
		}
		DebugLog(DEBUG_Team,"ooooooooooooooo(Sorted)ooooooooooooooo");
	*/
}
void AAGP_TeamInfo::RandomizePlayers()
{
	/*
		AAA2_PlayerState* Swap;
		int32 i = 0;
		int32 sw;
		for (i=0; i<tsize; i++)
		{
			sw=Rand(tsize - i) + i;
			if (sw != i)
			{
				Swap=Temp[sw];
				Temp[sw]=Temp[i];
				Temp[i]=Swap;
			}
		}
	*/
}
void AAGP_TeamInfo::DoAssignment(AAGP_PlayerStart* PS)
{
	/*
		tsize --;
		DebugLog(DEBUG_Team,"AGP_TeamInfo::DoAssignment()	" + PS @ tsize @ Temp[tsize].GetHumanReadableName());
		if (Cast<AController>(Temp[tsize].Owner).StartSpot != nullptr)
		{
			DebugLog(DEBUG_Error,"" + Temp[tsize].GetHumanReadableName() + " already has a PS at " + Cast<AController>(Temp[tsize].Owner).StartSpot);
			return;
		}
		Controller(Temp[tsize].Owner).StartSpot=PS;
		Temp[tsize]=nullptr;
		PS.bEnabled=false;
	*/
}
void AAGP_TeamInfo::AssignLeaders()
{
	int32 i = 0;
	int32 j = 0;
	AAGP_PlayerStart* PS = nullptr;
	int32 nAssigned = 0;
	j = 0;
	/*
	for (i = 0; i < Size; i++)
	{
		if (TeamList[i].bWantsSquadLeader)
		{
			Temp[j] = TeamList[i];
			j++;
		}
	}
	tsize = j;
	PrintTeamList("SquadLeader");
	nAssigned = 0;
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if ((tsize == 0) || (nAssigned >= nSLeaders))
		{
		}
		if (!PS.bEnabled)
		{
		}
		if (PS.bSquadLeader)
		{
			nAssigned++;
			DoAssignment(PS);
		}
	}
	PrintPSList("SquadLeader");
	if (nSLeaders > nAssigned)
	{
		ForceLeaders(true, (nSLeaders - nAssigned));
	}
	j = 0;
	for (i = 0; i < Size; i++)
	{
		if (TeamList[i].bWantsSquadLeader || TeamList[i].bWantsFTLeader)
		{
			if (Cast<AController>(TeamList[i].Owner).StartSpot == nullptr)
			{
				Temp[j] = TeamList[i];
				j++;
			}
		}
	}
	tsize = j;
	PrintTeamList("FTLeader");
	nAssigned = 0;
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if ((tsize == 0) || (nAssigned >= nFTLeaders))
		{
		}
		if (!PS.bEnabled)
		{
		}
		if (PS.bFTLeader)
		{
			nAssigned++;
			DoAssignment(PS);
		}
	}
	PrintPSList("FTLeader");
	if (nFTLeaders > nAssigned)
	{
		ForceLeaders(false, (nFTLeaders - nAssigned));
	}
	*/
}

void AAGP_TeamInfo::ForceLeaders(bool bSquad, int32 discrepancy)
{
	int32 i = 0;
	int32 j = 0;
	AAGP_PlayerStart* PS = nullptr;
	if (Size < 2)
	{
		return;
	}
	j = 0;
	/*
	for (i = 0; i < Size; i++)
	{
		if (Cast<AController>(TeamList[i].Owner).StartSpot == nullptr)
		{
			Temp[j] = TeamList[i];
			j++;
		}
	}
	tsize = j;
	RandomizePlayers();
	for (i = 0; i < tsize; i++)
	{
		if (tsize <= discrepancy)
		{
		}
		if (Temp[i].bAvoidLeaderRole)
		{
			tsize--;
			for (j = i; j < tsize; j++)
			{
				Temp[j] = Temp[(j + 1)];
			}
		}
	}
	PrintTeamList("ForceLeaders");
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if (tsize == 0)
		{
		}
		if (!PS.bEnabled)
		{
		}
		if ((bSquad && PS.bSquadLeader) || ((!bSquad) && PS.bFTLeader))
		{
			DoAssignment(PS);
		}
	}
	*/
}

void AAGP_TeamInfo::AssignClass(UObject* aClass)
{
	int32 i = 0;
	int32 j = 0;
	AAGP_PlayerStart* PS = nullptr;
	UObject* Desired = nullptr;
	if (ClassNotAvailable(aClass))
	{
		return;
	}
	j = 0;
	/*
	for (i = 0; i < Size; i++)
	{
		if (Cast<AController>(TeamList[i].Owner).StartSpot == nullptr)
		{
			Desired = Cast<AHumanController>(TeamList[i].Owner).GetDesiredTeamClass();
			if ((Desired != nullptr) && (Desired == aClass))
			{
				Temp[j] = TeamList[i];
				j++;
			}
		}
	}
	tsize = j;
	PrintTeamList(string(aClass));
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if (tsize == 0)
		{
		}
		if (!PS.bEnabled)
		{
		}
		if (EquivalentClasses(PS.GetSpawnClass(), aClass))
		{
			DoAssignment(PS);
		}
	}
	PrintPSList(string(aClass));
	*/
}

bool AAGP_TeamInfo::ClassNotAvailable(UObject* aClass)
{
	int32 Index = 0;
	Index=GetIndex(aClass);
	if (Index < 0 || Index > 6)
	{
		return false;
	}
	if (NumAvailable[Index] > 0 && NumDesired[Index] > 0)
	{
		return false;
	}
	return true;
}

bool AAGP_TeamInfo::EquivalentClasses(UObject*  c1, UObject*  c2)
{
	if (c1 == c2)
	{
		return true;
	}
	else
	{
		//if (c1 == AClassRiflemanM4A1AutoIron::StaticClass() && c2 == AClassRifleman::StaticClass())
		if (c1->IsA(AClassRiflemanM4A1AutoIron::StaticClass()) && c2->IsA(AClassRifleman::StaticClass()))
		{
			return true;
		}
	}
	return false;
}
void AAGP_TeamInfo::AssignLeftovers()
{
	int32 i = 0;
	int32 j = 0;
	AAGP_PlayerStart* PS = nullptr;
	j = 0;
	/*
	for (i = 0; i < Size; i++)
	{
		if (Cast<AController>(TeamList[i].Owner).StartSpot == nullptr)
		{
			Temp[j] = TeamList[i];
			j++;
		}
	}
	tsize = j;
	PrintTeamList("Leftovers");
	for (PS = PSList; PS != nullptr; PS = PS.nextPS)
	{
		if (tsize == 0)
		{
		}
		if (PS.bEnabled)
		{
			DoAssignment(PS);
		}
	}
	if (tsize != 0)
	{
		DebugLog(DEBUG_Warn, "Some Players did not receive PlayerStarts. Team Size " + FString::FromInt(tsize));
	}
	*/
}

AAGP_PlayerStart* AAGP_TeamInfo::GetPS(AAA2_PlayerState*  PRI)
{
	/*
		if (PRI != nullptr)
		{
			return AGP_PlayerStart(Cast<AController>(PRI.Owner).StartSpot);
		}
	*/
	return nullptr;
}
bool AAGP_TeamInfo::IsPVT(AAGP_PlayerStart* PS)
{
	if (PS != nullptr)
	{
		return CanBeMedic(PS) && ! PS->bFTLeader;
	}
	return false;
}

bool AAGP_TeamInfo::IsRiflePVT(AAGP_PlayerStart* PS)
{
	if (PS != nullptr)
	{
		//return IsPVT(PS) && PS->GetSpawnClass().Default.nativeWeapon == 2;
	}
	return false;
}

bool AAGP_TeamInfo::CanBeMedic(AAGP_PlayerStart* PS)
{
	if (PS != nullptr)
	{
		//return ! PS->bSquadLeader && PS->GetSpawnClass()->Default->nativeWeapon != 4 && ! ClassIsChildOf(PS->GetSpawnClass(),AClassGuerrillaBase::StaticClass());
	}
	return false;
}

void AAGP_TeamInfo::TestMedics()
{
	int32 i = 0;
	TArray<uint8> HasMedic = {0,0,0,0,0};
	AAA2_PlayerState* PRI = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	TArray<int32> LostMedic = {};
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		return;
	}
	HasMedic[0]=1;
	/*
	for (i=0; i<NumRequestSlots; i++)
	{
		PRI=RequestList_Player[i];
		PS=RequestList_StartSpot[i];
		if (PS != nullptr && PRI != nullptr)
		{
			if (PRI.bWantsMedic && PRI.bWillBeMedic)
			{
				if (IsRiflePVT(PS))
				{
					HasMedic[PS.FireTeam]=1;
				}
				else
				{
					PRI.bWillBeMedic=false;
					LostMedic[LostMedic.Num()]=i;
				}
			}
			else
			{
				PRI.bWillBeMedic=false;
			}
		}
	}
	for (i=0; i<NumRequestSlots; i++)
	{
		PRI=RequestList_Player[i];
		PS=RequestList_StartSpot[i];
		if (PS != nullptr && PRI != nullptr)
		{
			if (PRI.bWantsMedic && PRI.bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && IsRiflePVT(PS))
			{
				PRI.bWillBeMedic=true;
				HasMedic[PS.FireTeam]=1;
			}
		}
	}
	for (i=0; i<LostMedic.Num(); i++)
	{
		PRI=RequestList_Player[LostMedic[i]];
		PS=RequestList_StartSpot[LostMedic[i]];
		if (PS != nullptr && PRI != nullptr)
		{
			if (PRI.bWantsMedic && PRI.bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && IsPVT(PS))
			{
				PRI.bWillBeMedic=true;
				HasMedic[PS.FireTeam]=1;
			}
		}
	}
	for (i=0; i<NumRequestSlots; i++)
	{
		PRI=RequestList_Player[i];
		PS=RequestList_StartSpot[i];
		if (PS != nullptr && PRI != nullptr)
		{
			if (PRI.bWantsMedic && PRI.bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && IsPVT(PS))
			{
				PRI.bWillBeMedic=true;
				HasMedic[PS.FireTeam]=1;
			}
		}
	}
	for (i=0; i<NumRequestSlots; i++)
	{
		PRI=RequestList_Player[i];
		PS=RequestList_StartSpot[i];
		if (PS != nullptr && PRI != nullptr)
		{
			if (PRI.bWantsMedic && PRI.bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && CanBeMedic(PS))
			{
				PRI.bWillBeMedic=true;
				HasMedic[PS.FireTeam]=1;
			}
		}
	}
	for (i=0; i<LostMedic.Num(); i++)
	{
		PRI=RequestList_Player[LostMedic[i]];
		if (PRI != nullptr)
		{
			if (! PRI.bWillBeMedic)
			{
				PRI.ClientNotifyLostMedic();
			}
		}
	}
	*/
}

void AAGP_TeamInfo::AssignMedics()
{
	TArray<uint8> HasMedic = { 0,0,0,0,0 };
	AAGP_PlayerStart* PS = nullptr;
	int32 i = 0;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		DebugLog(DEBUG_Team,"Cannot Assign Medics. No medics in MILES maps");
		return;
	}
	DebugLog(DEBUG_Team,"Assigning medics to team");
	HasMedic[0]=1;
	for (i=0; i<Size; i++)
	{
		PS=GetPS(TeamList[i]);
		if (PS != nullptr && PS->IsA(AClassSF18BPS::StaticClass()))
		{
			TeamList[i].bIsMedic=true;
			HasMedic[PS.FireTeam]=1;
		}
	}
	TestMedics();
	for (i=0; i<Size; i++)
	{
		PS=GetPS(TeamList[i]);
		if (PS != nullptr && TeamList[i].bWillBeMedic)
		{
			DebugLog(DEBUG_Team,"Assigning medic to player " + TeamList[i].PlayerName);
			TeamList[i].bIsMedic=true;
			HasMedic[PS.FireTeam]=1;
		}
	}
	for (i=0; i<Size; i++)
	{
		PS=GetPS(TeamList[i]);
		if (PS != nullptr && TeamList[i].bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && IsRiflePVT(PS))
		{
			TeamList[i].bIsMedic=true;
			HasMedic[PS.FireTeam]=1;
		}
	}
	for (i=0; i<Size; i++)
	{
		PS=GetPS(TeamList[i]);
		if (PS != nullptr && TeamList[i].bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && IsPVT(PS))
		{
			TeamList[i].bIsMedic=true;
			HasMedic[PS.FireTeam]=1;
		}
	}
	for (i=0; i<Size; i++)
	{
		PS=GetPS(TeamList[i]);
		if (PS != nullptr && TeamList[i].bQualifiedMedic && HasMedic[PS.FireTeam] == 0 && CanBeMedic(PS))
		{
			TeamList[i].bIsMedic=true;
			HasMedic[PS.FireTeam]=1;
		}
	}
	*/
}
void AAGP_TeamInfo::OLD_AssignStartPoints()
{
	/*
		int32 i = 0;
		if (Size == 0)
		{
			return;
		}
		CalculatePlayerWeights();
		GeneratePSList();
		PrintPSList("generated");
		for (i=0; i<Size; i++)
		{
			Controller(TeamList[i].Owner).StartSpot=nullptr;
		}
		AssignLeaders();
		for (i=0; i<7; i++)
		{
			if (IsClassAvailable(i))
			{
				AssignClass(GetClass(i));
			}
		}
		AssignLeftovers();
		AssignMedics();
	*/
}
FString AAGP_TeamInfo::GetFireteamDisplayName(int32 Index)
{
	switch (Index)
	{
	case 0:
		return "Squad Leader";
	case 1:
		return "Alpha";
	case 2:
		return "Bravo";
	case 3:
		return "Charlie";
	case 4:
		return "Delta";
	default:
		return "XXX";
	}
}
FString AAGP_TeamInfo::GetFireteamLetter(int32 Index)
{
	switch (Index)
	{
		case 0:
			return "";
		case 1:
			return "A";
		case 2:
			return "B";
		case 3:
			return "C";
		case 4:
			return "D";
		default:
			return "";
	}
}
int32 AAGP_TeamInfo::GetNumLeadersAvailable()
{
	return NumLeadersAvailable;
}
int32 AAGP_TeamInfo::GetNumLeadersDesired()
{
	return NumLeadersDesired;
}
int32 AAGP_TeamInfo::GetNumMedicsAvailable()
{
	return NumMedicsAvailable;
}
int32 AAGP_TeamInfo::GetNumMedicsDesired()
{
	return NumMedicsDesired;
}
int32 AAGP_TeamInfo::GetNumClasses()
{
	return 7;
}
bool AAGP_TeamInfo::IsClassAvailable(int32 Index)
{
	if (Index == -1)
	{
		return true;
	}
	if (Index < 0 || Index >= 7)
	{
		return false;
	}
	return NumAvailable[Index] > 0;
}
int32 AAGP_TeamInfo::UseAltClass(int32 Index)
{
	switch(Index)
	{
		case 0:
		case 5:
		case 6:
			return yRifleType;
		default:
			return 0;
	}
}
FString AAGP_TeamInfo::GetRifle(bool bLeader)
{
	switch(yRifleType)
	{
		case 0:
			return "(M16A2)";
		case 1:
			return "(M4)";
		case 2:
			return "(M4A1)";
		default:
			if (bLeader && yRifleType == 3)
			{
				return "(M249)";
			}
			return "(M16A2)";
	}
}
FString AAGP_TeamInfo::GetClassDisplayName(int32 Index)
{
	FString DisplayName="";
	switch(Index)
	{
		case 0:
			DisplayName="RIFLEMAN " + GetRifle(false);
			break;
		case 1:
			DisplayName="GRENADIER (M16A2-M203)";
			break;
		case 2:
			DisplayName="ADV. MARKSMAN (M82)";
			break;
		case 3:
			DisplayName="ADV. MARKSMAN (M24)";
			break;
		case 4:
			DisplayName="AUTOMATIC RIFLEMAN (M249)";
			break;
		case 5:
			DisplayName="SQUAD LEADER " + GetRifle(true);
			break;
		case 6:
			DisplayName="FIRETEAM LEADER " + GetRifle(true);
			break;
		default:
			return "ERROR: Unknown Weapon!";
	}
	if (NumAvailable[Index] == 0)
	{
		NumDesired[Index]=0;
	}
	DisplayName=DisplayName + " [" + FString::FromInt(NumDesired[Index]) + "/" + FString::FromInt(NumAvailable[Index]) + "]";
	//DebugLog(DEBUG_Team,"AGP_TeamInfo::GetClassDisplayName() " + Index @ DisplayName);
	return DisplayName;
}
bool AAGP_TeamInfo::IsSquadLeader(int32 Index)
{
	return Index == 5;
}
bool AAGP_TeamInfo::IsFTLeader(int32 Index)
{
	return Index == 6;
}
UObject* AAGP_TeamInfo::GetClass(int32 Index)
{
	switch(Index)
	{
		case 5:
		case 6:
		case -1:
			return nullptr;
		case 0:
			return AClassRifleman::StaticClass();
		case 1:
			return AClassGrenadier::StaticClass();
		case 2:
			return AClassSniper::StaticClass();
		case 3:
			return AClassSniper24_US::StaticClass();
		case 4:
			return AClassAutomaticRifleman::StaticClass();
		default:
			//DebugLog(DEBUG_Team,"AGP_TeamInfo::GetClass() Invalid Class " + Index);
			return nullptr;
	}
}
int32 AAGP_TeamInfo::GetIndex(UObject* aClass)
{
	if (aClass->IsA(AClassRifleman::StaticClass()))				{		return 0;	}
	if (aClass->IsA(AClassRiflemanM4A1AutoIron::StaticClass()))	{		return 0;	}
	if (aClass->IsA(AClassRiflemanM4A1Auto::StaticClass()))		{		return 0;	}
	if (aClass->IsA(AClassRiflemanBare::StaticClass()))			{		return 0;	}
	if (aClass->IsA(AClassGrenadier::StaticClass()))			{		return 1;	}
	if (aClass->IsA(AClassSniper::StaticClass()))				{		return 2;	}
	if (aClass->IsA(AClassSniper24_US::StaticClass()))			{		return 3;	}
	if (aClass->IsA(AClassAutomaticRifleman::StaticClass()))	{		return 4;	}
	return -1;
}
void AAGP_TeamInfo::AssignClassAndRole()
{
	int32 i = 0;
	AController* C = nullptr;
	/*
	DebugLog(DEBUG_Team,"AGP_TeamInfo::AssignClassAndRole()	---------" @ TeamIndex @ "---------" @ Size);
	for (i=0; i<Size; i++)
	{
		C=Controller(TeamList[i].Owner);
		if (Cast<AHumanController>(C) != nullptr && ! Cast<AHumanController>(C).bPBChecked)
		{
		}
		AssignTeamClassAndRole(C);
		C.PlayerReplicationInfo.SetWaitingPlayer(false);
	}
	VerifyTeamStructure();
	printTeam();
	*/
}

void AAGP_TeamInfo::AssignTeamClassAndRole(AController* C)
{
	AAGP_PlayerStart* PS = nullptr;
	PS = Cast<AAGP_PlayerStart>(C->StartSpot);
	/*
	if (PS != nullptr && PS.GetSpawnClass() != nullptr)
	{
		C.TeamClassClass=PS.GetSpawnClass();
		if (PS.bGuerrilla)
		{
			C.PlayerReplicationInfo.bGuerrillaPS=true;
		}
		if (PS.bSpecialForces)
		{
			if (! C.PlayerReplicationInfo.bQualifiedSF)
			{
				C.PlayerReplicationInfo.bGuerrillaPS=true;
			}
			else
			{
				C.PlayerReplicationInfo.bSpecialForcesPS=true;
			}
		}
		if (PS.bIFVIP)
		{
			C.PlayerReplicationInfo.bVIPPS=true;
		}
		C.PlayerReplicationInfo.FT=PS.getFT();
		if (PS.bSquadLeader)
		{
			DebugLog(DEBUG_Team,"AGP_TeamInfo::AssignTeamClassAndRole()	Assign SL" @ C.PlayerReplicationInfo.PlayerName);
			AssignSquadLeader(C);
		}
		if (PS.bFTLeader)
		{
			DebugLog(DEBUG_Team,"AGP_TeamInfo::AssignTeamClassAndRole()	Assign FTL" @ PS.getFT() @ C.PlayerReplicationInfo.PlayerName);
			AssignFTLeader(C,PS.getFT());
		}
	}
	else
	{
		if (C->IsA(AHumanController::StaticClass()))
		{
			DebugLog(DEBUG_Warn,"Assigning Class and Role should not get here...");
			C.TeamClassClass=class<SoldierClass>(Cast<AHumanController>(C).GetDesiredTeamClass());
		}
		else
		{
			DebugLog(DEBUG_Warn,"Unable to assign Class!");
		}
	}
	if (Level.debugObjective)
	{
		if (C.PlayerReplicationInfo.IsSquadLeader())
		{
			DebugLog(DEBUG_Team,"AGP_TeamInfo::AssignTeamClassAndRole() SSG" @ C.PlayerReplicationInfo.PlayerName @ "is class" @ C.TeamClassClass);
		}
		else
		{
			if (C.PlayerReplicationInfo.isTeamLeader())
			{
				DebugLog(DEBUG_Team,"AGP_TeamInfo::AssignTeamClassAndRole() SGT" @ C.PlayerReplicationInfo.PlayerName @ "is class" @ C.TeamClassClass);
			}
			else
			{
				DebugLog(DEBUG_Team,"AGP_TeamInfo::AssignTeamClassAndRole() PVT" @ C.PlayerReplicationInfo.PlayerName @ "is class" @ C.TeamClassClass);
			}
		}
	}
	DebugLog(DEBUG_Multi,"AGP_TeamInfo::AssignClassAndRole() " + C.TeamRoleClass @ C.TeamClassClass);
	*/
}

void AAGP_TeamInfo::AssignSquadLeader(AController* C)
{
	/*
	if (SquadLeader == C.PlayerReplicationInfo)
	{
		return;
	}
	if (SquadLeader != nullptr)
	{
		DebugLog(DEBUG_Warn,"Unable to assign " + C.PlayerReplicationInfo.PlayerName + " as Squad Leader." @ SquadLeader.PlayerName);
		return;
	}
	SquadLeader=C.PlayerReplicationInfo;
	*/
}
void AAGP_TeamInfo::AssignFTLeader(AController* C, uint8 FT)
{
	/*
		if (FTLeader[FT] == C.PlayerReplicationInfo)
		{
			return;
		}
		if (FT == 255 || FTLeader[FT] != nullptr)
		{
			DebugLog(DEBUG_Warn,"Unable to assign " + C.PlayerReplicationInfo + " as FireTeam Leader. " @ FT @ FTLeader[FT]);
			return;
		}
		FTLeader[FT]=C.PlayerReplicationInfo;
	*/
}
AAA2_PlayerState* AAGP_TeamInfo::GetAnyTeamMember()
{
	int32 iPlayerIndex;
	if (GetSquadLeader(nullptr) != nullptr)
	{
		return GetSquadLeader(nullptr);
	}
	if (FTLeader[0] != nullptr)
	{
		return FTLeader[0];
	}
	else
	{
		for (iPlayerIndex=0; iPlayerIndex<Size; iPlayerIndex++)
		{
			if (TeamList[iPlayerIndex] != nullptr)
			{
				return TeamList[iPlayerIndex];
			}
		}
	}
	return nullptr;
}

AAA2_PlayerState* AAGP_TeamInfo::GetSquadLeader(AAA2_PlayerState* PRI)
{
	return SquadLeader;
}

AAA2_PlayerState* AAGP_TeamInfo::GetFTLeader(AAA2_PlayerState* PRI)
{
	if (PRI->FT != 255)
	{
		return FTLeader[PRI->FT];
	}
	return nullptr;
}

AAA2_PlayerState* AAGP_TeamInfo::GetFromList(int32 Index)
{
	return TeamList[Index];
}

AAA2_PlayerState* AAGP_TeamInfo::GetFTLeaderFromList(int32 Index)
{
	return FTLeader[Index];
}

void AAGP_TeamInfo::VerifyTeamStructure()
{
	int32 i = 0;
	uint8 FT = 0;
	if (Size == 0)
	{
		return;
	}
	/*
	for (i=0; i<4; i++)
	{
		DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() FT" @ i @ " enabled-" @ IsEnabled(i + 1) @ " leader-" @ FTLeader[i]);
		if (IsEnabled(i + 1))
		{
			if (FTLeader[i] == nullptr)
			{
				ReplaceTeamLeader(i,,true);
				DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() No initial FTLeader" @ i @ " - New" @ FTLeader[i]);
				if (FTLeader[i] != nullptr)
				{
					DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() New FTLeader" @ i @ " - New name is" @ FTLeader[i].PlayerName);
				}
				else
				{
					DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() No FTLeader" @ i @ " found! There should be one!");
				}
			}
		}
	}
	DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() SquadLeader enabled-" @ IsEnabled(0) @ " leader-" @ SquadLeader);
	if (SquadLeader == nullptr)
	{
		if (IsEnabled(0))
		{
			ReplaceSquadLeader(,true);
			if (SquadLeader != nullptr)
			{
				DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() No initial SquadLeader - New" @ SquadLeader @ SquadLeader.PlayerName);
			}
			else
			{
				DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() No SquadLeader found! There should always be one!");
			}
		}
		else
		{
			if (FTLeader[0] != nullptr)
			{
				SquadLeader=FTLeader[0];
			}
			else
			{
				SquadLeader=nullptr;
			}
			DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() Only 1 FT. FTLeader is also SLeader " + FTLeader[0]);
		}
	}
	for (i=0; i<Size; i++)
	{
		FT=TeamList[i].FT;
		if (TeamList[i] != SquadLeader && FTLeader[FT] == nullptr)
		{
			DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() FTLeader for" @ FT @ "not found!");
			LogTeamStructure();
		}
	}
	if (SquadLeader == nullptr)
	{
		DebugLog(DEBUG_Team,"AGP_TeamInfo::VerifyTeamStructure() No SquadLeader!");
		LogTeamStructure();
	}
	*/
}

uint8 AAGP_TeamInfo::Test(AAA2_PlayerState*  PRI)
{
	if (PRI == nullptr)
	{
		return -1;
	}
	else
	{
		return PRI->FT;
	}
}

void AAGP_TeamInfo::printTeam()
{
}

ATeamInfo* AAGP_TeamInfo::GetOtherTeam()
{
	return otherTeam;
}

void AAGP_TeamInfo::TeamReset()
{
	int32 i=0;
	for (i=0; i<Size; i++)
	{
		TeamList[i]->TeamReset();
	}
	SquadLeader=nullptr;
	for (i=0; i<4; i++)
	{
		FTLeader[i]=nullptr;
	}
	bDead=false;
}

void AAGP_TeamInfo::ScoreRound(bool bWon)
{
	int32 i = 0;
	FName Reason = "";
	APlayerController* PC = nullptr;
	/*
	if (Level.Game != nullptr && AGP_GameTournament(GetGameMode()) != nullptr)
	{
		if (Cast<AAGP_GameTournament>(GetGameMode()).bTournamentWarmupStarted || AGP_GameTournament(GetGameMode()).bFirstRunAfterWarmup)
		{
			return;
		}
	}
	if (bWon)
	{
		teamScore ++;
	}
	if (GiveCredit_Wins())
	{
		for (i=0; i<Size; i++)
		{
			TeamList[i].ScoreRound(bWon);
		}
	}
	else
	{
		if (CheckIf_NoEnemy())
		{
			Reason='NoEnemy';
		}
		else
		{
			if (CheckIf_SmallGame())
			{
				Reason='SmallGame';
			}
			else
			{
				if (! Level.Game.CheatsDisabled())
				{
					Reason='CheatServer';
				}
				else
				{
					Reason='ShortGame';
				}
			}
		}
		for (i=0; i<Size; i++)
		{
			TeamList[i].NotifyNoScore(Reason);
		}
	}
	if (Level.Game.Stats != nullptr)
	{
		for (i=0; i<NumRequestSlots; i++)
		{
			if (ActualList_Player[i] != nullptr)
			{
				PC=Cast<APlayerController>(ActualList_Player[i].Owner);
				if (PC != nullptr && PC.PlayerStatsIndex >= 0)
				{
					if (bWon)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundWon();
					}
					else
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundLost();
					}
				}
			}
		}
	}
	*/
}

int32 AAGP_TeamInfo::GetTotalScore()
{
	int32 i = 0;
	int32 total=0;
	for (i=0; i<Size; i++)
	{
		total += TeamList[i]->Score_Total;
	}
	return total;
}

int32 AAGP_TeamInfo::GetWinBonus(bool bSurvived)
{
	int32 bonus;
	switch(TeamIndex)
	{
		case 0:
			bonus= Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team0_Win;
			if (bSurvived)
			{
				bonus += Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team0_SurviveWin;
			}
			return bonus;
		case 1:
			bonus= Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team1_Win;
			if (bSurvived)
			{
				bonus += Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team1_SurviveWin;
			}
			return bonus;
		default:
			UE_LOG(LogTemp, Warning, TEXT("AGP_TeamInfo::GetWinBonus() Invalid team index %d"), TeamIndex);
			return 0;
	}
}

bool AAGP_TeamInfo::GiveCredit_Wins()
{
	if (!Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->CheatsDisabled())
	{
		return false;
	}
	if (CheckIf_NoEnemy())
	{
		return false;
	}
	if (CheckIf_SmallGame())
	{
		return false;
	}
	if (CheckIf_ShortGame())
	{
		return false;
	}
	return true;
}

bool AAGP_TeamInfo::GiveCredit_Objectives()
{
	if (!Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->CheatsDisabled())
	{
		return false;
	}
	if (CheckIf_NoEnemy())
	{
		return false;
	}
	if (CheckIf_SmallGame())
	{
		return false;
	}
	return true;
}
bool AAGP_TeamInfo::CheckIf_NoEnemy()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		if (TeamIndex == 0)
		{
			return false;
		}
		return true;
	}
	if (GetOtherTeam() != nullptr)
	{
		return (Cast<AAGP_TeamInfo>(GetOtherTeam())->CountActivePlayers() == 0);
	}
	else
	{
		return true;
	}
	
}

bool AAGP_TeamInfo::CheckIf_SmallGame()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		UE_LOG(LogTemp, Log, TEXT("Human Players: %d"), CountActivePlayers());
		return CountActivePlayers() < 2;
	}
	if (GetOtherTeam() != nullptr)
	{
		return (Cast<AAGP_TeamInfo>(GetOtherTeam())->CountActivePlayers() + CountActivePlayers()) < 4;
	}
	else
	{
		return true;
	}
}

bool AAGP_TeamInfo::CheckIf_ShortGame()
{
	return false;
}

void AAGP_TeamInfo::ResetScores()
{
	teamScore=0;
}

void AAGP_TeamInfo::AddToTeamSP(APawn* Other)
{
	/*
	TeamList[Size - 1]=Other.PlayerReplicationInfo;
	Size ++;
	ActualList_Player[NumRequestSlots ++]=Other.PlayerReplicationInfo;
	Other.PlayerReplicationInfo.Team=Self;
	*/
}

bool AAGP_TeamInfo::AddToTeam(AController* Other)
{
	bool bSuccess = false;
	/*
	bSuccess=AddToTeam(Other);
	if (bSuccess)
	{
		TeamList[Size - 1]=Other.PlayerReplicationInfo;
		Other.PlayerReplicationInfo.bIsSpectator=bSpectatorTeam;
		Other.PlayerReplicationInfo.bWaitingPlayer=true;
	}
	DebugLog(DEBUG_Multi,"AGP_TeamInfo::AddToTeam()");
	printTeam();
	if (! Level.Game.bWaitingToStartMatch)
	{
	}

	TeamDead();
	CountAvailablePlayerStarts();
	CountDesiredPlayerStarts();
	VerifyDesiredClass(Cast<AHumanController>(Other));
	Other.PlayerReplicationInfo.bReadyToPlay=true;
	AddToNoRequestList(Other.PlayerReplicationInfo);
	*/
	return bSuccess;
}

void AAGP_TeamInfo::VerifyDesiredClass(AHumanController* HC)
{
	UObject* Desired = nullptr;
	if (HC == nullptr)
	{
		return;
	}
	/*
	Desired=HC.GetDesiredTeamClass();
	if (Desired == nullptr || ! IsClassAvailable(GetIndex(Desired)))
	{
		HC.DesiredTeamClass=nullptr;
	}
	*/
}

void AAGP_TeamInfo::RemoveFromTeam(AController* Other)
{
	int32 i = 0;
	int32 j = 0;
	bool bFound = false;
	AAA2_PlayerState* rem = nullptr;
	APlayerController* PC = nullptr;
	int32 old_index = 0;
	/*
	rem=Other.PlayerReplicationInfo;
	if (rem.Team != Self)
	{
		DebugLog(DEBUG_Warn,"Trying to remove from " + this + " but " + Other.PlayerReplicationInfo.PlayerName + " had team reference " + rem.Team);
	}
	bFound=false;
	j=0;
	DebugLog(DEBUG_Multi,"AGP_TeamInfo::RemoveFromTeam() " + Other @ Other.PlayerReplicationInfo);
	printTeam();
	for (i=0; i<Size; i++)
	{
		DebugLog(DEBUG_Multi,"AGP_TeamInfo::RemoveFromTeam() Testing " + TeamList[i] @ rem);
		if (TeamList[i] != rem)
		{
			DebugLog(DEBUG_Multi,"AGP_TeamInfo::RemoveFromTeam() " + i @ j @ TeamList[i] @ TeamList[j]);
			TeamList[j]=TeamList[i];
			j ++;
		}
		else
		{
			bFound=true;
		}
	}
	if (bFound)
	{
		Size --;
		TeamList[j]=nullptr;
		rem.Team=nullptr;
		if (! bSpectatorTeam)
		{
			Level.Game.CheckScore(nullptr);
		}
		if (Level.Game.Stats != nullptr && Level.Game.IsInState('MatchInProgress'))
		{
			PC=Cast<APlayerController>(rem.Owner);
			if (PC != nullptr && PC.PlayerStatsIndex >= 0)
			{
				if (PC.Pawn != nullptr)
				{
					if (GetWorld()->GetTimeSeconds() - PC.Pawn.LastStartTime > 30)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_RoundLost();
					}
				}
			}
		}
		for (i=0; i<NumRequestSlots; i++)
		{
			if (ActualList_Player[i] == rem)
			{
				ActualList_Player[i]=nullptr;
			}
			if (RequestList_Player[i] == rem)
			{
				RequestList_Player[i]=nullptr;
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Warn,"" + Other.PlayerReplicationInfo.PlayerName + " wasn't a member of " + Self);
	}
	DebugLog(DEBUG_Multi,"AGP_TeamInfo::RemoveFromTeam() Finished removal");
	old_index=GetPlayerRequestIndex(rem);
	ClearPlayerRequests(rem);
	CheckSwaps(old_index);
	printTeam();
	CountAvailablePlayerStarts();
	CountDesiredPlayerStarts();
	*/
}
AController* AAGP_TeamInfo::GetSwapPlayer()
{
	AAA2_PlayerState* PRI=nullptr;
	AController* Player;
	int32 i = 0;
	if (Size == 0)
	{
		return nullptr;
	}
	for (i=0; i<Size; i++)
	{
		if (PRI == nullptr)
		{
			PRI=TeamList[i];
		}
		else
		{
			/*
			if (TeamList[i]->PlayerID > PRI->PlayerID)
			{
				PRI=TeamList[i];
			}
			*/
		}
	}
	Player=Cast<AController>(PRI->GetOwner());
	return Player;
}
void AAGP_TeamInfo::NotifyKilled(AController* Killer, AController* Killed, APawn* KilledPawn)
{
	AAA2_PlayerState* KIA = nullptr;
	AAA2_PlayerState* killa = nullptr;
	/*
	KIA=Killed.PlayerReplicationInfo;
	killa=Killer.PlayerReplicationInfo;
	if (KIA == SquadLeader && ! bVIP)
	{
		ReplaceSquadLeader(killa);
	}
	else
	{
		if (KIA.isTeamLeader())
		{
			ReplaceTeamLeader(KIA.FT,killa);
		}
	}
	*/
}
void AAGP_TeamInfo::ReplaceSquadLeader(AAA2_PlayerState*  killa, bool bStartOfRound)
{
	uint8 FT = 0;
	APlayerController* PC = nullptr;
	/*
	SquadLeader=FindBestSquadLeader(bStartOfRound);
	if (SquadLeader != nullptr)
	{
		if (Level.Game.Stats != nullptr)
		{
			PC=Cast<APlayerController>(SquadLeader.Owner);
			if (PC != nullptr && PC.PlayerStatsIndex >= 0)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ChangedRoleToSQL();
			}
		}
		if (! SquadLeader.bGuerrillaPS && ! bStartOfRound)
		{
			SquadLeader.NotifyPromotion();
		}
		if (SquadLeader.isTeamLeader())
		{
			FT=SquadLeader.FT;
			SquadLeader.FT=255;
			ReplaceTeamLeader(FT,killa,bStartOfRound);
		}
		else
		{
			FTLeader[SquadLeader.FT]=SquadLeader;
		}
		if (Level.bAddSLBinocs && ! SquadLeader.bGuerrillaPS)
		{
			Cast<AAGP_Pawn>(SquadLeader.myPawn).CreateInventoryFromName(Level.GetDefaultBinoc());
		}
	}
	*/
}

void AAGP_TeamInfo::LogTeamStructure()
{
	int32 X = 0;
	AAA2_PlayerState* member = nullptr;
	int32 FT = 0;
	/*
	if (SquadLeader == nullptr)
	{
		DebugLog(DEBUG_Team,"SQUAD LEADER: NONE");
	}
	else
	{
		DebugLog(DEBUG_Team,"SQUAD LEADER:" @ SquadLeader.PlayerName);
	}
	for (X=0; X<4; X++)
	{
		if (FTLeader[X] == nullptr)
		{
			DebugLog(DEBUG_Team,"FIRE TEAM " + X + " LEADER: NONE");
		}
		else
		{
			DebugLog(DEBUG_Team,"FIRE TEAM " + X + " LEADER:" @ FTLeader[X].PlayerName);
		}
	}
	for (X=0; X<Size; X++)
	{
		member=TeamList[X];
		FT=member.FT;
		if (member.IsSquadLeader())
		{
			DebugLog(DEBUG_Team,X @ "FT:" + FT @ "SSG" + ":" + member.PlayerName);
		}
		else
		{
			if (member.isTeamLeader())
			{
				DebugLog(DEBUG_Team,X @ "FT:" + FT @ "SGT" + ":" + member.PlayerName);
			}
			else
			{
				DebugLog(DEBUG_Team,X @ "FT:" + FT @ "PVT" + ":" + member.PlayerName);
			}
		}
	}
	*/
}
void AAGP_TeamInfo::ReplaceTeamLeader(uint8 FT, AAA2_PlayerState*  Killer, bool bStartOfRound)
{
	APlayerController* PC = nullptr;
	/*
	FTLeader[FT]=FindBestFTLeader(FT,Killer,bStartOfRound);
	if (FTLeader[FT] != nullptr)
	{
		if (Level.Game.Stats != nullptr)
		{
			PC=Cast<APlayerController>(FTLeader[FT].Owner);
			if (PC != nullptr && PC.PlayerStatsIndex >= 0)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ChangedRoleToFTL();
			}
		}
		if (! FTLeader[FT].bGuerrillaPS && ! bStartOfRound)
		{
			FTLeader[FT].NotifyPromotion(true,FT);
		}
		if (Level.bAddFTBinocs && ! FTLeader[FT].bGuerrillaPS && FTLeader[FT].myPawn != nullptr)
		{
			Cast<AAGP_Pawn>(FTLeader[FT].myPawn).CreateInventoryFromName(Level.GetDefaultBinoc());
		}
	}
	*/
}

AAA2_PlayerState* AAGP_TeamInfo::FindBestFTLeader(uint8 FT, AAA2_PlayerState*  Killer, bool bStartOfRound)
{
	AAA2_PlayerState* Best = nullptr;
	AAA2_PlayerState* Other = nullptr; 
	float bestscore = 0;
	float currentscore = 0;
	int32 i = 0;
	bool bSetFirst = false;
	bSetFirst=false;
	/*
		DebugLog(DEBUG_Team,"AGP_TeamInfo::FindBestFTLeader(" + FT + ")");
	DebugLog(DEBUG_Team,"----Size:" + Size);
	for (i=0; i<Size; i++)
	{
		Other=TeamList[i];
		DebugLog(DEBUG_Team,"----got PRI for" @ Other.PlayerName @ "FT:" + Other.FT);
		if (bStartOfRound || ! Other.isDead() && Other.FT == FT)
		{
			currentscore=Other.GetWeight();
			if (Other.bSpecialForcesPS && Other.bQualifiedSF)
			{
				currentscore += 1000;
			}
			if (Other.bSpecialForcesPS && ! Other.bQualifiedSF)
			{
				currentscore *= 0.01;
			}
			if (Other == Killer || Other.bGuerrillaPS)
			{
				currentscore *= 0.01;
			}
			if (! bSetFirst)
			{
				bestscore=currentscore;
				bSetFirst=true;
			}
			DebugLog(DEBUG_Team,"----current score:" + currentscore);
			DebugLog(DEBUG_Team,"----bestscore:" + bestscore);
			if (currentscore >= bestscore)
			{
				bestscore=currentscore;
				Best=Other;
				DebugLog(DEBUG_Team,"--so far best is:" + Best.PlayerName);
			}
		}
		else
		{
			DebugLog(DEBUG_Team,"----skipping " + Other.PlayerName @ "FT:" + Other.FT @ "dead?" + Other.isDead());
		}
	}
	*/
	return Best;
}

AAA2_PlayerState* AAGP_TeamInfo::FindBestSquadLeader(bool bStartOfRound)
{
	AAA2_PlayerState* Best = nullptr;
	AAA2_PlayerState* Other = nullptr;
	float bestscore = 0;
	float currentscore = 0;
	bool bbesttl = false;
	bool bothertl = false;
	int32 i = 0;
	bool bSetFirst = false;
	bSetFirst=false;
	/*
	for (i=0; i<Size; i++)
	{
		Other=TeamList[i];
		if (bStartOfRound || ! Other.isDead())
		{
			currentscore=Other.GetWeight();
			if (Other.bSpecialForcesPS && Other.bQualifiedSF)
			{
				currentscore += 1000;
			}
			if (Other.bSpecialForcesPS && ! Other.bQualifiedSF)
			{
				currentscore *= 0.01;
			}
			if (Other.bGuerrillaPS)
			{
				currentscore *= 0.01;
			}
			bothertl=Other.isTeamLeader();
			if (bothertl == bbesttl)
			{
				if (! bSetFirst)
				{
					bestscore=currentscore;
					bSetFirst=true;
				}
				if (currentscore >= bestscore)
				{
					bestscore=currentscore;
					Best=Other;
				}
			}
			else
			{
				if (bothertl)
				{
					bestscore=currentscore;
					Best=Other;
					bbesttl=true;
				}
			}
		}
	}
	*/
	return Best;
}

bool AAGP_TeamInfo::TeamDead()
{
	int32 Health = 0;
	int32 i = 0;
	bDead=true;
	//DebugLog(DEBUG_Multi,"AGP_TeamInfo::TeamDead() Team " + Self);
	for (i=0; i<Size; i++)
	{
		Health=0;
		if (TeamList[i]->myPawn != nullptr)
		{
			//Health=TeamList[i]->myPawn->Health;
			if (Health > 0)
			{
				bDead=false;
			}
		}
		//DebugLog(DEBUG_Multi,"AGP_TeamInfo::TeamDead() " + TeamList[i] @ TeamList[i].myPawn @ Health);
	}
	//DebugLog(DEBUG_Multi,"AGP_TeamInfo::TeamDead() Returning " + bDead);
	return bDead;
}
int32 AAGP_TeamInfo::NumAlive(bool bFT, uint8 FT)
{
	int32 i = 0;
	int32 Num = 0;
	/*
	for (i=0; i<Size; i++)
	{
		if (bFT && TeamList[i]->FT != FT)
		{
		}
		if (TeamList[i]->myPawn != NULL)
		{
			if (TeamList[i]->myPawn->Health > 0)
			{
				Num ++;
			}
		}
	}
	*/
	return Num;
}

void AAGP_TeamInfo::ScoreAGPObjective(AAGP_Objective* obj, AAA2_PlayerState*  Scorer, bool bScorerOnly)
{
	int32 i = 0;
	bool bTestForAuth = false;
	/*
	if (! obj.CanTeamAttack(TeamIndex))
	{
		DebugLog(DEBUG_Warn,"Cannot score AGP Objective. " + Scorer.PlayerName + " can't attack this!");
		return;
	}
	if (! GiveCredit_Objectives())
	{
		return;
	}
	if (Scorer != nullptr)
	{
		bTestForAuth=Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization();
		DebugLog(DEBUG_Always,"AGP_TeamInfo.uc (first check) -> Scorer.bQualifiedES2 = " + Scorer.bQualifiedES2 + ", Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() = " + bTestForAuth + ".");
		if (Scorer.bQualifiedES2 || ! Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
		{
			Scorer.PScoreObjective(obj.Score_AssaultPlayer);
		}
		else
		{
			Cast<AHumanController>(Scorer.Owner).ClientESSConsoleMessage("You score zero individual points for identification because you have not taken the ES2 training.");
		}
	}
	if (bScorerOnly)
	{
		return;
	}
	for (i=0; i<Size; i++)
	{
		DebugLog(DEBUG_Always,"AGP_TeamInfo.uc (second check) -> Scorer.bQualifiedES2 = " + Scorer.bQualifiedES2 + ", Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() = " + bTestForAuth + ".");
		if (! TeamList[i].bQualifiedES2 && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
		{
			Cast<AHumanController>(TeamList[i].Owner).ClientESSConsoleMessage("You score zero individual points for identification because you have not taken the ES2 training.");
		}
		else
		{
			TeamList[i].PScoreObjective(obj.Score_AssaultTeam);
			if (! TeamList[i].isDead())
			{
				TeamList[i].PScoreObjective(obj.Score_AssaultSurvivor);
				if (TeamList[i] != Scorer && TeamList[i].GetNearbyObjective() == obj)
				{
					TeamList[i].PScoreObjective(obj.Score_AssaultHelper);
				}
			}
		}
	}
	*/
}

void AAGP_TeamInfo::ScoreDecoMesh(AAA2_PlayerState*  Scorer, int32 ScorePoints, bool bScorerOnly)
{
	if (! GiveCredit_Objectives())
	{
		return;
	}
	if (Scorer != nullptr)
	{
		Scorer->PScoreObjective(ScorePoints);
	}
}

void AAGP_TeamInfo::ScoreDefendObjective(AAGP_Objective* obj, AAA2_PlayerState*  Scorer)
{
	if (!GiveCredit_Objectives())
	{
		return;
	}
	if (Scorer != NULL)
	{
		Scorer->PScoreObjective(obj->Score_DefenderKill);
	}
}
void AAGP_TeamInfo::PrintRequestList()
{
	int32 i = 0;
	AAGP_PlayerStart* PS = nullptr;
	//DebugLog(DEBUG_Always, "AGP_TeamInfo::PrintRequestList()	----------------- REQUEST");
	for (i = 0; i < NumRequestSlots; i++)
	{
		//DebugLog(DEBUG_Always, "AGP_TeamInfo::PrintRequestList()	" @ FString::FromInt(RequestList_UnitID[i]) @ FString::FromInt(RequestList_Index[i]) @ FString::FromInt(RequestList_StartSpot[i]) @ FString::FromInt(RequestList_Player[i]));
	}
	//DebugLog(DEBUG_Always, "AGP_TeamInfo::PrintRequestList()	----------------- NO REQUEST");
	for (i = 0; i < NumRequestSlots; i++)
	{
		//DebugLog(DEBUG_Always, "AGP_TeamInfo::PrintRequestList()	" @ FString::FromInt(NoRequest[i]));
	}
	//DebugLog(DEBUG_Always, "AGP_TeamInfo::PrintRequestList()	----------------- PLAYER STARTS");
	/*
	for (PS = PSList; PS != nullptr; PS = PS->nextPS)
	{
		DebugLog(DEBUG_Always, "AGP_TeamInfo::PrintRequestList()	" @ FString::FromInt(PS) @ FString::FromInt(PS.getFT()) @ FString::FromInt(PS.bFTLeader));
	}
	*/
}

bool AAGP_TeamInfo::TournamentSubmitPlayerRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index)
{
	int32 RealIndex = 0;
	RealIndex = GetRealIndex(UnitID, Index);
	if (RealIndex == -1)
	{
		return false;
	}
	AssignPlayerRequest(PRI, RealIndex);
	return true;
}


void AAGP_TeamInfo::SubmitSwapRequest()
{
	if (!((Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld())) != nullptr) && Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld()))->IsTournamentMode()))
	{
		return;
	}
}

void AAGP_TeamInfo::SubmitPauseRequest()
{
	if (!((Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld())) != nullptr) && Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld()))->IsTournamentMode()))
	{
		return;
	}
}

void AAGP_TeamInfo::SubmitResumeRequest()
{
	if (!((Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld())) != nullptr) && Cast<AAGP_GameTeam>(UGameplayStatics::GetGameMode(GetWorld()))->IsTournamentMode()))
	{
		return;
	}
}

void AAGP_TeamInfo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LinkTick(DeltaTime);
}

void AAGP_TeamInfo::LinkTick(float DeltaTime)
{
	int32 i = 0;
	int32 j = 0;
	bool bEmptyTrace = false;
	bool bTraceSucceeded = false;
	AAA2_PlayerState* TracingPRI = nullptr;
	AAA2_PlayerState* SQLPRI = nullptr;
	AAA2_PlayerState* FTLPRI = nullptr;
	APlayerController* PC = nullptr;
	LinkTimerCount += DeltaTime;
	/*
	if (LinkTimerCount >= LinkTimerThreshold)
	{
		if (LinkTimerCount >= LinkTimerThreshold)
		{
			if (TracingPlayerIndex < 0 || TracingPlayerIndex >= NumRequestSlots)
			{
				SQLPRI=GetSquadLeader();
				for (i=0; i<NumRequestSlots; i++)
				{
					if (ActualList_Player[i] != nullptr)
					{
						ActualList_Player[i].LinkedToSquadLeader=false;
						ActualList_Player[i].LinkedToFTLeader=false;
					}
				}
				for (i=0; i<NumRequestSlots; i++)
				{
					if (ActualList_Player[i] != nullptr)
					{
						FTLPRI=GetFTLeader(ActualList_Player[i]);
						for (j=0; j<NumRequestSlots; j++)
						{
							if (ActualList_Player[j] != nullptr && i != j)
							{
								if (ActualList_Player[i].TempLinked & ActualList_Player[j].TempLinked != 0)
								{
									if (VSizeSquared(ActualList_Player[i].myPawn.Location - ActualList_Player[j].myPawn.EyePosition()) <= MaxIndirectLinkDistance * MaxIndirectLinkDistance)
									{
										ActualList_Player[i].TempLinked=ActualList_Player[i].TempLinked | ActualList_Player[j].TempLinked;
										ActualList_Player[j].TempLinked=ActualList_Player[i].TempLinked;
										if (ActualList_Player[i] == SQLPRI)
										{
											ActualList_Player[j].LinkedToSquadLeader=true;
										}
										if (ActualList_Player[i] == FTLPRI && ActualList_Player[i].FT == ActualList_Player[j].FT)
										{
											ActualList_Player[j].LinkedToFTLeader=true;
										}
									}
								}
							}
						}
						ActualList_Player[i].LinkedTo=ActualList_Player[i].TempLinked;
					}
				}
				for (i=0; i<NumRequestSlots; i++)
				{
					if (ActualList_Player[i] != nullptr)
					{
						PC=Cast<APlayerController>(ActualList_Player[i].Owner);
						if (PC != nullptr && Level.Game.Stats != nullptr && PC.PlayerStatsIndex >= 0)
						{
							if (ActualList_Player[i].LinkedTo & ~ 1 << i == 0)
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_Unlinked();
							}
							else
							{
								if (ActualList_Player[i].LinkedToSquadLeader && ActualList_Player[i].LinkedToFTLeader)
								{
									Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_LinkedToSQLAndFTL();
								}
								else
								{
									if (ActualList_Player[i].LinkedToSquadLeader)
									{
										Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_LinkedToSQL();
									}
									else
									{
										if (ActualList_Player[i].LinkedToFTLeader)
										{
											Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_LinkedToFTL();
										}
										else
										{
											Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_LinkedToSoldier();
										}
									}
								}
							}
						}
					}
				}
				TracingPlayerIndex=0;
				if (Size > 0)
				{
					LinkTimerThreshold=LinkUpdateFrequency / Size;
				}
				else
				{
					LinkTimerThreshold=1;
				}
				LinkTimerCount=0;
			}
			else
			{
				TracingPRI=ActualList_Player[TracingPlayerIndex];
				if (TracingPRI != nullptr)
				{
					TracingPRI.LinkedToMe=0;
					for (i=0; i<NumRequestSlots; i++)
					{
						if (ActualList_Player[i] == nullptr || ActualList_Player[i].isDead())
						{
							bEmptyTrace=true;
							bTraceSucceeded=false;
						}
						else
						{
							if (i == TracingPlayerIndex)
							{
								bTraceSucceeded=true;
							}
							else
							{
								bTraceSucceeded=false;
								if (TracingPRI.myPawn != nullptr && ActualList_Player[i].myPawn != nullptr)
								{
									if (VSizeSquared(ActualList_Player[i].myPawn.Location - TracingPRI.myPawn.EyePosition()) <= MaxLinkDistance * MaxLinkDistance)
									{
										bTraceSucceeded=FastTrace(TracingPRI.myPawn.EyePosition(),ActualList_Player[i].myPawn.Location);
									}
								}
							}
						}
						if (bTraceSucceeded)
						{
							TracingPRI.LinkedToMe=TracingPRI.LinkedToMe | 1 << i;
						}
					}
					TracingPRI.TempLinked=TracingPRI.LinkedToMe;
				}
				else
				{
					bEmptyTrace=true;
				}
				TracingPlayerIndex ++;
				if (! bEmptyTrace)
				{
					LinkTimerCount -= LinkTimerThreshold;
				}
			}
		}
	}
	*/
}

void AAGP_TeamInfo::AlertTeamToEnemyLocations(float alertTime)
{
	int32 i = 0;
	int32 j = 0;
	ATeamInfo* EnemyTeam = nullptr;
	AAA2_PlayerState* TeammatePRI = nullptr;
	AAA2_PlayerState* enemyPlayerPRI = nullptr;
	FVector enemyPosition = FVector(0,0,0);
	EnemyTeam = GetOtherTeam();
	/*
	for (i=0; i<NumRequestSlots; i++)
	{
		TeammatePRI=ActualList_Player[i];
		if (TeammatePRI != nullptr)
		{
			for (j=0; j<EnemyTeam.NumRequestSlots; j++)
			{
				enemyPlayerPRI=EnemyTeam.ActualList_Player[j];
				if (enemyPlayerPRI != nullptr)
				{
					enemyPosition=enemyPlayerPRI.GetPawnLocation();
					Cast<AHumanController>(TeammatePRI.Owner).ClientEnemySpotted(enemyPosition.X,enemyPosition.Y,enemyPosition.Z,alertTime);
				}
			}
		}
	}
	*/
}
