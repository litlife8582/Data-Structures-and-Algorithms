class Main {
    public static void main(String[] args){
        SingleLinkedList sLL=new SingleLinkedList();
        sLL.createSinglyLinkedList(5);
        //System.out.println(sLL.head.value);
        sLL.insertInLinkedList(6, 1);
        sLL.insertInLinkedList(7, 3);
        //System.out.println(sLL.head.next.next.value);
        sLL.insertInLinkedList(8,4);
        sLL.insertInLinkedList(8,5);
        sLL.insertInLinkedList(9,0);
        sLL.traverseSinglyLinkedList();
        sLL.searchNode(7);
        sLL.searchNode(1);
        sLL.deleteOfNode(3);
        System.out.println();
        sLL.traverseSinglyLinkedList();
        sLL.deleteSLL();
        sLL.traverseSinglyLinkedList();
    }
}
