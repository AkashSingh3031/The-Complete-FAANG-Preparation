if __name__ == '__main__':
    n = int(input().strip())

    print("Weird" if n % 2 or 6 <= n <= 20 else "Not Weird")
