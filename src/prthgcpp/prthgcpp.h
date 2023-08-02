#ifndef PRTHGCPP_H
#define PRTHGCPP_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"

#include <memory>


#pragma region all in one header
#include "prthgcpp/classes/Cryptography.h"
#include "prthgcpp/classes/Utility.h"

#include "prthgcpp/enums/LanguageEnums.h"
#include "prthgcpp/enums/StatusEnums.h"
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

        // utility accesss shared pointer
        inline static std::shared_ptr<prthgcpp::CUtility> pUtility = std::make_shared<prthgcpp::CUtility>();
    };


    // prthgcpp global shared pointer
    inline static std::shared_ptr<prthgcpp::SGlobal> gsPtr = std::make_shared<prthgcpp::SGlobal>();
} // namespace prthgcpp


#endif // PRTHGCPP_H