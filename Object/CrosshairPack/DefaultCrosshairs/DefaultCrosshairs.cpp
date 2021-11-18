// All the original content belonged to the US Army


#include "AA29/Object/CrosshairPack/DefaultCrosshairs/DefaultCrosshairs.h"


UDefaultCrosshairs::UDefaultCrosshairs()
{
	CrossHair.SetNum(14);

	CrossHair[0] = {"Cross (1)", nullptr};
	CrossHair[1] = {"Cross {2}", nullptr};
	CrossHair[2] = {"Cross {3}", nullptr};
	CrossHair[3] = {"Cross {4}", nullptr};
	CrossHair[4] = {"Cross {5}", nullptr};
	CrossHair[5] = {"Dot", nullptr};
	CrossHair[6] = {"Pointer", nullptr};
	CrossHair[7] = {"Triad {1}", nullptr};
	CrossHair[8] = {"Triad {2}", nullptr};
	CrossHair[9] = {"Triad {3}", nullptr};
	CrossHair[10] = {"Bracket {1}", nullptr};
	CrossHair[11] = {"Bracket {2}", nullptr};
	CrossHair[12] = {"Circle {1}", nullptr};
	CrossHair[13] = {"Circle {2}", nullptr};

}