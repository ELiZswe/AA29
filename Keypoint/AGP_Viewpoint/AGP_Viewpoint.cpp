// All the original content belonged to the US Army

#include "AGP_Viewpoint.h"

//Sets the default values
AAGP_Viewpoint::AAGP_Viewpoint()
{
	Description = (TEXT("Default Description"));
	bSpectatorViewpoint = true;

	//Texture = Texture'Engine.tAGP_Viewpoint'
	//Texture = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Breathe/BreatheIn.BreatheIn"), NULL, LOAD_None, NULL);
	//bDirectional = true;

}
void AAGP_Viewpoint::BeginPlay()
{
	Super::BeginPlay();
}