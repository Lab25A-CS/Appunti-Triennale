public class ConcreteSubject extends Subject {
    private boolean state;

    public boolean getState() {
        return this.state;
    }

    public void setState(boolean state) {
        this.state = state;
        notifyObservers();
    }
    
}
