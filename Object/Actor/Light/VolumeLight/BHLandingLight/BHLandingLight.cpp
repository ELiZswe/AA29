// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/VolumeLight/BHLandingLight/BHLandingLight.h"

ABHLandingLight::ABHLandingLight()
{
	//SpriteNum = 15;
	//bSpriteDynamic = true;
	//SpriteScaleBegin = 0.2;
	//SpriteScaleEnd = 1.2;
	//SpriteFadeBegin = 16;
	//SpriteTexture = Texture'T_AA2_FX.Corona.fx_whitespot_alpha';
	//SpriteStyle = 6;
	MinCoronaSize = 44;
	MaxCoronaSize = 66;
	//LightHue = 177;
	//LightSaturation = 233;
	//LightBrightness = 0;
	//LightRadius = 8;
	//DrawType = 2;
	//bActorShadows = false;
	bCorona = true;
	//bLightingVisibility = false;
	//fCoronaClampDistance = 1024;
	//fCoronaNearClampDistance = 512;
	//bHidden = false;
	//bDynamicLight = true;
	//Texture = Texture'Engine.S_VolumeLight';
	//Skins(0) = Texture'T_AA2_FX.Coronas.fx_cor_2tonecorona';
}


void ABHLandingLight::TurnOn()
{
	//bCorona = true;
	//Activate(True);
}
void ABHLandingLight::TurnOff()
{
	//bCorona = False;
	//Activate(False);
}