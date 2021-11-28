// All the original content belonged to the US Army


#include "PickupT_PDM_Munition.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_POM_2S/PickupT_POM_2S.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_PDM_Munition/Throw_PDM_Munition.h"

APickupT_PDM_Munition::APickupT_PDM_Munition()
{
	ArmedSound			= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Spoonpop.WeaponsUS_Grenades_Spoonpop"), NULL, LOAD_None, NULL);
	PopUpSound			= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Fire.WeaponsOPFOR_BS1_Fire"), NULL, LOAD_None, NULL);
	TriggerRadius		= 315;
	PopupVelocity		= 350;
	ArmedSoundRadius	= 400;
	PopupSoundRadius	= 400;
	PopTime				= 0.25;
	TriggerCheckRate	= 0.25;
	_fBounceDamp		= 0.3;
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pdm_3p_deployed.wpn2_pdm_3p_deployed"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_PDM_Munition::StaticClass();
	PickupMessage		= FString("You found a PDM Munition.");
	EnemyPickupClass	= APickupT_POM_2S::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pdm_3p_inhand.wpn2_pdm_3p_inhand"), NULL, LOAD_None, NULL));
}



void APickupT_PDM_Munition::PostBeginPlay()
{
	/*
	PostBeginPlay();
	SetTimer(TriggerCheckRate, true);
	*/
}
void APickupT_PDM_Munition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (bArmed && !bArmedEffectsProcessed)
	{
		bArmedEffectsProcessed = true;
		ClientArmedEffects();
	}
	else
	{
		if (bTriggered && !bTriggerProcessed)
		{
			ClientPopUp();
		}
	}
	*/
}
void APickupT_PDM_Munition::ClientPopUp()
{
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		Return;
	}
	SetPhysics(6);
	Velocity = SavedLandedVector * PopupVelocity;
	*/
}
void APickupT_PDM_Munition::ClientArmedEffects()
{
	/*
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		Return;
	}
	PlayOwnedSound(ArmedSound, 1, 1, False, ArmedSoundRadius, , True, false);
	*/
}
void APickupT_PDM_Munition::Landed(FVector HitNormal)
{
	/*
	Landed(HitNormal);
	SavedLandedVector = HitNormal;
	*/
}
void APickupT_PDM_Munition::ShouldTrigger(AActor* Other)
{
	/*
	local float speedsquared;
	local float speedpercentage;
	local float DistanceFactor;
	local float triggerchance;
	if (Other != Self)
	{
		DistanceFactor = VSize(Other.Location - Location) / TriggerRadius;
	}
	if (Other != Self && Other.IsA('Pickup') || Other.IsA('Projectile') && VSizeSquared(Other.Velocity) != 0)
	{
		if (FRand() > DistanceFactor)
		{
			Return True;
		}
	}
	else
	{
		if (Pawn(Other) != None && Pawn(Other).IsPlayerPawn() || Pawn(Other).WasPlayerPawn())
		{
			if (Pawn(Other).bIsProne)
			{
				Return True;
			}
			speedsquared = VSizeSquared(Pawn(Other).Velocity);
			speedpercentage = speedsquared / Square(Pawn(Other).fRunSpeed);
			if (DistanceFactor > 0.9)
			{
				triggerchance = 0.15;
			}
			else
			{
				if (DistanceFactor > 0.7)
				{
					triggerchance = 0.5;
				}
				else
				{
					if (DistanceFactor > 0.5)
					{
						triggerchance = 0.75;
					}
					else
					{
						if (DistanceFactor > 0.3)
						{
							triggerchance = 0.95;
						}
						else
						{
							if (DistanceFactor > 0.1)
							{
								triggerchance = 0.99;
							}
							else
							{
								triggerchance = 1;
							}
						}
					}
				}
			}
			if (FRand() < triggerchance)
			{
				if (FRand() < speedpercentage)
				{
					Return True;
				}
			}
		}
		else
		{
			Return False;
		}
	}
	*/
}
/*
void APickupT_PDM_Munition::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial)
{
	if (Inventory != None)
	{
		Throw_PDM_Munition(Inventory).BlowUp();
	}
}
*/
void APickupT_PDM_Munition::Timer()
{
	/*
	local Actor A;
	if (Inventory != None && !bTriggered && Throw_PDM_Munition(Inventory).bMunitionArmed)
	{
		ForEach VisibleCollidingActors(Class'Actor', A, TriggerRadius, Location)
		{
			if (ShouldTrigger(A))
			{
				bTriggered = true;
				PopUp();
				SetTimer(PopTime, false);
			}
		}
	}
	else
	{
		if (Inventory != None && bTriggered)
		{
			Throw_PDM_Munition(Inventory).BlowUp();
		}
	}
	*/
}
void APickupT_PDM_Munition::PopUp()
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		Return;
	}
	SetPhysics(6);
	PlayOwnedSound(PopUpSound, 1, 1, False, PopupSoundRadius, , True, false);
	Velocity = SavedLandedVector * PopupVelocity;
	*/
}