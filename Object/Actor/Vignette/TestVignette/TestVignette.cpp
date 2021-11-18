// All the original content belonged to the US Army


#include "AA29/Object/Actor/Vignette/TestVignette/TestVignette.h"

ATestVignette::ATestVignette()
{
	LogoPosX = 0.49;
	LogoPosY = 0.25;
	LogoScaleX = 0.5;
	LogoScaleY = 0.5;
	LoadingFontName = "UT2003Fonts.FontLarge";
	LoadingString = ". . . L O A D I N G . . .";
	LoadingPosX = 0.5;
	LoadingPosY = 0.65;
	MapPosY = 0.725;
	LoadingPivot = EDrawPivot::DP_MiddleMiddle;
	LoadingColor = FColor(255, 255, 255, 255);
}

void ATestVignette::Init()
{
	/*
	int32 i = 0;
	PreBeginPlay();
	i = Rand(Backgrounds.Length);
	Background = Texture(DynamicLoadObject(Backgrounds[i], Class'Texture'));
	if (Background == None)
	{
		Log(Backgrounds[i] $ " not found for Vignette", 'Error');
	}
	*/
}

void ATestVignette::ScreenText(UCanvas* C, FString Text, float PosX, float PosY, float ScaleX, float ScaleY)
{
	/*
	C.Style = 6;
	C.Font = LoadLoadingFont();
	C.DrawColor = LoadingColor;
	C.FontScaleX = ScaleX;
	C.FontScaleY = ScaleY;
	C.DrawScreenText(Text, PosX, PosY, LoadingPivot);
	*/
}

AFont* ATestVignette::LoadLoadingFont()
{
	/*
	if (LoadingFontFont == None)
	{
		LoadingFontFont = Font(DynamicLoadObject(LoadingFontName, Class'Font'));
		if (LoadingFontFont == None)
		{
			Log("Warning: " $ string(Self) $ " Couldn't dynamically load font " $ LoadingFontName);
		}
	}
	
	return LoadingFontFont;
	*/
	return nullptr;
}

void ATestVignette::DrawVignette(UCanvas* C, float Progress)
{
	/*
	float ResScaleX = 0;
	float ResScaleY = 0;
	float PosX = 0;
	float PosY = 0;
	float dx = 0;
	float dy = 0;
	C.Reset();
	ResScaleX = (float(C.SizeX) / 640);
	ResScaleY = (float(C.SizeY) / 480);
	C.Style = 6;
	C.DrawColor = C.MakeColor(255, 255, 255);
	C.SetPos(0, 0);
	C.DrawTile(Background, float(C.SizeX), float(C.SizeY), 0, 0, float(Background.USize), float(Background.VSize));
	dx = ((float(Logo.USize) * ResScaleX) * LogoScaleX);
	dy = ((float(Logo.VSize) * ResScaleY) * LogoScaleY);
	PosX = ((LogoPosX * float(C.SizeX)) - (dx * 0.5));
	PosY = ((LogoPosY * float(C.SizeY)) - (dy * 0.5));
	C.SetPos(PosX, PosY);
	C.Style = 6;
	C.DrawTile(Logo, dx, dy, 0, 0, float(Logo.USize), float(Logo.VSize));
	ScreenText(C, LoadingString, LoadingPosX, LoadingPosY, (ResScaleX * 0.5), (ResScaleY * 0.5));
	if (((MapName ~= "endgame.ut2") || (MapName ~= "ut2-intro.ut2")) || (Caps(Left(MapName, 3)) == "TUT"))
	{
		return;
	}
	ScreenText(C, MapName, LoadingPosX, MapPosY, ResScaleX, ResScaleY);
	*/
}