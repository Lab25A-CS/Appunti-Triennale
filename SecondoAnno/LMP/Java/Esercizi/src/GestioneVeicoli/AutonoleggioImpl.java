package GestioneVeicoli;

public class AutonoleggioImpl implements AutonoleggioAbs{

    @Override
    void aggiungiVeicolo(Veicolo aggiunta) {
        listaVeicoli.add(aggiunta);
    }

    @Override
    Veicolo rimuoviVeicolo(String targa) {
        for (int i = 0; i<= listaVeicoli.size(); i++){
            if (listaVeicoli.get(i).getTarga() == targa){
                listaVeicoli.remove(i);
                return listaVeicoli.get(i);
            }
        }
        System.out.println("la targa non è presente  nel database");
        return null;
    }

    @Override
    String stampaDettagliVeicolo(Veicolo info) {
        return "";
    }
}
