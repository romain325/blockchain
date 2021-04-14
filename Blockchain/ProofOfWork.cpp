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

unsigned int ProofOfWork::DIFFICULTY = 3;

void ProofOfWork::proofOfWork(std::shared_ptr<bc::Block> block) {
    while (!ProofOfWork::validProof(block->hash())){
        block->proof++;
    }
}

bool ProofOfWork::validProof(std::string hash) {
    for (int i = 0; i < ProofOfWork::DIFFICULTY; i++) {
        if(hash[i] != '6') return false;
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
