#pragma once
#include "../core/messages.hpp"
#include <string>

namespace paxos {

class Learner {
public:
    Learner() = default;
    ~Learner() = default;
    
    void learn(const Message& msg);
    bool has_consensus() const;
    std::optional<Value> get_consensus_value() const;

private:
    std::optional<Value> consensus_value_;
};

} // namespace paxos
