// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BassLaserAttachment.generated.h"

UCLASS()
class ABassLaserAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	ABassLaserAttachment();

	//Mine
	UPROPERTY()					USkeletalMeshComponent* VisibleSkeletalMesh;
	UPROPERTY()					USceneComponent* Root;
	UPROPERTY(EditAnywhere)		USkeletalMesh* Mesh;

	FVector GetTipLocation();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

};
