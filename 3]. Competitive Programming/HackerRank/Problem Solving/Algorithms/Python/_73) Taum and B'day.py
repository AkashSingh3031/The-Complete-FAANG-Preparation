
# Contributed by Paraj Shah
# https://github.com/parajshah

def taumBday(b, w, bc, wc, z):
    return b*min(bc, wc+z) + w*min(wc,bc+z)