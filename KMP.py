
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
def KMP(string:str,subString:str) -> int:
    next = buildNextArr(subString)
    i, j = 0, 0
    while i < len(string):
        if j == len(subString):
            return i - j
        elif string[i] == subString[j]:
            i += 1
            j += 1
            continue
        elif j > 0: 
            j = next[j-1]
            continue
        elif j == 0: # 如果第一个匹配就不通过
            i += 1  # 主指针向前
            continue
        
            
        
            
    