// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/xPickUpBase/xPickUpBase.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/InventorySpot/InventorySpot.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"

// Sets default values
APickup::APickup()
{
	TeamOwner.SetNum(4);
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

/*
auto State Pickup
{
	Function bool UsedBy(APawn* User)
	{
		if ((EventLab != nullptr) && EventLab.ActorNotify(this,ET_UsedBy,User))
		{
			return false;
		}
		if (ReadyToPickup(0))
		{
			TakeItem(User);
			return true;
		}
		return false;
	}
	Function bool ReadyToPickup(float MaxWait)
	{
		return true;
	}
	Function bool ValidTouch(AActor* Other)
	{
		APawn* p = nullptr;
		p=Pawn(Other);
		if (bActiveOnTrigger && bHidden)
		{
			return false;
		}
		if (((Cast<APawn>(Other) == nullptr) || (! Pawn(Other).bCanPickupInventory)) || ((Cast<APawn>(Other).DrivenVehicle == nullptr) && (Cast<APawn>(Other).Controller == nullptr)))
		{
			return false;
		}
		if (p.IsInState("BusyDrawingBack"))
		{
			return false;
		}
		if (! FastTrace(p.EyePosition(),Location))
		{
			return false;
		}
		if (Level.Game.PickupQuery(p,Self))
		{
			TriggerEvent(Event,Self,p);
			return true;
		}
		return false;
	}
	Function bool ForceRealInventory(APawn* p)
	{
		return false;
	}
	Function Inventory TakeItem(AActor* Other)
	{
		APawn* p = nullptr;
		AInventory* Copy = nullptr;
		if (ValidTouch(Other))
		{
			p=Pawn(Other);
			Copy=SpawnCopy(p,ForceRealInventory(p));
			if (Instigator != nullptr)
			{
				PickupTaken();
			}
		}
		return Copy;
	}
}
*/

/*
State FallingPickup extends Pickup
{
	Function CheckTouching()
	{
	}
	Function Timer()
	{
		GotoState("FadeOut");
	}
	Function BeginState()
	{
		SetTimer(8,false);
	}
}
*/

/*
State FadeOut extends Pickup
{
	Function Tick(float DeltaTime)
	{
		SetDrawScale(FMax(0.01,(DrawScale - (Default.DrawScale * DeltaTime))));
	}
	Function BeginState()
	{
		RotationRate.Yaw=60000;
		SetPhysics(PHYS_Rotating);
		LifeSpan=1;
	}
	Function EndState()
	{
		LifeSpan=0;
		SetDrawScale(Default.DrawScale);
		if (Physics == 5)
		{
			SetPhysics(PHYS_None);
		}
	}
}
*/

/*
State WaitingForMatch
{
	Function MatchStarting()
	{
		GotoState("Sleeping","DelayedSpawn");
	}
	Function BeginState()
	{
		NetUpdateTime=(GetWorld()->GetTimeSeconds() - 1);
		bHidden=true;
	}
}
*/

/*
State Sleeping
{
	Function bool ReadyToPickup(float MaxWait)
	{
		return false;
	}
	Function StartSleeping()
	{
	}
	Function BeginState()
	{
		int32 i = 0;
		NetUpdateTime=(GetWorld()->GetTimeSeconds() - 1);
		SetCollision(false,false,false);
		Level.removePickup(this);
		bHidden=true;
		for (i=0; i<4; i++)
		{
			TeamOwner[i]=nullptr;
		}
	}
	Function EndState()
	{
		SetCollision(true,true,true);
		Instigator=nullptr;
		Level.addPickup(this);
		NetUpdateTime=(GetWorld()->GetTimeSeconds() - 1);
		if (! bActiveOnTrigger)
		{
			bHidden=false;
		}
	}
Begin:
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		Sleep(FMin(30,(Level.Game.GameDifficulty * 8)));
	}
	else
	{
		Sleep(30);
	}
	JL"Respawn"
;
}
*/

/*
State Disabled
{
	Function bool ReadyToPickup(float MaxWait)
	{
		return false;
	}
	Function Reset()
	{
	}
	Function StartSleeping()
	{
	}
	simulated Function BeginState()
	{
		MaxDesireability=0;
		bHidden=true;
		ResetStaticFilterState();
		SetCollision(false,false,false);
	}
}
*/


void APickup::BeginPlay()
{
	Super::BeginPlay();
}


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

void APickup::StaticPrecache(ALevelInfo* L)
{
}

void APickup::PostBeginPlay()
{
	/*
	bPlacedPickup = Level.bStartup;
	Level.addPickup(this);
	*/
}
void APickup::MatchStarting()
{
	if (bActiveOnTrigger)
	{
		//bHidden = true;
	}
	if (bPlacedPickup)
	{
		//GotoState('Pickup');
	}
}

void APickup::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bActiveOnTrigger)
	{
		//bHidden = false;
	}
}

void APickup::MatchEnding()
{
	if (!bPlacedPickup)
	{
		Destroy();
	}
}

void APickup::Destroyed()
{
	//Level.removePickup(this);
	if (myMarker != nullptr)
	{
		Cast<AInventorySpot>(myMarker)->markedItem = nullptr;
	}
	/*
	if (Inventory != nullptr)
	{
		Inventory.Destroy();
		Inventory = nullptr;
	}
	*/
}

FString APickup::GetHumanReadableName() const
{
	/*
	if (InventoryType == nullptr)
	{
		return GetItemName(Class);
	}
	if (InventoryType.Default.ItemName == "")
	{
		return GetItemName(InventoryType);
	}
	return InventoryType.Default.ItemName;
	*/
	return "FAKE";    //FAKE   /EliZ
}

bool APickup::IsSuperItem()
{
	return PickUpBase != nullptr && Cast<AxPickUpBase>(PickUpBase)->bDelayedSpawn;
}

/*
void APickup::UpdateHUD(AAA2_HUD* H)
{
	Cast<AHud>(H).LastPickupTime = H.GetWorld()->GetTimeSeconds();
}
*/

void APickup::Reset()
{
	/*
	if (Inventory != nullptr)
	{
		Destroy();
	}
	else
	{
		if (myMarker != nullptr && myMarker.bSuperPickup)
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

APickup* APickup::Transmogrify(APickup*  NewClass)
{
	APickup* NewPickup = nullptr;
	/*
	NewPickup = Spawn(NewClass);
	NewPickup.PickUpBase = PickUpBase;
	NewPickup.RespawnTime = RespawnTime;
	if (myMarker != nullptr)
	{
		myMarker.markedItem = NewPickup;
		NewPickup.myMarker = myMarker;
		myMarker = nullptr;
	}
	Destroy();
	*/
	return NewPickup;
}

float APickup::DetourWeight(APawn* Other, float PathWeight)
{
	return 0;
}

float APickup::BotDesireability(APawn* Bot)
{
	AInventory* AlreadyHas = nullptr;
	float desire = 0;
	desire = MaxDesireability;
	/*
	if (RespawnTime < 10)
	{
		AlreadyHas = Bot.FindInventoryType(InventoryType);
		if (AlreadyHas != nullptr)
		{
			if (Inventory != nullptr)
			{
				if (Inventory.Charge <= AlreadyHas.Charge)
				{
					return - 1;
				}
			}
			else
			{
				if (InventoryType.Default.Charge <= AlreadyHas.Charge)
				{
					return - 1;
				}
			}
		}
	}
	return desire;
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

AInventory* APickup::GetInventoryClassFor(APawn* Other)
{
	/*
	if (!UseEnemyClass(Other.PlayerReplicationInfo))
	{
		DebugLog(DEBUG_Inv, "Pickup::GetInventoryClassFor()	Pickup is a friend: " + InventoryType);
		return InventoryType;
	}
	else
	{
		DebugLog(DEBUG_Inv, "Pickup::GetInventoryClassFor()	Pickup is an enemy: " + EnemyPickupClass.Default.InventoryType);
		return EnemyPickupClass.Default.InventoryType;
	}
	*/
	return nullptr;     //FAKE   /ELiZ
}

AInventory* APickup::SpawnCopy(APawn* Other, bool bRealInventory)
{
	AInventory* Copy = nullptr;
	AInventory* SpawnType = nullptr;
	bool bVirtual = false;
	/*
	SpawnType = GetInventoryClassFor(Other);
	if (false)
	{
		Copy = Inventory;
		Inventory = nullptr;
	}
	else
	{
		Copy = Spawn(SpawnType, Other, , , FRotator(0 0 0));
		Copy.InitFor(Inventory);
		if (EventLab != nullptr)
		{
			Copy.SetEventLab(EventLab);
		}
		if (Inventory != nullptr)
		{
			Inventory.Destroy();
			Inventory = nullptr;
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
			Copy.GiveTo(Other, this);
			Copy.PickupFunction(Other);
		}
		Instigator = Other;
	}
	else
	{
		Instigator = nullptr;
		Inventory = Copy;
		Copy = nullptr;
	}
	*/
	return Copy;
}

bool APickup::ValidTouch(AActor* Other)
{
	return false;     //FAKE   /ELiZ
}

bool APickup::CanSpawnCopy(APawn* Other, bool bRealInventory)
{
	AInventory* Copy = nullptr;
	AInventory* SpawnType = nullptr;
	bool bVirtual = false;
	bool bCanSpawn = false;
	/*
	if (!ValidTouch(Other))
	{
		return false;
	}
	SpawnType = GetInventoryClassFor(Other);
	Copy = Spawn(SpawnType, Other, , , FRotator(0 0 0));
	bVirtual = Copy.bVirtualInventory && !bRealInventory;
	bCanSpawn = Other.CanPickupItem(Copy, bVirtual);
	Copy.Destroy();
	*/
	return bCanSpawn;
}
void APickup::SetupCopy(AInventory* Copy, APawn* Other)
{
}
void APickup::PickupTaken()
{
	/*
	if (Level.Game.ShouldRespawn(this))
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
	//GotoState('Sleeping');
}
void APickup::AnnouncePickup(APawn* Receiver)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 2, Receiver);
	}
	Receiver.HandlePickup(this);
	PlaySound(PickupSound, 1, 0.5, false, 40, , true, false);
	*/
}

void APickup::SetRespawn()
{
	/*
	if (Level.Game.ShouldRespawn(this))
	{
		StartSleeping();
	}
	else
	{
		Destroy();
	}
	*/
}

FString APickup::GetLocalString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2)
{
	return GetDefault<APickup>()->PickupMessage;
}

AInventory* APickup::TakeItem(AActor* Other)
{
	return nullptr;
}

void APickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	if (bFreeze)
	{
		//GotoState("Pickup");
	}
	else
	{
		//SetPhysics(2);
		MaybeAdjustCollisionSize();
		//GotoState("None");
	}
	//Inventory = Inv;
	bAlwaysRelevant = false;
	bOnlyReplicateHidden = false;
	if (Inv == nullptr || Inv->IsA(AWeapon::StaticClass()) && Cast<AWeapon>(Inv)->bGuerrillaWeapon == true)
	{
		idTeamOwner = 255;
	}
	else
	{
		idTeamOwner = Inv->idTeamOwner;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		MaybeSetStaticMesh();
	}
	//bUpdateSimulatedPosition = true;
	bDropped = true;
	//bIgnoreEncroachers = false;
}

void APickup::MaybeAdjustCollisionSize()
{
}

bool APickup::MaybeSetStaticMesh()
{
	if (UseEnemyClass(nullptr))
	{
		switch(DrawType)
		{
		case EDrawType::DT_StaticMesh:
				//SetStaticMesh(EnemyPickupClass.Default.StaticMesh);
				break;
		case EDrawType::DT_Mesh:
				//LinkMesh(EnemyPickupClass.Default.Mesh);
				break;
			default:
				break;
		}
		//Level.SetActorLevelSkin(this, false);
		return true;
	}
	//Level.SetActorLevelSkin(this, true);
	return false;
}

bool APickup::ReadyToPickup(float MaxWait)
{
	return false;
}

void APickup::Landed(FVector HitNormal)
{
	//GotoState('Pickup');
}
float APickup::GetRespawnTime()
{
	return RespawnTime;
}
