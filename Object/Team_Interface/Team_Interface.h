// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyStructs.h"
#include "Team_Interface.generated.h"

class AAGP_Pawn;
	
	
UCLASS()
class AA29_API UTeam_Interface : public UObject
{
	GENERATED_BODY()
public:
	UTeam_Interface();


	UPROPERTY()									UTeam_Interface* nextTeam;									//var Team_Interface nextTeam;
	UPROPERTY()									int32 nSubordinates;										//var int nSubordinates;
	UPROPERTY()									AAGP_Pawn* Subordinate;										//var AGP_Pawn Subordinate;
	UPROPERTY()									ETeam team_id;												//var Pawn.ETeam team_id;

	virtual void replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub);
	virtual void printTeam();


};
