def cons(a, b):
    def pair(f):
        return f(a, b)

    return pair


def car(pair):
    """Returns first element of the pair"""
    return pair(lambda x, y: x)


def cdr(pair):
    """Returns second element of the pair"""
    return pair(lambda x, y: y)


def main():
    assert car(cons(3,4)) == 3
    print(car(cons(3,4)))
    assert cdr(cons(3, 4)) == 4
    print(cdr(cons(3, 4)))


if __name__ == '__main__':
    main()
