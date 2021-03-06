// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "AA29/Object/Actor/Info/ZoneInfo/SkyZoneInfo/SkyZoneInfo.h"
#include "AA29/Object/I3DL2Listener/I3DL2Listener.h"

AZoneInfo::AZoneInfo()
{
	KillZ = -10000;
	AmbientSaturation = 255;
	DistanceFogColor = FColor(128, 128, 128, 0);
	DistanceFogStart = 3000;
	DistanceFogEnd = 8000;
	TexUPanSpeed = 1;
	TexVPanSpeed = 1;
	DramaticLightingScale = 1.2;
	NV_DistanceFogColor = FColor(128, 128, 128, 0);
	NV_DistanceFogStart = 3000;
	NV_DistanceFogEnd = 8000;
	LocationPriority = 2;
	bScoreHelper = true;
	bScoreDefender = true;
	//bStatic = true;
	//bNoDelete = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_ZoneInfo_Mat.S_ZoneInfo_Mat'"), NULL, LOAD_None, NULL);
}

//native(308) final iterator Function ZoneActors(class<Actor>  baseClass, Actor& Actor);
void AZoneInfo::ZoneActors(AActor* baseClass, AActor*& Actor)
{

}

void AZoneInfo::LinkToSkybox()
{
	ASkyZoneInfo* TempSkyZone = nullptr;
	/*
	ForEach AllActors(ASkyZoneInfo::StaticClass(), TempSkyZone, "None")
	{
		SkyZone = TempSkyZone;
	}
	if (Level.DetailMode == 0)
	{
		ForEach AllActors(ASkyZoneInfo::StaticClass(), TempSkyZone, "None")
		{
			if ((!TempSkyZone.bHighDetail) && (!TempSkyZone.bSuperHighDetail))
			{
				SkyZone = TempSkyZone;
			}
		}
	}
	else
	{
		if (Level.DetailMode == 1)
		{
			ForEach AllActors(ASkyZoneInfo::StaticClass(), TempSkyZone, "None")
			{
				if (!TempSkyZone.bSuperHighDetail)
				{
					SkyZone = TempSkyZone;
				}
			}
		}
		else
		{
			if (Level.DetailMode == 2)
			{
				ForEach AllActors(ASkyZoneInfo::StaticClass(), TempSkyZone, "None")
				{
					SkyZone = TempSkyZone;
				}
			}
		}
	}
	*/
}

void AZoneInfo::PreBeginPlay()
{
	//Super::PreBeginPlay();
	LinkToSkybox();
}

void AZoneInfo::ActorEntered(AActor* Other)
{
}

void AZoneInfo::ActorLeaving(AActor* Other)
{
}

void AZoneInfo::BeginPlay()
{
	Super::BeginPlay();
	if (LocationName == "")
	{
		LocationPriority = -1;
	}
	if ((!bScoreDefender) && (!bScoreHelper))
	{
		Objective = nullptr;
	}
}

AActor* AZoneInfo::GetNearbyObjective(bool bDefender)
{
	
	if ((bDefender && bScoreDefender) || ((!bDefender) && bScoreHelper))
	{
		return Objective;
	}
	else
	{
		return nullptr;
	}
}
