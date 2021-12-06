// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/RadarImageVolume/RadarImageVolume.h"

ARadarImageVolume::ARadarImageVolume()
{

}

UMaterialInstance* ARadarImageVolume::GetRadarImage(FVector PlayerLocation)
{
	int32 i;
	for (i = 0; i < ImageStrata.Num()-1; i++)
	{
		if (PlayerLocation.Z >= ImageStrata[i].LowerBound && PlayerLocation.Z < ImageStrata[i].UpperBound)
		{
			return ImageStrata[i].RadarImage;
		}
	}
	return nullptr;
}
UMaterialInstance* ARadarImageVolume::GetBestRadarImage(APawn* p)
{
	UMaterialInstance* BestImage = nullptr;
	ARadarImageVolume* ImageVolume = nullptr;
	int BestImageVolumePriority = 0;
	/*
	ForEach p.TouchingActors('RadarImageVolume', ImageVolume)
	{
		if (ImageVolume == nullptr)
		{
		continue;

		}
		else
		{
			if (BestImage == nullptr || BestImageVolumePriority < ImageVolume.ImageVolumePriority)
			{
				BestImage = ImageVolume.GetRadarImage(p.Location);
				BestImageVolumePriority = ImageVolume.ImageVolumePriority;
			}
		}
	}
	*/

	return BestImage;
	
}
bool ARadarImageVolume::ShouldDisableRadar(APawn* p)
{
	/*
	ARadarImageVolume* ImageVolume;
	ForEach p.TouchingActors('RadarImageVolume', ImageVolume)
	{
		if (ImageVolume.bDisableRadarInVolume)
		{
			return true;
		}
	}
	*/
	return false;
}