#!/usr/bin/env python3

x=1

def f(y):
   
    global x

    print(x)
    x=2

f(10)
print(x)
