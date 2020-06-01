#include <string>

class Movie {
    private:
    std::string name;
    std::string rating;
    int watched;

    public:
    //constructor defenition
    Movie(std::string name_val, std::string rating_val, int watched_val);

    //getters defenition
    std::string get_name();
    std::string get_rating();
    int get_watched();
    void display_data();
};