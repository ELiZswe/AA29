// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "M1117_ASV_Turret.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM1117_ASV_Turret : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	AM1117_ASV_Turret();

	UPROPERTY()							uint8						OldAltFlashCount;								//var byte OldAltFlashCount;
	UPROPERTY()							uint8						AltFlashCount;									//var byte AltFlashCount;
	UPROPERTY()							AEmitter*					AltFlashEmitter;								//var Emitter AltFlashEmitter;
	UPROPERTY()							AEmitter*					AltFlashEmitterClass;							//var class<Emitter> AltFlashEmitterClass;
	UPROPERTY()							FName						AltWeaponFireAttachmentBone;					//var name AltWeaponFireAttachmentBone;


	void InitEffects();
	void OwnerEffects();
	void FlashAltMuzzleFlash();
	void CalcAltWeaponFire();
	void AltMuzzleFlash();
	void CeaseFire(AController* C);
	void DestroyEffects();
	void PostNetReceive();

};
