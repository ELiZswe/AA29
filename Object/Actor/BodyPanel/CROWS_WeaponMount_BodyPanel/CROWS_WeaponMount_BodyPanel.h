// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "CROWS_WeaponMount_BodyPanel.generated.h"

UCLASS()
class ACROWS_WeaponMount_BodyPanel : public ABodyPanel
{
	GENERATED_BODY()
public:
	ACROWS_WeaponMount_BodyPanel();

	UPROPERTY()					FName nmAttachBone;								//var name nmAttachBone

	void PostNetBeginPlay();

};
