#include <sstream>
#include<bits/stdc++.h>

int abs(int a)
{
  return a>0? -1*a: a;  
}

int indexOf(const std::vector<std::pair<std::string, int>>& copy, std::string str)
{
  for(int i=0; i<copy.size(); ++i)
    if(copy[i].first == str)
      return i;
  return -1;
}

namespace Closest //ignoring compiler warnings is one of my greatest c++ skills
{
    int weight(std::string);
    bool compareSecond(std::pair<std::string, int> &, std::pair<std::string, int>&);
    std::pair<int, int> getIndicesOfSmallestWeight(const std::vector<std::pair<std::string, int>> & pairs, const std::vector<std::pair<std::string, int>> & copy, const std::string & strng);
    std::vector<std::tuple<int, unsigned int, long long>> correctOrderVector(std::tuple<int, int, long long> first, std::tuple<int, int, long long> second);
  
    std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string &strng)
    {
       std::vector<std::pair<std::string, int>> pairs;
      std::vector<std::pair<std::string, int>> copy; //for finding indices of a number in the string
       std::istringstream ss(strng);
       for(std::string s; ss>>s;)
       {
           pairs.push_back(std::pair<std::string, int>(s, Closest::weight(s)));
           copy.push_back(std::pair<std::string, int>(s, Closest::weight(s)));
       }
      
       if(pairs.size() == 0)
        return {{},{}};
      
       sort(pairs.begin(), pairs.end(), Closest::compareSecond);
       std::pair<int,int> indices = Closest::getIndicesOfSmallestWeight(pairs, copy, strng);
       std::cout<<pairs[indices.first].first<<" "<<pairs[indices.second].first<<std::endl;
       std::tuple<int, int, long long> first = {pairs[indices.first].second, 
                                             indexOf(copy, pairs[indices.first].first), 
                                             std::stoll(pairs[indices.first].first)};
       std::tuple<int, int, long long> second = {pairs[indices.second].second, 
                                             indexOf(copy, pairs[indices.second].first), 
                                             std::stoll(pairs[indices.second].first)};
      
     
      return Closest::correctOrderVector(first, second); 
    }
    
   //spagheti code
  //returns the indices of the vector (pairs) in which the strings which are
  //the closest together, have the smallest indices and smallest weights are found
   std::pair<int, int> getIndicesOfSmallestWeight(const std::vector<std::pair<std::string, int>> & pairs, const std::vector<std::pair<std::string, int>> & copy, const std::string & strng)
   {
      std::pair<int,int> indices(-1, -1);
      int min_difference = INT_MAX;
      for(int i=0; i<pairs.size()-1; ++i)
      {
        for(int k=i+1; k<pairs.size(); ++k)
        {
          if(abs(pairs[i].second - pairs[k].second) < min_difference) //find smallest difference
          {
            min_difference = abs(pairs[i].second - pairs[k].second);
            indices.first = i;
            indices.second = k;
          }
          else if(abs(pairs[i].second - pairs[k].second) == min_difference) //smallest difference is the same, look for the smaller weights
          {
            int current_pair_sum_weights = pairs[indices.first].second + pairs[indices.second].second;
            int new_pair_sum_weights =pairs[i].second + pairs[k].second;

            if(current_pair_sum_weights > new_pair_sum_weights)
            {

              indices.first = i;
              indices.second = k;
            }
            else if(current_pair_sum_weights == new_pair_sum_weights)
            {
              int curr_sum_indices = indexOf(copy, pairs[indices.first].first) + indexOf(copy, pairs[indices.second].first);
              int new_sum_indices = indexOf(copy, pairs[i].first) + indexOf(copy, pairs[k].first);
              if(curr_sum_indices > new_sum_indices)
              {
                indices.first = i;
                indices.second = k;
              }
            }
          
          }
            
        }
      }
     
     return indices;
   }
  
   std::vector<std::tuple<int, unsigned int, long long>> correctOrderVector(std::tuple<int, int, long long> first, std::tuple<int, int, long long> second)
   {
      if(std::get<0>(first) > std::get<0>(second))
        return {second, first};
     else if (std::get<0>(first) == std::get<0>(second) && std::get<1>(first) > std::get<1>(second))
        return {second, first};
     else if (std::get<0>(first) == std::get<0>(second) && std::get<1>(first) == std::get<1>(second) && std::get<2>(first) > std::get<2>(second))
       return {second, first};
       
    return {first, second};
   }
  
  int weight(std::string str)
  {
    int weight = 0;
    
    for(int i=0;i<str.length(); ++i)
      weight += str[i] -'0';
    
    return weight;
  }
  
  bool compareSecond(std::pair<std::string, int> &a, std::pair<std::string, int> &b)
  {
    return a.second < b.second;
  }
}

