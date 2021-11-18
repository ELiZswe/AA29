// All the original content belonged to the US Army


#include "AA29/Keypoint/AIScript/AIScript.h"

AAIScript::AAIScript(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	//Texture = Texture'Engine.S_AIScript';
	//DrawScale = 0.5;
}



void AAIScript::SpawnControllerFor(APawn* p)
{
	/*
	local AIController C;
	if (ControllerClass == None)
	{
		if (p.ControllerClass == None)
		{
			Return;
		}
		C = Spawn(p.ControllerClass, , , p.Location, p.Rotation);
	}
	else
	{
		C = Spawn(ControllerClass, , , p.Location, p.Rotation);
	}
	C.MyScript = Self;
	C.Possess(p);
	*/
}
void AAIScript::GetMoveTarget()
{
	/*
	if (myMarker != nullptr)
	{
		return myMarker;
	}
	return this;
	*/
}
void AAIScript::TakeOver(APawn* p)
{
}