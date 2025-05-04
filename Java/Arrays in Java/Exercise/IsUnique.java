import java.util.*;
public class IsUnique {
    int arr[]=null;
    public int[] AcceptingNumber(int n){
        Scanner sc=new Scanner(System.in);
        arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();    
        }
        return arr;
        }
    public boolean Check(int arr[]){
        boolean flag=false;
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr.length;j++){
                if(arr[i]==arr[j]){
                    flag=true;
                    break;
                }
            }
        }
        return flag;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        IsUnique is=new IsUnique();
        int num=sc.nextInt();
        int arr[]=is.AcceptingNumber(num);
        boolean flag=is.Check(arr);
        if(flag==true){
            System.out.println("Not Unique");
        }
        else{
            System.out.println("Unique");
        }
        sc.close();
    }
}
