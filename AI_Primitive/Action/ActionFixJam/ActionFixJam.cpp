// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Action/ActionFixJam/ActionFixJam.h"

AActionFixJam::AActionFixJam()
{

}



float AActionFixJam::evaluateAction()
{
	/*
	if (Controller.weaponJammed() == true)
	{
		return 0.25;
	}
	else
	{
		return 0;
	}
	*/
	return 0;     //FAKE /ELiZ
}
void AActionFixJam::executeAction()
{
	//Controller.registerNotification(Self);
	//Controller.FixJam();
}