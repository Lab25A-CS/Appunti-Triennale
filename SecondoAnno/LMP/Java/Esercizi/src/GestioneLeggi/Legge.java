package GestioneLeggi;

import java.time.LocalDate;
import java.util.ArrayList;

public class Legge {

    final String tipo;
    final LocalDate data;
    final String identità;
    private final String intestazione;
    private ArrayList<Articolo> articoli;
    private ArrayList<Object> oggetti;
    private final String conclusioni;
    private int numeroArticoli;

    Legge(String tipo, String identità, String intestazione, String conclusioni){
        this.tipo = tipo;
        this.data = LocalDate.now();
        this.identità = identità;
        this.intestazione = intestazione;
        this.conclusioni = conclusioni;
        this.articoli = new ArrayList<Articolo>();
        this.oggetti = new ArrayList<Object>();
        this.numeroArticoli = 0;
    }

    void AggiuntaOggetti(Object oggetto){
        oggetti.add(oggetto);
        System.out.println("l'oggetto è stato aggiunto correttamente");
    }

    void AggiuntaArticolo(String introduzione){
        int identificativo = articoli.size();
        articoli.add(new Articolo(identificativo, introduzione));
        numeroArticoli++;
    }

    public Articolo getArticolo(int i) {
        return articoli.get(i);
    }

    public ArrayList<Object> getOggetti() {
        return oggetti;
    }

    public String getIntestazione() {
        return intestazione;
    }

    public int getNumeroArticoli() {
        return numeroArticoli;
    }

    @Override
    public String toString() {
        return identità + " { " +
                "tipo = '" + tipo + '\'' +
                ", data = " + data + '\'' +
                ", intestazione = '" + intestazione + '\'' +
                ", articoli = " + articoli +
                ", oggetti = " + oggetti +
                ", conclusioni = '" + conclusioni + '\'' +
                '}';
    }
}
