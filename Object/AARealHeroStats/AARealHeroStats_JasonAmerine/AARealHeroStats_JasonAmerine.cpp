// All the original content belonged to the US Army


#include "AA29/Object/AARealHeroStats/AARealHeroStats_JasonAmerine/AARealHeroStats_JasonAmerine.h"

UAARealHeroStats_JasonAmerine::UAARealHeroStats_JasonAmerine()
{
	Headshot = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Photo_Amerine_Mat.T_UI_RecordBrief_Photo_Amerine_Mat'"), NULL, LOAD_None, NULL);
	ShortName = "amerine";
	HeroName = "Jason Amerine";
	rank = "Major (O-4)";
	HeroNameAndRank = "MAJ Jason Amerine";
	BioParagraphs = { "" };

	ClassAUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Amerine_ClassA_Mat.T_UI_RecordBrief_Uniform_Amerine_ClassA_Mat'"), NULL, LOAD_None, NULL);
	ClassABadges = {
		{"Ribbons|(Jason Amerine)", 0.465, 0.6, 0.459, 0.518 },
		{"Special Forces Combat Patch", 0.086, 0.146, 0.438, 0.55},
		{"U.S. Military Academy (West Point) Patch", 0.643, 0.699, 0.467, 0.539},
		{"Rank Major", 0.144, 0.17, 0.386, 0.406},
		{"Rank Major", 0.615, 0.64, 0.393, 0.412},
		{"Special Forces Unassigned Flash<Green Beret>", 0.4, 0.453, 0.078, 0.14},
		{"", 0, 0, 0, 0},
		{"", 0, 0, 0, 0},
		{"Special Forces Officer Insignia", 0.287, 0.326, 0.403, 0.429},
		{"Special Forces Officer Insignia", 0.457, 0.496, 0.402, 0.429},
		{"<Amerine Jump Wings>", 0.188, 0.287, 0.465, 0.498},
		{"Combat Infantry Badge", 0.52, 0.601, 0.42, 0.449},
		{"Parachutist- Senior Badge", 0.447, 0.484, 0.533, 0.56},
		{"Military Freefall Parachutist Badge", 0.496, 0.554, 0.533, 0.566},
		{"Air Assault Badge", 0.559, 0.603, 0.539, 0.564},
		{"Presidential Unit Citation", 0.191, 0.238, 0.504, 0.523},
		{"Joint Meritorious Citation<2 Oak>", 0.238, 0.286, 0.504, 0.523},
		{"1st Special Forces Regimental Crest", 0.223, 0.25, 0.426, 0.457},
		{"U.S. Military Academy (West Point) Crest", 0.184, 0.209, 0.377, 0.396},
		{"U.S. Military Academy (West Point) Crest", 0.576, 0.601, 0.381, 0.402}
	};
	ACUUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Amerine_ACU_Mat.T_UI_RecordBrief_Uniform_Amerine_ACU_Mat'"), NULL, LOAD_None, NULL);
	ACUBadges = {
		{"Special Forces Combat Patch<ACU>",				0.047,	0.093, 0.592,	0.675	},
		{"Special Forces Combat Patch<ACU>",				0.093,	0.132, 0.607,	0.663	},
		{"U.S. Military Academy (West Point) Patch<ACU>",	0.637,	0.716,	0.602,	0.671	},
		{"",												0,		0,		0,		0		},
		{"Rank Major<ACU>",									0.365,	0.403,	0.652,	0.691	},
		{"Special Forces Unassigned Flash<Green Beret>",	0.402,	0.451,	0.078,	0.14	},
		{"Combat Infantry Badge<ACU>",						0.47,	0.55,	0.421,	0.449	},
		{"Parachutist- Senior Badge<ACU>",					0.469,	0.535,	0.455,	0.498	},
		{"Air Assault Badge<ACU>",							0.475,	0.536,	0.5,	0.529	},
		{"American Flag Patch",								0.084,	0.115,	0.533,	0.583	},
		{"American Flag Patch",								0.115,	0.163,	0.547,	0.597	}
	};
	RibbonRows = {
		{"Bronze Star (VALOR)", "Purple Heart", "" },
		{"Meritorious Service", "Army Commendation (2 OAK)", "Army Achievement (1 OAK)" },
		{"National Defense Service (STAR)", "Global War on Terror Expeditionary", "Global War on Terror Service" },
		{"Afghanistan Campaign (ARROW)", "Korean Defense Service", "Southwest Asia Service" },
		{"Humanitarian Service", "Army Service", "Overseas Service (TWO)" }
	};
}

