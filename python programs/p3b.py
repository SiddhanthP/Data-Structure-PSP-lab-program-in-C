str1=input("enter string 1")
str2=input("enter string 2")
if(len(str1)<len(str2)):
    print("string 1 is Shorter than another one")
    short=len(str1)
    long=len(str2)
else:
    print("string 2 is Shorter than another one")
    short=len(str2)
    long=len(str1)

cnt=0
for i in range (short):
    if str1[i]==str2[i]:
            cnt+=1
print("similarity between 2 said strings:")
print((cnt/long)*100,"%")