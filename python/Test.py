# Some allowed libraries
# import threading, multiprocessing, concurrent.futures, asyncio
# import joblib, math, string, re, collections, queue

# Your code here
def pisano_period(M):
    prev, curr = 0, 1
    for i in range(0, M * M):
        prev, curr = curr, (prev + curr) % M
        if (prev == 0 and curr == 1):
            return i + 1

def fibonacci_mod(n, M, memo, pisano_len):
    if n in memo:
        return memo[n]

    n_mod_pisano = n % pisano_len

    if n_mod_pisano == 0:
        return 0
    elif n_mod_pisano == 1:
        return 1

    fib_prev, fib_curr = 0, 1
    for _ in range(2, n_mod_pisano + 1):
        fib_prev, fib_curr = fib_curr, (fib_prev + fib_curr) % M

    memo[n] = fib_curr
    return fib_curr

def MAIN(filename="input.txt"):
    # Your code here
    with open(filename, "r") as file:
        lines = file.readlines()
    
    N, M = map(int, lines[0].split())
    queries = [int(lines[i]) for i in range(1, N + 1)]
    
    pisano_len = pisano_period(M)
    memo = {}
    results = [fibonacci_mod(q, M, memo, pisano_len) for q in queries]
    
    your_output = results
    return your_output
