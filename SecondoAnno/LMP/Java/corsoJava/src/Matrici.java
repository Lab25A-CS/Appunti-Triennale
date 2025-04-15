public class Matrici {

    public static void main(String[] args){

        /*
        String[][] matrix = new String[3][3];

        matrix[0][0] = "Luca";
        matrix[0][1] = "Anna";
        matrix[0][2] = "Marco";

        matrix[1][0] = "Edoardo";
        matrix[1][1] = "Leonardo";
        matrix[1][2] = "Maria";

        matrix[2][0] = "Arianna";
        matrix[2][1] = "Paolo";
        matrix[2][2] = "Teseo";
        */

        String[][] matrix = {
                {"Luca", "Anna", "Marco"},
                {"Edoardo", "Leonardo", "Maria"},
                {"Arianna", "Paolo", "Teseo"}
        };

        /*
        for(int riga = 0; riga < matrix.length; riga++){
            System.out.println();
            for(int colonna = 0; colonna < matrix[riga].length; colonna++){
                System.out.print(matrix[riga][colonna] + " ");
            }
        }
        */

        for (String[] classe: matrix){
            System.out.println();
            for (String studente : classe){
                System.out.print(studente + " ");
            }
        }

    }
}
