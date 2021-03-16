#include <string>
#include <stack>
#include <vector>
#include <map>

using namespace std;
bool isDigit(char );
vector<string> tokenizeString(string);
bool isHigherPrecedence(string, string);

map<string, int> PRECEDENCE_MAP = {
  {"+",4},
  {"-", 4},
  {"*", 3},
  {"/", 3},
  {"^", 2},
  {"(", 1},
  {")",1}
};

string to_postfix(string infix) { //algorithm used is the shunting algorithm
  
  stack<string> ops;
  string output = "";
  vector<string> tokens = tokenizeString(infix);
  
  for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
  {
    string token = *it;
    
    if(isDigit(token[0]))
      output += token;
    else if(token == "(" )//left Bracket
         ops.push(token);
    else if(token == ")" )//right bracket
    {
      while(!ops.empty() && ops.top() != "(")
      {
        output += ops.top();
        ops.pop();
      }
      ops.pop(); //discard corresponding left bracket
    }
    else //its a regular operator
    {
      while(!ops.empty() && ops.top() != "(" && isHigherPrecedence(ops.top(), token))
      {
        output += ops.top();
        ops.pop();
      }
      ops.push(token);
    }
  }

  while(!ops.empty()) //operators on stack
  {
      output += ops.top();
      ops.pop();
  }
      
  return output;
}

bool isHigherPrecedence(string op1, string op2)
{
   int left_precedence = PRECEDENCE_MAP[op1];
   int right_precedence = PRECEDENCE_MAP[op2];
  return (left_precedence <= right_precedence);
}
       
vector<string> tokenizeString(string str) //helper function that tokenizes strings using mathematical operators as separators
{
  string temp ="";
  vector<string> tokens;
  
  for(int i=0; i<str.length(); ++i)
  {
    if(isDigit(str[i]))
      temp += str[i];
    else
    {
      tokens.push_back(temp);
      temp = "";
      tokens.push_back(string(1,str[i]));
    }
  }
  
  if(temp != "")
    tokens.push_back(temp);
  
  return tokens;
}

bool isDigit(char d)
{
  return (d- '0' >=0 && d-'0'<=9);
}
       
