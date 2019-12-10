#!/usr/bin/env python3
"""Modul o prvočíslach
"""

def primes(until,fromm=2):

    """Vráti zoznam prvočísel
until - pokiaľ
fromm - odkiaľ"""

    p=[]
    for n in range(fromm,until):
        # Tuna by stacilo po sqrt(n)
        for d in range(2,n//2+1):
            if (n % d)==0:
                break
        else:
            p.append(n)
    return p

cislo = 5617

#print(primes(100))
#print(primes(100,50))
#print(primes(100,fromm=50))




