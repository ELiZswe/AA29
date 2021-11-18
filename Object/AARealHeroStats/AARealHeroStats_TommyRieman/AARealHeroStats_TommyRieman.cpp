// All the original content belonged to the US Army


#include "AA29/Object/AARealHeroStats/AARealHeroStats_TommyRieman/AARealHeroStats_TommyRieman.h"

UAARealHeroStats_TommyRieman::UAARealHeroStats_TommyRieman()
{
	Headshot = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Photo_Rieman_Mat.T_UI_RecordBrief_Photo_Rieman_Mat'"), NULL, LOAD_None, NULL);
	ShortName = "rieman";
	HeroName = "Tommy Rieman";
	rank = "Sergeant (E-5)";
	HeroNameAndRank = "SGT Tommy Rieman";
	MOS = "Infantry (11B)";
	Unit = "B Company, 3rd Battalion,|           504th Parachute Infantry Regiment";
	Hometown = "Independence, KY";
	Training = "Airborne, Air Assault, PLDC,|           BNOC, ANOC, JumpMaster, LifeSaver";
	BioParagraphs =
	{
	"On Dec. 3, 2003, 35 Iraqi insurgents ambushed U.S. Army Sgt. Tommy Rieman and his seven-man squad near Abu Ghraib prison, firing AK-47s and rocket-propelled grenades at the team's unarmored humvees. Rieman returned fire as his driver sped out of the kill zone. Away from the ambush, the squad started to assess their injuries only to come under another attack by 15 fighters. Taking cover behind his humvee, Rieman launched grenades and emptied his magazine clip. When the firefight ended, Rieman called in a medevac helicopter. One squad member lost a leg to an enemy grenade; another had been shot in his buttocks. Rieman himself took bullets in the arm and the chest and shrapnel in his chest, head, and legs. But the ambush had been repelled, and a total of 35 insurgents had been killed in the two engagements. To the Army, Rieman's actions embodied the warrior ethos of a true hero: accomplish the mission, save your soldiers, and kill the enemy.",
	"Rieman was in charge during the patrol that garnered him the Silver Star because he had scouted the area before and knew the terrain. His eight-man patrol was in three light-skinned Humvees with no doors when the first rocket-propelled grenade hit.",
	"'The thing I remember most was the sound of the explosion. It was so loud,' said Rieman. They were hit by three RPGs and a barrage of small arms fire coming from 10 dug-in enemy fighting positions. Staying in the kill zone meant certain death, so the vehicles never stopped moving. Rieman knew he had to return fire. Bullets whizzed after them as the vehicles sped away from the ambush and the soldiers found themselves caught in another ambush.",
	"There were maybe 50 enemy attackers blasting away at him with small arms fire from a grove of palm trees nearby. Injuries to his men were beginning to pile up. Out of his squad, Sgt. Bruce Robinson had lost his right leg in the RPG attack and Spc. Robert Macallister had been shot in the buttocks. Rieman himself had been shot in the right arm and chest, and had shrapnel wounds to his chest, stomach and ear. Worst of all, they were almost out of ammo. He began firing away with his M203 grenade launcher, raining round after round down on the attackers. After being battered by 15 of Rieman’s 40mm grenades, the enemy’s guns were silent."
	};
		
	ClassAUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Rieman_ClassA_Mat.T_UI_RecordBrief_Uniform_Rieman_ClassA_Mat'"), NULL, LOAD_None, NULL);

	ClassABadges = {
	{"Ribbons|{Tommy Rieman},", 0.466,0.601, 0.459, 0.517},
	{"Rank Sergeant", 0.666,0.734, 0.598, 0.701},
	{"Rank Sergeant", 0.063,0.126, 0.598, 0.695},
	{"Service Stripes {2},", 0.688,0.732, 0.898, 0.953},
	{"Overseas Service Bars {2},", 0.043,0.097, 0.94, 0.97},
	{"Combat Infantry Badge", 0.52,0.603, 0.418, 0.449},
	{"Parachutist- Basic Badge", 0.459,0.505, 0.539, 0.566},
	{"Infantry Branch Insignia", 0.29,0.318, 0.404, 0.433},
	{"Infantry Branch Insignia", 0.465,0.494, 0.406, 0.435},
	{"Expert Marksman Badge", 0.557,0.591, 0.535, 0.589},
	{"Pentagon Staff Patch", 0.631,0.701, 0.447, 0.544},
	{"Eco 51st Airborne Combat Patch", 0.08,0.142, 0.432, 0.537},
	{"Eco 51st Airborne Unit Crest", 0.232,0.25, 0.43, 0.451},
	{"Headquarters Department of the Army Crest", 0.176,0.193, 0.379, 0.396},
	{"Headquarters Department of the Army Crest", 0.59,0.609, 0.389, 0.406},
	{"Headquarters Department of the Army Flash<Black Beret>", 0.4,0.452, 0.08, 0.142},
	{"Belgian Jump Wings", 0.201,0.283, 0.459, 0.486},
	{"Valorous Unit Award", 0.184,0.222, 0.508, 0.527},
	{"Army Superior Unit Award", 0.267,0.311, 0.508, 0.527},
	{"Meritorious Unit Commendation", 0.222,0.267, 0.508, 0.527},
	{"Presidential Unit Citation", 0.222,0.267, 0.492, 0.508},
	{"Infantry Blue Shoulder Cord", 0.172,0.2, 0.397, 0.507},
	{"Infantry Blue Shoulder Cord", 0.154,0.181, 0.507, 0.582},
	{"Army Staff Badge", 0.207,0.25, 0.619, 0.664}
	};
	ACUUniform = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/RecordBrief/T_UI_RecordBrief_Uniform_Rieman_ACU_Mat.T_UI_RecordBrief_Uniform_Rieman_ACU_Mat'"), NULL, LOAD_None, NULL);

	ACUBadges = {
		{"Combat Infantry Badge<ACU>", 0.469,0.55, 0.443, 0.47},
		{"Parachutist- Basic Badge<ACU>", 0.475,0.535, 0.486, 0.517},
		{"Eco 51st Airborne Combat Patch<ACU>", 0.053,0.095, 0.596, 0.697},
		{"Eco 51st Airborne Combat Patch<ACU>", 0.095,0.126, 0.607, 0.664},
		{"Rank Sergeant<ACU>", 0.365,0.4, 0.653, 0.692},
		{"Headquarters Department of the Army Flash<Black Beret>", 0.401,0.453, 0.078, 0.141},
		{"Pentagon Staff Patch<ACU>", 0.643,0.716, 0.596, 0.677},
		{"", 0,0, 0, 0},
		{"American Flag Patch", 0.086,0.16, 0.537, 0.592},
		{"American Flag Patch", 0.125,0.15, 0.592, 0.607}
	};
	RibbonRows = {
		{"Silver Star", "Purple Heart", ""},
		{"Army Commendation {VALOR, 1 OAK},", "Army Achievement {1 SILVER OAK},", "Good Conduct {BAR},"},
		{"National Defense Service", "Kosovo Campaign", "Iraq Campaign"},
		{"Global War on Terror Expeditionary", "Global War on Terror Service", "Armed Forces Service"},
		{"Army Service", "Overseas Service", "NATO Kosovo"}
	};
}
