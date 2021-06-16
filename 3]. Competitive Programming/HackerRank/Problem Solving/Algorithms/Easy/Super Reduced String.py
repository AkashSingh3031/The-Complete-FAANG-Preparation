
# Contributed by Paraj Shah
# https://github.com/parajshah

def superReducedString(s):
    stringList = list(s)
    i = 0
    while i < len(stringList) - 1:
        if stringList[i] == stringList[i + 1]:
            del stringList[i]
            del stringList[i]
            # Reset i
            i = 0
            if len(stringList) == 0:
                return('Empty String')
        else:
            i += 1
    return "".join(stringList)