// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "FSTS_Pawn.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_Pawn : public AAGP_Character
{
	GENERATED_BODY()
public:
	AFSTS_Pawn();

	UPROPERTY(EditAnywhere)								bool bNoTakeDamage;					//var() bool bNoTakeDamage;

	void PossessedBy(AController* C);
	void BeginPlay();
};
