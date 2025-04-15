public class Pesce implements Preda, Predatore{
    @Override
    public void scappa() {
        System.out.println("il pesce scappa via");
    }

    @Override
    public void caccia() {
        System.out.println("il pesce sta cacciando");
    }
}
