// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_WeaponPref/Tab_WeaponPref.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"


UTab_WeaponPref::UTab_WeaponPref()
{
	UmoCheckBox* WeaponSwap = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	WeaponSwap->ComponentJustification = EeTextAlign::TXTA_Left;
	WeaponSwap->Caption = "Swap Fire Mode";
	//WeaponSwap->OnCreateComponent=WeaponSwap.InternalOnCreateComponent;
	WeaponSwap->Hint = "Check this box to swap the firing mode on the selected weapon.";
	WeaponSwap->WinTop = 0.970312;
	WeaponSwap->WinLeft = 0.551437;
	WeaponSwap->WinWidth = 0.26875;
	WeaponSwap->WinHeight = 0.04;
	//WeaponSwap->OnChange=Tab_WeaponPref.InternalOnChange;
	UGUIScrollTextBox* WeaponDescription = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	WeaponDescription->CharDelay = 0.0015;
	WeaponDescription->EOLDelay = 0.25;
	//WeaponDescription->OnCreateComponent=WeaponDescription.InternalOnCreateComponent;
	WeaponDescription->WinTop = 0.656667;
	WeaponDescription->WinLeft = 0.449999;
	WeaponDescription->WinWidth = 0.532501;
	WeaponDescription->WinHeight = 0.27875;
	WeaponDescription->bAcceptsInput = false;
	WeaponDescription->bNeverFocus = true;
	UmoCheckBox* WeaponAutoSwitch = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	WeaponAutoSwitch->ComponentJustification = EeTextAlign::TXTA_Left;
	WeaponAutoSwitch->Caption = "Switch On Pickup";
	//WeaponAutoSwitch->OnCreateComponent=WeaponAutoSwitch.InternalOnCreateComponent;
	WeaponAutoSwitch->Hint = "Automatically change weapons when you pick up a better one.";
	WeaponAutoSwitch->WinTop = 0.939062;
	WeaponAutoSwitch->WinLeft = 0.028;
	WeaponAutoSwitch->WinWidth = 0.3;
	WeaponAutoSwitch->WinHeight = 0.06;
	//WeaponAutoSwitch->OnChange=Tab_WeaponPref.InternalOnChange;
	UGUIButton* WeaponDefaults = NewObject<UGUIButton>(UGUIButton::StaticClass());
	WeaponDefaults->Caption = "Defaults";
	WeaponDefaults->Hint = "Set the weapon priorities back to default";
	WeaponDefaults->WinTop = 0.8;
	WeaponDefaults->WinLeft = 0.23125;
	WeaponDefaults->WinWidth = 0.19;
	WeaponDefaults->WinHeight = 0.05;
	//WeaponDefaults->OnClick=Tab_WeaponPref.WeapDefaults;
	//WeaponDefaults->OnKeyEvent=WeaponDefaults.InternalOnKeyEvent;
	UGUIButton* WeaponPrefWeapDown = NewObject<UGUIButton>(UGUIButton::StaticClass());
	WeaponPrefWeapDown->Caption = "Lower Priority";
	WeaponPrefWeapDown->Hint = "Decrease the priority this weapon will have when picking your best weapon.";
	WeaponPrefWeapDown->WinTop = 0.87;
	WeaponPrefWeapDown->WinLeft = 0.022;
	WeaponPrefWeapDown->WinWidth = 0.19;
	WeaponPrefWeapDown->WinHeight = 0.05;
	WeaponPrefWeapDown->OnClickSound = EClickSound::CS_Down;
	//WeaponPrefWeapDown->OnClick=Tab_WeaponPref.WeapDown;
	//WeaponPrefWeapDown->OnKeyEvent=WeaponPrefWeapDown.InternalOnKeyEvent;
	UGUIButton* WeaponPrefWeapUp = NewObject<UGUIButton>(UGUIButton::StaticClass());
	WeaponPrefWeapUp->Caption = "Raise Priority";
	WeaponPrefWeapUp->Hint = "Increase the priority this weapon will have when picking your best weapon.";
	WeaponPrefWeapUp->WinTop = 0.8;
	WeaponPrefWeapUp->WinLeft = 0.022;
	WeaponPrefWeapUp->WinWidth = 0.19;
	WeaponPrefWeapUp->WinHeight = 0.05;
	WeaponPrefWeapUp->OnClickSound = EClickSound::CS_Up;
	//WeaponPrefWeapUp->OnClick=Tab_WeaponPref.WeapUp;
	//WeaponPrefWeapUp->OnKeyEvent=WeaponPrefWeapUp.InternalOnKeyEvent;
	UGUIListBox* WeaponPrefWeapList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	WeaponPrefWeapList->bVisibleWhenEmpty = true;
	//WeaponPrefWeapList->OnCreateComponent=WeaponPrefWeapList.InternalOnCreateComponent;
	WeaponPrefWeapList->StyleName = "SquareButton";
	WeaponPrefWeapList->Hint = "Select order for weapons";
	WeaponPrefWeapList->WinTop = 0.083333;
	WeaponPrefWeapList->WinLeft = 0.022;
	WeaponPrefWeapList->WinWidth = 0.4;
	WeaponPrefWeapList->WinHeight = 0.696251;
	//WeaponPrefWeapList->OnChange=Tab_WeaponPref.InternalOnChange;
	UGUILabel* WeaponPriorityLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	WeaponPriorityLabel->Caption = "Weapon Priority";
	WeaponPriorityLabel->TextColor = FColor(255, 255, 255, 255);
	WeaponPriorityLabel->WinTop = 0.015;
	WeaponPriorityLabel->WinLeft = 0.031914;
	WeaponPriorityLabel->WinWidth = 0.4;
	WeaponPriorityLabel->WinHeight = 32;
	UGUIImage* WeaponBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	WeaponBK->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBox_Mat.BorderBox_Mat'"), NULL, LOAD_None, NULL);
	WeaponBK->ImageColor = FColor(255, 255, 255, 160);
	WeaponBK->ImageStyle = EImgStyle::ISTY_Stretched;
	WeaponBK->WinTop = 0.085365;
	WeaponBK->WinLeft = 0.450391;
	WeaponBK->WinWidth = 0.533749;
	WeaponBK->WinHeight = 0.55227;
	SpinnyWeapOffset = FVector(150, 54.5, 14);
	Controls = { WeaponPrefWeapList,WeaponPrefWeapUp,WeaponPrefWeapDown,WeaponDefaults,WeaponAutoSwitch,WeaponDescription,WeaponPriorityLabel,WeaponBK,WeaponSwap };
	WinTop = 0.15;
	WinHeight = 0.74;
	//OnDraw = Tab_WeaponPref.InternalDraw;
}


int32 UTab_WeaponPref::CompareWeaponPriority(FGUIListElem ElemA, FGUIListElem ElemB)
{
	/*
	int32 PA = 0;
	int32 PB = 0;
	local class<Weapon>  WA;
	local class<Weapon>  WB;
	WA = class<Weapon>(ElemA.ExtraData);
	WB = class<Weapon>(ElemB.ExtraData);
	if (bUseDefaultPriority)
	{
		GOTO JL0062;
	}
	PA = WA.Default.Priority;
	PB = WB.Default.Priority;
JL0062:
	return (PB - PA);
	*/

	return 0;    //FAKE   /EliZ
}

void UTab_WeaponPref::ShowPanel(bool bShow)
{
	/*
	if (!bWeapPrefInitialised)
	{
		MyCurWeaponList.List.__CompareItem__Delegate = CompareWeaponPriority;
		if (Controller.OpenMenu("xinterface.UT2LoadingWeapons"))
		{
			UT2LoadingWeapons(Controller.TopPage()).StartLoad(Self);
		}
	}
	Super::ShowPanel(bShow);
	if ((!bShow) && bWeapPrefInitialised)
	{
		WeapApply(None);
	}
	*/
}

void UTab_WeaponPref::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyCurWeaponList = GUIListBox(Controls[0]);
	SwitchWeaponCheckBox = moCheckBox(Controls[4]);
	WeaponDescriptionBox = GUIScrollTextBox(Controls[5]);
	SwitchWeaponCheckBox.Checked((!Class'PlayerController'.Default.bNeverSwitchOnPickup));
	*/
}

void UTab_WeaponPref::UpdateWeaponPriorities()
{
	/*
	int32 i = 0;
	local class<Weapon>  W;
	for (i = 0; i < MyCurWeaponList.List.ItemCount; i++)
	{
		W = class<Weapon>(MyCurWeaponList.List.GetObjectAtIndex(i));
		W.Default.Priority = byte((MyCurWeaponList.List.ItemCount - i));
		W.StaticSaveConfig();
	}
	*/
}

bool UTab_WeaponPref::WeapDefaults(UGUIComponent* Sender)
{
	/*
	bUseDefaultPriority = true;
	MyCurWeaponList.List.SortList();
	MyCurWeaponList.List.SetIndex(0);
	UpdateCurrentWeapon();
	bChanged = true;
	bUseDefaultPriority = false;
	*/
	return true;
}

bool UTab_WeaponPref::WeapApply(UGUIComponent* Sender)
{
	/*
	if (bChanged)
	{
		UpdateWeaponPriorities();
	}
	bChanged = false;
	*/
	return true;
}

void UTab_WeaponPref::OnDeActivate()
{
	//WeapApply(Self);
}

void UTab_WeaponPref::SwapWeapons(int32 IndexA, int32 IndexB)
{
	/*
	MyCurWeaponList.List.Swap(IndexA, IndexB);
	bChanged = true;
	*/
}

bool UTab_WeaponPref::WeapUp(UGUIComponent* Sender)
{
	/*
	int32 currPos = 0;
	if (MyCurWeaponList.List.ItemCount == 0)
	{
		return true;
	}
	currPos = MyCurWeaponList.List.Index;
	if (currPos == 0)
	{
		return true;
	}
	SwapWeapons(currPos, (currPos - 1));
	MyCurWeaponList.List.Index = (currPos - 1);
	*/
	return true;
}

bool UTab_WeaponPref::WeapDown(UGUIComponent* Sender)
{
	/*
	int32 currPos = 0;
	if (MyCurWeaponList.List.ItemCount == 0)
	{
		return true;
	}
	currPos = MyCurWeaponList.List.Index;
	if (currPos == (MyCurWeaponList.List.ItemCount - 1))
	{
		return true;
	}
	SwapWeapons(currPos, (currPos + 1));
	MyCurWeaponList.List.Index = (currPos + 1);
	*/
	return true;
}

bool UTab_WeaponPref::InternalDraw(UCanvas* Canvas)
{
	/*
	FVector CamPos = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector WX = FVector(0, 0, 0);
	FVector WY = FVector(0, 0, 0);
	FVector WZ = FVector(0, 0, 0);
	FRotator CamRot = FRotator(0, 0, 0);
	if (MyCurWeapon != None)
	{
		Canvas.GetCameraLocation(CamPos, CamRot);
		GetAxes(CamRot, X, Y, Z);
		if (SpinnyWeap.DrawType == 2)
		{
			GetAxes(SpinnyWeap.Rotation, WX, WY, WZ);
			SpinnyWeap.SetLocation(((((CamPos + (SpinnyWeapOffset.X * X)) + (SpinnyWeapOffset.Y * Y)) + (SpinnyWeapOffset.Z * Z)) + (float(30) * WX)));
		}
		else
		{
			SpinnyWeap.SetLocation((((CamPos + (SpinnyWeapOffset.X * X)) + (SpinnyWeapOffset.Y * Y)) + (SpinnyWeapOffset.Z * Z)));
		}
		Canvas.DrawActor(SpinnyWeap, false, true, 90);
	}
	*/
	return false;
}

void UTab_WeaponPref::UpdateCurrentWeapon()
{
	/*
	local class<Weapon>  currWeap;
	local class<Pickup>  PickupClass;
	local class<InventoryAttachment>  attachClass;
	FVector Scale3D = FVector(0, 0, 0);
	bool B = false;
	int32 i = 0;
	if (SpinnyWeap == None)
	{
		return;
	}
	currWeap = class<Weapon>(MyCurWeaponList.List.GetObject());
	if ((currWeap != None) && (currWeap != MyCurWeapon))
	{
		MyCurWeapon = currWeap;
		PickupClass = MyCurWeapon.Default.PickupClass;
		attachClass = MyCurWeapon.Default.AttachmentClass;
		if (MyCurWeapon != None)
		{
			if ((PickupClass != None) && (PickupClass.Default.StaticMesh != None))
			{
				SpinnyWeap.LinkMesh(None);
				SpinnyWeap.SetStaticMesh(PickupClass.Default.StaticMesh);
				SpinnyWeap.SetDrawScale(PickupClass.Default.DrawScale);
				SpinnyWeap.SetDrawScale3D(PickupClass.Default.DrawScale3D);
				SpinnyWeap.Skins.Length = PickupClass.Default.Skins.Length;
				for (i = 0; i < PickupClass.Default.Skins.Length; i++)
				{
					SpinnyWeap.Skins[i] = PickupClass.Default.Skins[i];
				}
				SpinnyWeap.SetDrawType(DT_StaticMesh);
			}
			else
			{
				if ((attachClass != None) && (attachClass.Default.Mesh != None))
				{
					SpinnyWeap.SetStaticMesh(None);
					SpinnyWeap.LinkMesh(attachClass.Default.Mesh);
					SpinnyWeap.SetDrawScale((1.5 * attachClass.Default.DrawScale));
					SpinnyWeap.Skins.Length = attachClass.Default.Skins.Length;
					for (i = 0; i < attachClass.Default.Skins.Length; i++)
					{
						SpinnyWeap.Skins[i] = attachClass.Default.Skins[i];
					}
					Scale3D = attachClass.Default.DrawScale3D;
					Scale3D.Z *= -1;
					SpinnyWeap.SetDrawScale3D((1.5 * Scale3D));
					SpinnyWeap.SetDrawType(DT_Mesh);
				}
				else
				{
					Log("Could not find graphic for weapon: " $ string(MyCurWeapon));
				}
			}
		}
	}
	WeaponDescriptionBox.SetContent(MyCurWeaponList.List.GetExtra());
	B = (currWeap.Default.ExchangeFireModes == 1);
	moCheckBox(Controls[8]).Checked(B);
	*/
}

void UTab_WeaponPref::InternalOnChange(UGUIComponent* Sender)
{
	/*
	bool sw = false;
	local class<Weapon>  currWeap;
	if (Sender == Controls[0])
	{
		UpdateCurrentWeapon();
		OnChange(Self);
	}
	else
	{
		if (Sender == Controls[4])
		{
			sw = (!SwitchWeaponCheckBox.IsChecked());
			PlayerOwner().bNeverSwitchOnPickup = sw;
			Class'PlayerController'.Default.bNeverSwitchOnPickup = sw;
			Class'PlayerController'.StaticSaveConfig();
		}
		else
		{
			if (Sender == Controls[8])
			{
				currWeap = class<Weapon>(MyCurWeaponList.List.GetObject());
				if (moCheckBox(Controls[8]).IsChecked())
				{
					currWeap.Default.ExchangeFireModes = 1;
				}
				else
				{
					currWeap.Default.ExchangeFireModes = 0;
				}
				currWeap.StaticSaveConfig();
			}
		}
	}
	*/
}