import os
for i in range(2,101):
    a=0
    for num in range(2,i):
        if(i%num==0):
            a=1
    if(a==0):
        print(i)       
    
    
os.system("pause")