// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Particles/Emitter.h"
#include "AA29/AA29.h"
#include "AA29/MyStructs.h"
#include "AA2_Emitter.generated.h"

class UAA2_ParticleEmitter;

UCLASS()
class AA29_API AAA2_Emitter : public AEmitter
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
		AAA2_Emitter();

		//UPROPERTY()														AParticleMaterial* ParticleMaterial;				//var transient ParticleMaterial ParticleMaterial;
		UPROPERTY()															bool ActorForcesEnabled;							//var transient bool ActorForcesEnabled;
		UPROPERTY()															bool DeleteParticleEmitters;						//var transient bool DeleteParticleEmitters;
		UPROPERTY()															bool UseParticleProjectors;							//var transient bool UseParticleProjectors;
		UPROPERTY()															float TimeTillReset;								//var transient float TimeTillReset;
		UPROPERTY()															float EmitterHeight;								//var transient float EmitterHeight;
		UPROPERTY()															float EmitterRadius;								//var transient float EmitterRadius;
		UPROPERTY()															UTexture2D* BoundingBox;							//var transient Object.Box BoundingBox;
		UPROPERTY()															int32 Initialized;									//var transient int Initialized;
		UPROPERTY()															FVector AbsoluteVelocity;							//var transient FVector AbsoluteVelocity;
		UPROPERTY()															FVector GlobalOffset;								//var transient FVector GlobalOffset;
		UPROPERTY()															FVector OldLocation;								//var transient FVector OldLocation;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Global")	uint8 ShowTeam;										//var(Global) byte ShowTeam;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Global")	bool DisableFogging;								//var(Global) bool DisableFogging;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Global")	bool AutoReset;										//var(Global) bool AutoReset;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Global")	bool AutoDestroy;									//var(Global) bool AutoDestroy;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Global")	FObjectRange TimeTillResetRange;					//var(Global) Object.Range TimeTillResetRange;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Global")	FRangeVector GlobalOffsetRange;						//var(Global) Object.RangeVector GlobalOffsetRange;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)							TArray<UAA2_ParticleEmitter*> Emitters;				//var() array<ParticleEmitter> Emitters;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)							float LifeSpan;
};