function multiply(a, b)
{
  if(a[0] == '0')
    a = removeLeadingZeros(a);
  if(b[0] == '0')
    b = removeLeadingZeros(b);
  
  var res = "0";
  var aLen = a.length;
  var bLen = b.length;
  
  for(var i=aLen-1; i>=0; --i)
    for(var k=bLen-1; k>=0; --k)
      res = addStrings(res, multiplyStrings(a[i],b[k], (aLen-i)+(bLen-k)-2));  
   
  return res;
}

function removeLeadingZeros(str)
{
  var noZeros = "";
  var index = 0;
  while(index != str.length && str[index] == 0)
    index ++;
  
  for(var i=index; i<str.length; ++i)
    noZeros += str[i];
  
  if(noZeros == "")
    return "0";
  
  return noZeros;
}

function multiplyStrings(char1, char2, numTrailingZeros)
{
  var product = (char1 - '0') * (char2-'0');
  if(product == 0)
    return "0";
  var ret = product + "";
  for(var i=0; i<numTrailingZeros; ++i)
    ret += "0";
  return ret;
}

function addStrings(x, y)
{
  if(x.length < y.length)
  {
    var temp = y;
    y=x;
    x = temp;
  }
  
  var maxLength = x.length;
  y = "0".repeat(maxLength-y.length) + y;
  var result = "";
  var carry = 0;
  var stopCondition = maxLength - y.length;
  
  for(var i=maxLength -1; i>= stopCondition; --i)
  {
    var sum = (x[i]-'0') + (y[i]-'0') + carry;
    console.log(sum);
    if(sum>=10)
    {
       carry = 1;
       sum -= 10;
    }
    else carry =0;
    result = sum.toString()  + result;
  }
  
  if(carry !=0)
  {  
      result =carry.toString() + result;
  }
  
  return result == "" ? "0" : result;
}
