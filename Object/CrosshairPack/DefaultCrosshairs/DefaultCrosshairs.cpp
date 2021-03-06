// All the original content belonged to the US Army

#include "AA29/Object/CrosshairPack/DefaultCrosshairs/DefaultCrosshairs.h"

UDefaultCrosshairs::UDefaultCrosshairs()
{
	CrossHair.SetNum(14);
	CrossHair[0] = FCrosshairItem({ "Cross (1)",nullptr });
	CrossHair[1] = FCrosshairItem({ "Cross (2)",nullptr });
	CrossHair[2] = FCrosshairItem({ "Cross (3)",nullptr });
	CrossHair[3] = FCrosshairItem({ "Cross (4)",nullptr });
	CrossHair[4] = FCrosshairItem({ "Cross (5)",nullptr });
	CrossHair[5] = FCrosshairItem({ "Dot",nullptr });
	CrossHair[6] = FCrosshairItem({ "Pointer",nullptr });
	CrossHair[7] = FCrosshairItem({ "Triad (1)",nullptr });
	CrossHair[8] = FCrosshairItem({ "Triad (2)",nullptr });
	CrossHair[9] = FCrosshairItem({ "Triad (3)",nullptr });
	CrossHair[10] = FCrosshairItem({ "Bracket (1)",nullptr });
	CrossHair[11] = FCrosshairItem({ "Bracket (2)",nullptr });
	CrossHair[12] = FCrosshairItem({ "Circle (1)",nullptr });
	CrossHair[13] = FCrosshairItem({ "Circle (2)",nullptr });
}
