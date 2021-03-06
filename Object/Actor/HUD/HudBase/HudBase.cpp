// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/HudBase/HudBase.h"
#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/ActionMessage/ActionMessage.h"
#include "Engine/Canvas.h"

AHudBase::AHudBase(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	Emphasized.SetNum(4);
	DamageTime.SetNum(4);
	DamageFlash.SetNum(4);
	LocalMessages.SetNum(8);
	InstructTextBorderX = 10;
	InstructTextBorderY = 10;
	InstructionFontName = "UT2003Fonts.jFontMono800x600";
	CroppingAmount = 0.25;
	LevelActionLoading = "LOADING...";
	LevelActionPaused = "PAUSED";
	LevelActionFontName = "UT2003Fonts.FontMedium";
	WonMatchPostFix = " won the match!";
	WaitingToSpawn = "Press [Fire] to join the match!";
	AtMenus = "Press [ESC] to close menu";
	YouveWonTheMatch = "You've won the match!";
	YouveLostTheMatch = "You've lost the match.";
	NowViewing = "Now viewing";
	ScoreText = "Score";
	InitialViewingString = "Press Fire to View a different Player";
	bUseCustomWeaponCrosshairs = true;
	ProgressFontName = "UT2003Fonts.FontMedium";
	FontArrayNames = {
		"UT2003Fonts.FontEurostile37",
		"UT2003Fonts.FontEurostile29",
		"UT2003Fonts.FontEurostile24",
		"UT2003Fonts.FontEurostile21",
		"UT2003Fonts.FontEurostile17",
		"UT2003Fonts.FontEurostile14",
		"UT2003Fonts.FontEurostile12",
		"UT2003Fonts.FontEurostile9",
		"UT2003Fonts.FontSmallText"
	};
	FontScreenWidthMedium = {
		2048,
		1600,
		1280,
		1024,
		800,
		640,
		512,
		400,
		320
	};
	FontScreenWidthSmall = {
		4096,
		3200,
		2560,
		2048,
		1600,
		1280,
		1024,
		800,
		640
	};
}

void AHudBase::UpdateHUD()
{
}

void AHudBase::DrawHudPassA(UCanvas* C)
{
}

void AHudBase::DrawHudPassB(UCanvas* C)
{
}

void AHudBase::DrawHudPassC(UCanvas* C)
{
}

void AHudBase::DrawHudPassD(UCanvas* C)
{
}

void AHudBase::PrecacheFonts(UCanvas* C)
{
	/*
	FontsPrecached++;
	C.Font = GetConsoleFont(C);
	C.SetPos(0, 0);
	C.DrawText("<>_Aa1");
	C.Font = GetFontSizeIndex(C, -2);
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, -4);
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, MessageFontOffset);
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, (1 + MessageFontOffset));
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, (2 + MessageFontOffset));
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, (3 + MessageFontOffset));
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	*/
}

void AHudBase::PostBeginPlay()
{
	//Super::PostBeginPlay();
	if (CustomHUDColorAllowed())
	{
		SetCustomHUDColor();
	}
}

bool AHudBase::CustomHUDColorAllowed()
{
	return false;
}

void AHudBase::SetCustomHUDColor()
{
}

void AHudBase::DisplayHit(FVector HitDir, int32 Damage, UaDamageType* DamageType)
{
	int32 i = 0;
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	TArray<uint8> Ignore = { 0,0,0,0 };
	FRotator LookDir = FRotator(0, 0, 0);
	float NewDamageTime = 0;
	float Forward = 0;
	float Left = 0;
	/*
	LookDir = PawnOwner.Rotation;
	LookDir.Pitch = 0;
	GetAxes(LookDir, X, Y, Z);
	HitDir.Z = 0;
	HitDir = Normal(HitDir);
	Forward = (HitDir Dot X);
	Left = (HitDir Dot Y);
	if (Forward > 0)
	{
		if (Forward > 0.7)
		{
			Emphasized[0] = 1;
		}
		Ignore[1] = 1;
	}
	else
	{
		if (Forward < -0.7)
		{
			Emphasized[1] = 1;
		}
		Ignore[0] = 1;
	}
	if (Left > 0)
	{
		if (Left > 0.7)
		{
			Emphasized[3] = 1;
		}
		Ignore[2] = 1;
	}
	else
	{
		if (Left < -0.7)
		{
			Emphasized[2] = 1;
		}
		Ignore[3] = 1;
	}
	NewDamageTime = (5 * float(Clamp(Damage, 20, 30)));
	for (i = 0; i < 4; i++)
	{
		if (Ignore[i] != 1)
		{
			DamageFlash[i].R = 255;
			DamageTime[i] = NewDamageTime;
		}
	}
	*/
}

void AHudBase::DrawDamageIndicators(UCanvas* C)
{
	/*
	if (DamageTime[0] > 0)
	{
		C.SetPos(0, 0);
		C.DrawColor = DamageFlash[0];
		C.DrawColor.A = uint8(DamageTime[0]);
	}
	else
	{
		Emphasized[0] = 0;
	}
	if (DamageTime[1] > 0)
	{
		C.DrawColor = DamageFlash[1];
		C.DrawColor.A = uint8(DamageTime[1]);
		if (Emphasized[1] == 1)
		{
			C.SetPos(0, (0.85 * C.ClipY));
		}
		else
		{
			C.SetPos(0, (0.9 * C.ClipY));
		}
	}
	else
	{
		Emphasized[1] = 0;
	}
	if (DamageTime[2] > 0)
	{
		C.SetPos(0, 0);
		C.DrawColor = DamageFlash[2];
		C.DrawColor.A = uint8(DamageTime[2]);
	}
	else
	{
		Emphasized[2] = 0;
	}
	if (DamageTime[3] > 0)
	{
		C.DrawColor = DamageFlash[3];
		C.DrawColor.A = uint8(DamageTime[3]);
		if (Emphasized[3] == 1)
		{
			C.SetPos((0.85 * C.ClipX), 0);
		}
		else
		{
			C.SetPos((0.95 * C.ClipX), 0);
		}
	}
	else
	{
		Emphasized[3] = 0;
	}
	*/
}

void AHudBase::Tick(float DeltaTime)
{
	int32 i = 0;
	/*
	for (i = 0; i < 4; i++)
	{
		if (DamageTime[i] > 0)
		{
			DamageTime[i] -= (float(120) * DeltaTime);
			if (DamageTime[i] < 1)
			{
				DamageTime[i] = 0;
			}
		}
	}
	*/
}

void AHudBase::DrawHeadShotSphere()
{
	FCoords CO;
	APawn* p = nullptr;
	FVector HeadLoc = FVector(0, 0, 0);
	/*
	ForEach DynamicActors(Class'Pawn', p)
	{
		if ((p != nullptr) && (p.HeadBone != "None"))
		{
			CO = p.GetBoneCoords(p.HeadBone);
			HeadLoc = (CO.Origin + ((p.HeadHeight * p.HeadScale) * CO.XAxis));
			p.DrawDebugSphere(HeadLoc, (p.HeadRadius * p.HeadScale), 10, 0, 255, 0);
		}
	}
	*/
}

void AHudBase::DrawHUD()
{
	UCanvas* C = Canvas;

	if (FontsPrecached < 2)
	{
		PrecacheFonts(C);
	}
	//Super::DrawHUD(C);
	UpdateHUD();
	if (bShowTargeting)
	{
		DrawTargeting(C);
	}
	PassStyle = ERenderStyle::STY_Alpha;
	DrawDamageIndicators(C);
	DrawHudPassA(C);
	PassStyle = ERenderStyle::STY_Additive;
	DrawHudPassB(C);
	PassStyle = ERenderStyle::STY_Alpha;
	DrawHudPassC(C);
	PassStyle = ERenderStyle::STY_None;
	DrawHudPassD(C);
	DisplayLocalMessages(C);
	DrawWeaponName(C);
	DrawVehicleName(C);
}

//native simulated Function DrawSpriteWidget(UCanvas* C, SpriteWidget& W);
void AHudBase::DrawSpriteWidget(UCanvas* C, FSpriteWidget& W)
{

}

//native simulated Function DrawNumericWidget(UCanvas* C, NumericWidget& W, DigitSet& D);
void AHudBase::DrawFNumericWidget(UCanvas* C, FNumericWidget& W, FDigitSet& D)
{

}

void AHudBase::ClearMessage(FHudLocalizedMessage& M)
{
	M.Message = nullptr;
	M.StringFont = nullptr;
}

void AHudBase::Message(AAA2_PlayerState* PRI, FString Msg, FName MsgType)
{
	ULocalMessage* LocalMessageClass = nullptr;
	//AddTextMessage(Msg, LocalMessageClass, PRI);
}

void AHudBase::LocalizedMessage(ULocalMessage*  Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString CriticalString)
{
	int32 i = 0;
	/*
	AAA2_PlayerState* HUDPRI;
	if (Message == nullptr)
	{
		return;
	}
	if (bIsCinematic && (!ClassIsChildOf(Message, AActionMessage::StaticClass())))
	{
		return;
	}
	if (CriticalString == "")
	{
		if ((PawnOwner != nullptr) && (PawnOwner.PlayerReplicationInfo != nullptr))
		{
			HUDPRI = PawnOwner.PlayerReplicationInfo;
		}
		else
		{
			HUDPRI = PlayerOwner.PlayerReplicationInfo;
		}
		if (HUDPRI == RelatedPRI_1)
		{
			CriticalString = Message.GetRelatedString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
		}
		else
		{
			CriticalString = Message.GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
		}
	}
	if (bMessageBeep && Message.Default.bBeep)
	{
		PlayerOwner.PlayBeepSound();
	}
	if (!Message.Default.bIsSpecial)
	{
		if (PlayerOwner.bDemoOwner)
		{
			for (i = 0; i < ConsoleMessageCount; i++)
			{
				if ((i >= 8) || (TextMessages[i].Text == ""))
				{
				}
			}
			if ((i > 0) && (TextMessages[(i - 1)].Text == CriticalString))
			{
				return;
			}
		}
		AddTextMessage(CriticalString, Message, RelatedPRI_1);
		return;
	}
	i = 8;
	if (Message.Default.bIsUnique)
	{
		for (i = 0; i < 8; i++)
		{
			if (LocalMessages[i].Message == nullptr)
			{
			}
			if (LocalMessages[i].Message == Message)
			{
			}
		}
	}
	else
	{
		if (Message.Default.bIsPartiallyUnique || PlayerOwner.bDemoOwner)
		{
			for (i = 0; i < 8; i++)
			{
				if (LocalMessages[i].Message == nullptr)
				{
				}
				if ((LocalMessages[i].Message == Message) && (LocalMessages[i].Switch == Switch))
				{
				}
			}
		}
	}
	if (i == 8)
	{
		for (i = 0; i < 8; i++)
		{
			if (LocalMessages[i].Message == nullptr)
			{
			}
		}
	}
	if (i == 8)
	{
		i = 0;
		if (i < (8 - 1))
		{
			LocalMessages[i] = LocalMessages[(i + 1)];
			i++;
		}
	}
	ClearMessage(LocalMessages[i]);
	LocalMessages[i].Message = Message;
	LocalMessages[i].Switch = Switch;
	LocalMessages[i].RelatedPRI = RelatedPRI_1;
	LocalMessages[i].RelatedPRI2 = RelatedPRI_2;
	LocalMessages[i].OptionalObject = OptionalObject;
	LocalMessages[i].EndOfLife = (Message.GetLifeTime(Switch) + GetWorld()->GetTimeSeconds());
	LocalMessages[i].StringMessage = CriticalString;
	LocalMessages[i].Lifetime = Message.GetLifeTime(Switch);
	*/
}

FColor AHudBase::GetTeamColor(uint8 TeamNum)
{
	return GetDefault<AHudBase>()->BlackColor;
}

void AHudBase::GetLocalStatsScreen()
{
}

void AHudBase::LayoutMessage(FHudLocalizedMessage& Message, UCanvas* C)
{
	/*
	int32 FontSize = 0;
	FontSize = Message.Message.GetFontSize(Message.Switch, Message.RelatedPRI, Message.RelatedPRI2, PlayerOwner.PlayerReplicationInfo);
	(FontSize += MessageFontOffset);
	Message.StringFont = GetFontSizeIndex(C, FontSize);
	Message.DrawColor = Message.Message.GetColor(Message.Switch, Message.RelatedPRI, Message.RelatedPRI2);
	Message.Message.GetPos(Message.Switch, Message.DrawPivot, Message.StackMode, Message.PosX, Message.PosY);
	C.Font = Message.StringFont;
	C.TextSize(Message.StringMessage, Message.dx, Message.dy);
	*/
}

void AHudBase::GetScreenCoords(float PosX, float PosY, float& ScreenX, float& ScreenY, FHudLocalizedMessage& Message, UCanvas* C)
{
	/*
	ScreenX = (((PosX * HudCanvasScale) * C.ClipX) + (((1 - HudCanvasScale) * 0.5) * C.ClipX));
	ScreenY = (((PosY * HudCanvasScale) * C.ClipY) + (((1 - HudCanvasScale) * 0.5) * C.ClipY));
	switch (Message.DrawPivot)
	{
	case 0:
		break;
	case 1:
		(ScreenX -= (Message.dx * 0.5));
		break;
	case 2:
		(ScreenX -= Message.dx);
		break;
	case 3:
		(ScreenX -= Message.dx);
		(ScreenY -= (Message.dy * 0.5));
		break;
	case 4:
		(ScreenX -= Message.dx);
		(ScreenY -= Message.dy);
		break;
	case 5:
		(ScreenX -= (Message.dx * 0.5));
		(ScreenY -= Message.dy);
		break;
	case 6:
		(ScreenY -= Message.dy);
		break;
	case 7:
		(ScreenY -= (Message.dy * 0.5));
		break;
	case 8:
		(ScreenX -= (Message.dx * 0.5));
		(ScreenY -= (Message.dy * 0.5));
		break;
	default:
	}
	*/
}

void AHudBase::DrawMessage(UCanvas* C, int32 i, float PosX, float PosY, float& dx, float& dy)
{
	float FadeValue = 0;
	float ScreenX = 0;
	float ScreenY = 0;
	/*
	if (!LocalMessages[i].Message.Default.bFadeMessage)
	{
		C.DrawColor = LocalMessages[i].DrawColor;
	}
	else
	{
		FadeValue = (LocalMessages[i].EndOfLife - GetWorld()->GetTimeSeconds());
		C.DrawColor = LocalMessages[i].DrawColor;
		C.DrawColor.A = uint8((float(LocalMessages[i].DrawColor.A) * (FadeValue / LocalMessages[i].Lifetime)));
	}
	C.Font = LocalMessages[i].StringFont;
	GetScreenCoords(PosX, PosY, ScreenX, ScreenY, LocalMessages[i], C);
	C.SetPos(ScreenX, ScreenY);
	dx = (LocalMessages[i].dx / C.ClipX);
	dy = (LocalMessages[i].dy / C.ClipY);
	if (LocalMessages[i].Message.Default.bComplexString)
	{
		LocalMessages[i].Message.RenderComplexMessage(C, LocalMessages[i].dx, LocalMessages[i].dy, LocalMessages[i].StringMessage, LocalMessages[i].Switch, LocalMessages[i].RelatedPRI, LocalMessages[i].RelatedPRI2, LocalMessages[i].OptionalObject);
	}
	else
	{
		C.DrawTextClipped(LocalMessages[i].StringMessage, false);
	}
	LocalMessages[i].Drawn = true;
	*/
}

void AHudBase::DisplayLocalMessages(UCanvas* C)
{
	float PosX = 0;
	float PosY = 0;
	float dy = 0;
	float dx = 0;
	int32 i = 0;
	int32 j = 0;
	float FadeValue = 0;
	FPlane OldCM;
	/*
	OldCM = C.ColorModulate;
	C.Reset();
	C.ColorModulate = OldCM;
	for (i = 0; i < 8; i++)
	{
		if (LocalMessages[i].Message == nullptr)
		{
		}
		LocalMessages[i].Drawn = false;
		if (LocalMessages[i].StringFont == nullptr)
		{
			LayoutMessage(LocalMessages[i], C);
		}
		if (LocalMessages[i].StringFont == nullptr)
		{
			Log("LayoutMessage(" + FString::FromInt(LocalMessages[i].Message) + ") failed!", "Error");
			j = i;
			if (j < (8 - 1))
			{
				LocalMessages[j] = LocalMessages[(j + 1)];
				j++;
			}
			ClearMessage(LocalMessages[j]);
			i--;
		}
		else
		{
			if (LocalMessages[i].Message.Default.bFadeMessage)
			{
				FadeValue = (LocalMessages[i].EndOfLife - GetWorld()->GetTimeSeconds());
				if (FadeValue <= 0)
				{
					j = i;
					if (j < (8 - 1))
					{
						LocalMessages[j] = LocalMessages[(j + 1)];
						j++;
					}
					ClearMessage(LocalMessages[j]);
					i--;
				}
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (LocalMessages[i].Message == nullptr)
		{
		}
		if (LocalMessages[i].Drawn)
		{
		}
		PosX = LocalMessages[i].PosX;
		PosY = LocalMessages[i].PosY;
		if (LocalMessages[i].StackMode == 0)
		{
			DrawMessage(C, i, PosX, PosY, dx, dy);
		}
		else
		{
			for (j = i; j < 8; j++)
			{
				if (LocalMessages[j].Drawn)
				{
				}
				if (LocalMessages[i].PosX != LocalMessages[j].PosX)
				{
				}
				if (LocalMessages[i].PosY != LocalMessages[j].PosY)
				{
				}
				if (LocalMessages[i].DrawPivot != LocalMessages[j].DrawPivot)
				{
				}
				if (LocalMessages[i].StackMode != LocalMessages[j].StackMode)
				{
				}
				DrawMessage(C, j, PosX, PosY, dx, dy);
				switch (LocalMessages[j].StackMode)
				{
				case 1:
					PosY -= dy;
					break;
				case 2:
					PosY += dy;
					break;
				default:
				}
			}
		}
	}
	*/
}

void AHudBase::CreateKeyMenus()
{
	/*
	if ((Cast<APlayerController>(GetOwner())->PlayerReplicationInfo != nullptr) && PlayerController(GetOwner())->PlayerReplicationInfo.bOnlySpectator)
	{
		return;
	}
	if (VoteMenuClass != nullptr)
	{
		VoteMenu = Spawn(VoteMenuClass, this);
	}
	*/
}

void AHudBase::Draw2DLocationDot(UCanvas* C, FVector loc, float OffsetX, float OffsetY, float ScaleX, float ScaleY)
{
	FRotator Dir = FRotator(0, 0, 0);
	float Angle = 0;
	float Scaling = 0;
	AActor* Start = nullptr;
	/*
	if (PawnOwner == nullptr)
	{
		Start = PlayerOwner;
	}
	else
	{
		Start = PawnOwner;
	}
	Dir = rotator((loc - Start.Location));
	Angle = ((float((int(float((Dir.Yaw - PlayerOwner.Rotation.Yaw))) & 65535)) * 6.2832) / float(65536));
	C.Style = 6;
	C.SetPos(((OffsetX * C.ClipX) + ((ScaleX * C.ClipX) * Sin(Angle))), ((OffsetY * C.ClipY) - ((ScaleY * C.ClipY) * Cos(Angle))));
	Scaling = (((24 * C.ClipX) * HudScale) / float(1600));
	C.DrawTile(LocationDot, Scaling, Scaling, 340, 432, 78, 78);
	*/
}

void AHudBase::SetTargeting(bool bShow, FVector TargetLocation, float Size)
{
	bShowTargeting = bShow;
	if (bShow)
	{
		TargetingLocation = TargetLocation;
		if (Size != 0)
		{
			TargetingSize = Size;
		}
	}
}

void AHudBase::DrawTargeting(UCanvas* C)
{
	int32 XPos = 0;
	int32 YPos = 0;
	FVector ScreenPos = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector Dir = FVector(0, 0, 0);
	float RatioX = 0;
	float RatioY = 0;
	float tileX = 0;
	float tileY = 0;
	float dist = 0;
	float SizeX = 0;
	float SizeY = 0;
	/*
	SizeX = (TargetingSize * 96);
	SizeY = (TargetingSize * 96);
	if (!bShowTargeting)
	{
		return;
	}
	ScreenPos = C.WorldToScreen(TargetingLocation);
	RatioX = (float(C.SizeX) / 640);
	RatioY = (float(C.SizeY) / 480);
	tileX = (SizeX * RatioX);
	tileY = (SizeY * RatioX);
	GetAxes(PlayerOwner.Rotation, X, Y, Z);
	Dir = (TargetingLocation - PawnOwner.Location);
	dist = VSize(Dir);
	Dir = (Dir / dist);
	if ((Dir Dot X) > 0.6)
	{
		XPos = int(ScreenPos.X);
		YPos = int(ScreenPos.Y);
		C.Style = 7;
		C.DrawColor.R = 255;
		C.DrawColor.G = 255;
		C.DrawColor.B = 255;
		C.DrawColor.A = 255;
		C.SetPos((float(XPos) - (tileX * 0.5)), (float(YPos) - (tileY * 0.5)));
		C.DrawTile(TargetMaterial, tileX, tileY, 0, 0, 256, 256);
	}
	*/
}

void AHudBase::SetCropping(bool Active)
{
	DoCropping = Active;
}

void AHudBase::DrawInstructionGfx(UCanvas* C)
{
	float CropHeight = 0;
	/*
	DrawCrossHair(C);
	DrawTargeting(C);
	if (DoCropping)
	{
		CropHeight = ((float(C.SizeY) * CroppingAmount) * 0.5);
		C.SetPos(0, 0);
		C.DrawTile(Texture'Engine.BlackTexture', float(C.SizeX), CropHeight, 0, 0, 64, 64);
		C.SetPos(0, (float(C.SizeY) - CropHeight));
		C.DrawTile(Texture'Engine.BlackTexture', float(C.SizeX), CropHeight, 0, 0, 64, 64);
	}
	*/
	DrawInstructionText(C);
	DrawInstructionKeyText(C);
}

void AHudBase::DrawInstructionText(UCanvas* C)
{
	/*
	if (InstructionText == "")
	{
		return;
	}
	C.Font = LoadInstructionFont();
	C.SetOrigin(InstructTextBorderX, InstructTextBorderY);
	C.SetClip((float(C.SizeX) - InstructTextBorderX), float(C.SizeY));
	C.SetPos(0, 0);
	C.DrawText(InstructionText);
	C.SetOrigin(0, 0);
	C.SetClip(float(C.SizeX), float(C.SizeY));
	*/
}

void AHudBase::DrawInstructionKeyText(UCanvas* C)
{
	float strX = 0;
	float strY = 0;
	/*
	if (InstructionKeyText == "")
	{
		return;
	}
	C.Font = LoadInstructionFont();
	C.SetOrigin(InstructTextBorderX, InstructTextBorderY);
	C.SetClip((float(C.SizeX) - InstructTextBorderX), float(C.SizeY));
	C.StrLen(InstructionKeyText, strX, strY);
	C.SetOrigin(InstructTextBorderX, ((float(C.SizeY) - strY) - InstructTextBorderY));
	C.SetClip((float(C.SizeX) - InstructTextBorderX), float(C.SizeY));
	C.SetPos(0, 0);
	C.DrawText(InstructionKeyText);
	C.SetOrigin(0, 0);
	C.SetClip(float(C.SizeX), float(C.SizeY));
	*/
}

void AHudBase::SetInstructionText(FString aText)
{
	InstructionText = aText;
}

void AHudBase::SetInstructionKeyText(FString aText)
{
	InstructionKeyText = aText;
}

UFont* AHudBase::LoadInstructionFont()
{
	if (InstructionFontFont == nullptr)
	{
		//InstructionFontFont = Font(DynamicLoadObject(InstructionFontName, Class'Font'));
		if (InstructionFontFont == nullptr)
		{
			//Log("Warning: " + FString::FromInt(this) + " Couldn't dynamically load font " + InstructionFontName);
		}
	}
	return InstructionFontFont;
}

void AHudBase::DrawWeaponName(UCanvas* C)
{
	FString CurWeaponName = "";
	float XL = 0;
	float YL = 0;
	float Fade = 0;
	if (bHideWeaponName)
	{
		return;
	}
	/*
	if (WeaponDrawTimer > GetWorld()->GetTimeSeconds())
	{
		C.Font = GetMediumFontFor(C);
		C.DrawColor = WeaponDrawColor;
		Fade = (WeaponDrawTimer - GetWorld()->GetTimeSeconds());
		if (Fade <= 1)
		{
			C.DrawColor.A = uint8((float(255) * Fade));
		}
		C.StrLen(LastWeaponName, XL, YL);
		C.SetPos(((C.ClipX / 2) - (XL / 2)), ((C.ClipY * 0.8) - YL));
		C.DrawText(LastWeaponName);
	}
	if ((PawnOwner == nullptr) || (PawnOwner.PendingWeapon == nullptr))
	{
		return;
	}
	CurWeaponName = PawnOwner.PendingWeapon.GetHumanReadableName();
	if (CurWeaponName != LastWeaponName)
	{
		WeaponDrawTimer = (GetWorld()->GetTimeSeconds() + 1.5);
	}
	*/
	LastWeaponName = CurWeaponName;
}

void AHudBase::DrawVehicleName(UCanvas* C)
{
}

void AHudBase::DrawCinematicHUD(UCanvas* C)
{
	//Super::DrawCinematicHUD(C);
	if (SubTitles != nullptr)
	{
		DrawIntroSubtitles(C);
	}
	else
	{
		if (bHideHUD)
		{
			DisplayLocalMessages(C);
		}
	}
}

void AHudBase::DrawIntroSubtitles(UCanvas* C)
{
	FString CurrentSubTitles = "";
	float XL = 0;
	float YL = 0;
	float YO = 0;
	TArray<FString> OutArray = {};
	int32 i = 0;
	/*
	CurrentSubTitles = SubTitles.GetSubTitles();
	if (CurrentSubTitles == "")
	{
		return;
	}
	C.DrawColor = WhiteColor;
	C.Style = 6;
	C.Font = GetFontSizeIndex(C, -1);
	C.WrapStringToArray(CurrentSubTitles, OutArray, (C.ClipX * 0.75));
	C.StrLen(OutArray[i], XL, YL);
	YO = FMin(((C.ClipY * 0.9) - ((YL * 0.5) * float(OutArray.Num()))), (C.ClipY - ((float(OutArray.Num()) + 1.1) * YL)));
	for (i = 0; i < OutArray.Num(); i++)
	{
		C.StrLen(OutArray[i], XL, YL);
		C.SetPos(((C.ClipX - XL) * 0.5), (YO + (YL * float(i))));
		C.DrawText(OutArray[i], false);
	}
	*/
}
