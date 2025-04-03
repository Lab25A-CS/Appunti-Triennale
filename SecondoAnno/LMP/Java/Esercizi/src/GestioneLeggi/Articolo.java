package GestioneLeggi;

import java.util.ArrayList;

public class Articolo {
    public final int identificativo;
    private final String introduzione;
    private ArrayList<Comma> commi;

    Articolo(int identificativo, String introduzione){
        this.identificativo = identificativo;
        this.introduzione = introduzione;
        this.commi = new ArrayList<Comma>();
    }

    void AggiuntaComma(String testo){
        int n = commi.size();
        commi.add(new Comma(n, testo));
    }


}
