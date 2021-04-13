//
// Created by romain on 13/04/2021.
//

#include "Block.h"
#include <openssl/sha.h>

std::string bc::Block::hash() {
    json j = *this;
    unsigned char hash[SHA512_DIGEST_LENGTH];
    char result[128];

    SHA512(reinterpret_cast<const unsigned char*>(j.dump().c_str()), strlen(j.dump().c_str()), hash);

    for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
        sprintf(result + (i * 2), "%02x", hash[i]);
    }
    return std::string(result);
}