#ifndef PRTHGCPP_UTILITY_H
#define PRTHGCPP_UTILITY_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"

#include <string>
#include <random>

 #include <json/json.h>


namespace prthgcpp
{
    /**
     * @brief prthgcpp utility class
     * 
     */
    class CUtility
    {
    private:
        std::string m_alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    protected:
        /* data */

    public:
        CUtility(/* args */);
        ~CUtility();

        /**
         * @brief generate random number
         * 
         * @tparam T posibly int or double
         * @param min 
         * @param max 
         * @return T 
         */
        template <typename T>
        T GenerateRandomNumber(const T min, const T max) const;

        /**
         * @brief generate random alphanumeric
         * 
         * @note if length < 1, default will be set to 1
         * 
         * @param length 
         * @return std::string 
         */
        std::string GenerateRandomAlphanumeric(int length) const;

        /**
         * @brief generate random uuid
         * 
         * @return std::string 
         */
        std::string GenerateRandomUUID() const;

        /**
         * @brief check if input is alphabetic value
         * 
         * @param input 
         * @return true 
         * @return false 
         */
        bool CheckInputIsAlphabetic(const std::string input) const;

        /**
         * @brief check if input is alphanumeric value
         * 
         * @param input 
         * @return true 
         * @return false 
         */
        bool CheckInputIsAlphaNumeric(const std::string input) const;

        /**
         * @brief change input to letter case
         * 
         * @param input 
         * @param letterCase 0 is lowercase, 1 is uppercase, 2 is mixedcase
         * @return std::string 
         */
        std::string ChangeInputLetterCase(const std::string input, const int letterCase) const;

        /**
         * @brief change json input to string
         * 
         * @param input 
         * @return std::string 
         */
        std::string StringFromJson(const Json::Value input) const;

        /**
         * @brief change string input to json
         * 
         * @param input 
         * @return Json::Value 
         */
        Json::Value JsonFromString(const std::string input) const;
    };
} // namespace prthgcpp


#endif // PRTHGCPP_UTILITY_H