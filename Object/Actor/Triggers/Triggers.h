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


	//From Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bIsLocal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bUseCylinderCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bCollideActors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bBlockBulletTraces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bBlockCoronaTraces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 CollisionRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector	ColLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 CollisionHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName Event;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString Group;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString InitialState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString Tag;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
