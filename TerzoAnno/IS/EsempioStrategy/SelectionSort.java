import java.util.List;

public class SelectionSort implements SortAlgorithm {
    public List sort(List unSortedList) {
        System.out.println("SelectionSort");
        for (int i = 0; i < unSortedList.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < unSortedList.size(); j++) {
                if ((int) unSortedList.get(j) < (int) unSortedList.get(minIndex)) {
                    minIndex = j;
                }
            }
            int temp = (int) unSortedList.get(i);
            unSortedList.set(i, unSortedList.get(minIndex));
            unSortedList.set(minIndex, temp);
        }
        return unSortedList;
    }
    
}
