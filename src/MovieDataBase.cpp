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


double MovieDataBase::getAverageRating(const Movie& movie) const{
    auto rates = getRatings(movie);
    if(rates.empty()) return 0.0;
    double sum = 0;
    for(int r : rates) sum += r;
    return sum / rates.size();
}


double MovieDataBase::calculateDistance(const Movie& m1,const Movie& m2) const{
    double avg1 = getAverageRating(m1);
    double avg2 = getAverageRating(m2);
    
    double genre1 = static_cast<int>(m1.getGenre());
    double genre2=  static_cast<int>(m2.getGenre());

    double dRating = avg1 - avg2;
    double dGenre = genre1 - genre2;

    return std::sqrt(dRating * dRating + dGenre * dGenre);
}

std::vector<Movie> MovieDataBase::recommendSimilar(const Movie& target,const std::vector<Movie>& allMovies,int k) const{
    std::vector<std::pair<double,Movie>> distances;

    for(const auto& movie : allMovies){
        if(movie.getTitle() != target.getTitle()){
            double dist = calculateDistance(target,movie);
            distances.push_back({dist,movie});
        }
    }

    std::sort(distances.begin(), distances.end(),[](const auto& a, const auto& b) {return a.first < b.first;});

    std::vector<Movie> recommendations;
    for(int i = 0; i < std::min(k,(int)distances.size()); i++){
        recommendations.push_back(distances[i].second);
    }

    return recommendations;
}