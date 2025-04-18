import java.util.ArrayList;

public abstract class Subject {
    private ArrayList<ObserverInterface> observers = new ArrayList<ObserverInterface>();

    public void addObserver(ObserverInterface observer) {
        observers.add(observer);
    }

    public void removeObserver(ObserverInterface observer) {
        observers.remove(observer);
    }

    public void notifyObservers() {
        for (ObserverInterface observer : observers) {
            observer.update();
        }
    }
}
