// All the original content belonged to the US Army

#include "AA29/Object/CountryFlags/CountryFlags.h"
#include "AA29/AA29.h"

UCountryFlags::UCountryFlags()
{
	FlagTexture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_countryflags.t_ui_mbs_countryflags'"), NULL, LOAD_None, NULL);
	Flags.SetNum(234);
	Flags[0] = { "ad","Andorra",0,0,18,12 };
	Flags[1] = { "ae","United Arab Emirates", 18, 0, 18, 12 };
	Flags[3] = { "ag", "Antigua and Barbuda", 36, 0, 18, 12};
	Flags[4] = { "ai", "Anguilla", 18, 12, 18, 12 };
	Flags[5] = { "al", "Albania", 0, 24, 18, 12 };
	Flags[6].CountryCode = "am";
	Flags[6].CountryName = "Armenia";
	Flags[6].U = 54;
	Flags[6].V = 0;
	Flags[6].UL = 18;
	Flags[6].VL = 12;
	Flags[7].CountryCode = "an";
	Flags[7].CountryName = "Netherlands Antilles";
	Flags[7].U = 36;
	Flags[7].V = 12;
	Flags[7].UL = 18;
	Flags[7].VL = 12;
	Flags[8].CountryCode = "ao";
	Flags[8].CountryName = "Angola";
	Flags[8].U = 18;
	Flags[8].V = 24;
	Flags[8].UL = 18;
	Flags[8].VL = 12;
	Flags[9].CountryCode = "aq";
	Flags[9].CountryName = "Antarctica";
	Flags[9].U = 0;
	Flags[9].V = 36;
	Flags[9].UL = 18;
	Flags[9].VL = 12;
	Flags[10].CountryCode = "ar";
	Flags[10].CountryName = "Argentina";
	Flags[10].U = 72;
	Flags[10].V = 0;
	Flags[10].UL = 18;
	Flags[10].VL = 12;
	Flags[11].CountryCode = "as";
	Flags[11].CountryName = "American Samoa";
	Flags[11].U = 54;
	Flags[11].V = 12;
	Flags[11].UL = 18;
	Flags[11].VL = 12;
	Flags[12].CountryCode = "at";
	Flags[12].CountryName = "Austria";
	Flags[12].U = 36;
	Flags[12].V = 24;
	Flags[12].UL = 18;
	Flags[12].VL = 12;
	Flags[13].CountryCode = "au";
	Flags[13].CountryName = "Australia";
	Flags[13].U = 18;
	Flags[13].V = 36;
	Flags[13].UL = 18;
	Flags[13].VL = 12;
	Flags[14].CountryCode = "aw";
	Flags[14].CountryName = "Aruba";
	Flags[14].U = 0;
	Flags[14].V = 48;
	Flags[14].UL = 18;
	Flags[14].VL = 12;
	Flags[15].CountryCode = "az";
	Flags[15].CountryName = "Azerbaijan";
	Flags[15].U = 90;
	Flags[15].V = 0;
	Flags[15].UL = 18;
	Flags[15].VL = 12;
	Flags[16].CountryCode = "ba";
	Flags[16].CountryName = "Bosnia and Herzegovina";
	Flags[16].U = 72;
	Flags[16].V = 12;
	Flags[16].UL = 18;
	Flags[16].VL = 12;
	Flags[17].CountryCode = "bb";
	Flags[17].CountryName = "Barbados";
	Flags[17].U = 54;
	Flags[17].V = 24;
	Flags[17].UL = 18;
	Flags[17].VL = 12;
	Flags[18].CountryCode = "bd";
	Flags[18].CountryName = "Bangladesh";
	Flags[18].U = 36;
	Flags[18].V = 36;
	Flags[18].UL = 18;
	Flags[18].VL = 12;
	Flags[19].CountryCode = "be";
	Flags[19].CountryName = "Belgium";
	Flags[19].U = 18;
	Flags[19].V = 48;
	Flags[19].UL = 18;
	Flags[19].VL = 12;
	Flags[20].CountryCode = "bf";
	Flags[20].CountryName = "Burkina Faso";
	Flags[20].U = 0;
	Flags[20].V = 60;
	Flags[20].UL = 18;
	Flags[20].VL = 12;
	Flags[21].CountryCode = "bg";
	Flags[21].CountryName = "Bulgaria";
	Flags[21].U = 108;
	Flags[21].V = 0;
	Flags[21].UL = 18;
	Flags[21].VL = 12;
	Flags[22].CountryCode = "bh";
	Flags[22].CountryName = "Bahrain";
	Flags[22].U = 90;
	Flags[22].V = 12;
	Flags[22].UL = 18;
	Flags[22].VL = 12;
	Flags[23].CountryCode = "bi";
	Flags[23].CountryName = "Burundi";
	Flags[23].U = 72;
	Flags[23].V = 24;
	Flags[23].UL = 18;
	Flags[23].VL = 12;
	Flags[24].CountryCode = "bj";
	Flags[24].CountryName = "Benin";
	Flags[24].U = 54;
	Flags[24].V = 36;
	Flags[24].UL = 18;
	Flags[24].VL = 12;
	Flags[25].CountryCode = "bm";
	Flags[25].CountryName = "Bermuda";
	Flags[25].U = 36;
	Flags[25].V = 48;
	Flags[25].UL = 18;
	Flags[25].VL = 12;
	Flags[26].CountryCode = "bn";
	Flags[26].CountryName = "Brunei Darussalam";
	Flags[26].U = 18;
	Flags[26].V = 60;
	Flags[26].UL = 18;
	Flags[26].VL = 12;
	Flags[27].CountryCode = "bo";
	Flags[27].CountryName = "Bolivia";
	Flags[27].U = 0;
	Flags[27].V = 72;
	Flags[27].UL = 18;
	Flags[27].VL = 12;
	Flags[28].CountryCode = "br";
	Flags[28].CountryName = "Brazil";
	Flags[28].U = 126;
	Flags[28].V = 0;
	Flags[28].UL = 18;
	Flags[28].VL = 12;
	Flags[29].CountryCode = "bs";
	Flags[29].CountryName = "Bahamas";
	Flags[29].U = 108;
	Flags[29].V = 12;
	Flags[29].UL = 18;
	Flags[29].VL = 12;
	Flags[30].CountryCode = "bt";
	Flags[30].CountryName = "Bhutan";
	Flags[30].U = 90;
	Flags[30].V = 24;
	Flags[30].UL = 18;
	Flags[30].VL = 12;
	Flags[31].CountryCode = "bv";
	Flags[31].CountryName = "Bouvet Island";
	Flags[31].U = 72;
	Flags[31].V = 36;
	Flags[31].UL = 18;
	Flags[31].VL = 12;
	Flags[32].CountryCode = "bw";
	Flags[32].CountryName = "Botswana";
	Flags[32].U = 54;
	Flags[32].V = 48;
	Flags[32].UL = 18;
	Flags[32].VL = 12;
	Flags[33].CountryCode = "by";
	Flags[33].CountryName = "Belarus";
	Flags[33].U = 36;
	Flags[33].V = 60;
	Flags[33].UL = 18;
	Flags[33].VL = 12;
	Flags[34].CountryCode = "bz";
	Flags[34].CountryName = "Belize";
	Flags[34].U = 18;
	Flags[34].V = 72;
	Flags[34].UL = 18;
	Flags[34].VL = 12;
	Flags[35].CountryCode = "ca";
	Flags[35].CountryName = "Canada";
	Flags[35].U = 0;
	Flags[35].V = 84;
	Flags[35].UL = 18;
	Flags[35].VL = 12;
	Flags[36].CountryCode = "cc";
	Flags[36].CountryName = "Cocos (Keeling Islands";
	Flags[36].U = 144;
	Flags[36].V = 0;
	Flags[36].UL = 18;
	Flags[36].VL = 12;
	Flags[37].CountryCode = "cd";
	Flags[37].CountryName = "Congo, The Democratic Republic of the";
	Flags[37].U = 126;
	Flags[37].V = 12;
	Flags[37].UL = 18;
	Flags[37].VL = 12;
	Flags[38].CountryCode = "cf";
	Flags[38].CountryName = "Central African Republic";
	Flags[38].U = 108;
	Flags[38].V = 24;
	Flags[38].UL = 18;
	Flags[38].VL = 12;
	Flags[39].CountryCode = "cg";
	Flags[39].CountryName = "Congo";
	Flags[39].U = 90;
	Flags[39].V = 36;
	Flags[39].UL = 18;
	Flags[39].VL = 12;
	Flags[40].CountryCode = "ch";
	Flags[40].CountryName = "Switzerland";
	Flags[40].U = 72;
	Flags[40].V = 48;
	Flags[40].UL = 18;
	Flags[40].VL = 12;
	Flags[41].CountryCode = "ci";
	Flags[41].CountryName = "Cote D'Ivoire";
	Flags[41].U = 54;
	Flags[41].V = 60;
	Flags[41].UL = 18;
	Flags[41].VL = 12;
	Flags[42].CountryCode = "ck";
	Flags[42].CountryName = "Cook Islands";
	Flags[42].U = 36;
	Flags[42].V = 72;
	Flags[42].UL = 18;
	Flags[42].VL = 12;
	Flags[43].CountryCode = "cl";
	Flags[43].CountryName = "Chile";
	Flags[43].U = 18;
	Flags[43].V = 84;
	Flags[43].UL = 18;
	Flags[43].VL = 12;
	Flags[44].CountryCode = "cm";
	Flags[44].CountryName = "Cameroon";
	Flags[44].U = 0;
	Flags[44].V = 96;
	Flags[44].UL = 18;
	Flags[44].VL = 12;
	Flags[45].CountryCode = "cn";
	Flags[45].CountryName = "China";
	Flags[45].U = 162;
	Flags[45].V = 0;
	Flags[45].UL = 18;
	Flags[45].VL = 12;
	Flags[46].CountryCode = "co";
	Flags[46].CountryName = "Colombia";
	Flags[46].U = 144;
	Flags[46].V = 12;
	Flags[46].UL = 18;
	Flags[46].VL = 12;
	Flags[47].CountryCode = "cr";
	Flags[47].CountryName = "Costa Rica";
	Flags[47].U = 126;
	Flags[47].V = 24;
	Flags[47].UL = 18;
	Flags[47].VL = 12;
	Flags[48].CountryCode = "cs";
	Flags[48].CountryName = "Former Czechoslovakia";
	Flags[48].U = 108;
	Flags[48].V = 36;
	Flags[48].UL = 18;
	Flags[48].VL = 12;
	Flags[49].CountryCode = "cv";
	Flags[49].CountryName = "Cape Verde";
	Flags[49].U = 72;
	Flags[49].V = 60;
	Flags[49].UL = 18;
	Flags[49].VL = 12;
	Flags[50].CountryCode = "cx";
	Flags[50].CountryName = "Christmas Island";
	Flags[50].U = 54;
	Flags[50].V = 72;
	Flags[50].UL = 18;
	Flags[50].VL = 12;
	Flags[51].CountryCode = "cy";
	Flags[51].CountryName = "Cyprus";
	Flags[51].U = 36;
	Flags[51].V = 84;
	Flags[51].UL = 18;
	Flags[51].VL = 12;
	Flags[52].CountryCode = "cz";
	Flags[52].CountryName = "Czech Republic";
	Flags[52].U = 18;
	Flags[52].V = 96;
	Flags[52].UL = 18;
	Flags[52].VL = 12;
	Flags[53].CountryCode = "de";
	Flags[53].CountryName = "Germany";
	Flags[53].U = 0;
	Flags[53].V = 108;
	Flags[53].UL = 18;
	Flags[53].VL = 12;
	Flags[54].CountryCode = "dj";
	Flags[54].CountryName = "Djibouti";
	Flags[54].U = 180;
	Flags[54].V = 0;
	Flags[54].UL = 18;
	Flags[54].VL = 12;
	Flags[55].CountryCode = "dk";
	Flags[55].CountryName = "Denmark";
	Flags[55].U = 162;
	Flags[55].V = 12;
	Flags[55].UL = 18;
	Flags[55].VL = 12;
	Flags[56].CountryCode = "dm";
	Flags[56].CountryName = "Dominica";
	Flags[56].U = 144;
	Flags[56].V = 24;
	Flags[56].UL = 18;
	Flags[56].VL = 12;
	Flags[57].CountryCode = "do";
	Flags[57].CountryName = "Dominican Republic";
	Flags[57].U = 126;
	Flags[57].V = 36;
	Flags[57].UL = 18;
	Flags[57].VL = 12;
	Flags[58].CountryCode = "dz";
	Flags[58].CountryName = "Algeria";
	Flags[58].U = 108;
	Flags[58].V = 48;
	Flags[58].UL = 18;
	Flags[58].VL = 12;
	Flags[59].CountryCode = "ec";
	Flags[59].CountryName = "Ecuador";
	Flags[59].U = 90;
	Flags[59].V = 60;
	Flags[59].UL = 18;
	Flags[59].VL = 12;
	Flags[60].CountryCode = "ee";
	Flags[60].CountryName = "Estonia";
	Flags[60].U = 72;
	Flags[60].V = 72;
	Flags[60].UL = 18;
	Flags[60].VL = 12;
	Flags[61].CountryCode = "eg";
	Flags[61].CountryName = "Egypt";
	Flags[61].U = 54;
	Flags[61].V = 84;
	Flags[61].UL = 18;
	Flags[61].VL = 12;
	Flags[62].CountryCode = "eh";
	Flags[62].CountryName = "Western Sahara";
	Flags[62].U = 36;
	Flags[62].V = 96;
	Flags[62].UL = 18;
	Flags[62].VL = 12;
	Flags[63].CountryCode = "er";
	Flags[63].CountryName = "Eritrea";
	Flags[63].U = 18;
	Flags[63].V = 108;
	Flags[63].UL = 18;
	Flags[63].VL = 12;
	Flags[64].CountryCode = "es";
	Flags[64].CountryName = "Spain";
	Flags[64].U = 0;
	Flags[64].V = 120;
	Flags[64].UL = 18;
	Flags[64].VL = 12;
	Flags[65].CountryCode = "et";
	Flags[65].CountryName = "Ethiopia";
	Flags[65].U = 198;
	Flags[65].V = 0;
	Flags[65].UL = 18;
	Flags[65].VL = 12;
	Flags[66].CountryCode = "fi";
	Flags[66].CountryName = "Finland";
	Flags[66].U = 180;
	Flags[66].V = 12;
	Flags[66].UL = 18;
	Flags[66].VL = 12;
	Flags[67].CountryCode = "fj";
	Flags[67].CountryName = "Fiji";
	Flags[67].U = 162;
	Flags[67].V = 24;
	Flags[67].UL = 18;
	Flags[67].VL = 12;
	Flags[68].CountryCode = "fk";
	Flags[68].CountryName = "Falkland Islands (Malvinas";
	Flags[68].U = 144;
	Flags[68].V = 36;
	Flags[68].UL = 18;
	Flags[68].VL = 12;
	Flags[69].CountryCode = "fm";
	Flags[69].CountryName = "Micronesia, Federated States of";
	Flags[69].U = 126;
	Flags[69].V = 48;
	Flags[69].UL = 18;
	Flags[69].VL = 12;
	Flags[70].CountryCode = "fo";
	Flags[70].CountryName = "Faroe Islands";
	Flags[70].U = 108;
	Flags[70].V = 60;
	Flags[70].UL = 18;
	Flags[70].VL = 12;
	Flags[71].CountryCode = "fr";
	Flags[71].CountryName = "France";
	Flags[71].U = 90;
	Flags[71].V = 72;
	Flags[71].UL = 18;
	Flags[71].VL = 12;
	Flags[72].CountryCode = "ga";
	Flags[72].CountryName = "Gabon";
	Flags[72].U = 72;
	Flags[72].V = 84;
	Flags[72].UL = 18;
	Flags[72].VL = 12;
	Flags[73].CountryCode = "gd";
	Flags[73].CountryName = "Grenada";
	Flags[73].U = 36;
	Flags[73].V = 108;
	Flags[73].UL = 18;
	Flags[73].VL = 12;
	Flags[74].CountryCode = "ge";
	Flags[74].CountryName = "Georgia";
	Flags[74].U = 18;
	Flags[74].V = 120;
	Flags[74].UL = 18;
	Flags[74].VL = 12;
	Flags[75].CountryCode = "gf";
	Flags[75].CountryName = "French Guiana";
	Flags[75].U = 0;
	Flags[75].V = 132;
	Flags[75].UL = 18;
	Flags[75].VL = 12;
	Flags[76].CountryCode = "gh";
	Flags[76].CountryName = "Ghana";
	Flags[76].U = 216;
	Flags[76].V = 0;
	Flags[76].UL = 18;
	Flags[76].VL = 12;
	Flags[77].CountryCode = "gi";
	Flags[77].CountryName = "Gibraltar";
	Flags[77].U = 198;
	Flags[77].V = 12;
	Flags[77].UL = 18;
	Flags[77].VL = 12;
	Flags[78].CountryCode = "gl";
	Flags[78].CountryName = "Greenland";
	Flags[78].U = 180;
	Flags[78].V = 24;
	Flags[78].UL = 18;
	Flags[78].VL = 12;
	Flags[79].CountryCode = "gm";
	Flags[79].CountryName = "Gambia";
	Flags[79].U = 162;
	Flags[79].V = 36;
	Flags[79].UL = 18;
	Flags[79].VL = 12;
	Flags[80].CountryCode = "gn";
	Flags[80].CountryName = "Guinea";
	Flags[80].U = 144;
	Flags[80].V = 48;
	Flags[80].UL = 18;
	Flags[80].VL = 12;
	Flags[81].CountryCode = "gp";
	Flags[81].CountryName = "Guadeloupe";
	Flags[81].U = 126;
	Flags[81].V = 60;
	Flags[81].UL = 18;
	Flags[81].VL = 12;
	Flags[82].CountryCode = "gq";
	Flags[82].CountryName = "Equatorial Guinea";
	Flags[82].U = 108;
	Flags[82].V = 72;
	Flags[82].UL = 18;
	Flags[82].VL = 12;
	Flags[83].CountryCode = "gr";
	Flags[83].CountryName = "Greece";
	Flags[83].U = 90;
	Flags[83].V = 84;
	Flags[83].UL = 18;
	Flags[83].VL = 12;
	Flags[84].CountryCode = "gs";
	Flags[84].CountryName = "S. Georgia & S. Sandwich Isls.";
	Flags[84].U = 72;
	Flags[84].V = 96;
	Flags[84].UL = 18;
	Flags[84].VL = 12;
	Flags[85].CountryCode = "gt";
	Flags[85].CountryName = "Guatemala";
	Flags[85].U = 54;
	Flags[85].V = 108;
	Flags[85].UL = 18;
	Flags[85].VL = 12;
	Flags[86].CountryCode = "gu";
	Flags[86].CountryName = "Guam";
	Flags[86].U = 36;
	Flags[86].V = 120;
	Flags[86].UL = 18;
	Flags[86].VL = 12;
	Flags[87].CountryCode = "gw";
	Flags[87].CountryName = "Guinea-Bissau";
	Flags[87].U = 18;
	Flags[87].V = 132;
	Flags[87].UL = 18;
	Flags[87].VL = 12;
	Flags[88].CountryCode = "gy";
	Flags[88].CountryName = "Guyana";
	Flags[88].U = 0;
	Flags[88].V = 144;
	Flags[88].UL = 18;
	Flags[88].VL = 12;
	Flags[89].CountryCode = "hk";
	Flags[89].CountryName = "Hong Kong";
	Flags[89].U = 234;
	Flags[89].V = 0;
	Flags[89].UL = 18;
	Flags[89].VL = 12;
	Flags[90].CountryCode = "hm";
	Flags[90].CountryName = "Heard Island and McDonald Islands";
	Flags[90].U = 216;
	Flags[90].V = 12;
	Flags[90].UL = 18;
	Flags[90].VL = 12;
	Flags[91].CountryCode = "hn";
	Flags[91].CountryName = "Honduras";
	Flags[91].U = 198;
	Flags[91].V = 24;
	Flags[91].UL = 18;
	Flags[91].VL = 12;
	Flags[92].CountryCode = "hr";
	Flags[92].CountryName = "Croatia";
	Flags[92].U = 180;
	Flags[92].V = 36;
	Flags[92].UL = 18;
	Flags[92].VL = 12;
	Flags[93].CountryCode = "ht";
	Flags[93].CountryName = "Haiti";
	Flags[93].U = 162;
	Flags[93].V = 48;
	Flags[93].UL = 18;
	Flags[93].VL = 12;
	Flags[94].CountryCode = "hu";
	Flags[94].CountryName = "Hungary";
	Flags[94].U = 144;
	Flags[94].V = 60;
	Flags[94].UL = 18;
	Flags[94].VL = 12;
	Flags[95].CountryCode = "id";
	Flags[95].CountryName = "Indonesia";
	Flags[95].U = 126;
	Flags[95].V = 72;
	Flags[95].UL = 18;
	Flags[95].VL = 12;
	Flags[96].CountryCode = "ie";
	Flags[96].CountryName = "Ireland";
	Flags[96].U = 108;
	Flags[96].V = 84;
	Flags[96].UL = 18;
	Flags[96].VL = 12;
	Flags[97].CountryCode = "il";
	Flags[97].CountryName = "Israel";
	Flags[97].U = 90;
	Flags[97].V = 96;
	Flags[97].UL = 18;
	Flags[97].VL = 12;
	Flags[98].CountryCode = "in";
	Flags[98].CountryName = "India";
	Flags[98].U = 72;
	Flags[98].V = 108;
	Flags[98].UL = 18;
	Flags[98].VL = 12;
	Flags[99].CountryCode = "io";
	Flags[99].CountryName = "British Indian Ocean Territory";
	Flags[99].U = 54;
	Flags[99].V = 120;
	Flags[99].UL = 18;
	Flags[99].VL = 12;
	Flags[100].CountryCode = "iq";
	Flags[100].CountryName = "Iraq";
	Flags[100].U = 36;
	Flags[100].V = 132;
	Flags[100].UL = 18;
	Flags[100].VL = 12;
	Flags[101].CountryCode = "is";
	Flags[101].CountryName = "Iceland";
	Flags[101].U = 0;
	Flags[101].V = 156;
	Flags[101].UL = 18;
	Flags[101].VL = 12;
	Flags[102].CountryCode = "it";
	Flags[102].CountryName = "Italy";
	Flags[102].U = 234;
	Flags[102].V = 12;
	Flags[102].UL = 18;
	Flags[102].VL = 12;
	Flags[103].CountryCode = "jm";
	Flags[103].CountryName = "Jamaica";
	Flags[103].U = 216;
	Flags[103].V = 24;
	Flags[103].UL = 18;
	Flags[103].VL = 12;
	Flags[104].CountryCode = "jo";
	Flags[104].CountryName = "Jordan";
	Flags[104].U = 198;
	Flags[104].V = 36;
	Flags[104].UL = 18;
	Flags[104].VL = 12;
	Flags[105].CountryCode = "jp";
	Flags[105].CountryName = "Japan";
	Flags[105].U = 180;
	Flags[105].V = 48;
	Flags[105].UL = 18;
	Flags[105].VL = 12;
	Flags[106].CountryCode = "ke";
	Flags[106].CountryName = "Kenya";
	Flags[106].U = 162;
	Flags[106].V = 60;
	Flags[106].UL = 18;
	Flags[106].VL = 12;
	Flags[107].CountryCode = "kg";
	Flags[107].CountryName = "Kyrgyzstan";
	Flags[107].U = 144;
	Flags[107].V = 72;
	Flags[107].UL = 18;
	Flags[107].VL = 12;
	Flags[108].CountryCode = "kh";
	Flags[108].CountryName = "Cambodia";
	Flags[108].U = 126;
	Flags[108].V = 84;
	Flags[108].UL = 18;
	Flags[108].VL = 12;
	Flags[109].CountryCode = "ki";
	Flags[109].CountryName = "Kiribati";
	Flags[109].U = 108;
	Flags[109].V = 96;
	Flags[109].UL = 18;
	Flags[109].VL = 12;
	Flags[110].CountryCode = "km";
	Flags[110].CountryName = "Comoros";
	Flags[110].U = 90;
	Flags[110].V = 108;
	Flags[110].UL = 18;
	Flags[110].VL = 12;
	Flags[111].CountryCode = "kn";
	Flags[111].CountryName = "Saint Kitts and Nevis";
	Flags[111].U = 72;
	Flags[111].V = 120;
	Flags[111].UL = 18;
	Flags[111].VL = 12;
	Flags[112].CountryCode = "kr";
	Flags[112].CountryName = "Korea, Republic of";
	Flags[112].U = 36;
	Flags[112].V = 144;
	Flags[112].UL = 18;
	Flags[112].VL = 12;
	Flags[113].CountryCode = "kw";
	Flags[113].CountryName = "Kuwait";
	Flags[113].U = 18;
	Flags[113].V = 156;
	Flags[113].UL = 18;
	Flags[113].VL = 12;
	Flags[114].CountryCode = "ky";
	Flags[114].CountryName = "Cayman Islands";
	Flags[114].U = 0;
	Flags[114].V = 168;
	Flags[114].UL = 18;
	Flags[114].VL = 12;
	Flags[115].CountryCode = "kz";
	Flags[115].CountryName = "Kazakstan";
	Flags[115].U = 234;
	Flags[115].V = 24;
	Flags[115].UL = 18;
	Flags[115].VL = 12;
	Flags[116].CountryCode = "la";
	Flags[116].CountryName = "Lao People's Democratic Republic";
	Flags[116].U = 216;
	Flags[116].V = 36;
	Flags[116].UL = 18;
	Flags[116].VL = 12;
	Flags[117].CountryCode = "lb";
	Flags[117].CountryName = "Lebanon";
	Flags[117].U = 198;
	Flags[117].V = 48;
	Flags[117].UL = 18;
	Flags[117].VL = 12;
	Flags[118].CountryCode = "lc";
	Flags[118].CountryName = "Saint Lucia";
	Flags[118].U = 180;
	Flags[118].V = 60;
	Flags[118].UL = 18;
	Flags[118].VL = 12;
	Flags[119].CountryCode = "li";
	Flags[119].CountryName = "Liechtenstein";
	Flags[119].U = 162;
	Flags[119].V = 72;
	Flags[119].UL = 18;
	Flags[119].VL = 12;
	Flags[120].CountryCode = "lk";
	Flags[120].CountryName = "Sri Lanka";
	Flags[120].U = 144;
	Flags[120].V = 84;
	Flags[120].UL = 18;
	Flags[120].VL = 12;
	Flags[121].CountryCode = "lr";
	Flags[121].CountryName = "Liberia";
	Flags[121].U = 126;
	Flags[121].V = 96;
	Flags[121].UL = 18;
	Flags[121].VL = 12;
	Flags[122].CountryCode = "ls";
	Flags[122].CountryName = "Lesotho";
	Flags[122].U = 108;
	Flags[122].V = 108;
	Flags[122].UL = 18;
	Flags[122].VL = 12;
	Flags[123].CountryCode = "lt";
	Flags[123].CountryName = "Lithuania";
	Flags[123].U = 90;
	Flags[123].V = 120;
	Flags[123].UL = 18;
	Flags[123].VL = 12;
	Flags[124].CountryCode = "lu";
	Flags[124].CountryName = "Luxembourg";
	Flags[124].U = 72;
	Flags[124].V = 132;
	Flags[124].UL = 18;
	Flags[124].VL = 12;
	Flags[125].CountryCode = "lv";
	Flags[125].CountryName = "Latvia";
	Flags[125].U = 54;
	Flags[125].V = 144;
	Flags[125].UL = 18;
	Flags[125].VL = 12;
	Flags[126].CountryCode = "ma";
	Flags[126].CountryName = "Morocco";
	Flags[126].U = 18;
	Flags[126].V = 168;
	Flags[126].UL = 18;
	Flags[126].VL = 12;
	Flags[127].CountryCode = "mc";
	Flags[127].CountryName = "Monaco";
	Flags[127].U = 0;
	Flags[127].V = 180;
	Flags[127].UL = 18;
	Flags[127].VL = 12;
	Flags[128].CountryCode = "md";
	Flags[128].CountryName = "Moldova, Republic of";
	Flags[128].U = 234;
	Flags[128].V = 36;
	Flags[128].UL = 18;
	Flags[128].VL = 12;
	Flags[129].CountryCode = "mg";
	Flags[129].CountryName = "Madagascar";
	Flags[129].U = 216;
	Flags[129].V = 48;
	Flags[129].UL = 18;
	Flags[129].VL = 12;
	Flags[130].CountryCode = "mh";
	Flags[130].CountryName = "Marshall Islands";
	Flags[130].U = 198;
	Flags[130].V = 60;
	Flags[130].UL = 18;
	Flags[130].VL = 12;
	Flags[131].CountryCode = "mk";
	Flags[131].CountryName = "Macedonia";
	Flags[131].U = 180;
	Flags[131].V = 72;
	Flags[131].UL = 18;
	Flags[131].VL = 12;
	Flags[132].CountryCode = "ml";
	Flags[132].CountryName = "Mali";
	Flags[132].U = 162;
	Flags[132].V = 84;
	Flags[132].UL = 18;
	Flags[132].VL = 12;
	Flags[133].CountryCode = "mm";
	Flags[133].CountryName = "Myanmar";
	Flags[133].U = 144;
	Flags[133].V = 96;
	Flags[133].UL = 18;
	Flags[133].VL = 12;
	Flags[134].CountryCode = "mn";
	Flags[134].CountryName = "Mongolia";
	Flags[134].U = 126;
	Flags[134].V = 108;
	Flags[134].UL = 18;
	Flags[134].VL = 12;
	Flags[135].CountryCode = "mo";
	Flags[135].CountryName = "Macau";
	Flags[135].U = 108;
	Flags[135].V = 120;
	Flags[135].UL = 18;
	Flags[135].VL = 12;
	Flags[136].CountryCode = "mp";
	Flags[136].CountryName = "Northern Mariana Islands";
	Flags[136].U = 90;
	Flags[136].V = 132;
	Flags[136].UL = 18;
	Flags[136].VL = 12;
	Flags[137].CountryCode = "mq";
	Flags[137].CountryName = "Martinique";
	Flags[137].U = 72;
	Flags[137].V = 144;
	Flags[137].UL = 18;
	Flags[137].VL = 12;
	Flags[138].CountryCode = "mr";
	Flags[138].CountryName = "Mauritania";
	Flags[138].U = 54;
	Flags[138].V = 156;
	Flags[138].UL = 18;
	Flags[138].VL = 12;
	Flags[139].CountryCode = "ms";
	Flags[139].CountryName = "Montserrat";
	Flags[139].U = 36;
	Flags[139].V = 168;
	Flags[139].UL = 18;
	Flags[139].VL = 12;
	Flags[140].CountryCode = "mt";
	Flags[140].CountryName = "Malta";
	Flags[140].U = 18;
	Flags[140].V = 180;
	Flags[140].UL = 18;
	Flags[140].VL = 12;
	Flags[141].CountryCode = "mu";
	Flags[141].CountryName = "Mauritius";
	Flags[141].U = 0;
	Flags[141].V = 192;
	Flags[141].UL = 18;
	Flags[141].VL = 12;
	Flags[142].CountryCode = "mv";
	Flags[142].CountryName = "Maldives";
	Flags[142].U = 234;
	Flags[142].V = 48;
	Flags[142].UL = 18;
	Flags[142].VL = 12;
	Flags[143].CountryCode = "mw";
	Flags[143].CountryName = "Malawi";
	Flags[143].U = 216;
	Flags[143].V = 60;
	Flags[143].UL = 18;
	Flags[143].VL = 12;
	Flags[144].CountryCode = "mx";
	Flags[144].CountryName = "Mexico";
	Flags[144].U = 198;
	Flags[144].V = 72;
	Flags[144].UL = 18;
	Flags[144].VL = 12;
	Flags[145].CountryCode = "my";
	Flags[145].CountryName = "Malaysia";
	Flags[145].U = 180;
	Flags[145].V = 84;
	Flags[145].UL = 18;
	Flags[145].VL = 12;
	Flags[146].CountryCode = "mz";
	Flags[146].CountryName = "Mozambique";
	Flags[146].U = 162;
	Flags[146].V = 96;
	Flags[146].UL = 18;
	Flags[146].VL = 12;
	Flags[147].CountryCode = "na";
	Flags[147].CountryName = "Namibia";
	Flags[147].U = 144;
	Flags[147].V = 108;
	Flags[147].UL = 18;
	Flags[147].VL = 12;
	Flags[148].CountryCode = "nc";
	Flags[148].CountryName = "New Caledonia";
	Flags[148].U = 126;
	Flags[148].V = 120;
	Flags[148].UL = 18;
	Flags[148].VL = 12;
	Flags[149].CountryCode = "ne";
	Flags[149].CountryName = "Niger";
	Flags[149].U = 108;
	Flags[149].V = 132;
	Flags[149].UL = 18;
	Flags[149].VL = 12;
	Flags[150].CountryCode = "nf";
	Flags[150].CountryName = "Norfolk Island";
	Flags[150].U = 90;
	Flags[150].V = 144;
	Flags[150].UL = 18;
	Flags[150].VL = 12;
	Flags[151].CountryCode = "ng";
	Flags[151].CountryName = "Nigeria";
	Flags[151].U = 72;
	Flags[151].V = 156;
	Flags[151].UL = 18;
	Flags[151].VL = 12;
	Flags[152].CountryCode = "ni";
	Flags[152].CountryName = "Nicaragua";
	Flags[152].U = 54;
	Flags[152].V = 168;
	Flags[152].UL = 18;
	Flags[152].VL = 12;
	Flags[153].CountryCode = "nl";
	Flags[153].CountryName = "Netherlands";
	Flags[153].U = 36;
	Flags[153].V = 180;
	Flags[153].UL = 18;
	Flags[153].VL = 12;
	Flags[154].CountryCode = "no";
	Flags[154].CountryName = "Norway";
	Flags[154].U = 18;
	Flags[154].V = 192;
	Flags[154].UL = 18;
	Flags[154].VL = 12;
	Flags[155].CountryCode = "np";
	Flags[155].CountryName = "Nepal";
	Flags[155].U = 0;
	Flags[155].V = 204;
	Flags[155].UL = 18;
	Flags[155].VL = 12;
	Flags[156].CountryCode = "nr";
	Flags[156].CountryName = "Nauru";
	Flags[156].U = 234;
	Flags[156].V = 60;
	Flags[156].UL = 18;
	Flags[156].VL = 12;
	Flags[157].CountryCode = "nu";
	Flags[157].CountryName = "Niue";
	Flags[157].U = 216;
	Flags[157].V = 72;
	Flags[157].UL = 18;
	Flags[157].VL = 12;
	Flags[158].CountryCode = "nz";
	Flags[158].CountryName = "New Zealand";
	Flags[158].U = 198;
	Flags[158].V = 84;
	Flags[158].UL = 18;
	Flags[158].VL = 12;
	Flags[159].CountryCode = "om";
	Flags[159].CountryName = "Oman";
	Flags[159].U = 180;
	Flags[159].V = 96;
	Flags[159].UL = 18;
	Flags[159].VL = 12;
	Flags[160].CountryCode = "pa";
	Flags[160].CountryName = "Panama";
	Flags[160].U = 162;
	Flags[160].V = 108;
	Flags[160].UL = 18;
	Flags[160].VL = 12;
	Flags[161].CountryCode = "pe";
	Flags[161].CountryName = "Peru";
	Flags[161].U = 144;
	Flags[161].V = 120;
	Flags[161].UL = 18;
	Flags[161].VL = 12;
	Flags[162].CountryCode = "pf";
	Flags[162].CountryName = "French Polynesia";
	Flags[162].U = 126;
	Flags[162].V = 132;
	Flags[162].UL = 18;
	Flags[162].VL = 12;
	Flags[163].CountryCode = "pg";
	Flags[163].CountryName = "Papua New Guinea";
	Flags[163].U = 108;
	Flags[163].V = 144;
	Flags[163].UL = 18;
	Flags[163].VL = 12;
	Flags[164].CountryCode = "ph";
	Flags[164].CountryName = "Philippines";
	Flags[164].U = 90;
	Flags[164].V = 156;
	Flags[164].UL = 18;
	Flags[164].VL = 12;
	Flags[165].CountryCode = "pk";
	Flags[165].CountryName = "Pakistan";
	Flags[165].U = 72;
	Flags[165].V = 168;
	Flags[165].UL = 18;
	Flags[165].VL = 12;
	Flags[166].CountryCode = "pl";
	Flags[166].CountryName = "Poland";
	Flags[166].U = 54;
	Flags[166].V = 180;
	Flags[166].UL = 18;
	Flags[166].VL = 12;
	Flags[167].CountryCode = "pm";
	Flags[167].CountryName = "Saint Pierre and Miquelon";
	Flags[167].U = 36;
	Flags[167].V = 192;
	Flags[167].UL = 18;
	Flags[167].VL = 12;
	Flags[168].CountryCode = "pn";
	Flags[168].CountryName = "Pitcairn Island";
	Flags[168].U = 18;
	Flags[168].V = 204;
	Flags[168].UL = 18;
	Flags[168].VL = 12;
	Flags[169].CountryCode = "pr";
	Flags[169].CountryName = "Puerto Rico";
	Flags[169].U = 0;
	Flags[169].V = 216;
	Flags[169].UL = 18;
	Flags[169].VL = 12;
	Flags[170].CountryCode = "ps";
	Flags[170].CountryName = "Palestinian Territory, Occupied";
	Flags[170].U = 234;
	Flags[170].V = 72;
	Flags[170].UL = 18;
	Flags[170].VL = 12;
	Flags[171].CountryCode = "pt";
	Flags[171].CountryName = "Portugal";
	Flags[171].U = 216;
	Flags[171].V = 84;
	Flags[171].UL = 18;
	Flags[171].VL = 12;
	Flags[172].CountryCode = "pw";
	Flags[172].CountryName = "Palau";
	Flags[172].U = 198;
	Flags[172].V = 96;
	Flags[172].UL = 18;
	Flags[172].VL = 12;
	Flags[173].CountryCode = "py";
	Flags[173].CountryName = "Paraguay";
	Flags[173].U = 180;
	Flags[173].V = 108;
	Flags[173].UL = 18;
	Flags[173].VL = 12;
	Flags[174].CountryCode = "qa";
	Flags[174].CountryName = "Qatar";
	Flags[174].U = 162;
	Flags[174].V = 120;
	Flags[174].UL = 18;
	Flags[174].VL = 12;
	Flags[175].CountryCode = "re";
	Flags[175].CountryName = "Reunion";
	Flags[175].U = 144;
	Flags[175].V = 132;
	Flags[175].UL = 18;
	Flags[175].VL = 12;
	Flags[176].CountryCode = "ro";
	Flags[176].CountryName = "Romania";
	Flags[176].U = 126;
	Flags[176].V = 144;
	Flags[176].UL = 18;
	Flags[176].VL = 12;
	Flags[177].CountryCode = "ru";
	Flags[177].CountryName = "Russian Federation";
	Flags[177].U = 108;
	Flags[177].V = 156;
	Flags[177].UL = 18;
	Flags[177].VL = 12;
	Flags[178].CountryCode = "rw";
	Flags[178].CountryName = "Rwanda";
	Flags[178].U = 90;
	Flags[178].V = 168;
	Flags[178].UL = 18;
	Flags[178].VL = 12;
	Flags[179].CountryCode = "sa";
	Flags[179].CountryName = "Saudi Arabia";
	Flags[179].U = 72;
	Flags[179].V = 180;
	Flags[179].UL = 18;
	Flags[179].VL = 12;
	Flags[180].CountryCode = "sb";
	Flags[180].CountryName = "Solomon Islands";
	Flags[180].U = 54;
	Flags[180].V = 192;
	Flags[180].UL = 18;
	Flags[180].VL = 12;
	Flags[181].CountryCode = "sc";
	Flags[181].CountryName = "Seychelles";
	Flags[181].U = 36;
	Flags[181].V = 204;
	Flags[181].UL = 18;
	Flags[181].VL = 12;
	Flags[182].CountryCode = "se";
	Flags[182].CountryName = "Sweden";
	Flags[182].U = 0;
	Flags[182].V = 228;
	Flags[182].UL = 18;
	Flags[182].VL = 12;
	Flags[183].CountryCode = "sg";
	Flags[183].CountryName = "Singapore";
	Flags[183].U = 234;
	Flags[183].V = 84;
	Flags[183].UL = 18;
	Flags[183].VL = 12;
	Flags[184].CountryCode = "sh";
	Flags[184].CountryName = "Saint Helena";
	Flags[184].U = 216;
	Flags[184].V = 96;
	Flags[184].UL = 18;
	Flags[184].VL = 12;
	Flags[185].CountryCode = "si";
	Flags[185].CountryName = "Slovenia";
	Flags[185].U = 198;
	Flags[185].V = 108;
	Flags[185].UL = 18;
	Flags[185].VL = 12;
	Flags[186].CountryCode = "sj";
	Flags[186].CountryName = "Svalbard and Jan Mayen Islands";
	Flags[186].U = 180;
	Flags[186].V = 120;
	Flags[186].UL = 18;
	Flags[186].VL = 12;
	Flags[187].CountryCode = "sk";
	Flags[187].CountryName = "Slovakia";
	Flags[187].U = 162;
	Flags[187].V = 132;
	Flags[187].UL = 18;
	Flags[187].VL = 12;
	Flags[188].CountryCode = "sl";
	Flags[188].CountryName = "Sierra Leone";
	Flags[188].U = 144;
	Flags[188].V = 144;
	Flags[188].UL = 18;
	Flags[188].VL = 12;
	Flags[189].CountryCode = "sm";
	Flags[189].CountryName = "San Marino";
	Flags[189].U = 126;
	Flags[189].V = 156;
	Flags[189].UL = 18;
	Flags[189].VL = 12;
	Flags[190].CountryCode = "sn";
	Flags[190].CountryName = "Senegal";
	Flags[190].U = 108;
	Flags[190].V = 168;
	Flags[190].UL = 18;
	Flags[190].VL = 12;
	Flags[191].CountryCode = "so";
	Flags[191].CountryName = "Somalia";
	Flags[191].U = 90;
	Flags[191].V = 180;
	Flags[191].UL = 18;
	Flags[191].VL = 12;
	Flags[192].CountryCode = "sr";
	Flags[192].CountryName = "Suriname";
	Flags[192].U = 72;
	Flags[192].V = 192;
	Flags[192].UL = 18;
	Flags[192].VL = 12;
	Flags[193].CountryCode = "st";
	Flags[193].CountryName = "Sao Tome and Principe";
	Flags[193].U = 54;
	Flags[193].V = 204;
	Flags[193].UL = 18;
	Flags[193].VL = 12;
	Flags[194].CountryCode = "sv";
	Flags[194].CountryName = "El Salvador";
	Flags[194].U = 36;
	Flags[194].V = 216;
	Flags[194].UL = 18;
	Flags[194].VL = 12;
	Flags[195].CountryCode = "sz";
	Flags[195].CountryName = "Swaziland";
	Flags[195].U = 0;
	Flags[195].V = 240;
	Flags[195].UL = 18;
	Flags[195].VL = 12;
	Flags[196].CountryCode = "tc";
	Flags[196].CountryName = "Turks and Caicos Islands";
	Flags[196].U = 234;
	Flags[196].V = 96;
	Flags[196].UL = 18;
	Flags[196].VL = 12;
	Flags[197].CountryCode = "td";
	Flags[197].CountryName = "Chad";
	Flags[197].U = 216;
	Flags[197].V = 108;
	Flags[197].UL = 18;
	Flags[197].VL = 12;
	Flags[198].CountryCode = "tf";
	Flags[198].CountryName = "French Southern Territories";
	Flags[198].U = 198;
	Flags[198].V = 120;
	Flags[198].UL = 18;
	Flags[198].VL = 12;
	Flags[199].CountryCode = "tg";
	Flags[199].CountryName = "Togo";
	Flags[199].U = 180;
	Flags[199].V = 132;
	Flags[199].UL = 18;
	Flags[199].VL = 12;
	Flags[200].CountryCode = "th";
	Flags[200].CountryName = "Thailand";
	Flags[200].U = 162;
	Flags[200].V = 144;
	Flags[200].UL = 18;
	Flags[200].VL = 12;
	Flags[201].CountryCode = "tj";
	Flags[201].CountryName = "Tajikistan";
	Flags[201].U = 144;
	Flags[201].V = 156;
	Flags[201].UL = 18;
	Flags[201].VL = 12;
	Flags[202].CountryCode = "tk";
	Flags[202].CountryName = "Tokelau";
	Flags[202].U = 126;
	Flags[202].V = 168;
	Flags[202].UL = 18;
	Flags[202].VL = 12;
	Flags[203].CountryCode = "tl";
	Flags[203].CountryName = "East Timor";
	Flags[203].U = 108;
	Flags[203].V = 180;
	Flags[203].UL = 18;
	Flags[203].VL = 12;
	Flags[204].CountryCode = "tm";
	Flags[204].CountryName = "Turkmenistan";
	Flags[204].U = 90;
	Flags[204].V = 192;
	Flags[204].UL = 18;
	Flags[204].VL = 12;
	Flags[205].CountryCode = "tn";
	Flags[205].CountryName = "Tunisia";
	Flags[205].U = 72;
	Flags[205].V = 204;
	Flags[205].UL = 18;
	Flags[205].VL = 12;
	Flags[206].CountryCode = "to";
	Flags[206].CountryName = "Tonga";
	Flags[206].U = 54;
	Flags[206].V = 216;
	Flags[206].UL = 18;
	Flags[206].VL = 12;
	Flags[207].CountryCode = "tr";
	Flags[207].CountryName = "Turkey";
	Flags[207].U = 36;
	Flags[207].V = 228;
	Flags[207].UL = 18;
	Flags[207].VL = 12;
	Flags[208].CountryCode = "tt";
	Flags[208].CountryName = "Trinidad and Tobago";
	Flags[208].U = 18;
	Flags[208].V = 240;
	Flags[208].UL = 18;
	Flags[208].VL = 12;
	Flags[209].CountryCode = "tv";
	Flags[209].CountryName = "Tuvalu";
	Flags[209].U = 234;
	Flags[209].V = 108;
	Flags[209].UL = 18;
	Flags[209].VL = 12;
	Flags[210].CountryCode = "tw";
	Flags[210].CountryName = "Taiwan";
	Flags[210].U = 216;
	Flags[210].V = 120;
	Flags[210].UL = 18;
	Flags[210].VL = 12;
	Flags[211].CountryCode = "tz";
	Flags[211].CountryName = "Tanzania, United Republic of";
	Flags[211].U = 198;
	Flags[211].V = 132;
	Flags[211].UL = 18;
	Flags[211].VL = 12;
	Flags[212].CountryCode = "ua";
	Flags[212].CountryName = "Ukraine";
	Flags[212].U = 180;
	Flags[212].V = 144;
	Flags[212].UL = 18;
	Flags[212].VL = 12;
	Flags[213].CountryCode = "ug";
	Flags[213].CountryName = "Uganda";
	Flags[213].U = 162;
	Flags[213].V = 156;
	Flags[213].UL = 18;
	Flags[213].VL = 12;
	Flags[214].CountryCode = "gb";
	Flags[214].CountryName = "United Kingdom";
	Flags[214].U = 54;
	Flags[214].V = 96;
	Flags[214].UL = 18;
	Flags[214].VL = 12;
	Flags[215].CountryCode = "um";
	Flags[215].CountryName = "United States Minor Outlying Islands";
	Flags[215].U = 144;
	Flags[215].V = 168;
	Flags[215].UL = 18;
	Flags[215].VL = 12;
	Flags[216].CountryCode = "us";
	Flags[216].CountryName = "United States";
	Flags[216].U = 126;
	Flags[216].V = 180;
	Flags[216].UL = 18;
	Flags[216].VL = 12;
	Flags[217].CountryCode = "uy";
	Flags[217].CountryName = "Uruguay";
	Flags[217].U = 108;
	Flags[217].V = 192;
	Flags[217].UL = 18;
	Flags[217].VL = 12;
	Flags[218].CountryCode = "uz";
	Flags[218].CountryName = "Uzbekistan";
	Flags[218].U = 90;
	Flags[218].V = 204;
	Flags[218].UL = 18;
	Flags[218].VL = 12;
	Flags[219].CountryCode = "va";
	Flags[219].CountryName = "Holy See (Vatican City State";
	Flags[219].U = 72;
	Flags[219].V = 216;
	Flags[219].UL = 18;
	Flags[219].VL = 12;
	Flags[220].CountryCode = "vc";
	Flags[220].CountryName = "Saint Vincent and the Grenadines";
	Flags[220].U = 54;
	Flags[220].V = 228;
	Flags[220].UL = 18;
	Flags[220].VL = 12;
	Flags[221].CountryCode = "ve";
	Flags[221].CountryName = "Venezuela";
	Flags[221].U = 36;
	Flags[221].V = 240;
	Flags[221].UL = 18;
	Flags[221].VL = 12;
	Flags[222].CountryCode = "vg";
	Flags[222].CountryName = "Virgin Islands, British";
	Flags[222].U = 234;
	Flags[222].V = 120;
	Flags[222].UL = 18;
	Flags[222].VL = 12;
	Flags[223].CountryCode = "vi";
	Flags[223].CountryName = "Virgin Islands, U.S.";
	Flags[223].U = 216;
	Flags[223].V = 132;
	Flags[223].UL = 18;
	Flags[223].VL = 12;
	Flags[224].CountryCode = "vn";
	Flags[224].CountryName = "Vietnam";
	Flags[224].U = 198;
	Flags[224].V = 144;
	Flags[224].UL = 18;
	Flags[224].VL = 12;
	Flags[225].CountryCode = "vu";
	Flags[225].CountryName = "Vanuatu";
	Flags[225].U = 180;
	Flags[225].V = 156;
	Flags[225].UL = 18;
	Flags[225].VL = 12;
	Flags[226].CountryCode = "wf";
	Flags[226].CountryName = "Wallis and Futuna";
	Flags[226].U = 162;
	Flags[226].V = 168;
	Flags[226].UL = 18;
	Flags[226].VL = 12;
	Flags[227].CountryCode = "ws";
	Flags[227].CountryName = "Samoa";
	Flags[227].U = 144;
	Flags[227].V = 180;
	Flags[227].UL = 18;
	Flags[227].VL = 12;
	Flags[228].CountryCode = "ye";
	Flags[228].CountryName = "Yemen";
	Flags[228].U = 126;
	Flags[228].V = 192;
	Flags[228].UL = 18;
	Flags[228].VL = 12;
	Flags[229].CountryCode = "yt";
	Flags[229].CountryName = "Mayotte";
	Flags[229].U = 108;
	Flags[229].V = 204;
	Flags[229].UL = 18;
	Flags[229].VL = 12;
	Flags[230].CountryCode = "yu";
	Flags[230].CountryName = "Yugoslavia";
	Flags[230].U = 90;
	Flags[230].V = 216;
	Flags[230].UL = 18;
	Flags[230].VL = 12;

	Flags[231] = { "za", "South Africa", 72, 228,  18, 12 };
	Flags[232] = { "zm", "Zambia", 54, 240, 18, 12 };
	Flags[233] = { "zw", "Zimbabwe", 234, 132, 18, 12 };

}


int32 UCountryFlags::NumFlags()
{
	return Flags.Num();
}
//native Function GetRenderData(out Object.FloatBox RenderData, string CountryName);
void UCountryFlags::GetRenderData(FFloatBox& RenderData, FString CountryName)
{

}
FString UCountryFlags::testonly_GetCountryName(int32 Index)
{
	return Flags[Index].CountryName;
}