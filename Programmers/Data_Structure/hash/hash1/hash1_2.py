import collections 

def solution(participant, completion): 
    answer= list((collections.Counter(participant)-collections.Counter(completion)).keys()) 
    return answer[0]

