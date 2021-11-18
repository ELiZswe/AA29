// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "Components/CapsuleComponent.h."
#include "Triggers.generated.h"


UCLASS()
class AA29_API ATriggers : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggers();


	UPROPERTY(VisibleAnywhere)		UBillboardComponent* SpriteComponent;
	UPROPERTY(VisibleAnywhere)		UCapsuleComponent* Capsule;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
