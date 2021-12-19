// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSTS_FA_MedicalAttachment.generated.h"

UCLASS()
class AFSTS_FA_MedicalAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFSTS_FA_MedicalAttachment();

	UPROPERTY()			UStaticMesh*	AltStaticMesh;		//var StaticMesh AltStaticMesh;
	UPROPERTY()			UStaticMesh*	AltStaticMesh2;		//var StaticMesh AltStaticMesh2;

	void SwitchToAltStaticMesh();
	void SwitchToAltStaticMesh2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
