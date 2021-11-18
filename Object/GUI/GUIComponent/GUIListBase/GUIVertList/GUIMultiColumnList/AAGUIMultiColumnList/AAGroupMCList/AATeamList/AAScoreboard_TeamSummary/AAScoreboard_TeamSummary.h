// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"
#include "AAScoreboard_TeamSummary.generated.h"

class AAA2_GameState;
class AAA2_PlayerState;

/**
 * 
 */
UCLASS()
class AA29_API UAAScoreboard_TeamSummary : public UAATeamList
{
	GENERATED_BODY()
public:
	UAAScoreboard_TeamSummary();

	UPROPERTY()						TArray<AAA2_PlayerState*> mTeamPRIArray;	//var array<PlayerReplicationInfo> mTeamPRIArray;
	UPROPERTY()						AAA2_GameState* GRI;						//var GameReplicationInfo GRI;
	UPROPERTY()						bool bIsSpectatorPanel;						//var bool bIsSpectatorPanel;
	UPROPERTY()						int32 mFireTeamSize;						//var int mFireTeamSize;
	UPROPERTY()						int32 mFireTeamId;							//var int mFireTeamId;
	UPROPERTY()						int32 TeamIndex;							//var int TeamIndex;
	UPROPERTY()						int32 mTeamId;								//var int mTeamId;



	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Initialize();
	bool InternalOnPreDraw(UCanvas* Canvas);
	void InternalOnRendered(UCanvas* Canvas);
	void SetTeamSizeForDisplay();
	float GetTeamCount(int32 iTeamID);
	bool ShouldDrawItem(AAA2_PlayerState* fPlayerInfo);
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth, EListMode SelectList, bool IsAssigned);
	bool PreDrawHint(UCanvas* C);
	bool DrawHint(UCanvas* C);
	void MousingOverIcons();
};
