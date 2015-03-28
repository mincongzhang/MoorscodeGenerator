#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <windows.h>

using namespace std;

void initialMorseMapping(std::map<std::string,std::string> & morse_map);
void printMapping(const std::map<std::string,std::string> & morse_map);
void generateBeep(const std::string code);
std::string getMorseCode(const std::map<std::string,std::string> & morse_map,std::string words);

int main(int argc, char* argv []){

	std::map<std::string,std::string> morse_map;
	initialMorseMapping(morse_map);
	//printMapping(morse_map);

	std::string welcome = "Welcome to Morse Code generator!";
	cout<<welcome<<endl;
	std::string welcome_code = getMorseCode(morse_map,"SOS");
	generateBeep(welcome_code);


	while(true){
	std::string input;
	cout <<endl<<"Please enter sth to get its morse code: "<<endl;
	getline(cin,input);

	std::string input_code = getMorseCode(morse_map,input);
	generateBeep(input_code);
	}

	//system("pause");
	//Sleep(1000000);	
	return 0;

}

std::string getMorseCode(const std::map<std::string,std::string> & morse_map,std::string words){
	//get uppercase
	std::transform(words.begin(), words.end(),words.begin(), ::toupper);

	std::string morse_code;

	for(std::string::size_type i = 0; i < words.size(); ++i) {
		char c_word = words[i];
		std::string s_word(1,c_word);

		std::map<std::string,std::string>::const_iterator map_iter = morse_map.find(s_word);
		if( map_iter != morse_map.end()){
			morse_code += map_iter->second;
			morse_code += " ";	 //add space after each letter
		} else {
		cout<<"Unexpected input: ["<<s_word<<"]!"<<endl;
		}
	}

	return 	morse_code;
}

void generateBeep(const std::string code){
	for(std::string::size_type i = 0; i < code.size(); ++i) {
		cout<<code[i];

		//Beep(freq,duration)
		if      (code[i]=='.') 	Beep(600,250);
		else if	(code[i]=='-')	Beep(600,500);
		else if	(code[i]==' ')	Sleep(300);
		else                    cout<<"Unexpected code: ["<<code[i]<<"]!"<<endl;
	}
}

void printMapping(const std::map<std::string,std::string> & morse_map){
	cout<<"Morse code:"<<endl;
	std::map<std::string,std::string>::const_iterator map_iter;
	for(map_iter=morse_map.begin();map_iter!=morse_map.end();++map_iter){
		cout<<map_iter->first<<" | "<<map_iter->second<<endl;
	}
}

void initialMorseMapping(std::map<std::string,std::string> & morse_map){
	morse_map["A"]=".-";
	morse_map["B"]="-...";
	morse_map["C"]="-.-.";
	morse_map["D"]="-..";
	morse_map["E"]=".";
	morse_map["F"]="..-.";
	morse_map["G"]="--.";
	morse_map["H"]="....";
	morse_map["I"]="..";
	morse_map["J"]=".---";
	morse_map["K"]="-.-";
	morse_map["L"]=".-..";
	morse_map["M"]="--";
	morse_map["N"]="-.";
	morse_map["O"]="---";
	morse_map["P"]=".--.";
	morse_map["Q"]="--.-";
	morse_map["R"]=".-.";
	morse_map["S"]="...";
	morse_map["T"]="-";
	morse_map["U"]="..-";
	morse_map["V"]="...-";
	morse_map["W"]=".--";
	morse_map["X"]="-..-";
	morse_map["Y"]="-.--";
	morse_map["Z"]="--..";
	morse_map["1"]=".----";
	morse_map["2"]="..---";
	morse_map["3"]="...--";
	morse_map["4"]="....-";
	morse_map["5"]=".....";
	morse_map["6"]="-....";
	morse_map["7"]="--...";
	morse_map["8"]="---..";
	morse_map["9"]="----.";
	morse_map["0"]="-----";
	morse_map[" "]=" ";
}