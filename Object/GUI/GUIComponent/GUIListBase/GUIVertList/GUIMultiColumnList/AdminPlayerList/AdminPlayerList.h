// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AdminPlayerList.generated.h"

class UGUIStyles;

/**
 * 
 */
UCLASS()
class AA29_API UAdminPlayerList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UAdminPlayerList();

	UPROPERTY()						UGUIStyles* SelStyle;									//var GUIStyles SelStyle;
	UPROPERTY()						TArray<FPlayerInfo> MyPlayers;							//var array<PlayerInfo> MyPlayers;


	void Clear();
	void Add(FString PlayerInfo);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	

};
