package GestioneLeggi;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;

public class Portale {
    private HashMap<LocalDate, ArrayList<Legge>> database;
    private HashMap<Integer, ArrayList<Legge>> leggiPerAnno;
    private ArrayList<Legge> libreriaDelleLeggi;

    Portale(){
        this.database = new HashMap<LocalDate, ArrayList<Legge>>();
        this.leggiPerAnno = new HashMap<Integer, ArrayList<Legge>>();
    }


    Legge RecuperoLegge(LocalDate data, String tipo) {
        if (database.containsKey(data) == false) {
            System.out.println("non sono state emanate leggi nel giorno " + data);
            return null;
        }
        System.out.println("sono state emanate leggi nel giorno " + data);
        ArrayList<Legge> listaLeggi = database.get(data);
        for (int i = 0; i <= listaLeggi.size(); i++) {
            Legge legge = listaLeggi.get(i);
            if (legge.tipo == tipo) {
                return legge;
            }
        }
        System.out.println("non è presente una legge emanata il giorno " + data + " del tipo " + tipo);
        return null;
    }

    void LeggiPerAnno(int anno){
        if (leggiPerAnno.containsKey(anno) == false) {
            System.out.println("non sono state emanate leggi nell'anno: " + anno);
            return;
        }
        System.out.println("sono state emanate leggi nel nell'anno: " + anno);
        ArrayList<Legge> lista = leggiPerAnno.get(anno);
        for(int i = 0; i <= lista.size(); i++){
            Legge legge = lista.get(i);
            System.out.println(legge.identità + " :<" + legge.tipo + ">-<" + legge.data.getYear() + ">-<" + legge.data.getMonth() + ">-<" + legge.data.getDayOfMonth() + ">");
        }
        return;
    }

    void LeggiCon20Articoli(){
        for(int i = 0; i <= libreriaDelleLeggi.size(); i++){
            Legge legge = libreriaDelleLeggi.get(i);
            if (legge.getNumeroArticoli() > 20){
                System.out.println(legge);
            }
        }
        return;
    }



}
