// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_ChopperCraft/AGP_ChopperCraft.h"

AAGP_ChopperCraft::AAGP_ChopperCraft()
{
	PushForce = 100000;
	//bFollowLookDir = true;
	//bPCRelativeFPRotation = false;
	//bCanFly = true;
	//bCanStrafe = true;
	//bCanBeBaseForPawns = false;
	//GroundSpeed = 1200;
}

bool AAGP_ChopperCraft::KUpdateState(FKRigidBodyState NewState)
{
	/*
	if (Role == 4 || !bNewCopterState)
	{
		Return False;
	}
	NewState = ChassisState;
	bNewCopterState = False;
	*/
	return true;
}

void AAGP_ChopperCraft::SVehicleUpdateParams()
{
	//SVehicleUpdateParams();
	//KSetStayUprightParams(UprightStiffness, UprightDamping);
}

void AAGP_ChopperCraft::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	//ViewActor = Self;
	//CameraLocation = Location + FPCamPos >> Rotation;
}

void AAGP_ChopperCraft::JumpOutCheck()
{
}