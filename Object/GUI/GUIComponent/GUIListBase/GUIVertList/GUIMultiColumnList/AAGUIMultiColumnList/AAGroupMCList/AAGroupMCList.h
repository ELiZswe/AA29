// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGUIMultiColumnList.h"
#include "AAGroupMCList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAGroupMCList : public UAAGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UAAGroupMCList();


	UPROPERTY()						int32 MaxVisibleTeamEntries;								//var int MaxVisibleTeamEntries;
	UPROPERTY()						bool bInitialized;								//var bool bInitialized;
	UPROPERTY()						TArray<int32> Separators;								//var array<int> Separators;
	UPROPERTY()						TArray<int32> Groups;								//var array<int> Groups;


	void InternalGetItemHeight(UCanvas* C);
	void Initialize();
	void ReInitialize();
	void SetGroupSize(int32 Group, int32 Size);
	int32 GetGroupSize(int32 Group);
	bool IsSeparator(int32 ItemNum);
	void DrawSeparator(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void DrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	bool InternalOnClick(UGUIComponent* Sender);
};
