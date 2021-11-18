// All the original content belonged to the US Army


#include "AA29/Object/Spline/Spline.h"

USpline::USpline()
{

}


//native simulated final Function InitSplinePath(float t0, FVector d0, FVector v0, float t1, FVector d1, FVector v1);
void USpline::InitSplinePath(float t0, FVector d0, FVector v0, float t1, FVector d1, FVector v1)
{
}

//native simulated final Function InitSplineRot(float t0, FRotator d0, FRotator v0, float t1, FRotator d1, FRotator v1);
void USpline::InitSplineRot(float t0, FRotator d0, FRotator v0, float t1, FRotator d1, FRotator v1)
{
}

//native simulated final Function NextSplinePos(float dt, out FVector D, out FVector V, out FVector A, out float outdt, optional bool bSmoothDt, optional bool bAccumDeltas);
void USpline::NextSplinePos(float dt, FVector &D, FVector &V, FVector &A, float &outdt, bool bSmoothDt, bool bAccumDeltas)
{
}

//native simulated final Function NextSplineRot(float dt, out FRotator D, out FRotator V, out FRotator A, out float outdt, optional bool bSmoothDt, optional bool bAccumDeltas);
void USpline::NextSplineRot(float dt, FRotator &D, FRotator &V, FRotator &A, float& outdt, bool bSmoothDt, bool bAccumDeltas)
{
}
