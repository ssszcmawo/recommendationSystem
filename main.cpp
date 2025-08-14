#include <iostream>
#include "MovieDataBase.hpp"


int main(){
    MovieDataBase database;

    Movie m1("Inception",2010,Genre::Thriller);
    Movie m2("Titanic",1997,Genre::Romance);
    Movie m3("The Shining", 1980, Genre::Horror);
    Movie m4("Die Hard", 1988, Genre::Action);
    Movie m5("The Godfather", 1972, Genre::Drama);
    Movie m6("Se7en", 1995, Genre::Thriller);

    std::vector<Movie> allMovies = {m1,m2,m3,m4,m5};

    for(const auto& movie: allMovies){
        database.addMovie(movie);
    }

    database.addRating(m1, 5);
    database.addRating(m1, 4);

    database.addRating(m2, 5);
    database.addRating(m2, 5);

    database.addRating(m3, 4);
    database.addRating(m3, 4);

    database.addRating(m4, 5);
    database.addRating(m4, 4);

    database.addRating(m5, 5);
    database.addRating(m5, 3);

    Movie target = m1;

    std::vector<Movie> recs = database.recommendSimilar(target,allMovies,3);

    std::cout << "recommendations for: " << target.getTitle() << "\n";

    for(auto& rec : recs){
        std::cout << "- " << rec.getTitle() << "\n";
    }

    return 0;
}