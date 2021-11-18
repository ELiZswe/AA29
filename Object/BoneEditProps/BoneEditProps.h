// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "BoneEditProps.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UBoneEditProps : public UObject
{
	GENERATED_BODY()
public:
	UBoneEditProps();

	UPROPERTY(EditAnywhere)			TArray<FBoneEditVars> Bones;				//var() array<BoneEditVars> Bones;
	UPROPERTY(EditAnywhere)			EBoneEditViewType PerBoneViewType;			//var() EBoneEditViewType PerBoneViewType;
	UPROPERTY(EditAnywhere)			bool HideZeroRadiusBones;					//var() bool HideZeroRadiusBones;
	UPROPERTY()						bool OldHideZeroRadiusBones;				//var const bool OldHideZeroRadiusBones;
	UPROPERTY()						EBoneEditViewType OldPerBoneViewType;		//var const EBoneEditViewType OldPerBoneViewType;
	UPROPERTY()						int32 OldArrayCount;						//var const int OldArrayCount;
	UPROPERTY()						int32 WBrowserAnimationPtr;					//var const int WBrowserAnimationPtr;

};
