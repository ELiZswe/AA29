// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ParticleEmitter/AA2_ParticleEmitter.h"
#include "MeshEmitter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UMeshEmitter : public UAA2_ParticleEmitter
{
	GENERATED_BODY()
public:
	UMeshEmitter();

	UPROPERTY(EditAnywhere, Category = "AbsoluteRotation")		EAbsoluteRotationSource AbsoluteRotationSource;		//var(Mesh) var(AbsoluteRotation) Enum EAbsoluteRotationSource AbsoluteRotationSource;
	UPROPERTY(EditAnywhere, Category = "Mesh")					UStaticMesh* StaticMesh;							//var(Mesh) StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool UseMeshBlendMode;								//var(Mesh) bool UseMeshBlendMode;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool RenderTwoSided;								//var(Mesh) bool RenderTwoSided;
	UPROPERTY(EditAnywhere, Category = "Mesh")					bool UseParticleColor;								//var(Mesh) bool UseParticleColor;
	UPROPERTY(EditAnywhere)										FVector MeshExtent;									//var transient Vector MeshExtent;
	UPROPERTY(EditAnywhere, Category = "AbsoluteRotation")		bool bUseAbsoluteRotation;							//var(AbsoluteRotation) bool bUseAbsoluteRotation;

};
