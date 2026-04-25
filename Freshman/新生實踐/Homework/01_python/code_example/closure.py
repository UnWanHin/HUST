# closure.py
def Fun_sub(a):
    print(a)
    def Fun_sub2(b):
        print(b)
        return a-b
    return Fun_sub2
i = float(input('请输入减数：'))
j = float(input('请输入被减数：'))
a = [1, 2, 3, 4, Fun_sub(i)(j)] # i,j分别传给Fun_sub与Fun_sub2. Fun_sub2能看到传给Fun_sub的a, 但Fun_sub不能看到传给Fun_sub2的b
print("a=", a)
print("the maxium in a is", max(a))
# Fun_sub2(23)