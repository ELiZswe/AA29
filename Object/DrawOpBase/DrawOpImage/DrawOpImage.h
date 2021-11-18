// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DrawOpBase/DrawOpBase.h"
#include "DrawOpImage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDrawOpImage : public UDrawOpBase
{
	GENERATED_BODY()
public:
	UDrawOpImage();

	UPROPERTY()		UMaterialInstance* Image;		//var Material Image;
	UPROPERTY()		uint8 ImageStyle;				//var uint8 ImageStyle;
	UPROPERTY()		float SubX;						//var float SubX;
	UPROPERTY()		float SubY;						//var float SubY;
	UPROPERTY()		float SubXL;					//var float SubXL;
	UPROPERTY()		float SubYL;					//var float SubYL;
	UPROPERTY()		bool Text;						//var deprecated bool bStretch;

	void Draw(UCanvas* Canvas);
};
