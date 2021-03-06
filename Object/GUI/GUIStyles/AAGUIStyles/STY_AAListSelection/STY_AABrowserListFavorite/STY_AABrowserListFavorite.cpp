// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAListSelection/STY_AABrowserListFavorite/STY_AABrowserListFavorite.h"

USTY_AABrowserListFavorite::USTY_AABrowserListFavorite()
{
	KeyName = "BrowserListFavorite";
	ImgColors[0] = FColor(26, 90, 108, 127);
	ImgColors[1] = FColor(26, 90, 108, 127);
	ImgColors[2] = FColor(26, 90, 108, 127);
	ImgColors[3] = FColor(26, 90, 108, 127);
	ImgColors[4] = FColor(26, 90, 108, 127);
	RStyles[0] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[1] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[2] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[3] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[4] = EMenuRenderStyle::MSTY_Translucent;
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_favorites_highlight_Mat.t_ui_mbs_favorites_highlight_Mat'"), NULL, LOAD_None, NULL);
}
