# Paxos Consensus Algorithm Implementation

## Overview

This project implements the Paxos consensus algorithm in C++.

## Features

- **Proposer**: Proposes values to be agreed upon.
- **Acceptor**: Accepts or rejects proposals.
- **Learner**: Learns the agreed-upon value.

The implementation follows the classic two-phase Paxos protocol:
1. **Phase 1 (Prepare/Promise)**
   - Proposer sends a prepare request.
   - Acceptors respond with promises.
2. **Phase 2 (Accept/Accepted)**
   - Proposer sends an accept request.
   - Acceptors accept the value.
   - Learner learns the accepted value.

## Requirements

- C++17 or higher
- CMake 3.15 or higher
- Google Test (for unit tests)

## Build Instructions

To build the project, use the following commands:

```bash
mkdir -p build && cd build
cmake ..
make
Running Tests
To run unit tests, use:


cd build
ctest --verbose
Project Structure

src/
├── consensus/
│   ├── acceptor.hpp      # Acceptor interface
│   ├── acceptor.cpp      # Acceptor implementation
│   ├── proposer.hpp      # Proposer interface
│   ├── proposer.cpp      # Proposer implementation
│   ├── learner.hpp       # Learner interface
│   └── learner.cpp       # Learner implementation
├── core/
│   ├── messages.hpp      # Message definitions
│   └── types.hpp         # Basic type definitions
└── storage/
    └── state_manager.hpp # State persistence interface
tests/
└── unit/
    ├── CMakeLists.txt
    └── test_consensus.cpp
Usage Example

// Setup participants
std::vector<std::string> acceptor_ids = {"server1", "server2", "server3"};
std::vector<Acceptor> acceptors;
for (const auto& id : acceptor_ids) {
    acceptors.emplace_back(id);
}

Proposer proposer("proposer1", acceptor_ids);
Learner learner;

// Value to be agreed upon
Value proposed_value = "important_data";

// Phase 1a: Proposer sends prepare
auto proposal_id = proposer.start_prepare();

// Phase 1b: Acceptors handle prepare
for (auto& acceptor : acceptors) {
    Message prepare_msg{
        .type = MessageType::PREPARE,
        .proposal_id = proposal_id
    };
    auto promise = acceptor.handle_prepare(prepare_msg);
    if (promise) {
        proposer.handle_promise(promise);
    }
}

// Phase 2a: Proposer sends accept
auto accept_msg = proposer.propose(proposed_value);

// Phase 2b: Acceptors handle accept
for (auto& acceptor : acceptors) {
    auto accepted = acceptor.handle_accept(accept_msg);
    if (accepted) {
        learner.learn(accepted);
    }
}

// Check consensus
if (learner.has_consensus()) {
    std::cout << "Consensus reached on: "
              << learner.get_consensus_value() << std::endl;
}
Limitations
In-memory implementation (no network layer).
Basic state management.
No failure recovery mechanisms.
Contributing
Contributions are welcome! Feel free to submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details.

References
Paxos Made Simple by Leslie Lamport
Understanding Paxos


Copyright (c) 2025 [Vijay Arvind Ramamoorthy]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
