public class Insegnante extends Persona{

    String materia = "Matematica";

    Insegnante(String nome, String cognome, String materia) {
        super(nome, cognome);
        this.materia = materia;
    }
    Insegnante(String nome, String cognome){
        super(nome, cognome);
    }

    void Insegnando(){
        System.out.println("sto insegnando..");
    }

    @Override
    void saluta(){
        System.out.println("buongiorno ragazzi..");
    }
}
