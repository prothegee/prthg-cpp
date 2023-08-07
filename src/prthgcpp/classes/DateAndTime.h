#ifndef PRTHGCPP_DATE_AND_TIME_H
#define PRTHGCPP_DATE_AND_TIME_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"

#include <time.h>
#include <ctime>
#include <chrono>
#include <string>

#include "prthgcpp/enums/DateEnums.h"


namespace prthgcpp
{
    /**
     * @brief prthgcpp date and time class
     * 
     */
    class CDateAndTime
    {
    private:
        time_t m_rawtime = time(0);
        tm* m_timeinfo = localtime(&m_rawtime);

    protected:
        /* data */

    public:
        CDateAndTime(/* args */);
        ~CDateAndTime();

        // current year
        const int m_year   = [&](){ return 1900 + m_timeinfo->tm_year; }();
        // current month
        const int m_month  = [&](){ return m_timeinfo->tm_mon + 1; }();
        // current day
        const int m_day    = [&](){ return m_timeinfo->tm_mday; }();
        // current hours
        const int m_hour   = [&](){ return m_timeinfo->tm_hour; }();
        // current minutes
        const int m_minute = [&](){ return m_timeinfo->tm_min; }();
        // current seconds
        const int m_second = [&](){ return m_timeinfo->tm_sec; }();

        /**
         * @brief get current time on current hardware
         * 
         * @note T is:
         * @note 0 = undefined
         * @note 1 = UTC_TIME // e.g. 2022-06-21 18:10:14
         * @note 2 = FULL_TIMESTAMP // e.g. YYYYMMDDhhmmss
         * @note 3 = YYYYMMDD
         * @note 4 = YYYY
         * @note 5 = MM
         * @note 6 = DD
         * @note 7 = hhmmss
         * @note 8 = hh
         * @note 9 = mm
         * @note 10 = ss
         * 
         * @tparam T based on ECDateAndTimeFormat or EDateAndTimeFormat or int
         * @param dateAndTimeFormat 
         * @return std::string 
         */
        template <typename T>
        std::string GetTime(const T dateAndTimeFormat) const;
    };
} // namespace prthgcpp

#endif // PRTHGCPP_DATE_AND_TIME_H