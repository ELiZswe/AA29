// All the original content belonged to the US Army


#include "AA29/Object/Actor/HelpIcon/HelpIcon.h"

// Sets default values
AHelpIcon::AHelpIcon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 0.5;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FX/star/m_fx_floating_star.m_fx_floating_star'"), NULL, LOAD_None, NULL);
	//bHidden = true;

}

// Called when the game starts or when spawned
void AHelpIcon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelpIcon::Tick(float DeltaTime)
{
	FRotator NewRotation = FRotator(0, 0, 0);
	Super::Tick(DeltaTime);

	/*
	SetLocation((Follower.Location + offset));
	NewRotation = Rotation;
	(NewRotation.Yaw += int((RotationSpeed * DeltaTime)));
	SetRotation(NewRotation);
	*/
}

void AHelpIcon::PostBeginPlay()
{
	//Super::PostBeginPlay();
}

void AHelpIcon::SetHelpIcon(AActor* FollowMe, FVector _offset, float Scale, float RotSpeed)
{
	/*
	bHidden = false;
	Follower = FollowMe;
	if (Scale > 0)
	{
		SetDrawScale(Scale);
	}
	RotationSpeed = RotSpeed;
	offset = _offset;
	*/
}
