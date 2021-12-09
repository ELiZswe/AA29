// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_DeployChute.generated.h"

class UCapsuleComponent;
class UBillboardComponent;
class USceneComponent;

UCLASS()
class AA29_API AAGP_DeployChute : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_DeployChute();

	UPROPERTY()									USceneComponent* Root;
	UPROPERTY()									UCapsuleComponent* Capsule;
	UPROPERTY()									UTexture2D* Texture;
	UPROPERTY()									UBillboardComponent* SpriteComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();

	void Trigger(AActor* Other, APawn* EventInstigator);
};
