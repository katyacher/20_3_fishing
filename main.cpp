#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::cout << "20.3 Simulation of the game 'Fishing' \n";
    std::string my_fish;
    std::string fish_in_river;

    int fishcounter = 0;
    int pos = 0;

    std::ofstream basket("/home/kate/CLionProjects/20_3_fishing/basket.txt", std::ios::app);
    std::ifstream river("/home/kate/CLionProjects/20_3_fishing/river.txt");


    std::cout << "What kind of fish do you want to catch? : ";
    std::cin >> my_fish;

    if (!river.is_open()){
        std::cout << "Error opening file" << std::endl;
    } else{
        while(!river.eof()){
            river.seekg(pos);
            getline(river, fish_in_river);
            pos = river.tellg();
            if(fish_in_river == my_fish){
                if(!basket.is_open()){
                    std::cout << "Error opening file" << std::endl;
                } else {
                    basket << my_fish << std::endl;
                    fishcounter++;
                }
            }
        }
    }

    river.close();
    basket.close();

    std::cout << "You caught " << fishcounter << " fish.";
}


