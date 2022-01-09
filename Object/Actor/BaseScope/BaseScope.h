// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "BaseScope.generated.h"


UCLASS()
class ABaseScope : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABaseScope();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				bHasNVMode;				//var bool bHasNVMode;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				bUseAimAdjust;			//var bool bUseAimAdjust;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				bInstantZoom;			//var bool bInstantZoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				bAux3dSights;			//var bool bAux3dSights;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				bUseScopeWeaponFOV;		//var bool bUseScopeWeaponFOV;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				b3dSights;				//var bool b3dSights;
	UPROPERTY()										int32				_iScopePosX;			//var int _iScopePosX;
	UPROPERTY()										int32				_iScopeSize;			//var int _iScopeSize;
	UPROPERTY()										int32				_iOldSizeY;				//var int _iOldSizeY;
	UPROPERTY()										int32				_iOldSizeX;				//var int _iOldSizeX;
	UPROPERTY()										int32				iZoomFOV;				//var int iZoomFOV;
	UPROPERTY(EditAnywhere)		int32				iYawOffset;				//var() int iYawOffset;
	UPROPERTY(EditAnywhere)		int32				iPitchOffset;			//var() int iPitchOffset;
	UPROPERTY()										float				ScopeZoomAnimFOV;		//var float ScopeZoomAnimFOV;
	UPROPERTY()										float				fZoomMultiplier;		//var float fZoomMultiplier;
	UPROPERTY()										float				fPreZoomFOV;			//var float fPreZoomFOV;
	UPROPERTY()										UMaterialInstance*	tZoomOverlayMILES;		//var Texture tZoomOverlayMILES;
	UPROPERTY()										UMaterialInstance*	tZoomOverlay;			//var Texture tZoomOverlay;
	UPROPERTY()										TArray<float>		aZoomFOV;				//var array<float> aZoomFOV;
	UPROPERTY()										EDrawType			DrawType;
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	void ZoomOut(APlayerController* PC);
	void ZoomIn(APlayerController* PC);
	void CycleZoom(APlayerController* PC);
	void UnZoom(APlayerController* PC);
	float GetaZoomFOV();
	void Zoom(APlayerController* PC);
	bool IsZoomed();
	float GetZoomMultiplier();
	bool HasNVMode();
	UMaterialInstance* GetZoomOverlay();
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	void VerticalMinuteAngle(bool increase);
	void LateralMinuteAngle(bool increase);
	void Zero();
	FRotator GetAimAdjustment();
};
