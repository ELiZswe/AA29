// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/B4SParser/B4SParser.h"

UB4SParser::UB4SParser()
{

}



void UB4SParser::ParseLines()
{
	/*
	local int i;
	local int pos;
	local string str;
	ParseLines();
	if (Lines.Length == 0)
	{
		Return;
	}
	for (i = 0; i < Lines.Length; i++)
	{
		if (InStr(Lines[i], "</playlist>") != -1 || Lines[i] == "")
		{
		}
		if (PlaylistName == "")
		{
			pos = InStr(Lines[i], "num_entries");
			if (pos == -1)
			{
			}
			pos = InStr(Lines[i], "label");
			if (pos == -1)
			{
				PlaylistName = Outer.DefaultPlaylistName;
			}
			else
			{
				PlaylistName = GetValue(Mid(Lines[i], pos));
			}
			else
			{
				if (InStr(Lines[i], "<entry ") != -1)
				{
					str = GetValue(Lines[i]);
					if (str == "" || Left(str, 5) != "file:")
					{
					}
					Paths[Paths.Length] = HtmlDecode(Mid(str, 5));
				}
			}
		}
	}
	*/
}
