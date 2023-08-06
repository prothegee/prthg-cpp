#ifndef PRTHGCPP_H
#define PRTHGCPP_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"

#include <memory>


#pragma region all in one header
#include "prthgcpp/classes/Cryptography.h"
#include "prthgcpp/classes/DateAndTime.h"
#include "prthgcpp/classes/DrogonFramework.h"
#include "prthgcpp/classes/MailSystem.h"
#include "prthgcpp/classes/Utility.h"

#include "prthgcpp/enums/DateEnums.h"
#include "prthgcpp/enums/LanguageEnums.h"
#include "prthgcpp/enums/StatusEnums.h"

#include "prthgcpp/types/ResultTypes.h"
#pragma endregion


namespace prthgcpp
{
    /**
     * @brief ptrthgcpp global
     * 
     */
    struct SGlobal
    {
        SGlobal();
        ~SGlobal();

        // cryptography accesss shared pointer
        inline static std::shared_ptr<prthgcpp::CCryptography> pCryptography = std::make_shared<prthgcpp::CCryptography>();

        // date and time accesss shared pointer
        inline static std::shared_ptr<prthgcpp::CDateAndTime> pDateAndTime = std::make_shared<prthgcpp::CDateAndTime>();

        // utility accesss shared pointer
        inline static std::shared_ptr<prthgcpp::CUtility> pUtility = std::make_shared<prthgcpp::CUtility>();

        #if __PRTHGCPP_INC_DROGON__
        // drogon framework accesss shared pointer
        inline static std::shared_ptr<prthgcpp::CDrogonFramework> pDrogonFramework = std::make_shared<prthgcpp::CDrogonFramework>();
        #endif // __PRTHGCPP_INC_DROGON__

        // mail system accesss shared pointer
        inline static std::shared_ptr<prthgcpp::CMailSystem> pMailSystem = std::make_shared<prthgcpp::CMailSystem>();
    };


    // prthgcpp global shared pointer
    inline static std::shared_ptr<prthgcpp::SGlobal> gsPtr = std::make_shared<prthgcpp::SGlobal>();
} // namespace prthgcpp


#endif // PRTHGCPP_H