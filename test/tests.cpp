//  Copyright 2021 Nikita Naumov
#include <gtest/gtest.h>
#include <string>
#include "train.h"

TEST(Train, test1) {
    Train trainObj;
    const size_t n = 30;
    for (size_t i = 0; i < n; ++i) {
        Cage* cage = new Cage();
        trainObj.addCage(cage);
    }
    size_t expected = n;
    size_t result = trainObj.calculateLength();
    EXPECT_EQ(expected, trainObj.calculateLength());
}

TEST(Train, test2) {
    Train trainObj;
    const size_t n = 10;
    for (size_t i = 0; i < n; ++i) {
        Cage* cage = new Cage();
        trainObj.addCage(cage);
    }
    Cage* _cage = new Cage();
    trainObj.addCage(_cage);
    size_t expected = n+1;
    EXPECT_EQ(expected, trainObj.calculateLength());
}

TEST(Train, test3) {
    Train trainObj;
    size_t n = 15;
    for (size_t i = 0; i < n; ++i) {
        Cage* cage = new Cage();
        trainObj.addCage(cage);
    }
    for (size_t i = 0; i < n; ++i) {
        Cage* cage = new Cage();
        trainObj.addCage(cage);
    }
    size_t expected = 2*n;
    EXPECT_EQ(expected, trainObj.getLength());
}
