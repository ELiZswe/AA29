// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"

//Sets the default values
AAGP_Viewpoint::AAGP_Viewpoint()
{
	bSpectatorViewpoint = true;
	Description = "Default Description";
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/tAGP_Viewpoint_Mat.tAGP_Viewpoint_Mat'"), NULL, LOAD_None, NULL);
	//bDirectional = true;
}
void AAGP_Viewpoint::BeginPlay()
{
	Super::BeginPlay();
}

void AAGP_Viewpoint::PreBeginPlay()
{
	//Super::PreBeginPlay();
	//Level.AddViewpoint(this);
	if (TeamNumber > 1)
	{
		bFriendlyOnly = false;
	}
}
