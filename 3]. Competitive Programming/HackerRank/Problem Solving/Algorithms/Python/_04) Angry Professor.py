
# Contributed by Paraj Shah
# https://github.com/parajshah

def angryProfessor(k, a):
    count = 0
    for i in a:
        if i <= 0:
            count += 1
    if count < k:
        return "YES"
    return "NO"