#include <iostream>
#include <string>
#include <chrono> 
using namespace std;

/*
    NOTE:
     While this solution is correct, it is not fast/efficient enough to complete the challenge.
*/

string removeLeadingZeros(string);
string multiplyStrings(char,char,int);
string addStrings(string, string);

string multiply(string a, string b) {
  
  //cout<<"---Multiplying numbers "<<a<<" and "<<b<<" ---"<<endl<<endl;
  //auto start = chrono::high_resolution_clock::now();
  if(a[0] == '0')
    a = removeLeadingZeros(a);
  if(b[0] == '0')
    b = removeLeadingZeros(b);
  string res = "0";
  int aLen = a.length(); 
  int bLen = b.length();
  
  for(int i=aLen-1; i>=0; --i)
  {
     for(int k=bLen-1; k >=0; --k)
     {
       res = addStrings(res, multiplyStrings(a[i], b[k], (aLen-i)+(bLen-k)-2));
     }

  }
  //auto stop = chrono::high_resolution_clock::now(); 
  //cout<<chrono::duration_cast<chrono::microseconds>(stop - start).count()<<"ms"<<endl;
  
  return removeLeadingZeros(res);
}

string addStrings(string x, string y)
{  
  if(x.length() < y.length())
   {
     string temp = y;
     y = x;
     x = temp;
   }
   int maxLength = x.length();
   y = string(maxLength-y.length(), '0') + y; //pad y with leading zeros

   string result = "";
   int carry = 0;
   int stopCondition = maxLength - y.length();
  
   for(int i=maxLength-1;i>=stopCondition; --i)
   {
     int sum = (x[i] - '0') + (y[i] - '0') + carry;
     if(sum >= 10)
     {
       carry = 1;
       sum -= 10;
     }
     else
     {
        carry =0;  
     }
     result = to_string(sum) + result;
   }
   
   if(carry !=0)
     result = to_string(carry) + result;
  
   return result =="" ? "0" : result;
}

string multiplyStrings(char a2,char b2, int numTrailingZeros)
{
    int product = (a2 - '0') * (b2 -'0');
    string ret = to_string(product);
    for(int i=0;i<numTrailingZeros; ++i)
      ret += "0";
    return ret;  
}

string removeLeadingZeros(string x)
{  
    string no_zeros = "";
    int index = 0;
    while(index != x.length() && x.compare(index,1,"0") == 0)
      index ++;
  
  for(int i=index;i < x.length(); ++i)
    no_zeros += x[i];
  
      if(no_zeros == "")
        return "0";
    else return no_zeros;
}
