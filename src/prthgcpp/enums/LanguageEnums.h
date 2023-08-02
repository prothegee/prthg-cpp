#ifndef PRTHGCPP_LANGUAGE_ENUMS_H
#define PRTHGCPP_LANGUAGE_ENUMS_H


namespace prthgcpp
{
    // enum language
    // - https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes
    enum ELanguage : int
    {
        eLanguage_undefined = 0,
        eLanguage_en,
        eLanguage_id,
    };
    // enum class language
    // - https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes
    enum class ECLanguage : int
    {
        undefined = ELanguage::eLanguage_undefined,
        en = ELanguage::eLanguage_en,
        id = ELanguage::eLanguage_id,
    };
} // namespace prthgcpp


#endif // PRTHGCPP_LANGUAGE_ENUMS_H