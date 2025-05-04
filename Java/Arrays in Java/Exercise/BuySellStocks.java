import java.util.*;
public class BuySellStocks {
    int arr[]=null;
    public int[] AcceptElements(int num){
        Scanner sc=new Scanner(System.in);
        arr=new int[num];
        for(int i=0;i<num;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    public int FindProfit(int arr[]){
        int minPrice=0;
        int maxProfit=0;
        for(int i=1;i<arr.length;i++){
            if(minPrice>arr[i]){
                minPrice=arr[i];
            }
            else if (arr[i]-minPrice>maxProfit){
                maxProfit=arr[i]-minPrice;
            }
        }
        return maxProfit;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        BuySellStocks bs=new BuySellStocks();
        int num=sc.nextInt();
        int arr[]=bs.AcceptElements(num);
        int profit=bs.FindProfit(arr);
        System.out.println("Profit: "+profit);
        sc.close();
    }
    
}
