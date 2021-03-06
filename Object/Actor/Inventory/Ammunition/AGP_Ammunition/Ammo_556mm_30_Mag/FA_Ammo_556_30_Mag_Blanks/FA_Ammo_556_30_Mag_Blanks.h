// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "FA_Ammo_556_30_Mag_Blanks.generated.h"

class AWeapon;

UCLASS()
class AFA_Ammo_556_30_Mag_Blanks : public AAmmo_556mm_30_Mag
{
	GENERATED_BODY()
public:
	AFA_Ammo_556_30_Mag_Blanks();

	void ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength);
};
