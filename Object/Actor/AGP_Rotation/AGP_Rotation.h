// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_Rotation.generated.h"

UCLASS()
class AAGP_Rotation : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_Rotation();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
