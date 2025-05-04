import java.util.*;
public class Second_Largest {
    public int[][] CheckElements(int arr[][]){
        int ele=Integer.MIN_VALUE;
        for(int row=0;row<arr.length;row++){
            for(int col=row;col<arr[0].length;col++){
                if(ele<arr[row][col]){
                    ele=arr[row][col];
                }
            }
        }
        return arr;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Second_Largest sl=new Second_Largest();
        AcceptNumbers2D ac2d=new AcceptNumbers2D();
        System.out.println("Enter the number of rows: ");
        int row=sc.nextInt();
        System.out.println("Enter the number of columns: ");
        int col=sc.nextInt();
        int arr[][]=ac2d.Accept(row, col);
        arr=sl.CheckElements(arr);
        System.out.println(Arrays.deepToString(arr));
        sc.close();
    }
}
