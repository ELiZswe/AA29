// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "AA29/MyEnums.h"
#include "NPCVehicleStart.generated.h"

class ANPCBasePreCrewedVehicleControlle;
class AVehicle;
class AAGP_Pawn;
class AAGP_Weapon;
class ANPCAICombatController;
class ANPCPlayerStart;

class ANPCBaseController;
UCLASS()
class ANPCVehicleStart : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	ANPCVehicleStart();

	UPROPERTY(EditAnywhere)										ENPCOrders2							enpcoPrimaryOrders;						//var ENPCOrders2 enpcoPrimaryOrders
	UPROPERTY(EditAnywhere)										bool								bDebugInit;								//var() bool bDebugInit;
	UPROPERTY()													bool								bEnabled;								//var bool bEnabled;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		ANPCBasePreCrewedVehicleControlle*	ControllerClass;						//var(NPCController) class<NPCBasePreCrewedVehicleController> ControllerClass;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		AVehicle*							VehicleClass;							//var(NPCController) class<Vehicle> VehicleClass;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								DrawDriverInTP;							//var(NPCController) bool DrawDriverInTP;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iNPCInitialMentalState;					//var(NPCController) int32 iNPCInitialMentalState;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iNPCLeadershipMentalStateBonus;			//var(NPCController) int32 iNPCLeadershipMentalStateBonus;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iNPCLeadershipMentalStateRange;			//var(NPCController) int32 iNPCLeadershipMentalStateRange;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iNPCTeamID;								//var(NPCController) int32 iNPCTeamID;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpNPCHearingRadius;						//var(NPCController) float fpNPCHearingRadius;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpNPCVisionConeAngle;					//var(NPCController) float fpNPCVisionConeAngle;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpNPCMaxVisualRange;					//var(NPCController) float fpNPCMaxVisualRange;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bIgnoreFogDistance;						//var(NPCController) bool bIgnoreFogDistance;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bNPCSpeaksEnglish;						//var(NPCController) bool bNPCSpeaksEnglish;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bNPCCanBeHealed;						//var(NPCController) bool bNPCCanBeHealed;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpNPCWeaponAccuracy;					//var(NPCController) float fpNPCWeaponAccuracy;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fNPCExperience;							//var(NPCController) float fNPCExperience;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fNPCLikesToCrouch;						//var(NPCController) float fNPCLikesToCrouch;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iMinThreatLevel;						//var(NPCController) int32 iMinThreatLevel;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bMaleVoice;								//var(NPCController) bool bMaleVoice;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bDebugMode;								//var(NPCController) bool bDebugMode;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bDebugSenses;							//var(NPCController) bool bDebugSenses;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FString								sMovieToPlayOnUse;						//var(NPCController) FString sMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		USoundBase*							sndAudioToPlayOnUse;					//var(NPCController) Sound sndAudioToPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iMovieToPlayOnUseFramerate;				//var(NPCController) int32 iMovieToPlayOnUseFramerate;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								ControllerTag;							//var(NPCController) FName ControllerTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bSpawnAsReserve;						//var(NPCNavigation) bool bSpawnAsReserve;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iReinforcementWave;						//var(NPCNavigation) int32 iReinforcementWave;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iRespawnsAllowed;						//var(NPCNavigation) int32 iRespawnsAllowed;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								ConvoyTag;								//var(NPCNavigation) FName ConvoyTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								ConvoyLeader;							//var(NPCNavigation) bool ConvoyLeader;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								Patrol_NoPathfinding;					//var(NPCNavigation) bool Patrol_NoPathfinding;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bStartAsDummyPawn;						//var(NPCDummyPawnController) bool bStartAsDummyPawn;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								AnimSequence;							//var(NPCDummyPawnController) FName AnimSequence;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								AnimRate;								//var(NPCDummyPawnController) float AnimRate;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								AnimTime;								//var(NPCDummyPawnController) float AnimTime;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								AnimChannel;							//var(NPCDummyPawnController) int32 AnimChannel;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		TArray<FName>						anameSquadPlayerStartsTag;				//var(NPCPassengerSquadMembers) TArray<FName> anameSquadPlayerStartsTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								namePostUnloadState;					//var(NPCPassengerSquadMembers) FName namePostUnloadState;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bFireWhileUnloading;					//var(NPCPassengerSquadMembers) bool bFireWhileUnloading;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpMinDelayBeforeMovingOut;				//var(NPCPassengerSquadMembers) float fpMinDelayBeforeMovingOut;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bUnloadIfDamaged;						//var(NPCPassengerSquadMembers) bool bUnloadIfDamaged;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpDelayedInitialOrderExecutionTime;		//var(NPCOrders) float fpDelayedInitialOrderExecutionTime;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								nameAssaultLocationTag;					//var(NPCOrders) FName nameAssaultLocationTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bSmokeOnAssault;						//var(NPCOrders) bool bSmokeOnAssault;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								nameUnloadLocation;						//var(NPCOrders) FName nameUnloadLocation;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								VehicleTag;								//var(NPCNavigation) FName VehicleTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bTriggerStartVehicle;					//var(NPCNavigation) bool bTriggerStartVehicle;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FString								sNPCWaypointTag;						//var(NPCNavigation) FString sNPCWaypointTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bMustSpawn;								//var(NPCNavigation) bool bMustSpawn;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iStartingPathNodeIndex;					//var(NPCNavigation) int32 iStartingPathNodeIndex;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bStartAndSpawnAtRandomNode;				//var(NPCNavigation) bool bStartAndSpawnAtRandomNode;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bUseRandomStartingNode;					//var(NPCNavigation) bool bUseRandomStartingNode;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bScanWhenStopped;						//var(NPCNavigation) bool bScanWhenStopped;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fChanceOfStoppingAtNode;				//var(NPCNavigation) float fChanceOfStoppingAtNode;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bAscendingNodeDirection;				//var(NPCNavigation) bool bAscendingNodeDirection;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bAutoReversePath;						//var(NPCNavigation) bool bAutoReversePath;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bLikesToCloseDoorBehindSelf;			//var(NPCNavigation) bool bLikesToCloseDoorBehindSelf;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpChanceOfSpawning;						//var(NPCNavigation) float fpChanceOfSpawning;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bDebugPath;								//var(NPCNavigation) bool bDebugPath;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iFragGrenadeCount;						//var(NPCWeaponry) int32 iFragGrenadeCount;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iSmokeGrenadeCount;						//var(NPCWeaponry) int32 iSmokeGrenadeCount;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iFlashGrenadeCount;						//var(NPCWeaponry) int32 iFlashGrenadeCount;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iRPGCount;								//var(NPCWeaponry) int32 iRPGCount;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								i203Rounds;								//var(NPCWeaponry) int32 i203Rounds;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bHasBinoculars;							//var(NPCWeaponry) bool bHasBinoculars;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iPrimaryWeaponReloads;					//var(NPCWeaponry) int32 iPrimaryWeaponReloads;
	UPROPERTY()													FString								sPrimaryWeaponDefaultClass;				//var FString sPrimaryWeaponDefaultClass;
	UPROPERTY()													FString								sSecondaryWeaponDefaultClass;			//var FString sSecondaryWeaponDefaultClass;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		AAGP_Weapon*						namePrimaryWeapon;						//var(NPCWeaponry) class<AGP_Weapon> namePrimaryWeapon;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		AAGP_Weapon*						nameSecondaryWeapon;					//var(NPCWeaponry) class<AGP_Weapon> nameSecondaryWeapon;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bNoDefaultWeapons;						//var(NPCWeaponry) bool bNoDefaultWeapons;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpMortarRequestSkill;					//var(NPCWeaponry) float fpMortarRequestSkill;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								fpNPCWeaponEffectiveRange;				//var(NPCWeaponry) float fpNPCWeaponEffectiveRange;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bHasCoAxMachineGun;						//var(VehicleWeaponry) bool bHasCoAxMachineGun;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iCoAxRounds;							//var(VehicleWeaponry) int32 iCoAxRounds;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		AAGP_Pawn*							PawnSpawnClass;							//var(NPCPawnOptions) class<AGP_Pawn> PawnSpawnClass;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		UMaterialInstance*					setPants;								//var(NPCPawnOptions) Material setPants;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		UMaterialInstance*					setShirt;								//var(NPCPawnOptions) Material setShirt;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		UMaterialInstance*					setHands;								//var(NPCPawnOptions) Material setHands;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		UMaterialInstance*					setFace;								//var(NPCPawnOptions) Material setFace;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		bool								bUserSetSkin;							//var(NPCPawnOptions) bool bUserSetSkin;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		USkeletalMesh*						meshPawn;								//var(NPCPawnOptions) Mesh meshPawn;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FString								RagdollOverride;						//var(NPCPawnOptions) FString RagdollOverride;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		FName								PawnTag;								//var(NPCPawnOptions) FName PawnTag;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		TArray<FNPCAttachObject>			aoAttachments;							//var(NPCPawnOptions) TArray<NPCAttachObject> aoAttachments;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagdollLifeSpan;						//var(NPCPawnKarma) float RagdollLifeSpan;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagInvInertia;							//var(NPCPawnKarma) float RagInvInertia;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagDeathVel;							//var(NPCPawnKarma) float RagDeathVel;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagShootStrength;						//var(NPCPawnKarma) float RagShootStrength;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagSpinScale;							//var(NPCPawnKarma) float RagSpinScale;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagDeathUpKick;							//var(NPCPawnKarma) float RagDeathUpKick;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		float								RagProneProjectileScale;				//var(NPCPawnKarma) float RagProneProjectileScale;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iPlatoonID;								//var(NPCController) int32 iPlatoonID;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iSquadID;								//var(NPCController) int32 iSquadID;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")		int32								iFireteamID;							//var(NPCController) int32 iFireteamID;
	UPROPERTY()													ANPCAICombatController*				npcaiccCombatController;				//var NPCAICombatController npcaiccCombatController;

	void Reset();
	void BeginPlay();
	bool ShouldUseStartSpot();
	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
	ANPCBaseController* CreateNPC();
	ANPCPlayerStart* FindNPCPlayerStartByTag(FString sTagToFind);
	void FindAICC();
};
