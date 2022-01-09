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
	
	AFSTS_FA_MedicalAttachment();

	UPROPERTY()			UStaticMesh*	AltStaticMesh;		//var StaticMesh AltStaticMesh;
	UPROPERTY()			UStaticMesh*	AltStaticMesh2;		//var StaticMesh AltStaticMesh2;

	void SwitchToAltStaticMesh();
	void SwitchToAltStaticMesh2();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
