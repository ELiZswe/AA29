// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASoldierSubPanel/AAPersonnelJacket_Profile.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/Actor/SpinnyActor/SpinnySoldier/SpinnySoldier.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PersonnelJacket/PersonnelJacket.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"

UAAPersonnelJacket_Profile::UAAPersonnelJacket_Profile()
{
	UGUIButton* CreateAccountButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CreateAccountButton->Caption="Create Account";
	CreateAccountButton->StyleName="SquareMenuButton";
	CreateAccountButton->Hint="Click here to create an account.";
	CreateAccountButton->WinTop=0.15;
	CreateAccountButton->WinLeft=0.1;
	CreateAccountButton->WinWidth=0.2;
	CreateAccountButton->WinHeight=0.053476;
	CreateAccountButton->TabOrder=0;
	//CreateAccountButton->OnClick=AAPersonnelJacket_Profile.ButtonClick;
	//CreateAccountButton->OnKeyEvent=CreateAccountButton.InternalOnKeyEvent;
	UmoEditBox* UserNameBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	UserNameBox->CaptionWidth=0.3;
	UserNameBox->Caption="User Name";
	//UserNameBox->OnCreateComponent=UserNameBox.InternalOnCreateComponent;
	UserNameBox->IniOption="@Internal";
	UserNameBox->Hint="Enter your user name here.";
	UserNameBox->WinTop=0.31;
	UserNameBox->WinLeft=0.1;
	UserNameBox->WinWidth=0.55;
	UserNameBox->WinHeight=0.053476;
	UserNameBox->TabOrder=2;
	UserNameBox->bStandardized=false;
	//UserNameBox->OnLoadINI=AAPersonnelJacket_Profile.InternalOnLoadINI;
	UmoEditBox* PasswordBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordBox->bMaskText=true;
	PasswordBox->CaptionWidth=0.3;
	PasswordBox->Caption="Password";
	//PasswordBox->OnCreateComponent=PasswordBox.InternalOnCreateComponent;
	PasswordBox->IniOption="@Internal";
	PasswordBox->Hint="Enter your password here.";
	PasswordBox->WinTop=0.37;
	PasswordBox->WinLeft=0.1;
	PasswordBox->WinWidth=0.55;
	PasswordBox->WinHeight=0.053476;
	PasswordBox->TabOrder=3;
	PasswordBox->bStandardized=false;
	//PasswordBox->OnLoadINI=AAPersonnelJacket_Profile.InternalOnLoadINI;
	UGUIButton* LoadButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LoadButton->Caption="Load";
	LoadButton->StyleName="SquareMenuButton";
	LoadButton->Hint="Enter your user name and password, then click here to load your profile.";
	LoadButton->WinTop=0.37;
	LoadButton->WinLeft=0.68;
	LoadButton->WinWidth=0.1;
	LoadButton->WinHeight=0.053476;
	LoadButton->TabOrder=4;
	//LoadButton->OnClick=AAPersonnelJacket_Profile.LoadClick;
	//LoadButton->OnKeyEvent=LoadButton.InternalOnKeyEvent;
	UmoCheckBox* RememberUserCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	RememberUserCheckBox->CaptionWidth=0.9;
	RememberUserCheckBox->Caption="Save Profile";
	//RememberUserCheckBox->OnCreateComponent=RememberUserCheckBox.InternalOnCreateComponent;
	RememberUserCheckBox->IniOption="@Internal";
	RememberUserCheckBox->Hint="Check this box to remember the username and password for this Profile.";
	RememberUserCheckBox->WinTop=0.45;
	RememberUserCheckBox->WinLeft=0.1;
	RememberUserCheckBox->WinWidth=0.55;
	RememberUserCheckBox->WinHeight=0.053476;
	RememberUserCheckBox->TabOrder=5;
	RememberUserCheckBox->bStandardized=false;
	//RememberUserCheckBox->OnChange=AAPersonnelJacket_Profile.InternalOnChange;
	//RememberUserCheckBox->OnLoadINI=AAPersonnelJacket_Profile.InternalOnLoadINI;
	UmoCheckBox* AutoLoadCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AutoLoadCheckBox->CaptionWidth=0.9;
	AutoLoadCheckBox->Caption="Automatically Log in";
	//AutoLoadCheckBox->OnCreateComponent=AutoLoadCheckBox.InternalOnCreateComponent;
	AutoLoadCheckBox->IniOption="@Internal";
	AutoLoadCheckBox->Hint="Check this box to automatically log in and load this Profile.";
	AutoLoadCheckBox->WinTop=0.49;
	AutoLoadCheckBox->WinLeft=0.1;
	AutoLoadCheckBox->WinWidth=0.55;
	AutoLoadCheckBox->WinHeight=0.053476;
	AutoLoadCheckBox->TabOrder=6;
	AutoLoadCheckBox->bStandardized=false;
	//AutoLoadCheckBox->OnChange=AAPersonnelJacket_Profile.InternalOnChange;
	//AutoLoadCheckBox->OnLoadINI=AAPersonnelJacket_Profile.InternalOnLoadINI;
	UGUIImage* detailBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK1->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	detailBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK1->WinTop=0.07;
	detailBK1->WinLeft=0.01;
	detailBK1->WinWidth=0.98;
	detailBK1->WinHeight=0.15;
	detailBK1->RenderWeight=0.01;
	UGUIImage* detailBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK2->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	detailBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK2->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK2->WinTop=0.23;
	detailBK2->WinLeft=0.01;
	detailBK2->WinWidth=0.98;
	detailBK2->WinHeight=0.33;
	detailBK2->RenderWeight=0.01;
	UGUIImage* detailBK3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK3->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	detailBK3->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK3->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK3->WinTop=0.57;
	detailBK3->WinLeft=0.01;
	detailBK3->WinWidth=0.98;
	detailBK3->WinHeight=0.42;
	detailBK3->RenderWeight=0.01;
	UGUILabel* StatusLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusLabel->Caption="Ready";
	StatusLabel->TextAlign = ETextAlign::TXTA_Right;
	StatusLabel->TextColor=FColor(255, 255, 255, 255);
	StatusLabel->StyleName="TextLabel";
	StatusLabel->WinTop=0.58;
	StatusLabel->WinLeft=0.5;
	StatusLabel->WinWidth=0.4;
	StatusLabel->WinHeight=0.053476;
	UGUILabel* UserNameLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	UserNameLabel->TextColor=FColor(255, 255, 255, 255);
	UserNameLabel->StyleName="TextLabel";
	UserNameLabel->WinTop=0.64;
	UserNameLabel->WinLeft=0.1;
	UserNameLabel->WinWidth=0.4;
	UserNameLabel->WinHeight=0.053476;
	UGUILabel* HonorLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HonorLabel->TextColor=FColor(255, 255, 255, 255);
	HonorLabel->StyleName="TextLabel";
	HonorLabel->WinTop=0.68;
	HonorLabel->WinLeft=0.1;
	HonorLabel->WinWidth=0.4;
	HonorLabel->WinHeight=0.053476;
	UGUILabel* ExperienceLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ExperienceLabel->TextColor=FColor(255, 255, 255, 255);
	ExperienceLabel->StyleName="TextLabel";
	ExperienceLabel->WinTop=0.72;
	ExperienceLabel->WinLeft=0.1;
	ExperienceLabel->WinWidth=0.4;
	ExperienceLabel->WinHeight=0.053476;
	UGUILabel* ExperienceNeededLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ExperienceNeededLabel->TextColor=FColor(255, 255, 255, 255);
	ExperienceNeededLabel->StyleName="TextLabel";
	ExperienceNeededLabel->WinTop=0.76;
	ExperienceNeededLabel->WinLeft=0.1;
	ExperienceNeededLabel->WinWidth=0.8;
	ExperienceNeededLabel->WinHeight=0.053476;
	UGUILabel* NewsLabel1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewsLabel1->TextColor=FColor(255, 255, 255, 255);
	NewsLabel1->StyleName="TextLabel";
	NewsLabel1->WinTop=0.82;
	NewsLabel1->WinLeft=0.1;
	NewsLabel1->WinWidth=0.8;
	NewsLabel1->WinHeight=0.053476;
	UGUILabel* NewsLabel2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewsLabel2->TextColor=FColor(255, 255, 255, 255);
	NewsLabel2->StyleName="TextLabel";
	NewsLabel2->WinTop=0.86;
	NewsLabel2->WinLeft=0.1;
	NewsLabel2->WinWidth=0.8;
	NewsLabel2->WinHeight=0.053476;
	UGUILabel* NewsLabel3 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewsLabel3->TextColor=FColor(255, 255, 255, 255);
	NewsLabel3->StyleName="TextLabel";
	NewsLabel3->WinTop=0.9;
	NewsLabel3->WinLeft=0.1;
	NewsLabel3->WinWidth=0.8;
	NewsLabel3->WinHeight=0.053476;
	UGUILabel* NewsLabel4 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewsLabel4->TextColor=FColor(255, 255, 255, 255);
	NewsLabel4->StyleName="TextLabel";
	NewsLabel4->WinTop=0.94;
	NewsLabel4->WinLeft=0.1;
	NewsLabel4->WinWidth=0.8;
	NewsLabel4->WinHeight=0.053476;
	UGUILabel* NewPlayerLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewPlayerLabel->Caption="New Player Account Setup";
	NewPlayerLabel->TextColor=FColor(149, 163, 116, 255);
	NewPlayerLabel->StyleName="TextLabel";
	NewPlayerLabel->WinTop=0.08;
	NewPlayerLabel->WinLeft=0.05;
	NewPlayerLabel->WinWidth=0.94;
	NewPlayerLabel->WinHeight=0.053476;
	UGUILabel* PlayerLoginLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerLoginLabel->Caption="Player Login";
	PlayerLoginLabel->TextColor=FColor(149, 163, 116, 255);
	PlayerLoginLabel->StyleName="TextLabel";
	PlayerLoginLabel->WinTop=0.24;
	PlayerLoginLabel->WinLeft=0.05;
	PlayerLoginLabel->WinWidth=0.4;
	PlayerLoginLabel->WinHeight=0.053476;
	UGUILabel* PlayerAccountStatusLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerAccountStatusLabel->Caption="Profile Summary";
	PlayerAccountStatusLabel->TextColor=FColor(149, 163, 116, 255);
	PlayerAccountStatusLabel->StyleName="TextLabel";
	PlayerAccountStatusLabel->WinTop=0.58;
	PlayerAccountStatusLabel->WinLeft=0.05;
	PlayerAccountStatusLabel->WinWidth=0.4;
	PlayerAccountStatusLabel->WinHeight=0.053476;

	i_BG1 = detailBK1;
	i_BG2 = detailBK2;
	i_BG3 = detailBK3;
	b_CreateAccount = CreateAccountButton;
	b_Load = LoadButton;
	ed_Username = UserNameBox;
	ed_Password = PasswordBox;
	ch_RememberUser = RememberUserCheckBox;
	ch_AutoLoad = AutoLoadCheckBox;
	l_Status = StatusLabel;
	l_UserName = UserNameLabel;
	l_Honor = HonorLabel;
	l_Experience = ExperienceLabel;
	l_ExperienceNeeded = ExperienceNeededLabel;
	l_News1 = NewsLabel1;
	l_News2 = NewsLabel2;
	l_News3 = NewsLabel3;
	l_News4 = NewsLabel4;
	l_PlayerAccountStatus = PlayerAccountStatusLabel;
	l_PlayerLogin = PlayerLoginLabel;
	l_NewPlayer = NewPlayerLabel;
	SpinnyCharacterOffset = FVector(70, 0, 0);
	DeleteProfile = "You are about to delete the profile for '%profile%'||Are you sure you want to delete this profile?";
	ConnectionText = "Ready";
	nfov = 65;
	PanelCaption = "Profile";
	//OnRendered = AAPersonnelJacket_Profile.InternalDraw;

}

void UAAPersonnelJacket_Profile::VoiceTypeChanged(FString NewVoiceType)
{
}

void UAAPersonnelJacket_Profile::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	if (((Cast<AHumanController>(PlayerOwner()) != nullptr) && (Cast<AHumanController>(PlayerOwner())->myHUD != nullptr)) && (Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD) != nullptr))
	{
		Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).__OnSetLoginStatus__Delegate = InternalSetLoginStatus;
	}
	*/
}

void UAAPersonnelJacket_Profile::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case ch_RememberUser:
		bSaveProfile = (!AHumanController::StaticClass().Default.bDontRememberUsernameAndPassword);
		ch_RememberUser.Checked(bSaveProfile);
		break;
	case ch_AutoLoad:
		bAutoLoad = AHumanController::StaticClass().Default.bAutoLoad;
		ch_AutoLoad.Checked(bAutoLoad);
		if (bAutoLoad && (!HumanController(PlayerOwner()).HasAutoLoggedInRunOnce()))
		{
			Cast<AHumanController>(PlayerOwner())->SetAutoLoggedInRunOnce();
			LoadClick(ch_AutoLoad);
		}
		break;
	case ed_Username:
		ed_Username.SetText(AHumanController::StaticClass().Default.UserName);
		break;
	case ed_Password:
		ed_Password.SetText(AHumanController::StaticClass().Default.UserPassword);
		break;
	default:
	}
	*/
}

void UAAPersonnelJacket_Profile::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ch_RememberUser:
		bSaveProfile = ch_RememberUser.IsChecked();
		SaveSettings();
		break;
	case ch_AutoLoad:
		bAutoLoad = ch_AutoLoad.IsChecked();
		SaveSettings();
		break;
	case ed_Username:
		break;
	case ed_Password:
		break;
	default:
	}
	*/
}

void UAAPersonnelJacket_Profile::UpdateProfileList()
{
}

bool UAAPersonnelJacket_Profile::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_CreateAccount:
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", "http://login.americasarmy.com", "http://www.americasarmy.com/redir.php?r=100");
		return true;
	default:
		return true;
	}
	*/

	return false;    //FAKE   /ELiZ
}

bool UAAPersonnelJacket_Profile::LoadClick(UGUIComponent* Sender)
{
	/*
	AHumanController* HC = nullptr;
	HC = Cast<AHumanController>(PlayerOwner());
	if (HC == nullptr)
	{
		return false;
	}
	Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).__OnSetLoginStatus__Delegate = InternalSetLoginStatus;
	ClearProfile();
	ClearNews();
	if ((ed_Username.GetText() == "") || (ed_Username.GetText() == "UserName"))
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Invalid User Name", "You must enter your user name in the \"User Name\" field.");
		return false;
	}
	if ((_iLoginStatus == 0) || (_iLoginStatus == -1))
	{
		SaveSettings();
		HC.UserName = ed_Username.GetText();
		HC.UserPassword = ed_Password.GetText();
		if ((HC.Level.Game != nullptr) && HC.Level.Game.bBinaryAuthProtocol)
		{
			_iLoginStatus = 1;
		}
		else
		{
			if (!HC.LoadUserProfileAndNews())
			{
				l_Status.Caption = "Cannot load profile now.";
			}
		}
	}
	DisableComponent(b_Load);
	*/
	return true;
}

bool UAAPersonnelJacket_Profile::DeleteClick(UGUIComponent* Sender)
{
	ClearAll();
	return true;
}

void UAAPersonnelJacket_Profile::InternalSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	AHumanController* HC = nullptr;
	HC = Cast<AHumanController>(PlayerOwner());
	/*
	if (HC == nullptr)
	{
		l_Status.Caption = "";
		EnableComponent(b_Load);
		_iLoginStatus = 0;
		return;
	}
	_iLoginStatus = iStatus;
	l_Status.Caption = sStatus;
	if ((iStatus == 0) && (Len(sNavMsg) > 0))
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Problem Loading Profile", sNavMsg);
	}
	if (_iLoginStatus == 2)
	{
		if (Cast<UAAGUIController>(Controller) != nullptr)
		{
			AAGUIController(Controller).bLoggedIn = true;
		}
		_iLoginStatus = 0;
		l_UserName.Caption = "Name: " + HC.UserName;
		if (HC.PlayerReplicationInfo != nullptr)
		{
			l_Honor.Caption = "Honor: " + FString::FromInt(HC.PlayerReplicationInfo.GetHonor());
			l_Experience.Caption = "Experience: " + FString::FromInt(HC.PlayerReplicationInfo.GetExperience());
			l_ExperienceNeeded.Caption = "Needed: " + FString::FromInt(APersonnelJacket::StaticClass().CalculateExperienceNeeded(HC.PlayerReplicationInfo.GetExperience(), HC.PlayerReplicationInfo.GetHonor()));
		}
		l_News1.Caption = HC.sNewsLine1;
		l_News2.Caption = HC.sNewsLine2;
		l_News3.Caption = HC.sNewsLine3;
		l_News4.Caption = HC.sNewsLine4;
		EnableComponent(b_Load);
	}
	else
	{
		if (_iLoginStatus != 1)
		{
			EnableComponent(b_Load);
		}
	}
	*/
}

void UAAPersonnelJacket_Profile::ClearAll()
{
	l_UserName->Caption = "";
	l_Honor->Caption = "";
	l_Experience->Caption = "";
	l_ExperienceNeeded->Caption = "";
	l_News1->Caption = "";
	l_News2->Caption = "";
	l_News3->Caption = "";
	l_News4->Caption = "";
}

void UAAPersonnelJacket_Profile::ClearProfile()
{
	l_UserName->Caption = "";
	l_Honor->Caption = "";
	l_Experience->Caption = "";
	l_ExperienceNeeded->Caption = "";
}

void UAAPersonnelJacket_Profile::ClearNews()
{
	l_News1->Caption = "";
	l_News2->Caption = "";
	l_News3->Caption = "";
	l_News4->Caption = "";
}

void UAAPersonnelJacket_Profile::Refresh()
{
}

void UAAPersonnelJacket_Profile::SaveSettings()
{
	/*
	bool bSave = false;
	bSaveProfile = ch_RememberUser.IsChecked();
	if (AHumanController::StaticClass().Default.bDontRememberUsernameAndPassword != (!bSaveProfile))
	{
		AHumanController::StaticClass().Default.bDontRememberUsernameAndPassword = (!bSaveProfile);
		bSave = true;
	}
	if (AHumanController::StaticClass().Default.bAutoLoad != bAutoLoad)
	{
		AHumanController::StaticClass().Default.bAutoLoad = bAutoLoad;
		bSave = true;
	}
	if (bSaveProfile)
	{
		if (AHumanController::StaticClass().Default.UserName != ed_Username.GetText())
		{
			AHumanController::StaticClass().Default.UserName = ed_Username.GetText();
			bSave = true;
		}
		if (AHumanController::StaticClass().Default.UserPassword != ed_Password.GetText())
		{
			AHumanController::StaticClass().Default.UserPassword = ed_Password.GetText();
			bSave = true;
		}
	}
	else
	{
		AHumanController::StaticClass().Default.UserName = "";
		AHumanController::StaticClass().Default.UserPassword = "";
		bSave = true;
	}
	if (bSave)
	{
		AHumanController::StaticClass().StaticSaveConfig();
	}
	*/
}

void UAAPersonnelJacket_Profile::UpdateSpinnyCharacter()
{
	USkeletalMesh* PlayerMesh = nullptr;
	/*
	PlayerMesh = Mesh(DynamicLoadObject("A_AA2_CharactersUS.Instructor_3P", Class'Mesh'));
	if (PlayerMesh == nullptr)
	{
		Log("Could not load mesh: " + "A_AA2_CharactersUS.Instructor_3P");
		return;
	}
	SpinnyCharacter.LinkMesh(PlayerMesh);
	SpinnyCharacter.LoopAnim('acf_scratchass', (1 / SpinnyCharacter.Level.TimeDilation));
	*/
}

void UAAPersonnelJacket_Profile::InternalDraw(UCanvas* Canvas)
{
	FVector CamPos = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FRotator CamRot = FRotator(0, 0, 0);
	float oOrgX = 0;
	float oOrgY = 0;
	float oClipX = 0;
	float oClipY = 0;
	if (bRenderCharacter)
	{
		/*
		oOrgX = Canvas.OrgX;
		oOrgY = Canvas.OrgY;
		oClipX = Canvas.ClipX;
		oClipY = Canvas.ClipY;
		Canvas.GetCameraLocation(CamPos, CamRot);
		GetAxes(CamRot, X, Y, Z);
		SpinnyCharacter.SetLocation((((CamPos + (SpinnyCharacterOffset.X * X)) + (SpinnyCharacterOffset.Y * Y)) + (SpinnyCharacterOffset.Z * Z)));
		Canvas.DrawActorClipped(SpinnyCharacter, false, i_BG2.ClientBounds[0], i_BG2.ClientBounds[1], (i_BG2.ClientBounds[2] - i_BG2.ClientBounds[0]), (i_BG2.ClientBounds[3] - i_BG2.ClientBounds[1]), true, 90);
		Canvas.OrgX = oOrgX;
		Canvas.OrgY = oOrgY;
		Canvas.ClipX = oClipX;
		Canvas.ClipY = oClipY;
		*/
	}
}

void UAAPersonnelJacket_Profile::ShowSpinnyCharacter()
{
	if (bRenderCharacter)
	{
		UpdateSpinnyCharacter();
	}
	else
	{
		//SpinnyCharacter->LinkMesh(nullptr);
	}
}

bool UAAPersonnelJacket_Profile::Toggle3DView(UGUIComponent* Sender)
{
	bRenderCharacter = (!bRenderCharacter);
	ShowSpinnyCharacter();
	return true;
}

bool UAAPersonnelJacket_Profile::NextAnim(UGUIComponent* Sender)
{
	if (bRenderCharacter)
	{
		SpinnyCharacter->PlayNextAnim();
	}
	return true;
}

bool UAAPersonnelJacket_Profile::RaceCapturedMouseMove(float deltaX, float deltaY)
{
	/*
	FRotator R = FRotator(0, 0, 0);
	R = SpinnyCharacter.Rotation;
	(R.Yaw -= int((float(256) * deltaX)));
	SpinnyCharacter.SetRotation(R);
	*/
	return true;
}

void UAAPersonnelJacket_Profile::IntializeCharacter()
{
	if (SpinnyCharacter == nullptr)
	{
		//SpinnyCharacter = PlayerOwner().Spawn(ASpinnySoldier::StaticClass());
	}
	if (SpinnyCharacter != nullptr)
	{
		//SpinnyCharacter.SetDrawType(DT_Mesh);
		//SpinnyCharacter.SetDrawScale(0.9);
		//SpinnyCharacter.spinRate = 0;
	}
}

void UAAPersonnelJacket_Profile::ShowPanel(bool bShow)
{
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (bInit)
		{
			bInit = false;
		}
	}
}

void UAAPersonnelJacket_Profile::Opened(UGUIComponent* Sender)
{
	FRotator R = FRotator(0, 0, 0);
	Super::Opened(Sender);
	if (SpinnyCharacter != nullptr)
	{
		R.Yaw = 32768;
		R.Pitch = -1024;
		//SpinnyCharacter.SetRotation((R + PlayerOwner().Rotation));
		//SpinnyCharacter.bHidden = false;
	}
}

void UAAPersonnelJacket_Profile::Closed(UGUIComponent* Sender, bool bCancelled)
{
	Super::Closed(Sender, bCancelled);
	if (SpinnyCharacter != nullptr)
	{
		//SpinnyCharacter->bHidden = true;
	}
}

void UAAPersonnelJacket_Profile::Free()
{
	Super::Free();
	if (SpinnyCharacter != nullptr)
	{
		SpinnyCharacter->Destroy();
	}
	SpinnyCharacter = nullptr;
}

void UAAPersonnelJacket_Profile::logspinnycharacter()
{
	//Log("SpinnyCharacterOffset X:" + FString::FromInt(SpinnyCharacterOffset.X) @ "Y:" + FString::FromInt(SpinnyCharacterOffset.Y) @ "Z:" + FString::FromInt(SpinnyCharacterOffset.Z) @ "Roll:" + FString::FromInt(SpinnyCharacter.Rotation.Roll) @ "Pitch:" + FString::FromInt(SpinnyCharacter.Rotation.Pitch) @ "Yaw:" + FString::FromInt(SpinnyCharacter.Rotation.Yaw) @ "FOV:" + FString::FromInt(nfov));
}
