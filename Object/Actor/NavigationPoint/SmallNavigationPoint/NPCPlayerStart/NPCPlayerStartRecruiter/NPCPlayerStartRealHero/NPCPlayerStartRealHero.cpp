// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartRealHero/NPCPlayerStartRealHero.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPCPlayerStartRealHero::ANPCPlayerStartRealHero()
{

	fpVertCollisionOffsetDown = 10;
	Radius = 255;
	//ControllerClass = ANPCRealHeroController::StaticClass();
	iNPCInitialMentalState = 10;
}

void ANPCPlayerStartRealHero::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
	Cast<ANPCRealHeroController>(npbcController)->anameUserActivatedAudio = anameRecruiterLipSynchAudio;
	Cast<ANPCRealHeroController>(npbcController)->Volume = Volume;
	Cast<ANPCRealHeroController>(npbcController)->Radius = Radius;
	Cast<ANPCRealHeroController>(npbcController)->Pitch = Pitch;
	Cast<ANPCRealHeroController>(npbcController)->fpPlayerDetectionRange = fpPlayerDetectionRange;
	Cast<ANPCRealHeroController>(npbcController)->fpVertCollisionOffsetDown = fpVertCollisionOffsetDown;
}
