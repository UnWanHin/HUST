import numpy as np

A = [[1, 3, 5], [2, 4, 6]]
B = [[22, 33], [11, 44], [101, 202]]

A_array = np.array(A)
B_array = np.array(B)

result = np.dot(A_array, B_array)

print(result)