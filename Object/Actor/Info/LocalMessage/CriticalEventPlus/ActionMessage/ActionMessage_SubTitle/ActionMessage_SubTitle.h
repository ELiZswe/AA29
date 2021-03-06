// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/ActionMessage/ActionMessage.h"
#include "ActionMessage_SubTitle.generated.h"

UCLASS()
class AActionMessage_SubTitle : public AActionMessage
{
	GENERATED_BODY()
public:
	AActionMessage_SubTitle();

	UPROPERTY()			TArray<float> Delays;					//var localized float Delays;

	float GetLifeTime(int32 Switch);
};
