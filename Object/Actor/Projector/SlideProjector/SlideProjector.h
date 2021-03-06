// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "SlideProjector.generated.h"

UCLASS()
class ASlideProjector : public AProjector
{
	GENERATED_BODY()
public:
	ASlideProjector();

	UPROPERTY(EditAnywhere, Category = "aaHelp")	TArray<FString>				SlideProjectorHelp;						//var(aaHelp) const editconst FString SlideProjectorHelp[10];
	UPROPERTY(EditAnywhere)							TArray<UMaterialInstance*>	MaterialList;							//var() TArray<Material> MaterialList;
	UPROPERTY(EditAnywhere)							int32						StartMaterialIndex;						//var() int32 StartMaterialIndex;
	UPROPERTY()										int32						CurrentMaterial;						//var int32 CurrentMaterial;
	UPROPERTY()										bool						ListIsEmpty;							//var bool ListIsEmpty;

	bool SetCurrentMaterial(int32 Index);
	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
};
