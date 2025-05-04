import java.util.*;
public class MissingNumber{
    public int Missing(int[] arr){
        int m=0;
        for(int i=arr[0],j=0;j<=arr.length;i++,j++){
            if(i!=arr[j]){
                m=i;
                break;
            }
        }
        return m;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        MissingNumber mn=new MissingNumber();
        AcceptNumbers an=new AcceptNumbers();
        int num=sc.nextInt();
        System.out.println("Enter the numbers in the given range: ");
        int arr[]=an.Accept(num);
        int m=mn.Missing(arr);
        System.out.println(m);
        sc.close();
    }
}
