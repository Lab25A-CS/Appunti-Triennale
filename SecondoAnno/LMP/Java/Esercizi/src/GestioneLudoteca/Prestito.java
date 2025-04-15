package GestioneLudoteca;

import java.time.LocalTime;

public class Prestito {
    LocalTime startTime;
    Cliente utilizzatore;
    Book libroInPrestito;
    Game giocoInPrestito;
    LocalTime endingTime;

    Prestito(Game gioco, Cliente user){
        this.giocoInPrestito = gioco;
        this.utilizzatore = user;
        this.startTime = LocalTime.now();
        LocalTime tempo = LocalTime.now();
        int hour = (tempo.getHour() + gioco.tempoDiGioco.getHour()) % 24;
        int minute = (tempo.getMinute() + gioco.tempoDiGioco.getMinute()) % 60;
        this.endingTime = LocalTime.of(hour, minute);
    }

    Prestito(Book libro, Cliente user){
        this.libroInPrestito = libro;
        this.utilizzatore = user;
        this.startTime = LocalTime.now();

    }

    @Override
    public String toString() {
        return "Prestito{" +
                "startTime=" + startTime +
                ", utilizzatore=" + utilizzatore +
                ", libroInPrestito=" + libroInPrestito +
                ", giocoInPrestito=" + giocoInPrestito +
                ", endingTime=" + endingTime +
                '}';
    }
}
