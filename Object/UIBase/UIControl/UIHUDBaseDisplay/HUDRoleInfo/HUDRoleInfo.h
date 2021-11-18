// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDRoleInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDRoleInfo : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDRoleInfo();

	UPROPERTY()										UMaterialInstance* _roleTexture;			//var Texture _roleTexture;


	void Destroyed();
	void Draw(UCanvas* Canvas);
	
};
