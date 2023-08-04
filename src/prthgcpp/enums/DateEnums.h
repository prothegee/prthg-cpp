#ifndef PRTHGCPP_DATE_ENUMS_H
#define PRTHGCPP_DATE_ENUMS_H


namespace prthgcpp
{
    // enum date and time format
    enum EDateAndTimeFormat : int
    {
        eDateAndTime_format_undefined = 0,
        eDateAndTime_format_UTC_TIME,
        eDateAndTime_format_FULL_TIMESTAMP,
        eDateAndTime_format_YYYYMMDD,
        eDateAndTime_format_YYYY,
        eDateAndTime_format_MM,
        eDateAndTime_format_DD,
        eDateAndTime_format_hhmmss,
        eDateAndTime_format_hh,
        eDateAndTime_format_mm,
        eDateAndTime_format_ss,
    };
    // enum class date and time format
    enum class ECDateAndTimeFormat : int
    {
        undefined = EDateAndTimeFormat::eDateAndTime_format_undefined,
        UTC_TIME = EDateAndTimeFormat::eDateAndTime_format_UTC_TIME,
        FULL_TIMESTAMP = EDateAndTimeFormat::eDateAndTime_format_FULL_TIMESTAMP,
        YYYYMMDD = EDateAndTimeFormat::eDateAndTime_format_YYYYMMDD,
        YYYY = EDateAndTimeFormat::eDateAndTime_format_YYYY,
        MM = EDateAndTimeFormat::eDateAndTime_format_MM,
        DD = EDateAndTimeFormat::eDateAndTime_format_DD,
        hhmmss = EDateAndTimeFormat::eDateAndTime_format_hhmmss,
        hh = EDateAndTimeFormat::eDateAndTime_format_hh,
        mm = EDateAndTimeFormat::eDateAndTime_format_mm,
        ss = EDateAndTimeFormat::eDateAndTime_format_ss,
    };
} // namespace prthgcpp


#endif // PRTHGCPP_DATE_ENUMS_H