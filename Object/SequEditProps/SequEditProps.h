// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "SequEditProps.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USequEditProps : public UObject
{
	GENERATED_BODY()
public:
	USequEditProps();

	UPROPERTY(EditAnywhere, Category = "Groups")						TArray<FName> Groups;						//var(Groups) array<name> Groups;
	UPROPERTY(EditAnywhere, Category = "SequenceProperties")			FName SequenceName;							//var(SequenceProperties) name SequenceName;
	UPROPERTY(EditAnywhere, Category = "SequenceProperties")			float Compression;							//var(SequenceProperties) float Compression;
	UPROPERTY(EditAnywhere, Category = "SequenceProperties")			float Rate;									//var(SequenceProperties) float Rate;
	UPROPERTY(EditAnywhere, Category = "Adjust")						FRotator Rotation;							//var(Adjust) Object.Rotator Rotation;
	UPROPERTY(EditAnywhere, Category = "Adjust")						FVector Translation;						//var(Adjust) Object.Vector Translation;
	UPROPERTY()															Fpointer WBrowserAnimationPtr;				//var const transient pointer WBrowserAnimationPtr;
};
