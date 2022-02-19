def power(base: int, exponent: int) -> int:
    return 1 if exponent == 0 else base * power(base, exponent - 1)
    
base, exponent = map(int, input("Enter the base and exponent: ").strip().split())
print(f"{base} raised to the power {exponent} gives", power(base, exponent))