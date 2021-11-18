// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAScoreboard_TeamSummary/AAScoreboard_TeamSummary.h"
#include "AAScoreboard_AutoScaleTeamSummar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAScoreboard_AutoScaleTeamSummar : public UAAScoreboard_TeamSummary
{
	GENERATED_BODY()
public:
	UAAScoreboard_AutoScaleTeamSummar();


	UPROPERTY()						UMaterialInstance* shadedEntry;			//var Texture shadedEntry;
	UPROPERTY()						bool bToggleShading;					//var bool bToggleShading;
	UPROPERTY()						bool bFullSpectatorPanel;				//var bool bFullSpectatorPanel;
	UPROPERTY()						float mUnassignedMargin;				//var float mUnassignedMargin;
	UPROPERTY()						int32 lastFireTeam;						//var int lastFireTeam;
	UPROPERTY()						int numUnassigned;						//var int numUnassigned;
	UPROPERTY()						int renderCounter;						//var int renderCounter;

	bool InternalOnPreDraw(UCanvas* Canvas);
	void SetSpectatorTeamSizeForDisplay();
	void SetScalableTeamSizeForDisplay();
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void InternalGetItemHeight(UCanvas* C);
	void InternalOnDraw(UCanvas* C);


};
