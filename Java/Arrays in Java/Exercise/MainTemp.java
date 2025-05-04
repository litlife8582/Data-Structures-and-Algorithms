import java.util.Scanner;
public class MainTemp {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Calculate_Average_Temperature temp= new Calculate_Average_Temperature();
        System.out.println("Enter the number of temperature to be checked: ");
        int n=sc.nextInt();
        temp.AcceptTemperature(n);
        float avg=temp.AverageTemp();
        System.out.println("The average temperature is: "+avg);
        temp.AboveorBelowTemperature();
        sc.close();
    }
    
}
