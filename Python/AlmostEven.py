import math

def split_integer(num, parts):
    #IDEA:
    #Divide num by parts
    #add 1 to each element until remainder = 0
    #Edge case: if parts > num, then num many 1's followed by parts - num 0's
    
    
    ans = [ math.floor(num/parts) for i in range(parts)]
    for i in range(num%parts):
        ans[len(ans)-1 - i] += 1
        
    if(parts > num):
        ans += [0 for i in range(parts-num)]
        
    return ans
