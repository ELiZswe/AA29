// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/JumpPad/JumpPad.h"

AJumpPad::AJumpPad()
{
	JumpVelocity = FVector(0, 0, 1200);
	JumpZModifier = 1;
	bDestinationOnly = true;
	//bCollideActors = true;
}