#include "Utility.h"


prthgcpp::CUtility::CUtility()
{
}

prthgcpp::CUtility::~CUtility()
{
}




template <typename T>
T prthgcpp::CUtility::GenerateRandomNumber(const T min, const T max) const
{
    T result;

    std::random_device rd;
    std::default_random_engine re(rd());

    if (std::is_same<T, int>::value)
    {
        std::uniform_int_distribution<> distribute(min, max);

        result = distribute(re);
    }
    else if (std::is_same<T, double>::value)
    {
        std::uniform_real_distribution<> distribute(min, max);

        result = distribute(re);
    }
    else
    {
        std::uniform_int_distribution<> distribute(min, max);

        result = distribute(re);
    }

    return result;
}

std::string prthgcpp::CUtility::GenerateRandomAlphanumeric(int length) const
{
    std::string result;

    if (length <= 0) { length = 1; }

    result.reserve(length);

    for (int i = 0; i < length; i++)
    {
        int j = GenerateRandomNumber(0, (int)m_alphanumeric.length() - 1);
        result += m_alphanumeric[j];
    }

    return result;
}

std::string prthgcpp::CUtility::GenerateRandomUUID() const
{
    std::string result;
    std::string str1(GenerateRandomAlphanumeric(8)), str2(GenerateRandomAlphanumeric(4)), str3(GenerateRandomAlphanumeric(4)), str4(GenerateRandomAlphanumeric(4)), str5(GenerateRandomAlphanumeric(12));

    result = str1 + "-" + str2 + "-" + str3 + "-" + str4 + "-" + str5;

    return result;
}

bool prthgcpp::CUtility::CheckInputIsAlphabetic(const std::string input) const
{
    auto itter = std::find_if(input.begin(), input.end(), [](char const& c)
    {
        return !isalpha(c);
    });

    return itter == input.end();
}

bool prthgcpp::CUtility::CheckInputIsAlphaNumeric(const std::string input) const
{
    auto itter = std::find_if(input.begin(), input.end(), [](char const& c)
    {
        return !isalnum(c);
    });

    return itter == input.end();
}

std::string prthgcpp::CUtility::ChangeInputLetterCase(const std::string input, const int letterCase) const
{
    std::string result;

    result.reserve(input.length());

    switch (letterCase)
    {
        case 0:
        {
            for (int i = 0; i < input.length(); i++)
            {
                result += tolower(input[i]);
            }
        }
        break;

        case 1:
        {
            for (int i = 0; i < input.length(); i++)
            {
                result += toupper(input[i]);
            }
        }
        break;

        case 2:
        {
            for (int i = 0; i < input.length(); i++)
            {
                //  0 is lower, 1 is upper
                int mixedcase = GenerateRandomNumber(0, 1);

                if (mixedcase == 0 && isalpha(input[i]))
                {
                    result += tolower(input[i]);
                }
                else if (mixedcase == 1 && isalpha(input[i]))
                {
                    result += toupper(input[i]);
                }
                else
                {
                    result += input[i];
                }
            }
        }
        break;

        default:
        {
            result = input;
        }
        break;
    }

    return result;
}

std::string prthgcpp::CUtility::StringFromJson(const Json::Value input) const
{
    std::string result;

    Json::StreamWriterBuilder builder;
    result = Json::writeString(builder, input);

    return result;
}

Json::Value prthgcpp::CUtility::JsonFromString(const std::string input) const
{
    Json::Value result;

    JSONCPP_STRING err;
    Json::CharReaderBuilder builder;
    const int inputLength = static_cast<int>(input.length());

    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    reader->parse(input.c_str(), input.c_str() + inputLength, &result, &err);

    return result;
}
