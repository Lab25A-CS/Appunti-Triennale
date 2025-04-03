public class Persona {

    //queste sono variabili globali in quanto sono al di fuori di metodi
    String nome;
    String cognome;


    final int prova = 5; //final non permette a quella variabile di essere modificata

    static int numeroPersone; //con static indichiamo una variabile CONDIVISA con tutti gli ogetti instanziati

    Persona(String nome, String cognome){ // costruttore chiamato automaticamente
        this.nome = nome;
        this.cognome = cognome; // il this fa in modo che ogni istanza abbia dei parametri personalizzati
        numeroPersone++;
    }

    void salutaPersona(Persona personaDaSalutare){
        System.out.println("ciao " + personaDaSalutare.nome + " io sono "+ this.nome);
    }

    void saluta(){
        System.out.println("ciao");
    }

    public String toString(){ //stiamo eseguendo l'override del metodo toString in modo che ritorni quello che vogliamo
        String stringa = (this.nome + "\n" + this.cognome);
        return stringa;
    }

    static void mostraNumeroPersone(){ //metodo richiamabile dalla classe senza che debba essere instanziabile
        System.out.println(numeroPersone);
    }

}
