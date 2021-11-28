// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "AA29/AA29.h"
#include "BaseShellEmitter.generated.h"

class UParticleEmitter;

UCLASS()
class AA29_API ABaseShellEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ABaseShellEmitter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bUseAnimNotifyEject;				//var bool bUseAnimNotifyEject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AActor* AttachTo3P;						//var Actor AttachTo3P;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FBoneOffset Offset3P;					//var Object.BoneOffset Offset3P;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FBoneOffset Offset1P;					//var Object.BoneOffset Offset1P;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float fPitchModifier;					//var float fPitchModifier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* ShellStaticMesh;			//var StaticMesh ShellStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector ShellDrawScale;					//var FVector ShellDrawScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FRotationRandomizer ShellDirInfo;		//var Object.RotationRandomizer ShellDirInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sDirt;				//var array<Sound> sDirt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sWater;				//var array<Sound> sWater;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sMetal;				//var array<Sound> sMetal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sConcrete;			//var array<Sound> sConcrete;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<USoundBase*> sWood;				//var array<Sound> sWood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bInFirstPerson;					//var bool bInFirstPerson;


	void PostBeginPlay();
	void Initialize(FRotationRandomizer newShellDirInfo, FBoneOffset newOffset1P, FBoneOffset newOffset3P, AActor* newAttachTo3P);
	void GetCollisionSound(UParticleEmitter* E, int32 PIndex, UMaterialInstance* HitMat, USoundBase*& HitSound, float& Volume, float& Radius, float& Pitch, float& Fade, float& Priority);
	FRangeVector GetRVFromV(FVector V);
	FRangeVector GetStartRotation();
	FRangeVector GetStartVelocity();
	FVector GetStartLocationOffset();
	void SetFirstPerson(bool bFirstPerson, bool bImmediate);
	void ImmedateUpdate1P();
	void ImmediateUpdate3P();
	void Eject(bool bFirstPerson);
	void AnimControlledEject();
};
