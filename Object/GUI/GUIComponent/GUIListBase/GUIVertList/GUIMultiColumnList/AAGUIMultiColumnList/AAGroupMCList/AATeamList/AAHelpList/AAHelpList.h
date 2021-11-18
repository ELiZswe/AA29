// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"
#include "AAHelpList.generated.h"

class AAA2_GameState;

UCLASS()
class AA29_API UAAHelpList : public UAATeamList
{
	GENERATED_BODY()
public:
	UAAHelpList();

	UPROPERTY()						int32 MinVisibleTeamEntries;				//var int MinVisibleTeamEntries;
	UPROPERTY()						int32 FTIndex;								//var int FTIndex;
	UPROPERTY()						int32 TeamIndex;							//var int TeamIndex;
	UPROPERTY()						AAA2_GameState* GRI;					//var GameReplicationInfo GRI;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Initialize();
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawItem(UCanvas* C, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void InternalGetItemHeight(UCanvas* C);
};
