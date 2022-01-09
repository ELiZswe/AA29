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
	
	ARealHeroAwarenessCylinder();

	UPROPERTY()			ANPCRealHeroController* RHController;		//var NPCRealHeroController RHController;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
