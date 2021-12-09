// All the original content belonged to the US Army


#include "Javelin_Tube.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Javelin/Ammo_Javelin.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Javelin.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Javelin_Tube/Pickup_Javelin_Tube.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_Javelin_Tube/AttachW_Javelin_Tube.h"

AJavelin_Tube::AJavelin_Tube()
{
	bSingleShot        = true;
	SelectChargeSound  = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Select_New.S_Armo_Javelin_Tube_Select_New"), NULL, LOAD_None, NULL);
	AmmoRoundClass     = AAmmoRound_Javelin::StaticClass();
	NumAmmoRounds      = 1;
	AmmoName           = AAmmo_Javelin::StaticClass();
	PickupAmmoCount    = 1;
	SelectSound        = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Select.S_Armo_Javelin_Tube_Select"), NULL, LOAD_None, NULL);
	DisplayFOV         = 50;
	WallTraceDist      = 45;
	weaponType         = EWeaponType::WEAPON_Javelin;
	PickupClass        = APickup_Javelin_Tube::StaticClass();
	fWeight            = 15.9;
	PlayerViewOffset   = FVector(0, 0, 0);
	AttachmentClass    = { AAttachW_Javelin_Tube::StaticClass() };
	IconMaterial       = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/tube_icon.tube_icon"), NULL, LOAD_None, NULL);
	ItemName           = "Javelin";
	Mesh               = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AAO_Armory/1stPrsnTube.1stPrsnTube"), NULL, LOAD_None, NULL);
}

void AJavelin_Tube::Fire(float Value)
{
}
void AJavelin_Tube::Reload()
{
}
void AJavelin_Tube::FixJam()
{
}
void AJavelin_Tube::ChangeFireMode()
{
}
void AJavelin_Tube::SpawnAndAttachMILESGear()
{
}
void AJavelin_Tube::AltFire(float Value)
{
}
void AJavelin_Tube::SpawnAndAttachAmmoRounds()
{
}
void AJavelin_Tube::SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial)
{
	//Return None;
}
/*
void AJavelin_Tube::StaticPrecache (LevelInfo L)
{
	L.AddPrecacheStaticMesh(StaticMesh'Tube_OnBack');
	L.AddPrecacheStaticMesh(StaticMesh'Tube3PIH');
	StaticPrecache(L);
}
*/
void AJavelin_Tube::CanLean()
{
	//Return False;
}
bool AJavelin_Tube::CanUseWeapon(int32 DesiredAction)
{
	switch(DesiredAction)
	{
		case 7:
		return true;
		default:
		return false;
	}
}
void AJavelin_Tube::GetSwapContainer()
{
	//Return AGP_Pawn(Instigator).getInvContainerAltShoulder();
}
void AJavelin_Tube::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
		local Inventory weap;
		GiveTo(Other,Pickup);
		weap=AGP_Pawn(Instigator).getHipInventory();
		if (weap == None)
		{
			weap=AGP_Pawn(Instigator).getHandsInventory();
		}
		if (weap.IsA('WEAPON_Javelin'))
		{
			AGP_Weapon(weap).AddClip(AmmoName);
			AGP_Weapon(weap).RecountAmmo();
		}
	*/
}
void AJavelin_Tube::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
		local Inventory weap;
		weap=AGP_Pawn(Instigator).getHipInventory();
		if (weap == None)
		{
			weap=AGP_Pawn(Instigator).getHandsInventory();
		}
		if (weap != None && weap.IsA('WEAPON_Javelin'))
		{
			AGP_Weapon(weap).SetClipCount(AGP_Weapon(weap).GetBestClip(),0);
			AGP_Weapon(weap).RecountAmmo();
		}
		Return DropFrom(StartLocation,bAttach);
	*/
}
bool AJavelin_Tube::CanSprint()
{
	return Super::CanSprint();
}
EUpperBodyAnim AJavelin_Tube::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_TUBE_Lower;
}
EUpperBodyAnim AJavelin_Tube::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_TUBE_Raise;
}
EUpperBodyAnim AJavelin_Tube::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_TUBE_Ready;
}
void AJavelin_Tube::RunAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	/*
		if (! HasAnim(Sequence))
		{
			Log("Javelin_Tube is missing 1st person anim:" @ Sequence,'PICA');
			Sequence='Idle';
		}
		RunAnimation(Sequence,Rate,TweenTime,bLoop);
	*/
}
void AJavelin_Tube::PlaySelect()
{
	/*
		local int initradius;
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
		}
		if (IsZoomed() && ShouldUse3dSights())
		{
			PlayIdleAnim();
		}
		else
		{
			if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew'))
			{
				if (_bActive)
				{
					if (HasAnim('Raise'))
					{
						RunAnimation('Raise',1);
					}
					else
					{
						if (Instigator != None && Instigator.bIsProne)
						{
							RunAnimation('proneselect',1);
						}
						else
						{
							RunAnimation('Select',1);
						}
					}
				}
				else
				{
					if (! _bCharged && HasAnim('SelectNew'))
					{
						if (Instigator != None && Instigator.bIsSprinting)
						{
							Instigator.StopSprint();
						}
						_bCharged=True;
						if (Instigator != None && Instigator.bIsProne)
						{
							RunAnimation('proneselect',1);
						}
						else
						{
							RunAnimation('SelectNew',1);
						}
						if (GetNetMode() == ENetMode::NM_Client)
						{
							initradius=1000000;
						}
						else
						{
							initradius=60;
						}
						PlayWeaponSound(SelectChargeSound,EnemyWeaponClass.Default.SelectChargeSound,,initradius);
					}
					else
					{
						if (Instigator != None && Instigator.bIsProne)
						{
							RunAnimation('proneselect',1);
						}
						else
						{
							RunAnimation('Select',1);
						}
						PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
					}
				}
			}
		}
	*/
}
void AJavelin_Tube::TweenDown()
{
	/*
		local name SeqName;
		local float AnimFrame;
		local float AnimRate;
		GetAnimParams(0,SeqName,AnimFrame,AnimRate);
		if (IsAnimating() && AnimIsInGroup(0,'Select') || AnimIsInGroup(0,'SelectNew'))
		{
			TweenAnim(SeqName,AnimFrame * 0.4);
		}
		else
		{
			if (_bActive)
			{
				if (HasAnim('Drop'))
				{
					RunAnimation('Drop',1);
				}
				else
				{
					if (Instigator != None && Instigator.bIsProne)
					{
						RunAnimation('pronedown',1);
					}
					else
					{
						RunAnimation('Down',1);
					}
				}
			}
			else
			{
				PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				if (SeqName == 'Drop' || SeqName == 'DropStill')
				{
					RunAnimation('LowDown',1);
				}
				else
				{
					if (Instigator != None && Instigator.bIsProne)
					{
						RunAnimation('pronedown',1);
					}
					else
					{
						RunAnimation('Down',1);
					}
				}
			}
		}
	*/
}
