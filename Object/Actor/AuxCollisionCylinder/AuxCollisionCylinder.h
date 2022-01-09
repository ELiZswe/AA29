// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuxCollisionCylinder.generated.h"

UCLASS()
class AAuxCollisionCylinder : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAuxCollisionCylinder();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	bool UsedBy(APawn* User);
	void SetAuxCylinder(bool bEnable);

};
