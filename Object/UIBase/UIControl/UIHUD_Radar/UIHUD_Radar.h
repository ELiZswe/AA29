// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIHUD_Radar.generated.h"

class UUIHUD_RadarDot;
/**
 * 
 */
UCLASS()
class AA29_API UUIHUD_Radar : public UUIControl
{
	GENERATED_BODY()
public:
	UUIHUD_Radar();


	UPROPERTY()										bool bInitialized;							//var bool bInitialized;
	UPROPERTY()										int32 MapSize;								//var int MapSize;
	UPROPERTY()										bool bMap;									//var bool bMap;
	UPROPERTY()										bool bFrontUp;								//var bool bFrontUp;
	UPROPERTY()										AAA2_PlayerState* myPRI;					//var PlayerReplicationInfo myPRI;
	UPROPERTY()										TArray<UUIHUD_RadarDot*> RadarDotPool;		//var array<UIHUD_RadarDot> RadarDotPool;
	UPROPERTY()										FPosition GridUV;							//var UIBase.Position GridUV;
	UPROPERTY()										float CurrentRange;							//var float CurrentRange;
	UPROPERTY()										FRange GridRange;							//var Object.Range GridRange;
	UPROPERTY()										UMaterialInstance* _tGrid;					//var Material _tGrid;

	void Initialize();
	bool ShouldDrawRadar();
	void Draw(UCanvas* C);
	void DrawRadarGrid(UCanvas* C);
	void UpdateRadarDots();
	void CreateNewRadarDot();
	void UpdateRadarDot(AAA2_PlayerState* PRI, int32 draw_number);
	bool ShouldDraw(AAA2_PlayerState* PRI);
	void UpdateCurrentRange(float max_distance);
	void SetCurrentRange(float NewRange);


};
