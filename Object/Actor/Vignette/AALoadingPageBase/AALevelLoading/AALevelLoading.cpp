// All the original content belonged to the US Army

#include "AA29/Object/Actor/Vignette/AALoadingPageBase/AALevelLoading/AALevelLoading.h"
#include "AA29/Object/DrawOpBase/DrawOpImage/DrawOpImage.h"
#include "AA29/Object/DrawOpBase/DrawOpText/DrawOpText.h"

AAALevelLoading::AAALevelLoading()
{
	UDrawOpImage* OpBackground = NewObject<UDrawOpImage>(UDrawOpImage::StaticClass());
	OpBackground->Height = 1;
	OpBackground->Width = 1;
	UDrawOpText* OpLoading = NewObject<UDrawOpText>(UDrawOpText::StaticClass());
	OpLoading->Text = "LOADING. . . ";
	OpLoading->FontName = "AGP_Interface.AAFontLarge";
	OpLoading->bWrapText = false;
	OpLoading->Top = 0.75;
	OpLoading->Lft = 0.2;
	OpLoading->Height = 0.05;
	OpLoading->Width = 0.49;
	OpLoading->DrawColor = FColor(52, 180, 217, 255);
	UDrawOpText* OpMapname = NewObject<UDrawOpText>(UDrawOpText::StaticClass());
	OpMapname->FontName = "AGP_Interface.AAFontLarge";
	OpMapname->bWrapText = false;
	OpMapname->Top = 0.8;
	OpMapname->Lft = 0.2;
	OpMapname->Height = 0.05;
	OpMapname->Width = 0.49;
	OpMapname->DrawColor = FColor(52, 180, 217, 255);
	UDrawOpText* OpHint = NewObject<UDrawOpText>(UDrawOpText::StaticClass());
	OpHint->FontName = "AGP_Interface.AAFontSmallHeader";
	OpHint->Top = 0.9;
	OpHint->Lft = 0.02;
	OpHint->Height = 0.2;
	OpHint->Width = 0.96;
	OpHint->DrawColor = FColor(156, 201, 168, 255);
	Operations = { OpBackground,OpLoading,OpMapname,OpHint };
}

void AAALevelLoading::Init()
{
	/*
	Super::Init();
	AddBackground();
	SetImage();
	SetText();
	*/
}

void AAALevelLoading::AddBackground()
{
	/*
	local Material Bg;
	Bg = MapScreenshot;
	if (Bg != None)
	{
		AddImage(Bg, 0, 0, 1, 1).DrawColor = Class'Canvas'.MakeColor(196, 196, 0);
	}
	*/
}

void AAALevelLoading::SetImage()
{
	/*
	int32 i = 0;
	int32 cnt = 0;
	FString str = "";
	local Material mat;
	DrawOpImage(Operations[0]).Image = mat;
	if (Backgrounds.Length == 0)
	{
		Warn("No background images configured for" @ string(Name));
		return;
		do
		{
		}
		i = Rand(Backgrounds.Length);
		str = Backgrounds[i];
		if (str == "")
		{
			Warn("Invalid value for " $ string(Name) $ ".Backgrounds[" $ string(i) $ "]");
		}
		else
		{
			mat = DLOTexture(str);
		}
	}
	until(((mat != None) || ((++cnt) >= 10)));
	if (mat == None)
	{
		Warn("Unable to find any valid images for vignette class" @ string(Name) $ "!");
	}
	DrawOpImage(Operations[0]).Image = mat;
	*/
}

FString AAALevelLoading::StripMap(FString S)
{
	/*
	int32 p = 0;
	p = Len(S);
	if (p > 0)
	{
		if (Mid(S, p, 1) == ".")
		{
			S = Left(S, p);
		}
		else
		{
	else
	{
		(p);
	}
		}
	}
	p = Len(S);
	if (p > 0)
	{
		if (((Mid(S, p, 1) == "\\") || (Mid(S, p, 1) == "/")) || (Mid(S, p, 1) == ":"))
		{
			return Right(S, ((Len(S) - p) - 1));
		}
		else
		{
			(p);
		}
	}
	*/
	return S;
}

void AAALevelLoading::SetText()
{
	/*
	local XInterface.DrawOpText HintOp;
	FString Hint = "";
	DrawOpText(Operations[2]).Text = StripMap(MapName);
	if (Level.IsSoftwareRendering())
	{
		return;
	}
	HintOp = DrawOpText(Operations[3]);
	if (HintOp == None)
	{
		return;
	}
	if (GameClass == None)
	{
		Warn("Invalid game class, so cannot draw loading hint!");
		return;
	}
	Hint = GameClass.GetLoadingHint(Level.GetLocalPlayerController(), MapName, HintOp.DrawColor);
	if (Hint == "")
	{
		Log("No loading hint configured for " @ string(GameClass.Name));
		return;
	}
	HintOp.Text = Hint;
	*/
}