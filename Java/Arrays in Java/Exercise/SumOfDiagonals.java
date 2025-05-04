import java.util.*;
public class SumOfDiagonals {
    public static int sumDiagonalElements(int[][] array){
        int sum=0;
        for(int i=0;i<array.length;i++){
            sum+=array[i][i];
        }
        return sum;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int i=3;
        int j=3;
        int arr[][]=new int[i][j];
        for(int row=0;row<arr.length;row++){
            for(int col=0;col<arr[0].length;col++){
                arr[row][col]=sc.nextInt();
            }
        }
        int sum=sumDiagonalElements(arr);
        System.out.println(sum);
        sc.close();
    }
}
/*public class Exercise {
    public static int sumDiagonalElements(int[][] array) {
        int sum = 0;
        int numRows = array.length;
 
        for (int i = 0; i < numRows; i++) {
            sum += array[i][i];
        }
 
        return sum;
    }
} */