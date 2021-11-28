// All the original content belonged to the US Army


#include "NPCPlayerStartRecruiter.h"

ANPCPlayerStartRecruiter::ANPCPlayerStartRecruiter()
{

	Volume = 1;
	Radius = 64;
	Pitch = 1;
	fpPlayerDetectionRange = 200;
	//ControllerClass = class'AGP.NPCRecruiterController'
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