// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"
#include "UIInvListBox.generated.h"

class UUIScrollbar;
class UUIInvList;

UCLASS()
class AA29_API UUIInvListBox : public UUIInvSlotBase
{
	GENERATED_BODY()
public:
	UUIInvListBox();

	UPROPERTY()										bool bFirstTime;							//var bool bFirstTime;
	UPROPERTY()										UUIScrollbar* cScrollV;						//var UIScrollbar cScrollV;
	UPROPERTY()										UUIScrollbar* cScrollH;						//var UIScrollbar cScrollH;
	UPROPERTY()										int32 nSelection;							//var int nSelection;
	UPROPERTY()										int32 nButtonDownSlot;						//var int nButtonDownSlot;
	UPROPERTY()										int32 nTopLine;								//var int nTopLine;
	UPROPERTY()										bool bButtonDown;							//var bool bButtonDown;
	UPROPERTY()										FString sTexSelName;						//var string sTexSelName;
	UPROPERTY()										FString sTexName;							//var string sTexName;
	UPROPERTY()										UUIInvList* cInvList;						//var UIInvList cInvList;


	void Destroyed();
	void CreateTexture();
	void ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type);
	void ScaleControl(UCanvas* Canvas);
	void ChildMessage(float Value);
	void GetSelectedIndex();
	void SetList(UUIInvList* pInvList);

};
