// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "AA29/MyEnums.h"
#include "SoldierClass.generated.h"

class AAI_Primitive;
class AAGP_Weapon;
class AAGP_Pawn;
class AInventory;

UCLASS()
class ASoldierClass : public AAI_Primitive
{
	GENERATED_BODY()
public:
	ASoldierClass();

	UPROPERTY()		TArray<FString>					WM_Override;				//var string WM_Override;
	UPROPERTY()		FString							_ShortName;					//var string _ShortName;
	UPROPERTY()		float							nativeBonus;				//var float nativeBonus;
	UPROPERTY()		EWeaponType						nativeWeapon;				//var Weapon.EWeaponType nativeWeapon;
	UPROPERTY()		TArray<FString>							MILESEquipment;				//var string MILESEquipment;
	UPROPERTY()		TArray<TSubclassOf<AInventory>> ClassEquipment;				//var string ClassEquipment;
	UPROPERTY()		float							fOriginalEndurance;			//var float fOriginalEndurance;
	UPROPERTY()		float							fOriginalAgility;			//var float fOriginalAgility;
	UPROPERTY()		float							fOriginalStrength;			//var float fOriginalStrength;	
	UPROPERTY()		float							fOriginalSpeed;				//var float fOriginalSpeed;
	UPROPERTY()		TSubclassOf<AAGP_Pawn>			myPawn;						//var AGP_Pawn myPawn;

	FString GetClassID();
	void PreBeginPlay();
	void adjustAttributes(ASoldierClass* LastClass);
	virtual void addClassInventory(bool bMaybeSkip);
	UClass* GetAlternateClass();
	bool AddBinocs();
	void addTeamInventory();
	void addPSInventory();
	bool IsInLoadout(AInventory* InventoryClass);
	virtual float WeaponEffectivenessBonus(AAGP_Weapon* W);
	bool IsBonusEquivalent(EWeaponType t1, EWeaponType t2);
};
