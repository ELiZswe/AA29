// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "xProcMesh.generated.h"

class AEffects;
class UBillboardComponent;

UCLASS()
class AxProcMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AxProcMesh();

	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;
	UPROPERTY(EditAnywhere)													UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)													TArray<UMaterialInstance*> OverrideMaterials;

	UPROPERTY(EditAnywhere)										float InfluenceRadius;						//var() float InfluenceRadius;
	UPROPERTY(EditAnywhere)										float TouchStrength;						//var() float TouchStrength;
	UPROPERTY(EditAnywhere)										float ShootStrength;						//var() float ShootStrength;
	UPROPERTY(EditAnywhere)										float BigTouchThreshold;					//var() float BigTouchThreshold;
	UPROPERTY(EditAnywhere)										float BigMomentumThreshold;					//var() float BigMomentumThreshold;
	UPROPERTY(EditAnywhere)										AEffects* BigHitEffect;						//var() class<Effects> BigHitEffect;
	UPROPERTY(EditAnywhere)										AEffects* HitEffect;						//var() class<Effects> HitEffect;
	UPROPERTY()													Fpointer pProcData;							//var const transient pointer pProcData;
	UPROPERTY(EditAnywhere)										bool bRigidEdges;							//var() bool bRigidEdges;
	UPROPERTY(EditAnywhere, Category = "Force")					bool bForceAffected;						//var(Force) bool bForceAffected;
	UPROPERTY(EditAnywhere)										EProcMeshType ProcType;						//var() EProcMeshType ProcType;
	UPROPERTY()													float NoiseCounter;							//var transient float NoiseCounter;
	UPROPERTY(EditAnywhere)										FRange NoiseTimer;							//var() Object.Range NoiseTimer;
	UPROPERTY(EditAnywhere)										FRange NoiseForce;							//var() Object.Range NoiseForce;
	UPROPERTY(EditAnywhere)										float Noise;								//var() float Noise;
	UPROPERTY(EditAnywhere)										bool CheckCollision;						//var() bool CheckCollision;
	UPROPERTY(EditAnywhere)										float RestTension;							//var() float RestTension;
	UPROPERTY(EditAnywhere)										float Tension;								//var() float Tension;
	UPROPERTY(EditAnywhere)										float ForceAttenuation;						//var() float ForceAttenuation;
	UPROPERTY(EditAnywhere)										FRange ForceClamp;							//var() Object.Range ForceClamp;
	UPROPERTY(EditAnywhere)										FRange MovementClamp;						//var() Object.Range MovementClamp;
	UPROPERTY(EditAnywhere)										FRange DampeningRange;						//var() Object.Range DampeningRange;
	UPROPERTY(EditAnywhere)										float Dampening;							//var() float Dampening;
	UPROPERTY()													TArray<int32> SectionOffsets;				//var const array<int> SectionOffsets;
	UPROPERTY()													TArray<FAA2_ProcMeshVertex> Vertices;			//var const array<ProcMeshVertex> Vertices;


	void ProcPling(FVector Position, float Strength, float Radius, FVector& EffectLocation, FVector& EffectNormal);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);
	void Touch(AActor* Other);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
	void LoadMesh();
};
