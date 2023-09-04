def fourSum(nums: list[int], target: int) -> list[list[int]]:
   nums.sort();
   ans = []
   n = len(nums) 

   for i in range(n-3):
      if i > 0 and nums[i] == nums[i-1]: 
         continue;
      for j in range(i+1, n-2):
         if j > i+1 and nums[j] == nums[j-1]:
            continue;

         twoSum = target-(nums[i]+nums[j])
         k = j+1;
         l = n-1
         while k<l:
            if nums[k]+nums[l] ==twoSum:
               ls = [nums[i], nums[j], nums[k], nums[l]]
               ans.append(ls) 
               while k<l and nums[k] == nums[k+1]:
                  k+=1
               while k<l and nums[l] == nums[l-1]:
                  l-=1
               k+=1   
               l-=1

            elif nums[k]+nums[l] > twoSum:  
               l-=1
            else:
               k+=1 



   return ans
   

nums = [1,0,-1,0,-2,2]
target = 0

print(fourSum(nums, target))
   

# print(count)