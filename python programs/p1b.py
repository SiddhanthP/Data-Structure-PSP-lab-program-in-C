n=(input("enter the number to check if its palindrome\n"))

if(n[::1]==n[ : : -1]):
    print("is a Palindrom")
else :
    print("its not a palindrom")
b=str(n)
for i in range (10):
    if b.count(str(n))>0 :
        print("number of occurance",i,"in",b,b.count(str(i)))


