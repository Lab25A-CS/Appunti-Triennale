public class Client {
    public static void main(String[] args) {
        ConcreteSubject subject = new ConcreteSubject();
        ConcreteObserver observer1 = new ConcreteObserver("Observer1");
        ConcreteObserver observer2 = new ConcreteObserver("Observer2");
        ConcreteObserver observer3 = new ConcreteObserver("Observer3");

        //aggiungo gli osservatori
        subject.addObserver(observer1);
        subject.addObserver(observer2);
        subject.addObserver(observer3);

        //modifico lo stato del soggetto
        subject.setState(true);

        //rimuovo un osservatore
        System.err.println("Rimuovo l'osservatore 2");
        subject.removeObserver(observer2);

        //modifico lo stato del soggetto
        System.out.println("Modifico lo stato del soggetto da true a false");
        subject.setState(false);
    }
}
