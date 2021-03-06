// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

// Sets default values
AItemAttachment::AItemAttachment()
{
	DrawScale          = 1.13;
	DrawType           = EDrawType::DT_StaticMesh;
	RelativeRotation   = FRotator(0, 180, 90);
	Rotation           = FRotator(0, 180, 90);
}

FName AItemAttachment::GetAttachBoneFor(AInventory* Inv)
{
	return AttachBone;
}

void AItemAttachment::SetMesh()
{
	Super::SetMesh();
	CheckOtherAttachments(false);
}

void AItemAttachment::Destroyed()
{
	Super::Destroyed();
	RemoveFromList();
	CheckOtherAttachments(true);
}

void AItemAttachment::RemoveFromList()
{
	APawn* p = nullptr;
	int32 i = 0;
	/*
	p = Cast<APawn>(Base);
	if (p == nullptr)
	{
		return;
	}
	for (i = 0; i < p.AttachmentList.Num(); i++)
	{
		if (p.AttachmentList[i] == this)
		{
			p.AttachmentList[i] = nullptr;
		}
	}
	*/
}

void AItemAttachment::CheckOtherAttachments(bool bEnable)
{
	int32 i = 0;
	int32 j = 0;
	APawn* p = nullptr;
	AItemAttachment* Item = nullptr;
	/*
	p = Cast<APawn>(Base);
	if (p == nullptr)
	{
		return;
	}
	for (i = 0; i < p.AttachmentList.Num(); i++)
	{
		Item = ItemAttachment(p.AttachmentList[i]);
		if (Item != nullptr)
		{
			DebugLog(DEBUG_Inv, "ItemAttachment::CheckOtherAttachment()	Checking(" @ FString::FromInt(Item) @ ")");
			for (j = 0; j < Item.DisableOtherAttachment.Num(); j++)
			{
				if (IsA(Item.DisableOtherAttachment[j]))
				{
					DebugLog(DEBUG_Inv, "ItemAttachment::CheckOtherAttachments()	THIS(" @ FString::FromInt(this) @ ") item(" @ FString::FromInt(Item) @ ") Enable(" @ FString::FromInt(bEnable) @ ")");
					EnableItem(bEnable, this);
				}
			}
			for (j = 0; j < DisableOtherAttachment.Num(); j++)
			{
				if (Item.IsA(DisableOtherAttachment[j]))
				{
					DebugLog(DEBUG_Inv, "ItemAttachment::CheckOtherAttachments()	this(" @ FString::FromInt(this) @ ") ITEM(" @ FString::FromInt(Item) @ ") Enable(" @ FString::FromInt(bEnable) @ ")");
					EnableItem(bEnable, Item);
				}
			}
		}
	}
	*/
}

void AItemAttachment::EnableItem(bool bEnable, AItemAttachment* Item)
{
	if (bEnable)
	{
		//Item.SetDrawType(Default.DrawType);
		//Item.CheckOtherAttachments(false);
	}
	else
	{
		//Item.SetDrawType(DT_None);
	}
}
