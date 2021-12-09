// All the original content belonged to the US Army


#include "AA29/Object/Actor/KActor/KConstraint/KHinge/KHinge.h"

AKHinge::AKHinge()
{
	KStiffness = 50;
	KProportionalGap = 8200;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_KHinge.S_KHinge'"), NULL, LOAD_None, NULL);
	//bDirectional = true;
}
/*
auto State Default
{
}

State ToggleMotor
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (KHingeType == 2)
		{
			KDesiredAngle = KCurrentAngle;
			KUseAltDesired = false;
			KHingeType = 3;
		}
		else
		{
			KHingeType = 2;
		}
		KUpdateConstraintParams();
		KConstraintActor1.KWake();
	}
Begin:
	KHingeType = 3;
	KUseAltDesired = false;
	KUpdateConstraintParams();
}

State ControlMotor
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (KHingeType != 2)
		{
			KHingeType = 2;
			KUpdateConstraintParams();
			KConstraintActor1.KWake();
		}
	}
	Function UnTrigger(Actor Other, Pawn EventInstigator)
	{
		if (KHingeType == 2)
		{
			KDesiredAngle = KCurrentAngle;
			KUseAltDesired = false;
			KHingeType = 3;
			KUpdateConstraintParams();
			KConstraintActor1.KWake();
		}
	}
Begin:
	KHingeType = 3;
	KUseAltDesired = false;
	KUpdateConstraintParams();
}

State ToggleDesired
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (KUseAltDesired)
		{
			KUseAltDesired = false;
		}
		else
		{
			KUseAltDesired = true;
		}
		KUpdateConstraintParams();
		KConstraintActor1.KWake();
	}
}

State ControlDesired
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		KUseAltDesired = true;
		KUpdateConstraintParams();
		KConstraintActor1.KWake();
	}
	Function UnTrigger(Actor Other, Pawn EventInstigator)
	{
		KUseAltDesired = false;
		KUpdateConstraintParams();
		KConstraintActor1.KWake();
	}
}

*/