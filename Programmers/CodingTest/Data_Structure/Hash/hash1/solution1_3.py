def solution(participant, completion):
    part={}; result=0
    for i in participant: part[hash(i)] = i
    for i in participant: result += hash(i)
    for j in completion: result -= hash(j)
    return part.get(result)
