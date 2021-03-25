def generate_hashtag(s):
    if(s=="" or len(s) >140):
        return False
    return "#" + "".join([x.capitalize() for x in s.split(" ")])
