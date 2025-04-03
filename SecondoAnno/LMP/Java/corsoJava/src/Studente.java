public class Studente extends Persona{

    //ereditando persona studente ha accesso ad ogni cosa che ha persona

    String materiaPreferita = "Storia";

    Studente(String nome, String cognome, String materiaPreferita) {
        super(nome, cognome); //invoca il costruttore della classe estesa
        this.materiaPreferita = materiaPreferita; //aggiungiamo dei parametri
    }
    Studente(String nome, String cognome){
        super(nome, cognome);
    }

    void studia(){
        System.out.println("sto stdiando");
    }

    @Override
    void saluta(){
        System.out.println("buongiorno prof..");
    }
}
