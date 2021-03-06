// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AA29/Object/Actor/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"
#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "Runtime/CoreUObject/Public/UObject/SoftObjectPtr.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAGP_ObjectivePickup::AAGP_ObjectivePickup()
{
	bDisplayTargetingInfo		= true;
	bWaitingFirstPickup			= true;
	USPickupMsg					= "Your Team has picked up the objective.";
	OPFORPickupMsg				= "The Opposing Team has picked up the objective.";
	USDropMsg					= "Your Team has dropped the objective.";
	OPFORDropMsg				= "The Opposing Team has dropped the objective.";
	FallBackDropMsg				= "The objective has been dropped.";
	InventoryType				= AAGP_ObjectiveInventory::StaticClass();
	bOnlyReplicateHidden		= false;
	EnemyPickupClass			= AAGP_ObjectivePickup::StaticClass();
	bDestroyOnMoverEncroach		= false;
	DrawType					= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/pelicancase.pelicancase"), NULL, LOAD_None, NULL));
	//bNoDelete = true;
	//bAlwaysTestCollision = true;
	//CollisionRadius = 24;
	//CollisionHeight = 16;
	//bBlockBulletTraces = false;

}

/*
State Sleeping
{
	Function BeginState()
	{
		int32 i = 0;
		NetUpdateTime=(GetWorld()->GetTimeSeconds() - 1);
		SetCollision(false,false,false);
		Level.removePickup(this);
		if (bInactiveForRound)
		{
			if (bHideOnRoundInactive)
			{
				bHidden=true;
			}
			else
			{
				bHidden=false;
			}
		}
		else
		{
			bHidden=true;
		}
		for (i=0; i<4; i++)
		{
			TeamOwner[i]=nullptr;
		}
	}
	Function EndState()
	{
		SetCollision(true,false,false);
		Instigator=nullptr;
		Level.addPickup(this);
		NetUpdateTime=(GetWorld()->GetTimeSeconds() - 1);
		bHidden=false;
	}
	Function MatchStarting()
	{
		if (Objective != nullptr)
		{
			SetTeamOwner(Objective.GetPickupTeamOwner());
		}
		else
		{
			SetTeamOwner(255);
		}
	}
	Function SetInactive(bool new_inactive)
	{
		if (! new_inactive)
		{
			GotoState("Pickup");
		}
	}
	Function SetInactiveForRound(bool bInactive)
	{
		if (! bInactive)
		{
			bInactiveForRound=false;
			GotoState("Pickup");
		}
	}
}
*/

/*
auto State Pickup
{
	Function bool UsedBy(APawn* User)
	{
		if (Objective != nullptr)
		{
			return Objective.CarryObjectiveUsed(User);
		}
		else
		{
			DebugLog(DEBUG_Multi,"AGP_ObjectivePickup::Pickup::UsedBy() No Objective!");
			return false;
		}
	}
	Function Inventory TakeItem(AActor* Other)
	{
		APawn* User = nullptr;
		AInventory* invItemPickedUp = nullptr;
		User=Pawn(Other);
		if (User == nullptr)
		{
			return nullptr;
		}
		if (Objective.CheckAllowedPickupTeam(User))
		{
			bPickupMoved=true;
			if (! bStartingLocAndRotSaved)
			{
				bStartingLocAndRotSaved=true;
				OriginalLocation=Location;
				OriginalRotation=Rotation;
				OriginalPrePivot=PrePivot;
			}
			invItemPickedUp=Super::TakeItem(Other);
			if (invItemPickedUp != nullptr)
			{
				LastHolderTeamIndex=byte(User.PlayerReplicationInfo.Team.TeamIndex);
				BroadcastPickupMessages(User);
			}
			return invItemPickedUp;
		}
		else
		{
			return nullptr;
		}
	}
	Function bool ReadyToPickup(float F)
	{
		return (! bPlacedPickup);
	}
}
*/

void AAGP_ObjectivePickup::BeginPlay()
{
	Super::BeginPlay();
	if (FriendlyStaticMesh != nullptr)
	{
		VisibleStaticMesh->SetStaticMesh(FriendlyStaticMesh);
	}
}

void AAGP_ObjectivePickup::PostBeginPlay()
{
	Super::PostBeginPlay();
	if (bPlacedPickup)
	{
		SetPlacedPickup(this);
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bHideInactiveObjectives)
	{
		bHideOnRoundInactive=true;
	}
	if (FriendlyStaticMesh == nullptr)
	{
		FriendlyStaticMesh=StaticMesh;
	}
	if (EnemyStaticMesh == nullptr)
	{
		EnemyStaticMesh=StaticMesh;
	}
}
void AAGP_ObjectivePickup::Destroyed()
{
	Objective=NULL;
	PlacedPickup=NULL;
	Super::Destroyed();
}
void AAGP_ObjectivePickup::SetupCopy(AInventory* Copy, APawn* Other)
{
	AAGP_ObjectiveInventory* OInventory = nullptr;
	OInventory = Cast<AAGP_ObjectiveInventory>(Copy);
	if (OInventory != nullptr)
	{
		//OInventory.Instigator = Other;
		//OInventory.setObjective(Objective);
		//OInventory.SetPlacedPickup(PlacedPickup);
		//Objective.SetLocationProxy(Other.PlayerReplicationInfo);
	}
	else
	{
		//DebugLog(DEBUG_Multi, "AGP_ObjectivePickup::SetupCopy() Failed to Spawn an ObjectiveInventory(" @ Copy @ ")");
	}
}

void AAGP_ObjectivePickup::SetInactiveForRound(bool bInactive)
{
	if (bInactive)
	{
		bInactiveForRound=true;
		//GotoState('Sleeping');
	}
}

void AAGP_ObjectivePickup::SetInactive(bool new_inactive)
{
	if (new_inactive)
	{
		//GotoState('Sleeping');
	}
}

AInventory* AAGP_ObjectivePickup::SpawnCopy(APawn* Other, bool bRealInventory)
{
	AInventory* Copy = nullptr;
	/*
	SpawnType=GetInventoryClassFor(Other);
	Copy=Spawn(SpawnType,Other,,,FRotator(0 0 0));
	Copy.InitFor(Inventory);
	AGP_ObjectiveInventory(Copy).setObjective(Objective);
	if (Inventory != nullptr)
	{
		Inventory.Destroy();
		Inventory=nullptr;
	}
	if (Other.CanPickupItem(Copy,false))
	{
		AnnouncePickup(Other);
		SetupCopy(Copy,Other);
		Copy.GiveTo(Other,Self);
		Copy.PickupFunction(Other);
		Instigator=Other;
	}
	else
	{
		Instigator=nullptr;
		Inventory=Copy;
		Copy=nullptr;
	}
	*/
	return Copy;
}
void AAGP_ObjectivePickup::BroadcastDropMessages(APawn* LastHolder)
{
	AController* C = nullptr;
	int32 teamNumUS = 0;
	int32 teamNumOPFOR = 0;
	/*
	if (LastHolder != nullptr)
	{
		C=LastHolder.Controller;
	}
	if (C != nullptr && C.PlayerReplicationInfo != nullptr)
	{
		teamNumUS=C.PlayerReplicationInfo.Team.TeamIndex;
		if (teamNumUS == 0)
		{
			teamNumOPFOR=1;
		}
		else
		{
			teamNumOPFOR=0;
		}
		if (USDropMsg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(teamNumUS,USDropMsg,'Center');
		}
		if (OPFORDropMsg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(teamNumOPFOR,OPFORDropMsg,'Center');
		}
	}
	else
	{
		DebugLog(DEBUG_Multi,Self + " Unable to determine side of new ObjectivePickup holder");
		if (FallBackDropMsg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(1,FallBackDropMsg,'Center');
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(0,FallBackDropMsg,'Center');
		}
	}
	*/
}

void AAGP_ObjectivePickup::BroadcastPickupMessages(APawn* NewHolder)
{
	AController* C = nullptr;
	int32 teamNumUS = 0;
	int32 teamNumOPFOR = 0;
	/*
	if (! bBroadcastPickupMsgs)
	{
		return;
	}
	if (NewHolder != nullptr)
	{
		C=Cast<APlayerController>(NewHolder.Controller);
	}
	if (C != nullptr && C.PlayerReplicationInfo != nullptr)
	{
		teamNumUS=C.PlayerReplicationInfo.Team.TeamIndex;
		if (teamNumUS == 0)
		{
			teamNumOPFOR=1;
		}
		else
		{
			teamNumOPFOR=0;
		}
		if (USPickupMsg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(teamNumUS,USPickupMsg,'Center');
		}
		if (OPFORPickupMsg != "")
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(teamNumOPFOR,OPFORPickupMsg,'Center');
		}
	}
	else
	{
		DebugLog(DEBUG_Multi,Self + " Unable to determine side of new ObjectivePickup holder");
	}
	*/
}

void AAGP_ObjectivePickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	AAGP_ObjectiveInventory* OInv = nullptr;
	/*
	bCollideWorld=false;
	if (Inv.Instigator == nullptr)
	{
		Log(Self + " does not have an instigator! Attempted to change location to a nonexistant instigator location!");
	}
	if (Inv.Instigator != nullptr && Inv.Instigator.bIsProne)
	{
		if (! SetLocation(Inv.Instigator.Location + FVector(0 0 72)))
		{
			SetActorLocation(Inv.Instigator.Location);
		}
	}
	else
	{
		SetActorLocation(Inv.Instigator.Location);
	}
	bCollideWorld=true;
	SetPhysics(2);
	PrePivot.Z=CollisionHeight * 1 / DrawScale3D.Z;
	MaybeAdjustCollisionSize();
	Inventory=Inv;
	bOnlyReplicateHidden=false;
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		MaybeSetStaticMesh();
	}
	bUpdateSimulatedPosition=true;
	bDropped=true;
	SetInactive(false);
	SetCollision(true,false,false);
	Level.addPickup(this);
	OInv=AGP_ObjectiveInventory(Inv);
	RegisterSelfWithObjective();
	SetPlacedPickup(OInv.PlacedPickup);
	BroadcastDropMessages(OInv.Instigator);
	if (Objective != nullptr)
	{
		Objective.SetLocationProxy(this);
		Objective.DetermineCarriedCompassVisbility(OInv.Instigator,true);
	}
	else
	{
		DebugLog(DEBUG_Warn,"AGP_ObjectiveInventory::SetupInventoryObjective()	Could not find an Objective!");
	}
	*/
}

void AAGP_ObjectivePickup::SetPlacedPickup(AAGP_ObjectivePickup* new_placed_pickup)
{
	if (PlacedPickup != NULL)
	{
		//DebugLog(DEBUG_Warn,"AGP_ObjectivePickup::SetPlacedPickup()	PlacedPickup has already been set! (" @ PlacedPickup @ ")");
	}
	else
	{
		PlacedPickup=new_placed_pickup;
		FriendlyStaticMesh=PlacedPickup->FriendlyStaticMesh;
		EnemyStaticMesh=PlacedPickup->EnemyStaticMesh;
	}
}

void AAGP_ObjectivePickup::setObjective(AAGP_Objective* new_objective)
{
	Objective=new_objective;
	if (! bPlacedPickup)
	{
		SetTeamOwner(Objective->GetPickupTeamOwner());
	}
}

void AAGP_ObjectivePickup::SetTeamOwner(uint8 new_team_owner)
{
	idTeamOwner=new_team_owner;
}

void AAGP_ObjectivePickup::RegisterSelfWithObjective()
{
	Objective->InventoryPickup=Cast<UClass>(this);
}

void AAGP_ObjectivePickup::ResetPickupLocation()
{
	float ColHeight = 0;
	float ColRadius = 0;
	bool bDebugResets = 0;
	bool bOldBlockActors = 0;
	/*
	ColHeight=CollisionHeight;
	ColRadius=CollisionRadius;
	SetCollisionSize(0,0);
	bUseCylinderCollision=false;
	bCollideWorld=false;
	bOldBlockActors=bBlockActors;
	bBlockActors=false;
	SetCollision(false,false,false);
	bDebugResets=SetLocation(OriginalLocation);
	SetActorRotation(OriginalRotation);
	PrePivot=OriginalPrePivot;
	if (! bDebugResets)
	{
		Log("OBJECTIVE PICKUP WARNING - " + this + " wasn't reset to original location!");
		Log("reset location is " + Location + " and reset rotation is " + Rotation);
	}
	SetPhysics(0);
	bBroadcastPickupMsgs=false;
	SetCollision(true,false,false);
	bCollideWorld=true;
	bBlockActors=bOldBlockActors;
	bUseCylinderCollision=true;
	SetCollisionSize(ColRadius,ColHeight);
	bPickupMoved=false;
	*/
}

void AAGP_ObjectivePickup::CheckPickupLocation()
{
	//Log(Self + " Location: " + Location);
}

void AAGP_ObjectivePickup::MatchEnding()
{
	/*
	if (Role < 4)
	{
		return;
	}
	if (bPlacedPickup)
	{
		ResetPickupLocation();
	}
	else
	{
		if (! bPlacedPickup)
		{
			Destroy();
		}
	}
	if (Objective != nullptr)
	{
		SetTeamOwner(Objective.GetPickupTeamOwner());
	}
	else
	{
		SetTeamOwner(255);
	}
	*/
}

void AAGP_ObjectivePickup::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	if (GetLocalRole() == ENetRole::ROLE_Authority && !bStartingLocAndRotSaved)
	{
		bStartingLocAndRotSaved=true;
		OriginalLocation=GetActorLocation();
		OriginalRotation=GetActorRotation();
		OriginalPrePivot=PrePivot;
	}
}

void AAGP_ObjectivePickup::MatchStarting()
{
	Super::MatchStarting();
	if (Objective != NULL)
	{
		SetTeamOwner(Objective->GetPickupTeamOwner());
	}
	else
	{
		SetTeamOwner(255);
	}
}

bool AAGP_ObjectivePickup::MaybeSetStaticMesh()
{
	if (UseEnemyClass(nullptr))
	{
		VisibleStaticMesh->SetStaticMesh(EnemyStaticMesh);
		Cast<AAA2_WorldSettings>(GetWorldSettings())->SetActorLevelSkin(this,false,"");
		return true;
	}
	else
	{
		VisibleStaticMesh->SetStaticMesh(FriendlyStaticMesh);
		Cast<AAA2_WorldSettings>(GetWorldSettings())->SetActorLevelSkin(this,true,"");
		return false;
	}
	return false;    //FAKE ELiZ
}
