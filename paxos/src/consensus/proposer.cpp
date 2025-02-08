#include "proposer.hpp"

namespace paxos {

Proposer::Proposer(std::string id, std::vector<std::string> acceptors)
    : id_(std::move(id))
    , acceptors_(std::move(acceptors)) {}

ProposalId Proposer::get_next_proposal_id() {
    return ProposalId{++proposal_number_, id_};
}

bool Proposer::has_majority(const std::set<std::string>& responses) {
    return responses.size() > acceptors_.size() / 2;
}

bool Proposer::propose(const Value& value) {
    auto proposal_id = get_next_proposal_id();
    proposals_[proposal_id] = value;
    promises_[proposal_id] = {};
    accepts_[proposal_id] = {};
    return true;
}

void Proposer::handle_promise(const Message& msg) {
    if (promises_.count(msg.proposal_id) > 0) {
        promises_[msg.proposal_id].insert(msg.proposal_id.proposer_id);
        if (has_majority(promises_[msg.proposal_id])) {
        }
    }
}

void Proposer::handle_accepted(const Message& msg) {
    if (accepts_.count(msg.proposal_id) > 0) {
        accepts_[msg.proposal_id].insert(msg.proposal_id.proposer_id);
        if (has_majority(accepts_[msg.proposal_id])) {
        }
    }
}

} // namespace paxos
