#include <iostream>
#include "MovieDataBase.hpp"


int main(){
    MovieDataBase database;

    Movie m1("Inception",2010,Genre::Thriller);
    Movie m2("Titanic",1997,Genre::Romance);

    database.addMovie(m1);
    database.addMovie(m2);

    database.addRating(m1,5);
    database.addRating(m2,4);
    database.addRating(m1,3);

    auto ratingsInception = database.getRatings(m1);
    std::cout << "Film ratings " << m1.getTitle() << ": ";
    for(int r: ratingsInception) std::cout << r << " ";
    std::cout << "\n";

    auto ratingsTitanic = database.getRatings(m2);
    std::cout << "Film ratings " << m2.getTitle() << ": ";
    for(int r: ratingsTitanic) std::cout << r << " ";
    std::cout << "\n";

    return 0;
}