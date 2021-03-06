// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "ZoneInfo.generated.h"

class ASkyZoneInfo;
class UI3DL2Listener;
class AZoneInfo;

UCLASS()
class AZoneInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AZoneInfo();

	UPROPERTY()												ASkyZoneInfo*		SkyZone;				//var SkyZoneInfo SkyZone;
	UPROPERTY(EditAnywhere)									FName				ZoneTag;				//var() FName ZoneTag;
	UPROPERTY(EditAnywhere)									float				KillZ;					//var() float KillZ;
	UPROPERTY(EditAnywhere)									bool				bSoftKillZ;				//var() bool bSoftKillZ;
	UPROPERTY(EditAnywhere)									bool				bTerrainZone;			//var() bool bTerrainZone;
	UPROPERTY(EditAnywhere)									bool				bDistanceFog;			//var() bool bDistanceFog;
	UPROPERTY(EditAnywhere)									bool				bClearToFogColor;		//var() bool bClearToFogColor;
	//UPROPERTY()										TArray<ATerrainInfo*>	Terrains;				//var const TArray<TerrainInfo> Terrains;
	UPROPERTY()												FVector				AmbientVector;			//var Vector AmbientVector;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			uint8				AmbientBrightness;		//var(ZoneLight) uint8 AmbientBrightness;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			uint8				AmbientHue;				//var(ZoneLight) uint8 AmbientHue;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			uint8				AmbientSaturation;		//var(ZoneLight) uint8 AmbientSaturation;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			FColor				DistanceFogColor;		//var(ZoneLight) Color DistanceFogColor;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				DistanceFogStart;		//var(ZoneLight) float DistanceFogStart;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				DistanceFogEnd;			//var(ZoneLight) float DistanceFogEnd;
	UPROPERTY(EditAnywhere)									float				RealDistanceFogEnd;		//var transient float RealDistanceFogEnd;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				DistanceFogEndMin;		//var(ZoneLight) float DistanceFogEndMin;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				DistanceFogBlendTime;	//var(ZoneLight) float DistanceFogBlendTime;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			UMaterialInstance*	EnvironmentMap;			//var(ZoneLight) const Texture EnvironmentMap;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				TexUPanSpeed;			//var(ZoneLight) float TexUPanSpeed;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				TexVPanSpeed;			//var(ZoneLight) float TexVPanSpeed;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				DramaticLightingScale;	//var(ZoneLight) float DramaticLightingScale;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			FColor				NV_DistanceFogColor;	//var(ZoneLight) Color NV_DistanceFogColor;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				NV_DistanceFogStart;	//var(ZoneLight) float NV_DistanceFogStart;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")			float				NV_DistanceFogEnd;		//var(ZoneLight) float NV_DistanceFogEnd;
	UPROPERTY(EditAnywhere, Category = "CommLocation")		int32				LocationPriority;		//var(CommLocation) int32 LocationPriority;
	UPROPERTY(EditAnywhere, Category = "CommLocation")		FString				LocationName;			//var(CommLocation) localized FString LocationName;
	UPROPERTY(EditAnywhere, Category = "CommLocation")		FName				LocationObjective;		//var(CommLocation) FName LocationObjective;
	UPROPERTY(EditAnywhere, Category = "CommLocation")		bool				bScoreHelper;			//var(CommLocation) bool bScoreHelper;
	UPROPERTY(EditAnywhere, Category = "CommLocation")		bool				bScoreDefender;			//var(CommLocation) bool bScoreDefender;
	UPROPERTY(EditAnywhere)									bool				bIndoorZone;			//var() bool bIndoorZone;
	UPROPERTY()												AActor*				Objective;				//var Actor Objective;
	UPROPERTY(EditAnywhere, Category = "ZoneSound")			UI3DL2Listener*		ZoneEffect;				//var(ZoneSound) I3DL2Listener ZoneEffect;
	UPROPERTY(EditAnywhere, Category = "ZoneVisibility")	bool				bLonelyZone;			//var(ZoneVisibility) bool bLonelyZone;
	UPROPERTY(EditAnywhere, Category = "ZoneVisibility")	TArray<AZoneInfo*>	ManualExcludes;			//var(ZoneVisibility) TArray<ZoneInfo> ManualExcludes;

	void ZoneActors(AActor* baseClass, AActor*& Actor);
	void LinkToSkybox();
	void PreBeginPlay();
	void ActorEntered(AActor* Other);
	void ActorLeaving(AActor* Other);
	void BeginPlay();
	AActor* GetNearbyObjective(bool bDefender);
};
