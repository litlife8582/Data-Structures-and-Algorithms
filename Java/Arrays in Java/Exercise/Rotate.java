import java.util.*;
public class Rotate {
    int arr1[][]=null;
    public int[][] Accept(int row, int col){
        this.arr1=new int[row][col];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<arr1.length;i++){
            for(int j=0;j<arr1[0].length;j++)
            arr1[i][j]=sc.nextInt();
        }
        return arr1;
    }
        public int[][] RotateElements(int arr1[][]) {
            int rows = arr1.length;
            int cols = arr1[0].length;
            int arr2[][] = new int[cols][rows];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    arr2[j][rows - 1 - i] = arr1[i][j];
                }
            }
            return arr2;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Rotate r=new Rotate();
        int row=sc.nextInt();
        int col=sc.nextInt();
        int[][] arr1=r.Accept(row, col);
        int[][] arr2=r.RotateElements(arr1);
        System.out.println(Arrays.deepToString(arr1));
        System.out.println(Arrays.deepToString(arr2));
    }
}
