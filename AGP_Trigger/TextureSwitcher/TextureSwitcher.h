// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "TextureSwitcher.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATextureSwitcher : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ATextureSwitcher();

	UPROPERTY()									bool ListIsEmpty;										//var bool ListIsEmpty;
	UPROPERTY()									int32 CurrentMaterial;									//var int CurrentMaterial;
	UPROPERTY(EditAnywhere)						int32 StartMaterialIndex;								//var() int StartMaterialIndex;
	UPROPERTY(EditAnywhere)						TArray<UMaterialInstance*> MaterialList;				//var() array<Material> MaterialList;
	UPROPERTY(EditAnywhere)						UMaterialInstance* FinalBlendMaterial;					//var() FinalBlend FinalBlendMaterial;



	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);

};
