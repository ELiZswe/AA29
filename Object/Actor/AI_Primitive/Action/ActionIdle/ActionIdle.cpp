// All the original content belonged to the US Army


#include "AA29/Object/Actor/AI_Primitive/Action/ActionIdle/ActionIdle.h"

AActionIdle::AActionIdle()
{

}

float AActionIdle::evaluateAction()
{
	return 0.01;
}
void AActionIdle::executeAction()
{
	//Controller.registerNotification(this);
	//Controller.Idle();
}