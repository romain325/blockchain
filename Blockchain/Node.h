//
// Created by romain on 15/04/2021.
//

#ifndef BLOCKCHAIN_NODE_H
#define BLOCKCHAIN_NODE_H


#include <cstddef>
#include <cstdint>
#include <string>
#include "../Utils/json.hpp"
using json = nlohmann::json;

namespace bc {
    class Node {
    public:
        std::string mHost;

        Node() = default;
        Node(const Node &node) = default;

        explicit Node(std::string host) : mHost(std::move(host)) {};
        std::string getHost() const { return this->mHost; };
        bool operator==(const Node &node) const;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Node, mHost);

}
namespace std {
    template <> struct hash<bc::Node>{
        size_t operator()(const bc::Node& node) const
        {
            return std::hash<std::string>()(node.getHost());
        }
    };
}

#endif //BLOCKCHAIN_NODE_H
