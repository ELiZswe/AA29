// All the original content belonged to the US Army


#include "AA29/Object/Actor/Projector/BaseContactProjector/BaseContactProjector.h"

ABaseContactProjector::ABaseContactProjector()
{
	bRandomRoll = true;
	bRandomScale = true;
	//FrameBufferBlendingOp = 2;
	//FOV = 1;
	//MaxTraceDistance = 16;
	//bProjectActor = false;
	//bClipBSP = true;
	//bGradient = true;
	//bProjectOnParallelBSP = false;
	//GradientTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/GRADIENT_Clip_Mat.GRADIENT_Clip_Mat'"), NULL, LOAD_None, NULL);
	//bDecalProjector = true;
	//bStatic = false;
	//LifeSpan = 10;
	//bHardAttach = true;
}

/*

void ABaseContactProjector::PostBeginPlay()
{
	FRotator Rot = FRotator(0, 0, 0);
	FName tmpAttchBone = "";
	if (bRandomRoll)
	{
		Rot = Rotation;
		Rot.Roll = Rand(65535);
		SetRotation(Rot);
	}
	if (bRandomScale)
	{
		SetDrawScale((((FRand() * 0.5) + 0.75) * Default.DrawScale));
	}
	if ((Owner != None) && Owner.IsA('DecoMesh'))
	{
		OwnerLoc = Owner.Location;
		OwnerRot = Owner.Rotation;
		SetDecoProjector(Owner);
		AttachProjector();
		ExpireProjector(LifeSpan);
		Enable('Tick');
		LifeSpan = 0;
	}
	else
	{
		if ((Owner != None) && Owner.IsA('BodyPanel'))
		{
			OwnerLoc = Owner.Location;
			OwnerRot = Owner.Rotation;
			AttachProjector();
			tmpAttchBone = Owner.AttachmentBone;
			SetOwner(Owner.Owner);
			SetBase(Owner);
			bBodyPanelProjector = true;
			Enable('Tick');
		}
		else
		{
			Disable('Tick');
			AttachProjector();
			AbandonProjector(LifeSpan);
			Destroy();
		}
	}
}

void ABaseContactProjector::UpdateProjector()
{
	if (bBodyPanelProjector)
	{
		if ((Owner != None) && ((OwnerLoc != Owner.Location) || (OwnerRot != Owner.Rotation)))
		{
			DetachProjector(true);
			OwnerLoc = Owner.Location;
			OwnerRot = Owner.Rotation;
			AttachProjector();
		}
		return;
	}
	if (M_UID < GetYoungestUID())
	{
		if (Level.bFadeDecoDecals)
		{
			DetachProjector(true);
			Destroy();
			return;
		}
		else
		{
			ReleaseUID();
		}
	}
	if (bMoverProjector)
	{
		if ((Owner != None) && ((OwnerLoc != Owner.Location) || (OwnerRot != Owner.Rotation)))
		{
			DetachProjector(true);
			OwnerLoc = Owner.Location;
			OwnerRot = Owner.Rotation;
			AttachProjector();
		}
	}
}

void ABaseContactProjector::Tick(float DeltaTime)
{
	UpdateProjector();
}

int32 ABaseContactProjector::GetYoungestUID()
{
	//return (AttachedToDeco.YoungestDecoDecal - Level.KeepDecoDecals);
	return 0;     //FAKE   /ELiZ
}

void ABaseContactProjector::NotifyRenderInfoExpired()
{
	LifeSpan = 2;
	Disable('Tick');
	SetTimer(0, false);
}

void ABaseContactProjector::Reset()
{
	Destroy();
}


*/