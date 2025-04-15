import java.util.Scanner;
import java.util.InputMismatchException;

public class TryCatch {
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        try {
            System.out.println("Inserire un numero");
            int x = scanner.nextInt();

            System.out.println("Inserire un secondo numero");
            int y = scanner.nextInt();

            int result = x / y;
            System.out.println("risultato:  " + result);
        }catch(ArithmeticException e){
            System.out.println("non puoi dividere per 0");
        }catch(InputMismatchException e){
            System.out.println("coglione hai sbagliato input");
        }catch(Exception e){
            System.out.println("c'è stato un problema");
        }finally{
            System.out.println("eseguito comunque");
            scanner.close();
        }
    }
}
