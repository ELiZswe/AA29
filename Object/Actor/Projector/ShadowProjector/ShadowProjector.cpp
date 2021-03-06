// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projector/ShadowProjector/ShadowProjector.h"

AShadowProjector::AShadowProjector()
{
	RootMotion = true;
	bShadowActive = true;
	bProjectActor = false;
	bClipBSP = true;
	bGradient = true;
	bProjectOnAlpha = true;
	bDynamicAttach = true;
	//CullDistance = 1200;
	//bStatic = false;
	//bOwnerNoSee = true;
}

void AShadowProjector::PostBeginPlay()
{
	Super::PostBeginPlay();
}

void AShadowProjector::Destroyed()
{
	/*
	if (ShadowTexture != nullptr)
	{
		ShadowTexture.ShadowActor = nullptr;
		if (!ShadowTexture.Invalid)
		{
			Level.ObjectPool.FreeObject(ShadowTexture);
		}
		ShadowTexture = nullptr;
		ProjTexture = nullptr;
	}
	Super::Destroyed();
	*/
}

void AShadowProjector::InitShadow()
{
	FPlane BoundingSphere = FPlane({});
	/*
	if (ShadowActor != nullptr)
	{
		BoundingSphere = ShadowActor.GetRenderBoundingSphere();
		FOV = int(((Atan(((BoundingSphere.W * 2) + float(160)), LightDistance) * float(180)) / 3.141593));
		ShadowTexture = ShadowBitmapMaterial(Level.ObjectPool.AllocateObject(Class'ShadowBitmapMaterial'));
		ProjTexture = ShadowTexture;
		if (ShadowTexture != nullptr)
		{
			SetDrawScale(((LightDistance * Tan((((0.5 * float(FOV)) * 3.141593) / float(180)))) / (0.5 * float(ShadowTexture.USize))));
			ShadowTexture.Invalid = false;
			ShadowTexture.ShadowActor = ShadowActor;
			ShadowTexture.LightDirection = Normal(LightDirection);
			ShadowTexture.LightDistance = LightDistance;
			ShadowTexture.LightFOV = float(FOV);
			ShadowTexture.CullDistance = CullDistance;
			Enable("Tick");
			UpdateShadow();
		}
		else
		{
			Log(string(Name) + ".InitShadow: Failed to allocate texture");
		}
	}
	else
	{
		Log(string(Name) + ".InitShadow: No actor");
	}
	*/
}

void AShadowProjector::UpdateShadow()
{
	FCoords C;
	FPlane BoundingSphere;
	APawn* OwningPawn = nullptr;
	DetachProjector(true);
	/*
	if ((Level.GRI != nullptr) && Level.GRI.bForceShadowsOff)
	{
		return;
	}
	if ((Level.ShadowDetail == 0) || (LightDistance == 0))
	{
		return;
	}
	OwningPawn = Cast<APawn>(ShadowActor);
	if ((((((OwningPawn != nullptr) && (OwningPawn.ShadowDarkness < 255)) && (!ShadowActor.bHidden)) && ((GetWorld()->GetTimeSeconds() - ShadowActor.LastRenderTime) < 4)) && (ShadowTexture != nullptr)) && bShadowActive)
	{
		if (ShadowTexture.Invalid)
		{
			Destroy();
		}
		else
		{
			BoundingSphere = ShadowActor.GetRenderBoundingSphere();
			FOV = int(((Atan(((BoundingSphere.W * 2) + float(160)), LightDistance) * float(180)) / 3.141593));
			SetDrawScale(((LightDistance * Tan((((0.5 * float(FOV)) * 3.141593) / float(180)))) / (0.5 * float(ShadowTexture.USize))));
			ShadowTexture.LightDirection = Normal(LightDirection);
			ShadowTexture.LightDistance = LightDistance;
			ShadowTexture.LightFOV = float(FOV);
			if ((RootMotion && (ShadowActor.DrawType == 2)) && (ShadowActor.Mesh != nullptr))
			{
				C = ShadowActor.GetBoneCoords("None");
				SetActorLocation(C.Origin);
			}
			else
			{
				SetActorLocation((ShadowActor.Location + FVector(0, 0, 5)));
			}
			SetActorRotation(rotator(Normal((-LightDirection))));
			ShadowTexture.Dirty = true;
			if (Level.bDropDetail)
			{
				ShadowTexture.CullDistance = (0.7 * CullDistance);
			}
			else
			{
				ShadowTexture.CullDistance = CullDistance;
			}
			AttachProjector();
		}
	}
	*/
}

void AShadowProjector::Tick(float DeltaTime)
{
	UpdateShadow();
}

void AShadowProjector::LightUpdate(TArray<AActor*> LightSources, TArray<float> LightRadii, TArray<FVector> LightDirections)
{
	float MeanDistance = 0;
	float dx = 0;
	float dist_scalar = 0;
	float ClosestLightScalar = 0;
	float diff = 0;
	FVector MeanDirection = FVector(0, 0, 0);
	FVector dv = FVector(0, 0, 0);
	FVector DownDir = FVector(0, 0, 0);
	int32 LightCount = 0;
	int32 i = 0;
	int32 ClosestLightIndex = 0;
	TArray<float> DistContributions = {};
	TArray<float> DistScalar = {};
	/*
	if (LightSources.Num() == 0)
	{
		LightDistance = 0;
		return;
	}
	DownDir = FVector(0, 0, 1);
	if (Level.ShadowDetail == 1)
	{
		LightDistance = 50;
		LightDirection = DownDir;
		return;
	}
	else
	{
		LightCount = LightSources.Num();
		DistContributions.Num() = LightCount;
		DistScalar.Num() = LightCount;
		for (i = 0; i < LightCount; i++)
		{
			if (LightSources[i].LightEffect == 20)
			{
				MeanDirection -= LightDirections[i];
				DistContributions[i] = 150;
				DistScalar[i] = 1;
			}
			else
			{
				dx = VSize((LightSources[i].Location - Owner.Location));
				if (dx < LightRadii[i])
				{
					dist_scalar = ((LightRadii[i] - dx) / LightRadii[i]);
					dv = ((LightSources[i].Location - Owner.Location) / dx);
					DistScalar[i] = dist_scalar;
					DistContributions[i] = dx;
					dv *= dist_scalar;
					MeanDirection += dv;
				}
			}
		}
	}
	if (LightCount == 1)
	{
		MeanDistance = DistContributions[0];
	}
	else
	{
		for (i = 0; i < LightCount; i++)
		{
			if (DistScalar[i] > ClosestLightScalar)
			{
				ClosestLightIndex = i;
				ClosestLightScalar = DistScalar[i];
			}
		}
		MeanDistance = DistContributions[ClosestLightIndex];
		for (i = 0; i < LightCount; i++)
		{
			if (i != ClosestLightIndex)
			{
				diff = (DistContributions[i] - DistContributions[ClosestLightIndex]);
				MeanDistance += (DistContributions[ClosestLightIndex] + (diff * DistScalar[i]));
			}
		}
		MeanDistance /= float(LightCount);
	}
	LightDistance = float(Clamp(int(MeanDistance), 150, 2000));
	LightDirection = Normal(MeanDirection);
	if (LightDirection.Z < 0.5)
	{
		LightDirection.Z = 0.5;
		LightDirection = Normal(LightDirection);
	}
	*/
}
