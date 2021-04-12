#include <utility>

//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

struct Transaction{
    Transaction(std::string sender, std::string recipient, unsigned int amount)
        : sender(std::move(sender)), recipient(std::move(recipient)), amount(amount) {}

    std::string sender;
    std::string recipient;
    unsigned int amount;
};

#endif //BLOCKCHAIN_TRANSACTION_H
