import java.util.*;
public class EqualArray {
    int arr[]=null;
    public int[] AcceptArrays(int n){
        Scanner sc=new Scanner(System.in);
        arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
     public void CheckEquality(int arr1[],int arr2[]){
        if(arr1.length!=arr2.length){
            System.out.println(" Arrays are not equal");
            return;
        } 
        for(int i=0;i<arr1.length;i++){
            if(arr1[i]!=arr2[i]){
                System.out.println("Arrays are not equal");
                return;
            }
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        EqualArray eq=new EqualArray();
        System.out.println("Enter the number of terms in the First Array: ");
        int n1=sc.nextInt();
        int arr1[]=eq.AcceptArrays(n1);
        System.out.println("Enter the number of terms in the Second Array: ");
        int n2=sc.nextInt();
        int arr2[]=eq.AcceptArrays(n2);
        eq.CheckEquality(arr1, arr2);
        sc.close();
    }
}

