// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_AnimObject.generated.h"

UCLASS()
class AAGP_AnimObject : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_AnimObject();

protected:
	
	virtual void BeginPlay() override;


public:	
	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)								float StartFrame;									//var() float StartFrame;
	UPROPERTY(EditAnywhere)								int32 AnimChannel;									//var() int AnimChannel;
	UPROPERTY(EditAnywhere)								float AnimTime;										//var() float AnimTime;
	UPROPERTY(EditAnywhere)								float AnimRate;										//var() float AnimRate;
	UPROPERTY(EditAnywhere)								FName AnimSequence;									//var() name AnimSequence;

	UPROPERTY()														USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY()														USceneComponent* RangeRoot;
	UPROPERTY(EditAnywhere)											USkeletalMesh* CustomMesh;
	UPROPERTY(EditAnywhere)											UAnimationAsset* Anim;

	void PostNetBeginPlay();
	void MatchStarting();
	void DoAnimLoop();
	void SetMesh();
};
