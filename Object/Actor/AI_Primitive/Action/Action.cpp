// All the original content belonged to the US Army


#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"

AAction::AAction()
{

}

void AAction::PreBeginPlay()
{
	/*
	my_goal = Goal(Owner);
	Controller = my_goal.Controller;
	lastCallFailed = false;
	*/
}
void AAction::getPawn()
{
	/*
	Return AGP_Pawn(Controller.Pawn);
	*/
}
void AAction::GetWeapon()
{
	/*
	Return Controller.Pawn.Weapon;
	*/
}
void AAction::getEnemy()
{
	/*
	Return AGP_Pawn(Controller.Enemy);
	*/
}
void AAction::SetEnemy(APawn* new_enemy)
{
	/*
	Return Controller.SetEnemy(new_enemy);
	*/
}
void AAction::getMentalModel()
{
	/*
	Return Controller.getMentalModel();
	*/
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
	//Controller.registerNotification(Self);
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