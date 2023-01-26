public class Main {

    public static void main(String[] args) throws Exception {
       DoubleLinkedList<String> list=new DoubleLinkedList<>();
       list.add("Hello");
       list.add(0,"Welcome");
        System.out.println(list);
        System.out.println(list.size());
        System.out.println(list.remove(0));
        System.out.println(list);
        System.out.println(list.remove(0));
    }
}
