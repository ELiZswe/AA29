// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/BeamEmitter/BeamEmitter.h"
#include "RopeBeamEmitter.generated.h"

class AAGP_Pawn;

UCLASS()
class AA29_API URopeBeamEmitter : public UBeamEmitter
{
	GENERATED_BODY()
public:
	URopeBeamEmitter();

	UPROPERTY(EditAnywhere, Category = "Rope")					EBeamRopeType RopeType;						//var(Rope) Enum EBeamRopeType  RopeType;
	UPROPERTY(EditAnywhere, Category = "Rope")					FVector vInitialDirection;					//var(Rope) Vector vInitialDirection;
	UPROPERTY(EditAnywhere, Category = "Rope")					float fMinVelThreshold;						//var(Rope) float fMinVelThreshold;
	UPROPERTY(EditAnywhere, Category = "Rope")					float fSlideDeadZone;						//var(Rope) float fSlideDeadZone;
	UPROPERTY(EditAnywhere, Category = "Rope")					float fSegmentLength;						//var(Rope) float fSegmentLength;
	UPROPERTY(EditAnywhere, Category = "Rope")					bool bDownOnly;								//var(Rope) bool bDownOnly;
	UPROPERTY(EditAnywhere, Category = "Collision")				float fBounciness;							//var(Collision) float fBounciness;
	UPROPERTY(EditAnywhere, Category = "Flex")					bool bUseFlex;								//var(Flex) bool bUseFlex;
	UPROPERTY(EditAnywhere, Category = "Flex")					int32 iFlexOffset;							//var(Flex) int32 iFlexOffset;
	UPROPERTY(EditAnywhere, Category = "Flex")					float fFlexThreshold;						//var(Flex) float fFlexThreshold;
	UPROPERTY(EditAnywhere, Category = "Flex")					int32 iRelaxFactor;							//var(Flex) int32 iRelaxFactor;
	UPROPERTY(EditAnywhere, Category = "Flex")					float fTwistFactor;							//var(Flex) float fTwistFactor;
	UPROPERTY(EditAnywhere, Category = "Anchor")				bool bUseAnchors;							//var(Anchor) bool bUseAnchors;
	UPROPERTY(EditAnywhere, Category = "Anchor")				UObject* cAnchorClass;						//var(Anchor) class<Object> cAnchorClass;
	UPROPERTY(EditAnywhere, Category = "Anchor")				FParticleAnchor PointAnchors;				//var(Anchor) ParticleAnchor PointAnchors[10];
	UPROPERTY(EditAnywhere, Category = "Rope")					int32 iVerletIntegrationCount;				//var(Rope) int32 iVerletIntegrationCount;
	UPROPERTY()													TArray<FAttachedPawnInfo> AttachedIndex;		//var TArray<AttachedPawnInfo> AttachedIndex;
	UPROPERTY()													TArray<FVector> ParticleAccel;				//var TArray<Vector> ParticleAccel;
	UPROPERTY()													TArray<float> SegmentTension;				//var TArray<float> SegmentTension;
	UPROPERTY()													float fAvgDeltaTime;						//var float fAvgDeltaTime;
	UPROPERTY(EditAnywhere, Category = "Debug")					bool bTest;									//var(Debug) bool bTest;
	UPROPERTY()													int32 iMoveParticleCount;					//var int32 iMoveParticleCount;
	UPROPERTY()													int32 iMoveParticleRecursions;				//var int32 iMoveParticleRecursions;

	void LinkAnchors(UObject* baseClass);
	void DetachPawn(AAGP_Pawn* Pawn);
};
