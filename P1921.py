#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from operator import mul
from functools import reduce

readline = sys.stdin.readline


def main():
    inp = readline()
    (n, m, q) = (int(i) for i in inp.split())
    inp = readline()
    pi = [float(i) for i in inp.split()]
    a = []
    for _ in range(n):
        inp = readline()
        a.append([float(i) for i in inp.split()])
    b = []
    for _ in range(n):
        inp = readline()
        b.append([float(i) for i in inp.split()])
    inp = readline()
    o = [int(i) for i in inp.split()]

    d = [pi]
    for _ in range(1, m):
        d.append([sum(d[-1][k]*b[k][j] for k in range(n)) for j in range(n)])

    p = reduce(mul, (sum(d[i][j] * a[j][o[i]] for j in range(n)) for i in range(m)), 1)

    print('{0:.4f}'.format(p))


if __name__ == '__main__':
    main()
