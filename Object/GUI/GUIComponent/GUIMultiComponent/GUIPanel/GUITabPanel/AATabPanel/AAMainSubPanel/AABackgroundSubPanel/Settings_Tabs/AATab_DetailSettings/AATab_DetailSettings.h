// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"
#include "AATab_DetailSettings.generated.h"

class UGUIImage;
class UmoComboBox;
class UmoCheckBox;
class UmoSlider;

/**
 * 
 */
UCLASS()
class AA29_API UAATab_DetailSettings : public USettings_Tabs
{
	GENERATED_BODY()
public:
	UAATab_DetailSettings();

	UPROPERTY(EditAnywhere)			FDisplayMode		DisplayModes;				//var() DisplayMode DisplayModes[17];
	UPROPERTY(EditAnywhere)			TArray<FString>		BitDepthText;				//var() localized FString BitDepthText[2];
	UPROPERTY(EditAnywhere)			TArray<FString>		DetailLevels;				//var() localized FString DetailLevels[9];
	UPROPERTY(EditAnywhere)			TArray<FString>		ShadowOptions;				//var() localized FString ShadowOptions[3];
	UPROPERTY(EditAnywhere)			TArray<FString>		RenderModeText;				//var() localized FString RenderModeText[2];
	UPROPERTY(EditAnywhere)			TArray<FString>		RenderMode;					//var() FString RenderMode[2];
	UPROPERTY(EditAnywhere)			FString				DisplayPromptMenu;			//var() FString DisplayPromptMenu;
	UPROPERTY(EditAnywhere)			bool				bPlayedSound;				//var() bool bPlayedSound;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_Gamma;					//var() automated XInterface.GUIImage i_Gamma;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_GammaBar;					//var() automated XInterface.GUIImage i_GammaBar;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Texture;					//var() automated XInterface.moComboBox co_Texture;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Char;					//var() automated XInterface.moComboBox co_Char;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_World;					//var() automated XInterface.moComboBox co_World;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Physics;					//var() automated XInterface.moComboBox co_Physics;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Decal;					//var() automated XInterface.moComboBox co_Decal;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_MeshLOD;					//var() automated XInterface.moComboBox co_MeshLOD;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Resolution;				//var() automated XInterface.moComboBox co_Resolution;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_RenderDevice;			//var() automated XInterface.moComboBox co_RenderDevice;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Shadows;					//var() automated XInterface.moComboBox co_Shadows;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Decals;					//var() automated XInterface.moCheckBox ch_Decals;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_DynLight;				//var() automated XInterface.moCheckBox ch_DynLight;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Coronas;					//var() automated XInterface.moCheckBox ch_Coronas;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Textures;				//var() automated XInterface.moCheckBox ch_Textures;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Projectors;				//var() automated XInterface.moCheckBox ch_Projectors;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_DecoLayers;				//var() automated XInterface.moCheckBox ch_DecoLayers;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Trilinear;				//var() automated XInterface.moCheckBox ch_Trilinear;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_FullScreen;				//var() automated XInterface.moCheckBox ch_FullScreen;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Weather;					//var() automated XInterface.moCheckBox ch_Weather;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_VSync;					//var() automated XInterface.moCheckBox ch_VSync;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Gamma;					//var() automated XInterface.moSlider sl_Gamma;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Brightness;				//var() automated XInterface.moSlider sl_Brightness;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_Contrast;				//var() automated XInterface.moSlider sl_Contrast;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_DistanceLOD;				//var() automated XInterface.moSlider sl_DistanceLOD;
	UPROPERTY(EditAnywhere)			FString				sRes;						//var() transient noexport FString sRes;
	UPROPERTY(EditAnywhere)			FString				sResD;						//var() transient noexport FString sResD;
	UPROPERTY(EditAnywhere)			FString				sRenDev;					//var() transient noexport FString sRenDev;
	UPROPERTY(EditAnywhere)			FString				sRenDevD;					//var() transient noexport FString sRenDevD;
	UPROPERTY(EditAnywhere)			float				fGamma;						//var() transient noexport float fGamma;
	UPROPERTY(EditAnywhere)			float				fBright;					//var() transient noexport float fBright;
	UPROPERTY(EditAnywhere)			float				fContrast;					//var() transient noexport float fContrast;
	UPROPERTY(EditAnywhere)			float				fDistance;					//var() transient noexport float fDistance;
	UPROPERTY(EditAnywhere)			float				fDistanceD;					//var() transient noexport float fDistanceD;
	UPROPERTY(EditAnywhere)			bool				bDecal;						//var() transient noexport bool bDecal;
	UPROPERTY(EditAnywhere)			bool				bDynLight;					//var() transient noexport bool bDynLight;
	UPROPERTY(EditAnywhere)			bool				bTexture;					//var() transient noexport bool bTexture;
	UPROPERTY(EditAnywhere)			bool				bCorona;					//var() transient noexport bool bCorona;
	UPROPERTY(EditAnywhere)			bool				bTrilin;					//var() transient noexport bool bTrilin;
	UPROPERTY(EditAnywhere)			bool				bProj;						//var() transient noexport bool bProj;
	UPROPERTY(EditAnywhere)			bool				bFol;						//var() transient noexport bool bFol;
	UPROPERTY(EditAnywhere)			bool				bFullScreen;				//var() transient noexport bool bFullScreen;
	UPROPERTY(EditAnywhere)			bool				bWeather;					//var() transient noexport bool bWeather;
	UPROPERTY(EditAnywhere)			bool				bVSync;						//var() transient noexport bool bVSync;
	UPROPERTY(EditAnywhere)			bool				bDecalD;					//var() transient noexport bool bDecalD;
	UPROPERTY(EditAnywhere)			bool				bDynLightD;					//var() transient noexport bool bDynLightD;
	UPROPERTY(EditAnywhere)			bool				bTextureD;					//var() transient noexport bool bTextureD;
	UPROPERTY(EditAnywhere)			bool				bCoronaD;					//var() transient noexport bool bCoronaD;
	UPROPERTY(EditAnywhere)			bool				bTrilinD;					//var() transient noexport bool bTrilinD;
	UPROPERTY(EditAnywhere)			bool				bProjD;						//var() transient noexport bool bProjD;
	UPROPERTY(EditAnywhere)			bool				bFolD;						//var() transient noexport bool bFolD;
	UPROPERTY(EditAnywhere)			bool				bFullScreenD;				//var() transient noexport bool bFullScreenD;
	UPROPERTY(EditAnywhere)			bool				bWeatherD;					//var() transient noexport bool bWeatherD;
	UPROPERTY(EditAnywhere)			bool				bVSyncD;					//var() transient noexport bool bVSyncD;
	UPROPERTY(EditAnywhere)			int32				iColDepth;					//var() transient noexport int32 iColDepth;
	UPROPERTY(EditAnywhere)			int32				iTexture;					//var() transient noexport int32 iTexture;
	UPROPERTY(EditAnywhere)			int32				iChar;						//var() transient noexport int32 iChar;
	UPROPERTY(EditAnywhere)			int32				iPhys;						//var() transient noexport int32 iPhys;
	UPROPERTY(EditAnywhere)			int32				iWorld;						//var() transient noexport int32 iWorld;
	UPROPERTY(EditAnywhere)			int32				iDecal;						//var() transient noexport int32 iDecal;
	UPROPERTY(EditAnywhere)			int32				iShadow;					//var() transient noexport int32 iShadow;
	UPROPERTY(EditAnywhere)			int32				iMeshLOD;					//var() transient noexport int32 iMeshLOD;
	UPROPERTY(EditAnywhere)			int32				iColDepthD;					//var() transient noexport int32 iColDepthD;
	UPROPERTY(EditAnywhere)			int32				iTextureD;					//var() transient noexport int32 iTextureD;
	UPROPERTY(EditAnywhere)			int32				iCharD;						//var() transient noexport int32 iCharD;
	UPROPERTY(EditAnywhere)			int32				iWorldD;					//var() transient noexport int32 iWorldD;
	UPROPERTY(EditAnywhere)			int32				iPhysD;						//var() transient noexport int32 iPhysD;
	UPROPERTY(EditAnywhere)			int32				iDecalD;					//var() transient noexport int32 iDecalD;
	UPROPERTY(EditAnywhere)			int32				iShadowD;					//var() transient noexport int32 iShadowD;
	UPROPERTY(EditAnywhere)			int32				iMeshLODD;					//var() transient noexport int32 iMeshLODD;
	UPROPERTY(EditAnywhere)			bool				bIgnoreResNotice;			//var() noexport bool bIgnoreResNotice;
	UPROPERTY(EditAnywhere)			bool				bInvalidRes;				//var() noexport bool bInvalidRes;
	UPROPERTY(EditAnywhere)			bool				bIgnoreChange;				//var() noexport bool bIgnoreChange;
	UPROPERTY(EditAnywhere)			FString				RelaunchQuestion;			//var() localized FString RelaunchQuestion;
	UPROPERTY(EditAnywhere)			FString				InvalidSelectionText;		//var() localized FString InvalidSelectionText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void InitializeCombos();
	void CheckSliders();
	void SetupPositions();
	void CheckSupportedResolutions();
	bool InternalOnPreDraw(UCanvas* C);
	void ResolutionChanged(int32 NewX, int32 NewY);
	void Refresh();
	int32 AddNewResolution(FString NewDisplayMode);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void ResetClicked();
	void ResetViewport();
	void ResetRenderDevice();
	void SaveSettings();
	void InternalOnChange(UGUIComponent* Sender);
	bool RenderDeviceClick(uint8 Btn);
	void VideoChangeClose(bool bCancelled);
	int32 GetDetailIndex(FString DetailString);
	FString GetGUIString(FString ConfigString);
	FString GetConfigString(FString DetailString);
	void GetComboOptions(UmoComboBox* Combo, TArray<FGUIListElem>& Ar);
	void UpdateDecalStay();

};
