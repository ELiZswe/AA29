// All the original content belonged to the US Army


#include "PickupT_DoorBreacher_Demo.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Demo_DoorBreacher/Demo_DoorBreacher.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_DoorBreacher_Demo/PickupT_PipeBomb_Demo/PickupT_PipeBomb_Demo.h"

APickupT_DoorBreacher_Demo::APickupT_DoorBreacher_Demo()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_door_breacher.wpn2_door_breacher"), NULL, LOAD_None, NULL);
	InventoryType		= ADemo_DoorBreacher::StaticClass();
	PickupMessage		= FString("You found a Door Breacher.");
	EnemyPickupClass	= APickupT_PipeBomb_Demo::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_door_breacher.wpn2_door_breacher"), NULL, LOAD_None, NULL));
		//Physics = 0
	RelativeRotation	= FRotator(0, -90, 0);
	CollisionRadius		= 3.5;
}


void APickupT_DoorBreacher_Demo::SetDoorBreacherEmitter(AEmitter* EM)
{
	/*
		DoorBreachedEmitter=EM;
	*/
}
void APickupT_DoorBreacher_Demo::DoBreacherEffects()
{
	/*
		local Emitter EM;
		if (DoorBreachedEmitter != None)
		{
			EM=Spawn(DoorBreachedEmitter,,,Location,Rotation);
			EM.InitEmitters(Location, Vector(Rotation));
		}
	*/
}
void APickupT_DoorBreacher_Demo::NotifyDoorBreacherExploded()
{
	/*
		if (Inventory != None && Demo_DoorBreacher(Inventory) != None)
		{
			Demo_DoorBreacher(Inventory).BlowUp();
		}
	*/
}
void APickupT_DoorBreacher_Demo::FindOtherDoorBreachers()
{
	/*
		local int i;
		if (Base != None)
		{
			for (i=0; i<Base.Attached.Length; i++)
			{
				if (Base.Attached[i] != Self && Base.Attached[i].IsA('PickupT_DoorBreacher_Demo'))
				{
					PickupT_DoorBreacher_Demo(Base.Attached[i]).NotifyDoorBreacherExploded();
				}
			}
		}
	*/
}
void APickupT_DoorBreacher_Demo::ProcessBlewUp()
{
	/*
		local class<AGP.ThrowWeapon>  W;
		W=class<Demo_DoorBreacher>(InventoryType);
		if (W != None)
		{
			if (GetNetMode() != ENetMode::NM_DedicatedServer)
			{
				if (W.Default.cExplosionEmitter != None)
				{
					Spawn(W.Default.cExplosionEmitter,,,Location,rot(16384 0 0));
				}
				if (W.Default.cExplosionDecal != None)
				{
					Spawn(W.Default.cExplosionDecal,,,Location,vect(0 0 -1));
				}
				SpawnSmokeEmitter(W);
				DoBreacherEffects();
				PlayOwnedSound(W.Default.BoomSound,3,1,True,1500,,True);
			}
			if (GetNetMode() != ENetMode::NM_Client)
			{
				FindOtherDoorBreachers();
				SpawnDamageArea(W);
			}
		}
		if (_EffectDuration > 0)
		{
			LifeSpan=_EffectDuration + 1;
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
			{
				LifeSpan /= 2;
			}
		}
		else
		{
			LifeSpan=1;
			bHidden=True;
		}
	*/
}
