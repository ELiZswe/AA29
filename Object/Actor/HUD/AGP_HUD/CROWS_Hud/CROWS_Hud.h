// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "CROWS_Hud.generated.h"

UCLASS()
class ACROWS_Hud : public AAGP_HUD
{
	GENERATED_BODY()
public:
	ACROWS_Hud(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()		FColor				CROWS_HUDColor;				//var Color CROWS_HUDColor;
	UPROPERTY()		FColor				CROWS_HUDRedColor;			//var Color CROWS_HUDRedColor;
	UPROPERTY()		float				CrosshairX;					//var float CrosshairX;
	UPROPERTY()		float				CrosshairY;					//var float CrosshairY;
	UPROPERTY()		float				CrosshairOffX;				//var float CrosshairOffX;
	UPROPERTY()		float				CrosshairOffY;				//var float CrosshairOffY;
	UPROPERTY()		float				CrosshairDrawX;				//var float CrosshairDrawX;
	UPROPERTY()		float				CrosshairDrawY;				//var float CrosshairDrawY;
	UPROPERTY()		float				CrosshairDrawOffX;			//var float CrosshairDrawOffX;
	UPROPERTY()		float				CrosshairDrawOffY;			//var float CrosshairDrawOffY;
	UPROPERTY()		UMaterialInstance*	CrosshairTexture;			//var UTexture* CrosshairTexture;
	UPROPERTY()		UMaterialInstance*	CrosshairDeadTexture;		//var UTexture* CrosshairDeadTexture;
	UPROPERTY()		float				SideMeterX;					//var float SideMeterX;
	UPROPERTY()		float				SideMeterY;					//var float SideMeterY;
	UPROPERTY()		float				SideMeterOffX;				//var float SideMeterOffX;
	UPROPERTY()		float				SideMeterOffY;				//var float SideMeterOffY;
	UPROPERTY()		float				SideMeterDrawX;				//var float SideMeterDrawX;
	UPROPERTY()		float				SideMeterDrawY;				//var float SideMeterDrawY;
	UPROPERTY()		float				SideMeterDrawOffX;			//var float SideMeterDrawOffX;
	UPROPERTY()		float				SideMeterDrawOffY;			//var float SideMeterDrawOffY;
	UPROPERTY()		UMaterialInstance*	SideMeterTexture;			//var UTexture* SideMeterTexture;
	UPROPERTY()		FString				AmmoType;					//var FString AmmoType;
	UPROPERTY()		float				AmmoIconX;					//var float AmmoIconX;
	UPROPERTY()		float				AmmoIconY;					//var float AmmoIconY;
	UPROPERTY()		float				AmmoIconOffX;				//var float AmmoIconOffX;
	UPROPERTY()		float				AmmoIconOffY;				//var float AmmoIconOffY;
	UPROPERTY()		float				AmmoIconDrawX;				//var float AmmoIconDrawX;
	UPROPERTY()		float				AmmoIconDrawY;				//var float AmmoIconDrawY;
	UPROPERTY()		float				AmmoIconDrawOffX;			//var float AmmoIconDrawOffX;
	UPROPERTY()		float				AmmoIconDrawOffY;			//var float AmmoIconDrawOffY;
	UPROPERTY()		UMaterialInstance*	AmmoIconTexture;			//var UTexture* AmmoIconTexture;
	UPROPERTY()		float				ArrowX;						//var float ArrowX;
	UPROPERTY()		float				ArrowY;						//var float ArrowY;
	UPROPERTY()		float				ArrowOffX;					//var float ArrowOffX;
	UPROPERTY()		float				ArrowOffY;					//var float ArrowOffY;
	UPROPERTY()		float				ArrowDrawX;					//var float ArrowDrawX;
	UPROPERTY()		float				ArrowDrawY;					//var float ArrowDrawY;
	UPROPERTY()		float				ArrowDrawOffX;				//var float ArrowDrawOffX;
	UPROPERTY()		float				ArrowDrawOffY;				//var float ArrowDrawOffY;
	UPROPERTY()		UMaterialInstance*	ArrowLeftTexture;			//var UTexture* ArrowLeftTexture;
	UPROPERTY()		UMaterialInstance*	ArrowRightTexture;			//var UTexture* ArrowRightTexture;
	UPROPERTY()		float				CompassOffX;				//var float CompassOffX;
	UPROPERTY()		float				CompassOffY;				//var float CompassOffY;
	UPROPERTY()		float				CompassDrawOffX;			//var float CompassDrawOffX;
	UPROPERTY()		float				CompassDrawOffY;			//var float CompassDrawOffY;
	UPROPERTY()		UMaterialInstance*	Compass;					//var UTexRotator* Compass;
	UPROPERTY()		float				VehicleCompassOffX;			//var float VehicleCompassOffX;
	UPROPERTY()		float				VehicleCompassOffY;			//var float VehicleCompassOffY;
	UPROPERTY()		float				VehicleCompassDrawOffX;		//var float VehicleCompassDrawOffX;
	UPROPERTY()		float				VehicleCompassDrawOffY;		//var float VehicleCompassDrawOffY;
	UPROPERTY()		UMaterialInstance*	VehicleCompass;				//var UTexRotator* VehicleCompass;
	UPROPERTY()		float				CompassArrowOffX;			//var float CompassArrowOffX;
	UPROPERTY()		float				CompassArrowOffY;			//var float CompassArrowOffY;
	UPROPERTY()		float				CompassArrowDrawOffX;		//var float CompassArrowDrawOffX;
	UPROPERTY()		float				CompassArrowDrawOffY;		//var float CompassArrowDrawOffY;
	UPROPERTY()		UMaterialInstance*	CompassArrow;				//var UTexRotator* CompassArrow;
	UPROPERTY()		int32				ProgBarX;					//var int32 ProgBarX;
	UPROPERTY()		int32				ProgBarY;					//var int32 ProgBarY;
	UPROPERTY()		int32				ProgBarOffX;				//var int32 ProgBarOffX;
	UPROPERTY()		int32				ProgBarOffY;				//var int32 ProgBarOffY;
	UPROPERTY()		int32				ProgBarDrawX;				//var int32 ProgBarDrawX;
	UPROPERTY()		int32				ProgBarDrawY;				//var int32 ProgBarDrawY;
	UPROPERTY()		int32				ProgBarDrawOffX;			//var int32 ProgBarDrawOffX;
	UPROPERTY()		int32				ProgBarDrawOffY;			//var int32 ProgBarDrawOffY;
	UPROPERTY()		UMaterialInstance*	ProgBarTexture;				//var UTexture* ProgBarTexture;
	UPROPERTY()		float				ProgBarCounter;				//var float ProgBarCounter;
	UPROPERTY()		float				ProgIndicatorX;				//var float ProgIndicatorX;
	UPROPERTY()		float				ProgIndicatorY;				//var float ProgIndicatorY;
	UPROPERTY()		int32				ProgIndicatorDrawX;			//var int32 ProgIndicatorDrawX;
	UPROPERTY()		int32				ProgIndicatorDrawY;			//var int32 ProgIndicatorDrawY;
	UPROPERTY()		UMaterialInstance*	ProgIndicatorTexture;		//var UTexture* ProgIndicatorTexture;
	UPROPERTY()		bool				bPlayProgressBar;			//var bool bPlayProgressBar;
	UPROPERTY()		int32				TiltWarnOffX;				//var int32 TiltWarnOffX;
	UPROPERTY()		int32				TiltWarnOffY;				//var int32 TiltWarnOffY;
	UPROPERTY()		int32				TiltWarnThreshold;			//var int32 TiltWarnThreshold;
	UPROPERTY()		int32				LasingOffX;					//var int32 LasingOffX;
	UPROPERTY()		int32				LasingOffY;					//var int32 LasingOffY;
	UPROPERTY()		int32				LasingDrawX;				//var int32 LasingDrawX;
	UPROPERTY()		int32				LasingDrawY;				//var int32 LasingDrawY;
	UPROPERTY()		bool				bIsLasing;					//var bool bIsLasing;
	UPROPERTY()		bool				bDrawLased;					//var bool bDrawLased;
	UPROPERTY()		UMaterialInstance*	LasingCrosshairTexture;		//var UTexture* LasingCrosshairTexture;
	UPROPERTY()		UMaterialInstance*	DayScopeTexture;			//var UTexture* DayScopeTexture;
	UPROPERTY()		int32				Ammo;						//var int32 Ammo;
	UPROPERTY()		int32				MaxAmmo;					//var int32 MaxAmmo;
	UPROPERTY()		bool				Stabilized;					//var bool Stabilized;
	UPROPERTY()		int32				YawOffset;					//var int32 YawOffset;
	UPROPERTY()		float				FOVReadout;					//var float FOVReadout;
	UPROPERTY()		int32				LaseDistance;				//var int32 LaseDistance;
	UPROPERTY()		int32				Elevation;					//var int32 Elevation;
	UPROPERTY()		int32				LaseRechargeTime;			//var int32 LaseRechargeTime;
	UPROPERTY()		float				xRatio;						//var float xRatio;
	UPROPERTY()		float				yRatio;						//var float yRatio;
	UPROPERTY()		UCanvas*			parentCanvas;				//var UCanvas* parentCanvas;

	FColor MakeCanvasColor(uint8 R, uint8 G, uint8 B, uint8 A);
	void CenterDraw(UCanvas* Canvas, UMaterialInstance* mat, float X, float Y, float UScale, float VScale, bool bStretched);
	void ScaleTextureValues();
	void DrawString(int32 XPos, int32 YPos, FString Text);
	void SetupFonts(UCanvas* C);
	void CalculateAzimuth();
	void CalculateElevation();
	bool ShouldDisplayMOTD();
	void DrawHUD();
	void DrawLased();
	void FinishDrawingLase();
	void SetAmmo(int32 aAmmo);
	void SetFOV(float aFOV);
	int32 FOVToZoom(float FOV);
	void SetStabilization(bool flag);
	void SetLaseDistance(float aLaseDistance);
	void Tick(float DeltaTime);
};
