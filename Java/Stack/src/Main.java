public class Main {
    public static void main(String[] args) {
        Stack newStack=new Stack(4);
        boolean result1=newStack.isEmpty();//Checks whether stack is empty
        System.out.println(result1);
        boolean result2=newStack.isFull();
        System.out.println(result2);
        newStack.push(1);
        newStack.push(2);
        newStack.push(3);
        newStack.push(4);
        newStack.push(5);
        int result3=newStack.pop();
        System.out.println(result3);
        newStack.deleteStack();
    }
}