#pragma once
#include <string>
#include <iostream>
enum class Genre{
    Horror,
    Drama,
    Romance,
    Thriller,
    Action

};

class Movie{
public:
    Movie(std::string Title,int pubYear,Genre gen);
    void getInfo();
    std::string getTitle() const;
    Genre getGenre() const;

private:
    std::string title;
    int publicationYear;
    Genre genre;

};