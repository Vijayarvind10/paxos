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


Markdown

## Project Structure

## Project Structure

* `src/`
    * `consensus/`
        * `acceptor.hpp`      # Acceptor interface
        * `acceptor.cpp`      # Acceptor implementation
        * `proposer.hpp`      # Proposer interface
        * `proposer.cpp`      # Proposer implementation
        * `learner.hpp`       # Learner interface
        * `learner.cpp`       # Learner implementation
    * `core/`
        * `messages.hpp`      # Message definitions
        * `types.hpp`         # Basic type definitions
    * `storage/`
        * `state_manager.hpp` # State persistence interface
        * `state_manager.cpp` # State persistence implementation
* `tests/`
    * `unit/`
        * `CMakeLists.txt`
        * `test_consensus.cpp`

## References
Paxos Made Simple by Leslie Lamport
Understanding Paxos
## Copyright
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
