// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC.h"
#include "FSTS_NPC_DrillSergeant.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_NPC_DrillSergeant : public AFSTS_NPC
{
	GENERATED_BODY()
public:
	AFSTS_NPC_DrillSergeant();
	
	UPROPERTY(EditAnywhere)		float TwitchInterval;					//var() float TwitchInterval;
	UPROPERTY(EditAnywhere)		FName DSIdleAnim;						//var() name DSIdleAnim;
	UPROPERTY(EditAnywhere)		TArray<FName> ConversationalAnims;		//var() array<name> ConversationalAnims;
	UPROPERTY(EditAnywhere)		TArray<FName> IdleGestureAnims;			//var() array<name> IdleGestureAnims;
};
