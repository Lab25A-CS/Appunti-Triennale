import java.util.List;

public class InsertionSort implements SortAlgorithm {
    public List sort(List unSortedList) {
        System.out.println("InsertionSort");
        for (int i = 1; i < unSortedList.size(); i++) {
            int key = (int) unSortedList.get(i);
            int j = i - 1;
            while (j >= 0 && (int) unSortedList.get(j) > key) {
                unSortedList.set(j + 1, unSortedList.get(j));
                j = j - 1;
            }
            unSortedList.set(j + 1, key);
        }
        return unSortedList;
    }
    
}
