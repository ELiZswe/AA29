// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseScope/BaseScope.h"
#include "Scope_BinocM22_A.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AScope_BinocM22_A : public ABaseScope
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AScope_BinocM22_A();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
