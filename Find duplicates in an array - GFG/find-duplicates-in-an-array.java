//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = g.duplicates(a, n);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    public static ArrayList<Integer> duplicates(int a[], int n) {
        ArrayList<Integer> arr=new ArrayList<>();
        TreeMap<Integer,Integer> tm= new TreeMap<>();
        
        for(int i:a){
            tm.put(i,tm.getOrDefault(i,0)+1);
        }
        
        for(Map.Entry<Integer,Integer> me:tm.entrySet()){
            if(me.getValue()>1) arr.add(me.getKey());
        }
        
        if(arr.size()==0) arr.add(-1);
        
        return arr;
    }
}
