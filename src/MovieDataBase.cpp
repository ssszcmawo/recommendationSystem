#include "MovieDataBase.hpp"

void MovieDataBase::addMovie(const Movie& movie){
    const std::string& title = movie.getTitle();
    if(ratings.find(title) != ratings.end()){
        std::cout << "Film already in dataBase: " << title << "\n";
        return; 
    }
    ratings[title] = {};
}
void MovieDataBase::addRating(const Movie &movie,int r){
    if(r < 1 || r > 5){
        throw std::out_of_range("Rating must be from 1 to 5");
    }

    const std::string& title = movie.getTitle();
    if(ratings.find(title) == ratings.end()){
        std::cout << "Film is not in dataBase: " << title << "\n";
        return;
    }
    ratings[title].push_back(r);
}

std::vector<int> MovieDataBase::getRatings(const Movie& movie) const {
    const std::string& title = movie.getTitle();
    auto it = ratings.find(title);
    if(it != ratings.end()){
        return it->second;
    }else{
        return {};
    }
}