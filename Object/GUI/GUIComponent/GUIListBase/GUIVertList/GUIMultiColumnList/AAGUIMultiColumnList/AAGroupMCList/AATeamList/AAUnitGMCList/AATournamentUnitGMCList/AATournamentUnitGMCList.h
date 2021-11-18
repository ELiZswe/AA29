// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAUnitGMCList/AAUnitGMCList.h"
#include "AATournamentUnitGMCList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAATournamentUnitGMCList : public UAAUnitGMCList
{
	GENERATED_BODY()
public:
	UAATournamentUnitGMCList();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void DrawButtons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	bool ButtonClick(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	bool CanSelect();

};
