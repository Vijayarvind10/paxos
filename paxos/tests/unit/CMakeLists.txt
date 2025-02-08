add_executable(test_consensus
    test_consensus.cpp
)

target_link_libraries(test_consensus
    PRIVATE
    paxos
    GTest::GTest
    GTest::Main
)

include(GoogleTest)
gtest_discover_tests(test_consensus)
