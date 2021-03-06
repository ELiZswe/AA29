// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "Projector.generated.h"

class ADecoMesh;

UCLASS()
class AProjector : public ADecalActor
{
	GENERATED_BODY()
public:
	AProjector();

	UPROPERTY(EditAnywhere)			EProjectorBlending			MaterialBlendingOp;					//var() Enum EProjectorBlending MaterialBlendingOp
	UPROPERTY(EditAnywhere)			EProjectorBlending			FrameBufferBlendingOp;				//var() Enum EProjectorBlending FrameBufferBlendingOp
	UPROPERTY(EditAnywhere)			UMaterialInstance*			ProjTexture;						//var() Material ProjTexture;
	UPROPERTY(EditAnywhere)			int32						FOV;								//var() int32 FOV;
	UPROPERTY(EditAnywhere)			int32						MaxTraceDistance;					//var() int32 MaxTraceDistance;
	UPROPERTY(EditAnywhere)			bool						bProjectBSP;						//var() bool bProjectBSP;
	UPROPERTY(EditAnywhere)			bool						bProjectTerrain;					//var() bool bProjectTerrain;
	UPROPERTY(EditAnywhere)			bool						bProjectStaticMesh;					//var() bool bProjectStaticMesh;
	UPROPERTY(EditAnywhere)			bool						bProjectParticles;					//var() bool bProjectParticles;
	UPROPERTY(EditAnywhere)			bool						bProjectActor;						//var() bool bProjectActor;
	UPROPERTY(EditAnywhere)			bool						bLevelStatic;						//var() bool bLevelStatic;
	UPROPERTY(EditAnywhere)			bool						bClipBSP;							//var() bool bClipBSP;
	UPROPERTY(EditAnywhere)			bool						bClipStaticMesh;					//var() bool bClipStaticMesh;
	UPROPERTY(EditAnywhere)			bool						bProjectOnUnlit;					//var() bool bProjectOnUnlit;
	UPROPERTY(EditAnywhere)			bool						bGradient;							//var() bool bGradient;
	UPROPERTY(EditAnywhere)			bool						bProjectOnBackfaces;				//var() bool bProjectOnBackfaces;
	UPROPERTY(EditAnywhere)			bool						bProjectOnAlpha;					//var() bool bProjectOnAlpha;
	UPROPERTY(EditAnywhere)			bool						bProjectOnParallelBSP;				//var() bool bProjectOnParallelBSP;
	UPROPERTY(EditAnywhere)			FName						ProjectTag;							//var() FName ProjectTag;
	UPROPERTY(EditAnywhere)			bool						bDynamicAttach;						//var() bool bDynamicAttach;
	UPROPERTY(EditAnywhere)			bool						bNoProjectOnOwner;					//var() bool bNoProjectOnOwner;
	UPROPERTY()						float						FadeInTime;							//var float FadeInTime;
	UPROPERTY()						TArray<FPlane>						FrustumPlanes;						//var const transient Plane FrustumPlanes[6];
	UPROPERTY()						TArray<FVector>						FrustumVertices;					//var const transient Vector FrustumVertices[8];
	UPROPERTY()						FBox						Box;								//var const transient Box Box;
	UPROPERTY()						FProjectorRenderInfoPtr		RenderInfo;							//var const native Actor.ProjectorRenderInfoPtr RenderInfo;
	UPROPERTY()						UMaterialInstance*			GradientTexture;					//var Texture GradientTexture;
	UPROPERTY()						FMatrix						GradientMatrix;						//var transient Matrix GradientMatrix;
	UPROPERTY()						FMatrix						Matrix;								//var transient Matrix Matrix;
	UPROPERTY()						FVector						OldLocation;						//var transient Vector OldLocation;
	UPROPERTY()						bool						bDrawLast;							//var bool bDrawLast;
	UPROPERTY()						bool						bLargeProjector;					//var const bool bLargeProjector;
	UPROPERTY()						bool						bDecalProjector;					//var const bool bDecalProjector;
	UPROPERTY()						int32						UID;								//var const int32 UID;
	UPROPERTY()						float						Expires;							//var const float Expires;
	UPROPERTY()						bool						bMoverProjector;					//var const bool bMoverProjector;
	UPROPERTY()						int32						M_UID;								//var const int32 M_UID;
	UPROPERTY()						ADecoMesh*					AttachedToDeco;						//var const DecoMesh AttachedToDeco;
	UPROPERTY()						AActor*						ActorToIgnore;						//var Actor ActorToIgnore;
	UPROPERTY(EditAnywhere)			bool						bNoProjectOnFirstPersonWeapons;		//var() bool bNoProjectOnFirstPersonWeapons;

	void SetDecoProjector(AActor* AttachTo);
	void ReleaseUID();
	void AttachProjector(float FadeInTime);
	void DetachProjector(bool Force);
	void AbandonProjector(float Lifetime);
	void ExpireProjector(float Lifetime);
	void AttachActor(AActor* A);
	void DetachActor(AActor* A);
	void NotifyRenderInfoExpired();
	void SetupProjector(bool bRoll, int32 TEST_ROLL);
	void PostBeginPlay();
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
