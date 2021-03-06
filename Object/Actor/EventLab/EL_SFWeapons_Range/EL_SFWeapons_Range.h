// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_SFWeapons_Range.generated.h"

class AAGP_UseTrigger;
UCLASS()
class AEL_SFWeapons_Range : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_SFWeapons_Range();

	UPROPERTY()						AAGP_UseTrigger* Practice_USE_Trigger;							//var AGP.AGP_UseTrigger Practice_USE_Trigger;
	UPROPERTY()						ATriggerVolume* Practice_Leaving;								//var ATriggerVolume* Practice_Leaving;
	UPROPERTY()						ATriggerVolume* Practice_Downrange;								//var ATriggerVolume* Practice_Downrange;
	UPROPERTY()						FChallengeStation PracticeStation;								//var EL_SFWeapons_Range.ChallengeStation PracticeStation;
	UPROPERTY()						ATriggerVolume* Rocket_Leaving;									//var ATriggerVolume* Rocket_Leaving;
	UPROPERTY()						ATriggerVolume* Rocket_Downrange;								//var ATriggerVolume* Rocket_Downrange;
	UPROPERTY()						FChallengeStation RocketStation;								//var EL_SFWeapons_Range.ChallengeStation RocketStation;
	UPROPERTY()						ATriggerVolume* Grenade_Leaving;								//var ATriggerVolume* Grenade_Leaving;
	UPROPERTY()						ATriggerVolume* Grenade_Downrange;								//var ATriggerVolume* Grenade_Downrange;
	UPROPERTY()						FChallengeStation GrenadeStation;								//var EL_SFWeapons_Range.ChallengeStation GrenadeStation;
	UPROPERTY()						ATriggerVolume* Rifle_Leaving;									//var ATriggerVolume* Rifle_Leaving;
	UPROPERTY()						ATriggerVolume* Rifle_Downrange;								//var ATriggerVolume* Rifle_Downrange;
	UPROPERTY()						FChallengeStation RifleStation;									//var EL_SFWeapons_Range.ChallengeStation RifleStation;
	UPROPERTY()						bool LevelStarted;												//var bool LevelStarted;
	UPROPERTY()						FRotator PlayerRestartRotation;									//var Object.Rotator PlayerRestartRotation;
	UPROPERTY()						FVector PlayerRestartLocation;									//var FVector PlayerRestartLocation;
	UPROPERTY()						FWeaponsSergeant GrenadeCadre;									//var EL_SFWeapons_Range.WeaponsSergeant GrenadeCadre;
	UPROPERTY()						FWeaponsSergeant RocketCadre;									//var EL_SFWeapons_Range.WeaponsSergeant RocketCadre;
	UPROPERTY()						FWeaponsSergeant RifleCadre;									//var EL_SFWeapons_Range.WeaponsSergeant RifleCadre;
	UPROPERTY()						FWeaponsSergeant PracticeCadre;									//var EL_SFWeapons_Range.WeaponsSergeant PracticeCadre;

	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	void CaptureChallengeVolumes();
	void UnCaptureChallengeVolumes();
	bool IsPlayerArmed();
	bool DownrangeVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool LeavingVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool PracticeChallengeVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool Practice_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool PracticeVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool Rocket_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool Rifle_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool Grenade_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
};
