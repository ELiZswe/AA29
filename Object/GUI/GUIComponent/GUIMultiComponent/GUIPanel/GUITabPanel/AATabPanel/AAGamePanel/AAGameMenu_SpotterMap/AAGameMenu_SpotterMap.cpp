// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_SpotterMap/AAGameMenu_SpotterMap.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAAGameMenu_SpotterMap::UAAGameMenu_SpotterMap()
{
	UGUIImageButton* MapImage = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	MapImage->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Maps/Overhead/NoImag_Mat.NoImag_Mat'"), NULL, LOAD_None, NULL);
	MapImage->ImageStyle = EImgStyle::ISTY_Scaled;
	MapImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapImage->WinTop = 0.05;
	MapImage->WinLeft = 0.05;
	MapImage->WinWidth = 0.675;
	MapImage->WinHeight = 0.75;
	//MapImage->OnKeyEvent=MapImage.InternalOnKeyEvent;
	UmoNumericEdit* SpotterGridXNumericEditBox = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	SpotterGridXNumericEditBox->CaptionWidth = 0.45;
	SpotterGridXNumericEditBox->Caption = "Target X:";
	//SpotterGridXNumericEditBox->OnCreateComponent=SpotterGridXNumericEditBox.InternalOnCreateComponent;
	SpotterGridXNumericEditBox->IniOption = "@Internal";
	SpotterGridXNumericEditBox->Hint = "Enter the target grid location.";
	SpotterGridXNumericEditBox->WinTop = 0.15;
	SpotterGridXNumericEditBox->WinLeft = 0.76;
	SpotterGridXNumericEditBox->WinWidth = 0.22;
	SpotterGridXNumericEditBox->WinHeight = 0.06;
	SpotterGridXNumericEditBox->TabOrder = 2;
	SpotterGridXNumericEditBox->bStandardized = false;
	//SpotterGridXNumericEditBox->OnChange=AAGameMenu_SpotterMap.InternalOnChange;
	UmoNumericEdit* SpotterGridYNumericEditBox = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	SpotterGridYNumericEditBox->CaptionWidth = 0.45;
	SpotterGridYNumericEditBox->Caption = "Target Y:";
	//SpotterGridYNumericEditBox->OnCreateComponent=SpotterGridYNumericEditBox.InternalOnCreateComponent;
	SpotterGridYNumericEditBox->IniOption = "@Internal";
	SpotterGridYNumericEditBox->Hint = "Enter the target grid location.";
	SpotterGridYNumericEditBox->WinTop = 0.23;
	SpotterGridYNumericEditBox->WinLeft = 0.76;
	SpotterGridYNumericEditBox->WinWidth = 0.22;
	SpotterGridYNumericEditBox->WinHeight = 0.06;
	SpotterGridYNumericEditBox->TabOrder = 2;
	SpotterGridYNumericEditBox->bStandardized = false;
	//SpotterGridYNumericEditBox->OnChange=AAGameMenu_SpotterMap.InternalOnChange;
	UmoComboBox* MissionTypeComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MissionTypeComboBox->bReadOnly = true;
	MissionTypeComboBox->CaptionWidth = 0.4;
	MissionTypeComboBox->Caption = "Mission:";
	//MissionTypeComboBox->OnCreateComponent=MissionTypeComboBox.InternalOnCreateComponent;
	MissionTypeComboBox->IniOption = "@Internal";
	MissionTypeComboBox->StyleName = "STY_AAComboListBox";
	MissionTypeComboBox->Hint = "Select the type of mission you would like to call in.";
	MissionTypeComboBox->WinTop = 0.31;
	MissionTypeComboBox->WinLeft = 0.76;
	MissionTypeComboBox->WinWidth = 0.22;
	MissionTypeComboBox->WinHeight = 0.06;
	MissionTypeComboBox->TabOrder = 8;
	MissionTypeComboBox->bStandardized = false;
	//MissionTypeComboBox->OnChange=AAGameMenu_SpotterMap.InternalOnChange;
	UmoComboBox* TargetTypeComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TargetTypeComboBox->bReadOnly = true;
	TargetTypeComboBox->CaptionWidth = 0.4;
	TargetTypeComboBox->Caption = "TGT-Type:";
	//TargetTypeComboBox->OnCreateComponent=TargetTypeComboBox.InternalOnCreateComponent;
	TargetTypeComboBox->IniOption = "@Internal";
	TargetTypeComboBox->StyleName = "STY_AAComboListBox";
	TargetTypeComboBox->Hint = "Select the type of target.";
	TargetTypeComboBox->WinTop = 0.38;
	TargetTypeComboBox->WinLeft = 0.76;
	TargetTypeComboBox->WinWidth = 0.22;
	TargetTypeComboBox->WinHeight = 0.06;
	TargetTypeComboBox->TabOrder = 8;
	TargetTypeComboBox->bStandardized = false;
	//TargetTypeComboBox->OnChange=AAGameMenu_SpotterMap.InternalOnChange;
	UGUIButton* GridFireMissionButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GridFireMissionButton->Caption = "Call For Fire";
	GridFireMissionButton->MenuState = EMenuState::MSAT_Disabled;
	GridFireMissionButton->StyleName = "SquareMenuButton";
	GridFireMissionButton->Hint = "Click here to make call for fire using entered grid reference.";
	GridFireMissionButton->WinTop = 0.46;
	GridFireMissionButton->WinLeft = 0.76;
	GridFireMissionButton->WinWidth = 0.15;
	GridFireMissionButton->WinHeight = 0.06;
	GridFireMissionButton->TabOrder = 14;
	//GridFireMissionButton->OnClick=AAGameMenu_SpotterMap.ButtonClick;
	//GridFireMissionButton->OnKeyEvent=GridFireMissionButton.InternalOnKeyEvent;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUILabel* TitleLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TitleLabel->Caption = "Reference Chart";
	TitleLabel->TextAlign = ETextAlign::TXTA_Center;
	TitleLabel->TextColor = FColor(52, 180, 217, 255);
	TitleLabel->TextFont = "AAFontMedium";
	TitleLabel->WinTop = 0.07;
	TitleLabel->WinLeft = 0.76;
	TitleLabel->WinWidth = 0.22;
	TitleLabel->WinHeight = 0.05;
	UGUILabel* DebugLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DebugLabel->TextColor = FColor(255, 255, 255, 255);
	DebugLabel->StyleName = "TextLabel";
	DebugLabel->WinTop = 0.8;
	DebugLabel->WinLeft = 0.75;
	DebugLabel->WinWidth = 0.9;
	DebugLabel->WinHeight = 0.05;
	i_Background = MyBackground;
	i_Map = MapImage;
	guilTitle = TitleLabel;
	guilDebug = DebugLabel;
	mneGridX = SpotterGridXNumericEditBox;
	mneGridY = SpotterGridYNumericEditBox;
	guibGridFireMission = GridFireMissionButton;
	mcbMissionType = MissionTypeComboBox;
	mcbTargetType = TargetTypeComboBox;
}

void UAAGameMenu_SpotterMap::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super.InitComponent(MyController, MyOwner);
	__OnRendered__Delegate = OnDrawMapGrid;
	InitializeMap();
	*/
}

bool UAAGameMenu_SpotterMap::NotifyLevelChange()
{
	InitializeMap();
	return true;
}

void UAAGameMenu_SpotterMap::InitializeMap()
{
	/*
	ScalingMapImage = new () classClass'TexScaler';
	ScalingMapImage.Material = PlayerOwner().Level.RadarMapImage;
	ScalingMapImage.UScale = 1;
	ScalingMapImage.VScale = 1;
	ScalingMapImage.UOffset = 0;
	ScalingMapImage.VOffset = 0;
	RotatingMapImage = new () classClass'TexRotator';
	RotatingMapImage.Material = ScalingMapImage;
	RotatingMapImage.TexRotationType = 0;
	RotatingMapImage.Rotation = rot(0, 16384, 0);
	RotatingMapImage.UOffset = (float(ScalingMapImage.Material.MaterialUSize()) / 2);
	RotatingMapImage.VOffset = (float(ScalingMapImage.Material.MaterialVSize()) / 2);
	RotatingMapImage.OscillationRate = rot(0, 0, 0);
	RotatingMapImage.OscillationAmplitude = rot(0, 0, 0);
	RotatingMapImage.OscillationPhase = rot(0, 0, 0);
	i_Map.Image = RotatingMapImage;
	mcbMissionType.MyComboBox.List.Insert(0, "Suppress", , "SUPPRESS");
	mcbMissionType.MyComboBox.List.Insert(1, "Smoke", , "SMOKE");
	mcbMissionType.MyComboBox.List.Insert(2, "Training", , "TRAINING");
	mcbMissionType.MyComboBox.Edit.bReadOnly = true;
	mcbTargetType.MyComboBox.List.Insert(0, "Infantry", , "Infantry");
	mcbTargetType.MyComboBox.List.Insert(1, "Vehicles", , "Vehicles");
	mcbTargetType.MyComboBox.Edit.bReadOnly = true;
	mneGridX.MyNumericEdit.MinValue = (0 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX);
	mneGridX.MyNumericEdit.MaxValue = (100 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX);
	mneGridX.SetComponentValue(string((mneGridX.MyNumericEdit.MinValue + 50)));
	mneGridY.MyNumericEdit.MinValue = (0 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY);
	mneGridY.MyNumericEdit.MaxValue = (100 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY);
	mneGridY.SetComponentValue(string((mneGridY.MyNumericEdit.MinValue + 50)));
	*/
}

FVector UAAGameMenu_SpotterMap::ConvertWorldToRotatedMapCoordinates(FVector vWorld)
{
	/*
	if ((vWorld.X >= 0) && (vWorld.Y <= 0))
	{
		(vWorld.Y *= -1);
		return vWorld;
	}
	if ((vWorld.X >= 0) && (vWorld.Y > 0))
	{
		(vWorld.X *= float(-1));
		return vWorld;
	}
	if ((vWorld.X <= 0) && (vWorld.Y > 0))
	{
		(vWorld.Y *= float(-1));
		return vWorld;
	}
	if ((vWorld.X <= 0) && (vWorld.Y <= 0))
	{
		(vWorld.X *= float(-1));
		return vWorld;
	}
	*/
	return vWorld;     //FAKE   /ELiZ
}

void UAAGameMenu_SpotterMap::OnDrawMapGrid(UCanvas* Canvas)
{
	/*
	local Color colorGridLine;
	local int32 i;
	local float fpNormalizedY;
	local float fpNormalizedX;
	local float fpMapScaleX;
	local float fpMapScaleY;
	local float fpMapStartX;
	local float fpMapStartY;
	local float fpMapHeight;
	local float fpMapWidth;
	local float fpMapCenterX;
	local float fpMapCenterY;
	local float fpCursorLocationX;
	local float fpCursorLocationY;
	fpMapStartX = (i_Map.WinLeft * float(Canvas.SizeX));
	fpMapStartY = ((i_Map.WinTop * float(Canvas.SizeY)) + (0.05 * float(Canvas.SizeY)));
	fpMapHeight = float((i_Map.iScreenBottom - i_Map.iScreenTop));
	fpMapWidth = float((i_Map.iScreenRight - i_Map.iScreenLeft));
	fpMapCenterX = (PlayerOwner().Level.RadarMapOffset.X - (PlayerOwner().Level.RadarMapSize / 2));
	fpMapCenterY = (PlayerOwner().Level.RadarMapOffset.Y - (PlayerOwner().Level.RadarMapSize / 2));
	fpMapScaleY = (fpMapHeight / 100);
	fpMapScaleX = (fpMapWidth / 100);
	Canvas.SetDrawColor(255, 255, 255, 192);
	Canvas.SetPos(fpMapStartX, fpMapStartY);
	Canvas.DrawHorizontal(fpMapStartY, fpMapWidth);
	Canvas.DrawHorizontal((fpMapStartY + fpMapHeight), fpMapWidth);
	Canvas.DrawVertical(fpMapStartX, fpMapHeight);
	Canvas.DrawVertical((fpMapStartX + fpMapWidth), fpMapHeight);
	colorGridLine = Class'Canvas'.MakeColor(255, 255, 255);
	i = 10;
	if (i <= 90)
	{
		if ((float(i) * fpMapScaleY) > float(i_Map.Image.MaterialVSize()))
		{
		}
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos(fpMapStartX, (fpMapStartY + (float(i) * fpMapScaleY)));
		Canvas.DrawHorizontal((fpMapStartY + (float(i) * fpMapScaleY)), fpMapWidth);
		Canvas.SetDrawColor(220, 220, 220);
		Canvas.SetPos((fpMapStartX - float(25)), ((fpMapStartY + (float(i) * fpMapScaleY)) - 5));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + (100 - i))));
		Canvas.SetPos(((fpMapStartX + fpMapWidth) + 4), ((fpMapStartY + (float(i) * fpMapScaleY)) - 5));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + (100 - i))));
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos((fpMapStartX + (float(i) * fpMapScaleX)), fpMapStartY);
		Canvas.DrawVertical((fpMapStartX + (float(i) * fpMapScaleX)), fpMapHeight);
		Canvas.SetDrawColor(220, 220, 220);
		Canvas.SetPos(((fpMapStartX + (float(i) * fpMapScaleX)) - 5), (fpMapStartY - float(15)));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i)));
		Canvas.SetPos(((fpMapStartX + (float(i) * fpMapScaleX)) - 5), ((fpMapStartY + fpMapHeight) + 2));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i)));
		(i += 10);
	}
	Canvas.SetDrawColor(128, 0, 0, 255);
	fpNormalizedX = (float(mneGridX.GetComponentValue()) + float(HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX));
	fpNormalizedY = ((100 - float(mneGridY.GetComponentValue())) + float(HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY));
	fpCursorLocationX = (fpMapStartX + (fpNormalizedX * fpMapScaleX));
	fpCursorLocationY = (fpMapStartY + (fpNormalizedY * fpMapScaleY));
	Canvas.SetPos(fpCursorLocationX, (fpCursorLocationY - (fpMapHeight * 0.05)));
	Canvas.DrawVertical(fpCursorLocationX, (fpMapHeight * 0.1));
	Canvas.SetPos((fpCursorLocationX - (fpMapWidth * 0.05)), fpCursorLocationY);
	Canvas.DrawHorizontal(fpCursorLocationY, (fpMapWidth * 0.1));
	*/
}

bool UAAGameMenu_SpotterMap::ButtonClick(UGUIComponent* Sender)
{
	/*
	local FString sCFFCommand;
	Switch(Sender)
	{
		case guibGridFireMission:
			sCFFCommand = "CallForFireGrid " $ mneGridX.GetComponentValue() $ " " $ mneGridY.GetComponentValue() $ " " $ mcbMissionType.GetExtra() $ " " $ mcbTargetType.GetExtra();
			HumanController(PlayerOwner()).ConsoleCommand(sCFFCommand);
			HumanController(PlayerOwner()).ClientCloseMenu(true);
			break;
		default:
	}
	*/
	return true;
}

void UAAGameMenu_SpotterMap::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch(Sender)
	{
		case mcbMissionType:
		case mcbTargetType:
		case mneGridX:
		case mneGridY:
			guibGridFireMission.EnableMe();
			break;
		default:
	}
	*/
}
