// All the original content belonged to the US Army

#include "AA29/Object/Team_Interface/Team_Interface.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

UTeam_Interface::UTeam_Interface()
{
	Subordinate.SetNum(16);

}

bool UTeam_Interface::replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub)
{
	return false;   //FAKE   /ELiZ
}

void UTeam_Interface::printTeam()
{

}
