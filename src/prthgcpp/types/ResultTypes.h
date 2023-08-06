#ifndef PRTHGCPP_RESUTL_TYPES_H
#define PRTHGCPP_RESUTL_TYPES_H
#include <string>


namespace prthgcpp
{
    // common result with condition and message
    typedef struct
    {
        bool m_isOk;
        std::string m_message;
    } TResultCommon;
} // namespace prthgcpp


#endif // PRTHGCPP_RESUTL_TYPES_H