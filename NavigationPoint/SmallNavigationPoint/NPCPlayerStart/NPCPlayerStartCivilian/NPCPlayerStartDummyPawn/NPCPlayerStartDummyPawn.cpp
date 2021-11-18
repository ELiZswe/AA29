// All the original content belonged to the US Army


#include "NPCPlayerStartDummyPawn.h"

ANPCPlayerStartDummyPawn::ANPCPlayerStartDummyPawn()
{


#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

	sDefaultPawnClass = "AGP_Characters.NPC_Civilian";
	//ControllerClass = class'AGP.NPCDummyPawnController'
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