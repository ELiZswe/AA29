// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/ROEVolume/ROEVolume.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

AROEVolume::AROEVolume()
{
	DefaultDamage = 90;
	DamageMultiplier = 0.333;
	sTextToDisplay = "Cease Fire!";
	//bBlockZeroExtentTraces = true;
}

void AROEVolume::PostBeginPlay()
{
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		ConfigureLinkDamage();
	}
	*/
}

void AROEVolume::ConfigureLinkDamage()
{
	AAGP_Objective* AO = nullptr;
	/*
	if ((DamageTag != "None") && (DamageTag != "None"))
	{
		ForEach AllActors(AAGP_Objective::StaticClass(), AO)
		{
			if (AO.DamageTag == DamageTag)
			{
				if (DamageObjective == nullptr)
				{
					DamageObjective = AO;
				}
				else
				{
					DebugLog(DEBUG_Warn, "ROEVolume::PostBeginPlay()	Already have a DamageObjective! " + FString::FromInt(AO) @ FString::FromInt(DamageObjective));
				}
			}
		}
		if (DamageObjective == nullptr)
		{
			DebugLog(DEBUG_Warn, "ROEVolume::PostBeginPlay()	Could not find DamageObjective for DamageTag " + FString::FromInt(DamageTag));
		}
	}
	*/
}
/*
void AROEVolume::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	if (DamageEvent != "None")
	{
		TriggerEvent(DamageEvent, this, instigatedBy);
	}
	if (DamageObjective != nullptr)
	{
		if (Damage == 0)
		{
			Damage = DefaultDamage;
		}
		DamageObjective.NotifyLinkDamage(instigatedBy, int((DamageMultiplier * float(Damage))));
		if (((instigatedBy != nullptr) && (instigatedBy.Controller != nullptr)) && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(instigatedBy.Controller).NotifyAdminMessage(sTextToDisplay);
		}
	}
}
*/
