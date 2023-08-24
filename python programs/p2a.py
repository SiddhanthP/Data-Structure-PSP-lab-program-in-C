def fib_series(n):
    n1,n2=0,1
    if n==1:
        return 0
    else:
        print(n1)
        print(n2)
        for i in range (2,n) :
            n3=n1+n2
            n1=n2
            n2=n3
            print(n3)
fib=int(input("enter the number of element in series\n"))
fib_series(fib)
