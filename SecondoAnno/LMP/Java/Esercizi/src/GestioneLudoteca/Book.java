package GestioneLudoteca;

import java.util.Date;

public class Book extends Product{
    int numeroDiPagine;

    Book(String titolo, String autore , String casaEditrice, int annoDiPubblicazione, int numeroDiPagine){
        super(titolo, autore, casaEditrice, annoDiPubblicazione);
        this.numeroDiPagine = numeroDiPagine;
    }

    @Override
    public String toString() {
        return  super.toString() +
                "numeroDiPagine = " + numeroDiPagine;
    }
}
