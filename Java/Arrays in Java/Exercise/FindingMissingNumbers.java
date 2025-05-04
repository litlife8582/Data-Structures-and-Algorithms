import java.util.*;
public class FindingMissingNumbers{
    int arr[]=null;
    public int[] AcceptingNumber(int n){
        Scanner sc=new Scanner(System.in);
        arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
        
    }
    public int CheckNumber(int Array[]){
        int num=0;
        for(int i=0;i<Array.length;i++){
            if(arr[i]==(i+1)){
                continue;
            }
            else{
                num=i+1;
                break;
            }
        }
        return num;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        FindingMissingNumbers f=new FindingMissingNumbers();
        System.out.println("Enter the range to be taken: ");
        int n=sc.nextInt();
        int array[]=new int[n];
        array=f.AcceptingNumber(n);
        int num=f.CheckNumber(array);
        System.out.println("Missing number is "+num);
        sc.close();
    }

}