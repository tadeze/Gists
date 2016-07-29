/*
 * demo.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: tadeze
 */
#include "gtest/gtest.h"
#include "Main/factorial.hpp"
GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


