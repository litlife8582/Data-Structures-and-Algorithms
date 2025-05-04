import java.util.Arrays;
import java.util.Scanner;
class Main2 {
    public static void main(String[] args){
        
        Scanner sc=new Scanner(System.in);
        int r=sc.nextInt();    
        int c=sc.nextInt();    
        TwoDimensionalArray tda=new TwoDimensionalArray(r,c);
        
        
        tda.insertValueInTheArray(0, 0, 10);
        tda.insertValueInTheArray(1, 0, 20);
        tda.insertValueInTheArray(1, 1, 30);
        tda.insertValueInTheArray(1, 0, 15);
        System.out.println(Arrays.deepToString(tda.arr));  
        
        tda.accessCell(1,1);
        tda.traverse2DArray();
        int value=sc.nextInt();
        tda.search2DArray(value);
        tda.Delete2DArray(1,1);
        System.out.println(Arrays.deepToString(tda.arr));
        sc.close();
    }
}
