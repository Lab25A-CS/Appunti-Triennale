public class Client {
    public static void main(String[] args) {
        ElementList elementList = new ElementList();
        ElementList elementList2 = new ElementList();
        elementList.addElement(64, 34, 25, 12, 22, 11, 90);
        elementList2.addElement(48, 34, 4, 12, 2, 11, 90);
        elementList.setSortAlgorithm(new BubbleSort());
        System.out.println(elementList.getSortedList());
        elementList2.setSortAlgorithm(new InsertionSort());
        System.out.println(elementList2.getSortedList());
    }
    
}
