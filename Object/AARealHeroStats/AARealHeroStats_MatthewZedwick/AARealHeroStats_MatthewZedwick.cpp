// All the original content belonged to the US Army


#include "AA29/Object/AARealHeroStats/AARealHeroStats_MatthewZedwick/AARealHeroStats_MatthewZedwick.h"

UAARealHeroStats_MatthewZedwick::UAARealHeroStats_MatthewZedwick()
{
	Headshot = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Photo_Zedwick_Mat.T_UI_RecordBrief_Photo_Zedwick_Mat'"), NULL, LOAD_None, NULL);
	ShortName = "zedwick";
	HeroName = "Matthew Zedwick";
	rank = "Staff Sergeant (E-6)";
	HeroNameAndRank = "SSG Matthew Zedwick";
	BioParagraphs = { "" };
	ClassAUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Zedwick_ClassA_Mat.T_UI_RecordBrief_Uniform_Zedwick_ClassA_Mat'"), NULL, LOAD_None, NULL);

	ClassABadges = {
		{"Ribbons|{Matthew Zedwick};", 0.465, 0.6, 0.459, 0.518},
		{"Rank Staff Sergeant", 0.664, 0.738, 0.605, 0.728},
		{"Rank Staff Sergeant", 0.051, 0.125, 0.604, 0.728},
		{"Service Stripes {2};", 0.686, 0.735, 0.898, 0.955},
		{"Overseas Service Bars {2};", 0.043, 0.096, 0.939, 0.97},
		{"1st Cavalry Combat Patch", 0.08, 0.153, 0.454, 0.563},
		{"Infantry Blue Shoulder Cord", 0.166, 0.201, 0.413, 0.5},
		{"Infantry Blue Shoulder Cord", 0.154, 0.177, 0.5, 0.58},
		{"41st Oregon National Guard Patch", 0.635, 0.696, 0.433, 0.482},
		{"Combat Infantry Badge", 0.52, 0.603, 0.418, 0.451},
		{"Expert Marksman Badge", 0.514, 0.544, 0.522, 0.57},
		{"Infantry Branch Insignia", 0.289, 0.318, 0.404, 0.433},
		{"Infantry Branch Insignia", 0.465, 0.494, 0.404, 0.435},
		{"41st Oregon National Guard Crest", 0.223, 0.253, 0.445, 0.48},
		{"41st Oregon National Guard Crest<Green>", 0.594, 0.619, 0.387, 0.408},
		{"41st Oregon National Guard Crest<Green>", 0.174, 0.199, 0.377, 0.396},
		{"41st Oregon National Guard Flash<Black Beret>", 0.398, 0.451, 0.078, 0.144},
		{"Presidential Unit Citation", 0.189, 0.238, 0.504, 0.523},
		{"Army Superior Unit Award|{Reserves};<National Guard>", 0.238, 0.286, 0.504, 0.523},
	};

	ACUUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Zedwick_ACU_Mat.T_UI_RecordBrief_Uniform_Zedwick_ACU_Mat'"), NULL, LOAD_None, NULL);

	ACUBadges = {
		{"1st Cavalry Combat Patch<ACU>", 0.047, 0.103, 0.596, 0.701},
		{"1st Cavalry Combat Patch<ACU>", 0.103, 0.132, 0.605, 0.667},
		{"Rank Staff Sergeant<ACU>", 0.371, 0.398, 0.655, 0.693},
		{"", 0, 0, 0, 0},
		{"Combat Infantry Badge<ACU>", 0.469, 0.548, 0.483, 0.512},
		{"41st Oregon National Guard Patch<ACU>", 0.646, 0.704, 0.586, 0.65},
		{"41st Oregon National Guard Flash<Black Beret>", 0.398, 0.451, 0.079, 0.145},
		{"American Flag Patch", 0.083, 0.113, 0.532, 0.585},
		{"American Flag Patch", 0.113, 0.16, 0.542, 0.594}
	};
	RibbonRows = {
		{"Silver Star", "Purple Heart", ""},
		{"Army Commendation {VALOR, 1 OAK},", "Army Achievement {1 OAK},", "Army Good Conduct"},
		{"Army Reserve Components Achievement", "National Defense Service", "Global War on Terror Expeditionary"},
		{"Global War on Terror Service", "NCO Professional Development", "Army Service"},
		{"Overseas Service", "Reserve Components Overseas Training {TWO},", "State Emergency {2 OAK},"}
	};
}

