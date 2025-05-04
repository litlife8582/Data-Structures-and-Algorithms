import java.util.Scanner;

public class AcceptNumbers {
    public int[] Accept(int num){
        Scanner sc=new Scanner(System.in);
        int[] arr=new int[num];
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
}
