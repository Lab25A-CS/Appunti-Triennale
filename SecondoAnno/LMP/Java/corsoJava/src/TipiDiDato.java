import java.io.PrintStream;

import static java.lang.System.out;

/*
* Primitive: dati messi a disposizione da java, iniziano sempre per minuscola, non hanno metodi correlati;
*   boolean -> true, false;
*
*   byte   -> int fra [-128, 127];
*   short  -> int fra [-32768, 32767];
*   int    -> int fra [-2 milioni, 2 milioni];
*   long   -> int mooooolto grande che deve finire per L;
*
*   float  -> float con 6/7 cifre decimali che deve finire per f;
*   double -> float con 15 cifre decimali;
*
*   char   -> singolo carattere fra '';
*
* Reference: dati creati dall'utente, possono avere dei metodi correlati, iniziano SEMPRE per maiuscola;
*   String -> sequenza di caratteri fra "";
* */
public class TipiDiDato {
    public static void main(String[] args) {
        boolean ilBoolean = true;

        byte ilByte = 127;
        short ilShort = -32768;
        int ilInt = 2_000_000_000;
    long ilLong = 89_473_892_479_237L;

        float ilFloat = 7.1234567f;
        double ilDouble = 1.23564789585858;

        char ilChar = 'c';
        String laString = "ciao";

        System.out.printf("%s Francesco", laString);
    }
}
