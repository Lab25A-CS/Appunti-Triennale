package GestioneLudoteca;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;

public class Ludoteca {

    public static int numeroSedi;
    public final String nome;
    private HashMap<String, Book> catalogoLibri;
    private HashMap<String, Game> catalogoGiochi;
    private HashMap<String, Integer> disponibilita;
    private HashMap<LocalDate, ArrayList<Prestito>> catalogoPrestiti;


    Ludoteca(String nome){
        this.nome = nome;
        this.catalogoLibri = new HashMap<String, Book>();
        this.catalogoGiochi = new HashMap<String, Game>();
        this.disponibilita = new HashMap<String, Integer>();
        this.catalogoPrestiti = new HashMap<LocalDate, ArrayList<Prestito>>();
        numeroSedi++;
    }

    void Inserimento(Game gioco){
        catalogoGiochi.put(gioco.titolo, gioco);
        if(disponibilita.containsKey(gioco.titolo) == true){
            int x = disponibilita.get(gioco.titolo);
            disponibilita.replace(gioco.titolo, x, x+1);
        }else{
            disponibilita.put(gioco.titolo, 1);
        }
    }

    void Inserimento(Book libro){
        catalogoLibri.put(libro.titolo, libro);
        if(disponibilita.containsKey(libro.titolo) == true){
            int x = disponibilita.get(libro.titolo);
            disponibilita.replace(libro.titolo, x, x+1);
        }else{
            disponibilita.put(libro.titolo, 1);
        }
    }

    void prestito(Cliente user, Game gioco){
        if (catalogoGiochi.containsKey(gioco.titolo) == false){
            System.out.println("il gioco non è presente");
            return;
        }
        else if (disponibilita.get(gioco.titolo) == 0){
            System.out.print("il gioco non è disponibile in questo momento, lo sarà in tempo : ");
            LocalDate serata = LocalDate.now();
            ArrayList<Prestito> prestiti = catalogoPrestiti.get(serata);
            for (int i = 0; i <= prestiti.size(); i++){
                Prestito possibileGioco = prestiti.get(i);
                if (possibileGioco.giocoInPrestito == gioco){
                    System.out.println(possibileGioco.endingTime);
                    return;
                }
            }
        }
        Prestito nuovoPrestito = new Prestito(gioco, user);
        if(catalogoPrestiti.containsKey(LocalDate.now()) == false){
            catalogoPrestiti.put(LocalDate.now(), new ArrayList<Prestito>());
        }
        catalogoPrestiti.get(LocalDate.now()).addLast(nuovoPrestito);
        int x  = disponibilita.get(gioco.titolo) - 1;
        disponibilita.put(gioco.titolo, x);
        System.out.println("il prestito è andato a buon fine");
        return;
    }

    void prestito(Cliente user, Book libro){
        if (catalogoLibri.containsKey(libro.titolo) == false){
            System.out.println("il libro non è presente");
            return;
        }
        else if (disponibilita.get(libro.titolo) == 0){
            System.out.println("il libro non è disponibile in questo momento");
        }
        Prestito nuovoPrestito = new Prestito(libro, user);
        if(catalogoPrestiti.containsKey(LocalDate.now()) == false){
            catalogoPrestiti.put(LocalDate.now(), new ArrayList<Prestito>());
        }
        catalogoPrestiti.get(LocalDate.now()).addLast(nuovoPrestito);
        int x  = disponibilita.get(libro.titolo) - 1;
        disponibilita.put(libro.titolo, x);
        System.out.println("il prestito è andato a buon fine");
        return;
    }

    void consegna(Cliente user, Game gioco){
        ArrayList<Prestito> prestiti = this.catalogoPrestiti.get(LocalDate.now());
        Prestito consegnato;
        for(int i = 0; i <= prestiti.size(); i++) {
            if ((prestiti.get(i).giocoInPrestito == gioco) && (prestiti.get(i).utilizzatore == user)) {
                prestiti.get(i).endingTime = LocalTime.now();
                int x = disponibilita.get(prestiti.get(i).giocoInPrestito.titolo);
                disponibilita.replace(prestiti.get(i).giocoInPrestito.titolo, x + 1);
                break;
            }
        }
    }

    void consegna(Cliente user, Book libro){
        ArrayList<Prestito> prestiti = catalogoPrestiti.get(LocalDate.now());
        Prestito consegnato;
        for(int i = 0; i <= prestiti.size(); i++){
            if ((prestiti.get(i).libroInPrestito == libro) && (prestiti.get(i).utilizzatore == user)){
                prestiti.get(i).endingTime = LocalTime.now();
                int x = disponibilita.get(prestiti.get(i).libroInPrestito.titolo);
                disponibilita.replace(prestiti.get(i).libroInPrestito.titolo, x+1);
                break;
            }
        }
    }

    @Override
    public String toString() {
        return "Ludoteca{" +
                "nome='" + nome + '\'' +
                ", catalogoLibri=" + catalogoLibri + '\n' +
                ", catalogoGiochi=" + catalogoGiochi + '\n' +
                ", disponibilita=" + disponibilita + '\n' +
                ", catalogoPrestiti=" + catalogoPrestiti +
                '}';
    }
}
