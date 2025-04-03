package GestioneLeggi;

public class Comma {
    public final int identificativo;
    private final String testo;

    Comma(int n, String t){
        this.identificativo = n;
        this.testo = t;
    }

    public String getTesto() {
        return testo;
    }
}
