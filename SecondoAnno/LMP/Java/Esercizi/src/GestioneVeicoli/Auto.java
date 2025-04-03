package GestioneVeicoli;

public class Auto extends Veicolo{

    int numeroPorte;
    private double costoNoleggio = 15.75;

    Auto(String targa, String modello, String marca, int numeroPorte){
        super(targa, modello, marca);
        this.numeroPorte = numeroPorte;
    }

    public int getNumeroPorte(){
        return numeroPorte;
    }

    double calcolaCostoNoleggio(int giorni){
        return giorni*costoNoleggio;
    }
    
}
