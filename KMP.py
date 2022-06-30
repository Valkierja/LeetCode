
def buildNextArr(subString:str) -> list:
    next = list(0)
    maxPrefixLenth = 0
    i = 1
    while i < len(subString):
        if subString[i] == subString[maxPrefixLenth]:
            
            maxPrefixLenth += 1
            next.append(maxPrefixLenth)
            i+=1
        else :
            if maxPrefixLenth == 0:
                next.append(0)
                i+=1
            else:
                maxPrefixLenth = next[maxPrefixLenth-1]
                
    return next
                
                
            