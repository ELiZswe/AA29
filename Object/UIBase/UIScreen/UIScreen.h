// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIBase.h"
#include "UIScreen.generated.h"

class AInventory;
class AInvContainer;
class UUIInvDef;
class UUIMouse;
class UUIControl;
class UUIInvSlotBase;
class UUIFrame;

UCLASS()
class AA29_API UUIScreen : public UUIBase
{
	GENERATED_BODY()
public:
	UUIScreen();

	//const kResX = 800.0;
	//const kResY = 600.0;

	UPROPERTY()										FString _sTitle;					//var string _sTitle;
	UPROPERTY()										FPoint offset;						//var UIBase.Point offset;
	UPROPERTY()										float fScaleY;						//var float fScaleY;
	UPROPERTY()										float fScaleX;						//var float fScaleX;
	UPROPERTY()										int32 _iOldSizeY;					//var int _iOldSizeY;
	UPROPERTY()										int32 _iOldSizeX;					//var int _iOldSizeX;
	UPROPERTY()										UUIFrame* cFrame;					//var UIFrame cFrame;
	UPROPERTY()										UUIControl* cFocus;					//var UIControl cFocus;
	UPROPERTY()										UUIControl* cControlList;			//var UIControl cControlList;
	UPROPERTY()										UUIScreen* cNextScreen;				//var UIScreen cNextScreen;

	void Create(UUIFrame* frame, int32 pID, FString sTitle);
	void Destroyed();
	void ScaleControls(UCanvas* Canvas);
	bool KeyType(int32 Key);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void DrawScreen(UCanvas* Canvas, bool bMouse);
	void Notify(int32 pUIEvent);
	void CreateUIListItems(FString ListItemsName);
	void CreateUIControl(FString ControlName);
	void CreateUIMouse(FString MouseName);
	void AddControl(FString szControl, int32 pUIEvent);
	void AddRolloverButton(FString sControl, int32 pID, int32 pUIEvent, FPosition pPos, FString tString, int32 pParams, FString sToolTip);
	void AddRolloverBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams, FString sToolTip);
	void AddRolloverBitmapButtonB(int32 pID, int32 pUIEvent, FPosition pPos, UMaterialInstance* Tex, FPosition dim, int32 pParams, FString sToolTip);
	void AddUIBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams, FString sToolTip);
	void AddSimpleBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, UMaterialInstance* Tex, int32 pParams, FString sToolTip);
	void AddControlWithBaseBitmap(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, FString tex1, int32 pParams);
	void AddScrollbarV(int32 pID, int32 pUIEvent, FPosition pos, int32 imgW, int32 imgH, UMaterialInstance* BackTex, UMaterialInstance* ThumbTex, int32 pParams);
	void AddScrollbarH(int32 pID, int32 pUIEvent, FPosition pos, int32 imgW, int32 imgH, UMaterialInstance* BackTex, UMaterialInstance* ThumbTex, int32 pParams);
	void AddUISlider(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pBack, FPosition pThumb, FString Label, int32 pParams, FString ClassName, FString PropName, float Min, float Max);
	void AddUISliderSeg(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pBack, FPosition pThumb, FString Label, int32 pParams, FString ClassName, FString PropName, int32 segments);
	void AddUISliderH(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pThumb, int32 pParams);
	void AddUIClassButton(int32 pID, int32 pUIEvent, FPosition pPos, FPosition dim, int32 Index, FString classtex, FString altclass1tex, FString altclass2tex, FString altclass3tex, FString overlaytex);
	void AddListItemBox(int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams, FString ToolTip);
	void AddInvListBox(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams);
	void AddInvDropBox(int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip);
	void AddInvSlot(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams);
	void AddInvContainerListBox(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip, bool bLarge);
	void AddInvContainerSlot(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip);
	void AddHUDRackItem(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, int32 Index);
	void AddHUDBaseDisplay(FString controlstring, int32 pID, FPosition pPos, int32 pParams);
	void AddUIBorder(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams);
	void AddUIBorder2(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams);
	void AddUIBorder3(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams);
	void AddUIBorderButton(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, UMaterialInstance* tex3, FString sLabel, int32 pParams, FString ToolTip);
	void AddUIBorderButtonB(int32 pID, int32 pUIEvent, int32 pUIEvent2, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, UMaterialInstance* tex3, FString sLabel, FString sLabel2, int32 pParams, FString ToolTip);
	void AddUICheckBoxFn(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName, FString funcname);
	void AddUICheckBox(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName);
	void AddUICheckBoxB(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName);
	void AddUICheckBoxC(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName, FString valuename);
	void AddUIKeymap(int32 pID, int32 pUIEvent, FPosition pPos, FString tex1, FPosition dim, FString Command, int32 pParams, FString Label);
	void AddUIEditBox(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FString ToolTip, int32 maxlen);
	void AddUITextDisplay(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FString ToolTip, int32 fontindex, int32 colorindex);
	void AddUITextDisplayColor(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FColor cColor);
	void AddUIVideoMode(int32 pID, int32 pUIEvent, FPosition pPos, FString tex1, int32 pParams);
	void AddUIBitmap(int32 pID, FPosition pos, FString tex1, int32 pParams);
	void AddUIBitmapB(int32 pID, FPosition pos, FString tex1, FPosition dim, int32 pParams);
	void AddUIDynamicBitmap(int32 pID, FPosition pos, FString tex1, int32 pParams);
	void AddHUDCompass(int32 pID, int32 pUIEvent, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams);
	void AddMissionResultDisplay(FString controlstring, int32 pID, FPosition pPos, int32 pParams);
	void AddUITextButton(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, FString ToolTip);
	void AddUITextButtonSize(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, int32 Size);
	void AddUIWebLink(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, FString ToolTip);
	void AddUIWebLinkButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams);
	void AddUIQuickLan(int32 pID, FPosition pPos, int32 pParams);
	void AddUIServerListDisplay(int32 pID, FPosition pPos, int32 pParams);
	void AddUIPlayerList(int32 pID, FPosition pPos, int32 pParams);
	void AddUISettingsList(int32 pID, FPosition pPos, int32 pParams);
	void AddUIConsole(int32 pID, FPosition pPos, int32 pParams);
	void AddUIImageListDisplay(int32 pID, FPosition pPos, int32 pParams);
	void AddUITextPageDisplay(int32 pID, FPosition pPos, int32 pParams, int32 Lines, bool bpagedisplay);
	void AddUIScrollingCredits(int32 pID, int32 pUIEvent, FPosition pPos, int32 pParams);
	void AddUIEscapeKey(int32 pID, int32 pUIEvent);
	void AddUIKeyCapture(int32 pID, int32 pUIEvent);
	void SetFocus(UUIControl* Control);
	void DumpControlLog();
	UUIControl* GetLastControl();
	void AddControlToTail(UUIControl* Control);
	UUIControl* GetControl(int32 Id);
	bool EnableControl(int32 Id, bool State);
	void SetCheckBoxGroup(int32 GroupID, int32 controlid);

};
