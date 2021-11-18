// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBase.h"
#include "AABrowser_ServerListPageMS.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_ServerListPageMS : public UAABrowser_ServerListPageBase
{
	GENERATED_BODY()
public:
	UAABrowser_ServerListPageMS();

	void ShowPanel(bool bShow);
	void Refresh();
	void ResetQueryClient(AServerQueryClient* Client);
	void BindQueryClient(AServerQueryClient* Client);
	void QueryComplete(EResponseInfo ResponseInfo, int32 Info);
	void ReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S);
	void ReceivedPingTimeout(int32 ListID, EPingCause PingCause);

};
