#include <cassert>
#include <iostream>
#include <string>

namespace ciphers
{
namespace caesar
{
inline char get_char(const int x)
{
    return char(x + 65);
}

inline int get_val(const char c)
{
    return int(c - 65);
}

std::string encrypt(const std::string &text, const int &shift)
{
    std::string encrypted = "";

    for (char c : text)
    {
        int place_val = get_val(c);
        place_val = (place_val + shift) % 26;
        char new_char = get_char(place_val);
        encrypted += new_char;
    }

    return encrypted;
}

std::string decrypt(const std::string &text, const int &shift)
{
    std::string decrypted = "";

    for (char c : text)
    {
        int place_val = get_val(c);
        place_val = (place_val - shift) % 26;

        if (place_val < 0)
        {
            place_val += 26;
        }

        char new_char = get_char(place_val);
        decrypted += new_char;
    }

    return decrypted;
}
} // namespace caesar
} // namespace ciphers

void test()
{
    // Test 1
    std::string text1 = "ALANTURING";
    std::string encrypted1 = ciphers::caesar::encrypt(text1, 17);
    std::string decrypted1 = ciphers::caesar::decrypt(encrypted1, 17);
    assert(text1 == decrypted1);
    std::cout << "Original text : " << text1;
    std::cout << " , Encrypted text (with shift = 21) : " << encrypted1;
    std::cout << " , Decrypted text : " << decrypted1 << std::endl;
    // Test 2
    std::string text2 = "HELLOWORLD";
    std::string encrypted2 = ciphers::caesar::encrypt(text2, 1729);
    std::string decrypted2 = ciphers::caesar::decrypt(encrypted2, 1729);
    assert(text2 == decrypted2);
    std::cout << "Original text : " << text2;
    std::cout << " , Encrypted text (with shift = 1729) : " << encrypted2;
    std::cout << " , Decrypted text : " << decrypted2 << std::endl;
}

int main()
{
    test();
    return 0;
}