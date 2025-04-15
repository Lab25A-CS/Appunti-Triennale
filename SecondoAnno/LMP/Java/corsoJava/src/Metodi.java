public class Metodi {

    public static void main(String[] args){

        faiPasta();
        cucinaPranzo("carne");
        int z = addizione(3, 5);
        System.out.println(z);

    }

    static void faiPasta(){
        System.out.println("cucinando la pasta");
    }

    static void cucinaPranzo(String cibo){
        System.out.println("sto cucinando " + cibo);
    }

    static int addizione(int a, int b){
        int z = a +b;
        return z;
    }


}
