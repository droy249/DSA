# Program for the CLASSIC "Tower of Hanoi" question in python

# GFG solution
def TowerOfHanoi(n: int, from_rod: str, to_rod: str, aux_rod: str) -> None:
    if n == 1:
        print("Move disk 1 from rod", from_rod, "to rod", to_rod)
        return
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod)
    print("Move disk", n, "from rod", from_rod, "to rod", to_rod)
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod)
     
# GFG Function Call
TowerOfHanoi(int(input('Enter number of discs: ')), 'A', 'C', 'B') 