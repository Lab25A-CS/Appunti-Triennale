import java.util.ArrayList;
import java.util.Iterator;

public class Iteratori {
    public static void main(String[] args){
        ArrayList<String> persone = new ArrayList<String>();
        persone.add("Luca");
        persone.add("Marco");
        persone.add("Anna");
        persone.add("Paolo");

        Iterator<String> it = persone.iterator();

        /*
        System.out.println(it.next());
        System.out.println(it.next());
        System.out.println(it.next());
        System.out.println(it.next());
        */

        while(it.hasNext()){
            String persona = it.next();
            if(persona == "Anna"){
                it.remove();
            }
        }
        System.out.println(persone);
    }
}
