#!/usr/bin/env python3

class Obdlznik:

    def __init__(self,a,b):
        self.a=a
        self.b=b

    def __str__(self):
        
        return "Obdlznik(a={},b={})".format(self.a,self.b)

    def plocha(self):
        
        return self.a*self.b
