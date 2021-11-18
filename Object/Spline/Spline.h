// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Spline.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USpline : public UObject
{
	GENERATED_BODY()
public:
	USpline();

	//const mMaxTimes = 5;


	UPROPERTY()						int32 mCnt;											//var int mCnt;
	UPROPERTY()						bool mbRotatorSpline;								//var bool mbRotatorSpline;
	UPROPERTY()						float mTotalTime;									//var float mTotalTime;
	UPROPERTY()						int32 mIndex;										//var int mIndex;
	UPROPERTY()						float maDeltaTimes;									//var float maDeltaTimes;
	UPROPERTY()						float mTime;										//var float mTime;
	UPROPERTY()						bool mbInit;										//var bool mbInit;
	UPROPERTY()						float mEndT;										//var float mEndT;
	UPROPERTY()						float mStartT;										//var float mStartT;
	UPROPERTY()						FRotator SplineH;									//var Object.Rotator SplineH;
	UPROPERTY()						FRotator SplineG;									//var Object.Rotator SplineG;
	UPROPERTY()						FRotator SplineF;									//var Object.Rotator SplineF;
	UPROPERTY()						FRotator SplineE;									//var Object.Rotator SplineE;
	UPROPERTY()						FVector SplineD;									//var Object.Vector SplineD;
	UPROPERTY()						FVector SplineC;									//var Object.Vector SplineC;
	UPROPERTY()						FVector SplineB;									//var Object.Vector SplineB;
	UPROPERTY()						FVector SplineA;									//var Object.Vector SplineA

	void InitSplinePath(float t0, FVector d0, FVector v0, float t1, FVector d1, FVector v1);
	void InitSplineRot(float t0, FRotator d0, FRotator v0, float t1, FRotator d1, FRotator v1);
	void NextSplinePos(float dt, FVector& D, FVector &V, FVector& A, float& outdt, bool bSmoothDt, bool bAccumDeltas);
	void NextSplineRot(float dt, FRotator& D, FRotator &V, FRotator& A, float& outdt, bool bSmoothDt, bool bAccumDeltas);

};
