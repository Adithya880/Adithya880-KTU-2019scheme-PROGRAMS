import java.util.*;

public class Dupli 
{
    public static int removeDuplicates(int[]
 nums) 
 {
        if (nums.length == 0) 
        {
            return 0;  

        }

        Set<Integer> uniqueNums = new HashSet<>();
        int i = 0;
        for (int num : nums) 
        {
            if (uniqueNums.add(num)) 
            {
                nums[i++] = num;
            }
        }
        return i;
  }

    public static void main(String[] args) 
    {
        int[] nums = {1, 1, 2};
        int length = removeDuplicates(nums);

        System.out.println("Array after removing duplicates:");
        for (int i = 0; i < length; i++) 
        {
            System.out.print(nums[i]+ " ");
        }
    }
}