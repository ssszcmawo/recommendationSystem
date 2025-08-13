#include "Movie.hpp"

Movie::Movie(std::string Title,int pubYear,Genre gen) : title(Title),publicationYear(pubYear),genre(gen){}
void Movie::getInfo(){
        std::cout << "Title: " << title << "\n";
        std::cout << "Publication Year: " << publicationYear << "\n";
        std::cout << "Genre: " << static_cast<int>(genre) << "\n"; 
}
std::string Movie:: getTitle() const {return title;}
Genre Movie:: getGenre() const {return genre;}



