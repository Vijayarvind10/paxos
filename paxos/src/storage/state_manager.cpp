#include "state_manager.hpp"
#include <fstream>
#include <sstream>

namespace paxos {

void StateManager::persist_state(const State& state) {
}

std::optional<State> StateManager::recover_state() {
    return std::nullopt;
}

} // namespace paxos
