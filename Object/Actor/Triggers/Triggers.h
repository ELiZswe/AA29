// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "Components/CapsuleComponent.h."
#include "Triggers.generated.h"


UCLASS()
class ATriggers : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ATriggers();


	UPROPERTY(VisibleAnywhere)		UBillboardComponent* SpriteComponent;
	UPROPERTY(VisibleAnywhere)		UCapsuleComponent* Capsule;


	//From Actor
	UPROPERTY(EditAnywhere)		bool bIsLocal;
	UPROPERTY(EditAnywhere)		bool bUseCylinderCollision;
	UPROPERTY(EditAnywhere)		bool bCollideActors;
	UPROPERTY(EditAnywhere)		bool bBlockBulletTraces;
	UPROPERTY(EditAnywhere)		bool bBlockCoronaTraces;
	UPROPERTY(EditAnywhere)		int32 CollisionRadius;
	UPROPERTY(EditAnywhere)		FVector	ColLocation;
	UPROPERTY(EditAnywhere)		int32 CollisionHeight;
	UPROPERTY(EditAnywhere)		FName Event;
	UPROPERTY(EditAnywhere)		FString Group;
	UPROPERTY(EditAnywhere)		FString InitialState;
	UPROPERTY(EditAnywhere)		FString Tag;


protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
