package GestioneScuola;

public class Studente {

    final String nome;
    final String cognome;
    final int annoDiNascita;
    final String luogoDiNascita;
    final int annoDiIscrizione;

    Studente(String nome, String cognome, int annoDiNascita, String luogoDiNascita, int annoDiIscrizione){
        this.nome = nome;
        this.cognome = cognome;
        this.annoDiNascita = annoDiNascita;
        this.luogoDiNascita = luogoDiNascita;
        this.annoDiIscrizione = annoDiIscrizione;
    }

}
