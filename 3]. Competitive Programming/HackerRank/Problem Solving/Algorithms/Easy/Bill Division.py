
# Contributed by Paraj Shah
# https://github.com/parajshah

def bonAppetit(bill, k, b):
    actualBill = 0
    chargedBill = b
    for i in range(len(bill)):
        if i == k:
            continue
        else:
            actualBill += bill[i]
    actualBill //= 2
    
    print("Bon Appetit" if actualBill == chargedBill else chargedBill - actualBill)
    return