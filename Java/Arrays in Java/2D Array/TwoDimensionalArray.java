public class TwoDimensionalArray{
    int arr[][]=null;
    //Creation and Initialization of the Array
    public TwoDimensionalArray(int numberOfRows, int numberOfColumns){
        this.arr=new int[numberOfRows][numberOfColumns];
        for(int row=0;row<arr.length;row++){
            //arr[0].length represents column length in 2D arrays
            for(int col=0;col<arr[0].length;col++){
                arr[row][col]=Integer.MIN_VALUE;
            }
        }
    }
    //Insertion of elemnts in the Array
    public void insertValueInTheArray(int row,int col,int value){
        try{
            if(arr[row][col]==Integer.MIN_VALUE){
                arr[row][col]=value;
                System.out.println("The value is successfully inserted");
            }
            else{
                System.out.println("This cell is already occupied");
            }
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Invalid Index for 2D Array");

        }
    }
    //Accessing cell value from given array
    public void accessCell(int row, int col){
        System.out.println("\nAccessing Row#"+row+", Col#"+col);
        try{
            System.out.println("Cell value is: " + arr[row][col]);
        }catch( ArrayIndexOutOfBoundsException e){
            System.out.println("Invalid index for 2D Array");
        }
    }
    //Traversing an Array
    public void traverse2DArray(){
            for(int row=0; row<arr.length;row++){
                for(int col=0;col<arr[0].length;col++){
                    System.out.println(arr[row][col]+ " ");                
            }
            System.out.println();
        }
    }
    //Searching 2D Array
    public void search2DArray(int value){
        for(int row=0;row<arr.length;row++){
            for(int col=0;col<arr[0].length;col++){
                if(arr[row][col]==value){
                System.out.println("Value is found at row: "+row+" Col: :" +col);
                return;
                }
            }
        }
        System.out.println("Value is not found");
    }
    //Delete element in a 2D Array
    public void Delete2DArray(int row, int col){
        try{
            System.out.println("Value for cell Successfully deleated: "+arr[row][col]);
            arr[row][col]=Integer.MIN_VALUE;
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("This index is invalid for array");
        }
    }
}