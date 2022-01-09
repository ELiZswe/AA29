// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "GameFramework/Actor.h"
#include "xEmitter.generated.h"

class UBillboardComponent;
class USceneComponent;
class ALevelInfo;

UCLASS()
class AxEmitter : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AxEmitter();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()											int32 mHeadIndex;								//var transient int mHeadIndex;
	UPROPERTY()											bool bCallPreSpawn;								//var bool bCallPreSpawn;
	UPROPERTY()											bool blockOnNet;								//var bool blockOnNet;
	UPROPERTY()											float mWavePhaseB;								//var transient float mWavePhaseB;
	UPROPERTY()											float mWavePhaseA;								//var transient float mWavePhaseA;
	UPROPERTY()											int32 mNumSprings;								//var transient int mNumSprings;
	UPROPERTY()											Fpointer mpSprings;								//var transient pointer mpSprings;
	UPROPERTY()											float mInvTileCols;								//var transient float mInvTileCols;
	UPROPERTY()											float mTotalTiles;								//var transient float mTotalTiles;
	UPROPERTY()											float mTexV;									//var transient float mTexV;
	UPROPERTY()											float mTexU;									//var transient float mTexU;
	UPROPERTY()											int32 mRenderableVerts;							//var transient int mRenderableVerts;
	UPROPERTY()											int32 mAtLeastOneFrame;							//var transient int mAtLeastOneFrame;
	UPROPERTY()											int32 mNumUpdates;								//var transient int mNumUpdates;
	UPROPERTY()											FVector mDir;									//var transient FVector mDir;
	UPROPERTY()											FPlane mSphere;									//var transient Object.Plane mSphere;
	UPROPERTY()											FBox mBounds;									//var transient Object.Box mBounds;
	UPROPERTY()											float mPauseTimer;								//var transient float mPauseTimer;
	UPROPERTY()											float mRegenTimer;								//var transient float mRegenTimer;
	UPROPERTY()											float mRegenBias;								//var transient float mRegenBias;
	UPROPERTY()											float mT;										//var transient float mT;
	UPROPERTY()											float mTime;									//var transient float mTime;
	UPROPERTY()											FVector mLastVector;							//var transient FVector mLastVector;
	UPROPERTY()											FVector mLastPos;								//var transient FVector mLastPos;
	UPROPERTY()											int32 mbSpinningNodes;							//var transient int mbSpinningNodes;
	UPROPERTY()											Fpointer mpIterator;							//var transient pointer mpIterator;
	UPROPERTY()											int32 mNumActivePcl;							//var transient int mNumActivePcl;
	UPROPERTY()											Fpointer nSubordinates;							//var transient pointer mpParticles;
	UPROPERTY()											int32 mpParticles;								//var transient int Expire;
	UPROPERTY()											int32 SystemHandle;								//var transient int SystemHandle;
	UPROPERTY()											bool bForceAffected;							//var(Force) bool bForceAffected;
	UPROPERTY(EditAnywhere, Category = "pclBeam")		bool mWaveLockEnd;								//var(pclBeam) bool mWaveLockEnd;
	UPROPERTY(EditAnywhere, Category = "pclBeam")		float mBendStrength;							//var(pclBeam) float mBendStrength;
	UPROPERTY(EditAnywhere, Category = "pclBeam")		float mWaveShift;								//var(pclBeam) float mWaveShift;
	UPROPERTY(EditAnywhere, Category = "pclBeam")		float mWaveAmplitude;							//var(pclBeam) float mWaveAmplitude;
	UPROPERTY(EditAnywhere, Category = "pclBeam")		float mWaveFrequency;							//var(pclBeam) float mWaveFrequency;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	bool mColMakeSound;								//var(PclMovement) bool mColMakeSound;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	float mAttraction;								//var(PclMovement) float mAttraction;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	float mColElasticity;							//var(PclMovement) float mColElasticity;
	UPROPERTY(EditAnywhere, Category = "PclSoftBody")	float springMaxCompress;						//var(PclSoftBody) float springMaxCompress;
	UPROPERTY(EditAnywhere, Category = "PclSoftBody")	float springMaxStretch;							//var(PclSoftBody) float springMaxStretch;
	UPROPERTY(EditAnywhere, Category = "PclSoftBody")	float springD;									//var(PclSoftBody) float springD;
	UPROPERTY(EditAnywhere, Category = "PclSoftBody")	float springK;									//var(PclSoftBody) float springK;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	UTexture2D* mLifeColorMap;						//var(PclVisuals) Texture mLifeColorMap;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	UTexture2D* mPosColorMapXZ;						//var(PclVisuals) Texture mPosColorMapXZ;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	UTexture2D* mPosColorMapXY;						//var(PclVisuals) Texture mPosColorMapXY;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mMeshNodes;								//var(PclVisuals) StaticMesh mMeshNodes;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mRandMeshes;								//var(PclVisuals) bool mRandMeshes;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mUseMeshNodes;							//var(PclVisuals) bool mUseMeshNodes;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mNumTileRows;								//var(PclVisuals) int mNumTileRows;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mNumTileColumns;							//var(PclVisuals) int mNumTileColumns;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mTileAnimation;							//var(PclVisuals) bool mTileAnimation;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	int32 mRandTextures;							//var(PclVisuals) bool mRandTextures;
	UPROPERTY()											int32 mpAttenFunc;								//var int mpAttenFunc;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	EAttenFunc mAttenFunc;							//var(PclVisuals) EAttenFunc mAttenFunc;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	float mAttenKb;									//var(PclVisuals) float mAttenKb;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	float mAttenKa;									//var(PclVisuals) float mAttenKa;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	bool mAttenuate;								//var(PclVisuals) bool mAttenuate;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	TArray<FColor> mColorRange;						//var(PclVisuals) Object.Color mColorRange;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	float mGrowthRate;								//var(PclVisuals) float mGrowthRate;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	TArray<float> mSizeRange;						//var(PclVisuals) float mSizeRange;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	TArray<float> mSpinRange;						//var(PclMovement) float mSpinRange;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	bool mRandOrient;								//var(PclVisuals) bool mRandOrient;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	float mOwnerVelocityFactor;						//var(PclMovement) float mOwnerVelocityFactor;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	bool mCollision;								//var(PclMovement) bool mCollision;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	float mAirResistance;							//var(PclMovement) float mAirResistance;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	TArray<float> mMassRange;						//var(PclMovement) float mMassRange;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	bool mPosRelative;								//var(PclMovement) bool mPosRelative;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	TArray<float> mSpeedRange;						//var(PclMovement) float mSpeedRange;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	FVector mSpawnVecB;								//var(PclMovement) FVector mSpawnVecB;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	FVector mSpawnVecA;								//var(PclMovement) FVector mSpawnVecA;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	FVector mPosDev;								//var(PclMovement) FVector mPosDev;
	UPROPERTY(EditAnywhere, Category = "PclMovement")	FVector mDirDev;								//var(PclMovement) FVector mDirDev;
	UPROPERTY(EditAnywhere, Category = "PclVisuals")	bool mDistanceAtten;							//var(PclVisuals) bool mDistanceAtten;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	bool bSuspendWhenNotVisible;					//var(PclEmitter) bool bSuspendWhenNotVisible;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	UStaticMesh* SourceStaticMesh;					//var(PclEmitter) StaticMeshActor SourceStaticMesh;
	UPROPERTY()											AxEmitter* mChildEmitter;						//var xEmitter mChildEmitter;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	FName mChildName;								//var(PclEmitter) name mChildName;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	FName mSourceActor;								//var(PclEmitter) name mSourceActor;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	float mRegenDist;								//var(PclEmitter) float mRegenDist;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	TArray<float> mRegenRange;						//var(PclEmitter) float mRegenRange;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	TArray<float> mLifeRange;						//var(PclEmitter) float mLifeRange;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	TArray<float> mDelayRange;						//var(PclEmitter) float mDelayRange;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	int32 mMaxParticles;							//var(PclEmitter) int mMaxParticles;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	int32 mStartParticles;							//var(PclEmitter) int mStartParticles;			// at runtime also, you can set this > 0 to spawn this many next tick
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	float mRegenOffTime;							//var(PclEmitter) float mRegenOffTime;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	float mRegenOnTime;								//var(PclEmitter) float mRegenOnTime;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	bool mRegenPause;								//var(PclEmitter) bool mRegenPause;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	int32 mRegen;									//var(PclEmitter) bool mRegen;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	ExSpawningTypes mSpawningType;					//var(PclEmitter) ExSpawningTypes mSpawningType;
	UPROPERTY(EditAnywhere, Category = "PclEmitter")	ExParticleTypes mParticleType;					//var(PclEmitter) ExParticleTypes mParticleType;

	UPROPERTY()										UTexture2D* Texture;
	UPROPERTY()										USceneComponent* Root;
	UPROPERTY()										UBillboardComponent* SpriteComponent;
	UPROPERTY(EditAnywhere)							TArray<UMaterialInstance*> OverrideMaterials;

	void CollisionSound();
	void PreSpawned();
	void ClampToMaxParticles(float InPart);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UpdatePrecacheMaterials();
	void PrecacheContent (ALevelInfo* Level);
	void LoadEditorIcon();
};
