//
// Created by romain on 15/04/2021.
//

#include "Node.h"

#include <utility>

bool bc::Node::operator==(const Node &node) const {
    return std::hash<Node>()(*this) == std::hash<Node>()(node);
}


