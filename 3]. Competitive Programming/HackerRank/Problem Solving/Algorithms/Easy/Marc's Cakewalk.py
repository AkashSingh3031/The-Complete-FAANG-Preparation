
# Contributed by Paraj Shah
# https://github.com/parajshah

def marcsCakewalk(calorie):
    calorie.sort(reverse=True)
    answer = 0
    for i in range(len(calorie)):
        answer += 2**i * calorie[i]
    return answer