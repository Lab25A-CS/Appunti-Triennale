import java.io.*;

public class FileManager {
    public static void main (String [] args){
        /*
        File file = new File("src/prova.txt");

        if(file.exists()){
            System.out.println("il file esiste");
            System.out.println(file.getPath());
            System.out.println(file.getAbsolutePath());
            System.out.println(file.isFile());
            file.delete();
        }else{
            System.out.println("il file non esiste");
        }
        */

        /*
        try {
            FileWriter writer = new FileWriter("src/prova.txt");
            writer.write("Ciao sono \nCiao");
            writer.append("\nciao c");
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        */

        try {
            FileReader reader = new FileReader("src/prova.txt");
            int data = reader.read();
            while(data != -1){
                System.out.print((char)data);
                data = reader.read();
            }
            System.out.println(data);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
