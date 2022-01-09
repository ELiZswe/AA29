// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_CLUpack.generated.h"

UCLASS()
class AAttch_CLUpack : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_CLUpack();

	void SetUpCLUPack(APawn* p);
	void RemoveCLUPack();
};
