#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "Movie.hpp"
#include "UserRating.hpp"


class MovieDataBase{
private:
    std::unordered_map<std::string,std::vector<int>> ratings;

    double getAverageRating(const Movie& movie) const;
    double calculateDistance(const Movie& m1,const Movie& m2) const;

public:
    void addMovie(const Movie& movie);
    void addRating(const Movie& movie,int r);
    std::vector<int> getRatings(const Movie& movie)const;

    std::vector<Movie> recommendSimilar(const Movie& target,const std::vector<Movie>& allMovies,int k) const;
};