class MyCount:
    def __init__(self, num=11):
        self.num = num

    def calSum(self):  # 方法需要self参数
        mysum = 0
        for i in range(0, self.num):
            mysum += i
        return mysum

count_1 = MyCount()
count_1.num = 101
print(count_1.calSum())

count_2 = MyCount()
print(count_2.calSum())