package GestioneAuto;

import java.util.ArrayList;

public class Database {
    ArrayList<Prodotto> listaProdotti;
    Prodotto piùRedditizio;

    Database(){
        this.listaProdotti = new ArrayList<Prodotto>();
        this.piùRedditizio = new Prodotto(0,"prova", 0.0, "a", 0.0);
    }

    void AggiuntaProdotto(Prodotto prodotto){
        listaProdotti.add(prodotto);
        if(prodotto.getCosto() > piùRedditizio.getCosto()){
            piùRedditizio = prodotto;
        }
    }

    @Override
    public String toString() {
        return "Database{" +
                "listaProdotti=" + listaProdotti +
                '}';
    }
}
