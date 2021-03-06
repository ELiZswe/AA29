// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Anpeq5_Laser/WeaponMod_Anpeq5_Laser.h"
#include "AA29/Object/Actor/LaserProjector/LaserProjector.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"

AWeaponMod_Anpeq5_Laser::AWeaponMod_Anpeq5_Laser()
{
	WithLaserMesh  = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/anpeq5.anpeq5"), NULL, LOAD_None, NULL);
	NonLaserMesh   = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/anpeq5_off.anpeq5_off"), NULL, LOAD_None, NULL);
	//ValidSlot(2) = 1
	//ValidSlot(3) = 1
	DrawType       = EDrawType::DT_Mesh;
}

void AWeaponMod_Anpeq5_Laser::Destroyed()
{
	Super::Destroyed();
	if (laser != nullptr)
	{
		laser->Destroy();
		laser=nullptr;
	}
}
void AWeaponMod_Anpeq5_Laser::ModifyWeapon()
{
	Super::ModifyWeapon();
	//LinkMesh(NonLaserMesh);
	//Log("Creating LaserProjector instance");
	//Log("Meshes are: " + NonLaserMesh + "    and    " + Mesh);
	//laser=Spawn(ALaserProjector::StaticClass(),Self,"None",Location);
}
void AWeaponMod_Anpeq5_Laser::NotifyWeaponZoom(bool bNewZoom)
{
	/*
		Log("Got zoom notification " + bNewZoom);
		if (bNewZoom)
		{
			if (bLaserOn)
			{
				laser.TurnOff();
				laser.TurnOn(Level.GetClientPawn());
			}
		}
		else
		{
			if (bLaserOn)
			{
				laser.TurnOff();
				laser.TurnOn(this);
			}
		}
	*/
}

void AWeaponMod_Anpeq5_Laser::Toggle()
{
	//Log("Anpeq5_Laser::Toggle() called");
	bLaserOn=! bLaserOn;
	if (bLaserOn)
	{
		laser->TurnOn(this);
		//Log("Turning local laser on...");
	}
	else
	{
		laser->TurnOff();
		//Log("Turning local laser off...");
	}
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ServerSetLaser(bLaserOn);
	}
}

void AWeaponMod_Anpeq5_Laser::ServerSetLaser(bool new_setting)
{
	AWeaponAttachment* WA = nullptr; 
	bLaserOn=new_setting;
	WA= Cast<AWeaponAttachment>(weap->ThirdPersonActor);
	if (WA != nullptr)
	{
		WA->bLaserOn=bLaserOn;
		//Log("Server modifying its bLaserOn variable");
	}
}
