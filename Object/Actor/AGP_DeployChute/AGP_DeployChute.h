// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_DeployChute.generated.h"

class UCapsuleComponent;
class UBillboardComponent;
class USceneComponent;

UCLASS()
class AAGP_DeployChute : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_DeployChute();

	UPROPERTY()									USceneComponent* Root;
	UPROPERTY()									UCapsuleComponent* Capsule;
	UPROPERTY()									UTexture2D* Texture;
	UPROPERTY()									UBillboardComponent* SpriteComponent;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();

	void Trigger(AActor* Other, APawn* EventInstigator);
};
