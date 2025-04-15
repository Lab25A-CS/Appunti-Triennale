package GestioneVeicoli;

public class Veicolo {
    static int numeroVeicoli;
    private final String targa;
    private final String modello;
    private final String marca;

    Veicolo(String targa, String modello, String marca){
        this.targa = targa;
        this.modello = modello;
        this.marca = marca;
        numeroVeicoli++;
    }

    String getTarga(){
        return targa;
    }

    String getModello(){
        return modello;
    }

    String getMarca(){
        return marca;
    }

    @Override
    public String toString() {
        return "targa='" + targa + '\'' +
                ", modello='" + modello + '\'' +
                ", marca='" + marca;
    }
}
