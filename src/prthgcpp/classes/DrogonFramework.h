#ifndef PRTHGCPP_DROGON_FRAMEWORK_H
#define PRTHGCPP_DROGON_FRAMEWORK_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"

#if __PRTHGCPP_INC_DROGON__
#include <drogon/drogon.h>


namespace prthgcpp
{
    /**
     * @brief drogon framework class intergration
     * 
     * @note only available if Drogon package is found
     * 
     */
    class CDrogonFramework
    {
    private:
        /* data */

    protected:
        /* data */

    public:
        CDrogonFramework(/* args */);
        ~CDrogonFramework();

        // shared view data object
        drogon::HttpViewData m_viewData;

        #pragma region view data integration // NOTE: all view data function must start with 'View' prefix
        /**
         * @brief generate invoke public view to view response
         * 
         * @note required custom_config of:
         * @note key: roothost > value: string (e.g. localhost.com:PORTNUMBER)
         * @note key: status > value: int (1 is devel, 2 is staging, 3 is production)
         * 
         * @note ---
         * 
         * @note value to pass on .csp view reponse:
         * @note [[username]] > by default if username session is not found, result will be "anonymous"
         * @note [[protocol]] > http:// if status config is 1, otherwise https://
         * @note [[currentPath]]
         * @note [[jsessionid]]
         * 
         * @param pReq 
         */
        void ViewInvokePublicView(drogon::HttpRequestPtr &pReq);

        /**
         * @brief invoke language
         * 
         * @note object to pass on .csp view response:
         * @note [[language]]
         * 
         * @param language 
         */
        void ViewInvokeLanguage(const std::string &language);

        /**
         * @brief invoke css bundle
         * 
         * @note object to pass on .csp view response:
         * @note [[bundle_css]] > e.g. <link rel='stylesheet' href='[[bundle_css]]'>
         * 
         * @note the idea is to integrate drogon & svelte to create frontend
         * 
         * @param bundleCSS 
         */
        void ViewInvokeBundleCSS(const std::string &bundleCSS);

        /**
         * @brief invoke js bundle
         * 
         * @note object to pass on .csp view response:
         * @note [[bundle_js]] > e.g. <script defer src='[[bundle_js]]'></script>
         * 
         * @note the idea is to integrate drogon & svelte to create frontend
         * 
         * @param bundleCSS 
         */
        void ViewInvokeBundleJS(const std::string &bundleJS);
        #pragma endregion

        /**
         * @brief evaluate request origin from json array whitelist
         * 
         * @param pReq 
         * @param whitelist 
         * @return true 
         * @return false 
         */
        bool EvaluateOriginIsAllowed(drogon::HttpRequestPtr pReq, const Json::Value &whitelist) const;

        /**
         * @brief evaluate request origin from json array whitelist
         * 
         * @note drogon coroutine
         * 
         * @param pReq 
         * @param whitelist 
         * @return drogon::Task<bool> 
         */
        drogon::Task<bool> EvaluateOriginIsAllowedCoro(drogon::HttpRequestPtr pReq, const Json::Value &whitelist) const;
    };
} // namespace prthgcpp

#endif // __PRTHGCPP_INC_DROGON__

#endif // PRTHGCPP_DROGON_FRAMEWORK_H