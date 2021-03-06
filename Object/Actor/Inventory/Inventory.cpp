// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/Object/Actor/Inventory/Powerups/Armor/Armor.h"
#include "AA29/Object/Actor/Inventory/Powerups/Powerups.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

// Sets default values
AInventory::AInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_bLarge				= true;
	idTeamOwner			= 255;
	bDrawOnHUD			= true;
	BobDamping			= 0.96f;
	//bHidden = true;
	//bReplicateMovement = false;
	//bClientAnim = true;
	//bOnlyOwnerSee = true;
	AttachmentClass		= { AInventoryAttachment::StaticClass() };
	DrawType			= EDrawType::DT_None;
	//RemoteRole = 2;
	//NetPriority = 1.4
	//bTravel = true
	DrawScale			= 1;
	
}


void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}


void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInventory::StaticPrecache(ALevelInfo* L)
{
}

bool AInventory::IsSniperRifle()
{
	return false;
}
bool AInventory::IsJavelin()
{
	return false;
}
void AInventory::AttachToPawn(APawn* p)
{
	FName BoneName = "";
	/*
	Instigator = p;
	if (IsA('ThrowWeapon') && this != p.Weapon)
	{
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			DetachFromPawn(p);
		}
		return;
	}
	if (ThirdPersonActor == nullptr)
	{
		ThirdPersonActor = Spawn(AttachmentClass, Owner);
		InventoryAttachment(ThirdPersonActor).InitFor(this);
	}
	else
	{
		ThirdPersonActor.NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	}
	BoneName = InventoryAttachment(ThirdPersonActor).GetAttachBoneFor(this);
	if (BoneName == "None")
	{
		ThirdPersonActor.SetLocation(p.Location);
		ThirdPersonActor.SetBase(p);
	}
	else
	{
		p.AttachToBone(ThirdPersonActor, BoneName);
	}
	if (ThirdPersonActor->IsA(AInventoryAttachment::StaticClass()) && GetNetMode() == ENetMode::NM_Standalone)
	{
		InventoryAttachment(ThirdPersonActor).NotifyBaseChange();
	}
	*/
}

void AInventory::updaterelative(int32 Pitch, int32 Yaw, int32 Roll)
{
	FRotator newRot = FRotator(0,0,0);
	newRot.Pitch = Pitch;
	newRot.Yaw = Yaw;
	newRot.Roll = Roll;
	//ThirdPersonActor.SetRelativeLocation(ThirdPersonActor.Default.RelativeLocation);
	//ThirdPersonActor.SetRelativeRotation(newRot);
}

void AInventory::DetachFromPawn(APawn* p, bool bPreserveWeapon)
{
	/*
	if (ThirdPersonActor != nullptr)
	{
		DetachFromBone(ThirdPersonActor);
		ThirdPersonActor.SetOwner(nullptr);
		ThirdPersonActor.SetDrawType(0);
	}
	if (p.Weapon == this && !bPreserveWeapon)
	{
		p.Weapon = nullptr;
	}
	*/
}

void AInventory::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		return;
	}
	SetActorLocation(Instigator.Location + Instigator.CalcDrawOffset(this));
	SetActorRotation(Instigator.GetViewRotation());
	Canvas.DrawActor(this, false);
	*/
}

FString AInventory::GetHumanReadableName() const
{
	/*
	if (ItemName == "")
	{
		ItemName = GetItemName(Class);
	}
	*/
	return ItemName;
}

void AInventory::PickupFunction(APawn* Other)
{
	/*
	if (bUseAttachment || Other->IsA(AWeapon::StaticClass()))
	{
		AttachToPawn(Other);
	}
	*/
}

AWeapon* AInventory::RecommendWeapon(float& rating)
{
	return nullptr;
}

void AInventory::TravelPreAccept()
{
	/*
	TravelPreAccept();
	GiveTo(Cast<APawn>(GetOwner()));
	*/
}

void AInventory::TravelPostAccept()
{
	/*
	TravelPostAccept();
	PickupFunction(Cast<APawn>(GetOwner()));
	*/
}

void AInventory::Destroyed()
{
	/*
	if (Cast<APawn>(GetOwner()) != nullptr)
	{
		Cast<APawn>(GetOwner())->DeleteInventory(this);
	}
	if (ThirdPersonActor != nullptr)
	{
		ThirdPersonActor.Destroy();
		ThirdPersonActor = nullptr;
	}
	*/
}

void AInventory::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
	Instigator = Other;
	if (Other.AddInventory(this))
	{
		SetTeamOwner();
		GotoState("None");
	}
	else
	{
		Destroy();
	}
	GotoState("None");
	*/
}
void AInventory::SetTeamOwner()
{
	/*
	if (idTeamOwner == 255)
	{
		idTeamOwner = Level.Game.GetPlayerTeamIndex(Instigator.Controller);
	}
	*/
}
bool AInventory::HandlePickupQuery(APickup* Item)
{
	if (Next == nullptr)
	{
		return false;
	}
	return Cast<AInventory>(Next)->HandlePickupQuery(Item);
}

APowerups* AInventory::SelectNext()
{
	
	if (Inventory != nullptr)
	{
		return Cast<AInventory>(Inventory)->SelectNext();
	}
	else
	{
		return nullptr;
	}
	
}

APickup* AInventory::DropFrom(FVector StartLocation, bool bAttach)
{
	APickup* p = nullptr;
	FRotator R = FRotator(0, 0, 0);
	FName AttachBone = "";
	if (PickupClass == nullptr)
	{
		//Log("Inventory.DropFrom() - Pickupclass FAILURE");
		return nullptr;
	}
	/*
	R = PickupClass.Default.Rotation;
	if (Instigator != nullptr)
	{
		if (bAttach && (ThirdPersonActor != nullptr))
		{
			AttachBone = ThirdPersonActor.AttachmentBone;
		}
		(R.Yaw += Instigator.Rotation.Yaw);
		DetachFromPawn(Instigator);
		Instigator.DeleteInventory(this);
	}
	else
	{
		if (bAttach)
		{
			bAttach = false;
		}
	}
	if (bAttach)
	{
		p = Spawn(PickupClass);
	}
	else
	{
		p = Spawn(PickupClass, , , StartLocation, R);
	}
	if (p == nullptr)
	{
		SetDrawType(DT_None);
		return nullptr;
	}
	if (EventLab != nullptr)
	{
		p.SetEventLab(EventLab);
		EventLab.ActorNotify(this, ET_Trigger, p);
	}
	if (bAttach)
	{
		p.Instigator = Instigator;
		p.SetLocation(Instigator.Location);
		if (AttachBone == "None")
		{
			DebugLog(DEBUG_Warn, "Inventory::DropFrom()	Unable to find Bone to attach to! " + FString::FromInt(this) @ FString::FromInt(p));
		}
		p.SetPhysics(PHYS_None);
		Instigator.AttachToBone(p, AttachBone);
		p.SetRelativeRotation(FRotator(-16384, 0, 0));
		if (Self->IsA(AWeapon::StaticClass()))
		{
			p.SetDrawScale(1.13);
		}
	}
	else
	{
		p.Velocity = Velocity;
	}
	p.InitDroppedPickupFor(this, bAttach);
	Velocity = FVector(0, 0, 0);
	SetDefaultDisplayProperties();
	Inventory = nullptr;
	Instigator = nullptr;
	GotoState("None");
	*/
	return p;
}

void AInventory::Use(float Value)
{
}

AWeapon* AInventory::WeaponChange(uint8 F, bool bSilent)
{
	if (Inventory == nullptr)
	{
		return nullptr;
	}
	else
	{
		return Cast<AWeapon>(Inventory)->WeaponChange(F, bSilent);
	}
}

AWeapon* AInventory::PrevWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{
	if (Inventory == nullptr)
	{
		return CurrentChoice;
	}
	else
	{
		return Cast<AWeapon>(Inventory)->PrevWeapon(CurrentChoice, CurrentWeapon);
	}
}

AWeapon* AInventory::NextWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{

	if (Inventory == nullptr)
	{
		return CurrentChoice;
	}
	else
	{
		return Cast<AWeapon>(Inventory)->NextWeapon(CurrentChoice, CurrentWeapon);
	}
}

AArmor* AInventory::PrioritizeArmor(int32 Damage, UaDamageType* DamageType, FVector HitLocation)
{
	AArmor* FirstArmor = nullptr;
	if (Inventory != nullptr)
	{
		FirstArmor = Cast<AArmor>(Inventory)->PrioritizeArmor(Damage, DamageType, HitLocation);
	}
	else
	{
		FirstArmor = nullptr;
	}
	return FirstArmor;
}

void AInventory::OwnerEvent(FName EventName)
{
	if (Next != nullptr)
	{
		//Next->OwnerEvent(EventName);
	}
}
void AInventory::SetOwnerDisplay()
{
}

FString AInventory::StaticItemName()
{
	return GetDefault<AInventory>()->ItemName;
}

bool AInventory::isLarge()
{
	return _bLarge;
}

bool AInventory::isHandsOnly()
{
	return _bHandsOnly;
}

bool AInventory::VirtualWeapon()
{
	return bVirtualInventory;
}

AInvContainer* AInventory::GetSwapContainer()
{
	return nullptr;
}
void AInventory::InitFor(AInventory* Inv)
{
}

void AInventory::NotifyNewParachuteState(int32 NewState)
{
}

FString AInventory::DisplayDebugMessage()
{
	return "FAKE";     //FAKE   /ELiZ
}
