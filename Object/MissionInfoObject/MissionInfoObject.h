// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MissionInfoObject.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UMissionInfoObject : public UObject
{
	GENERATED_BODY()
public:
	UMissionInfoObject();

	UPROPERTY()							int32		TourID;						//var int32 TourID;
	UPROPERTY()							int32		MissionID;					//var int32 MissionID;
	UPROPERTY()							FString		MapFilename;				//var FString MapFilename;
	UPROPERTY()							FString		MBSTitle;					//var FString MBSTitle;
	UPROPERTY()							FString		MissionImage;				//var FString MissionImage;
};
