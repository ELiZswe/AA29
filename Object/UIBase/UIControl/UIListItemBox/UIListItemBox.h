// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIListItemBox.generated.h"

class UUIScrollbar;
class UUIListItems;

UCLASS()
class AA29_API UUIListItemBox : public UUIControl
{
	GENERATED_BODY()
public:
	UUIListItemBox();


	UPROPERTY()										bool bFirstTime;					//var bool bFirstTime;
	UPROPERTY()										int32 iItemHeight;					//var int iItemHeight;
	UPROPERTY()										UUIScrollbar* cScrollV;				//var UIScrollbar cScrollV;
	UPROPERTY()										UUIScrollbar* cScrollH;				//var UIScrollbar cScrollH;
	UPROPERTY()										int32 nSelection;					//var int nSelection;
	UPROPERTY()										int32 nTopLine;						//var int nTopLine;
	UPROPERTY()										UMaterialInstance* _Texture2;		//var Texture _Texture2;
	UPROPERTY()										UMaterialInstance* _Texture;		//var Texture _Texture;
	UPROPERTY()										bool bSorted;						//var bool bSorted;
	UPROPERTY()										UUIListItems* cListItems;			//var UIListItems cListItems;

	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	void SetListItems(UUIListItems* pListItems);
	void ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type);
	void ScaleControl(UCanvas* Canvas);
	void ChildMessage(float Value);
	void GetSelectedIndex();
	void SetItems(UUIListItems* pListItems);
	void SetTexture(UMaterialInstance* Tex);
	void SetTexture2(UMaterialInstance* Tex);

};
