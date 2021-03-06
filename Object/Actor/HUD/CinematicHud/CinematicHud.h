// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "CinematicHud.generated.h"

class ALocalMessage;

UCLASS()
class ACinematicHud : public AAA2_HUD
{
	GENERATED_BODY()
public:
	ACinematicHud(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()			float			Delta;					//var float Delta;
	UPROPERTY()			bool			bHideScope;				//var bool bHideScope;
	UPROPERTY()			TArray<float>	xOffsets;				//var float xOffsets[2];
	UPROPERTY()			TArray<float>	xRates;					//var float xRates[2];
	UPROPERTY()			TArray<float>	yOffsets;				//var float yOffsets[2];
	UPROPERTY()			TArray<float>	yRates;					//var float yRates[2];
	UPROPERTY()			bool			bInitialized;			//var bool bInitialized;
	UPROPERTY()			float			Scale;					//var float Scale;
	UPROPERTY()			FString			SubTitle;				//var FString SubTitle;
	UPROPERTY()			float			SubTitleKillTime;		//var float SubTitleKillTime;

	void DrawHUD();
	void Initialize(UCanvas* Canvas);
	void LocalizedMessage(ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString CriticalString);
};
