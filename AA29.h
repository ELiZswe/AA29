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

USTRUCT(BlueprintType)
struct FNPCSquadDetails
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSquadDetails")			ANPCNCOController*					npcncoLeader;			//var NPCNCOController npcncoLeader;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSquadDetails")			TArray<ANPCBaseSoldierController*>	npcscMembers;			//var TArray<NPCBaseSoldierController> npcscMembers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSquadDetails")			int32								iSquadOrders;			//var int32 iSquadOrders;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSquadDetails")			float								fpTimeSinceLastOrders;	//var float fpTimeSinceLastOrders;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSquadDetails")			bool								bSquadDead;				//var bool bSquadDead;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSquadDetails")			int32								iAmbushSet;				//var int32 iAmbushSet;
};

USTRUCT(BlueprintType)
struct FNPCPlatoons
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPlatoons")			FNPCSquadDetails		anpcsdSquads;			//var NPCSquadDetails anpcsdSquads[8];
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPlatoons")			FString					sPlatoonName;			//var FString sPlatoonName;
};

USTRUCT(BlueprintType)
struct FEnemyContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			ANPCBaseController*		npcbcReporting;			//var NPCBaseController npcbcReporting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			APawn*					pawnEnemyContact;		//var Pawn pawnEnemyContact;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			int32					iContactType;			//var int32 iContactType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			FVector					vLocation;				//var Vector vLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			FRotator				rotRotation;			//var Rotator rotRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			float					fpEstimatedRange;		//var float fpEstimatedRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			int32					iThreatLevel;			//var int32 iThreatLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			float					fpTimeOfReport;			//var float fpTimeOfReport;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyContact")			bool					bContactLost;			//var bool bContactLost;
};

USTRUCT(BlueprintType)
struct FOrderQueue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			ANPCBaseController*		npcbc;					//var NPCBaseController npcbc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			int32					iSupportRequest;		//var int32 iSupportRequest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			bool					bOrderForAll;			//var bool bOrderForAll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			FString					sAICCCombatAction;		//var FString sAICCCombatAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			int32					iOrder;					//var int32 iOrder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			int32					iTacticalOrder;			//var int32 iTacticalOrder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			float					fpTimeToDeliver;		//var float fpTimeToDeliver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			FVector					vSupportArea;			//var Vector vSupportArea;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			APawn*					pawnTarget;				//var Pawn pawnTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrderQueue")			bool					bSmokeMission;			//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FFireMissionInFlight
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireMissionInFlight")			FVector				vTargetArea;			//var Vector vTargetArea;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireMissionInFlight")			float				fpSpawnTime;			//var float fpSpawnTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireMissionInFlight")			float				fpSkill;				//var float fpSkill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireMissionInFlight")			APawn*				pawnSpotter;			//var Pawn pawnSpotter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireMissionInFlight")			bool				bSmokeMission;			//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FSupportFireRequestQueue
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			ANPCBaseSoldierController*	npcbscSpotter;			//var NPCBaseSoldierController npcbscSpotter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			float						fpSkillLevel;			//var float fpSkillLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			int32						iSupportType;			//var int32 iSupportType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			int32						iRoundsToFire;			//var int32 iRoundsToFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			float						fpTimeToFire;			//var float fpTimeToFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			float						fpTimeToSpawn;			//var float fpTimeToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			FVector						vTargetArea;			//var Vector vTargetArea;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SupportFireRequestQueue")			bool						bSmokeMission;			//var bool bSmokeMission;
};

USTRUCT(BlueprintType)
struct FMortarRangeTable
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MortarRangeTable")			float				fpMin;				//var float fpMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MortarRangeTable")			float				fpMax;				//var float fpMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MortarRangeTable")			float				fpFlightTime;		//var float fpFlightTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MortarRangeTable")			float				fpAngle;			//var float fpAngle;
};

USTRUCT(BlueprintType)
struct FReinforcementRespawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ReinforcementRespawn")			ASmallNavigationPoint*		snpStart;				//var SmallNavigationPoint snpStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ReinforcementRespawn")			int32						iRespawnsLeft;			//var int32 iRespawnsLeft;
};


USTRUCT(BlueprintType)
struct FLensFlareDescriptor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LensFlareDescriptor")			UMaterialInstance*	LensFlareMaterial;		//var Material LensFlareMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LensFlareDescriptor")			FColor				LensFlareColor;			//var Color LensFlareColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LensFlareDescriptor")			float				LensFlareOffset;		//var float LensFlareOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LensFlareDescriptor")			float				LensFlareRadius_Min;	//var float LensFlareRadius_Min;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LensFlareDescriptor")			float				LensFlareRadius_Max;	//var float LensFlareRadius_Max;
};

USTRUCT(BlueprintType)
struct FAA2_ProcMeshVertex
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProcMeshVertex")				FVector				Position;		//var Vector Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProcMeshVertex")				FVector				Normal;			//var Vector Normal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProcMeshVertex")				FColor				Color;			//var Color Color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProcMeshVertex")				float				U;				//var float U;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProcMeshVertex")				float				V;				//var float V;
};


USTRUCT(BlueprintType)
struct FConvSpeech
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConvSpeech")					FString				sMemberName;			//var FString sMemberName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConvSpeech")					FName				nameLipSynchAudio;		//var FName nameLipSynchAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConvSpeech")					FName				nameAnimation;			//var FName nameAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConvSpeech")					USoundBase*			sndNonLSAudio;			//var Sound sndNonLSAudio;
};

USTRUCT(BlueprintType)
struct FAnimInfo2
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					FName				SeqName;			//var FName SeqName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					float				AnimFrame;			//var float AnimFrame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					float				AnimRate;			//var float AnimRate;
};


USTRUCT(BlueprintType)
struct FFireProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					AAmmunition*		AmmoClass;				//var class<Ammunition>  AmmoClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					AProjectile*		ProjectileClass;		//var class<Projectile>  ProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					float				WarnTargetPct;			//var float WarnTargetPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					float				MaxRange;				//var float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					bool				bTossed;				//var bool bTossed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					bool				bTrySplash;				//var bool bTrySplash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					bool				bLeadTarget;			//var bool bLeadTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					bool				bInstantHit;			//var bool bInstantHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireProperties")					bool				bInitialized;			//var bool bInitialized;
};

USTRUCT(BlueprintType)
struct FAnimInstruction
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInstruction")					EeAnimationCommand	Command;			//var eAnimationCommand Command;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInstruction")					FName				Sequence;			//var FName Sequence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInstruction")					float				Rate;				//var float Rate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInstruction")					float				Time;				//var float Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInstruction")					int32				Channel;			//var int32 Channel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInstruction")					int32				LoopNum;			//var int32 LoopNum;
};


USTRUCT(BlueprintType)
struct FArrayControl
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRBVec")					UGUIButton* b_New;				//var XInterface.GUIButton b_New;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRBVec")					UGUIButton* b_Remove;			//var XInterface.GUIButton b_Remove;
};
USTRUCT(BlueprintType)
struct FKRBVec
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRBVec")					float X;						//var float X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRBVec")					float Y;						//var float Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRBVec")					float Z;						//var float Z;
};


USTRUCT(BlueprintType)
struct FUAVState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					FKRBVec ChassisPosition;				//var Actor.KRBVec ChassisPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					FQuat ChassisQuaternion;				//var Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					FKRBVec ChassisLinVel;					//var Actor.KRBVec ChassisLinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					FKRBVec ChassisAngVel;					//var Actor.KRBVec ChassisAngVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					float ServerThrust;						//var float ServerThrust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					float ServerStrafe;						//var float ServerStrafe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					float ServerRise;						//var float ServerRise;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVState")					int32 bNewState;						//var int32 bNewState;
};

USTRUCT(BlueprintType)
struct FHelicopterState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			FKRBVec ChassisPosition;		//var Actor.KRBVec ChassisPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			FQuat ChassisQuaternion;		//var Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			FKRBVec ChassisLinVel;			//var Actor.KRBVec ChassisLinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			FKRBVec ChassisAngVel;			//var Actor.KRBVec ChassisAngVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			float ServerThrust;				//var float ServerThrust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			float ServerStrafe;				//var float ServerStrafe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			float ServerRise;				//var float ServerRise;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterState")			int32 bNewState;				//var int32 bNewState;
};

USTRUCT(BlueprintType)
struct FCoords
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coords")					FVector Origin;						//var config Vector Origin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coords")					FVector XAxis;						//var config Vector XAxis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coords")					FVector YAxis;						//var config Vector YAxis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coords")					FVector ZAxis;						//var config Vector ZAxis;
};

USTRUCT(BlueprintType)
struct FEffectMatProps
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectMatProps")					bool bNoEffect;							//var bool bNoEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectMatProps")					FColor DirtColor;						//var Color DirtColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectMatProps")					float DirtAmount;						//var float DirtAmount;
};

USTRUCT(BlueprintType)
struct FRange
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								float Min;								//var float Min;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								float Max;								//var float Max;
};

USTRUCT(BlueprintType)
struct FParticleAnchor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleAnchor")						FName Tag;							//var FName Tag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleAnchor")						float Position;						//var float Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleAnchor")						AActor* Actor;						//var AActor* Actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleAnchor")						int32 Index;						//var int32 Index;
};

USTRUCT(BlueprintType)
struct FAttachedPawnInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachedPawnInfo")						float Index;						//var float Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachedPawnInfo")						float nextUpateTime;				//var float nextUpateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachedPawnInfo")						float updateTime;					//var float updateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttachedPawnInfo")						float percent;						//var float percent;
};

USTRUCT(BlueprintType)
struct FRangeVector
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RangeVector")						FRange X;							//var Range X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RangeVector")						FRange Y;							//var Range Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RangeVector")						FRange Z;							//var Range Z;
};

USTRUCT(BlueprintType)
struct FParticleBeamData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamData")					FVector Location;					//var Vector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamData")					float t;							//var float t;
};

USTRUCT(BlueprintType)
struct FParticleBeamEndPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamEndPoint")				FName ActorTag;						//var FName ActorTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamEndPoint")				FRangeVector offset;				//var RangeVector offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamEndPoint")				float Weight;						//var float Weight;
};

USTRUCT(BlueprintType)
struct FParticleBeamScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamScale")					FVector FrequencyScale;				//var Vector FrequencyScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleBeamScale")					FVector RelativeLength;				//var float RelativeLength;
};

USTRUCT(BlueprintType)
struct FParticleSparkData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSparkData")					FVector TimeBeforeVisible;					//var float TimeBeforeVisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSparkData")					FVector TimeBetweenSegments;				//var float TimeBetweenSegments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSparkData")					FVector StartLocation;						//var Vector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSparkData")					FVector StartVelocity;						//var Vector StartVelocity;
};

USTRUCT(BlueprintType)
struct FParticleTrailData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								FVector Location;							//var Vector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								FColor Color;								//var Color Color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								float Size;									//var float Size;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								int32 DoubleDummy1;							//var int32 DoubleDummy1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								int32 DoubleDummy2;							//var int32 DoubleDummy2;
};

USTRUCT(BlueprintType)
struct FParticleTrailInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								int32 TrailIndex;							//var int32 TrailIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								int32 NumPoints;							//var int32 NumPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								FVector LastLocation;						//var Vector LastLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")								FVector LastEmitterLocation;				//var Vector LastEmitterLocation;
};

USTRUCT(BlueprintType)
struct FParticleTimeScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleTimeScale")					float RelativeTime;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleTimeScale")					float RelativeSize;							//var float RelativeSize;
};

USTRUCT(BlueprintType)
struct FParticleRevolutionScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleRevolutionScale")			float RelativeTime;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleRevolutionScale")			FVector RelativeRevolution;					//var Vector RelativeRevolution;
};

USTRUCT(BlueprintType)
struct FParticleColorScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleColorScale")					float RelativeTime;						//var float RelativeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleColorScale")					FColor Color;							//var Color Color;
};

USTRUCT(BlueprintType)
struct FParticleVelocityScale
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleVelocityScale")					float RelativeTime;							//var float RelativeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleVelocityScale")					FVector RelativeVelocity;						//var Vector RelativeVelocity;
};

USTRUCT(BlueprintType)
struct FParticle
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector Location;						//var Vector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector OldLocation;					//var Vector OldLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector Velocity;						//var Vector Velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector StartSize;						//var Vector StartSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector SpinsPerSecond;					//var Vector SpinsPerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector StartSpin;						//var Vector StartSpin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector RevolutionCenter;				//var Vector RevolutionCenter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector RevolutionsPerSecond;			//var Vector RevolutionsPerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector RevolutionsMultiplier;			//var Vector RevolutionsMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector Size;							//var Vector Size;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector StartLocation;					//var Vector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector ColorMultiplier;				//var Vector ColorMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector VelocityMultiplier;				//var Vector VelocityMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FVector OldMeshLocation;				//var Vector OldMeshLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					FColor Color;							//var Color Color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					float Time;								//var float Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					float MaxLifetime;						//var float MaxLifetime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					float Mass;								//var float Mass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					int32 HitCount;							//var int32 HitCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					int32 Flags;							//var int32 Flags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					int32 Subdivision;						//var int32 Subdivision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					int32 BoneIndex;						//var int32 BoneIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					uint8 NumFramesRendered;				//var uint8 NumFramesRendered;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")					float FadeTime;							//var float FadeTime;
};

USTRUCT(BlueprintType)
struct FParticleSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSound")					USoundBase* Sound;						//var Sound Sound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSound")					FRange Radius;							//var Range Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSound")					FRange Pitch;							//var Range Pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSound")					int32 Weight;							//var int32 Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSound")					FRange Volume;							//var Range Volume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSound")					FRange Probability;						//var Range Probability;
};

USTRUCT(BlueprintType)
struct FGameSpyPlayerInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					int32 Honor;							//var int Honor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					FString Name;							//var string Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					int32 Score_Total;						//var int Score_Total;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					int32 Enemy;							//var int Enemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					int32 KIA;								//var int KIA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					int32 ROE;								//var int ROE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyPlayerInfo")					int32 Ping;								//var int Ping;
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
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString FullName;							//var FString FullName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Name;								//var FString Name;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Path;								//var FString Path;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						int32 FileLength;							//var int32 FileLength;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString SHA;								//var FString SHA;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString Date;								//var FString Date;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						int32 bShouldRemove;						//var int32 bShouldRemove;
};

USTRUCT(BlueprintType)
struct FAA2_AssetMapping
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString AssetName;								//var FString AssetName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString AssetFileName;							//var FString AssetFileName;
	UPROPERTY(BlueprintReadWrite, Category = "AA2_AssetMapping")						FString AssetTitle;								//var FString AssetTitle;
};

USTRUCT(BlueprintType)
struct FKeyValuePair
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "KeyValuePair")						FString Key;								//var string Key;
	UPROPERTY(BlueprintReadWrite, Category = "KeyValuePair")						FString Value;								//var string Value;
};


USTRUCT(BlueprintType)
struct FPlayerResponseLine
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")					int32 PlayerNum;							//var int PlayerNum;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")					FString PlayerName;							//var string PlayerName;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")					int32 Ping;									//var int Ping;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")					int32 Score;								//var int Score;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerResponseLine")					int32 StatsID;								//var int StatsID;
};



USTRUCT(BlueprintType)
struct FServerResponseLine
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 ServerID;								//var int ServerID;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					FString IP;									//var string IP;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 Port;									//var int Port;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 QueryPort;							//var int QueryPort;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					FString ServerName;							//var string ServerName;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					FString MapName;							//var string MapName;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					FString GameType;							//var string GameType;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 CurrentPlayers;						//var int CurrentPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 MaxPlayers;							//var int MaxPlayers;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 Ping;									//var int Ping;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					int32 Flags;								//var int Flags;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					FString SkillLevel;							//var string SkillLevel;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					TArray<FKeyValuePair>  ServerInfo;			//var array<KeyValuePair> ServerInfo;
	UPROPERTY(BlueprintReadWrite, Category = "ServerResponseLine")					TArray<FPlayerResponseLine> PlayerInfo;		//var array<PlayerResponseLine> PlayerInfo;
};


USTRUCT(BlueprintType)
struct FHeaderColumnPos
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeaderColumnPos")			TArray<float> ColumnSizes;		//var TArray<float> ColumnSizes;
};

USTRUCT(BlueprintType)
struct FeServerCacheInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FeServerCacheInfo")			FString GameType;				//var FString GameType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FeServerCacheInfo")			int32 SubnetIndex;				//var int32 SubnetIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FeServerCacheInfo")			FServerResponseLine SRL;		//var GameInfo.ServerResponseLine SRL;
};


USTRUCT(BlueprintType)
struct FUAVFlightPlannerWaypoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVFlightPlannerWaypoint")		FVector vLocation;			//var Vector vLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVFlightPlannerWaypoint")		float fpHeight;				//var float fpHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVFlightPlannerWaypoint")		float fpSpeed;				//var float fpSpeed;
};


USTRUCT(BlueprintType)
struct FLayoutItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LayoutItem")		UGUIComponent* Component;				//var UGUIComponent* Component;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LayoutItem")		EeCellAlign Alignment;					//var eCellAlign Alignment;
};

USTRUCT(BlueprintType)
struct FBadge
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Badge")		FString BadgeName;					//var string BadgeName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Badge")		FString BadgeDescription;			//var string BadgeDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Badge")		UMaterialInstance* BadgeImage;		//var Material BadgeImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Badge")		FString MenuPath;					//var string MenuPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Badge")		FString MenuParam1;					//var string MenuParam1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Badge")		FString MenuParam2;					//var string MenuParam2;
};

USTRUCT(BlueprintType)
struct FActiveFilter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActiveFilter")		FString CategoryName;					//var string CategoryName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActiveFilter")		FString FilterName;						//var string FilterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActiveFilter")		FString FilterChoiceLabel;				//var string FilterChoiceLabel;
};


USTRUCT(BlueprintType)
struct FActiveFilterSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActiveFilterSet")		TArray<FActiveFilter> List;			//var array<ActiveFilter> List;
};

USTRUCT(BlueprintType)
struct FReport
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FReport")			int32 ListID;							//var int ListID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FReport")			FString Ping;							//var string Ping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FReport")			FString receive;						//var string receive;
};

USTRUCT(BlueprintType)
struct FFilterItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterItem")		FString Key;							//var string Key;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterItem")		FString Value;							//var string Value;
};

USTRUCT(BlueprintType)
struct FFilterChoice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterChoice")		FString Label;							//var string Label;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterChoice")		TArray<FFilterItem> DBMBSFilters;		//var array<ServerBrowserBase.FilterItem> DBMBSFilters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterChoice")		FString GameSpyFilter;					//var string GameSpyFilter;
};

USTRUCT(BlueprintType)
struct FFilterDesc
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterDesc")		FString CategoryName;					//var string CategoryName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterDesc")		FString FilterName;						//var string FilterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterDesc")		TArray<FFilterChoice> Choices;			//var array<FilterChoice> Choices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilterDesc")		bool RuntimeChoiceGeneration;			//var bool RuntimeChoiceGeneration;
};

USTRUCT(BlueprintType)
struct FQueryData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueryData")		FString Key;							//var string Key;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueryData")		FString Value;							//var string Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueryData")		EQueryType QueryType;					//var EQueryType QueryType;
};

USTRUCT(BlueprintType)
struct FAFilterRule
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AFilterRule")	FString FilterItem;						//var MasterServerClient.QueryData FilterItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AFilterRule")	EDataType FilterType;					//var EDataType FilterType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AFilterRule")	FString ItemName;						//var string ItemName;
};
USTRUCT(BlueprintType)
struct FCurrentFilter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentFilter")	FAFilterRule Item;							//var CustomFilter.AFilterRule Item;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentFilter")	int32 ItemIndex;							//var int ItemIndex;
};

USTRUCT(BlueprintType)
struct FFavoriteServer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FavoriteServer")	FString IPAddress;							//var string IPAddress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FavoriteServer")	int32 Port;									//var int Port;
};

USTRUCT(BlueprintType)
struct FMultiColumnSortData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiColumnSortData")	FString SortString;						//var string SortString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiColumnSortData")	int32 SortItem;							//var int SortItem;
};


USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")			FString PlayerName;						//var string PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")			FString PlayerID;						//var string PlayerID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")			FString PlayerIP;						//var string PlayerIP;
};

USTRUCT(BlueprintType)
struct FSprite
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite")				ASpriteSlave* Sprite;					//var SpriteSlave Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite")				float MinFadeValue;						//var float MinFadeValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite")				float MaxFadeValue;						//var float MaxFadeValue;
};

USTRUCT(BlueprintType)
struct FVehicleWeaponAIInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				bool bTossed;							//var bool bTossed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				bool bTrySplash;						//var bool bTrySplash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				bool bLeadTarget;						//var bool bLeadTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				bool bInstantHit;						//var bool bInstantHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				bool bFireOnRelease;					//var bool bFireOnRelease;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				float aimerror;							//var float aimerror;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				float WarnTargetPct;					//var float WarnTargetPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				float RefireRate;						//var float RefireRate;
};

USTRUCT(BlueprintType)
struct FBodyPanelStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				ABodyPanel* ClassType;					//var class<AGP.BodyPanel>  ClassType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				UStaticMesh* Mesh;						//var StaticMesh Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				FName AttachBone;						//var name AttachBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				FName EntryBone;						//var name EntryBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				int32 EntryRadius;						//var int EntryRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				int32 EntryPosIndex;					//var int EntryPosIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				FString ExteriorHintText;				//var string ExteriorHintText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				UStaticMesh* DamagedMesh;				//var StaticMesh DamagedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				int32 bInvincible;						//var int bInvincible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				int32 bAcceptsProjectileDamage;			//var int bAcceptsProjectileDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BodyPanelStruct")				int32 bDisableCollision;				//var int bDisableCollision;
};

USTRUCT(BlueprintType)
struct FDriverWeaponStruct
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DriverWeaponStruct")				AVehicleWeapon* WeaponClass;			//var class<VehicleWeapon>  WeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DriverWeaponStruct")				FName WeaponBone;						//var name WeaponBone;
};

USTRUCT(BlueprintType)
struct FVehiclePositionStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePositionStruct")				AVehiclePosition* VehiclePositionClass;		//var class<VehiclePosition>  VehiclePositionClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePositionStruct")				FName WeaponBone;							//var name WeaponBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePositionStruct")				FName PositionBone;							//var name PositionBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePositionStruct")				FVector FPCameraOffset;						//var Object.Vector FPCameraOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePositionStruct")				FVector PosOffset;							//var Object.Vector PosOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePositionStruct")				FRotator RotOffset;							//var Object.Rotator RotOffset;
};

USTRUCT(BlueprintType)
struct FsDamageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				UaDamageType* AcceptsDamage;				//var class<DamageType>  AcceptsDamage;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				AAGP_VehicleParticles* DamageEffect;				//var class<AGP_Effects.AGP_VehicleParticles>  DamageEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Front_Left;					//var float AM_Front_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Front_Right;					//var float AM_Front_Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Back_Left;						//var float AM_Back_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Back_Right;					//var float AM_Back_Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Undercarriage;					//var float AM_Undercarriage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Turret;						//var float AM_Turret;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Roof;							//var float AM_Roof;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Tread_Left;					//var float AM_Tread_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Tread_Right;					//var float AM_Tread_Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Wheels_Left;					//var float AM_Wheels_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float AM_Wheels_Right;					//var float AM_Wheels_Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "sDamageInfo")				float DamageEffectPct;					//var float DamageEffectPct;
};

USTRUCT(BlueprintType)
struct FTestDamageZoneInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				FName ZoneName;							//var name ZoneName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				uint8 ZoneNumber;						//var byte ZoneNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				int32 ArmorThreshold;					//var int ArmorThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				int32 MaxHitPoints;						//var int MaxHitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				uint8 bInitialSyncToVehicleHealth;		//var byte bInitialSyncToVehicleHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				uint8 bNoPassDamageToVehicle;			//var byte bNoPassDamageToVehicle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				float DamageModifier;					//var float DamageModifier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				float DS1HealthPct;						//var float DS1HealthPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestDamageZoneInfo")				float DS2HealthPct;						//var float DS2HealthPct;
};

USTRUCT(BlueprintType)
struct FIniParticleInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IniParticleInfo")				FName ZoneName;						//var name ZoneName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IniParticleInfo")				FString DS1ParticleString;			//var string DS1ParticleString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IniParticleInfo")				FString DS2ParticleString;			//var string DS2ParticleString;
};


USTRUCT(BlueprintType)
struct FActorAttachment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorAttachment")				AActor* attachClass;				//var class<Actor>  attachClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorAttachment")				FName AttachBone;					//var name AttachBone;
};

USTRUCT(BlueprintType)
struct FImpactInfoStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImpactInfoStruct")				AActor* Other;					//var AActor* Other;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImpactInfoStruct")				FVector pos;					//var Object.Vector pos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImpactInfoStruct")				FVector impactVel;				//var Object.Vector impactVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImpactInfoStruct")				FVector impactNorm;				//var Object.Vector impactNorm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImpactInfoStruct")				FVector ImpactAccel;			//var Object.Vector ImpactAccel;
};

USTRUCT(BlueprintType)
struct FTrackedCraftState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				FVector ChassisPosition;			//var Object.Vector ChassisPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				FQuat ChassisQuaternion;			//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				FVector ChassisLinVel;				//var Object.Vector ChassisLinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				FVector ChassisAngVel;				//var Object.Vector ChassisAngVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				uint8 ServerThrust;					//var byte ServerThrust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				uint8 ServerTurn;					//var byte ServerTurn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				int32 ServerViewPitch;				//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrackedCraftState")				int32 ServerViewYaw;				//var int ServerViewYaw;
};

USTRUCT(BlueprintType)
struct FSCarState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				FVector ChassisPosition;				//var Object.Vector ChassisPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				FQuat ChassisQuaternion;				//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				FVector ChassisLinVel;					//var Object.Vector ChassisLinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				FVector ChassisAngVel;					//var Object.Vector ChassisAngVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				uint8 ServerHandbrake;					//var byte ServerHandbrake;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				uint8 ServerBrake;						//var byte ServerBrake;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				uint8 ServerGas;						//var byte ServerGas;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				uint8 ServerGear;						//var byte ServerGear;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				uint8 ServerSteering;					//var byte ServerSteering;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				int32 ServerViewPitch;					//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SCarState")				int32 ServerViewYaw;					//var int ServerViewYaw;
};

/*
USTRUCT(BlueprintType)
struct FInterpCurvePoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InterpCurvePoint")				float InVal;					//var float InVal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InterpCurvePoint")				float OutVal;					//var float OutVal;
};

USTRUCT(BlueprintType)
struct FInterpCurve
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")				TArray<FInterpCurvePoint> Points;		//var array<InterpCurvePoint> Points;
};
*/


USTRUCT(BlueprintType)
struct FPlaneStateStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				FKRBVec ChassisPosition;		//var Actor.KRBVec ChassisPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				FQuat ChassisQuaternion;		//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				FKRBVec ChassisLinVel;			//var Actor.KRBVec ChassisLinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				FKRBVec ChassisAngVel;			//var Actor.KRBVec ChassisAngVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				float ServerThrust;				//var float ServerThrust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				float ServerStrafe;				//var float ServerStrafe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				float ServerRise;				//var float ServerRise;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				int32 ServerViewPitch;			//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaneStateStruct")				int32 ServerViewYaw;			//var int ServerViewYaw;
};


USTRUCT(BlueprintType)
struct FKRigidBodyState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRigidBodyState")				FKRBVec Position;				//var KRBVec Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRigidBodyState")				FQuat Quaternion;				//var Object.Quat Quaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRigidBodyState")				FKRBVec LinVel;					//var KRBVec LinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KRigidBodyState")				FKRBVec AngVel;					//var KRBVec AngVel;
};

USTRUCT(BlueprintType)
struct FCopterState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					FVector ChassisPosition;		//var Object.Vector ChassisPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					FQuat ChassisQuaternion;		//var Object.Quat ChassisQuaternion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					FVector ChassisLinVel;			//var Object.Vector ChassisLinVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					FVector ChassisAngVel;			//var Object.Vector ChassisAngVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					uint8 ServerThrust;				//var byte ServerThrust;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					uint8 ServerStrafe;				//var byte ServerStrafe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					uint8 ServerRise;				//var byte ServerRise;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					int32 ServerViewPitch;			//var int ServerViewPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CopterState")					int32 ServerViewYaw;			//var int ServerViewYaw;
};


USTRUCT(BlueprintType)
struct FSVehicleIcon
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SVehicleIcon")					UMaterialInstance* Material;		//var Material Material;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SVehicleIcon")					float X;							//var float X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SVehicleIcon")					float Y;							//var float Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SVehicleIcon")					float SizeX;						//var float SizeX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SVehicleIcon")					float SizeY;						//var float SizeY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SVehicleIcon")					bool bIsGreyScale;					//var bool bIsGreyScale;
};



USTRUCT(BlueprintType)
struct FMapItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapItem")					FString MapName;					//var string MapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapItem")					FString OptionString;				//var string OptionString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapItem")					FString FullURL;					//var string FullURL;


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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecordGroup")					FString GameType;						//var string GameType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecordGroup")					FString ActiveMaplist;					//var string ActiveMaplist;
};

USTRUCT(BlueprintType)
struct FMaplistRecordGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaplistRecordGroup")				FString GameType;						//var string GameType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaplistRecordGroup")				int32 Active;							//var int Active;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaplistRecordGroup")				int32 LastActive;						//var int LastActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaplistRecordGroup")				TArray<FMapItem> AllMaps;				//var array<MaplistRecord.MapItem> AllMaps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaplistRecordGroup")				TArray<UMaplistRecord*> Records;		//var array<MaplistRecord> Records;
};

USTRUCT(BlueprintType)
struct FKeyInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyInfo")				FString Alias;										//var string Alias;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyInfo")				FString KeyLabel;									//var string KeyLabel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyInfo")				bool bIsSection;									//var bool bIsSection;
};

USTRUCT(BlueprintType)
struct FBoneEditVars
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneEditVars")			FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneEditVars")			float Radius;										//var float Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneEditVars")			bool bCheckCaps;									//var bool bCheckCaps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneEditVars")			float DamageModifier;								//var float DamageModifier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneEditVars")			EBoneRegion BoneRegion;								//var Object.EBoneRegion BoneRegion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneEditVars")			int32 BoneIdx;										//var int BoneIdx;
};

USTRUCT(BlueprintType)
struct FPlaylistParser
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaylistParser")			EStreamPlaylistType Type;						//var StreamBase.EStreamPlaylistType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlaylistParser")			FString ParserClass;							//var string ParserClass;
};

USTRUCT(BlueprintType)
struct FHtmlChar
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HtmlChar")					FString Plain;									//var string Plain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HtmlChar")					FString Coded;									//var string Coded;
};


USTRUCT(BlueprintType)
struct Fpointer
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "pointer")				int32 Dummy;										//var native const int Dummy;
};

/*
USTRUCT(BlueprintType)
struct FFilePath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilePath")					FString FullPath;									//var string FullPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilePath")					FString Directory;									//var string Directory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilePath")					FString Filename;									//var string Filename;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilePath")					FString Extension;									//var string Extension;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FilePath")					TArray<FString> DirectoryParts;						//var array<String> DirectoryParts;
};
*/

USTRUCT(BlueprintType)
struct FID3Field
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FID3Field")					Fpointer ID3Field;									//var pointer ID3Field;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FID3Field")					FString FieldName;									//var string FieldName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FID3Field")					FString FieldValue;									//var string FieldValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FID3Field")					uint8 FieldID;										//var byte FieldID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FID3Field")					uint8 Code;											//var byte Code;
};


/*
USTRUCT(BlueprintType)
struct FInterpCurvePoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InterpCurvePoint")					float InVal;											//var float InVal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InterpCurvePoint")					float OutVal;											//var float OutVal;
};

USTRUCT(BlueprintType)
struct FInterpCurve
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InterpCurve")						TArray<FInterpCurvePoint> Points;						//var array<InterpCurvePoint> Points;
};
*/

USTRUCT(BlueprintType)
struct FSpeechReplacement
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpeechReplacement")					TArray< FString> MatchWords;							//var array<String> MatchWords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpeechReplacement")					FString ReplaceWord;									//var string ReplaceWord;
};


USTRUCT(BlueprintType)
struct Ft_VideoMode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "t_VideoMode")						int32 X;												//var int X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "t_VideoMode")						int32 Y;												//var int Y;
};

USTRUCT(BlueprintType)
struct FLine
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")								FString Text;											//var string Text;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")								int32 ix;												//var int ix;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")								int32 iY;												//var int iY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")								int32 iScaledX;											//var int iScaledX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")								int32 iScaledY;											//var int iScaledY;
};
USTRUCT(BlueprintType)
struct FScoring
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")								int32 LoRange;										//var int LoRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")								int32 HiRange;										//var int HiRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")								FString Award;										//var string Award;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")								UMaterialInstance* AwardTexture;					//var Texture AwardTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")								USoundBase* AwardSound;								//var Sound AwardSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")								bool bPass;											//var bool bPass;
};

USTRUCT(BlueprintType)
struct FImageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleData")								FString Info;										//var string Info;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleData")								UMaterialInstance* Tex;								//var Texture Tex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleData")								FString sData;										//var string sData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleData")								int32 Status;										//var int Status;
};

USTRUCT(BlueprintType)
struct FVehicleData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleData")								AAA2_PlayerState* Passengers;						//var PlayerReplicationInfo Passengers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleData")								bool bDrewVehicle;									//var bool bDrewVehicle;
};

USTRUCT(BlueprintType)
struct FPoint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point")										int32 X;											//var int X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point")										int32 Y;											//var int Y;
};

USTRUCT(BlueprintType)
struct FPosition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position")									int32 X;											//var int X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position")									int32 Y;											//var int Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position")									int32 W;											//var int W;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position")									int32 H;											//var int H;
};

USTRUCT(BlueprintType)
struct FInvProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvProperties")								int32 iItemID;										//var int iItemID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvProperties")								int32 iParam;										//var int iParam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvProperties")								int32 iSize;										//var int iSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvProperties")								float fWeight;										//var float fWeight;
};


USTRUCT(BlueprintType)
struct FInvDefStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvDefStruct")								FString sItemName;										//var string sItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvDefStruct")								int32 iParam;											//var int iParam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvDefStruct")								float fWeight;											//var float fWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvDefStruct")								int32 iSize;											//var int iSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvDefStruct")								UMaterialInstance* cTexture;								//var Texture cTexture;
};

USTRUCT(BlueprintType)
struct FDamageStateStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								FName DamageBones;									//var name DamageBones;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								uint8 BoneSlot;										//var byte BoneSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								float DamagePct;									//var float DamagePct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								float ChildDamagePct;								//var float ChildDamagePct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								AEmitter* VisualEffectClass;						//var class<Emitter>  VisualEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								AVehicleVisualEffect* VisualEffect;					//var VehicleVisualEffect VisualEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageStateStruct")								UVehiclePhysicalEffect* PhysicalEffect;				//var class<VehiclePhysicalEffect>  PhysicalEffect;
};

USTRUCT(BlueprintType)
struct FDecorationType
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								UStaticMesh* StaticMesh;						//var StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								FRange Count;									//var Object.Range Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								FRange DrawScale;								//var Object.Range DrawScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								uint8 bAlign;									//var int bAlign;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								uint8 bRandomPitch;								//var int bRandomPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								uint8 bRandomYaw;								//var int bRandomYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DecorationType")								uint8 bRandomRoll;								//var int bRandomRoll;
};


USTRUCT(BlueprintType)
struct FPoolItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PoolItem")								AActor* aElement;								//var AActor* aElement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PoolItem")								int32 iUsed;									//var int iUsed;
};

USTRUCT(BlueprintType)
struct FEnumStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnumStat")								FString statName;								//var string statName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnumStat")								uint8 trueValue;								//var byte trueValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnumStat")								uint8 spoofValue;								//var byte spoofValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnumStat")								float spoofChance;								//var float spoofChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnumStat")								float obscurity;								//var float obscurity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnumStat")								bool isStatic;									//var bool isStatic;
};

USTRUCT(BlueprintType)
struct FVectorStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VectorStat")								FString statName;								//var string statName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VectorStat")								FVector trueValue;								//var Object.Vector trueValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VectorStat")								FVector spoofValue;								//var Object.Vector spoofValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VectorStat")								float spoofChance;								//var float spoofChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VectorStat")								float obscurity;								//var float obscurity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VectorStat")								bool isStatic;									//var bool isStatic;
};

USTRUCT(BlueprintType)
struct FFloatStat
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatStat")									FString statName;								//var string statName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatStat")									float trueValue;								//var float trueValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatStat")									float spoofValue;								//var float spoofValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatStat")									float spoofChance;								//var float spoofChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatStat")									float obscurity;								//var float obscurity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatStat")									bool isStatic;									//var bool isStatic;
};



USTRUCT(BlueprintType)
struct FUAVFlightPlanWaypoints
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVFlightPlanWaypoints")					FVector vLocation;								//var Object.Vector vLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVFlightPlanWaypoints")					float fpSpeed;									//var float fpSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UAVFlightPlanWaypoints")					float fpAltitude;								//var float fpAltitude;
};


USTRUCT(BlueprintType)
struct FCrosshairItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CrosshairItem")								FString FriendlyName;							//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CrosshairItem")								UTexture2D* CrosshairTexture;					//var Texture CrosshairTexture;
};


USTRUCT(BlueprintType)
struct FFloatBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatBox")									float X1;										//var float X1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatBox")									float Y1;										//var float Y1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatBox")									float X2;										//var float X2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatBox")									float Y2;										//var float Y2;
};


USTRUCT(BlueprintType)
struct FCountryFlag
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CountryFlag")								FString CountryCode;							//var string CountryCode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CountryFlag")								FString CountryName;							//var string CountryName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CountryFlag")								float U;										//var float U;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CountryFlag")								float V;										//var float V;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CountryFlag")								float UL;										//var float UL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CountryFlag")								float VL;										//var float VL;
};


USTRUCT(BlueprintType)
struct FOrientation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							ECamOrientation CamOrientation;						//var Object.ECamOrientation CamOrientation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							AActor* LookAt;										//var AActor* LookAt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							AActor* DollyWith;									//var AActor* DollyWith;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float EaseIntime;									//var float EaseIntime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							int32 bReversePitch;								//var int bReversePitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							int32 bReverseYaw;									//var int bReverseYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							int32 bReverseRoll;									//var int bReverseRoll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							Fpointer Orientation;								//var pointer Orientation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float PctInStart;									//var float PctInStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float PctInEnd;										//var float PctInEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float PctInDuration;								//var float PctInDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							FRotator StartingRotation;							//var Object.Rotator StartingRotation;
};

USTRUCT(BlueprintType)
struct FInterpolator
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							int32 bDone;										//var int bDone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float _value;										//var float _value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float _remainingTime;								//var float _remainingTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float _totalTime;									//var float _totalTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float _speed;										//var float _speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orientation")							float _acceleration;								//var float _acceleration;
};

USTRUCT(BlueprintType)
struct FCachedSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CachedSound")							FName CacheName;									//var name CacheName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CachedSound")							USoundBase* CacheSound;								//var Sound CacheSound;
};
USTRUCT(BlueprintType)
struct FQueueItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueItem")								FName Name;											//var name Voice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueItem")								float Delay;										//var float Delay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueItem")								uint8 Switch;										//var byte Switch;
};

USTRUCT(BlueprintType)
struct FVehiclePatrolPaths
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePatrolPaths")					TArray<ARoadPathNode*> apnDrivingPathNodesForPatrol;	//var array<RoadPathNode> apnDrivingPathNodesForPatrol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehiclePatrolPaths")					TArray<APathNode*> apnDrivingPathNodesForPatrol;	//var array<RoadPathNode> apnDrivingPathNodesForPatrol;
};

USTRUCT(BlueprintType)
struct FScoreItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								FName PosActorTag;									//var name PosActorTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								FVector Location;									//var FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								FRotator Rotation;									//var Object.Rotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								bool bBaseToPosActor;								//var bool bBaseToPosActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								EFontType Font;										//var EFontType Font;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								AActor* PosActor;									//var AActor* PosActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScoreItem")								TArray<ATextDisplay_Char*> Digits;					//var array<TextDisplay_Char> Digits;
};

USTRUCT(BlueprintType)
struct FSection
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Section")								FString Header;										//var string Header;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Section")								FString Id;											//var string Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Section")								FString Display;									//var string Display;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Section")								FString Caption;									//var string Caption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Section")								FString URL;										//var string URL;
};


USTRUCT(BlueprintType)
struct FTargetInfo
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetInfo")							ATargetMover* Target;								//var AGP_Gameplay.TargetMover Target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetInfo")							int32 hits;											//var int hits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetInfo")							bool Triggered;										//var bool Triggered;
};

USTRUCT(BlueprintType)
struct Flipsync
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "lipsync")								FName AnimName;										//var name AnimName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "lipsync")								int32 TargetID;										//var int TargetID;
};

USTRUCT(BlueprintType)
struct FLipSyncDebug
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LipSyncDebug")							FString Line1;										//var string Line1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LipSyncDebug")							FString Line2;										//var string Line2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LipSyncDebug")							float Duration;										//var float Duration;
};


USTRUCT(BlueprintType)
struct FFadeMoveInfoStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FadeMoveInfoStruct")						AActor* PlayerMovePoint;						//var AActor* PlayerMovePoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FadeMoveInfoStruct")						AFSTS_EventLab* CallBackScript;					//var FSTS_EventLab CallBackScript;
};

USTRUCT(BlueprintType)
struct FWeaponsSergeant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName Tag;										//var name Tag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							ANPC_SpecialForces* Actor;						//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName CadreTriggerTag;							//var name CadreTriggerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							AAGP_UseTrigger* CadreTrigger;					//var AGP.AGP_UseTrigger CadreTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							bool bGreeted;									//var bool bGreeted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName Greeting;									//var name Greeting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							bool bInstructed;								//var bool bInstructed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName Instruction;								//var name Instruction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							bool bReminded;									//var bool bReminded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName Reminder;									//var name Reminder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName ChallengeReady;							//var name ChallengeReady;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName ChallengeGo;								//var name ChallengeGo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName ChallengeIncomplete;						//var name ChallengeIncomplete;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName ChallengeComplete;						//var name ChallengeComplete;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName WarningLeavingArea;						//var name WarningLeavingArea;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsSergeant")							FName WarningDownrange;							//var name WarningDownrange;
};

USTRUCT(BlueprintType)
struct FWeaponsAssistant
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsAssistant")							FName Tag;										//var name Tag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsAssistant")							ANPC_SpecialForces* Actor;						//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsAssistant")							FName PickupTag;								//var name PickupTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsAssistant")							FName WarningDownrange;							//var name WarningDownrange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsAssistant")							FName WarningLeavingArea;						//var name WarningLeavingArea;
};
USTRUCT(BlueprintType)
struct FChallengeStation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							int32 MaxNumberTargets;							//var int MaxNumberTargets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							int32 MinPassingScore;							//var int MinPassingScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							AMarksmanTarget* CurrentMarksmanTarget;			//var AGP_Gameplay.MarksmanTarget CurrentMarksmanTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							ADecoMesh* CurrentDecoMesh;						//var DecoMesh CurrentDecoMesh;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							ADamageDetector* CurrentDamageDetector;		//var AGP_Gameplay.DamageDetector CurrentDamageDetector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							TArray<FName> TargetStack;						//var array<name> TargetStack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							TArray<FName> TargetStates;						//var array<name> TargetStates;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							int32 TargetActiveTime;							//var int TargetActiveTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							int32 TargetInactiveTime;						//var int TargetInactiveTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							FName ChallengeState;							//var name ChallengeState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							FName ChallengeVolumeTag;						//var name ChallengeVolumeTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							ATriggerVolume* ChallengeVolume;				//var AGP_Gameplay.TriggerVolume ChallengeVolume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							FName ChallengeReadyTriggerTag;					//var name ChallengeReadyTriggerTag;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							AAGP_Trigger* ChallengeReadyTrigger;		//var AGP_Gameplay.AGP_Trigger ChallengeReadyTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							FWeaponsSergeant Instructor;					//var EL_SFWeapons_Range.WeaponsSergeant Instructor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							FWeaponsAssistant Assistant1;					//var EL_SFWeapons_Range.WeaponsAssistant Assistant1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							FWeaponsAssistant Assistant2;					//var EL_SFWeapons_Range.WeaponsAssistant Assistant2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChallengeStation")							bool bWeaponActive;								//var bool bWeaponActive;
};

USTRUCT(BlueprintType)
struct FHelpInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelpInfo")									FName HelpName;										//var name HelpName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelpInfo")									float HelpTimer;									//var float HelpTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelpInfo")									FString Line1HelpText;								//var string Line1HelpText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelpInfo")									FString Line2HelpText;								//var string Line2HelpText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelpInfo")									FName LSHelpAnimation;								//var name LSHelpAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelpInfo")									AActor* LSActor;									//var AActor* LSActor;
};


USTRUCT(BlueprintType)
struct FLFTargetStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LFTargetStruct")							TArray<AActor*> InvalidTarget;						//var array<AGP_Vehicle> InvalidTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LFTargetStruct")							TArray<AActor*> ValidTarget;						//var array<AGP_Vehicle> ValidTarget;
};


USTRUCT(BlueprintType)
struct FTeamMember
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								FName ActorTag;										//var name ActorTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								ANPC_SpecialForces* Actor;							//var AGP_Characters.NPC_SpecialForces Actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								FName VolTriggerTag;								//var name VolTriggerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								ATriggerVolume* VolTrigger;							//var AGP_Gameplay.TriggerVolume VolTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								FName UseTriggerTag;								//var name UseTriggerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								AAGP_UseTrigger* UseTrigger;						//var AGP.AGP_UseTrigger UseTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								FString TalkText;									//var string TalkText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								FString MOSText;									//var string MOSText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeamMember")								int32 offset;										//var int offset;
};

USTRUCT(BlueprintType)
struct FLevelTex
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTex")									UMaterialInstance* Image;							//var Shader Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTex")									UMaterialInstance* Status;							//var Shader Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTex")									UMaterialInstance* ImageEnabled;					//var Texture ImageEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTex")									UMaterialInstance* ImageDisabled;					//var Texture ImageDisabled;
};

USTRUCT(BlueprintType)
struct FLevelTrigger
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTrigger")								FName Tag;											//var name Tag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTrigger")								AAGP_UseTrigger* Trigger;							//var AGP.AGP_UseTrigger Trigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTrigger")								FString MSG_NotAvailable;							//var string MSG_NotAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTrigger")								FString MSG_Available;								//var string MSG_Available;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTrigger")								FString MSG_Completed;								//var string MSG_Completed;
};

USTRUCT(BlueprintType)
struct FMissionInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MissionInfo")								uint8 Tour;											//var byte Tour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MissionInfo")								uint8 Mission;										//var byte Mission;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MissionInfo")								FString LoadMessage;								//var string LoadMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MissionInfo")								FString MapName;									//var string MapName;
};
USTRUCT(BlueprintType)
struct FHeliPath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeliPath")									FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeliPath")									ASceneManager* Path;								//var SceneManager Path;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeliPath")									bool bFlown;										//var bool bFlown;
};

USTRUCT(BlueprintType)
struct FCSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CSound")									bool bFadeUp;										//var bool bFadeUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CSound")									bool bFadeDown;										//var bool bFadeDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CSound")									float FadeTime;										//var float FadeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CSound")									float Volume;										//var float Volume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CSound")									float StartVolume;									//var float StartVolume;
};


USTRUCT(BlueprintType)
struct FBoneProfile
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneProfile")								FName BodyPart;										//var name BodyPart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoneProfile")								FName BoneName;										//var name BoneName;
};


USTRUCT(BlueprintType)
struct FGameSound
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSound")									USoundBase* Sound;									//var Sound Sound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSound")									FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSound")									float Duration;										//var float Duration;
};
USTRUCT(BlueprintType)
struct FLSAnim
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									FName Anim;											//var name Anim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									USoundBase* Sound;									//var Sound Sound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									TArray<FName> GestureAnim;							//var name GestureAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									TArray<float> GestureDelay;							//var float GestureDelay;
};
USTRUCT(BlueprintType)
struct FGameAnim
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameAnim")									FName Anim;											//var name Anim;
};

USTRUCT(BlueprintType)
struct FTimerEvent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerEvent")								FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerEvent")								float StartTime;									//var float StartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerEvent")								float WaitTime;										//var float WaitTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerEvent")								ETimerType TType;									//var ETimerType TType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerEvent")								bool bRepeat;										//var bool bRepeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerEvent")								bool bPause;										//var bool bPause;
};
USTRUCT(BlueprintType)
struct FQueueAnimation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							FName Anim;											//var name Anim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							AActor* Actor;										//var AActor* Actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							float StartTime;									//var float StartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							float Length;										//var float Length;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							bool bLoop;											//var bool bLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							float Rate;											//var float Rate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							float TweenTime;									//var float TweenTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							int32 Channel;										//var int Channel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QueueAnimation")							bool bRemove;										//var bool bRemove;
};



USTRUCT(BlueprintType)
struct FPrevNext
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									float HotSpotX;										//var float HotSpotX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									float HotSpotY;										//var float HotSpotY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									float HotSpotZ;										//var float HotSpotZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									float HotSpotRadius;								//var float HotSpotRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									FString HotSpotText;								//var string HotSpotText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									FName LookTargetName;								//var name LookTargetName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrevNext")									AExamAnswer* Answer;								//var ExamAnswer Answer;
};

USTRUCT(BlueprintType)
struct FTestAnswer
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								bool bCorrectAnswer;								//var bool bCorrectAnswer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								float HotSpotX;										//var float HotSpotX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								float HotSpotY;										//var float HotSpotY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								float HotSpotZ;										//var float HotSpotZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								float HotSpotRadius;								//var float HotSpotRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								FString HotSpotText;								//var string HotSpotText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								FName QuestionName;									//var name QuestionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								FName LookTargetName;								//var name LookTargetName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								AExamAnswer* Answer;								//var ExamAnswer Answer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestAnswer")								bool bMarkedCorrect;								//var bool bMarkedCorrect;
};

USTRUCT(BlueprintType)
struct FTestPage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestPage")									FName PageName;										//var name PageName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestPage")									UMaterialInstance* PageTexture;						//var Material PageTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestPage")									TArray<FTestAnswer> TestAnswers;					//var array<TestAnswer> TestAnswers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestPage")									FPrevNext PageNext;									//var MedExam.PrevNext PageNext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestPage")									FPrevNext PagePrev;									//var MedExam.PrevNext PagePrev;
};




USTRUCT(BlueprintType)
struct FWeatherPcl
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								FVector pos;										//var FVector pos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								FVector Vel;										//var FVector Vel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								float Life;											//var float Life;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								float Size;											//var float Size;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								float HitTime;										//var float HitTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								float InvLifeSpan;									//var float InvLifeSpan;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								float DistAtten;									//var float DistAtten;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								uint8 frame;										//var byte frame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								uint8 Dummy1;										//var byte Dummy1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								uint8 Visible;										//var byte Visible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeatherPcl")								uint8 Dummy2;										//var byte Dummy2;
};

USTRUCT(BlueprintType)
struct FEventParms
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventParms")								FName Name;											//var name Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventParms")								bool bDelay;										//var bool bDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventParms")								float DelayMin;										//var float DelayMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EventParms")								float DelayMax;										//var float DelayMax;
};

USTRUCT(BlueprintType)
struct FPropFlags
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool bHidden;										//var bool bHidden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool bBlockActors;									//var bool bBlockActors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool bBlockPlayers;									//var bool bBlockPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool bBlockZeroExtentTraces;						//var bool bBlockZeroExtentTraces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool bBlockNonZeroExtentTraces;						//var bool bBlockNonZeroExtentTraces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool AmbientGlow;									//var bool AmbientGlow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropFlags")									bool DrawScale;										//var bool DrawScale;
};

USTRUCT(BlueprintType)
struct FPropValues
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								bool bHidden;										//var bool bHidden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								bool bBlockActors;									//var bool bBlockActors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								bool bBlockPlayers;									//var bool bBlockPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								bool bBlockZeroExtentTraces;						//var bool bBlockZeroExtentTraces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								bool bBlockNonZeroExtentTraces;						//var bool bBlockNonZeroExtentTraces;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								uint8 AmbientGlow;									//var byte AmbientGlow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PropValues")								float DrawScale;									//var float DrawScale;
};

USTRUCT(BlueprintType)
struct FTargetActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetActor")								FName ActorTag;										//var name ActorTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetActor")								FPropFlags PropertyFlags;							//var PropertyTrigger.PropFlags PropertyFlags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetActor")								FPropValues SetValues;								//var PropertyTrigger.PropValues SetValues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetActor")								FPropValues UnSetValues;							//var PropertyTrigger.PropValues UnSetValues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetActor")								AActor* ActorRef;									//var AActor* ActorRef;
};


USTRUCT(BlueprintType)
struct FImageStratum
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageStratum")								float LowerBound;									//var float LowerBound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageStratum")								float UpperBound;									//var float UpperBound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageStratum")								UMaterialInstance* RadarImage;						//var Material RadarImage;
};


USTRUCT(BlueprintType)
struct FNPCRestStopAnimSequenceSet
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRestStopAnimSequenceSet")				FName animStart;									//var name animStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRestStopAnimSequenceSet")				FName animMiddle;									//var name animMiddle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRestStopAnimSequenceSet")				FName AnimEnd;										//var name AnimEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRestStopAnimSequenceSet")				bool bShoulderWeaponFirst;							//var bool bShoulderWeaponFirst;
};


USTRUCT(BlueprintType)
struct FNPCAttachObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							AActor* actSpawnedItem;								//var AActor* actSpawnedItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							AActor* Attachment;									//var class<Actor>  Attachment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							FName Bone;											//var name Bone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							FVector LocationOffset;								//var FVector LocationOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							FRotator RotationOffset;							//var Object.Rotator RotationOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							bool bUseParentScale;								//var bool bUseParentScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAttachObject")							float Scale;										//var float Scale;
};

USTRUCT(BlueprintType)
struct FRecentContact
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								APawn* pawnContact;									//var Pawn pawnContact;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								bool bHumanControlled;								//var bool bHumanControlled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								bool bEnemy;										//var bool bEnemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								FVector vLocation;									//var FVector vLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								float fpThreatLevel;								//var float fpThreatLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								float fpTimeSeen;									//var float fpTimeSeen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								float fpClosureRate;								//var float fpClosureRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								int32 iConfidencePenalty;							//var int iConfidencePenalty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecentContact")								bool bContactLost;									//var bool bContactLost;
};
USTRUCT(BlueprintType)
struct FGrenadeThreatContact
{
	GENERATED_BODY()

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GrenadeThreatContact")						AThrowWeaponPickup* twpGrenade;						//var ThrowWeaponPickup twpGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GrenadeThreatContact")						float fpTimeSeen;									//var float fpTimeSeen;
};

USTRUCT(BlueprintType)
struct FNPCAnimSequenceSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAnimSequenceSet")						FName animStart;									//var name animStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAnimSequenceSet")						FName animMiddle;									//var name animMiddle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAnimSequenceSet")						FName AnimEnd;										//var name AnimEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAnimSequenceSet")						bool bShoulderWeaponFirst;							//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FTarget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									UStaticMesh* StaticMesh;							//var StaticMesh StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									UStaticMesh* ZoneMesh;								//var StaticMesh ZoneMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									float Z1Scale;										//var float Z1Scale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FVector Z1Scale3D;									//var FVector Z1Scale3D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FVector Z1Offset;									//var FVector Z1Offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FRotator Z1Rotation;								//var Object.Rotator Z1Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FString Z1ID;										//var string Z1ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									float Z2Scale;										//var float Z2Scale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FVector Z2Scale3D;									//var FVector Z2Scale3D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FVector Z2Offset;									//var FVector Z2Offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FRotator Z2Rotation;								//var Object.Rotator Z2Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")									FString Z2ID;										//var string Z2ID;
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
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									FVector LocationOffset;								//var FVector LocationOffset;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									FRotator RotationOffset;							//var Object.Rotator RotationOffset;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									bool bUseParentScale;								//var bool bUseParentScale;
	UPROPERTY(BlueprintReadWrite, Category = "AttachObject")									float Scale;										//var float Scale;
};

USTRUCT(BlueprintType)
struct FTarGroup
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TarGroup")										FString Label;										//var string Label;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TarGroup")										int32 nShot;										//var int nShot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TarGroup")										int32 nMissed;										//var int nMissed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TarGroup")										int32 nTotal;										//var int nTotal;
};

USTRUCT(BlueprintType)
struct FOutStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OutStruct")										FName Event;										//var name Event;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OutStruct")										int32 Counter;										//var int Counter;
};


USTRUCT(BlueprintType)
struct FVisibleDelay
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VisibleDelay")									float Visible;										//var float Visible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VisibleDelay")									float Delay;										//var float Delay;
};

USTRUCT(BlueprintType)
struct FPaddingPercent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PaddingPercent")									float HorzPerc;										//var float HorzPerc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PaddingPercent")									float VertPerc;										//var float VertPerc;
};

USTRUCT(BlueprintType)
struct FAnimInfo
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float cX;											//var float cX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float cY;											//var float cY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float Scale;										//var float Scale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float FadeTime;										//var float FadeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float Alpha;										//var float Alpha;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float TargetAlpha;									//var float TargetAlpha;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float ResetDelay;									//var float ResetDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimInfo")										float TravelTime;									//var float TravelTime;
};

USTRUCT(BlueprintType)
struct FProfileStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProfileStruct")									FString ProfileName;								//var string ProfileName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProfileStruct")									float ProfileSeconds;								//var float ProfileSeconds;
};

USTRUCT(BlueprintType)
struct FeOwnageMap
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "eOwnageMap")										int32 RLevel;										//var int RLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "eOwnageMap")										FString MapName;									//var string MapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "eOwnageMap")										FString MapDesc;									//var string MapDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "eOwnageMap")										FString MapURL;										//var string MapURL;
};
USTRUCT(BlueprintType)
struct FAutoLoadMenu
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoadMenu")									FString MenuClassName;								//var string MenuClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoadMenu")									bool bPreInitialize;								//var bool bPreInitialize;
};

USTRUCT(BlueprintType)
struct FRestoreMenuItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RestoreMenuItem")									FString MenuClassName;								//var string MenuClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RestoreMenuItem")									FString Param1;										//var string Param1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RestoreMenuItem")									FString Param2;										//var string Param2;
};
USTRUCT(BlueprintType)
struct FDesignModeHint
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DesignModeHint")									FString Key;										//var string Key;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DesignModeHint")									FString Description;										//var string Description;
};

USTRUCT(BlueprintType)
struct FGUIListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUIListElem")										FString Item;										//var string Item;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUIListElem")										UObject* ExtraData;									//var Object ExtraData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUIListElem")										FString ExtraStrData;								//var string ExtraStrData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUIListElem")										FString bSection;									//var bool bSection;
};

USTRUCT(BlueprintType)
struct FAPackInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APackInfo")										FString PackageName;								//var string PackageName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APackInfo")										FString Description;								//var string Description;
};

USTRUCT(BlueprintType)
struct FMultiSelectListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiSelectListElem")								FString Item;										//var string Item;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiSelectListElem")								UObject* ExtraData;									//var Object ExtraData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiSelectListElem")								FString ExtraStrData;								//var string ExtraStrData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiSelectListElem")								bool bSelected;										//var bool bSelected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiSelectListElem")								int32 SelectionIndex;								//var int SelectionIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MultiSelectListElem")								bool bSection;										//var bool bSection;
};

USTRUCT(BlueprintType)
struct FImageListElem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageListElem")									int32 Item;											//var int Item;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageListElem")									UMaterialInstance* Image;							//var Material Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageListElem")									int32 Locked;										//var int Locked;
};

USTRUCT(BlueprintType)
struct FGUITreeNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITreeNode")										FString Caption;									//var string Caption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITreeNode")										FString Value;										//var string Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITreeNode")										FString ParentCaption;								//var string ParentCaption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITreeNode")										FString ExtraInfo;									//var string ExtraInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITreeNode")										int32 Level;										//var int Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITreeNode")										bool bEnabled;										//var bool bEnabled;
};

USTRUCT(BlueprintType)
struct FAutoLoginInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoginInfo")									FString IP;											//var string IP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoginInfo")									FString Port;										//var string Port;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoginInfo")									FString UserName;									//var string UserName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoginInfo")									FString Password;									//var string Password;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AutoLoginInfo")									bool bAutologin;									//var bool bAutologin;
};

USTRUCT(BlueprintType)
struct FGUITabItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITabItem")										FString ClassName;									//var string ClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITabItem")										FString Caption;									//var string Caption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GUITabItem")										FString Hint;										//var string Hint;
};

USTRUCT(BlueprintType)
struct FBadgeInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BadgeInfo")										FString BadgeName;									//var string BadgeName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BadgeInfo")										float RangeXMin;									//var float RangeXMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BadgeInfo")										float RangeXMax;									//var float RangeXMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BadgeInfo")										float RangeYMin;									//var float RangeYMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BadgeInfo")										float RangeYMax;									//var float RangeYMax;
};

USTRUCT(BlueprintType)
struct FRibbonRowInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RibbonRowInfo")									FString RibbonName1;								//var string RibbonName1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RibbonRowInfo")									FString RibbonName2;								//var string RibbonName2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RibbonRowInfo")									FString RibbonName3;								//var string RibbonName3;
};


USTRUCT(BlueprintType)
struct FCommandAlias
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommandAlias")									FString AliasText;									//var string AliasText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommandAlias")									FString RealCommand;								//var string RealCommand;
};

USTRUCT(BlueprintType)
struct FServerSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServerSettings")									FString Key;										//var string Key;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServerSettings")									FString Value;										//var string Value;
};

USTRUCT(BlueprintType)
struct FMapVoteGameConfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfig")								FString GameClass;									//var string GameClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfig")								FString Prefix;										//var string Prefix;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfig")								FString Acronym;									//var string Acronym;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfig")								FString GameName;									//var string GameName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfig")								FString Mutators;									//var string Mutators;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfig")								FString Options;									//var string Options;
};

USTRUCT(BlueprintType)
struct FMapVoteGameConfigLite
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfigLite")							FString GameClass;									//var string GameClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfigLite")							FString Prefix;										//var string Prefix;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteGameConfigLite")							FString GameName;									//var string GameName;
};

USTRUCT(BlueprintType)
struct FMapVoteMapList
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteMapList")									FString MapName;									//var string MapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteMapList")									int32 PlayCount;									//var int PlayCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteMapList")									int32 Sequence;										//var int Sequence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapVoteMapList")									bool bEnabled;										//var bool bEnabled;
};

USTRUCT(BlueprintType)
struct FMapHistoryInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapHistoryInfo")									FString M;											//var string M;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapHistoryInfo")									int32 p;											//var int p;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapHistoryInfo")									int32 S;											//var int S;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapHistoryInfo")									FString G;;											//var string G;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapHistoryInfo")									FString U;											//var string U;
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
	UPROPERTY(BlueprintReadWrite, Category = "sPendingRequest")									int32 Index;										//var int index;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMBSInfo")						FString PlayerName;									//var string PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMBSInfo")						FString IPAddress;									//var string IPAddress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMBSInfo")						int32 Ping;											//var int Ping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMBSInfo")						TArray<FKeyValuePair> Attributes;					//var array<GameInfo.KeyValuePair> Attributes;
};

USTRUCT(BlueprintType)
struct FStoredChatPassword
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoredChatPassword")				FString ChatRoomName;								//var string ChatRoomName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StoredChatPassword")				FString ChatRoomPassword;							//var string ChatRoomPassword;
};

USTRUCT(BlueprintType)
struct FPlayerNameInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerNameInfo")					FString mInfo;										//var string mInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerNameInfo")					FColor mColor;										//var Object.Color mColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerNameInfo")					float mXPos;										//var float mXPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerNameInfo")					float mYPos;										//var float mYPos;
};
/*
USTRUCT(BlueprintType)
struct FClientAdjustment
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					float TimeStamp;									//var float TimeStamp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					FName NewState;										//var name NewState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					EPhysics newPhysics;								//var Actor.EPhysics newPhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					FVector NewLoc;										//var FVector NewLoc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					FVector NewVel;										//var FVector NewVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					AActor* NewBase;									//var AActor* NewBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientAdjustment")					FVector NewFloor;									//var FVector NewFloor;
};
*/
USTRUCT(BlueprintType)
struct FAuthJacket
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 ToursCompleted;								//var int ToursCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 MissionsCompleted;							//var int MissionsCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 MarksmanshipScore;							//var int MarksmanshipScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 Honor;										//var int Honor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 Experience;									//var int Experience;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 Group;										//var int Group;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthJacket")						int32 UID;											//var int UID;
};


USTRUCT(BlueprintType)
struct FWeaponRecordBrief
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecordBrief")					int32 ShotsFired;									//var int ShotsFired;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecordBrief")					int32 ShotsHit;										//var int ShotsHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecordBrief")					int32 Kills;										//var int Kills;
};

	USTRUCT(BlueprintType)
struct FQualificationRecordBrief
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QualificationRecordBrief")			int32 Grade;										//var int Grade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QualificationRecordBrief")			FString Date;										//var string Date;
};

USTRUCT(BlueprintType)
struct FRecordBriefStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString UserName;									//var string UserName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 GroupID;										//var int GroupID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 UserID;										//var int UserID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 Experience;									//var int Experience;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 Honor;										//var int Honor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString CreationDate;								//var string CreationDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString LastLoginDate;								//var string LastLoginDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					float HoursPlayed;									//var float HoursPlayed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString FavoriteMap;								//var string FavoriteMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 AverageScore;									//var int AverageScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 HeroesVisited;								//var int HeroesVisited;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 BetaUser;										//var int BetaUser;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 MissionsCompleted;							//var int MissionsCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 RoundsWon;									//var int RoundsWon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 RoundsLost;									//var int RoundsLost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 MatchesCompleted;								//var int MatchesCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 ObjectivesCompleted;							//var int ObjectivesCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 ObjectiveDeaths;								//var int ObjectiveDeaths;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 MedpaksApplied;								//var int MedpaksApplied;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 TimesHealed;									//var int TimesHealed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FWeaponRecordBrief WeaponUseRecords;				//var WeaponRecordBrief WeaponUseRecords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 ROE;											//var int ROE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString version;									//var string version;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FQualificationRecordBrief QualificationRecords;		//var QualificationRecordBrief QualificationRecords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 ToursCompletedBitset;							//var int ToursCompletedBitset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					int32 MissionsCompletedBitset;						//var int MissionsCompletedBitset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString SquadLeaderSeconds;							//var string SquadLeaderSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString FireteamLeaderSeconds;						//var string FireteamLeaderSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString SoldierSeconds;								//var string SoldierSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString SquadLeaderLinkedSeconds;					//var string SquadLeaderLinkedSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString FireteamLeaderLinkedSeconds;				//var string FireteamLeaderLinkedSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString SoldierLinkedSeconds;						//var string SoldierLinkedSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString MedicTourCompletionDate;					//var string MedicTourCompletionDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString AirborneTourCompletionDate;					//var string AirborneTourCompletionDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString AdvancedMarksmanshipTourCompletionDate;		//var string AdvancedMarksmanshipTourCompletionDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RecordBriefStruct")					FString SpecialForcesTrainingTourCompletionDate;	//var string SpecialForcesTrainingTourCompletionDate;
};

USTRUCT(BlueprintType)
struct FPlayerEvents
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString PlayerName;								//var string PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString Password;								//var string Password;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 Quit = 0;									//var int Quit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 TimePlayed = 0;							//var int TimePlayed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 TimeAlive = 0;							//var int TimeAlive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 RoundsStarted = 0;						//var int RoundsStarted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 RoundsWon = 0;							//var int RoundsWon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 RoundsLost = 0;							//var int RoundsLost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 RoundsSurvivedWon = 0;					//var int RoundsSurvivedWon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 RoundsSurvivedLost = 0;					//var int RoundsSurvivedLost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 SecondsAsSQL = 0;							//var int SecondsAsSQL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 SecondsAsFTL = 0;							//var int SecondsAsFTL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 SecondsAsSoldier;							//var int SecondsAsSoldier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 Kills;									//var int Kills;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 Deaths;									//var int Deaths;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 SecondsLinkedToSQL;						//var int SecondsLinkedToSQL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 SecondsLinkedToFTL;						//var int SecondsLinkedToFTL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 SecondsLinkedToSoldiers;					//var int SecondsLinkedToSoldiers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 UsedMedic;								//var int UsedMedic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 Healed;									//var int Healed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 MedPaksUsed;								//var int MedPaksUsed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 Score;									//var int Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ROE;										//var int ROE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 CapturedObjective;						//var int CapturedObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ObjectiveDeaths;							//var int ObjectiveDeaths;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 AdminKicked;								//var int AdminKicked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 PBKicked;									//var int PBKicked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ShotsFiredGrenade;						//var int ShotsFiredGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ShotsFiredAstRifle;						//var int ShotsFiredAstRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ShotsFiredPistol;							//var int ShotsFiredPistol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ShotsFiredMG;								//var int ShotsFiredMG;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ShotsFiredRocket;							//var int ShotsFiredRocket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 ShotsFiredSprRifle;						//var int ShotsFiredSprRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 HitsGrenade;								//var int HitsGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 HitsAstRifle;								//var int HitsAstRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 HitsPistol;								//var int HitsPistol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 HitsMG;									//var int HitsMG;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 HitsRocket;								//var int HitsRocket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 HitsSprRifle;								//var int HitsSprRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 KillsGrenade;								//var int KillsGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 KillsAstRifle;							//var int KillsAstRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 KillsPistol;								//var int KillsPistol;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 KillsMG;									//var int KillsMG;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 KillsRocket;								//var int KillsRocket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 KillsSprRifle;							//var int KillsSprRifle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectAvailable;						//var int iESSObjectAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectDiscovered;						//var int iESSObjectDiscovered;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectExaminedByOtherPlayer;			//var int iESSObjectExaminedByOtherPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectDiscoveryRadioed;				//var int iESSObjectDiscoveryRadioed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPostRadioExaminedObject;				//var int iESSPostRadioExaminedObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSNoRadioExaminedObject;				//var int iESSNoRadioExaminedObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPostRadioLinkedObjectTaken;			//var int iESSPostRadioLinkedObjectTaken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSNoRadioLinkedObjectTaken;				//var int iESSNoRadioLinkedObjectTaken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSMissionFailureTime;					//var int iESSMissionFailureTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSMissionSuccessTime;					//var int iESSMissionSuccessTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSMissionProgressTime;					//var int iESSMissionProgressTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSMissionTotalPlayers;					//var int iESSMissionTotalPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSMissionSurvivingPlayers;				//var int iESSMissionSurvivingPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectReportedLethal;					//var int iESSObjectReportedLethal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectReportedNonLethal;				//var int iESSObjectReportedNonLethal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectReportableLethal;				//var int iESSObjectReportableLethal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectReportableNonLethal;			//var int iESSObjectReportableNonLethal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSObjectUnreportedLocations;			//var string iESSObjectUnreportedLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectReportingErrors = 0;			//var int iESSObjectReportingErrors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSObjectUnnecessaryUse = 0;				//var int iESSObjectUnnecessaryUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSObjectDistribution = "";			//var string iESSObjectDistribution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSCombatHeadshots = 0;					//var int iESSCombatHeadshots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSCombatTotalDamage	= 0;				//var int iESSCombatTotalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSCombatTotalDamageRange = 0;			//var int iESSCombatTotalDamageRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSCombatDamageCount;					//var int iESSCombatDamageCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSCombatEnemyContactTime;				//var int iESSCombatEnemyContactTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSCombatAIKill;						//var string iESSCombatAIKill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSCombatSurvivingAI;					//var int iESSCombatSurvivingAI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSCombatSurvivingAILocation;			//var string iESSCombatSurvivingAILocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByAI;				//var int iESSPlayerTotalDeathsByAI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByFriendlyFire;		//var int iESSPlayerTotalDeathsByFriendlyFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalDeathsByObject;			//var int iESSPlayerTotalDeathsByObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSPlayerDeathLocation;				//var string iESSPlayerDeathLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuries;					//var int iESSPlayerTotalInjuries;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesByAI;				//var int iESSPlayerTotalInjuriesByAI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesFriendlyFire;		//var int iESSPlayerTotalInjuriesFriendlyFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSPlayerTotalInjuriesByObject;			//var int iESSPlayerTotalInjuriesByObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSPlayerInjuryLocation;				//var string iESSPlayerInjuryLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSROEFriendlyFireHits;					//var int iESSROEFriendlyFireHits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSROEFriendlyFireDeaths;				//var int iESSROEFriendlyFireDeaths;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSROEFriendlyFireHitLocation;			//var string iESSROEFriendlyFireHitLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSROEFriendlyFireDeathLocation;		//var string iESSROEFriendlyFireDeathLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSROECivilianHits;						//var int iESSROECivilianHits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSROECivilianDeaths;					//var int iESSROECivilianDeaths;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					int32 iESSROECivilianDeathsByIED;				//var int iESSROECivilianDeathsByIED;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSROECivilianHitMapLocation;			//var string iESSROECivilianHitMapLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSROECivilianKillByPlayerMapLocation;	//var string iESSROECivilianKillByPlayerMapLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerEvents")					FString iESSROECivilianKillByES2MapLocation;	//var string iESSROECivilianKillByES2MapLocation;
};


USTRUCT(BlueprintType)
struct FGameSpyServerItem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bValid;								//var int bValid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bOfficial;							//var int bOfficial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bLeased;								//var int bLeased;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bNATO;								//var int bNATO;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bMiles;								//var int bMiles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bPassword;							//var int bPassword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bPunkBuster;							//var int bPunkBuster;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bCheats;								//var int bCheats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bTournament;							//var int bTournament;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bExploreTheArmy;						//var int bExploreTheArmy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bThirdParty;							//var int bThirdParty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString Name;								//var string Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString MapName;							//var string MapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString GameVer;							//var string GameVer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString Guid;								//var string Guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 IP;									//var int IP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 Port;									//var int Port;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 QueryPort;							//var int QueryPort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 Ping;									//var int Ping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 Index;								//var int Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 Tour;									//var int Tour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 NumPlayers;							//var int NumPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 MaxPlayers;							//var int MaxPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 MinHonor;								//var int MinHonor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 MaxHonor;								//var int MaxHonor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString Groups;								//var string Groups;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 CustomFlags;							//var int CustomFlags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					float Time;									//var float Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 NetOrderIP;							//var int NetOrderIP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString Locale;								//var string Locale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bRequiresAuthorization;				//var int bRequiresAuthorization;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 bCoop;								//var int bCoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 AverageHonor;							//var int AverageHonor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 CurrentRound;							//var int CurrentRound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 Addr;									//var int CurrentRound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					FString OperatingSystem;					//var string OperatingSystem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 AveragePlayerPing;					//var int AveragePlayerPing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameSpyServerItem")					int32 MissionTimeRemaining;					//var int MissionTimeRemaining;
};

USTRUCT(BlueprintType)
struct FIpAddr
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IpAddr")					int32 Addr;								//var int Addr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IpAddr")					int32 Port;								//var int Port;
};

USTRUCT(BlueprintType)
struct FBeaconInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeaconInfo")				FIpAddr Addr;							//var InternetLink.IpAddr Addr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeaconInfo")				float Time;								//var float Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeaconInfo")				FString Text;							//var string Text;
};

USTRUCT(BlueprintType)
struct FMD5UpdateData
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MD5UpdateData")				FString Guid;							//var string Guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MD5UpdateData")				FString MD5;							//var string MD5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MD5UpdateData")				int32 Revision;							//var int Revision;
};


USTRUCT(BlueprintType)
struct FtMasterServerEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "tMasterServerEntry")		FString Address;						//var string Address;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "tMasterServerEntry")		int32 Port;								//var int Port;
};


USTRUCT(BlueprintType)
struct FAuthSurveyQuestion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveyQuestion")		FString QuestionText;					//var string QuestionText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveyQuestion")		int32 UIComponentType;					//var int UIComponentType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveyQuestion")		bool bIsOptional;						//var bool bIsOptional;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveyQuestion")		int32 NumAnswers;						//var int NumAnswers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveyQuestion")		TArray<FString> AnswerText;				//var array<String> AnswerText;
};

USTRUCT(BlueprintType)
struct FAuthSurvey
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				int32 SurveyID;							//var int SurveyID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				FString SurveyTitle;					//var string SurveyTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				FString SurveyDescription;				//var string SurveyDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				bool bCompleted;						//var bool bCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				int32 ExperienceBonus;					//var int ExperienceBonus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				int32 NumQuestions;						//var int NumQuestions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurvey")				TArray<FAuthSurveyQuestion> Questions;	//var array<AuthSurveyQuestion> Questions;
};

USTRUCT(BlueprintType)
struct FAuthSurveySubmission
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveySubmission")		int32 SurveyID;							//var int SurveyID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthSurveySubmission")		TArray<int32> AnswerBits;				//var array<int> AnswerBits;
};

USTRUCT(BlueprintType)
struct FAuthInt64
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthInt64")					int32 LowPart;							//var int LowPart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthInt64")					int32 HighPart;							//var int HighPart;
};

USTRUCT(BlueprintType)
struct FAuthPersonnelJacket
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		FAuthInt64 UserID;						//var AuthInt64 UserID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		FAuthInt64 GroupID;						//var AuthInt64 GroupID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		bool bBanned;							//var bool bBanned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 BanDuration;						//var int BanDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 Experience;						//var int Experience;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 ExperienceNext;					//var int ExperienceNext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 Honor;							//var int Honor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 ToursCompleted;					//var int ToursCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 TourInfo;							//var int TourInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AuthPersonnelJacket")		int32 Marksmanship;						//var int Marksmanship;
};



USTRUCT(BlueprintType)
struct FPlayInfoData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString ThisProp;					//var Property ThisProp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				AAA2_Info* ClassFrom;				//var class<Info>  ClassFrom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString SettingName;				//var string SettingName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString DisplayName;				//var string DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString Description;				//var string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString Grouping;					//var string Grouping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString Data;						//var string Data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString ExtraPriv;					//var string ExtraPriv;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				FString Value;						//var string Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				EPlayInfoType RenderType;			//var EPlayInfoType RenderType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				uint8 SecLevel;						//var byte SecLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				uint8 Weight;						//var byte Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				bool bMPOnly;						//var bool bMPOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				bool bAdvanced;						//var bool bAdvanced;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				bool bGlobal;						//var bool bGlobal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				bool bStruct;						//var bool bStruct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayInfoData")				int32 ArrayDim;						//var int ArrayDim;
};

USTRUCT(BlueprintType)
struct FPlayerAdminAccounts
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAdminAccounts")		FString sPlayerName;				//var string sPlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAdminAccounts")		FString sPassword;					//var string sPassword;
};

USTRUCT(BlueprintType)
struct FBanDescription
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BanDescription")			EBanType BanType;					//var EBanType BanType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BanDescription")			int32 BanEndDate_LoWord;			//var int BanEndDate_LoWord;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BanDescription")			int32 BanEndDate_HiWord;			//var int BanEndDate_HiWord;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BanDescription")			FString Banee;						//var string Banee;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BanDescription")			FString OriginalUserName;			//var string OriginalUserName;
};


USTRUCT(BlueprintType)
struct FGameRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString ClassName;					//var string ClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString GameName;					//var string GameName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString Description;				//var string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString TextName;					//var string TextName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString GameAcronym;				//var string GameAcronym;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString MapListClassName;			//var string MapListClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString MapPrefix;					//var string MapPrefix;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString ScreenshotRef;				//var string ScreenshotRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString HUDMenu;					//var string HUDMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				FString RulesMenu;					//var string RulesMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				bool bTeamGame;						//var bool bTeamGame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				uint8 GameTypeGroup;				//var byte GameTypeGroup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameRecord")				int32 RecordIndex;					//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FMutatorRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				FString ClassName;					//var string ClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				FString FriendlyName;				//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				FString Description;				//var string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				FString IconMaterialName;			//var string IconMaterialName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				FString ConfigMenuClassName;		//var string ConfigMenuClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				FString GroupName;					//var string GroupName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				int32 RecordIndex;					//var int RecordIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MutatorRecord")				uint8 bActivated;					//var byte bActivated;
};

USTRUCT(BlueprintType)
struct FMapRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString Acronym;						//var string Acronym;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString MapName;						//var string MapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString TextName;						//var string TextName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString Author;							//var string Author;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					float Description;						//var string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					int32 PlayerCountMin;					//var int PlayerCountMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					int32 PlayerCountMax;					//var int PlayerCountMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString ScreenshotRef;					//var string ScreenshotRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					FString ExtraInfo;						//var string ExtraInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MapRecord")					int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FWeaponRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				FString ClassName;						//var string ClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				FString PickupClassName;				//var string PickupClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				FString AttachmentClassName;			//var string AttachmentClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				FString Description;					//var string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				FString TextName;						//var string TextName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponRecord")				int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FVehicleRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleRecord")				FString ClassName;						//var string ClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleRecord")				FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleRecord")				FString Description;					//var string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VehicleRecord")				int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FCrosshairRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CrosshairRecord")			FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CrosshairRecord")			UTexture* CrosshairTexture;				//var Texture CrosshairTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CrosshairRecord")			int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FAnnouncerRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnnouncerRecord")			FString ClassName;						//var string ClassName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnnouncerRecord")			FString FriendlyName;					//var string FriendlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnnouncerRecord")			FString PackageName;					//var string PackageName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnnouncerRecord")			FString FallbackPackage;				//var string FallbackPackage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnnouncerRecord")			bool bEnglishOnly;						//var bool bEnglishOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnnouncerRecord")			int32 RecordIndex;						//var int RecordIndex;
};

USTRUCT(BlueprintType)
struct FStandard
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Standard")					TArray<FString> Classes;					//	var array<String> Classes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Standard")					TArray<FString> Maps;						//var array<String> Maps;
};





USTRUCT(BlueprintType)
struct FTestOffset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestOffset")				float H;						//var float H;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestOffset")				float V;						//var float V;

};

USTRUCT(BlueprintType)
struct FNPCPSAnimSequenceSet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAnimSequenceSet")				FName animStart;						//var name animStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAnimSequenceSet")				FName animMiddle;						//var name animMiddle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAnimSequenceSet")				FName AnimEnd;							//var name AnimEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAnimSequenceSet")				bool bShoulderWeaponFirst;				//var bool bShoulderWeaponFirst;
};

USTRUCT(BlueprintType)
struct FNPCPSAttachObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAttachObject")				AActor* Attachment;				//var class<Actor>  Attachment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAttachObject")				FName Bone;						//var name Bone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAttachObject")				FVector LocationOffset;			//var var FVector LocationOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAttachObject")				FRotator RotationOffset;		//var Object.Rotator RotationOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAttachObject")				bool bUseParentScale;			//var bool bUseParentScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPSAttachObject")				float Scale;					//var float Scale;
};

USTRUCT(BlueprintType)
struct FSoundEmitter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundEmitter")				float EmitInterval;						//var float EmitInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundEmitter")				float EmitVariance;						//var float EmitVariance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundEmitter")				float EmitTime;							//var float EmitTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundEmitter")				USoundBase* EmitSound;					//var Sound EmitSound;
};

USTRUCT(BlueprintType)
struct FTournamentPlayerStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				FString sTeamName;							//var string sTeamName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				FString sPlayerName;						//var string sPlayerName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iTeamIndex;							//var int iTeamIndex;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iKills;								//var int iKills;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iDeaths;								//var int iDeaths;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iGoalPoints;							//var int iGoalPoints;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iLeaderPoints;						//var int iLeaderPoints;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iTotalScore;							//var int iTotalScore;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iROE;									//var int iROE;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentPlayerStats")				int32 iRoundsPlayed;						//var int iRoundsPlayed;
};

USTRUCT(BlueprintType)
struct FTournamentTeamResults
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")				FString sTeamName;							//var string sTeamName;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")				int32 iTotalScore;							//var int iTotalScore;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")				int32 iTotalWins;							//var int iTotalWins;
	UPROPERTY(BlueprintReadWrite, Category = "TournamentTeamResults")				int32 iTotalLosses;							//var int iTotalLosses;
};


USTRUCT(BlueprintType)
struct FESSObjectiveSet
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectiveSet")						TArray<AAGP_Objective*> aagpobjs;			//var array<AGP_Objective> aagpobjs;
};



USTRUCT(BlueprintType)
struct FMissionStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString Title;						//var string Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString MBSTitle;					//var string MBSTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString Image;						//var string Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString Disabled;					//var string Disabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString ImageDisabled;				//var string ImageDisabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString MapFilename;				//var string MapFilename;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						bool bFileExists;					//var bool bFileExists;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						int32 Status;						//var int Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FMissionStruct")						FString NMLFilename;				//var int NMLFilename;
};

USTRUCT(BlueprintType)
struct FTourStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString Tour;						//var string Tour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							int32 Dependency;					//var int Dependency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString Image;						//var string Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString TourText;					//var string TourText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString TourTextTitle;				//var string TourTextTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString TourRolloverText;			//var string TourRolloverText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString HistoryText;				//var string HistoryText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							FString HistoryTextTitle;			//var string HistoryTextTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							bool IsSequential;					//var bool IsSequential;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							bool IsTraining;					//var bool IsTraining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							int32 iNumMissions;					//var int iNumMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							int32 Status;						//var int Status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTourStruct")							TArray<FMissionStruct> Mission;	//var array<MissionStruct> Mission;
};

USTRUCT(BlueprintType)
struct FRotationRandomizer
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		FVector MeanDirection;				//var Vector MeanDirection;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		uint8  bPitch;						//var byte bPitch;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float PitchMean;					//var float PitchMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float PitchMaxDeviation;			//var float PitchMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float PitchFalloff;					//var float PitchFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		uint8 bYaw;							//var byte bYaw;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float YawMean;						//var float YawMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float YawMaxDeviation;				//var float YawMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float YawFalloff;					//var float YawFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		uint8 bRoll;						//var byte bRoll;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float RollMean;						//var float RollMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float RollMaxDeviation;				//var float RollMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float RollFalloff;					//var float RollFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float SpeedMean;					//var float SpeedMean;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float SpeedMaxDeviation;			//var float SpeedMaxDeviation;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		float SpeedFalloff;					//var float SpeedFalloff;
	UPROPERTY(BlueprintReadWrite, Category = "RotationRandomizer")		FRotator Base;						//var Rotator Base;
};

USTRUCT(BlueprintType)
struct FLaserDotInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "LaserDotInfo")			float  LaserDotIntensity;			//var float LaserDotIntensity;
	UPROPERTY(BlueprintReadWrite, Category = "LaserDotInfo")			float  LaserDotTimeStarted;			//var float LaserDotTimeStarted;
	UPROPERTY(BlueprintReadWrite, Category = "LaserDotInfo")			uint8  LaserDot;					//var LaserProjector LaserDot;
};

USTRUCT(BlueprintType)
struct FEnemySpottedData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		FVector  SpottedLocation;			//var FVector SpottedLocation;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  TimeSpottedSeconds;			//var float TimeSpottedSeconds;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  LifeSpan;					//var float LifeSpan;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  BlinkStartTime;				//var float BlinkStartTime;
	UPROPERTY(BlueprintReadWrite, Category = "EnemySpottedData")		float  BlinkEndTime;				//var float BlinkEndTime;
};
USTRUCT(BlueprintType)
struct FESSObjectData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		FVector  SpottedLocation;				//var FVector SpottedLocation;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  TimeSpottedSeconds;				//var float TimeSpottedSeconds;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  LifeSpan;						//var float LifeSpan;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  BlinkStartTime;					//var float BlinkStartTime;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		float  BlinkEndTime;					//var float BlinkEndTime;
	UPROPERTY(BlueprintReadWrite, Category = "ESSObjectData")		bool  bLethal;							//var bool bLethal;
};

USTRUCT(BlueprintType)
struct FBoneInfo
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		int32 HitBone;								//var int HitBone;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		FString Name;								//var string Name;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		float DamageModifier;						//var float DamageModifier;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		float PenetrationDepth;						//var float PenetrationDepth;
	UPROPERTY(BlueprintReadWrite, Category = "BoneInfo")		EBoneRegion BoneRegion;						//var Object.EBoneRegion BoneRegion;
};


USTRUCT(BlueprintType)
struct FBoneOffset
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "BoneOffset")		FVector VOffset;							//var Vector VOffset;
	UPROPERTY(BlueprintReadWrite, Category = "BoneOffset")		FRotator ROffset;							//var Rotator ROffset;
	UPROPERTY(BlueprintReadWrite, Category = "BoneOffset")		FName nBone;								//var name nBone;
};

USTRUCT(BlueprintType)
struct FObjectRange
{
	GENERATED_BODY()

	UPROPERTY()		float Min;
	UPROPERTY()		float Max;

	FObjectRange()
	{
		Min = 0.0f;
		Max = 1.0f;
	}
};
