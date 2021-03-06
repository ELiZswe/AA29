// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDrop.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"

ASideEffectWeaponDrop::ASideEffectWeaponDrop()
{
	EffectDuration         = 0.75;
	bServerEffect          = true;
	bReplaceExtantEffects  = false;
}

void ASideEffectWeaponDrop::ScaleByDamage(int32 Damage)
{
	EffectDuration = (EffectDuration + (float(Damage) / 100));
}

bool ASideEffectWeaponDrop::HasValidDropAnimation(AAGP_Weapon* AffectedWeapon)
{
	return (!AffectedWeapon->IsA(ARocketWeapon::StaticClass()));
}

void ASideEffectWeaponDrop::Start()
{
	AController* AffectedController = nullptr;
	AAGP_Pawn* AffectedPawn = nullptr;
	AAGP_Weapon* AffectedWeapon = nullptr;
	//Super::Start();
	AffectedController = Cast<AController>(GetOwner());
	if (AffectedController != nullptr)
	{
		AffectedPawn = Cast<AAGP_Pawn>(AffectedController->GetPawn());
		if ((AffectedPawn != nullptr) && (AffectedPawn->Weapon != nullptr))
		{
			AffectedWeapon = Cast<AAGP_Weapon>(AffectedPawn->Weapon);
			/*
			if (((((((((((((((HasValidDropAnimation(AffectedWeapon) && (AffectedWeapon != nullptr)) && (!AffectedWeapon->bInZoom)) && (!AffectedPawn->IsInState("BusyReloading"))) && AffectedWeapon->_bWeaponAlreadyRaised) && (!AffectedWeapon->IsInState("BusyTempRaising"))) && (!AffectedWeapon->IsInState("BusyRaisingWeapon"))) && (!AffectedWeapon->IsInState("BusyLoweringWeapon"))) && (!AffectedWeapon->IsInState("BusyTempDown"))) && (!AffectedPawn->bIsSprinting)) && (!AffectedWeapon->IsInState("BusyChangingFireMode"))) && (!AffectedWeapon->IsInState("BusyZooming"))) && (!AffectedWeapon->IsInState("BusyFixingJam"))) && (!AffectedWeapon->IsInState("BusySupporting"))) && (!AffectedWeapon->IsInState("BusySuppressor"))) && (!AffectedPawn->IsSupported()))
			{
				AffectedWeapon->_bWeaponAlreadyRaised = false;
				AffectedWeapon->TempLowerWeapon();
			}
			else
			{
				Destroy();
				//GotoState("None");
			}
			*/
		}
	}
}

void ASideEffectWeaponDrop::update(float DeltaTime)
{
	//Super::update(DeltaTime);
}

void ASideEffectWeaponDrop::End()
{
	AController* AffectedController = nullptr;
	AAGP_Pawn* AffectedPawn = nullptr;
	AAGP_Weapon* AffectedWeapon = nullptr;
	AffectedController = Cast<AController>(GetOwner());
	if (AffectedController != nullptr)
	{
		AffectedPawn = Cast<AAGP_Pawn>(AffectedController->GetPawn());
		if ((AffectedPawn != nullptr) && (AffectedPawn->Weapon != nullptr))
		{
			AffectedWeapon = Cast<AAGP_Weapon>(AffectedPawn->Weapon);
			/*
			if (((((AffectedWeapon != nullptr) && (!AffectedWeapon->_bWeaponAlreadyRaised)) && (!AffectedPawn->bIsSprinting)) && (AffectedPawn->Physics != 11)) && (!AffectedPawn->IsInState("BusyProning")))
			{
				AffectedWeapon.TempRaiseWeapon();
			}
			*/
		}
	}
	//Super::End();
}
