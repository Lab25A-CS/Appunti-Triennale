
/*
i modificatori di accesso servono per aggiungere un livello di sicurezza aggiuntivo

            class   package   subclass  world
public      si      si        si        si
protected   si      si        si        no
default     si      si        no        no
private     si      no        no        no

subclass -> classi figlie
world -> al di fuori del pacchetto
*/

package Pacchetto1;
import Pacchetto2.*;

public class Main {
    public static void main(String[] args){
        A prova = new A();
        System.out.println(prova.nome);
    }
}
