#include "MailSystem.h"


prthgcpp::CMailSystem::CMailSystem()
{
}

prthgcpp::CMailSystem::~CMailSystem()
{
}




#if __PRTHGCPP_INC_MAILIO__
prthgcpp::TResultCommon prthgcpp::CMailSystem::SendTextMessageMailioTLS(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const
{
    prthgcpp::TResultCommon result;

    try
    {
        mailio::message msg;

        msg.header_codec(mailio::message::header_codec_t::BASE64);
        msg.from(mailio::mail_address(senderName, senderEmail));
        msg.add_recipient(mailio::mail_address(recipientName, recipientEmail));

        msg.subject(mailSubject);
        msg.content_transfer_encoding(mailio::mime::content_transfer_encoding_t::QUOTED_PRINTABLE);
        msg.content_type(mailio::message::media_type_t::TEXT, "plain", "utf-8");

        msg.content(mailContent);

        mailio::smtps conn(mailServer, 587);

        conn.authenticate(mailAuthUser, mailAuthPassword, mailio::smtps::auth_method_t::START_TLS);

        conn.submit(msg);

        result.m_isOk = true;
        result.m_message = "mail system ok";
    }
    catch(mailio::smtp_error &e)
    {
        result.m_isOk = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }
    catch(mailio::dialog_error &e)
    {
        result.m_isOk = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }

    return result;
}

#if __PRTHGCPP_INC_DROGON__
drogon::Task<prthgcpp::TResultCommon> prthgcpp::CMailSystem::SendTextMessageMailioTLSCoro(const std::string senderName, const std::string senderEmail, const std::string recipientName, const std::string recipientEmail, const std::string mailSubject, const std::string mailContent, const std::string mailServer, const std::string mailAuthUser, const std::string mailAuthPassword) const
{
    prthgcpp::TResultCommon result;

    try
    {
        mailio::message msg;

        msg.header_codec(mailio::message::header_codec_t::BASE64);
        msg.from(mailio::mail_address(senderName, senderEmail));
        msg.add_recipient(mailio::mail_address(recipientName, recipientEmail));

        msg.subject(mailSubject);
        msg.content_transfer_encoding(mailio::mime::content_transfer_encoding_t::QUOTED_PRINTABLE);
        msg.content_type(mailio::message::media_type_t::TEXT, "plain", "utf-8");

        msg.content(mailContent);

        mailio::smtps conn(mailServer, 587);

        conn.authenticate(mailAuthUser, mailAuthPassword, mailio::smtps::auth_method_t::START_TLS);

        conn.submit(msg);

        result.m_isOk = true;
        result.m_message = "mail system ok";
    }
    catch(mailio::smtp_error &e)
    {
        result.m_isOk = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }
    catch(mailio::dialog_error &e)
    {
        result.m_isOk = false;
        result.m_message = e.what();

        std::cout << "(ERR) - " << result.m_message << "\n";
    }

    co_return result;
}
#endif // __PRTHGCPP_INC_DROGON__
#endif // __PRTHGCPP_INC_MAILIO__
