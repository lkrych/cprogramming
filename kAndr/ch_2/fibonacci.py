#time for fibonacci of 41: 1m14.016s
def fibonacci(n):
    if n <= 1:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

# print(fibonacci(41))
storage = {1: 1, 0: 1}

#time for fibonacci_optimized of 41: 
def fibonacci_optimized(n):
    if n in storage:
        return storage[n]
    else:
        storage[n] = fibonacci_optimized(n-1) + fibonacci_optimized(n-2)
        return storage[n]
# print(fibonacci_optimized(41))

#time for fib_dynamic of 41: 0m0.034s
#time for fib_dynamic of 1000: 0m0.041s
def fib_dynamic(n):
    current = 1
    prev_val = 0
    i = 0
    while i < n:
        new_current = prev_val + current
        prev_val = current
        current = new_current
        i+=1
    return current
print(fib_dynamic(1000))