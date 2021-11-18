// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PlaylistParserBase.h"

UPlaylistParserBase::UPlaylistParserBase()
{
	//SpecialChars(0) = (Plain = "&", Coded = "&amp;")
	//SpecialChars(1) = (Plain = """,Coded=" & quot; ")
	//SpecialChars(2) = (Plain = " ", Coded = "&nbsp;")
	//SpecialChars(3) = (Plain = "<", Coded = "&lt;")
	//SpecialChars(4) = (Plain = ">", Coded = "&gt;")
	//SpecialChars(5) = (Plain = "©", Coded = "&copy;")
	//SpecialChars(6) = (Plain = "™", Coded = "&#8482;")
	//SpecialChars(7) = (Plain = "®", Coded = "&reg;")
	//SpecialChars(8) = (Plain = "'", Coded = "&apos;")

}


EStreamPlaylistType UPlaylistParserBase::GetType()
{
	return Type;
}
void UPlaylistParserBase::SetType(EStreamPlaylistType InType)
{
	/*
	if (Type != 0)
	{
		Return;
	}
	*/
	Type = InType;
}
bool UPlaylistParserBase::Import(int32 PlaylistIndex, int32 InsertPosition, FString Path)
{
	/*
	if (Outer.FileManager.LoadPlaylist(Path, Lines))
	{
		ImportedPlaylist(PlaylistIndex, InsertPosition);
		Return True;
	}
	*/
	return false;
}
void UPlaylistParserBase::ImportedPlaylist(int32 PlaylistIndex, int32 InsertPosition)
{
	/*
	local StreamPlaylist Playlist;
	local int i;
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
	for (i = Paths.Length - 1; i >= 0; i--)
	{
		Outer.InsertInPlaylist(PlaylistIndex, InsertPosition, Paths[i], i > 0);
	}
	Outer.Save();
	*/
}
void UPlaylistParserBase::ParseLines()
{
	//Paths.remove(0, Paths.Length);
}
FString UPlaylistParserBase::GetValue(FString KeyValuePair, bool bAllowSpaces)
{
	/*
	local int i;
	local string str;
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
			Return str;
		}
		i = InStr(str, " ");
		if (i != -1 && !bAllowSpaces)
		{
			str = Left(str, i);
		}
		Return str;
	}
	*/
	return "";
}
FString UPlaylistParserBase::GetTagged(FString &Text)
{
	/*
	local string Tag;
	local int opos;
	local int cpos;
	opos = InStr(Text, "<");
	if (opos != -1)
	{
		Text = Mid(Text, opos + 1);
		cpos = InStr(Text, ">");
		if (cpos == -1)
		{
			Return "";
		}
		Tag = Left(Text, cpos);
		Text = Mid(Text, cpos + 1);
		opos = InStr(Locs(Text), "</" $ Locs(Tag) $ ">");
		if (opos == -1)
		{
			Return Tag;
		}
		Text = Left(Text, opos);
		Return Tag;
	}
	*/
	return "";
}
FString UPlaylistParserBase::HtmlDecode(FString Src)
{
	/*
	local int i;
	for (i = 0; i < Default.SpecialChars.Length; i++)
	{
		Src = Repl(Src, Default.SpecialChars[i].Coded, Default.SpecialChars[i].Plain);
	}
	*/
	return Src;
}