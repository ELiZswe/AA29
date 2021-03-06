// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

// Sets default values
AInventoryAttachment::AInventoryAttachment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bFastAttachmentReplication  = true;
	AttachmentBone              = FName("righthand");
	//bUseLightingFromBase = true;
	//bOnlyDrawIfAttached = true;
	//bOnlyDirtyReplication = true;
	//NetUpdateFrequency = 10;
	DrawType                    = EDrawType::DT_Mesh;
	//RemoteRole = 2

}


void AInventoryAttachment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInventoryAttachment::InitFor(AInventory* i)
{
	/*
		Instigator=i.Instigator;
	*/
}
void AInventoryAttachment::BeginPlay()
{
	Super::BeginPlay();
	//NV_AmbientGlow=Cast<AAA2_WorldSettings>(GetWorldSettings())->Pawn_NV_AmbientGlow;
}

FName AInventoryAttachment::GetAttachBoneFor(AInventory* Inv)
{
	return "FAKE";    //FAKE   /EliZ
}

USkeletalMesh* AInventoryAttachment::GetMesh(bool bFriendly)
{
	return Mesh;
}

UStaticMesh* AInventoryAttachment::GetStaticMesh(bool bFriendly)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly))
	{
		return FriendlyStaticMesh;
	}
	else
	{
		return EnemyStaticMesh;
	}
}
void AInventoryAttachment::NotifyBaseChange()
{
	AAGP_Character* p;
	p = Cast<AAGP_Character>(Base);
	if (p == NULL)
	{
		return;
	}
	//DebugLog(DEBUG_Inv,"InventoryAttachment::NotifyBaseChange()	" + this @ p);
	p->RegisterAttachment(this);
}

void AInventoryAttachment::NotifyFoundClient()
{
	SetMesh();
}

float AInventoryAttachment::GetDrawScaleDecision(float PawnScale)
{
	return PawnScale;
}

void AInventoryAttachment::SetMesh()
{
	USkeletalMesh* NewMesh = nullptr;
	UStaticMesh* NewStaticMesh = nullptr;
	APawn* p = nullptr;
	/*
		p=Pawn(Base);
		if (p == nullptr)
		{
			DebugLog(DEBUG_Warn,"InventoryAttachment::SetMesh()	No Pawn for " + Self);
			return;
		}
		SetDrawScale(GetDrawScaleDecision(p.DrawScale));
		switch(Default.DrawType)
		{
			case 0:
			return;
			case 8:
			NewStaticMesh=GetStaticMesh(p.bClientFriend);
			if (NewStaticMesh == nullptr)
			{
				SetDrawType(0);
				break;
			}
			if (NewStaticMesh != StaticMesh)
			{
				SetStaticMesh(NewStaticMesh);
				NotifyNewMesh(p.bClientFriend);
			}
		}
		GOTO JL01A8;
		case 2:
		NewMesh=GetMesh(p.bClientFriend);
		DebugLog(DEBUG_Char,"InventoryAttachment::SetMesh()	DT_Mesh Mesh(" @ Mesh @ ")-->(" @ NewMesh @ ")");
		if (NewMesh == nullptr)
		{
			SetDrawType(0);
		}
		else
		{
			if (NewMesh != Mesh)
			{
				LinkMesh(NewMesh);
				NotifyNewMesh(p.bClientFriend);
			}
		}
		GOTO JL01A8;
		default:
	JL01A8:
		Level.SetActorLevelSkin(this,p.bClientFriend);
		DebugLog(DEBUG_Char,"InventoryAttachment::SetMesh()	" + StaticMesh);
	*/
}
void AInventoryAttachment::NotifyNewMesh(bool bFriendly)
{
	SetDrawType(GetDefault<AInventoryAttachment>()->DrawType);
}
void AInventoryAttachment::AttachmentAnimation()
{
}

void AInventoryAttachment::SetDrawType(EDrawType NewDrawType)
{

}
