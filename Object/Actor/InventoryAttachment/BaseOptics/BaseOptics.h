// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"
#include "BaseOptics.generated.h"

UCLASS()
class ABaseOptics : public AInventoryAttachment
{
	GENERATED_BODY()
public:
	ABaseOptics();

	UPROPERTY()		UTexture2D* Icon;			//var Material Icon;
	UPROPERTY()		bool bIsActive;				//var bool bIsActive;

	void Toggle();
	void Activate();
	void Deactivate();
	bool IsActive();
	void CleanUp();
	void StatusChanged();
	void DoAttachStuffWhichShouldBeDoneInInventory();
	void NotifyBRoll(bool bRoll);

protected:
	
	virtual void BeginPlay() override;
};

