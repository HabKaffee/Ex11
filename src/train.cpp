//  Copyright 2021 Nikita Naumov


#include <iostream>
#include "train.h"

void Cage::setLight() {
    switch (std::rand()%2) {
        case 0:
            this->off();
            break;
        case 1:
            this->on();
            break;
    }
}

void Cage::changeLight() {
    light = !light;
}


Train::Train() {
    this->first = nullptr;
    this->last = nullptr;
}

void Train::addCage(Cage *cageToAdd) {
    if (!first && !last) {
        first = cageToAdd;
        last = cageToAdd;
        first->prev = last;
        last->next = first;
        return;
    }
    last->next = cageToAdd;
    first->prev = cageToAdd;
    cageToAdd->prev = last;
    cageToAdd->next = first;
    last = cageToAdd;
}
void Train::printState() {
    Cage* ptr = first;
    unsigned cnt = 0;
    while (ptr != first->prev) {
        std::cout << cnt << ":" << ((ptr->getCurStatus()) ? ("on") : ("off")) << std::endl;
        ++cnt;
        ptr = ptr->next;
    }
    std::cout << cnt << ":" << (ptr->getCurStatus() ? ("on") : ("off")) << std::endl;
}

unsigned Train::calculateLength() {
    if (first == nullptr) {
        return 0;
    }
    unsigned length;
    unsigned counter = 1;
    Cage* ptr = first;
    const bool startStatus = first->getCurStatus();
    while (true) {
        ptr = ptr->next;
        if (ptr->getCurStatus() != startStatus) {
            ++counter;
            continue;
        } else {
            length = counter;
            ptr->changeLight();
            for (size_t i = 0; i < counter; ++i) {
                ptr = ptr->prev;
            }
            counter = 1;
            if (ptr->getCurStatus() != startStatus)
                return length;
        }
    }
}
