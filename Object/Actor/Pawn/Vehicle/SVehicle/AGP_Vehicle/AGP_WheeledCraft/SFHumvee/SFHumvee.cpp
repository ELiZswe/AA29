// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/SFHumvee/SFHumvee.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

ASFHumvee::ASFHumvee()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 3;
	KParams0->KInertiaTensor[3] = 7;
	KParams0->KInertiaTensor[5] = 10;
	KParams0->KCOMOffset = FVector(0.2, 0, 0.161);
	KParams0->KLinearDamping = 0.07;
	KParams0->KAngularDamping = 0.005;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 2200;
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
	DriverSideEntry->EntryAnim = "SF_Humvee_Driver_Enter";
	DriverSideEntry->DoorAnim = "SF_Humvee_Driver_Door_Enter";
	DriverSideEntry->DoorBone = "door_left_1_bone";
	DriverSideEntry->DoorBoneDS1 = "DS1_door_left_1_bone";
	DriverSideEntry->DoorBoneDS2 = "DS2_door_left_1_bone";
	DriverSideEntry->DoorOpenAngle = -10536;
	DriverSideEntry->EntryPosOffset = FVector(15, 5, 0);
	DriverSideEntry->EntryRotOffset = FRotator(0, 32768, 0);
	UVehicleEntryPoint* PassengerSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	PassengerSideEntry->EntryBone = "Entry_Passenger_1_bone";
	PassengerSideEntry->PositionIndex = { 0 };
	PassengerSideEntry->EntryAnim = "SF_Humvee_Passenger_Enter";
	PassengerSideEntry->DoorAnim = "SF_Humvee_Passenger_Door_Enter";
	PassengerSideEntry->DoorBone = "door_right_1_bone";
	PassengerSideEntry->DoorBoneDS1 = "DS1_door_right_1_bone";
	PassengerSideEntry->DoorBoneDS2 = "DS2_door_right_1_bone";
	PassengerSideEntry->DoorOpenAngle = 10000;
	PassengerSideEntry->EntryPosOffset = FVector(-15, -3, 0);
	PassengerSideEntry->EntryRotOffset = FRotator(0, 32768, 0);
	UVehicleEntryPoint* GunnerEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	GunnerEntry->EntryBone = "entry_gunner_1_bone";
	GunnerEntry->PositionIndex = { 1 };
	GunnerEntry->EntryAnim = "SF_Humvee_Gunner_enter";
	GunnerEntry->EntryPosOffset = FVector(2, 12, 10);
	GunnerEntry->EntryRotOffset = FRotator(0, 32768, 0);
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 3;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0)=({"body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Right->DamageStates(1)=({"DS1_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Front_Right->DamageStates(2)=({"DS2_body_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Front_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Middle->ArmorThreshold = 2;
	Front_Middle->MaxHitPoints = 1000;
	//Front_Middle->DamageStates(0)=({"body_middle_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Middle->DamageStates(1)=({"DS1_body_middle_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'AGP_Vehicles.VPE_EngineDamage'});
	//Front_Middle->DamageStates(2)=({"DS2_body_middle_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'AGP_Vehicles.VPE_EngineDestroyed'});
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 3;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0)=({"body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Front_Left->DamageStates(1)=({"DS1_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Front_Left->DamageStates(2)=({"DS2_body_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Right_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Right_Windshield->MaxHitPoints = 1000;
	//Right_Windshield->DamageStates(0)=({"windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Right_Windshield->DamageStates(1)=({"ds1_windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,class'None',class'None',class'None'});
	//Right_Windshield->DamageStates(2)=({"ds2_windshield_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Right_Windshield->bNoPassDamageToVehicle = true;
	Right_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Right->ArmorThreshold = 3;
	Side_Right->MaxHitPoints = 1000;
	Side_Right->WindowDamageZones = { 12,13 };
	//Side_Right->DamageStates(0)=({"body_right_2_bone","door_right_1_bone","door_right_2_bone","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Right->DamageStates(1)=({"DS1_body_right_2_bone","DS1_door_right_1_bone","DS1_door_right_2_bone","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Side_Right->DamageStates(2)=({"DS2_body_right_2_bone","DS2_door_right_1_bone","DS2_door_right_2_bone","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle->ArmorThreshold = 3;
	Middle->MaxHitPoints = 1000;
	//Middle->DamageStates(0)=({"body_middle_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Middle->DamageStates(1)=({"ds1_body_middle_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Middle->DamageStates(2)=({"ds2_body_middle_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Left_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Left_Windshield->MaxHitPoints = 1000;
	//Left_Windshield->DamageStates(0)=({"windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Left_Windshield->DamageStates(1)=({"ds1_windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'None'});
	//Left_Windshield->DamageStates(2)=({"ds2_windshield_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Left_Windshield->bNoPassDamageToVehicle = true;
	Left_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Left->ArmorThreshold = 3;
	Side_Left->MaxHitPoints = 1000;
	Side_Left->WindowDamageZones = { 10,11 };
	//Side_Left->DamageStates(0)=({"body_left_2_bone","door_left_1_bone","door_left_2_bone","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Left->DamageStates(1)=({"DS1_body_left_2_bone","DS1_door_left_1_bone","DS1_door_left_2_bone","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Side_Left->DamageStates(2)=({"DS2_body_left_2_bone","DS2_door_left_1_bone","DS2_door_left_2_bone","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Rear_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Middle->ArmorThreshold = 3;
	Rear_Middle->MaxHitPoints = 1000;
	//Rear_Middle->DamageStates(0)=({"body_middle_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Middle->DamageStates(1)=({"ds1_body_middle_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Middle->DamageStates(2)=({"ds2_body_middle_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 3;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0)=({"body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Left->DamageStates(1)=({"DS1_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Left->DamageStates(2)=({"DS2_body_left_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Side_Front_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Left_Window->MaxHitPoints = 1000;
	//Side_Front_Left_Window->DamageStates(0)=({"window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Front_Left_Window->DamageStates(1)=({"DS1_window_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Front_Left_Window->bNoPassDamageToVehicle = true;
	Side_Front_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Rear_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Left_Window->MaxHitPoints = 1000;
	//Side_Rear_Left_Window->DamageStates(0)=({"window_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Rear_Left_Window->DamageStates(1)=({"DS1_window_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Rear_Left_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Front_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Right_Window->MaxHitPoints = 1000;
	//Side_Front_Right_Window->DamageStates(0)=({"window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Front_Right_Window->DamageStates(1)=({"DS1_window_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Front_Right_Window->bNoPassDamageToVehicle = true;
	Side_Front_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Rear_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Right_Window->MaxHitPoints = 1000;
	//Side_Rear_Right_Window->DamageStates(0)=({"window_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Side_Rear_Right_Window->DamageStates(1)=({"DS1_window_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleGlassShatter',class'None',class'None'});
	Side_Rear_Right_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 3;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0)=({"body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Rear_Right->DamageStates(1)=({"DS1_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.9,0,Class'AGP_Effects.VehicleLightSmoke',class'None',class'None'});
	//Rear_Right->DamageStates(2)=({"DS2_body_right_3_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.6,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 3;
	//Wheel_Left_1->DamageStates(0)=({"wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Left_1->DamageStates(1)=({"ds1_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Left_1->DamageStates(2)=({"ds2_wheel_left_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	Wheel_Right_1->WheelNum = 2;
	//Wheel_Right_1->DamageStates(0)=({"wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Right_1->DamageStates(1)=({"ds1_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Right_1->DamageStates(2)=({"ds2_wheel_right_1_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 2;
	Wheel_Right_2->DamageModifier = 10;
	Wheel_Right_2->MaxHitPoints = 1000;
	Wheel_Right_2->bWheelZone = true;
	//Wheel_Right_2->DamageStates(0)=({"wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Right_2->DamageStates(1)=({"ds1_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Right_2->DamageStates(2)=({"ds2_wheel_right_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Right_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 1;
	//Wheel_Left_2->DamageStates(0)=({"wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Wheel_Left_2->DamageStates(1)=({"ds1_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0.5,0,class'None',class'None',class'AGP_Vehicles.VPE_TireFlat'});
	//Wheel_Left_2->DamageStates(2)=({"ds2_wheel_left_2_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,class'None',class'None',class'AGP_Vehicles.VPE_TireMissing'});
	Wheel_Left_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 3;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0)=({"Yaw_bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,1,0,class'None',class'None',class'None'});
	//Turret->DamageStates(1)=({"DS1_yaw_Bone","None","None","None","None","None","None","None",0,0,0,0,0,0,0,0,0,0,Class'AGP_Effects.VehicleFireHeavySmokeSmall',class'None',class'None'});
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
	RRWheel->SupportBoneName = "suspension_rear_right_1_bone";
	RRWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->BoneName = "wheel_left_2_bone";
	LRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelBoneOffset = FVector(0, -6, 0);
	LRWheel->WheelRadius = 25;
	LRWheel->FlatWheelRadius = 22;
	LRWheel->RimWheelRadius = 18;
	LRWheel->SupportBoneName = "suspension_rear_left_1_bone";
	LRWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->SteerType = EVehicleSteerType::VST_Steered;
	RFWheel->BoneName = "wheel_right_1_bone";
	RFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelBoneOffset = FVector(0, 6, 0);
	RFWheel->WheelRadius = 25;
	RFWheel->FlatWheelRadius = 22;
	RFWheel->RimWheelRadius = 18;
	RFWheel->SupportBoneName = "suspension_front_right_1_bone";
	RFWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->SteerType = EVehicleSteerType::VST_Steered;
	LFWheel->BoneName = "wheel_left_1_bone";
	LFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelBoneOffset = FVector(0, -6, 0);
	LFWheel->WheelRadius = 25;
	LFWheel->FlatWheelRadius = 22;
	LFWheel->RimWheelRadius = 18;
	LFWheel->SupportBoneName = "suspension_front_left_1_bone";
	LFWheel->SupportBoneAxis = EAA2_Axis::AXIS_Z;
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
	FTScale = 0.03;
	ChassisTorqueScale = 0.1;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = {-0.49, 0.43, 0.74, 1.23, 2.05};
	TransRatio = 0.15;
	ChangeUpPoint = 3600;
	ChangeDownPoint = 1200;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0002;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 95;
	StopThreshold = 100;
	HandbrakeThresh = 200;
	EngineInertia = 0.1;
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
	bAllowCOMAdjust = true;
	MaxCOMOffset = 0.3;
	COMAdjustScale = 0.00032;
	//PositionTypes(0) = ({ class'AGP_Vehicles.PassengerPosition',"None","Seat_Passenger_1_Bone",FVector(15, 35, 65),FVector(0, 6, -25),FRotator(0,0,0) })
	//PositionTypes(1) = ({ class'AGP_Vehicles.SFHumvee_Gunner',"Weapon_1_Bone","player_attach_bone",FVector(0, 0, 0),FVector(11, 0, -38),FRotator(0,0,0) });
	EntryPoints = { DriverSideEntry,PassengerSideEntry,GunnerEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/HUMMWV/HUMMWV_Idle_Lp_3_Que.HUMMWV_Idle_Lp_3_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/HUMMWV/HUMMWV_Start_3_Que.HUMMWV_Start_3_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/SF_Humvee/SF_Humvee_Static_Damage.SF_Humvee_Static_Damage'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = class'AGP_Vehicles.SFHumvee_DestroyedBody';
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = {
		Front_Right,
		Front_Middle,
		Front_Left,
		Right_Windshield,
		Side_Right,
		Middle,
		Left_Windshield,
		Side_Left,
		Rear_Middle,
		Rear_Left,
		Side_Front_Left_Window,
		Side_Rear_Left_Window,
		Side_Front_Right_Window,
		Side_Rear_Right_Window,
		Rear_Right,
		Wheel_Left_1,
		Wheel_Right_1,
		Wheel_Right_2,
		Wheel_Left_2,
		Turret
	};
	TestDamageZones = {
		FTestDamageZoneInfo({ "Front_Right",0,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Front_Middle",1,2,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Front_Left",2,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Right_Windshield",3,0,1000,0,1,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Side_Right",4,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Middle",5,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Left_Windshield",6,0,1000,0,1,1,0.5,0 }),
		FTestDamageZoneInfo({ "Side_Left",7,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Rear_Middle",8,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Rear_Left",9,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Side_Front_Left_Window",10,0,1000,0,1,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Rear_Left_Window",11,0,1000,0,1,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Front_Right_Window",12,0,1000,0,1,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Rear_Right_Window",13,0,1000,0,1,1,0,0 }),
		FTestDamageZoneInfo({ "Rear_Right",14,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Wheel_Left_1",15,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_1",16,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Right_2",17,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Wheel_Left_2",18,2,1000,0,1,10,0.5,0 }),
		FTestDamageZoneInfo({ "Turret",19,3,1000,0,0,1,0,0 })
	};
	ParticleInfo = {
		FIniParticleInfo({ "Front_Right","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Front_Middle","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Front_Left","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Right_Windshield","None","AGP_Effects.VehicleGlassShatter" }),
		FIniParticleInfo({ "Side_Right","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Middle","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Left_Windshield","None","AGP_Effects.VehicleGlassShatter" }),
		FIniParticleInfo({ "Side_Left","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Rear_Middle","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Rear_Left","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Side_Front_Left_Window","AGP_Effects.VehicleGlassShatter","" }),
		FIniParticleInfo({ "Side_Rear_Left_Window","AGP_Effects.VehicleGlassShatter","" }),
		FIniParticleInfo({ "Side_Front_Right_Window","AGP_Effects.VehicleGlassShatter","" }),
		FIniParticleInfo({ "Side_Rear_Right_Window","AGP_Effects.VehicleGlassShatter","" }),
		FIniParticleInfo({ "Rear_Right","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Wheel_Left_1","None","None" }),
		FIniParticleInfo({ "Wheel_Right_1","None","None" }),
		FIniParticleInfo({ "Wheel_Right_2","None","None" }),
		FIniParticleInfo({ "Wheel_Left_2","None","None" }),
		FIniParticleInfo({ "Turret","AGP_Effects.VehicleFireHeavySmokeSmall","" })
	};
	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	VehicleMass = 5;
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
	VehiclePositionString = "in a Humvee";
	VehicleNameString = "SF Humvee";
	ObjectiveGetOutDist = 1500;
	FlagBone = "Dummy01";
	FlagRotation = FRotator(0, 32768, 0);
	GroundSpeed = 900;
	HealthMax = 1000;
	Health = 1000;
	Bob = 0.016;
	//bDemoRecSounds = false;
	//bDemoRecMuzzleFlash = false;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/SFHumvee.SFHumvee'"), NULL, LOAD_None, NULL);
	//SoundRadius = 255;
	//CollisionRadius = 190;
	//CollisionHeight = 120;
	KParams = KParams0;

}



/*
void ASFHumvee::StaticPrecache(LevelInfo L)
{
	StaticPrecache(L);
}
*/

void ASFHumvee::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ASFHumvee::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}
