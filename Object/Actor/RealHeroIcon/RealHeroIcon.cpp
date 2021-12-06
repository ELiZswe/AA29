// All the original content belonged to the US Army


#include "AA29/Object/Actor/RealHeroIcon/RealHeroIcon.h"

// Sets default values
ARealHeroIcon::ARealHeroIcon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	maxAlpha = 175;
	minAlpha = 1;
	fadePerSecond = 200;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/UI/m_attachments_ui_realherostar2a.m_attachments_ui_realherostar2a'"), NULL, LOAD_None, NULL);
	//bUseDynamicLights = true;
	//bAcceptsProjectors = false;
	//Physics = PHYS_Rotating;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Attachments/UI/t_attachments_ui_realherostar2a_Mat.t_attachments_ui_realherostar2a_Mat'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
	//DrawScale3D = FVector(0.5, 0.5, 0.5);
	//bUnlit = true;
	//bShouldBaseAtStartup = true;
	//bCanTeleport = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = true;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//RotationRate = FRotator(0, 3000, 0);
}

// Called when the game starts or when spawned
void ARealHeroIcon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARealHeroIcon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (desiredAlpha != alphaFader.Color.A)
	{
		if (desiredAlpha > alphaFader.Color.A)
		{
			alphaFader.Color.A = byte(Clamp(int((float(alphaFader.Color.A) + (DeltaTime * fadePerSecond))), minAlpha, maxAlpha));
		}
		else
		{
			alphaFader.Color.A = byte(Clamp(int((float(alphaFader.Color.A) - (DeltaTime * fadePerSecond))), minAlpha, maxAlpha));
		}
	}
	*/

}

void ARealHeroIcon::PostBeginPlay()
{
	//RHShader = new () classClass'Shader';
	//alphaFader = new () classClass'ConstantColor';
	//alphaFader.Color.A = maxAlpha;
	//RHShader.Diffuse = Texture;
	//RHShader.Opacity = alphaFader;
	//Skins[0] = RHShader;
}

void ARealHeroIcon::Destroyed()
{
	//RHShader.Opacity = None;
}


void ARealHeroIcon::SetToMaxAlpha()
{
	desiredAlpha = maxAlpha;
}

void ARealHeroIcon::SetToMinAlpha()
{
	desiredAlpha = minAlpha;
}