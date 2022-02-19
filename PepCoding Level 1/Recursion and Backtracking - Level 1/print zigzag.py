# Important question for understanding recursion!!
# Refer video link: https://www.youtube.com/watch?v=R7qja_gZrvI&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=10


def zigzag(n: int) -> None:
    if n == 0: return
    print('Pre: ', n)
    zigzag(n - 1)
    print('In: ', n)
    zigzag(n - 1)
    print('Post: ', n)

zigzag(int(input('Enter a number: ')))