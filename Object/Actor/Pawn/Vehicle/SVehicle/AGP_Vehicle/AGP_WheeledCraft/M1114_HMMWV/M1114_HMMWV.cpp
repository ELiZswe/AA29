// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1114_HMMWV/M1114_HMMWV.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

AM1114_HMMWV::AM1114_HMMWV()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 3;
	KParams0->KInertiaTensor[3] = 7;
	KParams0->KInertiaTensor[5] = 10;
	KParams0->KCOMOffset = FVector(0.2, 0, 0.161);
	KParams0->KLinearDamping = 0.065;
	KParams0->KAngularDamping = 0.005;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2175;
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
	UVehicleEntryPoint* PassengerSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	PassengerSideEntry->EntryBone = "Entry_Passenger_1_bone";
	PassengerSideEntry->PositionIndex = { 0 };
	UVehicleEntryPoint* GunnerEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	GunnerEntry->EntryBone = "entry_gunner_1_bone";
	GunnerEntry->PositionIndex = { 1 };
	UVehicleDamageZone* Front_Left_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left_Panel->ArmorThreshold = 5;
	Front_Left_Panel->MaxHitPoints = 1000;
	//Front_Left_Panel->DamageStates(0)=({"body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Left_Panel->DamageStates(1)=({"DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Front_Left_Panel->DamageStates(2)=({"DS2_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Front_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Middle->ArmorThreshold = 4;
	Front_Middle->MaxHitPoints = 1000;
	//Front_Middle->DamageStates(0)=({"body_middle_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Middle->DamageStates(1)=({"DS1_body_middle_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage'});
	//Front_Middle->DamageStates(2)=({"DS2_body_middle_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed'});
	UVehicleDamageZone* Front_Right_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right_Panel->ArmorThreshold = 5;
	Front_Right_Panel->MaxHitPoints = 1000;
	//Front_Right_Panel->DamageStates(0)=({"body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Right_Panel->DamageStates(1)=({"DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Front_Right_Panel->DamageStates(2)=({"DS2_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Front_Left_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left_Door->ArmorThreshold = 5;
	Front_Left_Door->MaxHitPoints = 1000;
	//Front_Left_Door->DamageStates(0)=({"body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Left_Door->DamageStates(1)=({"DS1_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Front_Left_Door->DamageStates(2)=({"DS2_body_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Front_Right_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right_Door->ArmorThreshold = 5;
	Front_Right_Door->MaxHitPoints = 1000;
	//Front_Right_Door->DamageStates(0)=({"body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Right_Door->DamageStates(1)=({"DS1_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Front_Right_Door->DamageStates(2)=({"DS2_body_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Rear_Left_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left_Door->ArmorThreshold = 5;
	Rear_Left_Door->MaxHitPoints = 1000;
	//Rear_Left_Door->DamageStates(0)=({"body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Left_Door->DamageStates(1)=({"DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Left_Door->DamageStates(2)=({"DS2_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Rear_Right_Door = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right_Door->ArmorThreshold = 5;
	Rear_Right_Door->MaxHitPoints = 1000;
	//Rear_Right_Door->DamageStates(0)=({"body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Right_Door->DamageStates(1)=({"DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Right_Door->DamageStates(2)=({"DS2_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Rear_Left_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left_Panel->ArmorThreshold = 5;
	Rear_Left_Panel->MaxHitPoints = 1000;
	//Rear_Left_Panel->DamageStates(0)=({"body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Left_Panel->DamageStates(1)=({"DS1_body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Left_Panel->DamageStates(2)=({"DS2_body_left_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Rear_Right_Panel = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right_Panel->ArmorThreshold = 5;
	Rear_Right_Panel->MaxHitPoints = 1000;
	//Rear_Right_Panel->DamageStates(0)=({"body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Right_Panel->DamageStates(1)=({"DS1_body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Right_Panel->DamageStates(2)=({"DS2_body_right_4_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.3,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Side_Front_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Left_Window->ArmorThreshold = 2;
	Side_Front_Left_Window->MaxHitPoints = 1000;
	//Side_Front_Left_Window->DamageStates(0)=({"window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Front_Left_Window->DamageStates(1)=({"DS1_window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Front_Left_Window->bNoPassDamageToVehicle = true;
	Side_Front_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Rear_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Left_Window->ArmorThreshold = 2;
	Side_Rear_Left_Window->MaxHitPoints = 1000;
	//Side_Rear_Left_Window->DamageStates(0)=({"window_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Rear_Left_Window->DamageStates(1)=({"DS1_window_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Rear_Left_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Wheel_Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Front_Left->ArmorThreshold = 2;
	Wheel_Front_Left->DamageModifier = 10;
	Wheel_Front_Left->MaxHitPoints = 1000;
	Wheel_Front_Left->bWheelZone = true;
	Wheel_Front_Left->WheelNum = 3;
	//Wheel_Front_Left->DamageStates(0)=({"wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Front_Left->DamageStates(1)=({"ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Front_Left->DamageStates(2)=({"ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Front_Left->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Rear_Left->ArmorThreshold = 2;
	Wheel_Rear_Left->DamageModifier = 10;
	Wheel_Rear_Left->MaxHitPoints = 1000;
	Wheel_Rear_Left->bWheelZone = true;
	Wheel_Rear_Left->WheelNum = 1;
	//Wheel_Rear_Left->DamageStates(0)=({"wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Rear_Left->DamageStates(1)=({"ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Rear_Left->DamageStates(2)=({"ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Rear_Left->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Side_Rear_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Right_Window->ArmorThreshold = 2;
	Side_Rear_Right_Window->MaxHitPoints = 1000;
	//Side_Rear_Right_Window->DamageStates(0)=({"window_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Rear_Right_Window->DamageStates(1)=({"DS1_window_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Rear_Right_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Front_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Right_Window->ArmorThreshold = 2;
	Side_Front_Right_Window->MaxHitPoints = 1000;
	//Side_Front_Right_Window->DamageStates(0)=({"window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Front_Right_Window->DamageStates(1)=({"DS1_window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Front_Right_Window->bNoPassDamageToVehicle = true;
	Side_Front_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Wheel_Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Rear_Right->ArmorThreshold = 2;
	Wheel_Rear_Right->DamageModifier = 10;
	Wheel_Rear_Right->MaxHitPoints = 1000;
	Wheel_Rear_Right->bWheelZone = true;
	//Wheel_Rear_Right->DamageStates(0)=({"wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Rear_Right->DamageStates(1)=({"ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Rear_Right->DamageStates(2)=({"ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Rear_Right->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Front_Right->ArmorThreshold = 2;
	Wheel_Front_Right->DamageModifier = 10;
	Wheel_Front_Right->MaxHitPoints = 1000;
	Wheel_Front_Right->bWheelZone = true;
	Wheel_Front_Right->WheelNum = 2;
	//Wheel_Front_Right->DamageStates(0)=({"wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Front_Right->DamageStates(1)=({"ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Front_Right->DamageStates(2)=({"ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Front_Right->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Front_Right_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right_Windshield->ArmorThreshold = 2;
	Front_Right_Windshield->MaxHitPoints = 1000;
	//Front_Right_Windshield->DamageStates(0)=({"windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Right_Windshield->DamageStates(1)=({"ds1_windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Front_Right_Windshield->bNoPassDamageToVehicle = true;
	Front_Right_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Front_Left_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left_Windshield->ArmorThreshold = 2;
	Front_Left_Windshield->MaxHitPoints = 1000;
	//Front_Left_Windshield->DamageStates(0)=({"windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Left_Windshield->DamageStates(1)=({"ds1_windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Front_Left_Windshield->bNoPassDamageToVehicle = true;
	Front_Left_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 5;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0)=({"Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Turret->DamageStates(1)=({"DS1_yaw_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	Turret->bNoPassDamageToVehicle = true;
	Turret->bControlsExternalMesh = true;
	Turret->VehiclePositionOwnerIndex = 1;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->BoneName = "wheel_right_2_bone";
	RRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelBoneOffset = FVector(0, 6, 0);
	RRWheel->WheelRadius = 25;
	RRWheel->FlatWheelRadius = 22;
	RRWheel->RimWheelRadius = 18;
	RRWheel->SupportBoneName = "right_suspension_2_bone";
	RRWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->BoneName = "wheel_left_2_bone";
	LRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelBoneOffset = FVector(0, -6, 0);
	LRWheel->WheelRadius = 25;
	LRWheel->FlatWheelRadius = 22;
	LRWheel->RimWheelRadius = 18;
	LRWheel->SupportBoneName = "left_suspension_2_bone";
	LRWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->SteerType = EVehicleSteerType::VST_Steered;
	RFWheel->BoneName = "wheel_right_1_bone";
	RFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelBoneOffset = FVector(0, 18, 0);
	RFWheel->WheelRadius = 25;
	RFWheel->FlatWheelRadius = 22;
	RFWheel->RimWheelRadius = 18;
	RFWheel->SupportBoneName = "right_suspension_1_bone";
	RFWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->SteerType = EVehicleSteerType::VST_Steered;
	LFWheel->BoneName = "wheel_left_1_bone";
	LFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelBoneOffset = FVector(0, -18, 0);
	LFWheel->WheelRadius = 25;
	LFWheel->FlatWheelRadius = 22;
	LFWheel->RimWheelRadius = 18;
	LFWheel->SupportBoneName = "left_suspension_1_bone";
	LFWheel->SupportBoneAxis = EAA2_Axis::AXIS_X;
	WheelSoftness = 0.02;
	WheelPenScale = 2.1;
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
	WheelSuspensionOffset = -5;
	WheelSuspensionMaxRenderTravel = 6;
	FTScale = 0.04;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.49, 0.43, 0.74, 1.23, 2.05 };
	TransRatio = 0.15;
	ChangeUpPoint = 3600;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0003;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 100;
	HandbrakeThresh = 200;
	EngineInertia = 0.1;
	IdleRPM = 500;
	EngineRPMSoundRange = 10000;
	SteerBoneName = "steering_wheel_bone";
	SteerBoneMaxAngle = 120;
	RevMeterScale = 4000;
	AirTurnTorque = 35;
	AirPitchTorque = 55;
	AirPitchDamping = 35;
	AirRollTorque = 35;
	AirRollDamping = 35;
	//PositionTypes(0) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_1_Bone",FVector(15, 35, 65),FVector(1, 0, -25),FRotator(0,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.M1114_Gunner',"Weapon_1_Bone","player_attach_bone",FVector(0, 0, 0),FVector(20, 0, -38),FRotator(0,0,0) })
	//PositionTypes(2) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_2_bone",FVector(-25, -35, 65),FVector(1, 0, -25),FRotator(0,0,0) })
	//PositionTypes(3) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_3_bone",FVector(-25, 35, 65),FVector(1, 0, -25),FRotator(0,0,0) });
	EntryPoints = { DriverSideEntry,PassengerSideEntry,GunnerEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/HUMMWV/HUMMWV_Idle_Lp_3_Que.HUMMWV_Idle_Lp_3_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/HUMMWV/HUMMWV_Start_3_Que.HUMMWV_Start_3_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/HMMWV/M1114_HMMWV_Static.M1114_HMMWV_Static'"), NULL, LOAD_None, NULL);
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = {
		Front_Left_Panel,
		Front_Middle,
		Front_Right_Panel,
		Front_Left_Door,
		Front_Right_Door,
		Rear_Left_Door,
		Rear_Right_Door,
		Rear_Left_Panel,
		Rear_Right_Panel,
		Side_Front_Left_Window,
		Side_Rear_Left_Window,
		Wheel_Front_Left,
		Wheel_Rear_Left,
		Side_Rear_Right_Window,
		Side_Front_Right_Window,
		Wheel_Rear_Right,
		Wheel_Front_Right,
		Front_Right_Windshield,
		Front_Left_Windshield,
		Turret
	};
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	VehicleMass = 4.8;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "SF_Humvee_Driver_turn_Idle";
	DriverPosOffset = FVector(1, 0, -21);
	DriverRotOffset = FRotator(1600, 0, 0);
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165, -100) };
	FPCamPos = FVector(15, -35, 65);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a M1114 HMMWV";
	VehicleNameString = "M1114 HMMWV";
	ObjectiveGetOutDist = 1500;
	FlagBone = "Dummy01";
	FlagRotation = FRotator(0, 32768, 0);
	GroundSpeed = 1290;
	HealthMax = 1000;
	Health = 1000;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1114_HMMWV.M1114_HMMWV'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 170;
	//CollisionHeight = 110;
	KParams = KParams0;
}



/*
void AM1114_HMMWV::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
}
*/

void AM1114_HMMWV::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1114_HMMWV::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}
