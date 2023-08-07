#include "DateAndTime.h"

#include <iomanip>


prthgcpp::CDateAndTime::CDateAndTime()
{
}

prthgcpp::CDateAndTime::~CDateAndTime()
{
}


template <typename T>
inline std::string prthgcpp::CDateAndTime::GetTime(const T dateAndTimeFormat) const
{
    std::string result;

    ECDateAndTimeFormat format = ECDateAndTimeFormat::undefined;

    if (std::is_same<T, int>::value)
    {
        format = (EDateAndTimeFormat)dateAndTimeFormat;
    }
    else if (std::is_same<T, EDateAndTimeFormat>::value)
    {
        format = (EDateAndTimeFormat)dateAndTimeFormat;
    }
    else if (std::is_same<T, ECDateAndTimeFormat>::value)
    {
        format = dateAndTimeFormat;
    }

    switch (dateAndTimeFormat)
    {
        case ECDateAndTimeFormat::UTC_TIME:
        {
            auto now = std::chrono::system_clock::now();
            auto itt = std::chrono::system_clock::to_time_t(now);

            std::stringstream ss;
            ss << std::put_time(gmtime(&itt), "%F %T UTC");

            result = ss.str();
        }
        break;

        case ECDateAndTimeFormat::FULL_TIMESTAMP:
        {
            auto year_str   = [&](){ return std::to_string(m_year); }();
            auto month_str  = [&](){ return std::to_string(m_month); }();
            auto day_str    = [&](){ return std::to_string(m_day); }();
            auto hour_str   = [&](){ return std::to_string(m_hour); }();
            auto minute_str = [&](){ return std::to_string(m_minute); }();
            auto second_str = [&](){ return std::to_string(m_second); }();

            auto year_fmt   = [&](){ return year_str; }();
            auto month_fmt  = [&](){ return (month_str.size() < 2) ? "0" + month_str : month_str; }();
            auto day_fmt    = [&](){ return (month_str.size() < 2) ? "0" + day_str : day_str; }();
            auto hour_fmt   = [&](){ return (hour_str.size() < 2) ? "0" + hour_str : hour_str; }();
            auto minute_fmt = [&](){ return (minute_str.size() < 2) ? "0" + minute_str : minute_str; }();
            auto second_fmt = [&](){ return (second_str.size() < 2) ? "0" + second_str : second_str; }();

            result = year_fmt + month_fmt + day_fmt + hour_fmt + minute_fmt + second_fmt;
        }
        break;

        case ECDateAndTimeFormat::YYYYMMDD:
        {
            auto year_str  = [&](){ return std::to_string(m_year); }();
            auto month_str = [&](){ return std::to_string(m_month); }();
            auto day_str   = [&](){ return std::to_string(m_day); }();

            auto year_fmt  = [&](){ return year_str; }();
            auto month_fmt = [&](){ return (month_str.size() < 2) ? "0" + month_str : month_str; }();
            auto day_fmt   = [&](){ return (month_str.size() < 2) ? "0" + day_str : day_str; }();

            result = year_fmt + month_fmt + day_fmt;
        }
        break;

        case ECDateAndTimeFormat::YYYY:
        {
            result = std::to_string(m_year);
        }
        break;

        case ECDateAndTimeFormat::MM:
        {
            auto month = std::to_string(m_month);

            result = [&](){ return (month.size() < 2) ? "0" + month : month; }();
        }
        break;

        case ECDateAndTimeFormat::DD:
        {
            auto day = std::to_string(m_day);

            result = [&](){ return (day.size() < 2) ? "0" + day : day; }();
        }
        break;

        case ECDateAndTimeFormat::hhmmss:
        {
            auto hour_str   = [&](){ return std::to_string(m_hour); }();
            auto minute_str = [&](){ return std::to_string(m_minute); }();
            auto second_str = [&](){ return std::to_string(m_second); }();

            auto hour_fmt   = [&](){ return (hour_str.size() < 2) ? "0" + hour_str : hour_str; }();
            auto minute_fmt = [&](){ return (minute_str.size() < 2) ? "0" + minute_str : minute_str; }();
            auto second_fmt = [&](){ return (second_str.size() < 2) ? "0" + second_str : second_str; }();

            result = hour_fmt + ":" + minute_fmt + ":" + second_fmt;
        }
        break;

        case ECDateAndTimeFormat::hh:
        {
            auto hour = std::to_string(m_hour);

            result = [&](){ return (hour.size() < 2) ? "0" + hour : hour; }();
        }
        break;

        case ECDateAndTimeFormat::mm:
        {
            auto minute = std::to_string(m_minute);

            result = [&](){ return (minute.size() < 2) ? "0" + minute : minute; }();
        }
        break;

        case ECDateAndTimeFormat::ss:
        {
            auto second = std::to_string(m_second);

            result = [&](){ return (second.size() < 2) ? "0" + second : second; }();
        }
        break;
    }

    return result;
}
