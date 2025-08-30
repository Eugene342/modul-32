#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
int main()
{
	nlohmann::json movie_info =
	{
		{"title", "Inception"},
		{"country", "USA"},
		{"release_date", "2010-07-16"},
		{"studio", "Warner Bros. Pictures"},
		{"screenwriter", "Christopher Nolan"},
		{"director", "Christopher Nolan"},
		{"producers", {"Emma Thomas", "Christopher Nolan"}},
		{"main_characters",{
			{{"character", "Dom Cobb"},{"actor", "Leonardo DiCaprio"}},
			{{"character", "Mal Cobb"},{"actor", "Marion Cotillard"}},
			{{"character", "Arthur"},{"actor", "Joseph Gordon-Levitt"}},
			{{"character", "Ariadne"},{"actor", "Elliot Page"}},
			{{"character", "Eames"},{"actor", "Tom Hardy"}}
	    }}
	};
	std::ofstream file("movie_info.json");
	file << movie_info.dump(4);
	file.close();
	std::cout << "The JSON file was created successfully!" << std::endl;
	return 0;
}
