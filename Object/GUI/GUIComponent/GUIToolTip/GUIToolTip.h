// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIToolTip.generated.h"

UCLASS(Config = Game)
class UGUIToolTip : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIToolTip();

	UPROPERTY(EditAnywhere)							bool				bResetPosition;			//var() bool bResetPosition;
	UPROPERTY(EditAnywhere)							bool				bTrackMouse;			//var() bool bTrackMouse;
	UPROPERTY(EditAnywhere)							bool				bMultiLine;				//var() bool bMultiLine;
	UPROPERTY(EditAnywhere)							bool				bTrackInput;			//var() bool bTrackInput;
	UPROPERTY(EditAnywhere)							FString				Text;					//var() const FString Text;
	UPROPERTY(EditAnywhere)							TArray<FString>		Lines;					//var() const TArray<FString> Lines;
	UPROPERTY(EditAnywhere)							float				StartTime;				//var() noexport float StartTime;
	UPROPERTY(EditAnywhere)							float				CurrentTime;			//var() noexport float CurrentTime;
	UPROPERTY(EditAnywhere, globalconfig)			float				MaxWidth;				//var() globalconfig float MaxWidth;
	UPROPERTY(EditAnywhere, globalconfig)			float				InitialDelay;			//var() globalconfig float InitialDelay;
	UPROPERTY(EditAnywhere, globalconfig)			float				ExpirationSeconds;		//var() globalconfig float ExpirationSeconds;

	UGUIToolTip* EnterArea();
	UGUIToolTip* InternalEnterArea();
	bool LeaveArea();
	bool InternalLeaveArea();
	void Tick(float RealSeconds);
	void ShowToolTip();
	void HideToolTip();
	void UpdatePosition(UCanvas* C);
	float GetLeft(UCanvas* C);
	float GetTop(UCanvas* C);
	float GetWidth(UCanvas* C);
	float GetHeight(UCanvas* C);
	float GetTopAboveCursor(UCanvas* C);
	float GetTopBelowCursor(UCanvas* C);
	void SetTip(FString NewTip);

};
