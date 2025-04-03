import java.util.ArrayList;

public class Arraylist {
    public static void main(String[] args){

        ArrayList<String> persone = new ArrayList<String>(); // può prendere solo reference

        persone.add("Luca"); //aggiunge elementi alla ArrayList
        persone.add("Marco");
        persone.add("Mario");

        persone.set(2, "Anna"); //modifica un elemento all'interno dell'ArrayList

        persone.remove(1); //elimina un elemento dell'ArrayList

        persone.clear(); //elimina TUTTI gli elementi dell'ArrayList

        for(int i = 0; i < persone.size(); i++) {
            System.out.println(persone.get(i));
        }

        ArrayList<ArrayList<String>> classi = new ArrayList();

        ArrayList<String> classe1 = new ArrayList<String>();

        classe1.add("Mario");
        classe1.add("Peppe");

        ArrayList<String> classe2 = new ArrayList<String>();

        classe2.add("Maria");
        classe2.add("Anna");

        classi.add(classe1);
        classi.add(classe2);

        for(int k = 0; k < classi.size(); k++){
            System.out.println();
            for(int t = 0; t < classi.get(k).size(); t++){
                System.out.print(classi.get(k).get(t) + " ");
            }
        }
        



    }
}
