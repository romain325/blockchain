//
// Created by romain on 15/04/2021.
//

#ifndef BLOCKCHAIN_NODE_H
#define BLOCKCHAIN_NODE_H


#include <cstddef>
#include <cstdint>
#include <string>

class Node {
private:
    std::string mHost;
public:
    Node() = default;
    Node(const Node& node) =default;
    Node(std::string host);
    std::string getHost() const {return this->mHost;};
    bool operator==(const Node& node) const;

};

namespace std {
    template <> struct hash<Node>{
        size_t operator()(const Node& node) const
        {
            return std::hash<std::string>()(node.getHost());
        }
    };
}

#endif //BLOCKCHAIN_NODE_H
