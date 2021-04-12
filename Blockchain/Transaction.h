//
// Created by romain on 11/04/2021.
//


#ifndef BLOCKCHAIN_TRANSACTION_H
#define BLOCKCHAIN_TRANSACTION_H

#include <utility>

#include "../Utils/json.hpp"
using json = nlohmann::json;

namespace bc {
    struct Transaction {
        Transaction() = default;
        Transaction(std::string sender, std::string recipient, unsigned int amount)
                : sender(std::move(sender)), recipient(std::move(recipient)), amount(amount) {}

        std::string sender;
        std::string recipient;
        unsigned int amount;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Transaction, sender, recipient, amount);
}
#endif //BLOCKCHAIN_TRANSACTION_H
