// All the original content belonged to the US Army


#include "AGP_WeaponPickup.h"

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
void AAGP_WeaponPickup::StaticPrecache (LevelInfo L)
{
	if (Default.EnemyPickupClass != None)
	{
		L.AddPrecacheStaticMesh(Default.EnemyPickupClass.Default.StaticMesh);
	}
	if (Default.StaticMesh != None)
	{
		L.AddPrecacheStaticMesh(Default.StaticMesh);
	}
	if (Default.StaticMeshFull != None)
	{
		L.AddPrecacheStaticMesh(Default.StaticMeshFull);
	}
	if (Default.StaticMeshEmpty != None)
	{
		L.AddPrecacheStaticMesh(Default.StaticMeshEmpty);
	}
	if (Default.InventoryType != None)
	{
		if (Default.InventoryType.Default.IconMaterial != None)
		{
			L.AddPrecacheMaterial(Default.InventoryType.Default.IconMaterial);
		}
		if (Default.InventoryType.Default.AttachmentClass != None)
		{
			if (Default.InventoryType.Default.AttachmentClass.Default.FriendlyStaticMesh != None)
			{
				L.AddPrecacheStaticMesh(Default.InventoryType.Default.AttachmentClass.Default.FriendlyStaticMesh);
			}
			if (Default.InventoryType.Default.AttachmentClass.Default.EnemyStaticMesh != None)
			{
				L.AddPrecacheStaticMesh(Default.InventoryType.Default.AttachmentClass.Default.EnemyStaticMesh);
			}
		}
	}
}
*/
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
		if (W == None)
		{
			Log("AGP_WeaponPickup::PostBeginPlay(): ERROR: Couln't spawn " $ InventoryType);
			Return;
		}
		if (Attach_RailTop != None)
		{
			W.WM_Default[0]=Attach_RailTop;
		}
		if (Attach_RailFront != None)
		{
			W.WM_Default[1]=Attach_RailFront;
		}
		if (Attach_RailLeft != None)
		{
			W.WM_Default[2]=Attach_RailLeft;
		}
		if (Attach_RailRight != None)
		{
			W.WM_Default[3]=Attach_RailRight;
		}
		if (Attach_RailBottom != None)
		{
			W.WM_Default[4]=Attach_RailBottom;
		}
		if (Attach_Barrel != None)
		{
			W.WM_Default[5]=Attach_Barrel;
		}
		W.LoadDefaultMods();
		InitDroppedPickupFor(Inventory);
	*/
}
void AAGP_WeaponPickup::BotDesireability(APawn* Bot)
{
	/*
		local AGP_Pawn agpbot;
		local AGP_Weapon weapons;
		local Weapon.EWeaponType myType;
		local int i;
		local class<Inventory>  SpawnType;
		local float Modifier;
		SpawnType=GetInventoryClassFor(Bot);
		Modifier=0.5;
		agpbot=AGP_Pawn(Bot);
		if (agpbot == None)
		{
			DebugLog(DEBUG_Warn,"AGP_WeaponPickup::BotDesireability()	Could not find AGP_Pawn Bot");
			Return 0;
		}
		weapons[0]=AGP_Weapon(agpbot.Weapon);
		weapons[1]=AGP_Weapon(agpbot.getShoulderInventory());
		if (weapons[0] == None)
		{
			if (weapons[1] == None)
			{
				DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot has no weapon! Return max");
				Return MaxDesireability;
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
			if (weapons[i] == None)
			{
				DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot has an available slot");
				Modifier *= 1.2;
			}
			else
			{
				if (weapons[i].Class == SpawnType)
				{
					DebugLog(DEBUG_InvAI,"AGP_WeaponPickup::BotDesireability()	Bot already has this weapon");
					Return 0;
				}
				myType=class<Weapon>(SpawnType).Default.weaponType;
				if (myType == 1)
				{
					DebugLog(DEBUG_Warn,"AGP_WeaponPickup::BotDesireabilit()	Weapon class " $ InventoryType $ " is of unknown type");
					Return 0;
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
		Return Modifier * MaxDesireability;
	*/
}
void AAGP_WeaponPickup::MaybeSetStaticMesh()
{
	/*
		local class<BaseWeaponAttachment>  bclass;
		local FVector offset;
		local bool bUseEnemy;
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
		Return bUseEnemy;
	*/
}
void AAGP_WeaponPickup::AttachToMe(AActor* att, FVector offset)
{
	/*
		local FVector X;
		local FVector Y;
		local FVector Z;
		local Pawn p;
		p=Instigator;
		if (Instigator == None)
		{
			p=Pawn(Base);
		}
		if (p != None && AttachmentBone != 'None')
		{
			p.AttachToBone(att,AttachmentBone);
			att.SetRelativeLocation(offset);
			att.SetRelativeRotation(MakeRot(-16384,0,0));
		}
		else
		{
			att.SetBase(Self);
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
			bAlreadyAdjustedLanded=True;
			CollisionHeightDropped=8;
		}
		InitDroppedPickupFor(Inv,bFreeze);
		if (AGP_Weapon(Inv).WeaponModList != None)
		{
			AttachHandler=Spawn('AttachmentHandler');
			AttachHandler.SetupHandler(Self,Self,Inv);
		}
	*/
}
void SpawnMILESAttachments()
{
	/*
		local class<Actor>  aClass;
		if (MILESBox == None)
		{
			aClass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_MILESBox",Class'Class'));
			MILESBox=Spawn(aClass,Instigator);
		}
		if (BlankPlug == None)
		{
			aClass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_BlankPlug",Class'Class'));
			BlankPlug=Spawn(aClass,Instigator);
		}
	*/
}
void AAGP_WeaponPickup::Destroyed()
{
	
		Super::Destroyed();
		if (MILESBox != NULL)
		{
			//MILESBox.Destroy();
			MILESBox=NULL;
		}
		if (BlankPlug != NULL)
		{
			//BlankPlug.Destroy();
			BlankPlug=NULL;
		}
		//if (AttachHandler != NULL)
		//{
		//	AttachHandler.Destroy();
		//	BlankPlug=NULL;
		//}
	
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
	/*
		local Controller cIterator;
		cIterator=Level.ControllerList;
		if (cIterator != None)
		{
			if (cIterator.IsA('NPCBaseHelicopterController'))
			{
				if (cIterator.Pawn != None)
				{
					Log("Found Blackhawk to signal - owner: " $ Instigator $ " Owner controller: " $ AGP_Pawn(Instigator).Controller);
					NPCBaseHelicopterController(Vehicle(cIterator.Pawn).Controller).Land(Location,AGP_Pawn(Instigator).Controller);
					Return;
				}
			}
			cIterator=cIterator.nextController;
		}
	*/
}