def binaryPower(base: int, exponent: int) -> int:
    if exponent == 0: 
        return 1
    elif exponent & 1 == 0:
        return binaryPower(base, exponent >> 1) * binaryPower(base, exponent >> 1)
    else:
        return binaryPower(base, exponent >> 1) * binaryPower(base, exponent >> 1) * base
    # return 1 if exponent == 0 else base * power(base, exponent - 1)
    
base, exponent = map(int, input("Enter the base and exponent: ").strip().split())
print(f"{base} raised to the power {exponent} gives", binaryPower(base, exponent))