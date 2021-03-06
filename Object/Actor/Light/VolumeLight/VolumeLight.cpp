// All the original content belonged to the US Army

#include "AA29/Object/Actor/Light/VolumeLight/VolumeLight.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

AVolumeLight::AVolumeLight()
{
	SpriteNum = 5;
	bStartOn = true;
	bSpriteFade = true;
	SpriteScaleBegin = 0.5;
	SpriteScaleEnd = 1;
	LightDistance = 256;
	SpriteFadeBegin = 255;
	bStatic = false;
	bNoDelete = false;
	//bAcceptsProjectors = false;
	//bMovable = true;
	//bCanTeleport = true;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	bDirectional = true;
}

void AVolumeLight::PreBeginPlay()
{
	int32 i = 0;
	float NewDrawScale = 0;
	float Radius = 0;
	/*
	SS.Num() = SpriteNum;
	for (i = 0; i < SpriteNum; i++)
	{
		SS[i].Sprite = Spawn('SpriteSlave');
		SS[i].Sprite.Texture = SpriteTexture;
		SS[i].Sprite.Style = SpriteStyle;
		if (bSpriteFade)
		{
			SS[i].Sprite.bVertexColors = true;
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

FVector AVolumeLight::GetNewLocation(float Rad)
{
	//return Location + Rad * Normal(Vector(Rotation));
	return GetActorLocation();    //FAKE   /EliZ
}

void AVolumeLight::BeginPlay()
{
	InitialBrightness = LightBrightness;
	if (bStartOn)
	{
		Activate(true);
	}
	else
	{
		Activate(false);
	}
}

void AVolumeLight::Tick(float DeltaTime)
{
	float Radius = 0;
	int32 i = 0;
	AActor* A = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0,0,0);
	/*
	if (bActorsBlock)
	{
		WaitTime += DeltaTime;
		if (WaitTime > 0.05 + FMath::FRand() * 0.05)
		{
			WaitTime = 0;
			A = Trace(HitLocation, HitNormal, Location, SS[SpriteNum - 1].Sprite->GetActorLocation(), true);
			if (A != nullptr && !A->IsA(ALevelInfo::StaticClass()))
			{
				for (i = 0; i < SpriteNum; i++)
				{
					if (VSize(Location - SS[i].Sprite.Location) + 32 > VSize(Location - HitLocation))
					{
						DoFade(SS[i], true);
					}
					else
					{
						DoFade(SS[i], false);
					}
				}
			}
			else
			{
				for (i = 0; i < SpriteNum; i++)
				{
					DoFade(SS[i], false);
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
	if (FadeOut)
	{
		SetFade(SSprite, SSprite.MinFadeValue);
	}
	else
	{
		SetFade(SSprite, SSprite.MaxFadeValue);
	}
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
	int32 i = 0;
	if (bEnable)
	{
		bEnabled = true;
		LightBrightness = InitialBrightness;
		for (i = 0; i < SpriteNum; i++)
		{
			SS[i].Sprite.bHidden = false;
		}
	}
	else
	{
		bEnabled = false;
		LightBrightness = 0;
		for (i = 0; i < SpriteNum; i++)
		{
			SS[i].Sprite.bHidden = true;
		}
	}
	*/
}

void AVolumeLight::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bEnabled)
	{
		Activate(false);
	}
	else
	{
		Activate(true);
	}
}
