// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealHeroAwarenessCylinder.generated.h"

class ANPCRealHeroController;

UCLASS()
class ARealHeroAwarenessCylinder : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ARealHeroAwarenessCylinder();

	UPROPERTY()			ANPCRealHeroController* RHController;		//var NPCRealHeroController RHController;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
