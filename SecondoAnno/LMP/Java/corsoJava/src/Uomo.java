public class Uomo {

    private String nome;  // non possono essere viste o modificate all'esterno della classe
    private String cognome;

    Uomo(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
    }

    Uomo(Uomo copia){//copia tramite costruttore
        this.copy(copia);
    }

    public String getNome(){//permette di vedere gli attributi privati di una classe
        return nome;
    }

    public void setNome(String nome){//permette di settare il valore di un campo privato
        this.nome = nome;
    }


    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    @Override
    public String toString() {
        return "Uomo{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                '}';
    }

    public void copy(Uomo uomo){//può esser fatto tramite costruttore
        this.setNome(uomo.getNome());
        this.setCognome(uomo.getCognome());
    }
}
