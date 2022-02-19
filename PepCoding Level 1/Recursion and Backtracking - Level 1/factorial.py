def factorial(n: int) -> int:
    return 1 if n < 2 else n * factorial(n - 1)
    
print(factorial(int(input('Enter number: '))))