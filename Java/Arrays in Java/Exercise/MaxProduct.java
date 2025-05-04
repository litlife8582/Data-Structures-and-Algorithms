import java.util.*;
public class MaxProduct{
    int arr[]=null;
    public int[] AcceptElements(int num){
        Scanner sc=new Scanner(System.in);
        arr=new int[num];
        for(int i=0;i<num;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public String CheckValues(int[] arr) {
        int Array[]=new int[2];
        int maxvalue=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            for(int j=(i+1);j<arr.length;j++){
                if((arr[i]*arr[j])>maxvalue){
                    Array[0]=arr[i];
                    Array[1]=arr[j];
                }
            }
        }
        String Arr=Arrays.toString(Array);
        return Arr;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        MaxProduct mp=new MaxProduct();
        int num=sc.nextInt();
        int array[]=mp.AcceptElements(num);
        String maxvalue=mp.CheckValues(array);
        System.out.println(maxvalue);
        sc.close();
    }
}
