#include "acceptor.hpp"

namespace paxos {

Acceptor::Acceptor(std::string id) 
    : id_(std::move(id))
    , state_manager_("acceptor_" + id_) {
    auto state = state_manager_.recover_state();
    if (state) {
        promised_id_ = state->promised_id;
        accepted_id_ = state->accepted_id;
        accepted_value_ = state->accepted_value;
    }
}

std::optional<Message> Acceptor::handle_prepare(const Message& msg) {
    if (!promised_id_ || msg.proposal_id >= *promised_id_) {
        promised_id_ = msg.proposal_id;
        state_manager_.persist_state({promised_id_, accepted_id_, accepted_value_});
        return Message{
            .type = MessageType::PROMISE,
            .proposal_id = msg.proposal_id,
            .accepted_proposal = accepted_id_,
            .accepted_value = accepted_value_
        };
    }
    return std::nullopt;
}

std::optional<Message> Acceptor::handle_accept(const Message& msg) {
    if (!promised_id_ || msg.proposal_id >= *promised_id_) {
        promised_id_ = msg.proposal_id;
        accepted_id_ = msg.proposal_id;
        accepted_value_ = msg.value;
        state_manager_.persist_state({promised_id_, accepted_id_, accepted_value_});
        return Message{
            .type = MessageType::ACCEPTED,
            .proposal_id = msg.proposal_id,
            .value = msg.value
        };
    }
    return std::nullopt;
}

} // namespace paxos
