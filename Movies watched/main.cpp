#include <iostream>
#include <string>
#include <vector>
#include "movie.h"

int main(void) {
    std::vector<Movie> Movies;
    int choice = 0;
    do {
        std::cout << "1. Add a movie" << std::endl << "2.Display movies watched" << std::endl << "0. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name; 
            std::string rating;
            int watched = 0;

            std::cin >> name;
            std::cin >> rating;
            std::cin >> watched;
            
            Movies.push_back(Movie(name, rating, watched));
        }
        else if (choice == 2) {
            for (int i = 0; i < Movies.size(); ++i)
                Movies.at(i).display_data();
        }
        else if(choice == 0) 
            abort();
        else 
            std::cout << "Unknown option..." << std::endl;

    } while(choice != 0);
    return 0;
}