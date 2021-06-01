#include "movie.h"
#include <iostream>

//constructor
Movie::Movie(std::string name_val, std::string rating_val, int watched_val):name(name_val), 
rating(rating_val), watched(watched_val) {
    //empty
}
    //getters
    std::string Movie::get_name() {
        return name;
    }
    std::string Movie::get_rating() {
        return rating;
    }
    int Movie::get_watched() {
        return watched;
    }

    void Movie::display_data() {
        std::cout << "Name: " << get_name() << std::endl
        << "Rating: " << get_rating() << std::endl << "Times watched: " << get_watched()  << std::endl
        << "-------------------------------" << std::endl;
    }