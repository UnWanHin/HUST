import time 
for i in range(1900,2001):
    if(i%4==0 and i%100!=0 or i%400==0):
        print(i)
time.sleep(1000)