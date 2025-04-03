package GestioneLudoteca;
import java.util.Date;

public abstract class Product {

    String titolo;
    String autore;
    String casaEditrice;
    int  annoDiPubblicazione;

    Product(String titolo, String autore , String casaEditrice, int annoDiPubblicazione){
        this.titolo = titolo;
        this.autore = autore;
        this.casaEditrice = casaEditrice;
        this.annoDiPubblicazione = annoDiPubblicazione;
    }

    @Override
    public String toString() {
        return
                "titolo = '" + titolo + '\'' +
                ", autore = '" + autore + '\'' +
                ", casaEditrice = '" + casaEditrice + '\'' +
                ", annoDiPubblicazione = " + annoDiPubblicazione + ", ";
    }
}
