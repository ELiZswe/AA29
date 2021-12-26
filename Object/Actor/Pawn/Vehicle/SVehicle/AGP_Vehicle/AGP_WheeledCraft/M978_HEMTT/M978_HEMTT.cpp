// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M978_HEMTT/M978_HEMTT.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

AM978_HEMTT::AM978_HEMTT()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 15;
	KParams0->KInertiaTensor[3] = 25;
	KParams0->KInertiaTensor[5] = 30;
	KParams0->KCOMOffset = FVector(0, 0, -0.9);
	KParams0->KLinearDamping = 0.02;
	KParams0->KAngularDamping = 0.0015;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2250;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 1;
	KParams0->KRestitution = 0.2;
	KParams0->KImpactThreshold = 500;
	UVehicleEntryPoint* DriverSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	DriverSideEntry->bDriverEntry = true;
	DriverSideEntry->EntryBone = "Entry_Driver_bone";
	UVehicleEntryPoint* Entry_Passenger = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	Entry_Passenger->EntryBone = "Entry_Passenger_2_bone";
	Entry_Passenger->PositionIndex = { 0 };
	UVehicleDamageZone* Body_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_1->ArmorThreshold = 3;
	Body_Right_1->MaxHitPoints = 1000;
	//Body_Right_1->DamageStates(0) = ({ "body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Right_1->DamageStates(1) = ({ "DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Body_Right_1->DamageStates(2) = ({ "DS2_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Body_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_1->ArmorThreshold = 3;
	Body_Left_1->MaxHitPoints = 1000;
	//Body_Left_1->DamageStates(0) = ({ "body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Left_1->DamageStates(1) = ({ "DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Body_Left_1->DamageStates(2) = ({ "DS2_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Body_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_2->ArmorThreshold = 3;
	Body_Right_2->MaxHitPoints = 1000;
	//Body_Right_2->DamageStates(0) = ({ "body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Right_2->DamageStates(1) = ({ "DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage' });
	//Body_Right_2->DamageStates(2) = ({ "DS2_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed' });
	UVehicleDamageZone* Body_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_2->ArmorThreshold = 3;
	Body_Left_2->MaxHitPoints = 1000;
	//Body_Left_2->DamageStates(0) = ({ "body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Left_2->DamageStates(1) = ({ "DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage' });
	//Body_Left_2->DamageStates(2) = ({ "DS2_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed' });
	UVehicleDamageZone* Body_Right_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_3->ArmorThreshold = 3;
	Body_Right_3->MaxHitPoints = 1000;
	//Body_Right_3->DamageStates(0) = ({ "body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Right_3->DamageStates(1) = ({ "DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Body_Right_3->DamageStates(2) = ({ "DS2_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Body_Left_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_3->ArmorThreshold = 3;
	Body_Left_3->MaxHitPoints = 1000;
	//Body_Left_3->DamageStates(0) = ({ "body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Left_3->DamageStates(1) = ({ "DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Body_Left_3->DamageStates(2) = ({ "DS2_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Body_Right_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Right_4->ArmorThreshold = 3;
	Body_Right_4->MaxHitPoints = 1000;
	//Body_Right_4->DamageStates(0) = ({ "body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Right_4->DamageStates(1) = ({ "DS1_body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Body_Right_4->DamageStates(2) = ({ "DS2_body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Body_Left_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Body_Left_4->ArmorThreshold = 3;
	Body_Left_4->MaxHitPoints = 1000;
	//Body_Left_4->DamageStates(0) = ({ "body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Body_Left_4->DamageStates(1) = ({ "DS1_body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Body_Left_4->DamageStates(2) = ({ "DS2_body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Window_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Window_Left->MaxHitPoints = 1000;
	//Window_Left->DamageStates(0) = ({ "window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Window_Left->DamageStates(1) = ({ "DS1_window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Window_Left->bNoPassDamageToVehicle = true;
	Window_Left->PenetrationPercent = 1;
	UVehicleDamageZone* Fuel_Tank_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Fuel_Tank_Left->ArmorThreshold = 3;
	Fuel_Tank_Left->MaxHitPoints = 1000;
	//Fuel_Tank_Left->DamageStates(0) = ({ "Fueltank_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Fuel_Tank_Left->DamageStates(1) = ({ "DS1_Fueltank_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None' });
	//Fuel_Tank_Left->DamageStates(2) = ({ "DS2_Fueltank_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None' });
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 1;
	//Wheel_Left_1->DamageStates(0) = ({ "wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_1->DamageStates(1) = ({ "ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_1->DamageStates(2) = ({ "ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 3;
	//Wheel_Left_2->DamageStates(0) = ({ "wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_2->DamageStates(1) = ({ "ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_2->DamageStates(2) = ({ "ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_3->ArmorThreshold = 2;
	Wheel_Left_3->DamageModifier = 10;
	Wheel_Left_3->MaxHitPoints = 1000;
	Wheel_Left_3->bWheelZone = true;
	Wheel_Left_3->WheelNum = 5;
	//Wheel_Left_3->DamageStates(0) = ({ "Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_3->DamageStates(1) = ({ "DS1_Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_3->DamageStates(2) = ({ "DS2_Wheel_Left_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_3->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_4->ArmorThreshold = 2;
	Wheel_Left_4->DamageModifier = 10;
	Wheel_Left_4->MaxHitPoints = 1000;
	Wheel_Left_4->bWheelZone = true;
	Wheel_Left_4->WheelNum = 7;
	//Wheel_Left_4->DamageStates(0) = ({ "Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Left_4->DamageStates(1) = ({ "DS1_Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Left_4->DamageStates(2) = ({ "DS2_Wheel_Left_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Left_4->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Window_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Window_Right->MaxHitPoints = 1000;
	//Window_Right->DamageStates(0) = ({ "window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Window_Right->DamageStates(1) = ({ "DS1_window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Window_Right->bNoPassDamageToVehicle = true;
	Window_Right->PenetrationPercent = 1;
	UVehicleDamageZone* Wheel_Right_4 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_4->ArmorThreshold = 2;
	Wheel_Right_4->DamageModifier = 10;
	Wheel_Right_4->MaxHitPoints = 1000;
	Wheel_Right_4->bWheelZone = true;
	Wheel_Right_4->WheelNum = 6;
	//Wheel_Right_4->DamageStates(0) = ({ "Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_4->DamageStates(1) = ({ "DS1_Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_4->DamageStates(2) = ({ "DS2_Wheel_Right_4_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_4->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_3 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_3->ArmorThreshold = 2;
	Wheel_Right_3->DamageModifier = 10;
	Wheel_Right_3->MaxHitPoints = 1000;
	Wheel_Right_3->bWheelZone = true;
	Wheel_Right_3->WheelNum = 4;
	//Wheel_Right_3->DamageStates(0) = ({ "Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_3->DamageStates(1) = ({ "DS1_Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_3->DamageStates(2) = ({ "DS2_Wheel_Right_3_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_3->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 2;
	Wheel_Right_2->DamageModifier = 10;
	Wheel_Right_2->MaxHitPoints = 1000;
	Wheel_Right_2->bWheelZone = true;
	Wheel_Right_2->WheelNum = 2;
	//Wheel_Right_2->DamageStates(0) = ({ "wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_2->DamageStates(1) = ({ "ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_2->DamageStates(2) = ({ "ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	//Wheel_Right_1->DamageStates(0) = ({ "wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Wheel_Right_1->DamageStates(1) = ({ "ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat' });
	//Wheel_Right_1->DamageStates(2) = ({ "ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing' });
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Winshield_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Winshield_Right->MaxHitPoints = 1000;
	//Winshield_Right->DamageStates(0) = ({ "windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Winshield_Right->DamageStates(1) = ({ "ds1_windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Winshield_Right->bNoPassDamageToVehicle = true;
	Winshield_Right->PenetrationPercent = 1;
	UVehicleDamageZone* Winshield_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Winshield_Left->MaxHitPoints = 1000;
	//Winshield_Left->DamageStates(0) = ({ "windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None' });
	//Winshield_Left->DamageStates(1) = ({ "ds1_windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None' });
	Winshield_Left->bNoPassDamageToVehicle = true;
	Winshield_Left->PenetrationPercent = 1;
	USVehicleWheel* RWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel1->bPoweredWheel = true;
	RWheel1->SteerType = EVehicleSteerType::VST_Steered;
	RWheel1->BoneName = "wheel_right_1_bone";
	RWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel1->WheelBoneOffset = FVector(0, 25, 0);
	RWheel1->WheelRadius = 48;
	RWheel1->FlatWheelRadius = 42;
	RWheel1->RimWheelRadius = 36;
	USVehicleWheel* LWheel1 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel1->bPoweredWheel = true;
	LWheel1->SteerType = EVehicleSteerType::VST_Steered;
	LWheel1->BoneName = "wheel_left_1_bone";
	LWheel1->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel1->WheelBoneOffset = FVector(0, -25, 0);
	LWheel1->WheelRadius = 48;
	LWheel1->FlatWheelRadius = 42;
	LWheel1->RimWheelRadius = 36;
	USVehicleWheel* RWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel2->bPoweredWheel = true;
	RWheel2->SteerType = EVehicleSteerType::VST_Steered;
	RWheel2->BoneName = "wheel_right_2_bone";
	RWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel2->WheelBoneOffset = FVector(0, 25, 0);
	RWheel2->WheelRadius = 48;
	RWheel2->FlatWheelRadius = 42;
	RWheel2->RimWheelRadius = 36;
	USVehicleWheel* LWheel2 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel2->bPoweredWheel = true;
	LWheel2->SteerType = EVehicleSteerType::VST_Steered;
	LWheel2->BoneName = "wheel_left_2_bone";
	LWheel2->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel2->WheelBoneOffset = FVector(0, -25, 0);
	LWheel2->WheelRadius = 48;
	LWheel2->FlatWheelRadius = 42;
	LWheel2->RimWheelRadius = 36;
	USVehicleWheel* RWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel3->bPoweredWheel = true;
	RWheel3->BoneName = "Wheel_Right_3_Bone";
	RWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel3->WheelBoneOffset = FVector(0, 25, 0);
	RWheel3->WheelRadius = 48;
	RWheel3->FlatWheelRadius = 42;
	RWheel3->RimWheelRadius = 36;
	USVehicleWheel* LWheel3 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel3->bPoweredWheel = true;
	LWheel3->BoneName = "Wheel_Left_3_Bone";
	LWheel3->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel3->WheelBoneOffset = FVector(0, -25, 0);
	LWheel3->WheelRadius = 48;
	LWheel3->FlatWheelRadius = 42;
	LWheel3->RimWheelRadius = 36;
	USVehicleWheel* RWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RWheel4->bPoweredWheel = true;
	RWheel4->BoneName = "Wheel_Right_4_Bone";
	RWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RWheel4->WheelBoneOffset = FVector(0, 25, 0);
	RWheel4->WheelRadius = 48;
	RWheel4->FlatWheelRadius = 42;
	RWheel4->RimWheelRadius = 36;
	USVehicleWheel* LWheel4 = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LWheel4->bPoweredWheel = true;
	LWheel4->BoneName = "Wheel_Left_4_Bone";
	LWheel4->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LWheel4->WheelBoneOffset = FVector(0, -25, 0);
	LWheel4->WheelRadius = 48;
	LWheel4->FlatWheelRadius = 42;
	LWheel4->RimWheelRadius = 36;
	WheelSoftness = 0.01;
	WheelPenScale = 1.1;
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
	WheelSuspensionTravel = 15;
	WheelSuspensionOffset = -9;
	WheelSuspensionMaxRenderTravel = 10;
	ExhaustBone = "Exhaust_1_Bone";
	bHasExhaust = true;
	FTScale = 0.03;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 5;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.48, 0.4,0.65,1,1.8 };
	TransRatio = 0.17;
	ChangeUpPoint = 2200;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.001;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 30;
	TurnDamping = 95;
	StopThreshold = 150;
	HandbrakeThresh = 200;
	EngineInertia = 0.14;
	IdleRPM = 500;
	EngineRPMSoundRange = 5500;
	SteerBoneName = "steering_wheel_1_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//PositionTypes(0) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_1_Bone",FVector(290, 55, 85),FVector(0, 0, 0),FRotator(0,0,0) });
	EntryPoints = { DriverSideEntry,Entry_Passenger };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/HEMTT/HEMMT_Idle_Lp_4_Que.HEMMT_Idle_Lp_4_Cue'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/HEMTT/HEMTT_Fuel_Static.HEMTT_Fuel_Static'"), NULL, LOAD_None, NULL);
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = {
		Body_Right_1,
		Body_Left_1,
		Body_Right_2,
		Body_Left_2,
		Body_Right_3,
		Body_Left_3,
		Body_Right_4,
		Body_Left_4,
		Window_Left,
		Fuel_Tank_Left,
		Wheel_Left_1,
		Wheel_Left_2,
		Wheel_Left_3,
		Wheel_Left_4,
		Window_Right,
		Wheel_Right_4,
		Wheel_Right_3,
		Wheel_Right_2,
		Wheel_Right_1,
		Winshield_Right,
		Winshield_Left
	};
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	ImpactDamageRadius = 350;
	Wheels = { RWheel1,LWheel1,RWheel2,LWheel2,RWheel3,LWheel3,RWheel4,LWheel4 };
	VehicleMass = 18;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "SF_Humvee_Driver_turn_Idle";
	DriverPosOffset = FVector(0, 0, -3);
	DriverRotOffset = FRotator(-1000, 0, 0);
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100) };
	FPCamPos = FVector(290, -60, 85);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a M978 HEMTT";
	VehicleNameString = "M978 HEMTT";
	ObjectiveGetOutDist = 1500;
	FlagBone = "Dummy01";
	FlagRotation = FRotator(0, 32768, 0);
	GroundSpeed = 1290;
	HealthMax = 1000;
	Health = 1000;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M978_Fuel_HEMTT.M978_Fuel_HEMTT'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 380;
	//CollisionHeight = 120;
	KParams = KParams0;

}
/*
void AM978_HEMTT::StaticPrecache(LevelInfo L)
{
	Super::StaticPrecache(L);
	L.AddPrecacheMaterial(Texture'skn_veh_hemmt');
	L.AddPrecacheMaterial(Shader'Hemtt_window');
	L.AddPrecacheMaterial(Texture'skn_veh_hemmt_fuel');
	L.AddPrecacheMaterial(Texture'skn_veh_hemmt_tire_mud');
	L.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt');
	L.AddPrecacheMaterial(Shader'ds1_hemtt_window');
	L.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_fuel');
	L.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_tire_mud');
	L.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt');
	L.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_fuel');
	L.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_tire_mud');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
}
*/

void AM978_HEMTT::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM978_HEMTT::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'skn_veh_hemmt');
	Level.AddPrecacheMaterial(Shader'Hemtt_window');
	Level.AddPrecacheMaterial(Texture'skn_veh_hemmt_fuel');
	Level.AddPrecacheMaterial(Texture'skn_veh_hemmt_tire_mud');
	Level.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt');
	Level.AddPrecacheMaterial(Shader'ds1_hemtt_window');
	Level.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_fuel');
	Level.AddPrecacheMaterial(Combiner'ds1_skn_veh_hemmt_tire_mud');
	Level.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt');
	Level.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_fuel');
	Level.AddPrecacheMaterial(Combiner'ds2_skn_veh_hemmt_tire_mud');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	*/
	Super::UpdatePrecacheMaterials();
}