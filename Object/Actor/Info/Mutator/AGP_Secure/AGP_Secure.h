// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/Mutator/Mutator.h"
#include "AGP_Secure.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_Secure : public AMutator
{
	GENERATED_BODY()
public:
	AAGP_Secure();

	UPROPERTY()			int32 LoginCnt;							//var int32 LoginCnt;

	void PostBeginPlay();
	void Tick(float Delta);
	void ModifyLogin(FString& Portal, FString& Options);
	void FixSecurity(APlayerController* PC);
};
