#include <map>

using namespace std;

class State
{
  private:
    bool isAccept;
    map<char, State *> transitions;  
  
  public:
    State(bool a)
    {
      isAccept = a;
    }
    
    bool isAcceptingState() {return isAccept;}
    
    State * transition(char c)
    {
       return transitions[c];
    }
  
    void addTransition(State * s, char c)
    {
      transitions.insert(pair<char, State*>(c, s));
    }
};

class Automaton
{
  private:
    vector<State *> states; //index 0 is start state
public:
  Automaton();
  bool read_commands(const std::vector<char>& commands);
  ~Automaton();
};

Automaton::Automaton()
{
  State * q1 = new State(false);
  State * q2 = new State(true);
  State * q3 = new State(false);
  
  q1->addTransition(q2, '1');
  q1->addTransition(q1, '0');
  
  q2->addTransition(q2, '1');
  q2->addTransition(q3, '0');
  
  q3->addTransition(q2, '0');
  q3->addTransition(q2, '1');
  
  states.push_back(q1);
  states.push_back(q2);
  states.push_back(q3);
}

Automaton::~Automaton()
{
  for(int i=0; i<states.size(); ++i)
    delete states[i];
}

bool Automaton::read_commands(const vector<char>& commands)
{
  State * currentState = states[0];
  
  for(int i=0; i<commands.size(); ++i)
     currentState = currentState->transition(commands[i]);


  return currentState->isAcceptingState();
}
