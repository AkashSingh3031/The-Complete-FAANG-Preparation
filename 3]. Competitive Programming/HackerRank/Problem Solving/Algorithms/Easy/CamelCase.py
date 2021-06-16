
# Contributed by Paraj Shah
# https://github.com/parajshah

def camelcase(s):
    count = 0
    for i in s:
        if i.isupper():
            count += 1
    return count + 1