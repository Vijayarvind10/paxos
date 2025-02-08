#pragma once
#include "../core/types.hpp"
#include <optional>
#include <string>
#include <fstream>

namespace paxos {

struct State {
    std::optional<ProposalId> promised_id;
    std::optional<ProposalId> accepted_id;
    std::optional<Value> accepted_value;
};

class StateManager {
public:
    explicit StateManager(std::string filename)
        : filename_(std::move(filename)) {}
    
    void persist_state(const State& state);
    std::optional<State> recover_state();

private:
    std::string filename_;
};

} // namespace paxos
