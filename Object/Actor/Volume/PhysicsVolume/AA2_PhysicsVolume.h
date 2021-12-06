// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "AA29/DamageType/aDamageType.h"
#include "AA2_PhysicsVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAA2_PhysicsVolume : public APhysicsVolume
{
	GENERATED_BODY()
public:
	AAA2_PhysicsVolume();

    //From PhysicsVolume
    UPROPERTY(EditAnywhere)                             float fPushPawnOffMag;						//var() float fPushPawnOffMag;
    UPROPERTY(EditAnywhere)                             bool bPushPawnOff;						    //var() bool bPushPawnOff;
    UPROPERTY(EditAnywhere, Category = "Parachute")     float fParaWindFactor;						//var(Parachute) float fParaWindFactor;
    UPROPERTY(EditAnywhere, Category = "Parachute")     float fParaGravFactor;						//var(Parachute) float fParaGravFactor;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")     float NV_DistanceFogEnd;					//var(VolumeFog) float NV_DistanceFogEnd;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")     float NV_DistanceFogStart;					//var(VolumeFog) float NV_DistanceFogStart;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")     FColor NV_DistanceFogColor;					//var(VolumeFog) Object.Color NV_DistanceFogColor;
    UPROPERTY()                                         APhysicsVolume* NextPhysicsVolume;          //var PhysicsVolume NextPhysicsVolume;
    UPROPERTY()                                         AInfo* PainTimer;					    	//var Info PainTimer;
    UPROPERTY(EditAnywhere, Category = "Karma")			float KBuoyancy;					    	//var(Karma) float KBuoyancy;
    UPROPERTY(EditAnywhere, Category = "Karma")			float KExtraAngularDamping;					//var(Karma) float KExtraAngularDamping;
    UPROPERTY(EditAnywhere, Category = "Karma")			float KExtraLinearDamping;					//var(Karma) float KExtraLinearDamping;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")		float DistanceFogEnd;						//var(VolumeFog) float DistanceFogEnd;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")		float DistanceFogStart;						//var(VolumeFog) float DistanceFogStart;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")		FColor DistanceFogColor;					//var(VolumeFog) Object.Color DistanceFogColor;
    UPROPERTY(EditAnywhere, Category = "VolumeFog")		bool bDistanceFog;				    		//var(VolumeFog) bool bDistanceFog;
    UPROPERTY(EditAnywhere)                             bool bSoundFromInstigator;					//var() bool bSoundFromInstigator;
    UPROPERTY(EditAnywhere)                             bool bForceSound;				    		//var() bool bForceSound;
    UPROPERTY(EditAnywhere)                             bool bDamagesVehicles;						//var() bool bDamagesVehicles;
    UPROPERTY(EditAnywhere)                             bool bNoDecals;				        		//var() bool bNoDecals;

    UPROPERTY(EditAnywhere)                             bool bNeutralZone;					    	//var() bool bNeutralZone;
    UPROPERTY(EditAnywhere)                             bool bBounceVelocity;						//var() bool bBounceVelocity;
    UPROPERTY(EditAnywhere)                             bool bMoveProjectiles;						//var() bool bMoveProjectiles;
    UPROPERTY(EditAnywhere)                             bool bNoInventory;				    		//var() bool bNoInventory;
    UPROPERTY(EditAnywhere)                             bool bDestructive;				    		//var() bool bDestructive;
    UPROPERTY(EditAnywhere)                             bool BACKUP_bPainCausing;					//var bool BACKUP_bPainCausing;
    UPROPERTY(EditAnywhere)                             bool bPainCausing;				    		//var() bool bPainCausing;
    UPROPERTY(EditAnywhere)                             FVector ViewFog;				    		//var() FVector ViewFog;
    UPROPERTY(EditAnywhere)                             FVector ViewFlash;				    		//var() FVector ViewFlash;

    UPROPERTY(EditAnywhere)                             AActor* PawnEntryActor;						//var() class<Actor> PawnEntryActor;
    UPROPERTY(EditAnywhere)                             AActor* ExitActor;					    	//var() class<Actor> ExitActor;
    UPROPERTY(EditAnywhere)                             AActor* EntryActor;					    	//var() class<Actor> EntryActor;
    //UPROPERTY(EditAnywhere)                           AI3DL2Listener* VolumeEffect;		    	//var() I3DL2Listener VolumeEffect;
    UPROPERTY(EditAnywhere)                             USoundBase* ExitSound;						//var() Sound ExitSound;
    UPROPERTY(EditAnywhere)                             USoundBase* EntrySound;						//var() Sound EntrySound;

    UPROPERTY(EditAnywhere)                             UaDamageType* DamageType;	        		//var() class<DamageType> DamageType;
    UPROPERTY(EditAnywhere)                             float DamagePerSec;		                	//var() float DamagePerSec;

    UPROPERTY(EditAnywhere)                             float GroundFriction;						//var() float GroundFriction;
    UPROPERTY()                                         FVector BACKUP_Gravity;						//var FVector BACKUP_Gravity;
    UPROPERTY(EditAnywhere)                             FVector Gravity;			    			//var() FVector Gravity;
    UPROPERTY()		                                	FVector ZoneVelocity;						//var() FVector ZoneVelocity;

};
