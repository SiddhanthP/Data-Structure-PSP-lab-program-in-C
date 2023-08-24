m1=int(input("enter marks of test 1\n"))
m2=int(input("enter marks of test 2\n"))
m3=int(input("enter marks of test 3\n"))

minimum=min(m1,m2,m3)
sum= (m1+m2+m3)-minimum
avg=sum/2
print("average marks of all three test is:",avg)
