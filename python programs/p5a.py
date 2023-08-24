import re
def isphonenumber(numStr):
    if len(numStr)!=12:
        return False
    for i in range(len(numStr)):
        if i==3 or i==7:
            if numStr[i]!='-':
                return True
            else:
                if numStr[i].isdigit()==
            