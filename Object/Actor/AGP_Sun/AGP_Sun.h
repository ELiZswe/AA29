// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AGP_Sun.generated.h"

UCLASS()
class AAGP_Sun : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_Sun();

	UPROPERTY(EditAnywhere, Category = "Force")		TArray<FLensFlareDescriptor>	LensFlares;							//var(Sun) TArray<LensFlareDescriptor> LensFlares;
	UPROPERTY(EditAnywhere, Category = "Force")		FColor							WhiteOutColorAndAlpha;				//var(Sun) Color WhiteOutColorAndAlpha;
	UPROPERTY(EditAnywhere, Category = "Force")		float							WhiteOutRampFactor;					//var(Sun) float WhiteOutRampFactor;
	UPROPERTY(EditAnywhere, Category = "Force")		float							AngleToStartWhiteOut;				//var(Sun) float AngleToStartWhiteOut;
	UPROPERTY(EditAnywhere, Category = "Force")		float							AngleToStartLensFlares;				//var(Sun) float AngleToStartLensFlares;
	UPROPERTY(EditAnywhere, Category = "Force")		FColor							SunIntensityColorScalar;			//var(Sun) Color SunIntensityColorScalar;
	UPROPERTY(EditAnywhere, Category = "Force")		AActor*							bForceSunGlowSourceAffected;		//var(Sun) Actor SunGlowSource;
	UPROPERTY(EditAnywhere, Category = "Force")		bool							bForceCorona;						//var(Sun) bool bForceCorona;
	UPROPERTY(EditAnywhere, Category = "Force")		bool							bLensFlaresInEditor;				//var(Sun) bool bLensFlaresInEditor;
	UPROPERTY(EditAnywhere, Category = "Force")		bool							bShowVultureHead;					//var(Sun) bool bShowVultureHead;
	UPROPERTY()										FPlane							ScreenSpace_Position;				//var transient Plane ScreenSpace_Position;
	UPROPERTY()										float							ScreenCoordStackX;					//var transient float ScreenCoordStackX[16];
	UPROPERTY()										float							ScreenCoordStackY;					//var transient float ScreenCoordStackY[16];
	UPROPERTY()										int32							ScreenCoordStackPos;				//var transient int32 ScreenCoordStackPos;
	UPROPERTY()										int32							ScreenCoordRevision;				//var transient int32 ScreenCoordRevision;
	UPROPERTY()										int32							LastScreenCoordRevisionUsed;		//var transient int32 LastScreenCoordRevisionUsed;
	UPROPERTY()										bool							UsingGlow;							//var transient bool UsingGlow;
	UPROPERTY()										UMaterialInstance*				SunIntensityMaterial;				//var transient Material SunIntensityMaterial;
	UPROPERTY()										TArray<UMaterialInstance* >		LensFlareFinalBlends;				//var transient TArray<Material> LensFlareFinalBlends;

	void TestGlowCaps();
	void PostBeginPlay();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
