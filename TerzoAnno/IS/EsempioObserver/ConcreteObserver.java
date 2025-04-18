public class ConcreteObserver implements ObserverInterface {
    private String name;

    public ConcreteObserver(String name) {
        this.name = name;
    }
    @Override
    public void update() {
        System.out.println("Sono : "+name+" il Subject è stato cambiato");
    }
    
}
