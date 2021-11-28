// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SHelicopter/SHelicopter.h"
#include "blackhawk.generated.h"

class AHelicopterDustCloudEffect;
class ABaseSmokeEmitter;
class AAGP_DestroyedVehicleModels;

UCLASS()
class AA29_API Ablackhawk : public ASHelicopter
{
	GENERATED_BODY()
public:
	Ablackhawk();

	UPROPERTY()											USoundBase*							sndCruising;						//var Sound sndCruising;
	UPROPERTY()											USoundBase*							sndHover;							//var Sound sndHover;
	UPROPERTY()											TArray<AHelicopterDustCloudEffect*>	emitDust;							//var HelicopterDustCloudEffect emitDust[16];
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	FName								DamageEvent;						//var(LinkDamage) FName DamageEvent;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	FName								DamageTag;							//var(LinkDamage) FName DamageTag;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	FName								KillEvent;							//var(LinkDamage) FName KillEvent;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	int32								KillHealth;							//var(LinkDamage) int32 KillHealth;
	UPROPERTY()											AAGP_Objective*						DamageObjective;					//var AGP_Objective DamageObjective;
	UPROPERTY()											int32								InitialKillHealth;					//var int32 InitialKillHealth;
	UPROPERTY()											ABaseSmokeEmitter*					SmokeGenerator;						//var AGP_Effects.BaseSmokeEmitter SmokeGenerator;
	UPROPERTY()											bool								bSmokeGeneratorOn;					//var bool bSmokeGeneratorOn;
	UPROPERTY()											float								fpSmokeEndTime;						//var float fpSmokeEndTime;
	UPROPERTY()											float								fpOriginalMaxRotorSpeed;			//var float fpOriginalMaxRotorSpeed;
	UPROPERTY()											FName								SmokeGeneratorAttachmentBone;		//var FName SmokeGeneratorAttachmentBone;
	UPROPERTY(EditAnywhere)								AAGP_DestroyedVehicleModels*		DestroyedModelClass;				//var() class<AGP_DestroyedVehicleModels> DestroyedModelClass;
	UPROPERTY(EditAnywhere)								UStaticMesh*						DestroyedVehicleMesh;				//var() StaticMesh DestroyedVehicleMesh;

	void PostBeginPlay();
	void Destroyed();
	void Timer();
	bool UsedBy(APawn* User);
	void DustCloudTimer();
	bool TryToDrive(APawn* p);
	void KDriverEnter(APawn* p);
	bool KDriverLeave(bool bForceLeave);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  dtDamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
	void HelicopterEngineSmoke(bool bEnable);
	void HelicopterRotorSmoke(bool bEnable);
	void HelicopterCockpitSmoke(bool bEnable);
	void CheckSmokeGenerator();
	void SpawnSmokeGenerator(float fpSmokeLengthSeconds);
	void StartSmokeGenerator();
	void SpawnDestructionEffects();
	void Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone);
	void Landed(FVector HitNormal);
	void HelicopterForceRotorMaxToIdleSpeed();
	void HelicopterRestoreRotorMaxSpeed();
	void DestroyAppearance();

};
