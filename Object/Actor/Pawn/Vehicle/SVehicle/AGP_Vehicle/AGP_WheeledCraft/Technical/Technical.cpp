// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/Technical/Technical.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"
#include "AA29/Object/VehicleEntryPoint/VehicleEntryPoint.h"
#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"

ATechnical::ATechnical()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor = { 3,6,6.5 };
	KParams0->KCOMOffset = FVector(0.7, 0, -0.3);
	KParams0->KLinearDamping = 0.035;
	KParams0->KAngularDamping = 0.005;
	KParams0->KStartEnabled = true;
	KParams0->bKNonSphericalInertia = true;
	KParams0->KMaxSpeed = 3200;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bDestroyOnWorldPenetrate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 0.8;
	KParams0->KImpactThreshold = 500;
	UVehicleEntryPoint* DriverSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	DriverSideEntry->bDriverEntry = true;
	DriverSideEntry->EntryBone = "Entry_Driver_bone";
	DriverSideEntry->EntryAnim = "Tacoma_Driver_Enter";
	DriverSideEntry->DoorAnim = "Tacoma_Driver_Door_Enter";
	DriverSideEntry->DoorBone = "door_left_1_bone";
	DriverSideEntry->DoorBoneDS1 = "DS1_door_left_1_bone";
	DriverSideEntry->DoorBoneDS2 = "DS2_door_left_1_bone";
	DriverSideEntry->DoorOpenAngle = -10536;
	DriverSideEntry->EntryPosOffset = FVector(15, -15, 0);
	UVehicleEntryPoint* PassengerSideEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	PassengerSideEntry->EntryBone = "Entry_Passenger_1_bone";
	//PassengerSideEntry->PositionIndex(0) = ();
	UVehicleEntryPoint* GunnerEntry = NewObject<UVehicleEntryPoint>(UVehicleEntryPoint::StaticClass());
	GunnerEntry->EntryBone = "entry_gunner_1_bone";
	//GunnerEntry->PositionIndex(0) = ();
	GunnerEntry->EntryAnim = "Tacoma_Gunner_Enter";
	GunnerEntry->EntryPosOffset = FVector(10, 0, 0);
	UVehicleDamageZone* Front_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Left->ArmorThreshold = 3;
	Front_Left->MaxHitPoints = 1000;
	//Front_Left->DamageStates(0) = (DamageBones = "body_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Front_Left->DamageStates(1) = (DamageBones = "DS1_body_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Front_Left->DamageStates(2) = (DamageBones = "DS2_body_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Front_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Middle->ArmorThreshold = 2;
	Front_Middle->MaxHitPoints = 1000;
	//Front_Middle->DamageStates(0) = (DamageBones = "body_middle_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Front_Middle->DamageStates(1) = (DamageBones = "DS1_body_middle_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_EngineDamage');
	//Front_Middle->DamageStates(2) = (DamageBones = "DS2_body_middle_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_EngineDestroyed');
	UVehicleDamageZone* Front_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Right->ArmorThreshold = 3;
	Front_Right->MaxHitPoints = 1000;
	//Front_Right->DamageStates(0) = (DamageBones = "body_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Front_Right->DamageStates(1) = (DamageBones = "DS1_body_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Front_Right->DamageStates(2) = (DamageBones = "DS2_body_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Front_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Front_Windshield->MaxHitPoints = 1000;
	//Front_Windshield->DamageStates(0) = (DamageBones = "Windshield_1_Bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Front_Windshield->DamageStates(1) = (DamageBones = "DS1_Windshield_1_Bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleGlassShatter', VisualEffect = class'None', PhysicalEffect = class'None');
	Front_Windshield->bNoPassDamageToVehicle = true;
	Front_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Right->ArmorThreshold = 3;
	Side_Right->MaxHitPoints = 1000;
	//Side_Right->DamageStates(0) = (DamageBones = "body_right_2_bone", DamageBones = "door_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Right->DamageStates(1) = (DamageBones = "DS1_body_right_2_bone", DamageBones = "DS1_door_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Right->DamageStates(2) = (DamageBones = "DS2_body_right_2_bone", DamageBones = "DS2_door_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Middle_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Middle_Middle->ArmorThreshold = 3;
	Middle_Middle->MaxHitPoints = 1000;
	//Middle_Middle->DamageStates(0) = (DamageBones = "body_middle_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Middle_Middle->DamageStates(1) = (DamageBones = "ds1_body_middle_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Middle_Middle->DamageStates(2) = (DamageBones = "ds2_body_middle_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Rear_Windshield = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Windshield->MaxHitPoints = 1000;
	//Rear_Windshield->DamageStates(0) = (DamageBones = "Window_Rear_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Windshield->DamageStates(1) = (DamageBones = "DS1_Window_Rear_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleGlassShatter', VisualEffect = class'None', PhysicalEffect = class'None');
	Rear_Windshield->bNoPassDamageToVehicle = true;
	Rear_Windshield->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Left->ArmorThreshold = 3;
	Side_Left->MaxHitPoints = 1000;
	//Side_Left->DamageStates(0) = (DamageBones = "body_left_2_bone", DamageBones = "door_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Left->DamageStates(1) = (DamageBones = "DS1_body_left_2_bone", DamageBones = "DS1_door_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Left->DamageStates(2) = (DamageBones = "DS2_body_left_2_bone", DamageBones = "DS2_door_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Rear_Middle = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Middle->ArmorThreshold = 3;
	Rear_Middle->MaxHitPoints = 1000;
	//Rear_Middle->DamageStates(0) = (DamageBones = "body_middle_3_bone", DamageBones = "tailgate_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Middle->DamageStates(1) = (DamageBones = "ds1_body_middle_3_bone", DamageBones = "DS1_tailgate_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Middle->DamageStates(2) = (DamageBones = "ds2_body_middle_3_bone", DamageBones = "DS2_tailgate_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Rear_Left = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Left->ArmorThreshold = 3;
	Rear_Left->MaxHitPoints = 1000;
	//Rear_Left->DamageStates(0) = (DamageBones = "body_left_3_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Left->DamageStates(1) = (DamageBones = "DS1_body_left_3_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Left->DamageStates(2) = (DamageBones = "DS2_body_left_3_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Side_Front_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Left_Window->MaxHitPoints = 1000;
	//Side_Front_Left_Window->DamageStates(0) = (DamageBones = "window_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Front_Left_Window->DamageStates(1) = (DamageBones = "DS1_window_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleGlassShatter', VisualEffect = class'None', PhysicalEffect = class'None');
	Side_Front_Left_Window->bNoPassDamageToVehicle = true;
	Side_Front_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Rear_Left_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Left_Window->MaxHitPoints = 1000;
	//Side_Rear_Left_Window->DamageStates(0) = (DamageBones = "window_left_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Rear_Left_Window->DamageStates(1) = (DamageBones = "DS1_window_left_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleGlassShatter', VisualEffect = class'None', PhysicalEffect = class'None');
	Side_Rear_Left_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Left_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Front_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Front_Right_Window->MaxHitPoints = 1000;
	//Side_Front_Right_Window->DamageStates(0) = (DamageBones = "window_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Front_Right_Window->DamageStates(1) = (DamageBones = "DS1_window_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleGlassShatter', VisualEffect = class'None', PhysicalEffect = class'None');
	Side_Front_Right_Window->bNoPassDamageToVehicle = true;
	Side_Front_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Side_Rear_Right_Window = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Side_Rear_Right_Window->MaxHitPoints = 1000;
	//Side_Rear_Right_Window->DamageStates(0) = (DamageBones = "window_right_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Side_Rear_Right_Window->DamageStates(1) = (DamageBones = "DS1_window_right_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleGlassShatter', VisualEffect = class'None', PhysicalEffect = class'None');
	Side_Rear_Right_Window->bNoPassDamageToVehicle = true;
	Side_Rear_Right_Window->PenetrationPercent = 1;
	UVehicleDamageZone* Rear_Right = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Rear_Right->ArmorThreshold = 3;
	Rear_Right->MaxHitPoints = 1000;
	//Rear_Right->DamageStates(0) = (DamageBones = "body_right_3_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Right->DamageStates(1) = (DamageBones = "DS1_body_right_3_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.9, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleLightSmoke', VisualEffect = class'None', PhysicalEffect = class'None');
	//Rear_Right->DamageStates(2) = (DamageBones = "DS2_body_right_3_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.6, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	UVehicleDamageZone* Wheel_Left_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_1->ArmorThreshold = 2;
	Wheel_Left_1->DamageModifier = 10;
	Wheel_Left_1->MaxHitPoints = 1000;
	Wheel_Left_1->bWheelZone = true;
	Wheel_Left_1->WheelNum = 3;
	//Wheel_Left_1->DamageStates(0) = (DamageBones = "wheel_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Wheel_Left_1->DamageStates(1) = (DamageBones = "ds1_wheel_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.5, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireFlat');
	//Wheel_Left_1->DamageStates(2) = (DamageBones = "ds2_wheel_left_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireMissing');
	Wheel_Left_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_1 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_1->ArmorThreshold = 2;
	Wheel_Right_1->DamageModifier = 10;
	Wheel_Right_1->MaxHitPoints = 1000;
	Wheel_Right_1->bWheelZone = true;
	Wheel_Right_1->WheelNum = 2;
	//Wheel_Right_1->DamageStates(0) = (DamageBones = "wheel_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Wheel_Right_1->DamageStates(1) = (DamageBones = "ds1_wheel_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.5, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireFlat');
	//Wheel_Right_1->DamageStates(2) = (DamageBones = "ds2_wheel_right_1_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireMissing');
	Wheel_Right_1->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Right_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Right_2->ArmorThreshold = 2;
	Wheel_Right_2->DamageModifier = 10;
	Wheel_Right_2->MaxHitPoints = 1000;
	Wheel_Right_2->bWheelZone = true;
	//Wheel_Right_2->DamageStates(0) = (DamageBones = "wheel_right_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Wheel_Right_2->DamageStates(1) = (DamageBones = "ds1_wheel_right_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.5, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireFlat');
	//Wheel_Right_2->DamageStates(2) = (DamageBones = "ds2_wheel_right_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireMissing');
	Wheel_Right_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Wheel_Left_2 = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Wheel_Left_2->ArmorThreshold = 2;
	Wheel_Left_2->DamageModifier = 10;
	Wheel_Left_2->MaxHitPoints = 1000;
	Wheel_Left_2->bWheelZone = true;
	Wheel_Left_2->WheelNum = 1;
	//Wheel_Left_2->DamageStates(0) = (DamageBones = "wheel_left_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Wheel_Left_2->DamageStates(1) = (DamageBones = "ds1_wheel_left_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0.5, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireFlat');
	//Wheel_Left_2->DamageStates(2) = (DamageBones = "ds2_wheel_left_2_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'AGP_Vehicles.VPE_TireMissing');
	Wheel_Left_2->bNoPassDamageToVehicle = true;
	UVehicleDamageZone* Turret = NewObject<UVehicleDamageZone>(UVehicleDamageZone::StaticClass());
	Turret->ArmorThreshold = 3;
	Turret->MaxHitPoints = 1000;
	//Turret->DamageStates(0) = (DamageBones = "Yaw_bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 1, ChildDamagePct = 0, VisualEffectClass = class'None', VisualEffect = class'None', PhysicalEffect = class'None');
	//Turret->DamageStates(1) = (DamageBones = "DS1_yaw_Bone", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", DamageBones = "None", BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, BoneSlot = 0, DamagePct = 0, ChildDamagePct = 0, VisualEffectClass = Class'AGP_Effects.VehicleFireHeavySmokeSmall', VisualEffect = class'None', PhysicalEffect = class'None');
	Turret->bControlsExternalMesh = true;
	Turret->VehiclePositionOwnerIndex = 1;
	Turret->MeshOwnerType = EMeshOwnerType::MO_VehiclePositionWeapon;
	USVehicleWheel* RRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RRWheel->bPoweredWheel = true;
	RRWheel->BoneName = "wheel_right_2_bone";
	RRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RRWheel->WheelBoneOffset = FVector(0, -2, 0);
	RRWheel->WheelRadius = 22;
	RRWheel->FlatWheelRadius = 18;
	RRWheel->RimWheelRadius = 14;
	USVehicleWheel* LRWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LRWheel->bPoweredWheel = true;
	LRWheel->BoneName = "wheel_left_2_bone";
	LRWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LRWheel->WheelBoneOffset = FVector(0, 2, 0);
	LRWheel->WheelRadius = 22;
	LRWheel->FlatWheelRadius = 18;
	LRWheel->RimWheelRadius = 14;
	USVehicleWheel* RFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	RFWheel->bPoweredWheel = true;
	RFWheel->SteerType = EVehicleSteerType::VST_Steered;
	RFWheel->BoneName = "wheel_right_1_bone";
	RFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	RFWheel->WheelBoneOffset = FVector(0, -2, 0);
	RFWheel->WheelRadius = 22;
	RFWheel->FlatWheelRadius = 18;
	RFWheel->RimWheelRadius = 14;
	USVehicleWheel* LFWheel = NewObject<USVehicleWheel>(USVehicleWheel::StaticClass());
	LFWheel->bPoweredWheel = true;
	LFWheel->SteerType = EVehicleSteerType::VST_Steered;
	LFWheel->BoneName = "wheel_left_1_bone";
	LFWheel->BoneRollAxis = EAA2_Axis::AXIS_Y;
	LFWheel->WheelBoneOffset = FVector(0, 2, 0);
	LFWheel->WheelRadius = 22;
	LFWheel->FlatWheelRadius = 18;
	LFWheel->RimWheelRadius = 14;
	WheelSoftness = 0.02;
	WheelPenScale = 1.7;
	WheelPenOffset = 0.01;
	WheelRestitution = 0.1;
	WheelInertia = 0.1;
	//ZeroSizeSize;
	WheelLongSlip = 0.0001;
	//ZeroSizeSize;
	WheelLongFrictionScale = 0.7;
	WheelLatFrictionScale = 1.15;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 25;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 3;
	FTScale = 0.03;
	ChassisTorqueScale = 0.2;
	MinBrakeFriction = 4;
	//ZeroSizeSize;
	//ZeroSizeSize;
	GearRatios = { -0.78,0.27,0.58,0.97,1.4,1.95 };
	NumForwardGears = 5;
	TransRatio = 0.2;
	ChangeUpPoint = 3700;
	ChangeDownPoint = 1400;
	LSDFactor = 1;
	EngineBrakeFactor = 5E-05;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 20;
	SteerSpeed = 40;
	TurnDamping = 40;
	StopThreshold = 50;
	HandbrakeThresh = 200;
	EngineInertia = 0.05;
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
	//PositionTypes(0) = (VehiclePositionClass = class'AGP_Vehicles.PassengerPosition', WeaponBone = "None", PositionBone = "Seat_Passenger_1_Bone", FPCameraOffset = FVector(38, 25.5, 47), PosOffset = FVector(-6, 0, -8), RotOffset = (Pitch = 0, Yaw = 0, Roll = 0))
	//PositionTypes(1) = (VehiclePositionClass = class'AGP_Vehicles.Technical_Gunner', WeaponBone = "Weapon_1_Bone", PositionBone = "Seat_Gunner_1_bone", FPCameraOffset = FVector(0, 0, 0), PosOffset = FVector(-22, 2, -15), RotOffset = (Pitch = 0, Yaw = 0, Roll = 0));
	EntryPoints = { DriverSideEntry,PassengerSideEntry,GunnerEntry };
	IdleSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/Technical/ToyotaTech_Idle_Lp_1_Que.ToyotaTech_Idle_Lp_1_Que'"), NULL, LOAD_None, NULL);
	StartUpSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Vehicles/Technical/ToyotaTech_Start_1_Que.ToyotaTech_Start_1_Que'"), NULL, LOAD_None, NULL);
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/tacoma/Tacoma_Static_Damage.Tacoma_Static_Damage'"), NULL, LOAD_None, NULL);
	//DestroyedModelClass = class'AGP_Vehicles.TacomaTechnical_DestroyedBody';
	DestructionLinearMomentum = FRange({ 250000, 400000 });
	DestructionAngularMomentum = FRange({ 100, 150 });
	DefaultDamageZones = { Front_Left,Front_Middle,Front_Right,Front_Windshield,Side_Right,Middle_Middle,Rear_Windshield,Side_Left,Rear_Middle,Rear_Left,Side_Front_Left_Window,Side_Rear_Left_Window,Side_Front_Right_Window,Side_Rear_Right_Window,Rear_Right,Wheel_Left_1,Wheel_Right_1,Wheel_Right_2,Wheel_Left_2,Turret };
	
	TestDamageZones = {
		FTestDamageZoneInfo({ "Front_Left",0,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Front_Middle",1,2,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Front_Right",2,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Front_Windshield",3,0,1000,0,1,1,0,0 }),
		FTestDamageZoneInfo({ "Side_Right",4,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Middle_Middle",5,3,1000,0,0,1,0.9,0.6 }),
		FTestDamageZoneInfo({ "Rear_Windshield",6,0,1000,0,1,1,0,0 }),
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
		FIniParticleInfo({ "Front_Left","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Front_Middle","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Front_Right","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Front_Windshield","AGP_Effects.VehicleGlassShatter","" }),
		FIniParticleInfo({ "Side_Right","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Middle_Middle","AGP_Effects.VehicleLightSmoke","AGP_Effects.VehicleFireHeavySmokeSmall" }),
		FIniParticleInfo({ "Rear_Windshield","AGP_Effects.VehicleGlassShatter","" }),
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
		FIniParticleInfo({ "Turret","AGP_Effects.VehicleFireHeavySmokeSmall","" }),
	};


	bEjectPassengersWhenFlipped = false;
	ImpactDamageMult = 0.001;
	ImpactDamageRadius = 150;
	Wheels = { RRWheel,LRWheel,RFWheel,LFWheel };
	VehicleMass = 3.5;
	FlipTorque = 2000;
	FlipTime = 5;
	bDrawDriverInTP = true;
	bDrawMeshInFP = true;
	bDesiredBehindView = false;
	Team = 255;
	DriverBone = "seat_driver_bone";
	DriveAnim = "SF_Humvee_Driver_turn_Idle";
	DriverPosOffset = FVector(0, 0, -10);
	DriverRotOffset = FRotator(2000, 0, 0);
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100),FVector(0, -165, -100),FVector(0, 165, -100) };
	FPCamPos = FVector(38, -25.5, 47);
	TPCamDistance = 375;
	TPCamLookat = FVector(0, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 100);
	MomentumMult = 2;
	DriverDamageMult = 0.4;
	VehiclePositionString = "in a Technical";
	VehicleNameString = "Technical";
	ObjectiveGetOutDist = 1500;
	GroundSpeed = 600;
	HealthMax = 1000;
	Health = 1000;
	Bob = 0.016;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/Technical.Technical'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 175;
	//CollisionHeight = 120;
	KParams = KParams0;
}



/*
void ATechnical::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'tacoma-tire1');
	L.AddPrecacheMaterial(Texture'tacoma-inside');
	L.AddPrecacheMaterial(Texture'tacoma-main1grey');
	L.AddPrecacheMaterial(Shader'window_final');
	L.AddPrecacheMaterial(Texture'tacoma-bar1');
	L.AddPrecacheMaterial(Shader'DS1_Final_Tacoma');
	L.AddPrecacheMaterial(Shader'DS1_Bar_Tacoma');
	L.AddPrecacheMaterial(Shader'DS1_Window_Final');
	L.AddPrecacheMaterial(Shader'DS2_Final_Tacoma');
	L.AddPrecacheMaterial(Shader'DS2_Final_Inside_Tacoma');
	L.AddPrecacheMaterial(Shader'DS2_Bar_Tacoma');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	L.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	L.AddPrecacheStaticMesh(StaticMesh'Tacoma_Static_Damage');
	StaticPrecache(L);
}
*/
void ATechnical::UpdatePrecacheStaticMeshes()
{
	//Level.AddPrecacheStaticMesh(StaticMesh'Tacoma_Static_Damage');
	//UpdatePrecacheStaticMeshes();
}
void ATechnical::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(Texture'tacoma-tire1');
	Level.AddPrecacheMaterial(Texture'tacoma-inside');
	Level.AddPrecacheMaterial(Texture'tacoma-main1grey');
	Level.AddPrecacheMaterial(Shader'window_final');
	Level.AddPrecacheMaterial(Texture'tacoma-bar1');
	Level.AddPrecacheMaterial(Shader'DS1_Final_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS1_Bar_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS1_Window_Final');
	Level.AddPrecacheMaterial(Shader'DS2_Final_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS2_Final_Inside_Tacoma');
	Level.AddPrecacheMaterial(Shader'DS2_Bar_Tacoma');
	Level.AddPrecacheMaterial(Texture'fx_smk_ball01_dk');
	Level.AddPrecacheMaterial(Texture'fx_part_glasschunk');
	Level.AddPrecacheMaterial(Texture'fx_part_explosion01');
	Level.AddPrecacheMaterial(Texture'FX2_misc_explosionA');
	UpdatePrecacheMaterials();
	*/
}