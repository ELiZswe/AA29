// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "AARealHeroStats.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAARealHeroStats : public UObject
{
	GENERATED_BODY()
public:
	UAARealHeroStats();

	UPROPERTY()											TArray<FRibbonRowInfo> RibbonRows;	//var array<RibbonRowInfo> RibbonRows;
	UPROPERTY()											TArray<FBadgeInfo> ACUBadges;		//var array<BadgeInfo> ACUBadges;
	UPROPERTY()											UMaterialInstance* ACUUniform;		//var Material ACUUniform;
	UPROPERTY()											TArray<FBadgeInfo> ClassABadges;	//var array<BadgeInfo> ClassABadges;
	UPROPERTY()											UMaterialInstance* ClassAUniform;	//var Material ClassAUniform;
	UPROPERTY()											TArray<FString> BioParagraphs;		//var array<String> BioParagraphs;
	UPROPERTY()											FString Training;					//var string Training;
	UPROPERTY()											FString Hometown;					//var string Hometown;
	UPROPERTY()											FString Unit;						//var string Unit;
	UPROPERTY()											FString MOS;						//var string MOS;
	UPROPERTY()											FString HeroNameAndRank;			//var string HeroNameAndRank;
	UPROPERTY()											FString rank;						//var string rank;
	UPROPERTY()											FString HeroName;					//var string HeroName;
	UPROPERTY()											FString ShortName;					//var string ShortName;
	UPROPERTY()											UMaterialInstance* Headshot;		//var Material Headshot;
};
