// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "AA29/Object/Actor/AttachmentHandler/AttachmentHandler.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

AAGP_WeaponPickup::AAGP_WeaponPickup()
{
	CollisionHeightDropped	= 2;
	bAttachMILESBox			= true;
	MaxDesireability		= 0.5;
	PickupMessage			= "You got a weapon";
	//bAlwaysTestCollision = true;
	//Physics = 2;
	LandedRotationOffset	= FRotator(0, 0, 90);
	Texture					= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/Engine/S_Weapon.S_Weapon"), NULL, LOAD_None, NULL);
	CollisionRadius			= 16;
	CollisionHeight			= 0.01;
}

/*
auto State Pickup
{
	Function Inventory TakeItem(AActor* Other)
	{
		if ((((AGP_Pawn(Other) != nullptr) && GetInventoryClassFor(AGP_Pawn(Other)).IsSniperRifle()) && (! AGP_Pawn(Other).PlayerReplicationInfo.bQualifiedSniper)) && (HumanController(AGP_Pawn(Other).Controller) != nullptr))
		{
			HumanController(AGP_Pawn(Other).Controller).SetPlayTips("Soldier, you are not qualified to employ","this weapon, your ability will be impaired.",5);
		}
		if ((((AGP_Pawn(Other) != nullptr) && GetInventoryClassFor(AGP_Pawn(Other)).IsJavelin()) && (! AGP_Pawn(Other).PlayerReplicationInfo.bQualifiedJavelin)) && (HumanController(AGP_Pawn(Other).Controller) != nullptr))
		{
			HumanController(AGP_Pawn(Other).Controller).SetPlayTips("Soldier, you are not qualified to employ","this weapon, your ability will be impaired.",5);
		}
		return Super::TakeItem(Other);
	}
}
*/

void AAGP_WeaponPickup::StaticPrecache(ALevelInfo* L)
{
	/*
	if (Default.EnemyPickupClass != nullptr)
	{
		L.AddPrecacheStaticMesh(Default.EnemyPickupClass.Default.StaticMesh);
	}
	if (Default.StaticMesh != nullptr)
	{
		L.AddPrecacheStaticMesh(Default.StaticMesh);
	}
	if (Default.StaticMeshFull != nullptr)
	{
		L.AddPrecacheStaticMesh(Default.StaticMeshFull);
	}
	if (Default.StaticMeshEmpty != nullptr)
	{
		L.AddPrecacheStaticMesh(Default.StaticMeshEmpty);
	}
	if (Default.InventoryType != nullptr)
	{
		if (Default.InventoryType.Default.IconMaterial != nullptr)
		{
			L->AddPrecacheMaterial(Default.InventoryType.Default.IconMaterial);
		}
		if (Default.InventoryType.Default.AttachmentClass != nullptr)
		{
			if (Default.InventoryType.Default.AttachmentClass.Default.FriendlyStaticMesh != nullptr)
			{
				L.AddPrecacheStaticMesh(Default.InventoryType.Default.AttachmentClass.Default.FriendlyStaticMesh);
			}
			if (Default.InventoryType.Default.AttachmentClass.Default.EnemyStaticMesh != nullptr)
			{
				L.AddPrecacheStaticMesh(Default.InventoryType.Default.AttachmentClass.Default.EnemyStaticMesh);
			}
		}
	}
	*/
}

void AAGP_WeaponPickup::PostBeginPlay()
{
	/*
	PostBeginPlay();
	if (GetNetMode() == ENetMode::NM_Standalone && Level.bStartup)
	{
		LoadStartupMods();
	}
	*/
}

void AAGP_WeaponPickup::LoadStartupMods()
{
	/*
		local AGP_Weapon W;
		W=AGP_Weapon(Spawn(InventoryType));
		Inventory=W;
		if (W == nullptr)
		{
			Log("AGP_WeaponPickup::PostBeginPlay(): ERROR: Couln't spawn " $ InventoryType);
			return;
		}
		if (Attach_RailTop != nullptr)
		{
			W.WM_Default[0]=Attach_RailTop;
		}
		if (Attach_RailFront != nullptr)
		{
			W.WM_Default[1]=Attach_RailFront;
		}
		if (Attach_RailLeft != nullptr)
		{
			W.WM_Default[2]=Attach_RailLeft;
		}
		if (Attach_RailRight != nullptr)
		{
			W.WM_Default[3]=Attach_RailRight;
		}
		if (Attach_RailBottom != nullptr)
		{
			W.WM_Default[4]=Attach_RailBottom;
		}
		if (Attach_Barrel != nullptr)
		{
			W.WM_Default[5]=Attach_Barrel;
		}
		W.LoadDefaultMods();
		InitDroppedPickupFor(Inventory);
	*/
}

float AAGP_WeaponPickup::BotDesireability(APawn* Bot)
{
	/*
	local AGP_Pawn agpbot;
	local AGP_Weapon weapons;
	local Weapon.EWeaponType myType;
	int32 i;
	local class<Inventory>  SpawnType;
	local float Modifier;
	SpawnType=GetInventoryClassFor(Bot);
	Modifier=0.5;
	agpbot=AGP_Pawn(Bot);
	if (agpbot == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_WeaponPickup::BotDesireability()	Could not find AGP_Pawn Bot");
		return 0;
	}
	weapons[0]=AGP_Weapon(agpbot.Weapon);
	weapons[1]=AGP_Weapon(agpbot.getShoulderInventory());
	if (weapons[0] == nullptr)
	{
		if (weapons[1] == nullptr)
		{
			DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot has no weapon! Return max");
			return MaxDesireability;
		}
		else
		{
			weapons[0]=weapons[1];
			weapons[1]=None;
		}
	}
	i=0;
	if (i < 2)
	{
		if (weapons[i] == nullptr)
		{
			DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot has an available slot");
			Modifier *= 1.2;
		}
		else
		{
			if (weapons[i].Class == SpawnType)
			{
				DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot already has this weapon");
				return 0;
			}
			myType=class<Weapon>(SpawnType).Default.weaponType;
			if (myType == 1)
			{
				DebugLog(DEBUG_Warn,"AGP_WeaponPickup::BotDesireabilit()	Weapon class " $ InventoryType $ " is of unknown type");
				return 0;
			}
			if (myType == weapons[i].weaponType)
			{
				DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot already has a similar weapon");
				Modifier *= 0.1;
			}
			i ++;
		}
	}
	Modifier=FClamp(Modifier,0,1);
	DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireabilit()	Returning " $ Modifier * MaxDesireability);
	return Modifier * MaxDesireability;
	*/
	return 0;     //FAKE   /ELiZ
}

bool AAGP_WeaponPickup::MaybeSetStaticMesh()
{
	FVector offset = FVector(0,0,0);
	bool bUseEnemy = false;
	/*
	local class<BaseWeaponAttachment>  bclass;
	bUseEnemy=MaybeSetStaticMesh();
	if (Level.GamePlayMode == 1 && ! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && bAttachMILESBox)
	{
		if (bUseEnemy)
		{
			bclass=class<BaseWeaponAttachment>(EnemyPickupClass.Default.InventoryType.Default.AttachmentClass);
		}
		else
		{
			bclass=class<BaseWeaponAttachment>(InventoryType.Default.AttachmentClass);
		}
		offset=bclass.Default._MuzzleOffset.VOffset;
		SpawnMILESAttachments();
		AttachToMe(MILESBox,offset);
		AttachToMe(BlankPlug,offset);
	}
	*/
	return bUseEnemy;
}
void AAGP_WeaponPickup::AttachToMe(AActor* att, FVector offset)
{
	/*
	local FVector X;
	local FVector Y;
	local FVector Z;
	local Pawn p;
	p=Instigator;
	if (Instigator == nullptr)
	{
		p=Pawn(Base);
	}
	if (p != nullptr && AttachmentBone != "None")
	{
		p.AttachToBone(att,AttachmentBone);
		att.SetRelativeLocation(offset);
		att.SetRelativeRotation(MakeRot(-16384,0,0));
	}
	else
	{
		att.SetBase(this);
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			GetAxes(Rotation * -1,X,Y,Z);
			att.SetRelativeLocation(- offset.Z * X + offset.Y * Y + offset.X * Z);
			att.SetRelativeRotation(Rotation * -1);
		}
		else
		{
			att.SetRelativeLocation(MakeVect(- offset.Z,offset.Y,offset.X));
		}
	}
	*/
}
void AAGP_WeaponPickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	/*
	if (Level.GamePlayMode == 1 && bAttachMILESBox)
	{
		bAlreadyAdjustedLanded=true;
		CollisionHeightDropped=8;
	}
	InitDroppedPickupFor(Inv,bFreeze);
	if (AGP_Weapon(Inv).WeaponModList != nullptr)
	{
		AttachHandler=Spawn('AttachmentHandler');
		AttachHandler.SetupHandler(Self,Self,Inv);
	}
	*/
}

void AAGP_WeaponPickup::SpawnMILESAttachments()
{
	/*
	local class<Actor>  aClass;
	if (MILESBox == nullptr)
	{
		aClass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_MILESBox",Class'Class'));
		MILESBox=Spawn(aClass,Instigator);
	}
	if (BlankPlug == nullptr)
	{
		aClass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_BlankPlug",Class'Class'));
		BlankPlug=Spawn(aClass,Instigator);
	}
	*/
}

void AAGP_WeaponPickup::Destroyed()
{
	Super::Destroyed();
	if (MILESBox != nullptr)
	{
		//MILESBox->Destroy();
		MILESBox= nullptr;
	}
	if (BlankPlug != nullptr)
	{
		//BlankPlug->Destroy();
		BlankPlug= nullptr;
	}
	if (AttachHandler != nullptr)
	{
		//AttachHandler->Destroy();
		BlankPlug= nullptr;
	}
}

void AAGP_WeaponPickup::MaybeAdjustCollisionSize()
{
	/*
	SetCollision(False,False,False);
	bBlockPlayers=False;
	SetCollisionSize(Default.CollisionRadius / 4,0.001);
	*/
}

void AAGP_WeaponPickup::SignalBlackhawkToLand()
{
	AController* cIterator = nullptr;
	/*
	for (cIterator = Level.ControllerList; cIterator != nullptr; cIterator = cIterator->nextController)
	{
		if (cIterator.IsA("NPCBaseHelicopterController"))
		{
			if (cIterator->Pawn != nullptr)
			{
				Log("Found Blackhawk to signal - owner: " $ string(Instigator) $ " Owner controller: " $ string(AGP_Pawn(Instigator).Controller));
				NPCBaseHelicopterController(Vehicle(cIterator.Pawn).Controller).Land(Location, AGP_Pawn(Instigator).Controller);
				return;
			}
		}
	}
	*/
}
