// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PLSParser/PLSParser.h"

UPLSParser::UPLSParser()
{

}

void UPLSParser::ParseLines()
{
	/*
	int32 i;
	ParseLines();
	if (Lines.Num() == 0)
	{
		return;
	}
	for (i = 0; i < Lines.Num(); i++)
	{
		if (Left(Lines[i], 1) == "[" || Lines[i] == "")
		{
		}
		if (PlaylistName == "" && Left(Lines[i], InStr(Lines[i], "=")) ~= "PlaylistName")
		{
			PlaylistName = GetValue(Lines[i], True);
		}
		else
		{
			if (Left(Lines[i], 4) ~= "File")
			{
				Paths[Paths.Num()] = GetValue(Lines[i], True);
			}
		}
	}
	*/
}
