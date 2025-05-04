import java.util.*;
public class Matrix_Multiplication {
    public int[][] Multiply(int arr1[][],int arr2[][]){
        int[][] arr=new int[arr1.length][arr1[0].length];
        int sop=0;
        try{
        for(int row=0;row<arr1.length;row++){
            for(int col=0;col<arr1[0].length;col++){
                int element1=arr1[row][col]; 
                int element2=arr2[col][row];
                sop+=element1*element2;
                arr[row][col]=sop;
            }
        }
    }catch(ArrayIndexOutOfBoundsException e){
        System.out.println("The given arrays cannot be multiplied");
    }
        return arr;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Matrix_Multiplication mm=new Matrix_Multiplication();
        AcceptNumbers2D ac2d=new AcceptNumbers2D();
        System.out.println("Enter the rows and colums of the two matrixes respectively");
        int row1=sc.nextInt();
        int col1=sc.nextInt();
        int row2=sc.nextInt();
        int col2=sc.nextInt();
        int arr1[][]=ac2d.Accept(row1, col1);
        int arr2[][]=ac2d.Accept(row2, col2);
        System.out.println(Arrays.deepToString(arr1));
        System.out.println(Arrays.deepToString(arr2));
        int arr[][]=mm.Multiply(arr1, arr2);
        System.out.println(Arrays.deepToString(arr));
        sc.close();
    }
}
