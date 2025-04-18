import java.util.ArrayList;
import java.util.List;

public class ElementList {

    private List elements;
    private SortAlgorithm sortAlgorithm;

    public ElementList() {
        elements = new ArrayList();
    }

    public void addElement(int... values) {
        for (int value : values) {
            elements.add(value);
        }
    }

    public void setSortAlgorithm(SortAlgorithm sortAlgorithm) {
        this.sortAlgorithm = sortAlgorithm;
    }

    public List getSortedList() {
        return sortAlgorithm.sort(elements);
    }
}