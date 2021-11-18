// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"

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
	/*
	local UIControl Control;
	local UIControl NextControl;
	cNextScreen = None;
	cFocus = None;
	cFrame = None;
	Control = cControlList;
	if (Control != None)
	{
		NextControl = Control.cNextControl;
		Control.bControlInitialized = False;
		Control.Destroyed();
		Control = NextControl;
	}
	cControlList = None;
	*/
}
void UUIScreen::ScaleControls(UCanvas* Canvas)
{
	/*
	local UIControl Control;
	if (_iOldSizeX == Canvas.SizeX && _iOldSizeY == Canvas.SizeY)
	{
		Return;
	}
	Control = cControlList;
	if (Control != None)
	{
		if (!Control.bControlInitialized)
		{
			Control = Control.cNextControl;
		}
		else
		{
			Control.ScaleControl(Canvas);
			Control = Control.cNextControl;
		}
	}
	_iOldSizeX = Canvas.SizeX;
	_iOldSizeY = Canvas.SizeY;
	offset.X = _Pos.X * fScaleX;
	offset.Y = _Pos.Y * fScaleY;
	*/
}
bool UUIScreen::KeyType(int32 Key)
{
	/*
	local UIControl Control;
	Control = cControlList;
	if (Control != None)
	{
		if (Control.KeyType(Key))
		{
			Return True;
		}
		Control = Control.cNextControl;
	}
	*/
	return false;
}
bool UUIScreen::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local UIControl Control;
	Control = cControlList;
	if (Control != None)
	{
		if (Control.ProcessKeyEvent(Key, Action, Delta))
		{
			Return True;
		}
		Control = Control.cNextControl;
	}
	if (Key == 9 && Action == 1)
	{
		Return True;
	}
	if (Action == 3)
	{
		if (Key == 40 || Key == 9)
		{
			if (cFrame._cMouseOver != None)
			{
				if (cFrame._cMouseOver.cScreen == Self)
				{
					Control = cFrame._cMouseOver;
					if (Control.cNextControl != None)
					{
						if (Control.cNextControl.IsA('UINavControl'))
						{
							cFrame._cMouseOver = Control.cNextControl;
							Return True;
						}
						Control = Control.cNextControl;
					}
					Control = cControlList;
					if (Control != cFrame._cMouseOver)
					{
						if (Control.IsA('UINavControl'))
						{
							cFrame._cMouseOver = Control;
							Return True;
						}
						Control = Control.cNextControl;
					}
				}
			}
			else
			{
				if (cFrame.cActiveScreen == Self)
				{
					Control = cControlList;
					if (Control != None)
					{
						if (Control.IsA('UINavControl'))
						{
							cFrame._cMouseOver = Control;
							Return True;
						}
						Control = Control.cNextControl;
					}
				}
			}
		}
		if (Key == 38)
		{
			if (cFrame._cMouseOver != None)
			{
				if (cFrame._cMouseOver.cScreen == Self)
				{
					Control = cFrame._cMouseOver;
					if (Control.cPrevControl != None)
					{
						if (Control.cPrevControl.IsA('UINavControl'))
						{
							cFrame._cMouseOver = Control.cPrevControl;
							Return True;
						}
						Control = Control.cPrevControl;
					}
					Control = GetLastControl();
					if (Control != cFrame._cMouseOver)
					{
						if (Control.IsA('UINavControl'))
						{
							cFrame._cMouseOver = Control;
							Return True;
						}
						Control = Control.cPrevControl;
					}
				}
			}
			else
			{
				if (cFrame.cActiveScreen == Self)
				{
					Control = GetLastControl();
					if (Control != None)
					{
						if (Control.IsA('UINavControl'))
						{
							cFrame._cMouseOver = Control;
							Return True;
						}
						Control = Control.cPrevControl;
					}
				}
			}
		}
	}
	*/
	return false;
}
void UUIScreen::DrawScreen(UCanvas* Canvas, bool bMouse)
{
	/*
	local UIControl Control;
	local int32 i;
	ScaleControls(Canvas);
	i = 1;
	i = 1;
	Control = cControlList;
	if (Control != None)
	{
		if (!Control.bControlInitialized)
		{
			Control = Control.cNextControl;
		}
		else
		{
			if (_bDebug)
			{
				Canvas.DrawText("UIFrame - Drawing control " $ i);
			}
			if (cFrame.cMouse != None && bMouse)
			{
				Control.MouseMove(cFrame.cMouse.iMouseX, cFrame.cMouse.iMouseY);
			}
			Control.Draw(Canvas);
			Control = Control.cNextControl;
			i++;
		}
	}
	i--;
	if (_bDebug)
	{
		Canvas.SetPos(0, 200);
		Canvas.DrawText("UIFrame - Controls drawn: " $ i);
		Canvas.DrawText("First Control ID: " $ cControlList.GetID());
	}
	if (cFocus != None && cFrame.cMouse != None && bMouse)
	{
		cFocus.MouseMove(cFrame.cMouse.iMouseX, cFrame.cMouse.iMouseY);
	}
	*/
}
void UUIScreen::Notify(int32 pUIEvent)
{
}
void UUIScreen::CreateUIListItems(FString ListItemsName)
{
	/*
	local UIListItems myListItems;
	local class<UIListItems>  cUIListItems;
	cUIListItems = class<UIListItems>(DynamicLoadObject(ListItemsName, Class'Class'));
	myListItems = new (None) classcUIListItems;
	Return myListItems;
	*/
}
void UUIScreen::CreateUIControl(FString ControlName)
{
	/*
	local UIControl myControl;
	local class<UIControl>  cUIControl;
	cUIControl = class<UIControl>(DynamicLoadObject(ControlName, Class'Class'));
	myControl = new (None) classcUIControl;
	Return myControl;
	*/
}
void UUIScreen::CreateUIMouse(FString MouseName)
{
	/*
	local UIMouse myMouse;
	local class<UIMouse>  cUIMouse;
	cUIMouse = class<UIMouse>(DynamicLoadObject(MouseName, Class'Class'));
	myMouse = new (None) classcUIMouse;
	Return myMouse;
	*/
}
void UUIScreen::AddControl(FString szControl, int32 pUIEvent)
{
}
void UUIScreen::AddRolloverButton(FString sControl, int32 pID, int32 pUIEvent, FPosition pPos, FString tString, int32 pParams, FString sToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl(sControl);
	Control.SetPos(pPos);
	UIRolloverButton(Control).SetTextureString(tString);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddRolloverBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams, FString sToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIRolloverBitmapButton");
	Control.SetPos(pPos);
	Control.SetTooltip(sToolTip);
	UIRolloverBitmapButton(Control).SetTextureDimensions(dim);
	UIRolloverBitmapButton(Control).SetTexture(Tex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddRolloverBitmapButtonB(int32 pID, int32 pUIEvent, FPosition pPos, UMaterialInstance* Tex, FPosition dim, int32 pParams, FString sToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIRolloverBitmapButtonB");
	Control.SetPos(pPos);
	Control.SetTooltip(sToolTip);
	UIRolloverBitmapButtonB(Control).SetTextureDimensions(dim);
	UIRolloverBitmapButtonB(Control).SetTexture(Tex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams, FString sToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBitmapButton");
	Control.SetPos(pPos);
	Control.SetTooltip(sToolTip);
	UIBitmapButton(Control).SetTextureDimensions(dim);
	UIBitmapButton(Control).SetTexture(Tex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddSimpleBitmapButton(int32 pID, int32 pUIEvent, FPosition pPos, UMaterialInstance* Tex, int32 pParams, FString sToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UISimpleBitmapButton");
	Control.SetPos(pPos);
	Control.SetTooltip(sToolTip);
	UISimpleBitmapButton(Control).SetTexture(Tex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddControlWithBaseBitmap(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, FString tex1, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl(sControl);
	Control.SetPos(pos);
	UIBitmap(Control).SetTexture(tex1);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddScrollbarV(int32 pID, int32 pUIEvent, FPosition pos, int32 imgW, int32 imgH, UMaterialInstance* BackTex, UMaterialInstance* ThumbTex, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIScrollbarV");
	Control.SetPos(pos);
	UIScrollbar(Control).SetImageDimensions(imgW, imgH);
	UIScrollbar(Control).SetBackTexture(BackTex);
	UIScrollbar(Control).SetThumbTexture(ThumbTex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddScrollbarH(int32 pID, int32 pUIEvent, FPosition pos, int32 imgW, int32 imgH, UMaterialInstance* BackTex, UMaterialInstance* ThumbTex, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIScrollbarH");
	Control.SetPos(pos);
	UIScrollbar(Control).SetImageDimensions(imgW, imgH);
	UIScrollbar(Control).SetBackTexture(BackTex);
	UIScrollbar(Control).SetThumbTexture(ThumbTex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUISlider(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pBack, FPosition pThumb, FString Label, int32 pParams, FString ClassName, FString PropName, float Min, float Max)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UISlider");
	Control.SetPos(pos);
	UISlider(Control).SetTexture(tex1);
	UISlider(Control).SetTexDimBack(pBack);
	UISlider(Control).SetTexDimThumb(pThumb);
	UISlider(Control).SetLabel(Label);
	UISlider(Control).SetClassName(ClassName);
	UISlider(Control).SetPropertyName(PropName);
	UISlider(Control).SetMinMax(Min, Max);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUISliderSeg(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pBack, FPosition pThumb, FString Label, int32 pParams, FString ClassName, FString PropName, int32 segments)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UISliderSeg");
	Control.SetPos(pos);
	UISliderSeg(Control).SetTexture(tex1);
	UISliderSeg(Control).SetTexDimBack(pBack);
	UISliderSeg(Control).SetTexDimThumb(pThumb);
	UISliderSeg(Control).SetLabel(Label);
	UISliderSeg(Control).SetClassName(ClassName);
	UISliderSeg(Control).SetPropertyName(PropName);
	UISliderSeg(Control).SetNumSegments(segments);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUISliderH(int32 pID, int32 pUIEvent, FPosition pos, FString tex1, FPosition pThumb, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UISliderH");
	Control.SetPos(pos);
	UISliderH(Control).SetTexture(tex1);
	UISliderH(Control).SetTexDimThumb(pThumb);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIClassButton(int32 pID, int32 pUIEvent, FPosition pPos, FPosition dim, int32 Index, FString classtex, FString altclass1tex, FString altclass2tex, FString altclass3tex, FString overlaytex)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIClassButton");
	Control.SetPos(pPos);
	UIClassButton(Control).SetTextureDimensions(dim);
	UIClassButton(Control).SetClassTexture(classtex);
	UIClassButton(Control).SetAltClass1Texture(altclass1tex);
	UIClassButton(Control).SetAltClass2Texture(altclass2tex);
	UIClassButton(Control).SetAltClass3Texture(altclass3tex);
	UIClassButton(Control).SetOverlayTexture(overlaytex);
	UIClassButton(Control).SetNotAvailTexture("T_AA2_UI.menu.ui_gm_na");
	UIClassButton(Control).SetNotQualTexture("T_AA2_UI.menu.ui_gm_nqual");
	UIClassButton(Control).SetSelectTexture("T_AA2_UI.menu.ui_gm_highlight");
	UIClassButton(Control).SetLabel("RANDOM");
	UIClassButton(Control).SetClassIndex(Index);
	Control.Create(cFrame, Self, pID, pUIEvent, 0);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddListItemBox(int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIListItemBox");
	if (Control == None)
	{
		cFrame.UILog("AddListItemBox - CreateUIControl FAILED");
	}
	Control.SetPos(pos);
	Control.SetTooltip(ToolTip);
	UIListItemBox(Control).SetTexture(tex1);
	UIListItemBox(Control).SetTexture2(tex2);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddInvListBox(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl(sControl);
	if (Control == None)
	{
		cFrame.UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Control.SetPos(pos);
	cFrame.UILog("AddInvListBox - set textures");
	UIInvListBox(Control).SetTexture(tex1);
	UIInvListBox(Control).SetTexture2(tex2);
	UIInvListBox(Control).SetSize(pParams);
	cFrame.UILog("AddInvListBox - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddInvDropBox(int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIInvDropBox");
	if (Control == None)
	{
		cFrame.UILog("AddInvDropBox - CreateUIControl FAILED");
	}
	Control.SetPos(pos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddInvDropBox - set textures");
	UIInvDropBox(Control).SetTexture(tex1);
	UIInvDropBox(Control).SetTexture2(tex2);
	UIInvDropBox(Control).SetBorderTexture(bordertex);
	UIInvDropBox(Control).SetTextureDimensions(pDim2);
	cFrame.UILog("AddInvDropBox - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddInvSlot(FString sControl, int32 pID, int32 pUIEvent, FPosition pos, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl(sControl);
	if (Control == None)
	{
		cFrame.UILog("AddInvSlot - CreateUIControl FAILED");
	}
	Control.SetPos(pos);
	cFrame.UILog("AddInvSlot - set textures");
	UIInvSlot(Control).SetTexture(tex1);
	UIInvSlot(Control).SetTexture2(tex2);
	UIInvSlot(Control).SetSize(pParams);
	cFrame.UILog("AddInvSlot - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddInvContainerListBox(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip, bool bLarge)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIInvContainerListBox");
	if (Control == None)
	{
		cFrame.UILog("AddInvListBox - CreateUIControl FAILED");
	}
	UIInvContainerListBox(Control).SetLarge(bLarge);
	cFrame.UILog("SetLarge: " $ bLarge);
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddInvContainerListBox - set textures");
	UIInvContainerListBox(Control).SetTexture(tex1);
	UIInvContainerListBox(Control).SetTexture2(tex2);
	UIInvContainerListBox(Control).SetBorderTexture(bordertex);
	UIInvContainerListBox(Control).SetTextureDimensions(pDim2);
	cFrame.UILog("AddInvContainerListBox - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	UIInvContainerListBox(Control).SetItemDimensions(pDim.X, pDim.Y, pDim.W, pDim.H);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddInvContainerSlot(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIInvContainerSlot");
	if (Control == None)
	{
		cFrame.UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddInvContainerSlot - set textures");
	UIInvContainerSlot(Control).SetTexture(tex1);
	UIInvContainerSlot(Control).SetTexture2(tex2);
	UIInvContainerSlot(Control).SetBorderTexture(bordertex);
	UIInvContainerSlot(Control).SetTextureDimensions(pDim2);
	cFrame.UILog("AddInvContainerSlot - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	UIInvContainerSlot(Control).SetItemDimensions(pDim.X, pDim.Y, pDim.W, pDim.H);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddHUDRackItem(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, FPosition pDim2, UMaterialInstance* bordertex, int32 pParams, int32 Index)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIHUDRackItem");
	if (Control == None)
	{
		cFrame.UILog("AddInvListBox - CreateUIControl FAILED");
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddHUDRackItem - set textures");
	UIHUDRackItem(Control).SetTexture(tex1);
	UIHUDRackItem(Control).SetTexture2(tex2);
	UIHUDRackItem(Control).SetBorderTexture(bordertex);
	UIHUDRackItem(Control).SetTextureDimensions(pDim2);
	UIHUDRackItem(Control).SetRackIndex(Index);
	cFrame.UILog("AddHUDRackItem - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	UIHUDRackItem(Control).SetItemDimensions(pDim.X, pDim.Y, pDim.W, pDim.H);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddHUDBaseDisplay(FString controlstring, int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	cFrame.UILog("AddHUDBaseDisplay - creating " $ controlstring);
	Control = CreateUIControl(controlstring);
	if (Control == None)
	{
		cFrame.UILog("AddHUDBaseDisplay - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddHUDBaseDisplay - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBorder(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBorder");
	if (Control == None)
	{
		cFrame.UILog("AddUIBorder - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	UIBorder(Control).SetTextureDimensions(pDim);
	cFrame.UILog("AddUIBorder - set textures");
	UIBorder(Control).SetTexture(tex1);
	UIBorder(Control).SetTexture2(tex2);
	cFrame.UILog("AddUIBorder - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBorder2(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBorder2");
	if (Control == None)
	{
		cFrame.UILog("AddUIBorder2 - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	UIBorder(Control).SetTextureDimensions(pDim);
	cFrame.UILog("AddUIBorder2 - set textures");
	UIBorder(Control).SetTexture(tex1);
	UIBorder(Control).SetTexture2(tex2);
	cFrame.UILog("AddUIBorder2 - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBorder3(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBorder3");
	if (Control == None)
	{
		cFrame.UILog("AddUIBorder3 - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	UIBorder(Control).SetTextureDimensions(pDim);
	cFrame.UILog("AddUIBorder3 - set textures");
	UIBorder(Control).SetTexture(tex1);
	UIBorder(Control).SetTexture2(tex2);
	cFrame.UILog("AddUIBorder3 - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBorderButton(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, UMaterialInstance* tex3, FString sLabel, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBorderButton");
	if (Control == None)
	{
		cFrame.UILog("AddUIBorderButton - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	UIBorderButton(Control).SetTextureDimensions(pDim);
	UIBorderButton(Control).SetLabel(sLabel);
	cFrame.UILog("AddUIBorderButton - set textures");
	UIBorderButton(Control).SetTexture(tex1);
	UIBorderButton(Control).SetTexture2(tex2);
	UIBorderButton(Control).SetTexture3(tex3);
	cFrame.UILog("AddUIBorderButton - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBorderButtonB(int32 pID, int32 pUIEvent, int32 pUIEvent2, FPosition pPos, FPosition pDim, UMaterialInstance* tex1, UMaterialInstance* tex2, UMaterialInstance* tex3, FString sLabel, FString sLabel2, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBorderButtonB");
	if (Control == None)
	{
		cFrame.UILog("AddUIBorderButtonB - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	UIBorderButtonB(Control).SetTextureDimensions(pDim);
	UIBorderButtonB(Control).SetLabel(sLabel);
	UIBorderButtonB(Control).SetLabel2(sLabel2);
	cFrame.UILog("AddUIBorderButtonB - set textures");
	UIBorderButtonB(Control).SetTexture(tex1);
	UIBorderButtonB(Control).SetTexture2(tex2);
	UIBorderButtonB(Control).SetTexture3(tex3);
	cFrame.UILog("AddUIBorderButtonB - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	UIBorderButtonB(Control).SetEvent2(pUIEvent2);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUICheckBoxFn(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName, FString funcname)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UICheckBoxFn");
	if (Control == None)
	{
		cFrame.UILog("AddUICheckBoxFn - CreateUIControl FAILED");
		Return;
	}
	Control.SetGroupID(GroupID);
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddCheckBox - set textures");
	UICheckboxFn(Control).SetLabel(Label);
	UICheckboxFn(Control).SetTexture(tex1);
	UICheckboxFn(Control).SetTextureDimensions(pDim);
	UICheckboxFn(Control).SetClassName(ClassName);
	UICheckboxFn(Control).SetPropertyName(PropName);
	UICheckboxFn(Control).SetFuncName(funcname);
	cFrame.UILog("AddUICheckBoxFn - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUICheckBox(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UICheckBox");
	if (Control == None)
	{
		cFrame.UILog("AddCheckBox - CreateUIControl FAILED");
		Return;
	}
	Control.SetGroupID(GroupID);
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddCheckBox - set textures");
	UICheckbox(Control).SetLabel(Label);
	UICheckbox(Control).SetTexture(tex1);
	UICheckbox(Control).SetTextureDimensions(pDim);
	UICheckbox(Control).SetClassName(ClassName);
	UICheckbox(Control).SetPropertyName(PropName);
	cFrame.UILog("AddCheckBox - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUICheckBoxB(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UICheckBoxB");
	if (Control == None)
	{
		cFrame.UILog("AddCheckBoxB - CreateUIControl FAILED");
		Return;
	}
	Control.SetGroupID(GroupID);
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddCheckBoxB - set textures");
	UICheckboxB(Control).SetLabel(Label);
	UICheckboxB(Control).SetTexture(tex1);
	UICheckboxB(Control).SetTextureDimensions(pDim);
	UICheckboxB(Control).SetClassName(ClassName);
	UICheckboxB(Control).SetPropertyName(PropName);
	cFrame.UILog("AddCheckBoxB - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUICheckBoxC(int32 pID, int32 pUIEvent, FPosition pPos, FPosition pDim, FString tex1, FString Label, int32 pParams, FString ToolTip, int32 GroupID, FString ClassName, FString PropName, FString valuename)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UICheckBoxC");
	if (Control == None)
	{
		cFrame.UILog("AddCheckBoxC - CreateUIControl FAILED");
		Return;
	}
	Control.SetGroupID(GroupID);
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddCheckBoxC - set textures");
	UICheckboxC(Control).SetLabel(Label);
	UICheckboxC(Control).SetTexture(tex1);
	UICheckboxC(Control).SetTextureDimensions(pDim);
	UICheckboxC(Control).SetClassName(ClassName);
	UICheckboxC(Control).SetPropertyName(PropName);
	UICheckboxC(Control).SetValueName(valuename);
	cFrame.UILog("AddCheckBoxC - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIKeymap(int32 pID, int32 pUIEvent, FPosition pPos, FString tex1, FPosition dim, FString Command, int32 pParams, FString Label)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIKeymap");
	if (Control == None)
	{
		cFrame.UILog("AddUIKeymap - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIKeymap - set textures");
	UIKeymap(Control).SetTexture(tex1);
	UIKeymap(Control).SetTextureDimensions(dim);
	UIKeymap(Control).SetCommand(Command);
	UIKeymap(Control).SetLabel(Label);
	cFrame.UILog("AddUIKeymap - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIEditBox(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FString ToolTip, int32 maxlen)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIEditBox");
	if (Control == None)
	{
		cFrame.UILog("AddUIEditBox - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddUIEditBox - set textures");
	UIEditBox(Control).SetLabel(Label);
	UIEditBox(Control).SetMaxLength(maxlen);
	cFrame.UILog("AddUIEditBox - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUITextDisplay(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FString ToolTip, int32 fontindex, int32 colorindex)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UITextDisplay");
	if (Control == None)
	{
		cFrame.UILog("AddUITextDisplay - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	cFrame.UILog("AddUITextDisplay - set label");
	UITextDisplay(Control).SetLabel(Label);
	UITextDisplay(Control).SetFontIndex(fontindex);
	UITextDisplay(Control).SetColorIndex(colorindex);
	cFrame.UILog("AddUITextDisplay - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUITextDisplayColor(int32 pID, int32 pUIEvent, FPosition pPos, FString Label, int32 pParams, FColor cColor)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UITextDisplayColor");
	if (Control == None)
	{
		cFrame.UILog("AddUITextDisplayColor - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUITextDisplayColor - label/color");
	UITextDisplayColor(Control).SetLabel(Label);
	UITextDisplayColor(Control).SetColor(cColor);
	cFrame.UILog("AddUITextDisplayColor - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIVideoMode(int32 pID, int32 pUIEvent, FPosition pPos, FString tex1, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIVideoMode");
	if (Control == None)
	{
		cFrame.UILog("AddUIVideoMode - CreateUIControl FAILED");
		Return;
	}
	UIVideoMode(Control).SetTexture(tex1);
	Control.SetPos(pPos);
	cFrame.UILog("AddUIVideoMode - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBitmap(int32 pID, FPosition pos, FString tex1, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBitmap");
	if (Control == None)
	{
		Return;
	}
	Control.SetPos(pos);
	UIBitmap(Control).SetTexture(tex1);
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIBitmapB(int32 pID, FPosition pos, FString tex1, FPosition dim, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIBitmapB");
	Control.SetPos(pos);
	UIBitmapB(Control).SetTexture(tex1);
	UIBitmapB(Control).SetTextureDimensions(dim);
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIDynamicBitmap(int32 pID, FPosition pos, FString tex1, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIDynamicBitmap");
	if (Control == None)
	{
		Return;
	}
	Control.SetPos(pos);
	UIDynamicBitmap(Control).SetTexture(tex1, 64, 64, 0);
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddHUDCompass(int32 pID, int32 pUIEvent, UMaterialInstance* tex1, UMaterialInstance* tex2, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIHUDCompass");
	if (Control == None)
	{
		cFrame.UILog("AddHUDCompass - CreateUIControl FAILED");
		Return;
	}
	cFrame.UILog("AddHUDCompass - set textures");
	UIHUDCompass(Control).SetTexture(tex1);
	UIHUDCompass(Control).SetBracketTexture(tex2);
	cFrame.UILog("AddHUDCompass - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddMissionResultDisplay(FString controlstring, int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl(controlstring);
	if (Control == None)
	{
		cFrame.UILog("AddMissionResultDisplay - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddMissionResultDisplay - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUITextButton(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UITextButton");
	if (Control == None)
	{
		cFrame.UILog("AddUITextButton - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	UITextButton(Control).SetLabel(sLabel);
	cFrame.UILog("AddUITextButton - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUITextButtonSize(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, int32 Size)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UITextButtonSize");
	if (Control == None)
	{
		cFrame.UILog("AddUITextButtonSize - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	UITextButtonSize(Control).SetSize(Size);
	UITextButtonSize(Control).SetLabel(sLabel);
	cFrame.UILog("AddUITextButtonSize - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIWebLink(int32 pID, int32 pUIEvent, FPosition pPos, FString sLabel, int32 pParams, FString ToolTip)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIWebLink");
	if (Control == None)
	{
		cFrame.UILog("AddUIWebLink - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	Control.SetTooltip(ToolTip);
	UIWebLink(Control).SetLabel(sLabel);
	cFrame.UILog("AddUIWebLink - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIWebLinkButton(int32 pID, int32 pUIEvent, FPosition pPos, FString Tex, FPosition dim, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIWebLinkButton");
	if (Control == None)
	{
		Return;
	}
	Control.SetPos(pPos);
	UIWebLinkButton(Control).SetTextureDimensions(dim);
	UIWebLinkButton(Control).SetTexture(Tex);
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIQuickLan(int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIQuickLan");
	if (Control == None)
	{
		cFrame.UILog("AddUIQuickLan - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIQuickLan - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIServerListDisplay(int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIServerListDisplay");
	if (Control == None)
	{
		cFrame.UILog("AddUIServerListDisplay - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIServerListDisplay - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIPlayerList(int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIPlayerList");
	if (Control == None)
	{
		cFrame.UILog("AddUIPlayerList - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIPlayerList - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUISettingsList(int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UISettingsList");
	if (Control == None)
	{
		cFrame.UILog("AddUISettingsList - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUISettingsList - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIConsole(int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIConsole");
	if (Control == None)
	{
		cFrame.UILog("AddUIConsole - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIConsole - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIImageListDisplay(int32 pID, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIImageListDisplay");
	if (Control == None)
	{
		cFrame.UILog("AddUIImageListDisplay - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIImageListDisplay - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUITextPageDisplay(int32 pID, FPosition pPos, int32 pParams, int32 Lines, bool bpagedisplay)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UITextPageDisplay");
	if (Control == None)
	{
		cFrame.UILog("AddUITextPageDisplay - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	UITextPageDisplay(Control).SetLinesPerPage(Lines);
	UITextPageDisplay(Control).SetPageDisplay(bpagedisplay);
	cFrame.UILog("AddUITextPageDisplay - create");
	Control.Create(cFrame, Self, pID, 0, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIScrollingCredits(int32 pID, int32 pUIEvent, FPosition pPos, int32 pParams)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIScrollingCredits");
	if (Control == None)
	{
		cFrame.UILog("AddUIScrollingCredits - CreateUIControl FAILED");
		Return;
	}
	Control.SetPos(pPos);
	cFrame.UILog("AddUIScrollingCredits - create");
	Control.Create(cFrame, Self, pID, pUIEvent, pParams);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIEscapeKey(int32 pID, int32 pUIEvent)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIEscapeKey");
	if (Control == None)
	{
		cFrame.UILog("AddUIEscapeKey - CreateUIControl FAILED");
		Return;
	}
	cFrame.UILog("AddUIEscapeKey - create");
	Control.Create(cFrame, Self, pID, pUIEvent, 0);
	AddControlToTail(Control);
	*/
}
void UUIScreen::AddUIKeyCapture(int32 pID, int32 pUIEvent)
{
	/*
	local UIControl Control;
	Control = CreateUIControl("AGP_UI.UIKeyCapture");
	if (Control == None)
	{
		cFrame.UILog("AddUIKeyCapture - CreateUIControl FAILED");
		Return;
	}
	cFrame.UILog("AddUIKeyCapture - create");
	Control.Create(cFrame, Self, pID, pUIEvent, 0);
	AddControlToTail(Control);
	*/
}
void UUIScreen::SetFocus(UUIControl* Control)
{
	/*
	if (cFocus != None && cFocus != Control)
	{
		cFocus.Focus(False);
	}
	cFocus = Control;
	cFocus.Focus(True);
	*/
}
void UUIScreen::DumpControlLog()
{
	/*
	local UIControl Control;
	local int32 i;
	cFrame.UILog("#### DUMP CONTROL LOG START ####");
	Control = cControlList;
	if (Control != None)
	{
		cFrame.UILog("control #" $ i $ " is ID " $ Control.GetID());
		Control = Control.cNextControl;
		i++;
	}
	cFrame.UILog("#### DUMP CONTROL LOG END ####");
	*/
}
UUIControl* UUIScreen::GetLastControl()
{
	UUIControl* Control = nullptr;
	/*
	Control = cControlList;
	if (Control != None)
	{
		if (Control.cNextControl == None)
		{
			Return Control;
		}
		Control = Control.cNextControl;
	}
	*/
	return Control;
}
void UUIScreen::AddControlToTail(UUIControl* Control)
{
	/*
	local UIControl lastcontrol;
	lastcontrol = GetLastControl();
	if (lastcontrol == None)
	{
		cControlList = Control;
	}
	else
	{
		lastcontrol.cNextControl = Control;
		Control.cPrevControl = lastcontrol;
		lastcontrol = Control;
	}
	Control.bControlInitialized = true;
	*/
}
UUIControl* UUIScreen::GetControl(int32 Id)
{
	UUIControl* Control = nullptr;
	/*
	Control = cControlList;
	if (Control != None)
	{
		if (Control.GetID() == Id)
		{
			return Control;
		}
		Control = Control.cNextControl;
	}
	*/
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
	/*
	local UIControl Control;
	Log("UIScreen::SetCheckBoxGroup(" $ GroupID $ ", " $ controlid $ ")");
	Control = cControlList;
	if (Control != None)
	{
		if (Control.IsA('UICheckbox') || Control.IsA('UICheckboxB') || Control.IsA('UICheckboxC'))
		{
			if (Control.GetGroupID() == GroupID)
			{
				if (Control.GetID() != controlid)
				{
					Control.Select(False);
				}
			}
		}
		Control = Control.cNextControl;
	}
	*/
}
