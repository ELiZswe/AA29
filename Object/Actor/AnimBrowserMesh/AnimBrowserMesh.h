// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimBrowserMesh.generated.h"

UCLASS()
class AAnimBrowserMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAnimBrowserMesh();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
