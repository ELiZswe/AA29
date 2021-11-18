// All the original content belonged to the US Army


#include "AA29/Object/AARealHeroStats/AARealHeroStats_GeraldWolford/AARealHeroStats_GeraldWolford.h"
UAARealHeroStats_GeraldWolford::UAARealHeroStats_GeraldWolford()
{
	Headshot = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Photo_Wolford_Mat.T_UI_RecordBrief_Photo_Wolford_Mat'"), NULL, LOAD_None, NULL);
	ShortName = "wolford";
	HeroName = "Gerald Wolford";
	rank = "Sergeant First Class (E-7)";
	HeroNameAndRank = "SFC Gerald Wolford";
	BioParagraphs = { "" };
	ClassAUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Wolford_ClassA_Mat.T_UI_RecordBrief_Uniform_Wolford_ClassA_Mat'"), NULL, LOAD_None, NULL);

	ClassABadges = {
		{ "Ribbons|(Gerald Wolford)", 0.475, 0.6, 0.461, 0.515 },
		{ "Rank Sergeant First Class", 0.051, 0.126, 0.602, 0.73 },
		{ "Rank Sergeant First Class", 0.658, 0.734, 0.598, 0.732 },
		{ "Overseas Service Bars (2)", 0.043, 0.097, 0.936, 0.974 },
		{ "Service Stripes (3)", 0.686, 0.736, 0.875, 0.958 },
		{ "82nd Airborne Combat Patch", 0.086, 0.14, 0.428, 0.536 },
		{ "82nd Airborne Patch", 0.635, 0.703, 0.433, 0.538 },
		{ "Infantry Branch Insignia", 0.29, 0.318, 0.404, 0.433 },
		{ "Infantry Branch Insignia", 0.465, 0.494, 0.406, 0.435 },
		{ "Combat Infantry Badge", 0.52, 0.603, 0.418, 0.45 },
		{ "Australian Jump Wings", 0.199, 0.275, 0.467, 0.498 },
		{ "Presidential Unit Citation<1 Oak>", 0.191, 0.237, 0.504, 0.521 },
		{ "Army Superior Unit Award", 0.237,0.287, 0.504, 0.521 },
		{ "Parachutist- Senior Badge<325th Airborne>", 0.436, 0.5, 0.525, 0.566 },
		{ "Air Assault Badge", 0.504, 0.55, 0.535, 0.56 },
		{ "Expert Marksman Badge", 0.563, 0.597, 0.537, 0.591 },
		{ "325th Airborne Unit Crest", 0.227, 0.246, 0.426, 0.455 },
		{ "325th Airborne Unit Crest", 0.176, 0.203, 0.375, 0.392 },
		{ "325th Airborne Unit Crest", 0.592, 0.621, 0.388, 0.406 },
		{ "325th Airborne Flash<Red Beret>", 0.402, 0.451, 0.082, 0.142 },
		{ "Infantry Blue Shoulder Cord", 0.172, 0.197, 0.396, 0.501 },
		{ "Infantry Blue Shoulder Cord", 0.156, 0.177, 0.501, 0.58 }
	};
	ACUUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Wolford_ACU_Mat.T_UI_RecordBrief_Uniform_Wolford_ACU_Mat'"), NULL, LOAD_None, NULL);
	ACUBadges = {
		{ "82nd Airborne Combat Patch<ACU>", 0.035, 0.107, 0.592, 0.695 },
		{ "82nd Airborne Combat Patch<ACU>", 0.107, 0.132, 0.602, 0.673 },
		{ "82nd Airborne Patch<ACU>", 0.666, 0.72, 0.593, 0.697 },
		{ "82nd Airborne Patch<ACU>", 0.634, 0.666, 0.597, 0.673 },
		{ "Rank Sergeant First Class<ACU>", 0.371, 0.4, 0.655, 0.693 },
		{ "Combat Infantry Badge<ACU>", 0.479, 0.535, 0.422, 0.451 },
		{ "Parachutist- Senior Badge<ACU>", 0.482, 0.542, 0.455, 0.498 },
		{ "Air Assault Badge<ACU>", 0.475, 0.537, 0.5, 0.527 },
		{ "325th Airborne Flash<Red Beret>", 0.403, 0.452, 0.08, 0.142 },
		{ "American Flag Patch", 0.084, 0.117, 0.533, 0.585 },
		{ "American Flag Patch", 0.117, 0.162, 0.545, 0.598 }
	};
	RibbonRows = {
		{ "Silver Star", "Purple Heart", "Army Commendation (3 OAK)" },
		{ "Army Achievement (3 OAK)", "Army Good Conduct (2 OAK)", "National Defense Service (1 OAK)" },
		{ "Armed Forces Expeditionary", "Iraq Campaign", "Global War on Terror Expeditionary" },
		{ "Global War on Terror Service", "Armed Forces Service", "NCO Professional Development (3)" },
		{ "Army Service", "United Nations Haiti", "Multinational Force & Observers" }
	};
}
