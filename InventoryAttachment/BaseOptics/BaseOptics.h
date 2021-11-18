// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/InventoryAttachment.h"
#include "BaseOptics.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABaseOptics : public AInventoryAttachment
{
	GENERATED_BODY()
public:
	ABaseOptics();

	UPROPERTY()		UTexture2D* Icon;			//var Material Icon;
	UPROPERTY()		bool bIsActive;				//var bool bIsActive;
	virtual void Toggle();
	virtual void Activate();
	virtual void Deactivate();
	virtual void IsActive();
	virtual void CleanUp();
	virtual void StatusChanged();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};

