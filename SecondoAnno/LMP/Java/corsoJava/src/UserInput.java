
import java.util.Scanner;
public class UserInput {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Qual'è il tuo nome?");
        String nome = scanner.nextLine();

        System.out.println("Qual'è il tuo cognome?");
        String cognome = scanner.nextLine();

        System.out.println("Qual'è la tua età?");
        int eta = scanner.nextInt();  //il next int non permette di andare a capo -> bisogna mettere
        scanner.nextLine();           //scanner.nextLine()

        System.out.println("In che città vivi?");
        String citta = scanner.nextLine();

        System.out.println("Ciao " + nome + " " + cognome);
        System.out.println("Hai " + eta + " anni");
        System.out.println("Vivi a " + citta);
    }
}
