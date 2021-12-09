// All the original content belonged to the US Army


#include "WeaponMod_Anpeq5_Laser.h"

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
	/*
		Destroyed();
		if (laser != None)
		{
			laser.Destroy();
			laser=None;
		}
	*/
}
void AWeaponMod_Anpeq5_Laser::ModifyWeapon()
{
	/*
		ModifyWeapon();
		LinkMesh(NonLaserMesh);
		Log("Creating LaserProjector instance");
		Log("Meshes are: " $ NonLaserMesh $ "    and    " $ Mesh);
		laser=Spawn(Class'LaserProjector',Self,'None',Location);
	*/
}
void AWeaponMod_Anpeq5_Laser::NotifyWeaponZoom(bool bNewZoom)
{
	/*
		Log("Got zoom notification " $ bNewZoom);
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
				laser.TurnOn(Self);
			}
		}
	*/
}
void AWeaponMod_Anpeq5_Laser::Toggle()
{
	/*
		Log("Anpeq5_Laser::Toggle() called");
		bLaserOn=! bLaserOn;
		if (bLaserOn)
		{
			laser.TurnOn(Self);
			Log("Turning local laser on...");
		}
		else
		{
			laser.TurnOff();
			Log("Turning local laser off...");
		}
		if (GetNetMode() == ENetMode::NM_Client)
		{
			ServerSetLaser(bLaserOn);
		}
	*/
}
void AWeaponMod_Anpeq5_Laser::ServerSetLaser(bool new_setting)
{
	/*
		local WeaponAttachment WA;
		bLaserOn=new_setting;
		WA=WeaponAttachment(weap.ThirdPersonActor);
		if (WA != None)
		{
			WA.bLaserOn=bLaserOn;
			Log("Server modifying its bLaserOn variable");
		}
	*/
}
