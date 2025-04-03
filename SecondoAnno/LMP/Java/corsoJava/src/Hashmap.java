import java.util.HashMap;

public class Hashmap {
    public static void main(String[] args){

        HashMap<String, String> capitali = new HashMap<String, String>();

        capitali.put("Italia", "Roma");
        capitali.put("Inghilterra", "Londra");
        capitali.put("Germania", "Berlino");
        capitali.put("Francia", "Parigi");

        System.out.println(capitali.get("Germania"));
        System.out.println(capitali);

        capitali.remove("Francia");
        System.out.println(capitali);
        capitali.clear();
        System.out.println(capitali);
    }
}
