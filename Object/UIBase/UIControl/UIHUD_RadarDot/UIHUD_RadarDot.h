// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIHUD_RadarDot.generated.h"

class UUIHUD_Radar;

UCLASS()
class UUIHUD_RadarDot : public UUIControl
{
	GENERATED_BODY()
public:
	UUIHUD_RadarDot();

	UPROPERTY()										UUIHUD_Radar* MyRadar;					//var UIHUD_Radar MyRadar;
	UPROPERTY()										FPosition PlayerXY;						//var UIBase.Position PlayerXY;
	UPROPERTY()										float dot_size;							//var float dot_size;
	UPROPERTY()										float Y;								//var float Y;
	UPROPERTY()										float X;								//var float X;
	UPROPERTY()										UMaterialInstance* _tPlayerDot;			//var Material _tPlayerDot;
	UPROPERTY()										bool bVisible;							//var bool bVisible;

	void SetMyRadar(UUIHUD_Radar* NewRadar);
	void Draw(UCanvas* C);
	void DrawPlayerDot(UCanvas* C);
	void UpdatePlayerDot();
	void SetRadarDotXY(float new_x, float new_y);
	float GetDistanceSquared();

};
