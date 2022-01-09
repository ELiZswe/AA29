// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "TEntryScreenplay.generated.h"

UCLASS()
class ATEntryScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ATEntryScreenplay();

	void Init();
};
