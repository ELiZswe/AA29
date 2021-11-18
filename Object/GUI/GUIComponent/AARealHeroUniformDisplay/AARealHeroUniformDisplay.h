// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AARealHeroUniformDisplay.generated.h"

class UAARealHeroStats;

UCLASS()
class AA29_API UAARealHeroUniformDisplay : public UGUIComponent
{
	GENERATED_BODY()
public:
	UAARealHeroUniformDisplay();


	UPROPERTY()														int32 HighlightedBadge;								//var int HighlightedBadge;
	UPROPERTY()														UMaterialInstance* UniformImage;					//var Material UniformImage;
	UPROPERTY()														TArray<FString> Uniforms;							//var array<String> Uniforms;
	UPROPERTY()														int32 UniformIndex;									//var int UniformIndex;
	UPROPERTY()														UAARealHeroStats* MyRealHeroStatsClass;				//var class<AARealHeroStats> MyRealHeroStatsClass;


	void dOnDescribeBadge(FString BadgeToDescribe, bool bForceLoad);
	void SwitchUniforms(int32 Index);
	void InternalOnClick(UGUIComponent* Sender);

};
