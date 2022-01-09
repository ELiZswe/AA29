// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "EntryScreenplay.generated.h"

UCLASS()
class AEntryScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	AEntryScreenplay();

	void Init();
};
