// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartSoldier.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartSoldier : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartSoldier();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSoldierAttachments")		ESoldierBackpack esbpBackpack;							//var(NPCSoldierAttachments) ESoldierBackpack esbpBackpack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSoldierAttachments")		ESoldierHeadGear eshgHeadGear;							//var(NPCSoldierAttachments) ESoldierHeadGear eshgHeadGear;
	UPROPERTY()																			TArray<ESoldierHeadGear> aeshgHeadGearTypes;			//var array<NPCPlayerStartSoldier.ESoldierHeadGear> aeshgHeadGearTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")				EReinforcementCommand epcReinforcementCommand;			//var(NPCNavigation) EReinforcementCommand epcReinforcementCommand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")				FName nameReinforcementHeadToObjectTag;					//var(NPCNavigation) name nameReinforcementHeadToObjectTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")				int32 iReinforcementWave;								//var(NPCNavigation) int iReinforcementWave;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSkins")					bool bUseRandomSkins;									//var(NPCSkins) bool bUseRandomSkins;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomShirtTextures;		//var array<String> asRandomShirtTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomPantTextures;		//var array<String> asRandomPantTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomHandTextures;		//var array<String> asRandomHandTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomFaceTextures;		//var array<String> asRandomFaceTextures;
	UPROPERTY()																			FString sDefaultPawnClass;								//var string sDefaultPawnClass;
	UPROPERTY()																			FString sDefaultMeshName;								//var string sDefaultMeshName;
};
