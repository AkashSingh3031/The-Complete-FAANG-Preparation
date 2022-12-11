
# Contributed by Paraj Shah
# https://github.com/parajshah

rocks = [set(input()) for _ in range(int(input()))]
gems = set.intersection(*rocks)
print(len(gems))