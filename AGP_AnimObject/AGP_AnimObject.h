// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_AnimObject.generated.h"

UCLASS()
class AA29_API AAGP_AnimObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_AnimObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float StartFrame;									//var() float StartFrame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 AnimChannel;									//var() int AnimChannel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float AnimTime;										//var() float AnimTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float AnimRate;										//var() float AnimRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FName AnimSequence;									//var() name AnimSequence;

	UPROPERTY()														USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY()														USceneComponent* RangeRoot;
	UPROPERTY(EditAnywhere)											USkeletalMesh* CustomMesh;
	UPROPERTY(EditAnywhere)											UAnimationAsset* Anim;

	void PostNetBeginPlay();
	void MatchStarting();
	void DoAnimLoop();
	void SetMesh();
};
