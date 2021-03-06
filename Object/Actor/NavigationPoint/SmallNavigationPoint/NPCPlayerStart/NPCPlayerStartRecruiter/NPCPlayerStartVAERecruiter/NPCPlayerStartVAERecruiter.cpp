// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartVAERecruiter/NPCPlayerStartVAERecruiter.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCVAERecruiterController/NPCVAERecruiterController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPCPlayerStartVAERecruiter::ANPCPlayerStartVAERecruiter()
{
	fpVertCollisionOffsetDown = 10;
	Radius = 255;
	//ControllerClass = ANPCVAERecruiterController::StaticClass()
	iNPCInitialMentalState = 10;
}

void ANPCPlayerStartVAERecruiter::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
	Cast<ANPCVAERecruiterController>(npbcController)->anameUserActivatedAudio = anameRecruiterLipSynchAudio;
	Cast<ANPCVAERecruiterController>(npbcController)->Volume = Volume;
	Cast<ANPCVAERecruiterController>(npbcController)->Radius = Radius;
	Cast<ANPCVAERecruiterController>(npbcController)->Pitch = Pitch;
	Cast<ANPCVAERecruiterController>(npbcController)->fpPlayerDetectionRange = fpPlayerDetectionRange;
	Cast<ANPCVAERecruiterController>(npbcController)->bGivesLanyards = bGivesLanyards;
	Cast<ANPCVAERecruiterController>(npbcController)->nameVAEBlockingNPC = nameVAEBlockingNPC;
	Cast<ANPCVAERecruiterController>(npbcController)->fpVertCollisionOffsetDown = fpVertCollisionOffsetDown;
}

void ANPCPlayerStartVAERecruiter::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	agpPawnNew->bEyeTrack = bEnableEyeTracking;
}
