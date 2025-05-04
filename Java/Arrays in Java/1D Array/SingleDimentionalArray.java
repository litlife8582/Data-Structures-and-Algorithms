//Declaration of class
public class SingleDimentionalArray{
    int arr[]=null;
    //Creation of an array
    public SingleDimentionalArray(int sizeOfArray){
        arr=new int[sizeOfArray];
        for(int i=0;i<arr.length;i++){
            arr[i]=Integer.MIN_VALUE;
        }
    }
    //Insertion in an array
    public void insert(int location, int valueToBeInserted){
        try{
            if(arr[location]==Integer.MIN_VALUE){
                arr[location]=valueToBeInserted;
                System.out.println("Successfully Inserted");
            }
            else{
                System.out.println("This cell is already occupied");
            }
        }
            catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Invalid index to access array");
        }
    }
    //Array Traversal
    public void traverseArray(){
        try{
            for (int i=0;i<arr.length;i++)
            {
                 System.out.print(arr[i]+" ");
            }
        }
        catch(Exception e){
            System.out.println("Array no longer exists");
        }
        System.out.println();
    }
    //Search in a Array
    public void searchInArray(int valueToSearch){
        for(int i=0;i<=arr.length;i++){
            if(arr[i]==valueToSearch){
                System.out.println("Value is found at the index of "+ i);
                return;
            }
        }
        System.out.println(valueToSearch+" is not found");
    }
    //Deleting values from Array
    public void deleteValue(int valueToDeleteIndex){
        try{
            arr[valueToDeleteIndex]=Integer.MIN_VALUE;
            System.out.println("The value has been deleted successfully");
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("The value that is provided is not in the range of Array");

        }
    }
}
