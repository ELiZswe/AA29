// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KActor.generated.h"

UCLASS()
class AA29_API AKActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKActor();



	UPROPERTY()											float LastImpactTime;										//var transient float LastImpactTime;
	UPROPERTY(EditAnywhere)								float ImpactInterval;										//var() float ImpactInterval;
	UPROPERTY(EditAnywhere)								bool bOrientImpactEffect;									//var() bool bOrientImpactEffect;
	UPROPERTY(EditAnywhere)								AActor* ImpactEffect;										//var() class<Actor> ImpactEffect;
	UPROPERTY(EditAnywhere)								float ImpactVolume;											//var() float ImpactVolume;
	UPROPERTY(EditAnywhere)								TArray<USoundBase*> ImpactSounds;							//var() array<Sound> ImpactSounds;
	UPROPERTY(EditAnywhere, Category = "Karma")			bool bKTakeShot;											//var(Karma) bool bKTakeShot;

	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;
	UPROPERTY(EditAnywhere)													UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)													TArray<UMaterialInstance*> OverrideMaterials;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
	void Trigger(AActor* Other, APawn* EventInstigator);
	void KImpact(AActor* Other, FVector pos, FVector impactVel, FVector impactNorm);


	void LoadEditorIcon();
	void LoadMesh();
	
};
