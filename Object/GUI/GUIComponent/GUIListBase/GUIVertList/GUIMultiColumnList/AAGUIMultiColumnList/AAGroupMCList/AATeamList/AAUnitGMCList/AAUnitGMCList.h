// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"
#include "AAUnitGMCList.generated.h"

class AAA2_GameState;
class UGUIButton;
class AAGP_PlayerStart;

UCLASS()
class AA29_API UAAUnitGMCList : public UAATeamList
{
	GENERATED_BODY()
public:
	UAAUnitGMCList();

	UPROPERTY()						int32 MinVisibleTeamEntries;					//var int MinVisibleTeamEntries;
	UPROPERTY()						int32 FTIndex;									//var int FTIndex;
	UPROPERTY()						int32 TeamIndex;								//var int TeamIndex;
	UPROPERTY()						AAA2_GameState* GRI;							//var GameReplicationInfo GRI;
	UPROPERTY()						FString AcceptSwapCaption;						//var localized string AcceptSwapCaption;
	UPROPERTY()						FString AcceptSwapHint;							//var localized string AcceptSwapHint;
	UPROPERTY()						FString SwapRequestCaption;						//var localized string SwapRequestCaption;
	UPROPERTY()						FString SwapRequestHint;						//var localized string SwapRequestHint;
	UPROPERTY()						FString SwapCaption;							//var localized string SwapCaption;
	UPROPERTY()						FString SwapHint;								//var localized string SwapHint;
	UPROPERTY()						FString PendingCaption;							//var localized string PendingCaption;
	UPROPERTY()						FString PendingHint;							//var localized string PendingHint;
	UPROPERTY()						FString RequestCaption;							//var localized string RequestCaption;
	UPROPERTY()						FString RequestHint;							//var localized string RequestHint;
	UPROPERTY()						FString RemoveCaption;							//var localized string RemoveCaption;
	UPROPERTY()						FString RemoveHint;								//var localized string RemoveHint;
	UPROPERTY()						FString SelectCaption;							//var localized string SelectCaption;
	UPROPERTY()						FString SelectHint;								//var localized string SelectHint;
	UPROPERTY()						FString ButtonCaption;							//var localized string ButtonCaption;
	UPROPERTY()						FString ButtonHint;								//var localized string ButtonHint;
	UPROPERTY()						TArray<UGUIButton*> mTeamId;					//var array<GUIButton> Buttons;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Initialize();
	bool PreDrawButtons(UCanvas* C);
	bool InternalOnPreDraw(UCanvas* Canvas);
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawSeparator(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	void DrawButtons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth);
	bool ButtonClick(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	bool PreDrawHint(UCanvas* C);
	bool DrawHint(UCanvas* C);
	void MousingOverIcons();
	void IsSlotEnabled(int32 i);
	void IsGroupEnabled(int32 i);
	void IsPSEnabled(AAGP_PlayerStart* PS);
	void IsEnabled();
	bool CanSelect();
	void InternalGetItemHeight(UCanvas* C);
};
