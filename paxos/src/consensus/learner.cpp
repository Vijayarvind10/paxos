#include "learner.hpp"

namespace paxos {

void Learner::learn(const Message& msg) {
    if (msg.type == MessageType::ACCEPTED && msg.value) {
        consensus_value_ = msg.value;
    }
}

bool Learner::has_consensus() const {
    return consensus_value_.has_value();
}

std::optional<Value> Learner::get_consensus_value() const {
    return consensus_value_;
}

} // namespace paxos
