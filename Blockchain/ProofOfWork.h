//
// Created by romain on 13/04/2021.
//

#ifndef BLOCKCHAIN_PROOFOFWORK_H
#define BLOCKCHAIN_PROOFOFWORK_H


#include <string>
#include "Block.h"

struct ProofOfWork {

    static unsigned int DIFFICULTY;

public:
    static void proofOfWork(std::shared_ptr<bc::Block> block);
    static std::string getUuid();
    static bool validProof(std::string hash);
};


#endif //BLOCKCHAIN_PROOFOFWORK_H
