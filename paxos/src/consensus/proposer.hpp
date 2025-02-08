#pragma once
#include "../core/messages.hpp"
#include <string>
#include <vector>
#include <map>
#include <set>

namespace paxos {

class Proposer {
public:
    Proposer(std::string id, std::vector<std::string> acceptors);
    bool propose(const Value& value);
    void handle_promise(const Message& msg);
    void handle_accepted(const Message& msg);

private:
    ProposalId get_next_proposal_id();
    bool has_majority(const std::set<std::string>& responses);

    std::string id_;
    std::vector<std::string> acceptors_;
    int proposal_number_ = 0;
    std::map<ProposalId, Value> proposals_;
    std::map<ProposalId, std::set<std::string>> promises_;
    std::map<ProposalId, std::set<std::string>> accepts_;
};

} // namespace paxos
