
# Contributed by Paraj Shah
# https://github.com/parajshah

def caesarCipher(s, k):
    k %= 26
    newString = ''
        
    for i in s:
        asciiValue = ord(i)
        # Uppercase alphabets
        if asciiValue >= 97 and asciiValue <= 122:
            if asciiValue + k > 122:
                newString += chr(96 + asciiValue - 122 + k)
            else:
                newString += chr(asciiValue + k)
        # Lowercase alphabets
        elif asciiValue >= 65 and asciiValue <= 90:
            if asciiValue + k > 90:
                newString += chr(64 + asciiValue - 90 + k)
            else:
                newString += chr(asciiValue + k)
        else:
            newString += i        
                
    return newString