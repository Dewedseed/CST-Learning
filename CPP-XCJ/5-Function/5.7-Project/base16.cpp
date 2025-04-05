#include "base16.h"
#include <string>
#include <vector>

// encoding table
static const std::string  base16_enc_tab {
    "0123456789ABCDEF"
};

// decoding table
static const std::vector<char> base16_dec_tab {
    -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, // 0 ~ 9
    -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, // 10 ~ 19
    -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, // 20 ~ 29
    -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, // 30 ~ 39
    -1, -1, -1, -1, -1,  -1, -1, -1,         // 40 ~ 47
     0,  1,  2,  3,  4,   5,  6,  7,  8,  9, // 48 ~ 57
    -1, -1, -1, -1, -1,  -1, -1,             // 58 ~ 64
    10, 11, 12, 13, 14,  15                  // 65 ~ 70
};

/*
base16 encode
@para data encode binary code
@return base16 string / empty
*/
std::string Base16Encode(
    const std::vector<unsigned char>& data)
{
    std::string base16str;
    for (unsigned char c : data){
        // 0100 0001 => 0000 0100
        char h = c >> 4;
        // 0100 0001 => 0000 0001
        char l = c & 0b00001111;
        // encode
        base16str += base16_enc_tab[h];
        base16str += base16_enc_tab[l];
    }
    return base16str;
}

/*
base16 decode
@para str base16 encode string
@return decode data
*/
std::vector<unsigned char> Base16Decode(
    const std::string &str)
{
    std::vector<unsigned char> res;
    int len = str.length();
    for (int i = 0; i < len; i += 2) {
        char ch = str[i];
        char cl = str[i+1];

        // decode
        unsigned char h = base16_dec_tab[ch];
        unsigned char l = base16_dec_tab[cl];

        res.push_back(h << 4 | l);
    }
    return res;
}
