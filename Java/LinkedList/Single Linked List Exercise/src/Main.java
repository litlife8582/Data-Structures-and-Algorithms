class Main {
    public static void main(String[] args){
        SinglyLinkedList sll= new SinglyLinkedList();
        sll.insertSinglyLinkedList(5);
        sll.push(5);
        System.out.println((sll.size));
        sll.push(10);
        System.out.println((sll.size));
        sll.pop();
        System.out.println(sll.size);
    }
}