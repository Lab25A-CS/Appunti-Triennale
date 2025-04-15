
public class Main {
    public static void main(String[] args) {
        //Persona persona = new Persona("mario", "rossi", 23, "blu");

        //System.out.println(persona.toString());

        // array di persona

        //Persona[] persone = new Persona[3];

        /*
        Persona persona0 = new Persona("mario", "rossi");
        Persona persona1 = new Persona("anna", "giallo");
        Persona persona2 = new Persona("marta", "blu");
        */

        /*
        persone[0] = persona0;
        persone[1] = persona1;
        persone[2] = persona2;
        */

        //Persona[] persone = {persona0, persona1, persona2};

        //persona0.saluta(persona1);


        //System.out.println(persone[2]);

        //System.out.println(Persona.numeroPersone);

        //Persona.mostraNumeroPersone();

        /*
        Studente studente1 = new Studente("mario", "rossi", "math");
        studente1.studia();
        studente1.saluta();

        Insegnante insegnante1 = new Insegnante("Anna", "Neri", "math");
        insegnante1.Insegnando();
        insegnante1.saluta();
        */

        /*
        Uomo uomo1 = new Uomo("Luca", "Rossi");
        Uomo uomo2 = new Uomo("Mario", "Giallo");

        //uomo2 = uomo1; --->  stessa casella di memoria

        uomo1.copy(uomo2); //--> celle di memoria differenti

        Uomo uomo3 = new Uomo(uomo2);// tramite costruttore

        System.out.println(uomo1);
        System.out.println(uomo2);
        System.out.println();
        System.out.println(uomo1.getNome());
        System.out.println(uomo1.getCognome());
        System.out.println();
        System.out.println(uomo2.getNome());
        System.out.println(uomo2.getCognome());

        */
        /*
        Gazzella gazzella = new Gazzella();
        Leone leone = new Leone();
        Pesce pesce = new Pesce();

        leone.caccia();
        gazzella.scappa();
        pesce.scappa();
        pesce.caccia();
        */

        Studente studente1 = new Studente("mario", "rossi");
        Insegnante insegnante1 = new Insegnante("Anna", "Neri");

        Persona[] classi = {studente1, insegnante1}; // possiamo creare un array con un insegnante e uno studente chiamandolo persona, grazie al fatto che ereditano proprio quella classe

        for(Persona pluto:classi){
            pluto.saluta();
        }

    }
}