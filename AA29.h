// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "MyEnums.h"
#include "AA29.generated.h"

class AAGP_Objective;
class AAA2_Info;
class AAA2_PlayerState;
class AExamAnswer;
class ANPC_SpecialForces;
class ATriggerVolume;
class AAGP_UseTrigger;
class AMarksmanTarget;
class ADecoMesh;
class AFSTS_EventLab;
class ATextDisplay_Char;
class APathNode;
class AVehicleVisualEffect;
class UVehiclePhysicalEffect;
class AEmitter;
class UMaplistRecord;
class UaDamageType;
class AVehiclePosition;
class ABodyPanel;
class UGUIComponent;
class AMBSPingServerRequestAdapter;
class UGUIButton;
class AAmmunition;
class AProjectile;
class ASceneManager;
class ANPCNCOController;
class ANPCBaseSoldierController;
class ANPCSquadDetails;
class ANPCBaseController;
class ASmallNavigationPoint;
class AAGP_VehicleParticles;
class AVehicleWeapon;
class ARoadPathNode;
class ATargetMover;
class ADamageDetector;
class AAGP_Trigger;
class AThrowWeaponPickup;

USTRUCT(BlueprintType)
struct FCompressedPosition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CompressedPosition")				FVector Location = FVector(0,0,0);
	UPROPERTY(EditAnywhere, Category = "CompressedPosition")				FRotator Rotation = FRotator(0,0,0);
	UPROPERTY(EditAnywhere, Category = "CompressedPosition")				FVector Velocity = FVector(0, 0, 0);
};

USTRUCT(BlueprintType)
struct FHitFXData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HitFXData")				FName Bone = "";
	UPROPERTY(EditAnywhere, Category = "HitFXData")				UaDamageType* damtype = nullptr;
	UPROPERTY(EditAnywhere, Category = "HitFXData")				bool bSever = false;
	UPROPERTY(EditAnywhere, Category = "HitFXData")				FRotator rotDir = FRotator(0, 0, 0);
};

USTRUCT(BlueprintType)
struct FPrecisionVector
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PrecisionVector")				uint8 Dummy = 0;
	UPROPERTY(EditAnywhere, Category = "PrecisionVector")				float pX = 0;
	UPROPERTY(EditAnywhere, Category = "PrecisionVector")				float pY = 0;
	UPROPERTY(EditAnywhere, Category = "PrecisionVector")				float pZ = 0;
};


USTRUCT(BlueprintType)
struct Fpointer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "pointer")				int32 Dummy = 0;
};

USTRUCT(BlueprintType)
struct FProjectorRenderInfoPtr
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ProjectorRenderInfoPtr")	Fpointer Ptr = Fpointer({});
};

USTRUCT(BlueprintType)
struct FVAEPosterViewingInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VAEPosterViewingInfo")		FString sPosterMaterial = "";
	UPROPERTY(EditAnywhere, Category = "VAEPosterViewingInfo")		float fpViewingTime = 0;
};

USTRUCT(BlueprintType)
struct FStoredChatBan
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "StoredChatBan")		FString PlayerHash = "";
	UPROPERTY(EditAnywhere, Category = "StoredChatBan")		uint8 Restriction = 0;
};

USTRUCT(BlueprintType)
struct FChatBan
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ChatBan")			int32 PlayerID = 0;
	UPROPERTY(EditAnywhere, Category = "ChatBan")			FString PlayerHash = "";
	UPROPERTY(EditAnywhere, Category = "ChatBan")			FString PlayerAddress = "";
	UPROPERTY(EditAnywhere, Category = "ChatBan")			uint8 PlayerVoiceMask = 0;
	UPROPERTY(EditAnywhere, Category = "ChatBan")			uint8 Restriction = 0;
};

USTRUCT(BlueprintType)
struct FNPCObjectiveResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			int32 iReservePlatoonID = 0;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			int32 iReserveSquadID = 0;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			int32 iReserveFireteamID = 0;
	//UPROPERTY(EditAnywhere, Category = "NPCTracking")			ENPCReserveObjectiveCommand enpcrocNPCCommand;	//var NPCObjectiveResponse.ENPCReserveObjectiveCommand enpcrocNPCCommand;
};

USTRUCT(BlueprintType)
struct FVoiceChatCodec
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			FString Codec = "";
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			FString CodecName = "";
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			FString CodecDescription = "";
};

USTRUCT(BlueprintType)
struct FNPCTracking
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			APawn* pawnSeen = nullptr;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			float fpTimeSeen = 0;
};

USTRUCT(BlueprintType)
struct FFireMissionRequests
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			FVector		vLocation = FVector(0,0,0);
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			APawn*		pawnTarget = nullptr;
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			float		fpTime = 0;
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			bool		bMissionFiring = false;
};

USTRUCT(BlueprintType)
struct FIntBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			X1 = 0;
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			Y1 = 0;
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			X2 = 0;
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			Y2 = 0;
};

USTRUCT(BlueprintType)
struct FConsoleMessage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		FString				Text = "";
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		FColor				TextColor = FColor(0,0,0);
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		float				MessageLife = 0;
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		AAA2_PlayerState*	PRI = nullptr;
};

USTRUCT(BlueprintType)
struct FWeaponState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeaponState")		float		PickupTimer = 0;			//var float PickupTimer;
	UPROPERTY(EditAnywhere, Category = "WeaponState")		bool		HasWeapon = false;			//var bool HasWeapon;
};


USTRUCT(BlueprintType)
struct FDigitSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DigitSet")				UMaterialInstance*		DigitTexture = nullptr;						//var Material DigitTexture;
	UPROPERTY(EditAnywhere, Category = "DigitSet")				FIntBox					TextureCoords = FIntBox({ 0,0,0,0 });		//var IntBox TextureCoords[11];
};

USTRUCT(BlueprintType)
struct FSpriteWidget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		UMaterialInstance*		WidgetTexture = nullptr;					//var Material WidgetTexture;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		ERenderStyle			RenderStyle = ERenderStyle::STY_None;		//var Actor.ERenderStyle RenderStyle;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		FIntBox					TextureCoords = FIntBox({ 0,0,0,0 });		//var IntBox TextureCoords;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		float					TextureScale = 0;							//var float TextureScale;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		EDrawPivot				DrawPivot = EDrawPivot::DP_UpperLeft;		//var Object.EDrawPivot DrawPivot;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		float					PosX = 0;									//var float PosX;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		float					PosY = 0;									//var float PosY;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		int32					OffsetX = 0;								//var int32 OffsetX;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		int32					OffsetY = 0;								//var int32 OffsetY;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		EScaleMode				ScaleMode = EScaleMode::SM_None;			//var EScaleMode ScaleMode;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		float					Scale = 0;									//var float Scale;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")		TArray<FColor>			Tints = {};									//var Color Tints[2];
};

USTRUCT(BlueprintType)
struct FNumericWidget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			ERenderStyle			RenderStyle = ERenderStyle::STY_None;		//var Actor.ERenderStyle RenderStyle;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			int32					MinDigitCount = 0;							//var int32 MinDigitCount;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			float					TextureScale = 0;							//var float TextureScale;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			EDrawPivot				DrawPivot = EDrawPivot::DP_UpperLeft;		//var Object.EDrawPivot DrawPivot;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			float					PosX = 0;									//var float PosX;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			float					PosY = 0;									//var float PosY;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			int32					OffsetX = 0;								//var int32 OffsetX;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			int32					OffsetY = 0;								//var int32 OffsetY;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			TArray<FColor>			Tints = {};									//var Color Tints[2];
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			int32					bPadWithZeroes = 0;							//var int32 bPadWithZeroes;
	UPROPERTY(EditAnywhere, Category = "NumericWidget")			int32					Value = 0;									//var transient int32 Value;
};

USTRUCT(BlueprintType)
struct FHudLocalizedMessage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			ULocalMessage*		Message = nullptr;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			FString				StringMessage = "";
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			int32				Switch = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			AAA2_PlayerState*	RelatedPRI = nullptr;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			AAA2_PlayerState*	RelatedPRI2 = nullptr;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			UObject*			OptionalObject = nullptr;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				EndOfLife = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				Lifetime = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			UFont*				StringFont = nullptr;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			FColor				DrawColor = FColor(0,0,0);
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			EDrawPivot			DrawPivot = EDrawPivot::DP_UpperLeft;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			EStackMode			StackMode = EStackMode::SM_None;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				PosX = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				PosY = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				dx = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				dy = 0;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			bool				Drawn = false;
};

USTRUCT(BlueprintType)
struct FNPCSquadDetails
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")			ANPCNCOController*					npcncoLeader = nullptr;			//var NPCNCOController npcncoLeader;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")			TArray<ANPCBaseSoldierController*>	npcscMembers = {};				//var TArray<NPCBaseSoldierController> npcscMembers;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")			int32								iSquadOrders = 0;				//var int32 iSquadOrders;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")			float								fpTimeSinceLastOrders = 0;		//var float fpTimeSinceLastOrders;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")			bool								bSquadDead = false;				//var bool bSquadDead;
	UPROPERTY(EditAnywhere, Category = "NPCSquadDetails")			int32								iAmbushSet = 0;					//var int32 iAmbushSet;
};

USTRUCT(BlueprintType)
struct FNPCPlatoons
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCPlatoons")			FNPCSquadDetails		anpcsdSquads	= FNPCSquadDetails({});
	UPROPERTY(EditAnywhere, Category = "NPCPlatoons")			FString					sPlatoonName	= "";
};

USTRUCT(BlueprintType)
struct FEnemyContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			ANPCBaseController*		npcbcReporting		= nullptr;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			APawn*					pawnEnemyContact	= nullptr;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			int32					iContactType		= 0;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			FVector					vLocation			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			FRotator				rotRotation			= FRotator(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			float					fpEstimatedRange	= 0;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			int32					iThreatLevel		= 0;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			float					fpTimeOfReport		= 0;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			bool					bContactLost		= false;
};

USTRUCT(BlueprintType)
struct FOrderQueue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			ANPCBaseController*		npcbc				= nullptr;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			int32					iSupportRequest		= 0;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			bool					bOrderForAll		= false;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			FString					sAICCCombatAction	= "";
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			int32					iOrder				= 0;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			int32					iTacticalOrder		= 0;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			float					fpTimeToDeliver		= 0;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			FVector					vSupportArea		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			APawn*					pawnTarget			= nullptr;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			bool					bSmokeMission		= false;
};

USTRUCT(BlueprintType)
struct FFireMissionInFlight
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			FVector				vTargetArea		= FVector(0, 0, 0);		//var FVector vTargetArea;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			float				fpSpawnTime		= 0;					//var float fpSpawnTime;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			float				fpSkill			= 0;					//var float fpSkill;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			APawn*				pawnSpotter		= nullptr;				//var APawn* pawnSpotter;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			bool				bSmokeMission	= false;				//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FSupportFireRequestQueue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			ANPCBaseSoldierController*	npcbscSpotter	= nullptr;				//var NPCBaseSoldierController npcbscSpotter;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			float						fpSkillLevel	= 0;					//var float fpSkillLevel;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			int32						iSupportType	= 0;					//var int32 iSupportType;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			int32						iRoundsToFire	= 0;					//var int32 iRoundsToFire;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			float						fpTimeToFire	= 0;					//var float fpTimeToFire;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			float						fpTimeToSpawn	= 0;					//var float fpTimeToSpawn;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			FVector						vTargetArea		= FVector(0, 0, 0);		//var FVector vTargetArea;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			bool						bSmokeMission	= false;				//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FMortarRangeTable
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpMin			= 0;
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpMax			= 0;
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpFlightTime	= 0;
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpAngle			= 0;
};

USTRUCT(BlueprintType)
struct FReinforcementRespawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ReinforcementRespawn")			ASmallNavigationPoint*		snpStart		= nullptr;
	UPROPERTY(EditAnywhere, Category = "ReinforcementRespawn")			int32						iRespawnsLeft	= 0;
};

USTRUCT(BlueprintType)
struct FLensFlareDescriptor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			UMaterialInstance*	LensFlareMaterial	= nullptr;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			FColor				LensFlareColor		= FColor(0,0,0);
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			float				LensFlareOffset		= 0;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			float				LensFlareRadius_Min	= 0;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			float				LensFlareRadius_Max	= 0;
};

USTRUCT(BlueprintType)
struct FAA2_ProcMeshVertex
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				FVector				Position	= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				FVector				Normal		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				FColor				Color		= FColor(0,0,0);
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				float				U			= 0;
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				float				V			= 0;
};

USTRUCT(BlueprintType)
struct FConvSpeech
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					FString				sMemberName			= "";
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					FName				nameLipSynchAudio	= "";
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					FName				nameAnimation		= "";
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					USoundBase*			sndNonLSAudio		= nullptr;
};

USTRUCT(BlueprintType)
struct FFireProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireProperties")				AAmmunition*		AmmoClass		= nullptr;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				AProjectile*		ProjectileClass	= nullptr;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				float				WarnTargetPct	= 0;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				float				MaxRange		= 0;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				bool				bTossed			= false;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				bool				bTrySplash		= false;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				bool				bLeadTarget		= false;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				bool				bInstantHit		= false;
	UPROPERTY(EditAnywhere, Category = "FireProperties")				bool				bInitialized	= false;
};

USTRUCT(BlueprintType)
struct FAnimInfo2
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AnimInfo2")					FName				SeqName = "";
	UPROPERTY(EditAnywhere, Category = "AnimInfo2")					float				AnimFrame = 0;
	UPROPERTY(EditAnywhere, Category = "AnimInfo2")					float				AnimRate = 0;
};

USTRUCT(BlueprintType)
struct FAnimInstruction
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")		EeAnimationCommand	Command;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")		FName				Sequence;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")		float				Rate;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")		float				Time;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")		int32				Channel;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")		int32				LoopNum;
};

USTRUCT(BlueprintType)
struct FArrayControl
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ArrayControl")		UGUIButton* b_New		= nullptr;
	UPROPERTY(EditAnywhere, Category = "ArrayControl")		UGUIButton* b_Remove	= nullptr;
};

USTRUCT(BlueprintType)
struct FKRBVec
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KRBVec")					float X = 0;
	UPROPERTY(EditAnywhere, Category = "KRBVec")					float Y = 0;
	UPROPERTY(EditAnywhere, Category = "KRBVec")					float Z = 0;
};

USTRUCT(BlueprintType)
struct FUAVState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "UAVState")		FKRBVec ChassisPosition = FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "UAVState")		FQuat ChassisQuaternion = FQuat(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "UAVState")		FKRBVec ChassisLinVel = FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "UAVState")		FKRBVec ChassisAngVel = FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "UAVState")		float ServerThrust = 0;
	UPROPERTY(EditAnywhere, Category = "UAVState")		float ServerStrafe = 0;
	UPROPERTY(EditAnywhere, Category = "UAVState")		float ServerRise = 0;
	UPROPERTY(EditAnywhere, Category = "UAVState")		int32 bNewState = 0;
};

USTRUCT(BlueprintType)
struct FHelicopterState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FKRBVec ChassisPosition			= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FQuat	ChassisQuaternion		= FQuat(0, 0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FKRBVec ChassisLinVel			= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FKRBVec ChassisAngVel			= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			float	ServerThrust			= 0;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			float	ServerStrafe			= 0;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			float	ServerRise				= 0;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			int32	bNewState				= 0;
};

USTRUCT(BlueprintType)
struct FCoords
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector Origin = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector XAxis = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector YAxis = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector ZAxis = FVector(0, 0, 0);
};

USTRUCT(BlueprintType)
struct FEffectMatProps
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EffectMatProps")		bool	bNoEffect	= false;
	UPROPERTY(EditAnywhere, Category = "EffectMatProps")		FColor	DirtColor	= FColor(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "EffectMatProps")		float	DirtAmount	= 0;
};

USTRUCT(BlueprintType)
struct FRange
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Range")					float Min = 0;
	UPROPERTY(EditAnywhere, Category = "Range")					float Max = 0;
};

USTRUCT(BlueprintType)
struct FParticleAnchor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")		FName Tag = "";
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")		float Position = 0;
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")		AActor* Actor = nullptr;
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")		int32 Index = 0;
};

USTRUCT(BlueprintType)
struct FAttachedPawnInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")		float Index = 0;
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")		float nextUpateTime = 0;
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")		float updateTime = 0;
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")		float percent = 0;
};

USTRUCT(BlueprintType)
struct FRangeVector
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RangeVector")			FRange X = FRange({ 0,0 });
	UPROPERTY(EditAnywhere, Category = "RangeVector")			FRange Y = FRange({ 0,0 });
	UPROPERTY(EditAnywhere, Category = "RangeVector")			FRange Z = FRange({ 0,0 });
};

USTRUCT(BlueprintType)
struct FParticleBeamData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleBeamData")					FVector Location = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "ParticleBeamData")					float t = 0;
};

USTRUCT(BlueprintType)
struct FParticleBeamEndPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleBeamEndPoint")				FName ActorTag = "";
	UPROPERTY(EditAnywhere, Category = "ParticleBeamEndPoint")				FRangeVector offset = FRangeVector({});
	UPROPERTY(EditAnywhere, Category = "ParticleBeamEndPoint")				float Weight = 0;
};

USTRUCT(BlueprintType)
struct FParticleBeamScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleBeamScale")					FVector FrequencyScale = FVector(0, 0, 0);				//var FVector FrequencyScale;
	UPROPERTY(EditAnywhere, Category = "ParticleBeamScale")					FVector RelativeLength = FVector(0, 0, 0);				//var float RelativeLength;
};

USTRUCT(BlueprintType)
struct FParticleSparkData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleSparkData")					FVector TimeBeforeVisible = FVector(0, 0, 0);					//var float TimeBeforeVisible;
	UPROPERTY(EditAnywhere, Category = "ParticleSparkData")					FVector TimeBetweenSegments = FVector(0, 0, 0);				//var float TimeBetweenSegments;
	UPROPERTY(EditAnywhere, Category = "ParticleSparkData")					FVector StartLocation = FVector(0, 0, 0);						//var FVector StartLocation;
	UPROPERTY(EditAnywhere, Category = "ParticleSparkData")					FVector StartVelocity = FVector(0, 0, 0);						//var FVector StartVelocity;
};

USTRUCT(BlueprintType)
struct FParticleTrailData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Range")								FVector Location = FVector(0, 0, 0);							//var FVector Location;
	UPROPERTY(EditAnywhere, Category = "Range")								FColor Color = FColor(0,0,0,0);								//var Color Color;
	UPROPERTY(EditAnywhere, Category = "Range")								float Size = 0;									//var float Size;
	UPROPERTY(EditAnywhere, Category = "Range")								int32 DoubleDummy1 = 0;							//var int32 DoubleDummy1;
	UPROPERTY(EditAnywhere, Category = "Range")								int32 DoubleDummy2 = 0;							//var int32 DoubleDummy2;
};

USTRUCT(BlueprintType)
struct FParticleTrailInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Range")								int32 TrailIndex = 0;							//var int32 TrailIndex;
	UPROPERTY(EditAnywhere, Category = "Range")								int32 NumPoints = 0;							//var int32 NumPoints;
	UPROPERTY(EditAnywhere, Category = "Range")								FVector LastLocation = FVector(0, 0, 0);						//var FVector LastLocation;
	UPROPERTY(EditAnywhere, Category = "Range")								FVector LastEmitterLocation = FVector(0, 0, 0);				//var FVector LastEmitterLocation;
};

USTRUCT(BlueprintType)
struct FParticleTimeScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleTimeScale")					float RelativeTime = 0;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleTimeScale")					float RelativeSize = 0;							//var float RelativeSize;
};

USTRUCT(BlueprintType)
struct FParticleRevolutionScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleRevolutionScale")			float RelativeTime = 0;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleRevolutionScale")			FVector RelativeRevolution = FVector(0, 0, 0);					//var FVector RelativeRevolution;
};

USTRUCT(BlueprintType)
struct FParticleColorScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleColorScale")					float RelativeTime = 0;						//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleColorScale")					FColor Color = FColor(0,0,0,0);							//var Color Color;
};

USTRUCT(BlueprintType)
struct FParticleVelocityScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleVelocityScale")					float RelativeTime = 0;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleVelocityScale")					FVector RelativeVelocity = FVector(0, 0, 0);						//var FVector RelativeVelocity;
};

USTRUCT(BlueprintType)
struct FParticle
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		Location				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		OldLocation				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		Velocity				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		StartSize				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		SpinsPerSecond			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		StartSpin				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		RevolutionCenter		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		RevolutionsPerSecond	= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		RevolutionsMultiplier	= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		Size					= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		StartLocation			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		ColorMultiplier			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		VelocityMultiplier		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector		OldMeshLocation			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Particle")					FColor		Color					= FColor(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "Particle")					float		Time					= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					float		MaxLifetime				= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					float		Mass					= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32		HitCount				= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32		Flags					= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32		Subdivision				= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32		BoneIndex				= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					uint8		NumFramesRendered		= 0;
	UPROPERTY(EditAnywhere, Category = "Particle")					float		FadeTime				= 0;
};

USTRUCT(BlueprintType)
struct FParticleSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					USoundBase* Sound = nullptr;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Radius = FRange({});
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Pitch = FRange({});
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					int32 Weight = 0;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Volume = FRange({});
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Probability = FRange({});
};

USTRUCT(BlueprintType)
struct FGameSpyPlayerInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Honor = 0;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					FString Name = "";
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Score_Total = 0;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Enemy = 0;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 KIA = 0;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 ROE = 0;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Ping = 0;
};

USTRUCT(BlueprintType)
struct FOutstandingPing
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				int32							IP = 0;
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				int32							Port = 0;
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				float							TimeOfLastPing = 0;
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				AMBSPingServerRequestAdapter*	Request = nullptr;
};

USTRUCT(BlueprintType)
struct FPlayerList
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayerList")					TArray<FGameSpyPlayerInfo>		players = {};			//var TArray<ServerBrowserBase.GameSpyPlayerInfo> players;
};


USTRUCT(BlueprintType)
struct FPlayListStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				bool				bRepeat = false;			//var config bool bRepeat;
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				bool				bShuffle = false;			//var config bool bShuffle;
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				FString				Current = "";			//var config FString Current;
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				TArray<FString>		Songs = {};				//var config TArray<FString> Songs;
};

USTRUCT(BlueprintType)
struct FStoredPassword
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "StoredPassword")				FString				Server = "";
	UPROPERTY(BlueprintReadWrite, Category = "StoredPassword")				FString				Password = "";
};

USTRUCT(BlueprintType)
struct FServerFavorite
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				int32				ServerID	= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				FString				IP			= "";
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				int32				Port		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				int32				QueryPort	= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				FString				ServerName	= "";
};


USTRUCT(BlueprintType)
struct FChatStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ChatStruct")				FString				Message = "";
	UPROPERTY(BlueprintReadWrite, Category = "ChatStruct")				int32				Team = 0;
};


USTRUCT(BlueprintType)
struct FInputKeyInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "InputKeyInfo")				int32				KeyNumber = 0;
	UPROPERTY(BlueprintReadWrite, Category = "InputKeyInfo")				FString				KeyName = "";
	UPROPERTY(BlueprintReadWrite, Category = "InputKeyInfo")				FString				LocalizedKeyName = "";
};

USTRUCT(BlueprintType)
struct FKeyBindMenyKeyBinding
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				bool				bIsSectionLabel = false;		//var bool bIsSectionLabel;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString				KeyLabel = "";				//var FString KeyLabel;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString				Alias = "";					//var FString Alias;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<int32>		BoundKeys={};				//var TArray<int32> BoundKeys;
};

USTRUCT(BlueprintType)
struct FRibbon
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "Ribbon")				FString				RibbonName = "";			//var FString RibbonName;
	UPROPERTY(BlueprintReadWrite, Category = "Ribbon")				FString				RibbonDescription = "";	//var FString RibbonDescription;
	UPROPERTY(BlueprintReadWrite, Category = "Ribbon")				UMaterialInstance*	RibbonImage = nullptr;		//var Material RibbonImage;
};

USTRUCT(BlueprintType)
struct FDisplayMode
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "DisplayMode")				int32			Width = 0;		//var int32 Width;
	UPROPERTY(BlueprintReadWrite, Category = "DisplayMode")				int32			Height = 0;		//var int32 Height;
};


USTRUCT(BlueprintType)
struct FKeyBinding
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				bool			bIsSectionLabel = false;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString			KeyLabel = "";
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString			Alias = "";
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<int32>	Binds = {};
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<FString>	BindKeyNames = {};
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<FString>	BindLocalizedKeyNames ={};
};

USTRUCT(BlueprintType)
struct FFavoritesServerInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")		int32	ServerID	= 0;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")		int32	IP			= 0;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")		int32	Port		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")		int32	QueryPort	= 0;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")		int32	ServerName	= 0;
};

USTRUCT(BlueprintType)
struct FDCDSImageInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		UMaterialInstance*	Image		= nullptr;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString				HttpLink	= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString				Caption		= "";
};

USTRUCT(BlueprintType)
struct FHaltedDownloadInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		AssetName		= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		int32		Length			= 0;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		int32		RemainingLength	= 0;
};

USTRUCT(BlueprintType)
struct FAssetFileInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		FullName		= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		Name			= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		Path			= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		int32		FileLength		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		SHA				= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		Date			= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		int32		bShouldRemove	= 0;
};

USTRUCT(BlueprintType)
struct FAA2_AssetMapping
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		AssetName		= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		AssetFileName	= "";
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")		FString		AssetTitle		= "";
};

USTRUCT(BlueprintType)
struct FKeyValuePair
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyValuePair")			FString		Key		= "";
	UPROPERTY(BlueprintReadWrite, Category = "KeyValuePair")			FString		Value	= "";
};

USTRUCT(BlueprintType)
struct FPlayerResponseLine
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32		PlayerNum	= 0;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		FString		PlayerName	= "";
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32		Ping		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32		Score		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32		StatsID		= 0;
};

USTRUCT(BlueprintType)
struct FServerResponseLine
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							ServerID		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString							IP				= "";
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							Port			= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							QueryPort		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString							ServerName		= "";
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString							MapName			= "";
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString							GameType		= "";
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							CurrentPlayers	= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							MaxPlayers		= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							Ping			= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32							Flags			= 0;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString							SkillLevel		= "";
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		TArray<FKeyValuePair>			ServerInfo		= {};
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		TArray<FPlayerResponseLine>		PlayerInfo		= {};
};

USTRUCT(BlueprintType)
struct FHeaderColumnPos
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HeaderColumnPos")		TArray<float> ColumnSizes ={};
};

USTRUCT(BlueprintType)
struct FeServerCacheInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FeServerCacheInfo")			FString					GameType	= "";
	UPROPERTY(EditAnywhere, Category = "FeServerCacheInfo")			int32					SubnetIndex = 0;
	UPROPERTY(EditAnywhere, Category = "FeServerCacheInfo")			FServerResponseLine		SRL			= FServerResponseLine({});
};


USTRUCT(BlueprintType)
struct FUAVFlightPlannerWaypoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlannerWaypoint")		FVector vLocation	= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlannerWaypoint")		float	fpHeight	= 0;
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlannerWaypoint")		float	fpSpeed		= 0;
};


USTRUCT(BlueprintType)
struct FLayoutItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LayoutItem")		UGUIComponent*	Component = nullptr;
	UPROPERTY(EditAnywhere, Category = "LayoutItem")		EeCellAlign		Alignment = EeCellAlign::CA_TopRight;
};

USTRUCT(BlueprintType)
struct FBadge
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Badge")		FString				BadgeName			= "";
	UPROPERTY(EditAnywhere, Category = "Badge")		FString				BadgeDescription	= "";
	UPROPERTY(EditAnywhere, Category = "Badge")		UMaterialInstance*	BadgeImage			= nullptr;
	UPROPERTY(EditAnywhere, Category = "Badge")		FString				MenuPath			= "";
	UPROPERTY(EditAnywhere, Category = "Badge")		FString				MenuParam1			= "";
	UPROPERTY(EditAnywhere, Category = "Badge")		FString				MenuParam2			= "";
};

USTRUCT(BlueprintType)
struct FActiveFilter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ActiveFilter")		FString		CategoryName		= "";
	UPROPERTY(EditAnywhere, Category = "ActiveFilter")		FString		FilterName			= "";
	UPROPERTY(EditAnywhere, Category = "ActiveFilter")		FString		FilterChoiceLabel	= "";
};


USTRUCT(BlueprintType)
struct FActiveFilterSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ActiveFilterSet")		TArray<FActiveFilter>	List = {};
};

USTRUCT(BlueprintType)
struct FReport
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FReport")			int32		ListID	= 0;
	UPROPERTY(EditAnywhere, Category = "FReport")			FString		Ping	= "";
	UPROPERTY(EditAnywhere, Category = "FReport")			FString		receive = "";
};

USTRUCT(BlueprintType)
struct FFilterItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilterItem")		FString		Key		= "";
	UPROPERTY(EditAnywhere, Category = "FilterItem")		FString		Value	= "";
};

USTRUCT(BlueprintType)
struct FFilterChoice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilterChoice")		FString				Label = "";
	UPROPERTY(EditAnywhere, Category = "FilterChoice")		TArray<FFilterItem> DBMBSFilters = {};
	UPROPERTY(EditAnywhere, Category = "FilterChoice")		FString				GameSpyFilter = "";
};

USTRUCT(BlueprintType)
struct FFilterDesc
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		FString					CategoryName = "";
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		FString					FilterName = "";
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		TArray<FFilterChoice>	Choices = {};
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		bool					RuntimeChoiceGeneration = false;
};

USTRUCT(BlueprintType)
struct FQueryData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QueryData")		FString		Key			= "";
	UPROPERTY(EditAnywhere, Category = "QueryData")		FString		Value		= "";
	UPROPERTY(EditAnywhere, Category = "QueryData")		EQueryType	QueryType	= EQueryType::QT_Equals;
};

USTRUCT(BlueprintType)
struct FAFilterRule
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AFilterRule")	FQueryData	FilterItem	= FQueryData({});
	UPROPERTY(EditAnywhere, Category = "AFilterRule")	EDataType	FilterType	= EDataType::DT_Unique;
	UPROPERTY(EditAnywhere, Category = "AFilterRule")	FString		ItemName	= "";
};
USTRUCT(BlueprintType)
struct FCurrentFilter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CurrentFilter")	FAFilterRule	Item		= FAFilterRule({});
	UPROPERTY(EditAnywhere, Category = "CurrentFilter")	int32			ItemIndex	= 0;
};

USTRUCT(BlueprintType)
struct FFavoriteServer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FavoriteServer")	FString IPAddress	= "";
	UPROPERTY(EditAnywhere, Category = "FavoriteServer")	int32	Port		= 0;
};

USTRUCT(BlueprintType)
struct FMultiColumnSortData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MultiColumnSortData")	FString		SortString	= "";
	UPROPERTY(EditAnywhere, Category = "MultiColumnSortData")	int32		SortItem	= 0;
};

USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")			FString		PlayerName = "";
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")			FString		PlayerID = "";
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")			FString		PlayerIP = "";
};

USTRUCT(BlueprintType)
struct FSprite
{
	GENERATED_BODY()
	// UPROPERTY(EditAnywhere, Category = "Sprite")				ASpriteSlave* Sprite;
	UPROPERTY(EditAnywhere, Category = "Sprite")				float MinFadeValue = 0;
	UPROPERTY(EditAnywhere, Category = "Sprite")				float MaxFadeValue = 0;
};

USTRUCT(BlueprintType)
struct FVehicleWeaponAIInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool	bTossed			= false;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool	bTrySplash		= false;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool	bLeadTarget		= false;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool	bInstantHit		= false;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool	bFireOnRelease	= false;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				float	aimerror		= 0;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				float	WarnTargetPct	= 0;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				float	RefireRate		= 0;
};

USTRUCT(BlueprintType)
struct FVehiclePositionStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			TSubclassOf <AVehiclePosition>	VehiclePositionClass	= nullptr;
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FName							WeaponBone				= "";
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FName							PositionBone			= "";
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FVector							FPCameraOffset			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FVector							PosOffset				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FRotator						RotOffset				= FRotator(0, 0, 0);
};

USTRUCT(BlueprintType)
struct FBodyPanelStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				TSubclassOf <ABodyPanel>	ClassType					= nullptr;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				UStaticMesh*				Mesh						= nullptr;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				FName						AttachBone					= "";
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				FName						EntryBone					= "";
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32						EntryRadius					= 0;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32						EntryPosIndex				= 0;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				FString						ExteriorHintText			= "";
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				UStaticMesh*				DamagedMesh					= nullptr;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32						bInvincible					= 0;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32						bAcceptsProjectileDamage	= 0;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32						bDisableCollision			= 0;
};

USTRUCT(BlueprintType)
struct FDriverWeaponStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DriverWeaponStruct")				AVehicleWeapon* WeaponClass = nullptr;
	UPROPERTY(EditAnywhere, Category = "DriverWeaponStruct")				FName			WeaponBone = "";
};


USTRUCT(BlueprintType)
struct FsDamageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				TSubclassOf < UaDamageType>				AcceptsDamage		= nullptr;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				TSubclassOf < AAGP_VehicleParticles>	DamageEffect		= nullptr;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Front_Left		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Front_Right		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Back_Left		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Back_Right		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Undercarriage	= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Turret			= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Roof				= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Tread_Left		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Tread_Right		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Wheels_Left		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									AM_Wheels_Right		= 0;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float									DamageEffectPct		= 0;
};	

USTRUCT(BlueprintType)
struct FTestDamageZoneInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				FName	ZoneName						= "";
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				uint8	ZoneNumber						= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				int32	ArmorThreshold					= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				int32	MaxHitPoints					= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				uint8	bInitialSyncToVehicleHealth		= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				uint8	bNoPassDamageToVehicle			= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				float	DamageModifier					= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				float	DS1HealthPct					= 0;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				float	DS2HealthPct					= 0;
};

USTRUCT(BlueprintType)
struct FIniParticleInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "IniParticleInfo")				FName	ZoneName			= "";
	UPROPERTY(EditAnywhere, Category = "IniParticleInfo")				FString DS1ParticleString	= "";
	UPROPERTY(EditAnywhere, Category = "IniParticleInfo")				FString DS2ParticleString	= "";
};

USTRUCT(BlueprintType)
struct FActorAttachment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ActorAttachment")				AActor* attachClass		= nullptr;
	UPROPERTY(EditAnywhere, Category = "ActorAttachment")				FName	AttachBone		= "";
};

USTRUCT(BlueprintType)
struct FImpactInfoStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				AActor* Other			= nullptr;
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector pos				= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector impactVel		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector impactNorm		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector ImpactAccel		= FVector(0, 0, 0);
};

USTRUCT(BlueprintType)
struct FTrackedCraftState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FVector ChassisPosition		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FQuat	ChassisQuaternion	= FQuat(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FVector ChassisLinVel		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FVector ChassisAngVel		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				uint8	ServerThrust		= 0;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				uint8	ServerTurn			= 0;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				int32	ServerViewPitch		= 0;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				int32	ServerViewYaw		= 0;
};

USTRUCT(BlueprintType)
struct FSCarState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SCarState")				FVector ChassisPosition			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "SCarState")				FQuat	ChassisQuaternion		= FQuat(0, 0, 0,0);
	UPROPERTY(EditAnywhere, Category = "SCarState")				FVector ChassisLinVel			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "SCarState")				FVector ChassisAngVel			= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerHandbrake			= 0;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerBrake				= 0;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerGas				= 0;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerGear				= 0;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerSteering			= 0;
	UPROPERTY(EditAnywhere, Category = "SCarState")				int32	ServerViewPitch			= 0;
	UPROPERTY(EditAnywhere, Category = "SCarState")				int32	ServerViewYaw			= 0;
};

USTRUCT(BlueprintType)
struct FAA2_InterpCurvePoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "InterpCurvePoint")				float	InVal	= 0;
	UPROPERTY(EditAnywhere, Category = "InterpCurvePoint")				float	OutVal	= 0;
};

USTRUCT(BlueprintType)
struct FAA2_InterpCurve
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CopterState")				TArray<FAA2_InterpCurvePoint> Points = {};
};

USTRUCT(BlueprintType)
struct FPlaneStateStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			FKRBVec		ChassisPosition		= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			FQuat		ChassisQuaternion	= FQuat(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			FKRBVec		ChassisLinVel		= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			FKRBVec		ChassisAngVel		= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			float		ServerThrust		= 0;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			float		ServerStrafe		= 0;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			float		ServerRise			= 0;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			int32		ServerViewPitch		= 0;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")			int32		ServerViewYaw		= 0;
};

USTRUCT(BlueprintType)
struct FKRigidBodyState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")			FKRBVec		Position	= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")			FQuat		Quaternion	= FQuat(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")			FKRBVec		LinVel		= FKRBVec({});
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")			FKRBVec		AngVel		= FKRBVec({});
};

USTRUCT(BlueprintType)
struct FCopterState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CopterState")			FVector		ChassisPosition		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "CopterState")			FQuat		ChassisQuaternion	= FQuat(0,0,0,0);
	UPROPERTY(EditAnywhere, Category = "CopterState")			FVector		ChassisLinVel		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "CopterState")			FVector		ChassisAngVel		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "CopterState")			uint8		ServerThrust		= 0;
	UPROPERTY(EditAnywhere, Category = "CopterState")			uint8		ServerStrafe		= 0;
	UPROPERTY(EditAnywhere, Category = "CopterState")			uint8		ServerRise			= 0;
	UPROPERTY(EditAnywhere, Category = "CopterState")			int32		ServerViewPitch		= 0;
	UPROPERTY(EditAnywhere, Category = "CopterState")			int32		ServerViewYaw		= 0;
};


USTRUCT(BlueprintType)
struct FSVehicleIcon
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					UMaterialInstance*	Material = nullptr;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float				X = 0;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float				Y = 0;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float				SizeX = 0;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float				SizeY = 0;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					bool				bIsGreyScale = false;
};

USTRUCT(BlueprintType)
struct FMapItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MapItem")					FString MapName			= "";
	UPROPERTY(EditAnywhere, Category = "MapItem")					FString OptionString	= "";
	UPROPERTY(EditAnywhere, Category = "MapItem")					FString FullURL			= "";

	bool operator==(const FMapItem& B)
	{
		if (MapName != B.MapName)
		{
			return false;
		}
		return true;
	}
};

USTRUCT(BlueprintType)
struct FGameRecordGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameRecordGroup")		FString		GameType		= "";
	UPROPERTY(EditAnywhere, Category = "GameRecordGroup")		FString		ActiveMaplist	= "";
};

USTRUCT(BlueprintType)
struct FMaplistRecordGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	FString					GameType	= "";
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	int32					Active		= 0;
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	int32					LastActive	= 0;
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	TArray<FMapItem>		AllMaps		= {};
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	TArray<UMaplistRecord*> Records		= {};
};

USTRUCT(BlueprintType)
struct FKeyInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KeyInfo")				FString		Alias		= "";
	UPROPERTY(EditAnywhere, Category = "KeyInfo")				FString		KeyLabel	= "";
	UPROPERTY(EditAnywhere, Category = "KeyInfo")				bool		bIsSection	= false;
};

USTRUCT(BlueprintType)
struct FBoneEditVars
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			FName		Name			= "";
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			float		Radius			= 0;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			bool		bCheckCaps		= false;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			float		DamageModifier	= 0;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			EBoneRegion BoneRegion		= EBoneRegion::BR_NONE;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			int32		BoneIdx			= 0;
};

USTRUCT(BlueprintType)
struct FPlaylistParser
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlaylistParser")			EStreamPlaylistType Type		= EStreamPlaylistType::SPT_None;
	UPROPERTY(EditAnywhere, Category = "PlaylistParser")			FString				ParserClass	= "";
};

USTRUCT(BlueprintType)
struct FHtmlChar
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HtmlChar")					FString Plain="";
	UPROPERTY(EditAnywhere, Category = "HtmlChar")					FString Coded="";
};

USTRUCT(BlueprintType)
struct FaFilePath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString			FullPath = "";
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString			Directory = "";
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString			Filename = "";
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString			Extension = "";
	UPROPERTY(EditAnywhere, Category = "FilePath")					TArray<FString>	DirectoryParts={};
};

USTRUCT(BlueprintType)
struct FID3Field
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FID3Field")					Fpointer ID3Field = Fpointer({});
	UPROPERTY(EditAnywhere, Category = "FID3Field")					FString FieldName = "";
	UPROPERTY(EditAnywhere, Category = "FID3Field")					FString FieldValue = "";
	UPROPERTY(EditAnywhere, Category = "FID3Field")					uint8 FieldID = 0;
	UPROPERTY(EditAnywhere, Category = "FID3Field")					uint8 Code = 0;
};

USTRUCT(BlueprintType)
struct FSpeechReplacement
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SpeechReplacement")		TArray<FString>		MatchWords = {};
	UPROPERTY(EditAnywhere, Category = "SpeechReplacement")		FString				ReplaceWord = "";
};

USTRUCT(BlueprintType)
struct Ft_VideoMode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "t_VideoMode")						int32 X = 0;
	UPROPERTY(EditAnywhere, Category = "t_VideoMode")						int32 Y = 0;
};

USTRUCT(BlueprintType)
struct FLine
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Line")			FString Text	= "";
	UPROPERTY(EditAnywhere, Category = "Line")			int32 ix		= 0;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 iY		= 0;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 iScaledX	= 0;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 iScaledY	= 0;
};

USTRUCT(BlueprintType)
struct FScoring
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Scoring")								int32 LoRange = 0;
	UPROPERTY(EditAnywhere, Category = "Scoring")								int32 HiRange = 0;
	UPROPERTY(EditAnywhere, Category = "Scoring")								FString Award = "";
	UPROPERTY(EditAnywhere, Category = "Scoring")								UMaterialInstance* AwardTexture = nullptr;
	UPROPERTY(EditAnywhere, Category = "Scoring")								USoundBase* AwardSound = nullptr;
	UPROPERTY(EditAnywhere, Category = "Scoring")								bool bPass = false;
};

USTRUCT(BlueprintType)
struct FImageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehicleData")			FString				Info	= "";
	UPROPERTY(EditAnywhere, Category = "VehicleData")			UMaterialInstance*	Tex		= nullptr;
	UPROPERTY(EditAnywhere, Category = "VehicleData")			TArray<FString>		sData	= {};
	UPROPERTY(EditAnywhere, Category = "VehicleData")			int32				Status	= 0;
};

USTRUCT(BlueprintType)
struct FVehicleData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehicleData")			AAA2_PlayerState*	Passengers		= nullptr;
	UPROPERTY(EditAnywhere, Category = "VehicleData")			bool				bDrewVehicle	= false;
};

USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Point")			int32 X=0;
	UPROPERTY(EditAnywhere, Category = "Point")			int32 Y=0;
};

USTRUCT(BlueprintType)
struct FPosition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Position")		int32 X=0;
	UPROPERTY(EditAnywhere, Category = "Position")		int32 Y=0;
	UPROPERTY(EditAnywhere, Category = "Position")		int32 W=0;
	UPROPERTY(EditAnywhere, Category = "Position")		int32 H=0;
};

USTRUCT(BlueprintType)
struct FInvProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "InvProperties")		int32	iItemID	= 0;
	UPROPERTY(EditAnywhere, Category = "InvProperties")		int32	iParam	= 0;
	UPROPERTY(EditAnywhere, Category = "InvProperties")		int32	iSize	= 0;
	UPROPERTY(EditAnywhere, Category = "InvProperties")		float	fWeight	= 0;
};


USTRUCT(BlueprintType)
struct FInvDefStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")			FString				sItemName		= "";
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")			int32				iParam			= 0;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")			float				fWeight			= 0;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")			int32				iSize			= 0;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")			UMaterialInstance*	cTexture		= nullptr;
};

USTRUCT(BlueprintType)
struct FDamageStateStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			TArray<FName>			DamageBones = { "" ,"" ,"" ,"" ,"" ,"" ,"" ,"" };
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			TArray<uint8>			BoneSlot = {0,0,0,0,0,0,0,0};
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			float					DamagePct = 0;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			float					ChildDamagePct = 0;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			AEmitter*				VisualEffectClass = nullptr;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			AVehicleVisualEffect*	VisualEffect = nullptr;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			UVehiclePhysicalEffect* PhysicalEffect = nullptr;
};

USTRUCT(BlueprintType)
struct FDecorationType
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DecorationType")			UStaticMesh*	StaticMesh		= nullptr;
	UPROPERTY(EditAnywhere, Category = "DecorationType")			FRange			Count			= FRange({});
	UPROPERTY(EditAnywhere, Category = "DecorationType")			FRange			DrawScale		= FRange({});
	UPROPERTY(EditAnywhere, Category = "DecorationType")			uint8			bAlign			= 0;
	UPROPERTY(EditAnywhere, Category = "DecorationType")			uint8			bRandomPitch	= 0;
	UPROPERTY(EditAnywhere, Category = "DecorationType")			uint8			bRandomYaw		= 0;
	UPROPERTY(EditAnywhere, Category = "DecorationType")			uint8			bRandomRoll		= 0;
};

USTRUCT(BlueprintType)
struct FPoolItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PoolItem")				AActor*		aElement	= nullptr;
	UPROPERTY(EditAnywhere, Category = "PoolItem")				int32		iUsed		= 0;
};

USTRUCT(BlueprintType)
struct FEnumStat
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EnumStat")				FString		statName		= "";
	UPROPERTY(EditAnywhere, Category = "EnumStat")				uint8		trueValue		= 0;
	UPROPERTY(EditAnywhere, Category = "EnumStat")				uint8		spoofValue		= 0;
	UPROPERTY(EditAnywhere, Category = "EnumStat")				float		spoofChance		= 0;
	UPROPERTY(EditAnywhere, Category = "EnumStat")				float		obscurity		= 0;
	UPROPERTY(EditAnywhere, Category = "EnumStat")				bool		isStatic		= false;
};

USTRUCT(BlueprintType)
struct FVectorStat
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VectorStat")			FString statName	= "";
	UPROPERTY(EditAnywhere, Category = "VectorStat")			FVector trueValue	= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "VectorStat")			FVector spoofValue	= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "VectorStat")			float	spoofChance = 0;
	UPROPERTY(EditAnywhere, Category = "VectorStat")			float	obscurity	= 0;
	UPROPERTY(EditAnywhere, Category = "VectorStat")			bool	isStatic	= false;
};

USTRUCT(BlueprintType)
struct FFloatStat
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FloatStat")				FString statName	= "";
	UPROPERTY(EditAnywhere, Category = "FloatStat")				float	trueValue	= 0;
	UPROPERTY(EditAnywhere, Category = "FloatStat")				float	spoofValue	= 0;
	UPROPERTY(EditAnywhere, Category = "FloatStat")				float	spoofChance = 0;
	UPROPERTY(EditAnywhere, Category = "FloatStat")				float	obscurity	= 0;
	UPROPERTY(EditAnywhere, Category = "FloatStat")				bool	isStatic	= false;
};

USTRUCT(BlueprintType)
struct FUAVFlightPlanWaypoints
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlanWaypoints")			FVector vLocation		= FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlanWaypoints")			float fpSpeed			= 0;
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlanWaypoints")			float fpAltitude		= 0;
};


USTRUCT(BlueprintType)
struct FCrosshairItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CrosshairItem")						FString FriendlyName			= "";			//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "CrosshairItem")						UTexture2D* CrosshairTexture	= nullptr;		//var Texture CrosshairTexture;
};


USTRUCT(BlueprintType)
struct FFloatBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FloatBox")				float X1 = 0;										//var float X1;
	UPROPERTY(EditAnywhere, Category = "FloatBox")				float Y1 = 0;										//var float Y1;
	UPROPERTY(EditAnywhere, Category = "FloatBox")				float X2 = 0;										//var float X2;
	UPROPERTY(EditAnywhere, Category = "FloatBox")				float Y2 = 0;										//var float Y2;
};


USTRUCT(BlueprintType)
struct FCountryFlag
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								FString CountryCode = "";							//var string CountryCode;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								FString CountryName = "";							//var string CountryName;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float U = 0;										//var float U;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float V = 0;										//var float V;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float UL = 0;										//var float UL;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float VL = 0;										//var float VL;
};


USTRUCT(BlueprintType)
struct FOrientation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Orientation")							ECamOrientation CamOrientation = ECamOrientation::CAMORIENT_None;						//var Object.ECamOrientation CamOrientation;
	UPROPERTY(EditAnywhere, Category = "Orientation")							AActor* LookAt = nullptr;										//var AActor* LookAt;
	UPROPERTY(EditAnywhere, Category = "Orientation")							AActor* DollyWith = nullptr;									//var AActor* DollyWith;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float EaseIntime = 0;									//var float EaseIntime;
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bReversePitch = 0;								//var int bReversePitch;
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bReverseYaw = 0;									//var int bReverseYaw;
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bReverseRoll = 0;									//var int bReverseRoll;
	UPROPERTY(EditAnywhere, Category = "Orientation")							Fpointer Orientation = Fpointer({});								//var pointer Orientation;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float PctInStart = 0;									//var float PctInStart;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float PctInEnd = 0;										//var float PctInEnd;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float PctInDuration = 0;								//var float PctInDuration;
	UPROPERTY(EditAnywhere, Category = "Orientation")							FRotator StartingRotation = FRotator(0, 0, 0);							//var Object.Rotator StartingRotation;
};

USTRUCT(BlueprintType)
struct FInterpolator
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bDone = 0;										//var int bDone;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _value = 0;										//var float _value;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _remainingTime = 0;								//var float _remainingTime;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _totalTime = 0;									//var float _totalTime;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _speed = 0;										//var float _speed;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _acceleration = 0;								//var float _acceleration;
};

USTRUCT(BlueprintType)
struct FCachedSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CachedSound")							FName CacheName = "";									//var name CacheName;
	UPROPERTY(EditAnywhere, Category = "CachedSound")							USoundBase* CacheSound = nullptr;								//var Sound CacheSound;
};
USTRUCT(BlueprintType)
struct FQueueItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QueueItem")								FName Name = "";											//var name Voice;
	UPROPERTY(EditAnywhere, Category = "QueueItem")								float Delay = 0;										//var float Delay;
	UPROPERTY(EditAnywhere, Category = "QueueItem")								uint8 Switch = 0;										//var byte Switch;
};

USTRUCT(BlueprintType)
struct FVehiclePatrolPaths
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehiclePatrolPaths")		TArray<ARoadPathNode*>	apnDrivingPathNodesForPatrol = {};	//var array<RoadPathNode> apnDrivingPathNodesForPatrol;
};

USTRUCT(BlueprintType)
struct FScoreItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FName Name = "";											//var name Name;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FName PosActorTag = "";									//var name PosActorTag;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FVector Location = FVector(0, 0, 0);				//var FVector Location;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FRotator Rotation = FRotator(0, 0, 0);				//var Object.Rotator Rotation;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								bool bBaseToPosActor = false;								//var bool bBaseToPosActor;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								EFontType Font = EFontType::FT_Courier;										//var EFontType Font;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								AActor* PosActor = nullptr;									//var AActor* PosActor;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								TArray<ATextDisplay_Char*> Digits = {};					//var array<TextDisplay_Char> Digits;
};

USTRUCT(BlueprintType)
struct FSection
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Section")			FString		Header	= "";			//var string Header;
	UPROPERTY(EditAnywhere, Category = "Section")			FString		Id		= "";			//var string Id;
	UPROPERTY(EditAnywhere, Category = "Section")			FString		Display	= "";			//var string Display;
	UPROPERTY(EditAnywhere, Category = "Section")			FString		Caption	= "";			//var string Caption;
	UPROPERTY(EditAnywhere, Category = "Section")			FString		URL		= "";			//var string URL;
};


USTRUCT(BlueprintType)
struct FTargetInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TargetInfo")							ATargetMover* Target = nullptr;								//var AGP_Gameplay.TargetMover Target;
	UPROPERTY(EditAnywhere, Category = "TargetInfo")							int32 hits = 0;											//var int hits;
	UPROPERTY(EditAnywhere, Category = "TargetInfo")							bool Triggered = false;										//var bool Triggered;
};

USTRUCT(BlueprintType)
struct Flipsync
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "lipsync")								FName AnimName = "";										//var name AnimName;
	UPROPERTY(EditAnywhere, Category = "lipsync")								int32 TargetID = 0;										//var int TargetID;
};

USTRUCT(BlueprintType)
struct FLipSyncDebug
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LipSyncDebug")							FString Line1 = "";										//var string Line1;
	UPROPERTY(EditAnywhere, Category = "LipSyncDebug")							FString Line2 = "";										//var string Line2;
	UPROPERTY(EditAnywhere, Category = "LipSyncDebug")							float Duration = 0;										//var float Duration;
};


USTRUCT(BlueprintType)
struct FFadeMoveInfoStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FadeMoveInfoStruct")		AActor* PlayerMovePoint = nullptr;							//var AActor* PlayerMovePoint;
	UPROPERTY(EditAnywhere, Category = "FadeMoveInfoStruct")		AFSTS_EventLab* CallBackScript = nullptr;					//var FSTS_EventLab CallBackScript;
};

USTRUCT(BlueprintType)
struct FWeaponsSergeant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Tag = "";										//var name Tag;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							ANPC_SpecialForces* Actor = nullptr;						//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName CadreTriggerTag = "";							//var name CadreTriggerTag;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							AAGP_UseTrigger* CadreTrigger = nullptr;					//var AGP.AGP_UseTrigger CadreTrigger;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							bool bGreeted = false;									//var bool bGreeted;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Greeting = "";									//var name Greeting;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							bool bInstructed = false;								//var bool bInstructed;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Instruction = "";								//var name Instruction;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							bool bReminded = false;									//var bool bReminded;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Reminder = "";									//var name Reminder;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeReady = "";							//var name ChallengeReady;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeGo = "";								//var name ChallengeGo;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeIncomplete = "";						//var name ChallengeIncomplete;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeComplete = "";						//var name ChallengeComplete;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName WarningLeavingArea = "";						//var name WarningLeavingArea;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName WarningDownrange = "";							//var name WarningDownrange;
};

USTRUCT(BlueprintType)
struct FWeaponsAssistant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName Tag = "";										//var name Tag;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							ANPC_SpecialForces* Actor = nullptr;						//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName PickupTag = "";								//var name PickupTag;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName WarningDownrange = "";							//var name WarningDownrange;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName WarningLeavingArea = "";						//var name WarningLeavingArea;
};
USTRUCT(BlueprintType)
struct FChallengeStation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 MaxNumberTargets = 0;							//var int MaxNumberTargets;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 MinPassingScore = 0;							//var int MinPassingScore;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							AMarksmanTarget* CurrentMarksmanTarget = nullptr;			//var AGP_Gameplay.MarksmanTarget CurrentMarksmanTarget;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							ADecoMesh* CurrentDecoMesh = nullptr;						//var DecoMesh CurrentDecoMesh;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							ADamageDetector* CurrentDamageDetector = nullptr;			//var AGP_Gameplay.DamageDetector CurrentDamageDetector;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							TArray<FName> TargetStack = {};						//var array<name> TargetStack;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							TArray<FName> TargetStates = {};						//var array<name> TargetStates;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 TargetActiveTime = 0;							//var int TargetActiveTime;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 TargetInactiveTime = 0;						//var int TargetInactiveTime;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FName ChallengeState = "";							//var name ChallengeState;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FName ChallengeVolumeTag = "";						//var name ChallengeVolumeTag;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							ATriggerVolume* ChallengeVolume = nullptr;				//var AGP_Gameplay.TriggerVolume ChallengeVolume;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FName ChallengeReadyTriggerTag = "";					//var name ChallengeReadyTriggerTag;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							AAGP_Trigger* ChallengeReadyTrigger = nullptr;			//var AGP_Gameplay.AGP_Trigger ChallengeReadyTrigger;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FWeaponsSergeant Instructor = FWeaponsSergeant({});					//var EL_SFWeapons_Range.WeaponsSergeant Instructor;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FWeaponsAssistant Assistant1 = FWeaponsAssistant({});					//var EL_SFWeapons_Range.WeaponsAssistant Assistant1;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FWeaponsAssistant Assistant2 = FWeaponsAssistant({});					//var EL_SFWeapons_Range.WeaponsAssistant Assistant2;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							bool bWeaponActive = false;								//var bool bWeaponActive;
};

USTRUCT(BlueprintType)
struct FHelpInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FName HelpName = "";										//var name HelpName;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									float HelpTimer = 0;									//var float HelpTimer;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FString Line1HelpText = "";								//var string Line1HelpText;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FString Line2HelpText = "";								//var string Line2HelpText;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FName LSHelpAnimation = "";								//var name LSHelpAnimation;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									AActor* LSActor = nullptr;									//var AActor* LSActor;
};

USTRUCT(BlueprintType)
struct FLFTargetStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LFTargetStruct")							TArray<AActor*> InvalidTarget = {};						//var array<AGP_Vehicle> InvalidTarget;
	UPROPERTY(EditAnywhere, Category = "LFTargetStruct")							TArray<AActor*> ValidTarget = {};						//var array<AGP_Vehicle> ValidTarget;
};


USTRUCT(BlueprintType)
struct FTeamMember
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FName ActorTag = "";										//var name ActorTag;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								ANPC_SpecialForces* Actor = nullptr;							//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FName VolTriggerTag = "";								//var name VolTriggerTag;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								ATriggerVolume* VolTrigger = nullptr;							//var AGP_Gameplay.TriggerVolume VolTrigger;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FName UseTriggerTag = "";								//var name UseTriggerTag;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								AAGP_UseTrigger* UseTrigger = nullptr;						//var AGP.AGP_UseTrigger UseTrigger;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FString TalkText = "";									//var string TalkText;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FString MOSText = "";									//var string MOSText;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								int32 offset = 0;										//var int offset;
};

USTRUCT(BlueprintType)
struct FLevelTex
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* Image = nullptr;							//var Shader Image;
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* Status = nullptr;							//var Shader Status;
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* ImageEnabled = nullptr;					//var Texture ImageEnabled;
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* ImageDisabled = nullptr;					//var Texture ImageDisabled;
};

USTRUCT(BlueprintType)
struct FLevelTrigger
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FName Tag = "";											//var name Tag;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								AAGP_UseTrigger* Trigger = nullptr;							//var AGP.AGP_UseTrigger Trigger;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FString MSG_NotAvailable = "";							//var string MSG_NotAvailable;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FString MSG_Available = "";								//var string MSG_Available;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FString MSG_Completed = "";								//var string MSG_Completed;
};

USTRUCT(BlueprintType)
struct FMissionInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								uint8 Tour = 0;											//var byte Tour;
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								uint8 Mission = 0;										//var byte Mission;
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								FString LoadMessage = "";								//var string LoadMessage;
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								FString MapName = "";									//var string MapName;
};
USTRUCT(BlueprintType)
struct FHeliPath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HeliPath")									FName Name = "";											//var name Name;
	UPROPERTY(EditAnywhere, Category = "HeliPath")									ASceneManager* Path = nullptr;								//var SceneManager Path;
	UPROPERTY(EditAnywhere, Category = "HeliPath")									bool bFlown = false;										//var bool bFlown;
};

USTRUCT(BlueprintType)
struct FCSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CSound")									bool bFadeUp = false;						//var bool bFadeUp;
	UPROPERTY(EditAnywhere, Category = "CSound")									bool bFadeDown = false;						//var bool bFadeDown;
	UPROPERTY(EditAnywhere, Category = "CSound")									float FadeTime = 0;							//var float FadeTime;
	UPROPERTY(EditAnywhere, Category = "CSound")									float Volume = 0;							//var float Volume;
	UPROPERTY(EditAnywhere, Category = "CSound")									float StartVolume = 0;						//var float StartVolume;
};


USTRUCT(BlueprintType)
struct FBoneProfile
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BoneProfile")								FName BodyPart = "";										//var name BodyPart;
	UPROPERTY(EditAnywhere, Category = "BoneProfile")								FName BoneName = "";										//var name BoneName;
};


USTRUCT(BlueprintType)
struct FGameSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameSound")									USoundBase* Sound = nullptr;									//var Sound Sound;
	UPROPERTY(EditAnywhere, Category = "GameSound")									FName Name = "";											//var name Name;
	UPROPERTY(EditAnywhere, Category = "GameSound")									float Duration = 0;										//var float Duration;
};
USTRUCT(BlueprintType)
struct FLSAnim
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PrevNext")				FName Anim					= "";				//var name Anim;
	UPROPERTY(EditAnywhere, Category = "PrevNext")				USoundBase* Sound			= nullptr;			//var Sound Sound;
	UPROPERTY(EditAnywhere, Category = "PrevNext")				TArray<FName> GestureAnim	= {};				//var name GestureAnim;
	UPROPERTY(EditAnywhere, Category = "PrevNext")				TArray<float> GestureDelay	= {};				//var float GestureDelay;
};
USTRUCT(BlueprintType)
struct FGameAnim
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameAnim")									FName Anim = "";											//var name Anim;
};

USTRUCT(BlueprintType)
struct FTimerEvent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TimerEvent")				FName		Name		= "";					//var name Name;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")				float		StartTime	= 0;					//var float StartTime;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")				float		WaitTime	= 0;					//var float WaitTime;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")				ETimerType	TType		= ETimerType::TT_Timer;								//var ETimerType TType;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")				bool		bRepeat		= false;				//var bool bRepeat;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")				bool		bPause		= false;				//var bool bPause;
};
USTRUCT(BlueprintType)
struct FQueueAnimation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			FName		Anim		= "";					//var name Anim;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			AActor*		Actor		= nullptr;				//var AActor* Actor;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			float		StartTime	= 0;					//var float StartTime;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			float		Length		= 0;					//var float Length;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			bool		bLoop		= 0;					//var bool bLoop;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			float		Rate		= 0;					//var float Rate;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			float		TweenTime	= 0;					//var float TweenTime;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			int32		Channel		= 0;					//var int Channel;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")			bool		bRemove		= false;				//var bool bRemove;
};

USTRUCT(BlueprintType)
struct FPrevNext
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PrevNext")			float HotSpotX			= 0;				//var float HotSpotX;
	UPROPERTY(EditAnywhere, Category = "PrevNext")			float HotSpotY			= 0;				//var float HotSpotY;
	UPROPERTY(EditAnywhere, Category = "PrevNext")			float HotSpotZ			= 0;				//var float HotSpotZ;
	UPROPERTY(EditAnywhere, Category = "PrevNext")			float HotSpotRadius		= 0;				//var float HotSpotRadius;
	UPROPERTY(EditAnywhere, Category = "PrevNext")			FString HotSpotText		= "";				//var string HotSpotText;
	UPROPERTY(EditAnywhere, Category = "PrevNext")			FName LookTargetName	= "";				//var name LookTargetName;
	UPROPERTY(EditAnywhere, Category = "PrevNext")			AExamAnswer* Answer		= nullptr;			//var ExamAnswer Answer;
};

USTRUCT(BlueprintType)
struct FTestAnswer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		bool			bCorrectAnswer	= false;			//var bool bCorrectAnswer;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		float			HotSpotX		= 0;				//var float HotSpotX;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		float			HotSpotY		= 0;				//var float HotSpotY;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		float			HotSpotZ		= 0;				//var float HotSpotZ;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		float			HotSpotRadius	= 0;				//var float HotSpotRadius;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		FString			HotSpotText		= "";				//var string HotSpotText;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		FName			QuestionName	= "";				//var name QuestionName;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		FName			LookTargetName	= "";				//var name LookTargetName;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		AExamAnswer*	Answer			= nullptr;			//var ExamAnswer Answer;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")		bool			bMarkedCorrect	= false;			//var bool bMarkedCorrect;
};

USTRUCT(BlueprintType)
struct FTestPage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TestPage")				FName				PageName		= "";				//var name PageName;
	UPROPERTY(EditAnywhere, Category = "TestPage")				UMaterialInstance*	PageTexture		= nullptr;			//var Material PageTexture;
	UPROPERTY(EditAnywhere, Category = "TestPage")				TArray<FTestAnswer> TestAnswers		= {};				//var array<TestAnswer> TestAnswers;
	UPROPERTY(EditAnywhere, Category = "TestPage")				FPrevNext			PageNext		= FPrevNext({});	//var MedExam.PrevNext PageNext;
	UPROPERTY(EditAnywhere, Category = "TestPage")				FPrevNext			PagePrev		= FPrevNext({});	//var MedExam.PrevNext PagePrev;
};

USTRUCT(BlueprintType)
struct FWeatherPcl
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			FVector pos			= FVector(0, 0, 0);			//var FVector pos;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			FVector Vel			= FVector(0, 0, 0);			//var FVector Vel;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			float Life			= 0;						//var float Life;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			float Size			= 0;						//var float Size;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			float HitTime		= 0;						//var float HitTime;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			float InvLifeSpan	= 0;						//var float InvLifeSpan;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			float DistAtten		= 0;						//var float DistAtten;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			uint8 frame			= 0;						//var byte frame;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			uint8 Dummy1		= 0;						//var byte Dummy1;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			uint8 Visible		= 0;						//var byte Visible;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")			uint8 Dummy2		= 0;						//var byte Dummy2;
};

USTRUCT(BlueprintType)
struct FEventParms
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EventParms")				FName Name			= "";								//var name Name;
	UPROPERTY(EditAnywhere, Category = "EventParms")				bool bDelay			= false;							//var bool bDelay;
	UPROPERTY(EditAnywhere, Category = "EventParms")				float DelayMin		= 0;								//var float DelayMin;
	UPROPERTY(EditAnywhere, Category = "EventParms")				float DelayMax		= 0;								//var float DelayMax;
};

USTRUCT(BlueprintType)
struct FPropFlags
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool bHidden					= false;				//var bool bHidden;
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool bBlockActors				= false;				//var bool bBlockActors;
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool bBlockPlayers				= false;				//var bool bBlockPlayers;
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool bBlockZeroExtentTraces		= false;				//var bool bBlockZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool bBlockNonZeroExtentTraces	= false;				//var bool bBlockNonZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool AmbientGlow				= false;				//var bool AmbientGlow;
	UPROPERTY(EditAnywhere, Category = "PropFlags")					bool DrawScale					= false;				//var bool DrawScale;
};

USTRUCT(BlueprintType)
struct FPropValues
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PropValues")				bool	bHidden						= false;				//var bool bHidden;
	UPROPERTY(EditAnywhere, Category = "PropValues")				bool	bBlockActors				= false;				//var bool bBlockActors;
	UPROPERTY(EditAnywhere, Category = "PropValues")				bool	bBlockPlayers				= false;				//var bool bBlockPlayers;
	UPROPERTY(EditAnywhere, Category = "PropValues")				bool	bBlockZeroExtentTraces		= false;				//var bool bBlockZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropValues")				bool	bBlockNonZeroExtentTraces	= false;				//var bool bBlockNonZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropValues")				uint8	AmbientGlow					= 0;					//var byte AmbientGlow;
	UPROPERTY(EditAnywhere, Category = "PropValues")				float	DrawScale					= 0;					//var float DrawScale;
};

USTRUCT(BlueprintType)
struct FTargetActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TargetActor")				FName			ActorTag		= "";						//var name ActorTag;
	UPROPERTY(EditAnywhere, Category = "TargetActor")				FPropFlags		PropertyFlags = FPropFlags({});								//var PropertyTrigger.PropFlags PropertyFlags;
	UPROPERTY(EditAnywhere, Category = "TargetActor")				FPropValues		SetValues = FPropValues({});									//var PropertyTrigger.PropValues SetValues;
	UPROPERTY(EditAnywhere, Category = "TargetActor")				FPropValues		UnSetValues = FPropValues({});								//var PropertyTrigger.PropValues UnSetValues;
	UPROPERTY(EditAnywhere, Category = "TargetActor")				AActor*			ActorRef		= nullptr;					//var AActor* ActorRef;
};

USTRUCT(BlueprintType)
struct FImageStratum
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ImageStratum")					float				LowerBound	= 0;			//var float LowerBound;
	UPROPERTY(EditAnywhere, Category = "ImageStratum")					float				UpperBound	= 0;			//var float UpperBound;
	UPROPERTY(EditAnywhere, Category = "ImageStratum")					UMaterialInstance*	RadarImage	= nullptr;		//var Material RadarImage;
};

USTRUCT(BlueprintType)
struct FNPCRestStopAnimSequenceSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")	FName	animStart				= "";			//var name animStart;
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")	FName	animMiddle				= "";			//var name animMiddle;
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")	FName	AnimEnd					= "";			//var name AnimEnd;
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")	bool	bShoulderWeaponFirst	= false;		//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FNPCAttachObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		AActor*		actSpawnedItem		= nullptr;				//var AActor* actSpawnedItem;
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		AActor*		Attachment			= nullptr;				//var class<Actor>  Attachment;
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		FName		Bone				= "";					//var name Bone;
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		FVector		LocationOffset		= FVector(0, 0, 0);		//var FVector LocationOffset;
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		FRotator	RotationOffset		= FRotator(0, 0, 0);	//var Object.Rotator RotationOffset;
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		bool		bUseParentScale		= false;				//var bool bUseParentScale;
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		float		Scale				= 0;					//var float Scale;
};

USTRUCT(BlueprintType)
struct FRecentContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RecentContact")			APawn* pawnContact			= nullptr;					//var APawn* pawnContact;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			bool bHumanControlled		= false;					//var bool bHumanControlled;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			bool bEnemy					= false;					//var bool bEnemy;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			FVector vLocation			= FVector(0, 0, 0);			//var FVector vLocation;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			float fpThreatLevel			= 0;						//var float fpThreatLevel;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			float fpTimeSeen			= 0;						//var float fpTimeSeen;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			float fpClosureRate			= 0;						//var float fpClosureRate;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			int32 iConfidencePenalty	= 0;						//var int iConfidencePenalty;
	UPROPERTY(EditAnywhere, Category = "RecentContact")			bool bContactLost			= false;					//var bool bContactLost;
};
USTRUCT(BlueprintType)
struct FGrenadeThreatContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GrenadeThreatContact")		AThrowWeaponPickup*		twpGrenade = nullptr;			//var ThrowWeaponPickup twpGrenade;
	UPROPERTY(EditAnywhere, Category = "GrenadeThreatContact")		float					fpTimeSeen = 0;					//var float fpTimeSeen;
};

USTRUCT(BlueprintType)
struct FNPCAnimSequenceSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")			FName	animStart				= "";				//var name animStart;
	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")			FName	animMiddle				= "";				//var name animMiddle;
	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")			FName	AnimEnd					= "";				//var name AnimEnd;
	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")			bool	bShoulderWeaponFirst	= false;			//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FTarget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Target")		UStaticMesh* StaticMesh			= nullptr;							//var StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Target")		UStaticMesh* ZoneMesh			= nullptr;								//var StaticMesh ZoneMesh;
	UPROPERTY(EditAnywhere, Category = "Target")		float Z1Scale					= 0;									//var float Z1Scale;
	UPROPERTY(EditAnywhere, Category = "Target")		FVector Z1Scale3D				= FVector(0, 0, 0);									//var FVector Z1Scale3D;
	UPROPERTY(EditAnywhere, Category = "Target")		FVector Z1Offset				= FVector(0, 0, 0);									//var FVector Z1Offset;
	UPROPERTY(EditAnywhere, Category = "Target")		FRotator Z1Rotation				= FRotator(0, 0, 0);								//var Object.Rotator Z1Rotation;
	UPROPERTY(EditAnywhere, Category = "Target")		FString Z1ID					= "";										//var string Z1ID;
	UPROPERTY(EditAnywhere, Category = "Target")		float Z2Scale					= 0;										//var float Z2Scale;
	UPROPERTY(EditAnywhere, Category = "Target")		FVector Z2Scale3D				= FVector(0, 0, 0);									//var FVector Z2Scale3D;
	UPROPERTY(EditAnywhere, Category = "Target")		FVector Z2Offset				= FVector(0, 0, 0);									//var FVector Z2Offset;
	UPROPERTY(EditAnywhere, Category = "Target")		FRotator Z2Rotation				= FRotator(0, 0, 0);								//var Object.Rotator Z2Rotation;
	UPROPERTY(EditAnywhere, Category = "Target")		FString Z2ID					= "";										//var string Z2ID;
};

USTRUCT(BlueprintType)
struct FTagAttachment
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "TagAttachment")		FName	ActorTag	= "";										//	var name ActorTag;
};

USTRUCT(BlueprintType)
struct FAttachObject
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")			AActor*		Attachment			= nullptr;					//var class<Actor>  Attachment;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")			FName		Bone				= "";						//var name Bone;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")			FVector		LocationOffset		= FVector(0, 0, 0);			//var FVector LocationOffset;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")			FRotator	RotationOffset		= FRotator(0, 0, 0);		//var Object.Rotator RotationOffset;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")			bool		bUseParentScale		= false;					//var bool bUseParentScale;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")			float		Scale				= 0;						//var float Scale;
};

USTRUCT(BlueprintType)
struct FTarGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TarGroup")			FString		Label		= "";				//var string Label;
	UPROPERTY(EditAnywhere, Category = "TarGroup")			int32		nShot		= 0;				//var int nShot;
	UPROPERTY(EditAnywhere, Category = "TarGroup")			int32		nMissed		= 0;				//var int nMissed;
	UPROPERTY(EditAnywhere, Category = "TarGroup")			int32		nTotal		= 0;				//var int nTotal;
};

USTRUCT(BlueprintType)
struct FOutStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "OutStruct")			FName Event				= "";				//var name Event;
	UPROPERTY(EditAnywhere, Category = "OutStruct")			int32 Counter			= 0;				//var int Counter;
};


USTRUCT(BlueprintType)
struct FVisibleDelay
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VisibleDelay")		float Visible			= 0;		//var float Visible;
	UPROPERTY(EditAnywhere, Category = "VisibleDelay")		float Delay				= 0;		//var float Delay;
};

USTRUCT(BlueprintType)
struct FPaddingPercent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PaddingPercent")		float HorzPerc		= 0;		//var float HorzPerc;
	UPROPERTY(EditAnywhere, Category = "PaddingPercent")		float VertPerc		= 0;		//var float VertPerc;
};

USTRUCT(BlueprintType)
struct FAnimInfo
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	cX				= 0;			//var float cX;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	cY				= 0;			//var float cY;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	Scale			= 0;			//var float Scale;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	FadeTime		= 0;			//var float FadeTime;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	Alpha			= 0;			//var float Alpha;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	TargetAlpha		= 0;			//var float TargetAlpha;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	ResetDelay		= 0;			//var float ResetDelay;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")			float	TravelTime		= 0;			//var float TravelTime;
};

USTRUCT(BlueprintType)
struct FProfileStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ProfileStruct")			FString ProfileName		= "";			//var string ProfileName;
	UPROPERTY(EditAnywhere, Category = "ProfileStruct")			float ProfileSeconds	= 0;			//var float ProfileSeconds;
};

USTRUCT(BlueprintType)
struct FeOwnageMap
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")		int32 RLevel = 0;			//var int RLevel;
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")		FString MapName = "";		//var string MapName;
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")		FString MapDesc = "";		//var string MapDesc;
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")		FString MapURL = "";			//var string MapURL;
};

USTRUCT(BlueprintType)
struct FAutoLoadMenu
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AutoLoadMenu")		FString		MenuClassName		= "";			//var string MenuClassName;
	UPROPERTY(EditAnywhere, Category = "AutoLoadMenu")		bool		bPreInitialize		= false;		//var bool bPreInitialize;
};

USTRUCT(BlueprintType)
struct FRestoreMenuItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RestoreMenuItem")		FString		MenuClassName	= "";			//var string MenuClassName;
	UPROPERTY(EditAnywhere, Category = "RestoreMenuItem")		FString		Param1			= "";			//var string Param1;
	UPROPERTY(EditAnywhere, Category = "RestoreMenuItem")		FString		Param2			= "";			//var string Param2;
};
USTRUCT(BlueprintType)
struct FDesignModeHint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DesignModeHint")		FString Key					= "";		//var string Key;
	UPROPERTY(EditAnywhere, Category = "DesignModeHint")		FString Description			= "";		//var string Description;
};

USTRUCT(BlueprintType)
struct FGUIListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GUIListElem")			FString		Item				= "";			//var string Item;
	UPROPERTY(EditAnywhere, Category = "GUIListElem")			UObject*	ExtraData			= nullptr;		//var Object ExtraData;
	UPROPERTY(EditAnywhere, Category = "GUIListElem")			FString		ExtraStrData		= "";			//var string ExtraStrData;
	UPROPERTY(EditAnywhere, Category = "GUIListElem")			bool		bSection			= false;		//var bool bSection;

	bool operator==(const FGUIListElem& GUIListElem)
	{
		return Item == GUIListElem.Item
			&& ExtraData == GUIListElem.ExtraData
			&& ExtraStrData == GUIListElem.ExtraStrData
			&& bSection == GUIListElem.bSection;
	}
};

USTRUCT(BlueprintType)
struct FAPackInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "APackInfo")				FString		PackageName		= "";								//var string PackageName;
	UPROPERTY(EditAnywhere, Category = "APackInfo")				FString		Description		= "";								//var string Description;
};

USTRUCT(BlueprintType)
struct FMultiSelectListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")			FString		Item			= "";					//var string Item;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")			UObject*	ExtraData		= nullptr;				//var Object ExtraData;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")			FString		ExtraStrData	= "";					//var string ExtraStrData;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")			bool		bSelected		= false;				//var bool bSelected;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")			int32		SelectionIndex	= 0;					//var int SelectionIndex;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")			bool		bSection		= false;				//var bool bSection;

	bool operator==(const FMultiSelectListElem& MultiSelectListElem)
	{
		return Item == MultiSelectListElem.Item
			&& ExtraData == MultiSelectListElem.ExtraData
			&& ExtraStrData == MultiSelectListElem.ExtraStrData
			&& bSelected == MultiSelectListElem.bSelected
			&& SelectionIndex == MultiSelectListElem.SelectionIndex
			&& bSection == MultiSelectListElem.bSection;
	}
};

USTRUCT(BlueprintType)
struct FImageListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ImageListElem")			int32				Item		= 0;			//var int Item;
	UPROPERTY(EditAnywhere, Category = "ImageListElem")			UMaterialInstance*	Image		= nullptr;		//var Material Image;
	UPROPERTY(EditAnywhere, Category = "ImageListElem")			int32				Locked		= 0;			//var int Locked;
};

USTRUCT(BlueprintType)
struct FGUITreeNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")			FString		Caption			= "";			//var string Caption;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")			FString		Value			= "";			//var string Value;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")			FString		ParentCaption   = "";			//var string ParentCaption;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")			FString		ExtraInfo		= "";			//var string ExtraInfo;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")			int32		Level			= 0;			//var int Level;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")			bool		bEnabled		= false;		//var bool bEnabled;
};

USTRUCT(BlueprintType)
struct FAutoLoginInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")					FString IP = "";											//var string IP;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")					FString Port = "";										//var string Port;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")					FString UserName = "";									//var string UserName;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")					FString Password = "";									//var string Password;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")					bool bAutologin = false;									//var bool bAutologin;
};

USTRUCT(BlueprintType)
struct FGUITabItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GUITabItem")										FString ClassName = "";									//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "GUITabItem")										FString Caption = "";									//var string Caption;
	UPROPERTY(EditAnywhere, Category = "GUITabItem")										FString Hint = "";										//var string Hint;
};

USTRUCT(BlueprintType)
struct FBadgeInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										FString BadgeName= "";									//var string BadgeName;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeXMin = 0;									//var float RangeXMin;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeXMax = 0;									//var float RangeXMax;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeYMin = 0;									//var float RangeYMin;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeYMax = 0;									//var float RangeYMax;
};

USTRUCT(BlueprintType)
struct FRibbonRowInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RibbonRowInfo")									FString RibbonName1 = "";								//var string RibbonName1;
	UPROPERTY(EditAnywhere, Category = "RibbonRowInfo")									FString RibbonName2 = "";								//var string RibbonName2;
	UPROPERTY(EditAnywhere, Category = "RibbonRowInfo")									FString RibbonName3 = "";								//var string RibbonName3;
};


USTRUCT(BlueprintType)
struct FCommandAlias
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CommandAlias")									FString AliasText = "";									//var string AliasText;
	UPROPERTY(EditAnywhere, Category = "CommandAlias")									FString RealCommand = "";								//var string RealCommand;
};

USTRUCT(BlueprintType)
struct FServerSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ServerSettings")									FString Key = "";										//var string Key;
	UPROPERTY(EditAnywhere, Category = "ServerSettings")									FString Value = "";										//var string Value;
};

USTRUCT(BlueprintType)
struct FMapVoteGameConfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString GameClass = "";									//var string GameClass;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Prefix = "";										//var string Prefix;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Acronym = "";									//var string Acronym;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString GameName = "";									//var string GameName;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Mutators = "";									//var string Mutators;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Options = "";									//var string Options;
};

USTRUCT(BlueprintType)
struct FMapVoteGameConfigLite
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfigLite")							FString GameClass = "";									//var string GameClass;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfigLite")							FString Prefix = "";										//var string Prefix;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfigLite")							FString GameName = "";									//var string GameName;
};

USTRUCT(BlueprintType)
struct FMapVoteMapList
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									FString MapName = "";									//var string MapName;
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									int32 PlayCount = 0;									//var int PlayCount;
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									int32 Sequence = 0;										//var int Sequence;
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									bool bEnabled = false;										//var bool bEnabled;
};

USTRUCT(BlueprintType)
struct FMapHistoryInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									FString M = "";											//var string M;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									int32 p = 0;											//var int p;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									int32 S = 0;											//var int S;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									FString G = "";											//var string G;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									FString U = "";											//var string U;
};

USTRUCT(BlueprintType)
struct FMapVoteScore
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "MapVoteScore")									int32 MapIndex = 0;										//var int MapIndex;
	UPROPERTY(BlueprintReadWrite, Category = "MapVoteScore")									int32 GameConfigIndex = 0;								//var int GameConfigIndex;
	UPROPERTY(BlueprintReadWrite, Category = "MapVoteScore")									int32 VoteCount = 0;									//var int VoteCount;
};

USTRUCT(BlueprintType)
struct FKickVoteScore
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KickVoteScore")									int32 PlayerID = 0;										//var int PlayerID;
	UPROPERTY(BlueprintReadWrite, Category = "KickVoteScore")									int32 Team = 0;											//var int Team;
	UPROPERTY(BlueprintReadWrite, Category = "KickVoteScore")									int32 KickVoteCount = 0;								//var int KickVoteCount;
};

USTRUCT(BlueprintType)
struct FAccumulationData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AccumulationData")								FString Name = "";										//var string Name;
	UPROPERTY(BlueprintReadWrite, Category = "AccumulationData")								int32 VoteCount = 0;									//var int VoteCount;
};

USTRUCT(BlueprintType)
struct FsPendingRequest
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									AAA2_PlayerState* PRI;								//var PlayerReplicationInfo PRI;
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									int32 UnitID = 0;										//var int UnitId;
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									int32 Index = 0;										//var int index;
};

USTRUCT(BlueprintType)
struct FTournamentPlayer
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayer")								FString PlayerName = "";									//var string PlayerName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayer")								int32 TeamIndex = 0;									//var int TeamIndex;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayer")								int32 Score = 0;										//var int Score;
};


USTRUCT(BlueprintType)
struct FPlayerMBSInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						FString PlayerName = "";									//var string PlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						FString IPAddress = "";									//var string IPAddress;
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						int32 Ping = 0;											//var int Ping;
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						TArray<FKeyValuePair> Attributes = {};					//var array<GameInfo.KeyValuePair> Attributes;
};

USTRUCT(BlueprintType)
struct FStoredChatPassword
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "StoredChatPassword")				FString ChatRoomName = "";								//var string ChatRoomName;
	UPROPERTY(EditAnywhere, Category = "StoredChatPassword")				FString ChatRoomPassword = "";							//var string ChatRoomPassword;
};

USTRUCT(BlueprintType)
struct FPlayerNameInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					FString mInfo = "";										//var string mInfo;
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					FColor mColor = FColor(0,0,0,0);										//var Object.Color mColor;
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					float mXPos = 0;										//var float mXPos;
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					float mYPos = 0;										//var float mYPos;
};

USTRUCT(BlueprintType)
struct FAA2_ClientAdjustment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					float TimeStamp = 0;									//var float TimeStamp;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FName NewState = "";										//var name NewState;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					EPhysics newPhysics = EPhysics::PHYS_None;								//var Actor.EPhysics newPhysics
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FVector NewLoc = FVector(0, 0, 0);										//var FVector NewLoc;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FVector NewVel = FVector(0, 0, 0);										//var FVector NewVel;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					AActor* NewBase = nullptr;									//var AActor* NewBase;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FVector NewFloor = FVector(0, 0, 0);									//var FVector NewFloor;
};

USTRUCT(BlueprintType)
struct FAuthJacket
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						int32			ToursCompleted			= 0;	//var int ToursCompleted;
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						TArray<int32>	MissionsCompleted		= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0 };	//var int MissionsCompleted;
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						int32			MarksmanshipScore		= 0;	//var int MarksmanshipScore;
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						int32			Honor					= 0;	//var int Honor;
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						int32			Experience				= 0;	//var int Experience;
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						int32			Group					= 0;	//var int Group;
	UPROPERTY(EditAnywhere, Category = "AuthJacket")						int32			UID						= 0;	//var int UID;
};


USTRUCT(BlueprintType)
struct FWeaponRecordBrief
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeaponRecordBrief")					int32 ShotsFired = 0;									//var int ShotsFired;
	UPROPERTY(EditAnywhere, Category = "WeaponRecordBrief")					int32 ShotsHit = 0;										//var int ShotsHit;
	UPROPERTY(EditAnywhere, Category = "WeaponRecordBrief")					int32 Kills = 0;										//var int Kills;
};

	USTRUCT(BlueprintType)
struct FQualificationRecordBrief
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QualificationRecordBrief")			int32 Grade = 0;										//var int Grade;
	UPROPERTY(EditAnywhere, Category = "QualificationRecordBrief")			FString Date = "";										//var string Date;
};

USTRUCT(BlueprintType)
struct FRecordBriefStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString UserName = "";									//var string UserName;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 GroupID = 0;										//var int GroupID;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 UserID = 0;										//var int UserID;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 Experience = 0;									//var int Experience;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 Honor = 0;										//var int Honor;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString CreationDate = "";								//var string CreationDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString LastLoginDate = "";								//var string LastLoginDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					float HoursPlayed = 0;									//var float HoursPlayed;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString FavoriteMap = "";								//var string FavoriteMap;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 AverageScore = 0;									//var int AverageScore;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 HeroesVisited = 0;								//var int HeroesVisited;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 BetaUser = 0;										//var int BetaUser;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MissionsCompleted = 0;							//var int MissionsCompleted;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 RoundsWon = 0;									//var int RoundsWon;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 RoundsLost = 0;									//var int RoundsLost;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MatchesCompleted = 0;								//var int MatchesCompleted;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ObjectivesCompleted = 0;							//var int ObjectivesCompleted;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ObjectiveDeaths = 0;								//var int ObjectiveDeaths;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MedpaksApplied = 0;								//var int MedpaksApplied;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 TimesHealed = 0;									//var int TimesHealed;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FWeaponRecordBrief WeaponUseRecords = FWeaponRecordBrief({});				//var WeaponRecordBrief WeaponUseRecords;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ROE = 0;											//var int ROE;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString version = "";									//var string version;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FQualificationRecordBrief QualificationRecords = FQualificationRecordBrief({});		//var QualificationRecordBrief QualificationRecords;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ToursCompletedBitset = 0;							//var int ToursCompletedBitset;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MissionsCompletedBitset = 0;						//var int MissionsCompletedBitset;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SquadLeaderSeconds = "";							//var string SquadLeaderSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString FireteamLeaderSeconds = "";						//var string FireteamLeaderSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SoldierSeconds = "";								//var string SoldierSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SquadLeaderLinkedSeconds = "";					//var string SquadLeaderLinkedSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString FireteamLeaderLinkedSeconds = "";				//var string FireteamLeaderLinkedSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SoldierLinkedSeconds = "";						//var string SoldierLinkedSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString MedicTourCompletionDate = "";					//var string MedicTourCompletionDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString AirborneTourCompletionDate = "";					//var string AirborneTourCompletionDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString AdvancedMarksmanshipTourCompletionDate = "";		//var string AdvancedMarksmanshipTourCompletionDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SpecialForcesTrainingTourCompletionDate = "";	//var string SpecialForcesTrainingTourCompletionDate;
};

USTRUCT(BlueprintType)
struct FPlayerEvents
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString PlayerName = "";								//var string PlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString Password = "";								//var string Password;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Quit = 0;									//var int Quit;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 TimePlayed = 0;							//var int TimePlayed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 TimeAlive = 0;							//var int TimeAlive;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 RoundsStarted = 0;						//var int RoundsStarted;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 RoundsWon = 0;							//var int RoundsWon;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 RoundsLost = 0;							//var int RoundsLost;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 RoundsSurvivedWon = 0;					//var int RoundsSurvivedWon;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 RoundsSurvivedLost = 0;					//var int RoundsSurvivedLost;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsAsSQL = 0;							//var int SecondsAsSQL;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsAsFTL = 0;							//var int SecondsAsFTL;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsAsSoldier = 0;							//var int SecondsAsSoldier;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Kills = 0;									//var int Kills;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Deaths = 0;									//var int Deaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsLinkedToSQL = 0;						//var int SecondsLinkedToSQL;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsLinkedToFTL = 0;						//var int SecondsLinkedToFTL;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsLinkedToSoldiers = 0;					//var int SecondsLinkedToSoldiers;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 UsedMedic = 0;								//var int UsedMedic;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Healed = 0;									//var int Healed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 MedPaksUsed = 0;								//var int MedPaksUsed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Score = 0;									//var int Score;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ROE = 0;										//var int ROE;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 CapturedObjective = 0;						//var int CapturedObjective;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ObjectiveDeaths = 0;							//var int ObjectiveDeaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 AdminKicked = 0;								//var int AdminKicked;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 PBKicked = 0;									//var int PBKicked;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredGrenade = 0;						//var int ShotsFiredGrenade;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredAstRifle = 0;						//var int ShotsFiredAstRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredPistol = 0;							//var int ShotsFiredPistol;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredMG = 0;								//var int ShotsFiredMG;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredRocket = 0;							//var int ShotsFiredRocket;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredSprRifle = 0;						//var int ShotsFiredSprRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsGrenade = 0;								//var int HitsGrenade;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsAstRifle = 0;								//var int HitsAstRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsPistol = 0;								//var int HitsPistol;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsMG = 0;									//var int HitsMG;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsRocket = 0;								//var int HitsRocket;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsSprRifle = 0;								//var int HitsSprRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsGrenade = 0;								//var int KillsGrenade;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsAstRifle = 0;							//var int KillsAstRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsPistol = 0;								//var int KillsPistol;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsMG = 0;									//var int KillsMG;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsRocket = 0;								//var int KillsRocket;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsSprRifle = 0;							//var int KillsSprRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectAvailable = 0;						//var int iESSObjectAvailable;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectDiscovered = 0;						//var int iESSObjectDiscovered;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectExaminedByOtherPlayer = 0;			//var int iESSObjectExaminedByOtherPlayer;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectDiscoveryRadioed = 0;				//var int iESSObjectDiscoveryRadioed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPostRadioExaminedObject = 0;				//var int iESSPostRadioExaminedObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSNoRadioExaminedObject = 0;				//var int iESSNoRadioExaminedObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPostRadioLinkedObjectTaken = 0;			//var int iESSPostRadioLinkedObjectTaken;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSNoRadioLinkedObjectTaken = 0;				//var int iESSNoRadioLinkedObjectTaken;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionFailureTime = 0;					//var int iESSMissionFailureTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionSuccessTime = 0;					//var int iESSMissionSuccessTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionProgressTime = 0;					//var int iESSMissionProgressTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionTotalPlayers = 0;					//var int iESSMissionTotalPlayers;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionSurvivingPlayers = 0;				//var int iESSMissionSurvivingPlayers;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportedLethal = 0;					//var int iESSObjectReportedLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportedNonLethal = 0;				//var int iESSObjectReportedNonLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportableLethal = 0;				//var int iESSObjectReportableLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportableNonLethal = 0;			//var int iESSObjectReportableNonLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSObjectUnreportedLocations = "";			//var string iESSObjectUnreportedLocations;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportingErrors = 0;			//var int iESSObjectReportingErrors;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectUnnecessaryUse = 0;				//var int iESSObjectUnnecessaryUse;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSObjectDistribution = "";			//var string iESSObjectDistribution;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatHeadshots = 0;					//var int iESSCombatHeadshots;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatTotalDamage	= 0;				//var int iESSCombatTotalDamage;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatTotalDamageRange = 0;			//var int iESSCombatTotalDamageRange;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatDamageCount = 0;					//var int iESSCombatDamageCount;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatEnemyContactTime = 0;				//var int iESSCombatEnemyContactTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSCombatAIKill = "";						//var string iESSCombatAIKill;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatSurvivingAI = 0;					//var int iESSCombatSurvivingAI;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSCombatSurvivingAILocation = "";			//var string iESSCombatSurvivingAILocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByAI = 0;				//var int iESSPlayerTotalDeathsByAI;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByFriendlyFire = 0;		//var int iESSPlayerTotalDeathsByFriendlyFire;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByObject = 0;			//var int iESSPlayerTotalDeathsByObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSPlayerDeathLocation = "";				//var string iESSPlayerDeathLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuries = 0;					//var int iESSPlayerTotalInjuries;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesByAI = 0;				//var int iESSPlayerTotalInjuriesByAI;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesFriendlyFire = 0;		//var int iESSPlayerTotalInjuriesFriendlyFire;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesByObject = 0;			//var int iESSPlayerTotalInjuriesByObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSPlayerInjuryLocation = "";				//var string iESSPlayerInjuryLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROEFriendlyFireHits = 0;					//var int iESSROEFriendlyFireHits;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROEFriendlyFireDeaths = 0;				//var int iESSROEFriendlyFireDeaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROEFriendlyFireHitLocation = "";			//var string iESSROEFriendlyFireHitLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROEFriendlyFireDeathLocation = "";		//var string iESSROEFriendlyFireDeathLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROECivilianHits = 0;						//var int iESSROECivilianHits;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROECivilianDeaths = 0;					//var int iESSROECivilianDeaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROECivilianDeathsByIED = 0;				//var int iESSROECivilianDeathsByIED;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROECivilianHitMapLocation = "";			//var string iESSROECivilianHitMapLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROECivilianKillByPlayerMapLocation = "";	//var string iESSROECivilianKillByPlayerMapLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROECivilianKillByES2MapLocation = "";	//var string iESSROECivilianKillByES2MapLocation;
};

USTRUCT(BlueprintType)
struct FGameSpyServerItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bValid = 0;								//var int bValid;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bOfficial = 0;							//var int bOfficial;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bLeased = 0;								//var int bLeased;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bNATO = 0;								//var int bNATO;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bMiles = 0;								//var int bMiles;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bPassword = 0;							//var int bPassword;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bPunkBuster = 0;							//var int bPunkBuster;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bCheats = 0;								//var int bCheats;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bTournament = 0;							//var int bTournament;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bExploreTheArmy = 0;						//var int bExploreTheArmy;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bThirdParty = 0;							//var int bThirdParty;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Name = "";								//var string Name;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString MapName = "";							//var string MapName;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString GameVer = "";							//var string GameVer;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Guid = "";								//var string Guid;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 IP = 0;									//var int IP;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Port = 0;									//var int Port;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 QueryPort = 0;							//var int QueryPort;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Ping = 0;									//var int Ping;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Index = 0;							//var int Index;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Tour = 0;									//var int Tour;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 NumPlayers = 0;							//var int NumPlayers;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MaxPlayers = 0;							//var int MaxPlayers;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MinHonor = 0;								//var int MinHonor;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MaxHonor = 0;								//var int MaxHonor;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Groups = "";								//var string Groups;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 CustomFlags = 0;							//var int CustomFlags;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					float Time = 0;									//var float Time;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 NetOrderIP = 0;							//var int NetOrderIP;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Locale = "";								//var string Locale;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bRequiresAuthorization = 0;				//var int bRequiresAuthorization;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bCoop = 0;								//var int bCoop;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 AverageHonor = 0;							//var int AverageHonor;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 CurrentRound = 0;							//var int CurrentRound;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 RoundsPerMatch = 0;						//var int RoundsPerMatch;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString OperatingSystem = "";					//var string OperatingSystem;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 AveragePlayerPing = 0;					//var int AveragePlayerPing;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MissionTimeRemaining = 0;					//var int MissionTimeRemaining;
};

USTRUCT(BlueprintType)
struct FIpAddr
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "IpAddr")					int32 Addr = 0;								//var int Addr;
	UPROPERTY(EditAnywhere, Category = "IpAddr")					int32 Port = 0;								//var int Port;
};

USTRUCT(BlueprintType)
struct FBeaconInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "BeaconInfo")				FIpAddr Addr = FIpAddr({});							//var InternetLink.IpAddr Addr;
	UPROPERTY(EditAnywhere, Category = "BeaconInfo")				float Time = 0;								//var float Time;
	UPROPERTY(EditAnywhere, Category = "BeaconInfo")				FString Text = "";							//var string Text;
};

USTRUCT(BlueprintType)
struct FMD5UpdateData
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, Category = "MD5UpdateData")				FString Guid = "";							//var string Guid;
	UPROPERTY(EditAnywhere, Category = "MD5UpdateData")				FString MD5 = "";							//var string MD5;
	UPROPERTY(EditAnywhere, Category = "MD5UpdateData")				int32 Revision = 0;							//var int Revision;
};


USTRUCT(BlueprintType)
struct FtMasterServerEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "tMasterServerEntry")		FString Address = "";						//var string Address;
	UPROPERTY(EditAnywhere, Category = "tMasterServerEntry")		int32 Port = 0;								//var int Port;
};


USTRUCT(BlueprintType)
struct FAuthSurveyQuestion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		FString QuestionText = "";					//var string QuestionText;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		int32 UIComponentType = 0;					//var int UIComponentType;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		bool bIsOptional = false;						//var bool bIsOptional;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		int32 NumAnswers = 0;						//var int NumAnswers;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		TArray<FString> AnswerText = {};				//var TArray<FString> AnswerText;
};

USTRUCT(BlueprintType)
struct FAuthSurvey
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				int32 SurveyID = 0;							//var int SurveyID;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				FString SurveyTitle = "";					//var string SurveyTitle;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				FString SurveyDescription = "";				//var string SurveyDescription;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				bool bCompleted = false;						//var bool bCompleted;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				int32 ExperienceBonus = 0;					//var int ExperienceBonus;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				int32 NumQuestions = 0;						//var int NumQuestions;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				TArray<FAuthSurveyQuestion> Questions =  {};	//var array<AuthSurveyQuestion> Questions;
};

USTRUCT(BlueprintType)
struct FAuthSurveySubmission
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthSurveySubmission")		int32 SurveyID = 0;							//var int SurveyID;
	UPROPERTY(EditAnywhere, Category = "AuthSurveySubmission")		TArray<int32> AnswerBits = {};				//var array<int> AnswerBits;
};

USTRUCT(BlueprintType)
struct FAuthInt64
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthInt64")					int32 LowPart = 0;							//var int LowPart;
	UPROPERTY(EditAnywhere, Category = "AuthInt64")					int32 HighPart = 0;							//var int HighPart;
};

USTRUCT(BlueprintType)
struct FAuthPersonnelJacket
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		FAuthInt64 UserID = FAuthInt64({});						//var AuthInt64 UserID;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		FAuthInt64 GroupID = FAuthInt64({});						//var AuthInt64 GroupID;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		bool bBanned = false;							//var bool bBanned;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 BanDuration = 0;						//var int BanDuration;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 Experience = 0;						//var int Experience;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 ExperienceNext = 0;					//var int ExperienceNext;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 Honor = 0;							//var int Honor;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 ToursCompleted = 0;					//var int ToursCompleted;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 TourInfo = 0;							//var int TourInfo;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 Marksmanship = 0;						//var int Marksmanship;
};

USTRUCT(BlueprintType)
struct FPlayInfoData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString ThisProp = "";					//var Property ThisProp;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				AAA2_Info* ClassFrom = nullptr;				//var class<Info>  ClassFrom;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString SettingName = "";				//var string SettingName;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString DisplayName = "";				//var string DisplayName;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Description = "";				//var string Description;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Grouping = "";					//var string Grouping;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Data = "";						//var string Data;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString ExtraPriv = "";					//var string ExtraPriv;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Value = "";						//var string Value;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				EPlayInfoType RenderType;			//var EPlayInfoType RenderType;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				uint8 SecLevel = 0;						//var byte SecLevel;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				uint8 Weight = 0;						//var byte Weight;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bMPOnly = false;						//var bool bMPOnly;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bAdvanced = false;						//var bool bAdvanced;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bGlobal = false;						//var bool bGlobal;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bStruct = false;						//var bool bStruct;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				int32 ArrayDim = 0;						//var int ArrayDim;
};

USTRUCT(BlueprintType)
struct FPlayerAdminAccounts
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "PlayerAdminAccounts")		FString sPlayerName = "";				//var string sPlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerAdminAccounts")		FString sPassword = "";					//var string sPassword;
};

USTRUCT(BlueprintType)
struct FBanDescription
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "BanDescription")			EBanType BanType = EBanType::BanType_PlayerName;					//var EBanType BanType;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			int32 BanEndDate_LoWord = 0;			//var int BanEndDate_LoWord;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			int32 BanEndDate_HiWord = 0;			//var int BanEndDate_HiWord;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			FString Banee = "";						//var string Banee;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			FString OriginalUserName = "";			//var string OriginalUserName;
};


USTRUCT(BlueprintType)
struct FGameRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString ClassName = "";					//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString GameName = "";					//var string GameName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString Description = "";				//var string Description;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString TextName = "";					//var string TextName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString GameAcronym = "";				//var string GameAcronym;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString MapListClassName = "";			//var string MapListClassName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString MapPrefix = "";					//var string MapPrefix;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString ScreenshotRef = "";				//var string ScreenshotRef;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString HUDMenu = "";					//var string HUDMenu;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString RulesMenu = "";					//var string RulesMenu;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				bool bTeamGame = false;						//var bool bTeamGame;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				uint8 GameTypeGroup = 0;				//var byte GameTypeGroup;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				int32 RecordIndex = 0;					//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FMutatorRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString ClassName = "";					//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString FriendlyName = "";				//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString Description = "";				//var string Description;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString IconMaterialName = "";			//var string IconMaterialName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString ConfigMenuClassName = "";		//var string ConfigMenuClassName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString GroupName = "";					//var string GroupName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				int32 RecordIndex = 0;					//var int RecordIndex;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				uint8 bActivated = 0;					//var byte bActivated;
};

USTRUCT(BlueprintType)
struct FMapRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString Acronym = "";						//var string Acronym;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString MapName = "";						//var string MapName;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString TextName = "";						//var string TextName;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString FriendlyName = "";					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString Author = "";							//var string Author;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					float Description = 0;						//var string Description;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					int32 PlayerCountMin = 0;					//var int PlayerCountMin;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					int32 PlayerCountMax = 0;					//var int PlayerCountMax;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString ScreenshotRef = "";					//var string ScreenshotRef;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString ExtraInfo = "";						//var string ExtraInfo;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					int32 RecordIndex = 0;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FWeaponRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString ClassName = "";						//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString PickupClassName = "";				//var string PickupClassName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString AttachmentClassName = "";			//var string AttachmentClassName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString Description = "";					//var string Description;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString TextName = "";						//var string TextName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString FriendlyName = "";					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				int32 RecordIndex = 0;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FVehicleRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				FString ClassName = "";						//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				FString FriendlyName = "";					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				FString Description = "";					//var string Description;
	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				int32 RecordIndex = 0;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FCrosshairRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "CrosshairRecord")			FString FriendlyName = "";					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "CrosshairRecord")			UTexture* CrosshairTexture = nullptr;				//var Texture CrosshairTexture;
	UPROPERTY(EditAnywhere, Category = "CrosshairRecord")			int32 RecordIndex = 0;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FAnnouncerRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString ClassName = "";						//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString FriendlyName = "";					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString PackageName = "";					//var string PackageName;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString FallbackPackage = "";				//var string FallbackPackage;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			bool bEnglishOnly = false;						//var bool bEnglishOnly;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			int32 RecordIndex = 0;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FStandard
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Standard")					TArray<FString> Classes = {};					//	var TArray<FString> Classes;
	UPROPERTY(EditAnywhere, Category = "Standard")					TArray<FString> Maps = {};						//var TArray<FString> Maps;
};

USTRUCT(BlueprintType)
struct FTestOffset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "TestOffset")				float H = 0;						//var float H;
	UPROPERTY(EditAnywhere, Category = "TestOffset")				float V = 0;						//var float V;

};

USTRUCT(BlueprintType)
struct FNPCPSAnimSequenceSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				FName animStart = "";						//var name animStart;
	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				FName animMiddle = "";						//var name animMiddle;
	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				FName AnimEnd = "";							//var name AnimEnd;
	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				bool bShoulderWeaponFirst = false;				//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FNPCPSAttachObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				AActor* Attachment = nullptr;				//var class<Actor>  Attachment;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				FName Bone = "";						//var name Bone;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				FVector LocationOffset = FVector(0, 0, 0);			//var var FVector LocationOffset;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				FRotator RotationOffset = FRotator(0, 0, 0);		//var Object.Rotator RotationOffset;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				bool bUseParentScale = false;			//var bool bUseParentScale;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				float Scale = 0;					//var float Scale;
};

USTRUCT(BlueprintType)
struct FSoundEmitter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				float EmitInterval = 0;						//var float EmitInterval;
	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				float EmitVariance = 0;						//var float EmitVariance;
	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				float EmitTime = 0;							//var float EmitTime;
	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				USoundBase* EmitSound = nullptr;					//var Sound EmitSound;
};

USTRUCT(BlueprintType)
struct FTournamentPlayerStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				FString	sTeamName		= "";			//var string sTeamName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				FString sPlayerName		= "";			//var string sPlayerName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iTeamIndex		= 0;			//var int iTeamIndex;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iKills			= 0;			//var int iKills;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iDeaths			= 0;			//var int iDeaths;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iGoalPoints		= 0;			//var int iGoalPoints;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iLeaderPoints	= 0;			//var int iLeaderPoints;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iTotalScore		= 0;			//var int iTotalScore;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iROE			= 0;			//var int iROE;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32	iRoundsPlayed	= 0;			//var int iRoundsPlayed;
};

USTRUCT(BlueprintType)
struct FTournamentTeamResults
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")			FString		sTeamName		= "";		//var string sTeamName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")			int32		iTotalScore		= 0;		//var int iTotalScore;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")			int32		iTotalWins		= 0;		//var int iTotalWins;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")			int32		iTotalLosses	= 0;		//var int iTotalLosses;
};

USTRUCT(BlueprintType)
struct FESSObjectiveSet
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectiveSet")					TArray<AAGP_Objective*> aagpobjs = {};			//var array<AGP_Objective> aagpobjs;
};

USTRUCT(BlueprintType)
struct FMissionStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		Title			= "";			//var string Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		MBSTitle		= "";			//var string MBSTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		Image			= "";			//var string Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		Disabled		= "";			//var string Disabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		ImageDisabled	= "";			//var string ImageDisabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		MapFilename		= "";			//var string MapFilename;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		bool		bFileExists		= false;		//var bool bFileExists;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		int32		Status			= 0;			//var int Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")		FString		NMLFilename		= "";			//var int NMLFilename;
};

USTRUCT(BlueprintType)
struct FTourStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					Tour = "";					//var string Tour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		int32					Dependency = 0;				//var int Dependency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					Image = "";					//var string Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					TourText = "";				//var string TourText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					TourTextTitle = "";			//var string TourTextTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					TourRolloverText = "";		//var string TourRolloverText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					HistoryText = "";			//var string HistoryText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		FString					HistoryTextTitle = "";		//var string HistoryTextTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		bool					IsSequential = false;		//var bool IsSequential;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		bool					IsTraining = false;			//var bool IsTraining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		int32					iNumMissions = 0;			//var int iNumMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		int32					Status = 0;					//var int Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")		TArray<FMissionStruct>	Mission= {};				//var array<MissionStruct> Mission;
};

USTRUCT(BlueprintType)
struct FRotationRandomizer
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		FVector MeanDirection = FVector(0, 0, 0);				//var FVector MeanDirection;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		uint8  bPitch = 0;						//var byte bPitch;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float PitchMean = 0;					//var float PitchMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float PitchMaxDeviation = 0;			//var float PitchMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float PitchFalloff = 0;					//var float PitchFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		uint8 bYaw = 0;							//var byte bYaw;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float YawMean = 0;						//var float YawMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float YawMaxDeviation = 0;				//var float YawMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float YawFalloff = 0;					//var float YawFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		uint8 bRoll = 0;						//var byte bRoll;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float RollMean = 0;						//var float RollMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float RollMaxDeviation = 0;				//var float RollMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float RollFalloff = 0;					//var float RollFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float SpeedMean = 0;					//var float SpeedMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float SpeedMaxDeviation = 0;			//var float SpeedMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float SpeedFalloff = 0;					//var float SpeedFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		FRotator Base= FRotator(0,0,0);			//var Rotator Base;
};

USTRUCT(BlueprintType)
struct FLaserDotInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "LaserDotInfo")			float  LaserDotIntensity = 0;			//var float LaserDotIntensity;
	UPROPERTY(BlueprintReadWrite, Category = "LaserDotInfo")			float  LaserDotTimeStarted = 0;			//var float LaserDotTimeStarted;
	UPROPERTY(BlueprintReadWrite, Category = "LaserDotInfo")			uint8  LaserDot = 0;					//var LaserProjector LaserDot;
};

USTRUCT(BlueprintType)
struct FEnemySpottedData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		FVector  SpottedLocation = FVector(0, 0, 0);	//var FVector SpottedLocation;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  TimeSpottedSeconds = 0;					//var float TimeSpottedSeconds;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  LifeSpan = 0;							//var float LifeSpan;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  BlinkStartTime = 0;						//var float BlinkStartTime;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  BlinkEndTime = 0;						//var float BlinkEndTime;
};
USTRUCT(BlueprintType)
struct FESSObjectData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		FVector  SpottedLocation = FVector(0,0,0);	//var FVector SpottedLocation;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  TimeSpottedSeconds = 0;				//var float TimeSpottedSeconds;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  LifeSpan = 0;						//var float LifeSpan;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  BlinkStartTime = 0;					//var float BlinkStartTime;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  BlinkEndTime = 0;					//var float BlinkEndTime;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		bool  bLethal = 0;							//var bool bLethal;
};

USTRUCT(BlueprintType)
struct FBoneInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		int32 HitBone = 0;									//var int HitBone;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		FString Name = "";									//var string Name;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		float DamageModifier = 0;							//var float DamageModifier;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		float PenetrationDepth = 0;							//var float PenetrationDepth;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		EBoneRegion BoneRegion = EBoneRegion::BR_NONE;		//var Object.EBoneRegion BoneRegion;
};

USTRUCT(BlueprintType)
struct FBoneOffset
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "BoneOffset")		FVector VOffset = FVector(0,0,0);				//var FVector VOffset;
	UPROPERTY(BlueprintReadWrite, Category = "BoneOffset")		FRotator ROffset = FRotator(0, 0, 0);			//var Rotator ROffset;
	UPROPERTY(BlueprintReadWrite, Category = "BoneOffset")		FName nBone = "";								//var name nBone;
};

USTRUCT(BlueprintType)
struct FObjectRange
{
	GENERATED_BODY()
	UPROPERTY()		float Min = 0;
	UPROPERTY()		float Max = 0;
};
