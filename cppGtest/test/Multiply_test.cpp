/*
 * Multiply_test.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: tadeze
 */
#include "gtest/gtest.h"
#include "../Main/Multiply.h"

class MultiplyTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {

    // Code here will be called immediately after each test

    // (right before the destructor).
  }

};

TEST_F(MultiplyTest,twoValues){
    const int x = 4;
    const int y = 5;
    Multiply multiply;
    EXPECT_EQ(20,multiply.twoValues(x,y));
    EXPECT_EQ(6,multiply.twoValues(2,3));
}
