// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

AAction::AAction()
{

}

void AAction::PreBeginPlay()
{
	/*
	my_goal = Goal(GetOwner());
	Controller = my_goal.Controller;
	lastCallFailed = false;
	*/
}
AAGP_Pawn* AAction::getPawn()
{
	//return Cast<AAGP_Pawn>(Controller.Pawn);
	return nullptr;    //FAKE   /ELiZ
}
AWeapon* AAction::GetWeapon()
{
	//return Controller.Pawn.Weapon;
	return nullptr;    //FAKE   /ELiZ
}
AAGP_Pawn* AAction::getEnemy()
{
	//return Cast<AAGP_Pawn>(Controller.Enemy);
	return nullptr;    //FAKE   /ELiZ
}
bool AAction::SetEnemy(APawn* new_enemy)
{
	//return Controller.SetEnemy(new_enemy);
	return nullptr;    //FAKE   /ELiZ
}
AMentalModel* AAction::getMentalModel()
{
	//return Controller.getMentalModel();
	return nullptr;    //FAKE   /ELiZ
}
float AAction::evaluateAction()
{
	return 0;
}
bool AAction::checkFailure()
{
	bool retval = false;
	retval = lastCallFailed;
	lastCallFailed = false;
	return retval;
}
void AAction::registerAndExecute()
{
	//Controller.registerNotification(this);
	executeAction();
}
void AAction::executeAction()
{
}
void AAction::CompleteAction()
{
}
void AAction::NotifyComplete(bool failed)
{
	lastCallFailed = failed;
	//my_goal.NotifyComplete();
}
