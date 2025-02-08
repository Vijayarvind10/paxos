#pragma once
#include "../core/messages.hpp"
#include "../storage/state_manager.hpp"
#include <string>
#include <optional>

namespace paxos {

class Acceptor {
public:
    explicit Acceptor(std::string id);
    std::optional<Message> handle_prepare(const Message& msg);
    std::optional<Message> handle_accept(const Message& msg);

private:
    std::string id_;
    std::optional<ProposalId> promised_id_;
    std::optional<ProposalId> accepted_id_;
    std::optional<Value> accepted_value_;
    StateManager state_manager_;
};

} // namespace paxos
