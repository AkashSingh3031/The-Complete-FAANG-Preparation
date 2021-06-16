
# Contributed by Paraj Shah
# https://github.com/parajshah

def catAndMouse(x, y, z):
    catA = abs(x-z)
    catB = abs(y-z)
    if catA > catB:
        return "Cat B"
    elif catA < catB:
        return "Cat A"
    else:
        return "Mouse C"