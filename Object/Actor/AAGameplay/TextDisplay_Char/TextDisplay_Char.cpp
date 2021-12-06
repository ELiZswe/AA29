// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/TextDisplay_Char/TextDisplay_Char.h"

ATextDisplay_Char::ATextDisplay_Char()
{
	DrawType = EDrawType::DT_StaticMesh;
	if (StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/misc/fx_misc_sheet.fx_misc_sheet'"), NULL, LOAD_None, NULL));
	}

	SetActorEnableCollision(false);

	//bUseDynamicLights = false;
	//bUnlit = true;
	//bShadowCast = false;
	//bStaticLighting = true;
}