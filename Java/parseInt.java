import java.util.*;

public class Parser {
    
    public static ArrayList<String> units = new ArrayList<String>(Arrays.asList("zero", "one", "two", "three","four", "five", "six", "seven",
                                     "eight","nine"));
  
    public static ArrayList<String> teens = new ArrayList<String>(Arrays.asList("ten","eleven", "twelve","thirteen","fourteen","fifteen",
                                    "sixteen","seventeen","eighteen","nineteen"));
  
    public static ArrayList<String> tens = new ArrayList<String>(Arrays.asList("blank","ten","twenty","thirty","forty","fifty","sixty",
                                   "seventy","eighty","ninety","twenty")); 
  
    public static int parseInt(String numStr) {
        
      String [] tokens = numStr.replaceAll("and"," ").replaceAll("-"," ").split(" ");
      Stack<Integer> stack = new Stack<Integer>();
      int ans = 0;
      
      for(int i=0;i<tokens.length; ++i)
      {
          int temp = Parser.getNumberValue(tokens[i]);
          if(temp != -1)
          {
            if(!stack.empty())
            {
              stack.push(stack.pop() + temp);
            }
            else stack.push(temp);
           
          }
          else
          {
            switch (tokens[i])
            {
               case "hundred": stack.push(stack.pop() * 100);
                break;
               case "thous": ans += stack.pop() * 1000;
                break;
               case "million": ans += stack.pop() * 1000000;
                break;
            }
          }
      }
      
      while(!stack.empty())
        ans += stack.pop();
      
      return ans;
    }
  
    private static int getNumberValue(String str)
    {
      if(units.indexOf(str) != -1)
        return units.indexOf(str);
      else if(teens.indexOf(str) != -1)
        return teens.indexOf(str) + 10;
      else if(tens.indexOf(str) != -1)
        return tens.indexOf(str) * 10;
      else return -1;
    }
  
}
