package GestioneLibri;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Book {

    public static int numbers = 0;

    private final String title;
    private final String author;
    private LocalDate release;
    protected String genre;

    Book(String title, String author, int year, int month, int day, String genre){
        this.title = title;
        this.author = author;
        this.release = LocalDate.of(year, month, day);
        this.genre = genre;

        numbers++;
    }

    public static int getNumbers() {
        return numbers;
    }

    public String getTitle(){
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public LocalDate getRelease(){
        return release;
    }

    public String getGenre(){
        return genre;
    }

    public String toString(){
        DateTimeFormatter formattazione = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        return ("title: " + this.title + "\n" +
                "author: " + this.author + "\n" +
                "release: " + this.release.format(formattazione) + "\n" +
                "genre: " + this.genre);
    }

}