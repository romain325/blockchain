//
// Created by romain on 13/04/2021.
//

#ifndef BLOCKCHAIN_PROOFOFWORK_H
#define BLOCKCHAIN_PROOFOFWORK_H


#include <string>

struct ProofOfWork {
    static std::string getUuid();

    static bool validProof(int lastproof, int proof);

private:
    static unsigned int DIFFICULTY;
    static std::string hash(int lastproof, int proof);

public:
    static int proofOfWork(int lastproof);

};


#endif //BLOCKCHAIN_PROOFOFWORK_H
