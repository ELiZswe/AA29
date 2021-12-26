// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"

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
	p = Pawn(Base);
	if (p == None)
	{
		return;
	}
	for (i = 0; i < p.AttachmentList.Length; i++)
	{
		if (p.AttachmentList[i] == Self)
		{
			p.AttachmentList[i] = None;
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
	p = Pawn(Base);
	if (p == None)
	{
		return;
	}
	for (i = 0; i < p.AttachmentList.Length; i++)
	{
		Item = ItemAttachment(p.AttachmentList[i]);
		if (Item != None)
		{
			DebugLog(DEBUG_Inv, "ItemAttachment::CheckOtherAttachment()	Checking(" @ string(Item) @ ")");
			for (j = 0; j < Item.DisableOtherAttachment.Length; j++)
			{
				if (IsA(Item.DisableOtherAttachment[j]))
				{
					DebugLog(DEBUG_Inv, "ItemAttachment::CheckOtherAttachments()	THIS(" @ string(Self) @ ") item(" @ string(Item) @ ") Enable(" @ string(bEnable) @ ")");
					EnableItem(bEnable, Self);
				}
			}
			for (j = 0; j < DisableOtherAttachment.Length; j++)
			{
				if (Item.IsA(DisableOtherAttachment[j]))
				{
					DebugLog(DEBUG_Inv, "ItemAttachment::CheckOtherAttachments()	this(" @ string(Self) @ ") ITEM(" @ string(Item) @ ") Enable(" @ string(bEnable) @ ")");
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
