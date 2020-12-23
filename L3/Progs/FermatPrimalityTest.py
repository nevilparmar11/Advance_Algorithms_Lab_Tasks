# -*- coding: utf-8 -*-
# @Author: nevil
# @Date:   2020-08-03 23:02:22
# @Last Modified by:   nevil
# @Last Modified time: 2020-08-03 23:03:57

#Primality testing program with Fermat's theorem.

import random

def GCD(x, y): #gcd calculator
   while(y): 
       x, y = y, x % y 
   return x 

def getNumber():
    return int(input("Enter an integer for Fermat's primality test: "))

def isPrime(n):
    #testing for the most simple cases like: odd numbers
    if n <= 3:
        return True
    elif n % 2 == 0:
        return False


    #testing for 7 times, should be enought to find any pseudo prime numbers
    for i in range(7):
        a = random.randint(2, n-1)
        print(f"Testing for a = {a}")

        if GCD(a,n) == 1:
            if (a ** (n-1)) % n == 1: continue
            else: return False
        else: return False
    return True


while True:
    if isPrime(getNumber()):
        print("This number is possibly prime\n")
    else:
        print("This number is not prime\n")
