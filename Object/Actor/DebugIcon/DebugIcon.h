// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugIcon.generated.h"

UCLASS()
class ADebugIcon : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ADebugIcon();

	UPROPERTY()				UMaterialInstance* Texture;
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
