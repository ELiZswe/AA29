// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartCivilian/NPCPlayerStartDummyPawn/NPCPlayerStartDummyPawn.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCDummyPawnController/NPCDummyPawnController.h"

ANPCPlayerStartDummyPawn::ANPCPlayerStartDummyPawn()
{

#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

	sDefaultPawnClass = "AGP_Characters.NPC_Civilian";
	//ControllerClass = ANPCDummyPawnController::StaticClass()
	fpNPCHearingRadius = 0;
	fpNPCVisionConeAngle = 0;
	fpNPCMaxVisualRange = 0;
	bStartAsDummyPawn = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNPCBlue.S_PNPCBlue'"), NULL, LOAD_None, NULL);
#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA
}

AAGP_Pawn* ANPCPlayerStartDummyPawn::GetPawnSpawnClass()
{
	/*
	if (PawnSpawnClass == nullptr)
	{
		return class<AGP_Pawn>(DynamicLoadObject(sDefaultPawnClass, Class'Class'));
	}
	else
	{
		return PawnSpawnClass;
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}

void ANPCPlayerStartDummyPawn::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
}
