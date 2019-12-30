//A simple vignere cipher/decipher program
//Coded by Inle Bush

#include <iostream>     //std::cout, std::cin
#include <string>       //std::string

bool check_not_in_alphabet(std::string check_string){
    for(int i = 0; i < check_string.length(); i++){
        if (isalpha(check_string[i]) == false){
            return true; //returns true if any letters in string are not letters
        }
    }
    return false; //Returns false if all letters in string are letters
}

int main(){

    //Declares used variables
    bool gamerunning = true;
    std::string ciph_deciph;
    std::string key;
    std::string message;
    std::string return_text = "";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string exit_value;

    while(true){

        // Receives cipher choice
        std::cout << "\nWould you like to cipher or decipher a message? \n(Enter cipher or decipher): ";
        std::cin >> ciph_deciph;

        if(ciph_deciph != "cipher" && ciph_deciph != "decipher"){ //Checks for valid cipher
            std::cout << "That was not a valid input. \nTry again.\n";
            continue;
        }

        while(true){
            std::cout << "\nPlease enter your key: ";
            std::cin >> key; //Receives key choice

            if (check_not_in_alphabet(key)){ //Checks if key letters are in alphabet
                std::cout << "\nPlease enter a string without numbers or special characters.";
                continue;
            }

            while(true){
                std::cout << "\nPlease enter your message: ";
                std::cin >> message; //Receives message choice
                
                if (check_not_in_alphabet(message)){ //checks if message letters are in alphabet
                    std::cout << "\nPlease enter a string without numbers or special characters.";
                    continue;
                }
                
                for(int message_index = 0; message_index < message.length(); message_index ++){
                    char message_letter = message[message_index];
                    int mencrypt_index = alphabet.find(message_letter);

                    char key_letter = key[message_index % key.length()];
                    int kencrypt_index = alphabet.find(key_letter);

                    if(ciph_deciph == "cipher"){
                        //Adds corresponding letter to return text, adds message index and key index
                        return_text.append(1, alphabet[(mencrypt_index + kencrypt_index) % 26]); 
                    } else{
                        //Adds corresponding letter to return text, subtracts key index from message index
                        return_text.append(1, alphabet[(mencrypt_index - kencrypt_index) % 26]);
                    }
                }
                std::cout << "The " << ciph_deciph << "ed message is " << return_text; //Returns message
                break;
            }
            break;
        }
        std::cout << "\n\nType exit to end the program. Type anything else to continue: ";
        std::cin >> exit_value; //Offers program exit 

        if (exit_value == "exit"){
            break;
        }
    }
}