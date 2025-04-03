package GestioneVeicoli;

public class Motocicletta extends Veicolo{

    private int cilindrata;
    private final double costoNoleggio = 10.2;

    Motocicletta(String targa, String modello, String marca, int cilindrata){
        super(targa, modello, marca);
        this.cilindrata = cilindrata;
    }

    public int getCilindrata() {
        return cilindrata;
    }

    double calcolaCostoNoleggio(int giorni){
        return giorni*costoNoleggio;
    }


}
