// All the original content belonged to the US Army

#include "AA29/Object/Actor/Vignette/AALoadingPageBase/AAServerLoading/AAServerLoading.h"
#include "AA29/Object/DrawOpBase/DrawOpImage/DrawOpImage.h"
#include "AA29/Object/DrawOpBase/DrawOpText/DrawOpText.h"

AAAServerLoading::AAAServerLoading()
{
	UDrawOpImage* OpBackground = NewObject<UDrawOpImage>(UDrawOpImage::StaticClass());
	OpBackground->Height = 1;
	OpBackground->Width = 1;
	OpBackground->DrawColor = FColor(192, 192, 192, 255);
	UDrawOpText* OpLoading = NewObject<UDrawOpText>(UDrawOpText::StaticClass());
	OpLoading->Text = "LOADING. . . ";
	OpLoading->FontName = "AGP_Interface.AAFontSmallHeader";
	OpLoading->bWrapText = false;
	OpLoading->Top = 0.85;
	OpLoading->Lft = 0.02;
	OpLoading->Height = 0.2;
	OpLoading->Width = 0.96;
	OpLoading->DrawColor = FColor(156, 201, 168, 255);
	UDrawOpText* OpHint = NewObject<UDrawOpText>(UDrawOpText::StaticClass());
	OpHint->FontName = "AGP_Interface.AAFontSmallHeader";
	OpHint->Top = 0.9;
	OpHint->Lft = 0.02;
	OpHint->Height = 0.2;
	OpHint->Width = 0.96;
	OpHint->DrawColor = FColor(156, 201, 168, 255);
	Operations = { OpBackground,OpLoading,OpHint };
}

void AAAServerLoading::Init()
{
	SetImage();
	SetText();
}

void AAAServerLoading::DrawVignette(UCanvas* C, float Progress)
{
	/*
	int32 i = 0;
	C.Reset();
	for (i = 0; i < Operations.Length; i++)
	{
		Operations[i].Draw(C);
	}
	*/
}

void AAAServerLoading::SetImage()
{
	/*
	local Material mat;
	switch (Rand(4))
	{
	case 0:
		mat = DLOTexture("T_AAO_UI.GUI.T_UI_GUI_Loading_A");
		break;
	case 1:
		mat = DLOTexture("T_AAO_UI.GUI.T_UI_GUI_Loading_B");
		break;
	case 2:
		mat = DLOTexture("T_AAO_UI.GUI.T_UI_GUI_Loading_C");
		break;
	case 3:
		mat = DLOTexture("T_AAO_UI.GUI.T_UI_GUI_Loading_D");
		break;
	default:
		mat = DLOTexture("T_AAO_UI.GUI.T_UI_GUI_Loading_A");
		break;
	}
	Log("AAServerLoading - mat: " $ string(mat));
	DrawOpImage(Operations[0]).Image = mat;
	DrawOpImage(Operations[0]).ImageStyle = 2;
	DrawOpImage(Operations[0]).SetPos(0, 0);
	*/
}

FString AAAServerLoading::StripMap(FString S)
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
	Log("Level in AAServerLoading is: " $ string(Level));
	*/
	return S;
}

void AAAServerLoading::SetText()
{
	/*
	local XInterface.DrawOpText HintOp;
	FString Hint = "";
	FString sCleanedMapName = "";
	int32 iNumTours = 0;
	int32 iNumMissions = 0;
	int32 iTour = 0;
	int32 iMission = 0;
	bool fFoundMission = false;
	sCleanedMapName = StripMap(MapName);
	DrawOpText(Operations[1]).Text = "Loading Mission \"" $ sCleanedMapName $ "\", please wait...";
	iNumTours = GetPrivateProfileInt(GetBaseDir() $ "Tours.ini", "Tours", "NumTours");
	fFoundMission = false;
	iTour = 0;
	if ((iTour < iNumTours) && (!fFoundMission))
	{
		iNumMissions = Level.GetTourMissions(iTour);
		iMission = 0;
		if (iMission < iNumMissions)
		{
			if (Level.GetTourMissionMapFilename(iTour, iMission) ~= sCleanedMapName)
			{
				if (Level.GetTourIsTraining(iTour))
				{
					DrawOpText(Operations[1]).Text = "Loading Training Mission \"" $ Level.GetTourMissionTitle(iTour, iMission) $ "\", please wait...";
				}
				else
				{
					DrawOpText(Operations[1]).Text = "Loading Mission \"" $ Level.GetTourMissionTitle(iTour, iMission) $ "\", please wait...";
				}
				fFoundMission = true;
			}
			else
			{
				iMission++;
			}
		}
		iTour++;
	}
	if (Level.IsSoftwareRendering())
	{
		return;
	}
	HintOp = DrawOpText(Operations[2]);
	if (HintOp == nullptr)
	{
		return;
	}
	if (GameClass == nullptr)
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