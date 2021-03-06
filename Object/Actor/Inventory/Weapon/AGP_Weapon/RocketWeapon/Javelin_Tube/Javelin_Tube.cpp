// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Javelin/Ammo_Javelin.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Javelin.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Javelin_Tube/Pickup_Javelin_Tube.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_Javelin_Tube/AttachW_Javelin_Tube.h"
#include "AA29/Object/Actor/BaseAmmoRound/BaseAmmoRound.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"

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
	IconMaterial       = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/tube_icon_Mat.tube_icon_Mat'"), NULL, LOAD_None, NULL);
	ItemName           = "Javelin";
	Mesh               = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AAO_Armory/1stPrsnTube.1stPrsnTube"), NULL, LOAD_None, NULL);
}

/*
simulated State BusyRaisingWeapon
{
	simulated Function BeginState()
	{
		if (Instigator != nullptr)
		{
			Instigator.ResetLean();
		}
		Super::BeginState();
	}
}
*/

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

ABaseAmmoRound* AJavelin_Tube::SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial)
{
	return nullptr;
}

void AJavelin_Tube::StaticPrecache(ALevelInfo* L)
{
	//L.AddPrecacheStaticMesh(StaticMesh'Tube_OnBack');
	//L.AddPrecacheStaticMesh(StaticMesh'Tube3PIH');
	//StaticPrecache(L);
}

bool AJavelin_Tube::CanLean()
{
	return false;
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

AInvContainer* AJavelin_Tube::GetSwapContainer()
{
	//return Cast<AAGP_Pawn>(Instigator).getInvContainerAltShoulder();
	return nullptr;    //FAKE  /EliZ
}
void AJavelin_Tube::GiveTo(APawn* Other, APickup* Pickup)
{
	AInventory* weap = nullptr;
	/*
	GiveTo(Other,Pickup);
	weap=Cast<AAGP_Pawn>(Instigator).getHipInventory();
	if (weap == nullptr)
	{
		weap=Cast<AAGP_Pawn>(Instigator).getHandsInventory();
	}
	if (weap->IsA(AWEAPON_Javelin::StaticClass()))
	{
		Cast<AAGP_Weapon>(weap).AddClip(AmmoName);
		Cast<AAGP_Weapon>(weap).RecountAmmo();
	}
	*/
}

APickup* AJavelin_Tube::DropFrom(FVector StartLocation, bool bAttach)
{
	AInventory* weap = nullptr;
	/*
	weap=Cast<AAGP_Pawn>(Instigator).getHipInventory();
	if (weap == nullptr)
	{
		weap=Cast<AAGP_Pawn>(Instigator).getHandsInventory();
	}
	if (weap != nullptr && weap->IsA(AWEAPON_Javelin::StaticClass()))
	{
		Cast<AAGP_Weapon>(weap).SetClipCount(Cast<AAGP_Weapon>(weap).GetBestClip(),0);
		Cast<AAGP_Weapon>(weap).RecountAmmo();
	}
	return DropFrom(StartLocation,bAttach);
	*/
	return nullptr;   //FAKE   /ELiZ
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
		int32 initradius;
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
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
						if (Instigator != nullptr && Instigator.bIsProne)
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
						if (Instigator != nullptr && Instigator.bIsSprinting)
						{
							Instigator.StopSprint();
						}
						_bCharged=true;
						if (Instigator != nullptr && Instigator.bIsProne)
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
						if (Instigator != nullptr && Instigator.bIsProne)
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
	FName SeqName = "";
	float AnimFrame = 0;
	float AnimRate = 0;
	/*
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
				if (Instigator != nullptr && Instigator.bIsProne)
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
				if (Instigator != nullptr && Instigator.bIsProne)
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
