// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/VolumeLight/HeadLight/HeadLight.h"

AHeadLight::AHeadLight()
{
	SpriteNum = 15;
	bSpriteDynamic = true;
	SpriteScaleBegin = 0.4;
	SpriteScaleEnd = 0.8;
	SpriteFadeBegin = 32;
	//SpriteTexture = Texture'T_AA2_FX.Corona.fx_whitespot_alpha';
	SpriteStyle = ERenderStyle::STY_Alpha;
	MinCoronaSize = 32;
	MaxCoronaSize = 64;
	//LightBrightness = 0;
	//LightRadius = 8;
	//DrawType = 2;
	//bActorShadows = False;
	//bLightingVisibility = False;
	//bHidden = False;
	//Texture = Texture'Engine.S_VolumeLight';
	//Skins(0) = Texture'T_AA2_FX.Coronas.fx_cor_01';
}