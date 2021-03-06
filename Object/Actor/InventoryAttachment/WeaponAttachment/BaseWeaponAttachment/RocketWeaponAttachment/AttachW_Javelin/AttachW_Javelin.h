// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/RocketWeaponAttachment.h"
#include "AttachW_Javelin.generated.h"

class AInventory;
UCLASS()
class AAttachW_Javelin : public ARocketWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttachW_Javelin();
	
	UPROPERTY()		float	fSizeToGrow;						//var float fSizeToGrow;
	UPROPERTY()		int32	TimeToShrink;						//var int TimeToShrink;
	UPROPERTY()		int32	TimeToGrow;							//var int TimeToGrow;
	UPROPERTY()		float	MinSize;							//var float MinSize;
	UPROPERTY()		float	MaxSize;							//var float MaxSize;
	UPROPERTY()		FName	ReloadAnimation;					//var name ReloadAnimation;
	UPROPERTY()		FName	EmptyTubeUnloadAnimation;			//var name EmptyTubeUnloadAnimation;
	UPROPERTY()		FName	FullTubeUnloadAnimation;			//var name FullTubeUnloadAnimation;
	UPROPERTY()		FName	CurrentAnimation;					//var name CurrentAnimation;
	UPROPERTY()		FName	PawnReloadAnimation;				//var name PawnReloadAnimation;
	UPROPERTY()		FName	PawnEmptyTubeUnloadAnimation;		//var name PawnEmptyTubeUnloadAnimation;
	UPROPERTY()		FName	PawnFullTubeUnloadAnimation;		//var name PawnFullTubeUnloadAnimation;
	UPROPERTY()		bool	bIsDetaching;						//var bool bIsDetaching;
	UPROPERTY()		bool	bTubeAttached;						//var bool bTubeAttached;

	void SetMesh();
	void SpawnAndAttachAR3P();
	void DestroyAR3P();
	bool GetbIsDetaching();
	void SetbIsDetaching(bool Detach);
	void SetbTubeAttached(bool Tube);
	uint8 AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv);
	void AttachmentAnimation();
	void PlayAttachmentReload(int32 SpecialReload);
	void Destroyed();
	FName GetAttachBoneFor(AInventory* Inv);
	FName GetPawnReloadAnimation();
	FName GetCurrentAnim();
};
