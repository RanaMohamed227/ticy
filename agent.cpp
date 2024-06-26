#include "agent.h"
#include <iostream>

Agent::Agent(int p) {
    playerNumber = p;
    human = false;
}

Agent::~Agent() {
}

bool Agent::isHuman() {
    return human;
}

int Agent::getPlayerNumber() {
    return playerNumber;
}
