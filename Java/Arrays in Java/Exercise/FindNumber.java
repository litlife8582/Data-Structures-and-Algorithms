import java.util.*;
public class FindNumber {
    int arr[]=null;
    public int[] AcceptElements(int num){
        Scanner sc=new Scanner(System.in);
        arr=new int[num];
        for(int i=0;i<num;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public int findNumber(int arr[],int num){
        int location=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==num){
                 location=i;
            }
        }
        return location;
    }
    public static void main(String[] args){
        FindNumber fn=new FindNumber();
        Scanner sc=new Scanner(System.in);
        int num=sc.nextInt();
        int n=sc.nextInt();
        int arr[]=new int[num];
        arr=fn.AcceptElements(num);
        int location=fn.findNumber(arr,n);
        System.out.println(location);
        sc.close();

    }
    
}
