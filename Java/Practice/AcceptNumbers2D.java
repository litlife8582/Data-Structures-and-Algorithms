import java.util.Scanner;

public class AcceptNumbers2D {
    public int[][] Accept(int row,int col){
        int[][] arr=new int[row][col];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                arr[row][col]=sc.nextInt();
            }
        }
        return arr;
    }
}
