size_t duplicateCount(const std::string& in); // helper for tests

#include <map>
#include <iostream>

using namespace std;

size_t duplicateCount(const char* in)
{
  map<char,int> char_map;

  for(int i=0;in[i] != '\0'; ++i)
  {
    if(char_map.find(tolower(in[i])) != char_map.end())
       char_map.at(tolower(in[i]))++;
    else char_map.insert(pair<char, int>(tolower(in[i]), 1));
  }
  
  int duplicates = 0;
  
  for(map<char, int>::iterator it=char_map.begin(); it != char_map.end(); ++it)
    if(it->second >1)
      duplicates ++;
  
  return duplicates;
}
