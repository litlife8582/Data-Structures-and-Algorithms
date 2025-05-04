import java.util.*;
public class Frequency {
    public void CheckFrequency(int arr[][]){
        int ele=0;
        int frequency=0;
        for(int row1=0;row1<arr.length;row1++){
            for(int col1=0;col1<arr[0].length;col1++){
                ele=arr[row1][col1];
                for(int row2=0;row2<arr.length;row2++){
                    for(int col2=0;col2<arr[0].length;col2++){
                        if(ele==arr[row2][col2]){
                            frequency++;
                        }
                    }
                }
                System.out.println("Element: "+ele+", "+"Frequency: "+frequency);
            }
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        AcceptNumbers2D ac2d=new AcceptNumbers2D();
        Frequency f=new Frequency();
        int row=sc.nextInt();
        int col=sc.nextInt();
        int arr[][]=ac2d.Accept(row, col);
        f.CheckFrequency(arr);
        sc.close();
    }
}
