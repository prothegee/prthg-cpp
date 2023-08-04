#include "DrogonFramework.h"


#if __PRTHGCPP_INC_DROGON__

prthgcpp::CDrogonFramework::CDrogonFramework()
{
}

prthgcpp::CDrogonFramework::~CDrogonFramework()
{
}

void prthgcpp::CDrogonFramework::ViewInvokePublicView(drogon::HttpRequestPtr &pReq)
{
    std::string username;
    (pReq->session()->get<std::string>("username").length() <= 0)
        ? username = "anonymous"
        : username = pReq->session()->get<std::string>("username");
    m_viewData.insert("username", username);

    try
    {
        m_viewData.insert("protocol", (drogon::app().getCustomConfig()["status"].asInt() == 1) ? "http://" : "https://");
    }
    catch(const std::exception& e)
    {
        m_viewData.insert("protocol", e.what());
    }

    m_viewData.insert("currentPath", pReq->getPath());

    m_viewData.insert("jsessionid", pReq->getCookie("JSESSIONID"));
    
}

void prthgcpp::CDrogonFramework::ViewInvokeMessageStatus(const int &messageStatusCode)
{
    m_viewData.insert("messageStatus", std::to_string(messageStatusCode));
}

void prthgcpp::CDrogonFramework::ViewInvokeMessageContext(const std::string &messageContextString)
{
    m_viewData.insert("messageContext", messageContextString);
}

void prthgcpp::CDrogonFramework::ViewInvokeLanguage(const std::string &language)
{
    m_viewData.insert("language", language);
}

void prthgcpp::CDrogonFramework::ViewInvokeBundleCSS(const std::string &bundleCSS)
{
    std::string bundle;
    bundle += "<link rel='stylesheet' href='";
    bundle += bundleCSS;
    bundle += "'>";

    m_viewData.insert("bundle_css", bundle);
}

void prthgcpp::CDrogonFramework::ViewInvokeBundleJS(const std::string &bundleJS)
{
    std::string bundle;
    bundle += "<script defer src='";
    bundle += bundleJS;
    bundle += "'></script>";

    m_viewData.insert("bundle_js", bundle);
}

#endif // __PRTHGCPP_INC_DROGON__
