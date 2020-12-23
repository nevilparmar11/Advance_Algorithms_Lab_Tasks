# -*- coding: utf-8 -*-
# @Author: nevil11
# @Date:   2020-10-25 17:57:51
# @Last Modified by:   nevil11
# @Last Modified time: 2020-10-25 18:24:19
def set_cover(lst, edge):
    U = lst.copy()
    all = []
    while len(U) != 0:
        s = findIntersaction(edge, U)
        edge.remove(s)
        U = [x for x in U if x not in s]
        all.append(s)
    return all

def findIntersaction(edge, u):
    index, max = 0, 0
    for i in range(len(edge)):
        temp = set(edge[i]).intersection(set(u))
        if len(temp) > max:
            max = len(temp)
            index = i
    return edge[index]

if __name__ == "__main__":
    lst = list(map(int, input().split()))
    n = int(input("Enter number of subsets\n"))
    edge = []
    for _ in range(n):
        temp = list(map(int, input().split()))
        edge.append(temp)
    
    result = set_cover(lst, edge)
    print(result)