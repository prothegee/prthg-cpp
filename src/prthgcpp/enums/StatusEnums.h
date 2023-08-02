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
        undefined = EStatusBuild::eStatusBuild_undefined,
        development = EStatusBuild::eStatusBuild_development,
        staging = EStatusBuild::eStatusBuild_staging,
        demo = EStatusBuild::eStatusBuild_demo,
        production = EStatusBuild::eStatusBuild_production,
    };
} // namespace prthgcpp


#endif // PRTHGCPP_STATUS_ENUMS_H