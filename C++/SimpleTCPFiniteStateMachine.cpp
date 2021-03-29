#include <string>
#include <vector>
#include <assert.h>
#include <map>
#include <iostream>

using namespace std;

class State
{
    private:
        string name;
        map<string, State *> transitions;
    public:
        State(string n) :name(n)
        {}
        void addTransitions(map<string, State *> m)
        {
            transitions = m;
        }
        State * getNextState(string t)
        {
            if(transitions.find(t) == transitions.end())
                return nullptr;
            return transitions[t];
        }
        string getName() {return name;}
};

class DFA
{
    private:
    vector<State *> states;
    public:
        DFA(vector<State *> s) : states(s)
        {}

        ~DFA()
        {
            for(int i=0; i<states.size(); ++i)
                delete states[i];
        }

        string evaluate(vector<string> commands)
        {
            State * currentState = states[0];

            for(int i=0; i<commands.size() && currentState != nullptr; ++i)
            {
                currentState = currentState->getNextState(commands[i]);
            }

            if(currentState == nullptr)
                return "ERROR";

            return currentState->getName();
        }
};

string traverse_TCP_states(const std::vector<std::string> &events){
  
  State * CLOSED = new State("CLOSED");
  State * LISTEN = new State("LISTEN");
  State * SYN_RCVD = new State("SYN_RCVD");
  State * SYN_SENT = new State("SYN_SENT");
  State * ESTABLISHED = new State("ESTABLISHED");
  State * FIN_WAIT_1 = new State("FIN_WAIT_1");
  State * CLOSING = new State("CLOSING");
  State * FIN_WAIT_2 = new State("FIN_WAIT_2");
  State * TIME_WAIT= new State("TIME_WAIT");
  State * CLOSE_WAIT = new State("CLOSE_WAIT");
  State * LAST_ACK = new State("LAST_ACK");

  CLOSED->addTransitions({
      {"APP_PASSIVE_OPEN",LISTEN},
      {"APP_ACTIVE_OPEN",SYN_SENT}
  });
  LISTEN->addTransitions({
      {"RCV_SYN",SYN_RCVD},
      {"APP_SEND",SYN_SENT},
      {"APP_CLOSE",CLOSED}
  });
 SYN_RCVD->addTransitions({
      {"APP_CLOSE", FIN_WAIT_1},
      {"RCV_ACK", ESTABLISHED}
  });
  SYN_SENT->addTransitions({
      {"RCV_SYN", SYN_RCVD},
      {"RCV_SYN_ACK", ESTABLISHED},
      {"APP_CLOSE", CLOSED}
  });
  ESTABLISHED->addTransitions({
      {"APP_CLOSE", FIN_WAIT_1},
      {"RCV_FIN", CLOSE_WAIT}
  });
  FIN_WAIT_1->addTransitions({
      {"RCV_FIN_ACK", TIME_WAIT},
      {"RCV_ACK", FIN_WAIT_2},
      {"RCV_FIN", CLOSING}
  });
  CLOSING->addTransitions({
      {"RCV_ACK", TIME_WAIT}
  });
  FIN_WAIT_2->addTransitions({
      {"RCV_FIN", TIME_WAIT}
  });
  TIME_WAIT->addTransitions({
      {"APP_TIMEOUT", CLOSED}
  });
  CLOSE_WAIT->addTransitions({
      {"APP_CLOSE", LAST_ACK},
  });
  LAST_ACK->addTransitions({
      {"RCV_ACK", CLOSED}
  });

  DFA dfa({CLOSED,LISTEN,SYN_RCVD,SYN_SENT,ESTABLISHED,FIN_WAIT_1,FIN_WAIT_2,CLOSING, TIME_WAIT, CLOSE_WAIT,LAST_ACK});

  return dfa.evaluate(events);
}
