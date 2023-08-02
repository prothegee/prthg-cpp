#ifndef PRTHGCPP_CRYPTOGRAPHY_H
#define PRTHGCPP_CRYPTOGRAPHY_H
#include "prthgcpp/prthgcpp_config.gen.h"
#include "prthgcpp/prthgcpp_export.gen.h"

#include <string>

#include <cryptopp/ec2n.h>
#include <cryptopp/hex.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/secblock.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/words.h>

#include <cryptopp/blake2.h>
#include <cryptopp/scrypt.h>
#include <cryptopp/sha.h>
#include <cryptopp/gcm.h>
#include <cryptopp/aes.h>
#include <cryptopp/chacha.h>
#include <cryptopp/rc6.h>


namespace prthgcpp
{
    /**
     * @brief prthgcpp cryptography class
     * 
     */
    class CCryptography
    {
    private:
        /* data */

    protected:
        /* data */

    public:
        CCryptography(/* args */);
        ~CCryptography();


        /**
         * @brief generate sha1 from input
         * 
         * @note STATUS: OK
         * 
         * @note return length will be 40
         * 
         * @param input 
         * @return std::string asci
         */
        std::string GenerateSHA1(const std::string &input) const;

        /**
         * @brief generate sha224 from input
         * 
         * @note STATUS: OK
         * 
         * @note return length will be 56
         * 
         * @param input 
         * @return std::string asci
         */
        std::string GenerateSHA224(const std::string &input) const;

        /**
         * @brief generate sha256 from input
         * 
         * @note STATUS: OK
         * 
         * @note return length will be 64
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA256(const std::string &input) const;

        /**
         * @brief generate sha384 from input
         * 
         * @note STATUS: OK
         * 
         * @note return length will be 96
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA384(const std::string &input) const;

        /**
         * @brief generate sha512 from input
         * 
         * @note STATUS: OK
         * 
         * @note return length will be 128
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateSHA512(const std::string &input) const;


        /**
         * @brief generate blake2b from input
         * 
         * @note STATUS: OK
         * 
         * @note return length will be 128
         * 
         * @param input 
         * @return std::string 
         */
        std::string GenerateBLAKE2b(const std::string &input) const;


        /**
         * @brief generate password hasher using scrypt
         * 
         * @note STATUS: OK
         * 
         * @param input 
         * @param salt 
         * @return std::string 
         */
        std::string GenerateHasherSCRYPT(std::string input, std::string salt) const;


        /**
         * @brief encrypt input using XChaCha20 stream cipher
         * 
         * @note STATUS: OK
         * 
         * @note initializeKey length must 32 byte e.g. abcdefghijklmnopqrstuvwxyz123456
         * @note initializeVector length must 24 byte e.g. abcdefghijklmnopqrstuvwx
         * 
         * @param input 
         * @param initializeVector 
         * @param initializeKey 
         * @return std::string 
         */
        std::string EncryptXChaCha20(std::string input, std::string initializeKey, std::string initializeVector) const;

        /**
         * @brief decrypt input using XChaCha20 stream cipher
         * 
         * @note STATUS: OK
         * 
         * @note initializeKey length must 32 byte e.g. abcdefghijklmnopqrstuvwxyz123456
         * @note initializeVector length must 24 byte e.g. abcdefghijklmnopqrstuvwx
         * @note considering use RC6 if you want asci/alphanumeric result rather than unicode
         * 
         * @param input 
         * @param initializeVector 
         * @param initializeKey 
         * @return std::string unicode
         */
        std::string DecryptXChaCha20(std::string input, std::string initializeKey, std::string initializeVector) const;


        /**
         * @brief encrypt input using CBC AES Rijndael stream cipher
         * 
         * @note STATUS: OK
         * 
         * @note initializeKey length must 9 byte and can't start from 0 e.g. 123456789
         * @note initializeVector length must 9 byte and can't start from 0 e.g. 987654321
         * @note considering use RC6 if you want asci/alphanumeric result rather than unicode
         * 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string unicode
         */
        std::string EncryptAES(std::string input, int initializeKey, int initializeVector) const;

        /**
         * @brief decrypt input using CBC AES Rijndael stream cipher
         * 
         * @note STATUS: OK
         * 
         * @note initializeKey length must 9 byte and can't start from 0 e.g. 123456789
         * @note initializeVector length must 9 byte and can't start from 0 e.g. 987654321
         * @note considering use RC6 if you want asci/alphanumeric result rather than unicode
         * 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string unicode
         */
        std::string DecryptAES(std::string input, int initializeKey, int initializeVector) const;


        /**
         * @brief encrypt input using CBC R6 stream cipher
         * 
         * @note STATUS: OK
         * 
         * @note initializeKey length must 16 byte and can't start from 0 e.g. 1234567891234567
         * @note initializeVector length must 16 byte and can't start from 0 e.g. 9876543219876543
         * 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string asci/alphanumeric
         */
        std::string EncryptRC6(std::string input, long initializeKey, long initializeVector) const;

        /**
         * @brief decrypt input using CBC R6 stream cipher
         * 
         * @note STATUS: OK
         * 
         * @note initializeKey length must 16 byte and can't start from 0 e.g. 1234567891234567
         * @note initializeVector length must 16 byte and can't start from 0 e.g. 9876543219876543
         * 
         * @param input 
         * @param initializeKey 
         * @param initializeVector 
         * @return std::string asci/alphanumeric
         */
        std::string DecryptRC6(std::string input, long initializeKey, long initializeVector) const;
    };
} // namespace prthgcpp


#endif // PRTHGCPP_CRYPTOGRAPHY_H