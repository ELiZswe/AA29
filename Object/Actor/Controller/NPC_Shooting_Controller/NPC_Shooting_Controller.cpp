// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/NPC_Shooting_Controller/NPC_Shooting_Controller.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ANPC_Shooting_Controller::ANPC_Shooting_Controller()
{

}

/*
auto State Shooting
{
Begin:
	Sleep((20 + (FMath::FRand() * 20)));
	if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
	{
		Pawn.Weapon.AmmoType.AmmoAmount=3;
		Pawn.Weapon.Fire(0);
	}
	Sleep((3 + (FMath::FRand() * 5)));
	JL"Loop"
;
}
*/

/*
void ANPC_Shooting_Controller::Possess(APawn* aPawn)
{
	Possess(aPawn);
	if (Cast<AAGP_Pawn>(aPawn) != nullptr)
	{
		Pawn.NPC_GiveWeapon(Cast<AAGP_Pawn>(aPawn).NPC_Weapon);
	}
}

*/
