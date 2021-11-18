// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseContactEmitter.generated.h"

UCLASS()
class AA29_API ABaseContactEmitter : public AActor
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)													USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;


public:	
	// Sets default values for this actor's properties
	ABaseContactEmitter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
