#pragma once
#include "types.hpp"
#include <optional>

namespace paxos {

enum class MessageType {
    PREPARE,
    PROMISE,
    ACCEPT,
    ACCEPTED,
    LEARN
};

struct Message {
    MessageType type;
    ProposalId proposal_id;
    std::optional<Value> value;
    std::optional<ProposalId> accepted_proposal;
    std::optional<Value> accepted_value;
};

} // namespace paxos
