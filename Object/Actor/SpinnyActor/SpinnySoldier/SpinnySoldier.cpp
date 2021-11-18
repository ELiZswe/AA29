// All the original content belonged to the US Army


#include "AA29/Object/Actor/SpinnyActor/SpinnySoldier/SpinnySoldier.h"

ASpinnySoldier::ASpinnySoldier()
{
	bPlayCrouches = true;
	AnimChangeInterval = 3;
	AnimNames = { "AE_Idle_A","AE_Idle_B","ACF_Idle_A","ACF_Idle_B","acf_scratchass" };
}

void ASpinnySoldier::PostBeginPlay()
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

void ASpinnySoldier::Tick(float Delta)
{
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

void ASpinnySoldier::AnimEnd(int32 Channel)
{
	/*
	Super::AnimEnd(Channel);
	PlayAnim(AnimNames[0], (1 / Level.TimeDilation), (0.25 / Level.TimeDilation));
	*/
}

void ASpinnySoldier::PlayNextAnim()
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

