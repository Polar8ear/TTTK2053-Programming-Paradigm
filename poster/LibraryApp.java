package poster;

import java.util.ArrayList;
import java.util.Date;

public class LibraryApp {
  public static void main(String[] args) {

  }
}

class Library {
  ArrayList<ReadingMaterial> readingMaterials;

  public ArrayList<ReadingMaterial> search(String identifier) {
    ArrayList<ReadingMaterial> result = new ArrayList<>();
    for (ReadingMaterial rm : readingMaterials) {
      if (rm.match(identifier)) {
        result.add(rm);
      }
    }
    return result;
  }
}

interface Searchable {
  boolean match(String s);
}

abstract class ReadingMaterial implements Searchable {
  String content;
  String title;
  String author;
  Date publishedDate;
}

class Book extends ReadingMaterial {
  String isbn;

  @Override
  public boolean match(String identifier) {
    return isbn.equals(identifier);
  }
}

class Magazine extends ReadingMaterial {
  String issn;

  @Override
  public boolean match(String identifier) {
    return issn.equals(identifier);
  }
}