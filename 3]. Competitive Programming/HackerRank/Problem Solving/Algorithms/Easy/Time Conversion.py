
# Contributed by Paraj Shah
# https://github.com/parajshah

def timeConversion(s):
    # if hours != 12 and AM
    if s[-2:].upper() == "AM" and s[:2] != '12':
        time = s[:-2]
    # if hours == 12 and AM
    elif s[-2:].upper() == "AM" and s[:2] == '12':
        s = '00' + s[2:]
        time = s[:-2]
    # if hours != 12 and PM
    if s[-2:].upper() == "PM" and s[:2] != '12':
        time = int(s[0:2]) + 12
        time = str(time) + s[2:-2]
    # if hours == 12 and PM
    elif s[-2:].upper() == "PM" and s[:2] == '12':
        time = int(s[0:2])
        time = str(time) + s[2:-2]
    return time