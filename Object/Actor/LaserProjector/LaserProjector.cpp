// All the original content belonged to the US Army

#include "AA29/Object/Actor/LaserProjector/LaserProjector.h"
#include "AA29/Object/Actor/Projector/DynamicProjector/DynamicProjector.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ALaserProjector::ALaserProjector()
{
	PrimaryActorTick.bCanEverTick = true;
	//LasTexture = FinalBlend'T_AA2_FX.Coronas.fx2_laser_spot_fb2'
	//DrawType = 0
	//bAcceptsProjectors = false
}

void ALaserProjector::BeginPlay()
{
	Super::BeginPlay();
}

void ALaserProjector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaserProjector::Destroyed()
{
	bIsOn = false;
	if (LasProj != nullptr)
	{
		LasProj->Destroy();
		LasProj = nullptr;
	}
}

void ALaserProjector::CreateLaserProjector()
{
	//LasProj = Spawn(ADynamicProjector::StaticClass(), this, "None", Location);
	if (LasProj == nullptr)
	{
		//Log("Couldn't create dynamic projector for laser dot!");
		return;
	}
	if (LasTexture == nullptr)
	{
		//Log("Assinging NULL Material as projecting material!");
	}
	LasProj->ProjTexture = LasTexture;
	//Log("Assinging material " + LasProj->ProjTexture + " to laser projector.");
	LasProj->FOV = 1;
	LasProj->MaxTraceDistance = 40;
	LasProj->bProjectBSP = true;
	LasProj->bProjectTerrain = true;
	LasProj->bProjectStaticMesh = true;
	LasProj->bProjectActor = true;
	LasProj->bLevelStatic = false;
	LasProj->bClipBSP = true;
	LasProj->bClipStaticMesh = true;
	LasProj->bGradient = false;
	LasProj->bProjectOnBackfaces = true;
	LasProj->bProjectOnAlpha = true;
	LasProj->bProjectOnParallelBSP = true;
	LasProj->bDynamicAttach = true;
	LasProj->bProjectParticles = false;
	LasProj->bDrawLast = true;
	//LasProj->bAcceptsProjectors = false;
	LasProj->bNoProjectOnFirstPersonWeapons = true;
	LasProj->MaterialBlendingOp = EProjectorBlending::PB_None;
	LasProj->FrameBufferBlendingOp = EProjectorBlending::PB_Add;
	//LasProj->bBlockBulletTraces = false;
	//LasProj->bBlockCoronaTraces = false;
	//LasProj->bBlockZeroExtentTraces = false;
	//LasProj->bBlockNonZeroExtentTraces = false;
	//LasProj->bHidden = true;
	//LasProj->bMovable = true;
}

void ALaserProjector::TurnOn(AActor* ActorToAttachTo)
{
	AActor* NextActor = nullptr;
	ABaseWeaponAttachment* BaseAttachment = nullptr;
	if (LasProj == nullptr)
	{
		CreateLaserProjector();
		if (LasProj == nullptr)
		{
			return;
		}
	}
	/*
	for (NextActor=ActorToAttachTo; NextActor!=nullptr; NextActor=NextActor->Base)
	{
		//Log("Actor in Base chain: " + FString::FromInt(NextActor));
	}
	*/
	LasProj->ActorToIgnore=ActorToAttachTo;
	//Log("LaserProjector is ignoring Actor: " + FString::FromInt(LasProj->ActorToIgnore));
	if (ActorToAttachTo->IsA(ABaseWeaponMod::StaticClass()))
	{
		//ActorToAttachTo.AttachToBone(this,"laser");
		//SetRelativeLocation(FVector(0,0,0));
		//SetRelativeRotation(FRotator(0,0,0));
		BaseType= ELaserBaseType::BASETYPE_BaseWeaponMod;
	}
	else
	{
		if (ActorToAttachTo->IsA(ABaseWeaponAttachment::StaticClass()))
		{
			//bRenderAttachmentSeperately=true;
			BaseAttachment=Cast<ABaseWeaponAttachment>(ActorToAttachTo);
			BaseType = ELaserBaseType::BASETYPE_BaseWeaponAttachment;
			//BaseAttachment->GetSource()->AttachToBone(this,BaseAttachment._MuzzleOffset.nBone);
			//SetRelativeLocation(BaseAttachment._MuzzleOffset.VOffset);
			//SetRelativeRotation(BaseAttachment._MuzzleOffset.ROffset);
			BaseAttachment->GetSource()->bAlwaysRelevant=true;
			LasProj->ActorToIgnore=BaseAttachment->GetSource();
			//Log("Laser attaching to BaseWeaponAttachment. MuzzleOffset Bone(" + FString::FromInt(BaseAttachment._MuzzleOffset.nBone) + "), VOffset(" + FString::FromInt(BaseAttachment._MuzzleOffset.VOffset.X) + ", " + FString::FromInt(BaseAttachment._MuzzleOffset.VOffset.Y) + ", " + FString::FromInt(BaseAttachment._MuzzleOffset.VOffset.Z) + "), ROffset(" + FString::FromInt(BaseAttachment._MuzzleOffset.ROffset.Yaw) + ", " + FString::FromInt(BaseAttachment._MuzzleOffset.ROffset.Pitch) + ", " + FString::FromInt(BaseAttachment._MuzzleOffset.ROffset.Roll) + ")");
		}
		else
		{
			if (ActorToAttachTo->IsA(AAGP_Pawn::StaticClass()))
			{
				BaseType = ELaserBaseType::BASETYPE_AGP_Pawn;
				//Log("Laser attaching to Pawn: " + FString::FromInt(ActorToAttachTo));
				//SetBase(ActorToAttachTo);
			}
			else
			{
				//Log("Trying to attach LaserProjector to unknown base type!");
				return;
			}
		}
	}
	bIsOn=true;
	//Log("Laser Projector is getting attached to actor: " + FString::FromInt(ActorToAttachTo));
}

void ALaserProjector::TurnOff()
{
	if (bIsOn)
	{
		//Log("Laser Projector is turning off (Parent actor was " + FString::FromInt(GetOwner()) + ")");
		if (BaseType == ELaserBaseType::BASETYPE_BaseWeaponAttachment)
		{

		}
		//SetBase(nullptr);
		LasProj->DetachProjector(true);
		bIsOn = false;
	}
	//bRenderAttachmentSeperately = false;
}
