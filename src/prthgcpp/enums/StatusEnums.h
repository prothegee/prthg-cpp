#ifndef PRTHGCPP_STATUS_ENUMS_H
#define PRTHGCPP_STATUS_ENUMS_H


namespace prthgcpp
{
    // enum for status build
    enum EStatusBuild : int
    {
        eStatusBuild_undefined = 0,
        eStatusBuild_development,
        eStatusBuild_staging,
        eStatusBuild_demo,
        eStatusBuild_production,
    };
    // enum class for status build
    enum class ECStatusBuild : int
    {
        undefined = 0,
        development,
        staging,
        demo,
        production,
    };
} // namespace prthgcpp


#endif // PRTHGCPP_STATUS_ENUMS_H