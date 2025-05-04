import java.util.*;
public class SumOfPairs{
    int pair[][]=null;
    public void CheckPair(int arr[],int target){
        this.pair=new int[arr.length][2];
        for(int i=0;i<arr.length;i++){
            for(int j=i;j<arr.length;j++){
                if(arr[i]+arr[j]==target){
                    System.out.println(arr[i]+","+arr[j]);
                }
            }
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        SumOfPairs sop=new SumOfPairs();
        AcceptNumbers ac=new AcceptNumbers();
        int num=sc.nextInt();
        int[] arr=ac.Accept(num);
        int target=sc.nextInt();
        sop.CheckPair(arr, target);
        sc.close();
    }
}