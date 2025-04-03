package GestioneLibri;/*
Gestione di Libri in una Library: Crea una classe Book con attributi come titolo, autore,
anno di pubblicazione, ecc. Poi crea una classe Library che gestisca un insieme di libri, consentendo
operazioni come aggiunta, rimozione, ricerca e visualizzazione dei libri presenti nella biblioteca.
 */

import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Book x = new Book(
                "Percy Jackson e gli dei dell'Olimpo: Il ladro di fulmini",
                "Rick Riordan",
                2005,
                6,
                28,
                "Adventure");

        Book y = new Book(
                "Maze runner",
                "phil collins",
                2001,
                5,
                3,
                "Apocalyptic"
        );

        Library casale = new Library("casale");

        casale.add(x);
        casale.add(y);

        System.out.println(casale.getCatalogue().get("Maze runner") + "\n" + casale.getBookshelf());
    }

}