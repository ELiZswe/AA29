// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARoundButton/STY_AAMoviePlayer_VolumeKnob/STY_AAMoviePlayer_VolumeKnob.h"

USTY_AAMoviePlayer_VolumeKnob::USTY_AAMoviePlayer_VolumeKnob()
{
	KeyName = "MoviePlayer_VolumeKnob";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
	ImgWidths = {
		16,
		16,
		16,
		16,
		16
	};
	ImgHeights = {
		32,
		32,
		32,
		32,
		32
	};
}
