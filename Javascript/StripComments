function solution(input, markers) {
  
  var low_index = 0;
  var high_index = 0;
  var ans = "";
  var tokens = input.split("\n");
  
  for(var i=0;i<tokens.length; ++i)
  {
      for(var k=0; k<markers.length; ++k)
      {
        if(tokens[i].indexOf(markers[k]) != -1) 
        {
            tokens[i] = tokens[i].substr(0,tokens[i].indexOf(markers[k]));
        }
      }
    tokens[i] = removeTrailingWhitespaces(tokens[i]);
  }
 
  return tokens.join("\n");
};

function removeTrailingWhitespaces(str)
{
  while(str.charAt(str.length-1) == " ")
    str = str.substr(0,str.length-1);
  return str;
}
