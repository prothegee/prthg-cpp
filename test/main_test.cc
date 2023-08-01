#include <iostream>
#include <stdexcept>
#include <prthgcpp/prthgcpp.h>


class CTest1
{
private:
    const std::string m_email = "foo@bar.baz";

    const std::string m_password = "password123!";
    const std::string m_passwordSalt = "superSALT321!";

    const std::string m_message = "secret message #1 !";

    const std::string m_iKeyXChaCha20 = "abcdefghijklmnopqrstuvwxyz123456";
    const std::string m_iVecXChaCha20 = "abcdefghijklmnopqrstuvwx";

    const int m_iKeyAES = 123456789;
    const int m_iVecAES = 987654321;

    const int m_iKeyRC6 = 1234567891234567;
    const int m_iVecRC6 = 9876543219876543;

protected:
    void RunTestUtilityClass()
    {
        prthgcpp::CUtility util;


        std::cout << "Generate Random Alphanumeric:\n";
        for (int i = 0; i < 10; i++)
        {
            std::cout << util.GenerateRandomAlphanumeric(i) << "\n";
        }
        std::cout << "\n";


        std::cout << "Generate Random UUID:\n";
        for (int i = 0; i < 10; i++)
        {
            std::string uuid = util.GenerateRandomUUID();
            std::cout << uuid << "\n";
            std::cout << util.ChangeInputLetterCase(uuid, 0) << "\n";
            std::cout << util.ChangeInputLetterCase(uuid, 1) << "\n";
            std::cout << util.ChangeInputLetterCase(uuid, 2) << "\n";
            std::cout << "\n";
        }


        const std::string t1 = "qweasd";
        if (util.CheckInputIsAlphabetic(t1))
        {
            std::cout << t1 << " is alphabetic\n";
        }
        std::cout << "\n";


        const std::string t2 = "asdzxc123456";
        if (util.CheckInputIsAlphaNumeric(t2))
        {
            std::cout << t2 << " is alphanumeric\n";
        }
        std::cout << "\n";
    }

    void RunTestCryptographyClassHasher()
    {
        prthgcpp::CCryptography crypt;


        std::string SHA1 = crypt.GenerateSHA1(m_email);
        if (SHA1 != "93560DA644DAA8BE7EC684EA113CA02287F80AD7")
        {
            throw std::invalid_argument("SHA1 failed");
        }


        std::string SHA224 = crypt.GenerateSHA224(m_email);
        if (SHA224 != "9BE6EC75046155F3B5737BECA50B278FA01CD21E487CC88ADB019CF5")
        {
            throw std::invalid_argument("SHA224 failed");
        }


        std::string SHA256 = crypt.GenerateSHA256(m_email);
        if (SHA256 != "80C66BDD90AE7FD4378CEF780422FE428EE7FB526301F7B236113C4ECE3BE146")
        {
            throw std::invalid_argument("SHA256 failed");
        }


        std::string SHA384 = crypt.GenerateSHA384(m_email);
        if (SHA384 != "A7CF0DC6586E904F0FA5CDE24AFC64ED5D8730599FAD759A4E8543EFCFE687CEDC70A68B50384E9DBC9F816CCFF07186")
        {
            throw std::invalid_argument("SHA384 failed");
        }


        std::string SHA512 = crypt.GenerateSHA512(m_email);
        if (SHA512 != "C6A0F190A0E38156B5A8DEB0E1BB5B192FFAEA46BF4C3E69082B3D71F85C7B3DDC8E5AFC4A81A5565F36361811ABBEE4E88CC1B367D6A6A8EAC36C31BD9ED75C")
        {
            throw std::invalid_argument("SHA512 failed");
        }


        std::string BLAKE2b = crypt.GenerateBLAKE2b(m_email);
        if (BLAKE2b != "BB07EFD34B28ED04357C760D2E2C00EF947E612D12D68E12A67B19B3F09E7C02A9D2D979F64BDCA47C35A2EFAF2E3B1AF2964475F616EFFA843B3FC25A83DC7A")
        {
            throw std::invalid_argument("BLAKE2b failed");
        }
    }

    void RunTestCryptographyClassPasswordHasher()
    {
        prthgcpp::CCryptography crypt;


        std::string SCRYPT = crypt.GenerateHasherSCRYPT(m_password, m_passwordSalt);
        if (SCRYPT != "0E3CBFDA7121E108F4CE6800C03C18171FB47BB46AAB782796F1D6F3FF9F798BFA6C159D38B685C91CF91C28082D4C92C41243DFD13048620672504F5AB3DA26593592312239D38A6ACCFCA37328B3AD87A0DA385AE038D08BD09A73D8CB70EF69C3D5FA5FA92E374390633812ABBA292809E11CA9593ED3518B6FAF9CAA19B8C8BDA858BEE52539E6AAC0758DA8988E3565DACED44CBAED2BC95E74D131B2E1C45F7C3C8942CBD801392FBCC14462C577F3F29E88C0474ED84DFC0CBB5D05C52F85C4208C70A94FEAC26A5441EA7AA3A63EEC45FBC641C66992E86A137E2CEA0F457C0E037F375AA11FF773C85F7925B34A77CB8CB8BB8F1FCFBD9821A993D8")
        {
            throw std::invalid_argument("SCRYPT failed");
        }
    }

    void RunTestCryptographyClassStreamCipher()
    {
        prthgcpp::CCryptography crypt;


        std::string EncryptXChaCha20 = crypt.EncryptXChaCha20(m_message, m_iKeyXChaCha20, m_iVecXChaCha20);
        std::string DecryptXChaCha20 = crypt.DecryptXChaCha20(EncryptXChaCha20, m_iKeyXChaCha20, m_iVecXChaCha20);
        if (m_message != DecryptXChaCha20)
        {
            throw std::invalid_argument("XChaCha20 message & decrypt failed");
        }


        std::string EncryptAES = crypt.EncryptAES(m_message, m_iKeyAES, m_iVecAES);
        std::string DecryptAES = crypt.DecryptAES(EncryptAES, m_iKeyAES, m_iVecAES);
        if (m_message != DecryptAES)
        {
            throw std::invalid_argument("AES Rijndael message & decrypt failed");
        }


        std::string EncryptRC6 = crypt.EncryptRC6(m_message, m_iKeyRC6, m_iVecRC6);
        std::string DecryptRC6 = crypt.DecryptRC6(EncryptRC6, m_iKeyRC6, m_iVecRC6);
        if (m_message != DecryptRC6)
        {
            throw std::invalid_argument("RC6 message & decrypt failed");
        }
    }

public:
    CTest1(){}
    ~CTest1(){}

    void TestUtility()
    {
        std::cout << "Test CUtility: Started\n";

        RunTestUtilityClass();
    
        std::cout << "Test CUtility: Finished\n";
    }

    void TestCryptography()
    {
        std::cout << "Test CCryptography: Started\n";

        RunTestCryptographyClassHasher();
        RunTestCryptographyClassPasswordHasher();
        RunTestCryptographyClassStreamCipher();

        std::cout << "Test CCryptography: Finished\n";
    }
};


int main()
{
    std::unique_ptr<CTest1> pTest = std::make_unique<CTest1>();


    pTest->TestCryptography();
    pTest->TestUtility();


    return 0;
}