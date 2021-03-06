// All the original content belonged to the US Army

#include "AA29/Object/AdminBase/AdminBase.h"
#include "AA29/Object/Actor/Info/AccessControl/AccessControl.h"

UAdminBase::UAdminBase()
{
	Msg_PlayerList = "Player List:";
	Msg_AllGameMaps = "Maps that are valid (can be added) to";
	Msg_AllMapLists = "Available maplists for %gametype%.";
	Msg_MapRotationList = "Active maps for maplist %maplist%.";
	Msg_NoMapsAdded = "No maps added to the maplist %maplist%.";
	Msg_AddedMapToList = "Maps successfully added to maplist";
	Msg_NoMapsRemoved = "No maps were removed from the maplist %maplist%.";
	Msg_RemovedFromList = "Maps successfully removed from maplist";
	Msg_PlayerBanned = "%Player% has been banned from this server";
	Msg_SessionBanned = "%Player% has been banned for this match";
	Msg_PlayerKicked = "%Player% has been kicked";
	Msg_NextMapNotFound = "Next map not found; Restarting same map";
	Msg_ChangingMapTo = "Changing Map to %NextMap%";
	Msg_NoMapInRotation = "No maps configured for %maplist%.";
	Msg_NoMapsFound = "No matching maps in maplist %maplist% were found.";
	Msg_MapIsInRotation = "Matching %maplist% maps";
	Msg_MapNotInRotation = "Matching maps which are not members of %maplist%.";
	Msg_UnknownParam = "Unknown Parameter : %Value%";
	Msg_NoParamsFound = "No Parameters found!";
	Msg_ParamModified = "Modification Successful";
	Msg_ParamNotModified = "Could not Modify Parameter";
	Msg_MapListAdded = "Maplist %listname% successfully added for gametype";
	Msg_MapListRemoved = "Maplist %listname% successfully removed from gametype";
	Msg_EditingMapList = "Now editing maplist";
}

void UAdminBase::Created()
{
	/*
	if (Outer.Level.Game.AccessControl != nullptr)
	{
		Manager = Outer.Level.Game.AccessControl;
	}
	*/
}
void UAdminBase::DoLogin(FString UserName, FString Password)
{
}
void UAdminBase::DoLogout()
{
}
void UAdminBase::DoSwitch(FString URL)
{
	//Outer.Level.ServerTravel(URL, false);
}
void UAdminBase::GoToNextMap()
{
	if (bAdmin)
	{
		//Outer.Level.Game.bChangeLevels = true;
		//Outer.Level.Game.bAlreadyChanged = false;
		//Outer.Level.Game.RestartGame();
	}
}
void UAdminBase::ShowCurrentMapList()
{
	int32 i = 0;
	int32 C = 0;
	TArray<FString> Ar = {};
	/*
	i = Outer.MapHandler.GetGameIndex(Outer.Level.Game.Class);
	C = Outer.MapHandler.GetActiveList(i);
	Ar = Outer.MapHandler.GetCacheMapList(Outer.Level.Game.Acronym);
	SendComplexMsg(Ar, Msg_AllGameMaps @ Outer.MapHandler.GetMapListTitle(i, C));
	*/
}
TArray<FString> UAdminBase::GetMapListNames(FString aGameType)
{
	int32 i = 0;
	TArray<FString> Ar = {};
	/*
	i = Outer.MapHandler.GetGameIndex(GameType);
	Ar = Outer.MapHandler.GetMapListNames(i);
	*/
	return Ar;
}

void UAdminBase::MaplistCommand(FString Cmd, FString Extra)
{
	TArray<FString> Values = {};
	FString str = "";
	int32 i = 0;
	int32 C = 0;
	/*
	if (CanPerform("Ml"))
	{
		Cmd = Caps(Cmd);
		i = Outer.MapHandler.GetGameIndex(Outer.Level.Game.Class);
		switch(Cmd)
		{
				case "LIST":
					Values = Outer.MapHandler.GetMapListNames(i);
					SendComplexMsg(Values, Repl(Msg_AllMapLists, "%gametype%", Outer.Level.Game.Class));
					break;
				case "USED":
					if (Extra == "")
					{
						C = Outer.MapHandler.GetActiveList(i);
					}
					else
					{
						C = Extra;
					}
					str = Outer.MapHandler.GetMapListTitle(i, C);
					Values = Outer.MapHandler.GetMapList(i, C);
					SendComplexMsg(Values, Repl(Msg_MapRotationList, "%maplist%", str));
				case "SWITCH":
					if (Extra == "")
					{
						C = Outer.MapHandler.GetActiveList(i);
					}
					else
					{
						C = Extra;
					}
					str = Outer.MapHandler.GetMapListTitle(i, C);
				case "ADD":
					C = Outer.MapHandler.GetActiveList(i);
					Split(Extra, ",", Values);
					if (Values.Num() == 0)
					{
						Outer.ClientMessage(Repl(Msg_NoMapsAdded, "%maplist%", Outer.MapHandler.GetMapListTitle(i, C)));
					}
					else
					{
						for (i = Values.Num() - 1; i >= 0; i--)
						{
							if (!Outer.MapHandler.AddMap(i, C, Values[i]))
							{
								Values.RemoveAt(i, 1);
							}
						}
						SendComplexMsg(Values, Msg_AddedMapToList @ Outer.MapHandler.GetMapListTitle(i, C));
					}
				case "DEL":
					C = Outer.MapHandler.GetActiveList(i);
					Split(Extra, ",", Values);
					if (Values.Num() == 0)
					{
						Outer.ClientMessage(Repl(Msg_NoMapsRemoved, "%maplist%", Outer.MapHandler.GetMapListTitle(i, C)));
					}
					else
					{
						for (i = Values.Num() - 1; i >= 0; i--)
						{
							if (!Outer.MapHandler.RemoveMap(i, C, Values[i]))
							{
								Values.RemoveAt(i, 1);
							}
						}
						SendComplexMsg(Values, Msg_RemovedFromList @ Outer.MapHandler.GetMapListTitle(i, C));
					}
				default:
		}
	}
	*/
}
void UAdminBase::RestartCurrentMap()
{
	//Outer.Level.ServerTravel("?restart", false);
}
void UAdminBase::PlayerList()
{
	/*
	AAA2_PlayerState* PRI = nullptr;
	if (CanPerform("Xp"))
	{
		Log(Msg_PlayerList);
		ForEach Outer.DynamicActors('PlayerReplicationInfo', PRI)
		{
			Log(PRI.PlayerName @ "( ping" @ PRI.Ping + ")");
		}
	}
	*/
}
void UAdminBase::Kick(FString Cmd, FString Extra)
{
}
void UAdminBase::KickBan(FString S)
{
	//Kick("ban", S);
}
void UAdminBase::RestartMap()
{
	RestartCurrentMap();
}
void UAdminBase::NextMap()
{
	GoToNextMap();
}
void UAdminBase::Map(FString Cmd)
{
	if(Cmd.Compare("Restart",ESearchCase::IgnoreCase))
	{
		//Outer->ConsoleCommand("RestartMap");
	}
	else
	{
		if (Cmd.Compare("Next", ESearchCase::IgnoreCase))
		{
			GoToNextMap();
		}
		else
		{
			if (Cmd.Compare("List", ESearchCase::IgnoreCase) )
			{
				ShowCurrentMapList();
			}
			else
			{
				DoSwitch(Cmd);
			}
		}
	}
}
void UAdminBase::MapList(FString Cmd, FString Extra)
{
	MaplistCommand(Cmd, Extra);
}

void UAdminBase::Switch(FString URL)
{
	DoSwitch(URL);
}

bool UAdminBase::CanPerform(FString priv)
{
	return true;
}

FString UAdminBase::FindGameType(FString aGameType)
{
	int32 i = 0;
	TArray<FGameRecord> Records = {};
	/*
	'CacheManager'.GetGameTypeList(Records);
	for (i = 0; i < Records.Num(); i++)
	{
		if (GameType ~= Records[i].ClassName)
		{
		}
		if (GameType ~= Records[i].GameAcronym)
		{
		}
		if (GameType ~= Records[i].TextName)
		{
		}
		if (Right(Records[i].ClassName, Len(GameType) + 1) ~= "." + GameType)
		{
		}
		if (Right(Records[i].TextName, Len(GameType) + 1) ~= "." + GameType)
		{
		}
	}
	if (i < Records.Num())
	{
		return Records[i].ClassName;
	}
	return "";
	*/

	return "FAKE";    //FAKE   /EliZ
}
void UAdminBase::SendComplexMsg(TArray<FString> Arr, FString Title)
{
	int32 i = 0;
	int32 Longest = 0;
	FString Line = "";
	FString Border = "";
	FString Prefix = "";
	FString Suffix = "";
	for (i = 0; i < Arr.Num(); i++)
	{
		if (Arr[i].Len() > Longest)
		{
			Longest = Arr[i].Len();
		}
	}
	Longest += 8;
	Border = "";
	if (Border.Len() < Longest)
	{
		Border = Border + "-";
	}
	/*
	Outer.ClientMessage(Title);
	Outer.ClientMessage(Border);
	for (i = 0; i < Arr.Num(); i++)
	{
		Prefix = Right("[] " + i, 4) + ")";
		Suffix = " []";
		Line = Prefix + Arr[i] + Suffix;
		if (Len(Line) < Longest)
		{
			Suffix = " " + Suffix;
			Line = Prefix + Arr[i] + Suffix;
		}
		Outer.ClientMessage(Line);
	}
	Outer.ClientMessage(Border);
	*/
}

bool UAdminBase::MaskedCompare(FString SettingName, FString Mask)
{
	bool bMaskLeft = false;
	bool bMaskRight = false;
	int32 MaskLen = 0;
	if (Mask == "*" || Mask == "**")
	{
		return true;
	}
	MaskLen = Mask.Len();
	/*
	bMaskLeft = Left(Mask, 1) == "*";
	bMaskRight = Right(Mask, 1) == "*";
	if (bMaskLeft && bMaskRight)
	{
		return InStr(Caps(SettingName), Mid(Caps(Mask), 1, MaskLen - 2)) >= 0;
	}
	if (bMaskLeft)
	{
		return Left(SettingName, MaskLen - 1) ~= Left(Mask, MaskLen - 1);
	}
	if (bMaskRight)
	{
		return Right(SettingName, MaskLen - 1) ~= Right(Mask, MaskLen - 1);
	}
	return SettingName ~= Mask;
	*/

	return false;    //FAKE  /EliZ
}

bool UAdminBase::IsNumeric(FString Param, bool bPositiveOnly)
{
	int32 p = 0;
	p = 0;
	/*
	if (Mid(Param, p, 1) == " ")
	{
		p++;
	}
	if (Mid(Param, p, 1) >= "0" && Mid(Param, p, 1) <= "9")
	{
		p++;
	}
	if (Mid(Param, p, 1) == " ")
	{
		p++;
	}
	if (Mid(Param, p) != "")
	{
		return false;
	}
	*/
	return true;
}

TArray<FString> UAdminBase::SplitParams(FString Params)
{
	TArray<FString> Splitted = {};
	FString Delim = "";
	int32 p = 0;
	int32 Start = 0;
	if (Params != "")
	{
		p = 0;
		/*
		if (Mid(Params, p, 1) == " ")
		{
			p++;
		}
		if (Mid(Params, p) == "")
		{
		}
		Start = p;
		if (Mid(Params, p, 1) == """")
		{
			p++;
			Start++;
			if (Mid(Params, p, 1) != "" && Mid(Params, p, 1) != """")
			{
				p++;
			}
			if (Mid(Params, p, 1) == """")
			{
				Splitted[Splitted.Num()] = Mid(Params, Start, p - Start);
				p++;
			}
		}
		else
		{
			if (Mid(Params, p, 1) != "" && Mid(Params, p, 1) != Delim)
			{
				p++;
			}
			Splitted[Splitted.Num()] = Mid(Params, Start, p - Start);
		}
		Params = Mid(Params, p);
		*/
	}
	return Splitted;
}
