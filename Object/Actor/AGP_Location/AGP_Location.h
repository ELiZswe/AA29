// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AGP_Location.generated.h"

UCLASS()
class AAGP_Location : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_Location();

	UPROPERTY(EditAnywhere)								EPostureSetting Posture;							//var() ePostureSetting Posture;
	UPROPERTY(EditAnywhere)								bool bIsWalking;									//var() bool bIsWalking;

	UPROPERTY()											UBillboardComponent* SpriteComponent;
	UPROPERTY()											USceneComponent* LRoot;

	void Start(AActor* Actor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
