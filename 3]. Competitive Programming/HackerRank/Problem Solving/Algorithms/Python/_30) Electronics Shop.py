
# Contributed by Paraj Shah
# https://github.com/parajshah

def getMoneySpent(keyboards, drives, b):
    # b -> budget
    s = 0
    for keyboard in keyboards:
        for drive in drives:
            if keyboard + drive <= b and s < (keyboard + drive):
                s = keyboard + drive
    if s == 0:
        return -1
    return s