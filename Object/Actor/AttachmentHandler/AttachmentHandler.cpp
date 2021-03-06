// All the original content belonged to the US Army

#include "AA29/Object/Actor/AttachmentHandler/AttachmentHandler.h"
#include "AA29/Object/Actor/BaseModAttachment/BaseModAttachment.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"

// Sets default values
AAttachmentHandler::AAttachmentHandler()
{
	WM_Attachment.SetNum(6);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	num_mods = -1;
	AnimState = 255;
	//DrawType = 0;
	//RemoteRole = 2;
}


void AAttachmentHandler::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAttachmentHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAttachmentHandler::NotifyReplicationComplete()
{
	SetDefaultWeaponMesh(nullptr);
	SpawnModAttachments();
}

bool AAttachmentHandler::IsReplicationComplete()
{
	int32 i = 0;
	int32 found_mods = 0;
	/*
	if (AttachProxy == nullptr || AnimState == 255)
	{
		return false;
	}
	if (AttachProxy->IsA(ABaseWeaponAttachment::StaticClass()) && AttachProxy.Instigator == nullptr)
	{
		return false;
	}
	for (i = 0; i < 6; i++)
	{
		if (WM_Attachment[i] != nullptr)
		{
			found_mods++;
		}
	}
	*/
	return num_mods == found_mods;
}

void AAttachmentHandler::SetupHandler(AActor* newproxy, AActor* AttachTo, AInventory* i)
{
	/*
	AttachProxy = newproxy;
	SetBase(AttachTo);
	SetOwner(AttachTo);
	if (i != nullptr)
	{
		CopyModsFrom(i);
		if (Level.IsServer())
		{
			CountModAttachments();
		}
		else
		{
			SpawnModAttachments();
		}
	}
	*/
}

void AAttachmentHandler::SetSlotDraw(int32 Slot, bool bDraw)
{
	ABaseModAttachment* MA = nullptr;
	for (MA = ModAttachmentList; MA != nullptr; MA = MA->NextModAttachment)
	{
		if ((MA->ModSlot == Slot) && MA->bSpinnyActive)
		{
			if (bDraw)
			{
				//MA->SetDrawType(MA->Default->DrawType);
			}
			else
			{
				//MA->SetDrawType(DT_None);
			}
		}
	}
}

void AAttachmentHandler::LoadModAttachment(ABaseModAttachment* BMA, int32 Slot)
{
	ABaseModAttachment* MA = nullptr;
	bool bAlreadyExists = false;
	bool bAdjustedWeaponMesh = false;
	int32 extra_slot = 0;
	TArray<int32> bAdjustSlot = { 0,0,0,0,0 };
	/*
	WM_Attachment[Slot] = BMA;
	for (MA = ModAttachmentList; MA != nullptr; MA = MA->NextModAttachment)
	{
		if (MA->ModSlot == Slot)
		{
			if (MA->Class == BMA)
			{
				MA->bSpinnyActive = true;
				MA->NotifyAttachmentAnimation(AnimState);
				MA->SetFriendlyMesh((!bSpinnyEnemy));
				MA->NotifyAttachMod();
				//Level.SetActorLevelSkin(MA, true, special_skin_tag);
				if ((MA->WeaponMesh != nullptr) && (AttachProxy->Mesh == MA->WeaponMesh))
				{
					bAdjustedWeaponMesh = true;
				}
				//extra_slot = MA->WeaponMod.Default->FillExtraSlot;
				if (extra_slot >= 0)
				{
					bAdjustSlot[extra_slot] = 1;
					SetSlotDraw(extra_slot, false);
				}
				bAlreadyExists = true;
			}
			else
			{
				MA->bSpinnyActive = false;
				//MA->SetDrawType(DT_None);
				if (!bAdjustedWeaponMesh)
				{
					MA->NotifyDetachMod();
				}
				//extra_slot = MA->WeaponMod.Default.FillExtraSlot;
				if ((extra_slot >= 0) && (bAdjustSlot[extra_slot] == 0))
				{
					SetSlotDraw(extra_slot, true);
				}
			}
		}
	}
	if ((!bAlreadyExists) && (BMA != nullptr))
	{
		MA = SpawnSingleAttachment(Slot, bSpinnyEnemy);
		if (MA != nullptr)
		{
			MA->bSpinnyActive = true;
			MA->SetFriendlyMesh((!bSpinnyEnemy));
			Level->SetActorLevelSkin(MA, true, special_skin_tag);
			extra_slot = MA->WeaponMod.Default.FillExtraSlot;
			if (extra_slot >= 0)
			{
				SetSlotDraw(extra_slot, false);
			}
		}
	}
	*/
}

void AAttachmentHandler::CopyModsFrom(AInventory* i)
{
	AAGP_Weapon* W = nullptr;
	ABaseWeaponMod* WM = nullptr;
	W = Cast<AAGP_Weapon>(i);
	if (W == nullptr)
	{
		//DebugLog(DEBUG_Warn, "AttachmentHandler::CopyModsFrom()	Don't know what to do with no Weapon" @ FString::FromInt(i) @ FString::FromInt(W));
		Destroy();
		return;
	}
	/*
	for (WM = W->WeaponModList; WM != nullptr; WM = WM->NextWeaponMod)
	{
		WM_Attachment[WM->ModSlot] = WM->GetModAttachment();
	}
	*/
	AnimState = 0;
	if (W->IsSuppressed())
	{
		//AnimState = uint8((AnimState | 4));
	}
}

void AAttachmentHandler::CountModAttachments()
{
	/*
	int32 i = 0;
	if (!Level.IsServer())
	{
		return;
	}
	num_mods = 0;
	for (i = 0; i < 6; i++)
	{
		if (WM_Attachment[i] != nullptr)
		{
			num_mods++;
		}
	}
	*/
}
bool AAttachmentHandler::IsEnemy()
{
	/*
	if (AttachProxy->IsA(ABaseWeaponAttachment::StaticClass()))
	{
		if (Cast<ABaseWeaponAttachment>(AttachProxy).bDontSwapMeshes)
		{
			return false;
		}
		else
		{
			if (AttachProxy.Instigator != nullptr)
			{
				return !Level.IsUSSkin(AttachProxy.Instigator.bClientFriend);
			}
			else
			{
				DebugLog(DEBUG_Warn, "AttachmentHandler::IsEnemy()	Got here with no Instigator for the AttachProxy.");
				return false;
			}
		}
	}
	else
	{
		if (AttachProxy->IsA(APickup::StaticClass()))
		{
			return Cast<APickup>(AttachProxy).UseEnemyClass();
		}
		else
		{
			DebugLog(DEBUG_Inv, "AttachmentHandler::IsEnemy()	Don't know how to tell with Proxy(" @ AttachProxy @ ")");
			return false;
		}
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AAttachmentHandler::InvalidAttachProxy()
{
	/*
	if (AttachProxy->IsA(ABaseWeaponAttachment::StaticClass()) && AttachProxy.Instigator == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;   //FAKE   /EliZ
}

void AAttachmentHandler::SpawnModAttachments()
{
	int32 i = 0;
	bool bIsEnemy = false;
	if (!InvalidAttachProxy())
	{
		bIsEnemy = IsEnemy();
		for (i = 0; i < 6; i++)
		{
			SpawnSingleAttachment(i, bIsEnemy);
		}
	}
	if (AttachProxy->IsA(ABaseWeaponAttachment::StaticClass()))
	{
		Cast<ABaseWeaponAttachment>(AttachProxy)->AttachHandler = this;
		NotifyModAttachmentAnimation(Cast<ABaseWeaponAttachment>(AttachProxy)->AnimState);
	}
}

ABaseModAttachment* AAttachmentHandler::SpawnSingleAttachment(int32 Slot, bool bIsEnemy)
{
	ABaseModAttachment* MA = nullptr;
	if (WM_Attachment[Slot] != nullptr)
	{
		//MA = Spawn(WM_Attachment[Slot], this);
		//AttachProxy->AttachToBone(MA, MA->GetAttachBone(Slot));
		//MA->SetDrawScale(AttachProxy->DrawScale);
		AddModAttachment(MA);
		MA->ModSlot = Slot;
		MA->SetFriendlyMesh(!bIsEnemy);
		//Level.SetActorLevelSkin(MA, !bIsEnemy, special_skin_tag);
		MA->NotifyAttachMod();
		MA->NotifyAttachmentAnimation(AnimState);
		//MA->bUnlit = bUnlit;
	}
	return MA;
}

void AAttachmentHandler::SetSpecialSkinTag(FString skin_tag)
{
	ABaseModAttachment* MA = nullptr;
	special_skin_tag = skin_tag;
	for (MA = ModAttachmentList; MA != nullptr; MA = MA->NextModAttachment)
	{
		//Level.SetActorLevelSkin(MA, true, special_skin_tag);
	}
}

void AAttachmentHandler::SetDefaultWeaponMesh(UStaticMesh* NewDefaultWeaponMesh)
{
	if (NewDefaultWeaponMesh == nullptr)
	{
		//DefaultWeaponMesh = AttachProxy->Default->Mesh;
	}
	else
	{
		DefaultWeaponMesh = NewDefaultWeaponMesh;
	}
}
void AAttachmentHandler::SetWeaponMesh(UStaticMesh* NewWeaponMesh)
{
	if (NewWeaponMesh == nullptr)
	{
		NewWeaponMesh = DefaultWeaponMesh;
	}
	//AttachProxy->LinkMesh(NewWeaponMesh);
	//Level.SetActorLevelSkin(AttachProxy, (!IsEnemy()), special_skin_tag);
}

void AAttachmentHandler::NotifyModAttachmentAnimation(uint8 NewAnimState)
{
	ABaseModAttachment* BM = nullptr;
	AnimState = NewAnimState;
	for (BM = ModAttachmentList; BM != nullptr; BM = BM->NextModAttachment)
	{
		BM->NotifyAttachmentAnimation(AnimState);
	}
}

void AAttachmentHandler::AddModAttachment(ABaseModAttachment* MA)
{
	if (ModAttachmentList == nullptr)
	{
		ModAttachmentList = MA;
	}
	else
	{
		MA->NextModAttachment = ModAttachmentList;
		ModAttachmentList = MA;
	}
}
void AAttachmentHandler::Destroyed()
{
	Super::Destroyed();
	ClearModAttachments();
}

void AAttachmentHandler::ClearModAttachments()
{
	if (ModAttachmentList != nullptr)
	{
		ModAttachmentList->Destroy();
		ModAttachmentList = nullptr;
	}
}

void AAttachmentHandler::SetFriendly(bool bFriendly)
{
	bSpinnyEnemy = !bFriendly;
}
