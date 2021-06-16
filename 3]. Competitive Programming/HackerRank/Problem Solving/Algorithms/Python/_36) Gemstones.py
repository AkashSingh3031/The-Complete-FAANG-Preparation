
# Contributed by Paraj Shah
# https://github.com/parajshah

# Replace whole program (Not just the function)
rocks = [set(input()) for _ in range(int(input()))]
gems = set.intersection(*rocks)
print(len(gems))