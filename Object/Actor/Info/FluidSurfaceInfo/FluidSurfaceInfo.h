// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "FluidSurfaceInfo.generated.h"

UCLASS()
class AFluidSurfaceInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AFluidSurfaceInfo();

	UPROPERTY(EditAnywhere)				EFluidGridType						FluidGridType;				//var() Enum EFluidGridType FluidGridType;
	UPROPERTY(EditAnywhere)				float								FluidGridSpacing;			//var() float FluidGridSpacing;
	UPROPERTY(EditAnywhere)				int32								FluidXSize;					//var() int32 FluidXSize;
	UPROPERTY(EditAnywhere)				int32								FluidYSize;					//var() int32 FluidYSize;
	UPROPERTY(EditAnywhere)				float								FluidHeightScale;			//var() float FluidHeightScale;
	UPROPERTY(EditAnywhere)				float								FluidSpeed;					//var() float FluidSpeed;
	UPROPERTY(EditAnywhere)				float								FluidTimeScale;				//var() float FluidTimeScale;
	UPROPERTY(EditAnywhere)				float								FluidDamping;				//var() float FluidDamping;
	UPROPERTY(EditAnywhere)				float								FluidNoiseFrequency;		//var() float FluidNoiseFrequency;
	UPROPERTY(EditAnywhere)				FRange								FluidNoiseStrength;			//var() Range FluidNoiseStrength;
	UPROPERTY(EditAnywhere)				bool								TestRipple;					//var() bool TestRipple;
	UPROPERTY(EditAnywhere)				float								TestRippleSpeed;			//var() float TestRippleSpeed;
	UPROPERTY(EditAnywhere)				float								TestRippleStrength;			//var() float TestRippleStrength;
	UPROPERTY(EditAnywhere)				float								TestRippleRadius;			//var() float TestRippleRadius;
	UPROPERTY(EditAnywhere)				float								UTiles;						//var() float UTiles;
	UPROPERTY(EditAnywhere)				float								UOffset;					//var() float UOffset;
	UPROPERTY(EditAnywhere)				float								VTiles;						//var() float VTiles;
	UPROPERTY(EditAnywhere)				float								VOffset;					//var() float VOffset;
	UPROPERTY(EditAnywhere)				float								AlphaCurveScale;			//var() float AlphaCurveScale;
	UPROPERTY(EditAnywhere)				float								AlphaHeightScale;			//var() float AlphaHeightScale;
	UPROPERTY(EditAnywhere)				uint8								AlphaMax;					//var() uint8 AlphaMax;
	UPROPERTY(EditAnywhere)				float								ShootStrength;				//var() float ShootStrength;
	UPROPERTY(EditAnywhere)				float								ShootRadius;				//var() float ShootRadius;
	UPROPERTY(EditAnywhere)				float								RippleVelocityFactor;		//var() float RippleVelocityFactor;
	UPROPERTY(EditAnywhere)				float								TouchStrength;				//var() float TouchStrength;
	UPROPERTY(EditAnywhere)				AActor*								ShootEffect;				//var() class<Actor> ShootEffect;
	UPROPERTY(EditAnywhere)				bool								OrientShootEffect;			//var() bool OrientShootEffect;
	UPROPERTY(EditAnywhere)				AActor*								TouchEffect;				//var() class<Actor> TouchEffect;
	UPROPERTY(EditAnywhere)				bool								OrientTouchEffect;			//var() bool OrientTouchEffect;
	UPROPERTY(EditAnywhere)				TArray<int32>						ClampBitmap;				//var const TArray<int32> ClampBitmap;
	// UPROPERTY(EditAnywhere)				ATerrainInfo*					ClampTerrain;				//var() edfindable TerrainInfo ClampTerrain;
	UPROPERTY(EditAnywhere)				bool								bShowBoundingBox;			//var() bool bShowBoundingBox;
	UPROPERTY(EditAnywhere)				bool								bUseNoRenderZ;				//var() bool bUseNoRenderZ;
	UPROPERTY(EditAnywhere)				float								NoRenderZ;					//var() float NoRenderZ;
	UPROPERTY(EditAnywhere)				float								WarmUpTime;					//var() float WarmUpTime;
	UPROPERTY(EditAnywhere)				float								UpdateRate;					//var() float UpdateRate;
	UPROPERTY(EditAnywhere)				FColor								FluidColor;					//var() Color FluidColor;
	UPROPERTY()							TArray<float>						Verts0;						//var const transient TArray<float> Verts0;
	UPROPERTY()							TArray<float>						Verts1;						//var const transient TArray<float> Verts1;
	UPROPERTY()							TArray<uint8>						VertAlpha;					//var const transient TArray<uint8> VertAlpha;
	UPROPERTY()							int32								LatestVerts;				//var const transient int32 LatestVerts;
	UPROPERTY()							FBox								FluidBoundingBox;			//var const transient Box FluidBoundingBox;
	UPROPERTY()							FVector								FluidOrigin;				//var const transient Vector FluidOrigin;
	UPROPERTY()							float								TimeRollover;				//var const transient float TimeRollover;
	UPROPERTY()							float								TestRippleAng;				//var const transient float TestRippleAng;
	// UPROPERTY()						FFluidSurfacePrimitive				Primitive;					//var const transient FluidSurfacePrimitive Primitive;
	// UPROPERTY()							TArray<AFluidSurfaceOscillator*>	Oscillators;				//var const transient TArray<FluidSurfaceOscillator> Oscillators;
	UPROPERTY()							bool								bHasWarmedUp;				//var const transient bool bHasWarmedUp;

	void Pling(FVector Position, float Strength, float Radius);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);
	void Touch(AActor* Other);
};
