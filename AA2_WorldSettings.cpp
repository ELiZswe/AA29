// All the original content belonged to the US Army

#include "AA2_WorldSettings.h"
#include "AA29/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

void AAA2_WorldSettings::LoadTours()
{
	TourInfo.SetNum(31);
	//***************************************************************
	//* Tour "Basic Training" (0)
	//***************************************************************
	TourInfo[0].Tour				= "Basic Training";
	TourInfo[0].Dependency			= -1;
	TourInfo[0].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_Basic.menu_touricon_Basic'";
	TourInfo[0].TourText			= "bct_tour";
	TourInfo[0].TourTextTitle		= "Basic Combat Training";
	TourInfo[0].TourRolloverText	= "Learn the basics";
	TourInfo[0].HistoryText			= "bct_history";
	TourInfo[0].HistoryTextTitle	= "History of Fort Benning";
	TourInfo[0].IsSequential		= true;
	TourInfo[0].IsTraining			= true;

	TourInfo[0].Mission.SetNum(4);
		//* Tour: "Basic Training" (0) - Mission: "BCT - Basic Rifle Marksmanship" (0);
		TourInfo[0].Mission[0].Title			= "BCT - Basic Rifle Marksmanship";
		TourInfo[0].Mission[0].MBSTitle			= "Basic Rifle Marksmanship";
		TourInfo[0].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_brm_range.map_levelshot_training_brm_range'";
		TourInfo[0].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_brm_range_g.map_levelshot_training_brm_range_g'";
		TourInfo[0].Mission[0].MapFilename		= "BRM_range";
		TourInfo[0].Mission[0].NMLFilename		= "/nml_training/x_training_bct_brm.nml";

		//* Tour: "Basic Training" (0) - Mission: "BCT - Eagle Tower Obstacle Course" (1)
		TourInfo[0].Mission[1].Title			= "BCT - Eagle Tower Obstacle Course";
		TourInfo[0].Mission[1].MBSTitle			= "Eagle Tower";
		TourInfo[0].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_eagle_tower.map_levelshot_training_eagle_tower'";
		TourInfo[0].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_eagle_tower_g.map_levelshot_training_eagle_tower_g'";
		TourInfo[0].Mission[1].MapFilename		= "Eagle_Tower";
		TourInfo[0].Mission[1].NMLFilename		= "/nml_training/x_training_bct_eagle_tower.nml";

		//* Tour: "Basic Training" (0) - Mission: "BCT - U.S. Weapons Familiarization" (2)
		TourInfo[0].Mission[2].Title			= "BCT - U.S. Weapons Familiarization";
		TourInfo[0].Mission[2].MBSTitle			= "Weapons Familiarization";
		TourInfo[0].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_brm_range.map_levelshot_training_brm_range'";
		TourInfo[0].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_brm_range_g.map_levelshot_training_brm_range_g'";
		TourInfo[0].Mission[2].MapFilename		= "Weapons_Fam";
		TourInfo[0].Mission[2].NMLFilename		= "/nml_training/x_training_bct_wpn_fam.nml";

		//* Tour: "Basic Training" (0) - Mission: "BCT - MOUT (Shoot House)" (3)
		TourInfo[0].Mission[3].Title			= "BCT - MOUT (Shoot House)";
		TourInfo[0].Mission[3].MBSTitle			= "MOUT";
		TourInfo[0].Mission[3].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Tactical.Map_levelshot_Tactical'";
		TourInfo[0].Mission[3].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Tactical_g.Map_levelshot_Tactical_g'";
		TourInfo[0].Mission[3].MapFilename		= "ShootHouse";
		TourInfo[0].Mission[3].NMLFilename		= "/nml_training/x_training_bct_shoot_house.nml";



	//***************************************************************
	//* Tour "Infantry Training" (1)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[1].Tour				= "Infantry Training";
	TourInfo[1].Dependency			= 0;
	TourInfo[1].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_Basic.menu_touricon_Basic'";
	TourInfo[1].TourText			= "infantry_tour";
	TourInfo[1].TourTextTitle		= "Infantry Training";
	TourInfo[1].TourRolloverText	= "Infantry Training";
	TourInfo[1].HistoryText			= "infantry_history";
	TourInfo[1].HistoryTextTitle	= "History of the Infantry Training Brigade";
	TourInfo[1].IsSequential		= false;
	TourInfo[1].IsTraining			= false;

	TourInfo[1].Mission.SetNum(1);
		//* Tour: "Infantry Training" (1) - Mission: "Inf Training - MOUT McKenna" (0)
		TourInfo[1].Mission[0].Title			= "Inf Training - MOUT McKenna";
		TourInfo[1].Mission[0].MBSTitle			= "MOUT McKenna";
		TourInfo[1].Mission[0].Image			= "T_AA2_Maps.LevelShots.Map_levelshot_Mout_McKenna";
		TourInfo[1].Mission[0].ImageDisabled	= "T_AA2_Maps.LevelShots.Map_levelshot_Mout_McKenna_g";
		TourInfo[1].Mission[0].MapFilename		= "mout_mckenna";
		TourInfo[1].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_mout_mckenna.nml";


	//***************************************************************
	//* Tour "172nd Sep. Infantry BDE" (2)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[2].Tour				= "172nd Sep.Infantry BDE";
	TourInfo[2].Dependency			= 0;
	TourInfo[2].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_172nd.menu_touricon_172nd'";
	TourInfo[2].TourText			= "mission_tour";
	TourInfo[2].TourTextTitle		= "172nd Sep.Infantry BDE";
	TourInfo[2].TourRolloverText	= "172nd Sep.Infantry BDE";
	TourInfo[2].HistoryText			= "172_history";
	TourInfo[2].HistoryTextTitle	= "History of the 172nd Sep.Infantry BDE";
	TourInfo[2].IsSequential		= false;
	TourInfo[2].IsTraining			= false;

	TourInfo[2].Mission.SetNum(8);
		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Pipeline" (0)
		TourInfo[2].Mission[0].Title		= "172nd Inf - Pipeline";
		TourInfo[2].Mission[0].MBSTitle		= "Pipeline";
		TourInfo[2].Mission[0].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Pipeline.Map_levelshot_Pipeline'";
		TourInfo[2].Mission[0].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Pipeline_g.Map_levelshot_Pipeline_g'";
		TourInfo[2].Mission[0].MapFilename	= "pipeline";
		TourInfo[2].Mission[0].NMLFilename	= "/nml_deploy/x_deploy_pipeline.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Bridge Crossing" (1)
		TourInfo[2].Mission[1].Title		= "172nd Inf - Bridge Crossing";
		TourInfo[2].Mission[1].MBSTitle		= "Bridge Crossing";
		TourInfo[2].Mission[1].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Bridge.Map_levelshot_Bridge'";
		TourInfo[2].Mission[1].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Bridge_g.Map_levelshot_Bridge_g'";
		TourInfo[2].Mission[1].MapFilename	= "bridge";
		TourInfo[2].Mission[1].NMLFilename	= "/nml_deploy/x_deploy_bridge_crossing.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Mountain Pass" (2)
		TourInfo[2].Mission[2].Title		= "172nd Inf - Mountain Pass";
		TourInfo[2].Mission[2].MBSTitle		= "Mountain Pass";
		TourInfo[2].Mission[2].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mt_Pass.Map_levelshot_Mt_Pass'";
		TourInfo[2].Mission[2].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mt_Pass_g.Map_levelshot_Mt_Pass_g'";
		TourInfo[2].Mission[2].MapFilename	= "mountain_pass";
		TourInfo[2].Mission[2].NMLFilename	= "/nml_deploy/x_deploy_mountain_pass.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Bridge SE" (3)
		TourInfo[2].Mission[3].Title		= "172nd Inf - Bridge SE";
		TourInfo[2].Mission[3].MBSTitle		= "Bridge SE";
		TourInfo[2].Mission[3].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Bridge_SE.Map_levelshot_Bridge_SE'";
		TourInfo[2].Mission[3].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Bridge_SE_g.Map_levelshot_Bridge_SE_g'";
		TourInfo[2].Mission[3].MapFilename	= "bridge_se";
		TourInfo[2].Mission[3].NMLFilename	= "/nml_deploy/x_deploy_bridge_se.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Mountain Pass SE" (4)
		TourInfo[2].Mission[4].Title		= "172nd Inf - Mountain Pass SE";
		TourInfo[2].Mission[4].MBSTitle		= "Mountain Pass SE";
		TourInfo[2].Mission[4].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mt_Pass_SE.Map_levelshot_Mt_Pass_SE'";
		TourInfo[2].Mission[4].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mt_Pass_SE_g.Map_levelshot_Mt_Pass_SE_g'";
		TourInfo[2].Mission[4].MapFilename	= "mountain_pass_Se";
		TourInfo[2].Mission[4].NMLFilename	= "/nml_deploy/x_deploy_mountain_pass_se.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Urban Assault" (5)
		TourInfo[2].Mission[5].Title		= "172nd Inf - Urban Assault";
		TourInfo[2].Mission[5].MBSTitle		= "Urban Assault";
		TourInfo[2].Mission[5].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_UrbanAssault.Map_levelshot_UrbanAssault'";
		TourInfo[2].Mission[5].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_UrbanAssault_g.Map_levelshot_UrbanAssault_g'";
		TourInfo[2].Mission[5].MapFilename	= "urban_assault";
		TourInfo[2].Mission[5].NMLFilename	= "/nml_deploy/x_deploy_urban_assault.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - Border" (6)
		TourInfo[2].Mission[6].Title		= "172nd Inf - Border";
		TourInfo[2].Mission[6].MBSTitle		= "Border";
		TourInfo[2].Mission[6].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Border.Map_levelshot_Border'";
		TourInfo[2].Mission[6].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Border_g.Map_levelshot_Border_g'";
		TourInfo[2].Mission[6].MapFilename	= "Border";
		TourInfo[2].Mission[6].NMLFilename	= "/nml_deploy/x_deploy_border.nml";

		//* Tour: "172nd Sep. Infantry BDE" (2) - Mission: "172nd Inf - ES2 Bridge" (7)
		TourInfo[2].Mission[7].Title		= "172nd Inf - ES2 Bridge";
		TourInfo[2].Mission[7].MBSTitle		= "ES2 Bridge";
		TourInfo[2].Mission[7].Image		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Bridge.Map_levelshot_Bridge'";
		TourInfo[2].Mission[7].Disabled		= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Bridge_g.Map_levelshot_Bridge_g'";
		TourInfo[2].Mission[7].MapFilename	= "ES2Bridge";
		TourInfo[2].Mission[7].NMLFilename	= "/nml_deploy/x_deploy_ES2_bridge.nml";

	//***************************************************************
	//* Tour "10th Mountain Division" (3)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[3].Tour				= "10th Mountain Division";
	TourInfo[3].Dependency			= 0;
	TourInfo[3].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_10th_mtn.menu_touricon_10th_mtn'";
	TourInfo[3].TourText			= "mission_tour";
	TourInfo[3].TourTextTitle		= "10th Mountain Division";
	TourInfo[3].TourRolloverText	= "10th Mountain Division";
	TourInfo[3].HistoryText			= "10_history";
	TourInfo[3].HistoryTextTitle	= "History of the 10th Mountain Division";
	TourInfo[3].IsSequential		= false;
	TourInfo[3].IsTraining			= false;

	TourInfo[3].Mission.SetNum(4);
		//* Tour: "10th Mountain Division" (3) - Mission: "10th Mountain - Headquarters Raid" (0)
		TourInfo[3].Mission[0].Title			= "10th Mountain - Headquarters Raid";
		TourInfo[3].Mission[0].MBSTitle			= "Headquarters Raid";
		TourInfo[3].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_HQ_Raid.Map_levelshot_HQ_Raid'";
		TourInfo[3].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_HQ_Raid_g.Map_levelshot_HQ_Raid_g'";
		TourInfo[3].Mission[0].MapFilename		= "hq_raid";
		TourInfo[3].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_hq_raid.nml";

		//* Tour: "10th Mountain Division" (3) - Mission: "10th Mountain - Collapsed Tunnel" (1)
		TourInfo[3].Mission[1].Title			= "10th Mountain - Collapsed Tunnel";
		TourInfo[3].Mission[1].MBSTitle			= "Collapsed Tunnel";
		TourInfo[3].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Tunnel.Map_levelshot_Tunnel'";
		TourInfo[3].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Tunnel_g.Map_levelshot_Tunnel_g'";
		TourInfo[3].Mission[1].MapFilename		= "tunnel";
		TourInfo[3].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_tunnel.nml";

		//* Tour: "10th Mountain Division" (3) - Mission: "10th Mountain - Insurgent Camp" (2)
		TourInfo[3].Mission[2].Title			= "10th Mountain - Insurgent Camp";
		TourInfo[3].Mission[2].MBSTitle			= "Insurgent Camp";
		TourInfo[3].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_InsurgentCamp.Map_levelshot_InsurgentCamp'";
		TourInfo[3].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_InsurgentCamp_g.Map_levelshot_InsurgentCamp_g'";
		TourInfo[3].Mission[2].MapFilename		= "insurgent_camp";
		TourInfo[3].Mission[2].NMLFilename		= "/nml_deploy/x_deploy_insurgent_camp.nml";

		//* Tour: "10th Mountain Division" (3) - Mission: "10th Mountain - River Basin" (3)
		TourInfo[3].Mission[3].Title			= "10th Mountain - River Basin";
		TourInfo[3].Mission[3].MBSTitle			= "River Basin";
		TourInfo[3].Mission[3].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_RiverBasin.Map_levelshot_RiverBasin'";
		TourInfo[3].Mission[3].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_RiverBasin_g.Map_levelshot_RiverBasin_g'";
		TourInfo[3].Mission[3].MapFilename		= "river_basin";
		TourInfo[3].Mission[3].NMLFilename		= "/nml_deploy/x_deploy_river_basin.nml";

	//***************************************************************
	//* Tour "Adv. Marksmanship" (4)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[4].Tour				= "Adv.Marksmanship";
	TourInfo[4].Dependency			= 0;
	TourInfo[4].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_Marksmanship.menu_touricon_Marksmanship'";
	TourInfo[4].TourText			= "marksman_tour";
	TourInfo[4].TourTextTitle		= "Advanced Marksmanship School";
	TourInfo[4].TourRolloverText	= "Take the advanced marksman course";
	TourInfo[4].HistoryText			= "marksman_history";
	TourInfo[4].HistoryTextTitle	= "History of Army Advanced Marksmanship School";
	TourInfo[4].IsSequential		= true;
	TourInfo[4].IsTraining			= true;

	TourInfo[4].Mission.SetNum(2);
		//*Tour: "Adv. Marksmanship" (4) - Mission : "Adv. Marksman - M-24 Range" (0)
		TourInfo[4].Mission[0].Title			= "Adv. Marksman - M-24 Range";
		TourInfo[4].Mission[0].MBSTitle			= "M-24 Range";
		TourInfo[4].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_m24.map_levelshot_training_m24'";
		TourInfo[4].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_m24_g.map_levelshot_training_m24_g'";
		TourInfo[4].Mission[0].MapFilename		= "M24_Range";
		TourInfo[4].Mission[0].NMLFilename		= "/nml_training/x_training_sniper_m24.nml";

		//* Tour: "Adv. Marksmanship" (4) - Mission : "Adv. Marksman - M-82 Range" (1)
		TourInfo[4].Mission[1].Title			= "Adv. Marksman - M-82 Range";
		TourInfo[4].Mission[1].MBSTitle			= "M-82 Range";
		TourInfo[4].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_M82.Map_levelshot_M82'";
		TourInfo[4].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_M82_g.Map_levelshot_M82_g'";
		TourInfo[4].Mission[1].MapFilename		= "M82_Range";
		TourInfo[4].Mission[1].NMLFilename		= "/nml_training/x_training_sniper_m82.nml";

	//***************************************************************
	//* Tour "Airborne School" (5)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[5].Tour				= "Airborne School";
	TourInfo[5].Dependency			= 0;
	TourInfo[5].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_AirBorne_school.menu_touricon_AirBorne_school'";
	TourInfo[5].TourText			= "airborne_tour";
	TourInfo[5].TourTextTitle		= "Airborne School";
	TourInfo[5].TourRolloverText	= "Learn what it takes to be Airborne";
	TourInfo[5].HistoryText			= "airborne_history";
	TourInfo[5].HistoryTextTitle	= "History of Army Airborne School";
	TourInfo[5].IsSequential		= true;
	TourInfo[5].IsTraining			= true;

	TourInfo[5].Mission.SetNum(2);

		//* Tour: "Airborne School" (5) - Mission: "Airborne - 250' Tower" (0)
		TourInfo[5].Mission[0].Title			= "Airborne - 250' Tower";
		TourInfo[5].Mission[0].MBSTitle			= "250' Tower";
		TourInfo[5].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_jump_tower.map_levelshot_training_jump_tower'";
		TourInfo[5].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_jump_tower_g.map_levelshot_training_jump_tower_g'";
		TourInfo[5].Mission[0].MapFilename		= "jump_tower";
		TourInfo[5].Mission[0].NMLFilename		= "/nml_training/x_training_airborne_jump_tower.nml";

		//* Tour: "Airborne School" (5) - Mission: "Airborne - Live Jump" (1)
		TourInfo[5].Mission[1].Title			= "Airborne - Live Jump";
		TourInfo[5].Mission[1].MBSTitle			= "Live Jump";
		TourInfo[5].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_live_jump.map_levelshot_training_live_jump'";
		TourInfo[5].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_live_jump_g.map_levelshot_training_live_jump_g'";
		TourInfo[5].Mission[1].MapFilename		= "live_jump";
		TourInfo[5].Mission[1].NMLFilename		= "/nml_training/x_training_airborne_live_jump.nml";

	//* **************************************************************
	//* Tour "82nd Airborne" (6)
	//* Depends on tour : "Airborne School"
	//***************************************************************
	TourInfo[6].Tour				= "82nd Airborne";
	TourInfo[6].Dependency			= 5;
	TourInfo[6].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_82nd.menu_touricon_82nd'";
	TourInfo[6].TourText			= "mission_tour";
	TourInfo[6].TourTextTitle		= "82nd Airborne";
	TourInfo[6].TourRolloverText	= "82nd Airborne";
	TourInfo[6].HistoryText			= "82_history";
	TourInfo[6].HistoryTextTitle	= "History of the 82nd Airborne";
	TourInfo[6].IsSequential		= false;
	TourInfo[6].IsTraining			= false;

	TourInfo[6].Mission.SetNum(2);
		//* Tour: "82nd Airborne" (6) - Mission: "82nd Airborne - FLS Assault" (0)
		TourInfo[6].Mission[0].Title			= "82nd Airborne - FLS Assault";
		TourInfo[6].Mission[0].MBSTitle			= "FLS Assault";
		TourInfo[6].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_FLS.Map_levelshot_FLS'";
		TourInfo[6].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_FLS_g.Map_levelshot_FLS_g'";
		TourInfo[6].Mission[0].MapFilename		= "fls";
		TourInfo[6].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_fls.nml";

		//* Tour: "82nd Airborne" (6) - Mission: "82nd Airborne - JRTC Farm Raid" (1)
		TourInfo[6].Mission[1].Title			= "82nd Airborne - JRTC Farm Raid";
		TourInfo[6].Mission[1].MBSTitle			= "JRTC Farm Raid";
		TourInfo[6].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_JRTC.Map_levelshot_JRTC'";
		TourInfo[6].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_JRTC_g.Map_levelshot_JRTC_g'";
		TourInfo[6].Mission[1].MapFilename		= "jrtc_farm";
		TourInfo[6].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_farm.nml";

	//* **************************************************************
	//* Tour "Ranger School" (7)
	//* Depends on tour : "Airborne School"
	//***************************************************************
	TourInfo[7].Tour				= "Ranger School";
	TourInfo[7].Dependency			= 5;
	TourInfo[7].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_Ranger.menu_touricon_Ranger'";
	TourInfo[7].TourText			= "mission_tour";
	TourInfo[7].TourTextTitle		= "Ranger School";
	TourInfo[7].TourRolloverText	= "Train to be a Ranger";
	TourInfo[7].HistoryText			= "ranger_history";
	TourInfo[7].HistoryTextTitle	= "History of Army Ranger School";
	TourInfo[7].IsSequential		= false;
	TourInfo[7].IsTraining			= false;

	TourInfo[7].Mission.SetNum(2);
		//* Tour: "Ranger School" (7) - Mission: "75th Rangers - Mountain Ambush" (0)
		TourInfo[7].Mission[0].Title			= "75th Rangers - Mountain Ambush";
		TourInfo[7].Mission[0].MBSTitle			= "Mountain Ambush";
		TourInfo[7].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mt_Ambush.Map_levelshot_Mt_Ambush'";
		TourInfo[7].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mt_Ambush_g.Map_levelshot_Mt_Ambush_g'";
		TourInfo[7].Mission[0].MapFilename		= "mountain_ambush";
		TourInfo[7].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_mountain_ambush.nml";

		//* Tour: "Ranger School" (7) - Mission: "75th Rangers - Swamp Raid" (1)
		TourInfo[7].Mission[1].Title			= "75th Rangers - Swamp Raid";
		TourInfo[7].Mission[1].MBSTitle			= "Swamp Raid";
		TourInfo[7].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SwampRaid.Map_levelshot_SwampRaid'";
		TourInfo[7].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SwampRaid_g.Map_levelshot_SwampRaid_g'";
		TourInfo[7].Mission[1].MapFilename		= "swamp_raid";
		TourInfo[7].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_swamp_raid.nml";

	//* **************************************************************
	//* Tour "75th Ranger Regiment" (8)
	//* Depends on tour : "Airborne School"
	//***************************************************************
	TourInfo[8].Tour				= "75th Ranger Regiment";
	TourInfo[8].Dependency			= 5;
	TourInfo[8].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_Ranger_75th.menu_touricon_Ranger_75th'";
	TourInfo[8].TourText			= "mission_tour";
	TourInfo[8].TourTextTitle		= "75th Ranger Regiment";
	TourInfo[8].TourRolloverText	= "75th Ranger Regiment";
	TourInfo[8].HistoryText			= "75_history";
	TourInfo[8].HistoryTextTitle	= "History of the 75th Ranger Regiment";
	TourInfo[8].IsSequential		= false;
	TourInfo[8].IsTraining			= false;

	TourInfo[8].Mission.SetNum(8);

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Weapons Cache" (0)
		TourInfo[8].Mission[0].Title			= "75th Rangers - Weapons Cache";
		TourInfo[8].Mission[0].MBSTitle			= "Weapons Cache";
		TourInfo[8].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_WeaponsCache.Map_levelshot_WeaponsCache'";
		TourInfo[8].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_WeaponsCache_g.Map_levelshot_WeaponsCache_g'";
		TourInfo[8].Mission[0].MapFilename		= "weapons_cache";
		TourInfo[8].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_weapons_cache.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Weapons Cache SE" (1)
		TourInfo[8].Mission[1].Title			= "75th Rangers - Weapons Cache SE";
		TourInfo[8].Mission[1].MBSTitle			= "Weapons Cache SE";
		TourInfo[8].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_WeaponsCache_SE.Map_levelshot_WeaponsCache_SE'";
		TourInfo[8].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_WeaponsCache_SE_g.Map_levelshot_WeaponsCache_SE_g'";
		TourInfo[8].Mission[1].MapFilename		= "weapons_cache_se";
		TourInfo[8].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_weapons_cache_se.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Radio Tower" (2)
		TourInfo[8].Mission[2].Title			= "75th Rangers - Radio Tower";
		TourInfo[8].Mission[2].MBSTitle			= "Radio Tower";
		TourInfo[8].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_RadioTower.Map_levelshot_RadioTower'";
		TourInfo[8].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_RadioTower_g.Map_levelshot_RadioTower_g'";
		TourInfo[8].Mission[2].MapFilename		= "radio_tower";
		TourInfo[8].Mission[2].NMLFilename		= "/nml_deploy/x_deploy_radio_tower.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Woodland Outpost" (3)
		TourInfo[8].Mission[3].Title			= "75th Rangers - Woodland Outpost";
		TourInfo[8].Mission[3].MBSTitle			= "Woodland Outpost";
		TourInfo[8].Mission[3].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_WoodlandOutpost.Map_levelshot_WoodlandOutpost'";
		TourInfo[8].Mission[3].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_WoodlandOutpost_g.Map_levelshot_WoodlandOutpost_g'";
		TourInfo[8].Mission[3].MapFilename		= "woodland_outpost";
		TourInfo[8].Mission[3].NMLFilename		= "/nml_deploy/x_deploy_woodland_outpost.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Dusk" (4)
		TourInfo[8].Mission[4].Title			= "75th Rangers - Dusk";
		TourInfo[8].Mission[4].MBSTitle			= "Dusk";
		TourInfo[8].Mission[4].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Dusk.Map_levelshot_Dusk'";
		TourInfo[8].Mission[4].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Dusk_g.Map_levelshot_Dusk_g'";
		TourInfo[8].Mission[4].MapFilename		= "Dusk";
		TourInfo[8].Mission[4].NMLFilename		= "/nml_deploy/x_deploy_dusk.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Steamroller" (5)
		TourInfo[8].Mission[5].Title			= "75th Rangers - Steamroller";
		TourInfo[8].Mission[5].MBSTitle			= "Steamroller";
		TourInfo[8].Mission[5].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_steamroller.map_levelshot_steamroller'";
		TourInfo[8].Mission[5].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_steamroller_g.map_levelshot_steamroller_g'";
		TourInfo[8].Mission[5].MapFilename		= "Steamroller";
		TourInfo[8].Mission[5].NMLFilename		= "/nml_deploy/x_deploy_steamroller.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Interdiction" (6)
		TourInfo[8].Mission[6].Title			= "75th Rangers - Interdiction";
		TourInfo[8].Mission[6].MBSTitle			= "Interdiction";
		TourInfo[8].Mission[6].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_interdiction.map_levelshot_interdiction'";
		TourInfo[8].Mission[6].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_interdiction_g.map_levelshot_interdiction_g'";
		TourInfo[8].Mission[6].MapFilename		= "Interdiction";
		TourInfo[8].Mission[6].NMLFilename		= "/nml_deploy/x_deploy_interdiction.nml";

		//* Tour: "75th Ranger Regiment" (8) - Mission: "75th Rangers - Rummage" (7)
		TourInfo[8].Mission[7].Title			= "75th Rangers - Rummage";
		TourInfo[8].Mission[7].MBSTitle			= "Rummage";
		TourInfo[8].Mission[7].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_rummage.map_levelshot_training_rummage'";
		TourInfo[8].Mission[7].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_rummage_G.map_levelshot_training_rummage_G'";
		TourInfo[8].Mission[7].MapFilename		= "Rummage";
		TourInfo[8].Mission[7].NMLFilename		= "/nml_deploy/x_deploy_rummage.nml";

	//* **************************************************************
	//* Tour "Medic Training" (9)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[9].Tour				= "Medic Training";
	TourInfo[9].Dependency			= 0;
	TourInfo[9].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_Medic.menu_touricon_Medic'";
	TourInfo[9].TourText			= "medic_tour";
	TourInfo[9].TourTextTitle		= "Medic Training";
	TourInfo[9].TourRolloverText	= "Train to be a Medic";
	TourInfo[9].HistoryText			= "medic_history";
	TourInfo[9].HistoryTextTitle	= "History of the Army Medic";
	TourInfo[9].IsSequential		= true;
	TourInfo[9].IsTraining			= true;

	TourInfo[9].Mission.SetNum(8);
		//* Tour: "Medic Training" (9) - Mission: "Medic - Airway Management" (0)
		TourInfo[9].Mission[0].Title			= "Medic - Airway Management";
		TourInfo[9].Mission[0].MBSTitle			= "Airway Management";
		TourInfo[9].Mission[0].Image			= "T_AA2_Maps.LevelShots.Map_levelshot_training_medic_airway";
		TourInfo[9].Mission[0].ImageDisabled	= "T_AA2_Maps.LevelShots.Map_levelshot_training_medic_airway_g";
		TourInfo[9].Mission[0].MapFilename		= "Medic_Training1";
		TourInfo[9].Mission[0].NMLFilename		= "/nml_training/x_training_medic_1.nml";

		//* Tour: "Medic Training" (9) - Mission: "Medic - Control Bleeding" (1)
		TourInfo[9].Mission[1].Title			= "Medic - Control Bleeding";
		TourInfo[9].Mission[1].MBSTitle			= "Control Bleeding";
		TourInfo[9].Mission[1].Image			= "T_AA2_Maps.LevelShots.Map_levelshot_training_medic_bleeding";
		TourInfo[9].Mission[1].ImageDisabled	= "T_AA2_Maps.LevelShots.Map_levelshot_training_medic_bleeding_g";
		TourInfo[9].Mission[1].MapFilename		= "Medic_Training2";
		TourInfo[9].Mission[1].NMLFilename		= "/nml_training/x_training_medic_2.nml";

		//* Tour: "Medic Training" (9) - Mission: "Medic - Treat Shock" (2)
		TourInfo[9].Mission[2].Title			= "Medic - Treat Shock";
		TourInfo[9].Mission[2].MBSTitle			= "Treat Shock";
		TourInfo[9].Mission[2].Image			= "T_AA2_Maps.LevelShots.Map_levelshot_training_medic_shock";
		TourInfo[9].Mission[2].ImageDisabled	= "T_AA2_Maps.LevelShots.Map_levelshot_training_medic_shock_g";
		TourInfo[9].Mission[2].MapFilename		= "Medic_Training3";
		TourInfo[9].Mission[2].NMLFilename		= "/nml_training/x_training_medic_3.nml";

		//* Tour: "Medic Training" (9) - Mission: "Medic - Field Training" (3)
		TourInfo[9].Mission[3].Title			= "Medic - Field Training";
		TourInfo[9].Mission[3].MBSTitle			= "Field Training";
		TourInfo[9].Mission[3].Image			= "T_AA2_Maps.LevelShots.map_levelshot_training_medic_field";
		TourInfo[9].Mission[3].ImageDisabled	= "T_AA2_Maps.LevelShots.map_levelshot_training_medic_field_g";
		TourInfo[9].Mission[3].MapFilename		= "Medic_Field";
		TourInfo[9].Mission[3].NMLFilename		= "/nml_training/x_training_medic_field.nml";


	//* **************************************************************
	//* Tour "SF Training" (10)
	//* Depends on tour : "Airborne School"
	//***************************************************************
	TourInfo[10].Tour				= "SF Training";
	TourInfo[10].Dependency			= 5;
	TourInfo[10].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_SF.menu_touricon_SF'";
	TourInfo[10].TourText			= "sf_tour";
	TourInfo[10].TourTextTitle		= "SF Training";
	TourInfo[10].TourRolloverText	= "Qualify to be Special Forces";
	TourInfo[10].HistoryText		= "sf_history";
	TourInfo[10].HistoryTextTitle	= "History of the Special Forces";
	TourInfo[10].IsSequential		= true;
	TourInfo[10].IsTraining			= true;

	TourInfo[10].Mission.SetNum(2);

		//* Tour: "SF Training" (10) - Mission: "SF - Camp Mackall Introduction" (0)
		TourInfo[10].Mission[0].Title			= "SF - Camp Mackall Introduction";
		TourInfo[10].Mission[0].MBSTitle		= "Camp Mackall";
		TourInfo[10].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_camp_mackall.map_levelshot_training_camp_mackall'";
		TourInfo[10].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_camp_mackall_g.map_levelshot_training_camp_mackall_g'";
		TourInfo[10].Mission[0].MapFilename		= "camp_mackall";
		TourInfo[10].Mission[0].NMLFilename		= "/nml_training/x_training_sf_camp_mackall.nml";

		//* Tour: "SF Training" (10) - Mission: "SF - Escape and Evade" (1)
		TourInfo[10].Mission[1].Title = "SF - Escape and Evade";
		TourInfo[10].Mission[1].MBSTitle = "Escape and Evade";
		TourInfo[10].Mission[1].Image = "T_AA2_Maps.LevelShots.Map_levelshot_SF_EscapeAndEvade";
		TourInfo[10].Mission[1].ImageDisabled = "T_AA2_Maps.LevelShots.Map_levelshot_SF_EscapeAndEvade_g";
		TourInfo[10].Mission[1].MapFilename = "eande";
		TourInfo[10].Mission[1].NMLFilename = "/nml_training/x_training_sf_escape_evade.nml";

	//* **************************************************************
	//* Tour "Special Forces" (11)
	//* Depends on tour : "Airborne School"
	//***************************************************************
	TourInfo[11].Tour				= "Special Forces";
	TourInfo[11].Dependency			= 5;
	TourInfo[11].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_SF.menu_touricon_SF'";
	TourInfo[11].TourText			= "mission_tour";
	TourInfo[11].TourTextTitle		= "Special Forces";
	TourInfo[11].TourRolloverText	= "Special Forces";
	TourInfo[11].HistoryText		= "sf_history";
	TourInfo[11].HistoryTextTitle	= "History of the Special Forces";
	TourInfo[11].IsSequential		= false;
	TourInfo[11].IsTraining			= false;

	TourInfo[11].Mission.SetNum(13);

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Combat Search & Rescue" (0)
		TourInfo[11].Mission[0].Title			= "Special Forces - Combat Search & Rescue";
		TourInfo[11].Mission[0].MBSTitle		= "SF CSAR";
		TourInfo[11].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_CSAR.Map_levelshot_SF_CSAR'";
		TourInfo[11].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_CSAR_g.Map_levelshot_SF_CSAR_g'";
		TourInfo[11].Mission[0].MapFilename		= "SFcsar";
		TourInfo[11].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_sf_csar.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Hospital Rescue" (1)
		TourInfo[11].Mission[1].Title			= "Special Forces - Hospital Rescue";
		TourInfo[11].Mission[1].MBSTitle		= "SF Hospital";
		TourInfo[11].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_HRescue.Map_levelshot_SF_HRescue'";
		TourInfo[11].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_HRescue_g.Map_levelshot_SF_HRescue_g'";
		TourInfo[11].Mission[1].MapFilename		= "SFhospital";
		TourInfo[11].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_sf_hospital.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Recon" (2)
		TourInfo[11].Mission[2].Title			= "Special Forces - Recon";
		TourInfo[11].Mission[2].MBSTitle		= "SF Recon";
		TourInfo[11].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Recon.Map_levelshot_SF_Recon'";
		TourInfo[11].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Recon_g.Map_levelshot_SF_Recon_g'";
		TourInfo[11].Mission[2].MapFilename		= "SFrecon";
		TourInfo[11].Mission[2].NMLFilename		= "/nml_deploy/x_deploy_sf_recon.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Sandstorm" (3)
		TourInfo[11].Mission[3].Title			= "Special Forces - Sandstorm";
		TourInfo[11].Mission[3].MBSTitle		= "SF Sandstorm";
		TourInfo[11].Mission[3].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Sandstorm.Map_levelshot_SF_Sandstorm'";
		TourInfo[11].Mission[3].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Sandstorm_g.Map_levelshot_SF_Sandstorm_g'";
		TourInfo[11].Mission[3].MapFilename		= "SFsandstorm";
		TourInfo[11].Mission[3].NMLFilename		= "/nml_deploy/x_deploy_sf_sandstorm.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Arctic" (4)
		TourInfo[11].Mission[4].Title			= "Special Forces - Arctic";
		TourInfo[11].Mission[4].MBSTitle		= "SF Arctic";
		TourInfo[11].Mission[4].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Arctic.Map_levelshot_SF_Arctic'";
		TourInfo[11].Mission[4].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Arctic_g.Map_levelshot_SF_Arctic_g'";
		TourInfo[11].Mission[4].MapFilename		= "SFarctic";
		TourInfo[11].Mission[4].NMLFilename		= "/nml_deploy/x_deploy_sf_arctic.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Oasis" (5)
		TourInfo[11].Mission[5].Title			= "Special Forces - Oasis";
		TourInfo[11].Mission[5].MBSTitle		= "SF Oasis";
		TourInfo[11].Mission[5].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Oasis.Map_levelshot_SF_Oasis'";
		TourInfo[11].Mission[5].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Oasis_g.Map_levelshot_SF_Oasis_g'";
		TourInfo[11].Mission[5].MapFilename		= "SFoasis";
		TourInfo[11].Mission[5].NMLFilename		= "/nml_deploy/x_deploy_sf_oasis.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Taiga" (6)
		TourInfo[11].Mission[6].Title			= "Special Forces - Taiga";
		TourInfo[11].Mission[6].MBSTitle		= "SF Taiga";
		TourInfo[11].Mission[6].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Taiga.Map_levelshot_SF_Taiga'";
		TourInfo[11].Mission[6].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Taiga_g.Map_levelshot_SF_Taiga_g'";
		TourInfo[11].Mission[6].MapFilename		= "SFtaiga";
		TourInfo[11].Mission[6].NMLFilename		= "/nml_deploy/x_deploy_sf_taiga.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Village" (7)
		TourInfo[11].Mission[7].Title			= "Special Forces - Village";
		TourInfo[11].Mission[7].MBSTitle		= "SF Village";
		TourInfo[11].Mission[7].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Village.Map_levelshot_SF_Village'";
		TourInfo[11].Mission[7].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Village_g.Map_levelshot_SF_Village_g'";
		TourInfo[11].Mission[7].MapFilename		= "SFvillage";
		TourInfo[11].Mission[7].NMLFilename		= "/nml_deploy/x_deploy_sf_village.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Courtyard" (8)
		TourInfo[11].Mission[8].Title			= "Special Forces - Courtyard";
		TourInfo[11].Mission[8].MBSTitle		= "SF Courtyard";
		TourInfo[11].Mission[8].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Courtyard.Map_levelshot_SF_Courtyard'";
		TourInfo[11].Mission[8].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Courtyard_g.Map_levelshot_SF_Courtyard_g'";
		TourInfo[11].Mission[8].MapFilename		= "SFcourtyard";
		TourInfo[11].Mission[8].NMLFilename		= "/nml_deploy/x_deploy_sf_courtyard.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Precious Cargo Recovery" (9)
		TourInfo[11].Mission[9].Title			= "Special Forces - Precious Cargo Recovery";
		TourInfo[11].Mission[9].MBSTitle		= "SF PCR";
		TourInfo[11].Mission[9].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_PCR.Map_levelshot_SF_PCR'";
		TourInfo[11].Mission[9].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_PCR_g.Map_levelshot_SF_PCR_g'";
		TourInfo[11].Mission[9].MapFilename		= "SFpcr";
		TourInfo[11].Mission[9].NMLFilename	= "/nml_deploy/x_deploy_sf_pcr.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Extraction" (10)
		TourInfo[11].Mission[10].Title			= "Special Forces - Extraction";
		TourInfo[11].Mission[10].MBSTitle		= "SF Extraction";
		TourInfo[11].Mission[10].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Extraction.Map_levelshot_SF_Extraction'";
		TourInfo[11].Mission[10].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Extraction_g.Map_levelshot_SF_Extraction_g'";
		TourInfo[11].Mission[10].MapFilename	= "SFExtraction";
		TourInfo[11].Mission[10].NMLFilename	= "/nml_deploy/x_deploy_sf_extraction.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - Hospital Rescue SE" (11)
		TourInfo[11].Mission[11].Title			= "Special Forces - Hospital Rescue SE";
		TourInfo[11].Mission[11].MBSTitle		= "SF Hospital SE";
		TourInfo[11].Mission[11].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_SFHospitalSe.map_levelshot_training_SFHospitalSe'";
		TourInfo[11].Mission[11].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_SFHospitalSe_G.map_levelshot_training_SFHospitalSe_G'";
		TourInfo[11].Mission[11].MapFilename	= "SFHospitalSE";
		TourInfo[11].Mission[11].NMLFilename	= "/nml_deploy/x_deploy_sf_hospital_se.nml";

		//* Tour: "Special Forces" (11) - Mission: "Special Forces - ES2 Border" (12)
		TourInfo[11].Mission[12].Title			= "Special Forces - ES2 Border";
		TourInfo[11].Mission[12].MBSTitle		= "SF ES2 Border";
		TourInfo[11].Mission[12].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Border.Map_levelshot_Border'";
		TourInfo[11].Mission[12].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Border_g.Map_levelshot_Border_g'";
		TourInfo[11].Mission[12].MapFilename	= "ES2Border";
		TourInfo[11].Mission[12].NMLFilename	= "/nml_deploy/x_deploy_sf_es2_border.nml";

	//* **************************************************************
	//* Tour "SF Exclusive" (12)
	//* Depends on tour : "SF Training"
	//***************************************************************
	TourInfo[12].Tour				= "SF Exclusive";
	TourInfo[12].Dependency			= 10;
	TourInfo[12].Image				= "T_AA2_UI.TourIcons.Menu_TourIcon_SF";
	TourInfo[12].TourText			= "mission_tour";
	TourInfo[12].TourTextTitle		= "Special Forces Exclusive";
	TourInfo[12].TourRolloverText	= "Special Forces Exclusive";
	TourInfo[12].HistoryText		= "sf_history";
	TourInfo[12].HistoryTextTitle	= "History of the Special Forces";
	TourInfo[12].IsSequential		= false;
	TourInfo[12].IsTraining			= false;

	TourInfo[12].Mission.SetNum(5);

		//* Tour: "SF Exclusive" (12) - Mission: "Special Forces - Pipeline" (0)
		TourInfo[12].Mission[0].Title			= "Special Forces - Pipeline";
		TourInfo[12].Mission[0].MBSTitle		= "SF Pipeline";
		TourInfo[12].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_pipeline.Map_levelshot_SF_pipeline'";
		TourInfo[12].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_pipeline_g.Map_levelshot_SF_pipeline_g'";
		TourInfo[12].Mission[0].MapFilename		= "pipeline_sf";
		TourInfo[12].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_sf_pipeline.nml";

		//* Tour: "SF Exclusive" (12) - Mission: "Special Forces - Blizzard" (1)
		TourInfo[12].Mission[1].Title			= "Special Forces - Blizzard";
		TourInfo[12].Mission[1].MBSTitle		= "SF Blizzard";
		TourInfo[12].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Blizzard.Map_levelshot_SF_Blizzard'";
		TourInfo[12].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Blizzard_g.Map_levelshot_SF_Blizzard_g'";
		TourInfo[12].Mission[1].MapFilename		= "SFblizzard";
		TourInfo[12].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_sf_blizzard.nml";

		//* Tour: "SF Exclusive" (12) - Mission: "Special Forces - Water Treatment" (2)
		TourInfo[12].Mission[2].Title			= "Special Forces - Water Treatment";
		TourInfo[12].Mission[2].MBSTitle		= "SF Water Treatment";
		TourInfo[12].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_WaterTreatment.Map_levelshot_SF_WaterTreatment'";
		TourInfo[12].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_WaterTreatment_g.Map_levelshot_SF_WaterTreatment_g'";
		TourInfo[12].Mission[2].MapFilename		= "SFwatertreatment";
		TourInfo[12].Mission[2].NMLFilename		= "/nml_deploy/x_deploy_sf_wtf.nml";

		//* Tour: "SF Exclusive" (12) - Mission: "Special Forces - Dockside" (3)
		TourInfo[12].Mission[3].Title			= "Special Forces - Dockside";
		TourInfo[12].Mission[3].MBSTitle		= "SF Dockside";
		TourInfo[12].Mission[3].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Dockside.Map_levelshot_SF_Dockside'";
		TourInfo[12].Mission[3].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SF_Dockside_g.Map_levelshot_SF_Dockside_g'";
		TourInfo[12].Mission[3].MapFilename		= "SFDockside";
		TourInfo[12].Mission[3].NMLFilename		= "/nml_deploy/x_deploy_sf_dockside.nml";

		//* Tour: "SF Exclusive" (12) - Mission: "Special Forces - Snake Plain" (4)
		TourInfo[12].Mission[4].Title			= "Special Forces - Snake Plain";
		TourInfo[12].Mission[4].MBSTitle		= "SF SnakePlain";
		TourInfo[12].Mission[4].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_sf_snake_plain.map_levelshot_sf_snake_plain'";
		TourInfo[12].Mission[4].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_sf_snake_plain_g.map_levelshot_sf_snake_plain_g'";
		TourInfo[12].Mission[4].MapFilename		= "SFSnakePlain";
		TourInfo[12].Mission[4].NMLFilename		= "/nml_deploy/x_deploy_sf_snakeplain.nml";

	//* **************************************************************
	//* Tour "Advanced Training" (13)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[13].Tour				= "Advanced Training";
	TourInfo[13].Dependency			= 0;
	TourInfo[13].Image				= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/TourIcons/menu_touricon_SF.menu_touricon_SF'";
	TourInfo[13].TourText			= "advanced_tour";
	TourInfo[13].TourTextTitle		= "Advanced Training";
	TourInfo[13].TourRolloverText	= "Advanced Training";
	TourInfo[13].HistoryText		= "advanced_training";
	TourInfo[13].HistoryTextTitle	= "History of Advanced Training";
	TourInfo[13].IsSequential		= false;
	TourInfo[13].IsTraining			= true;

	TourInfo[13].Mission.SetNum(4);

		//* Tour: "Advanced Training" (13) - Mission: "Advanced - Javelin Training" (0)
		TourInfo[13].Mission[0].Title			= "Advanced - Javelin Training";
		TourInfo[13].Mission[0].MBSTitle		= "Javelin Training";
		TourInfo[13].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_javelin.map_levelshot_training_javelin'";
		TourInfo[13].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_javelin_g.map_levelshot_training_javelin_g'";
		TourInfo[13].Mission[0].MapFilename		= "JavelinTraining";
		TourInfo[13].Mission[0].NMLFilename		= "/nml_training/x_training_advtrn_javelin.nml";

		//* Tour: "Advanced Training" (13) - Mission: "Advanced - HMMWV Driver Training" (1)
		TourInfo[13].Mission[1].Title			= "Advanced - HMMWV Driver Training";
		TourInfo[13].Mission[1].MBSTitle		= "HMMWV Driver Training";
		TourInfo[13].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_driver.map_levelshot_training_driver'";
		TourInfo[13].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_driver_g.map_levelshot_training_driver_g'";
		TourInfo[13].Mission[1].MapFilename		= "Vehicle_Training_Driver";
		TourInfo[13].Mission[1].NMLFilename		= "/nml_training/x_training_advtrn_hmmwv_driving.nml";

		//* Tour: "Advanced Training" (13) - Mission: "Advanced - CROWS Gunnery Training" (2)
		TourInfo[13].Mission[2].Title			= "Advanced - CROWS Gunnery Training";
		TourInfo[13].Mission[2].MBSTitle		= "CROWS Gunnery Training";
		TourInfo[13].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_gunnery.map_levelshot_training_gunnery'";
		TourInfo[13].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/map_levelshot_training_gunnery_g.map_levelshot_training_gunnery_g'";
		TourInfo[13].Mission[2].MapFilename		= "Vehicle_Training_Gunner";
		TourInfo[13].Mission[2].NMLFilename		= "/nml_training/x_training_advtrn_crows_gunnery.nml";

		//* Tour: "Advanced Training" (13) - Mission: "Advanced - ES2 Training" (3)
		TourInfo[13].Mission[3].Title			= "Advanced - ES2 Training";
		TourInfo[13].Mission[3].MBSTitle		= "ES2 Training";
		TourInfo[13].Mission[3].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mout_McKenna.Map_levelshot_Mout_McKenna'";
		TourInfo[13].Mission[3].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_Mout_McKenna_g.Map_levelshot_Mout_McKenna_g'";
		TourInfo[13].Mission[3].MapFilename		= "ES2McKenna";
		TourInfo[13].Mission[3].NMLFilename		= "/nml_training/x_training_advtrn_es2.nml";


	//* **************************************************************
	//* Tour "Official User Created Maps 1" (15)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[15].Tour				= "Official User Created Maps 1";
	TourInfo[15].Dependency			= 0;
	TourInfo[15].Image				= NULL;
	TourInfo[15].TourText			= "mission_tour";
	TourInfo[15].TourTextTitle		= "Official User Created Maps 1";
	TourInfo[15].TourRolloverText	= "Official User Created Maps 1";
	TourInfo[15].HistoryText		= "official_user_maps";
	TourInfo[15].HistoryTextTitle	= "Official User Maps 1 Overview";
	TourInfo[15].IsSequential		= false;
	TourInfo[15].IsTraining			= false;

	TourInfo[15].Mission.SetNum(2);

		//Tour: "Official User Created Maps 1" (15) - Mission : "SMU GH River Village" (0)
		TourInfo[15].Mission[0].Title			= "SMU GH River Village";
		TourInfo[15].Mission[0].MBSTitle		= "SMU GH RiverVillage";
		TourInfo[15].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_RiverVillage.Map_levelshot_RiverVillage'";
		TourInfo[15].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_RiverVillage_g.Map_levelshot_RiverVillage_g'";
		TourInfo[15].Mission[0].MapFilename		= "SMU_GH_RiverVillage";
		TourInfo[15].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_smu_rivervillage.nml";

		//*Tour: "Official User Created Maps 1" (15) - Mission : "Oil Rig" (1)
		TourInfo[15].Mission[1].Title			= "Oil Rig";
		TourInfo[15].Mission[1].MBSTitle		= "Oil Rig";
		TourInfo[15].Mission[1].Image			= "/img_deploy/i_deploy_oilrig";
		TourInfo[15].Mission[1].ImageDisabled	= "/img_deploy/i_deploy_oilrig_g";
		TourInfo[15].Mission[1].MapFilename		= "oil_rig";
		TourInfo[15].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_oilrig.nml";



	//* **************************************************************
	//* Tour "Official User Created Maps 2" (16)
	//* Depends on tour : "Airborne School"
	//***************************************************************
	TourInfo[16].Tour = "Official User Created Maps 2";
	TourInfo[16].Dependency = 5;
	TourInfo[16].Image = NULL;
	TourInfo[16].TourText = "mission_tour";
	TourInfo[16].TourTextTitle = "Official User Created Maps 2";
	TourInfo[16].TourRolloverText = "Official User Created Maps 2";
	TourInfo[16].HistoryText = "official_user_maps";
	TourInfo[16].HistoryTextTitle = "Official User Maps 2 Overview";
	TourInfo[16].IsSequential = false;
	TourInfo[16].IsTraining = false;

	TourInfo[16].Mission.SetNum(4);

		//* Tour: "Official User Created Maps 2" (16) - Mission: "SMU GH SF Refinery" (0)
		TourInfo[16].Mission[0].Title			= "SMU GH SF Refinery";
		TourInfo[16].Mission[0].MBSTitle		= "SMU GH SFRefinery";
		TourInfo[16].Mission[0].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SFRefinery.Map_levelshot_SFRefinery'";
		TourInfo[16].Mission[0].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SFRefinery_g.Map_levelshot_SFRefinery_g'";
		TourInfo[16].Mission[0].MapFilename		= "SMU_GH_SFRefinery";
		TourInfo[16].Mission[0].NMLFilename		= "/nml_deploy/x_deploy_smu_sfrefinery.nml";

		//* Tour: "Official User Created Maps 2" (16) - Mission: "SMU GH SF Old Town" (1)
		TourInfo[16].Mission[1].Title			= "SMU GH SF Old Town";
		TourInfo[16].Mission[1].MBSTitle		= "SMU GH SFOldTown";
		TourInfo[16].Mission[1].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SFOldTown.Map_levelshot_SFOldTown'";
		TourInfo[16].Mission[1].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SFOldTown_g.Map_levelshot_SFOldTown_g'";
		TourInfo[16].Mission[1].MapFilename		= "SMU_GH_SFOldTown";
		TourInfo[16].Mission[1].NMLFilename		= "/nml_deploy/x_deploy_smu_sfoldtown.nml";

		//* Tour: "Official User Created Maps 2" (16) - Mission: "SMU GH SF Floodgate" (2)
		TourInfo[16].Mission[2].Title			= "SMU GH SF Floodgate";
		TourInfo[16].Mission[2].MBSTitle		= "SMU GH SFFloodgate";
		TourInfo[16].Mission[2].Image			= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SFFloodgate.Map_levelshot_SFFloodgate'";
		TourInfo[16].Mission[2].ImageDisabled	= "Texture2D'/Game/AmericasArmy/Textures/T_AA2_Maps/LevelShots/Map_levelshot_SFFloodgate_g.Map_levelshot_SFFloodgate_g'";
		TourInfo[16].Mission[2].MapFilename		= "SMU_GH_SFFloodgate";
		TourInfo[16].Mission[2].NMLFilename		= "/nml_deploy/x_deploy_smu_sffloodgate.nml";

		//* Tour: "Official User Created Maps 2" (16) - Mission: "Operation Shrouded Eagle" (3)
		TourInfo[16].Mission[3].Title			= "Operation Shrouded Eagle";
		TourInfo[16].Mission[3].MBSTitle		= "Operation Shrouded Eagle";
		TourInfo[16].Mission[3].Image			= "/img_deploy/i_deploy_opshroudedeagle";
		TourInfo[16].Mission[3].ImageDisabled	= "/img_deploy/i_deploy_opshroudedeagle_g";
		TourInfo[16].Mission[3].MapFilename		= "operationshroudedeagle";
		TourInfo[16].Mission[3].NMLFilename		= "/nml_deploy/x_deploy_opshroudedeagle.nml";

	//* **************************************************************
	//* Tour "Authorized User Created Maps" (30)
	//* Depends on tour : "Basic Training"
	//***************************************************************
	TourInfo[30].Tour				= "Authorized User Created Maps";
	TourInfo[30].Dependency			= 0;
	TourInfo[30].Image				= NULL;
	TourInfo[30].TourText			= "mission_tour";
	TourInfo[30].TourTextTitle		= "Authorized User Created Maps";
	TourInfo[30].TourRolloverText	= "Authorized User Created Maps";
	TourInfo[30].HistoryText		= "authorized_user_maps";
	TourInfo[30].HistoryTextTitle	= "Authorized User Maps Overview";
	TourInfo[30].IsSequential		= false;
	TourInfo[30].IsTraining			= false;

}

AAA2_WorldSettings::AAA2_WorldSettings()
{

	TimeDilation = 1.1;
	Title = "Untitled";
	Author = "America's Army";
	IdealPlayerCountMin = 6;
	IdealPlayerCountMax = 10;
	RadarMapSize = 10000;
	RadarZoomLevels = { 50 };
	PhysicsDetailLevel = EPhysicsDetailLevel::PDL_Medium;
	MeshLODDetailLevel = EMeshLODDetailLevel::MDL_Medium;
	KarmaTimeScale = 0.9;
	RagdollTimeScale = 1;
	MaxRagdolls = 16;
	KarmaGravScale = 1;
	bKStaticFriction = true;
	DecalStayScale = 1;
	VisibleGroups = "None";
	//DetailMode = EDetailMode::DM_High;
	AnimMeshGlobalLOD = 1;
	MusicVolumeOverride = -1;
	Brightness = 1;
	//	DefaultTexture = Texture'Engine.DefaultTexture';
	//	WireframeTexture = Texture'Engine.WhiteSquareTexture';
	//	WhiteSquareTexture = Texture'Engine.WhiteSquareTexture';
	//	LargeVertex = Texture'Engine.LargeVertex';
	PreCacheGame = "Engine.GameInfo";
	DefaultGravity = -950;
	StallZ = 10000;
	bUseHeadlights = true;
	HeadlightScaling = 1;
	IndoorMeshDrawscale = 1;
	OutdoorMeshDrawscale = 1;
	WaterDustColor = FColor(255, 255, 255, 0);
	MoveRepSize = 42;
	MaxClientFrameRate = 90;
	MaxTimeMargin = 1;
	TimeMarginSlack = 1.35;
	MinTimeMargin = -1;
	SkinSetEnemy = ESkinSet::SKINS_OpFor;
	TeamName = { "ASSAULT",  "DEFENSE" };
	bTeam0HasNVGs = true;
	bTeam1HasNVGs = true;
	bTeam0AllowM203Mod = true;
	bTeam1AllowM203Mod = true;
	Pawn_NV_AmbientGlow = 140;
	JavelinMinRangeDirect = 3000;
	JavelinMinRangeTop = 7500;
	Score_Team0_Win = 50;
	Score_Team0_SquadLeaderBonusPerSurvivor = 10;
	Score_Team0_FTLeaderBonusPerSurvivor = 10;
	Score_Team1_Win = 50;
	Score_Team1_SquadLeaderBonusPerSurvivor = 10;
	Score_Team1_FTLeaderBonusPerSurvivor = 10;
	DecalSession = 1;
	KeepDecals = 100;
	KeepDecoDecals = 10;
	bFadeDecoDecals = true;
	ShadowDetail = EShadowDetail::SHADOW_Blob;

	asETASurNames = { "Adams", "Alexander", "Allen", "Anderson", "Bailey", "Baker", "Barnes", "Bell", "Bennett", "Brooks", "Brown", "Bryant", "Butler", "Campbell", "Carter", "Clark", "Coleman", "Collins", "Cook", "Cooper", "Cox",
						"Davis", "Diaz", "Edwards", "Evans", "Flores", "Foster", "Garcia", "Gonzales", "Gonzalez", "Gray", "Green", "Griffin", "Hall", "Harris", "Hayes", "Henderson", "Hernandez", "Hill", "Howard", "Hughes", "Jackson", "James",
						"Jenkins", "Johnson", "Jones", "Kelly", "King", "Lee", "Lewis", "Long", "Lopez", "Martin", "Martinez", "Miller", "Mitchell", "Moore", "Morgan", "Morris", "Murphy", "Nelson", "Parker", "Patterson", "Perez", "Perry", "Peterson", "Phillips", "Powell",
						"Price", "Ramirez", "Reed", "Richardson", "Rivera", "Roberts", "Robinson", "Rodriguez", "Rogers", "Ross", "Russell", "Sanchez", "Sanders", "Scott", "Simmons", "Smith", "Stewart", "Taylor", "Thomas", "Thompson", "Torres", "Turner", "Walker", "Ward",
						"Washington", "Watson", "White", "Williams", "Wilson", "Wood", "Wright", "Young"
	};
	
	asETANickNames = { "Alpha", "Apollo", "Arrow", "Atlas", "Avenger", "Bear", "Blade", "Blitz", "Boomstick", "Bravo", "Bulldog", "Bullet", "Bullseye", "Camper", "Cash", "Cobra",
						"Crispy", "Critter", "Daredevil", "Delta", "Demo", "Eagle", "Echo", "Ferret", "Flash", "Frago", "GridSquare", "GroundHog", "Gunship", "Hawkeye", "Hero", "Hooah",
						"Hulk", "Iron", "Invincible", "Justice", "Lantern", "Lifer", "Lightning", "Meteor", "Neo", "Nightmare", "Ninja", "November", "Nuke", "Medevac", "Patriot", "Pointer",
						"Rock", "Ricochet", "Sierra", "Smack", "Spider", "Spirit", "Stealth", "Steel", "Stretch", "Surgeon", "Tango", "Thunder", "Torch", "Touchdown", "Tripwire", "Rabbit",
						"Victory", "Warrior", "Weasel", "Whiskey", "Wolf", "Yankee", "Zeus", "Zulu"
	};
	
	asETAFirstNames = { "A.",	"B.",	"C.",	"D.",	"E.",	"F.",	"G.",	"H.",	"I.",	"J.",	"K.",	"L.",	"M.",	"N.",	"O.",	"P.",	"Q.",	"R.",	"S.",	"T.",	"U.",	"V.",	"W.",	"X.",	"Y.",	"Z." };

	TourCategory = "<unknown>";
	IgnoreTours = { 15, 16,30 };
	//bWorldGeometry = true;
	//bAlwaysRelevant = true;
	//RemoteRole = 1;
	//NV_AmbientGlow = 55;
	//bHiddenEd = true;
	LoadTours();

}


void AAA2_WorldSettings::BeginPlay()
{
	//FString Temp;
	//BeginPlay();
	//Temp=GetBaseDir();
	//sMapsDir=Left(Temp,Len(Temp) - 7);
	//sMapsDir=sMapsDir $ "maps\";
	LoadTourInfo();
	//sLevelName=GetLevelNamePrivate();
	//GetLevelTourAndMissionPrivate(sLevelName,iTour,iMission);
	//GetLevelTourCategory(sLevelName,TourCategory);
	//bTourSequential=IsTourSequentialPrivate(iTour);
	SetupProjectileMod();
	PostBeginPlay();
}
void AAA2_WorldSettings::PostBeginPlay()
{

	//PostBeginPlay();
	//DecalStayScale=Math::Max(DecalStayScale,0);
	if (IsMILES())
	{
		SkinSetFriendly = GetMILESSkin(SkinSetFriendly);
		SkinSetEnemy = GetMILESSkin(SkinSetEnemy);
		MeshFriendly = GetMILESMesh(MeshFriendly);
		MeshEnemy = GetMILESMesh(MeshEnemy);
	}
}



bool AAA2_WorldSettings::IsLanOnlyServer()
{
	return false;  //FAKE ELiZ
}
void AAA2_WorldSettings::SetLanOnlyServer()
{
}
void AAA2_WorldSettings::UnsetLanOnlyServer()
{
}
bool AAA2_WorldSettings::IsBetaServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsLeasedServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsOfficialServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsUnofficialServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsNATOServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsTournamentServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsUltimateArenaServer()
{
	return false;  //FAKE ELiZ
}
bool AAA2_WorldSettings::IsAuthorizedServer()
{
	return false;  //FAKE ELiZ
}

//native Function IsExploreTheArmyServer ();
bool AAA2_WorldSettings::IsExploreTheArmyServer()
{
	return false;  //FAKE ELiZ
}

//native Function IsExploreTheArmyAccount (Controller ctrlr, string sUserName, optional bool bTestOnly);
FString AAA2_WorldSettings::IsExploreTheArmyAccount(AController* ctrlr, FString sUserName, bool bTestOnly)
{
	return "PlayerName";     //Fake   /ELiZ
}
bool AAA2_WorldSettings::EnableDebugThis()
{
	return false;
}
void AAA2_WorldSettings::PBNotifyServerTravel()
{
}
void AAA2_WorldSettings::PBIsEnabled()
{
}
void AAA2_WorldSettings::PBEnable()
{
}
void AAA2_WorldSettings::PBDisable()
{
}
void AAA2_WorldSettings::FirstDraw()
{
	/*
		local Actor A;
		ForEach AllActors('Actor',A)
		{
			if (A.IsA('EventLab'))
			{
				A.ActorNotify(Self,22,None,"");
			}
		}
	*/
}
void AAA2_WorldSettings::SetupProjectileMod()
{
	/*
		local AGP_WorldInfo L;
		ForEach AllActors('AGP_WorldInfo',L)
		{
			fProjectileMod=L.fHumidBase - L.fHumidity * L.fHumidFactor + L.fTemperature - L.fTempBase * L.fTempFactor;
		}
	*/
}

float AAA2_WorldSettings::GetProjectileMod()
{
	return fProjectileMod;
}

void AAA2_WorldSettings::AddViewpoint(AAGP_Viewpoint* nextv)
{
	/*
		local AGP_Viewpoint insertv;
		UE_LOG(LogTemp, Warning, TEXT("---------------------------------------------------------------"));
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::AddViewpoint()	Adding " $ nextv @ nextv.iSequence));
		if (ViewpointList == None)
		{
			ViewpointList=nextv;
			nextv.NextViewpoint=None;
		}
		else
		{
			if (nextv.iSequence < ViewpointList.iSequence)
			{
				nextv.NextViewpoint=ViewpointList;
				ViewpointList=nextv;
			}
			else
			{
				insertv=ViewpointList;
				if (insertv.NextViewpoint != None && insertv.NextViewpoint.iSequence < nextv.iSequence)
				{
					insertv=insertv.NextViewpoint;
				}
				if (insertv.NextViewpoint != None)
				{
					nextv.NextViewpoint=insertv.NextViewpoint;
				}
				insertv.NextViewpoint=nextv;
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::AddViewpoint()	------------------------------"));
		insertv=ViewpointList;
		if (insertv != None)
		{
			UE_LOG(LogTemp, Warning, TEXT("LevelInfo::AddViewpoint()	" $ insertv @ insertv.iSequence));
			insertv=insertv.NextViewpoint;
		}
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::AddViewpoint()	------------------------------"));
	*/
}

bool AAA2_WorldSettings::debugThis(EDebugTag Debug)
{
	int32 i;
	if (! EnableDebugThis() && Debug != EDebugTag::DEBUG_Warn && Debug != EDebugTag::DEBUG_Error)
	{
		return false;
	}
	switch (Debug)
	{
	case EDebugTag::DEBUG_Default:
	case EDebugTag::DEBUG_Warn:
	case EDebugTag::DEBUG_Error:
		return false;
	case EDebugTag::DEBUG_Always:
		return !bSilentLog;
	case EDebugTag::DEBUG_Network:
		return GetNetMode() != ENetMode::NM_Standalone;
	case EDebugTag::DEBUG_Server:
		return GetNetMode() == ENetMode::NM_ListenServer || GetNetMode() == ENetMode::NM_DedicatedServer;
	case EDebugTag::DEBUG_Client:
		return GetNetMode() == ENetMode::NM_Client;
	case EDebugTag::DEBUG_Standalone:
		return GetNetMode() == ENetMode::NM_Standalone;
	default:
		i = 0;
		if (i < debug_num)
		{
			if (debugList[i] == Debug)
			{
				return true;
			}
			i++;
			break;
		}
		return false;
	}
	return false;
}
bool AAA2_WorldSettings::addDebug(EDebugTag Debug)
{
	
		int32 i;
		if (Debug <= EDebugTag::DEBUG_Standalone)
		{
			return false;
		}
		for (i=0; i<debug_num; i++)
		{
			if (debugList[i] == Debug)
			{
				return false;
			}
		}
		debugList[debug_num]=Debug;
		debug_num ++;
		return true;
	
}
bool AAA2_WorldSettings::removeDebug(EDebugTag Debug)
{
	int32 i;
	int32 ilocation;
	if (Debug <= EDebugTag::DEBUG_Standalone)
	{
		return false;
	}
	ilocation=-1;
	i=0;
	if (i < debug_num)
	{
		if (debugList[i] == Debug)
		{
			ilocation=i;
		}
		else
		{
			i ++;
		}
	}
	if (ilocation == -1)
	{
		return false;
	}
	debug_num --;
	for (i=ilocation; i<debug_num; i++)
	{
		debugList[i]=debugList[i + 1];
	}
	return true;
}
bool AAA2_WorldSettings::toggleDebug(EDebugTag Debug)
{
	if (addDebug(Debug) == true)
	{
		return true;
	}
	else
	{
		removeDebug(Debug);
		return false;
	}
}
void AAA2_WorldSettings::addPickup(APickup* add_pickup)
{
	/*
		local Pickup last_pickup;
		if (PickupList == None)
		{
			PickupList=add_pickup;
		}
		else
		{
			last_pickup=PickupList;
			if (last_pickup.Next != None)
			{
				if (last_pickup == add_pickup)
				{
					Log("WARNING: LevelInfo::addPickup()	Attempting to add Pickup already in the list " $ add_pickup);
					Return;
				}
				last_pickup=last_pickup.Next;
			}
			last_pickup.Next=add_pickup;
		}
		add_pickup.Next=None;
	*/
}
void AAA2_WorldSettings::removePickup(APickup* remove_pickup)
{
	/*
		local Pickup last_pickup;
		if (PickupList == remove_pickup)
		{
			PickupList=PickupList.Next;
		}
		else
		{
			last_pickup=PickupList;
			if (last_pickup.Next != remove_pickup)
			{
				last_pickup=last_pickup.Next;
				if (last_pickup == None)
				{
					Log("WARNING: LevelInfo::removePickup()	Attempting to remove Pickup not in the list " $ remove_pickup);
					remove_pickup.Next=None;
					Return;
				}
			}
			last_pickup.Next=last_pickup.Next.Next;
		}
		remove_pickup.Next=None;
	*/
}
void AAA2_WorldSettings::LogPickupList(FString printstring)
{
	/*
		local Pickup p;
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::LogPickupList()	====BEGIN LIST==== (" @ printstring @ ")"));
		p=PickupList;
		if (p != None)
		{
			UE_LOG(LogTemp, Warning, TEXT("LevelInfo::LogPickupList()	Pickup(" @ p @ ")"));
			p=p.Next;
		}
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::LogPickupList()	=====END LIST===== (" @ printstring @ ")"));
	*/
}

FString AAA2_WorldSettings::GetDefaultBinoc()
{
	switch (DefaultBinoc)
	{
	case EDefaultBinoc::BINOC_M22:
		return "AGP_Inventory.Item_BinocM22_A";
	case EDefaultBinoc::BINOC_M24:
		return "AGP_Inventory.Item_BinocM24_B";
	case EDefaultBinoc::BINOC_Tank:
		return "AGP_Inventory.Item_BinocTank_B";
	case EDefaultBinoc::BINOC_Newt:
		return "AGP_Inventory.Item_BinocNewt_B";
	case EDefaultBinoc::BINOC_VIPER:
		return "AGP_Inventory.Item_VIPER";
	default:
		return "";
	}
}

ESkinSet AAA2_WorldSettings::GetSkinSet(bool bFriendly)
{
	ESkinSet SkinSet;
	if (bFriendly)
	{
		SkinSet=SkinSetFriendly;
	}
	else
	{
		SkinSet=SkinSetEnemy;
	}
	return SkinSet;
}
EWeaponSkinSet AAA2_WorldSettings::GetWeaponSkinSet(bool bFriendly)
{
	return WeaponSkinSetFriendly;
}
bool AAA2_WorldSettings::IsUSSkin(bool bFriendly)
{
	switch (GetSkinSet(bFriendly))
	{
		case ESkinSet::SKINS_Training:
		case ESkinSet::SKINS_Forest:
		case ESkinSet::SKINS_Desert:
		case ESkinSet::SKINS_Arctic:
		case ESkinSet::SKINS_SF_Arctic:
		case ESkinSet::SKINS_IBCT:
			return true;
		default:
			return false;
	}
}
FString AAA2_WorldSettings::GetSkin_Package()
{
	return "T_AA2_Characters";
}
ESkinSet AAA2_WorldSettings::GetMILESSkin(ESkinSet tSkin)
{
	switch (tSkin)
	{
		case ESkinSet::SKINS_Desert:
			return ESkinSet::SKINS_Desert;
		case ESkinSet::SKINS_Arctic:
		case ESkinSet::SKINS_SF_Arctic:
		case ESkinSet::SKINS_IBCT:
		case ESkinSet::SKINS_Training:
		case ESkinSet::SKINS_Forest:
			return ESkinSet::SKINS_Forest;
		case ESkinSet::SKINS_DesOp:
		case ESkinSet::SKINS_OpFor:
		case ESkinSet::SKINS_ArcOpFor:
		case ESkinSet::SKINS_CivOp:
		case ESkinSet::SKINS_OpInfantry:
			return ESkinSet::SKINS_OpInfantry;
		default:
			return tSkin;
	}
}
EMesh AAA2_WorldSettings::GetMILESMesh(EMesh tMesh)
{
	switch (tMesh)
	{
		case EMesh::MESH_SF:
		case EMesh::MESH_IBCT:
		case EMesh::MESH_Arctic:
		case EMesh::MESH_SF_Arctic:
		case EMesh::MESH_Soldier:
			return EMesh::MESH_Soldier;

		case EMesh::MESH_DesOp:
		case EMesh::MESH_OPFOR:
		case EMesh::MESH_CivOp:
		case EMesh::MESH_OpInfantry:
		case EMesh::MESH_ArcOpFor:
			return EMesh::MESH_OpInfantry;

		default:
			return tMesh;
	}
}
FString AAA2_WorldSettings::GetSkin_Option(bool bFriendly)
{
	switch (GetSkinSet(bFriendly))
	{
		case ESkinSet::SKINS_Arctic:
			return "Arctic";
		case ESkinSet::SKINS_SF_Arctic:
			return "SFArctic";
		case ESkinSet::SKINS_Forest:
			return "Forest";
		case ESkinSet::SKINS_Desert:
			return "Desert";
		case ESkinSet::SKINS_CivOp:
			return "CivOp";
		case ESkinSet::SKINS_OpFor:
			return "OpM";
		case ESkinSet::SKINS_OpInfantry:
			return "OpInf";
		case ESkinSet::SKINS_ArcOpFor:
			return "ArcOp";
		case ESkinSet::SKINS_DesOp:
			return "";
		case ESkinSet::SKINS_IBCT:
			return "";
		case ESkinSet::SKINS_Training:
			return "";
		default:
			return "INVALID";
	}
}
FString AAA2_WorldSettings::GetSkin_Option_Parachute(bool bFriendly)
{
	return GetSkin_Option(bFriendly);
}
FString AAA2_WorldSettings::GetSkin_Group(bool bFriendly)
{
	if (GetMesh(bFriendly) == EMesh::MESH_SF)
	{
		return "SF";
	}
	switch(GetSkinSet(bFriendly))
	{
		case ESkinSet::SKINS_Forest:
			return "Inf";
		case ESkinSet::SKINS_Desert:
			return "Inf";
		case ESkinSet::SKINS_IBCT:
			return "Inf";
		case ESkinSet::SKINS_Training:
			return "Inf";
		case ESkinSet::SKINS_Arctic:
			return "Inf";
		case ESkinSet::SKINS_SF_Arctic:
			return "SFArc";
		case ESkinSet::SKINS_ArcOpFor:
			return "ArcOp";
		case ESkinSet::SKINS_CivOp:
			return "CivOp";
		case ESkinSet::SKINS_OpFor:
			return "OpM";
		case ESkinSet::SKINS_OpInfantry:
			return "OpInf";
		case ESkinSet::SKINS_DesOp:
		default:
			return "INVALID";
	}
}
EMesh AAA2_WorldSettings::GetMesh(bool bFriendly)
{
	if (bFriendly)
	{
		return MeshFriendly;
	}
	else
	{
		return MeshEnemy;
	}
}
void AAA2_WorldSettings::SetActorLevelSkin(AActor* A, bool bFriendly, FString level_tag)
{
	/*
		int32 i;
		UMaterial old_material;
		UMaterial new_material;
		FString new_name;
		UObject* temp_obj;

		A->AlphaSkins.Remove (0,A->AlphaSkins.Max());
		A->BlackSkins.Remove (0,A->BlackSkins.Max());
		A->Skins.remove (0,A.Skins.Max());

		if (level_tag == "")
		{
			if (A.IsA('Pickup') || A.IsA('WeaponAttachment') || A.IsA('BaseModAttachment') || A.IsA('AGP_Weapon') || A.IsA('BaseWeaponMod'))
			{
				switch(GetWeaponSkinSet(bFriendly))
				{
					case 0:
						break;
					case 1:
						level_tag="Des";
						break;
					case 2:
						level_tag="Arc";
						break;
					default:
						break;
				}
			}
			else
			{
				switch(GetSkinSet(bFriendly))
				{
					case 1:
						level_tag="Des";
						break;
					case 10:
					case 4:
						level_tag="Arc";
						break;
					default:
						break;
				}
			}
		}
		i=0;
		old_material=A->GetDisplayedSkin(i);
		if (old_material != nullptr)
		{
			new_name=A.GetActorLevelSkin(i,old_material,level_tag);
			temp_obj=DynamicLoadObject(new_name,'Material',True);
			new_material=Material(temp_obj);
			//UE_LOG(LogTemp, Warning, TEXT("LevelInfo::SetActorLevelSkin()	Actor" @ A @ "old(" @ old_material @ ") new(" @ new_name @ ")" @ new_material));
			if (new_material == nullptr)
			{
				new_material=old_material;
			}
			A->Skins[i]=new_material;
			i ++;
			old_material=A->GetDisplayedSkin(i);
		}
	*/
}

AGrenadeHelper* AAA2_WorldSettings::GetGrenadeHelper()
{
	if (GrenHelper == nullptr)
	{
		//GrenHelper=Spawn('GrenadeHelper');
		GrenHelper = NewObject<AGrenadeHelper>(AGrenadeHelper::StaticClass());
		//GrenHelper=newobject Spawn('GrenadeHelper');
	}
	return GrenHelper;
}
void AAA2_WorldSettings::GetClientController()
{
	/*
		AAA2_PlayerState* PRI;
		PRI=GetClient();
		if (PRI != None)
		{
			return PlayerController(PRI.Owner);
		}
	*/
}
void AAA2_WorldSettings::GetClientPawn()
{
	/*
		local PlayerReplicationInfo PRI;
		PRI=GetClient();
		if (PRI != None)
		{
			Return PRI.myPawn;
		}
		Return None;
	*/
}
void AAA2_WorldSettings::SetClientController(AController* C)
{
	/*
		if (Client == None || Client.Owner == None && C.IsA('PlayerController') && C.PlayerReplicationInfo != None)
		{
			Client=C.PlayerReplicationInfo;
			Client.SetOwner(C);
		}
	*/
}
AAA2_PlayerState* AAA2_WorldSettings::GetClient()
{
	/*
	APlayerController* PC;
		
	if (Client == nullptr || Client->Owner == nullptr && ! IsServer())
	{
		ForEach DynamicActors('PlayerController',PC)
		{
			if (PC.PlayerReplicationInfo != None)
			{
				Client=PC.PlayerReplicationInfo;
				Client.SetOwner(PC);
			}
		}
	}
	*/
	return Client;
}
bool AAA2_WorldSettings::IsMILES()
{
	return (GamePlayMode == EGameplayModes::GM_MILES);
}
bool AAA2_WorldSettings::IsServer()
{
	return GetNetMode() == ENetMode::NM_DedicatedServer || GetNetMode() == ENetMode::NM_ListenServer;
}
void AAA2_WorldSettings::GetLevelNamePrivate()
{
	/*
		local int pos0;
		local int pos1;
		local int pos2;
		local string string0;
		local string string1;
		local string string2;
		string0=Level.GetLocalURL();
		pos0=InStr(string0,"/");
		pos1=InStr(string0,".");
		pos2=InStr(string0,"?");
		if (pos0 != -1)
		{
			string1=Mid(string0,pos0 + 1,pos2 - pos0);
			string0=string1;
			pos1=InStr(string0,".");
			pos2=InStr(string0,"?");
		}
		if (pos1 == -1 || pos1 > pos2)
		{
			pos1=pos2;
		}
		if (pos0 == -1 && pos1 == -1 && pos2 == -1)
		{
			string2=string0;
		}
		else
		{
			string2=Left(string0,pos1);
		}
		Return string2;
	*/
}
void AAA2_WorldSettings::GetLevelMissionPrivate(FString D_sLevelName, int32 D_iTour, FString D_sLevelFile)
{
	/*
		local string sFile;
		local string sTemp;
		local string sLine;
		local string sInfo;
		local int iCurTour;
		local int iCurMission;
		local int iCurNumTours;
		local int iCurNumMissions;
		local string sMissionName;
		local string sMissionFile;
		sLevelFile="";
		if (sLevelName ~= "entry")
		{
			Return;
		}
		if (30 == iTour)
		{
			Return;
		}
		sTemp=GetBaseDir();
		sFile=sTemp $ "tours.ini";
		iCurNumTours=GetPrivateProfileInt(sFile,"Tours","NumTours");
		for (iCurTour=0; iCurTour<iCurNumTours; iCurTour++)
		{
			sLine="Tour(" $ iCurTour $ ")";
			sInfo=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine=sInfo;
			iCurNumMissions=GetPrivateProfileInt(sFile,sLine,"NumMissions");
			for (iCurMission=0; iCurMission<iCurNumMissions; iCurMission++)
			{
				sMissionName=GetPrivateProfileString(sFile,sLine,"MissionMBSTitle(" $ iCurMission $ ")");
				sMissionFile=GetPrivateProfileString(sFile,sLine,"MissionMapFilename(" $ iCurMission $ ")");
				if (sMissionName ~= sLevelName)
				{
					sLevelFile=sMissionFile;
					Return;
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("Failure finding mission '" $ sLevelName $ "' - tours.ini is invalid."));
	*/
}

void AAA2_WorldSettings::GetLevelTourAndMissionPrivate(FString D_sLevelName, int32 D_iTour, int32 D_iMission)
{
	/*
		local string sFile;
		local string sTemp;
		local string sLine;
		local string sInfo;
		local int iCurTour;
		local int iCurMission;
		local int iCurNumTours;
		local int iCurNumMissions;
		local string sMissionName;
		if (30 == iTour)
		{
			iMission=0;
			Return;
		}
		iTour=-1;
		iMission=-1;
		if (sLevelName ~= "entry")
		{
			Return;
		}
		sTemp=GetBaseDir();
		sFile=sTemp $ "tours.ini";
		iCurNumTours=GetPrivateProfileInt(sFile,"Tours","NumTours");
		for (iCurTour=0; iCurTour<iCurNumTours; iCurTour++)
		{
			sLine="Tour(" $ iCurTour $ ")";
			sInfo=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine=sInfo;
			iCurNumMissions=GetPrivateProfileInt(sFile,sLine,"NumMissions");
			for (iCurMission=0; iCurMission<iCurNumMissions; iCurMission++)
			{
				sMissionName=GetPrivateProfileString(sFile,sLine,"MissionMapFilename(" $ iCurMission $ ")");
				if (sMissionName ~= sLevelName)
				{
					iTour=iCurTour;
					iMission=iCurMission;
					Return;
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::GetLevelTourAndMissionPrivate Failure finding mission '" $ sLevelName $ "' - tours.ini is invalid."));
	*/
}

void AAA2_WorldSettings::GetMBSTitleTourAndMissionPrivate(FString D_sLevelName, int32 D_iTour, int32 D_iMission)
{
	/*
		local string sFile;
		local string sTemp;
		local string sLine;
		local string sInfo;
		local int iCurTour;
		local int iCurMission;
		local int iCurNumTours;
		local int iCurNumMissions;
		local string sMissionName;
		iTour=-1;
		iMission=-1;
		if (sLevelName ~= "entry")
		{
			Return;
		}
		sTemp=GetBaseDir();
		sFile=sTemp $ "tours.ini";
		iCurNumTours=GetPrivateProfileInt(sFile,"Tours","NumTours");
		for (iCurTour=0; iCurTour<iCurNumTours; iCurTour++)
		{
			sLine="Tour(" $ iCurTour $ ")";
			sInfo=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine=sInfo;
			iCurNumMissions=GetPrivateProfileInt(sFile,sLine,"NumMissions");
			for (iCurMission=0; iCurMission<iCurNumMissions; iCurMission++)
			{
				sMissionName=GetPrivateProfileString(sFile,sLine,"MissionMBSTitle(" $ iCurMission $ ")");
				if (sMissionName ~= sLevelName)
				{
					iTour=iCurTour;
					iMission=iCurMission;
					Return;
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::GetLevelTourAndMissionPrivate Failure finding mission '" $ sLevelName $ "' - tours.ini is invalid."));
	*/
}

void AAA2_WorldSettings::GetLevelTourCategory(FString D_sLevelName, FString D_TourCategory)
{
	/*
		local string sFile;
		local string sTemp;
		local string sLine;
		local string sInfo;
		local int iCurTour;
		local int iCurMission;
		local int iCurNumTours;
		local int iCurNumMissions;
		local string sMissionName;
		if (sLevelName ~= "entry")
		{
			Return;
		}
		sTemp=GetBaseDir();
		sFile=sTemp $ "tours.ini";
		iCurNumTours=GetPrivateProfileInt(sFile,"Tours","NumTours");
		for (iCurTour=0; iCurTour<iCurNumTours; iCurTour++)
		{
			sLine="Tour(" $ iCurTour $ ")";
			sInfo=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine=sInfo;
			iCurNumMissions=GetPrivateProfileInt(sFile,sLine,"NumMissions");
			for (iCurMission=0; iCurMission<iCurNumMissions; iCurMission++)
			{
				sMissionName=GetPrivateProfileString(sFile,sLine,"MissionMapFilename(" $ iCurMission $ ")");
				if (sMissionName ~= sLevelName)
				{
					TourCategory=GetPrivateProfileString(sFile,sLine,"TourCategory");
					Return;
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("LevelInfo::GetLevelTourCategory Failure finding tour category for mission '" $ sLevelName $ "' - tours.ini is invalid."));
	*/
}

void AAA2_WorldSettings::IsTourSequentialPrivate(int32 D_iTour)
{
	/*
		local string sFile;
		local string sTemp;
		local int iIsSequential;
		if (iTour == -1)
		{
			Return False;
		}
		sTemp=GetBaseDir();
		sFile=sTemp $ "tours.ini";
		iIsSequential=GetPrivateProfileInt(sFile,"Tours","IsSequential(" $ iTour $ ")");
		if (iIsSequential != 0)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	*/
}
void AAA2_WorldSettings::CanPlayerPlayMissionPrivate(APlayerController* PC, int32 D_iTour, int32 D_iMission)
{
	/*
		local int iCurMission;
		local int iCurTour;
		if (iTour == -1 && iMission == -1)
		{
			if (PC.PlayerReplicationInfo.hasSoldiersCharacter())
			{
				Return True;
			}
		}
		if (30 == iTour && iMission >= 0)
		{
			if (PC.iCompleted[1] == 0)
			{
				Return False;
			}
			Return True;
		}
		if (! iTour >= 0 && iTour < 32 && iMission >= 0)
		{
			Return False;
		}
		if (! iTour < iNumTours && iMission < TourInfo[iTour].iNumMissions)
		{
			Return False;
		}
		if (PC.PlayerReplicationInfo != None)
		{
			if (iTour == 1 || iTour == 2 || iTour == 3 || iTour == 6 || iTour == 7 || iTour == 8 || iTour == 11 && PC.PlayerReplicationInfo.bQualifiedViaInstantAction)
			{
				Log("Skipping training requirements for non-SF exclusive map and player not completing BCT for tour " $ iTour);
				Return True;
			}
			if (iTour == 11 && PC.PlayerReplicationInfo.bQualifiedBCT)
			{
				Log("BCT qualified allowed to play on SF map");
				Return True;
			}
			if (PC.PlayerReplicationInfo.bQualifiedViaInstantAction && iTour == 12)
			{
				Log("Rejecting instant action player on SF exclusive server tour " $ iTour);
				Return False;
			}
		}
		if (! IgnoreTourComplete(iTour))
		{
			if (2 ** iMission & PC.iCompleted[iTour + 1] > 0)
			{
				Return True;
			}
			if (TourInfo[iTour].IsSequential)
			{
				for (iCurMission=iMission-1; iCurMission>=0; iCurMission--)
				{
					if (2 ** iCurMission & PC.iCompleted[iTour + 1] == 0)
					{
						Return False;
					}
				}
			}
		}
		iCurTour=iTour;
		if (TourInfo[iCurTour].Dependency != -1)
		{
			iCurTour=TourInfo[iCurTour].Dependency;
			Log("Dependency for tour " $ iTour $ " is tour " $ iCurTour $ ", bit shift " $ 2 ** iCurTour $ ", and player completed for BCT " $ PC.iCompleted[0]);
			if (2 ** iCurTour & PC.iCompleted[0] == 0)
			{
				Log("AGP_GameInfo::CanPlayerPlayMissionPrivate() no - 4 - dependency not met.",'TourInfo');
				Return False;
			}
		}
		if (iTour == 4)
		{
			if (PC.iRifleRangeRating < 36)
			{
				Return False;
			}
		}
		if (iTour == 12)
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && ! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
			{
				if (PC.PlayerReplicationInfo.GetHonor() < 15)
				{
					Return False;
				}
			}
		}
		Log("AGP_GameInfo::CanPlayerPlayMissionPrivate() yes - its all good!",'TourInfo');
		Return True;
	*/
}
int32 AAA2_WorldSettings::DidPlayerCompleteNewMission(APlayerController* PC)
{
	return DidPlayerCompleteNewMissionPrivate(PC,iTour,iMission);
}
int32 AAA2_WorldSettings::DidPlayerCompleteNewMissionPrivate(APlayerController* PC, int32 D_iTour, int32 D_iMission)
{
	// 0. bounds check 1 - must be between 0 and 32
	if (!((iTour >= 0) && (iTour < 32) && (iMission >= 0) && (iMission < 32)))
	{
		// (!((iTour>=0) && (iTour<iNumTours) && (iMission>=0) && (iMission < TourInfo[iTour].iNumMissions)))
		UE_LOG(LogTemp, Log, TEXT("no - 0 - out of bounds."));
		return -1; // illegal tour/mission
	}

	// 1. bounds check 2 - makes sure they are valid
	if (!((iTour < iNumTours) && (iMission < TourInfo[iTour].iNumMissions)))
	{
		UE_LOG(LogTemp, Log, TEXT("no - 1 - invalid tour/mission. TourInfo[iTour].iNumMissions %d" ), TourInfo[iTour].iNumMissions);
		return -1; // illegal tour/mission
	}

	// 1.5 - fake it for rifle range mission - always let them xmit the new data
	if ((iTour == 0) && (iMission == 0))
	{
		return 1;
	}

	// 2. see if mission is already completed this mission before
	//if (((2 * *iMission) & (Cast<AHumanController>(PC)->iCompleted[iTour + 1])) > 0)
	if (((2 * iMission) & (Cast<AHumanController>(PC)->iCompleted[iTour + 1])) > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("no - 2 - mission is already completed."));
		return 0; // go ahead, knock yourself out!
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("yes - 2 - this mission has not been completed before"));
		return 1;
	}
}

FString AAA2_WorldSettings::GetLevelName()
{
	return sLevelName;
}

int32 AAA2_WorldSettings::GetLevelTour()
{
	return iTour;
}
int32 AAA2_WorldSettings::GetLevelMission()
{
	return iMission;
}
bool AAA2_WorldSettings::IsTourSequential()
{
	return bTourSequential;
}
void AAA2_WorldSettings::CanPlayerPlayMission(APlayerController* PC)
{
	/*
		Return CanPlayerPlayMissionPrivate(PC,iTour,iMission);
	*/
}
void AAA2_WorldSettings::LoadTourInfo()
{
	/*
		local string sTemp;
		local string sFile;
		local string sLine;
		local int iCurNumMissions;
		local int iCurTour;
		local int iCurMission;
		local MissionStruct NewMission;
		sTemp=GetBaseDir();
		sFile=sTemp $ "tours.ini";
		iNumTours=GetPrivateProfileInt(sFile,"Tours","NumTours");
		if (iNumTours < 0)
		{
			iNumTours=0;
		}
		if (iNumTours > 32)
		{
			iNumTours=32;
		}
		for (iCurTour=0; iCurTour<iNumTours; iCurTour++)
		{
			sLine="Tour(" $ iCurTour $ ")";
			TourInfo[iCurTour].Tour=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="Dependency(" $ iCurTour $ ")";
			TourInfo[iCurTour].Dependency=GetPrivateProfileInt(sFile,"Tours",sLine);
			sLine="Image(" $ iCurTour $ ")";
			TourInfo[iCurTour].Image=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="TourText(" $ iCurTour $ ")";
			TourInfo[iCurTour].TourText=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="TourTextTitle(" $ iCurTour $ ")";
			TourInfo[iCurTour].TourTextTitle=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="HistoryText(" $ iCurTour $ ")";
			TourInfo[iCurTour].HistoryText=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="HistoryTextTitle(" $ iCurTour $ ")";
			TourInfo[iCurTour].HistoryTextTitle=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="IsSequential(" $ iCurTour $ ")";
			TourInfo[iCurTour].IsSequential=GetPrivateProfileString(sFile,"Tours",sLine);
			sLine="IsTraining(" $ iCurTour $ ")";
			TourInfo[iCurTour].IsTraining=GetPrivateProfileString(sFile,"Tours",sLine);
			if (debugTours)
			{
				Log("Tour" $ iCurTour @ TourInfo[iCurTour].Tour,'TourInfo');
				Log("Dependency " $ TourInfo[iCurTour].Dependency,'TourInfo');
				Log("Image " $ TourInfo[iCurTour].Image,'TourInfo');
				Log("TourText " $ TourInfo[iCurTour].TourText,'TourInfo');
				Log("TourTextTitle " $ TourInfo[iCurTour].TourTextTitle,'TourInfo');
				Log("HistoryText " $ TourInfo[iCurTour].HistoryText,'TourInfo');
				Log("HistoryTextTitle " $ TourInfo[iCurTour].HistoryTextTitle,'TourInfo');
				Log("IsSequential " $ TourInfo[iCurTour].IsSequential,'TourInfo');
				Log("IsTraining " $ TourInfo[iCurTour].IsTraining,'TourInfo');
			}
			iCurNumMissions=GetPrivateProfileInt(sFile,TourInfo[iCurTour].Tour,"NumMissions");
			if (iCurNumMissions < 0)
			{
				iCurNumMissions=0;
			}
			TourInfo[iCurTour].iNumMissions=iCurNumMissions;
			if (debugTours)
			{
				Log("iNumMissions " $ TourInfo[iCurTour].iNumMissions,'TourInfo');
			}
			for (iCurMission=0; iCurMission<iCurNumMissions; iCurMission++)
			{
				sLine="MissionTitle(" $ iCurMission $ ")";
				NewMission.Title=GetPrivateProfileString(sFile,TourInfo[iCurTour].Tour,sLine);
				sLine="MissionMBSTitle(" $ iCurMission $ ")";
				NewMission.MBSTitle=GetPrivateProfileString(sFile,TourInfo[iCurTour].Tour,sLine);
				sLine="MissionImage(" $ iCurMission $ ")";
				NewMission.Image=GetPrivateProfileString(sFile,TourInfo[iCurTour].Tour,sLine);
				sLine="MissionImageDisabled(" $ iCurMission $ ")";
				NewMission.ImageDisabled=GetPrivateProfileString(sFile,TourInfo[iCurTour].Tour,sLine);
				sLine="MissionMapFilename(" $ iCurMission $ ")";
				NewMission.MapFilename=GetPrivateProfileString(sFile,TourInfo[iCurTour].Tour,sLine);
				NewMission.bFileExists=DoesMapExist(NewMission.MapFilename);
				TourInfo[iCurTour].Mission[iCurMission]=NewMission;
				if (debugTours)
				{
					Log("  Mission" $ iCurMission @ TourInfo[iCurTour].Mission[iCurMission].Title,'TourInfo');
					Log("    MBSTitle" $ iCurMission @ TourInfo[iCurTour].Mission[iCurMission].MBSTitle,'TourInfo');
					Log("    Image " $ TourInfo[iCurTour].Mission[iCurMission].Image,'TourInfo');
					Log("    ImageDisabled " $ TourInfo[iCurTour].Mission[iCurMission].ImageDisabled,'TourInfo');
					Log("    MapFilename" @ TourInfo[iCurTour].Mission[iCurMission].MapFilename @ "exists:" @ TourInfo[iCurTour].Mission[iCurMission].bFileExists,'TourInfo');
				}
			}
		}
	*/
}
FTourStruct AAA2_WorldSettings::GetTour(int32 Index)
{
	FTourStruct ts;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index];
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourName(int32 Index)
{
	FString ts;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].Tour;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourImage(int32 Index)
{
		FString ts;
		if (Index >= 0 && Index < 32)
		{
			ts=TourInfo[Index].Image;
		}
		return ts;
}
FString AAA2_WorldSettings::GetTourText(int32 Index)
{
	FString ts;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].TourText;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourTextTitle(int32 Index)
{
	FString ts;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].TourTextTitle;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourHistoryText(int32 Index)
{
	FString ts;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].HistoryText;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourHistoryTextTitle(int32 Index)
{
	FString ts;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].HistoryTextTitle;
	}
	return ts;
}
int32 AAA2_WorldSettings::GetTourDependency(int32 Index)
{
	int32 ts;
	ts=-1;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].Dependency;
	}
	return ts;
}
bool AAA2_WorldSettings::GetTourIsSequential(int32 Index)
{
	bool ts=false;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].IsSequential;
	}
	return ts;
}
bool AAA2_WorldSettings::GetTourIsTraining(int32 Index)
{
	bool ts=false;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].IsTraining;
	}
	return ts;
}
int32 AAA2_WorldSettings::GetTourMissions(int32 Index)
{
	int32 ts;
	ts=0;
	if (Index >= 0 && Index < 32)
	{
		ts=TourInfo[Index].iNumMissions;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourMissionTitle(int32 Tour, int32 Mission)
{
	FString ts;
	if (Tour >= 0 && Tour < 32 && Mission >= 0 && Mission < TourInfo[Tour].iNumMissions)
	{
		ts=TourInfo[Tour].Mission[Mission].Title;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourMissionMBSTitle(int32 Tour, int32 Mission)
{
	FString ts;
	if (Tour >= 0 && Tour < 32 && Mission >= 0 && Mission < TourInfo[Tour].iNumMissions)
	{
		ts=TourInfo[Tour].Mission[Mission].MBSTitle;
	}
	return ts;
}
FString AAA2_WorldSettings::GetTourMissionImage(int32 Tour, int32 Mission)
{
		FString ts;
		if (Tour >= 0 && Tour < 32 && Mission >= 0 && Mission < TourInfo[Tour].iNumMissions)
		{
			ts=TourInfo[Tour].Mission[Mission].Image;
		}
		return ts;
}
FString AAA2_WorldSettings::GetTourMissionImageDisabled(int32 Tour, int32 Mission)
{
		FString ts;
		if (Tour >= 0 && Tour < 32 && Mission >= 0 && Mission < TourInfo[Tour].iNumMissions)
		{
			ts=TourInfo[Tour].Mission[Mission].ImageDisabled;
		}
		return ts;
}
FString AAA2_WorldSettings::GetTourMissionMapFilename(int32 Tour, int32 Mission)
{
	FString ts;
	if (Tour >= 0 && Tour < 32 && Mission >= 0 && Mission < TourInfo[Tour].iNumMissions)
	{
		ts=TourInfo[Tour].Mission[Mission].MapFilename;
	}
	return ts;
}
void AAA2_WorldSettings::ClientGetInfo()
{
	/*
		LoadTourInfo();
		sLevelName=GetLevelNamePrivate();
		GetLevelTourAndMissionPrivate(sLevelName,iTour,iMission);
		GetLevelTourCategory(sLevelName,TourCategory);
		bTourSequential=IsTourSequentialPrivate(iTour);
	*/
}
void AAA2_WorldSettings::DoesMapExist(FString MapName)
{
	/*
		local string sFullName;
		sFullName=sMapsDir $ MapName $ ".aao";
		if (FOpen(sFullName))
		{
			FClose();
			Return True;
		}
		else
		{
			Return False;
		}
	*/
}
bool AAA2_WorldSettings::IgnoreTourComplete(int32 TourIndex)
{
	int32 i;
	for (i=0; i<IgnoreTours.Max(); i++)
	{
		if (TourIndex == IgnoreTours[i])
		{
			return true;
		}
	}
	return false;
}
void AAA2_WorldSettings::UpdateAllMissionsStatus(APlayerController* PC)
{
	/*
		local int it;
		local int im;
		local int iTempMissions;
		local bool bFoundLastSeqCompleted;
		for (it=0; it<32; it++)
		{
			for (im=0; im<TourInfo[it].iNumMissions; im++)
			{
				TourInfo[it].Status=-1;
				TourInfo[it].Mission[im].Status=-1;
			}
		}
		if (debugTours)
		{
			Log("LevelInfo::UpdateAllMissionsStatus()",'TourInfo');
		}
		for (it=0; it<iNumTours; it++)
		{
			if (debugTours)
			{
				Log("Tour " $ it,'TourInfo');
			}
			iTempMissions=0;
			if (2 ** it & PC.iCompleted[0] > 0)
			{
				if (debugTours)
				{
					Log("marked as completed",'TourInfo');
				}
				if (TourInfo[it].Dependency != -1)
				{
					if (debugTours)
					{
						Log("Tour Dependency " $ TourInfo[it].Dependency,'TourInfo');
					}
					if (2 ** TourInfo[it].Dependency & PC.iCompleted[0] > 0)
					{
						if (debugTours)
						{
							Log("Depedency is met - setting as complete",'TourInfo');
						}
						TourInfo[it].Status=1;
					}
					else
					{
						if (debugTours)
						{
							Log("Depenency not met",'TourInfo');
						}
					}
				}
				else
				{
					if (debugTours)
					{
						Log("No Tour Dependency - setting as complete",'TourInfo');
					}
					TourInfo[it].Status=1;
				}
				if (debugTours)
				{
					Log("checking missions",'TourInfo');
				}
				for (im=0; im<TourInfo[it].iNumMissions; im++)
				{
					if (2 ** im & PC.iCompleted[it + 1] > 0)
					{
						if (TourInfo[it].Mission[im].bFileExists)
						{
							if (debugTours)
							{
								Log("Mission" @ im @ "completed and file exists",'TourInfo');
							}
							TourInfo[it].Mission[im].Status=1;
						}
						else
						{
							if (debugTours)
							{
								Log("Mission" @ im @ "completed and file DOES NOT exist",'TourInfo');
							}
						}
					}
					else
					{
						if (debugTours)
						{
							Log("Mission" @ im @ "not completed",'TourInfo');
						}
					}
				}
			}
			else
			{
				if (debugTours)
				{
					Log("Tour" @ it @ "is NOT flagged as completed",'TourInfo');
				}
				if (TourInfo[it].Dependency != -1)
				{
					if (debugTours)
					{
						Log("Tour Dependency " $ TourInfo[it].Dependency,'TourInfo');
					}
					if (2 ** TourInfo[it].Dependency & PC.iCompleted[0] > 0)
					{
						if (debugTours)
						{
							Log("Depedency is met - checking mission specific dependencies",'TourInfo');
						}
						if (it == 4)
						{
							if (PC.iRifleRangeRating >= 36)
							{
								TourInfo[it].Status=0;
							}
						}
						else
						{
							if (debugTours)
							{
								Log("no dependency - set as available",'TourInfo');
							}
							TourInfo[it].Status=0;
						}
					}
				}
				else
				{
					if (debugTours)
					{
						Log("no dependency - set as available",'TourInfo');
					}
					TourInfo[it].Status=0;
				}
				bFoundLastSeqCompleted=False;
				if (debugTours)
				{
					Log("checking missions",'TourInfo');
				}
				if (! IgnoreTourComplete(it))
				{
					for (im=0; im<TourInfo[it].iNumMissions; im++)
					{
						if (2 ** im & PC.iCompleted[it + 1] > 0)
						{
							if (TourInfo[it].Mission[im].bFileExists)
							{
								if (debugTours)
								{
									Log("Mission" @ im @ "completed and file exists",'TourInfo');
								}
								TourInfo[it].Mission[im].Status=1;
							}
							else
							{
								if (debugTours)
								{
									Log("Mission" @ im @ "completed and file DOES NOT exist",'TourInfo');
								}
							}
						}
						else
						{
							if (debugTours)
							{
								Log("Mission" @ im @ "not completed",'TourInfo');
							}
							if (TourInfo[it].IsSequential)
							{
								if (debugTours)
								{
									Log("Tour is Sequential",'TourInfo');
								}
								if (TourInfo[it].Status != -1)
								{
									if (! bFoundLastSeqCompleted)
									{
										if (TourInfo[it].Mission[im].bFileExists)
										{
											if (debugTours)
											{
												Log("Mission" @ im @ "file exists - made available",'TourInfo');
											}
											TourInfo[it].Mission[im].Status=0;
										}
										bFoundLastSeqCompleted=True;
									}
								}
							}
							else
							{
								if (debugTours)
								{
									Log("Tour is NOT Sequential",'TourInfo');
								}
								if (TourInfo[it].Status != -1)
								{
									if (TourInfo[it].Mission[im].bFileExists)
									{
										if (debugTours)
										{
											Log("Mission" @ im @ "file exists - made available",'TourInfo');
										}
										TourInfo[it].Mission[im].Status=0;
									}
								}
							}
						}
					}
				}
				else
				{
					if (TourInfo[it].Status != -1)
					{
						for (im=0; im<TourInfo[it].iNumMissions; im++)
						{
							if (TourInfo[it].Mission[im].bFileExists)
							{
								TourInfo[it].Mission[im].Status=0;
							}
						}
					}
				}
			}
		}
		if (debugTours)
		{
			for (it=0; it<iNumTours; it++)
			{
				Log("******* TOUR" @ it @ " is" @ TourInfo[it].Status,'TourInfo');
			}
		}
	*/
}
int32 AAA2_WorldSettings::GetTourStatus(int32 Tour)
{
	if (Tour < 0 || Tour > 31)
	{
		return -100;
	}
	if (Tour > iNumTours)
	{
		return -101;
	}
	return TourInfo[Tour].Status;
}
int32 AAA2_WorldSettings::GetMissionStatus(int32 Tour, int32 Mission)
{
	if (Tour < 0 || Tour > 31)
	{
		return -100;
	}
	if (Tour > iNumTours)
	{
		return -101;
	}
	if (Mission < 0)
	{
		return -102;
	}
	if (Mission > TourInfo[Tour].iNumMissions)
	{
		return -103;
	}
	return TourInfo[Tour].Mission[Mission].Status;
}
FString AAA2_WorldSettings::GetTimeString()
{
	return FString::FromInt(Hour) + ":" + FString::FromInt(Minute) + ":" + FString::FromInt(Second) + ":" + FString::FromInt(Millisecond);
}
void AAA2_WorldSettings::PBKickPlayerByController(AController* C, FString Reason)
{
	/*
		Game.KickByController(PlayerController(C),Reason);
	*/
}
void AAA2_WorldSettings::PBKickPlayer(FString PlayerName, FString Reason)
{
	/*
		Game.Kick(PlayerName,Reason);
	*/
}
void AAA2_WorldSettings::DetailChange(EDetailMode NewDetailMode)
{
}
void AAA2_WorldSettings::IsEntry()
{
}
void AAA2_WorldSettings::UpdateDistanceFogLOD(float LOD)
{
}
void AAA2_WorldSettings::ForceLoadTexture(UTexture2D* Texture)
{
}
void AAA2_WorldSettings::GetPhysicsVolume(FVector loc)
{
}
void AAA2_WorldSettings::GetPBGUID(APlayerController* PC)
{
}
void AAA2_WorldSettings::GetPBGUIDFromIP(FString sIPAddress)
{
}
void AAA2_WorldSettings::GetGameClass()
{
	/*
		local class<GameInfo>  G;
		if (Level.Game != None)
		{
			Return Level.Game.Class;
		}
		if (GRI != None && GRI.GameClass != "")
		{
			G=class<GameInfo>(DynamicLoadObject(GRI.GameClass,Class'Class'));
		}
		if (G != None)
		{
			Return G;
		}
		if (DefaultGameType != "")
		{
			G=class<GameInfo>(DynamicLoadObject(DefaultGameType,Class'Class'));
		}
		Return G;
	*/
}
void AAA2_WorldSettings::FillPrecacheMaterialsArray(bool FullPrecache)
{
	/*
		local Actor A;
		local class<GameInfo>  G;
		local bool bRealDesire;
		if (NetMode == 1)
		{
			Return;
		}
		if (! bSkinsPreloaded || FullPrecache)
		{
			if (Game != None)
			{
				G=Game.Class;
			}
			else
			{
				if (GRI != None && GRI.GameClass != "")
				{
					G=class<GameInfo>(DynamicLoadObject(GRI.GameClass,Class'Class'));
				}
			}
			if (G != None)
			{
				G.PrecacheGameTextures(Self);
				bSkinsPreloaded=True;
			}
			if (G == None && DefaultGameType != "")
			{
				G=class<GameInfo>(DynamicLoadObject(DefaultGameType,Class'Class'));
			}
			if (G == None)
			{
				G=class<GameInfo>(DynamicLoadObject(PreCacheGame,Class'Class'));
			}
			if (G != None)
			{
				bRealDesire=bDesireSkinPreload;
				bDesireSkinPreload=False;
				G.PrecacheGameTextures(Self);
				bDesireSkinPreload=bRealDesire;
			}
		}
		ForEach AllActors('Actor',A)
		{
			if (! A.bAlreadyPrecachedMaterials || FullPrecache)
			{
				A.UpdatePrecacheMaterials();
				A.bAlreadyPrecachedMaterials=True;
			}
		}
	*/
}
void AAA2_WorldSettings::PrecacheAnnouncements()
{
}
void AAA2_WorldSettings::FillPrecacheStaticMeshesArray(bool FullPrecache)
{
	/*
		local Actor A;
		local class<GameInfo>  G;
		if (NetMode == 1)
		{
			Return;
		}
		if (Game == None)
		{
			if (GRI != None && GRI.GameClass != "")
			{
				G=class<GameInfo>(DynamicLoadObject(GRI.GameClass,Class'Class'));
			}
			if (G == None && DefaultGameType != "")
			{
				G=class<GameInfo>(DynamicLoadObject(DefaultGameType,Class'Class'));
			}
			if (G == None)
			{
				G=class<GameInfo>(DynamicLoadObject(PreCacheGame,Class'Class'));
			}
			if (G != None)
			{
				G.PrecacheGameStaticMeshes(Self);
			}
		}
		ForEach AllActors('Actor',A)
		{
			if (! A.bAlreadyPrecachedMeshes || FullPrecache)
			{
				A.UpdatePrecacheStaticMeshes();
				A.bAlreadyPrecachedMeshes=True;
			}
		}
	*/
}
void AAA2_WorldSettings::AddPrecacheMaterial(UTexture2D* mat)
{
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		return;
	}
	if (mat == nullptr)
	{
		return;
	}
	PrecacheMaterials.Add(mat);
}
void AAA2_WorldSettings::AddPrecacheStaticMesh(UStaticMesh* stat)
{
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		return;
	}
	if (stat == nullptr)
	{
		return;
	}
	PrecacheStaticMeshes.Add(stat);
}
//native simulated Function GetLocalURL ();
//Needs to be added /ELIZ
void AAA2_WorldSettings::GetLocalURL()
{
}
//native static simulated final Function IsDemoBuild ();
//Needs to be added /ELIZ
void AAA2_WorldSettings::IsDemoBuild()
{
}

//native static simulated final Function IsSoftwareRendering();
//Needs to be added /ELIZ
void AAA2_WorldSettings::IsSoftwareRendering()
{
}

//native simulated Function GetAddressURL();
//Needs to be added /ELIZ
FString AAA2_WorldSettings::GetAddressURL()
{
	return "127.0.0.1:4444";
}

//native simulated Function IsPendingConnection();
//Needs to be added /ELIZ
void AAA2_WorldSettings::IsPendingConnection()
{
}


void AAA2_WorldSettings::ServerTravel(FString URL, bool bItems)
{
	/*
		if (InStr(URL,"%") >= 0)
		{
			Log("URL Contains illegal character '%'.");
			Return;
		}
		if (InStr(URL,":") >= 0 || InStr(URL,"/") >= 0 || InStr(URL,"\") >= 0)
		{
			Log("URL blocked");
			Return;
		}
		if (NextURL == "")
		{
			bLevelChange=True;
			bNextItems=bItems;
			NextURL=URL;
			if (Game != None)
			{
				Game.ProcessServerTravel(URL,bItems);
			}
			else
			{
				NextSwitchCountdown=0;
			}
		}
	*/
}
void AAA2_WorldSettings::ThisIsNeverExecuted()
{
	/*
		local DefaultPhysicsVolume p;
		p=None;
	*/
}
void AAA2_WorldSettings::Reset()
{
	/*
		DefaultGravity=Default.DefaultGravity;
		ConsoleCommand("OBJ GARBAGE");
		Reset();
	*/
}
void AAA2_WorldSettings::PreBeginPlay()
{
	/*
		PreBeginPlay();
		ObjectPool=new (None) class'ObjectPool';
	*/
}
void AAA2_WorldSettings::GetLocalPlayerController()
{
	/*
		local PlayerController PC;
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			Return None;
		}
		if (LocalPlayerController != None)
		{
			Return LocalPlayerController;
		}
		ForEach DynamicActors('PlayerController',PC)
		{
			if (Viewport(PC.Player) != None)
			{
				LocalPlayerController=PC;
			}
			else
			{
			}
		}
		Return LocalPlayerController;
	*/
}
