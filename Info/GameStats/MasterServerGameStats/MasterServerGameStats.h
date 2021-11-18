// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/GameStats/GameStats.h"
#include "MasterServerGameStats.generated.h"

class AMasterServerUplink;

UCLASS()
class AA29_API AMasterServerGameStats : public AGameStats
{
	GENERATED_BODY()
public:
	AMasterServerGameStats();

	UPROPERTY()			AMasterServerUplink* Uplink;							//var MasterServerUplink Uplink;

	void Init();
	void Logf(FString LogString);

};
