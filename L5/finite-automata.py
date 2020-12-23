# -*- coding: utf-8 -*-
# @Author: nevil
# @Date:   2020-08-07 15:49:25
# @Last Modified by:   nevil
# @Last Modified time: 2020-08-07 15:49:40


# Python program for Finite Automata
# Pattern searching Algorithm

numChars = 256

def nextForm(PATTERN, M, state, x):

    if state < M and x == ord(PATTERN[state]):
        return state+1

    i=0

    for nosaj in range(state,0,-1):
        if ord(PATTERN[nosaj-1]) == x:
            while(i<nosaj-1):
                if PATTERN[i] != PATTERN[state-nosaj+1+i]:
                    break
                i+=1
            if i == nosaj-1:
                return nosaj
    return 0

def MakeAutomata(PATTERN, M):

    global numChars

    TF = [[0 for i in range(numChars)]\
          for _ in range(M+1)]

    for state in range(M+1):
        for x in range(numChars):
            z = nextForm(PATTERN, M, state, x)
            TF[state][x] = z

    return TF

def search(PATTERN, TEXT):
    strout = ""
    global numChars
    M = len(PATTERN)
    N = len(TEXT)
    TF = MakeAutomata(PATTERN, M)

    state=0
    for i in range(N):
        state = TF[state][ord(TEXT[i])]
        if state == M:
            strout += str(i-M+1)
            strout += " "
    return strout

def main():
    with open("input.txt", "r") as ins:
        array = []
        for line in ins:
            array.append(line.strip('\n'))

    file = open("output.txt","w")
    TEXT = array[1]
    PATTERN = array[0]
    reverseTXT = TEXT[::-1]
    file.write(str(search(PATTERN, TEXT)))
    file.write(str(search(PATTERN, reverseTXT)))
    file.write('\n')

    ins.close()
    file.close()

if __name__ == '__main__':
    main()
