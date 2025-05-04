import java.util.*;
public class Permutation {
    int arr[]=null;
    public int[] AcceptElements(int num){
        Scanner sc=new Scanner(System.in);
        arr=new int[num];
        for(int i=0;i<num;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public void Check(int[] arr1,int[] arr2){
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        for (int i = 0; i < arr1.length; i++){
            if(arr1==arr2){
                System.out.println("Permutation");
            }
            else{
                System.out.println("Not permutation");
            }
        }
       
    } 
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Permutation p=new Permutation();
        int num=sc.nextInt();
        int[] arr1=p.AcceptElements(num);
        int[] arr2=p.AcceptElements(num);
        p.Check(arr1, arr2);
        sc.close();
    }
}
