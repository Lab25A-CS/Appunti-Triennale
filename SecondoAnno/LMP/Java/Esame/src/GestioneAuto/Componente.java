package GestioneAuto;

public class Componente {
    public int identificativo;
    private int tempoDiOrdinazione;
    private double costoComponente;
    private String provenienza;

    Componente(int identificativo, int tempoDiOrdinazione, double costoComponente, String provenienza){
        this.identificativo = identificativo;
        this.tempoDiOrdinazione = tempoDiOrdinazione;
        this.costoComponente = costoComponente;
        this.provenienza = provenienza;
    }

    public int getTempoDiOrdinazione() {
        return tempoDiOrdinazione;
    }

    public double getCostoComponente() {
        return costoComponente;
    }

    @Override
    public String toString() {
        return " Componente{" +
                " identificativo = " + identificativo +
                '}';
    }
}
