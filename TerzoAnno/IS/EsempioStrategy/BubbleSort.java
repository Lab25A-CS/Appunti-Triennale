import java.util.List;

public class BubbleSort implements SortAlgorithm {
    public List sort(List unSortedList) {
        System.out.println("BubbleSort");
        for (int i = 0; i < unSortedList.size(); i++) {
            for (int j = 0; j < unSortedList.size() - 1; j++) {
                if ((int) unSortedList.get(j) > (int) unSortedList.get(j + 1)) {
                    int temp = (int) unSortedList.get(j);
                    unSortedList.set(j, unSortedList.get(j + 1));
                    unSortedList.set(j + 1, temp);
                }
            }
        }
        return unSortedList;
    }
    
}
