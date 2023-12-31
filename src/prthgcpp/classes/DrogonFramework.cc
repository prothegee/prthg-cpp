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
    try
    {
        m_viewData.insert("protocol", (drogon::app().getCustomConfig()["status"].asInt() == 1) ? "http://" : "https://");
    }
    catch(const std::exception& e)
    {
        m_viewData.insert("protocol", e.what());
    }

    m_viewData.insert("currentPath", pReq->getPath());

    m_viewData.insert("sessionid", pReq->getCookie("JSESSIONID"));
    
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

void prthgcpp::CDrogonFramework::ViewInvokeUsername(drogon::HttpRequestPtr &pReq)
{
    std::string username;

    (pReq->session()->get<std::string>("username").length() <= 0) ? username = "anonymous" : username = pReq->session()->get<std::string>("username");

    m_viewData.insert("username", username);
}

void prthgcpp::CDrogonFramework::ViewInvokeCommonMessage(const std::string &commonMessage)
{
    m_viewData.insert("commonMessage", commonMessage);
}

void prthgcpp::CDrogonFramework::ViewInvokeCommonMessageCode(const int &commonMessageCode)
{
    m_viewData.insert("commonMessageCode", std::to_string(commonMessageCode));
}

bool prthgcpp::CDrogonFramework::EvaluateOriginIsAllowed(drogon::HttpRequestPtr pReq, const Json::Value &whitelist) const
{
    bool result{false};

    for (auto host : whitelist)
    {
        if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
        {
            result = true;
            break;
        }
    }

    return result;
}

drogon::Task<bool> prthgcpp::CDrogonFramework::EvaluateOriginIsAllowedCoro(drogon::HttpRequestPtr pReq, const Json::Value &whitelist) const
{
    bool result{false};

    for (auto host : whitelist)
    {
        if (host.asString().rfind(pReq->getHeader("origin"), 0) == 0)
        {
            result = true;
            break;
        }
    }

    co_return result;
}

#endif // __PRTHGCPP_INC_DROGON__
