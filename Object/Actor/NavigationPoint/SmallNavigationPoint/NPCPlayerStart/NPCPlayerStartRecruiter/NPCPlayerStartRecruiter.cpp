// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartRecruiter.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRecruiterController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPCPlayerStartRecruiter::ANPCPlayerStartRecruiter()
{

	Volume = 1;
	Radius = 64;
	Pitch = 1;
	fpPlayerDetectionRange = 200;
	//ControllerClass = ANPCRecruiterController::StaticClass()
	iNPCInitialMentalState = 99;
	iNPCLeadershipMentalStateRange = 250;
	iNPCTeamID = 3;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNPCBlue.S_PNPCBlue'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5

#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}

void ANPCPlayerStartRecruiter::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
	Cast<ANPCRecruiterController>(npbcController)->anameUserActivatedAudio = anameRecruiterLipSynchAudio;
	Cast<ANPCRecruiterController>(npbcController)->Volume = Volume;
	Cast<ANPCRecruiterController>(npbcController)->Radius = Radius;
	Cast<ANPCRecruiterController>(npbcController)->Pitch = Pitch;
	Cast<ANPCRecruiterController>(npbcController)->fpPlayerDetectionRange = fpPlayerDetectionRange;
	Cast<ANPCRecruiterController>(npbcController)->nameUserLeavingAudio = nameUserLeavingAudio;
	//Log("NPC Recruiter has " + FString::FromInt(Cast<ANPCRecruiterController>(npbcController).anameUserActivatedAudio.Num()) + " lipsynchs");
}

void ANPCPlayerStartRecruiter::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	/*
	Super::ConfigurePawn(npbcController, agpPawnNew);
	agpPawnNew.bEyeTrack = bEnableEyeTracking;
	if (bUserSetSkin)
	{
		if (string(meshPawn) == "A_AA2_CharactersUS.InfantryBasicACU")
		{
			if (setPants != nullptr)
			{
				agpPawnNew.Skins[0] = setFace;
				agpPawnNew.Skins[1] = setPants;
				agpPawnNew.Skins[2] = setHands;
				agpPawnNew.Skins[3] = setShirt;
			}
		}
	}
	*/
}
