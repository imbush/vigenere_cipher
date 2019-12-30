#A simple vignere cipher/decipher program
#Coded by Inle Bush

#declares used variables
alphabet = "abcdefghijklmnopqrstuvwxyz"
running = True
returntext = ""

while running:

    #strips and lowercases cipher/decipher choice
    ciph_deciph = input("\nWould you like to cipher or decipher a message? \n(Enter cipher or decipher): ").lower().strip()
    
    #Checks for a valid ciph_deciph 
    if ciph_deciph != "cipher" and ciph_deciph != "decipher":
        print("That was not a valid input. \nTry again.\n")
        continue

    while True:
        key = input("Please enter your key:\n").strip()

        #checks for a valid key
        if not key.isalpha(): #Cross checks characters in alphabet
            print("Please enter a string without numbers or special characters.\n")
            continue
        
        while True:
            message = input("Please enter the message you would like to cipher:\n").strip()
            
            #checks for a valid message
            if not message.isalpha(): #Cross checks characters in alphabet
                print("Please enter a string without numbers or special characters.\n")
                continue
                
            #loops through letters in message
            for message_index in range(len(message)):
                message_letter = message[message_index] #retrieves letter from message 
                mencrypt_index = alphabet.index(message_letter) #gets index from alphabet

                key_letter = key[message_index % (len(key))] #retrieves letter from key
                kencrypt_index = alphabet.index(key_letter) #gets index from alphabet
                
                if ciph_deciph == "cipher":
                    returntext = returntext + alphabet[(kencrypt_index + mencrypt_index) % len(alphabet)] #adds new letter to cipher text
                else:
                    returntext = returntext + alphabet[(mencrypt_index - kencrypt_index) %len(alphabet)] #adds new letter to cipher text
            
            print("The " + ciph_deciph + "ed message is:\n" + returntext)
            break
        break

    #Asks if Program should continue
    if input("\nType exit to end the program. Type anything else to continue:\n").strip().lower() == "exit":
        running = False