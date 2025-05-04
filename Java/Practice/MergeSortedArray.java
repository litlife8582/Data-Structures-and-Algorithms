import java.util.*;
public class MergeSortedArray{
    public int[] Merged(int arr1[],int arr2[]){
        int[] arr=new int[arr1.length+arr2.length];
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        for(int i=0;i<arr1.length;i++){
            arr[i]=arr1[i];
        }
        for(int i=arr1.length,j=0;i<arr.length && j<arr2.length;i++,j++){
            arr[i]=arr2[j];
        }
        return arr;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        MergeSortedArray msa=new MergeSortedArray();
        AcceptNumbers ac=new AcceptNumbers();
        int num1=sc.nextInt();
        int num2=sc.nextInt();
        int[] arr1=ac.Accept(num1); 
        int[] arr2=ac.Accept(num2);
        int[] farr=msa.Merged(arr1,arr2);
        System.out.println(Arrays.toString(farr));
        sc.close();
    }
}
