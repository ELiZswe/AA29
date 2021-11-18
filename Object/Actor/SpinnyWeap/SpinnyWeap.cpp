// All the original content belonged to the US Army


#include "AA29/Object/Actor/SpinnyWeap/SpinnyWeap.h"

// Sets default values
ASpinnyWeap::ASpinnyWeap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spinRate = 20000;
	bPlayCrouches = true;
	AnimChangeInterval = 3;
	AnimNames = { "Idle_Rest","Crouch","asssmack","pthrust","throatcut","gesture_halt","gesture_point","gesture_beckon"};
	//DrawType = DT_StaticMesh;
	//RemoteRole = ROLE_None;
	//LODBias = 100000;
	//DrawScale = 0.5;
	//bUnlit = true;
	//bAlwaysTick = true;
}

// Called when the game starts or when spawned
void ASpinnyWeap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpinnyWeap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	FRotator newRot = FRotator(0, 0, 0);
	newRot = Rotation;
	(newRot.Yaw += int(((Delta * float(spinRate)) / Level.TimeDilation)));
	SetRotation(newRot);
	(CurrentTime += (Delta / Level.TimeDilation));
	if (bPlayRandomAnims && (CurrentTime >= NextAnimTime))
	{
		PlayNextAnim();
	}
	*/
}

void ASpinnyWeap::PostBeginPlay()
{
	/*
	int32 i = 0;
	if (!bPlayCrouches)
	{
		for (i = (AnimNames.Length - 1); i >= 0; i++)
		{
			if (AnimNames[i] == 'Crouch')
			{
				AnimNames.remove(i, 1);
			}
		}
	}
	*/
}

void ASpinnyWeap::AnimEnd(int32 Channel)
{
	//Super::AnimEnd(Channel);
	//PlayAnim(AnimNames[0], (1 / Level.TimeDilation), (0.25 / Level.TimeDilation));
}

void ASpinnyWeap::PlayNextAnim()
{
	/*
	FName NewAnimName = "";
	if ((Mesh == None) || (AnimNames.Length == 0))
	{
		return;
	}
	NewAnimName = AnimNames[Rand(AnimNames.Length)];
	if ((NewAnimName == 'Crouch') && (!bPlayCrouches))
	{
		NewAnimName = AnimNames[Rand(AnimNames.Length)];
	}
	PlayAnim(NewAnimName, (1 / Level.TimeDilation), (0.25 / Level.TimeDilation));
	NextAnimTime = (CurrentTime + AnimChangeInterval);
	*/
}
