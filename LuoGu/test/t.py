def max_product(n):
    if n <= 3:
        return n
    factors = []
    for i in range(2, n):
        if n - i <= i:
            factors.append(n)
            break
        else:
            factors.append(i)
            n -= i
    product = 1
    for factor in factors:
        product *= factor
    return product

n = int(input("请输入一个正整数 n："))
print("最大乘积为：", max_product(n))
