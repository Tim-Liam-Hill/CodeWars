import string

def is_pangram(s):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    s= "".join(s.split(" ")).lower()
    print(s)
    for str in alphabet:
        if(str not in s):
            return False
    return True
