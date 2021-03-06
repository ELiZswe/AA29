// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"
#include "AA29/Object/Actor/StaticMeshActor/FlagMeshActor/FlagMeshActor.h"
#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"

AAGP_Objective::AAGP_Objective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	bFirstObjective			= true;
	AccomplishedBy			= 255;
	AttackTeam				= 255;
	AccomplishMessage		= "Your team accomplished the objective.";
	FailedDefenseMessage	= "Your team failed to defend the objective.";
	AttackDescription		= "Attack the objective.";
	DefenseDescription		= "Defend the objective.";
	AccomplishSound			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Objective/Generic/objectiveaccomplished.objectiveaccomplished"), NULL, LOAD_None, NULL);
	ProgressSound			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Objective/Generic/warningpip.warningpip"), NULL, LOAD_None, NULL);
	ProgressSoundStart		= 20;
	ProgressSoundInterval	= 41;
	fROE_Damage_Multiplier	= 1;
	USPickupMsg				= "Your Team has picked up the objective.";
	OPFORPickupMsg			= "The Opposing Team has picked up the objective.";
	//bStatic = false;
	//bHidden = false;
	Texture					= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Objective.AGP_Objective"), NULL, LOAD_None, NULL);
}

void AAGP_Objective::BlinkObjectiveOnRadar(int32 iTeam, float BlinkDuration)
{
	if (iTeam == 0)
	{
		if (GetWorld()->GetTimeSeconds() > RadarBlinkEndTime)
		{
			RadarBlinkStartTime=GetWorld()->GetTimeSeconds();
		}
		if (GetWorld()->GetTimeSeconds() + BlinkDuration > RadarBlinkEndTime)
		{
			RadarBlinkEndTime=GetWorld()->GetTimeSeconds() + BlinkDuration;
		}
	}
	else
	{
		if (iTeam == 1)
		{
			if (GetWorld()->GetTimeSeconds() > RadarBlinkEndTime1)
			{
				RadarBlinkStartTime1=GetWorld()->GetTimeSeconds();
			}
			if (GetWorld()->GetTimeSeconds() + BlinkDuration > RadarBlinkEndTime1)
			{
				RadarBlinkEndTime1=GetWorld()->GetTimeSeconds() + BlinkDuration;
			}
		}
	}
}

void AAGP_Objective::BeginPlay()
{
	_OriginalAttackTeam=AttackTeam;
	_OriginalObjectiveOnCompass=ObjectiveOnCompass;
	Super::BeginPlay();
}

void AAGP_Objective::InitializeVolumesAndZones()
{
	AActor* A = nullptr;
	AVolume* V = nullptr;
	AZoneInfo* Z = nullptr;
	if (ObjectiveTag == "None" || ObjectiveTag == "None")
	{
		return;
	}
	/*
		ForEach AllActors(Class'Actor',A)
	{
		if (A->IsA(AVolume::StaticClass()))
		{
			V=Volume(A);
			if (V.LocationObjective == ObjectiveTag)
			{
				V.Objective=Self;
			}
		}
		else
		{
			if (A->IsA(AZoneInfo::StaticClass()))
			{
				Z=ZoneInfo(A);
				if (Z.LocationObjective == ObjectiveTag)
				{
					Z.Objective=Self;
				}
			}
		}
	}
	*/
}
void AAGP_Objective::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	InitializeVolumesAndZones();
}
void AAGP_Objective::PostBeginPlay()
{
	AAGP_Objective* O = nullptr;
	AAGP_Objective* CurrentObjective = nullptr;
	//Super::PostBeginPlay();
	if (bFirstObjective)
	{
		CurrentObjective=this;
		/*
		ForEach AllActors('AGP_Objective',O)
		{
			if (O != CurrentObjective)
			{
				CurrentObjective.nextObjective=O;
				O.bFirstObjective=false;
				CurrentObjective=O;
			}
		}
		*/
	}
	/*
	if (bFirstObjective && Role == 4)
	{
		Cast<AAGP_GameInfo>(GetGameMode())->SetFirstObjective(this);
	}
	*/
	InitializeNPCObjective();
	InitializeVisibilityObjective();
	InitializeSequenceObjective();
	InitializeInventoryObjective();
	ResetLocationProxy();
	SetTeamMesh();
	pawnMustBeUsedBy=nullptr;
	bPlayerRadioedObectiveInfo=false;
	ctrlrESSReporter=nullptr;
}
void AAGP_Objective::InitializeNPCObjective()
{
	APawn* NPC = nullptr;
	/*
	ForEach RadiusActors(Class'Pawn',NPC,24)
	{
		if (NPC->IsA(AAGP_Pawn::StaticClass()) && ! NPC.IsPlayerPawn())
		{
			LinkedNPC=NPC;
		}
		else
		{
		}
	}
	*/
}

bool AAGP_Objective::HandleGrenadeDamage()
{
	/*
	if (LinkedNPC != nullptr)
	{
		if (! LinkedNPC.bHidden)
		{
			return true;
		}
	}
	*/
	return false;
}

void AAGP_Objective::InitializeVisibilityObjective()
{
	AAGP_Objective* AO = nullptr;
	/*
	if (VisibilityChildTag != "None")
	{
		ForEach AllActors('AGP_Objective',AO)
		{
			if (AO.VisibilityTag == VisibilityChildTag)
			{
				VisibilityChildren[VisibilityChildren.Num()]=AO;
			}
		}
	}
	*/
}

void AAGP_Objective::InitializeInventoryObjective()
{
	AAGP_ObjectivePickup* OPickup = nullptr;
	/*
	if (InventoryTag != "None")
	{
		ForEach AllActors('AGP_ObjectivePickup',OPickup)
		{
			if (InventoryTag == OPickup.InventoryTag)
			{
				if (InventoryPickup == nullptr)
				{
					InventoryPickup=OPickup;
				}
				else
				{
					DebugLog(DEBUG_Warn,"AGP_Objective::InitializeInventoryObjective()	Found multiple matching InventoryPickups! Tag(" @ InventoryTag @ ") Duplicate(" @ OPickup @ ")");
				}
			}
		}
		if (InventoryPickup != nullptr)
		{
			if (InventoryPickup.Objective == nullptr)
			{
				InventoryPickup.setObjective(this);
			}
			else
			{
				InventoryPickup=nullptr;
				DebugLog(DEBUG_Warn,"AGP_Objective::InitializeInventoryObjective()	InventoryPickup already has an objective! Existing(" @ InventoryPickup @ ")");
			}
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Objective::InitializeInventoryObjective() Failed to find an InventoryPickup with matching Tag(" @ InventoryTag @ ")");
		}
	}
	*/
}
void AAGP_Objective::ResetLocationProxy()
{
	LocationProxy=NULL;
}

void AAGP_Objective::SetLocationProxy(TSubclassOf<class AActor> new_proxy)
{
	LocationProxy=new_proxy;
}

bool AAGP_Objective::IsOnCompass(AController* ctrlRequesting)
{
	AAA2_PlayerState* ProxyPRI = nullptr;
	AAA2_PlayerState* ClientPRI = nullptr;
	/*
	if (ctrlRequesting == nullptr)
	{
		ctrlRequesting=Level.GetClient().GetController();
	}
	switch(ObjectiveOnCompass)
	{
		case 1:
		return false;
		case 2:
		if (ctrlRequesting.PlayerReplicationInfo.Team != nullptr)
		{
			return ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex == 0;
			break;
		}
		return false;
	}
	GOTO JL028D;
	case 3:
	if (ctrlRequesting.PlayerReplicationInfo.Team != nullptr)
	{
		return ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex == 1;
	}
	else
	{
		return false;
	}
	GOTO JL028D;
	case 4:
	if (! IsEnabled() || ctrlRequesting.PlayerReplicationInfo.Team != nullptr && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 0)
	{
		return false;
	}
	if (IsA('AGP_ESSObjective') && ctrlRequesting.PlayerReplicationInfo.Team != nullptr && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 0)
	{
		return false;
	}
	GOTO JL028D;
	case 5:
	if (! IsEnabled() || ctrlRequesting.PlayerReplicationInfo.Team != nullptr && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 1)
	{
		return false;
	}
	if (IsA('AGP_ESSObjective') && ctrlRequesting.PlayerReplicationInfo.Team != nullptr && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 1)
	{
		return false;
	}
	GOTO JL028D;
	case 6:
	if (IsEnabled() && Level.GetClient() != nullptr && ctrlRequesting != nullptr && ctrlRequesting.Pawn == pawnMustBeUsedBy)
	{
		return true;
	}
	else
	{
		return false;
	}
	GOTO JL028D;
	default:
JL028D:
	if (LocationProxy != nullptr)
	{
		if (LocationProxy->IsA(APlayerReplicationInfo::StaticClass()))
		{
			ClientPRI=ctrlRequesting.PlayerReplicationInfo;
			ProxyPRI=PlayerReplicationInfo(LocationProxy);
			if (ProxyPRI == ClientPRI || ClientPRI == nullptr)
			{
				return false;
			}
			else
			{
				return ClientPRI.IsFriend(ProxyPRI);
			}
		}
		else
		{
			if (LocationProxy->IsA(AAGP_ObjectivePickup::StaticClass()))
			{
				return AGP_ObjectivePickup(LocationProxy).ReadyToPickup(0);
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		return IsEnabled();
	}
	*/
	return false;   //FAKE   /ELiZ
}

FVector AAGP_Objective::GetCompassLocation()
{
	if (LocationProxy == NULL)
	{
		//return Location;
	}
	else
	{
		/*
		if (LocationProxy->IsA(APlayerReplicationInfo::StaticClass()))
		{
			return PlayerReplicationInfo(LocationProxy).GetPawnLocation();
		}
		else
		{
			return LocationProxy->Location;
		}
		*/
	}
	return FVector(0, 0, 0);    //FAKE    /ELiZ
}

void AAGP_Objective::InitializeSequenceObjective()
{
	AAGP_Objective* AO = nullptr;
	int32 i = 0;
	/*
	if (ParentTags.Num() > 0)
	{
		ForEach AllActors('AGP_Objective',AO)
		{
			if (AO.SequenceTag != "None")
			{
				for (i=0; i<ParentTags.Num(); i++)
				{
					if (AO.SequenceTag == ParentTags[i])
					{
						AddSequenceParent(AO);
					}
				}
			}
		}
	}
	VerifyAllParentsFound();
	if (ParentSequence.Num() != 0)
	{
		SetDisabled(true);
	}
	*/
}

void AAGP_Objective::VerifyAllParentsFound()
{
	int32 i = 0;
	int32 j = 0;
	bool bFound = false;
	/*
	if (ParentTags.Num() == ParentSequence.Num())
	{
		return;
	}
	for (i=0; i<ParentTags.Num(); i++)
	{
		bFound=false;
		j=0;
		if (j < ParentSequence.Num())
		{
			if (ParentSequence[j].SequenceTag == ParentTags[i])
			{
				bFound=true;
			}
			else
			{
				j ++;
			}
		}
		if (! bFound)
		{
			DebugLog(DEBUG_Warn,"AGP_Objective::WarnParentsMissing()	Could not find parent" @ ParentTags[i]);
		}
	}
	*/
}
bool AAGP_Objective::IsAParentOf(TSubclassOf<AAGP_Objective> AO)
{
	int32 i = 0;
	if (Cast<AAGP_Objective>(AO) == this)
	{
		return true;
	}
	for (i=0; i<ParentSequence.Num(); i++)
	{
		if (Cast<AAGP_Objective>(ParentSequence[i])->IsAParentOf(AO))
		{
			return true;
		}
	}
	return false;
}
void AAGP_Objective::AddSequenceParent(TSubclassOf<AAGP_Objective> AO)
{
	/*
	int32 i = 0;
	if (Cast<AAGP_Objective>(AO)->IsAParentOf(this))
	{
		//DebugLog(DEBUG_Error,"AGP_Objective::AddSequenceParent()	Avoiding parent loop: Cannot make" @ AO @ " a parent of" @ Self);
		return;
	}
	i=ParentSequence.Num();
	ParentSequence[i]=AO;
	Cast<AAGP_Objective>(AO)->AddSequenceChild(this);
	*/
}
void AAGP_Objective::AddSequenceChild(TSubclassOf<AAGP_Objective> AO)
{
	ChildSequence[ChildSequence.Num()]=AO;
}
void AAGP_Objective::NotifySequenceChildren()
{
	/*
		int32 i = 0;
		for (i=0; i<ChildSequence.Num(); i++)
		{
			ChildSequence[i].ParentAccomplished(this);
		}
	*/
}
void AAGP_Objective::ParentAccomplished(TSubclassOf<AAGP_Objective> AO)
{
	bool bActivate=false;
	bool bSomeInactive=false;
	bool bFound = false;
	int32 i = 0;
	for (i=0; i<ParentSequence.Num(); i++)
	{
		if (AO == ParentSequence[i])
		{
			bFound=true;
		}
		else
		{
			if (Cast<AAGP_Objective>(ParentSequence[i])->AccomplishedBy == 255 && !Cast<AAGP_Objective>(ParentSequence[i])->bInactive)
			{
				bSomeInactive=true;
			}
		}
	}
	if (! bFound)
	{
		//DebugLog(DEBUG_Warn,"AGP_Objective::ParentEnabled()	Could not find parent:" @ AO);
		return;
	}
	switch(ActivateOn)
	{
		case EActivateOn::ACTON_AnyParent:
			bActivate=true;
			break;
		case EActivateOn::ACTON_AllParents:
			bActivate=! bSomeInactive;
			break;
		case EActivateOn::ACTON_SameTeam:
			bActivate= Cast<AAGP_Objective>(AO)->AccomplishedBy == AttackTeam;
			break;
		default:
			break;
	}
	SetDisabled(! bActivate);
}
void AAGP_Objective::NotifyLinkUsedBy(APawn* User)
{
	uint8 new_team = 0;
	if (bUseLinkAccomplishes)
	{
		//new_team=User.PlayerReplicationInfo.Team.TeamIndex;
		//Log("AGP_Objective::NotifyLinkUsedBy()	" @ User @ new_team);
		if (! WasAccomplishedBy(new_team))
		{
			AccomplishObjective(User,nullptr);
		}
	}
}

void AAGP_Objective::NotifyLinkDecoDamage(APawn* instigatedBy, int32 DestroyPoints)
{
	ATeamInfo* Team = nullptr;
	/*
	if (Instigator != nullptr && Instigator.PlayerReplicationInfo != nullptr)
	{
		Team=Instigator.PlayerReplicationInfo.Team;
	}
	if (Team != nullptr)
	{
		if (Cast<AAGP_GameInfo>(GetGameMode()) != nullptr)
		{
			AGP_GameInfo(GetGameMode()).ScoreDecoMesh(Team,Self,DestroyPoints,Instigator.PlayerReplicationInfo,true);
		}
	}
	*/
}
void AAGP_Objective::NotifyLinkDamage(APawn* instigatedBy, int32 Damage)
{
	/*
	if (DamageTag == 'Civiliandamage' && fROE_Damage_Multiplier == 0)
	{
		fROE_Damage_Multiplier=1;
	}
	NotifyShortCut(instigatedBy,Damage * fROE_Damage_Multiplier,bKickInstigator_Damage,DoWhenLinkDamaged);
	*/
}

void AAGP_Objective::NotifyLinkKill(APawn* instigatedBy)
{
	//NotifyShortCut(instigatedBy,Kill_ROE_Penalty,bKickInstigator_Kill,DoWhenLinkKilled);
}

void AAGP_Objective::NotifyShortCut(APawn* instigatedBy, int32 ROE, bool Kick, EGameDo DoWhen)
{
	AAA2_PlayerState* Winner = nullptr;
	FString Reason = "";
	AAGP_GameInfo* G = nullptr;
	//G = Cast<AAGP_GameInfo>(GetGameMode());
	/*
	if (ROE > 0)
	{
		if (instigatedBy != nullptr && instigatedBy.Controller != nullptr && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You are hitting a non-combatant.");
		}
		G.RecordFriendlyFire(instigatedBy.PlayerReplicationInfo,None,ROE);
	}
	if (Kick)
	{
		G.Kick(instigatedBy.PlayerReplicationInfo.PlayerName,"ROE");
	}
	switch(DoWhen)
	{
		case 2:
		Winner=nullptr;
		Reason="ObjectiveImpossible";
		break;
		case 1:
		Winner=nullptr;
		Reason="NoScore";
		break;
		case 3:
		Winner=instigatedBy.PlayerReplicationInfo.Team.GetOtherTeam().GetSquadLeader();
		Reason="ObjectiveImpossible";
		break;
		case 4:
		Winner=instigatedBy.PlayerReplicationInfo;
		Reason="ObjectiveImpossible";
		break;
		case 5:
		Winner=instigatedBy.PlayerReplicationInfo;
		Reason="NoWinner";
		break;
		default:
	}
	if (Reason != "")
	{
		G.EndGame(Winner,Reason);
	}
	*/
}

void AAGP_Objective::SetTeamMesh()
{
	switch(AttackTeam)
	{
		case 0:
			if (smTeam1Holds != NULL)
			{
				//SetDrawType(8);
				//SetStaticMesh(smTeam1Holds);
			}
			break;
		case 1:
			if (smTeam0Holds != NULL)
			{
				//SetDrawType(8);
				//SetStaticMesh(smTeam0Holds);
			}
			break;
		case 255:
			if (smUncaptured != NULL)
			{
				//SetDrawType(8);
				//SetStaticMesh(smUncaptured);
			}
			break;
		default:
			break;
	}
	
}
void AAGP_Objective::PawnDied(APawn* p)
{
}
void AAGP_Objective::StopCounting()
{
}
void AAGP_Objective::NotifyParentInactive()
{
	int32 i = 0;
	if (! bInactive)
	{
		for (i=0; i<ParentSequence.Num(); i++)
		{
			if (!Cast<AAGP_Objective>(ParentSequence[i])->bInactive)
			{
				return;
			}
		}
		SetInactive(true);
	}
}

void AAGP_Objective::SetInactive(bool new_inactive)
{
	int32 i = 0;
	bInactive = new_inactive;
	/*
	if (bInactive)
	{
		ObjectiveOnCompass=1;
		SetLocationProxy(nullptr);
		SetDisabled(true);
		for (i=0; i<ChildSequence.Num(); i++)
		{
			ChildSequence[i].NotifyParentInactive();
		}
	}
	SetCollision(! new_inactive);
	if (InventoryPickup != nullptr)
	{
		InventoryPickup.SetInactiveForRound(bInactive);
	}
	if (LinkedNPC != nullptr)
	{
		if (! new_inactive)
		{
			LinkedNPC.TurnOnPawn(LinkedNPC);
			LinkedNPC.SetCollision(LinkedNPC.Default.bCollideActors,LinkedNPC.Default.bBlockActors,LinkedNPC.Default.bBlockPlayers);
			LinkedNPC.bHidden=false;
			LinkedNPC.bStasis=false;
		}
		else
		{
			LinkedNPC.TurnOffPawn(LinkedNPC);
			LinkedNPC.SetCollision(false,false,false);
			LinkedNPC.bHidden=true;
			LinkedNPC.bStasis=true;
		}
	}
	*/
}

void AAGP_Objective::SetDisabled(bool E)
{
	if (bInactive)
	{
		bDisabled=true;
	}
	else
	{
		if (E == false && EnabledEvent != "None" && EnabledEvent != "None")
		{
			//TriggerEvent(EnabledEvent,Self,None);
		}
		bDisabled=E;
	}
}

void AAGP_Objective::SetSquadTarget(int32 iTeam, bool E)
{
	BlinkObjectiveOnRadar(iTeam,6);
	if (iTeam == 0)
	{
		_bSquadTarget=E;
	}
	else
	{
		if (iTeam == 1)
		{
			_bSquadTarget1=E;
		}
	}
}
bool AAGP_Objective::IsEnabled()
{
	return !bDisabled;
}
bool AAGP_Objective::IsInstantWin()
{
	return bInstantWin;
}
bool AAGP_Objective::IsSquadTarget(int32 iTeam)
{
	if (iTeam == 0)
	{
		return _bSquadTarget;
	}
	else
	{
		return _bSquadTarget1;
	}
}

bool AAGP_Objective::IsRequired()
{
	return bRequiredToWin && ! bInactive;
}

bool AAGP_Objective::CheckAllowedPickupTeam(APawn* User)
{
	return false;    //FAKE  /ELiZ
}

void AAGP_Objective::DetermineCarriedCompassVisbility(APawn* ObjCarrier, bool bDropped)
{
}

bool AAGP_Objective::CarryObjectiveUsed(APawn* User)
{
	return false;    //FAKE  /ELiZ
}

uint8 AAGP_Objective::GetPickupTeamOwner()
{
	return 0;
}

bool AAGP_Objective::IsAlternating()
{
	return bTakeTurns;
}

float AAGP_Objective::GetPercentComplete()
{
	if (bDisabled)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

FString AAGP_Objective::GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener)
{
	/*
	if (AnyTeamCanAttack())
	{
		if (Accomplisher == listener)
		{
			return AccomplishMessage;
		}
		else
		{
			return FailedDefenseMessage;
		}
	}
	if (listener == AttackTeam)
	{
		return AccomplishMessage;
	}
	else
	{
		return FailedDefenseMessage;
	}
	*/
	return "FAKE";     //FAKE  /EliZ
}

FString AAGP_Objective::GetDescriptionByTeam(uint8 listener)
{
	/*
	if (AnyTeamCanAttack())
	{
		return AttackDescription;
	}
	if (! Cast<AAGP_GameInfo>(GetGameMode()).IsTeamGame())
	{
		return AttackDescription;
	}
	if (listener == AttackTeam)
	{
		return AttackDescription;
	}
	else
	{
		return DefenseDescription;
	}
	*/
	return "FAKE";     //FAKE  /EliZ
}

FString AAGP_Objective::GetDescriptionByPawn(APawn* listener)
{
	/*
	if (listener == nullptr)
	{
		return AttackDescription;
	}
	if (AnyTeamCanAttack())
	{
		return AttackDescription;
	}
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if (! Cast<AAGP_GameInfo>(GetGameMode()).IsTeamGame())
		{
			return AttackDescription;
		}
	}
	else
	{
		if (listener.PlayerReplicationInfo == nullptr || listener.PlayerReplicationInfo.Team == nullptr)
		{
			return AttackDescription;
		}
	}
	if (listener.PlayerReplicationInfo.Team.TeamIndex == AttackTeam)
	{
		return AttackDescription;
	}
	else
	{
		return DefenseDescription;
	}
	*/
	return "FAKE";     //FAKE  /EliZ
}

FString AAGP_Objective::GetDescriptionByController(AController* listener)
{
	/*
	int32 i = 0;
	if (! IsEnabled())
	{
		return "";
	}
	if (ObjectiveOnCompass == 6 && listener.Pawn != pawnMustBeUsedBy)
	{
		return "";
	}
	if (listener == nullptr)
	{
		return AttackDescription;
	}
	if (AnyTeamCanAttack())
	{
		return AttackDescription;
	}
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if (! Cast<AAGP_GameInfo>(GetGameMode()).IsTeamGame())
		{
			return AttackDescription;
		}
	}
	else
	{
		if (listener.PlayerReplicationInfo == nullptr || listener.PlayerReplicationInfo.Team == nullptr)
		{
			return AttackDescription;
		}
	}
	if (listener.PlayerReplicationInfo.Team.TeamIndex == AttackTeam && ! listener.PlayerReplicationInfo.bGuerrillaPS)
	{
		if (MustBeClass == nullptr)
		{
			return AttackDescription;
		}
		if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
		{
			return MBCAttackDescription;
		}
		for (i=0; i<32; i++)
		{
			if (listener.PlayerReplicationInfo.Team.TeamList[i] != nullptr)
			{
				if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
				{
					return AttackDescription;
				}
			}
		}
		return altAttackDescription;
	}
	else
	{
		if (listener.PlayerReplicationInfo.Team.TeamIndex == AttackTeam && listener.PlayerReplicationInfo.bGuerrillaPS)
		{
			if (MustBeClass == nullptr)
			{
				return IFAttackDescription;
			}
			if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
			{
				return MBCAttackDescription;
			}
			for (i=0; i<32; i++)
			{
				if (listener.PlayerReplicationInfo.Team.TeamList[i] != nullptr)
				{
					if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
					{
						return IFAttackDescription;
					}
				}
			}
			return altAttackDescription;
		}
		else
		{
			if (listener.PlayerReplicationInfo.Team.TeamIndex != AttackTeam && ! listener.PlayerReplicationInfo.bGuerrillaPS)
			{
				if (MustBeClass == nullptr)
				{
					return DefenseDescription;
				}
				if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
				{
					return MBCDefenseDescription;
				}
				for (i=0; i<32; i++)
				{
					if (listener.PlayerReplicationInfo.Team.TeamList[i] != nullptr)
					{
						if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
						{
							return DefenseDescription;
						}
					}
				}
				return altDefenseDescription;
			}
			else
			{
				if (listener.PlayerReplicationInfo.Team.TeamIndex != AttackTeam && listener.PlayerReplicationInfo.bGuerrillaPS)
				{
					if (MustBeClass == nullptr)
					{
						return IFDefenseDescription;
					}
					if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
					{
						return MBCDefenseDescription;
					}
					for (i=0; i<32; i++)
					{
						if (listener.PlayerReplicationInfo.Team.TeamList[i] != nullptr)
						{
							if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
							{
								return IFDefenseDescription;
							}
						}
					}
					return altDefenseDescription;
				}
			}
		}
	}
	*/
	return "FAKE";     //FAKE  /EliZ
}

bool AAGP_Objective::IsHigherPriorityThan(ABaseObjective* otherb)
{
	AAGP_Objective* Other = nullptr;
	/*
	if (otherb == nullptr || ! otherb.IsEnabled() || ! otherb->IsA(AAGP_Objective::StaticClass()))
	{
		return true;
	}
	Other=AGP_Objective(otherb);
	if (! IsEnabled())
	{
		return false;
	}
	if (bInstantWin && ! Other.bInstantWin)
	{
		return true;
	}
	if (! bInstantWin && Other.bInstantWin)
	{
		return false;
	}
	return AttackPriority >= Other.AttackPriority;
	*/
	return false;    //FAKE   /ELiZ
}

uint8 AAGP_Objective::GetHUDPosition()
{
	return HUDLetter;
}

bool AAGP_Objective::AnyTeamCanAttack()
{
	return AttackTeam == 255;
}
bool AAGP_Objective::CanTeamAttack(uint8 B)
{
	if(GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	return AnyTeamCanAttack() || B == AttackTeam;
}
bool AAGP_Objective::CanTeamInfoAttack(ATeamInfo* t)
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	if (t == NULL)
	{
		return false;
	}
	return false;
	//return AnyTeamCanAttack() || Cast<ATeamInfo>(t)->TeamIndex == AttackTeam;
}

bool AAGP_Objective::CanAccomplish(APawn* p)
{
	int32 i = 0;
	AController* C = nullptr;
	bool TeammateCanAccomplish = false;
	/*
	if (p == nullptr || p.Controller == nullptr)
	{
		return false;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	if (bCheckRequiredChildObjectives)
	{
		for (i=0; i<ChildSequence.Num(); i++)
		{
			if (ChildSequence[i].IsRequired() && ! ChildSequence[i].CanAccomplish(p))
			{
				TeammateCanAccomplish=false;
				C=Level.ControllerList;
				if (C != nullptr)
				{
					if (! C.Pawn.IsHumanControlled())
					{
					}
					if (C.Pawn.GetTeam().TeamIndex != p.GetTeam().TeamIndex)
					{
					}
					if (ChildSequence[i].CanAccomplish(C.Pawn))
					{
						TeammateCanAccomplish=true;
					}
					else
					{
						C=C.nextController;
					}
				}
				if (! TeammateCanAccomplish)
				{
					return false;
				}
			}
		}
	}
	if (p.Controller->IsA(AHumanController::StaticClass()) && Cast<AHumanController>(p->Controller).StartupStage == 6 || GetNetMode() == ENetMode::NM_Standalone)
	{
		if (p.PlayerReplicationInfo != nullptr)
		{
			if (CanTeamInfoAttack(p.PlayerReplicationInfo.Team))
			{
				return true;
			}
		}
	}
	return false;
	*/
	return true;   //FAKE /ELiZ
}

bool AAGP_Objective::WasAccomplishedBy(uint8 some_team)
{
	return some_team == AccomplishedBy;
}

void AAGP_Objective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	ATeamInfo* Team = nullptr;
	FString Msg = "";
	int32 i = 0;
	APlayerController* PC = nullptr;
	ANPCAICombatController* npcaiccIterator = nullptr;
	int32 iObjCommandIndex = 0;
	/*
	if (Instigator != nullptr && Instigator.PlayerReplicationInfo != nullptr)
	{
		Team=Instigator.PlayerReplicationInfo.Team;
		if (Team != nullptr)
		{
			AccomplishedBy=Team.TeamIndex;
		}
	}
	else
	{
		if (Killer != nullptr && Killer.PlayerReplicationInfo != nullptr)
		{
			Instigator=Killer.Pawn;
			Team=Killer.PlayerReplicationInfo.Team;
			if (Team != nullptr)
			{
				AccomplishedBy=Team.TeamIndex;
			}
		}
		else
		{
			AccomplishedBy=255;
		}
	}
	NotifySequenceChildren();
	for (i=0; i<VisibilityChildren.Num(); i++)
	{
		if (! VisibilityChildren[i].bInactive)
		{
			switch(AccomplishedBy)
			{
				case 0:
				VisibilityChildren[i].ObjectiveOnCompass=2;
				break;
				case 1:
				VisibilityChildren[i].ObjectiveOnCompass=3;
				break;
				default:
				VisibilityChildren[i].ObjectiveOnCompass=0;
				break;
			}
		}
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Msg=GetAccomplishMessageByTeam(AccomplishedBy,0);
		if (Msg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(0,Msg,'Center');
		}
		Msg=GetAccomplishMessageByTeam(AccomplishedBy,1);
		if (Msg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(1,Msg,'Center');
		}
	}
	PlaySound(AccomplishSound,0,,,,,false);
	SetDisabled(true);
	TriggerEvent(Event,Self,Instigator);
	if (bChangeObjectiveOnCompassOnCompletion)
	{
		ObjectiveOnCompass=CompletedObjectiveOnCompass;
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		if (IsAlternating())
		{
			if (AccomplishedBy == 0)
			{
				AttackTeam=1;
			}
			else
			{
				if (AccomplishedBy == 1)
				{
					AttackTeam=0;
				}
				else
				{
					AttackTeam=255;
				}
			}
			SideReset();
		}
		if (Cast<AAGP_GameInfo>(GetGameMode()) != nullptr)
		{
			AGP_GameInfo(GetGameMode()).ScoreAGPObjective(Team,Self,false,Instigator.PlayerReplicationInfo);
			if (ctrlrESSReporter != nullptr && ctrlrESSReporter != Instigator.Controller)
			{
				AGP_GameInfo(GetGameMode()).ScoreAGPObjective(ctrlrESSReporter.PlayerReplicationInfo.Team,Self,false,Instigator.PlayerReplicationInfo);
			}
		}
		if (IsAlternating())
		{
			SetDisabled(false);
		}
	}
	PC=Cast<APlayerController>(Instigator.Controller);
	if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
	{
		Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_CapturedObjective();
	}
	if (_Target != nullptr)
	{
		_Target.Notify();
	}
	ForEach AllActors('NPCAICombatController',npcaiccIterator)
	{
		if (! npcaiccIterator.bDisableCombatController)
		{
			for (iObjCommandIndex=0; iObjCommandIndex<anpcoaNPCResponse.Num(); iObjCommandIndex++)
			{
				switch(anpcoaNPCResponse[iObjCommandIndex].enpcrocNPCCommand)
				{
					case 0:
					npcaiccIterator.SpawnTriggeredReinforcements(anpcoaNPCResponse[iObjCommandIndex].iReservePlatoonID,anpcoaNPCResponse[iObjCommandIndex].iReserveSquadID,anpcoaNPCResponse[iObjCommandIndex].iReserveFireteamID,"FollowOrders",Location);
					break;
					case 1:
					npcaiccIterator.SpawnTriggeredReinforcements(anpcoaNPCResponse[iObjCommandIndex].iReservePlatoonID,anpcoaNPCResponse[iObjCommandIndex].iReserveSquadID,anpcoaNPCResponse[iObjCommandIndex].iReserveFireteamID,"GotoObjective",Location);
					break;
					default:
				}
			}
			npcaiccIterator.NotifyObjectiveAccomplished(this);
		}
		else
		{
		}
	}
	if (bPlayerRadioedObectiveInfo)
	{
		Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ESSPostRadioLinkedObjectTaken();
	}
	else
	{
		if (sndESSObjectiveCompletionAcknowledgement != nullptr)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ESSNoRadioLinkedObjectTaken();
		}
	}
	PlayESSCompletionMessage(PC);
	*/
}

void AAGP_Objective::PlayESSCompletionMessage(APlayerController* PC)
{
	AController* ctrlIterator = nullptr;
	if (sndESSObjectiveCompletionAcknowledgement == nullptr)
	{
		return;
	}
	/*
	if (bESSObjectiveCompleteSoundPlayerOnly)
	{
		Cast<AHumanController>(PC)->ClientESSRadioSuccessMessage(sndESSObjectiveCompletionAcknowledgement);
	}
	else
	{
		for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
		{
			if ((((Cast<AHumanController>(ctrlIterator) != nullptr) && (Cast<AHumanController>(ctrlIterator).PlayerReplicationInfo != nullptr)) && (Cast<APlayerController>(ctrlIterator).PlayerReplicationInfo.Team != nullptr)) && (Cast<AHumanController>(ctrlIterator).PlayerReplicationInfo.Team.TeamIndex == PC.PlayerReplicationInfo.Team.TeamIndex))
			{
				Cast<AHumanController>(ctrlIterator).ClientESSRadioSuccessMessage(sndESSObjectiveCompletionAcknowledgement);
			}
		}
	}
	*/
}

void AAGP_Objective::SendPercentage(APawn* whocares)
{
	int32 iPercent = 0;
	APlayerController* PC = nullptr;
	/*
	if (whocares == nullptr || whocares.Controller == nullptr)
	{
		return;
	}
	PC=Cast<APlayerController>(whocares.Controller);
	if (PC == nullptr)
	{
		return;
	}
	iPercent=GetPercentComplete() * 100;
	if (iLastPercent != iPercent)
	{
		Level.Game.BroadcastHandler.BroadcastLocalized(this,PC,'ObjLocalMessage',iPercent);
		if (iPercent > ProgressSoundStart)
		{
			if (iLastProgressPercent < ProgressSoundStart || iPercent > iLastProgressPercent + ProgressSoundInterval)
			{
				PlaySound(ProgressSound,0,0.5);
				iLastProgressPercent=iPercent;
			}
		}
		iLastPercent=iPercent;
	}
	*/
}
void AAGP_Objective::SideReset()
{
	SetTeamMesh();
}
void AAGP_Objective::Reset()
{
	Super::Reset();
	InitializeNPCObjective();
	SetInactive(false);
	AttackTeam=_OriginalAttackTeam;
	ObjectiveOnCompass=_OriginalObjectiveOnCompass;
	_bSquadTarget=false;
	iLastPercent=0;
	iLastProgressPercent=0;
	SetTeamMesh();
	if (ParentSequence.Num() == 0)
	{
		SetDisabled(false);
	}
	else
	{
		SetDisabled(true);
	}
	ResetLocationProxy();
	AccomplishedBy=255;
}
void AAGP_Objective::grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController)
{
}

float AAGP_Objective::getReportDistance()
{
	return 0;    //FAKE   /EliZ
}

float AAGP_Objective::getObserveDistance()
{
	return 0;    //FAKE   /EliZ
}

float AAGP_Objective::getDangerDistance()
{
	return 0;    //FAKE   /EliZ
}

bool AAGP_Objective::isDangerous()
{
	return false;    //FAKE   /EliZ
}

bool AAGP_Objective::isReportable()
{
	return false;    //FAKE   /EliZ
}

void AAGP_Objective::MakeES2ObjectiveReportable()
{
}

USoundBase* AAGP_Objective::getAcknowledgeVO()
{
	return nullptr;    //FAKE   /EliZ
}

FString AAGP_Objective::getAcknowledgeText()
{
	return "FAKE";    //FAKE   /EliZ
}

FName AAGP_Objective::getFlagTag()
{
	return "FAKE";    //FAKE   /EliZ
}

AFlagMeshActor* AAGP_Objective::getFlagReference()
{
	return nullptr;    //FAKE   /EliZ
}

bool AAGP_Objective::isUseable()
{
	return false;    //FAKE   /EliZ
}

float AAGP_Objective::getDialogLength()
{
	return 0;    //FAKE   /EliZ
}

TArray<AAGP_Objective*> AAGP_Objective::getLinkedArray()
{
	return {};    //FAKE   /EliZ
}

void AAGP_Objective::ActivateFromRadio(AHumanController* aInstigator)
{
}

bool AAGP_Objective::isOnRadar()
{
	return false;    //FAKE  /EliZ
}

void AAGP_Objective::MakeESSObjectAppearOnRadar()
{
}

FName AAGP_Objective::getReportEventName()
{
	return "FAKE";    //FAKE  /EliZ
}

bool AAGP_Objective::isDummyTrainingObject()
{
	return false;    //FAKE  /EliZ
}

FName AAGP_Objective::getBecomeActiveEvent()
{
	return "FAKE";    //FAKE  /EliZ
}

bool AAGP_Objective::isUseOnReport()
{
	return false;    //FAKE  /EliZ
}
