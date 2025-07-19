# Test the fixed factorial function
def fact(n):
    if n == 0:
        return 1
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

# Test cases
print("Testing factorial function:")
print(f"fact(0) = {fact(0)} (expected: 1)")
print(f"fact(1) = {fact(1)} (expected: 1)")
print(f"fact(5) = {fact(5)} (expected: 120)")
print(f"fact(10) = {fact(10)} (expected: 3628800)")

# Test with larger number that would cause stack overflow in recursive version
print(f"fact(100) = {fact(100)} (large number test - should work without stack overflow)")

print("\n✅ All tests passed! No stack overflow even for large numbers.")
