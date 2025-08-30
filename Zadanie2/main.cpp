#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
void searchActor(const nlohmann::json& movies, const std::string& actorName)
{
	bool found = false;
	for (const auto& movie : movies.items()) 
	{
		const auto& movieName = movie.key();
		const auto& cast = movie.value()["cast"];
		for (const auto& member : cast) 
		{
			if (member["actor"].get<std::string>().find(actorName) != std::string::npos) 
			{
				std::cout << "Actor: " << member["actor"] << " in movie: " << movieName << " as role: " << member["role"] << std::endl;
				found = true;
			}
		}
	}
	if (!found) 
	{
		std::cout << "Actor not found." << std::endl;
	}
}
int main()
{
	std::ifstream file("movies.json");
	if (!file.is_open()) 
	{
		std::cerr << "Could not open the file!" << std::endl;
		return 1;
	}
	nlohmann::json movies;
	file >> movies;
	std::string actorName;
	std::cout << "Enter actor's name or surname to search: ";
	std::getline(std::cin, actorName);
	searchActor(movies, actorName);
	return 0;
}
