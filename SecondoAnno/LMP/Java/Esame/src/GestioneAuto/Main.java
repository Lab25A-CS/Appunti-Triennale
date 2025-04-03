package GestioneAuto;

public class Main {
    public static void main(String[] args) {
        Database database = new Database();

        Prodotto prodotto1 = new Prodotto(01,"ruota", 2.5, "Lazio", 1.5);
        Componente componente1 = new Componente(001, 4, 4.5, "Lazio");

        prodotto1.AggiuntaComponente(componente1);

        System.out.println(prodotto1);

        database.AggiuntaProdotto(prodotto1);

        System.out.println(database);




    }
}