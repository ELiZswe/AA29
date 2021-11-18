// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "AA29/MyStructs.h"
#include "SceneSubtitles.generated.h"


UCLASS()
class AA29_API ASceneSubtitles : public AAA2_Info
{
	GENERATED_BODY()
public:
	ASceneSubtitles();


	UPROPERTY()						int32 CurrentIndex;									//var int CurrentIndex;
	UPROPERTY(EditAnywhere)			TArray<FString> SubTitles;							//var() localized array<String> SubTitles;

	//virtual void ProcessEvent(ESST_Mode Mode) override;

	FString GetSubTitles();
	void Reset();

};
