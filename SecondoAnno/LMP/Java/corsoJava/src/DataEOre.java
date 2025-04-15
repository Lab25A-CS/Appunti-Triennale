import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class DataEOre {
    public static void main (String[] args){
        LocalDate x = "2 maggio 2929";
        DateTimeFormatter t = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        DateTimeFormatter u = DateTimeFormatter.ofPattern("EEEE, dd/MMMM/yyyy");
        LocalTime y = LocalTime.now();
        System.out.println(x.format(u));
    }
}
