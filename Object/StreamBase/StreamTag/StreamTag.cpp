// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamTag/StreamTag.h"

UStreamTag::UStreamTag()
{

}




void UStreamTag::OnRefresh()
{
}
void UStreamTag::DumpScriptTag()
{
	/*
	local int i;
	Log("================");
	Log("      TagID:" $ TagID.FieldName @ "#" @ TagID.FieldValue);
	Log("TrackNumber:" $ TrackNumber.FieldName @ "#" @ TrackNumber.FieldValue);
	Log("      Title:" $ Title.FieldName @ "#" @ Title.FieldValue);
	Log("     Artist:" $ Artist.FieldName @ "#" @ Artist.FieldValue);
	Log("      Album:" $ Album.FieldName @ "#" @ Album.FieldValue);
	Log("       Year:" $ Year.FieldName @ "#" @ Year.FieldValue);
	Log("      Genre:" $ Genre.FieldName @ "#" @ Genre.FieldValue);
	Log("   Duration:" $ Duration.FieldName @ "#" @ Duration.FieldValue);
	Log("  == All Fields == ");
	for (i = 0; i < Fields.Length; i++)
	{
		Log("    " $ i $ ") ID:" $ Fields[i].FieldID @ "Name:" $ Fields[i].FieldName @ "Value:" $ Fields[i].FieldValue);
	}
	Log("");
	*/
}

//native final Function DumpTag();
void UStreamTag::DumpTag()
{
}
