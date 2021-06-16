
# Contributed by Paraj Shah
# https://github.com/parajshah

def pageCount(n, p):
    # p -> page to be turned to
    # n -> number of pages in book
    if(p<=n):
        return min(p//2, n//2 - p//2) 