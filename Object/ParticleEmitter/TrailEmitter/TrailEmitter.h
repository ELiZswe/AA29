// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ParticleEmitter/AA2_ParticleEmitter.h"
#include "TrailEmitter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTrailEmitter : public UAA2_ParticleEmitter
{
	GENERATED_BODY()
public:
	UTrailEmitter();

	UPROPERTY(EditAnywhere, Category = "Tail")		ETrailLocation TrailLocation;							//var(Trail) Enum ETrailLocation TrailLocation;
	UPROPERTY(EditAnywhere, Category = "Tail")		ETrailShadeType TrailShadeType;							//var(Trail) Enum ETrailShadeType TrailShadeType;
	UPROPERTY(EditAnywhere, Category = "Tail")		int32 MaxPointsPerTrail;								//var(Trail) int32 MaxPointsPerTrail;
	UPROPERTY(EditAnywhere, Category = "Tail")		float DistanceThreshold;								//var(Trail) float DistanceThreshold;
	UPROPERTY(EditAnywhere, Category = "Tail")		bool UseCrossedSheets;									//var(Trail) bool UseCrossedSheets;
	UPROPERTY(EditAnywhere, Category = "Tail")		int32 MaxTrailTwistAngle;								//var(Trail) int32 MaxTrailTwistAngle;
	UPROPERTY(EditAnywhere, Category = "Tail")		float PointLifeTime;									//var(Trail) float PointLifeTime;
	UPROPERTY()										TArray<FParticleTrailData> TrailData;					//var transient TArray<ParticleTrailData> TrailData;
	UPROPERTY()										TArray<FParticleTrailInfo> TrailInfo;					//var transient TArray<ParticleTrailInfo> TrailInfo;
	//UPROPERTY()										VertexBuffer VertexBuffer;							//var transient VertexBuffer VertexBuffer;
	//UPROPERTY()										IndexBuffer IndexBuffer;							//var transient IndexBuffer IndexBuffer;
	UPROPERTY()										int32 VerticesPerParticle;								//var transient int32 VerticesPerParticle;
	UPROPERTY()										int32 IndicesPerParticle;								//var transient int32 IndicesPerParticle;
	UPROPERTY()										int32 PrimitivesPerParticle;							//var transient int32 PrimitivesPerParticle;

	void ResetTrail();
};
