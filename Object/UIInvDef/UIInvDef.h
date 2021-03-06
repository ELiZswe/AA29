// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "UIInvDef.generated.h"

UCLASS()
class UUIInvDef : public UObject
{
	GENERATED_BODY()
public:
	UUIInvDef();

	UPROPERTY()			TArray<FInvDefStruct>	_InvDef;

	FString GetItemNameFromID(int32 Index); 
	int32 GetItemParam(int32 Index);
	float GetItemWeight(int32 Index);
	int32 GetItemSize(int32 Index);
	UMaterialInstance* GetItemTexture(int32 Index);
	FInvDefStruct GetItem(int32 Index);
};
