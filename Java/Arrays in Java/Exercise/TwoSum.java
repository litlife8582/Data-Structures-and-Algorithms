import java.util.*;
public class TwoSum {
    int arr[]=null;
    int farr[]=null;
    public int[] AcceptElements(int num){
        Scanner sc=new Scanner(System.in);
        arr=new int[num];
        for(int i=0;i<num;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public int[] twoSum(int arr[],int Target){
        int sum=0;
        farr=new int[2];
        for(int i=0;i<arr.length;i++){
            for(int j=i;j<arr.length;j++){
                sum=arr[i]+arr[j];
                if(arr[i]==arr[j]){
                    continue;
                }
                if(sum==Target){
                    farr[0]=i;
                    farr[1]=j;
                    break;
                }
            }
        }
    return farr;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        TwoSum ts=new TwoSum();
        int num=sc.nextInt();
        int Target=sc.nextInt();
        int arr[]=ts.AcceptElements(num);
        int farr[]=ts.twoSum(arr,Target);
        System.out.println(Arrays.toString(farr));
        sc.close();
        }
}
