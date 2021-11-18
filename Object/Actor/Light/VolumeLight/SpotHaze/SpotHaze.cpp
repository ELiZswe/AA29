// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/VolumeLight/SpotHaze/SpotHaze.h"

ASpotHaze::ASpotHaze()
{
	SpriteNum = 25;
	bSpriteDynamic = true;
	SpriteScaleEnd = 2;
	LightDistance = 512;
	SpriteFadeBegin = 32;
	//SpriteTexture = Texture'T_AA2_FX.Corona.fx_whitespot_alpha';
	//SpriteStyle = 6;
	MinCoronaSize = 64;
	MaxCoronaSize = 96;
	//LightBrightness = 0;
	//LightRadius = 8;
	//DrawType = 2;
	//bActorShadows = False;
	bCorona = true;
	//bLightingVisibility = False;
	//fCoronaClampDistance = 1024;
	//fCoronaNearClampDistance = 512;
	//bHidden = False;
	//bDynamicLight = True;
	//Texture = Texture'Engine.S_VolumeLight';
	//Skins(0) = Texture'T_AA2_FX.Coronas.fx_cor_01';
	//bHardAttach = True;
}


void ASpotHaze::BeginPlay()
{
	Super::BeginPlay();
}