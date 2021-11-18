// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"
#include "AAUnassignedTeamList.generated.h"

class AAA2_GameState;

UCLASS()
class AA29_API UAAUnassignedTeamList : public UAATeamList
{
	GENERATED_BODY()
public:
	UAAUnassignedTeamList();

	UPROPERTY()						AAA2_GameState* mTeamId;					//var GameReplicationInfo GRI;
	//UPROPERTY()						int32 mTeamId;								//var int mTeamId;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnPreDraw(UCanvas* Canvas);
	void InternalGetItemHeight(UCanvas* C);
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, float X, float Y, float CellLeft, float CellWidth);
	void DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void DrawScores(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
};
