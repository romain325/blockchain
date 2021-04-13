//
// Created by romain on 13/04/2021.
//

#include <openssl/sha.h>
#include <cstring>
#include <random>
#include <iostream>
#include "ProofOfWork.h"
#include "../Utils/base64.h"

using namespace macaron;

unsigned int ProofOfWork::DIFFICULTY = 4;

std::string ProofOfWork::hash(int lastproof, int proof) {
    std::string j = Base64::Encode(std::to_string(lastproof) + std::to_string(proof));
    unsigned char hash[SHA512_DIGEST_LENGTH];
    char result[128];

    SHA512(reinterpret_cast<const unsigned char*>(j.c_str()), strlen(j.c_str()), hash);

    for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
        sprintf(result + (i * 2), "%02x", hash[i]);
    }
    return std::string(result);
}

int ProofOfWork::proofOfWork(int lastproof) {
    int proof = 0;
    while (!ProofOfWork::validProof(lastproof,proof)){
        proof++;
    }
    return proof;
}

bool ProofOfWork::validProof(int lastproof, int proof) {
    std::string hash = ProofOfWork::hash(lastproof,proof);
    for (int i = 1; i < ProofOfWork::DIFFICULTY +1; i++) {
        if(hash[hash.size() - i] != '0') return false;
    }
    return true;
}

std::string ProofOfWork::getUuid() {
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const char *v = "0123456789abcdef";
    const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

    std::string res;
    for (int i = 0; i < 16; i++) {
        if (dash[i]) res += "-";
        res += v[dist(rng)];
        res += v[dist(rng)];
    }
    return res;
}
