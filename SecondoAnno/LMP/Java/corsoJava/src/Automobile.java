public class Automobile extends Veicolo{ // una classe che eredita una astratta DEVE imlementare i metodi astratti
    @Override
    void muovi() {
        System.out.println("si muove");
    }

    @Override
    void frena() {
        System.out.println("la macchina frena");
    }


}
