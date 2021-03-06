// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projector/Projector.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"

AProjector::AProjector()
{
	FrustumVertices.SetNum(8);
	FrustumPlanes.SetNum(6);
	FrameBufferBlendingOp = EProjectorBlending::PB_Modulate;
	MaxTraceDistance = 1000;
	bProjectBSP = true;
	bProjectTerrain = true;
	bProjectStaticMesh = true;
	bProjectParticles = true;
	bProjectActor = true;
	bProjectOnParallelBSP = true;
	GradientTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/GRADIENT_Fade_Mat.GRADIENT_Fade_Mat'"), NULL, LOAD_None, NULL);
	//bStatic = true;
	//bHidden = true;
	//RemoteRole = ROLE_None;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/Proj_Icon_Mat.Proj_Icon_Mat'"), NULL, LOAD_None, NULL);
	//bDirectional = true;
}

/*
State NoProjection
{
	Function BeginState()
	{
		Disable("Tick");
	}
}
*/

//native Function SetDecoProjector(Actor AttachTo);
void AProjector::SetDecoProjector(AActor* AttachTo)
{

}

//native Function ReleaseUID();
void AProjector::ReleaseUID()
{

}

//native Function AttachProjector(float FadeInTime);
void AProjector::AttachProjector(float aFadeInTime)
{

}

//native Function DetachProjector(bool Force);
void AProjector::DetachProjector(bool Force)
{

}

//native Function AbandonProjector(float Lifetime);
void AProjector::AbandonProjector(float Lifetime)
{

}

//native Function ExpireProjector(float Lifetime);
void AProjector::ExpireProjector(float Lifetime)
{

}

//native Function AttachActor(Actor A);
void AProjector::AttachActor(AActor* A)
{

}

//native Function DetachActor(Actor A);
void AProjector::DetachActor(AActor* A)
{

}

void AProjector::NotifyRenderInfoExpired()
{
}

void AProjector::SetupProjector(bool bRoll, int32 TEST_ROLL)
{
}

void AProjector::PostBeginPlay()
{
	/*
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		GotoState("NoProjection");
		return;
	}
	AttachProjector(FadeInTime);
	if (bLevelStatic)
	{
		AbandonProjector();
		Destroy();
	}
	if (bProjectActor)
	{
		SetCollision(true, false, false);
	}
	*/
}

void AProjector::Touch(AActor* Other)
{
	/*
	if (Other == nullptr)
	{
		return;
	}
	if (((Other.bAcceptsProjectors && ((ProjectTag == "None") || (Other.Tag == ProjectTag))) && (bProjectStaticMesh || (Other.StaticMesh == nullptr))) && (!((Other.bStatic && bStatic) && (Other.StaticMesh != nullptr))))
	{
		AttachActor(Other);
	}
	*/
}

void AProjector::UnTouch(AActor* Other)
{
	DetachActor(Other);
}
