// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "BTR80APC.generated.h"

class AVehicle;
UCLASS()
class ABTR80APC : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	ABTR80APC();

	UPROPERTY(EditAnywhere)					bool WeaponBoneHack;									//var() bool WeaponBoneHack;

	void PostBeginPlay();
	AVehicle* FindEntryVehicle(APawn* p);
	bool TryToDrive(APawn* p);
	void KDriverEnter(APawn* p);
	void IdleSoundTimer();
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, UaDamageType* InDamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
};
