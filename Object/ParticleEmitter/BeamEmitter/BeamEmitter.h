// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ParticleEmitter/AA2_ParticleEmitter.h"
#include "AA29/AA29.h"
#include "BeamEmitter.generated.h"

UCLASS()
class AA29_API UBeamEmitter : public UAA2_ParticleEmitter
{
	GENERATED_BODY()
public:
	UBeamEmitter();

	UPROPERTY(EditAnywhere, Category = "Mesh")					EBeamEndPointType DetermineEndPointBy;			//var(Beam) Enum EBeamEndPointType  DetermineEndPointBy;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRange BeamDistanceRange;						//var(Beam) Range BeamDistanceRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					TArray<FParticleBeamEndPoint> BeamEndPoints;	//var(Beam) TArray<ParticleBeamEndPoint> BeamEndPoints;
	UPROPERTY(EditAnywhere, Category = "Mesh")					float BeamTextureUScale;						//var(Beam) float BeamTextureUScale;
	UPROPERTY(EditAnywhere, Category = "Mesh")					float BeamTextureVScale;						//var(Beam) float BeamTextureVScale;
	UPROPERTY(EditAnywhere, Category = "Mesh")					int32 RotatingSheets;							//var(Beam) int32 RotatingSheets;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool TriggerEndpoint;							//var(Beam) bool TriggerEndpoint;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRangeVector LowFrequencyNoiseRange;			//var(BeamNoise) RangeVector LowFrequencyNoiseRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					int32 LowFrequencyPoints;						//var(BeamNoise) int32 LowFrequencyPoints;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRangeVector HighFrequencyNoiseRange;			//var(BeamNoise) RangeVector HighFrequencyNoiseRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					int32 HighFrequencyPoints;						//var(BeamNoise) int32 HighFrequencyPoints;
	UPROPERTY(EditAnywhere, Category = "Mesh")					TArray<FParticleBeamScale> LFScaleFactors;		//var(BeamNoise) TArray<ParticleBeamScale> LFScaleFactors;
	UPROPERTY(EditAnywhere, Category = "Mesh")					TArray<FParticleBeamScale> HFScaleFactors;		//var(BeamNoise) TArray<ParticleBeamScale> HFScaleFactors;
	UPROPERTY(EditAnywhere, Category = "Mesh")					float LFScaleRepeats;							//var(BeamNoise) float LFScaleRepeats;
	UPROPERTY(EditAnywhere, Category = "Mesh")					float HFScaleRepeats;							//var(BeamNoise) float HFScaleRepeats;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool UseHighFrequencyScale;						//var(BeamNoise) bool UseHighFrequencyScale;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool UseLowFrequencyScale;						//var(BeamNoise) bool UseLowFrequencyScale;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool NoiseDeterminesEndPoint;					//var(BeamNoise) bool NoiseDeterminesEndPoint;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRangeVector DynamicHFNoiseRange;				//var(BeamNoise) RangeVector DynamicHFNoiseRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRange DynamicHFNoisePointsRange;				//var(BeamNoise) Range DynamicHFNoisePointsRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRange DynamicTimeBetweenNoiseRange;			//var(BeamNoise) Range DynamicTimeBetweenNoiseRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool UseBranching;								//var(BeamBranching) bool UseBranching;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRange BranchProbability;						//var(BeamBranching) Range BranchProbability;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRange BranchHFPointsRange;						//var(BeamBranching) Range BranchHFPointsRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					int32 BranchEmitter;							//var(BeamBranching) int32 BranchEmitter;
	UPROPERTY(EditAnywhere, Category = "Mesh")					FRange BranchSpawnAmountRange;					//var(BeamBranching) Range BranchSpawnAmountRange;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool LinkupLifetime;							//var(BeamBranching) bool LinkupLifetime;
	UPROPERTY()													int32 SheetsUsed;								//var transient int32 SheetsUsed;
	UPROPERTY()													int32 VerticesPerParticle;						//var transient int32 VerticesPerParticle;
	UPROPERTY()													int32 IndicesPerParticle;						//var transient int32 IndicesPerParticle;
	UPROPERTY()													int32 PrimitivesPerParticle;					//var transient int32 PrimitivesPerParticle;
	UPROPERTY()													float BeamValueSum;								//var transient float BeamValueSum;
	UPROPERTY()													TArray<FParticleBeamData> HFPoints;				//var transient TArray<ParticleBeamData> HFPoints;
	UPROPERTY()													TArray<FVector> LFPoints;						//var transient TArray<Vector> LFPoints;
	UPROPERTY()													TArray<FVector> HitActors;						//var transient TArray<Actor> HitActors;
	UPROPERTY()													float TimeSinceLastDynamicNoise;				//var transient float TimeSinceLastDynamicNoise;

};
