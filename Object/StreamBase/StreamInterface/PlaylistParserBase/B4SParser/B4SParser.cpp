// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/B4SParser/B4SParser.h"

UB4SParser::UB4SParser()
{

}

void UB4SParser::ParseLines()
{
	int32 i = 0;
	int32 pos = 0;
	FString str = "";
	Super::ParseLines();
	if (Lines.Num() == 0)
	{
		return;
	}
	/*
	for (i = 0; i < Lines.Num(); i++)
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
					Paths[Paths.Num()] = HtmlDecode(Mid(str, 5));
				}
			}
		}
	}
	*/
}
