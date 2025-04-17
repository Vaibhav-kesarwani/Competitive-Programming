import java.util.*;
import java.io.*;

public class Main {
    static Map<String, Integer> cache = new HashMap<>();

    private static int calcSum(int[] nums) {
        int sum = 0;
        int i = 0;
        while (i < nums.length) {
            sum += nums[i];
            i++;
        }
        return sum;
    }

    private static int[] calcDiff(int[] nums) {
        int[] diff = new int[nums.length - 1];
        int i = 0;
        while (i < diff.length) {
            diff[i] = nums[i + 1] - nums[i];
            i++;
        }
        return diff;
    }

    private static int findMax(int[] nums) {
        int sum = calcSum(nums);
        if (nums.length == 1) {
            return sum;
        }
        String key = Arrays.toString(nums);
        if (cache.containsKey(key)) {
            return cache.get(key);
        }

        int[] diff = calcDiff(nums);
        int opt1 = findMax(diff);

        int[] rev = reverseArray(nums);
        int[] revDiff = calcDiff(rev);
        int opt2 = findMax(revDiff);

        int bestOpt = Math.max(opt1, opt2);
        int res = Math.max(sum, bestOpt);
        cache.put(key, res);
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        int i = 0;
        while (i < t) {
            int n = Integer.parseInt(reader.readLine());
            int[] arr = Arrays.stream(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int res = findMax(arr);
            System.out.println(res);
            i++;
        }
    }
}
