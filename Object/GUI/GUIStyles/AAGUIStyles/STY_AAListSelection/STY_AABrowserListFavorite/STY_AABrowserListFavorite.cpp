// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAListSelection/STY_AABrowserListFavorite/STY_AABrowserListFavorite.h"

USTY_AABrowserListFavorite::USTY_AABrowserListFavorite()
{
	KeyName = "BrowserListFavorite";
	ImgColors = {
		FColor(26, 90, 108, 127),
		FColor(26, 90, 108, 127),
		FColor(26, 90, 108, 127),
		FColor(26, 90, 108, 127),
		FColor(26, 90, 108, 127)
	};
	RStyles = {
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL)
	};
}
