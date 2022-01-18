import math

def swapLetters(p, ind1, ind2):
    temp = p[ind1]
    p = p[:ind1] + p[ind2] + p[ind1 + 1:]
    p = p[:ind2] + temp + p[ind2+1:]
    
    return p

def removeLetterFromPred(pred, letter):
    ind = pred.index(letter)
    temp = pred[ind]
    pred = pred[:ind] + pred[0] + pred[ind+1:]
    pred = temp + pred[1:]

    return (''.join(sorted(pred[1:])))
    
    
def listLettersThatCanPrecede(pred, letter):
    l = list(dict.fromkeys(pred))
    return l[:l.index(letter)]


def combinationsOfRemainingLetters(pred , letter): #issue is here! need to sum individually when replacing letters  
                                                #as the letter in front effects which letters in body can be repeated
    ans = 0
    CONST_FACT = math.factorial(len(pred) - 1)
    precedeLetters = listLettersThatCanPrecede(pred, letter)
    for char in precedeLetters:
        
        pred = swapLetters(pred, 0, pred.index(char))
        temp = CONST_FACT
        duplicates = duplicatedLettersCount(pred[1:])
        for d in duplicates:
            temp = temp//math.factorial(d)
        ans += temp
 
    return ans

def duplicatedLettersCount(remaining):
    
    count = []
    while(len(remaining) != 0):
        count.append(remaining.count(remaining[0]))
        remaining = remaining.replace(remaining[0], '')
    
    return count

def listPosition(word):
    """Return the anagram list position of the word"""
    pred = ''.join(sorted(word))
    count = 0
    
    while(pred != word):
        if(pred[0] != word[0]):
            count += combinationsOfRemainingLetters(pred, word[0])
            pred = removeLetterFromPred(pred, word[0])   
        else: 
            pred = pred[1:]
        
        word = word[1:]
    
    return 1 + count
