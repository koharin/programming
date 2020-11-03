import java.util.*;
class Solution{
	public int[] twoSum(int[] nums, int targets) {
		int[] answer = new int[2];
		int i=0;
		
		for(int j=0; j<nums.length-1; j++) {
			for(int k=j+1; k<nums.length; k++) {
				if(Integer.sum(nums[j], nums[k]) == targets) {
					answer[i++] = j;
					answer[i] = k;
				}
			}
		}
		
		return answer;
	}
}
public class Problem_1 {
	public static void main(String[] args) {
		Solution s = new Solution();
		int[] nums = {-3, 4, 3, 90};
		int[] ans = new int[2];
		ans = s.twoSum(nums, 0);
		System.out.println(Arrays.toString(ans));
	}
	
}
