// All the original content belonged to the US Army

#include "AA29/Object/Actor/LaserProjector/LaserProjector.h"

// Sets default values
ALaserProjector::ALaserProjector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//LasTexture = FinalBlend'T_AA2_FX.Coronas.fx2_laser_spot_fb2'
	//DrawType = 0
	//bAcceptsProjectors = False
}

// Called when the game starts or when spawned
void ALaserProjector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserProjector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaserProjector::Destroyed()
{
	/*
	bIsOn = False;
	if (LasProj != None)
	{
		LasProj.Destroy();
		LasProj = nullptr;
	}
	*/
}
void ALaserProjector::CreateLaserProjector()
{
	/*
	LasProj = Spawn(Class'DynamicProjector', Self, 'None', Location);
	if (LasProj == nullptr)
	{
		Log("Couldn't create dynamic projector for laser dot!");
		Return;
	}
	if (LasTexture == nullptr)
	{
		Log("Assinging NULL Material as projecting material!");
	}
	LasProj.ProjTexture = LasTexture;
	Log("Assinging material " $ LasProj.ProjTexture $ " to laser projector.");
	LasProj.FOV = 1;
	LasProj.MaxTraceDistance = 40;
	LasProj.bProjectBSP = true;
	LasProj.bProjectTerrain = true;
	LasProj.bProjectStaticMesh = true;
	LasProj.bProjectActor = true;
	LasProj.bLevelStatic = False;
	LasProj.bClipBSP = true;
	LasProj.bClipStaticMesh = true;
	LasProj.bGradient = False;
	LasProj.bProjectOnBackfaces = true;
	LasProj.bProjectOnAlpha = true;
	LasProj.bProjectOnParallelBSP = true;
	LasProj.bDynamicAttach = true;
	LasProj.bProjectParticles = False;
	LasProj.bDrawLast = true;
	LasProj.bAcceptsProjectors = False;
	LasProj.bNoProjectOnFirstPersonWeapons = true;
	LasProj.MaterialBlendingOp = 0;
	LasProj.FrameBufferBlendingOp = 3;
	LasProj.bBlockBulletTraces = False;
	LasProj.bBlockCoronaTraces = False;
	LasProj.bBlockZeroExtentTraces = False;
	LasProj.bBlockNonZeroExtentTraces = False;
	LasProj.bHidden = true;
	LasProj.bMovable = true;
	*/
}
void ALaserProjector::TurnOn(AActor* ActorToAttachTo)
{
	/*
	local Actor NextActor;
	local BaseWeaponAttachment BaseAttachment;
	if (LasProj == nullptr)
	{
		CreateLaserProjector();
		if (LasProj == nullptr)
		{
			return;
		}
	}
	for (NextActor=ActorToAttachTo; NextActor!=nullptr; NextActor=NextActor.Base)
	{
		Log("Actor in Base chain: " $ string(NextActor));
	}
	LasProj.ActorToIgnore=ActorToAttachTo;
	Log("LaserProjector is ignoring Actor: " $ string(LasProj.ActorToIgnore));
	if (ActorToAttachTo.IsA("BaseWeaponMod"))
	{
		ActorToAttachTo.AttachToBone(Self,"laser");
		SetRelativeLocation(vect(0,0,0));
		SetRelativeRotation(MakeRot(0,0,0));
		BaseType=0;
	}
	else
	{
		if (ActorToAttachTo.IsA("BaseWeaponAttachment"))
		{
			bRenderAttachmentSeperately=true;
			BaseAttachment=BaseWeaponAttachment(ActorToAttachTo);
			BaseType=1;
			BaseAttachment.GetSource().AttachToBone(Self,BaseAttachment._MuzzleOffset.nBone);
			SetRelativeLocation(BaseAttachment._MuzzleOffset.VOffset);
			SetRelativeRotation(BaseAttachment._MuzzleOffset.ROffset);
			BaseAttachment.GetSource().bAlwaysRelevant=true;
			LasProj.ActorToIgnore=BaseAttachment.GetSource();
			Log("Laser attaching to BaseWeaponAttachment. MuzzleOffset Bone(" $ string(BaseAttachment._MuzzleOffset.nBone) $ "), VOffset(" $ string(BaseAttachment._MuzzleOffset.VOffset.X) $ ", " $ string(BaseAttachment._MuzzleOffset.VOffset.Y) $ ", " $ string(BaseAttachment._MuzzleOffset.VOffset.Z) $ "), ROffset(" $ string(BaseAttachment._MuzzleOffset.ROffset.Yaw) $ ", " $ string(BaseAttachment._MuzzleOffset.ROffset.Pitch) $ ", " $ string(BaseAttachment._MuzzleOffset.ROffset.Roll) $ ")");
		}
		else
		{
			if (ActorToAttachTo.IsA("AGP_Pawn"))
			{
				BaseType=2;
				Log("Laser attaching to Pawn: " $ string(ActorToAttachTo));
				SetBase(ActorToAttachTo);
			}
			else
			{
				Log("Trying to attach LaserProjector to unknown base type!");
				return;
			}
		}
	}
	bIsOn=true;
	Log("Laser Projector is getting attached to actor: " $ string(ActorToAttachTo));
	*/
}
void ALaserProjector::TurnOff()
{
	/*
	if (bIsOn)
	{
		Log("Laser Projector is turning off (Parent actor was " $ Owner $ ")");
		if (BaseType == 1)
	}
	{
		SetBase(None);
		LasProj.DetachProjector(True);
		bIsOn = False;
	}
	bRenderAttachmentSeperately = False;
	*/
}
