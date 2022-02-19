def printIncreasing(n: int) -> None:
    if n == 0: return
    printIncreasing(n - 1)
    print(n, end=' ')
         
printIncreasing(int(input('Enter a number: ')))
print()