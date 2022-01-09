// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_Scripted.h"
#include "AnimNotify_FireWeapon.generated.h"

UCLASS()
class UAnimNotify_FireWeapon : public UAnimNotify_Scripted
{
	GENERATED_BODY()
public:
	UAnimNotify_FireWeapon();

	void Notify(AActor* Owner);
};
