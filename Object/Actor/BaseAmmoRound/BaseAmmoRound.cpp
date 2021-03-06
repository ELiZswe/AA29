// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseAmmoRound/BaseAmmoRound.h"

// Sets default values
ABaseAmmoRound::ABaseAmmoRound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ammo_id			= -1;
	//DrawType		= EDrawType::DT_StaticMesh;
	//bOnlyOwnerSee = true;
}


void ABaseAmmoRound::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABaseAmmoRound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseAmmoRound::Destroyed()
{
	Super::Destroyed();
	if (NextAmmoRound != nullptr)
	{
		NextAmmoRound->Destroy();
	}
}

void ABaseAmmoRound::AdjustAmmoRound(int32 total_ammo)
{
	if (total_ammo < ammo_id)
	{
		if (ExpendedSM != nullptr)
		{
			//SetStaticMesh(ExpendedSM);
			//SetDrawType(DT_StaticMesh);
		}
		else
		{
			//SetDrawType(DT_None);
		}
	}
	else
	{
		if (bHasBreechRound && (ammo_id == 1))
		{
			if (bRoundInBreech)
			{
				//SetStaticMesh(Default.StaticMesh);
				//SetDrawType(DT_StaticMesh);
				//SetRelativeLocation(FVector(0, 0.5, 0));
			}
			else
			{
				//SetDrawType(DT_None);
			}
		}
		else
		{
			//SetStaticMesh(Default.StaticMesh);
			//SetDrawType(DT_StaticMesh);
		}
	}
	if (NextAmmoRound != nullptr)
	{
		NextAmmoRound->AdjustAmmoRound(total_ammo);
	}
}

void ABaseAmmoRound::AdjustSpecialAmmoRounds(bool bRender)
{
	if (bRender)
	{
		//SetStaticMesh(Default.StaticMesh);
		//SetDrawType(DT_StaticMesh);
	}
	else
	{
		//SetDrawType(DT_None);
	}
	if (NextAmmoRound != nullptr)
	{
		NextAmmoRound->AdjustSpecialAmmoRounds(bRender);
	}
}

void ABaseAmmoRound::SetAmmoID(int32 new_id)
{
	ammo_id = new_id;
}

FName ABaseAmmoRound::GetBoneNameForAmmoAttach(bool bAux, bool bSpecial)
{
	if (bAux)
	{
		switch (ammo_id)
		{
		case 1:
			return "AuxAmmo01";
		default:
			break;
		}
		if (bSpecial)
		{
			switch (ammo_id)
			{
			case 1:
				return "XtraAmmo01";
			case 2:
				return "XtraAmmo02";
			case 3:
				return "XtraAmmo03";
			case 4:
				return "XtraAmmo04";
			case 5:
				return "XtraAmmo05";
			case 6:
				return "XtraAmmo06";
			case 7:
				return "XtraAmmo07";
			case 8:
				return "XtraAmmo08";
			case 9:
				return "XtraAmmo09";
			case 10:
				return "XtraAmmo10";
			case 11:
				return "XtraAmmo11";
			case 12:
				return "XtraAmmo12";
			case 13:
				return "XtraAmmo13";
			default:
				break;
			}
			if (bHasBreechRound)
			{
				switch (ammo_id)
				{
				case 1:
					return "Slide";
				case 2:
					return "Ammo01";
				case 3:
					return "Ammo02";
				case 4:
					return "Ammo03";
				case 5:
					return "Ammo04";
				case 6:
					return "Ammo05";
				case 7:
					return "Ammo06";
				case 8:
					return "Ammo07";
				case 9:
					return "Ammo08";
				case 10:
					return "Ammo09";
				case 11:
					return "Ammo10";
				case 12:
					return "Ammo11";
				case 13:
					return "Ammo12";
				case 14:
					return "Ammo13";
				default:
					break;
				}
				switch (ammo_id)
				{
				case 1:
					return "Ammo01";
				case 2:
					return "Ammo02";
				case 3:
					return "Ammo03";
				case 4:
					return "Ammo04";
				case 5:
					return "Ammo05";
				case 6:
					return "Ammo06";
				case 7:
					return "Ammo07";
				case 8:
					return "Ammo08";
				case 9:
					return "Ammo09";
				case 10:
					return "Ammo10";
				case 11:
					return "Ammo11";
				case 12:
					return "Ammo12";
				case 13:
					return "Ammo13";
				default:
					break;
				}
			}
		}
		//DebugLog(DEBUG_Warn, "BaseAmmoRound::GetBoneNameForAmmoAttach()	Unknown bone for id(" @ FString::FromInt(ammo_id) @ ") aux(" @ FString::FromInt(bAux) @ ")");
	}
	return "None"; 
}
