import java.util.Arrays;
class Array_Creation2D {
    public static void main(String args[]){
        int[][] int2DArray;
        int2DArray = new int[2][2];
        int2DArray[0][0]=1;
        int2DArray[0][1]=2;
        int2DArray[1][0]=3;
        int2DArray[1][1]=4;
        /**To print 2D arrays we need to use deep to string
        method from the Arrays Library in java**/ 
        System.out.println(Arrays.deepToString(int2DArray));
        /**We cannot directly print 2D directly as we can print
          1D array in Java, we have to use Arrays library**/
        String s2DArray[][]={{"a","b"},{"c","d"}};
        System.out.println(Arrays.deepToString(s2DArray));
    }
}
