// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/CameraController/AA2_CameraController.h"

AAA2_CameraController::AAA2_CameraController()
{
	fVisionAngle = 55;
	rSinAmp = FRotator(0, 100, 0);
	fSinFreq = 1;
}

/*
auto State Scanning
{
	Function bool EnemyIsVisible()
	{
		local Pawn p;
		bool bSeen = false;
		FVector Eye = FVector(0,0,0);
		FVector VectToEnemy = FVector(0,0,0);
		FVector VectOfVision = FVector(0,0,0);
		float DistToEnemy = 0;
		Eye = Pawn.EyePosition();
		VectOfVision = Normal(Vector(Rotation));
		ForEach DynamicActors(Class'Pawn',p)
		{
			if (p != Pawn)
			{
				VectToEnemy = (p.Location - Pawn.Location);
				DistToEnemy = VSize(VectToEnemy);
				if ((fViewDist <= 0) || (DistToEnemy <= fViewDist))
				{
					(VectToEnemy /= DistToEnemy);
					if ((VectToEnemy Dot VectOfVision) > fCosVisionAngle)
					{
						if ((FastTrace(p.Location,Eye) || FastTrace((p.Location + (p.CollisionHeight * vect(0,0,1))),Eye)) || FastTrace((p.Location - (p.CollisionHeight * vect(0,0,1))),Eye))
						{
							bSeen = true;
						}
					}
				}
			}
			else
			{
			}
		}
		return bSeen;
	}
	Function Tick(float DeltaTime)
	{
		FRotator addRot = FRotator(0,0,0);
		(fScanTime += DeltaTime);
		addRot = (rSinAmp * Sin((fSinFreq * fScanTime)));
		SetRotation((Rotation + addRot));
		Pawn.SetRotation(Rotation);
		if (EnemyIsVisible())
		{
			ScreenPrint("ENEMY VISIBLE");
			if (_EnemySpottedMonitor != None)
			{
				_EnemySpottedMonitor.Notify();
			}
		}
	}
	Function BeginState()
	{
		SetRotation(Pawn.Rotation);
		fScanTime = 0;
		fCosVisionAngle = Cos((fVisionAngle * (3.141593 / 360)));
	}
}
*/


void AAA2_CameraController::BeginState()
{
	//SetRotation(Pawn.Rotation);
	fScanTime = 0;
	//fCosVisionAngle = Cos(fVisionAngle * 3.141593 / 360);
}
void AAA2_CameraController::Tick(float DeltaTime)
{
	FRotator addRot = FRotator(0,0,0);
	/*
	fScanTime += DeltaTime;
	addRot = rSinAmp * Sin(fSinFreq * fScanTime);
	SetRotation(Rotation + addRot);
	Pawn.SetRotation(Rotation);
	if (EnemyIsVisible())
	{
		ScreenPrint("ENEMY VISIBLE");
		if (_EnemySpottedMonitor != None)
		{
			_EnemySpottedMonitor.Notify();
		}
	}
	*/
}
bool AAA2_CameraController::EnemyIsVisible()
{
	APawn* p = nullptr;
	bool bSeen = false;
	FVector Eye = FVector(0,0,0);
	FVector VectToEnemy = FVector(0, 0, 0);
	FVector VectOfVision = FVector(0, 0, 0);
	float DistToEnemy = 0;
	/*
	Eye = Pawn.EyePosition();
	VectOfVision = Normal(Vector(Rotation));
	ForEach DynamicActors(Class'Pawn',p)
	{
		if (p != Pawn)
		{
			VectToEnemy = p.Location - Pawn.Location;
			DistToEnemy = VSize(VectToEnemy);
			if (fViewDist <= 0 || DistToEnemy <= fViewDist)
			{
				VectToEnemy /= DistToEnemy;
				if (VectToEnemy Dot VectOfVision > fCosVisionAngle)
				{
					if (FastTrace(p.Location,Eye) || FastTrace(p.Location + p.CollisionHeight * vect(0 0 1),Eye) || FastTrace(p.Location - p.CollisionHeight * vect(0 0 1),Eye))
					{
						bSeen = true;
					}
				}
			}
		}
		else
		{
		}
	}
	*/
	return bSeen;
}

void AAA2_CameraController::SetEnemySpottedMonitor(UScriptObject* esm)
{
	_EnemySpottedMonitor = esm;
}
