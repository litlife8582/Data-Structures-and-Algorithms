public class Stack {
    int[] arr;
    int topOfStack;

    public Stack(int size) {
        this.arr = new int[size];
        this.topOfStack = -1;
        System.out.println("The Stack is created with size of: " + size);
    }

    //check whether stack is empty
    public boolean isEmpty() {
        if (topOfStack == -1) return true;
        else return false;
    }

    //next method
    public boolean isFull() {
        if (topOfStack == arr.length - 1) {
            //System.out.println("Stack is Full");
            return true;
        }
        else return false;
    }

    //Push
    public void push(int value){
        if(isFull()){
            System.out.println("Stack is full");
        }
        else{
            arr[topOfStack+1]=value;
            topOfStack++;
            System.out.println("The value is successfully inserted");
        }
    }

    //pop
    public int pop(){
        if(isEmpty()){
            System.out.println("The stack is Empty");
            return -1;
        }else{
            int topStack = arr[topOfStack]; // Store the top value
            topOfStack--; // Decrement top pointer
            return topStack;
        }
    }

    //peek
    public int peek(){
        if(isEmpty()){
            System.out.println("The Stack is Empty");
            return -1;
        }
        else{
            return arr[topOfStack];
        }
    }

    //delete
    public void deleteStack(){
        arr=null;
        System.out.println("The Stack is successfully deleted");
    }
}
