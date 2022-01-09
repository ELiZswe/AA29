// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "AA29/AA29.h"
#include "BaseShellEmitter.generated.h"

class UParticleEmitter;

UCLASS()
class ABaseShellEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ABaseShellEmitter();

	UPROPERTY(EditAnywhere)		bool bUseAnimNotifyEject;				//var bool bUseAnimNotifyEject;
	UPROPERTY(EditAnywhere)		AActor* AttachTo3P;						//var Actor AttachTo3P;
	UPROPERTY(EditAnywhere)		FBoneOffset Offset3P;					//var Object.BoneOffset Offset3P;
	UPROPERTY(EditAnywhere)		FBoneOffset Offset1P;					//var Object.BoneOffset Offset1P;
	UPROPERTY(EditAnywhere)		float fPitchModifier;					//var float fPitchModifier;
	UPROPERTY(EditAnywhere)		UStaticMesh* ShellStaticMesh;			//var StaticMesh ShellStaticMesh;
	UPROPERTY(EditAnywhere)		FVector ShellDrawScale;					//var FVector ShellDrawScale;
	UPROPERTY(EditAnywhere)		FRotationRandomizer ShellDirInfo;		//var Object.RotationRandomizer ShellDirInfo;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> sDirt;				//var array<Sound> sDirt;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> sWater;				//var array<Sound> sWater;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> sMetal;				//var array<Sound> sMetal;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> sConcrete;			//var array<Sound> sConcrete;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*> sWood;				//var array<Sound> sWood;
	UPROPERTY(EditAnywhere)		bool bInFirstPerson;					//var bool bInFirstPerson;


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
