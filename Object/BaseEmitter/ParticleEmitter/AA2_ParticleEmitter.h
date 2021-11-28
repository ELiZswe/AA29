// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/Object/BaseEmitter/BaseEmitter.h"
#include "AA29/AA29.h"
#include "AA2_ParticleEmitter.generated.h"

UCLASS()
class AA29_API UAA2_ParticleEmitter : public UBaseEmitter
{
	GENERATED_BODY()
public:
	UAA2_ParticleEmitter();

	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleCollisionSound SpawningSound;					//var(Sound) Enum EParticleCollisionSound  SpawningSound, CollisionSound;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleCollisionSound CollisionSound;					//var(Sound) Enum EParticleCollisionSound  SpawningSound, CollisionSound;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleDrawStyle DrawStyle;							//var(Texture) Enum EParticleDrawStyle  DrawStyle;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleCoordinateSystem CoordinateSystem;				//var(General) Enum EParticleCoordinateSystem  CoordinateSystem;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleRotationSource UseRotationFrom;				//var(Rotation) Enum EParticleRotationSource  UseRotationFrom;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleVelocityDirection GetVelocityDirectionFrom;	//var(Velocity) Enum EParticleVelocityDirectio GetVelocityDirectionFrom;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleStartLocationShape StartLocationShape;			//var(Location) Enum EParticleStartLocationShape  StartLocationShape;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleEffectAxis EffectAxis;							//var(General) Enum EParticleEffectAxis  EffectAxis;
	UPROPERTY(EditAnywhere, Category = "Collision")			EParticleMeshSpawning MeshSpawning;						//var(MeshSpawning) Enum EParticleMeshSpawning  MeshSpawning;
	UPROPERTY(EditAnywhere, Category = "Collision")			ESkelLocationUpdate UseSkeletalLocationAs;				//var(SkeletalMesh) Enum ESkelLocationUpdate  UseSkeletalLocationAs;

	UPROPERTY(EditAnywhere, Category = "Collision")			bool UseCollision;										//var(Collision) bool UseCollision;
	UPROPERTY(EditAnywhere, Category = "Collision")			bool UseCollisionPlanes;								//var(Collision) bool UseCollisionPlanes;
	UPROPERTY(EditAnywhere, Category = "Collision")			bool UseMaxCollisions;									//var(Collision) bool UseMaxCollisions;
	UPROPERTY(EditAnywhere, Category = "Collision")			bool UseSpawnedVelocityScale;							//var(Collision) bool UseSpawnedVelocityScale;
	UPROPERTY(EditAnywhere, Category = "Color")				bool UseColorScale;										//var(Color) bool UseColorScale;
	UPROPERTY(EditAnywhere, Category = "Fading")			bool FadeOut;											//var(Fading) bool FadeOut;
	UPROPERTY(EditAnywhere, Category = "Fading")			bool FadeIn;											//var(Fading) bool FadeIn;
	UPROPERTY(EditAnywhere, Category = "Force")				bool UseActorForces;									//var(Force) bool UseActorForces;
	UPROPERTY(EditAnywhere, Category = "General")			bool ResetAfterChange;									//var(General) bool ResetAfterChange;
	UPROPERTY(EditAnywhere, Category = "Local")				bool RespawnDeadParticles;								//var(Local) bool RespawnDeadParticles;
	UPROPERTY(EditAnywhere, Category = "Local")				bool AutoDestroy;										//var(Local) bool AutoDestroy;
	UPROPERTY(EditAnywhere, Category = "Local")				bool AutoReset;											//var(Local) bool AutoReset;
	UPROPERTY(EditAnywhere, Category = "Local")				bool Disabled;											//var(Local) bool Disabled;
	UPROPERTY()												bool Backup_Disabled;									//var bool Backup_Disabled;
	UPROPERTY(EditAnywhere, Category = "Local")				bool DisableFogging;									//var(Local) bool DisableFogging;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		bool VelocityFromMesh;									//var(MeshSpawning) bool VelocityFromMesh;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		bool UniformMeshScale;									//var(MeshSpawning) bool UniformMeshScale;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		bool UniformVelocityScale;								//var(MeshSpawning) bool UniformVelocityScale;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		bool UseColorFromMesh;									//var(MeshSpawning) bool UseColorFromMesh;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		bool SpawnOnlyInDirectionOfNormal;						//var(MeshSpawning) bool SpawnOnlyInDirectionOfNormal;
	UPROPERTY(EditAnywhere, Category = "Rendering")			bool AlphaTest;											//var(Rendering) bool AlphaTest;
	UPROPERTY(EditAnywhere, Category = "Rendering")			bool AcceptsProjectors;									//var(Rendering) bool AcceptsProjectors;
	UPROPERTY(EditAnywhere, Category = "Rendering")			bool ZTest;												//var(Rendering) bool ZTest;
	UPROPERTY(EditAnywhere, Category = "Rendering")			bool ZWrite;											//var(Rendering) bool ZWrite;
	UPROPERTY(EditAnywhere, Category = "Revolution")		bool UseRevolution;										//var(Revolution) bool UseRevolution;
	UPROPERTY(EditAnywhere, Category = "Revolution")		bool UseRevolutionScale;								//var(Revolution) bool UseRevolutionScale;
	UPROPERTY(EditAnywhere, Category = "Rotation")			bool SpinParticles;										//var(Rotation) bool SpinParticles;
	UPROPERTY(EditAnywhere, Category = "Rotation")			bool DampRotation;										//var(Rotation) bool DampRotation;
	UPROPERTY(EditAnywhere, Category = "Size")				bool UseSizeScale;										//var(Size) bool UseSizeScale;
	UPROPERTY(EditAnywhere, Category = "Size")				bool UseAbsoluteTimeForSizeScale;						//var(Size) bool UseAbsoluteTimeForSizeScale;
	UPROPERTY(EditAnywhere, Category = "Size")				bool UseRegularSizeScale;								//var(Size) bool UseRegularSizeScale;
	UPROPERTY(EditAnywhere, Category = "Size")				bool UniformSize;										//var(Size) bool UniformSize;
	UPROPERTY(EditAnywhere, Category = "Size")				bool DetermineVelocityByLocationDifference;				//var(Size) bool DetermineVelocityByLocationDifference;
	UPROPERTY(EditAnywhere, Category = "Size")				bool ScaleSizeXByVelocity;								//var(Size) bool ScaleSizeXByVelocity;
	UPROPERTY(EditAnywhere, Category = "Size")				bool ScaleSizeYByVelocity;								//var(Size) bool ScaleSizeYByVelocity;
	UPROPERTY(EditAnywhere, Category = "Size")				bool ScaleSizeZByVelocity;								//var(Size) bool ScaleSizeZByVelocity;
	UPROPERTY(EditAnywhere, Category = "Spawning")			bool AutomaticInitialSpawning;							//var(Spawning) bool AutomaticInitialSpawning;
	UPROPERTY(EditAnywhere, Category = "Texture")			bool BlendBetweenSubdivisions;							//var(Texture) bool BlendBetweenSubdivisions;
	UPROPERTY(EditAnywhere, Category = "Texture")			bool UseSubdivisionScale;								//var(Texture) bool UseSubdivisionScale;
	UPROPERTY(EditAnywhere, Category = "Texture")			bool UseRandomSubdivision;								//var(Texture) bool UseRandomSubdivision;
	UPROPERTY(EditAnywhere, Category = "Trigger")			bool TriggerDisabled;									//var(Trigger) bool TriggerDisabled;
	UPROPERTY(EditAnywhere, Category = "Trigger")			bool ResetOnTrigger;									//var(Trigger) bool ResetOnTrigger;
	UPROPERTY(EditAnywhere, Category = "Velocity")			bool UseVelocityScale;									//var(Velocity) bool UseVelocityScale;
	UPROPERTY(EditAnywhere, Category = "Velocity")			bool AddVelocityFromOwner;								//var(Velocity) bool AddVelocityFromOwner;
	UPROPERTY(EditAnywhere, Category = "Performance")		float LowDetailFactor;									//var(Performance) float LowDetailFactor;
	UPROPERTY(EditAnywhere, Category = "Acceleration")		FVector Acceleration;									//var(Acceleration) Vector Acceleration;
	UPROPERTY(EditAnywhere, Category = "Collision")			FVector ExtentMultiplier;								//var(Collision) Vector ExtentMultiplier;
	UPROPERTY(EditAnywhere, Category = "Collision")			FRangeVector DampingFactorRange;						//var(Collision) RangeVector DampingFactorRange;
	UPROPERTY(EditAnywhere, Category = "Collision")			TArray<FPlane> CollisionPlanes;							//var(Collision) TArray<Plane> CollisionPlanes;
	UPROPERTY(EditAnywhere, Category = "Collision")			FRange MaxCollisions;									//var(Collision) Range MaxCollisions;
	UPROPERTY(EditAnywhere, Category = "Collision")			int32 SpawnFromOtherEmitter;							//var(Collision) int32 SpawnFromOtherEmitter;
	UPROPERTY(EditAnywhere, Category = "Collision")			int32 SpawnAmount;										//var(Collision) int32 SpawnAmount;
	UPROPERTY(EditAnywhere, Category = "Collision")			FRangeVector SpawnedVelocityScaleRange;					//var(Collision) RangeVector SpawnedVelocityScaleRange;
	UPROPERTY(EditAnywhere, Category = "Collision")			bool bOnlyBSPCollision;									//var(Collision) bool bOnlyBSPCollision;
	UPROPERTY(EditAnywhere, Category = "Color")				TArray<FParticleColorScale> ColorScale;					//var(Color) TArray<ParticleColorScale> ColorScale;
	UPROPERTY(EditAnywhere, Category = "Color")				float ColorScaleRepeats;								//var(Color) float ColorScaleRepeats;
	UPROPERTY(EditAnywhere, Category = "Color")				FRangeVector ColorMultiplierRange;						//var(Color) RangeVector ColorMultiplierRange;
	UPROPERTY(EditAnywhere, Category = "Color")				float Opacity;											//var(Color) float Opacity;
	UPROPERTY(EditAnywhere, Category = "Fading")			FPlane FadeOutFactor;									//var(Fading) Plane FadeOutFactor;
	UPROPERTY(EditAnywhere, Category = "Fading")			float FadeOutStartTime;									//var(Fading) float FadeOutStartTime;
	UPROPERTY(EditAnywhere, Category = "Fading")			FPlane FadeInFactor;									//var(Fading) Plane FadeInFactor;
	UPROPERTY(EditAnywhere, Category = "Fading")			float FadeInEndTime;									//var(Fading) float FadeInEndTime;
	UPROPERTY(EditAnywhere, Category = "General")			int32 MaxParticles;										//var(General) const int32 MaxParticles;
	UPROPERTY(EditAnywhere, Category = "Local")				FRange AutoResetTimeRange;								//var(Local) Range AutoResetTimeRange;
	UPROPERTY(EditAnywhere, Category = "Local")				FString Name;											//var(Local) FString Name;


	UPROPERTY(EditAnywhere, Category = "Local")				TEnumAsByte<EDetailMode>	DetailMode;				//var(Local) Object.EDetailMode DetailMode;
	
																													
	//UPROPERTY(EditAnywhere, Category = "Local")				EDetailMode DetailMode;									//var(Local) Object.EDetailMode DetailMode;
	
	UPROPERTY(EditAnywhere, Category = "Location")			FVector StartLocationOffset;							//var(Location) Vector StartLocationOffset;
	UPROPERTY(EditAnywhere, Category = "Location")			FRangeVector StartLocationRange;						//var(Location) RangeVector StartLocationRange;
	UPROPERTY(EditAnywhere, Category = "Location")			int32 AddLocationFromOtherEmitter;						//var(Location) int32 AddLocationFromOtherEmitter;
	UPROPERTY(EditAnywhere, Category = "Location")			FRange SphereRadiusRange;								//var(Location) Range SphereRadiusRange;
	UPROPERTY(EditAnywhere, Category = "Location")			FRangeVector StartLocationPolarRange;					//var(Location) RangeVector StartLocationPolarRange;
	UPROPERTY(EditAnywhere, Category = "Mass")				FRange StartMassRange;									//var(Mass) Range StartMassRange;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		UStaticMesh* MeshSpawningStaticMesh;					//var(MeshSpawning) StaticMesh MeshSpawningStaticMesh;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		FRangeVector VelocityScaleRange;						//var(MeshSpawning) RangeVector VelocityScaleRange;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		FRangeVector MeshScaleRange;							//var(MeshSpawning) RangeVector MeshScaleRange;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		FVector MeshNormal;										//var(MeshSpawning) Vector MeshNormal;
	UPROPERTY(EditAnywhere, Category = "MeshSpawning")		FRange MeshNormalThresholdRange;						//var(MeshSpawning) Range MeshNormalThresholdRange;
	UPROPERTY(EditAnywhere, Category = "Rendering")			int32 AlphaRef;											//var(Rendering) int32 AlphaRef;
	UPROPERTY(EditAnywhere, Category = "Revolution")		FRangeVector RevolutionCenterOffsetRange;				//var(Revolution) RangeVector RevolutionCenterOffsetRange;
	UPROPERTY(EditAnywhere, Category = "Revolution")		FRangeVector RevolutionsPerSecondRange;					//var(Revolution) RangeVector RevolutionsPerSecondRange;
	UPROPERTY(EditAnywhere, Category = "Revolution")		TArray<FParticleRevolutionScale> RevolutionScale;		//var(Revolution) TArray<ParticleRevolutionScale> RevolutionScale;
	UPROPERTY(EditAnywhere, Category = "Revolution")		float RevolutionScaleRepeats;							//var(Revolution) float RevolutionScaleRepeats;
	UPROPERTY(EditAnywhere, Category = "Rotation")			FRotator RotationOffset;								//var(Rotation) Rotator RotationOffset;
	UPROPERTY(EditAnywhere, Category = "Rotation")			FVector SpinCCWorCW;									//var(Rotation) Vector SpinCCWorCW;
	UPROPERTY(EditAnywhere, Category = "Rotation")			FRangeVector SpinsPerSecondRange;						//var(Rotation) RangeVector SpinsPerSecondRange;
	UPROPERTY(EditAnywhere, Category = "Rotation")			FRangeVector StartSpinRange;							//var(Rotation) RangeVector StartSpinRange;
	UPROPERTY(EditAnywhere, Category = "Rotation")			FRangeVector RotationDampingFactorRange;				//var(Rotation) RangeVector RotationDampingFactorRange;
	UPROPERTY(EditAnywhere, Category = "Rotation")			FVector RotationNormal;									//var(Rotation) Vector RotationNormal;
	UPROPERTY(EditAnywhere, Category = "Size")				TArray<FParticleTimeScale> SizeScale;					//var(Size) TArray<ParticleTimeScale> SizeScale;
	UPROPERTY(EditAnywhere, Category = "Size")				float SizeScaleRepeats;									//var(Size) float SizeScaleRepeats;
	UPROPERTY(EditAnywhere, Category = "Size")				FRangeVector StartSizeRange;							//var(Size) RangeVector StartSizeRange;
	UPROPERTY(EditAnywhere, Category = "Size")				FVector ScaleSizeByVelocityMultiplier;					//var(Size) Vector ScaleSizeByVelocityMultiplier;
	UPROPERTY(EditAnywhere, Category = "Size")				float ScaleSizeByVelocityMax;							//var (Size) float ScaleSizeByVelocityMax;
	UPROPERTY(EditAnywhere, Category = "Size")				bool bFitSizing;										//var(Size) bool bFitSizing;
	UPROPERTY(EditAnywhere, Category = "SkeletalMesh")		AActor* SkeletalMeshActor;								//var(SkeletalMesh) Actor SkeletalMeshActor;
	UPROPERTY(EditAnywhere, Category = "SkeletalMesh")		FVector SkeletalScale;									//var(SkeletalMesh) Vector SkeletalScale;
	UPROPERTY(EditAnywhere, Category = "SkeletalMesh")		FRange RelativeBoneIndexRange;							//var(SkeletalMesh) Range RelativeBoneIndexRange;
	UPROPERTY(EditAnywhere, Category = "Sound")				TArray<FParticleSound> Sounds;							//var(Sound) TArray<ParticleSound> Sounds;
	UPROPERTY(EditAnywhere, Category = "Sound")				FRange SpawningSoundIndex;								//var(Sound) Range SpawningSoundIndex;
	UPROPERTY(EditAnywhere, Category = "Sound")				FRange SpawningSoundProbability;						//var(Sound) Range SpawningSoundProbability;
	UPROPERTY(EditAnywhere, Category = "Sound")				FRange CollisionSoundIndex;								//var(Sound) Range CollisionSoundIndex;
	UPROPERTY(EditAnywhere, Category = "Sound")				FRange CollisionSoundProbability;						//var(Sound) Range CollisionSoundProbability;
	UPROPERTY(EditAnywhere, Category = "Spawning")			float ParticlesPerSecond;								//var(Spawning) float ParticlesPerSecond;
	UPROPERTY(EditAnywhere, Category = "Spawning")			float InitialParticlesPerSecond;						//var(Spawning) float InitialParticlesPerSecond;
	UPROPERTY(EditAnywhere, Category = "Texture")			UMaterialInstance* Texture;								//var(Texture) Texture Texture;
	UPROPERTY(EditAnywhere, Category = "Texture")			int32 TextureUSubdivisions;								//var(Texture) int32 TextureUSubdivisions;
	UPROPERTY(EditAnywhere, Category = "Texture")			int32 TextureVSubdivisions;								//var(Texture) int32 TextureVSubdivisions;
	UPROPERTY(EditAnywhere, Category = "Texture")			TArray<float> SubdivisionScale;							//var(Texture) TArray<float> SubdivisionScale;
	UPROPERTY(EditAnywhere, Category = "Texture")			int32 SubdivisionStart;									//var(Texture) int32 SubdivisionStart;
	UPROPERTY(EditAnywhere, Category = "Texture")			int32 SubdivisionEnd;									//var(Texture) int32 SubdivisionEnd;
	UPROPERTY(EditAnywhere, Category = "Tick")				float SecondsBeforeInactive;							//var(Tick) float SecondsBeforeInactive;
	UPROPERTY(EditAnywhere, Category = "Tick")				float MinSquaredVelocity;								//var(Tick) float MinSquaredVelocity;
	UPROPERTY(EditAnywhere, Category = "Time")				FRange InitialTimeRange;								//var(Time) Range InitialTimeRange;
	UPROPERTY(EditAnywhere, Category = "Time")				FRange LifetimeRange;									//var(Time) Range LifetimeRange;
	UPROPERTY(EditAnywhere, Category = "Time")				FRange InitialDelayRange;								//var(Time) Range InitialDelayRange;
	UPROPERTY(EditAnywhere, Category = "Trigger")			FRange SpawnOnTriggerRange;								//var(Trigger) Range SpawnOnTriggerRange;
	UPROPERTY(EditAnywhere, Category = "Trigger")			float SpawnOnTriggerPPS;								//var(Trigger) float SpawnOnTriggerPPS;
	UPROPERTY(EditAnywhere, Category = "Velocity")			FRangeVector StartVelocityRange;						//var(Velocity) RangeVector StartVelocityRange;
	UPROPERTY(EditAnywhere, Category = "Velocity")			FRange StartVelocityRadialRange;						//var(Velocity) Range StartVelocityRadialRange;
	UPROPERTY(EditAnywhere, Category = "Velocity")			FVector MaxAbsVelocity;									//var(Velocity) Vector MaxAbsVelocity;
	UPROPERTY(EditAnywhere, Category = "Velocity")			FRangeVector VelocityLossRange;							//var(Velocity) RangeVector VelocityLossRange;
	UPROPERTY(EditAnywhere, Category = "Velocity")			int32 RotateVelocityLossRange;							//var(Velocity) int32 RotateVelocityLossRange;
	UPROPERTY(EditAnywhere, Category = "Velocity")			int32 AddVelocityFromOtherEmitter;						//var(Velocity) int32 AddVelocityFromOtherEmitter;
	UPROPERTY(EditAnywhere, Category = "Velocity")			FRangeVector AddVelocityMultiplierRange;				//var(Velocity) RangeVector AddVelocityMultiplierRange;
	UPROPERTY(EditAnywhere, Category = "Velocity")			TArray<FParticleVelocityScale> VelocityScale;			//var(Velocity) TArray<ParticleVelocityScale> VelocityScale;
	UPROPERTY(EditAnywhere, Category = "Velocity")			float VelocityScaleRepeats;								//var(Velocity) float VelocityScaleRepeats;
	UPROPERTY(EditAnywhere, Category = "Warmup")			float WarmupTicksPerSecond;								//var(Warmup) float WarmupTicksPerSecond;
	UPROPERTY(EditAnywhere, Category = "Warmup")			float RelativeWarmupTime;								//var(Warmup) float RelativeWarmupTime;
	UPROPERTY()												AEmitter* Owner;										//var transient Emitter Owner;
	UPROPERTY()												bool Initialized;										//var transient bool Initialized;
	UPROPERTY()												bool Inactive;											//var transient bool Inactive;
	UPROPERTY()												bool RealDisableFogging;								//var transient bool RealDisableFogging;
	UPROPERTY()												bool AllParticlesDead;									//var transient bool AllParticlesDead;
	UPROPERTY()												bool WarmedUp;											//var transient bool WarmedUp;
	UPROPERTY()												float InactiveTime;										//var transient float InactiveTime;
	UPROPERTY()												TArray<FParticle> Particles;							//var transient TArray<Particle> Particles;
	UPROPERTY()												int32 ParticleIndex;									//var transient int32 ParticleIndex;
	UPROPERTY()												int32 ActiveParticles;									//var transient int32 ActiveParticles;
	UPROPERTY()												float PPSFraction;										//var transient float PPSFraction;
	UPROPERTY()												FBox BoundingBox;										//var transient Box BoundingBox;
	UPROPERTY()												FVector RealExtentMultiplier;							//var transient Vector RealExtentMultiplier;
	UPROPERTY()												int32 OtherIndex;										//var transient int32 OtherIndex;
	UPROPERTY()												float InitialDelay;										//var transient float InitialDelay;
	UPROPERTY()												FVector GlobalOffset;									//var transient Vector GlobalOffset;
	UPROPERTY()												float TimeTillReset;									//var transient float TimeTillReset;
	UPROPERTY()												int32 PS2Data;											//var transient int32 PS2Data;
	UPROPERTY()												int32 MaxActiveParticles;								//var transient int32 MaxActiveParticles;
	UPROPERTY()												int32 CurrentCollisionSoundIndex;						//var transient int32 CurrentCollisionSoundIndex;
	UPROPERTY()												int32 CurrentSpawningSoundIndex;						//var transient int32 CurrentSpawningSoundIndex;
	UPROPERTY()												int32 CurrentMeshSpawningIndex;							//var transient int32 CurrentMeshSpawningIndex;
	UPROPERTY()												float MaxSizeScale;										//var transient float MaxSizeScale;
	UPROPERTY()												int32 KillPending;										//var transient int32 KillPending;
	UPROPERTY()												int32 DeferredParticles;								//var transient int32 DeferredParticles;
	UPROPERTY()												FVector RealMeshNormal;									//var transient Vector RealMeshNormal;
	UPROPERTY()												TArray<FVector> MeshVertsAndNormals;					//var transient TArray<Vector> MeshVertsAndNormals;
	UPROPERTY()												int32 CurrentSpawnOnTrigger;							//var transient int32 CurrentSpawnOnTrigger;
	UPROPERTY()												int32 RenderableParticles;								//var transient int32 RenderableParticles;
	UPROPERTY()												FRangeVector RealVelocityLossRange;						//var transient RangeVector RealVelocityLossRange;
	UPROPERTY(EditAnywhere, Category = "AGP")				bool bPlayCollisionSoundFromOwner;						//var(AGP) bool bPlayCollisionSoundFromOwner;
	UPROPERTY(EditAnywhere, Category = "AGP")				float LandedMinSquaredVelocity;							//var(AGP) float LandedMinSquaredVelocity;
	UPROPERTY(EditAnywhere, Category = "AGP")				bool bRestOnLand;										//var(AGP) bool bRestOnLand;
	UPROPERTY(EditAnywhere, Category = "AGP")				FVector RestReset;										//var(AGP) Vector RestReset;
	UPROPERTY(EditAnywhere, Category = "AGP")				bool bRestReset_XYaw;									//var(AGP) bool bRestReset_XYaw;
	UPROPERTY(EditAnywhere, Category = "AGP")				bool bRestReset_YPitch;									//var(AGP) bool bRestReset_YPitch;
	UPROPERTY(EditAnywhere, Category = "AGP")				bool bRestReset_ZRoll;									//var(AGP) bool bRestReset_ZRoll;
	UPROPERTY(EditAnywhere, Category = "AGP")				bool bWeirdSpinOnCollide;								//var(AGP) bool bWeirdSpinOnCollide;
	UPROPERTY(EditAnywhere, Category = "AGP")				float WeirdBounce;										//var(AGP) float WeirdBounce;

	

	void SpawnParticle(int32 Amount);
	void Trigger();
	void Reset();

};
