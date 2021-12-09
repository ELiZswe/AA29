// All the original content belonged to the US Army


#include "AA29/Object/Actor/AttachmentHandler/AttachmentHandler.h"

// Sets default values
AAttachmentHandler::AAttachmentHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	num_mods = -1;
	AnimState = 255;
	//DrawType = 0;
	//RemoteRole = 2;
}

// Called when the game starts or when spawned
void AAttachmentHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAttachmentHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AAttachmentHandler::NotifyReplicationComplete()
{
	SetDefaultWeaponMesh(nullptr);
	SpawnModAttachments();
}
void AAttachmentHandler::IsReplicationComplete()
{
	/*
	local int i;
	local int found_mods;
	if (AttachProxy == None || AnimState == 255)
	{
		Return False;
	}
	if (AttachProxy.IsA('BaseWeaponAttachment') && AttachProxy.Instigator == None)
	{
		Return False;
	}
	for (i = 0; i < 6; i++)
	{
		if (WM_Attachment[i] != None)
		{
			found_mods++;
		}
	}
	Return num_mods == found_mods;
	*/
}
void AAttachmentHandler::SetupHandler(AActor* newproxy, AActor* AttachTo, AInventory* i)
{
	/*
	AttachProxy = newproxy;
	SetBase(AttachTo);
	SetOwner(AttachTo);
	if (i != None)
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
	/*
	local BaseModAttachment MA;
	MA = ModAttachmentList;
	if (MA != None)
	{
		if (MA.ModSlot == Slot && MA.bSpinnyActive)
		{
			if (bDraw)
			{
				MA.SetDrawType(MA.Default.DrawType);
			}
			else
			{
				MA.SetDrawType(0);
			}
		}
		MA = MA.NextModAttachment;
	}
	*/
}
void AAttachmentHandler::LoadModAttachment(ABaseModAttachment* BMA, int32 Slot)
{
	/*
	local BaseModAttachment MA;
	local bool bAlreadyExists;
	local bool bAdjustedWeaponMesh;
	local int extra_slot;
	local int bAdjustSlot;
	WM_Attachment[Slot] = BMA;
	MA = ModAttachmentList;
	if (MA != None)
	{
		if (MA.ModSlot == Slot)
		{
			if (MA.Class == BMA)
			{
				MA.bSpinnyActive = true;
				MA.NotifyAttachmentAnimation(AnimState);
				MA.SetFriendlyMesh(!bSpinnyEnemy);
				MA.NotifyAttachMod();
				Level.SetActorLevelSkin(MA, True, special_skin_tag);
				if (MA.WeaponMesh != None && AttachProxy.Mesh == MA.WeaponMesh)
				{
					bAdjustedWeaponMesh = true;
				}
				extra_slot = MA.WeaponMod.Default.FillExtraSlot;
				if (extra_slot >= 0)
				{
					bAdjustSlot[extra_slot] = 1;
					SetSlotDraw(extra_slot, False);
				}
				bAlreadyExists = true;
			}
			else
			{
				MA.bSpinnyActive = False;
				MA.SetDrawType(0);
				if (!bAdjustedWeaponMesh)
				{
					MA.NotifyDetachMod();
				}
				extra_slot = MA.WeaponMod.Default.FillExtraSlot;
				if (extra_slot >= 0 && bAdjustSlot[extra_slot] == 0)
				{
					SetSlotDraw(extra_slot, True);
				}
			}
		}
		MA = MA.NextModAttachment;
	}
	if (!bAlreadyExists && BMA != None)
	{
		MA = SpawnSingleAttachment(Slot, bSpinnyEnemy);
		if (MA != None)
		{
			MA.bSpinnyActive = true;
			MA.SetFriendlyMesh(!bSpinnyEnemy);
			Level.SetActorLevelSkin(MA, True, special_skin_tag);
			extra_slot = MA.WeaponMod.Default.FillExtraSlot;
			if (extra_slot >= 0)
			{
				SetSlotDraw(extra_slot, False);
			}
		}
	}
	*/
}
void AAttachmentHandler::CopyModsFrom(AInventory* i)
{
	/*
	local AGP_Weapon W;
	local BaseWeaponMod WM;
	W = AGP_Weapon(i);
	if (W == None)
	{
		DebugLog(DEBUG_Warn, "AttachmentHandler::CopyModsFrom()	Don't know what to do with no Weapon" @ i @ W);
		Destroy();
		Return;
	}
	WM = W.WeaponModList;
	if (WM != None)
	{
		WM_Attachment[WM.ModSlot] = WM.GetModAttachment();
		WM = WM.NextWeaponMod;
	}
	AnimState = 0;
	if (W.IsSuppressed())
	{
		AnimState = AnimState | 4;
	}
	*/
}
void AAttachmentHandler::CountModAttachments()
{
	/*
	local int i;
	if (!Level.IsServer())
	{
		Return;
	}
	num_mods = 0;
	for (i = 0; i < 6; i++)
	{
		if (WM_Attachment[i] != None)
		{
			num_mods++;
		}
	}
	*/
}
void AAttachmentHandler::IsEnemy()
{
	/*
	if (AttachProxy.IsA('BaseWeaponAttachment'))
	{
		if (BaseWeaponAttachment(AttachProxy).bDontSwapMeshes)
		{
			Return False;
		}
		else
		{
			if (AttachProxy.Instigator != None)
			{
				Return !Level.IsUSSkin(AttachProxy.Instigator.bClientFriend);
			}
			else
			{
				DebugLog(DEBUG_Warn, "AttachmentHandler::IsEnemy()	Got here with no Instigator for the AttachProxy.");
				Return False;
			}
		}
	}
	else
	{
		if (AttachProxy.IsA('Pickup'))
		{
			Return Pickup(AttachProxy).UseEnemyClass();
		}
		else
		{
			DebugLog(DEBUG_Inv, "AttachmentHandler::IsEnemy()	Don't know how to tell with Proxy(" @ AttachProxy @ ")");
			Return False;
		}
	}
	*/
}
void AAttachmentHandler::InvalidAttachProxy()
{
	/*
	if (AttachProxy.IsA('BaseWeaponAttachment') && AttachProxy.Instigator == None)
	{
		Return True;
	}
	else
	{
		Return False;
	}
	*/
}
void AAttachmentHandler::SpawnModAttachments()
{
	/*
	local int i;
	local bool bIsEnemy;
	if (!InvalidAttachProxy())
	{
		bIsEnemy = IsEnemy();
		for (i = 0; i < 6; i++)
		{
			SpawnSingleAttachment(i, bIsEnemy);
		}
	}
	if (AttachProxy.IsA('BaseWeaponAttachment'))
	{
		BaseWeaponAttachment(AttachProxy).AttachHandler = Self;
		NotifyModAttachmentAnimation(BaseWeaponAttachment(AttachProxy).AnimState);
	}
	*/
}
void AAttachmentHandler::SpawnSingleAttachment(int32 Slot, bool bIsEnemy)
{
	/*
	local BaseModAttachment MA;
	if (WM_Attachment[Slot] != None)
	{
		MA = Spawn(WM_Attachment[Slot], Self);
		AttachProxy.AttachToBone(MA, MA.GetAttachBone(Slot));
		MA.SetDrawScale(AttachProxy.DrawScale);
		AddModAttachment(MA);
		MA.ModSlot = Slot;
		MA.SetFriendlyMesh(!bIsEnemy);
		Level.SetActorLevelSkin(MA, !bIsEnemy, special_skin_tag);
		MA.NotifyAttachMod();
		MA.NotifyAttachmentAnimation(AnimState);
		MA.bUnlit = bUnlit;
	}
	Return MA;
	*/
}
void AAttachmentHandler::SetSpecialSkinTag(FString skin_tag)
{
	/*
	local BaseModAttachment MA;
	special_skin_tag = skin_tag;
	MA = ModAttachmentList;
	if (MA != None)
	{
		Level.SetActorLevelSkin(MA, True, special_skin_tag);
		MA = MA.NextModAttachment;
	}
	*/
}
void AAttachmentHandler::SetDefaultWeaponMesh(UStaticMesh* NewDefaultWeaponMesh)
{
	/*
	if (NewDefaultWeaponMesh == None)
	{
		DefaultWeaponMesh = AttachProxy.Default.Mesh;
	}
	else
	{
		DefaultWeaponMesh = NewDefaultWeaponMesh;
	}
	*/
}
void AAttachmentHandler::SetWeaponMesh(UStaticMesh* NewWeaponMesh)
{
	/*
	if (NewWeaponMesh == None)
	{
		NewWeaponMesh = DefaultWeaponMesh;
	}
	AttachProxy.LinkMesh(NewWeaponMesh);
	Level.SetActorLevelSkin(AttachProxy, !IsEnemy(), special_skin_tag);
	*/
}
void AAttachmentHandler::NotifyModAttachmentAnimation(uint8 NewAnimState)
{
	/*
	local BaseModAttachment BM;
	AnimState = NewAnimState;
	BM = ModAttachmentList;
	if (BM != None)
	{
		BM.NotifyAttachmentAnimation(AnimState);
		BM = BM.NextModAttachment;
	}
	*/
}
void AAttachmentHandler::AddModAttachment(ABaseModAttachment* MA)
{
	/*
	if (ModAttachmentList == None)
	{
		ModAttachmentList = MA;
	}
	else
	{
		MA.NextModAttachment = ModAttachmentList;
		ModAttachmentList = MA;
	}
	*/
}
void AAttachmentHandler::Destroyed()
{
	//Super::Destroyed();
	ClearModAttachments();
}
void AAttachmentHandler::ClearModAttachments()
{
	if (ModAttachmentList != nullptr)
	{
		//ModAttachmentList->Destroy();
		ModAttachmentList = nullptr;
	}
}
void AAttachmentHandler::SetFriendly(bool bFriendly)
{
	bSpinnyEnemy = !bFriendly;
}
