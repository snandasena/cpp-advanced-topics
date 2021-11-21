
def func(arr):
    arr.sort()
    n = len(arr)
    dup =0
    total = (1 + n) * n // 2
    total -=arr[0]
    for i in range(1, n):
        if arr[i] == arr[i-1]:
            dup = arr[i]

        total -=arr[i]
    return [dup, total+dup]


# arr =[1,2,3,4,3]
arr = [3, 2, 3, 4, 5, 6, 7, 8]
print(func(arr))
