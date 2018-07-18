// Java program to remove duplicates from unsorted 
// linked list
 
class LinkedList {
 
    static Node head;
 
    static class Node {
 
        int data;
        Node next;
 
        Node(int d) {
            data = d;
            next = null;
        }
    }
 
    /* Function to remove duplicates from an
       unsorted linked list */
    void remove_duplicates() {
        Node a = null; Node b = null; Node duplicate = null;
        a = head;
 
        /* Pick elements one by one */
        while (a != null && a.next != null) {
            b = a;
 
            /* Compare the picked element with rest
                of the elements */
            while (b.next != null) {
 
                /* If duplicate then delete it */
                if (a.data == b.next.data) {
 
                    /* sequence of steps is important here */
                    duplicate = b.next;
                    b.next = b.next.next;
                    System.gc();//garbage collection
                } else /* This is tricky */ {
                    b = b.next;
                }
            }
            a = a.next;
        }
    }
 
    void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
 
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.head = new Node(10);
        list.head.next = new Node(12);
        list.head.next.next = new Node(11);
        list.head.next.next.next = new Node(11);
        list.head.next.next.next.next = new Node(12);
        list.head.next.next.next.next.next = new Node(11);
        list.head.next.next.next.next.next.next = new Node(10);
 
        System.out.println("Linked List before removing duplicates : \n ");
        list.printList(head);
 
        list.remove_duplicates();
        System.out.println("");
        System.out.println("Linked List after removing duplicates : \n ");
        list.printList(head);
    }
}

