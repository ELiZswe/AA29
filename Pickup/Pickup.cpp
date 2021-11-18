// All the original content belonged to the US Army


#include "Pickup.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/AA2_PlayerState.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxDesireability         = 0.1;
	bOnlyReplicateHidden     = true;
	RespawnEffectTime        = 0.5;
	PickupMessage            = FString("Snagged an item.");
	idTeamOwner              = 255;
	bDestroyOnMoverEncroach  = true;
	DrawType                 = EDrawType::DT_Mesh;
	//CullDistance = 8000;
	//bOrientOnSlope = true;
	//bIgnoreEncroachers = true;
	bAlwaysRelevant          = true;
	//bIgnoreVehicles = true;
	NetUpdateFrequency       = 8;
	NetPriority              = 1.4;
	Texture                  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/Engine/S_Inventory.S_Inventory"), NULL, LOAD_None, NULL);
	//bShouldBaseAtStartup = true;
	//bCollideActors = true;
	//bCollideWorld = true;
	//bProjTarget = true;
	//bUseCylinderCollision = true;
	DrawType                 = EDrawType::DT_Mesh;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	VisibleStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	VisibleStaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	VisibleSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	VisibleSkeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void APickup::AddToNavigation()
{

}
void APickup::RemoveFromNavigation()
{

}
/*
void APickup::StaticPrecache(LevelInfo L)
{
}
*/
void APickup::PostBeginPlay()
{
	/*
	bPlacedPickup = Level.bStartup;
	Level.addPickup(Self);
	*/
}
void APickup::MatchStarting()
{
	/*
	if (bActiveOnTrigger)
	{
		bHidden = true;
	}
	if (bPlacedPickup)
	{
		GotoState('Pickup');
	}
	*/
}
void APickup::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (bActiveOnTrigger)
	{
		bHidden = False;
	}
	*/
}
void APickup::MatchEnding()
{
	/*
	if (!bPlacedPickup)
	{
		Destroy();
	}
	*/
}
void APickup::Destroyed()
{
	/*
	Level.removePickup(Self);
	if (myMarker != None)
	{
		myMarker.markedItem = None;
	}
	if (Inventory != None)
	{
		Inventory.Destroy();
		Inventory = None;
	}
	*/
}
/*
void APickup::GetHumanReadableName()
{
	if (InventoryType == None)
	{
		Return GetItemName(Class);
	}
	if (InventoryType.Default.ItemName == "")
	{
		Return GetItemName(InventoryType);
	}
	Return InventoryType.Default.ItemName;
}
*/

bool APickup::IsSuperItem()
{
	return PickUpBase != nullptr && Cast<AxPickUpBase>(PickUpBase)->bDelayedSpawn;
}

/*
void APickup::UpdateHUD(AHUD* H)
{
	Cast<AHud>(H).LastPickupTime = H.GetWorld()->GetTimeSeconds();
}
*/
void APickup::Reset()
{
	/*
	if (Inventory != None)
	{
		Destroy();
	}
	else
	{
		if (myMarker != None && myMarker.bSuperPickup)
		{
			GotoState('Sleeping', 'DelayedSpawn');
		}
		else
		{
			GotoState('Pickup');
		}
		Reset();
	}
	*/
}
void APickup::RespawnEffect()
{
}
void APickup::Transmogrify(APickup*  NewClass)
{
	/*
	local Pickup NewPickup;
	NewPickup = Spawn(NewClass);
	NewPickup.PickUpBase = PickUpBase;
	NewPickup.RespawnTime = RespawnTime;
	if (myMarker != None)
	{
		myMarker.markedItem = NewPickup;
		NewPickup.myMarker = myMarker;
		myMarker = None;
	}
	Destroy();
	Return NewPickup;
	*/
}
float APickup::DetourWeight(APawn* Other, float PathWeight)
{
	return 0;
}
float APickup::BotDesireability(APawn* Bot)
{
	/*
	local Inventory AlreadyHas;
	local float desire;
	desire = MaxDesireability;
	if (RespawnTime < 10)
	{
		AlreadyHas = Bot.FindInventoryType(InventoryType);
		if (AlreadyHas != None)
		{
			if (Inventory != None)
			{
				if (Inventory.Charge <= AlreadyHas.Charge)
				{
					Return - 1;
				}
			}
			else
			{
				if (InventoryType.Default.Charge <= AlreadyHas.Charge)
				{
					Return - 1;
				}
			}
		}
	}
	Return desire;
	*/
	return 0;   //FAKE /ELiZ
}

bool APickup::UseEnemyClass(AAA2_PlayerState* PRI)
{
	if (PRI == nullptr)
	{
		PRI = Cast<AAA2_WorldSettings>(GetWorldSettings())->GetClient();
		if (PRI == nullptr)
		{
			//DebugLog(DEBUG_Warn, "Pickup::UseEnemyClass()	Could not find the Client PRI! Returning false");
			return false;
		}
	}
	if (Cast<AHumanController>(Cast<AAA2_PlayerState>(PRI)->GetOwner())->DebugSwapPickups())
	{
		return true;
	}
	
	if (Cast<AAA2_PlayerState>(PRI)->Team == nullptr)
	{
		return false;
	}
	return !(EnemyPickupClass == nullptr || idTeamOwner == 255 || idTeamOwner == Cast<AAA2_PlayerState>(PRI)->Team->TeamIndex || Cast<AAA2_WorldSettings>(GetWorldSettings())->GamePlayMode == EGameplayModes::GM_MILES);
}

void APickup::GetInventoryClassFor(APawn* Other)
{
	/*
	if (!UseEnemyClass(Other.PlayerReplicationInfo))
	{
		DebugLog(DEBUG_Inv, "Pickup::GetInventoryClassFor()	Pickup is a friend: " $ InventoryType);
		Return InventoryType;
	}
	else
	{
		DebugLog(DEBUG_Inv, "Pickup::GetInventoryClassFor()	Pickup is an enemy: " $ EnemyPickupClass.Default.InventoryType);
		Return EnemyPickupClass.Default.InventoryType;
	}
	*/
}
void APickup::SpawnCopy(APawn* Other, bool bRealInventory)
{
	/*
	local Inventory Copy;
	local class<Inventory>  SpawnType;
	local bool bVirtual;
	SpawnType = GetInventoryClassFor(Other);
	if (False)
	{
		Copy = Inventory;
		Inventory = None;
	}
	else
	{
		Copy = Spawn(SpawnType, Other, , , rot(0 0 0));
		Copy.InitFor(Inventory);
		if (EventLab != None)
		{
			Copy.SetEventLab(EventLab);
		}
		if (Inventory != None)
		{
			Inventory.Destroy();
			Inventory = None;
		}
	}
	bVirtual = Copy.bVirtualInventory && !bRealInventory;
	if (Other.CanPickupItem(Copy, bVirtual))
	{
		AnnouncePickup(Other);
		if (bVirtual)
		{
			Other.CreateVirtualInventory(Copy.Class);
			Copy.Destroy();
		}
		else
		{
			SetupCopy(Copy, Other);
			Copy.GiveTo(Other, Self);
			Copy.PickupFunction(Other);
		}
		Instigator = Other;
	}
	else
	{
		Instigator = None;
		Inventory = Copy;
		Copy = None;
	}
	Return Copy;
	*/
}
void APickup::ValidTouch(AActor* Other)
{
}
void APickup::CanSpawnCopy(APawn* Other, bool bRealInventory)
{
	/*
	local Inventory Copy;
	local class<Inventory>  SpawnType;
	local bool bVirtual;
	local bool bCanSpawn;
	if (!ValidTouch(Other))
	{
		Return False;
	}
	SpawnType = GetInventoryClassFor(Other);
	Copy = Spawn(SpawnType, Other, , , rot(0 0 0));
	bVirtual = Copy.bVirtualInventory && !bRealInventory;
	bCanSpawn = Other.CanPickupItem(Copy, bVirtual);
	Copy.Destroy();
	Return bCanSpawn;
	*/
}
void APickup::SetupCopy(AInventory* Copy, APawn* Other)
{
}
void APickup::PickupTaken()
{
	/*
	if (Level.Game.ShouldRespawn(Self))
	{
		StartSleeping();
	}
	else
	{
		Destroy();
	}
	*/
}
void APickup::StartSleeping()
{
	/*
	GotoState('Sleeping');
	*/
}
void APickup::AnnouncePickup(APawn* Receiver)
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 2, Receiver);
	}
	Receiver.HandlePickup(Self);
	PlaySound(PickupSound, 1, 0.5, False, 40, , True, false);
	*/
}
void APickup::SetRespawn()
{
	/*
	if (Level.Game.ShouldRespawn(Self))
	{
		StartSleeping();
	}
	else
	{
		Destroy();
	}
	*/
}
/*
void GetLocalString(int32 Switch, PlayerReplicationInfo RelatedPRI_1, PlayerReplicationInfo RelatedPRI_2)
{
	Return Default.PickupMessage;
}
*/
AInventory* APickup::TakeItem(AActor* Other)
{
	return NULL;
}
void APickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	/*
	if (bFreeze)
	{
		GotoState('Pickup');
	}
	else
	{
		SetPhysics(2);
		MaybeAdjustCollisionSize();
		GotoState('None');
	}
	Inventory = Inv;
	bAlwaysRelevant = False;
	bOnlyReplicateHidden = False;
	if (Inv == None || Inv.IsA('Weapon') && Weapon(Inv).bGuerrillaWeapon == true)
	{
		idTeamOwner = 255;
	}
	else
	{
		idTeamOwner = Inv.idTeamOwner;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		MaybeSetStaticMesh();
	}
	bUpdateSimulatedPosition = true;
	bDropped = true;
	bIgnoreEncroachers = False;
	*/
}
void APickup::MaybeAdjustCollisionSize()
{
}
void APickup::MaybeSetStaticMesh()
{
	/*
	if (UseEnemyClass())
	{
		Switch(DrawType)
		{
			case 8:
				SetStaticMesh(EnemyPickupClass.Default.StaticMesh);
				break;
			case 2:
				LinkMesh(EnemyPickupClass.Default.Mesh);
				break;
			default:
		}
		Level.SetActorLevelSkin(Self, false);
		Return True;
	}
	Level.SetActorLevelSkin(Self, true);
	Return False;
	*/
}
bool APickup::ReadyToPickup(float MaxWait)
{
	return false;
}
void APickup::Landed(FVector HitNormal)
{
	/*
	GotoState('Pickup');
	*/
}
float APickup::GetRespawnTime()
{
	return RespawnTime;
}