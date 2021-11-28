// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/ChevySuburban/ChevySuburban.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

AChevySuburban::AChevySuburban()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 5;
	KParams0->KInertiaTensor[3] = 10.5;
	KParams0->KInertiaTensor[5] = 12;
	KParams0->KCOMOffset = FVector(0.2, 0, 0.161);
	KParams0->KLinearDamping = 0.06;
	KParams0->KAngularDamping = 0.005;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 3600;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	KParams0->KRestitution = 0.2;
	KParams0->KImpactThreshold = 500;
	UVehicleEntryPoint* Front_Left_Entry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	Front_Left_Entry->bDriverEntry = true;
	Front_Left_Entry->EntryBone = "Entry_Driver_bone";
	UVehicleEntryPoint* Front_Right_Entry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	Front_Right_Entry->EntryBone = "Entry_Passenger_1_bone";
	Front_Right_Entry->PositionIndex = { 0 };
	UVehicleEntryPoint* Middle_Left_Entry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	Middle_Left_Entry->EntryBone = "Entry_Passenger_2_bone";
	Middle_Left_Entry->PositionIndex = { 1, 3 };
	UVehicleEntryPoint* Middle_Right_Entry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	Middle_Right_Entry->EntryBone = "Entry_Passenger_3_bone";
	Middle_Right_Entry->PositionIndex = { 2, 4 };
	UVehicleDamageZone* Front_Left_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left_Panel->ArmorThreshold = 3;
	Front_Left_Panel->MaxHitPoints = 1000;
	//Front_Left_Panel->DamageStates(0) = ({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Left_Panel->DamageStates(1) = ({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Front_Left_Panel->DamageStates(2) = ({ "DS2_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Front_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Middle->ArmorThreshold = 2;
	Front_Middle->MaxHitPoints = 1000;
	//Front_Middle->DamageStates(0) = ({ "body_middle_1_bone","Hood_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Middle->DamageStates(1) = ({ "DS1_body_middle_1_bone","DS1_Hood_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage' });
	//Front_Middle->DamageStates(2) = ({ "DS2_body_middle_1_bone","DS2_Hood_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed' });
	UVehicleDamageZone* Front_Right_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right_Panel->ArmorThreshold = 3;
	Front_Right_Panel->MaxHitPoints = 1000;
	//Front_Right_Panel->DamageStates(0) = ({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Right_Panel->DamageStates(1) = ({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Front_Right_Panel->DamageStates(2) = ({ "DS2_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Front_Left_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left_Door->ArmorThreshold = 3;
	Front_Left_Door->MaxHitPoints = 1000;
	//Front_Left_Door->DamageStates(0) = ({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Left_Door->DamageStates(1) = ({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Front_Left_Door->DamageStates(2) = ({ "DS2_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Front_Right_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right_Door->ArmorThreshold = 3;
	Front_Right_Door->MaxHitPoints = 1000;
	//Front_Right_Door->DamageStates(0) = ({ "body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Front_Right_Door->DamageStates(1) = ({ "DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Front_Right_Door->DamageStates(2) = ({ "DS2_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Middle_Left_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Left_Door->ArmorThreshold = 3;
	Middle_Left_Door->MaxHitPoints = 1000;
	//Middle_Left_Door->DamageStates(0) = ({ "body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Middle_Left_Door->DamageStates(1) = ({ "DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Middle_Left_Door->DamageStates(2) = ({ "DS2_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Middle_Right_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Right_Door->ArmorThreshold = 3;
	Middle_Right_Door->MaxHitPoints = 1000;
	//Middle_Right_Door->DamageStates(0) = ({ "body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Middle_Right_Door->DamageStates(1) = ({ "DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Middle_Right_Door->DamageStates(2) = ({ "DS2_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Rear_Left_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left_Panel->ArmorThreshold = 3;
	Rear_Left_Panel->MaxHitPoints = 1000;
	//Rear_Left_Panel->DamageStates(0) = ({ "body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Left_Panel->DamageStates(1) = ({ "DS1_body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Rear_Left_Panel->DamageStates(2) = ({ "DS2_body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Rear_Right_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right_Panel->ArmorThreshold = 3;
	Rear_Right_Panel->MaxHitPoints = 1000;
	//Rear_Right_Panel->DamageStates(0) = ({ "body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Right_Panel->DamageStates(1) = ({ "DS1_body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Rear_Right_Panel->DamageStates(2) = ({ "DS2_body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Side_Front_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Left_Window->MaxHitPoints = 1000;
	//Side_Front_Left_Window->DamageStates(0) = ({ "window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Front_Left_Window->DamageStates(1) = ({ "DS1_window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Side_Front_Left_Window->bNoPassDamageToVehicle = true;
	Side_Front_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Middle_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Middle_Left_Window->MaxHitPoints = 1000;
	//Side_Middle_Left_Window->DamageStates(0) = ({ "window_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Middle_Left_Window->DamageStates(1) = ({ "DS1_window_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Side_Middle_Left_Window->bNoPassDamageToVehicle = true;
	Side_Middle_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Rear_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Left_Window->MaxHitPoints = 1000;
	//Side_Rear_Left_Window->DamageStates(0) = ({ "window_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Rear_Left_Window->DamageStates(1) = ({ "DS1_window_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Side_Rear_Left_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Wheel_Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Front_Left->ArmorThreshold = 2;
	Wheel_Front_Left->DamageModifier = 10;
	Wheel_Front_Left->MaxHitPoints = 1000;
	Wheel_Front_Left->bWheelZone = true;
	Wheel_Front_Left->WheelNum = 3;
	//Wheel_Front_Left->DamageStates(0) = ({ "wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Front_Left->DamageStates(1) = ({ "ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Front_Left->DamageStates(2) = ({ "ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Front_Left->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Rear_Left->ArmorThreshold = 2;
	Wheel_Rear_Left->DamageModifier = 10;
	Wheel_Rear_Left->MaxHitPoints = 1000;
	Wheel_Rear_Left->bWheelZone = true;
	Wheel_Rear_Left->WheelNum = 1;
	//Wheel_Rear_Left->DamageStates(0) = ({ "wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Rear_Left->DamageStates(1) = ({ "ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Rear_Left->DamageStates(2) = ({ "ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Rear_Left->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Side_Rear_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Right_Window->MaxHitPoints = 1000;
	//Side_Rear_Right_Window->DamageStates(0) = ({ "window_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Rear_Right_Window->DamageStates(1) = ({ "DS1_window_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Side_Rear_Right_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Middle_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Middle_Right_Window->MaxHitPoints = 1000;
	//Side_Middle_Right_Window->DamageStates(0) = ({ "window_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Middle_Right_Window->DamageStates(1) = ({ "DS1_window_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Side_Middle_Right_Window->bNoPassDamageToVehicle = true;
	Side_Middle_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Front_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Right_Window->MaxHitPoints = 1000;
	//Side_Front_Right_Window->DamageStates(0) = ({ "window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Side_Front_Right_Window->DamageStates(1) = ({ "DS1_window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Side_Front_Right_Window->bNoPassDamageToVehicle = true;
	Side_Front_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Wheel_Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Rear_Right->ArmorThreshold = 2;
	Wheel_Rear_Right->DamageModifier = 10;
	Wheel_Rear_Right->MaxHitPoints = 1000;
	Wheel_Rear_Right->bWheelZone = true;
	//Wheel_Rear_Right->DamageStates(0) = ({ "wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Rear_Right->DamageStates(1) = ({ "ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Rear_Right->DamageStates(2) = ({ "ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Rear_Right->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Front_Right->ArmorThreshold = 2;
	Wheel_Front_Right->DamageModifier = 10;
	Wheel_Front_Right->MaxHitPoints = 1000;
	Wheel_Front_Right->bWheelZone = true;
	Wheel_Front_Right->WheelNum = 2;
	//Wheel_Front_Right->DamageStates(0) = ({ "wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Front_Right->DamageStates(1) = ({ "ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Front_Right->DamageStates(2) = ({ "ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Front_Right->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Windshield->MaxHitPoints = 1000;
	//Windshield->DamageStates(0) = ({ "Windshield_1_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Windshield->DamageStates(1) = ({ "DS1_Windshield_1_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Windshield->bNoPassDamageToVehicle = true;
	Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Rear_Hatch = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Hatch->MaxHitPoints = 1000;
	//Rear_Hatch->DamageStates(0) = ({ "hatch_1_bone","window_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Hatch->DamageStates(1) = ({ "DS1_hatch_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'None' });
	//Rear_Hatch->DamageStates(2) = ({ "DS2_hatch_1_bone","DS1_window_1_bone","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Rear_Hatch->bNoPassDamageToVehicle = true;
	Rear_Hatch->PenetrationPercent = 1;
	UVehicleDamageZone* Rear_Tailgate = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Tailgate->ArmorThreshold = 3;
	Rear_Tailgate->MaxHitPoints = 1000;
	//Rear_Tailgate->DamageStates(0) = ({ "tailgate_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Rear_Tailgate->DamageStates(1) = ({ "DS1_tailgate_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Rear_Tailgate->DamageStates(2) = ({ "DS2_tailgate_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->BoneName = "wheel_right_2_bone";
	RRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelBoneOffset = FVector(0, 8, 0);
	RRWheel->WheelRadius = 24;
	RRWheel->FlatWheelRadius = 20;
	RRWheel->RimWheelRadius = 16;
	RRWheel->SupportBoneName = "suspension_rear_right_1_bone";
	RRWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->BoneName = "wheel_left_2_bone";
	LRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelBoneOffset = FVector(0, -8, 0);
	LRWheel->WheelRadius = 24;
	LRWheel->FlatWheelRadius = 20;
	LRWheel->RimWheelRadius = 16;
	LRWheel->SupportBoneName = "suspension_rear_left_1_bone";
	LRWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->SteerType = EVehicleSteerType::VST_Steered;
	RFWheel->BoneName = "wheel_right_1_bone";
	RFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelBoneOffset = FVector(0, 8, 0);
	RFWheel->WheelRadius = 24;
	RFWheel->FlatWheelRadius = 20;
	RFWheel->RimWheelRadius = 16;
	RFWheel->SupportBoneName = "suspension_front_right_1_bone";
	RFWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->SteerType = EVehicleSteerType::VST_Steered;
	LFWheel->BoneName = "wheel_left_1_bone";
	LFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelBoneOffset = FVector(0, -8, 0);
	LFWheel->WheelRadius = 24;
	LFWheel->FlatWheelRadius = 20;
	LFWheel->RimWheelRadius = 16;
	LFWheel->SupportBoneName = "suspension_front_left_1_bone";
	LFWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	WheelSoftness = 0.025;
	WheelPenScale = 1.6;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.2;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 1.5;
	WheelLatFrictionScale = 1;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 5;
	FTScale = 0.04;
	ChassisTorqueScale = 0.2;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.86,0.43,0.74,1.23,1.85 };
	TransRatio = 0.15;
	ChangeUpPoint = 3500;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 8E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	EngineInertia = 0.025;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	SteerBoneName = "steering_wheel_1_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//PositionTypes(0) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_1_Bone",FVector(35, 25, 60),FVector(5, 0, -5),FRotator(0,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_2_bone",FVector(-20, -25, 60),FVector(5, 0, -10),FRotator(0,0,0) })
	//PositionTypes(2) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_3_bone",FVector(-20, 25, 60),FVector(5, 0, -10),FRotator(0,0,0) })
	//PositionTypes(3) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_4_bone",FVector(-70, -25, 60),FVector(5, 0, -10),FRotator(0,32768,0) })
	//PositionTypes(4) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_5_bone",FVector(-70, 25, 60),FVector(5, 0, -10),FRotator(0,32768,0) });
	EntryPoints = { Front_Left_Entry,Front_Right_Entry,Middle_Left_Entry,Middle_Right_Entry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/ChevySuburban/SUV_Idle_Lp_1_Que.SUV_Idle_Lp_1_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/ChevySuburban/SUV_Start_1_Que.SUV_Start_1_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/suburban/Suburban_Static.Suburban_Static'"), NULL, LOAD_None, NULL);
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = {
		Front_Left_Panel,
		Front_Middle,
		Front_Right_Panel,
		Front_Left_Door,
		Front_Right_Door,
		Middle_Left_Door,
		Middle_Right_Door,
		Rear_Left_Panel,
		Rear_Right_Panel,
		Side_Front_Left_Window,
		Side_Middle_Left_Window,
		Side_Rear_Left_Window,
		Wheel_Front_Left,
		Wheel_Rear_Left,
		Side_Rear_Right_Window,
		Side_Middle_Right_Window,
		Side_Front_Right_Window,
		Wheel_Rear_Right,
		Wheel_Front_Right,
		Windshield,
		Rear_Hatch,
		Rear_Tailgate,
	};
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	VehicleMass = 4;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "SF_Humvee_Driver_turn_Idle";
	DriverPosOffset = FVector(4, 0, 0);
	DriverRotOffset = FRotator(1600, 0, 0);
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165, -100) };
	FPCamPos = FVector(35, -25, 60);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a Chevy Suburban";
	VehicleNameString = "Chevy Suburban";
	ObjectiveGetOutDist = 1500;
	FlagBone = "Dummy01";
	FlagRotation = FRotator(0, 32768, 0);
	GroundSpeed = 1290;
	HealthMax = 1000;
	Health = 1000;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/suburban.suburban'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 175;
	//CollisionHeight = 100;
	KParams = KParams0;

}


/*
void AChevySuburban::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'chevy_suburban_tire');
	L.AddPrecacheMaterial(Texture'chevy_suburban_b');
	L.AddPrecacheMaterial(Texture'chevy_suburban_a');
	L.AddPrecacheMaterial(Shader'suburban_window_final');
	L.AddPrecacheMaterial(Combiner'ds1_combiner_tire');
	L.AddPrecacheMaterial(Shader'ds1_final_body');
	L.AddPrecacheMaterial(Shader'ds1_final_interior');
	L.AddPrecacheMaterial(Shader'suburban_window_final_ds1');
	L.AddPrecacheMaterial(Combiner'ds2_combiner_tire');
	L.AddPrecacheMaterial(Shader'ds2_final_body');
	L.AddPrecacheMaterial(Shader'ds2_final_interior');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AChevySuburban::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AChevySuburban::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'chevy_suburban_tire');
	Level.AddPrecacheMaterial(Texture'chevy_suburban_b');
	Level.AddPrecacheMaterial(Texture'chevy_suburban_a');
	Level.AddPrecacheMaterial(Shader'suburban_window_final');
	Level.AddPrecacheMaterial(Combiner'ds1_combiner_tire');
	Level.AddPrecacheMaterial(Shader'ds1_final_body');
	Level.AddPrecacheMaterial(Shader'ds1_final_interior');
	Level.AddPrecacheMaterial(Shader'suburban_window_final_ds1');
	Level.AddPrecacheMaterial(Combiner'ds2_combiner_tire');
	Level.AddPrecacheMaterial(Shader'ds2_final_body');
	Level.AddPrecacheMaterial(Shader'ds2_final_interior');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	UpdatePrecacheMaterials();
	*/
}