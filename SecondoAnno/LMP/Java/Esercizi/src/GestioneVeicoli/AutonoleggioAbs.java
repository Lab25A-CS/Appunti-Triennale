package GestioneVeicoli;

import java.util.ArrayList;

public abstract class AutonoleggioAbs {
    ArrayList<Veicolo> listaVeicoli = new ArrayList<Veicolo>();

    abstract void aggiungiVeicolo(Veicolo aggiunta);
    abstract Veicolo rimuoviVeicolo(String targa);
    abstract String stampaDettagliVeicolo(Veicolo info);
}
