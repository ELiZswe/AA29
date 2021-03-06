// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAScoreboard_TeamSummary/AAScoreboard_TeamSummary.h"
#include "AAScoreboard_AutoScaleTeamSummar.generated.h"

UCLASS()
class UAAScoreboard_AutoScaleTeamSummar : public UAAScoreboard_TeamSummary
{
	GENERATED_BODY()
public:
	UAAScoreboard_AutoScaleTeamSummar();
	
	UPROPERTY()						int32				renderCounter;					//var int32 renderCounter;
	UPROPERTY()						int32				numUnassigned;					//var int32 numUnassigned;
	UPROPERTY()						int32				lastFireTeam;					//var int32 lastFireTeam;
	UPROPERTY()						float				mUnassignedMargin;				//var float mUnassignedMargin;
	UPROPERTY()						bool				bFullSpectatorPanel;			//var bool bFullSpectatorPanel;
	UPROPERTY()						bool				bToggleShading;					//var bool bToggleShading;
	UPROPERTY()						UMaterialInstance*	shadedEntry;					//var UTexture* shadedEntry;

	bool InternalOnPreDraw(UCanvas* Canvas);
	void SetSpectatorTeamSizeForDisplay();
	void SetScalableTeamSizeForDisplay();
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	float InternalGetItemHeight(UCanvas* C);
	bool InternalOnDraw(UCanvas* C);
};