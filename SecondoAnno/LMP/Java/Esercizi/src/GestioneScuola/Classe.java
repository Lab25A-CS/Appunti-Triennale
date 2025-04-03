package GestioneScuola;

import java.util.ArrayList;
import java.util.HashMap;

public class Classe {
    final public String nome;
    final private int annataStudenti;
    public int annoCorso;
    public final char sezione;
    private int numeroStudenti;

    private HashMap<String, Ripetente> alunniRipetenti;
    private ArrayList<Studente> registro;

    Classe(char sezione, int annoCorso, int annataStudenti){
        this.sezione = sezione;
        this.annoCorso = annoCorso;
        this.nome = "%s%s".formatted(sezione, annoCorso);
        this.annataStudenti = annataStudenti;

        this.numeroStudenti = 0;

        this.alunniRipetenti = new HashMap<String, Ripetente>();
        this.registro = new ArrayList<Studente>();
    }

    void aggiuntaAlunno(Studente alunno){
        numeroStudenti++;
        registro.add(alunno);
    }

    void aggiuntaRipetente(Studente bocciato){
        Ripetente ripetente = new Ripetente(bocciato.nome, bocciato.cognome, bocciato.annoDiNascita, bocciato.luogoDiNascita,  bocciato.annoDiIscrizione, 1);

        alunniRipetenti.put(bocciato.nome + " " + bocciato.cognome, ripetente);
    }
}


