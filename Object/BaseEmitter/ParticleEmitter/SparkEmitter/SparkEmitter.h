// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/AA2_ParticleEmitter.h"
#include "SparkEmitter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USparkEmitter : public UAA2_ParticleEmitter
{
	GENERATED_BODY()
public:
	USparkEmitter();

	UPROPERTY(EditAnywhere, Category = "Sprite")		FRange LineSegmentsRange;						//var(Spark) Range LineSegmentsRange;
	UPROPERTY(EditAnywhere, Category = "Sprite")		FRange TimeBeforeVisibleRange;					//var(Spark) Range TimeBeforeVisibleRange;
	UPROPERTY(EditAnywhere, Category = "Sprite")		FRange TimeBetweenSegmentsRange;				//var(Spark) Range TimeBetweenSegmentsRange;
	UPROPERTY()											TArray<FParticleSparkData> SparkData;			//var transient TArray<ParticleSparkData> SparkData;
	//UPROPERTY()											VertexBuffer VertexBuffer;					//var transient VertexBuffer VertexBuffer;
	//UPROPERTY()											IndexBuffer IndexBuffer;					//var transient IndexBuffer IndexBuffer;
	UPROPERTY()											int32 NumSegments;								//var transient int32 NumSegments;
	UPROPERTY()											int32 VerticesPerParticle;						//var transient int32 VerticesPerParticle;
	UPROPERTY()											int32 IndicesPerParticle;						//var transient int32 IndicesPerParticle;
	UPROPERTY()											int32 PrimitivesPerParticle;					//var transient int32 PrimitivesPerParticle;

};
