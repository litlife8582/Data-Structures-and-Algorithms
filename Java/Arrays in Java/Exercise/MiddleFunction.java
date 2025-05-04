/*Middle Function
Write a function called middle that takes an array and
returns a new array that contains all but the first and last elements. */
public class MiddleFunction {
   
    public static int[] middle(int[] array) {
        if(array.length==2){
            return new int[0];
        }
        int f[]=new int[array.length-2];
        for(int i=1;i<array.length-1;i++){
            f[i-1]=array[i];
        }
        return f;
    }
    public static void main(String[] args){
        int arr[]={1,2,3,4};
        int result[]=middle(arr);
        for(int i=0;i<result.length;i++){
        System.out.print(result[i]);
        }
    }
}
