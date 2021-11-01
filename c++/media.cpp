#include <iostream>
#include <string>

using namespace std;

// needs sudo apt-get install flatpak-xdg-utils

int main(){

	string l;

	cout << "YOUTUBE +y\n";
	cout << "INSTAGRAM +i\n";
	cout << "TWITTER +t\n";
	cout << "WHATSAPP +w\n";

	getline(cin,l);

	if (l == "y"){
		system("xdg-open https://youtube.com/");
	} else if (l == "i"){
		system("xdg-open https://instagram.com/");
	} else if (l == "t"){
		system("xdg-open https://twitter.com/");
	} else if (l == "w"){
		system("xdg-open https://web.whatsapp.com/");
	} else {
		cout << "\ninvalid char\n";
	}


	return 0;

}