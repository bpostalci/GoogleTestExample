#include <iostream>

#include "gtest/gtest.h"

class IntegerPair {
 public:
  IntegerPair(int x, int y) : x_(x), y_(y) {}
  IntegerPair() : x_(0), y_(0) {}
  int Mul() const { return x_ * y_; }
  int Sum() const { return x_ + y_; }
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }

 private:
  int x_, y_;
};

// The fixture for testing class Foo.
class PairArithmeticTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  PairArithmeticTest() : integer_pair_() {
    // You can do set-up work for each test here.
  }

  ~PairArithmeticTest() override {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.

  IntegerPair integer_pair_;
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(PairArithmeticTest, SummationWorks) {
  integer_pair_.SetX(20);
  integer_pair_.SetY(500);
  int expected_result = 20 + 500;
  EXPECT_EQ(integer_pair_.Sum(), expected_result);
}

TEST_F(PairArithmeticTest, MultiplicationWorks) {
  integer_pair_.SetX(20);
  integer_pair_.SetY(500);
  int expected_result = 20 * 500;
  EXPECT_EQ(integer_pair_.Mul(), expected_result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
