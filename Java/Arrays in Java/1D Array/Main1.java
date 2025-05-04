import java.util.*;
public class Main1 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        SingleDimentionalArray sda=new SingleDimentionalArray(n);
        //Insertion in Array
        sda.insert(0,0);
        sda.insert(1,10);
        sda.insert(2,20);
        sda.insert(1,30);
        sda.insert(12,120);
        //FInding Element in Array
        var firstElement=sda.arr[3];
        System.out.println(firstElement);
        System.out.println("Array Traversal:");
        //Traversing Array
        sda.traverseArray();
        //Searching in Array
        sda.searchInArray(20);
        //Delete from Array
        sda.deleteValue(0);
        System.out.println(sda.arr[0]);
        sc.close();
    }
}
