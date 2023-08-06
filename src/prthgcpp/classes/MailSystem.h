#ifndef PRTHGCPP_MAIL_SYSTEM_H
#define PRTHGCPP_MAIL_SYSTEM_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"
#include "prthgcpp/types/ResultTypes.h"


#if __PRTHGCPP_INC_MAILIO__
    #include <mailio/message.hpp>
    #include <mailio/mime.hpp>
    #include <mailio/smtp.hpp>
#endif // __PRTHGCPP_INC_MAILIO__


namespace prthgcpp
{
    /**
     * @brief prthgcpp mail system class
     * 
     */
    class CMailSystem
    {
    private:
        /* data */

    protected:
        /* data */

    public:
        CMailSystem(/* args */);
        ~CMailSystem();

        #if __PRTHGCPP_INC_MAILIO__
        /**
         * @brief send mail message using mailio TLS
         * 
         * @param senderName 
         * @param senderEmail 
         * @param recipientName 
         * @param recipientEmail 
         * @param mailSubject 
         * @param mailContent 
         * @param mailServer 
         * @param mailAuthUser 
         * @param mailAuthPassword 
         * @return prthgcpp::TResultCommon 
         */
        prthgcpp::TResultCommon SendTextMessageMailioTLS(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const;
        #endif // __PRTHGCPP_INC_MAILIO__
    };
} // namespace prthgcpp


#endif // PRTHGCPP_MAIL_SYSTEM_H