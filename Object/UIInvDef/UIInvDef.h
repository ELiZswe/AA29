// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "UIInvDef.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIInvDef : public UObject
{
	GENERATED_BODY()
public:
	UUIInvDef();

	UPROPERTY()										TArray<FInvDefStruct> _InvDef;					//var UIInvDef.InvDefStruct _InvDef;

	void GetItemNameFromID(int32 Index); 
	void GetItemParam(int32 Index);
	void GetItemWeight(int32 Index);
	void GetItemSize(int32 Index);
	void GetItemTexture(int32 Index);
	void GetItem(int32 Index);

};
