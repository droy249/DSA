def printDecreasing(n: int) -> None:
    if n == 0: return
    print(n, end=' ')
    printDecreasing(n - 1)
         
printDecreasing(int(input('Enter a number: ')))
print()