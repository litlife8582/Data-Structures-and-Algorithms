import java.util.*;
public class KthSmallestElement{
    public int Smallest(int arr[],int k){
        int num=0;
       Arrays.sort(arr);
       for(int i=0;i<=arr.length;i++){
        num=arr[k];
       }
       return num;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        AcceptNumbers an=new AcceptNumbers();
        KthSmallestElement ks=new KthSmallestElement();
        int num=sc.nextInt();
        int arr[]=an.Accept(num);
        System.out.println("Enter the kth number: ");
        int k=sc.nextInt();
        Arrays.sort(arr);
        int n=ks.Smallest(arr,k);
        System.out.println(n);
        sc.close();
        }
}