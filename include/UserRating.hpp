#pragma once
#include <stdexcept>
#include "Movie.hpp"
class UserRating{
public:

    UserRating(const Movie& m,int r);
    int getRating() const;
    Movie getMovie() const;

private:
    Movie movie;
    int rating;
};