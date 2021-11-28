// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

ACROWS_HMMWV::ACROWS_HMMWV()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 1;
	KParams0->KInertiaTensor[3] = 3;
	KParams0->KInertiaTensor[5] = 3;
	KParams0->KLinearDamping = 0.05;
	KParams0->KAngularDamping = 0.05;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 3800;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 5;
	KParams0->KImpactThreshold = 700;
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->bHandbrakeWheel = true;
	RRWheel->BoneName = "B_Wheel_RB";
	RRWheel->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelRadius = 24.672001;
	RRWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->bHandbrakeWheel = true;
	LRWheel->BoneName = "B_Wheel_LB";
	LRWheel->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelRadius = 24.672001;
	LRWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->SteerType = EVehicleSteerType::VST_Steered;
	RFWheel->BoneName = "B_Wheel_RF";
	RFWheel->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelRadius = 24.672001;
	RFWheel->SupportBoneName = "B_WheelTravel_RF";
	RFWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->SteerType = EVehicleSteerType::VST_Steered;
	LFWheel->BoneName = "B_Wheel_LF";
	LFWheel->BoneSteerAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelRadius = 24.672001;
	LFWheel->SupportBoneName = "B_WheelTravel_LF";
	LFWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	POSITION_LF = 7;
	POSITION_LFBoard = 3;
	POSITION_LBBoard = 4;
	POSITION_RF = 1;
	POSITION_RFBoard = 5;
	POSITION_RB = 2;
	POSITION_RBBoard = 6;
	PANEL_Wheel_RF = 1;
	PANEL_Wheel_LB = 2;
	PANEL_Wheel_RB = 3;
	PANEL_Door_LF = 4;
	PANEL_Door_RF = 5;
	PANEL_Door_LB = 6;
	PANEL_Door_RB = 7;
	PANEL_Fender_LF = 8;
	PANEL_Fender_RF = 9;
	PANEL_Fender_LB = 10;
	PANEL_Fender_RB = 11;
	PANEL_SteeringWheel = 12;
	PANEL_Shifter_Gear = 13;
	PANEL_Shifter_HiLo = 14;
	PANEL_Pedal_Accelerator = 15;
	PANEL_Pedal_Brake = 16;
	PANEL_Hood = 17;
	PANEL_TrunkLid = 18;
	PANEL_Bumper_Rear = 19;
	PANEL_Bumper_Front = 20;
	PANEL_Roof = 21;
	PANEL_Tailgate = 22;
	PANEL_CROWS_Interface = 23;
	PANEL_EBrake = 24;
	PANEL_Interior = 25;
	PANEL_Body_L = 26;
	PANEL_Body_R = 27;
	PANEL_Cap = 28;
	PANEL_Dashboard = 29;
	PANEL_Seat_LF = 30;
	PANEL_Seat_LB = 31;
	PANEL_Seat_RF = 32;
	PANEL_Seat_RB = 33;
	PANEL_Windshield = 34;
	PANEL_Window_LF = 35;
	PANEL_Window_LB = 36;
	PANEL_Window_RF = 37;
	PANEL_Window_RB = 38;
	PANEL_Rail_L = 39;
	PANEL_Rail_R = 40;
	PANEL_Collision = 41;
	PANEL_Collision_Door_LF = 42;
	PANEL_Collision_Door_RF = 43;
	PANEL_Collision_Door_LB = 44;
	PANEL_Collision_Door_RB = 45;
	PANEL_Collision_CROWS_Interface = 46;
	PANEL_Collision_Dashboard = 47;
	PANEL_Collision_Seat_LF = 48;
	PANEL_Collision_Seat_LB = 49;
	PANEL_Collision_Seat_RF = 50;
	PANEL_Collision_Seat_RB = 51;
	NoSeatbeltMultiplier = 2;
	NotDirectImpactMultiplier = 0.75;
	//StartBodyPanels(0) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',"B_Wheel_LF","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',0,1,0 })
	//StartBodyPanels(1) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',"B_Wheel_RF","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',0,1,0 })
	//StartBodyPanels(2) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',"B_Wheel_LB","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',0,1,0 })
	//StartBodyPanels(3) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',"B_Wheel_RB","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Wheel_01a',0,1,0 })
	//StartBodyPanels(4) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_LF_01a',"B_Door_LF","B_ENTERPOINT_LF",400,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_LF_01a_Damaged',0,0,0 })
	//StartBodyPanels(5) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_RF_01a',"B_Door_RF","B_ENTERPOINT_RF",400,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_RF_01a_Damaged',0,0,0 })
	//StartBodyPanels(6) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_LB_01a',"B_Door_LB","B_ENTERPOINT_LB",400,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_LB_01a_Damaged',0,0,0 })
	//StartBodyPanels(7) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_RB_01a',"B_Door_RB","B_ENTERPOINT_RB",400,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_RB_01a_Damaged',0,0,0 })
	//StartBodyPanels(8) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_LF_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_LF_01a_Damaged',0,0,0 })
	//StartBodyPanels(9) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_RF_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_RF_01a_Damaged',0,0,0 })
	//StartBodyPanels(10) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_LB_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_LB_01a_Damaged',0,0,0 })
	//StartBodyPanels(11) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_RB_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Fender_RB_01a_Damaged',0,0,0 })
	//StartBodyPanels(12) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Steeringwheel',"B_SteeringWheel","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(13) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Shifter_gear',"B_Shifter_gear","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(14) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Shifter_hilo',"B_Shifter_hilo","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(15) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Pedal_Accelerator',"B_Pedal_accelerator","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(16) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Pedal_Brake',"B_Pedal_brake","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(17) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Hood_01a',"B_Hood","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Hood_01a_Damaged',0,0,0 })
	//StartBodyPanels(18) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_TrunkLid_01a',"B_Trunklid","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_TrunkLid_01a_Damaged',0,0,0 })
	//StartBodyPanels(19) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Bumper_Rear_01a',"B_Bumper_Rear","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Bumper_Rear_01a_Damaged',0,0,0 })
	//StartBodyPanels(20) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Bumper_Front_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Bumper_Front_01a1_Damaged',0,0,0 })
	//StartBodyPanels(21) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Roof_01a',"B_Roof","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Roof_01a_Damaged',0,0,0 })
	//StartBodyPanels(22) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Tailgate_01a',"B_Tailgate","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Tailgate_01a_Damaged',0,0,0 })
	//StartBodyPanels(23) = ({ Class'AGP.BodyPanel',class'None',"B_CROWS_Interface","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(24) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Ebrake',"B_EBrake","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(25) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Interior',"HMMWV_root","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(26) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Body_L_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Body_L_01a_Damaged',0,0,0 })
	//StartBodyPanels(27) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Body_R_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Body_R_01a_Damaged',0,0,0 })
	//StartBodyPanels(28) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Cap_01a',"B_Roof","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(29) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Dashboard',"HMMWV_root","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(30) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seat',"B_Sitbone_LF","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(31) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seat',"B_Sitbone_LB","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(32) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seat',"B_Sitbone_RF","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(33) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seat',"B_Sitbone_RB","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(34) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Windshield',"b_windshield","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(35) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Window',"B_Window_LF","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(36) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Window',"B_Window_LB","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(37) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Window',"B_Window_RF","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(38) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Window',"B_Window_RB","None",0,-1,"",class'None',1,0,0 })
	//StartBodyPanels(39) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Rail_L_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Rail_L_01a_Damaged',0,0,0 })
	//StartBodyPanels(40) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Rail_R_01a',"HMMWV_root","None",0,-1,"",StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Rail_R_01a_Damaged',0,0,0 })
	//StartBodyPanels(41) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_01a',"HMMWV_root","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(42) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Door_L_01a',"B_Door_LF","B_ENTERPOINT_LF",400,-1,"Press %UseKey% to enter the driver seat",class'None',1,0,1 })
	//StartBodyPanels(43) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Door_R_01a',"B_Door_RF","B_ENTERPOINT_RF",400,-1,"Press %UseKey% to enter the front passenger seat",class'None',1,0,1 })
	//StartBodyPanels(44) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Door_L_01a',"B_Door_LB","B_ENTERPOINT_LB",400,-1,"Press %UseKey% to enter the gunner seat",class'None',1,0,1 })
	//StartBodyPanels(45) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Door_R_01a',"B_Door_RB","B_ENTERPOINT_RB",400,-1,"Press %UseKey% to enter the rear passenger seat",class'None',1,0,1 })
	//StartBodyPanels(46) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_CROWS_Interface',"HMMWV_root","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(47) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Dashboard',"HMMWV_root","None",0,-1,"",class'None',1,0,1 })
	//StartBodyPanels(48) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Seat',"B_Sitbone_LF","None",0,-1,"Press %UseKey% to enter the driver seat",class'None',1,0,0 })
	//StartBodyPanels(49) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Seat',"B_Sitbone_LB","None",0,-1,"Press %UseKey% to enter the gunner seat",class'None',1,0,0 })
	//StartBodyPanels(50) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Seat',"B_Sitbone_RF","None",0,-1,"Press %UseKey% to enter the front passenger seat",class'None',1,0,0 })
	//StartBodyPanels(51) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Collision_Seat',"B_Sitbone_RB","None",0,-1,"Press %UseKey% to enter the rear passenger seat",class'None',1,0,0 });
	SeatBeltOnMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Vehicles/HMMWV1114/m_vehi_HMMWV1114_Seatbelt_L_on.m_vehi_HMMWV1114_Seatbelt_L_on'"), NULL, LOAD_None, NULL);
	SeatBeltOffMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Vehicles/HMMWV1114/m_vehi_HMMWV1114_Seatbelt_L_off.m_vehi_HMMWV1114_Seatbelt_L_off'"), NULL, LOAD_None, NULL);
	CameraBone = "CameraBone";
	EngineDamagedIdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Motor_Damage_1_Que.S_vehi_HMMWV_Motor_Damage_1_Que'"), NULL, LOAD_None, NULL);
	EngineDamagedHissSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Motor_Damage_2_Que.S_vehi_HMMWV_Motor_Damage_2_Que'"), NULL, LOAD_None, NULL);
	ShiftGearsSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Gear_Shift_Que.S_vehi_HMMWV_Gear_Shift_Que'"), NULL, LOAD_None, NULL);
	CollisionSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Crash_Que.S_vehi_HMMWV_Crash_Que'"), NULL, LOAD_None, NULL);
	SuspensionSqueaksSound = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Sus_1_Que.S_vehi_HMMWV_Squeaks_Sus_1_Que'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Sus_2_Que.S_vehi_HMMWV_Squeaks_Sus_2_Que'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Sus_3_Que.S_vehi_HMMWV_Squeaks_Sus_3_Que'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Sus_4_Que.S_vehi_HMMWV_Squeaks_Sus_4_Que'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Sus_5_Que.S_vehi_HMMWV_Squeaks_Sus_5_Que'"), NULL, LOAD_None, NULL)
	};
	FrameSqueaksSound = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Frame_1_Que.S_vehi_HMMWV_Squeaks_Frame_1_Que'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Frame_2_Que.S_vehi_HMMWV_Squeaks_Frame_2_Que'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Squeaks_Frame_3_Que.S_vehi_HMMWV_Squeaks_Frame_3_Que'"), NULL, LOAD_None, NULL)
	};
	SlideSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Dirt_Stop_Que.S_vehi_HMMWV_Dirt_Stop_Que'"), NULL, LOAD_None, NULL);
	ShiftVolume = 0.2;
	ShiftDelay = 0.3;
	ShiftRadius = 64;
	SuspensionTriggerThreshold = 1.2;
	SlideThreshold = 50;
	RollTriggerThreshold = 4.5;
	bIsInHighGear = true;
	fLowGearMultiplier = 0.3;
	bCanShiftHiLo = true;
	bCanShiftDrive = true;
	FlatTireRadius = 13.65;
	SteeringWheelHintText = "Press %UseKey% to start the vehicle";
	StopBrakeFriction = 20;
	WheelSoftness = 0.02;
	WheelPenScale = 1.2;
	WheelPenOffset = 0.01;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 2;
	WheelLatFrictionScale = 1.35;
	WheelHandbrakeSlip = 100;
	WheelHandbrakeFriction = 1;
	WheelSuspensionTravel = 8;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 7;
	FTScale = 0.03;
	ChassisTorqueScale = 0.4;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.4, 0.25,0.41,0.65,1.12 };
	TransRatio = 0.65;
	ChangeUpPoint = 3400;
	ChangeDownPoint = 1000;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0001;
	EngineBrakeRPMScale = 0.2;
	MaxBrakeTorque = 60;
	SteerSpeed = 160;
	TurnDamping = 35;
	StopThreshold = 100;
	HandbrakeThresh = 4000;
	EngineInertia = 0.1;
	IdleRPM = 8214;
	EngineRPMSoundRange = 32856;
	SteerBoneName = "B_SteeringWheel";
	SteerBoneAxis = EAA2_Axis::AXIS_Z;
	SteerBoneMaxAngle = -180;
	OutputBrake = 1;
	RevMeterScale = 4000;
	bMakeBrakeLights = true;
	BrakeLightOffset = { FVector(-100, 23, 7),FVector(-100, -23, 7) };
	AirTurnTorque = 35;
	bAllowCOMAdjust = true;
	COMAdjustScale = 0.00032;
	//PositionTypes(0) = ({ class'AGP_Vehicles.HMMWV_RearLeftPassenger',"None","B_Sitbone_LB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.HMMWV_Passenger',"None","B_Sitbone_RF",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(2) = ({ class'AGP_Vehicles.HMMWV_RearPassenger',"None","B_Sitbone_RB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(3) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerLF',"None","B_Sitbone_LF",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(4) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerLB',"None","B_Sitbone_LB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(5) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerRF',"None","B_Sitbone_RF",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(6) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerRB',"None","B_Sitbone_RB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) });
	ActiveWeapon = 99;
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_idle_Que.S_vehi_HMMWV_idle_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_start_Que.S_vehi_HMMWV_start_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DamagedEffectScale = 1;
	DamagedEffectOffset = FVector(60, 10, 10);
	bEjectPassengersWhenFlipped = false;
	HeadlightCoronaOffset = { FVector(86, 30, 7),FVector(86, -30, 7) };
	HeadlightCoronaMaxSize = 65;
	HeadlightProjectorOffset = FVector(90, 0, 7);
	HeadlightProjectorRotation = FRotator(-1000, 0, 0);
	HeadlightProjectorScale = 0.3;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	VehicleMass = 5;
	bDrawVehicleShadow = false;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	bPCRelativeFPRotation = false;
	bCanFlip = false;
	bHasHandbrake = true;
	DriverBone = "B_Sitbone_LF";
	DrivePos = FVector(2, 0, 48);
	DriveAnim = "DrvrSteerLR";
	bPlayDrivingAnimations = false;
	bCustomAttach = true;
	DriverPosOffset = FVector(0, 0, 8);
	EntryRadius = 160;
	DesiredTPCamDistance = 3;
	DriverDamageMult = 0.8;
	VehiclePositionString = "in a HMMWV";
	VehicleNameString = "HMMWV";
	MinRunOverSpeed = 640;
	MaxDesireability = 0.4;
	ObjectiveGetOutDist = 1500;
	SeatbeltSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/HMMWV/S_vehi_HMMWV_Seatbelt_Que.S_vehi_HMMWV_Seatbelt_Que'"), NULL, LOAD_None, NULL);
	HornSounds = { LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Vehicles/Scratch/s_veh_scratch_btr_fire_Que.s_veh_scratch_btr_fire_Que'"), NULL, LOAD_None, NULL) };
	//bSpecialHUD = false;
	GroundSpeed = 940;
	HealthMax = 300;
	Health = 300;
	//AmbientSoundScaling = 1;
	//iTraceDistance = 512;
	//iShortTraceDistance = 512;
	//bReplicateAnimations = true;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AAO_Vehicles/HMMWV1114.HMMWV1114'"), NULL, LOAD_None, NULL);
	//DrawScale = 1.13;
	//bFullVolume = true;
	//SoundVolume = 76;
	//SoundRadius = 32;
	//CollisionRadius = 192;
	//CollisionHeight = 96;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	KParams = KParams0;
}


//native Function CheckDriverCanExit(APawn* TestDriver, name ExitBone);
void ACROWS_HMMWV::CheckDriverCanExit(APawn* TestDriver, FName ExitBone)
{

}

//native Function UpdateAttachedActorLocations();
void ACROWS_HMMWV::UpdateAttachedActorLocations()
{
}

bool ACROWS_HMMWV::VehicleDisabled()
{
	return bVehicleDisabled;
}

void ACROWS_HMMWV::SetDriverHiddenAttachments()
{
	/*
	if (Driver != None)
	{
		Driver.HiddenAttachmentClasses[0] = Class'Attch_MedicRuck';
		Driver.HiddenAttachmentClasses[1] = Class'WeaponAttachment';
		Driver.HiddenAttachmentClasses[2] = Class'Attch_ParaRuck';
		Driver.HiddenAttachmentClasses[3] = Class'Attch_RuckSackChute';
		Driver.HiddenAttachmentClasses[4] = Class'Attch_RPGBackpack';
		Driver.HiddenAttachmentClasses[5] = Class'Attch_ReserveChute';
		Driver.HiddenAttachmentClasses[6] = Class'Attch_Parachute';
		Driver.HiddenAttachmentClasses[7] = class<ItemAttachment>(DynamicLoadObject("AGP_Armory.Attch_CLUpack", Class'Class'));
	}
	*/
}

void ACROWS_HMMWV::ShiftDriveGearsUp()
{
	//ServerTryToShiftDriveGears(True);
}

void ACROWS_HMMWV::ShiftDriveGearsDown()
{
	//ServerTryToShiftDriveGears(False);
}

void ACROWS_HMMWV::ShiftHiLoGears()
{
	//ServerTryToShiftHiLoGears();
}

void ACROWS_HMMWV::LookRearViewLeft()
{
	bIsRearView = !bIsRearView;
	bRearViewIsLeft = true;
}

void ACROWS_HMMWV::LookRearViewRight()
{
	bIsRearView = !bIsRearView;
	bRearViewIsLeft = false;
}

void ACROWS_HMMWV::Horn()
{
	//ServerPlayHorn(Rand(HornSounds.Length));
}

//native Function PlayEngineStartUpSound();
void ACROWS_HMMWV::PlayEngineStartUpSound()
{

}

//native Function PlayEngineDamagedSounds(bool bDestroyed);
void ACROWS_HMMWV::PlayEngineDamagedSounds(bool bDestroyed)
{

}

void ACROWS_HMMWV::GetVehicleBase()
{
	//return Self;
}

void ACROWS_HMMWV::PostBeginPlay()
{
	Super::PostBeginPlay();
	/*
	AnimManager = Spawn('HMMWVDriverAnimManager');
	HMMWVAnimManager(AnimManager).Vehicle = Self;
	ExitPositions.remove(0, ExitPositions.Length);
	*/
}

void ACROWS_HMMWV::PostNetBeginPlay()
{
	Super::PostNetBeginPlay();
	/*
	local int32 i;
	
	if (Role == 4)
	{
		AttachBodyPanels();
		for (i = 0; i < Wheels.Length; i++)
		{
			WheelRadii[i] = Wheels[i].WheelRadius;
		}
	}
	FixBoneRotations();
	ActiveWeapon = Default.ActiveWeapon;
	SetTimer(1, True);
	SetCustomTimer(1, False, 'StartSounds');
	*/
}

void ACROWS_HMMWV::PostNetReceive()
{
	/*
	local int32 i;
	for (i = 0; i < Wheels.Length; i++)
	{
		if (Wheels[i].WheelRadius != WheelRadii[i])
		{
			Wheels[i].WheelRadius = WheelRadii[i];
		}
	}
	*/
	Super::PostNetReceive();
}
void ACROWS_HMMWV::StartSounds()
{
	bInitialSound = true;
}
void ACROWS_HMMWV::DriverDied()
{
}
void ACROWS_HMMWV::Destroyed()
{
	/*
	local int32 i;
	if (AnimManager != None)
	{
		AnimManager.Destroy();
	}
	Super::Destroyed();
	if (Role == 4)
	{
		for (i = 0; i < 52; i++)
		{
			BodyPanels[i].Destroy();
		}
		if (Seatbelt != None)
		{
			Seatbelt.Destroy();
		}
	}
	if (HMMWVHoodSmokeEmitter != None)
	{
		HMMWVHoodSmokeEmitter.Destroy();
	}
	*/
}

void ACROWS_HMMWV::KDriverEnter(APawn* p)
{
	/*
	p.bSetPCRotOnPossess = false;
	KDriverEnter(p);
	HMMWVAnimManager(AnimManager).BindToPawn(p);
	if (HMMWVAnimManager(AnimManager) != None && bHitIgnition)
	{
		HMMWVAnimManager(AnimManager).PlayActionAnim();
	}
	*/
}

bool ACROWS_HMMWV::KDriverLeave(bool bForceLeave)
{
	/*
	HMMWVAnimManager(AnimManager).ReleasePawn();
	Return KDriverLeave(bForceLeave);
	*/
	return false;    //FAKE  /ELiZ
}

void ACROWS_HMMWV::ClientKDriverEnter(APlayerController* PC)
{
	/*
	PC.Pawn.bSetPCRotOnPossess = false;
	ClientKDriverEnter(PC);
	if (PC != None)
	{
		PC.SetViewTarget(Self);
	}
	PC.bBehindView = true;
	ClientSetIgnition(bHitIgnition);
	*/
}

void ACROWS_HMMWV::ClientKDriverLeave(APlayerController* PC)
{
	/*
	ClientKDriverLeave(PC);
	if (PC != None && PC.ViewTarget == Self)
	{
		PC.SetViewTarget(Driver);
	}
	*/
}

void ACROWS_HMMWV::AttachDriver(APawn* p)
{
	//Super::AttachDriver(p);
}

void ACROWS_HMMWV::FindEntryVehicle(APawn* p)
{
	//Return Self;
}

bool ACROWS_HMMWV::UsedBy(APawn* User)
{
	return true;
}

void ACROWS_HMMWV::LeanLeft(bool bFullLeft)
{
}

void ACROWS_HMMWV::LeanRight(bool bFullRight)
{
}

void ACROWS_HMMWV::CheckForHeadShot(FVector loc, FVector ray, float AdditionalScale)
{
	/*
	local Object.Vector X;
	local Object.Vector Y;
	local Object.Vector Z;
	GetAxes(Rotation, X, Y, Z);
	if (Driver != None && Driver.IsHeadShot(loc, ray, AdditionalScale))
	{
		Return Driver;
	}
	Return None;
	*/
}

/*
void ACROWS_HMMWV::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
}
*/

void ACROWS_HMMWV::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ACROWS_HMMWV::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}

int32 ACROWS_HMMWV::GetVehiclePositionIndex(AVehicle* VehiclePosition)
{
	int32 i=0;
	/*
	if (VehiclePosition == Self)
	{
		Return POSITION_LF;
	}
	for (i = 0; i < 7; i++)
	{
		if (Positions[i] == VehiclePosition)
		{
			Return i;
		}
	}
	*/

	return 0;     //FAKE   ELIZ
}

void ACROWS_HMMWV::FixBoneRotations()
{
	/*
	local int32 i;
	SetBoneRotation(DriverBone, rot(0 - 16384 16384), 0, 1);
	for (i = 0; i < PositionTypes.Length; i++)
	{
		SetBoneRotation(PositionTypes[i].PositionBone, rot(0 - 16384 16384), 0, 1);
	}
	*/
}

void ACROWS_HMMWV::AttachBodyPanels()
{
	/*
	local int32 i;
	local int32 j;
	local AGP.BodyPanel Panel;
	local Actor AttachActor;
	local name AttachBone;
	for (i = 0; i < StartBodyPanels.Length; i++)
	{
		Panel = Spawn(StartBodyPanels[i].ClassType);
		Panel.SetDrawType(8);
		Panel.SetStaticMesh(StartBodyPanels[i].Mesh);
		if (i < 41)
		{
			Panel.SetCollision(False, False, False);
		}
		else
		{
			Panel.SetCollision(True, True, True);
			Panel.bHidden = true;
		}
		for (j = 0; j < Panel.DamagedMesh.Length; j++)
		{
			Panel.DamagedMesh[j] = StartBodyPanels[i].Mesh;
		}
		j = Panel.DamagedMesh.Length - 1;
		if (StartBodyPanels[i].DamagedMesh != None)
		{
			Panel.DamagedMesh[j] = StartBodyPanels[i].DamagedMesh;
		}
		else
		{
			Panel.DamagedMesh[j] = StartBodyPanels[i].Mesh;
		}
		Panel.SetOwner(Self);
		Panel.EntryBone = StartBodyPanels[i].EntryBone;
		Panel.EntryRadius = StartBodyPanels[i].EntryRadius;
		Panel.PanelID = i;
		if (StartBodyPanels[i].bAcceptsProjectileDamage == 1)
		{
			Panel.bAcceptsProjectileDamage = true;
		}
		if (StartBodyPanels[i].bInvincible == 1)
		{
			Panel.bInvincible = true;
		}
		Panel.ExteriorHintText = StartBodyPanels[i].ExteriorHintText;
		if (StartBodyPanels[i].EntryPosIndex >= 0)
		{
			Panel.EntryVehicle = Positions[StartBodyPanels[i].EntryPosIndex];
		}
		else
		{
			Panel.EntryVehicle = Self;
		}
		if (i == PANEL_Wheel_RF || i == PANEL_Wheel_RB)
		{
			Panel.RelRotation = rot(0 32768 - 16384);
		}
		else
		{
			if (i >= PANEL_Seat_LF && i <= PANEL_Seat_RB || i >= PANEL_Collision_Seat_LF && i <= PANEL_Collision_Seat_RB)
			{
				Panel.RelRotation = rot(0 - 16384 0);
			}
			else
			{
				Panel.RelRotation = rot(0 0 - 16384);
			}
		}
		if (i == PANEL_Wheel_RF || i == PANEL_Wheel_RB || i == PANEL_Wheel_LF || i == PANEL_Wheel_LB)
		{
			Panel.ProjectileDamageThreshholds.remove(2, 1);
			Panel.DamagedMesh[1] = StaticMesh'm_vehi_HMMWV1114_Wheel_01a_Damaged_01';
			Panel.DamagedTexture[1] = None;
			Panel.DamagedMesh[2] = StaticMesh'm_vehi_HMMWV1114_Wheel_01a_Damaged_02';
			Panel.DamagedTexture[2] = None;
		}
		if (i == PANEL_Rail_L || i == PANEL_Rail_R)
		{
			Panel.DamagedTexture[0] = Texture't_vehi_HMMWV1114_interior_01a';
			Panel.DamagedTexture[1] = Panel.DamagedTexture[0];
			Panel.DamagedTexture[2] = Panel.DamagedTexture[0];
		}
		AttachToBone(Panel, StartBodyPanels[i].AttachBone);
		Panel.SetRelativeRotation(Panel.RelRotation);
		BodyPanels[i] = Panel;
	}
	Seatbelt = Spawn(Class'BodyPanel');
	Seatbelt.SetDrawType(8);
	Seatbelt.SetStaticMesh(SeatBeltOffMesh);
	Seatbelt.SetOwner(Self);
	GetDriverAttachmentBone(AttachActor, AttachBone);
	AttachActor.AttachToBone(Seatbelt, AttachBone);
	Seatbelt.RelRotation = rot(0 - 16384 0);
	Seatbelt.SetRelativeRotation(rot(0 - 16384 0));
	BodyPanels[PANEL_Interior].bBlockZeroExtentTraces = false;
	BodyPanels[PANEL_Collision_Dashboard].PassengerHintText[POSITION_LF] = SteeringWheelHintText;
	BodyPanels[PANEL_Collision_CROWS_Interface].PassengerHintText[POSITION_LB] = "Press %UseKey% to take control of CROWS";
	BodyPanels[PANEL_Collision_Door_LF].PassengerHintText[POSITION_LF] = "Press %UseKey% to exit the vehicle";
	BodyPanels[PANEL_Collision_Door_RF].PassengerHintText[POSITION_RF] = "Press %UseKey% to exit the vehicle";
	BodyPanels[PANEL_Collision_Door_LB].PassengerHintText[POSITION_LB] = "Press %UseKey% to exit the vehicle";
	BodyPanels[PANEL_Collision_Door_RB].PassengerHintText[POSITION_RB] = "Press %UseKey% to exit the vehicle";
	BodyPanels[PANEL_Collision_Seat_LF].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Door_LF].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Seat_LF].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Door_LF].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Seat_LF].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Door_LF].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Dashboard].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Dashboard].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Dashboard].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the driver seat";
	BodyPanels[PANEL_Collision_Seat_LB].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_Door_LB].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_Seat_LB].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_Door_LB].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_Seat_LB].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_Door_LB].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_CROWS_Interface].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_CROWS_Interface].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_CROWS_Interface].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the gunner seat";
	BodyPanels[PANEL_Collision_Seat_RF].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the front passenger seat";
	BodyPanels[PANEL_Collision_Door_RF].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the front passenger seat";
	BodyPanels[PANEL_Collision_Seat_RF].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the front passenger seat";
	BodyPanels[PANEL_Collision_Door_RF].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the front passenger seat";
	BodyPanels[PANEL_Collision_Seat_RF].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the front passenger seat";
	BodyPanels[PANEL_Collision_Door_RF].PassengerHintText[POSITION_RB] = "Press %UseKey% to switch to the front passenger seat";
	BodyPanels[PANEL_Collision_Seat_RB].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the rear passenger seat";
	BodyPanels[PANEL_Collision_Door_RB].PassengerHintText[POSITION_LF] = "Press %UseKey% to switch to the rear passenger seat";
	BodyPanels[PANEL_Collision_Seat_RB].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the rear passenger seat";
	BodyPanels[PANEL_Collision_Door_RB].PassengerHintText[POSITION_LB] = "Press %UseKey% to switch to the rear passenger seat";
	BodyPanels[PANEL_Collision_Seat_RB].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the rear passenger seat";
	BodyPanels[PANEL_Collision_Door_RB].PassengerHintText[POSITION_RF] = "Press %UseKey% to switch to the rear passenger seat";
	BodyPanels[PANEL_Bumper_Front].AddLinkedPanel(BodyPanels[PANEL_Hood]);
	BodyPanels[PANEL_Bumper_Front].AddLinkedPanel(BodyPanels[PANEL_Fender_LF]);
	BodyPanels[PANEL_Bumper_Front].AddLinkedPanel(BodyPanels[PANEL_Fender_RF]);
	BodyPanels[PANEL_Hood].AddLinkedPanel(BodyPanels[PANEL_Bumper_Front]);
	BodyPanels[PANEL_Hood].AddLinkedPanel(BodyPanels[PANEL_Fender_LF]);
	BodyPanels[PANEL_Hood].AddLinkedPanel(BodyPanels[PANEL_Fender_RF]);
	BodyPanels[PANEL_Fender_LF].AddLinkedPanel(BodyPanels[PANEL_Hood]);
	BodyPanels[PANEL_Fender_LF].AddLinkedPanel(BodyPanels[PANEL_Wheel_LF]);
	BodyPanels[PANEL_Fender_RF].AddLinkedPanel(BodyPanels[PANEL_Hood]);
	BodyPanels[PANEL_Fender_RF].AddLinkedPanel(BodyPanels[PANEL_Wheel_RF]);
	BodyPanels[PANEL_Wheel_LF].AddLinkedPanel(BodyPanels[PANEL_Fender_LF]);
	BodyPanels[PANEL_Wheel_RF].AddLinkedPanel(BodyPanels[PANEL_Fender_RF]);
	BodyPanels[PANEL_Body_L].AddLinkedPanel(BodyPanels[PANEL_Door_LF]);
	BodyPanels[PANEL_Body_L].AddLinkedPanel(BodyPanels[PANEL_Door_LB]);
	BodyPanels[PANEL_Body_L].AddLinkedPanel(BodyPanels[PANEL_Rail_L]);
	BodyPanels[PANEL_Door_LF].AddLinkedPanel(BodyPanels[PANEL_Body_L]);
	BodyPanels[PANEL_Door_LF].AddLinkedPanel(BodyPanels[PANEL_Door_LB]);
	BodyPanels[PANEL_Door_LB].AddLinkedPanel(BodyPanels[PANEL_Body_L]);
	BodyPanels[PANEL_Door_LB].AddLinkedPanel(BodyPanels[PANEL_Door_LF]);
	BodyPanels[PANEL_Body_R].AddLinkedPanel(BodyPanels[PANEL_Door_RF]);
	BodyPanels[PANEL_Body_R].AddLinkedPanel(BodyPanels[PANEL_Door_RB]);
	BodyPanels[PANEL_Body_R].AddLinkedPanel(BodyPanels[PANEL_Rail_R]);
	BodyPanels[PANEL_Door_RF].AddLinkedPanel(BodyPanels[PANEL_Body_R]);
	BodyPanels[PANEL_Door_RF].AddLinkedPanel(BodyPanels[PANEL_Door_RB]);
	BodyPanels[PANEL_Door_RB].AddLinkedPanel(BodyPanels[PANEL_Body_R]);
	BodyPanels[PANEL_Door_RB].AddLinkedPanel(BodyPanels[PANEL_Door_RF]);
	BodyPanels[PANEL_Bumper_Rear].AddLinkedPanel(BodyPanels[PANEL_TrunkLid]);
	BodyPanels[PANEL_Bumper_Rear].AddLinkedPanel(BodyPanels[PANEL_Tailgate]);
	BodyPanels[PANEL_Bumper_Rear].AddLinkedPanel(BodyPanels[PANEL_Fender_LB]);
	BodyPanels[PANEL_Bumper_Rear].AddLinkedPanel(BodyPanels[PANEL_Fender_RB]);
	BodyPanels[PANEL_Tailgate].AddLinkedPanel(BodyPanels[PANEL_Fender_LB]);
	BodyPanels[PANEL_Tailgate].AddLinkedPanel(BodyPanels[PANEL_Fender_RB]);
	BodyPanels[PANEL_Tailgate].AddLinkedPanel(BodyPanels[PANEL_TrunkLid]);
	BodyPanels[PANEL_TrunkLid].AddLinkedPanel(BodyPanels[PANEL_TrunkLid]);
	BodyPanels[PANEL_TrunkLid].AddLinkedPanel(BodyPanels[PANEL_Tailgate]);
	BodyPanels[PANEL_TrunkLid].AddLinkedPanel(BodyPanels[PANEL_Fender_LB]);
	BodyPanels[PANEL_TrunkLid].AddLinkedPanel(BodyPanels[PANEL_Fender_RB]);
	BodyPanels[PANEL_Fender_LB].AddLinkedPanel(BodyPanels[PANEL_Bumper_Rear]);
	BodyPanels[PANEL_Fender_LB].AddLinkedPanel(BodyPanels[PANEL_Wheel_LB]);
	BodyPanels[PANEL_Fender_RB].AddLinkedPanel(BodyPanels[PANEL_Bumper_Rear]);
	BodyPanels[PANEL_Fender_RB].AddLinkedPanel(BodyPanels[PANEL_Wheel_RB]);
	BodyPanels[PANEL_Roof].AddLinkedPanel(BodyPanels[PANEL_Cap]);
	BodyPanels[PANEL_Cap].AddLinkedPanel(BodyPanels[PANEL_Roof]);
	*/
}

void ACROWS_HMMWV::StopReplicateMovement()
{
	/*
	local int32 i;
	for (i = 0; i < StartBodyPanels.Length; i++)
	{
		BodyPanels[i].bReplicateMovement = false;
	}
	*/
}

void ACROWS_HMMWV::PanelUsedBy(APawn* User, int32 Id)
{
	/*
	DebugLog(DEBUG_Vehicle, "PanelUsedBy User:" $ User $ " Id:" $ Id);
	if (HMMWVAnimManager(User.AnimManager) != None && HMMWVAnimManager(User.AnimManager).bBusyAnimating)
	{
		return false;
	}
	Switch(Id)
	{
			case PANEL_Collision_Seat_LF:
				if (User == Self)
				{
					return true;
				}
			case PANEL_Collision_Door_LF:
				Return DoDoor(User, Self, Positions[POSITION_LFBoard], User == Positions[POSITION_RF]);
			case PANEL_Collision_Seat_RF:
				if (User == Positions[POSITION_RF])
				{
					return true;
				}
			case PANEL_Collision_Door_RF:
				Return DoDoor(User, Positions[POSITION_RF], Positions[POSITION_RFBoard], User == Self);
			case PANEL_Collision_CROWS_Interface:
				if (User == Positions[POSITION_LB])
				{
					if (Level.NetMode != 0 && PlayerController(User.Controller).PlayerReplicationInfo != None && !PlayerController(User.Controller).PlayerReplicationInfo.bQualifiedUseCROWS)
					{
						PlayerController(User.Controller).ClientNotifyAdminMessage("You are not qualified to use the CROWS.");
						return true;
					}
					CROWS_Gunner(Positions[POSITION_LB]).ActivateCrows();
					return true;
				}
			case PANEL_Collision_Seat_LB:
				if (User == Positions[POSITION_LB])
				{
					return true;
				}
			case PANEL_Collision_Door_LB:
				Return DoDoor(User, Positions[POSITION_LB], Positions[POSITION_LBBoard], User == Positions[POSITION_RB]);
			case PANEL_Collision_Seat_RB:
				if (User == Positions[POSITION_RB])
				{
					return true;
				}
			case PANEL_Collision_Door_RB:
				Return DoDoor(User, Positions[POSITION_RB], Positions[POSITION_RBBoard], User == Positions[POSITION_LB]);
			case PANEL_Collision_Dashboard:
				if (User == Self)
				{
					Ignition();
				}
				return true;
			default:
				return false;
	}
	*/
}

bool ACROWS_HMMWV::DoDoor(APawn* User, AVehicle* EntryVehicle, AVehicle* EntryBoard, bool bSideStep)
{
	/*
	local Pawn TempDriver;
	local bool bOldCollideActors;
	local bool bOldBlockActors;
	local name TestBone;
	if (User == EntryVehicle)
	{
		if (!EntryBoard.bReservedOccupation && !HMMWVAnimManager(EntryVehicle.AnimManager).bBusyAnimating)
		{
			TempDriver = Vehicle(User).Driver;
			bOldCollideActors = TempDriver.bCollideActors;
			bOldBlockActors = TempDriver.bBlockActors;
			Switch(EntryVehicle)
			{
		case Self:
			TestBone = 'B_ENTERPOINT_LF';
			break;
		case Positions[POSITION_RF]:
			TestBone = 'B_ENTERPOINT_RF';
			break;
		case Positions[POSITION_LB]:
			TestBone = 'B_ENTERPOINT_LB';
			break;
		case Positions[POSITION_RB]:
			TestBone = 'B_ENTERPOINT_RB';
			break;
		default:
			}
			TempDriver.SetCollision(True, True);
			if (!CheckDriverCanExit(TempDriver, TestBone))
			{
				TempDriver.SetCollision(bOldCollideActors, bOldBlockActors);
				return false;
			}
			TempDriver.SetCollision(bOldCollideActors, bOldBlockActors);
			HMMWVSeatedOccupantAnimManager(EntryVehicle.AnimManager).DestVehicle = EntryBoard;
			HMMWVSeatedOccupantAnimManager(EntryVehicle.AnimManager).PlayVehicleExitToRunningBoardAnim();
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (Vehicle(User) != None && !EntryVehicle.bReservedOccupation)
		{
			if (!HMMWVAnimManager(Vehicle(User).AnimManager).bBusyAnimating && !bTransitioningCenter || bSideStep)
			{
				EntryVehicle.bReservedOccupation = true;
				Vehicle(User).ServerRemoveSeatbelt();
				if (bSideStep)
				{
					HMMWVSeatedOccupantAnimManager(Vehicle(User).AnimManager).PlayVehicleTransitionToSideSeatAnim(EntryVehicle);
				}
				else
				{
					HMMWVSeatedOccupantAnimManager(Vehicle(User).AnimManager).PlayVehicleTransitionToCenterAnim(EntryVehicle);
				}
				return true;
			}
			return false;
			HMMWVSeatedOccupantAnimManager(Vehicle(User).AnimManager).PlayVehicleTransitionToCenterAnim(EntryVehicle);
			return true;
			return false;
		}
		else
		{
			EntryBoard.AnimManager.SetOwner(User);
			HMMWVRunningBoardAnimManager(EntryBoard.AnimManager).ClientBeginEnterVehicle(User, Self);
			HMMWVRunningBoardAnimManager(EntryBoard.AnimManager).ServerBeginEnterVehicle(User, EntryVehicle, EntryBoard);
		}
	}
	*/
	return true;
}

void ACROWS_HMMWV::Ignition()
{
	/*
	local float StartupDelay;
	if (!bHitIgnition && !bVehicleDisabled && Shifter == 0)
	{
		if (PlayerController(Controller).PlayerReplicationInfo != None && !PlayerController(Controller).PlayerReplicationInfo.bQualifiedDriveHMMWV && Level.NetMode != 0)
		{
			PlayerController(Controller).ClientNotifyAdminMessage("You are not qualified to start the HMMWV");
			Return;
		}
		if (IdleSound != None && StartUpSound != None)
		{
			PlayEngineStartUpSound();
			StartupDelay = Abs(GetSoundDuration(StartUpSound) - 0.2);
			SetCustomTimer(StartupDelay, True, 'IdleSoundTimer');
		}
		if (HMMWVAnimManager(AnimManager) != None)
		{
			HMMWVAnimManager(AnimManager).PlayActionAnim();
		}
		bHitIgnition = true;
		ClientSetIgnition(True);
	}
	*/
}

void ACROWS_HMMWV::DevSuperJump()
{
	bJumpIt = true;
}

void ACROWS_HMMWV::ClientSetIgnition(bool bNewHitIgnition)
{
	/*
	local float StartupDelay;
	local bool bOldHitIgnition;
	bOldHitIgnition = bHitIgnition;
	bHitIgnition = bNewHitIgnition;
	if (bHitIgnition)
	{
		if (!bOldHitIgnition)
		{
			PlayEngineStartUpSound();
			StartupDelay = Abs(GetSoundDuration(StartUpSound) - 0.2);
			SetCustomTimer(StartupDelay, True, 'IdleSoundTimer');
		}
		BodyPanels[PANEL_SteeringWheel].PassengerHintText[POSITION_LF] = "";
		BodyPanels[PANEL_Dashboard].PassengerHintText[POSITION_LF] = "";
	}
	else
	{
		BodyPanels[PANEL_SteeringWheel].PassengerHintText[POSITION_LF] = SteeringWheelHintText;
		BodyPanels[PANEL_Dashboard].PassengerHintText[POSITION_LF] = SteeringWheelHintText;
	}
	*/
}

void ACROWS_HMMWV::CalcRearView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local name RearViewBone;
	if (Driver != None)
	{
		Driver.bOwnerNoSee = false;
	}
	if (!bRearViewIsLeft)
	{
		RearViewBone = 'B_RearviewMirror_R';
	}
	else
	{
		RearViewBone = 'B_RearviewMirror_L';
	}
	ViewActor = Driver;
	CameraLocation = GetBoneCoords(RearViewBone).Origin;
	CameraRotation = GetBoneRotation(RearViewBone);
	*/
}

void ACROWS_HMMWV::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Quat FowardLookQuat;
	local Object.Quat ControllerLookQuat;
	local Object.Vector TmpCameraLocation;
	local Object.Rotator TmpCameraRotation;
	local AGP.HumanController HC;
	UpdateAttachedActorLocations();
	HC = HumanController(PC);
	if (Driver == None)
	{
		Return;
	}
	Driver.bOwnerNoSee = true;
	ViewActor = Driver;
	TmpCameraLocation = Driver.GetBoneCoords(CameraBone).Origin;
	FowardLookQuat = QuatFromRotator(Driver.GetBoneRotation(CameraBone));
	FowardLookQuat = QuatProduct(QuatFromRotator(rot(16384 16384 0)), FowardLookQuat);
	if (PC.bTrackIREnabled)
	{
		PC.SetRotation(PC.Rotation + MakeRot(-PC.fpTrackIRPitch - PC.fpTrackIRLastPitch, -PC.fpTrackIRYaw - PC.fpTrackIRLastYaw, 0));
	}
	ControllerLookQuat = QuatFromRotator(PC.Rotation);
	TmpCameraRotation = QuatToRotator(QuatProduct(ControllerLookQuat, FowardLookQuat));
	CameraLocation = TmpCameraLocation;
	CameraRotation = TmpCameraRotation;
	HC.LastViewLocation = CameraLocation;
	HC.LastViewRotation = CameraRotation;
	*/
}

void ACROWS_HMMWV::SpecialSetFirstPersonViewRotation(APlayerController* PC, FRotator CameraRotation)
{
	/*
	local Object.Quat FowardLookQuat;
	local Object.Quat ControllerLookQuat;
	FowardLookQuat = QuatFromRotator(Driver.GetBoneRotation(CameraBone));
	FowardLookQuat = QuatProduct(QuatFromRotator(rot(16384 16384 0)), FowardLookQuat);
	ControllerLookQuat = QuatProduct(QuatFromRotator(CameraRotation), QuatInvert(FowardLookQuat));
	PC.SetRotation(QuatToRotator(ControllerLookQuat));
	*/
}
	
bool ACROWS_HMMWV::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC == None)
	{
		return false;
	}
	PC.bBehindView = false;
	Driver.Velocity = vect(0 0 0);
	if (bIsRearView)
	{
		CalcRearView(PC, ViewActor, CameraLocation, CameraRotation);
	}
	else
	{
		SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
	}
	LastCameraCalcTime = Level.TimeSeconds;
	*/
	return true;
}

void ACROWS_HMMWV::ServerTryToShiftHiLoGears()
{
	/*
	if (bCanShiftHiLo)
	{
		ServerShiftHiLoGears();
		bCanShiftHiLo = false;
		SetCustomTimer(ShiftDelay, False, 'ShiftHiLoTimer');
	}
	*/
}

void ACROWS_HMMWV::ShiftHiLoTimer()
{
	bCanShiftHiLo = true;
}

void ACROWS_HMMWV::ServerShiftHiLoGears()
{
	/*
	if (CarMPH <= 5)
	{
		if (!bIsInHighGear)
		{
			bIsInHighGear = true;
		}
		else
		{
			bIsInHighGear = false;
		}
		PlaySound(ShiftGearsSound, 0, ShiftVolume, False, ShiftRadius);
	}
	*/
}

void ACROWS_HMMWV::ServerTryToShiftDriveGears(bool ShiftUp)
{
	/*
	if (bCanShiftDrive)
	{
		ServerShiftDriveGears(ShiftUp);
		bCanShiftDrive = false;
		SetCustomTimer(ShiftDelay, False, 'ShiftDriveTimer');
	}
	*/
}

void ACROWS_HMMWV::ShiftDriveTimer()
{
	bCanShiftDrive = true;
}

void ACROWS_HMMWV::ServerShiftDriveGears(bool ShiftUp)
{
	/*
	local eShifterState OldShifter;
	OldShifter = Shifter;
	if (CarMPH <= 10)
	{
		Switch(Shifter)
		{
		case 2:
			if (ShiftUp)
			{
				Shifter = 1;
				break;
			}
			Shifter = 2;
		}
		case 0:
			if (ShiftUp)
			{
				Shifter = 0;
			}
			else
			{
				Shifter = 1;
			}
		case 1:
			if (ShiftUp)
			{
				Shifter = 0;
			}
			else
			{
				Shifter = 2;
			}
		default:
	}
	if (OldShifter != Shifter)
	{
		PlaySound(ShiftGearsSound, 0, ShiftVolume, False, ShiftRadius);
	}
	*/
}

void ACROWS_HMMWV::ServerSetSeatbelt()
{
	//Seatbelt.SetStaticMesh(SeatBeltOnMesh);
	//Super::ServerSetSeatbelt();
}

void ACROWS_HMMWV::ServerRemoveSeatbelt()
{
	//Seatbelt.SetStaticMesh(SeatBeltOffMesh);
	//Super::ServerRemoveSeatbelt();
}

void ACROWS_HMMWV::GetDamageModifier(int32 BodyPanelID, UaDamageType* DamageType, int32 Damage)
{
	/*
	if (class<ProjectileDamage>(DamageType) != None && class<ProjectileDamageT62A115mmHE>(DamageType) == None)
	{
		BodyPanels[BodyPanelID].HandleDamage(Damage, 0);
	}
	else
	{
		if (class<ExplosionDamage>(DamageType) != None || class<RocketAT4Damage>(DamageType) != None || class<RocketRPGDamage>(DamageType) != None || class<MortarDamage>(DamageType) != None || class<ProjectileDamageT62A115mmHE>(DamageType) != None)
		{
			BodyPanels[BodyPanelID].HandleDamage(Damage, 1);
		}
	}
	*/
}

void ACROWS_HMMWV::NotifyVehiclePanelDamaged(int32 PanelID, int32 DamageLevel)
{
	/*
	if (PanelID == PANEL_Hood && DamageLevel > 0 && bHitIgnition || DamageLevel >= 2)
	{
		PlayEngineDamagedSounds(DamageLevel >= 2);
	}
	bDisturbedDamage = true;
	*/
}

void ACROWS_HMMWV::NotifyVehiclePanelDestroyed(int32 PanelID)
{
	/*
	Switch(PanelID)
	{
		case PANEL_Hood:
			bVehicleDisabled = true;
			Health = 0;
			if (IdleSound != None)
			{
				BodyPanels[PANEL_Hood].StopSound(IdleSound);
				IdleSound = None;
			}
			if (EngineDamagedIdleSound != None)
			{
				StopSound(EngineDamagedIdleSound);
				EngineDamagedIdleSound = None;
			}
			bHoodDisabled = true;
			break;
		case PANEL_Wheel_LF:
			if (BodyPanels[PanelID].DamageIndex == BodyPanels[PanelID].ExplosionDamageThreshholds.Length - 1)
			{
				Wheels[3].WheelRadius = FlatTireRadius;
				WheelRadii[3] = Wheels[3].WheelRadius;
				DriftFactor += 0.5;
				WheelsDestroyed++;
			}
			break;
		case PANEL_Wheel_RF:
			if (BodyPanels[PanelID].DamageIndex == BodyPanels[PanelID].ExplosionDamageThreshholds.Length - 1)
			{
				Wheels[2].WheelRadius = FlatTireRadius;
				WheelRadii[2] = Wheels[2].WheelRadius;
				DriftFactor -= 0.5;
				WheelsDestroyed++;
			}
			break;
		case PANEL_Wheel_LB:
			if (BodyPanels[PanelID].DamageIndex == BodyPanels[PanelID].ExplosionDamageThreshholds.Length - 1)
			{
				Wheels[1].WheelRadius = FlatTireRadius;
				WheelRadii[1] = Wheels[1].WheelRadius;
				DriftFactor += 0.25;
				WheelsDestroyed++;
			}
			break;
		case PANEL_Wheel_RB:
			if (BodyPanels[PanelID].DamageIndex == BodyPanels[PanelID].ExplosionDamageThreshholds.Length - 1)
			{
				Wheels[0].WheelRadius = FlatTireRadius;
				WheelRadii[0] = Wheels[0].WheelRadius;
				DriftFactor -= 0.25;
				WheelsDestroyed++;
			}
			break;
		default:
	}
	if (WheelsDestroyed >= 3)
	{
		DebugLog(DEBUG_Vehicle, "Wheels are destroyed, disabling vehicle...");
		bVehicleDisabled = true;
		Health = 0;
	}
	*/
}

void ACROWS_HMMWV::TakeImpactDamage(float AccelMag)
{
	/*
	local int32 DamageDir;
	local int32 DamageRootPanel;
	local int32 DamageToPassengers;
	local float LocationalDamageArray;
	local float DamageModifier;
	local float DamageToPanels;
	local int32 i;
	if (AccelMag < 1000 && !bVehicleUpsideDownLastCheck || AccelMag < 2500)
	{
		Return;
	}
	DamageModifier = 1;
	if (bVehicleUpsideDownLastCheck)
	{
		DamageModifier *= 3;
	}
	PlaySound(CollisionSound, 0, FMax(AccelMag - 7000, 0) / 15000, , FMax(AccelMag - 7000, 0) / 15000 * 2000);
	DamageToPassengers = AccelMag / 12500 * *3 * DamageModifier;
	DamageToPanels = AccelMag / 7000 * *3;
	DebugLog(DEBUG_Vehicle, "=== COLLISION! === Acceleration:" $ AccelMag $ " Damage to Passengers:" $ DamageToPassengers $ " Damage to Panels:" $ DamageToPanels * DamageModifier);
	DamageDir = Rotation.Yaw - KParams.KAcceleration.Yaw;
	if (DamageDir < 0)
	{
		DamageDir += 65536;
	}
	if (DamageDir > 24576 && DamageDir < 40960)
	{
		DamageRootPanel = PANEL_Hood;
		LocationalDamageArray[POSITION_LF] = 1;
		LocationalDamageArray[POSITION_LB] = 1;
		LocationalDamageArray[POSITION_RF] = 1;
		LocationalDamageArray[POSITION_RB] = 1;
		LocationalDamageArray[POSITION_LFBoard] = 2;
		LocationalDamageArray[POSITION_LBBoard] = 2;
		LocationalDamageArray[POSITION_RFBoard] = 2;
		LocationalDamageArray[POSITION_RBBoard] = 2;
	}
	else
	{
		if (DamageDir < 8192 || DamageDir > 57344)
		{
			DamageRootPanel = PANEL_TrunkLid;
			LocationalDamageArray[POSITION_LF] = 1;
			LocationalDamageArray[POSITION_LB] = 1;
			LocationalDamageArray[POSITION_RF] = 1;
			LocationalDamageArray[POSITION_RB] = 1;
			LocationalDamageArray[POSITION_LFBoard] = 2;
			LocationalDamageArray[POSITION_LBBoard] = 2;
			LocationalDamageArray[POSITION_RFBoard] = 2;
			LocationalDamageArray[POSITION_RBBoard] = 2;
		}
		else
		{
			if (DamageDir >= 8192 && DamageDir <= 24576)
			{
				DamageRootPanel = PANEL_Body_R;
				LocationalDamageArray[POSITION_LF] = 0.75;
				LocationalDamageArray[POSITION_LB] = 0.75;
				LocationalDamageArray[POSITION_RF] = 1;
				LocationalDamageArray[POSITION_RB] = 1;
				LocationalDamageArray[POSITION_LFBoard] = 2;
				LocationalDamageArray[POSITION_LBBoard] = 2;
				LocationalDamageArray[POSITION_RFBoard] = 2;
				LocationalDamageArray[POSITION_RBBoard] = 2;
			}
			else
			{
				if (DamageDir <= 57344 && DamageDir >= 40960)
				{
					DamageRootPanel = PANEL_Body_L;
					LocationalDamageArray[POSITION_LF] = 1;
					LocationalDamageArray[POSITION_LB] = 1;
					LocationalDamageArray[POSITION_RF] = 0.75;
					LocationalDamageArray[POSITION_RB] = 0.75;
					LocationalDamageArray[POSITION_LFBoard] = 2;
					LocationalDamageArray[POSITION_LBBoard] = 2;
					LocationalDamageArray[POSITION_RFBoard] = 2;
					LocationalDamageArray[POSITION_RBBoard] = 2;
				}
			}
		}
	}
	BodyPanels[DamageRootPanel].HandleDamage(DamageToPanels, 2);
	for (i = 0; i < BodyPanels[DamageRootPanel].LinkedPanels.Length; i++)
	{
		BodyPanels[DamageRootPanel].LinkedPanels[i].HandleDamage(DamageToPanels * DamageModifier, 2);
	}
	if (Driver != None)
	{
		if (bWearingSeatbelt)
		{
			DebugLog(DEBUG_Vehicle, "Driver Damage Received: " $ LocationalDamageArray[POSITION_LF] * DamageToPassengers);
			Driver.TakeDamage(LocationalDamageArray[POSITION_LF] * DamageToPassengers, Self, Self.Location, vect(0 0 0), Class'VehicleDamage');
		}
		else
		{
			DebugLog(DEBUG_Vehicle, "Driver Damage Received: " $ LocationalDamageArray[POSITION_LF] * DamageToPassengers * NoSeatbeltMultiplier);
			Driver.TakeDamage(LocationalDamageArray[POSITION_LF] * DamageToPassengers * NoSeatbeltMultiplier, Self, Self.Location, vect(0 0 0), Class'VehicleDamage');
		}
	}
	for (i = 0; i < Positions.Length; i++)
	{
		if (Positions[i] != None && Positions[i].Driver != None)
		{
			if (Positions[i].bWearingSeatbelt)
			{
				DebugLog(DEBUG_Vehicle, "Passenger Damage Received: " $ LocationalDamageArray[i] * DamageToPassengers);
				Positions[i].Driver.TakeDamage(LocationalDamageArray[i] * DamageToPassengers, Self, Self.Location, vect(0 0 0), Class'VehicleDamage');
			}
			else
			{
				DebugLog(DEBUG_Vehicle, "Passenger Damage Received: " $ LocationalDamageArray[i] * DamageToPassengers * NoSeatbeltMultiplier);
				Positions[i].Driver.TakeDamage(LocationalDamageArray[i] * DamageToPassengers * NoSeatbeltMultiplier, Self, Self.Location, vect(0 0 0), Class'VehicleDamage');
			}
		}
	}
	*/
}

void ACROWS_HMMWV::TakeRollOverDamage()
{
}

void ACROWS_HMMWV::SpawnHoodEmitter()
{
	/*
	local Object.BoneOffset BO;
	if (HMMWVHoodSmokeEmitter == None)
	{
		HMMWVHoodSmokeEmitter = Spawn(Class'fx_hmmwvsmallsmoke', Self, , Location, rot(16384 0 0));
		BO.VOffset = vect(0 - 10 10);
		BO.nBone = 'B_Hood';
		HMMWVHoodSmokeEmitter.SetBase(Self);
		AttachToBoneOffset(HMMWVHoodSmokeEmitter, BO);
		SetCustomTimer(0.1, False, 'ActivateSmoke');
	}
	*/
}

void ACROWS_HMMWV::ActivateSmoke()
{
	/*
	if (HMMWVHoodSmokeEmitter != None)
	{
		HMMWVHoodSmokeEmitter.Emitters[0].Disabled = false;
	}
	*/
}

void ACROWS_HMMWV::SuspensionThreshold(float DeltaTravel)
{
	/*
	local int32 TmpSqueak;
	TmpSqueak = Rand(5);
	if (TmpSqueak == LastSusRandSqueak)
	{
		TmpSqueak = Rand(5);
	}
	PlaySound(SuspensionSqueaksSound[TmpSqueak], 1, Abs(DeltaTravel) / 7, , 512, 1 + Clamp(Abs(DeltaTravel) / 7, 0, 1));
	LastSusRandSqueak = TmpSqueak;
	*/
}
void ACROWS_HMMWV::RollThreshold(float DeltaRoll)
{
	/*
	local int32 TmpSqueak;
	TmpSqueak = Rand(3);
	if (TmpSqueak == LastRollRandSqueak)
	{
		TmpSqueak = Rand(3);
	}
	PlaySound(FrameSqueaksSound[TmpSqueak], 2, Abs(DeltaRoll) / 30, , 512, 0.8 + Clamp(DeltaRoll / 9, 0, 1.2));
	LastRollRandSqueak = TmpSqueak;
	*/
}
void ACROWS_HMMWV::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	DisplayVehicleDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("Stopwatch: " $ StopwatchTime);
	YPos += YL;
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("Gear: " $ Gear $ "    CarMPH: " $ CarMPH);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("EngineRPM: " $ EngineRPM);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("IdleRPM: " $ IdleRPM);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("EngineInertia: " $ EngineInertia);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("Seatbelt: " $ bWearingSeatbelt);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Switch(Shifter)
	{
		case 0:
			Canvas.DrawText("Gear: PARK");
			break;
		case 1:
			Canvas.DrawText("Gear: DRIVE");
			break;
		case 2:
			Canvas.DrawText("Gear: REVERSE");
			break;
		default:
	}
	YPos += YL;
	Canvas.SetPos(0, YPos);
	if (bIsInHighGear)
	{
		Canvas.DrawText("High Gear");
	}
	else
	{
		Canvas.DrawText("Low Gear");
	}
	YPos += YL;
	Canvas.DrawText("Timer: " $ TimerCounter $ " LifeSpan " $ LifeSpan $ " AmbientSound " $ AmbientSound $ " volume " $ SoundVolume);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	*/
}
/*
void ACROWS_HMMWV::DisplayDebug(Canvas Canvas, out float YL, out float YPos)
{
	DisplayVehicleDebug(Canvas, YL, YPos);
}
*/
/*
void ACROWS_HMMWV::TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, UaDamageType* DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	local int32 i;
	if (class<ProjectileDamageT62A115mmHE>(DamageType) != None || class<ProjectileDamageBMPAutoCannon>(DamageType) != None)
	{
		if (Pawn(instigatedBy.Owner) != None)
		{
			instigatedBy = Pawn(instigatedBy.Owner);
			KillerController = instigatedBy.Controller;
		}
		if (Driver != None)
		{
			Driver.TakeDamage(500, instigatedBy, HitLocation, Momentum, DamageType);
		}
		for (i = 0; i < Positions.Length; i++)
		{
			if (Positions[i] != None && Positions[i].Driver != None)
			{
				if (Positions[i].bWearingSeatbelt)
				{
					Positions[i].Driver.TakeDamage(500, instigatedBy, HitLocation, Momentum, DamageType);
				}
				else
				{
					Positions[i].Driver.TakeDamage(500, instigatedBy, HitLocation, Momentum, DamageType);
				}
			}
		}
	}
	Return;
}
*/
void ACROWS_HMMWV::Timer()
{
	//MakeNoise(1, Self);
}


