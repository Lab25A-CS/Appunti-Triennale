import java.util.Arrays;

public class Array {
    public static void main(String[] arg){

        char[] array = new char[3]; //abbiamo creato un array di 0 lungo 3
        array[2] = 2;
        for (char caratteri : array) {
            System.out.println(caratteri);
        }
        int[] numeri = {1,2,3,4,5,6,7,8,9};
        for (int i = 0; i < numeri.length-2; i++){
            System.out.println(numeri[i]);
        }
    }
}
