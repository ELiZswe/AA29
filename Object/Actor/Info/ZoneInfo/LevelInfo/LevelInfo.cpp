// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Info/AGP_WorldInfo/AGP_WorldInfo.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/ObjectPool/ObjectPool.h"
#include "AA29/Object/LevelSummary/LevelSummary.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/BaseModAttachment/BaseModAttachment.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"

ALevelInfo::ALevelInfo()
{
	TourInfo.SetNum(32);
	actrlETAUsedFirstNamePrefixes.SetNum(26);
	asETAFirstNames.SetNum(26);
	NumAccomplishedObjectivesRequired.SetNum(2);
	TeamName.SetNum(2);
	Team1Inventory.SetNum(16);
	Team0Inventory.SetNum(16);
	LastTaunt.SetNum(2);
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
	DefaultTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/DefaultTexture_Mat.DefaultTexture_Mat'"), NULL, LOAD_None, NULL);
	WireframeTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/WhiteSquareTexture_Mat.WhiteSquareTexture_Mat'"), NULL, LOAD_None, NULL);
	WhiteSquareTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/WhiteSquareTexture_Mat.WhiteSquareTexture_Mat'"), NULL, LOAD_None, NULL);
	LargeVertex = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/LargeVertex_Mat.LargeVertex_Mat'"), NULL, LOAD_None, NULL);
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
	TeamName = {
		"ASSAULT",
		"DEFENSE"
	};
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
	asETASurNames = {
		"Adams",
		"Alexander",
		"Allen",
		"Anderson",
		"Bailey",
		"Baker",
		"Barnes",
		"Bell",
		"Bennett",
		"Brooks",
		"Brown",
		"Bryant",
		"Butler",
		"Campbell",
		"Carter",
		"Clark",
		"Coleman",
		"Collins",
		"Cook",
		"Cooper",
		"Cox",
		"Davis",
		"Diaz",
		"Edwards",
		"Evans",
		"Flores",
		"Foster",
		"Garcia",
		"Gonzales",
		"Gonzalez",
		"Gray",
		"Green",
		"Griffin",
		"Hall",
		"Harris",
		"Hayes",
		"Henderson",
		"Hernandez",
		"Hill",
		"Howard",
		"Hughes",
		"Jackson",
		"James",
		"Jenkins",
		"Johnson",
		"Jones",
		"Kelly",
		"King",
		"Lee",
		"Lewis",
		"Long",
		"Lopez",
		"Martin",
		"Martinez",
		"Miller",
		"Mitchell",
		"Moore",
		"Morgan",
		"Morris",
		"Murphy",
		"Nelson",
		"Parker",
		"Patterson",
		"Perez",
		"Perry",
		"Peterson",
		"Phillips",
		"Powell",
		"Price",
		"Ramirez",
		"Reed",
		"Richardson",
		"Rivera",
		"Roberts",
		"Robinson",
		"Rodriguez",
		"Rogers",
		"Ross",
		"Russell",
		"Sanchez",
		"Sanders",
		"Scott",
		"Simmons",
		"Smith",
		"Stewart",
		"Taylor",
		"Thomas",
		"Thompson",
		"Torres",
		"Turner",
		"Walker",
		"Ward",
		"Washington",
		"Watson",
		"White",
		"Williams",
		"Wilson",
		"Wood",
		"Wright",
		"Young",
	};
	asETANickNames = {
		"Alpha",
		"Apollo",
		"Arrow",
		"Atlas",
		"Avenger",
		"Bear",
		"Blade",
		"Blitz",
		"Boomstick",
		"Bravo",
		"Bulldog",
		"Bullet",
		"Bullseye",
		"Camper",
		"Cash",
		"Cobra",
		"Crispy",
		"Critter",
		"Daredevil",
		"Delta",
		"Demo",
		"Eagle",
		"Echo",
		"Ferret",
		"Flash",
		"Frago",
		"GridSquare",
		"GroundHog",
		"Gunship",
		"Hawkeye",
		"Hero",
		"Hooah",
		"Hulk",
		"Iron",
		"Invincible",
		"Justice",
		"Lantern",
		"Lifer",
		"Lightning",
		"Meteor",
		"Neo",
		"Nightmare",
		"Ninja",
		"November",
		"Nuke",
		"Medevac",
		"Patriot",
		"Pointer",
		"Rock",
		"Ricochet",
		"Sierra",
		"Smack",
		"Spider",
		"Spirit",
		"Stealth",
		"Steel",
		"Stretch",
		"Surgeon",
		"Tango",
		"Thunder",
		"Torch",
		"Touchdown",
		"Tripwire",
		"Rabbit",
		"Victory",
		"Warrior",
		"Weasel",
		"Whiskey",
		"Wolf",
		"Yankee",
		"Zeus",
		"Zulu"
	};
	asETAFirstNames = {
		"A.",
		"B.",
		"C.",
		"D.",
		"E.",
		"F.",
		"G.",
		"H.",
		"I.",
		"J.",
		"K.",
		"L.",
		"M.",
		"N.",
		"O.",
		"P.",
		"Q.",
		"R.",
		"S.",
		"T.",
		"U.",
		"V.",
		"W.",
		"X.",
		"Y.",
		"Z."
	};

	TourCategory = "<unknown>";
	IgnoreTours = { 15,16,30 };
	//bWorldGeometry = true;
	bAlwaysRelevant = true;
	//RemoteRole = ROLE_DumbProxy;
	//NV_AmbientGlow = 55;
	bHiddenEd = true;
}

/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		TimeDilation, Pauser, DefaultGravity;
	reliable if ((bNetInitial && (Role == ROLE_Authority)))
		KarmaTimeScale, RagdollTimeScale, KarmaGravScale;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		debugList, debug_num;
}
*/

void ALevelInfo::BeginPlay()
{
	FString Temp = "";
	Super::BeginPlay();
	/*
	Temp = GetBaseDir();
	sMapsDir = Left(Temp, (Len(Temp) - 7));
	sMapsDir = sMapsDir + "maps\\";
	LoadTourInfo();
	sLevelName = GetLevelNamePrivate();
	GetLevelTourAndMissionPrivate(sLevelName, iTour, iMission);
	GetLevelTourCategory(sLevelName, TourCategory);
	bTourSequential = IsTourSequentialPrivate(iTour);
	SetupProjectileMod();
	*/
}

//native Function bool IsLanOnlyServer();
bool ALevelInfo::IsLanOnlyServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function SetLanOnlyServer();
void ALevelInfo::SetLanOnlyServer()
{

}

//native Function UnsetLanOnlyServer();
void ALevelInfo::UnsetLanOnlyServer()
{

}

//native Function bool IsBetaServer();
bool ALevelInfo::IsBetaServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsLeasedServer();
bool ALevelInfo::IsLeasedServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsOfficialServer();
bool ALevelInfo::IsOfficialServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsUnofficialServer();
bool ALevelInfo::IsUnofficialServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsNATOServer();
bool ALevelInfo::IsNATOServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsTournamentServer();
bool ALevelInfo::IsTournamentServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsUltimateArenaServer();
bool ALevelInfo::IsUltimateArenaServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsAuthorizedServer();
bool ALevelInfo::IsAuthorizedServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function bool IsExploreTheArmyServer();
bool ALevelInfo::IsExploreTheArmyServer()
{
	return false;   //FAKE  /ELiZ
}

//native Function FString IsExploreTheArmyAccount(Controller ctrlr, FString sUserName, bool bTestOnly);
FString ALevelInfo::IsExploreTheArmyAccount(AController* ctrlr, FString sUserName, bool bTestOnly)
{
	return "FAKE";   //FAKE  /ELiZ
}

//native Function bool EnableDebugThis();
bool ALevelInfo::EnableDebugThis()
{
	return false;   //FAKE  /ELiZ
}

//native Function PBNotifyServerTravel();
void ALevelInfo::PBNotifyServerTravel()
{

}

//native Function int32 PBIsEnabled();
int32 ALevelInfo::PBIsEnabled()
{
	return 0;   //FAKE  /ELiZ
}

//native Function PBEnable();
void ALevelInfo::PBEnable()
{

}

//native Function PBDisable();
void ALevelInfo::PBDisable()
{

}

void ALevelInfo::FirstDraw()
{
	AActor* A = nullptr;
	/*
	ForEach AllActors(Class'Actor', A)
	{
		if (A->IsA(AEventLab::StaticClass()))
		{
			A.ActorNotify(this, 22, nullptr, "");
		}
	}
	*/
}

void ALevelInfo::SetupProjectileMod()
{
	/*
	AAGP_WorldInfo* L = nullptr;
	ForEach AllActors(AAGP_WorldInfo::StaticClass(), L)
	{
		fProjectileMod = (((L.fHumidBase - L.fHumidity) * L.fHumidFactor) + ((L.fTemperature - L.fTempBase) * L.fTempFactor));
	}
	*/
}

float ALevelInfo::GetProjectileMod()
{
	return fProjectileMod;
}

void ALevelInfo::AddViewpoint(AAGP_Viewpoint* nextv)
{
	AAGP_Viewpoint* insertv = nullptr;
	/*
	DebugLog(DEBUG_Spec, "---------------------------------------------------------------");
	DebugLog(DEBUG_Spec, "LevelInfo::AddViewpoint()	Adding " + FString::FromInt(nextv) @ FString::FromInt(nextv.iSequence));
	if (ViewpointList == nullptr)
	{
		ViewpointList = nextv;
		nextv.NextViewpoint = nullptr;
	}
	else
	{
		if (nextv.iSequence < ViewpointList.iSequence)
		{
			nextv.NextViewpoint = ViewpointList;
			ViewpointList = nextv;
		}
		else
		{
			insertv = ViewpointList;
			if ((insertv.NextViewpoint != nullptr) && (insertv.NextViewpoint.iSequence < nextv.iSequence))
			{
				insertv = insertv.NextViewpoint;
			}
			if (insertv.NextViewpoint != nullptr)
			{
				nextv.NextViewpoint = insertv.NextViewpoint;
			}
			insertv.NextViewpoint = nextv;
		}
	}
	DebugLog(DEBUG_Spec, "LevelInfo::AddViewpoint()	------------------------------");
	for (insertv = ViewpointList; insertv != nullptr; insertv = insertv.NextViewpoint)
	{
		DebugLog(DEBUG_Spec, "LevelInfo::AddViewpoint()	" + FString::FromInt(insertv) @ FString::FromInt(insertv.iSequence));
	}
	DebugLog(DEBUG_Spec, "LevelInfo::AddViewpoint()	------------------------------");
	*/
}

bool ALevelInfo::debugThis(EDebugTag Debug)
{
	int32 i = 0;
	/*
	if (((!EnableDebugThis()) && (Debug != 1)) && (Debug != 2))
	{
		return false;
	}
	switch (Debug)
	{
	case 0:
	case 1:
	case 2:
		return false;
	case 3:
		return (!bSilentLog);
	case 4:
		return (NetMode != 0);
	case 5:
		return ((NetMode == 2) || (NetMode == 1));
	case 6:
		return (NetMode == 3);
	case 7:
		return (NetMode == 0);
	default:
		i = 0;

		//HERE iS a forLOOP
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
	*/
	return false;    //FAKE  /ELiZ
}

bool ALevelInfo::addDebug(EDebugTag Debug)
{
	int32 i = 0;
	/*
	if (Debug <= 7)
	{
		return false;
	}
	for (i = 0; i < debug_num; i++)
	{
		if (debugList[i] == Debug)
		{
			return false;
		}
	}
	debugList[debug_num] = Debug;
	debug_num++;
	*/
	return true;
}

bool ALevelInfo::removeDebug(EDebugTag Debug)
{
	int32 i = 0;
	int32 ilocation = 0;
	/*
	if (Debug <= 7)
	{
		return false;
	}
	ilocation = -1;
	i = 0;
	if (i < debug_num)
	{
		if (debugList[i] == Debug)
		{
			ilocation = i;
		}
		else
		{
			i++;
		}
	}
	if (ilocation == -1)
	{
		return false;
	}
	debug_num--;
	for (i = ilocation; i < debug_num; i++)
	{
		debugList[i] = debugList[(i + 1)];
	}
	*/
	return true;
}

bool ALevelInfo::toggleDebug(EDebugTag Debug)
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

void ALevelInfo::addPickup(APickup* add_pickup)
{
	APickup* last_pickup = nullptr;
	/*
	if (PickupList == nullptr)
	{
		PickupList = add_pickup;
	}
	else
	{
		last_pickup = PickupList;
		if (last_pickup.Next != nullptr)
		{
			if (last_pickup == add_pickup)
			{
				Log("WARNING: LevelInfo::addPickup()	Attempting to add Pickup already in the list " + FString::FromInt(add_pickup));
				return;
			}
			last_pickup = last_pickup.Next;
		}
		last_pickup.Next = add_pickup;
	}
	add_pickup.Next = nullptr;
	*/
}

void ALevelInfo::removePickup(APickup* remove_pickup)
{
	APickup* last_pickup = nullptr;
	/*
	if (PickupList == remove_pickup)
	{
		PickupList = PickupList->Next;
	}
	else
	{
		last_pickup = PickupList;
		if (last_pickup->Next != remove_pickup)
		{
			last_pickup = last_pickup.Next;
			if (last_pickup == nullptr)
			{
				Log("WARNING: LevelInfo::removePickup()	Attempting to remove Pickup not in the list " + FString::FromInt(remove_pickup));
				remove_pickup->Next = nullptr;
				return;
			}
		}
		last_pickup->Next = last_pickup->Next->Next;
	}
	remove_pickup->Next = nullptr;
	*/
}

void ALevelInfo::LogPickupList(FString printstring)
{
	APickup* p = nullptr;
	/*
	DebugLog(DEBUG_Always, "LevelInfo::LogPickupList()	====BEGIN LIST==== (" @ printstring @ ")");
	for (p = PickupList; p != nullptr; p = p.Next)
	{
		DebugLog(DEBUG_Always, "LevelInfo::LogPickupList()	Cast<APickup>(" @ FString::FromInt(p) @ ")");
	}
	DebugLog(DEBUG_Always, "LevelInfo::LogPickupList()	=====END LIST===== (" @ printstring @ ")");
	*/
}

FString ALevelInfo::GetDefaultBinoc()
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

ESkinSet ALevelInfo::GetSkinSet(bool bFriendly)
{
	ESkinSet aSkinSet;
	if (bFriendly)
	{
		aSkinSet = SkinSetFriendly;
	}
	else
	{
		aSkinSet = SkinSetEnemy;
	}
	return aSkinSet;
}

EWeaponSkinSet ALevelInfo::GetWeaponSkinSet(bool bFriendly)
{
	return WeaponSkinSetFriendly;
}

bool ALevelInfo::IsUSSkin(bool bFriendly)
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

FString ALevelInfo::GetSkin_Package()
{
	return "T_AA2_Characters";
}

ESkinSet ALevelInfo::GetMILESSkin(ESkinSet tSkin)
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

EMesh ALevelInfo::GetMILESMesh(EMesh tMesh)
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

FString ALevelInfo::GetSkin_Option(bool bFriendly)
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

FString ALevelInfo::GetSkin_Option_Parachute(bool bFriendly)
{
	return GetSkin_Option(bFriendly);
}

FString ALevelInfo::GetSkin_Group(bool bFriendly)
{
	if (GetMesh(bFriendly) == EMesh::MESH_SF)
	{
		return "SF";
	}
	switch (GetSkinSet(bFriendly))
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

EMesh ALevelInfo::GetMesh(bool bFriendly)
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

void ALevelInfo::SetActorLevelSkin(AActor* A, bool bFriendly, FString level_tag)
{
	int32 i = 0;
	UMaterialInstance* old_material = nullptr;
	UMaterialInstance* new_material = nullptr;
	FString new_name = "";
	UObject* temp_obj = nullptr;
	/*
	A.AlphaSkins.RemoveAt(0, A.AlphaSkins.Num());
	A.BlackSkins.RemoveAt(0, A.BlackSkins.Num());
	A.Skins.RemoveAt(0, A.Skins.Num());
	if (level_tag == "")
	{
		if ((((A->IsA(APickup::StaticClass()) || A->IsA(AWeaponAttachment::StaticClass())) || A->IsA(ABaseModAttachment::StaticClass())) || A->IsA(AAGP_Weapon::StaticClass())) || A->IsA(ABaseWeaponMod::StaticClass()))
		{
			switch (GetWeaponSkinSet(bFriendly))
			{
			case 0:
				break;
			case 1:
				level_tag = "Des";
				break;
			case 2:
				level_tag = "Arc";
				break;
			default:
			}
		}
		else
		{
			switch (GetSkinSet(bFriendly))
			{
			case 1:
				level_tag = "Des";
				break;
			case 10:
			case 4:
				level_tag = "Arc";
				break;
			default:
			}
		}
	}
	i = 0;
	old_material = A.GetDisplayedSkin(i);
	if (old_material != nullptr)
	{
		new_name = A.GetActorLevelSkin(i, old_material, level_tag);
		temp_obj = DynamicLoadObject(new_name, Class'Material', true);
		new_material = Cast<UMaterialInstance>(temp_obj);
		DebugLog(DEBUG_Skin, "LevelInfo::SetActorLevelSkin()	Actor" @ FString::FromInt(A) @ "old(" @ FString::FromInt(old_material) @ ") new(" @ new_name @ ")" @ FString::FromInt(new_material));
		if (new_material == nullptr)
		{
			new_material = old_material;
		}
		A.Skins[i] = new_material;
		i++;
		old_material = A.GetDisplayedSkin(i);
	}
	*/
}

AGrenadeHelper* ALevelInfo::GetGrenadeHelper()
{
	if (GrenHelper == nullptr)
	{
		//GrenHelper = Spawn(AGrenadeHelper::StaticClass());
	}
	return GrenHelper;
}

APlayerController* ALevelInfo::GetClientController()
{
	AAA2_PlayerState* PRI = nullptr;
	PRI = GetClient();
	if (PRI != nullptr)
	{
		//return PlayerController(PRI.Owner);
	}
	return nullptr;    //FAKE   /EliZ
}

APawn* ALevelInfo::GetClientPawn()
{
	AAA2_PlayerState* PRI = nullptr;
	PRI = GetClient();
	if (PRI != nullptr)
	{
		//return PRI.myPawn;
	}
	return nullptr;
}

void ALevelInfo::SetClientController(AController* C)
{
	/*
	if (((Client == nullptr) || (Client.Owner == nullptr)) && (C->IsA(APlayerController::StaticClass()) && (C.PlayerReplicationInfo != nullptr)))
	{
		Client = C.PlayerReplicationInfo;
		Client.SetOwner(C);
	}
	*/
}

AAA2_PlayerState* ALevelInfo::GetClient()
{
	APlayerController* PC = nullptr;
	/*
	if (((Client == nullptr) || (Client.Owner == nullptr)) && (!IsServer()))
	{
		ForEach DynamicActors(Class'PlayerController', PC)
		{
			if (PC.PlayerReplicationInfo != nullptr)
			{
				Client = PC.PlayerReplicationInfo;
				Client.SetOwner(PC);
			}
		}
	}
	*/
	return Client;
}

bool ALevelInfo::IsMILES()
{
	return (GamePlayMode == EGameplayModes::GM_MILES);
}

bool ALevelInfo::IsServer()
{
	//return ((NetMode == ENetMode::NM_DedicatedServer) || (NetMode == ENetMode::NM_ListenServer));
	return false;    //FAKE  /EliZ
}

FString ALevelInfo::GetLevelNamePrivate()
{
	int32 pos0 = 0;
	int32 pos1 = 0;
	int32 pos2 = 0;
	FString string0 = "";
	FString string1 = "";
	FString string2 = "";
	/*
	string0 = Level.GetLocalURL();
	pos0 = InStr(string0, "/");
	pos1 = InStr(string0, ".");
	pos2 = InStr(string0, "?");
	if (pos0 != -1)
	{
		string1 = Mid(string0, (pos0 + 1), (pos2 - pos0));
		string0 = string1;
		pos1 = InStr(string0, ".");
		pos2 = InStr(string0, "?");
	}
	if ((pos1 == -1) || (pos1 > pos2))
	{
		pos1 = pos2;
	}
	if (((pos0 == -1) && (pos1 == -1)) && (pos2 == -1))
	{
		string2 = string0;
	}
	else
	{
		string2 = Left(string0, pos1);
	}
	*/
	return string2;
}

void ALevelInfo::GetLevelMissionPrivate(FString asLevelName, int32 aiTour, FString& sLevelFile)
{
	FString sFile = "";
	FString sTemp = "";
	FString sLine = "";
	FString sInfo = "";
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	int32 iCurNumTours = 0;
	int32 iCurNumMissions = 0;
	FString sMissionName = "";
	FString sMissionFile = "";
	/*
	sLevelFile = "";
	if (asLevelName ~= "entry")
	{
		return;
	}
	if (30 == aiTour)
	{
		return;
	}
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iCurNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iCurNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		sInfo = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = sInfo;
		iCurNumMissions = GetPrivateProfileInt(sFile, sLine, "NumMissions");
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sMissionName = GetPrivateProfileString(sFile, sLine, "MissionMBSTitle(" + FString::FromInt(iCurMission) + ")");
			sMissionFile = GetPrivateProfileString(sFile, sLine, "MissionMapFilename(" + FString::FromInt(iCurMission) + ")");
			if (sMissionName ~= asLevelName)
			{
				sLevelFile = sMissionFile;
				return;
			}
		}
	}
	DebugLog(DEBUG_Warn, "Failure finding mission '" + asLevelName + "' - tours.ini is invalid.");
	*/
}

void ALevelInfo::GetLevelTourAndMissionPrivate(FString asLevelName, int32& aiTour, int32& aiMission)
{
	FString sFile = "";
	FString sTemp = "";
	FString sLine = "";
	FString sInfo = "";
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	int32 iCurNumTours = 0;
	int32 iCurNumMissions = 0;
	FString sMissionName = "";
	/*
	if (30 == aiTour)
	{
		aiMission = 0;
		return;
	}
	aiTour = -1;
	aiMission = -1;
	if (asLevelName ~= "entry")
	{
		return;
	}
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iCurNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iCurNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		sInfo = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = sInfo;
		iCurNumMissions = GetPrivateProfileInt(sFile, sLine, "NumMissions");
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sMissionName = GetPrivateProfileString(sFile, sLine, "MissionMapFilename(" + FString::FromInt(iCurMission) + ")");
			if (sMissionName ~= asLevelName)
			{
				aiTour = iCurTour;
				aiMission = iCurMission;
				return;
			}
		}
	}
	DebugLog(DEBUG_Warn, "LevelInfo::GetLevelTourAndMissionPrivate Failure finding mission '" + asLevelName + "' - tours.ini is invalid.");
	*/
}

void ALevelInfo::GetMBSTitleTourAndMissionPrivate(FString asLevelName, int32& aiTour, int32& aiMission)
{
	FString sFile = "";
	FString sTemp = "";
	FString sLine = "";
	FString sInfo = "";
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	int32 iCurNumTours = 0;
	int32 iCurNumMissions = 0;
	FString sMissionName = "";
	aiTour = -1;
	aiMission = -1;
	/*
	if (asLevelName ~= "entry")
	{
		return;
	}
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iCurNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iCurNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		sInfo = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = sInfo;
		iCurNumMissions = GetPrivateProfileInt(sFile, sLine, "NumMissions");
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sMissionName = GetPrivateProfileString(sFile, sLine, "MissionMBSTitle(" + FString::FromInt(iCurMission) + ")");
			if (sMissionName ~= asLevelName)
			{
				aiTour = iCurTour;
				aiMission = iCurMission;
				return;
			}
		}
	}
	DebugLog(DEBUG_Warn, "LevelInfo::GetLevelTourAndMissionPrivate Failure finding mission '" + asLevelName + "' - tours.ini is invalid.");
	*/
}

void ALevelInfo::GetLevelTourCategory(FString asLevelName, FString& aTourCategory)
{
	FString sFile = "";
	FString sTemp = "";
	FString sLine = "";
	FString sInfo = "";
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	int32 iCurNumTours = 0;
	int32 iCurNumMissions = 0;
	FString sMissionName = "";
	/*
	if (asLevelName ~= "entry")
	{
		return;
	}
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iCurNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iCurNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		sInfo = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = sInfo;
		iCurNumMissions = GetPrivateProfileInt(sFile, sLine, "NumMissions");
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sMissionName = GetPrivateProfileString(sFile, sLine, "MissionMapFilename(" + FString::FromInt(iCurMission) + ")");
			if (sMissionName ~= asLevelName)
			{
				aTourCategory = GetPrivateProfileString(sFile, sLine, "TourCategory");
				return;
			}
		}
	}
	DebugLog(DEBUG_Warn, "LevelInfo::GetLevelTourCategory Failure finding tour category for mission '" + asLevelName + "' - tours.ini is invalid.");
	*/
}

bool ALevelInfo::IsTourSequentialPrivate(int32 aiTour)
{
	FString sFile = "";
	FString sTemp = "";
	int32 iIsSequential = 0;
	if (aiTour == -1)
	{
		return false;
	}
	/*
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iIsSequential = GetPrivateProfileInt(sFile, "Tours", "IsSequential(" + FString::FromInt(aiTour) + ")");
	*/
	if (iIsSequential != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ALevelInfo::CanPlayerPlayMissionPrivate(APlayerController* PC, int32 aiTour, int32 aiMission)
{
	int32 iCurMission = 0;
	int32 iCurTour = 0;
	/*
	if ((aiTour == -1) && (aiMission == -1))
	{
		if (PC.PlayerReplicationInfo.hasSoldiersCharacter())
		{
			return true;
		}
	}
	if ((30 == aiTour) && (aiMission >= 0))
	{
		if (PC.iCompleted[1] == 0)
		{
			return false;
		}
		return true;
	}
	if (!(((aiTour >= 0) && (aiTour < 32)) && (aiMission >= 0)))
	{
		return false;
	}
	if (!((aiTour < iNumTours) && (aiMission < TourInfo[aiTour].iNumMissions)))
	{
		return false;
	}
	if (PC.PlayerReplicationInfo != nullptr)
	{
		if ((((((((aiTour == 1) || (aiTour == 2)) || (aiTour == 3)) || (aiTour == 6)) || (aiTour == 7)) || (aiTour == 8)) || (aiTour == 11)) && PC.PlayerReplicationInfo.bQualifiedViaInstantAction)
		{
			Log("Skipping training requirements for non-SF exclusive map and player not completing BCT for tour " + FString::FromInt(aiTour));
			return true;
		}
		if ((aiTour == 11) && PC.PlayerReplicationInfo.bQualifiedBCT)
		{
			Log("BCT qualified allowed to play on SF map");
			return true;
		}
		if (PC.PlayerReplicationInfo.bQualifiedViaInstantAction && (aiTour == 12))
		{
			Log("Rejecting instant action player on SF exclusive server tour " + FString::FromInt(aiTour));
			return false;
		}
	}
	if (!IgnoreTourComplete(aiTour))
	{
		if ((int((2 * *float(aiMission))) & PC.iCompleted[(aiTour + 1)]) > 0)
		{
			return true;
		}
		if (TourInfo[aiTour].IsSequential)
		{
			for (iCurMission = (aiMission - 1); iCurMission >= 0; iCurMission--)
			{
				if ((int((2 * *float(iCurMission))) & PC.iCompleted[(aiTour + 1)]) == 0)
				{
					return false;
				}
			}
		}
	}
	iCurTour = aiTour;
	if (TourInfo[iCurTour].Dependency != -1)
	{
		iCurTour = TourInfo[iCurTour].Dependency;
		Log("Dependency for tour " + FString::FromInt(aiTour) + " is tour " + FString::FromInt(iCurTour) + ", bit shift " + FString::FromInt((2 * *float(iCurTour))) + ", and player completed for BCT " + FString::FromInt(PC.iCompleted[0]));
		if ((int((2 * *float(iCurTour))) & PC.iCompleted[0]) == 0)
		{
			Log("AGP_GameInfo::CanPlayerPlayMissionPrivate() no - 4 - dependency not met.", "TourInfo");
			return false;
		}
	}
	if (aiTour == 4)
	{
		if (PC.iRifleRangeRating < 36)
		{
			return false;
		}
	}
	if (aiTour == 12)
	{
		if ((Level.IsServer() && Level.Game.IsRequireAuthorization()) && (!Level.IsExploreTheArmyServer()))
		{
			if (PC.PlayerReplicationInfo.GetHonor() < 15)
			{
				return false;
			}
		}
	}
	Log("AGP_GameInfo::CanPlayerPlayMissionPrivate() yes - its all good!", "TourInfo");
	*/
	return true;
}

int32 ALevelInfo::DidPlayerCompleteNewMission(APlayerController* PC)
{
	return DidPlayerCompleteNewMissionPrivate(PC, iTour, iMission);
}

int32 ALevelInfo::DidPlayerCompleteNewMissionPrivate(APlayerController* PC, int32 aiTour, int32 aiMission)
{
	/*
	if (!(((aiTour >= 0) && (aiTour < 32)) && (aiMission >= 0)))
	{
		return -1;
	}
	if (!((aiTour < iNumTours) && (aiMission < TourInfo[aiTour].iNumMissions)))
	{
		return -1;
	}
	if ((aiTour == 0) && (aiMission == 0))
	{
		return 1;
	}
	if (!IgnoreTourComplete(aiTour))
	{
		if ((int((2 * *float(aiMission))) & PC.iCompleted[(aiTour + 1)]) > 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	*/
	return 1;
}

FString ALevelInfo::GetLevelName()
{
	return sLevelName;
}

int32 ALevelInfo::GetLevelTour()
{
	return iTour;
}

int32 ALevelInfo::GetLevelMission()
{
	return iMission;
}

bool ALevelInfo::IsTourSequential()
{
	return bTourSequential;
}

bool ALevelInfo::CanPlayerPlayMission(APlayerController* PC)
{
	return CanPlayerPlayMissionPrivate(PC, iTour, iMission);
}

void ALevelInfo::LoadTourInfo()
{
	FString sTemp = "";
	FString sFile = "";
	FString sLine = "";
	int32 iCurNumMissions = 0;
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	FMissionStruct NewMission = FMissionStruct({});
	/*
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	if (iNumTours < 0)
	{
		iNumTours = 0;
	}
	if (iNumTours > 32)
	{
		iNumTours = 32;
	}
	for (iCurTour = 0; iCurTour < iNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].Tour = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "Dependency(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].Dependency = GetPrivateProfileInt(sFile, "Tours", sLine);
		sLine = "Image(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].Image = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "TourText(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].TourText = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "TourTextTitle(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].TourTextTitle = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "HistoryText(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].HistoryText = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "HistoryTextTitle(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].HistoryTextTitle = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "IsSequential(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].IsSequential = bool(GetPrivateProfileString(sFile, "Tours", sLine));
		sLine = "IsTraining(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].IsTraining = bool(GetPrivateProfileString(sFile, "Tours", sLine));
		if (debugTours)
		{
			Log("Tour" + FString::FromInt(iCurTour) @ TourInfo[iCurTour].Tour, "TourInfo");
			Log("Dependency " + FString::FromInt(TourInfo[iCurTour].Dependency), "TourInfo");
			Log("Image " + TourInfo[iCurTour].Image, "TourInfo");
			Log("TourText " + TourInfo[iCurTour].TourText, "TourInfo");
			Log("TourTextTitle " + TourInfo[iCurTour].TourTextTitle, "TourInfo");
			Log("HistoryText " + TourInfo[iCurTour].HistoryText, "TourInfo");
			Log("HistoryTextTitle " + TourInfo[iCurTour].HistoryTextTitle, "TourInfo");
			Log("IsSequential " + FString::FromInt(TourInfo[iCurTour].IsSequential), "TourInfo");
			Log("IsTraining " + FString::FromInt(TourInfo[iCurTour].IsTraining), "TourInfo");
		}
		iCurNumMissions = GetPrivateProfileInt(sFile, TourInfo[iCurTour].Tour, "NumMissions");
		if (iCurNumMissions < 0)
		{
			iCurNumMissions = 0;
		}
		TourInfo[iCurTour].iNumMissions = iCurNumMissions;
		if (debugTours)
		{
			Log("iNumMissions " + FString::FromInt(TourInfo[iCurTour].iNumMissions), "TourInfo");
		}
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sLine = "MissionTitle(" + FString::FromInt(iCurMission) + ")";
			NewMission.Title = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionMBSTitle(" + FString::FromInt(iCurMission) + ")";
			NewMission.MBSTitle = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionImage(" + FString::FromInt(iCurMission) + ")";
			NewMission.Image = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionImageDisabled(" + FString::FromInt(iCurMission) + ")";
			NewMission.ImageDisabled = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionMapFilename(" + FString::FromInt(iCurMission) + ")";
			NewMission.MapFilename = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			NewMission.bFileExists = DoesMapExist(NewMission.MapFilename);
			TourInfo[iCurTour].Mission[iCurMission] = NewMission;
			if (debugTours)
			{
				Log("  Mission" + FString::FromInt(iCurMission) @ TourInfo[iCurTour].Mission[iCurMission].Title, "TourInfo");
				Log("    MBSTitle" + FString::FromInt(iCurMission) @ TourInfo[iCurTour].Mission[iCurMission].MBSTitle, "TourInfo");
				Log("    Image " + TourInfo[iCurTour].Mission[iCurMission].Image, "TourInfo");
				Log("    ImageDisabled " + TourInfo[iCurTour].Mission[iCurMission].ImageDisabled, "TourInfo");
				Log("    MapFilename" @ TourInfo[iCurTour].Mission[iCurMission].MapFilename @ "exists:" @ FString::FromInt(TourInfo[iCurTour].Mission[iCurMission].bFileExists), "TourInfo");
			}
		}
	}
	*/
}

FTourStruct ALevelInfo::GetTour(int32 Index)
{
	FTourStruct ts = {};
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index];
	}
	return ts;
}

FString ALevelInfo::GetTourName(int32 Index)
{
	FString ts = "";
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].Tour;
	}
	return ts;
}

FString ALevelInfo::GetTourImage(int32 Index)
{
	FString ts = "";
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].Image;
	}
	return ts;
}

FString ALevelInfo::GetTourText(int32 Index)
{
	FString ts = "";
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].TourText;
	}
	return ts;
}

FString ALevelInfo::GetTourTextTitle(int32 Index)
{
	FString ts = "";
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].TourTextTitle;
	}
	return ts;
}

FString ALevelInfo::GetTourHistoryText(int32 Index)
{
	FString ts = "";
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].HistoryText;
	}
	return ts;
}

FString ALevelInfo::GetTourHistoryTextTitle(int32 Index)
{
	FString ts = "";
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].HistoryTextTitle;
	}
	return ts;
}

int32 ALevelInfo::GetTourDependency(int32 Index)
{
	int32 ts = 0;
	ts = -1;
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].Dependency;
	}
	return ts;
}

bool ALevelInfo::GetTourIsSequential(int32 Index)
{
	bool ts = false;
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].IsSequential;
	}
	return ts;
}

bool ALevelInfo::GetTourIsTraining(int32 Index)
{
	bool ts = false;
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].IsTraining;
	}
	return ts;
}

int32 ALevelInfo::GetTourMissions(int32 Index)
{
	int32 ts = 0;
	ts = 0;
	if ((Index >= 0) && (Index < 32))
	{
		ts = TourInfo[Index].iNumMissions;
	}
	return ts;
}

FString ALevelInfo::GetTourMissionTitle(int32 Tour, int32 Mission)
{
	FString ts = "";
	if ((((Tour >= 0) && (Tour < 32)) && (Mission >= 0)) && (Mission < TourInfo[Tour].iNumMissions))
	{
		ts = TourInfo[Tour].Mission[Mission].Title;
	}
	return ts;
}

FString ALevelInfo::GetTourMissionMBSTitle(int32 Tour, int32 Mission)
{
	FString ts = "";
	if ((((Tour >= 0) && (Tour < 32)) && (Mission >= 0)) && (Mission < TourInfo[Tour].iNumMissions))
	{
		ts = TourInfo[Tour].Mission[Mission].MBSTitle;
	}
	return ts;
}

FString ALevelInfo::GetTourMissionImage(int32 Tour, int32 Mission)
{
	FString ts = "";
	if ((((Tour >= 0) && (Tour < 32)) && (Mission >= 0)) && (Mission < TourInfo[Tour].iNumMissions))
	{
		ts = TourInfo[Tour].Mission[Mission].Image;
	}
	return ts;
}

FString ALevelInfo::GetTourMissionImageDisabled(int32 Tour, int32 Mission)
{
	FString ts = "";
	if ((((Tour >= 0) && (Tour < 32)) && (Mission >= 0)) && (Mission < TourInfo[Tour].iNumMissions))
	{
		ts = TourInfo[Tour].Mission[Mission].ImageDisabled;
	}
	return ts;
}

FString ALevelInfo::GetTourMissionMapFilename(int32 Tour, int32 Mission)
{
	FString ts = "";
	if ((((Tour >= 0) && (Tour < 32)) && (Mission >= 0)) && (Mission < TourInfo[Tour].iNumMissions))
	{
		ts = TourInfo[Tour].Mission[Mission].MapFilename;
	}
	return ts;
}

void ALevelInfo::ClientGetInfo()
{
	LoadTourInfo();
	sLevelName = GetLevelNamePrivate();
	GetLevelTourAndMissionPrivate(sLevelName, iTour, iMission);
	GetLevelTourCategory(sLevelName, TourCategory);
	bTourSequential = IsTourSequentialPrivate(iTour);
}

bool ALevelInfo::DoesMapExist(FString MapName)
{
	FString sFullName = "";
	/*
	sFullName = sMapsDir + MapName + ".aao";
	if (FOpen(sFullName))
	{
		FClose();
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool ALevelInfo::IgnoreTourComplete(int32 TourIndex)
{
	int32 i = 0;
	for (i = 0; i < IgnoreTours.Num(); i++)
	{
		if (TourIndex == IgnoreTours[i])
		{
			return true;
		}
	}
	return false;
}

void ALevelInfo::UpdateAllMissionsStatus(APlayerController* PC)
{
	int32 it = 0;
	int32 im = 0;
	int32 iTempMissions = 0;
	bool bFoundLastSeqCompleted = false;
	for (it = 0; it < 32; it++)
	{
		for (im = 0; im < TourInfo[it].iNumMissions; im++)
		{
			TourInfo[it].Status = -1;
			TourInfo[it].Mission[im].Status = -1;
		}
	}
	if (debugTours)
	{
		//Log("LevelInfo::UpdateAllMissionsStatus()", "TourInfo");
	}
	/*
	for (it = 0; it < iNumTours; it++)
	{
		if (debugTours)
		{
			//Log("Tour " + FString::FromInt(it), "TourInfo");
		}
		iTempMissions = 0;
		if ((int((2 * *float(it))) & PC.iCompleted[0]) > 0)
		{
			if (debugTours)
			{
				//Log("marked as completed", "TourInfo");
			}
			if (TourInfo[it].Dependency != -1)
			{
				if (debugTours)
				{
					//Log("Tour Dependency " + FString::FromInt(TourInfo[it].Dependency), "TourInfo");
				}
				if ((int((2 * *float(TourInfo[it].Dependency))) & PC.iCompleted[0]) > 0)
				{
					if (debugTours)
					{
						//Log("Depedency is met - setting as complete", "TourInfo");
					}
					TourInfo[it].Status = 1;
				}
				else
				{
					if (debugTours)
					{
						//Log("Depenency not met", "TourInfo");
					}
				}
			}
			else
			{
				if (debugTours)
				{
					//Log("No Tour Dependency - setting as complete", "TourInfo");
				}
				TourInfo[it].Status = 1;
			}
			if (debugTours)
			{
				//Log("checking missions", "TourInfo");
			}
			for (im = 0; im < TourInfo[it].iNumMissions; im++)
			{
				if ((int((2 * *float(im))) & PC.iCompleted[(it + 1)]) > 0)
				{
					if (TourInfo[it].Mission[im].bFileExists)
					{
						if (debugTours)
						{
							//Log("Mission" @ FString::FromInt(im) @ "completed and file exists", "TourInfo");
						}
						TourInfo[it].Mission[im].Status = 1;
					}
					else
					{
						if (debugTours)
						{
							//Log("Mission" @ FString::FromInt(im) @ "completed and file DOES NOT exist", "TourInfo");
						}
					}
				}
				else
				{
					if (debugTours)
					{
						//Log("Mission" @ FString::FromInt(im) @ "not completed", "TourInfo");
					}
				}
			}
		}
		else
		{
			if (debugTours)
			{
				//Log("Tour" @ FString::FromInt(it) @ "is NOT flagged as completed", "TourInfo");
			}
			if (TourInfo[it].Dependency != -1)
			{
				if (debugTours)
				{
					//Log("Tour Dependency " + FString::FromInt(TourInfo[it].Dependency), "TourInfo");
				}
				if ((int((2 * *float(TourInfo[it].Dependency))) & PC.iCompleted[0]) > 0)
				{
					if (debugTours)
					{
						//Log("Depedency is met - checking mission specific dependencies", "TourInfo");
					}
					if (it == 4)
					{
						if (PC.iRifleRangeRating >= 36)
						{
							TourInfo[it].Status = 0;
						}
					}
					else
					{
						if (debugTours)
						{
							//Log("no dependency - set as available", "TourInfo");
						}
						TourInfo[it].Status = 0;
					}
				}
			}
			else
			{
				if (debugTours)
				{
					//Log("no dependency - set as available", "TourInfo");
				}
				TourInfo[it].Status = 0;
			}
			bFoundLastSeqCompleted = false;
			if (debugTours)
			{
				//Log("checking missions", "TourInfo");
			}
			if (!IgnoreTourComplete(it))
			{
				for (im = 0; im < TourInfo[it].iNumMissions; im++)
				{
					if ((int((2 * *float(im))) & PC.iCompleted[(it + 1)]) > 0)
					{
						if (TourInfo[it].Mission[im].bFileExists)
						{
							if (debugTours)
							{
								//Log("Mission" @ FString::FromInt(im) @ "completed and file exists", "TourInfo");
							}
							TourInfo[it].Mission[im].Status = 1;
						}
						else
						{
							if (debugTours)
							{
								//Log("Mission" @ FString::FromInt(im) @ "completed and file DOES NOT exist", "TourInfo");
							}
						}
					}
					else
					{
						if (debugTours)
						{
							//Log("Mission" @ FString::FromInt(im) @ "not completed", "TourInfo");
						}
						if (TourInfo[it].IsSequential)
						{
							if (debugTours)
							{
								//Log("Tour is Sequential", "TourInfo");
							}
							if (TourInfo[it].Status != -1)
							{
								if (!bFoundLastSeqCompleted)
								{
									if (TourInfo[it].Mission[im].bFileExists)
									{
										if (debugTours)
										{
											//Log("Mission" @ FString::FromInt(im) @ "file exists - made available", "TourInfo");
										}
										TourInfo[it].Mission[im].Status = 0;
									}
									bFoundLastSeqCompleted = true;
								}
							}
						}
						else
						{
							if (debugTours)
							{
								//Log("Tour is NOT Sequential", "TourInfo");
							}
							if (TourInfo[it].Status != -1)
							{
								if (TourInfo[it].Mission[im].bFileExists)
								{
									if (debugTours)
									{
										//Log("Mission" @ FString::FromInt(im) @ "file exists - made available", "TourInfo");
									}
									TourInfo[it].Mission[im].Status = 0;
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
					for (im = 0; im < TourInfo[it].iNumMissions; im++)
					{
						if (TourInfo[it].Mission[im].bFileExists)
						{
							TourInfo[it].Mission[im].Status = 0;
						}
					}
				}
			}
		}
	}
	*/
	if (debugTours)
	{
		for (it = 0; it < iNumTours; it++)
		{
			//Log("******* TOUR" @ FString::FromInt(it) @ " is" @ FString::FromInt(TourInfo[it].Status), "TourInfo");
		}
	}
}

int32 ALevelInfo::GetTourStatus(int32 Tour)
{
	if ((Tour < 0) || (Tour > 31))
	{
		return -100;
	}
	if (Tour > iNumTours)
	{
		return -101;
	}
	return TourInfo[Tour].Status;
}

int32 ALevelInfo::GetMissionStatus(int32 Tour, int32 Mission)
{
	if ((Tour < 0) || (Tour > 31))
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

FString ALevelInfo::GetTimeString()
{
	//return FString::FromInt(Hour) @ ":" @ FString::FromInt(Minute) @ ":" @ FString::FromInt(Second) @ ":" @ FString::FromInt(Millisecond);
	return "FAKE";    //FAKE   /ELiZ
}

void ALevelInfo::PBKickPlayerByController(AController* C, FString Reason)
{
	//Game.KickByController(Cast<APlayerController>(C), Reason);
}

void ALevelInfo::PBKickPlayer(FString PlayerName, FString Reason)
{
	//Game.Kick(PlayerName, Reason);
}

//native simulated Function DetailChange(Object.EDetailMode NewDetailMode);
void ALevelInfo::DetailChange(EDetailMode NewDetailMode)
{

}

//native simulated Function bool IsEntry();
bool ALevelInfo::IsEntry()
{
	return false;    //FAKE   /ELiZ
}

//native simulated Function UpdateDistanceFogLOD(float LOD);
void ALevelInfo::UpdateDistanceFogLOD(float LOD)
{

}

//native simulated Function ForceLoadTexture(Texture Texture);
void ALevelInfo::ForceLoadTexture(UMaterialInstance* Texture)
{

}

//native simulated Function PhysicsVolume GetPhysicsVolume(Vector loc);
APhysicsVolume* ALevelInfo::GetPhysicsVolume(FVector loc)
{
	return nullptr;    //FAKE   /ELiZ
}

//native Function FString GetPBGUID(PlayerController PC);
FString ALevelInfo::GetPBGUID(APlayerController* PC)
{
	return "FAKE";    //FAKE   /ELiZ
}

//native Function FString GetPBGUIDFromIP(FString sIPAddress);
FString ALevelInfo::GetPBGUIDFromIP(FString sIPAddress)
{
	return "FAKE";    //FAKE   /ELiZ
}

void ALevelInfo::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	DecalStayScale = float(Max(int(DecalStayScale), 0));
	if (IsMILES())
	{
		SkinSetFriendly = GetMILESSkin(SkinSetFriendly);
		SkinSetEnemy = GetMILESSkin(SkinSetEnemy);
		MeshFriendly = GetMILESMesh(MeshFriendly);
		MeshEnemy = GetMILESMesh(MeshEnemy);
	}
	*/
}

AGameInfo* ALevelInfo::GetGameClass()
{
	AGameInfo* G = nullptr;
	/*
	if (Level.Game != nullptr)
	{
		return Level.Game.Class;
	}
	if ((GRI != nullptr) && (GRI.GameClass != ""))
	{
		G = class<GameInfo>(DynamicLoadObject(GRI.GameClass, Class'Class'));
	}
	if (G != nullptr)
	{
		return G;
	}
	if (DefaultGameType != "")
	{
		G = class<GameInfo>(DynamicLoadObject(DefaultGameType, Class'Class'));
	}
	*/
	return G;
}

void ALevelInfo::FillPrecacheMaterialsArray(bool FullPrecache)
{
	AActor* A = nullptr;
	AGameInfo* G = nullptr;
	bool bRealDesire = false;
	/*
	if (NetMode == 1)
	{
		return;
	}
	if ((!bSkinsPreloaded) || FullPrecache)
	{
		if (Game != nullptr)
		{
			G = Game.Class;
		}
		else
		{
			if ((GRI != nullptr) && (GRI.GameClass != ""))
			{
				G = class<GameInfo>(DynamicLoadObject(GRI.GameClass, Class'Class'));
			}
		}
		if (G != nullptr)
		{
			G.PrecacheGameTextures(this);
			bSkinsPreloaded = true;
		}
		if ((G == nullptr) && (DefaultGameType != ""))
		{
			G = class<GameInfo>(DynamicLoadObject(DefaultGameType, Class'Class'));
		}
		if (G == nullptr)
		{
			G = class<GameInfo>(DynamicLoadObject(PreCacheGame, Class'Class'));
		}
		if (G != nullptr)
		{
			bRealDesire = bDesireSkinPreload;
			bDesireSkinPreload = false;
			G.PrecacheGameTextures(this);
			bDesireSkinPreload = bRealDesire;
		}
	}
	ForEach AllActors(Class'Actor', A)
	{
		if ((!A.bAlreadyPrecachedMaterials) || FullPrecache)
		{
			A.UpdatePrecacheMaterials();
			A.bAlreadyPrecachedMaterials = true;
		}
	}
	*/
}

void ALevelInfo::PrecacheAnnouncements()
{
}

void ALevelInfo::FillPrecacheStaticMeshesArray(bool FullPrecache)
{
	AActor* A = nullptr;
	AGameInfo* G = nullptr;
	/*
	if (NetMode == 1)
	{
		return;
	}
	if (Game == nullptr)
	{
		if ((GRI != nullptr) && (GRI.GameClass != ""))
		{
			G = class<GameInfo>(DynamicLoadObject(GRI.GameClass, Class'Class'));
		}
		if ((G == nullptr) && (DefaultGameType != ""))
		{
			G = class<GameInfo>(DynamicLoadObject(DefaultGameType, Class'Class'));
		}
		if (G == nullptr)
		{
			G = class<GameInfo>(DynamicLoadObject(PreCacheGame, Class'Class'));
		}
		if (G != nullptr)
		{
			G.PrecacheGameStaticMeshes(this);
		}
	}
	ForEach AllActors(Class'Actor', A)
	{
		if ((!A.bAlreadyPrecachedMeshes) || FullPrecache)
		{
			A.UpdatePrecacheStaticMeshes();
			A.bAlreadyPrecachedMeshes = true;
		}
	}
	*/
}

void ALevelInfo::AddPrecacheMaterial(UMaterialInstance* mat)
{
	int32 Index = 0;
	/*
	if (NetMode == 1)
	{
		return;
	}
	if (mat == nullptr)
	{
		return;
	}
	Index = Level.PrecacheMaterials.Num();
	PrecacheMaterials.insert(Index, 1);
	PrecacheMaterials[Index] = mat;
	*/
}

void ALevelInfo::AddPrecacheStaticMesh(UStaticMesh* stat)
{
	int32 Index = 0;
	/*
	if (NetMode == 1)
	{
		return;
	}
	if (stat == nullptr)
	{
		return;
	}
	Index = Level.PrecacheStaticMeshes.Num();
	PrecacheStaticMeshes.insert(Index, 1);
	PrecacheStaticMeshes[Index] = stat;
	*/
}

//native simulated Function FString GetLocalURL();
FString ALevelInfo::GetLocalURL()
{
	return "FAKE";    //FAKE   /ELiZ
}

//native static simulated final Function bool IsDemoBuild();
bool ALevelInfo::IsDemoBuild()
{
	return false;    //FAKE   /ELiZ
}

//native static simulated final Function bool IsSoftwareRendering();
bool ALevelInfo::IsSoftwareRendering()
{
	return false;    //FAKE   /ELiZ
}

//native simulated Function FString GetAddressURL();
FString ALevelInfo::GetAddressURL()
{
	return "FAKE";    //FAKE   /ELiZ
}

//native simulated Function bool IsPendingConnection();
bool ALevelInfo::IsPendingConnection()
{
	return false;    //FAKE   /ELiZ
}

void ALevelInfo::ServerTravel(FString URL, bool bItems)
{
	/*
	if (InStr(URL, "%") >= 0)
	{
		Log("URL Contains illegal character '%'.");
		return;
	}
	if (((InStr(URL, ":") >= 0) || (InStr(URL, "/") >= 0)) || (InStr(URL, "\\") >= 0))
	{
		Log("URL blocked");
		return;
	}
	if (NextURL == "")
	{
		bLevelChange = true;
		bNextItems = bItems;
		NextURL = URL;
		if (Game != nullptr)
		{
			Game.ProcessServerTravel(URL, bItems);
		}
		else
		{
			NextSwitchCountdown = 0;
		}
	}
	*/
}

void ALevelInfo::ThisIsNeverExecuted()
{
	ADefaultPhysicsVolume* p = nullptr;
	p = nullptr;
}

void ALevelInfo::Reset()
{
	/*
	DefaultGravity = Default.DefaultGravity;
	ConsoleCommand("OBJ GARBAGE");
	Super::Reset();
	*/
}

void ALevelInfo::PreBeginPlay()
{
	/*
	Super::PreBeginPlay();
	ObjectPool = new (nullptr) UObjectPool::StaticClass();
	*/
}

APlayerController* ALevelInfo::GetLocalPlayerController()
{
	APlayerController* PC = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		return nullptr;
	}
	if (LocalPlayerController != nullptr)
	{
		return LocalPlayerController;
	}
	ForEach DynamicActors(Class'PlayerController', PC)
	{
		if (Viewport(PC.Player) != nullptr)
		{
			LocalPlayerController = PC;
		}
		else
		{
		}
	}
	*/
	return LocalPlayerController;
}
