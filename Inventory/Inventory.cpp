// All the original content belonged to the US Army


#include "Inventory.h"
#include "AA29/DamageType/aDamageType.h"
#include "AA29/InventoryAttachment/InventoryAttachment.h"



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
	//bTravel = True
	DrawScale			= 1;
	
}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


/*
void AInventory::StaticPrecache(LevelInfo L)
{
}
*/


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
	/*
	local name BoneName;
	Instigator = p;
	if (IsA('ThrowWeapon') && Self != p.Weapon)
	{
		if (Role == 4)
		{
			DetachFromPawn(p);
		}
		Return;
	}
	if (ThirdPersonActor == None)
	{
		ThirdPersonActor = Spawn(AttachmentClass, Owner);
		InventoryAttachment(ThirdPersonActor).InitFor(Self);
	}
	else
	{
		ThirdPersonActor.NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	}
	BoneName = InventoryAttachment(ThirdPersonActor).GetAttachBoneFor(Self);
	if (BoneName == 'None')
	{
		ThirdPersonActor.SetLocation(p.Location);
		ThirdPersonActor.SetBase(p);
	}
	else
	{
		p.AttachToBone(ThirdPersonActor, BoneName);
	}
	if (ThirdPersonActor.IsA('InventoryAttachment') && GetNetMode() == ENetMode::NM_Standalone)
	{
		InventoryAttachment(ThirdPersonActor).NotifyBaseChange();
	}
	*/
}
void AInventory::updaterelative(int32 Pitch, int32 Yaw, int32 Roll)
{
	/*
	local Object.Rotator newRot;
	newRot.Pitch = Pitch;
	newRot.Yaw = Yaw;
	newRot.Roll = Roll;
	ThirdPersonActor.SetRelativeLocation(ThirdPersonActor.Default.RelativeLocation);
	ThirdPersonActor.SetRelativeRotation(newRot);
	*/
}
void AInventory::DetachFromPawn(APawn* p, bool bPreserveWeapon)
{
	/*
	if (ThirdPersonActor != None)
	{
		DetachFromBone(ThirdPersonActor);
		ThirdPersonActor.SetOwner(None);
		ThirdPersonActor.SetDrawType(0);
	}
	if (p.Weapon == Self && !bPreserveWeapon)
	{
		p.Weapon = None;
	}
	*/
}
void AInventory::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	if (Instigator == None || Instigator.Controller == None)
	{
		Return;
	}
	SetLocation(Instigator.Location + Instigator.CalcDrawOffset(Self));
	SetRotation(Instigator.GetViewRotation());
	Canvas.DrawActor(Self, false);
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
	if (bUseAttachment || Other.IsA('Weapon'))
	{
		AttachToPawn(Other);
	}
	*/
}
void AInventory::RecommendWeapon(float rating)
{
	//return NULL;
}
void AInventory::TravelPreAccept()
{
	/*
	TravelPreAccept();
	GiveTo(Pawn(Owner));
	*/
}
void AInventory::TravelPostAccept()
{
	/*
	TravelPostAccept();
	PickupFunction(Pawn(Owner));
	*/
}

void AInventory::Destroyed()
{
	/*
	if (Pawn(Owner) != None)
	{
		Pawn(Owner).DeleteInventory(Self);
	}
	if (ThirdPersonActor != None)
	{
		ThirdPersonActor.Destroy();
		ThirdPersonActor = None;
	}
	*/
}

void AInventory::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
	Instigator = Other;
	if (Other.AddInventory(Self))
	{
		SetTeamOwner();
		GotoState('None');
	}
	else
	{
		Destroy();
	}
	GotoState('None');
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
	if (Next == NULL)
	{
		return false;
	}
	return Cast<AInventory>(Next)->HandlePickupQuery(Item);
}
AInventory* AInventory::SelectNext()
{
	
	if (Inventory != NULL)
	{
		return Cast<AInventory>(Inventory)->SelectNext();
	}
	else
	{
		return NULL;
	}
	
}
void AInventory::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
	local Pickup p;
	local Object.Rotator R;
	local name AttachBone;
	if (PickupClass == None)
	{
		Log("Inventory.DropFrom() - Pickupclass FAILURE");
		Return None;
	}
	R = PickupClass.Default.Rotation;
	if (Instigator != None)
	{
		if (bAttach && ThirdPersonActor != None)
		{
			AttachBone = ThirdPersonActor.AttachmentBone;
		}
		R.Yaw += Instigator.Rotation.Yaw;
		DetachFromPawn(Instigator);
		Instigator.DeleteInventory(Self);
	}
	else
	{
		if (bAttach)
		{
			bAttach = False;
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
	if (p == None)
	{
		SetDrawType(0);
		Return None;
	}
	if (EventLab != None)
	{
		p.SetEventLab(EventLab);
		EventLab.ActorNotify(Self, 3, p);
	}
	if (bAttach)
	{
		p.Instigator = Instigator;
		p.SetLocation(Instigator.Location);
		if (AttachBone == 'None')
		{
			DebugLog(DEBUG_Warn, "Inventory::DropFrom()	Unable to find Bone to attach to! " $ Self @ p);
		}
		p.SetPhysics(0);
		Instigator.AttachToBone(p, AttachBone);
		p.SetRelativeRotation(MakeRot(-16384, 0, 0));
		if (Self.IsA('Weapon'))
		{
			p.SetDrawScale(1.13);
		}
	}
	else
	{
		p.Velocity = Velocity;
	}
	p.InitDroppedPickupFor(Self, bAttach);
	Velocity = vect(0 0 0);
	SetDefaultDisplayProperties();
	Inventory = None;
	Instigator = None;
	GotoState('None');
	Return p;
	*/
}
void AInventory::Use(float Value)
{
}
void AInventory::WeaponChange(uint8 F, bool bSilent)
{
	/*
	if (Inventory == None)
	{
		Return None;
	}
	else
	{
		Return Inventory.WeaponChange(F, bSilent);
	}
	*/
}
/*
void AInventory::PrevWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{
	if (Inventory == None)
	{
		Return CurrentChoice;
	}
	else
	{
		Return Inventory.PrevWeapon(CurrentChoice, CurrentWeapon);
	}
}
*/
/*
void AInventory::NextWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{

	if (Inventory == None)
	{
		Return CurrentChoice;
	}
	else
	{
		Return Inventory.NextWeapon(CurrentChoice, CurrentWeapon);
	}
}
*/
void AInventory::PrioritizeArmor(int32 Damage, UaDamageType* DamageType, FVector HitLocation)
{
	/*
	local Armor FirstArmor;
	if (Inventory != None)
	{
		FirstArmor = Inventory.PrioritizeArmor(Damage, DamageType, HitLocation);
	}
	else
	{
		FirstArmor = None;
	}
	Return FirstArmor;
	*/
}
void AInventory::OwnerEvent(FName EventName)
{
	/*
	if (Next != None)
	{
		Next.OwnerEvent(EventName);
	}
	*/
}
void AInventory::SetOwnerDisplay()
{
}
void AInventory::StaticItemName()
{
	/*
	Return Default.ItemName;
	*/
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
	return NULL;
}
void AInventory::InitFor(AInventory* Inv)
{
}
void AInventory::NotifyNewParachuteState(int32 NewState)
{
}
void AInventory::DisplayDebugMessage()
{
}
