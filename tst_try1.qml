import QtQuick 2.15
import QtTest 1.0

TestCase {
    name: "AgentTests"

        function test_createAgent() {
            var agent = new Agent();
            compare(agent.name, "DefaultAgentName", "Agent should have a default name");
        }

        function test_agentAction() {
            var agent = new Agent();
            var result = agent.performAction();
            verify(result !== null, "Agent should perform an action");
        }
}
