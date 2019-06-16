letters = {}

def start():
    #ask user for text
    text = ask()

    count(text)
    display()

def ask():
    userinput = ""
    #reax file for text
    filename = input("File name: (txt file) ")
    try:
        with open(filename,"r") as file:
            for i in  file:
                userinput += i
    except:
        print("File does n ot exist or cannot be opened")


    aslist = list(userinput)
    #cycle each letter and remove anything bad
    copyaslist = aslist
    


    bannedletters = [' ',';' ,':' ,'.' ,',' ,'('  ,')'  ,'[',']' ,'{' ,'}','\n' ,'\t']
    #looping with a for loop
    for bannedletter in bannedletters:
        # removin bannedletter
        copyaslist[:] = (value for value in copyaslist if value != bannedletter)





    #makin list a string again
    userinput = "".join(copyaslist)

    return userinput
    #check

def count(text):
    for i in  text:
        if i in letters:
            letters[i] += 1
        else:
            letters[i] = 1




def display():
    #prints in order by frequency
    for w in sorted(letters, key=letters.get, reverse=True):
        print(w, letters[w])

if __name__ == '__main__':
    start()

