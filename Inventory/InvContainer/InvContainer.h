// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Inventory.h"
#include "AA29/Inventory/Ammunition/Ammunition.h"
#include "InvContainer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInvContainer : public AInventory
{
	GENERATED_BODY()
public:
	AInvContainer();


	UPROPERTY()								AInvContainer* nextContainer;					//var InvContainer nextContainer;
	UPROPERTY()								TSubclassOf<AInventory> _headItem;				//var Inventory _headItem;
	UPROPERTY()								TSubclassOf<AInventory> _currentItem;			//var Inventory _currentItem;
	UPROPERTY()								FString thename;								//var string thename;
	UPROPERTY()								int32 _iUsedCapacity;							//var int _iUsedCapacity;
	UPROPERTY()								int32 _iMaxCapacity;							//var int _iMaxCapacity;

	virtual bool IsFull();
	virtual bool isEmpty();
	virtual void Destroyed();
	virtual int32 getMaxCapcity();
	virtual TSubclassOf<AInventory> getFirstItem();
	virtual TSubclassOf<AInventory> getNextItem();
	virtual int32 getUsedCapacity();
	virtual TSubclassOf<AInventory> getItemAtIndex(int32 Index);
	virtual TSubclassOf<AInventory> getCurrentItem();
	virtual bool FindInventoryItem(TSubclassOf<AInventory> p_item);
	virtual void setCurrentItem(TSubclassOf<AInventory> p_item);
	virtual bool DeleteItem(TSubclassOf<AInventory> p_item);
	virtual void dropCurrentItem();
	virtual bool ItemAllowable(TSubclassOf<AInventory> p_item);
	virtual bool FindInventorySpace(TSubclassOf<AInventory> p_item);
	virtual bool addItem(TSubclassOf<AInventory> p_item);
	virtual bool swapItems(TSubclassOf<AInventory> new_item, TSubclassOf<AInventory> old_item);
	virtual int32 CountItems();
	virtual void addLastItem(TSubclassOf<AInventory> p_item);
	virtual void NextInventoryItem();
	virtual void FindInventoryType(TSubclassOf<AInventory>  invtype);
	virtual void CountInventoryType(TSubclassOf<AInventory> invtype);
	virtual int32 AbsorbDamage(int32 Damage, UaDamageType DamageType, FVector HitLocation);
	virtual void FindAmmo(AAmmunition* Ammo);
	virtual void toString();
	virtual void SetMaxCapacity(int32 capacity);
	virtual float GetWeight();
	virtual void DumpContainer();

};
