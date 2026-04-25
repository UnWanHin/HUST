import os


a=int(input())
b=int(input())
a1=a
b1=b
while(b!=0):
    c=b
    b=a%b
    a=c

print(a)
print(a1*b1/a)
    

os.system("pause")