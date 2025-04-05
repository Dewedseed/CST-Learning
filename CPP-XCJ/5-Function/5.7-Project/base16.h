#pragma once
#include <vector>
#include <string>

/*
base16 encode
@para data encode binary code
@return base16 string / empty
*/
std::string Base16Encode(
    const std::vector<unsigned char>& data
);

/*
base16 decode
@para str base16 encode string
@return decode data
*/
std::vector<unsigned char> Base16Decode(
    const std::string &str
);
