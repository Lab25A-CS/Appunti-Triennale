public class Cicli {
    public static void main(String[] args){

        int i = 0;

        while (i < 10){
            System.out.println(i);
            i++;
        }

        int j = 0;
        do {
            System.out.println(j);
            j++;
        }while(j < 0); // viene eseguito almeno una volta anche se è sempre false

        for(int t = 0; t < 5; t++){
            System.out.println("sei popo un coglione");
        }

        int[] numeri = {10,20,30,40,50};
        for(int pippo: numeri){//for each
            System.out.println(pippo);
        }
    }
}
