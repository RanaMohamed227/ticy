#include <QtTest>
#include "agent.h"
#include "gamestate.h"

class AgentTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    /*void testIsHuman();
    void testGetPlayerNumber();*/
    // Add more test functions as needed

private:
    Agent* agent;
    GameState* state;
};

void AgentTest::initTestCase() {
    agent = new Agent(1);  // Initialize the agent with player number 1
    state = new GameState(3, 1);  // Initialize a 3x3 game state with player 1
}

void AgentTest::cleanupTestCase() {
    delete agent;
    delete state;
}/*
void AgentTest::testIsHuman() {
    QCOMPARE(agent->isHuman(), false);  // Agent is not human
}

void AgentTest::testGetPlayerNumber() {
    QCOMPARE(agent->getPlayerNumber(), 1);  // Player number should be 1
}*/


// Add more test functions to test other functionalities

QTEST_MAIN(AgentTest)

#include "tst_agent.moc"
