// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDBodyInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDBodyInfo : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDBodyInfo();

	UPROPERTY()										int32 ProneY;									//var int ProneY;
	UPROPERTY()										int32 ProneX;									//var int ProneX;
	UPROPERTY()										UMaterialInstance* _BleedingSlowTexture;		//var Material _BleedingSlowTexture;
	UPROPERTY()										UMaterialInstance* _BleedingTexture;			//var Material _BleedingTexture;
	UPROPERTY()										UMaterialInstance* _SprintFillTexture;			//var Texture _SprintFillTexture;
	UPROPERTY()										UMaterialInstance* _SprintTexture;				//var Texture _SprintTexture;
	UPROPERTY()										UMaterialInstance* _PassengerFillTexture;		//var Texture _PassengerFillTexture;
	UPROPERTY()										UMaterialInstance* _CROWSFillTexture;			//var Texture _CROWSFillTexture;
	UPROPERTY()										UMaterialInstance* _DriverFillTexture;			//var Texture _DriverFillTexture;
	UPROPERTY()										UMaterialInstance* _PassengerTexture;			//var Texture _PassengerTexture;
	UPROPERTY()										UMaterialInstance* _CROWSTexture;				//var Texture _CROWSTexture;
	UPROPERTY()										UMaterialInstance* _DriverTexture;				//var Texture _DriverTexture;
	UPROPERTY()										TArray<UMaterialInstance*> _SlowFillTextures;	//var Texture _SlowFillTextures;
	UPROPERTY()										TArray<UMaterialInstance*> _FastFillTextures;	//var Texture _FastFillTextures;
	UPROPERTY()										TArray<UMaterialInstance*> _SlowTextures;		//var Texture _SlowTextures;
	UPROPERTY()										TArray<UMaterialInstance*> _FastTextures;		//var Texture _FastTextures;

	void Destroyed();
	void Draw(UCanvas* Canvas);


};
