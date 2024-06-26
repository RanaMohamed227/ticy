#ifndef AGENT_H
#define AGENT_H

#include "gamestate.h"

struct possibleMove{
    int move;
    int score;
    int depth;
};

class Agent{
private:
    int playerNumber;
    bool human;

public:
    Agent(int);
    ~Agent();
    bool isHuman();
    int getPlayerNumber();

};

#endif // AGENT_H
