// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AA2_Pawn.generated.h"

UCLASS()
class AA29_API AAA2_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAA2_Pawn();

	//From Actor+Pawn

	UPROPERTY()												bool			InVal;
	UPROPERTY()												USkeletalMesh*	Mesh;
	UPROPERTY(EditAnywhere, Category = "Collision")			uint8			ValidJavelinTarget;			//var(Collision) byte ValidJavelinTarget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
