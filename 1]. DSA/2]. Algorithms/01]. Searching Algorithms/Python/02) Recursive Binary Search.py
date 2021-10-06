def recusive_binary_search(array, target):
    if len(array) == 0:
        return False
    else:
        midpoint = (len(array)) // 2

        if array[midpoint] == target:
            return True
        else:
            if array[midpoint] < target:
                return recusive_binary_search(array[midpoint + 1 :], target)
            elif array[midpoint] > target:
                return recusive_binary_search(array[:midpoint], target)


def verify(result, target):
    if result:
        print("Target", target, "found in list !")
    else:
        print("Target", target, "not in list !")


array = [x for x in range(1, 10)]
verify(recusive_binary_search(array, 15), 15)
verify(recusive_binary_search(array, 4), 4)
