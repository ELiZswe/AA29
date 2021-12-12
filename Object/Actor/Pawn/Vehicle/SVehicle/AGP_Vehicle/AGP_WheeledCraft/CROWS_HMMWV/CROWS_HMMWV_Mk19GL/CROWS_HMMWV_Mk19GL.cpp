// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_Mk19GL/CROWS_HMMWV_Mk19GL.h"

ACROWS_HMMWV_Mk19GL::ACROWS_HMMWV_Mk19GL()
{
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
	//StartBodyPanels(23) = ({ Class'AGP.BodyPanel',StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_CROWS_Interface_01a',"B_CROWS_Interface","None",0,-1,"",class'None',1,0,0 })
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
	//PositionTypes(0) = ({ class'AGP_Vehicles.CROWS_GunnerMk19GL',"B_Roof","B_Sitbone_LB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.HMMWV_Passenger',"None","B_Sitbone_RF",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(2) = ({ class'AGP_Vehicles.HMMWV_RearPassenger',"None","B_Sitbone_RB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(3) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerLF',"None","B_Sitbone_LF",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(4) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerLB',"None","B_Sitbone_LB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(5) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerRF',"None","B_Sitbone_RF",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) })
	//PositionTypes(6) = ({ class'AGP_Vehicles.HMMWV_RunningBoardPassengerRB',"None","B_Sitbone_RB",FVector(0, 0, 0),FVector(0, 0, 8),FRotator(0,0,0) });
}
