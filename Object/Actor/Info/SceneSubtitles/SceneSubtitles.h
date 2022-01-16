// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/MyEnums.h"
#include "SceneSubtitles.generated.h"


UCLASS()
class ASceneSubtitles : public AAA2_Info
{
	GENERATED_BODY()
public:
	ASceneSubtitles();


	UPROPERTY()						int32 CurrentIndex;									//var int CurrentIndex;
	UPROPERTY(EditAnywhere)			TArray<FString> SubTitles;							//var() localized TArray<FString> SubTitles;

	//virtual void ProcessEvent(ESST_Mode Mode) override;

	FString GetSubTitles();
	void Reset();

};
