// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PlaylistParserBase.h"

UPlaylistParserBase::UPlaylistParserBase()
{
	SpecialChars = {
		FHtmlChar({"&", "&amp;"}),
		FHtmlChar({""""," & quot; "}),
		FHtmlChar({" ", "&nbsp;"}),
		FHtmlChar({"<", "&lt;"}),
		FHtmlChar({">", "&gt;"}),
		FHtmlChar({"©", "&copy;"}),
		FHtmlChar({"™", "&#8482;"}),
		FHtmlChar({"®", "&reg;"}),
		FHtmlChar({"'", "&apos;"})
	};
}

EStreamPlaylistType UPlaylistParserBase::GetType()
{
	return Type;
}

void UPlaylistParserBase::SetType(EStreamPlaylistType InType)
{
	if (Type != EStreamPlaylistType::SPT_None)
	{
		return;
	}
	Type = InType;
}
bool UPlaylistParserBase::Import(int32 PlaylistIndex, int32 InsertPosition, FString Path)
{
	/*
	if (Outer.FileManager.LoadPlaylist(Path, Lines))
	{
		ImportedPlaylist(PlaylistIndex, InsertPosition);
		return true;
	}
	*/
	return false;
}
void UPlaylistParserBase::ImportedPlaylist(int32 PlaylistIndex, int32 InsertPosition)
{
	/*
	local StreamPlaylist Playlist;
	int32 i;
	ParseLines();
	if (!Outer.ValidIndex(PlaylistIndex))
	{
		PlaylistIndex = Outer.AddPlaylist(PlaylistName);
	}
	Playlist = Outer.Playlists[PlaylistIndex];
	if (!Playlist.ValidStreamIndex(InsertPosition))
	{
		InsertPosition = Playlist.GetPlaylistLength();
	}
	for (i = Paths.Num() - 1; i >= 0; i--)
	{
		Outer.InsertInPlaylist(PlaylistIndex, InsertPosition, Paths[i], i > 0);
	}
	Outer.Save();
	*/
}
void UPlaylistParserBase::ParseLines()
{
	//Paths.remove(0, Paths.Num());
}
FString UPlaylistParserBase::GetValue(FString KeyValuePair, bool bAllowSpaces)
{
	/*
	int32 i;
	FString str;
	i = InStr(KeyValuePair, "=");
	if (i != -1)
	{
		str = Mid(KeyValuePair, i + 1);
		if (Left(str, 1) == """")
		{
			str = Mid(str, 1);
			i = RevInStr(str, """");
			if (i != -1)
			{
				str = Left(str, i);
			}
			return str;
		}
		i = InStr(str, " ");
		if (i != -1 && !bAllowSpaces)
		{
			str = Left(str, i);
		}
		return str;
	}
	*/
	return "";
}
FString UPlaylistParserBase::GetTagged(FString &Text)
{
	/*
	FString Tag;
	int32 opos;
	int32 cpos;
	opos = InStr(Text, "<");
	if (opos != -1)
	{
		Text = Mid(Text, opos + 1);
		cpos = InStr(Text, ">");
		if (cpos == -1)
		{
			return "";
		}
		Tag = Left(Text, cpos);
		Text = Mid(Text, cpos + 1);
		opos = InStr(Locs(Text), "</" $ Locs(Tag) $ ">");
		if (opos == -1)
		{
			return Tag;
		}
		Text = Left(Text, opos);
		return Tag;
	}
	*/
	return "";
}

FString UPlaylistParserBase::HtmlDecode(FString Src)
{
	/*
	int32 i;
	for (i = 0; i < Default.SpecialChars.Num(); i++)
	{
		Src = Repl(Src, Default.SpecialChars[i].Coded, Default.SpecialChars[i].Plain);
	}
	*/
	return Src;
}
