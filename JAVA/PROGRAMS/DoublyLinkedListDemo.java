import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;

    Node(int item) {
        this.data = item;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    Node header = null;
    Node tail = null;

    // Insert at the front
    public void insertFront(int item) {
        Node newNode = new Node(item);
        if (header == null) { // If list is empty
            header = tail = newNode;
        } else {
            newNode.next = header;
            header.prev = newNode;
            header = newNode;
        }
    }

    // Insert at the end
    public void insertEnd(int item) {
        Node newNode = new Node(item);
        if (header == null) { // If list is empty
            header = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    // Delete from the front
    public void deleteFront() {
        if (header == null) {
            System.out.println("List is empty, nothing to delete.");
            return;
        }
        header = header.next;
        if (header != null) {
            header.prev = null;
        } else {
            tail = null; // If list becomes empty, update tail
        }
    }

    // Delete from the end
    public void deleteEnd() {
        if (header == null) {
            System.out.println("List is empty, nothing to delete.");
            return;
        }
        if (header.next == null) { // Only one node
            header = tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
    }

    // Delete by key
    public void deleteByKey(int key) {
        if (header == null) {
            System.out.println("List is empty, nothing to delete.");
            return;
        }
        Node temp = header;
        while (temp != null && temp.data != key) {
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Key not found, no deletion possible.");
        } else {
            if (temp.prev != null) {
                temp.prev.next = temp.next;
            } else {
                header = temp.next;
            }
            if (temp.next != null) {
                temp.next.prev = temp.prev;
            } else {
                tail = temp.prev;
            }
        }
    }

    // Display the list from front to end
    public void displayForward() {
        Node temp = header;
        System.out.print("List in forward order: ");
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    // Display the list from end to front
    public void displayReverse() {
        Node temp = tail;
        System.out.print("List in reverse order: ");
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.prev;
        }
        System.out.println("NULL");
    }
}

public class DoublyLinkedListDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();
        int item, key, choice;

        do {
            System.out.println("Enter your choice:");
            System.out.println("1. Insert at front");
            System.out.println("2. Insert at end");
            System.out.println("3. Delete at front");
            System.out.println("4. Delete at end");
            System.out.println("5. Delete by key");
            System.out.println("6. Display forward");
            System.out.println("7. Display reverse");
            System.out.println("8. Exit");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert at front: ");
                    item = sc.nextInt();
                    list.insertFront(item);
                    break;
                case 2:
                    System.out.print("Enter value to insert at end: ");
                    item = sc.nextInt();
                    list.insertEnd(item);
                    break;
                case 3:
                    list.deleteFront();
                    break;
                case 4:
                    list.deleteEnd();
                    break;
                case 5:
                    System.out.print("Enter the key to delete: ");
                    key = sc.nextInt();
                    list.deleteByKey(key);
                    break;
                case 6:
                    list.displayForward();
                    break;
                case 7:
                    list.displayReverse();
                    break;
                case 8:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        } while (choice != 8);

        sc.close();
    }
}
