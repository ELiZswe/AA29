// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AARealHeroBrief/AARealHeroBrief.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAARealHeroBrief::UAARealHeroBrief()
{
	UmoComboBox* RealHeroComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	RealHeroComboBox->bReadOnly=true;
	RealHeroComboBox->CaptionWidth=0;
	//RealHeroComboBox->OnCreateComponent=RealHeroComboBox.InternalOnCreateComponent;
	RealHeroComboBox->Hint="Select the Real Hero you wish to view.";
	RealHeroComboBox->WinTop=0.0685;
	RealHeroComboBox->WinLeft=0.14;
	RealHeroComboBox->WinWidth=0.3;
	RealHeroComboBox->WinHeight=0.036;
	RealHeroComboBox->RenderWeight=0.8;
	RealHeroComboBox->TabOrder=1;
	//RealHeroComboBox->OnChange=AARealHeroBrief.InternalOnChange;
	UGUIButton* StatsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	StatsButton->Caption="Bio";
	StatsButton->StyleName="SquareMenuButton";
	StatsButton->Hint="View this Real Hero's stats.";
	StatsButton->WinTop=0.06625;
	StatsButton->WinLeft=0.46;
	StatsButton->WinWidth=0.12;
	StatsButton->WinHeight=0.036;
	StatsButton->RenderWeight=1;
	StatsButton->bBoundToParent=true;
	StatsButton->bScaleToParent=true;
	//StatsButton->OnClick=AARealHeroBrief.InternalOnClick;
	//StatsButton->OnKeyEvent=StatsButton.InternalOnKeyEvent;
	UGUIButton* ACUButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ACUButton->Caption="ACU";
	ACUButton->StyleName="SquareMenuButton";
	ACUButton->Hint="See this Real Hero in their Army Combat Uniform.";
	ACUButton->WinTop=0.06625;
	ACUButton->WinLeft=0.6;
	ACUButton->WinWidth=0.12;
	ACUButton->WinHeight=0.036;
	ACUButton->RenderWeight=1;
	ACUButton->bBoundToParent=true;
	ACUButton->bScaleToParent=true;
	//ACUButton->OnClick=AARealHeroBrief.InternalOnClick;
	//ACUButton->OnKeyEvent=ACUButton.InternalOnKeyEvent;
	UGUIButton* ClassAButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ClassAButton->Caption="Class A";
	ClassAButton->StyleName="SquareMenuButton";
	ClassAButton->Hint="See this Real Hero in their Class A Uniform.";
	ClassAButton->WinTop=0.06625;
	ClassAButton->WinLeft=0.74;
	ClassAButton->WinWidth=0.12;
	ClassAButton->WinHeight=0.036;
	ClassAButton->RenderWeight=1;
	ClassAButton->bBoundToParent=true;
	ClassAButton->bScaleToParent=true;
	//ClassAButton->OnClick=AARealHeroBrief.InternalOnClick;
	//ClassAButton->OnKeyEvent=ClassAButton.InternalOnKeyEvent;

	co_RealHero = RealHeroComboBox;
	b_SubPanelButtons = {StatsButton,ACUButton,ClassAButton};
	RealHeroStatsClasses = { "AGP_Interface.AARealHeroStats_TommyRieman","AGP_Interface.AARealHeroStats_JasonAmerine","AGP_Interface.AARealHeroStats_GeraldWolford","AGP_Interface.AARealHeroStats_MatthewZedwick" };

}

void UAARealHeroBrief::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < b_SubPanelButtons.Length; i++)
	{
		b_SubPanelButtons[i].FocusInstead = Self;
		b_SubPanelButtons[i].bNeverFocus = true;
	}
	InitSubPanels();
	RepopulateComboBoxes();
	SetRealHeroStatsClassByIndex(0);
	ShowSubPanel(0);
	*/
}

void UAARealHeroBrief::InitSubPanels()
{
	/*
	rhbsp_SubPanels[0] = new () class'AGP_Interface.AARealHeroBrief_Stats';
	rhbsp_SubPanels[0].InitComponent(Controller, Self);
	rhbsp_SubPanels[0].RenderWeight = 0.4;
	rhbsp_SubPanels[0].WinLeft = 0;
	rhbsp_SubPanels[0].WinTop = 0;
	rhbsp_SubPanels[0].WinWidth = 1;
	rhbsp_SubPanels[0].WinHeight = 1;
	rhbsp_SubPanels[0].bBoundToParent = true;
	rhbsp_SubPanels[0].bScaleToParent = true;
	rhbsp_SubPanels[0].bVisible = true;
	rhbsp_SubPanels[1] = new () class'AGP_Interface.AARealHeroBrief_Badges';
	rhbsp_SubPanels[1].InitComponent(Controller, Self);
	rhbsp_SubPanels[1].RenderWeight = 0.4;
	rhbsp_SubPanels[1].WinLeft = 0;
	rhbsp_SubPanels[1].WinTop = 0;
	rhbsp_SubPanels[1].WinWidth = 1;
	rhbsp_SubPanels[1].WinHeight = 1;
	rhbsp_SubPanels[1].bBoundToParent = true;
	rhbsp_SubPanels[1].bScaleToParent = true;
	rhbsp_SubPanels[1].bVisible = true;
	*/
}

void UAARealHeroBrief::RepopulateComboBoxes()
{
	/*
	int32 i = 0;
	local class<AARealHeroStats>  RealHeroStatsClass;
	co_RealHero.ResetComponent();
	for (i = 0; i < Default.RealHeroStatsClasses.Length; i++)
	{
		RealHeroStatsClass = class<AARealHeroStats>(DynamicLoadObject(Default.RealHeroStatsClasses[i], Class'Class'));
		co_RealHero.addItem(RealHeroStatsClass.Default.HeroNameAndRank, RealHeroStatsClass);
	}
	*/
}

void UAARealHeroBrief::ShowSubPanel(int32 WhichPanel)
{
	/*
	if (WhichPanel < rhbsp_SubPanels.Length)
	{
		ActiveSubPanel = rhbsp_SubPanels[WhichPanel];
	}
	*/
}

bool UAARealHeroBrief::InternalOnClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	for (i = 0; i < b_SubPanelButtons.Length; i++)
	{
		if (Sender == b_SubPanelButtons[i])
		{
			if ((i == 1) || (i == 2))
			{
				if (AARealHeroBrief_Badges(rhbsp_SubPanels[1]) != None)
				{
					AARealHeroBrief_Badges(rhbsp_SubPanels[1]).SetUniform((i - 1));
				}
				ShowSubPanel(1);
			}
			else
			{
				ShowSubPanel(i);
			}
			return true;
		}
	}
	*/
	return false;
}

void UAARealHeroBrief::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case co_RealHero:
		SetRealHeroStatsClass(class<AARealHeroStats>(co_RealHero.GetObject()));
		break;
	default:
	}
	*/
}

void UAARealHeroBrief::SetRealHeroStatsClassByIndex(int32 NewRealHeroStatsClassIndex)
{
	//SetRealHeroStatsClassByName(RealHeroStatsClasses[NewRealHeroStatsClassIndex]);
}

void UAARealHeroBrief::SetRealHeroStatsClassByName(FString NewRealHeroStatsClassName)
{
	//SetRealHeroStatsClass(class<AARealHeroStats>(DynamicLoadObject(NewRealHeroStatsClassName, Class'Class')));
}

void UAARealHeroBrief::SetRealHeroStatsClass(UAARealHeroStats* NewRealHeroStatsClass)
{
	/*
	int32 i = 0;
	if (NewRealHeroStatsClass != None)
	{
		MyRealHeroStatsClass = NewRealHeroStatsClass;
		for (i = 0; i < rhbsp_SubPanels.Length; i++)
		{
			rhbsp_SubPanels[i].SetRealHeroStatsClass(NewRealHeroStatsClass);
		}
	}
	*/
}