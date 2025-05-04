import java.util.*;
public class RemoveDuplicate {
    int arr[]=null;
    int dup[]=null;
    public int[] AcceptElements(int num){
        Scanner sc=new Scanner(System.in);
        arr=new int[num];
        for(int i=0;i<num;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public int Duplication(int arr[]){
        int index=0;
        dup=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            boolean flag=false;
            for(int j=0;j<dup.length;j++){
                if(arr[i]==dup[j]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                dup[index++]=arr[i];
            }
        }
        return index;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        RemoveDuplicate dn=new RemoveDuplicate();
        System.out.println("Enter the number of terms in the array:");
        int num=sc.nextInt();
        int Array[]=new int[num];
        Array=dn.AcceptElements(num);
        int duplicate=dn.Duplication(Array);
        System.out.println(duplicate);
        sc.close();
    }
}
