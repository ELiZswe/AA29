// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartSoldier.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartSoldier : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartSoldier();

	UPROPERTY(EditAnywhere, Category = "NPCSoldierAttachments")		ESoldierBackpack esbpBackpack;							//var(NPCSoldierAttachments) ESoldierBackpack esbpBackpack;
	UPROPERTY(EditAnywhere, Category = "NPCSoldierAttachments")		ESoldierHeadGear eshgHeadGear;							//var(NPCSoldierAttachments) ESoldierHeadGear eshgHeadGear;
	UPROPERTY()																			TArray<ESoldierHeadGear> aeshgHeadGearTypes;			//var array<NPCPlayerStartSoldier.ESoldierHeadGear> aeshgHeadGearTypes;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				EReinforcementCommand epcReinforcementCommand;			//var(NPCNavigation) EReinforcementCommand epcReinforcementCommand;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				FName nameReinforcementHeadToObjectTag;					//var(NPCNavigation) name nameReinforcementHeadToObjectTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				int32 iReinforcementWave;								//var(NPCNavigation) int iReinforcementWave;
	UPROPERTY(EditAnywhere, Category = "NPCSkins")					bool bUseRandomSkins;									//var(NPCSkins) bool bUseRandomSkins;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomShirtTextures;		//var TArray<FString> asRandomShirtTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomPantTextures;		//var TArray<FString> asRandomPantTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomHandTextures;		//var TArray<FString> asRandomHandTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomFaceTextures;		//var TArray<FString> asRandomFaceTextures;
	UPROPERTY()																			FString sDefaultPawnClass;								//var string sDefaultPawnClass;
	UPROPERTY()																			FString sDefaultMeshName;								//var string sDefaultMeshName;

	void BeginPlay();
	AAGP_Pawn* GetPawnSpawnClass();
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
	void ConfigureRandomSkins(AAGP_Pawn* agpPawnNew);
};
