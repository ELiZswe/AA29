// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealHeroFadeInCylinder.generated.h"

class ANPCRealHeroController;

UCLASS()
class AA29_API ARealHeroFadeInCylinder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARealHeroFadeInCylinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()			ANPCRealHeroController* RHController;		//var NPCRealHeroController RHController;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
