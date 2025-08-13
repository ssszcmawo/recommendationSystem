#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>
#include "Movie.hpp"
#include "UserRating.hpp"


class MovieDataBase{
private:
    std::unordered_map<std::string,std::vector<int>> ratings;

public:
    void addMovie(const Movie& movie);
    void addRating(const Movie& movie,int r);
    std::vector<int> getRatings(const Movie& movie)const;
};