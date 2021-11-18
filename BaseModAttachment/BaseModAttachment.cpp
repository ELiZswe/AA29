// All the original content belonged to the US Army


#include "BaseModAttachment.h"

// Sets default values
ABaseModAttachment::ABaseModAttachment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseModAttachment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseModAttachment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseModAttachment::PostNetBeginPlay()
{
	/*
		GetWeaponMod();
		PostNetBeginPlay();
	*/
}
void ABaseModAttachment::GetWeaponMod()
{
	/*
		local int loc;
		local string mod_name;
		local string attch_name;
		local string front;
		local string back;
		if (WeaponMod == None)
		{
			mod_name=Default.Class;
			loc=InStr(mod_name,"AttachMod_");
			front=Left(mod_name,loc);
			back=Mid(mod_name,loc + Len("AttachMod_"),Len(mod_name));
			attch_name=front $ "WeaponMod_" $ back;
			WeaponMod=class<BaseWeaponMod>(DynamicLoadObject(attch_name,Class'Class',True));
		}
	*/
}
void ABaseModAttachment::GetAttachBone(int32 Slot)
{
	/*
		Return WeaponMod.GetAttachBone(Slot);
	*/
}
void ABaseModAttachment::NotifyAttachmentAnimation(uint8 AnimState)
{
	/*
		if (IsSuppressor())
		{
			if (AnimState & 4 == 4)
			{
				SetDrawType(2);
			}
			else
			{
				SetDrawType(0);
			}
		}
		if (AnimState & 8 == 8)
		{
			SetDefaultMesh();
		}
	*/
}
void ABaseModAttachment::Destroyed()
{
	/*
		Destroyed();
		if (NextModAttachment != None)
		{
			NextModAttachment.Destroy();
		}
	*/
}
void ABaseModAttachment::GetEnemyClass()
{
	/*
		local class<BaseWeaponMod>  BWM;
		if (WeaponMod != None)
		{
			BWM=WeaponMod.Default.EnemyModClass;
			if (BWM != None)
			{
				Return BWM.GetModAttachment();
			}
		}
		Return None;
	*/
}
void ABaseModAttachment::NotifyAttachMod()
{
	/*
		if (SpinnyWeaponMesh != None)
		{
			if (AttachmentHandler(Owner).bSpinny)
			{
				WeaponMesh=SpinnyWeaponMesh;
			}
		}
		if (WeaponMesh != None)
		{
			AttachmentHandler(Owner).SetWeaponMesh(WeaponMesh);
		}
	*/
}
void ABaseModAttachment::NotifyDetachMod()
{
	/*
		if (WeaponMesh != None)
		{
			AttachmentHandler(Owner).SetWeaponMesh();
		}
	*/
}
void ABaseModAttachment::SetFriendlyMesh(bool bFriendly)
{
	/*
		local Mesh NewMesh;
		local StaticMesh NewStaticMesh;
		local class<BaseModAttachment>  UseClass;
		if (bFriendly)
		{
			UseClass=Class;
		}
		else
		{
			UseClass=GetEnemyClass();
		}
		if (UseClass == None)
		{
			SetDrawType(0);
			Return;
		}
		SetDrawType(UseClass.Default.DrawType);
		Switch(DrawType)
		{
			case 8:
			NewStaticMesh=UseClass.Default.StaticMesh;
			if (NewStaticMesh == None)
			{
				SetDrawType(0);
				break;
			}
			SetStaticMesh(NewStaticMesh);
		}
		GOTO JL00F5;
		case 2:
		NewMesh=UseClass.Default.Mesh;
		if (NewMesh == None)
		{
			SetDrawType(0);
		}
		else
		{
			if (NewMesh != Mesh)
			{
				LinkMesh(NewMesh);
			}
		}
		GOTO JL00F5;
		case 0:
		LinkMesh(None);
		SetStaticMesh(None);
		GOTO JL00F5;
		default:
	JL00F5:
		WeaponMesh=UseClass.Default.WeaponMesh;
		SpinnyWeaponMesh=UseClass.Default.SpinnyWeaponMesh;
	*/
}
void ABaseModAttachment::SetDefaultMesh()
{
	/*
		SetDrawType(Default.DrawType);
		SetStaticMesh(Default.StaticMesh);
		LinkMesh(Default.Mesh);
	*/
}
void ABaseModAttachment::IsSuppressor()
{
	/*
		Return cSuppressorMuzzleFlash != None;
	}
	void IsSuppressed ()
	{
	/*
		Switch(DrawType)
		{
			case 2:
			Return Mesh != None;
			case 8:
			Return StaticMesh != None;
			default:
			Return False;
	*/
}
void ABaseModAttachment::GetSuppressorMuzzleFlash()
{
	/*
		if (SuppressorMuzzleFlash == None)
		{
			if (cSuppressorMuzzleFlash == None)
			{
				DebugLog(DEBUG_Warn,"BaseModAttachment::GetSuppressorMuzzleFlash() Got here with no muzzle flash class");
			}
			else
			{
				SuppressorMuzzleFlash=Spawn(cSuppressorMuzzleFlash,Self);
				AttachToBone(SuppressorMuzzleFlash,'Muzzle');
			}
		}
		Return SuppressorMuzzleFlash;
	*/
}
