package GestioneLibri;

import java.util.ArrayList;
import java.util.HashMap;

public class Library {

    public final String name;
    private int numberOfBooks;
    private HashMap<String, Book> catalogue; //hashmap nome->libro
    private HashMap<String, ArrayList<String>> bookshelf;


    Library(String name){
        this.name = name;
        this.numberOfBooks = 0;
        this.bookshelf = new HashMap<String, ArrayList<String>>();
        this.catalogue = new HashMap<String, Book>();
    }


    void add(Book libro){

        numberOfBooks++;
        catalogue.put(libro.getTitle(), libro);

        if(bookshelf.containsKey(libro.genre)) {
            bookshelf.get(libro.genre).add(libro.getTitle());
        }
        else{
            bookshelf.put(libro.genre, new ArrayList<>());
            bookshelf.get(libro.genre).add(libro.getTitle());
        }
    }

    void remove(Book libro){
        if (catalogue.containsKey(libro.getTitle())){
            numberOfBooks--;
            catalogue.remove(libro.getTitle());
            ArrayList<String> array = bookshelf.get(libro.genre);

            for(int i = 0; i < array.size(); i++){
                if (array.get(i) == libro.getTitle()){
                    array.remove(i);
                }
            }
        }
    }

    Boolean research(String title){
        if(catalogue.containsValue(title)){
            return true;
        }

        return false;
    }

    Book find(String title){
        if(research(title)){
            return catalogue.get(title);
        }
        System.out.println("il libro "+title+ "non è presente all'interno del catalogo della biblioteca "+this.name);
        return null;
    }

    HashMap<String, ArrayList<String>> getBookshelf(){
        return bookshelf;
    }
    HashMap<String, Book> getCatalogue(){
        return catalogue;
    }
    int getNumberOfBooks(){
        return numberOfBooks;
    }

}
