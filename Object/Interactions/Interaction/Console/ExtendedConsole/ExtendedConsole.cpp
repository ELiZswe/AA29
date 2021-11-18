// All the original content belonged to the US Army


#include "AA29/Object/Interactions/Interaction/Console/ExtendedConsole/ExtendedConsole.h"

UExtendedConsole::UExtendedConsole()
{
	MaxScrollbackSize = 128;
	ConsoleSoundVol = 0.3;
	AddedCurrentHead = "Added Server:";
	AddedCurrentTail = "To Favorites!";
	ServerFullMsg = "Server is now full";
	SMOriginX = 0.01;
	SMOriginY = 0.3;
	SMMargin = 0.015;
	SMStateName = { "Speech Menu","Voice Chat","Acknowledge","Friendly Fire","Order","Other","Taunt","Taunt Anim","Player Select" };
	SMChannelOptions = { "Join","Leave","Talk" };
	SMAllString = "[ALL]";
	SMMoreString = "[MORE]";
	LetterKeys = { EInputKey::IK_Q,EInputKey::IK_W,EInputKey::IK_E,EInputKey::IK_R,EInputKey::IK_A,EInputKey::IK_S,EInputKey::IK_D,EInputKey::IK_F,EInputKey::IK_Z,EInputKey::IK_X };
	NumberKeys = { EInputKey::IK_0,EInputKey::IK_1,EInputKey::IK_2,EInputKey::IK_3,EInputKey::IK_4,EInputKey::IK_5,EInputKey::IK_6,EInputKey::IK_7,EInputKey::IK_8,EInputKey::IK_9 };
	bSpeechMenuUseMouseWheel = true;
	ChatMenuClass = "GUI2K4.UT2K4InGameChat";
	StatsPromptMenuClass = "GUI2K4.UT2K4StatsPrompt";
	NeedPasswordMenuClass = "AGP_Interface.AAGetPassword";
	ServerInfoMenu = "GUI2K4.UT2K4ServerInfo";
}
/*
State ConsoleVisible
{
	Function bool KeyType(EInputKey Key, FString Unicode)
	{
		local PlayerController PC;
		if (bIgnoreKeys || bConsoleHotKey)
		{
			return true;
		}
		if (ViewportOwner != None)
		{
			PC = ViewportOwner.Actor;
		}
		if (bCtrl && (PC != None))
		{
			if (Key == 3)
			{
				PC.CopyToClipboard(TypedStr);
				return true;
			}
			else
			{
				if (Key == 22)
				{
					(TypedStr $ = PC.PasteFromClipboard());
					(TypedStrPos += Len(PC.PasteFromClipboard()));
					return true;
				}
				else
				{
					if (Key == 24)
					{
						PC.CopyToClipboard(TypedStr);
						TypedStr = "";
						TypedStrPos = 0;
						return true;
					}
				}
			}
		}
		if (Key >= 32)
		{
			if (Unicode != "")
			{
				TypedStr = Left(TypedStr,TypedStrPos) $ Unicode $ Right(TypedStr,(Len(TypedStr) - TypedStrPos));
			}
			else
			{
				TypedStr = Left(TypedStr,TypedStrPos) $ Chr(Key) $ Right(TypedStr,(Len(TypedStr) - TypedStrPos));
			}
			TypedStrPos++;
			return true;
		}
		return true;
	}
	Function bool KeyEvent(EInputKey Key, EInputAction Action, float Delta)
	{
		FString Temp = "";
		int32 i = 0;
		if (Action == 3)
		{
			if (Key == ConsoleHotKey)
			{
				if (bConsoleHotKey)
				{
					ConsoleClose();
				}
				return true;
			}
			switch (Key)
			{
				case 17:
				bCtrl = false;
				break;
				case 18:
				bAlt = false;
				break;
				case 16:
				bShift = false;
				break;
				case 27:
				if (TypedStr != "")
				{
					TypedStr = "";
					TypedStrPos = 0;
					HistoryCur = HistoryTop;
				}
				else
				{
					ConsoleClose();
				}
				return true;
				default:
				return true;
			}
		}
		else
		{
			if (Action == 1)
			{
				bIgnoreKeys = false;
				if (Key == ConsoleHotKey)
				{
					bConsoleHotKey = true;
					return true;
				}
				switch (Key)
				{
					case 17:
					bCtrl = true;
					break;
					case 18:
					bAlt = true;
					break;
					case 16:
					bShift = true;
					break;
					case 27:
					return true;
					case 13:
					if (TypedStr != "")
					{
						History[HistoryTop] = TypedStr;
						HistoryTop = int((float((HistoryTop + 1)) % float(16)));
						if ((HistoryBot == -1) || (HistoryBot == HistoryTop))
						{
							HistoryBot = int((float((HistoryBot + 1)) % float(16)));
						}
						HistoryCur = HistoryTop;
						Temp = TypedStr;
						TypedStr = "";
						TypedStrPos = 0;
						if (!ConsoleCommand(Temp))
						{
							Message(Localize("Errors","Exec","Core"),6);
						}
						Message("",6);
					}
					return true;
					case 38:
					if (HistoryBot >= 0)
					{
						if (HistoryCur == HistoryBot)
						{
							HistoryCur = HistoryTop;
						}
						else
						{
							(HistoryCur);
							if (HistoryCur < 0)
							{
								HistoryCur = (16 - 1);
							}
						}
						TypedStr = History[HistoryCur];
						TypedStrPos = Len(TypedStr);
					}
					return true;
					case 40:
					if (HistoryBot >= 0)
					{
						if (HistoryCur == HistoryTop)
						{
							HistoryCur = HistoryBot;
						}
						else
						{
							HistoryCur = int((float((HistoryCur + 1)) % float(16)));
						}
						TypedStr = History[HistoryCur];
						TypedStrPos = Len(TypedStr);
					}
					return true;
					case 8:
					if (TypedStrPos > 0)
					{
						TypedStr = Left(TypedStr,(TypedStrPos - 1)) $ Right(TypedStr,(Len(TypedStr) - TypedStrPos));
						(TypedStrPos);
					}
					return true;
					case 46:
					if (TypedStrPos < Len(TypedStr))
					{
						TypedStr = Left(TypedStr,TypedStrPos) $ Right(TypedStr,((Len(TypedStr) - TypedStrPos) - 1));
					}
					return true;
					case 37:
					i = (TypedStrPos - 1);
					if (bCtrl)
					{
						if ((i > 0) && (Mid(string(TypedStrPos),i,1) != " "))
						{
							(i);
						}
					}
					TypedStrPos = Max(0,i);
					return true;
					case 39:
					i = (TypedStrPos + 1);
					if (bCtrl)
					{
						if ((i <= Len(TypedStr)) && (Mid(TypedStr,i,1) != " "))
						{
							i++;
						}
					}
					TypedStrPos = Min(Len(TypedStr),i);
					return true;
					case 36:
					TypedStrPos = 0;
					return true;
					case 35:
					TypedStrPos = Len(TypedStr);
					return true;
					case 33:
					case 236:
					if (SBPos < (Scrollback.Length - 1))
					{
						if (bCtrl)
						{
							(SBPos += 5);
						}
						else
						{
							SBPos++;
						}
						if (SBPos >= Scrollback.Length)
						{
							SBPos = (Scrollback.Length - 1);
						}
					}
					return true;
					case 34:
					case 237:
					if (SBPos > 0)
					{
						if (bCtrl)
						{
							(SBPos -= 5);
						}
						else
						{
							(SBPos);
						}
						if (SBPos < 0)
						{
							SBPos = 0;
						}
					}
					default:
				}
			}
		}
		return true;
	}
	Function BeginState()
	{
		SBPos = 0;
		bVisible = true;
		bIgnoreKeys = true;
		bConsoleHotKey = false;
		HistoryCur = HistoryTop;
		bCtrl = false;
	}
	Function EndState()
	{
		bVisible = false;
		bCtrl = false;
		bConsoleHotKey = false;
	}
	Function PostRender(Canvas Canvas)
	{
		float fw = 0;
		float fh = 0;
		float yclip = 0;
		float Y = 0;
		int32 idx = 0;
		Canvas.Font = class'XInterface.HudBase'.GetConsoleFont(Canvas);
		yclip = (Canvas.ClipY * 0.5);
		Canvas.StrLen("X",fw,fh);
		Canvas.SetPos(0,0);
		Canvas.SetDrawColor(255,255,255,200);
		Canvas.Style = ERenderStyle.STY_Modulated;
		Canvas.DrawTileStretched(Texture'InterfaceContent.Menu.ConsoleBack',Canvas.ClipX,yclip);
		Canvas.Style = ERenderStyle.STY_Normal;
		Canvas.SetPos(0,(yclip - 1));
		Canvas.SetDrawColor(255,255,255,255);
		Canvas.DrawTile(Texture'InterfaceContent.Menu.BorderBoxA',Canvas.ClipX,2,0,0,64,2);
		Canvas.SetDrawColor(255,255,255,255);
		Canvas.SetPos(0,((yclip - 5) - fh));
		Canvas.DrawTextClipped("(>" @ Left(TypedStr,TypedStrPos) $ Chr(4) $ Eval((TypedStrPos < Len(TypedStr)),Mid(TypedStr,TypedStrPos),"_"),true);
		idx = (SBHead - SBPos);
		Y = (((yclip - Y) - 5) - (fh * 2));
		if (Scrollback.Length == 0)
		{
			return;
		}
		Canvas.SetDrawColor(255,255,255,255);
		if ((Y > fh) && (idx >= 0))
		{
			Canvas.SetPos(0,Y);
			Canvas.DrawText(Scrollback[idx],false);
			(idx);
			(Y -= fh);
		}
	}
}

State SpeechMenuVisible
{
	exec Function SpeechMenuToggle()
	{
		GotoState('None');
	}
	Function bool KeyType(EInputKey Key, FString Unicode)
	{
		if (bIgnoreKeys)
		{
			return true;
		}
		return false;
	}
	Function EnterState(ESpeechMenuState NewState, bool bNoSound)
	{
		SMState = NewState;
		HighlightRow = 0;
		if (!bNoSound)
		{
			PlayConsoleSound(SMAcceptSound);
		}
	}
	Function LeaveState()
	{
		PlayConsoleSound(SMDenySound);
		switch (SMState)
		{
			case 0:
			CloseSpeechMenu();
			break;
			case 8:
			EnterState(4,true);
			break;
			case 9:
			EnterState(1,true);
			break;
			default:
			EnterState(0,true);
		}
	}
	Function HandleInput(int32 keyIn)
	{
	}
	Function FString NumberToString(int32 Num)
	{
		local EInputKey Key;
		FString S = "";
		if ((Num < 0) || (Num > 9))
		{
			return "";
		}
		if (bSpeechMenuUseLetters)
		{
			Key = LetterKeys[Num];
		}
		else
		{
			Key = NumberKeys[Num];
		}
		S = ViewportOwner.Actor.ConsoleCommand("LOCALIZEDKEYNAME" @ string(Key));
		return S;
	}
	Function DrawNumbers(Canvas Canvas, int32 NumNums, bool IncZero, bool sizing, float& XMax, float& YMax)
	{
		int32 i = 0;
		float XPos = 0;
		float YPos = 0;
		float XL = 0;
		float YL = 0;
		XPos = (Canvas.ClipX * (SMOriginX + SMMargin));
		YPos = (Canvas.ClipY * (SMOriginY + SMMargin));
		Canvas.SetDrawColor(128,255,128,255);
		for (i = 0; i < NumNums; i++)
		{
			Canvas.SetPos(XPos,YPos);
			if (!sizing)
			{
				Canvas.DrawText(NumberToString((i + 1)) $ "-",false);
			}
			else
			{
				Canvas.TextSize(NumberToString((i + 1)) $ "-",XL,YL);
				XMax = float(Max(int(XMax),int((XPos + XL))));
				YMax = float(Max(int(YMax),int((YPos + YL))));
			}
			YPos += SMLineSpace;
		}
		if (IncZero)
		{
			Canvas.SetPos(XPos,YPos);
			if (!sizing)
			{
				Canvas.DrawText(NumberToString(0) $ "-",false);
			}
			XPos += SMTab;
			Canvas.SetPos(XPos,YPos);
			if (!sizing)
			{
				Canvas.DrawText(SMMoreString,false);
			}
			else
			{
				Canvas.TextSize(SMMoreString,XL,YL);
				XMax = float(Max(int(XMax),int((XPos + XL))));
				YMax = float(Max(int(YMax),int((YPos + YL))));
			}
		}
	}
	Function DrawCurrentArray(Canvas Canvas, bool sizing, float& XMax, float& YMax)
	{
		int32 i = 0;
		int32 stopAt = 0;
		float XPos = 0;
		float YPos = 0;
		float XL = 0;
		float YL = 0;
		XPos = ((Canvas.ClipX * (SMOriginX + SMMargin)) + SMTab);
		YPos = (Canvas.ClipY * (SMOriginY + SMMargin));
		stopAt = Min((SMOffset + 9),SMArraySize);
		for (i = SMOffset; i < stopAt; i++)
		{
			Canvas.SetPos(XPos,YPos);
			if (!sizing)
			{
				if (SMState == 9)
				{
					if (IsActiveChannel((SMOffset + i)))
					{
						Canvas.SetDrawColor(0,255,0,255);
					}
					else
					{
						if ((SMIndex == 2) && (!IsMember((SMOffset + i))))
						{
							Canvas.SetDrawColor(160,160,160,255);
						}
						else
						{
							Canvas.SetDrawColor(255,255,255,255);
						}
					}
				}
				else
				{
					Canvas.SetDrawColor(255,255,255,255);
				}
				Canvas.DrawText(SMNameArray[i],false);
			}
			else
			{
				Canvas.TextSize(SMNameArray[i],XL,YL);
				XMax = float(Max(int(XMax),int((XPos + XL))));
				YMax = float(Max(int(YMax),int((YPos + YL))));
			}
			YPos += SMLineSpace;
		}
	}
	Function bool IsActiveChannel(int32 i)
	{
		if (SMState != 9)
		{
			return false;
		}
		if ((ViewportOwner.Actor == None) || (ViewportOwner.Actor.ActiveRoom == None))
		{
			return false;
		}
		if ((i < 0) || (i > SMArraySize))
		{
			return false;
		}
		if (SMIndexArray[i] != ViewportOwner.Actor.ActiveRoom.ChannelIndex)
		{
			return false;
		}
		return true;
	}
	Function bool IsMember(int32 i)
	{
		if (SMState != 9)
		{
			return false;
		}
		if (((ViewportOwner.Actor == None) || (ViewportOwner.Actor.VoiceReplicationInfo == None)) || (ViewportOwner.Actor.PlayerReplicationInfo == None))
		{
			return false;
		}
		return ViewportOwner.Actor.VoiceReplicationInfo.IsMember(ViewportOwner.Actor.PlayerReplicationInfo,SMIndexArray[i]);
	}
	Function int32 KeyToNumber(EInputKey InKey)
	{
		int32 i = 0;
		for (i = 0; i < 10; i++)
		{
			if (bSpeechMenuUseLetters)
			{
				if (InKey == LetterKeys[i])
				{
					return i;
				}
			}
			else
			{
				if (InKey == NumberKeys[i])
				{
					return i;
				}
			}
		}
		return -1;
	}
	Function bool KeyEvent(EInputKey Key, EInputAction Action, float Delta)
	{
		int32 Input = 0;
		int32 NumNums = 0;
		NumNums = Min((SMArraySize - SMOffset),10);
		if (Action == 1)
		{
			bIgnoreKeys = false;
			if (Key == 17)
			{
				bCtrl = true;
			}
			else
			{
				if (Key == 18)
				{
					bAlt = true;
				}
				else
				{
					if (Key == 16)
					{
						bShift = true;
					}
				}
			}
		}
		if (Action == 3)
		{
			if (bAlt)
			{
				if (Key == 37)
				{
					HandleInput(-1);
					return true;
				}
				else
				{
					if (Key == 39)
					{
						Input = (HighlightRow + 1);
						if (Input == 10)
						{
							Input = 0;
						}
						HighlightRow = 0;
						HandleInput(Input);
						return true;
					}
				}
			}
		}
		if (Action != 1)
		{
			return false;
		}
		if (Key == 27)
		{
			HandleInput(-1);
			return true;
		}
		Input = KeyToNumber(Key);
		if (Input != -1)
		{
			HandleInput(Input);
			return true;
		}
		if (!bSpeechMenuUseMouseWheel)
		{
			return false;
		}
		if (Key == 236)
		{
			if ((HighlightRow == 0) && (SMOffset > 0))
			{
				HandleInput(-2);
				HighlightRow = 9;
			}
			else
			{
				HighlightRow = Max((HighlightRow - 1),0);
			}
			return true;
		}
		else
		{
			if (Key == 237)
			{
				if (HighlightRow == 9)
				{
					HandleInput(0);
					HighlightRow = 0;
				}
				else
				{
					HighlightRow = Min((HighlightRow + 1),(NumNums - 1));
				}
				return true;
			}
			else
			{
				if (Key == 4)
				{
					Input = (HighlightRow + 1);
					if (Input == 10)
					{
						Input = 0;
					}
					HighlightRow = 0;
					HandleInput(Input);
					return true;
				}
			}
		}
		return false;
	}
	Function Font MyGetSmallFontFor(Canvas Canvas)
	{
		int32 i = 0;
		for (i = 1; i < 8; i++)
		{
			if (float(class'XInterface.HudBase'.Default.FontScreenWidthSmall[i]) <= Canvas.ClipX)
			{
				return class'XInterface.HudBase'.LoadFontStatic((i - 1));
			}
		}
		return class'XInterface.HudBase'.LoadFontStatic(7);
	}
	Function PostRender(Canvas Canvas)
	{
		float XL = 0;
		float YL = 0;
		int32 SelLeft = 0;
		int32 i = 0;
		float XMax = 0;
		float YMax = 0;
		Canvas.Font = class'XInterface.UT2MidGameFont'.GetMidGameFont(int(Canvas.ClipX));
		XMax = 0;
		YMax = 0;
		for (i = 0; i < 10; i++)
		{
			Canvas.TextSize(NumberToString(i) $ "- ",XL,YL);
			XMax = float(Max(int(XMax),int(XL)));
			YMax = float(Max(int(YMax),int(YL)));
		}
		SMLineSpace = (YMax * 1.1);
		SMTab = XMax;
		SelLeft = (SMArraySize - SMOffset);
		XMax = 0;
		YMax = 0;
		DrawNumbers(Canvas,Min(SelLeft,9),(SelLeft > 9),true,XMax,YMax);
		DrawCurrentArray(Canvas,true,XMax,YMax);
		Canvas.TextSize(SMStateName[SMState],XL,YL);
		XMax = float(Max(int(XMax),int(((Canvas.ClipX * (SMOriginX + SMMargin)) + XL))));
		YMax = float(Max(int(YMax),int(((float(int((Canvas.ClipY * SMOriginY))) - (1.2 * SMLineSpace)) + YL))));
		XMax -= (Canvas.ClipX * SMOriginX);
		YMax -= (Canvas.ClipY * SMOriginY);
		Canvas.SetDrawColor(255,255,255,255);
		Canvas.SetPos((Canvas.ClipX * SMOriginX),(Canvas.ClipY * SMOriginY));
		Canvas.DrawTileStretched(Texture'InterfaceContent.Menu.BorderBoxD',(XMax + (SMMargin * Canvas.ClipX)),(YMax + (SMMargin * Canvas.ClipY)));
		if (bSpeechMenuUseMouseWheel)
		{
			Canvas.SetDrawColor(255,255,255,128);
			Canvas.SetPos((Canvas.ClipX * SMOriginX),((Canvas.ClipY * (SMOriginY + SMMargin)) + ((float(HighlightRow) - 0.1) * SMLineSpace)));
			Canvas.DrawTileStretched(Texture'InterfaceContent.Menu.BorderBoxD',(XMax + (SMMargin * Canvas.ClipX)),(1.1 * SMLineSpace));
		}
		DrawNumbers(Canvas,Min(SelLeft,9),(SelLeft > 9),false,XMax,YMax);
		DrawCurrentArray(Canvas,false,XMax,YMax);
		Canvas.SetDrawColor(255,255,255,255);
		Canvas.SetPos((Canvas.ClipX * SMOriginX),((Canvas.ClipY * SMOriginY) - (1.5 * SMLineSpace)));
		Canvas.DrawTileStretched(Texture'InterfaceContent.Menu.BorderBoxD',(XMax + (SMMargin * Canvas.ClipX)),(1.5 * SMLineSpace));
		Canvas.SetDrawColor(255,255,128,255);
		Canvas.SetPos((Canvas.ClipX * (SMOriginX + SMMargin)),((Canvas.ClipY * SMOriginY) - (1.2 * SMLineSpace)));
		Canvas.DrawText(SMStateName[SMState]);
		if (SMState == 9)
		{
			DrawMembers(Canvas,XMax,YMax);
		}
	}
	Function DrawMembers(Canvas Canvas, float XMax, float YMax)
	{
		local TArray<int32> Members;
		int32 i = 0;
		float XPos = 0;
		float YPos = 0;
		float XL = 0;
		float YL = 0;
		local GameReplicationInfo GRI;
		FString CurrentPlayer = "";
		GRI = ViewportOwner.Actor.GameReplicationInfo;
		if (GRI == None)
		{
			return;
		}
		if ((HighlightRow >= 0) && (HighlightRow < SMArraySize))
		{
			Members = ViewportOwner.Actor.VoiceReplicationInfo.GetChannelMembersAt(SMIndexArray[(SMOffset + HighlightRow)]);
			Canvas.SetDrawColor(255,255,175,220);
			XPos = (XMax + ((SMMargin * Canvas.ClipX) * 2.25));
			YPos = ((Canvas.ClipY * (SMOriginY + SMMargin)) + ((float(HighlightRow) + 0.1) * SMLineSpace));
			for (i = 0; i < Members.Length; i++)
			{
				CurrentPlayer = GRI.FindPlayerByID(Members[i]).PlayerName;
				Canvas.SetPos(XPos,YPos);
				Canvas.TextSize(CurrentPlayer,XL,YL);
				XMax = float(Max(int(XMax),int((XPos + XL))));
				YMax = float(Max(int(YMax),int((YPos + YL))));
				YPos += SMLineSpace;
				Canvas.DrawText(CurrentPlayer);
			}
		}
	}
	Function BeginState()
	{
		bVisible = true;
		bIgnoreKeys = true;
		bCtrl = false;
		HighlightRow = 0;
		EnterState(0,true);
		SMCallsign = "";
		PlayConsoleSound(SMOpenSound);
	}
	Function CloseSpeechMenu()
	{
		if (!bSpeechMenuLocked)
		{
			GotoState('None');
		}
	}
	Function EndState()
	{
		bVisible = false;
		bCtrl = false;
	}
	Event NotifyLevelChange()
	{
		Global.FailCode();
		GotoState('None');
	}
}
*/


void UExtendedConsole::OnChat(FString Msg, int32 TeamIndex)
{
}

void UExtendedConsole::OnStatsClosed(bool bCancelled)
{
	/*
	if (bCancelled)
	{
		return;
	}
	OnStatsConfigured();
	*/
}

void UExtendedConsole::OnStatsConfigured()
{
	//ViewportOwner.GUIController.CloseAll(false);
	//ViewportOwner.Actor.ClientTravel(LastURL, 0, false);
}

void UExtendedConsole::ConnectFailure(FString FailCode, FString URL)
{
	/*
	FString Error = "";
	FString Server = "";
	int32 i = 0;
	int32 Index = 0;
	LastURL = URL;
	Server = Left(URL, InStr(URL, "/"));
	i = InStr(FailCode, " ");
	if (i > 0)
	{
		Error = Right(FailCode, ((Len(FailCode) - i) - 1));
		FailCode = Left(FailCode, i);
	}
	Log("Connect Failure: " @ FailCode $ "[" $ Error $ "] (" $ URL $ ")", 'Debug');
	if (FailCode == "NEEDPW")
	{
		for (Index = 0; Index < SavedPasswords.Length; Index++)
		{
			if (SavedPasswords[Index].Server == Server)
			{
				ViewportOwner.Actor.ClearProgressMessages();
				ViewportOwner.Actor.ClientTravel(URL $ "?password=" $ SavedPasswords[Index].Password, 0, false);
				return;
			}
		}
		LastConnectedServer = Server;
		if (ViewportOwner.GUIController.OpenMenu(NeedPasswordMenuClass, URL, FailCode))
		{
			return;
		}
	}
	else
	{
		if (FailCode == "WRONGPW")
		{
			ViewportOwner.Actor.ClearProgressMessages();
			for (Index = 0; Index < SavedPasswords.Length; Index++)
			{
				if (SavedPasswords[Index].Server == Server)
				{
					SavedPasswords.remove(Index, 1);
					SaveConfig();
				}
			}
			LastConnectedServer = Server;
			if (ViewportOwner.GUIController.OpenMenu(NeedPasswordMenuClass, URL, FailCode))
			{
				return;
			}
		}
		else
		{
			if (FailCode == "NEEDSTATS")
			{
				ViewportOwner.Actor.ClearProgressMessages();
				if (ViewportOwner.GUIController.OpenMenu(StatsPromptMenuClass, "", FailCode))
				{
					GUIController(ViewportOwner.GUIController).ActivePage.__OnReOpen__Delegate = OnStatsConfigured;
					return;
				}
			}
			else
			{
				if (FailCode == "LOCALBAN")
				{
					ViewportOwner.Actor.ClearProgressMessages();
					ViewportOwner.GUIController.OpenMenu(Class'GameEngine'.Default.DisconnectMenuClass, Localize("Errors", "ConnectionFailed", "Engine"), Class'AccessControl'.Default.IPBanned);
					return;
				}
				else
				{
					if (FailCode == "SESSIONBAN")
					{
						ViewportOwner.Actor.ClearProgressMessages();
						return;
					}
					else
					{
						if (FailCode == "SERVERFULL")
						{
							ViewportOwner.Actor.ClearProgressMessages();
							ViewportOwner.GUIController.OpenMenu(Class'GameEngine'.Default.DisconnectMenuClass, ServerFullMsg);
							return;
						}
						else
						{
							if (FailCode == "CHALLENGE")
							{
								ViewportOwner.Actor.ClearProgressMessages();
								ViewportOwner.Actor.ClientNetworkMessage("FC_Challege", "");
								return;
							}
						}
					}
				}
			}
		}
	}
	Log("Unhandled connection failure!  FailCode '" $ FailCode @ "'   URL '" $ URL $ "'");
	ViewportOwner.Actor.ProgressCommand("menu:" $ Class'GameEngine'.Default.DisconnectMenuClass, FailCode, Error);
	*/
}

void UExtendedConsole::NotifyLevelChange()
{
	/*
	Super::NotifyLevelChange();
	if (VoiceChannels.Length > 0)
	{
		VoiceChannels.remove(0, VoiceChannels.Length);
	}
	*/
}

void UExtendedConsole::Cls()
{
	/*
	SBHead = 0;
	Scrollback.remove(0, Scrollback.Length);
	*/
}

void UExtendedConsole::PostRender(UCanvas* Canvas)
{
}

void UExtendedConsole::Chat(FString Msg, float MsgLife, AAA2_PlayerState* PRI)
{
	/*
	int32 Index = 0;
	Message(Msg, MsgLife);
	Index = ChatMessages.Length;
	ChatMessages.Length = (Index + 1);
	ChatMessages[Index].Message = Msg;
	if ((PRI != None) && (PRI.Team != None))
	{
		ChatMessages[Index].Team = PRI.Team.TeamIndex;
	}
	else
	{
		ChatMessages[Index].Team = 2;
	}
	if ((((!bTeamChatOnly) || (PRI == None)) || (PRI.Team == None)) || (PRI.Team == ViewportOwner.Actor.PlayerReplicationInfo.Team))
	{
		OnChat(Msg, ChatMessages[Index].Team);
		OnChatMessage(Msg);
	}
	if (ChatMessages.Length > 100)
	{
		ChatMessages.remove(0, 1);
	}
	*/
}

void UExtendedConsole::OnChatMessage(FString Msg)
{
}

void UExtendedConsole::Message(FString Msg, float MsgLife, FColor Color)
{
	/*
	if (Scrollback.Length == MaxScrollbackSize)
	{
		Scrollback.remove(0, 1);
		SBHead = (MaxScrollbackSize - 1);
	}
	else
	{
		SBHead++;
	}
	Scrollback.Length = (Scrollback.Length + 1);
	Scrollback[SBHead] = Msg;
	Super::Message(Msg, MsgLife);
	*/
}

bool UExtendedConsole::KeyEvent(EInputKey Key, EInputAction Action, float Delta)
{
	/*
	if (Key == ConsoleHotKey)
	{
		if (Action == 3)
		{
			ConsoleOpen();
		}
		return true;
	}
	return Super::KeyEvent(Key, Action, Delta);
	*/
	return false;   //FAKE   /ELiZ

}

void UExtendedConsole::PlayConsoleSound(USoundBase* S)
{
	/*
	if (((ViewportOwner == None) || (ViewportOwner.Actor == None)) || (ViewportOwner.Actor.Pawn == None))
	{
		return;
	}
	ViewportOwner.Actor.ClientPlaySound(S);
	*/
}

void UExtendedConsole::NativeConsoleOpen()
{
	//ConsoleOpen();
}

void UExtendedConsole::ConsoleOpen()
{
	/*
	UnPressButtons();
	TypedStr = "";
	TypedStrPos = 0;
	bCtrl = false;
	bAlt = false;
	bShift = false;
	GotoState('ConsoleVisible');
	PlayConsoleSound(SMOpenSound);
	*/
}

void UExtendedConsole::ConsoleClose()
{
	/*
	TypedStr = "";
	TypedStrPos = 0;
	bCtrl = false;
	bAlt = false;
	bShift = false;
	if (GetStateName() == 'ConsoleVisible')
	{
		PlayConsoleSound(SMDenySound);
		GotoState('None');
	}
	*/
}

void UExtendedConsole::ConsoleToggle()
{
	/*
	Log("console toggle");
	UnPressButtons();
	if (GetStateName() == 'ConsoleVisible')
	{
		ConsoleClose();
	}
	else
	{
		ConsoleOpen();
	}
	*/
}

void UExtendedConsole::OnExecAddFavorite(FServerFavorite Fav)
{
}

void UExtendedConsole::AddCurrentToFavorites()
{
	/*
	FString Address = "";
	FString IPString = "";
	FString portString = "";
	int32 colonPos = 0;
	int32 portNum = 0;
	local ServerFavorite NewFav;
	if ((ViewportOwner == None) || (ViewportOwner.Actor == None))
	{
		return;
	}
	Address = ViewportOwner.Actor.GetServerNetworkAddress();
	if (Address == "")
	{
		return;
	}
	colonPos = InStr(Address, ":");
	if (colonPos < 0)
	{
		IPString = Address;
		portNum = 7777;
	}
	else
	{
		IPString = Left(Address, colonPos);
		portString = Mid(Address, (colonPos + 1));
		portNum = int(portString);
	}
	NewFav.IP = IPString;
	NewFav.Port = portNum;
	NewFav.QueryPort = (portNum + 1);
	if (AddFavorite(NewFav))
	{
		ViewportOwner.Actor.ClientMessage(AddedCurrentHead @ Address @ AddedCurrentTail);
	}
	OnExecAddFavorite(NewFav);
	*/
}

bool UExtendedConsole::InFavorites(FServerFavorite Fav)
{
	/*
	int32 i = 0;
	if (Fav.IP == "")
	{
		return false;
	}
	if (Fav.Port == 0)
	{
		Fav.Port = 7777;
	}
	if (Fav.QueryPort == 0)
	{
		Fav.QueryPort = (Fav.Port + 1);
	}
	for (i = 0; i < Default.Favorites.Length; i++)
	{
		if (((Fav.IP == Default.Favorites[i].IP) && (Fav.Port == Default.Favorites[i].Port)) && (Fav.QueryPort == Default.Favorites[i].QueryPort))
		{
			return true;
		}
	}
	*/
	return false;
}

bool UExtendedConsole::AddFavorite(FServerFavorite NewFav)
{
	int32 i = 0;
	bool bNew = false;
	/*
	if (NewFav.IP == "")
	{
		return false;
	}
	if (NewFav.Port == 0)
	{
		NewFav.Port = 7777;
	}
	if (NewFav.QueryPort == 0)
	{
		NewFav.QueryPort = (NewFav.Port + 1);
	}
	bNew = true;
	i = 0;
	if (i < Default.Favorites.Length)
	{
		if (((NewFav.IP == Default.Favorites[i].IP) && (NewFav.Port == Default.Favorites[i].Port)) && (NewFav.QueryPort == Default.Favorites[i].QueryPort))
		{
			if (NewFav.ServerName ~= Default.Favorites[i].ServerName)
			{
				return false;
			}
			bNew = false;
		}
		else
		{
			i++;
		}
	}
	Default.Favorites[i] = NewFav;
	StaticSaveConfig();
	*/
	return bNew;
}

bool UExtendedConsole::RemoveFavorite(FString IP, int32 Port, int32 QueryPort)
{
	/*
	int32 i = 0;
	for (i = 0; i < Default.Favorites.Length; i++)
	{
		if (((Default.Favorites[i].IP == IP) && (Default.Favorites[i].Port == Port)) && (Default.Favorites[i].QueryPort == QueryPort))
		{
			Default.Favorites.remove(i, 1);
			StaticSaveConfig();
			return true;
		}
	}
	*/
	return false;
}

void UExtendedConsole::GetFavorites(TArray<FServerFavorite>& List)
{
	//List = Default.Favorites;
}

void UExtendedConsole::SaveFavorites()
{
	//StaticSaveConfig();
}

void UExtendedConsole::SpeechMenuToggle()
{
	/*
	if (ViewportOwner.Actor.PlayerReplicationInfo.bOnlySpectator || (ViewportOwner.Actor.PlayerReplicationInfo.VoiceType == None))
	{
		return;
	}
	GotoState('SpeechMenuVisible');
	*/
}

void UExtendedConsole::IngameChat()
{
	/*
	local GUIController gc;
	gc = GUIController(ViewportOwner.GUIController);
	if (gc.OpenMenu(ChatMenuClass))
	{
		ChatMenu = gc.ActivePage;
	}
	*/
}

void UExtendedConsole::ServerInfo()
{
	/*
	local GUIController gc;
	gc = GUIController(ViewportOwner.GUIController);
	if (gc == None)
	{
		return;
	}
	gc.OpenMenu(ServerInfoMenu);
	*/
}

void UExtendedConsole::TeamChatOnly()
{
	//bTeamChatOnly = (!bTeamChatOnly);
}

void UExtendedConsole::PlayWaitingGame()
{
	/*
	local GUIController gc;
	if (WaitingGameClassName == "")
	{
		return;
	}
	gc = GUIController(ViewportOwner.GUIController);
	if (gc != None)
	{
		gc.OpenMenu(WaitingGameClassName);
	}
	*/
}

void UExtendedConsole::MusicMenu()
{
	/*
	local GUIController C;
	int32 i = 0;
	if (MusicManagerClassName == "")
	{
		Log("No music player menu configured.  Please check the MusicManagerClassName line of the [XInterface.ExtendedConsole] section of the UT2004.ini.");
		return;
	}
	C = GUIController(ViewportOwner.GUIController);
	if (C != None)
	{
		i = C.FindMenuIndexByName(MusicManagerClassName);
		if (i == -1)
		{
			C.OpenMenu(MusicManagerClassName);
		}
		else
		{
			C.RemoveMenuAt(i, true);
		}
	}
	*/
}

void UExtendedConsole::DumpPlayInfo(FString Group)
{
	/*
	local PlayInfo PInfo;
	ForEach AllObjects(Class'PlayInfo', PInfo)
	{
		if ((PInfo.InfoClasses.Length > 0) && (PInfo.Settings.Length > 0))
		{
			PInfo.Dump(Group);
		}
		else
		{
		}
	}
	*/
}

void UExtendedConsole::DumpRecords(FString Type)
{
	//DumpCacheRecords(Type);
}

void UExtendedConsole::AddMessage(FString Mesg)
{
	/*
	Log(Mesg);
	Message(Mesg, 0);
	*/
}

void UExtendedConsole::DumpCacheRecords(FString CacheType)
{
	/*
	int32 i = 0;
	FString Margin = "";
	local TArray<CrosshairRecord> CRecs;
	local TArray<CacheManager.WeaponRecord> WRecs;
	local TArray<CacheManager.MapRecord> MRecs;
	local TArray<MutatorRecord> MutRecs;
	local TArray<CacheManager.GameRecord> GRecs;
	local TArray<AnnouncerRecord> ARecs;
	local TArray<VehicleRecord> VRecs;
	if ((CacheType == "") || (CacheType ~= "Crosshair"))
	{
		Class'CacheManager'.GetCrosshairList(CRecs);
		AddMessage(" ================ Cached crosshair records ================ ");
		for (i = 0; i < CRecs.Length; i++)
		{
			AddMessage(string(CRecs[i].RecordIndex) $ ")" @ CRecs[i].FriendlyName @ string(CRecs[i].CrosshairTexture));
		}
		AddMessage("");
	}
	if ((CacheType == "") || (CacheType ~= "GameType"))
	{
		Class'CacheManager'.GetGameTypeList(GRecs);
		AddMessage(" ================ Cached gametype records ================ ");
		for (i = 0; i < GRecs.Length; i++)
		{
			Margin = "";
			if (Len(Margin) < Len(string(i)))
			{
				Margin $ = " ";
			}
			AddMessage(string(GRecs[i].RecordIndex) $ ")" @ GRecs[i].ClassName);
			AddMessage(Margin $ "    Name        :" $ GRecs[i].GameName);
			AddMessage(Margin $ "    Description :" $ GRecs[i].Description);
			AddMessage(Margin $ "    TextName    :" $ GRecs[i].TextName);
			AddMessage(Margin $ "    GameAcronym :" $ GRecs[i].GameAcronym);
			AddMessage(Margin $ "    MapListType :" $ GRecs[i].MapListClassName);
			AddMessage(Margin $ "    MapPrefix   :" $ GRecs[i].MapPrefix);
			AddMessage(Margin $ "    bTeamGame   :" $ string(GRecs[i].bTeamGame));
			AddMessage(Margin $ "    Group       :" $ string(GRecs[i].GameTypeGroup));
		}
		AddMessage("");
	}
	if ((CacheType == "") || (CacheType ~= "Weapon"))
	{
		Class'CacheManager'.GetWeaponList(WRecs);
		AddMessage(" ================ Cached weapon records ================ ");
		for (i = 0; i < WRecs.Length; i++)
		{
			Margin = "";
			if (Len(Margin) < Len(string(i)))
			{
				Margin $ = " ";
			}
			AddMessage(string(WRecs[i].RecordIndex) $ ")" @ WRecs[i].ClassName);
			AddMessage(Margin $ "    FriendlyName:" $ WRecs[i].FriendlyName);
			AddMessage(Margin $ "    Description :" $ WRecs[i].Description);
			AddMessage(Margin $ "    TextName    :" $ WRecs[i].TextName);
			AddMessage(Margin $ "    PickupClass :" $ WRecs[i].PickupClassName);
			AddMessage(Margin $ "    Attachment  :" $ WRecs[i].AttachmentClassName);
		}
		AddMessage("");
	}
	if ((CacheType == "") || (CacheType ~= "Map"))
	{
		Class'CacheManager'.GetMapList(MRecs);
		AddMessage(" ================ Cached map records ================ ");
		for (i = 0; i < MRecs.Length; i++)
		{
			Margin = "";
			if (Len(Margin) < Len(string(i)))
			{
				Margin $ = " ";
			}
			AddMessage(string(MRecs[i].RecordIndex) $ ")" @ MRecs[i].MapName);
			AddMessage(Margin $ "    Acronym       :" $ MRecs[i].Acronym);
			AddMessage(Margin $ "    TextName      :" $ MRecs[i].TextName);
			AddMessage(Margin $ "    FriendlyName  :" $ MRecs[i].FriendlyName);
			AddMessage(Margin $ "    Author        :" $ MRecs[i].Author);
			AddMessage(Margin $ "    PlayerCountMin:" $ string(MRecs[i].PlayerCountMin));
			AddMessage(Margin $ "    PlayerCountMax:" $ string(MRecs[i].PlayerCountMax));
			AddMessage(Margin $ "    Description   :" $ MRecs[i].Description);
			AddMessage(Margin $ "    Screenshot    :" $ MRecs[i].ScreenshotRef);
			AddMessage(Margin $ "    ExtraInfo     :" $ MRecs[i].ExtraInfo);
		}
		AddMessage("");
	}
	if ((CacheType == "") || (CacheType ~= "Mutator"))
	{
		Class'CacheManager'.GetMutatorList(MutRecs);
		AddMessage(" ================ Cached mutator records ================ ");
		for (i = 0; i < MutRecs.Length; i++)
		{
			Margin = "";
			if (Len(Margin) < Len(string(i)))
			{
				Margin $ = " ";
			}
			AddMessage(string(MutRecs[i].RecordIndex) $ ")" @ MutRecs[i].ClassName);
			AddMessage(Margin $ "    FriendlyName       :" $ MutRecs[i].FriendlyName);
			AddMessage(Margin $ "    Description        :" $ MutRecs[i].Description);
			AddMessage(Margin $ "    GroupName          :" $ MutRecs[i].GroupName);
			AddMessage(Margin $ "    ConfigMenu         :" $ MutRecs[i].ConfigMenuClassName);
			AddMessage(Margin $ "    IconMaterialName   :" $ MutRecs[i].IconMaterialName);
		}
		AddMessage("");
	}
	if ((CacheType == "") || (CacheType ~= "Announcer"))
	{
		Class'CacheManager'.GetAnnouncerList(ARecs);
		AddMessage(" ================ Cached announcer records ================ ");
		for (i = 0; i < ARecs.Length; i++)
		{
			Margin = "";
			if (Len(Margin) < Len(string(i)))
			{
				Margin $ = " ";
			}
			AddMessage(string(ARecs[i].RecordIndex) $ ")" @ ARecs[i].ClassName);
			AddMessage(Margin $ "    FriendlyName       :" $ ARecs[i].FriendlyName);
			AddMessage(Margin $ "    PackageName        :" $ ARecs[i].PackageName);
			AddMessage(Margin $ "    FallbackPackage    :" $ ARecs[i].FallbackPackage);
		}
		AddMessage("");
	}
	if ((CacheType == "") || (CacheType ~= "Vehicle"))
	{
		Class'CacheManager'.GetVehicleList(VRecs);
		AddMessage(" ================ Cached vehicle records ================ ");
		for (i = 0; i < VRecs.Length; i++)
		{
			Margin = "";
			if (Len(Margin) < Len(string(i)))
			{
				Margin $ = " ";
			}
			AddMessage(string(VRecs[i].RecordIndex) $ ")" @ VRecs[i].ClassName);
			AddMessage(Margin $ "    FriendlyName       :" $ VRecs[i].FriendlyName);
			AddMessage(Margin $ "    Description        :" $ VRecs[i].Description);
		}
		AddMessage("");
	}
	*/
}

bool UExtendedConsole::VoiceChatAllowed()
{
	/*
	if (ViewportOwner == None)
	{
		return false;
	}
	if (ViewportOwner.Actor == None)
	{
		return false;
	}
	if (ViewportOwner.Actor.Level == None)
	{
		return false;
	}
	if (ViewportOwner.Actor.Level.NetMode == NM_DedicatedServer)
	{
		return false;
	}
	if (ViewportOwner.Actor.Level.NetMode == NM_Standalone)
	{
		return false;
	}
	*/
	return true;
}

void UExtendedConsole::DLO(FString ClassName, FString ClassType)
{
	/*
	local class<Object>  C;
	local Object O;
	if (ClassName == "")
	{
		Log("No class name specified.");
		return;
	}
	if (ClassType != "")
	{
		C = class<Object>(DynamicLoadObject(ClassType, Class'Class'));
	}
	else
	{
		C = Class'Class';
	}
	O = DynamicLoadObject(ClassName, C);
	Log("Result of DLO was " $ string(O));
	*/
}

void UExtendedConsole::DumpLoadingHints(FString Param)
{
	/*
	local TArray<CacheManager.GameRecord> Recs;
	int32 i = 0;
	int32 j = 0;
	bool bShowAll = false;
	local class<GameInfo>  GameClass;
	local TArray<FString> Hints;
	Class'CacheManager'.GetGameTypeList(Recs);
	bShowAll = (Param == "");
	for (i = 0; i < Recs.Length; i++)
	{
		GameClass = class<GameInfo>(DynamicLoadObject(Recs[i].ClassName, Class'Class'));
		if (GameClass != None)
		{
			Hints = GameClass.GetAllLoadHints((!bShowAll));
			if (Hints.Length > 0)
			{
				Log(Recs[i].GameName @ "Loading Hints -");
				for (j = 0; j < Hints.Length; j++)
				{
					Log("  " $ string(j) $ ") " $ Hints[j]);
				}
				Log("");
			}
		}
	}
	*/
}

void UExtendedConsole::DebugTabOrder()
{
	/*
	if ((GUIController(ViewportOwner.GUIController) != None) && (GUIController(ViewportOwner.GUIController).ActivePage != None))
	{
		Log("Searching for components with invalid tab order...");
		GUIController(ViewportOwner.GUIController).ActivePage.DebugTabOrder();
	}
	*/
}