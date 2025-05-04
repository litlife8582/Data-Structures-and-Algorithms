
import java.util.*;

public class Calculate_Average_Temperature {
    float arr[]=null;//declaration of array
    float avg=0;//declaration of a global variable to store avg
    //Accepting elements in the array
    public void AcceptTemperature(int n){
        Scanner sc=new Scanner(System.in);
        arr=new float[n];
        System.out.println("Enter the temperatures: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextFloat();
        }
        sc.close();
    }
    //Calculating the average of all the tempearatures stored in the array
    public float AverageTemp(){
        float sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
        }
        avg=sum/arr.length;
        return avg;
    }
    //Calculating the number of elemnents present above or below the average temperature
    public void AboveorBelowTemperature(){
        int above=0, below=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>=avg){
                above++;
            }else{
                below++;
            }
        }
        System.out.println("The number of days above "+ avg+" is: "+ above);
        System.out.println("The number of days below "+ avg+" is: "+ below);
    }
 }

