package GestioneLudoteca;

public class Main {
    public static void main(String[] args){
        Game gioco1 = new Game( "dixit", "mario", "giochi.com", 1892, 2, 14 );
        Game gioco2 = new Game("monopoly", "giacomo", "mondadori", 2001, 4,52);
        Book libro1 = new Book("Dune", "Hilbert", "mondadori", 1960, 300);
        Book libro2 = new Book("Eden", "Adam", "mondadori", 1980, 120);

        Cliente cliente1 = new Cliente("francesco", "cosciotti");
        Cliente cliente2 = new Cliente("dorothea", "carafa");

        Ludoteca ludoteca1 = new Ludoteca("giochiamo");
        ludoteca1.Inserimento(gioco1);
        ludoteca1.Inserimento(libro1);
        ludoteca1.Inserimento(gioco2);
        ludoteca1.Inserimento(libro2);

        ludoteca1.prestito(cliente1, gioco1);
        ludoteca1.prestito(cliente2, libro1);

        System.out.println(ludoteca1 + "\n");

        ludoteca1.consegna(cliente1, gioco1);
        ludoteca1.consegna(cliente2, libro1);

        System.out.println(ludoteca1);



    }

}
