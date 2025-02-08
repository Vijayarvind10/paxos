#include <gtest/gtest.h>
#include "consensus/acceptor.hpp"
#include "consensus/proposer.hpp"
#include "consensus/learner.hpp"
#include "core/messages.hpp"

namespace paxos {
namespace {

TEST(AcceptorTest, HandlePrepare) {
    Acceptor acceptor("test_acceptor");
    
    ProposalId proposal_id{1, "proposer1"};
    Message prepare_msg{
        .type = MessageType::PREPARE,
        .proposal_id = proposal_id
    };
    
    auto response = acceptor.handle_prepare(prepare_msg);
    ASSERT_TRUE(response.has_value());
    EXPECT_EQ(response->type, MessageType::PROMISE);
    EXPECT_EQ(response->proposal_id, proposal_id);
}

TEST(AcceptorTest, HandleAccept) {
    Acceptor acceptor("test_acceptor");
    
    ProposalId proposal_id{1, "proposer1"};
    Value test_value = "test_value";
    
    Message accept_msg{
        .type = MessageType::ACCEPT,
        .proposal_id = proposal_id,
        .value = test_value
    };
    
    auto response = acceptor.handle_accept(accept_msg);
    ASSERT_TRUE(response.has_value());
    EXPECT_EQ(response->type, MessageType::ACCEPTED);
    EXPECT_EQ(response->proposal_id, proposal_id);
    EXPECT_EQ(response->value, test_value);
}

TEST(ProposerTest, Propose) {
    std::vector<std::string> acceptors = {"acceptor1", "acceptor2", "acceptor3"};
    Proposer proposer("proposer1", acceptors);
    
    EXPECT_TRUE(proposer.propose("test_value"));
}

TEST(LearnerTest, Learn) {
    Learner learner;
    Value test_value = "test_value";
    
    Message accepted_msg{
        .type = MessageType::ACCEPTED,
        .proposal_id = ProposalId{1, "proposer1"},
        .value = test_value
    };
    
    learner.learn(accepted_msg);
    EXPECT_TRUE(learner.has_consensus());
    EXPECT_EQ(learner.get_consensus_value(), test_value);
}

} // namespace
} // namespace paxos
