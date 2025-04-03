package GestioneLudoteca;

import java.time.LocalTime;

public class Game extends Product{

    LocalTime tempoDiGioco;


    Game(String titolo, String autore, String casaEditrice, int annoDiPubblicazione, int hour, int minutes) {
        super(titolo, autore, casaEditrice, annoDiPubblicazione);
        this.tempoDiGioco = LocalTime.of(hour, minutes);
    }

    @Override
    public String toString() {
        return  super.toString() +
                "tempoDiGioco = " + tempoDiGioco;
    }

    public LocalTime getTempoDiGioco() {
        return tempoDiGioco;
    }
}
