// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/ActionRecovery/ActionRecovery.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

AActionRecovery::AActionRecovery()
{

}

float AActionRecovery::evaluateAction()
{
	//DebugLog(DEBUG_InvAI, "ActionRecovery::evaluateAction()");
	//return getMentalModel().getBestPickup(getPawn(), recovery_pickup);

	return 0;     //FAKE    /ELiZ
}

void AActionRecovery::executeAction()
{
	//Controller.registerNotification(this);
	//Controller.Recovery(recovery_pickup);
}
