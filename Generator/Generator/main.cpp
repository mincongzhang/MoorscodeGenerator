#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <windows.h>

using namespace std;

typedef std::map<std::string,std::string>::value_type morse_value;

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
		cout<<"Unexpected input: ["<<s_word<<"]"<<endl;
		}
	}

	return 	morse_code;
}

void generateBeep(const std::string code){

	unsigned int speed = 1;
	unsigned int beep_duration,sleep_duration;
	beep_duration  = 125/speed;
	sleep_duration = 250/speed;

	for(std::string::size_type i = 0; i < code.size(); ++i) {
		cout<<code[i];

		//Beep(freq,duration)
		if      (code[i]=='.') 	Beep(600,beep_duration);
		else if	(code[i]=='-')	Beep(600,beep_duration*2);
		else if	(code[i]==' ')	Sleep(sleep_duration);
		else if	(code[i]=='|')	Sleep(sleep_duration);
		else                    cout<<"Unexpected code: ["<<code[i]<<"]"<<endl;
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
	//avoid stupid morse_map["A"]=".-";
	//that will search and create an empty element then insert
	morse_map.insert(morse_value("A", ".-"));
	morse_map.insert(morse_value("B","-..."));
	morse_map.insert(morse_value("C","-.-."));
	morse_map.insert(morse_value("D","-.."));
	morse_map.insert(morse_value("E","."));
	morse_map.insert(morse_value("F","..-."));
	morse_map.insert(morse_value("G","--."));
	morse_map.insert(morse_value("H","...."));
	morse_map.insert(morse_value("I",".."));
	morse_map.insert(morse_value("J",".---"));
	morse_map.insert(morse_value("K","-.-"));
	morse_map.insert(morse_value("L",".-.."));
	morse_map.insert(morse_value("M","--"));
	morse_map.insert(morse_value("N","-."));
	morse_map.insert(morse_value("O","---"));
	morse_map.insert(morse_value("P",".--."));
	morse_map.insert(morse_value("Q","--.-"));
	morse_map.insert(morse_value("R",".-."));
	morse_map.insert(morse_value("S","..."));
	morse_map.insert(morse_value("T","-"));
	morse_map.insert(morse_value("U","..-"));
	morse_map.insert(morse_value("V","...-"));
	morse_map.insert(morse_value("W",".--"));
	morse_map.insert(morse_value("X","-..-"));
	morse_map.insert(morse_value("Y","-.--"));
	morse_map.insert(morse_value("Z","--.."));
	morse_map.insert(morse_value("1",".----"));
	morse_map.insert(morse_value("2","..---"));
	morse_map.insert(morse_value("3","...--"));
	morse_map.insert(morse_value("4","....-"));
	morse_map.insert(morse_value("5","....."));
	morse_map.insert(morse_value("6","-...."));
	morse_map.insert(morse_value("7","--..."));
	morse_map.insert(morse_value("8","---.."));
	morse_map.insert(morse_value("9","----."));
	morse_map.insert(morse_value("0","-----"));
	morse_map.insert(morse_value(" ","|"));
}