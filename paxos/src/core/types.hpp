#pragma once
#include <string>
#include <optional>

namespace paxos {

using Value = std::string;

struct ProposalId {
    int number;
    std::string proposer_id;

    bool operator>=(const ProposalId& other) const {
        return number >= other.number;
    }

    bool operator<(const ProposalId& other) const {
        return number < other.number;
    }

    bool operator==(const ProposalId& other) const {
        return number == other.number && proposer_id == other.proposer_id;
    }
};

} // namespace paxos
