// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAGame_ListBase.h"
#include "AAScoreboard_FireTeamList.generated.h"

class AAGP_TeamInfo;
class UGUIButton;

UCLASS()
class AA29_API UAAScoreboard_FireTeamList : public UAAGame_ListBase
{
	GENERATED_BODY()
public:
	UAAScoreboard_FireTeamList();

	UPROPERTY()						int32 FTIndex;										//var int FTIndex;
	UPROPERTY()						AAGP_TeamInfo* Team;								//var AGP_Gameplay.AGP_TeamInfo Team;
	UPROPERTY()						FString ButtonHint;									//var localized string ButtonHint;
	UPROPERTY()						TArray<UGUIButton*> Buttons;						//var array<GUIButton> Buttons;

	bool ButtonClick(UGUIComponent* Sender);
	bool InternalOnPreDraw(UCanvas* Canvas);
	void InitList(AAGP_TeamInfo* FTTeam, int32 FTI);
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void UpdateButton(AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void Free();

};
