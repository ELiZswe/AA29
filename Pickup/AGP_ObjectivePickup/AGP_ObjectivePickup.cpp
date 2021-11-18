// All the original content belonged to the US Army


#include "AGP_ObjectivePickup.h"
#include "AA29/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"
#include "AA29/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "Runtime/CoreUObject/Public/UObject/SoftObjectPtr.h"

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
	/*
	local AGP_ObjectiveInventory OInventory;
	OInventory = AGP_ObjectiveInventory(Copy);
	if (OInventory != None)
	{
		OInventory.Instigator = Other;
		OInventory.setObjective(Objective);
		OInventory.SetPlacedPickup(PlacedPickup);
		Objective.SetLocationProxy(Other.PlayerReplicationInfo);
	}
	else
	{
		DebugLog(DEBUG_Multi, "AGP_ObjectivePickup::SetupCopy() Failed to Spawn an ObjectiveInventory(" @ Copy @ ")");
	}
	*/
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
void AAGP_ObjectivePickup::SpawnCopy(APawn* Other, bool bRealInventory)
{
	/*
		local Inventory Copy;
		local class<Inventory>  SpawnType;
		SpawnType=GetInventoryClassFor(Other);
		Copy=Spawn(SpawnType,Other,,,rot(0 0 0));
		Copy.InitFor(Inventory);
		AGP_ObjectiveInventory(Copy).setObjective(Objective);
		if (Inventory != None)
		{
			Inventory.Destroy();
			Inventory=None;
		}
		if (Other.CanPickupItem(Copy,False))
		{
			AnnouncePickup(Other);
			SetupCopy(Copy,Other);
			Copy.GiveTo(Other,Self);
			Copy.PickupFunction(Other);
			Instigator=Other;
		}
		else
		{
			Instigator=None;
			Inventory=Copy;
			Copy=None;
		}
		Return Copy;
	*/
}
void AAGP_ObjectivePickup::BroadcastDropMessages(APawn* LastHolder)
{
	/*
		local Controller C;
		local int teamNumUS;
		local int teamNumOPFOR;
		if (LastHolder != None)
		{
			C=LastHolder.Controller;
		}
		if (C != None && C.PlayerReplicationInfo != None)
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
			DebugLog(DEBUG_Multi,Self $ " Unable to determine side of new ObjectivePickup holder");
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
	/*
		local Controller C;
		local int teamNumUS;
		local int teamNumOPFOR;
		if (! bBroadcastPickupMsgs)
		{
			Return;
		}
		if (NewHolder != None)
		{
			C=PlayerController(NewHolder.Controller);
		}
		if (C != None && C.PlayerReplicationInfo != None)
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
			DebugLog(DEBUG_Multi,Self $ " Unable to determine side of new ObjectivePickup holder");
		}
	*/
}
void AAGP_ObjectivePickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	/*
		local AGP_ObjectiveInventory OInv;
		bCollideWorld=False;
		if (Inv.Instigator == None)
		{
			Log(Self $ " does not have an instigator! Attempted to change location to a nonexistant instigator location!");
		}
		if (Inv.Instigator != None && Inv.Instigator.bIsProne)
		{
			if (! SetLocation(Inv.Instigator.Location + vect(0 0 72)))
			{
				SetLocation(Inv.Instigator.Location);
			}
		}
		else
		{
			SetLocation(Inv.Instigator.Location);
		}
		bCollideWorld=True;
		SetPhysics(2);
		PrePivot.Z=CollisionHeight * 1 / DrawScale3D.Z;
		MaybeAdjustCollisionSize();
		Inventory=Inv;
		bOnlyReplicateHidden=False;
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			MaybeSetStaticMesh();
		}
		bUpdateSimulatedPosition=True;
		bDropped=True;
		SetInactive(False);
		SetCollision(True,False,False);
		Level.addPickup(Self);
		OInv=AGP_ObjectiveInventory(Inv);
		RegisterSelfWithObjective();
		SetPlacedPickup(OInv.PlacedPickup);
		BroadcastDropMessages(OInv.Instigator);
		if (Objective != None)
		{
			Objective.SetLocationProxy(Self);
			Objective.DetermineCarriedCompassVisbility(OInv.Instigator,True);
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
	/*
		local float ColHeight;
		local float ColRadius;
		local bool bDebugResets;
		local bool bOldBlockActors;
		ColHeight=CollisionHeight;
		ColRadius=CollisionRadius;
		SetCollisionSize(0,0);
		bUseCylinderCollision=False;
		bCollideWorld=False;
		bOldBlockActors=bBlockActors;
		bBlockActors=False;
		SetCollision(False,False,False);
		bDebugResets=SetLocation(OriginalLocation);
		SetRotation(OriginalRotation);
		PrePivot=OriginalPrePivot;
		if (! bDebugResets)
		{
			Log("OBJECTIVE PICKUP WARNING - " $ Self $ " wasn't reset to original location!");
			Log("reset location is " $ Location $ " and reset rotation is " $ Rotation);
		}
		SetPhysics(0);
		bBroadcastPickupMsgs=False;
		SetCollision(True,False,False);
		bCollideWorld=True;
		bBlockActors=bOldBlockActors;
		bUseCylinderCollision=True;
		SetCollisionSize(ColRadius,ColHeight);
		bPickupMoved=False;
	*/
}
void AAGP_ObjectivePickup::CheckPickupLocation()
{
	/*
		Log(Self $ " Location: " $ Location);
	*/
}
void AAGP_ObjectivePickup::MatchEnding()
{
	/*
		if (Role < 4)
		{
			Return;
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
		if (Objective != None)
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
	/*
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
	*/
	return false;    //FAKE ELiZ
}