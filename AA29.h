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
struct Fpointer
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, Category = "pointer")				int32 Dummy = 0;										//var native const int Dummy;
};

USTRUCT(BlueprintType)
struct FProjectorRenderInfoPtr
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ProjectorRenderInfoPtr")	Fpointer Ptr;					//var transient Fpointer Ptr;
};

USTRUCT(BlueprintType)
struct FVAEPosterViewingInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VAEPosterViewingInfo")		FString sPosterMaterial = "";		//var FString sPosterMaterial;
	UPROPERTY(EditAnywhere, Category = "VAEPosterViewingInfo")		float fpViewingTime = 0;			//var float fpViewingTime;
};

USTRUCT(BlueprintType)
struct FStoredChatBan
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "StoredChatBan")		FString PlayerHash = "";					//var FString PlayerHash;
	UPROPERTY(EditAnywhere, Category = "StoredChatBan")		uint8 Restriction = 0;						//var uint8 Restriction;
};

USTRUCT(BlueprintType)
struct FChatBan
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ChatBan")			int32 PlayerID = 0;							//var int32 PlayerID;
	UPROPERTY(EditAnywhere, Category = "ChatBan")			FString PlayerHash = "";						//var FString PlayerHash;
	UPROPERTY(EditAnywhere, Category = "ChatBan")			FString PlayerAddress = "";					//var FString PlayerAddress;
	UPROPERTY(EditAnywhere, Category = "ChatBan")			uint8 PlayerVoiceMask = 0;					//var uint8 PlayerVoiceMask;
	UPROPERTY(EditAnywhere, Category = "ChatBan")			uint8 Restriction = 0;						//var uint8 Restriction;
};

USTRUCT(BlueprintType)
struct FNPCObjectiveResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			int32 iReservePlatoonID = 0;						//var int32 iReservePlatoonID;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			int32 iReserveSquadID = 0;							//var int32 iReserveSquadID;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			int32 iReserveFireteamID = 0;						//var int32 iReserveFireteamID;
	// UPROPERTY(EditAnywhere, Category = "NPCTracking")			ENPCReserveObjectiveCommand enpcrocNPCCommand;	//var NPCObjectiveResponse.ENPCReserveObjectiveCommand enpcrocNPCCommand;
};

USTRUCT(BlueprintType)
struct FVoiceChatCodec
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			FString Codec = "";					//var FString Codec;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			FString CodecName = "";				//var localized FString CodecName;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			FString CodecDescription = "";		//var localized FString CodecDescription;
};

USTRUCT(BlueprintType)
struct FNPCTracking
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			APawn* pawnSeen = nullptr;			//var Pawn pawnSeen;
	UPROPERTY(EditAnywhere, Category = "NPCTracking")			float fpTimeSeen = 0;				//var float fpTimeSeen;
};

USTRUCT(BlueprintType)
struct FFireMissionRequests
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			FVector		vLocation = FVector(0,0,0);		//var FVector vLocation;
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			APawn*		pawnTarget = nullptr;			//var APawn* pawnTarget;
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			float		fpTime = 0;						//var float fpTime;
	UPROPERTY(EditAnywhere, Category = "FireMissionRequests")			bool		bMissionFiring = false;			//var bool bMissionFiring;
};

USTRUCT(BlueprintType)
struct FIntBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			X1 = 0;			//var int32 X1;
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			Y1 = 0;			//var int32 Y1;
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			X2 = 0;			//var int32 X2;
	UPROPERTY(EditAnywhere, Category = "IntBox")			int32			Y2 = 0;			//var int32 Y2;
};

USTRUCT(BlueprintType)
struct FConsoleMessage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		FString				Text = "";						//var FString Text;
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		FColor				TextColor = FColor(0,0,0);		//var Color TextColor;
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		float				MessageLife = 0;				//var float MessageLife;
	UPROPERTY(EditAnywhere, Category = "ConsoleMessage")		AAA2_PlayerState*	PRI = nullptr;					//var PlayerReplicationInfo PRI;
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
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			ULocalMessage*		Message = nullptr;						//var class<LocalMessage>  Message;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			FString				StringMessage = "";						//var FString StringMessage;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			int32				Switch = 0;								//var int32 Switch;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			AAA2_PlayerState*	RelatedPRI = nullptr;					//var PlayerReplicationInfo RelatedPRI;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			AAA2_PlayerState*	RelatedPRI2 = nullptr;					//var PlayerReplicationInfo RelatedPRI2;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			UObject*			OptionalObject = nullptr;				//var Object OptionalObject;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				EndOfLife = 0;							//var float EndOfLife;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				Lifetime = 0;							//var float Lifetime;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			UFont*				StringFont = nullptr;					//var Font StringFont;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			FColor				DrawColor = FColor(0,0,0);				//var Color DrawColor;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			EDrawPivot			DrawPivot = EDrawPivot::DP_UpperLeft;	//var Object.EDrawPivot DrawPivot;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			EStackMode			StackMode = EStackMode::SM_None;		//var LocalMessage.EStackMode StackMode;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				PosX = 0;								//var float PosX;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				PosY = 0;								//var float PosY;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				dx = 0;									//var float dx;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			float				dy = 0;									//var float dy;
	UPROPERTY(EditAnywhere, Category = "HudLocalizedMessage")			bool				Drawn = false;							//var bool Drawn;
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
	UPROPERTY(EditAnywhere, Category = "NPCPlatoons")			FNPCSquadDetails		anpcsdSquads;			//var NPCSquadDetails anpcsdSquads[8];
	UPROPERTY(EditAnywhere, Category = "NPCPlatoons")			FString					sPlatoonName;			//var FString sPlatoonName;
};

USTRUCT(BlueprintType)
struct FEnemyContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			ANPCBaseController*		npcbcReporting;			//var NPCBaseController npcbcReporting;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			APawn*					pawnEnemyContact;		//var APawn* pawnEnemyContact;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			int32					iContactType;			//var int32 iContactType;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			FVector					vLocation = FVector(0, 0, 0);				//var FVector vLocation;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			FRotator				rotRotation = FRotator(0, 0, 0);			//var Rotator rotRotation;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			float					fpEstimatedRange;		//var float fpEstimatedRange;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			int32					iThreatLevel;			//var int32 iThreatLevel;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			float					fpTimeOfReport;			//var float fpTimeOfReport;
	UPROPERTY(EditAnywhere, Category = "EnemyContact")			bool					bContactLost;			//var bool bContactLost;
};

USTRUCT(BlueprintType)
struct FOrderQueue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			ANPCBaseController*		npcbc;					//var NPCBaseController npcbc;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			int32					iSupportRequest;		//var int32 iSupportRequest;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			bool					bOrderForAll;			//var bool bOrderForAll;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			FString					sAICCCombatAction;		//var FString sAICCCombatAction;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			int32					iOrder;					//var int32 iOrder;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			int32					iTacticalOrder;			//var int32 iTacticalOrder;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			float					fpTimeToDeliver;		//var float fpTimeToDeliver;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			FVector					vSupportArea = FVector(0, 0, 0);			//var FVector vSupportArea;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			APawn*					pawnTarget;				//var APawn* pawnTarget;
	UPROPERTY(EditAnywhere, Category = "OrderQueue")			bool					bSmokeMission;			//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FFireMissionInFlight
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			FVector				vTargetArea = FVector(0, 0, 0);			//var FVector vTargetArea;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			float				fpSpawnTime;			//var float fpSpawnTime;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			float				fpSkill;				//var float fpSkill;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			APawn*				pawnSpotter;			//var APawn* pawnSpotter;
	UPROPERTY(EditAnywhere, Category = "FireMissionInFlight")			bool				bSmokeMission;			//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FSupportFireRequestQueue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			ANPCBaseSoldierController*	npcbscSpotter;			//var NPCBaseSoldierController npcbscSpotter;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			float						fpSkillLevel;			//var float fpSkillLevel;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			int32						iSupportType;			//var int32 iSupportType;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			int32						iRoundsToFire;			//var int32 iRoundsToFire;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			float						fpTimeToFire;			//var float fpTimeToFire;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			float						fpTimeToSpawn;			//var float fpTimeToSpawn;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			FVector						vTargetArea = FVector(0, 0, 0);			//var FVector vTargetArea;
	UPROPERTY(EditAnywhere, Category = "SupportFireRequestQueue")			bool						bSmokeMission;			//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FMortarRangeTable
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpMin;				//var float fpMin;
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpMax;				//var float fpMax;
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpFlightTime;		//var float fpFlightTime;
	UPROPERTY(EditAnywhere, Category = "MortarRangeTable")			float				fpAngle;			//var float fpAngle;
};

USTRUCT(BlueprintType)
struct FReinforcementRespawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ReinforcementRespawn")			ASmallNavigationPoint*		snpStart;				//var SmallNavigationPoint snpStart;
	UPROPERTY(EditAnywhere, Category = "ReinforcementRespawn")			int32						iRespawnsLeft;			//var int32 iRespawnsLeft;
};


USTRUCT(BlueprintType)
struct FLensFlareDescriptor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			UMaterialInstance*	LensFlareMaterial;		//var Material LensFlareMaterial;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			FColor				LensFlareColor;			//var Color LensFlareColor;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			float				LensFlareOffset;		//var float LensFlareOffset;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			float				LensFlareRadius_Min;	//var float LensFlareRadius_Min;
	UPROPERTY(EditAnywhere, Category = "LensFlareDescriptor")			float				LensFlareRadius_Max;	//var float LensFlareRadius_Max;
};

USTRUCT(BlueprintType)
struct FAA2_ProcMeshVertex
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				FVector				Position = FVector(0, 0, 0);		//var FVector Position;
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				FVector				Normal = FVector(0, 0, 0);			//var FVector Normal;
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				FColor				Color;			//var Color Color;
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				float				U;				//var float U;
	UPROPERTY(EditAnywhere, Category = "ProcMeshVertex")				float				V;				//var float V;
};


USTRUCT(BlueprintType)
struct FConvSpeech
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					FString				sMemberName;			//var FString sMemberName;
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					FName				nameLipSynchAudio;		//var FName nameLipSynchAudio;
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					FName				nameAnimation;			//var FName nameAnimation;
	UPROPERTY(EditAnywhere, Category = "ConvSpeech")					USoundBase*			sndNonLSAudio;			//var Sound sndNonLSAudio;
};

USTRUCT(BlueprintType)
struct FAnimInfo2
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireProperties")					FName				SeqName;			//var FName SeqName;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					float				AnimFrame;			//var float AnimFrame;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					float				AnimRate;			//var float AnimRate;
};


USTRUCT(BlueprintType)
struct FFireProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FireProperties")					AAmmunition*		AmmoClass;				//var class<Ammunition>  AmmoClass;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					AProjectile*		ProjectileClass;		//var class<Projectile>  ProjectileClass;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					float				WarnTargetPct;			//var float WarnTargetPct;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					float				MaxRange;				//var float MaxRange;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					bool				bTossed;				//var bool bTossed;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					bool				bTrySplash;				//var bool bTrySplash;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					bool				bLeadTarget;			//var bool bLeadTarget;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					bool				bInstantHit;			//var bool bInstantHit;
	UPROPERTY(EditAnywhere, Category = "FireProperties")					bool				bInitialized;			//var bool bInitialized;
};

USTRUCT(BlueprintType)
struct FAnimInstruction
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")					EeAnimationCommand	Command;			//var eAnimationCommand Command;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")					FName				Sequence;			//var FName Sequence;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")					float				Rate;				//var float Rate;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")					float				Time;				//var float Time;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")					int32				Channel;			//var int32 Channel;
	UPROPERTY(EditAnywhere, Category = "AnimInstruction")					int32				LoopNum;			//var int32 LoopNum;
};


USTRUCT(BlueprintType)
struct FArrayControl
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KRBVec")					UGUIButton* b_New;				//var XInterface.GUIButton b_New;
	UPROPERTY(EditAnywhere, Category = "KRBVec")					UGUIButton* b_Remove;			//var XInterface.GUIButton b_Remove;
};
USTRUCT(BlueprintType)
struct FKRBVec
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KRBVec")					float X;						//var float X;
	UPROPERTY(EditAnywhere, Category = "KRBVec")					float Y;						//var float Y;
	UPROPERTY(EditAnywhere, Category = "KRBVec")					float Z;						//var float Z;
};


USTRUCT(BlueprintType)
struct FUAVState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "UAVState")					FKRBVec ChassisPosition;				//var Actor.KRBVec ChassisPosition;
	UPROPERTY(EditAnywhere, Category = "UAVState")					FQuat ChassisQuaternion;				//var Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, Category = "UAVState")					FKRBVec ChassisLinVel;					//var Actor.KRBVec ChassisLinVel;
	UPROPERTY(EditAnywhere, Category = "UAVState")					FKRBVec ChassisAngVel;					//var Actor.KRBVec ChassisAngVel;
	UPROPERTY(EditAnywhere, Category = "UAVState")					float ServerThrust;						//var float ServerThrust;
	UPROPERTY(EditAnywhere, Category = "UAVState")					float ServerStrafe;						//var float ServerStrafe;
	UPROPERTY(EditAnywhere, Category = "UAVState")					float ServerRise;						//var float ServerRise;
	UPROPERTY(EditAnywhere, Category = "UAVState")					int32 bNewState;						//var int32 bNewState;
};

USTRUCT(BlueprintType)
struct FHelicopterState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FKRBVec ChassisPosition;		//var Actor.KRBVec ChassisPosition;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FQuat ChassisQuaternion;		//var Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FKRBVec ChassisLinVel;			//var Actor.KRBVec ChassisLinVel;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			FKRBVec ChassisAngVel;			//var Actor.KRBVec ChassisAngVel;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			float ServerThrust;				//var float ServerThrust;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			float ServerStrafe;				//var float ServerStrafe;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			float ServerRise;				//var float ServerRise;
	UPROPERTY(EditAnywhere, Category = "HelicopterState")			int32 bNewState;				//var int32 bNewState;
};

USTRUCT(BlueprintType)
struct FCoords
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector Origin = FVector(0, 0, 0);						//var config FVector Origin;
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector XAxis = FVector(0, 0, 0);						//var config FVector XAxis;
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector YAxis = FVector(0, 0, 0);						//var config FVector YAxis;
	UPROPERTY(EditAnywhere, Category = "Coords")					FVector ZAxis = FVector(0, 0, 0);						//var config FVector ZAxis;
};

USTRUCT(BlueprintType)
struct FEffectMatProps
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EffectMatProps")					bool bNoEffect;							//var bool bNoEffect;
	UPROPERTY(EditAnywhere, Category = "EffectMatProps")					FColor DirtColor;						//var Color DirtColor;
	UPROPERTY(EditAnywhere, Category = "EffectMatProps")					float DirtAmount;						//var float DirtAmount;
};

USTRUCT(BlueprintType)
struct FRange
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Range")								float Min;								//var float Min;
	UPROPERTY(EditAnywhere, Category = "Range")								float Max;								//var float Max;
};

USTRUCT(BlueprintType)
struct FParticleAnchor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")						FName Tag;							//var FName Tag;
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")						float Position;						//var float Position;
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")						AActor* Actor;						//var AActor* Actor;
	UPROPERTY(EditAnywhere, Category = "ParticleAnchor")						int32 Index = 0;						//var int32 Index;
};

USTRUCT(BlueprintType)
struct FAttachedPawnInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")						float Index;						//var float Index;
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")						float nextUpateTime;				//var float nextUpateTime;
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")						float updateTime;					//var float updateTime;
	UPROPERTY(EditAnywhere, Category = "AttachedPawnInfo")						float percent;						//var float percent;
};

USTRUCT(BlueprintType)
struct FRangeVector
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RangeVector")						FRange X;							//var Range X;
	UPROPERTY(EditAnywhere, Category = "RangeVector")						FRange Y;							//var Range Y;
	UPROPERTY(EditAnywhere, Category = "RangeVector")						FRange Z;							//var Range Z;
};

USTRUCT(BlueprintType)
struct FParticleBeamData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleBeamData")					FVector Location = FVector(0, 0, 0);					//var FVector Location;
	UPROPERTY(EditAnywhere, Category = "ParticleBeamData")					float t;							//var float t;
};

USTRUCT(BlueprintType)
struct FParticleBeamEndPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleBeamEndPoint")				FName ActorTag;						//var FName ActorTag;
	UPROPERTY(EditAnywhere, Category = "ParticleBeamEndPoint")				FRangeVector offset;				//var RangeVector offset;
	UPROPERTY(EditAnywhere, Category = "ParticleBeamEndPoint")				float Weight;						//var float Weight;
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
	UPROPERTY(EditAnywhere, Category = "Range")								FColor Color;								//var Color Color;
	UPROPERTY(EditAnywhere, Category = "Range")								float Size;									//var float Size;
	UPROPERTY(EditAnywhere, Category = "Range")								int32 DoubleDummy1;							//var int32 DoubleDummy1;
	UPROPERTY(EditAnywhere, Category = "Range")								int32 DoubleDummy2;							//var int32 DoubleDummy2;
};

USTRUCT(BlueprintType)
struct FParticleTrailInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Range")								int32 TrailIndex;							//var int32 TrailIndex;
	UPROPERTY(EditAnywhere, Category = "Range")								int32 NumPoints;							//var int32 NumPoints;
	UPROPERTY(EditAnywhere, Category = "Range")								FVector LastLocation = FVector(0, 0, 0);						//var FVector LastLocation;
	UPROPERTY(EditAnywhere, Category = "Range")								FVector LastEmitterLocation = FVector(0, 0, 0);				//var FVector LastEmitterLocation;
};

USTRUCT(BlueprintType)
struct FParticleTimeScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleTimeScale")					float RelativeTime;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleTimeScale")					float RelativeSize;							//var float RelativeSize;
};

USTRUCT(BlueprintType)
struct FParticleRevolutionScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleRevolutionScale")			float RelativeTime;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleRevolutionScale")			FVector RelativeRevolution = FVector(0, 0, 0);					//var FVector RelativeRevolution;
};

USTRUCT(BlueprintType)
struct FParticleColorScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleColorScale")					float RelativeTime;						//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleColorScale")					FColor Color;							//var Color Color;
};

USTRUCT(BlueprintType)
struct FParticleVelocityScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleVelocityScale")					float RelativeTime;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, Category = "ParticleVelocityScale")					FVector RelativeVelocity = FVector(0, 0, 0);						//var FVector RelativeVelocity;
};

USTRUCT(BlueprintType)
struct FParticle
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector Location = FVector(0, 0, 0);						//var FVector Location;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector OldLocation = FVector(0, 0, 0);					//var FVector OldLocation;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector Velocity = FVector(0, 0, 0);						//var FVector Velocity;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector StartSize = FVector(0, 0, 0);						//var FVector StartSize;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector SpinsPerSecond = FVector(0, 0, 0);					//var FVector SpinsPerSecond;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector StartSpin = FVector(0, 0, 0);						//var FVector StartSpin;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector RevolutionCenter = FVector(0, 0, 0);				//var FVector RevolutionCenter;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector RevolutionsPerSecond = FVector(0, 0, 0);			//var FVector RevolutionsPerSecond;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector RevolutionsMultiplier = FVector(0, 0, 0);			//var FVector RevolutionsMultiplier;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector Size = FVector(0, 0, 0);							//var FVector Size;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector StartLocation = FVector(0, 0, 0);					//var FVector StartLocation;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector ColorMultiplier = FVector(0, 0, 0);				//var FVector ColorMultiplier;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector VelocityMultiplier = FVector(0, 0, 0);				//var FVector VelocityMultiplier;
	UPROPERTY(EditAnywhere, Category = "Particle")					FVector OldMeshLocation = FVector(0, 0, 0);				//var FVector OldMeshLocation;
	UPROPERTY(EditAnywhere, Category = "Particle")					FColor Color;							//var Color Color;
	UPROPERTY(EditAnywhere, Category = "Particle")					float Time;								//var float Time;
	UPROPERTY(EditAnywhere, Category = "Particle")					float MaxLifetime;						//var float MaxLifetime;
	UPROPERTY(EditAnywhere, Category = "Particle")					float Mass;								//var float Mass;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32 HitCount;							//var int32 HitCount;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32 Flags;							//var int32 Flags;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32 Subdivision;						//var int32 Subdivision;
	UPROPERTY(EditAnywhere, Category = "Particle")					int32 BoneIndex;						//var int32 BoneIndex;
	UPROPERTY(EditAnywhere, Category = "Particle")					uint8 NumFramesRendered;				//var uint8 NumFramesRendered;
	UPROPERTY(EditAnywhere, Category = "Particle")					float FadeTime;							//var float FadeTime;
};

USTRUCT(BlueprintType)
struct FParticleSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					USoundBase* Sound;						//var Sound Sound;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Radius;							//var Range Radius;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Pitch;							//var Range Pitch;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					int32 Weight;							//var int32 Weight;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Volume;							//var Range Volume;
	UPROPERTY(EditAnywhere, Category = "ParticleSound")					FRange Probability;						//var Range Probability;
};

USTRUCT(BlueprintType)
struct FGameSpyPlayerInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Honor;							//var int Honor;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					FString Name;							//var string Name;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Score_Total;						//var int Score_Total;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Enemy;							//var int Enemy;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 KIA;								//var int KIA;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 ROE;								//var int ROE;
	UPROPERTY(EditAnywhere, Category = "GameSpyPlayerInfo")					int32 Ping;								//var int Ping;
};

USTRUCT(BlueprintType)
struct FOutstandingPing
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				int32							IP;					//var int32 IP;
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				int32							Port;				//var int32 Port;
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				float							TimeOfLastPing;		//var float TimeOfLastPing;
	UPROPERTY(BlueprintReadWrite, Category = "OutstandingPing")				AMBSPingServerRequestAdapter*	Request;			//var MBSPingServerRequestAdapter Request;
};

USTRUCT(BlueprintType)
struct FPlayerList
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayerList")					TArray<FGameSpyPlayerInfo>		players;			//var TArray<ServerBrowserBase.GameSpyPlayerInfo> players;
};


USTRUCT(BlueprintType)
struct FPlayListStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				bool				bRepeat;			//var config bool bRepeat;
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				bool				bShuffle;			//var config bool bShuffle;
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				FString				Current;			//var config FString Current;
	UPROPERTY(BlueprintReadWrite, Category = "PlayListStruct")				TArray<FString>		Songs;				//var config TArray<FString> Songs;
};


USTRUCT(BlueprintType)
struct FStoredPassword
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "StoredPassword")				FString				Server;			//var config FString Server;
	UPROPERTY(BlueprintReadWrite, Category = "StoredPassword")				FString				Password;		//var config FString Password;
};

USTRUCT(BlueprintType)
struct FServerFavorite
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				int32				ServerID;		//var config int32 ServerID;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				FString				IP;				//var config FString IP;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				int32				Port;			//var config int32 Port;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				int32				QueryPort;		//var config int32 QueryPort;
	UPROPERTY(BlueprintReadWrite, Category = "ServerFavorite")				FString				ServerName;		//var config FString ServerName;
};


USTRUCT(BlueprintType)
struct FChatStruct
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ChatStruct")				FString				Message;		//var FString Message;
	UPROPERTY(BlueprintReadWrite, Category = "ChatStruct")				int32				Team;			//var int32 Team;
};


USTRUCT(BlueprintType)
struct FInputKeyInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "InputKeyInfo")				int32				KeyNumber;			//var int32 KeyNumber;
	UPROPERTY(BlueprintReadWrite, Category = "InputKeyInfo")				FString				KeyName;			//var FString KeyName;
	UPROPERTY(BlueprintReadWrite, Category = "InputKeyInfo")				FString				LocalizedKeyName;	//var FString LocalizedKeyName;
};

USTRUCT(BlueprintType)
struct FKeyBindMenyKeyBinding
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				bool				bIsSectionLabel;		//var bool bIsSectionLabel;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString				KeyLabel;				//var FString KeyLabel;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString				Alias;					//var FString Alias;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<int32>		BoundKeys;				//var TArray<int32> BoundKeys;
};

USTRUCT(BlueprintType)
struct FRibbon
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "Ribbon")				FString				RibbonName;			//var FString RibbonName;
	UPROPERTY(BlueprintReadWrite, Category = "Ribbon")				FString				RibbonDescription;	//var FString RibbonDescription;
	UPROPERTY(BlueprintReadWrite, Category = "Ribbon")				UMaterialInstance*	RibbonImage;		//var Material RibbonImage;
};

USTRUCT(BlueprintType)
struct FDisplayMode
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "DisplayMode")				int32			Width;		//var int32 Width;
	UPROPERTY(BlueprintReadWrite, Category = "DisplayMode")				int32			Height;		//var int32 Height;
};


USTRUCT(BlueprintType)
struct FKeyBinding
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				bool			bIsSectionLabel;		//var bool bIsSectionLabel;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString			KeyLabel;				//var localized FString KeyLabel;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				FString			Alias;					//var FString Alias;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<int32>	Binds;					//var TArray<int32> Binds;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<FString>	BindKeyNames;			//var TArray<FString> BindKeyNames;
	UPROPERTY(BlueprintReadWrite, Category = "KeyBinding")				TArray<FString>	BindLocalizedKeyNames;	//var TArray<FString> BindLocalizedKeyNames;
};

USTRUCT(BlueprintType)
struct FFavoritesServerInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")				int32 ServerID;				//var config int32 ServerID;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")				int32 IP;					//var config FString IP;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")				int32 Port;					//var config int32 Port;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")				int32 QueryPort;			//var config int32 QueryPort;
	UPROPERTY(BlueprintReadWrite, Category = "FavoritesServerInfo")				int32 ServerName;			//var config FString ServerName;
};

USTRUCT(BlueprintType)
struct FDCDSImageInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						UMaterialInstance* Image;					//var Texture Image;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString HttpLink;							//var FString HttpLink;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Caption;							//var FString Caption;
};

USTRUCT(BlueprintType)
struct FHaltedDownloadInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString AssetName;							//var FString AssetName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						int32 Length;								//var int32 Length;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						int32 RemainingLength;						//var int32 RemainingLength;
};

USTRUCT(BlueprintType)
struct FAssetFileInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString FullName = "";				//var FString FullName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Name = "";					//var FString Name;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Path = "";					//var FString Path;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						int32 FileLength = 0;				//var int32 FileLength;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString SHA = "";					//var FString SHA;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Date = "";					//var FString Date;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						int32 bShouldRemove = 0;			//var int32 bShouldRemove;
};

USTRUCT(BlueprintType)
struct FAA2_AssetMapping
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")			FString AssetName = "";				//var FString AssetName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")			FString AssetFileName = "";			//var FString AssetFileName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")			FString AssetTitle = "";			//var FString AssetTitle;
};

USTRUCT(BlueprintType)
struct FKeyValuePair
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyValuePair")			FString Key = "";					//var string Key;
	UPROPERTY(BlueprintReadWrite, Category = "KeyValuePair")			FString Value = "";					//var string Value;
};

USTRUCT(BlueprintType)
struct FPlayerResponseLine
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32 PlayerNum = 0;				//var int PlayerNum;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		FString PlayerName = "";			//var string PlayerName;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32 Ping = 0;						//var int Ping;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32 Score = 0;					//var int Score;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")		int32 StatsID = 0;					//var int StatsID;
};



USTRUCT(BlueprintType)
struct FServerResponseLine
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 ServerID = 0;								//var int ServerID;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString IP = "";								//var string IP;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 Port = 0;									//var int Port;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 QueryPort = 0;							//var int QueryPort;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString ServerName = "";						//var string ServerName;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString MapName = "";							//var string MapName;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString GameType = "";							//var string GameType;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 CurrentPlayers = 0;						//var int CurrentPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 MaxPlayers = 0;							//var int MaxPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 Ping = 0;									//var int Ping;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		int32 Flags = 0;								//var int Flags;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		FString SkillLevel = "";						//var string SkillLevel;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		TArray<FKeyValuePair>  ServerInfo = {};			//var array<KeyValuePair> ServerInfo;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")		TArray<FPlayerResponseLine> PlayerInfo ={};		//var array<PlayerResponseLine> PlayerInfo;
};

USTRUCT(BlueprintType)
struct FHeaderColumnPos
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HeaderColumnPos")		TArray<float> ColumnSizes ={};		//var TArray<float> ColumnSizes;
};

USTRUCT(BlueprintType)
struct FeServerCacheInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FeServerCacheInfo")			FString GameType = "";				//var FString GameType;
	UPROPERTY(EditAnywhere, Category = "FeServerCacheInfo")			int32 SubnetIndex = 0;				//var int32 SubnetIndex;
	UPROPERTY(EditAnywhere, Category = "FeServerCacheInfo")			FServerResponseLine SRL;		//var GameInfo.ServerResponseLine SRL;
};


USTRUCT(BlueprintType)
struct FUAVFlightPlannerWaypoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlannerWaypoint")		FVector vLocation = FVector(0, 0, 0);			//var FVector vLocation;
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlannerWaypoint")		float fpHeight;				//var float fpHeight;
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlannerWaypoint")		float fpSpeed;				//var float fpSpeed;
};


USTRUCT(BlueprintType)
struct FLayoutItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LayoutItem")		UGUIComponent* Component;				//var UGUIComponent* Component;
	UPROPERTY(EditAnywhere, Category = "LayoutItem")		EeCellAlign Alignment;					//var eCellAlign Alignment;
};

USTRUCT(BlueprintType)
struct FBadge
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Badge")		FString BadgeName;					//var string BadgeName;
	UPROPERTY(EditAnywhere, Category = "Badge")		FString BadgeDescription;			//var string BadgeDescription;
	UPROPERTY(EditAnywhere, Category = "Badge")		UMaterialInstance* BadgeImage;		//var Material BadgeImage;
	UPROPERTY(EditAnywhere, Category = "Badge")		FString MenuPath;					//var string MenuPath;
	UPROPERTY(EditAnywhere, Category = "Badge")		FString MenuParam1;					//var string MenuParam1;
	UPROPERTY(EditAnywhere, Category = "Badge")		FString MenuParam2;					//var string MenuParam2;
};

USTRUCT(BlueprintType)
struct FActiveFilter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ActiveFilter")		FString CategoryName;					//var string CategoryName;
	UPROPERTY(EditAnywhere, Category = "ActiveFilter")		FString FilterName;						//var string FilterName;
	UPROPERTY(EditAnywhere, Category = "ActiveFilter")		FString FilterChoiceLabel;				//var string FilterChoiceLabel;
};


USTRUCT(BlueprintType)
struct FActiveFilterSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ActiveFilterSet")		TArray<FActiveFilter> List;			//var array<ActiveFilter> List;
};

USTRUCT(BlueprintType)
struct FReport
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FReport")			int32 ListID;							//var int ListID;
	UPROPERTY(EditAnywhere, Category = "FReport")			FString Ping;							//var string Ping;
	UPROPERTY(EditAnywhere, Category = "FReport")			FString receive;						//var string receive;
};

USTRUCT(BlueprintType)
struct FFilterItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilterItem")		FString Key;							//var string Key;
	UPROPERTY(EditAnywhere, Category = "FilterItem")		FString Value;							//var string Value;
};

USTRUCT(BlueprintType)
struct FFilterChoice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilterChoice")		FString Label;							//var string Label;
	UPROPERTY(EditAnywhere, Category = "FilterChoice")		TArray<FFilterItem> DBMBSFilters;		//var array<ServerBrowserBase.FilterItem> DBMBSFilters;
	UPROPERTY(EditAnywhere, Category = "FilterChoice")		FString GameSpyFilter;					//var string GameSpyFilter;
};

USTRUCT(BlueprintType)
struct FFilterDesc
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		FString CategoryName;					//var string CategoryName;
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		FString FilterName;						//var string FilterName;
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		TArray<FFilterChoice> Choices;			//var array<FilterChoice> Choices;
	UPROPERTY(EditAnywhere, Category = "FilterDesc")		bool RuntimeChoiceGeneration;			//var bool RuntimeChoiceGeneration;
};

USTRUCT(BlueprintType)
struct FQueryData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QueryData")		FString Key;							//var string Key;
	UPROPERTY(EditAnywhere, Category = "QueryData")		FString Value;							//var string Value;
	UPROPERTY(EditAnywhere, Category = "QueryData")		EQueryType QueryType;					//var EQueryType QueryType;
};

USTRUCT(BlueprintType)
struct FAFilterRule
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AFilterRule")	FQueryData FilterItem;					//var MasterServerClient.QueryData FilterItem;
	UPROPERTY(EditAnywhere, Category = "AFilterRule")	EDataType FilterType;					//var EDataType FilterType;
	UPROPERTY(EditAnywhere, Category = "AFilterRule")	FString ItemName;						//var string ItemName;
};
USTRUCT(BlueprintType)
struct FCurrentFilter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CurrentFilter")	FAFilterRule Item;							//var CustomFilter.AFilterRule Item;
	UPROPERTY(EditAnywhere, Category = "CurrentFilter")	int32 ItemIndex;							//var int ItemIndex;
};

USTRUCT(BlueprintType)
struct FFavoriteServer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FavoriteServer")	FString IPAddress;							//var string IPAddress;
	UPROPERTY(EditAnywhere, Category = "FavoriteServer")	int32 Port;									//var int Port;
};

USTRUCT(BlueprintType)
struct FMultiColumnSortData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MultiColumnSortData")	FString SortString;						//var string SortString;
	UPROPERTY(EditAnywhere, Category = "MultiColumnSortData")	int32 SortItem;							//var int SortItem;
};


USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")			FString PlayerName;						//var string PlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")			FString PlayerID;						//var string PlayerID;
	UPROPERTY(EditAnywhere, Category = "PlayerInfo")			FString PlayerIP;						//var string PlayerIP;
};

USTRUCT(BlueprintType)
struct FSprite
{
	GENERATED_BODY()
	// UPROPERTY(EditAnywhere, Category = "Sprite")				ASpriteSlave* Sprite;					//var SpriteSlave Sprite;
	UPROPERTY(EditAnywhere, Category = "Sprite")				float MinFadeValue;						//var float MinFadeValue;
	UPROPERTY(EditAnywhere, Category = "Sprite")				float MaxFadeValue;						//var float MaxFadeValue;
};

USTRUCT(BlueprintType)
struct FVehicleWeaponAIInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool bTossed;							//var bool bTossed;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool bTrySplash;						//var bool bTrySplash;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool bLeadTarget;						//var bool bLeadTarget;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool bInstantHit;						//var bool bInstantHit;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				bool bFireOnRelease;					//var bool bFireOnRelease;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				float aimerror;							//var float aimerror;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				float WarnTargetPct;					//var float WarnTargetPct;
	UPROPERTY(EditAnywhere, Category = "VehicleWeaponAIInfo")				float RefireRate;						//var float RefireRate;
};

USTRUCT(BlueprintType)
struct FVehiclePositionStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			TSubclassOf <AVehiclePosition>	VehiclePositionClass = nullptr;			//var class<VehiclePosition>  VehiclePositionClass;
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FName							WeaponBone = "";						//var name WeaponBone;
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FName							PositionBone = "";						//var name PositionBone;
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FVector							FPCameraOffset = FVector(0, 0, 0);		//var Object.Vector FPCameraOffset;
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FVector							PosOffset = FVector(0, 0, 0);			//var Object.Vector PosOffset;
	UPROPERTY(EditAnywhere, Category = "VehiclePositionStruct")			FRotator						RotOffset = FRotator(0, 0, 0);			//var Object.Rotator RotOffset;
};

USTRUCT(BlueprintType)
struct FBodyPanelStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				TSubclassOf <ABodyPanel>	ClassType;					//var class<AGP.BodyPanel>  ClassType;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				UStaticMesh*				Mesh;						//var StaticMesh Mesh;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				FName AttachBone;						//var name AttachBone;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				FName EntryBone;						//var name EntryBone;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32 EntryRadius;						//var int EntryRadius;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32 EntryPosIndex;					//var int EntryPosIndex;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				FString ExteriorHintText;				//var string ExteriorHintText;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				UStaticMesh* DamagedMesh;				//var StaticMesh DamagedMesh;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32 bInvincible;						//var int bInvincible;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32 bAcceptsProjectileDamage;			//var int bAcceptsProjectileDamage;
	UPROPERTY(EditAnywhere, Category = "BodyPanelStruct")				int32 bDisableCollision;				//var int bDisableCollision;
};


USTRUCT(BlueprintType)
struct FDriverWeaponStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DriverWeaponStruct")				AVehicleWeapon* WeaponClass = nullptr;			//var class<VehicleWeapon>  WeaponClass;
	UPROPERTY(EditAnywhere, Category = "DriverWeaponStruct")				FName			WeaponBone = "";				//var name WeaponBone;
};


USTRUCT(BlueprintType)
struct FsDamageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				TSubclassOf < UaDamageType>			AcceptsDamage		= nullptr;				//var class<DamageType>  AcceptsDamage;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				TSubclassOf < AAGP_VehicleParticles>	DamageEffect		= nullptr;				//var class<AGP_Effects.AGP_VehicleParticles>  DamageEffect;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Front_Left		= 0;					//var float AM_Front_Left;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Front_Right		= 0;					//var float AM_Front_Right;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Back_Left		= 0;					//var float AM_Back_Left;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Back_Right		= 0;					//var float AM_Back_Right;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Undercarriage	= 0;					//var float AM_Undercarriage;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Turret			= 0;					//var float AM_Turret;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Roof				= 0;					//var float AM_Roof;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Tread_Left		= 0;					//var float AM_Tread_Left;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Tread_Right		= 0;					//var float AM_Tread_Right;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Wheels_Left		= 0;					//var float AM_Wheels_Left;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					AM_Wheels_Right		= 0;					//var float AM_Wheels_Right;
	UPROPERTY(EditAnywhere, Category = "sDamageInfo")				float					DamageEffectPct		= 0;					//var float DamageEffectPct;
};	

USTRUCT(BlueprintType)
struct FTestDamageZoneInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				FName	ZoneName						= "";		//var name ZoneName;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				uint8	ZoneNumber						= 0;		//var byte ZoneNumber;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				int32	ArmorThreshold					= 0;		//var int ArmorThreshold;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				int32	MaxHitPoints					= 0;		//var int MaxHitPoints;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				uint8	bInitialSyncToVehicleHealth		= 0;		//var byte bInitialSyncToVehicleHealth;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				uint8	bNoPassDamageToVehicle			= 0;		//var byte bNoPassDamageToVehicle;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				float	DamageModifier					= 0;		//var float DamageModifier;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				float	DS1HealthPct					= 0;		//var float DS1HealthPct;
	UPROPERTY(EditAnywhere, Category = "TestDamageZoneInfo")				float	DS2HealthPct					= 0;		//var float DS2HealthPct;
};

USTRUCT(BlueprintType)
struct FIniParticleInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "IniParticleInfo")				FName	ZoneName			= "";			//var name ZoneName;
	UPROPERTY(EditAnywhere, Category = "IniParticleInfo")				FString DS1ParticleString	= "";			//var string DS1ParticleString;
	UPROPERTY(EditAnywhere, Category = "IniParticleInfo")				FString DS2ParticleString	= "";			//var string DS2ParticleString;
};


USTRUCT(BlueprintType)
struct FActorAttachment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ActorAttachment")				AActor* attachClass		= nullptr;				//var class<Actor>  attachClass;
	UPROPERTY(EditAnywhere, Category = "ActorAttachment")				FName	AttachBone		= "";					//var name AttachBone;
};

USTRUCT(BlueprintType)
struct FImpactInfoStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				AActor* Other			= nullptr;					//var AActor* Other;
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector pos				= FVector(0, 0, 0);			//var Object.Vector pos;
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector impactVel		= FVector(0, 0, 0);			//var Object.Vector impactVel;
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector impactNorm		= FVector(0, 0, 0);			//var Object.Vector impactNorm;
	UPROPERTY(EditAnywhere, Category = "ImpactInfoStruct")				FVector ImpactAccel		= FVector(0, 0, 0);			//var Object.Vector ImpactAccel;
};

USTRUCT(BlueprintType)
struct FTrackedCraftState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FVector ChassisPosition		= FVector(0, 0, 0);		//var Object.Vector ChassisPosition;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FQuat	ChassisQuaternion	= FQuat(0,0,0,0);		//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FVector ChassisLinVel		= FVector(0, 0, 0);		//var Object.Vector ChassisLinVel;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				FVector ChassisAngVel		= FVector(0, 0, 0);		//var Object.Vector ChassisAngVel;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				uint8	ServerThrust		= 0;					//var byte ServerThrust;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				uint8	ServerTurn			= 0;					//var byte ServerTurn;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				int32	ServerViewPitch		= 0;					//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, Category = "TrackedCraftState")				int32	ServerViewYaw		= 0;					//var int ServerViewYaw;
};

USTRUCT(BlueprintType)
struct FSCarState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SCarState")				FVector ChassisPosition			= FVector(0, 0, 0);		//var Object.Vector ChassisPosition;
	UPROPERTY(EditAnywhere, Category = "SCarState")				FQuat	ChassisQuaternion		= FQuat(0, 0, 0,0);		//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, Category = "SCarState")				FVector ChassisLinVel			= FVector(0, 0, 0);		//var Object.Vector ChassisLinVel;
	UPROPERTY(EditAnywhere, Category = "SCarState")				FVector ChassisAngVel			= FVector(0, 0, 0);		//var Object.Vector ChassisAngVel;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerHandbrake			= 0;					//var byte ServerHandbrake;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerBrake				= 0;						//var byte ServerBrake;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerGas				= 0;						//var byte ServerGas;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerGear				= 0;						//var byte ServerGear;
	UPROPERTY(EditAnywhere, Category = "SCarState")				uint8	ServerSteering			= 0;					//var byte ServerSteering;
	UPROPERTY(EditAnywhere, Category = "SCarState")				int32	ServerViewPitch			= 0;					//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, Category = "SCarState")				int32	ServerViewYaw			= 0;					//var int ServerViewYaw;
};

USTRUCT(BlueprintType)
struct FAA2_InterpCurvePoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "InterpCurvePoint")				float InVal;					//var float InVal;
	UPROPERTY(EditAnywhere, Category = "InterpCurvePoint")				float OutVal;					//var float OutVal;
};

USTRUCT(BlueprintType)
struct FAA2_InterpCurve
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CopterState")				TArray<FAA2_InterpCurvePoint> Points;		//var array<InterpCurvePoint> Points;
};


USTRUCT(BlueprintType)
struct FPlaneStateStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				FKRBVec ChassisPosition;		//var Actor.KRBVec ChassisPosition;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				FQuat ChassisQuaternion;		//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				FKRBVec ChassisLinVel;			//var Actor.KRBVec ChassisLinVel;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				FKRBVec ChassisAngVel;			//var Actor.KRBVec ChassisAngVel;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				float ServerThrust;				//var float ServerThrust;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				float ServerStrafe;				//var float ServerStrafe;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				float ServerRise;				//var float ServerRise;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				int32 ServerViewPitch;			//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, Category = "PlaneStateStruct")				int32 ServerViewYaw;			//var int ServerViewYaw;
};


USTRUCT(BlueprintType)
struct FKRigidBodyState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")				FKRBVec Position;				//var KRBVec Position;
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")				FQuat Quaternion;				//var Object.Quat Quaternion;
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")				FKRBVec LinVel;					//var KRBVec LinVel;
	UPROPERTY(EditAnywhere, Category = "KRigidBodyState")				FKRBVec AngVel;					//var KRBVec AngVel;
};

USTRUCT(BlueprintType)
struct FCopterState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CopterState")					FVector ChassisPosition = FVector(0, 0, 0);		//var Object.Vector ChassisPosition;
	UPROPERTY(EditAnywhere, Category = "CopterState")					FQuat ChassisQuaternion;		//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, Category = "CopterState")					FVector ChassisLinVel = FVector(0, 0, 0);			//var Object.Vector ChassisLinVel;
	UPROPERTY(EditAnywhere, Category = "CopterState")					FVector ChassisAngVel = FVector(0, 0, 0);			//var Object.Vector ChassisAngVel;
	UPROPERTY(EditAnywhere, Category = "CopterState")					uint8 ServerThrust;				//var byte ServerThrust;
	UPROPERTY(EditAnywhere, Category = "CopterState")					uint8 ServerStrafe;				//var byte ServerStrafe;
	UPROPERTY(EditAnywhere, Category = "CopterState")					uint8 ServerRise;				//var byte ServerRise;
	UPROPERTY(EditAnywhere, Category = "CopterState")					int32 ServerViewPitch;			//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, Category = "CopterState")					int32 ServerViewYaw;			//var int ServerViewYaw;
};


USTRUCT(BlueprintType)
struct FSVehicleIcon
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					UMaterialInstance* Material;		//var Material Material;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float X;							//var float X;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float Y;							//var float Y;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float SizeX;						//var float SizeX;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					float SizeY;						//var float SizeY;
	UPROPERTY(EditAnywhere, Category = "SVehicleIcon")					bool bIsGreyScale;					//var bool bIsGreyScale;
};



USTRUCT(BlueprintType)
struct FMapItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MapItem")					FString MapName;					//var string MapName;
	UPROPERTY(EditAnywhere, Category = "MapItem")					FString OptionString;				//var string OptionString;
	UPROPERTY(EditAnywhere, Category = "MapItem")					FString FullURL;					//var string FullURL;


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
	UPROPERTY(EditAnywhere, Category = "GameRecordGroup")		FString		GameType		= "";			//var string GameType;
	UPROPERTY(EditAnywhere, Category = "GameRecordGroup")		FString		ActiveMaplist	= "";			//var string ActiveMaplist;
};

USTRUCT(BlueprintType)
struct FMaplistRecordGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	FString					GameType	= "";		//var string GameType;
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	int32					Active		= 0;		//var int Active;
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	int32					LastActive	= 0;		//var int LastActive;
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	TArray<FMapItem>		AllMaps		= {};		//var array<MaplistRecord.MapItem> AllMaps;
	UPROPERTY(EditAnywhere, Category = "MaplistRecordGroup")	TArray<UMaplistRecord*> Records		= {};		//var array<MaplistRecord> Records;
};

USTRUCT(BlueprintType)
struct FKeyInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "KeyInfo")				FString Alias = "";										//var string Alias;
	UPROPERTY(EditAnywhere, Category = "KeyInfo")				FString KeyLabel= "";									//var string KeyLabel;
	UPROPERTY(EditAnywhere, Category = "KeyInfo")				bool bIsSection=false;									//var bool bIsSection;
};

USTRUCT(BlueprintType)
struct FBoneEditVars
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			FName Name = "";										//var name Name;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			float Radius = 0;									//var float Radius;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			bool bCheckCaps=false;								//var bool bCheckCaps;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			float DamageModifier=0;								//var float DamageModifier;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			EBoneRegion BoneRegion = EBoneRegion::BR_NONE;		//var Object.EBoneRegion BoneRegion;
	UPROPERTY(EditAnywhere, Category = "BoneEditVars")			int32 BoneIdx=0;										//var int BoneIdx;
};

USTRUCT(BlueprintType)
struct FPlaylistParser
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlaylistParser")			EStreamPlaylistType Type;						//var StreamBase.EStreamPlaylistType Type;
	UPROPERTY(EditAnywhere, Category = "PlaylistParser")			FString ParserClass="";							//var string ParserClass;
};

USTRUCT(BlueprintType)
struct FHtmlChar
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HtmlChar")					FString Plain="";									//var string Plain;
	UPROPERTY(EditAnywhere, Category = "HtmlChar")					FString Coded="";									//var string Coded;
};

USTRUCT(BlueprintType)
struct FaFilePath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString FullPath="";									//var string FullPath;
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString Directory = "";									//var string Directory;
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString Filename = "";									//var string Filename;
	UPROPERTY(EditAnywhere, Category = "FilePath")					FString Extension = "";									//var string Extension;
	UPROPERTY(EditAnywhere, Category = "FilePath")					TArray<FString> DirectoryParts={};						//var TArray<FString> DirectoryParts;
};

USTRUCT(BlueprintType)
struct FID3Field
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FID3Field")					Fpointer ID3Field;									//var pointer ID3Field;
	UPROPERTY(EditAnywhere, Category = "FID3Field")					FString FieldName = "";									//var string FieldName;
	UPROPERTY(EditAnywhere, Category = "FID3Field")					FString FieldValue = "";									//var string FieldValue;
	UPROPERTY(EditAnywhere, Category = "FID3Field")					uint8 FieldID = 0;										//var byte FieldID;
	UPROPERTY(EditAnywhere, Category = "FID3Field")					uint8 Code = 0;											//var byte Code;
};

USTRUCT(BlueprintType)
struct FSpeechReplacement
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "SpeechReplacement")					TArray< FString> MatchWords;							//var TArray<FString> MatchWords;
	UPROPERTY(EditAnywhere, Category = "SpeechReplacement")					FString ReplaceWord;									//var string ReplaceWord;
};


USTRUCT(BlueprintType)
struct Ft_VideoMode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "t_VideoMode")						int32 X = 0;												//var int X;
	UPROPERTY(EditAnywhere, Category = "t_VideoMode")						int32 Y = 0;												//var int Y;
};

USTRUCT(BlueprintType)
struct FLine
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Line")			FString Text	= "";											//var string Text;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 ix		= 0;												//var int ix;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 iY		= 0;												//var int iY;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 iScaledX	= 0;											//var int iScaledX;
	UPROPERTY(EditAnywhere, Category = "Line")			int32 iScaledY	= 0;											//var int iScaledY;
};
USTRUCT(BlueprintType)
struct FScoring
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Scoring")								int32 LoRange;										//var int LoRange;
	UPROPERTY(EditAnywhere, Category = "Scoring")								int32 HiRange;										//var int HiRange;
	UPROPERTY(EditAnywhere, Category = "Scoring")								FString Award;										//var string Award;
	UPROPERTY(EditAnywhere, Category = "Scoring")								UMaterialInstance* AwardTexture;					//var Texture AwardTexture;
	UPROPERTY(EditAnywhere, Category = "Scoring")								USoundBase* AwardSound;								//var Sound AwardSound;
	UPROPERTY(EditAnywhere, Category = "Scoring")								bool bPass;											//var bool bPass;
};

USTRUCT(BlueprintType)
struct FImageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehicleData")								FString Info;										//var string Info;
	UPROPERTY(EditAnywhere, Category = "VehicleData")								UMaterialInstance* Tex;								//var Texture Tex;
	UPROPERTY(EditAnywhere, Category = "VehicleData")								TArray<FString> sData;								//var string sData;
	UPROPERTY(EditAnywhere, Category = "VehicleData")								int32 Status;										//var int Status;
};

USTRUCT(BlueprintType)
struct FVehicleData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VehicleData")								AAA2_PlayerState* Passengers;						//var PlayerReplicationInfo Passengers;
	UPROPERTY(EditAnywhere, Category = "VehicleData")								bool bDrewVehicle;									//var bool bDrewVehicle;
};

USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Point")			int32 X=0;											//var int X;
	UPROPERTY(EditAnywhere, Category = "Point")			int32 Y=0;											//var int Y;
};

USTRUCT(BlueprintType)
struct FPosition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Position")									int32 X=0;											//var int X;
	UPROPERTY(EditAnywhere, Category = "Position")									int32 Y=0;											//var int Y;
	UPROPERTY(EditAnywhere, Category = "Position")									int32 W=0;											//var int W;
	UPROPERTY(EditAnywhere, Category = "Position")									int32 H=0;											//var int H;
};

USTRUCT(BlueprintType)
struct FInvProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "InvProperties")								int32 iItemID=0;										//var int iItemID;
	UPROPERTY(EditAnywhere, Category = "InvProperties")								int32 iParam=0;										//var int iParam;
	UPROPERTY(EditAnywhere, Category = "InvProperties")								int32 iSize=0;										//var int iSize;
	UPROPERTY(EditAnywhere, Category = "InvProperties")								float fWeight=0;										//var float fWeight;
};


USTRUCT(BlueprintType)
struct FInvDefStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")								FString sItemName;										//var string sItemName;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")								int32 iParam;											//var int iParam;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")								float fWeight;											//var float fWeight;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")								int32 iSize;											//var int iSize;
	UPROPERTY(EditAnywhere, Category = "InvDefStruct")								UMaterialInstance* cTexture;								//var Texture cTexture;
};

USTRUCT(BlueprintType)
struct FDamageStateStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			TArray<FName> DamageBones = { "" ,"" ,"" ,"" ,"" ,"" ,"" ,"" };		//var name DamageBones;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			TArray<uint8> BoneSlot = {0,0,0,0,0,0,0,0};							//var byte BoneSlot;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			float DamagePct = 0;												//var float DamagePct;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			float ChildDamagePct = 0;											//var float ChildDamagePct;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			AEmitter* VisualEffectClass = nullptr;								//var class<Emitter>  VisualEffectClass;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			AVehicleVisualEffect* VisualEffect = nullptr;						//var VehicleVisualEffect VisualEffect;
	UPROPERTY(EditAnywhere, Category = "DamageStateStruct")			UVehiclePhysicalEffect* PhysicalEffect = nullptr;					//var class<VehiclePhysicalEffect>  PhysicalEffect;
};

USTRUCT(BlueprintType)
struct FDecorationType
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DecorationType")								UStaticMesh* StaticMesh;						//var StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere, Category = "DecorationType")								FRange Count;									//var Object.Range Count;
	UPROPERTY(EditAnywhere, Category = "DecorationType")								FRange DrawScale;								//var Object.Range DrawScale;
	UPROPERTY(EditAnywhere, Category = "DecorationType")								uint8 bAlign;									//var int bAlign;
	UPROPERTY(EditAnywhere, Category = "DecorationType")								uint8 bRandomPitch;								//var int bRandomPitch;
	UPROPERTY(EditAnywhere, Category = "DecorationType")								uint8 bRandomYaw;								//var int bRandomYaw;
	UPROPERTY(EditAnywhere, Category = "DecorationType")								uint8 bRandomRoll;								//var int bRandomRoll;
};


USTRUCT(BlueprintType)
struct FPoolItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PoolItem")								AActor* aElement;								//var AActor* aElement;
	UPROPERTY(EditAnywhere, Category = "PoolItem")								int32 iUsed;									//var int iUsed;
};

USTRUCT(BlueprintType)
struct FEnumStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "EnumStat")								FString statName;								//var string statName;
	UPROPERTY(EditAnywhere, Category = "EnumStat")								uint8 trueValue;								//var byte trueValue;
	UPROPERTY(EditAnywhere, Category = "EnumStat")								uint8 spoofValue;								//var byte spoofValue;
	UPROPERTY(EditAnywhere, Category = "EnumStat")								float spoofChance;								//var float spoofChance;
	UPROPERTY(EditAnywhere, Category = "EnumStat")								float obscurity;								//var float obscurity;
	UPROPERTY(EditAnywhere, Category = "EnumStat")								bool isStatic;									//var bool isStatic;
};

USTRUCT(BlueprintType)
struct FVectorStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "VectorStat")								FString statName;								//var string statName;
	UPROPERTY(EditAnywhere, Category = "VectorStat")								FVector trueValue = FVector(0, 0, 0);								//var Object.Vector trueValue;
	UPROPERTY(EditAnywhere, Category = "VectorStat")								FVector spoofValue = FVector(0, 0, 0);								//var Object.Vector spoofValue;
	UPROPERTY(EditAnywhere, Category = "VectorStat")								float spoofChance;								//var float spoofChance;
	UPROPERTY(EditAnywhere, Category = "VectorStat")								float obscurity;								//var float obscurity;
	UPROPERTY(EditAnywhere, Category = "VectorStat")								bool isStatic;									//var bool isStatic;
};

USTRUCT(BlueprintType)
struct FFloatStat
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FloatStat")									FString statName;								//var string statName;
	UPROPERTY(EditAnywhere, Category = "FloatStat")									float trueValue;								//var float trueValue;
	UPROPERTY(EditAnywhere, Category = "FloatStat")									float spoofValue;								//var float spoofValue;
	UPROPERTY(EditAnywhere, Category = "FloatStat")									float spoofChance;								//var float spoofChance;
	UPROPERTY(EditAnywhere, Category = "FloatStat")									float obscurity;								//var float obscurity;
	UPROPERTY(EditAnywhere, Category = "FloatStat")									bool isStatic;									//var bool isStatic;
};



USTRUCT(BlueprintType)
struct FUAVFlightPlanWaypoints
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlanWaypoints")					FVector vLocation = FVector(0, 0, 0);								//var Object.Vector vLocation;
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlanWaypoints")					float fpSpeed;									//var float fpSpeed;
	UPROPERTY(EditAnywhere, Category = "UAVFlightPlanWaypoints")					float fpAltitude;								//var float fpAltitude;
};


USTRUCT(BlueprintType)
struct FCrosshairItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CrosshairItem")								FString FriendlyName;							//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "CrosshairItem")								UTexture2D* CrosshairTexture;					//var Texture CrosshairTexture;
};


USTRUCT(BlueprintType)
struct FFloatBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "FloatBox")									float X1;										//var float X1;
	UPROPERTY(EditAnywhere, Category = "FloatBox")									float Y1;										//var float Y1;
	UPROPERTY(EditAnywhere, Category = "FloatBox")									float X2;										//var float X2;
	UPROPERTY(EditAnywhere, Category = "FloatBox")									float Y2;										//var float Y2;
};


USTRUCT(BlueprintType)
struct FCountryFlag
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								FString CountryCode;							//var string CountryCode;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								FString CountryName;							//var string CountryName;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float U;										//var float U;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float V;										//var float V;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float UL;										//var float UL;
	UPROPERTY(EditAnywhere, Category = "CountryFlag")								float VL;										//var float VL;
};


USTRUCT(BlueprintType)
struct FOrientation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Orientation")							ECamOrientation CamOrientation;						//var Object.ECamOrientation CamOrientation;
	UPROPERTY(EditAnywhere, Category = "Orientation")							AActor* LookAt;										//var AActor* LookAt;
	UPROPERTY(EditAnywhere, Category = "Orientation")							AActor* DollyWith;									//var AActor* DollyWith;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float EaseIntime;									//var float EaseIntime;
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bReversePitch;								//var int bReversePitch;
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bReverseYaw;									//var int bReverseYaw;
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bReverseRoll;									//var int bReverseRoll;
	UPROPERTY(EditAnywhere, Category = "Orientation")							Fpointer Orientation;								//var pointer Orientation;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float PctInStart;									//var float PctInStart;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float PctInEnd;										//var float PctInEnd;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float PctInDuration;								//var float PctInDuration;
	UPROPERTY(EditAnywhere, Category = "Orientation")							FRotator StartingRotation = FRotator(0, 0, 0);							//var Object.Rotator StartingRotation;
};

USTRUCT(BlueprintType)
struct FInterpolator
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Orientation")							int32 bDone;										//var int bDone;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _value;										//var float _value;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _remainingTime;								//var float _remainingTime;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _totalTime;									//var float _totalTime;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _speed;										//var float _speed;
	UPROPERTY(EditAnywhere, Category = "Orientation")							float _acceleration;								//var float _acceleration;
};

USTRUCT(BlueprintType)
struct FCachedSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CachedSound")							FName CacheName;									//var name CacheName;
	UPROPERTY(EditAnywhere, Category = "CachedSound")							USoundBase* CacheSound;								//var Sound CacheSound;
};
USTRUCT(BlueprintType)
struct FQueueItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QueueItem")								FName Name;											//var name Voice;
	UPROPERTY(EditAnywhere, Category = "QueueItem")								float Delay;										//var float Delay;
	UPROPERTY(EditAnywhere, Category = "QueueItem")								uint8 Switch;										//var byte Switch;
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
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FName PosActorTag;									//var name PosActorTag;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FVector Location = FVector(0, 0, 0);				//var FVector Location;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								FRotator Rotation = FRotator(0, 0, 0);				//var Object.Rotator Rotation;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								bool bBaseToPosActor;								//var bool bBaseToPosActor;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								EFontType Font;										//var EFontType Font;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								AActor* PosActor;									//var AActor* PosActor;
	UPROPERTY(EditAnywhere, Category = "ScoreItem")								TArray<ATextDisplay_Char*> Digits;					//var array<TextDisplay_Char> Digits;
};

USTRUCT(BlueprintType)
struct FSection
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Section")								FString Header;										//var string Header;
	UPROPERTY(EditAnywhere, Category = "Section")								FString Id;											//var string Id;
	UPROPERTY(EditAnywhere, Category = "Section")								FString Display;									//var string Display;
	UPROPERTY(EditAnywhere, Category = "Section")								FString Caption;									//var string Caption;
	UPROPERTY(EditAnywhere, Category = "Section")								FString URL;										//var string URL;
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
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Tag;										//var name Tag;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							ANPC_SpecialForces* Actor;						//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName CadreTriggerTag;							//var name CadreTriggerTag;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							AAGP_UseTrigger* CadreTrigger;					//var AGP.AGP_UseTrigger CadreTrigger;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							bool bGreeted;									//var bool bGreeted;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Greeting;									//var name Greeting;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							bool bInstructed;								//var bool bInstructed;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Instruction;								//var name Instruction;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							bool bReminded;									//var bool bReminded;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName Reminder;									//var name Reminder;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeReady;							//var name ChallengeReady;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeGo;								//var name ChallengeGo;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeIncomplete;						//var name ChallengeIncomplete;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName ChallengeComplete;						//var name ChallengeComplete;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName WarningLeavingArea;						//var name WarningLeavingArea;
	UPROPERTY(EditAnywhere, Category = "WeaponsSergeant")							FName WarningDownrange;							//var name WarningDownrange;
};

USTRUCT(BlueprintType)
struct FWeaponsAssistant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName Tag;										//var name Tag;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							ANPC_SpecialForces* Actor;						//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName PickupTag;								//var name PickupTag;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName WarningDownrange;							//var name WarningDownrange;
	UPROPERTY(EditAnywhere, Category = "WeaponsAssistant")							FName WarningLeavingArea;						//var name WarningLeavingArea;
};
USTRUCT(BlueprintType)
struct FChallengeStation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 MaxNumberTargets;							//var int MaxNumberTargets;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 MinPassingScore;							//var int MinPassingScore;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							AMarksmanTarget* CurrentMarksmanTarget;			//var AGP_Gameplay.MarksmanTarget CurrentMarksmanTarget;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							ADecoMesh* CurrentDecoMesh;						//var DecoMesh CurrentDecoMesh;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							ADamageDetector* CurrentDamageDetector;			//var AGP_Gameplay.DamageDetector CurrentDamageDetector;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							TArray<FName> TargetStack;						//var array<name> TargetStack;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							TArray<FName> TargetStates;						//var array<name> TargetStates;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 TargetActiveTime;							//var int TargetActiveTime;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							int32 TargetInactiveTime;						//var int TargetInactiveTime;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FName ChallengeState;							//var name ChallengeState;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FName ChallengeVolumeTag;						//var name ChallengeVolumeTag;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							ATriggerVolume* ChallengeVolume;				//var AGP_Gameplay.TriggerVolume ChallengeVolume;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FName ChallengeReadyTriggerTag;					//var name ChallengeReadyTriggerTag;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							AAGP_Trigger* ChallengeReadyTrigger;			//var AGP_Gameplay.AGP_Trigger ChallengeReadyTrigger;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FWeaponsSergeant Instructor;					//var EL_SFWeapons_Range.WeaponsSergeant Instructor;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FWeaponsAssistant Assistant1;					//var EL_SFWeapons_Range.WeaponsAssistant Assistant1;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							FWeaponsAssistant Assistant2;					//var EL_SFWeapons_Range.WeaponsAssistant Assistant2;
	UPROPERTY(EditAnywhere, Category = "ChallengeStation")							bool bWeaponActive;								//var bool bWeaponActive;
};

USTRUCT(BlueprintType)
struct FHelpInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FName HelpName;										//var name HelpName;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									float HelpTimer;									//var float HelpTimer;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FString Line1HelpText;								//var string Line1HelpText;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FString Line2HelpText;								//var string Line2HelpText;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									FName LSHelpAnimation;								//var name LSHelpAnimation;
	UPROPERTY(EditAnywhere, Category = "HelpInfo")									AActor* LSActor;									//var AActor* LSActor;
};


USTRUCT(BlueprintType)
struct FLFTargetStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LFTargetStruct")							TArray<AActor*> InvalidTarget;						//var array<AGP_Vehicle> InvalidTarget;
	UPROPERTY(EditAnywhere, Category = "LFTargetStruct")							TArray<AActor*> ValidTarget;						//var array<AGP_Vehicle> ValidTarget;
};


USTRUCT(BlueprintType)
struct FTeamMember
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FName ActorTag;										//var name ActorTag;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								ANPC_SpecialForces* Actor;							//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FName VolTriggerTag;								//var name VolTriggerTag;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								ATriggerVolume* VolTrigger;							//var AGP_Gameplay.TriggerVolume VolTrigger;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FName UseTriggerTag;								//var name UseTriggerTag;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								AAGP_UseTrigger* UseTrigger;						//var AGP.AGP_UseTrigger UseTrigger;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FString TalkText;									//var string TalkText;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								FString MOSText;									//var string MOSText;
	UPROPERTY(EditAnywhere, Category = "TeamMember")								int32 offset;										//var int offset;
};

USTRUCT(BlueprintType)
struct FLevelTex
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* Image;							//var Shader Image;
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* Status;							//var Shader Status;
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* ImageEnabled;					//var Texture ImageEnabled;
	UPROPERTY(EditAnywhere, Category = "LevelTex")									UMaterialInstance* ImageDisabled;					//var Texture ImageDisabled;
};

USTRUCT(BlueprintType)
struct FLevelTrigger
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FName Tag;											//var name Tag;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								AAGP_UseTrigger* Trigger;							//var AGP.AGP_UseTrigger Trigger;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FString MSG_NotAvailable;							//var string MSG_NotAvailable;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FString MSG_Available;								//var string MSG_Available;
	UPROPERTY(EditAnywhere, Category = "LevelTrigger")								FString MSG_Completed;								//var string MSG_Completed;
};

USTRUCT(BlueprintType)
struct FMissionInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								uint8 Tour;											//var byte Tour;
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								uint8 Mission;										//var byte Mission;
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								FString LoadMessage;								//var string LoadMessage;
	UPROPERTY(EditAnywhere, Category = "MissionInfo")								FString MapName;									//var string MapName;
};
USTRUCT(BlueprintType)
struct FHeliPath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "HeliPath")									FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, Category = "HeliPath")									ASceneManager* Path;								//var SceneManager Path;
	UPROPERTY(EditAnywhere, Category = "HeliPath")									bool bFlown;										//var bool bFlown;
};

USTRUCT(BlueprintType)
struct FCSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CSound")									bool bFadeUp;										//var bool bFadeUp;
	UPROPERTY(EditAnywhere, Category = "CSound")									bool bFadeDown;										//var bool bFadeDown;
	UPROPERTY(EditAnywhere, Category = "CSound")									float FadeTime;										//var float FadeTime;
	UPROPERTY(EditAnywhere, Category = "CSound")									float Volume;										//var float Volume;
	UPROPERTY(EditAnywhere, Category = "CSound")									float StartVolume;									//var float StartVolume;
};


USTRUCT(BlueprintType)
struct FBoneProfile
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BoneProfile")								FName BodyPart;										//var name BodyPart;
	UPROPERTY(EditAnywhere, Category = "BoneProfile")								FName BoneName;										//var name BoneName;
};


USTRUCT(BlueprintType)
struct FGameSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameSound")									USoundBase* Sound;									//var Sound Sound;
	UPROPERTY(EditAnywhere, Category = "GameSound")									FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, Category = "GameSound")									float Duration;										//var float Duration;
};
USTRUCT(BlueprintType)
struct FLSAnim
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PrevNext")									FName Anim;											//var name Anim;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									USoundBase* Sound;									//var Sound Sound;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									TArray<FName> GestureAnim;							//var name GestureAnim;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									TArray<float> GestureDelay;							//var float GestureDelay;
};
USTRUCT(BlueprintType)
struct FGameAnim
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameAnim")									FName Anim;											//var name Anim;
};

USTRUCT(BlueprintType)
struct FTimerEvent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TimerEvent")								FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")								float StartTime;									//var float StartTime;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")								float WaitTime;										//var float WaitTime;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")								ETimerType TType;									//var ETimerType TType;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")								bool bRepeat;										//var bool bRepeat;
	UPROPERTY(EditAnywhere, Category = "TimerEvent")								bool bPause;										//var bool bPause;
};
USTRUCT(BlueprintType)
struct FQueueAnimation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							FName Anim;											//var name Anim;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							AActor* Actor;										//var AActor* Actor;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							float StartTime;									//var float StartTime;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							float Length;										//var float Length;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							bool bLoop;											//var bool bLoop;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							float Rate;											//var float Rate;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							float TweenTime;									//var float TweenTime;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							int32 Channel;										//var int Channel;
	UPROPERTY(EditAnywhere, Category = "QueueAnimation")							bool bRemove;										//var bool bRemove;
};



USTRUCT(BlueprintType)
struct FPrevNext
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PrevNext")									float HotSpotX = 0;									//var float HotSpotX;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									float HotSpotY = 0;									//var float HotSpotY;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									float HotSpotZ = 0;									//var float HotSpotZ;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									float HotSpotRadius = 0;							//var float HotSpotRadius;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									FString HotSpotText;								//var string HotSpotText;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									FName LookTargetName;								//var name LookTargetName;
	UPROPERTY(EditAnywhere, Category = "PrevNext")									AExamAnswer* Answer;								//var ExamAnswer Answer;
};

USTRUCT(BlueprintType)
struct FTestAnswer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								bool bCorrectAnswer;								//var bool bCorrectAnswer;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								float HotSpotX;										//var float HotSpotX;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								float HotSpotY;										//var float HotSpotY;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								float HotSpotZ;										//var float HotSpotZ;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								float HotSpotRadius;								//var float HotSpotRadius;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								FString HotSpotText;								//var string HotSpotText;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								FName QuestionName;									//var name QuestionName;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								FName LookTargetName;								//var name LookTargetName;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								AExamAnswer* Answer;								//var ExamAnswer Answer;
	UPROPERTY(EditAnywhere, Category = "TestAnswer")								bool bMarkedCorrect;								//var bool bMarkedCorrect;
};

USTRUCT(BlueprintType)
struct FTestPage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TestPage")									FName PageName;										//var name PageName;
	UPROPERTY(EditAnywhere, Category = "TestPage")									UMaterialInstance* PageTexture;						//var Material PageTexture;
	UPROPERTY(EditAnywhere, Category = "TestPage")									TArray<FTestAnswer> TestAnswers;					//var array<TestAnswer> TestAnswers;
	UPROPERTY(EditAnywhere, Category = "TestPage")									FPrevNext PageNext;									//var MedExam.PrevNext PageNext;
	UPROPERTY(EditAnywhere, Category = "TestPage")									FPrevNext PagePrev;									//var MedExam.PrevNext PagePrev;
};

USTRUCT(BlueprintType)
struct FWeatherPcl
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								FVector pos = FVector(0, 0, 0);										//var FVector pos;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								FVector Vel = FVector(0, 0, 0);										//var FVector Vel;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								float Life;											//var float Life;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								float Size;											//var float Size;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								float HitTime;										//var float HitTime;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								float InvLifeSpan;									//var float InvLifeSpan;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								float DistAtten;									//var float DistAtten;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								uint8 frame;										//var byte frame;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								uint8 Dummy1;										//var byte Dummy1;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								uint8 Visible;										//var byte Visible;
	UPROPERTY(EditAnywhere, Category = "WeatherPcl")								uint8 Dummy2;										//var byte Dummy2;
};

USTRUCT(BlueprintType)
struct FEventParms
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "EventParms")								FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, Category = "EventParms")								bool bDelay;										//var bool bDelay;
	UPROPERTY(EditAnywhere, Category = "EventParms")								float DelayMin;										//var float DelayMin;
	UPROPERTY(EditAnywhere, Category = "EventParms")								float DelayMax;										//var float DelayMax;
};

USTRUCT(BlueprintType)
struct FPropFlags
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool bHidden;										//var bool bHidden;
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool bBlockActors;									//var bool bBlockActors;
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool bBlockPlayers;									//var bool bBlockPlayers;
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool bBlockZeroExtentTraces;						//var bool bBlockZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool bBlockNonZeroExtentTraces;						//var bool bBlockNonZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool AmbientGlow;									//var bool AmbientGlow;
	UPROPERTY(EditAnywhere, Category = "PropFlags")									bool DrawScale;										//var bool DrawScale;
};

USTRUCT(BlueprintType)
struct FPropValues
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PropValues")								bool bHidden;										//var bool bHidden;
	UPROPERTY(EditAnywhere, Category = "PropValues")								bool bBlockActors;									//var bool bBlockActors;
	UPROPERTY(EditAnywhere, Category = "PropValues")								bool bBlockPlayers;									//var bool bBlockPlayers;
	UPROPERTY(EditAnywhere, Category = "PropValues")								bool bBlockZeroExtentTraces;						//var bool bBlockZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropValues")								bool bBlockNonZeroExtentTraces;						//var bool bBlockNonZeroExtentTraces;
	UPROPERTY(EditAnywhere, Category = "PropValues")								uint8 AmbientGlow;									//var byte AmbientGlow;
	UPROPERTY(EditAnywhere, Category = "PropValues")								float DrawScale;									//var float DrawScale;
};

USTRUCT(BlueprintType)
struct FTargetActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TargetActor")								FName ActorTag;										//var name ActorTag;
	UPROPERTY(EditAnywhere, Category = "TargetActor")								FPropFlags PropertyFlags;							//var PropertyTrigger.PropFlags PropertyFlags;
	UPROPERTY(EditAnywhere, Category = "TargetActor")								FPropValues SetValues;								//var PropertyTrigger.PropValues SetValues;
	UPROPERTY(EditAnywhere, Category = "TargetActor")								FPropValues UnSetValues;							//var PropertyTrigger.PropValues UnSetValues;
	UPROPERTY(EditAnywhere, Category = "TargetActor")								AActor* ActorRef;									//var AActor* ActorRef;
};


USTRUCT(BlueprintType)
struct FImageStratum
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ImageStratum")								float LowerBound;									//var float LowerBound;
	UPROPERTY(EditAnywhere, Category = "ImageStratum")								float UpperBound;									//var float UpperBound;
	UPROPERTY(EditAnywhere, Category = "ImageStratum")								UMaterialInstance* RadarImage;						//var Material RadarImage;
};


USTRUCT(BlueprintType)
struct FNPCRestStopAnimSequenceSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")				FName animStart;									//var name animStart;
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")				FName animMiddle;									//var name animMiddle;
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")				FName AnimEnd;										//var name AnimEnd;
	UPROPERTY(EditAnywhere, Category = "NPCRestStopAnimSequenceSet")				bool bShoulderWeaponFirst;							//var bool bShoulderWeaponFirst;
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
	UPROPERTY(EditAnywhere, Category = "NPCAttachObject")		float		Scale				=0;						//var float Scale;
};

USTRUCT(BlueprintType)
struct FRecentContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RecentContact")								APawn* pawnContact;									//var APawn* pawnContact;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								bool bHumanControlled;								//var bool bHumanControlled;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								bool bEnemy;										//var bool bEnemy;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								FVector vLocation = FVector(0, 0, 0);									//var FVector vLocation;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								float fpThreatLevel;								//var float fpThreatLevel;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								float fpTimeSeen;									//var float fpTimeSeen;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								float fpClosureRate;								//var float fpClosureRate;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								int32 iConfidencePenalty;							//var int iConfidencePenalty;
	UPROPERTY(EditAnywhere, Category = "RecentContact")								bool bContactLost;									//var bool bContactLost;
};
USTRUCT(BlueprintType)
struct FGrenadeThreatContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GrenadeThreatContact")						AThrowWeaponPickup* twpGrenade;						//var ThrowWeaponPickup twpGrenade;
	UPROPERTY(EditAnywhere, Category = "GrenadeThreatContact")						float fpTimeSeen;									//var float fpTimeSeen;
};

USTRUCT(BlueprintType)
struct FNPCAnimSequenceSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")						FName animStart;									//var name animStart;
	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")						FName animMiddle;									//var name animMiddle;
	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")						FName AnimEnd;										//var name AnimEnd;
	UPROPERTY(EditAnywhere, Category = "NPCAnimSequenceSet")						bool bShoulderWeaponFirst;							//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FTarget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Target")									UStaticMesh* StaticMesh;							//var StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Target")									UStaticMesh* ZoneMesh;								//var StaticMesh ZoneMesh;
	UPROPERTY(EditAnywhere, Category = "Target")									float Z1Scale;										//var float Z1Scale;
	UPROPERTY(EditAnywhere, Category = "Target")									FVector Z1Scale3D = FVector(0, 0, 0);									//var FVector Z1Scale3D;
	UPROPERTY(EditAnywhere, Category = "Target")									FVector Z1Offset = FVector(0, 0, 0);									//var FVector Z1Offset;
	UPROPERTY(EditAnywhere, Category = "Target")									FRotator Z1Rotation = FRotator(0, 0, 0);								//var Object.Rotator Z1Rotation;
	UPROPERTY(EditAnywhere, Category = "Target")									FString Z1ID;										//var string Z1ID;
	UPROPERTY(EditAnywhere, Category = "Target")									float Z2Scale;										//var float Z2Scale;
	UPROPERTY(EditAnywhere, Category = "Target")									FVector Z2Scale3D = FVector(0, 0, 0);									//var FVector Z2Scale3D;
	UPROPERTY(EditAnywhere, Category = "Target")									FVector Z2Offset = FVector(0, 0, 0);									//var FVector Z2Offset;
	UPROPERTY(EditAnywhere, Category = "Target")									FRotator Z2Rotation = FRotator(0, 0, 0);								//var Object.Rotator Z2Rotation;
	UPROPERTY(EditAnywhere, Category = "Target")									FString Z2ID;										//var string Z2ID;
};



USTRUCT(BlueprintType)
struct FTagAttachment
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "TagAttachment")									FName ActorTag;										//	var name ActorTag;
};


USTRUCT(BlueprintType)
struct FAttachObject
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									AActor* Attachment;									//var class<Actor>  Attachment;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									FName Bone;											//var name Bone;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									FVector LocationOffset = FVector(0, 0, 0);								//var FVector LocationOffset;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									FRotator RotationOffset = FRotator(0, 0, 0);							//var Object.Rotator RotationOffset;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									bool bUseParentScale;								//var bool bUseParentScale;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									float Scale;										//var float Scale;
};

USTRUCT(BlueprintType)
struct FTarGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TarGroup")										FString Label;										//var string Label;
	UPROPERTY(EditAnywhere, Category = "TarGroup")										int32 nShot;										//var int nShot;
	UPROPERTY(EditAnywhere, Category = "TarGroup")										int32 nMissed;										//var int nMissed;
	UPROPERTY(EditAnywhere, Category = "TarGroup")										int32 nTotal;										//var int nTotal;
};

USTRUCT(BlueprintType)
struct FOutStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "OutStruct")										FName Event;										//var name Event;
	UPROPERTY(EditAnywhere, Category = "OutStruct")										int32 Counter;										//var int Counter;
};


USTRUCT(BlueprintType)
struct FVisibleDelay
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "VisibleDelay")									float Visible;										//var float Visible;
	UPROPERTY(EditAnywhere, Category = "VisibleDelay")									float Delay;										//var float Delay;
};

USTRUCT(BlueprintType)
struct FPaddingPercent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PaddingPercent")									float HorzPerc;										//var float HorzPerc;
	UPROPERTY(EditAnywhere, Category = "PaddingPercent")									float VertPerc;										//var float VertPerc;
};

USTRUCT(BlueprintType)
struct FAnimInfo
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float cX;											//var float cX;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float cY;											//var float cY;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float Scale;										//var float Scale;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float FadeTime;										//var float FadeTime;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float Alpha;										//var float Alpha;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float TargetAlpha;									//var float TargetAlpha;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float ResetDelay;									//var float ResetDelay;
	UPROPERTY(EditAnywhere, Category = "AnimInfo")										float TravelTime;									//var float TravelTime;
};

USTRUCT(BlueprintType)
struct FProfileStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ProfileStruct")									FString ProfileName;								//var string ProfileName;
	UPROPERTY(EditAnywhere, Category = "ProfileStruct")									float ProfileSeconds;								//var float ProfileSeconds;
};

USTRUCT(BlueprintType)
struct FeOwnageMap
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")										int32 RLevel;										//var int RLevel;
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")										FString MapName;									//var string MapName;
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")										FString MapDesc;									//var string MapDesc;
	UPROPERTY(EditAnywhere, Category = "eOwnageMap")										FString MapURL;										//var string MapURL;
};
USTRUCT(BlueprintType)
struct FAutoLoadMenu
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AutoLoadMenu")									FString MenuClassName;								//var string MenuClassName;
	UPROPERTY(EditAnywhere, Category = "AutoLoadMenu")									bool bPreInitialize;								//var bool bPreInitialize;
};

USTRUCT(BlueprintType)
struct FRestoreMenuItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RestoreMenuItem")									FString MenuClassName;								//var string MenuClassName;
	UPROPERTY(EditAnywhere, Category = "RestoreMenuItem")									FString Param1;										//var string Param1;
	UPROPERTY(EditAnywhere, Category = "RestoreMenuItem")									FString Param2;										//var string Param2;
};
USTRUCT(BlueprintType)
struct FDesignModeHint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "DesignModeHint")									FString Key;										//var string Key;
	UPROPERTY(EditAnywhere, Category = "DesignModeHint")									FString Description;										//var string Description;
};

USTRUCT(BlueprintType)
struct FGUIListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GUIListElem")										FString Item;										//var string Item;
	UPROPERTY(EditAnywhere, Category = "GUIListElem")										UObject* ExtraData;									//var Object ExtraData;
	UPROPERTY(EditAnywhere, Category = "GUIListElem")										FString ExtraStrData;								//var string ExtraStrData;
	UPROPERTY(EditAnywhere, Category = "GUIListElem")										bool bSection;										//var bool bSection;
};

USTRUCT(BlueprintType)
struct FAPackInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "APackInfo")										FString PackageName;								//var string PackageName;
	UPROPERTY(EditAnywhere, Category = "APackInfo")										FString Description;								//var string Description;
};

USTRUCT(BlueprintType)
struct FMultiSelectListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")								FString Item;										//var string Item;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")								UObject* ExtraData;									//var Object ExtraData;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")								FString ExtraStrData;								//var string ExtraStrData;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")								bool bSelected;										//var bool bSelected;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")								int32 SelectionIndex;								//var int SelectionIndex;
	UPROPERTY(EditAnywhere, Category = "MultiSelectListElem")								bool bSection;										//var bool bSection;
};

USTRUCT(BlueprintType)
struct FImageListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ImageListElem")									int32 Item;											//var int Item;
	UPROPERTY(EditAnywhere, Category = "ImageListElem")									UMaterialInstance* Image;							//var Material Image;
	UPROPERTY(EditAnywhere, Category = "ImageListElem")									int32 Locked;										//var int Locked;
};

USTRUCT(BlueprintType)
struct FGUITreeNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")										FString Caption;									//var string Caption;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")										FString Value;										//var string Value;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")										FString ParentCaption;								//var string ParentCaption;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")										FString ExtraInfo;									//var string ExtraInfo;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")										int32 Level;										//var int Level;
	UPROPERTY(EditAnywhere, Category = "GUITreeNode")										bool bEnabled;										//var bool bEnabled;
};

USTRUCT(BlueprintType)
struct FAutoLoginInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")									FString IP;											//var string IP;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")									FString Port;										//var string Port;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")									FString UserName;									//var string UserName;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")									FString Password;									//var string Password;
	UPROPERTY(EditAnywhere, Category = "AutoLoginInfo")									bool bAutologin;									//var bool bAutologin;
};

USTRUCT(BlueprintType)
struct FGUITabItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GUITabItem")										FString ClassName;									//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "GUITabItem")										FString Caption;									//var string Caption;
	UPROPERTY(EditAnywhere, Category = "GUITabItem")										FString Hint;										//var string Hint;
};

USTRUCT(BlueprintType)
struct FBadgeInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										FString BadgeName;									//var string BadgeName;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeXMin;									//var float RangeXMin;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeXMax;									//var float RangeXMax;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeYMin;									//var float RangeYMin;
	UPROPERTY(EditAnywhere, Category = "BadgeInfo")										float RangeYMax;									//var float RangeYMax;
};

USTRUCT(BlueprintType)
struct FRibbonRowInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RibbonRowInfo")									FString RibbonName1;								//var string RibbonName1;
	UPROPERTY(EditAnywhere, Category = "RibbonRowInfo")									FString RibbonName2;								//var string RibbonName2;
	UPROPERTY(EditAnywhere, Category = "RibbonRowInfo")									FString RibbonName3;								//var string RibbonName3;
};


USTRUCT(BlueprintType)
struct FCommandAlias
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "CommandAlias")									FString AliasText;									//var string AliasText;
	UPROPERTY(EditAnywhere, Category = "CommandAlias")									FString RealCommand;								//var string RealCommand;
};

USTRUCT(BlueprintType)
struct FServerSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ServerSettings")									FString Key;										//var string Key;
	UPROPERTY(EditAnywhere, Category = "ServerSettings")									FString Value;										//var string Value;
};

USTRUCT(BlueprintType)
struct FMapVoteGameConfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString GameClass;									//var string GameClass;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Prefix;										//var string Prefix;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Acronym;									//var string Acronym;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString GameName;									//var string GameName;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Mutators;									//var string Mutators;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfig")								FString Options;									//var string Options;
};

USTRUCT(BlueprintType)
struct FMapVoteGameConfigLite
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfigLite")							FString GameClass;									//var string GameClass;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfigLite")							FString Prefix;										//var string Prefix;
	UPROPERTY(EditAnywhere, Category = "MapVoteGameConfigLite")							FString GameName;									//var string GameName;
};

USTRUCT(BlueprintType)
struct FMapVoteMapList
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									FString MapName;									//var string MapName;
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									int32 PlayCount;									//var int PlayCount;
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									int32 Sequence;										//var int Sequence;
	UPROPERTY(EditAnywhere, Category = "MapVoteMapList")									bool bEnabled;										//var bool bEnabled;
};

USTRUCT(BlueprintType)
struct FMapHistoryInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									FString M;											//var string M;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									int32 p;											//var int p;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									int32 S;											//var int S;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									FString G;;											//var string G;
	UPROPERTY(EditAnywhere, Category = "MapHistoryInfo")									FString U;											//var string U;
};

USTRUCT(BlueprintType)
struct FMapVoteScore
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "MapVoteScore")									int32 MapIndex;										//var int MapIndex;
	UPROPERTY(BlueprintReadWrite, Category = "MapVoteScore")									int32 GameConfigIndex;								//var int GameConfigIndex;
	UPROPERTY(BlueprintReadWrite, Category = "MapVoteScore")									int32 VoteCount;									//var int VoteCount;
};

USTRUCT(BlueprintType)
struct FKickVoteScore
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KickVoteScore")									int32 PlayerID;										//var int PlayerID;
	UPROPERTY(BlueprintReadWrite, Category = "KickVoteScore")									int32 Team;											//var int Team;
	UPROPERTY(BlueprintReadWrite, Category = "KickVoteScore")									int32 KickVoteCount;								//var int KickVoteCount;
};

USTRUCT(BlueprintType)
struct FAccumulationData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AccumulationData")								FString Name;										//var string Name;
	UPROPERTY(BlueprintReadWrite, Category = "AccumulationData")								int32 VoteCount;									//var int VoteCount;
};

USTRUCT(BlueprintType)
struct FsPendingRequest
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									AAA2_PlayerState* PRI;								//var PlayerReplicationInfo PRI;
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									int32 UnitID;										//var int UnitId;
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									int32 Index = 0;										//var int index;
};

USTRUCT(BlueprintType)
struct FTournamentPlayer
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayer")								FString PlayerName;									//var string PlayerName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayer")								int32 TeamIndex;									//var int TeamIndex;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayer")								int32 Score;										//var int Score;
};


USTRUCT(BlueprintType)
struct FPlayerMBSInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						FString PlayerName;									//var string PlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						FString IPAddress;									//var string IPAddress;
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						int32 Ping;											//var int Ping;
	UPROPERTY(EditAnywhere, Category = "PlayerMBSInfo")						TArray<FKeyValuePair> Attributes;					//var array<GameInfo.KeyValuePair> Attributes;
};

USTRUCT(BlueprintType)
struct FStoredChatPassword
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "StoredChatPassword")				FString ChatRoomName;								//var string ChatRoomName;
	UPROPERTY(EditAnywhere, Category = "StoredChatPassword")				FString ChatRoomPassword;							//var string ChatRoomPassword;
};

USTRUCT(BlueprintType)
struct FPlayerNameInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					FString mInfo;										//var string mInfo;
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					FColor mColor;										//var Object.Color mColor;
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					float mXPos;										//var float mXPos;
	UPROPERTY(EditAnywhere, Category = "PlayerNameInfo")					float mYPos;										//var float mYPos;
};

USTRUCT(BlueprintType)
struct FAA2_ClientAdjustment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					float TimeStamp;									//var float TimeStamp;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FName NewState;										//var name NewState;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					EPhysics newPhysics;								//var Actor.EPhysics newPhysics;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FVector NewLoc = FVector(0, 0, 0);										//var FVector NewLoc;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					FVector NewVel = FVector(0, 0, 0);										//var FVector NewVel;
	UPROPERTY(EditAnywhere, Category = "ClientAdjustment")					AActor* NewBase;									//var AActor* NewBase;
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
	UPROPERTY(EditAnywhere, Category = "WeaponRecordBrief")					int32 ShotsFired;									//var int ShotsFired;
	UPROPERTY(EditAnywhere, Category = "WeaponRecordBrief")					int32 ShotsHit;										//var int ShotsHit;
	UPROPERTY(EditAnywhere, Category = "WeaponRecordBrief")					int32 Kills;										//var int Kills;
};

	USTRUCT(BlueprintType)
struct FQualificationRecordBrief
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "QualificationRecordBrief")			int32 Grade;										//var int Grade;
	UPROPERTY(EditAnywhere, Category = "QualificationRecordBrief")			FString Date;										//var string Date;
};

USTRUCT(BlueprintType)
struct FRecordBriefStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString UserName;									//var string UserName;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 GroupID;										//var int GroupID;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 UserID;										//var int UserID;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 Experience;									//var int Experience;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 Honor;										//var int Honor;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString CreationDate;								//var string CreationDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString LastLoginDate;								//var string LastLoginDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					float HoursPlayed;									//var float HoursPlayed;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString FavoriteMap;								//var string FavoriteMap;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 AverageScore;									//var int AverageScore;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 HeroesVisited;								//var int HeroesVisited;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 BetaUser;										//var int BetaUser;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MissionsCompleted;							//var int MissionsCompleted;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 RoundsWon;									//var int RoundsWon;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 RoundsLost;									//var int RoundsLost;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MatchesCompleted;								//var int MatchesCompleted;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ObjectivesCompleted;							//var int ObjectivesCompleted;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ObjectiveDeaths;								//var int ObjectiveDeaths;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MedpaksApplied;								//var int MedpaksApplied;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 TimesHealed;									//var int TimesHealed;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FWeaponRecordBrief WeaponUseRecords;				//var WeaponRecordBrief WeaponUseRecords;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ROE;											//var int ROE;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString version;									//var string version;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FQualificationRecordBrief QualificationRecords;		//var QualificationRecordBrief QualificationRecords;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 ToursCompletedBitset;							//var int ToursCompletedBitset;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					int32 MissionsCompletedBitset;						//var int MissionsCompletedBitset;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SquadLeaderSeconds;							//var string SquadLeaderSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString FireteamLeaderSeconds;						//var string FireteamLeaderSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SoldierSeconds;								//var string SoldierSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SquadLeaderLinkedSeconds;					//var string SquadLeaderLinkedSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString FireteamLeaderLinkedSeconds;				//var string FireteamLeaderLinkedSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SoldierLinkedSeconds;						//var string SoldierLinkedSeconds;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString MedicTourCompletionDate;					//var string MedicTourCompletionDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString AirborneTourCompletionDate;					//var string AirborneTourCompletionDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString AdvancedMarksmanshipTourCompletionDate;		//var string AdvancedMarksmanshipTourCompletionDate;
	UPROPERTY(EditAnywhere, Category = "RecordBriefStruct")					FString SpecialForcesTrainingTourCompletionDate;	//var string SpecialForcesTrainingTourCompletionDate;
};

USTRUCT(BlueprintType)
struct FPlayerEvents
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString PlayerName;								//var string PlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString Password;								//var string Password;
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
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsAsSoldier;							//var int SecondsAsSoldier;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Kills;									//var int Kills;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Deaths;									//var int Deaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsLinkedToSQL;						//var int SecondsLinkedToSQL;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsLinkedToFTL;						//var int SecondsLinkedToFTL;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 SecondsLinkedToSoldiers;					//var int SecondsLinkedToSoldiers;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 UsedMedic;								//var int UsedMedic;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Healed;									//var int Healed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 MedPaksUsed;								//var int MedPaksUsed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 Score;									//var int Score;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ROE;										//var int ROE;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 CapturedObjective;						//var int CapturedObjective;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ObjectiveDeaths;							//var int ObjectiveDeaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 AdminKicked;								//var int AdminKicked;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 PBKicked;									//var int PBKicked;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredGrenade;						//var int ShotsFiredGrenade;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredAstRifle;						//var int ShotsFiredAstRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredPistol;							//var int ShotsFiredPistol;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredMG;								//var int ShotsFiredMG;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredRocket;							//var int ShotsFiredRocket;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 ShotsFiredSprRifle;						//var int ShotsFiredSprRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsGrenade;								//var int HitsGrenade;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsAstRifle;								//var int HitsAstRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsPistol;								//var int HitsPistol;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsMG;									//var int HitsMG;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsRocket;								//var int HitsRocket;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 HitsSprRifle;								//var int HitsSprRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsGrenade;								//var int KillsGrenade;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsAstRifle;							//var int KillsAstRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsPistol;								//var int KillsPistol;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsMG;									//var int KillsMG;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsRocket;								//var int KillsRocket;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 KillsSprRifle;							//var int KillsSprRifle;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectAvailable;						//var int iESSObjectAvailable;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectDiscovered;						//var int iESSObjectDiscovered;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectExaminedByOtherPlayer;			//var int iESSObjectExaminedByOtherPlayer;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectDiscoveryRadioed;				//var int iESSObjectDiscoveryRadioed;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPostRadioExaminedObject;				//var int iESSPostRadioExaminedObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSNoRadioExaminedObject;				//var int iESSNoRadioExaminedObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPostRadioLinkedObjectTaken;			//var int iESSPostRadioLinkedObjectTaken;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSNoRadioLinkedObjectTaken;				//var int iESSNoRadioLinkedObjectTaken;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionFailureTime;					//var int iESSMissionFailureTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionSuccessTime;					//var int iESSMissionSuccessTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionProgressTime;					//var int iESSMissionProgressTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionTotalPlayers;					//var int iESSMissionTotalPlayers;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSMissionSurvivingPlayers;				//var int iESSMissionSurvivingPlayers;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportedLethal;					//var int iESSObjectReportedLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportedNonLethal;				//var int iESSObjectReportedNonLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportableLethal;				//var int iESSObjectReportableLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportableNonLethal;			//var int iESSObjectReportableNonLethal;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSObjectUnreportedLocations;			//var string iESSObjectUnreportedLocations;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectReportingErrors = 0;			//var int iESSObjectReportingErrors;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSObjectUnnecessaryUse = 0;				//var int iESSObjectUnnecessaryUse;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSObjectDistribution = "";			//var string iESSObjectDistribution;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatHeadshots = 0;					//var int iESSCombatHeadshots;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatTotalDamage	= 0;				//var int iESSCombatTotalDamage;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatTotalDamageRange = 0;			//var int iESSCombatTotalDamageRange;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatDamageCount;					//var int iESSCombatDamageCount;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatEnemyContactTime;				//var int iESSCombatEnemyContactTime;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSCombatAIKill;						//var string iESSCombatAIKill;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSCombatSurvivingAI;					//var int iESSCombatSurvivingAI;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSCombatSurvivingAILocation;			//var string iESSCombatSurvivingAILocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByAI;				//var int iESSPlayerTotalDeathsByAI;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByFriendlyFire;		//var int iESSPlayerTotalDeathsByFriendlyFire;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByObject;			//var int iESSPlayerTotalDeathsByObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSPlayerDeathLocation;				//var string iESSPlayerDeathLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuries;					//var int iESSPlayerTotalInjuries;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesByAI;				//var int iESSPlayerTotalInjuriesByAI;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesFriendlyFire;		//var int iESSPlayerTotalInjuriesFriendlyFire;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesByObject;			//var int iESSPlayerTotalInjuriesByObject;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSPlayerInjuryLocation;				//var string iESSPlayerInjuryLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROEFriendlyFireHits;					//var int iESSROEFriendlyFireHits;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROEFriendlyFireDeaths;				//var int iESSROEFriendlyFireDeaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROEFriendlyFireHitLocation;			//var string iESSROEFriendlyFireHitLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROEFriendlyFireDeathLocation;		//var string iESSROEFriendlyFireDeathLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROECivilianHits;						//var int iESSROECivilianHits;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROECivilianDeaths;					//var int iESSROECivilianDeaths;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					int32 iESSROECivilianDeathsByIED;				//var int iESSROECivilianDeathsByIED;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROECivilianHitMapLocation;			//var string iESSROECivilianHitMapLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROECivilianKillByPlayerMapLocation;	//var string iESSROECivilianKillByPlayerMapLocation;
	UPROPERTY(EditAnywhere, Category = "PlayerEvents")					FString iESSROECivilianKillByES2MapLocation;	//var string iESSROECivilianKillByES2MapLocation;
};


USTRUCT(BlueprintType)
struct FGameSpyServerItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bValid;								//var int bValid;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bOfficial;							//var int bOfficial;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bLeased;								//var int bLeased;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bNATO;								//var int bNATO;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bMiles;								//var int bMiles;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bPassword;							//var int bPassword;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bPunkBuster;							//var int bPunkBuster;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bCheats;								//var int bCheats;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bTournament;							//var int bTournament;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bExploreTheArmy;						//var int bExploreTheArmy;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bThirdParty;							//var int bThirdParty;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Name;								//var string Name;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString MapName;							//var string MapName;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString GameVer;							//var string GameVer;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Guid;								//var string Guid;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 IP;									//var int IP;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Port;									//var int Port;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 QueryPort;							//var int QueryPort;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Ping;									//var int Ping;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Index = 0;							//var int Index;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Tour;									//var int Tour;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 NumPlayers;							//var int NumPlayers;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MaxPlayers;							//var int MaxPlayers;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MinHonor;								//var int MinHonor;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MaxHonor;								//var int MaxHonor;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Groups;								//var string Groups;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 CustomFlags;							//var int CustomFlags;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					float Time;									//var float Time;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 NetOrderIP;							//var int NetOrderIP;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString Locale;								//var string Locale;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bRequiresAuthorization;				//var int bRequiresAuthorization;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 bCoop;								//var int bCoop;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 AverageHonor;							//var int AverageHonor;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 CurrentRound;							//var int CurrentRound;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 Addr;									//var int CurrentRound;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					FString OperatingSystem;					//var string OperatingSystem;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 AveragePlayerPing;					//var int AveragePlayerPing;
	UPROPERTY(EditAnywhere, Category = "GameSpyServerItem")					int32 MissionTimeRemaining;					//var int MissionTimeRemaining;
};

USTRUCT(BlueprintType)
struct FIpAddr
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "IpAddr")					int32 Addr;								//var int Addr;
	UPROPERTY(EditAnywhere, Category = "IpAddr")					int32 Port;								//var int Port;
};

USTRUCT(BlueprintType)
struct FBeaconInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "BeaconInfo")				FIpAddr Addr;							//var InternetLink.IpAddr Addr;
	UPROPERTY(EditAnywhere, Category = "BeaconInfo")				float Time;								//var float Time;
	UPROPERTY(EditAnywhere, Category = "BeaconInfo")				FString Text;							//var string Text;
};

USTRUCT(BlueprintType)
struct FMD5UpdateData
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, Category = "MD5UpdateData")				FString Guid;							//var string Guid;
	UPROPERTY(EditAnywhere, Category = "MD5UpdateData")				FString MD5;							//var string MD5;
	UPROPERTY(EditAnywhere, Category = "MD5UpdateData")				int32 Revision;							//var int Revision;
};


USTRUCT(BlueprintType)
struct FtMasterServerEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "tMasterServerEntry")		FString Address;						//var string Address;
	UPROPERTY(EditAnywhere, Category = "tMasterServerEntry")		int32 Port;								//var int Port;
};


USTRUCT(BlueprintType)
struct FAuthSurveyQuestion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		FString QuestionText;					//var string QuestionText;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		int32 UIComponentType;					//var int UIComponentType;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		bool bIsOptional;						//var bool bIsOptional;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		int32 NumAnswers;						//var int NumAnswers;
	UPROPERTY(EditAnywhere, Category = "AuthSurveyQuestion")		TArray<FString> AnswerText;				//var TArray<FString> AnswerText;
};

USTRUCT(BlueprintType)
struct FAuthSurvey
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				int32 SurveyID;							//var int SurveyID;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				FString SurveyTitle;					//var string SurveyTitle;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				FString SurveyDescription;				//var string SurveyDescription;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				bool bCompleted;						//var bool bCompleted;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				int32 ExperienceBonus;					//var int ExperienceBonus;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				int32 NumQuestions;						//var int NumQuestions;
	UPROPERTY(EditAnywhere, Category = "AuthSurvey")				TArray<FAuthSurveyQuestion> Questions;	//var array<AuthSurveyQuestion> Questions;
};

USTRUCT(BlueprintType)
struct FAuthSurveySubmission
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthSurveySubmission")		int32 SurveyID;							//var int SurveyID;
	UPROPERTY(EditAnywhere, Category = "AuthSurveySubmission")		TArray<int32> AnswerBits;				//var array<int> AnswerBits;
};

USTRUCT(BlueprintType)
struct FAuthInt64
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthInt64")					int32 LowPart;							//var int LowPart;
	UPROPERTY(EditAnywhere, Category = "AuthInt64")					int32 HighPart;							//var int HighPart;
};

USTRUCT(BlueprintType)
struct FAuthPersonnelJacket
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		FAuthInt64 UserID;						//var AuthInt64 UserID;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		FAuthInt64 GroupID;						//var AuthInt64 GroupID;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		bool bBanned;							//var bool bBanned;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 BanDuration;						//var int BanDuration;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 Experience;						//var int Experience;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 ExperienceNext;					//var int ExperienceNext;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 Honor;							//var int Honor;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 ToursCompleted;					//var int ToursCompleted;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 TourInfo;							//var int TourInfo;
	UPROPERTY(EditAnywhere, Category = "AuthPersonnelJacket")		int32 Marksmanship;						//var int Marksmanship;
};



USTRUCT(BlueprintType)
struct FPlayInfoData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString ThisProp;					//var Property ThisProp;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				AAA2_Info* ClassFrom;				//var class<Info>  ClassFrom;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString SettingName;				//var string SettingName;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString DisplayName;				//var string DisplayName;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Description;				//var string Description;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Grouping;					//var string Grouping;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Data;						//var string Data;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString ExtraPriv;					//var string ExtraPriv;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				FString Value;						//var string Value;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				EPlayInfoType RenderType;			//var EPlayInfoType RenderType;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				uint8 SecLevel;						//var byte SecLevel;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				uint8 Weight;						//var byte Weight;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bMPOnly;						//var bool bMPOnly;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bAdvanced;						//var bool bAdvanced;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bGlobal;						//var bool bGlobal;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				bool bStruct;						//var bool bStruct;
	UPROPERTY(EditAnywhere, Category = "PlayInfoData")				int32 ArrayDim;						//var int ArrayDim;
};

USTRUCT(BlueprintType)
struct FPlayerAdminAccounts
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "PlayerAdminAccounts")		FString sPlayerName;				//var string sPlayerName;
	UPROPERTY(EditAnywhere, Category = "PlayerAdminAccounts")		FString sPassword;					//var string sPassword;
};

USTRUCT(BlueprintType)
struct FBanDescription
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "BanDescription")			EBanType BanType;					//var EBanType BanType;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			int32 BanEndDate_LoWord;			//var int BanEndDate_LoWord;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			int32 BanEndDate_HiWord;			//var int BanEndDate_HiWord;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			FString Banee;						//var string Banee;
	UPROPERTY(EditAnywhere, Category = "BanDescription")			FString OriginalUserName;			//var string OriginalUserName;
};


USTRUCT(BlueprintType)
struct FGameRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString ClassName;					//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString GameName;					//var string GameName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString Description;				//var string Description;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString TextName;					//var string TextName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString GameAcronym;				//var string GameAcronym;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString MapListClassName;			//var string MapListClassName;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString MapPrefix;					//var string MapPrefix;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString ScreenshotRef;				//var string ScreenshotRef;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString HUDMenu;					//var string HUDMenu;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				FString RulesMenu;					//var string RulesMenu;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				bool bTeamGame;						//var bool bTeamGame;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				uint8 GameTypeGroup;				//var byte GameTypeGroup;
	UPROPERTY(EditAnywhere, Category = "GameRecord")				int32 RecordIndex;					//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FMutatorRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString ClassName;					//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString FriendlyName;				//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString Description;				//var string Description;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString IconMaterialName;			//var string IconMaterialName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString ConfigMenuClassName;		//var string ConfigMenuClassName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				FString GroupName;					//var string GroupName;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				int32 RecordIndex;					//var int RecordIndex;
	UPROPERTY(EditAnywhere, Category = "MutatorRecord")				uint8 bActivated;					//var byte bActivated;
};

USTRUCT(BlueprintType)
struct FMapRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString Acronym;						//var string Acronym;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString MapName;						//var string MapName;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString TextName;						//var string TextName;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString Author;							//var string Author;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					float Description;						//var string Description;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					int32 PlayerCountMin;					//var int PlayerCountMin;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					int32 PlayerCountMax;					//var int PlayerCountMax;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString ScreenshotRef;					//var string ScreenshotRef;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					FString ExtraInfo;						//var string ExtraInfo;
	UPROPERTY(EditAnywhere, Category = "MapRecord")					int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FWeaponRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString ClassName;						//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString PickupClassName;				//var string PickupClassName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString AttachmentClassName;			//var string AttachmentClassName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString Description;					//var string Description;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString TextName;						//var string TextName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "WeaponRecord")				int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FVehicleRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				FString ClassName;						//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				FString Description;					//var string Description;
	UPROPERTY(EditAnywhere, Category = "VehicleRecord")				int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FCrosshairRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "CrosshairRecord")			FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "CrosshairRecord")			UTexture* CrosshairTexture;				//var Texture CrosshairTexture;
	UPROPERTY(EditAnywhere, Category = "CrosshairRecord")			int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FAnnouncerRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString ClassName;						//var string ClassName;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString PackageName;					//var string PackageName;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			FString FallbackPackage;				//var string FallbackPackage;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			bool bEnglishOnly;						//var bool bEnglishOnly;
	UPROPERTY(EditAnywhere, Category = "AnnouncerRecord")			int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FStandard
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Standard")					TArray<FString> Classes;					//	var TArray<FString> Classes;
	UPROPERTY(EditAnywhere, Category = "Standard")					TArray<FString> Maps;						//var TArray<FString> Maps;
};





USTRUCT(BlueprintType)
struct FTestOffset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "TestOffset")				float H;						//var float H;
	UPROPERTY(EditAnywhere, Category = "TestOffset")				float V;						//var float V;

};

USTRUCT(BlueprintType)
struct FNPCPSAnimSequenceSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				FName animStart;						//var name animStart;
	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				FName animMiddle;						//var name animMiddle;
	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				FName AnimEnd;							//var name AnimEnd;
	UPROPERTY(EditAnywhere, Category = "NPCPSAnimSequenceSet")				bool bShoulderWeaponFirst;				//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FNPCPSAttachObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				AActor* Attachment;				//var class<Actor>  Attachment;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				FName Bone;						//var name Bone;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				FVector LocationOffset = FVector(0, 0, 0);			//var var FVector LocationOffset;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				FRotator RotationOffset = FRotator(0, 0, 0);		//var Object.Rotator RotationOffset;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				bool bUseParentScale;			//var bool bUseParentScale;
	UPROPERTY(EditAnywhere, Category = "NPCPSAttachObject")				float Scale;					//var float Scale;
};

USTRUCT(BlueprintType)
struct FSoundEmitter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				float EmitInterval;						//var float EmitInterval;
	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				float EmitVariance;						//var float EmitVariance;
	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				float EmitTime;							//var float EmitTime;
	UPROPERTY(EditAnywhere, Category = "SoundEmitter")				USoundBase* EmitSound;					//var Sound EmitSound;
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
