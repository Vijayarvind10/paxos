# Paxos Consensus Algorithm Implementation

This project implements the Paxos consensus algorithm in C++.

## Features

* **Proposer:** Proposes values to be agreed upon.
* **Acceptor:** Accepts or rejects proposals.
* **Learner:** Learns the agreed-upon value.

The implementation follows the classic two-phase Paxos protocol:

1. **Phase 1 (Prepare/Promise)**
    * Proposer sends a prepare request.
    * Acceptors respond with promises.

2. **Phase 2 (Accept/Accepted)**
    * Proposer sends an accept request.
    * Acceptors accept the value.
    * Learner learns the accepted value.

## Requirements

* C++17 or higher
* CMake 3.15 or higher
* Google Test (for unit tests)

## Build Instructions

To build the project, use the following commands:

```bash
mkdir -p build && cd build
cmake ..
make
