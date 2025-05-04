public class SingleLinkedList {
    public Node head;
    public Node tail;
    public int size;

    public Node createSinglyLinkedList(int nodeValue) {
        head = new Node();
        Node node = new Node();
        node.next = null;//reference is null,i.e,initially size of LinkedList is 1
        node.value = nodeValue;//value of node as supplied from user
        head = node;
        tail = node;//Both Head and tail are referenced to the same node
        size = 1;
        return head;
    }

    //Insert method at any given location
    public void insertInLinkedList(int nodeValue, int location) {
        Node node = new Node();
        node.value = nodeValue;
        if (head == null) {
            createSinglyLinkedList(nodeValue);
            return;
        } else if (location == 0) {
            node.next = head;
            head = node;
        } else if (location >= size) {
            node.next = null;//Represents the absence of any next element,i.e, the end
            tail.next = node;
            tail = node;
        } else {
            Node tempNode = head;
            int index = 0;
            while (index <= location - 1) {
                tempNode = tempNode.next;/*tempNode is the node that is
                currently occupying the position where the new node has
                to be created*/
                index++;
            }
            Node nextNode = tempNode.next;/*stores the next-reference of the current node at
            that position,i.e, the physical location the node next to the current node at that
            location*/
            tempNode.next = node;/*sets the next reference of the currently positioned
            node at that position to the new node*/
            node.next = nextNode;/*Sets the next reference of the new node to the
            physical location of the node next to the previous node at that 
            position(Node that was after tempNode) to the newly created node */
            //Hence successfully inserting a new node between two nodes
        }
        size++;
    }
    //Traversing a Linked List
    public void traverseSinglyLinkedList() {
        if (head == null) {
            System.out.println("SLL does not exists!");
        } else {
            Node tempNode = head;
            for (int i = 0; i < size; i++) {
                System.out.print(tempNode.value);
                if (i != size - 1) {
                    System.out.print("->");
                }
                tempNode = tempNode.next;
            }
        }
        System.out.println("\n");
    }
    //Search for a node
    boolean searchNode(int nodeValue) {
        if (head != null) {
            Node tempNode = head;
            for (int i = 0; i < size; i++) {
                if (tempNode.value == nodeValue) {
                    System.out.print("Found the node at location: " + i + "\n");
                    return true;
                }
                tempNode=tempNode.next;
            }
        }
        System.out.print("Node not found");
        return false;
    }

    //Delete a Node from Singly Linked List
    public void deleteOfNode(int location){
        if(head == null){
            System.out.println(("Singly Linked List does not exists"));
        }
        else if(location == 0){
            head=head.next;
            size--;
            if(size==0){
                tail=null;
                head=null;
            }
        }
        else if(location >= size){
            Node tempNode=head;
            for(int i=0;i<size-1;i++)//size-1 is used because we have to find the node before the last node
            {
                tempNode=tempNode.next;
            }
            if(tempNode==head){
                tail=head=null;
                size--;
                return;
            }
            tempNode.next=null;
            tail=tempNode;
            size--;
        }
        else{
            Node tempNode=head;
            for(int i=0;i<location-1;i++){
                tempNode=tempNode.next;
            }
            tempNode.next=tempNode.next.next;
            size--;
        }
    }

    //delete the entire Singly Linked List
    public void deleteSLL(){
        head=null;
        tail=null;
        System.out.println("Singly Linked List deleted successfully");
    }
}