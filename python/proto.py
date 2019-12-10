
def proto(f):

    def f_ret(arg):
        
        print("Volana funkcia",f.__name__,"argument",arg)
        return f(arg)

    return f_ret
