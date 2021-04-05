// Copyright 2021
#include <iostream>
#include <string>

#include "train.h"
#include <ctime>

int main() {
    srand(time(nullptr));
    Train newTrain;
    for (size_t i = 0; i < 5; ++i) {
        Cage* cgtmp = new Cage();
        cgtmp->setLight();
        newTrain.addCage(cgtmp);
    }
    newTrain.printState();
    std::cout << newTrain.calculateLength() << std::endl;
    return 0;
}
