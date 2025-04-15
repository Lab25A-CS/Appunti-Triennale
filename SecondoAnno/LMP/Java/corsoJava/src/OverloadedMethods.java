public class OverloadedMethods { // metodi con lo stesso nome ma con funzioni diverse

    public static void main(String[] args){
        int z = addizione(1,2);
        int t = addizione(1,2,3);
        double d = addizione(4.5, 9.4);
        System.out.println(z +" "+t+" "+d );

    }

    static int addizione(int a, int b){
        int z = a + b;
        return z;
    }
    static int addizione(int a, int b, int c){
        int z = a + b + c;
        return z;
    }
    static double addizione(double a, double b){
        double z = a + b;
        return z;
    }
}
