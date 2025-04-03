package GestioneVeicoli;

public class Camion extends Veicolo{
    double capacitàCarico;
    private final double costoNoleggio = 45.5;

    Camion(String targa, String modello, String marca, int capacitàCarico){
        super(targa, modello, marca);
        this.capacitàCarico = capacitàCarico;
    }

    public double getCapacitàCarico() {
        return capacitàCarico;
    }

    double calcolaCostoNoleggio(int giorni){
        return giorni*costoNoleggio;
    }
}
