// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_Pawn.h"
#include "FSTS_NPC.generated.h"

UCLASS()
class AFSTS_NPC : public AFSTS_Pawn
{
	GENERATED_BODY()
public:
	AFSTS_NPC();

	UPROPERTY(EditAnywhere)			bool	bNoTakeDamage;							//var() bool bNoTakeDamage;

	void PostNetBeginPlay();
};
