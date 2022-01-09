// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "MapDox.generated.h"

class AAGP_PlayerStart;
class ALevelInfo;

UCLASS()
class UMapDox : public UObject
{
	GENERATED_BODY()
public:
	UMapDox();
	
	UPROPERTY()					ESetting				Setting;
	UPROPERTY()					ETimeSetting			Time;
	UPROPERTY()					EWeatherSetting			Weather;
	UPROPERTY()					EFormat					FileFormat;
	UPROPERTY(EditAnywhere)		bool					bGenOverview;			//var() bool bGenOverview;
	UPROPERTY(EditAnywhere)		bool					bGenImageBox;			//var() bool bGenImageBox;
	UPROPERTY(EditAnywhere)		bool					bGenViewpoints;			//var() bool bGenViewpoints;
	UPROPERTY(EditAnywhere)		bool					bGenBriefings;			//var() bool bGenBriefings;
	UPROPERTY(EditAnywhere)		bool					bGenLoadouts;			//var() bool bGenLoadouts;
	UPROPERTY(EditAnywhere)		bool					bGenObjectives;			//var() bool bGenObjectives;
	UPROPERTY(EditAnywhere)		bool					bGenCommVolumes;		//var() bool bGenCommVolumes;
	UPROPERTY(EditAnywhere)		bool					bGenOtherVolumes;		//var() bool bGenOtherVolumes;
	UPROPERTY(EditAnywhere)		bool					bGenSpawns;				//var() bool bGenSpawns;
	UPROPERTY(EditAnywhere)		FString					VersionDeployment;		//var() FString VersionDeployment;
	UPROPERTY(EditAnywhere)		FString					FileNameNoExtension;	//var() FString FileNameNoExtension;
	UPROPERTY(EditAnywhere)		FString					ImageName;				//var() FString ImageName;
	UPROPERTY()					FString					FileExtension;			//var FString FileExtension;
	UPROPERTY()					ALevelInfo*				myLevel;				//var LevelInfo myLevel;
	UPROPERTY()					int32					ListItemCount;			//var int32 ListItemCount;
	UPROPERTY()					int32					iMyTour;				//var int32 iMyTour;
	UPROPERTY()					int32					iMyMission;				//var int32 iMyMission;
	UPROPERTY()					TArray<FTourStruct>		TourInfo;				//var LevelInfo.TourStruct TourInfo[32];
	UPROPERTY()					TArray<FString>			HistoryBriefing;		//var TArray<FString> HistoryBriefing;
	UPROPERTY()					TArray<FString>			Briefing;				//var TArray<FString> Briefing;
	UPROPERTY()					TArray<FString>			Team0Briefing;			//var TArray<FString> Team0Briefing;
	UPROPERTY()					TArray<FString>			Team1Briefing;			//var TArray<FString> Team1Briefing;

	//From Brushbuilder:
	UPROPERTY(EditAnywhere)		FString					BitmapFilename;			//var() FString BitmapFilename;
	UPROPERTY(EditAnywhere)		FString					ToolTip;				//var() FString ToolTip;

	FString SettingString();
	FString TimeString();
	FString WeatherString();
	//ALevelInfo* GetLevel();
	void FlushBuffer(FString& Buffer);
	FString LineBreak();
	FString WikiEndLine();
	FString Bold(FString Text);
	FString Italic(FString Text);
	FString Underline(FString Text);
	FString ALink(FString link_url, FString Text);
	FString Image(FString image_url, FString Text);
	FString Center(FString Text);
	FString Header(int32 header_num, FString Text);
	FString StartList();
	FString StartNumList();
	FString NumListItem(FString Text);
	FString listitem(FString Text);
	FString EndNumList();
	FString EndList();
	FString HorizontalRule();
	FString WikiArrow();
	void GenFileHeader();
	void GenFileFooter();
	FString StartLoadoutTable();
	FString LoadoutHeaderEntry();
	FString LoadoutTableEntry(FString Team, FString Role, FString WeaponClass, FString SpawnClass, FString SpawnPS, FString BaseLoadout, FString Added, FString Removed);
	FString EndLoadoutTable();
	void GenOverview();
	void GenImageBox();
	FString EndGameToString(EEndGameViewpoint EndGame);
	void GenViewpoints();
	void LoadTours();
	void GenBriefingText(TArray<FString> Brief);
	void GenBriefings();
	FString FTToString(EFireTeam FireTeam);
	FString PSToRole(AAGP_PlayerStart* PS);
	FString GenerateDefaultItems(AAGP_PlayerStart* PS);
	FString GenerateAddedItems(AAGP_PlayerStart* PS);
	FString GenerateRemovedItems(AAGP_PlayerStart* PS);
	bool Compare(AAGP_PlayerStart* PS1, AAGP_PlayerStart* PS2);
	int32 CompareScore(EWeaponType W);
	void Swap(AAGP_PlayerStart*& PS1, AAGP_PlayerStart*& PS2);
	void SortFT(TArray<AAGP_PlayerStart*>& FireTeam);
	void GenLoadouts();
	void GenObjectives();
	void GenCommVolumes();
	void GenOtherVolumes();
	void GenSpawns();
	bool Build();

};
