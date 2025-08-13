#include "UserRating.hpp"

UserRating::UserRating(const Movie& m,int r) : movie(m){
    if(r < 1 || r > 5){
        throw std::out_of_range("Rating must be from 1 to 5");
    }
    rating = r;
};

Movie UserRating::getMovie() const {return movie;}
int UserRating::getRating() const {return rating;}