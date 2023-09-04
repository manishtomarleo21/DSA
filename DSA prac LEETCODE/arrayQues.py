def maxScore(cardPoints: list[int], k: int) -> int:
    
    size = len(cardPoints)
    arr = [0]*size

    runSum = 0
    for i in range(size):
        runSum+=cardPoints[i]
        arr[i]=runSum

    score = 0
    ans = 0

    for i in range(k+1):
        j = i+size-k-1

        if i == 0:
            ans = arr[j]
        else:
            ans = arr[j]-arr[i-1]

        score = max(score, runSum-ans)  

    return score  



nums = [1,2,3,4,5,6,1]
target = 3

print(maxScore(nums, target))
   

# print(count)