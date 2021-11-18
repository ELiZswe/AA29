// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "NPC_Ambient.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPC_Ambient : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_Ambient();

	UPROPERTY(EditAnywhere)															int32 nNPCusedtime;								//var() int nNPCusedtime;
	UPROPERTY(EditAnywhere)															int32 nNPCthinktime;							//var() int nNPCthinktime;
	UPROPERTY(EditAnywhere)															bool bNPCused;									//var() bool bNPCused;
	UPROPERTY(EditAnywhere)															bool bPlayDyingAnimation;						//var() bool bPlayDyingAnimation;
	UPROPERTY(EditAnywhere)															bool bUseKarmaDeathAnimation;					//var() bool bUseKarmaDeathAnimation;
	UPROPERTY()																		int32 InitialKillHealth;						//var int InitialKillHealth;
	UPROPERTY()																		AAGP_Objective* DamageObjective;				//var AGP.AGP_Objective DamageObjective;


	void PossessedBy(AController* C);
	void BeginPlay();
};
