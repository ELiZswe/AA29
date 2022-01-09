// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealHeroFadeInCylinder.generated.h"

class ANPCRealHeroController;

UCLASS()
class ARealHeroFadeInCylinder : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ARealHeroFadeInCylinder();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()			ANPCRealHeroController* RHController;		//var NPCRealHeroController RHController;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
