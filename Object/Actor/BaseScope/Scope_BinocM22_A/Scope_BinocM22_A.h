// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseScope/BaseScope.h"
#include "Scope_BinocM22_A.generated.h"

UCLASS()
class AScope_BinocM22_A : public ABaseScope
{
	GENERATED_BODY()
public:
	
	AScope_BinocM22_A();

protected:
	
	virtual void BeginPlay() override;
};
