class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        inputs:
        - nums: an array of integers in the range [1, n]
        - all numbers in the array (but one) are unique

        output:
        - integer: the duplicate value in the array

        notes:
        - we want to find the cycle entrance (duplicate number)
        - let A be the distance from the start of the list to the cycle entrance
        - let B be the distance from the cycle entrance to the meeting point
        - the two pointers will meet at point B in the cycle
        - the slow pointer will have traveled A + B total distance, and the fast pointer will have traveled twice that so 2(A + B)
            let D be the length of the cycle
            let C = D - B (the remaining distance from the meeting point to the cycle entrance)
            let k be the number of times the fast pointer finished a cycle
            2(A + B) - kD = A + B
            A + B - kD = 0
            A = kD - B
            A = k(C + B) - B
            A = kC + kB - B
            A = jD + C

            The distance from the start of the linked list to the meeting point (A) is equal to 
            a multiple of D (cycle length) + C (distance from meeting point to entrance)
            Thus, setting a pointer to the start of the linked list, and moving both pointers at equal speed until they meet 
            will yield the cycle entrance

            The cycle entrance is the duplicate number.
            This is because a cycle entrance must have two incoming edges 
            (one entering from the list outside the cycle, and one entering from inside the cycle).
        """

        slow_ptr = nums[0]
        fast_ptr = nums[nums[0]]
        while slow_ptr != fast_ptr:
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[nums[fast_ptr]]
        
        slow_ptr = 0
        while slow_ptr != fast_ptr:
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[fast_ptr]
        
        return slow_ptr