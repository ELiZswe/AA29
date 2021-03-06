// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIRolloverBitmapButton/UIRolloverBitmapButton.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckbox/UICheckbox.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxB/UICheckboxB.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxC/UICheckboxC.h"
#include "AA29/Object/UIBase/UIControl/UIListItems/UIListItems.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "AA29/Object/UIBase/UIControl/UIRolloverBitmapButtonB/UIRolloverBitmapButtonB.h"
#include "AA29/Object/UIBase/UIControl/UIRolloverButton/UIRolloverButton.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIBitmapButton/UIBitmapButton.h"
#include "AA29/Object/UIBase/UIControl/UISimpleBitmapButton/UISimpleBitmapButton.h"
#include "AA29/Object/UIBase/UIControl/UIBitmap/UIBitmap.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISlider/UISlider.h"
#include "AA29/Object/UIBase/UIControl/UIListItemBox/UIListItemBox.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIClassButton/UIClassButton.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISliderH/UISliderH.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISliderSeg/UISliderSeg.h"
#include "AA29/Object/UIBase/UIControl/UIDynamicBitmap/UIDynamicBitmap.h"
#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplay.h"
#include "AA29/Object/UIBase/UIControl/UIBitmap/UIBitmapB/UIBitmapB.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorder.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorderButton/UIBorderButton.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorderButton/UIBorderButtonB/UIBorderButtonB.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxFn/UICheckboxFn.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIEditBox/UIEditBox.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompass/UIHUDCompass.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIHUDRackItem/UIHUDRackItem.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvContainerListBox/UIInvContainerListBox.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvContainerSlot/UIInvContainerSlot.h"
#include "AA29/Object/UIBase/UIControl/UIInvDropBox/UIInvDropBox.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvListBox/UIInvListBox.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlot/UIInvSlot.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIKeymap/UIKeymap.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButton.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButtonSize/UITextButtonSize.h"
#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplayColor/UITextDisplayColor.h"
#include "AA29/Object/UIBase/UIControl/UITextPageDisplay/UITextPageDisplay.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIVideoMode/UIVideoMode.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UIWebLink/UIWebLink.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UIWebLinkButton/UIWebLinkButton.h"
#include "Engine/Canvas.h"

UUIScreen::UUIScreen()
{

}

void UUIScreen::Create(UUIFrame* frame, int32 pID, FString sTitle)
{
	_iID = pID;
	cFrame = frame;
	_sTitle = sTitle;
}

void UUIScreen::Destroyed()
{
	UUIControl* Control = nullptr;
	UUIControl* NextControl = nullptr;
	cNextScreen = nullptr;
	cFocus = nullptr;
	cFrame = nullptr;
	Control = cControlList;
	if (Control != nullptr)
	{
		NextControl = Control->cNextControl;
		Control->bControlInitialized = false;
		Control->Destroyed();
		Control = NextControl;
	}
	cControlList = nullptr;
}

void UUIScreen::ScaleControls(UCanvas* Canvas)
{
	UUIControl* Control = nullptr;
	if (_iOldSizeX == Canvas->SizeX && _iOldSizeY == Canvas->SizeY)
	{
		return;
	}
	Control = cControlList;
	if (Control != nullptr)
	{
		if (!Control->bControlInitialized)
		{
			Control = Control->cNextControl;
		}
		else
		{
			Control->ScaleControl(Canvas);
			Control = Control->cNextControl;
		}
	}
	_iOldSizeX = Canvas->SizeX;
	_iOldSizeY = Canvas->SizeY;
	offset.X = _Pos.X * fScaleX;
	offset.Y = _Pos.Y * fScaleY;
}

bool UUIScreen::KeyType(int32 Key)
{
	UUIControl* Control = nullptr;
	for (Control=cControlList; Control!=nullptr; Control=Control->cNextControl)
	{
		if (Control->KeyType(Key))
		{
			return true;
		}
	}
	return false;
}

bool UUIScreen::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	UUIControl* Control = nullptr;
	for (Control = cControlList; Control != nullptr; Control = Control->cNextControl)
	{
		if (Control->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	if ((Key == 9) && (Action == 1))
	{
		return true;
	}
	if (Action == 3)
	{
		if ((Key == 40) || (Key == 9))
		{
			if (cFrame->_cMouseOver != nullptr)
			{
				if (cFrame->_cMouseOver->cScreen == this)
				{
					Control = cFrame->_cMouseOver;
					if (Control->cNextControl != nullptr)
					{
						if (Control->cNextControl->IsA(UUINavControl::StaticClass()))
						{
							cFrame->_cMouseOver = Control->cNextControl;
							return true;
						}
						Control = Control->cNextControl;
					}
					for (Control = cControlList; Control != cFrame->_cMouseOver; Control = Control->cNextControl)
					{
						if (Control->IsA(UUINavControl::StaticClass()))
						{
							cFrame->_cMouseOver = Control;
							return true;
						}
					}
				}
			}
			else
			{
				if (cFrame->cActiveScreen == this)
				{
					for (Control = cControlList; Control != nullptr; Control = Control->cNextControl)
					{
						if (Control->IsA(UUINavControl::StaticClass()))
						{
							cFrame->_cMouseOver = Control;
							return true;
						}
					}
				}
			}
		}
		if (Key == 38)
		{
			if (cFrame->_cMouseOver != nullptr)
			{
				if (cFrame->_cMouseOver->cScreen == this)
				{
					Control = cFrame->_cMouseOver;
					if (Control->cPrevControl != nullptr)
					{
						if (Control->cPrevControl->IsA(UUINavControl::StaticClass()))
						{
							cFrame->_cMouseOver = Control->cPrevControl;
							return true;
						}
						Control = Control->cPrevControl;
					}
					for (Control = GetLastControl(); Control != cFrame->_cMouseOver; Control = Control->cPrevControl)
					{
						if (Control->IsA(UUINavControl::StaticClass()))
						{
							cFrame->_cMouseOver = Control;
							return true;
						}
					}
				}
			}
			else
			{
				if (cFrame->cActiveScreen == this)
				{
					for (Control = GetLastControl(); Control != nullptr; Control = Control->cPrevControl)
					{
						if (Control->IsA(UUINavControl::StaticClass()))
						{
							cFrame->_cMouseOver = Control;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void UUIScreen::DrawScreen(UCanvas* Canvas, bool bMouse)
{
	UUIControl* Control = nullptr;
	int32 i = 0;
	ScaleControls(Canvas);
	i = 1;
	i = 1;
	Control = cControlList;
	if (Control != nullptr)
	{
		if (!Control->bControlInitialized)
		{
			Control = Control->cNextControl;
		}
		else
		{
			if (_bDebug)
			{
				//Canvas.DrawText("UIFrame - Drawing control " + i);
			}
			if (cFrame->cMouse != nullptr && bMouse)
			{
				Control->MouseMove(cFrame->cMouse->iMouseX, cFrame->cMouse->iMouseY);
			}
			Control->Draw(Canvas);
			Control = Control->cNextControl;
			i++;
		}
	}
	i--;
	if (_bDebug)
	{
		//Canvas.SetPos(0, 200);
		//Canvas.DrawText("UIFrame - Controls drawn: " + i);
		//Canvas.DrawText("First Control ID: " + cControlList.GetID());
	}
	if (cFocus != nullptr && cFrame->cMouse != nullptr && bMouse)
	{
		cFocus->MouseMove(cFrame->cMouse->iMouseX, cFrame->cMouse->iMouseY);
	}
}

void UUIScreen::Notify(int32 pUIEvent)
{
}

UUIListItems* UUIScreen::CreateUIListItems(FString ListItemsName)
{
	UUIListItems* myListItems = nullptr;
	UUIListItems* cUIListItems = nullptr;
	//cUIListItems = class<UIListItems>(DynamicLoadObject(ListItemsName, Class'Class'));
	//myListItems = new (nullptr) classcUIListItems;
	return myListItems;
}

UUIControl* UUIScreen::CreateUIControl(FString ControlName)
{
	UUIControl* myControl = nullptr;
	UUIControl* cUIControl = nullptr;
	//cUIControl = class<UIControl>(DynamicLoadObject(ControlName, Class'Class'));
	//myControl = new (nullptr) classcUIControl;
	return myControl;
}

UUIMouse* UUIScreen::CreateUIMouse(FString MouseName)
{
	UUIMouse* myMouse = nullptr;
	UUIMouse* cUIMouse = nullptr;
	//cUIMouse = class<UIMouse>(DynamicLoadObject(MouseName, Class'Class'));
	//myMouse = new (nullptr) classcUIMouse;
	return myMouse;
}

void UUIScreen::AddControl(FString szControl, int32 pUIEvent)
{
}

void UUIScreen::AddRolloverButton(FString sControl, int32 pID, int32 pUIEvent, FPosition pPos, FString tString, int32 pParams, FString sToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl(sControl);
	Control->SetPos(pPos);
	Cast<UUIRolloverButton>(Control)->SetTextureString(tString);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddRolloverBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams, FString sToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIRolloverBitmapButton");
	Control->SetPos(pPos);
	Control->SetTooltip(sToolTip);
	Cast<UUIRolloverBitmapButton>(Control)->SetTextureDimensions(dim);
	Cast<UUIRolloverBitmapButton>(Control)->SetTexture(Tex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddRolloverBitmapButtonB(int32 pID, int32 pUIEvent, FPosition pPos, UMaterialInstance* Tex, FPosition dim, int32 pParams, FString sToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIRolloverBitmapButtonB");
	Control->SetPos(pPos);
	Control->SetTooltip(sToolTip);
	Cast<UUIRolloverBitmapButtonB>(Control)->SetTextureDimensions(dim);
	Cast<UUIRolloverBitmapButtonB>(Control)->SetTexture(Tex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams, FString sToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBitmapButton");
	Control->SetPos(pPos);
	Control->SetTooltip(sToolTip);
	Cast<UUIBitmapButton>(Control)->SetTextureDimensions(dim);
	Cast<UUIBitmapButton>(Control)->SetTexture(Tex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddSimpleBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, UMaterialInstance* Tex, int32 pParams, FString sToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UISimpleBitmapButton");
	Control->SetPos(pPos);
	Control->SetTooltip(sToolTip);
	Cast<UUISimpleBitmapButton>(Control)->SetTexture(Tex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddControlWithBaseBitmap(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, FString tex1, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl(sControl);
	Control->SetPos(pos);
	Cast<UUIBitmap>(Control)->SetTexture(tex1);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddScrollbarV(int32 pID, int32 pUIEvent, FPosition pos, int32 imgW, int32 imgH, UMaterialInstance* BackTex, UMaterialInstance* ThumbTex, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIScrollbarV");
	Control->SetPos(pos);
	Cast<UUIScrollbar>(Control)->SetImageDimensions(imgW, imgH);
	Cast<UUIScrollbar>(Control)->SetBackTexture(BackTex);
	Cast<UUIScrollbar>(Control)->SetThumbTexture(ThumbTex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddScrollbarH(int32 pID, int32 pUIEvent, FPosition pos, int32 imgW, int32 imgH, UMaterialInstance* BackTex, UMaterialInstance* ThumbTex, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIScrollbarH");
	Control->SetPos(pos);
	Cast<UUIScrollbar>(Control)->SetImageDimensions(imgW, imgH);
	Cast<UUIScrollbar>(Control)->SetBackTexture(BackTex);
	Cast<UUIScrollbar>(Control)->SetThumbTexture(ThumbTex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUISlider(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pBack, FPosition pThumb, FString Label, int32 pParams, FString ClassName, FString PropName, float Min, float Max)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UISlider");
	Control->SetPos(pos);
	Cast<UUISlider>(Control)->SetTexture(tex1);
	Cast<UUISlider>(Control)->SetTexDimBack(pBack);
	Cast<UUISlider>(Control)->SetTexDimThumb(pThumb);
	Cast<UUISlider>(Control)->SetLabel(Label);
	Cast<UUISlider>(Control)->SetClassName(ClassName);
	Cast<UUISlider>(Control)->SetPropertyName(PropName);
	Cast<UUISlider>(Control)->SetMinMax(Min, Max);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUISliderSeg(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pBack, FPosition pThumb, FString Label, int32 pParams, FString ClassName, FString PropName, int32 segments)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UISliderSeg");
	Control->SetPos(pos);
	Cast<UUISliderSeg>(Control)->SetTexture(tex1);
	Cast<UUISliderSeg>(Control)->SetTexDimBack(pBack);
	Cast<UUISliderSeg>(Control)->SetTexDimThumb(pThumb);
	Cast<UUISliderSeg>(Control)->SetLabel(Label);
	Cast<UUISliderSeg>(Control)->SetClassName(ClassName);
	Cast<UUISliderSeg>(Control)->SetPropertyName(PropName);
	Cast<UUISliderSeg>(Control)->SetNumSegments(segments);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUISliderH(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pThumb, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UISliderH");
	Control->SetPos(pos);
	Cast<UUISliderH>(Control)->SetTexture(tex1);
	Cast<UUISliderH>(Control)->SetTexDimThumb(pThumb);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIClassButton(int32 pID, int32 pUIEvent, FPosition pPos, FPosition dim, int32 Index, FString classtex, FString altclass1tex, FString altclass2tex, FString altclass3tex, FString overlaytex)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIClassButton");
	Control->SetPos(pPos);
	Cast<UUIClassButton>(Control)->SetTextureDimensions(dim);
	Cast<UUIClassButton>(Control)->SetClassTexture(classtex);
	Cast<UUIClassButton>(Control)->SetAltClass1Texture(altclass1tex);
	Cast<UUIClassButton>(Control)->SetAltClass2Texture(altclass2tex);
	Cast<UUIClassButton>(Control)->SetAltClass3Texture(altclass3tex);
	Cast<UUIClassButton>(Control)->SetOverlayTexture(overlaytex);
	Cast<UUIClassButton>(Control)->SetNotAvailTexture("T_AA2_UI.menu.ui_gm_na");
	Cast<UUIClassButton>(Control)->SetNotQualTexture("T_AA2_UI.menu.ui_gm_nqual");
	Cast<UUIClassButton>(Control)->SetSelectTexture("T_AA2_UI.menu.ui_gm_highlight");
	Cast<UUIClassButton>(Control)->SetLabel("RANDOM");
	Cast<UUIClassButton>(Control)->SetClassIndex(Index);
	Control->Create(cFrame, this, pID, pUIEvent, 0);
	AddControlToTail(Control);
}

void UUIScreen::AddListItemBox(int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIListItemBox");
	if (Control == nullptr)
	{
		cFrame->UILog("AddListItemBox - CreateUIControl FAILED");
	}
	Control->SetPos(pos);
	Control->SetTooltip(ToolTip);
	Cast<UUIListItemBox>(Control)->SetTexture(tex1);
	Cast<UUIListItemBox>(Control)->SetTexture2(tex2);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddInvListBox(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl(sControl);
	if (Control == nullptr)
	{
		cFrame->UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Control->SetPos(pos);
	cFrame->UILog("AddInvListBox - set textures");
	Cast<UUIInvListBox>(Control)->SetTexture(tex1);
	Cast<UUIInvListBox>(Control)->SetTexture2(tex2);
	Cast<UUIInvListBox>(Control)->SetSize(pParams);
	cFrame->UILog("AddInvListBox - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddInvDropBox(int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIInvDropBox");
	if (Control == nullptr)
	{
		cFrame->UILog("AddInvDropBox - CreateUIControl FAILED");
	}
	Control->SetPos(pos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddInvDropBox - set textures");
	Cast<UUIInvDropBox>(Control)->SetTexture(tex1);
	Cast<UUIInvDropBox>(Control)->SetTexture2(tex2);
	Cast<UUIInvDropBox>(Control)->SetBorderTexture(bordertex);
	Cast<UUIInvDropBox>(Control)->SetTextureDimensions(pDim2);
	cFrame->UILog("AddInvDropBox - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddInvSlot(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl(sControl);
	if (Control == nullptr)
	{
		cFrame->UILog("AddInvSlot - CreateUIControl FAILED");
	}
	Control->SetPos(pos);
	cFrame->UILog("AddInvSlot - set textures");
	Cast<UUIInvSlot>(Control)->SetTexture(tex1);
	Cast<UUIInvSlot>(Control)->SetTexture2(tex2);
	Cast<UUIInvSlot>(Control)->SetSize(pParams);
	cFrame->UILog("AddInvSlot - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddInvContainerListBox(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip, bool bLarge)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIInvContainerListBox");
	if (Control == nullptr)
	{
		cFrame->UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Cast<UUIInvContainerListBox>(Control)->SetLarge(bLarge);
	cFrame->UILog("SetLarge: " + bLarge);
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddInvContainerListBox - set textures");
	Cast<UUIInvContainerListBox>(Control)->SetTexture(tex1);
	Cast<UUIInvContainerListBox>(Control)->SetTexture2(tex2);
	Cast<UUIInvContainerListBox>(Control)->SetBorderTexture(bordertex);
	Cast<UUIInvContainerListBox>(Control)->SetTextureDimensions(pDim2);
	cFrame->UILog("AddInvContainerListBox - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	Cast<UUIInvContainerListBox>(Control)->SetItemDimensions(pDim.X, pDim.Y, pDim.W, pDim.H);
	AddControlToTail(Control);
}

void UUIScreen::AddInvContainerSlot(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIInvContainerSlot");
	if (Control == nullptr)
	{
		cFrame->UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddInvContainerSlot - set textures");
	Cast<UUIInvContainerSlot>(Control)->SetTexture(tex1);
	Cast<UUIInvContainerSlot>(Control)->SetTexture2(tex2);
	Cast<UUIInvContainerSlot>(Control)->SetBorderTexture(bordertex);
	Cast<UUIInvContainerSlot>(Control)->SetTextureDimensions(pDim2);
	cFrame->UILog("AddInvContainerSlot - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	Cast<UUIInvContainerSlot>(Control)->SetItemDimensions(pDim.X, pDim.Y, pDim.W, pDim.H);
	AddControlToTail(Control);
}

void UUIScreen::AddHUDRackItem(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, int32 Index)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIHUDRackItem");
	if (Control == nullptr)
	{
		cFrame->UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddHUDRackItem - set textures");
	Cast<UUIHUDRackItem>(Control)->SetTexture(tex1);
	Cast<UUIHUDRackItem>(Control)->SetTexture2(tex2);
	Cast<UUIHUDRackItem>(Control)->SetBorderTexture(bordertex);
	Cast<UUIHUDRackItem>(Control)->SetTextureDimensions(pDim2);
	Cast<UUIHUDRackItem>(Control)->SetRackIndex(Index);
	cFrame->UILog("AddHUDRackItem - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	Cast<UUIHUDRackItem>(Control)->SetItemDimensions(pDim.X, pDim.Y, pDim.W, pDim.H);
	AddControlToTail(Control);
}

void UUIScreen::AddHUDBaseDisplay(FString controlstring, int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	cFrame->UILog("AddHUDBaseDisplay - creating " + controlstring);
	Control = CreateUIControl(controlstring);
	if (Control == nullptr)
	{
		cFrame->UILog("AddHUDBaseDisplay - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddHUDBaseDisplay - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBorder(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBorder");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIBorder - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Cast<UUIBorder>(Control)->SetTextureDimensions(pDim);
	cFrame->UILog("AddUIBorder - set textures");
	Cast<UUIBorder>(Control)->SetTexture(tex1);
	Cast<UUIBorder>(Control)->SetTexture2(tex2);
	cFrame->UILog("AddUIBorder - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBorder2(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBorder2");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIBorder2 - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Cast<UUIBorder>(Control)->SetTextureDimensions(pDim);
	cFrame->UILog("AddUIBorder2 - set textures");
	Cast<UUIBorder>(Control)->SetTexture(tex1);
	Cast<UUIBorder>(Control)->SetTexture2(tex2);
	cFrame->UILog("AddUIBorder2 - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBorder3(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBorder3");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIBorder3 - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Cast<UUIBorder>(Control)->SetTextureDimensions(pDim);
	cFrame->UILog("AddUIBorder3 - set textures");
	Cast<UUIBorder>(Control)->SetTexture(tex1);
	Cast<UUIBorder>(Control)->SetTexture2(tex2);
	cFrame->UILog("AddUIBorder3 - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBorderButton(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, UMaterialInstance* tex3, FString sLabel, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBorderButton");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIBorderButton - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	Cast<UUIBorderButton>(Control)->SetTextureDimensions(pDim);
	Cast<UUIBorderButton>(Control)->SetLabel(sLabel);
	cFrame->UILog("AddUIBorderButton - set textures");
	Cast<UUIBorderButton>(Control)->SetTexture(tex1);
	Cast<UUIBorderButton>(Control)->SetTexture2(tex2);
	Cast<UUIBorderButton>(Control)->SetTexture3(tex3);
	cFrame->UILog("AddUIBorderButton - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBorderButtonB(int32 pID, int32 pUIEvent, int32 pUIEvent2, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, UMaterialInstance* tex3, FString sLabel, FString sLabel2, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBorderButtonB");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIBorderButtonB - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	Cast<UUIBorderButtonB>(Control)->SetTextureDimensions(pDim);
	Cast<UUIBorderButtonB>(Control)->SetLabel(sLabel);
	Cast<UUIBorderButtonB>(Control)->SetLabel2(sLabel2);
	cFrame->UILog("AddUIBorderButtonB - set textures");
	Cast<UUIBorderButtonB>(Control)->SetTexture(tex1);
	Cast<UUIBorderButtonB>(Control)->SetTexture2(tex2);
	Cast<UUIBorderButtonB>(Control)->SetTexture3(tex3);
	cFrame->UILog("AddUIBorderButtonB - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	Cast<UUIBorderButtonB>(Control)->SetEvent2(pUIEvent2);
	AddControlToTail(Control);
}

void UUIScreen::AddUICheckBoxFn(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName, FString funcname)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UICheckBoxFn");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUICheckBoxFn - CreateUIControl FAILED");
		return;
	}
	Control->SetGroupID(GroupID);
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddCheckBox - set textures");
	Cast<UUICheckboxFn>(Control)->SetLabel(Label);
	Cast<UUICheckboxFn>(Control)->SetTexture(tex1);
	Cast<UUICheckboxFn>(Control)->SetTextureDimensions(pDim);
	Cast<UUICheckboxFn>(Control)->SetClassName(ClassName);
	Cast<UUICheckboxFn>(Control)->SetPropertyName(PropName);
	Cast<UUICheckboxFn>(Control)->SetFuncName(funcname);
	cFrame->UILog("AddUICheckBoxFn - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUICheckBox(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UICheckBox");
	if (Control == nullptr)
	{
		cFrame->UILog("AddCheckBox - CreateUIControl FAILED");
		return;
	}
	Control->SetGroupID(GroupID);
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddCheckBox - set textures");
	Cast<UUICheckbox>(Control)->SetLabel(Label);
	Cast<UUICheckbox>(Control)->SetTexture(tex1);
	Cast<UUICheckbox>(Control)->SetTextureDimensions(pDim);
	Cast<UUICheckbox>(Control)->SetClassName(ClassName);
	Cast<UUICheckbox>(Control)->SetPropertyName(PropName);
	cFrame->UILog("AddCheckBox - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUICheckBoxB(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UICheckBoxB");
	if (Control == nullptr)
	{
		cFrame->UILog("AddCheckBoxB - CreateUIControl FAILED");
		return;
	}
	Control->SetGroupID(GroupID);
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddCheckBoxB - set textures");
	Cast<UUICheckboxB>(Control)->SetLabel(Label);
	Cast<UUICheckboxB>(Control)->SetTexture(tex1);
	Cast<UUICheckboxB>(Control)->SetTextureDimensions(pDim);
	Cast<UUICheckboxB>(Control)->SetClassName(ClassName);
	Cast<UUICheckboxB>(Control)->SetPropertyName(PropName);
	cFrame->UILog("AddCheckBoxB - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUICheckBoxC(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName, FString valuename)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UICheckBoxC");
	if (Control == nullptr)
	{
		cFrame->UILog("AddCheckBoxC - CreateUIControl FAILED");
		return;
	}
	Control->SetGroupID(GroupID);
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddCheckBoxC - set textures");
	Cast<UUICheckboxC>(Control)->SetLabel(Label);
	Cast<UUICheckboxC>(Control)->SetTexture(tex1);
	Cast<UUICheckboxC>(Control)->SetTextureDimensions(pDim);
	Cast<UUICheckboxC>(Control)->SetClassName(ClassName);
	Cast<UUICheckboxC>(Control)->SetPropertyName(PropName);
	Cast<UUICheckboxC>(Control)->SetValueName(valuename);
	cFrame->UILog("AddCheckBoxC - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIKeymap(int32 pID, int32 pUIEvent, FPosition pPos, FString tex1, FPosition dim, FString Command, int32 pParams, FString Label)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIKeymap");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIKeymap - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIKeymap - set textures");
	Cast<UUIKeymap>(Control)->SetTexture(tex1);
	Cast<UUIKeymap>(Control)->SetTextureDimensions(dim);
	Cast<UUIKeymap>(Control)->SetCommand(Command);
	Cast<UUIKeymap>(Control)->SetLabel(Label);
	cFrame->UILog("AddUIKeymap - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIEditBox(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FString ToolTip, int32 maxlen)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIEditBox");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIEditBox - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddUIEditBox - set textures");
	Cast<UUIEditBox>(Control)->SetLabel(Label);
	Cast<UUIEditBox>(Control)->SetMaxLength(maxlen);
	cFrame->UILog("AddUIEditBox - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUITextDisplay(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FString ToolTip, int32 fontindex, int32 colorindex)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UITextDisplay");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUITextDisplay - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	cFrame->UILog("AddUITextDisplay - set label");
	Cast<UUITextDisplay>(Control)->SetLabel(Label);
	Cast<UUITextDisplay>(Control)->SetFontIndex(fontindex);
	Cast<UUITextDisplay>(Control)->SetColorIndex(colorindex);
	cFrame->UILog("AddUITextDisplay - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUITextDisplayColor(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FColor cColor)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UITextDisplayColor");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUITextDisplayColor - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUITextDisplayColor - label/color");
	Cast<UUITextDisplayColor>(Control)->SetLabel(Label);
	Cast<UUITextDisplayColor>(Control)->SetColor(cColor);
	cFrame->UILog("AddUITextDisplayColor - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIVideoMode(int32 pID, int32 pUIEvent, FPosition pPos, FString tex1, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIVideoMode");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIVideoMode - CreateUIControl FAILED");
		return;
	}
	Cast<UUIVideoMode>(Control)->SetTexture(tex1);
	Control->SetPos(pPos);
	cFrame->UILog("AddUIVideoMode - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBitmap(int32 pID, FPosition pos, FString tex1, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBitmap");
	if (Control == nullptr)
	{
		return;
	}
	Control->SetPos(pos);
	Cast<UUIBitmap>(Control)->SetTexture(tex1);
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIBitmapB(int32 pID, FPosition pos, FString tex1, FPosition dim, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIBitmapB");
	Control->SetPos(pos);
	Cast<UUIBitmapB>(Control)->SetTexture(tex1);
	Cast<UUIBitmapB>(Control)->SetTextureDimensions(dim);
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIDynamicBitmap(int32 pID, FPosition pos, FString tex1, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIDynamicBitmap");
	if (Control == nullptr)
	{
		return;
	}
	Control->SetPos(pos);
	Cast<UUIDynamicBitmap>(Control)->SetTexture(tex1, 64, 64, 0);
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddHUDCompass(int32 pID, int32 pUIEvent, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIHUDCompass");
	if (Control == nullptr)
	{
		cFrame->UILog("AddHUDCompass - CreateUIControl FAILED");
		return;
	}
	cFrame->UILog("AddHUDCompass - set textures");
	Cast<UUIHUDCompass>(Control)->SetTexture(tex1);
	Cast<UUIHUDCompass>(Control)->SetBracketTexture(tex2);
	cFrame->UILog("AddHUDCompass - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddMissionResultDisplay(FString controlstring, int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl(controlstring);
	if (Control == nullptr)
	{
		cFrame->UILog("AddMissionResultDisplay - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddMissionResultDisplay - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUITextButton(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UITextButton");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUITextButton - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	Cast<UUITextButton>(Control)->SetLabel(sLabel);
	cFrame->UILog("AddUITextButton - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUITextButtonSize(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, int32 Size)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UITextButtonSize");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUITextButtonSize - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Cast<UUITextButtonSize>(Control)->SetSize(Size);
	Cast<UUITextButtonSize>(Control)->SetLabel(sLabel);
	cFrame->UILog("AddUITextButtonSize - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIWebLink(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, FString ToolTip)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIWebLink");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIWebLink - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Control->SetTooltip(ToolTip);
	Cast<UUIWebLink>(Control)->SetLabel(sLabel);
	cFrame->UILog("AddUIWebLink - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIWebLinkButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIWebLinkButton");
	if (Control == nullptr)
	{
		return;
	}
	Control->SetPos(pPos);
	Cast<UUIWebLinkButton>(Control)->SetTextureDimensions(dim);
	Cast<UUIWebLinkButton>(Control)->SetTexture(Tex);
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIQuickLan(int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIQuickLan");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIQuickLan - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIQuickLan - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIServerListDisplay(int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIServerListDisplay");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIServerListDisplay - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIServerListDisplay - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIPlayerList(int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIPlayerList");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIPlayerList - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIPlayerList - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUISettingsList(int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UISettingsList");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUISettingsList - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUISettingsList - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIConsole(int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIConsole");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIConsole - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIConsole - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIImageListDisplay(int32 pID, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIImageListDisplay");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIImageListDisplay - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIImageListDisplay - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUITextPageDisplay(int32 pID, FPosition pPos, int32 pParams, int32 Lines, bool bpagedisplay)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UITextPageDisplay");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUITextPageDisplay - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	Cast<UUITextPageDisplay>(Control)->SetLinesPerPage(Lines);
	Cast<UUITextPageDisplay>(Control)->SetPageDisplay(bpagedisplay);
	cFrame->UILog("AddUITextPageDisplay - create");
	Control->Create(cFrame, this, pID, 0, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIScrollingCredits(int32 pID, int32 pUIEvent, FPosition pPos, int32 pParams)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIScrollingCredits");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIScrollingCredits - CreateUIControl FAILED");
		return;
	}
	Control->SetPos(pPos);
	cFrame->UILog("AddUIScrollingCredits - create");
	Control->Create(cFrame, this, pID, pUIEvent, pParams);
	AddControlToTail(Control);
}

void UUIScreen::AddUIEscapeKey(int32 pID, int32 pUIEvent)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIEscapeKey");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIEscapeKey - CreateUIControl FAILED");
		return;
	}
	cFrame->UILog("AddUIEscapeKey - create");
	Control->Create(cFrame, this, pID, pUIEvent, 0);
	AddControlToTail(Control);
}

void UUIScreen::AddUIKeyCapture(int32 pID, int32 pUIEvent)
{
	UUIControl* Control = nullptr;
	Control = CreateUIControl("AGP_UI.UIKeyCapture");
	if (Control == nullptr)
	{
		cFrame->UILog("AddUIKeyCapture - CreateUIControl FAILED");
		return;
	}
	cFrame->UILog("AddUIKeyCapture - create");
	Control->Create(cFrame, this, pID, pUIEvent, 0);
	AddControlToTail(Control);
}

void UUIScreen::SetFocus(UUIControl* Control)
{
	if (cFocus != nullptr && cFocus != Control)
	{
		cFocus->Focus(false);
	}
	cFocus = Control;
	cFocus->Focus(true);
}

void UUIScreen::DumpControlLog()
{
	UUIControl* Control = nullptr;
	int32 i = 0;
	cFrame->UILog("#### DUMP CONTROL LOG START ####");
	Control = cControlList;
	if (Control != nullptr)
	{
		cFrame->UILog("control #" + FString::FromInt(i) + " is ID " + FString::FromInt(Control->GetID()));
		Control = Control->cNextControl;
		i++;
	}
	cFrame->UILog("#### DUMP CONTROL LOG END ####");
}

UUIControl* UUIScreen::GetLastControl()
{
	UUIControl* Control = nullptr;
	for (Control = cControlList; Control != nullptr; Control = Control->cNextControl)
	{
		if (Control->cNextControl == nullptr)
		{
			return Control;
		}
	}
	return Control;
}

void UUIScreen::AddControlToTail(UUIControl* Control)
{
	UUIControl* lastcontrol = nullptr;
	lastcontrol = GetLastControl();
	if (lastcontrol == nullptr)
	{
		cControlList = Control;
	}
	else
	{
		lastcontrol->cNextControl = Control;
		Control->cPrevControl = lastcontrol;
		lastcontrol = Control;
	}
	Control->bControlInitialized = true;
}

UUIControl* UUIScreen::GetControl(int32 Id)
{
	UUIControl* Control = nullptr;
	for (Control = cControlList; Control != nullptr; Control = Control->cNextControl)
	{
		if (Control->GetID() == Id)
		{
			return Control;
		}
	}
	return nullptr;
}

bool UUIScreen::EnableControl(int32 Id, bool State)
{
	UUIControl* Control = nullptr;
	Control = GetControl(Id);
	if (Control == nullptr)
	{
		return false;
	}
	else
	{
		Control->SetEnabled(State);
		return true;
	}
}

void UUIScreen::SetCheckBoxGroup(int32 GroupID, int32 controlid)
{
	UUIControl* Control = nullptr;
	//Log("UIScreen::SetCheckBoxGroup(" + FString::FromInt(GroupID) + ", " + FString::FromInt(controlid) + ")");
	for (Control = cControlList; Control != nullptr; Control = Control->cNextControl)
	{
		if ((Control->IsA(UUICheckbox::StaticClass()) || Control->IsA(UUICheckboxB::StaticClass())) || Control->IsA(UUICheckboxC::StaticClass()))
		{
			if (Control->GetGroupID() == GroupID)
			{
				if (Control->GetID() != controlid)
				{
					Control->Select(false);
				}
			}
		}
	}
}
