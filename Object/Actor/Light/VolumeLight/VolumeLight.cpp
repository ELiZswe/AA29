// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/VolumeLight/VolumeLight.h"

AVolumeLight::AVolumeLight()
{
	SpriteNum = 5;
	bStartOn = true;
	bSpriteFade = true;
	SpriteScaleBegin = 0.5;
	SpriteScaleEnd = 1;
	LightDistance = 256;
	SpriteFadeBegin = 255;
	//bStatic = False;
	//bNoDelete = False;
	//bAcceptsProjectors = False;
	//bMovable = True;
	//bCanTeleport = True;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
	//bBlockZeroExtentTraces = False;
	//bBlockNonZeroExtentTraces = False;
	//bBlockBulletTraces = False;
	//bDirectional = True;
}

void AVolumeLight::PreBeginPlay()
{
	/*
	local int i;
	local float NewDrawScale;
	local float Radius;
	SS.Length = SpriteNum;
	for (i = 0; i < SpriteNum; i++)
	{
		SS[i].Sprite = Spawn('SpriteSlave');
		SS[i].Sprite.Texture = SpriteTexture;
		SS[i].Sprite.Style = SpriteStyle;
		if (bSpriteFade)
		{
			SS[i].Sprite.bVertexColors = True;
			SS[i].MaxFadeValue = SpriteFadeBegin - SpriteFadeBegin - SpriteFadeEnd / SpriteNum * i;
			SS[i].MinFadeValue = SS[i].MaxFadeValue * MinFadeMultiplier;
			SetFade(SS[i], SS[i].MaxFadeValue);
		}
		Radius = LightDistance / SpriteNum * i;
		SS[i].Sprite.SetLocation(GetNewLocation(Radius));
		NewDrawScale = SpriteScaleBegin + SpriteScaleEnd - SpriteScaleBegin / SpriteNum * i;
		SS[i].Sprite.SetDrawScale(NewDrawScale);
	}
	*/
}

void AVolumeLight::GetNewLocation(float Rad)
{
	//Return Location + Rad * Normal(Vector(Rotation));
}

void AVolumeLight::BeginPlay()
{
	/*
	InitialBrightness = LightBrightness;
	if (bStartOn)
	{
		Activate(True);
	}
	else
	{
		Activate(False);
	}
	*/
}

void AVolumeLight::Tick(float DeltaTime)
{
	/*
	local float Radius;
	local int i;
	local Actor A;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	if (bActorsBlock)
	{
		WaitTime += DeltaTime;
		if (WaitTime > 0.05 + FRand() * 0.05)
		{
			WaitTime = 0;
			A = Trace(HitLocation, HitNormal, Location, SS[SpriteNum - 1].Sprite.Location, True);
			if (A != None && !A.IsA('LevelInfo'))
			{
				for (i = 0; i < SpriteNum; i++)
				{
					if (VSize(Location - SS[i].Sprite.Location) + 32 > VSize(Location - HitLocation))
					{
						DoFade(SS[i], True);
					}
					else
					{
						DoFade(SS[i], False);
					}
				}
			}
			else
			{
				for (i = 0; i < SpriteNum; i++)
				{
					DoFade(SS[i], False);
				}
			}
		}
	}
	if (bSpriteDynamic)
	{
		for (i = 0; i < SpriteNum; i++)
		{
			Radius = LightDistance / SpriteNum * i;
			SS[i].Sprite.SetLocation(GetNewLocation(Radius));
		}
		LastRotation = Rotation;
	}
	*/
}
void AVolumeLight::DoFade(FSprite SSprite, bool FadeOut)
{
	/*
	if (FadeOut)
	{
		SetFade(SSprite, SSprite.MinFadeValue);
	}
	else
	{
		SetFade(SSprite, SSprite.MaxFadeValue);
	}
	*/
}

void AVolumeLight::SetFade(FSprite &SSprite, float Value)
{
	/*
	if (SpriteStyle == 6)
	{
		SSprite.Sprite.ActorVertexColors.A = Value;
	}
	else
	{
		SSprite.Sprite.ActorVertexColors.R = Value;
		SSprite.Sprite.ActorVertexColors.G = Value;
		SSprite.Sprite.ActorVertexColors.B = Value;
	}
	*/
}

void AVolumeLight::Activate(bool bEnable)
{
	/*
	local int i;
	if (bEnable)
	{
		bEnabled = True;
		LightBrightness = InitialBrightness;
		for (i = 0; i < SpriteNum; i++)
		{
			SS[i].Sprite.bHidden = False;
		}
	}
	else
	{
		bEnabled = False;
		LightBrightness = 0;
		for (i = 0; i < SpriteNum; i++)
		{
			SS[i].Sprite.bHidden = True;
		}
	}
	*/
}

void AVolumeLight::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (bEnabled)
	{
		Activate(False);
	}
	else
	{
		Activate(True);
	}
	*/
}