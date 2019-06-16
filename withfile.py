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
    

    #removin all spaces
    copyaslist[:] = (value for value in copyaslist if value != " ")

    # removin all semicolons
    copyaslist[:] = (value for value in copyaslist if value != ";")

    # removin all colons
    copyaslist[:] = (value for value in copyaslist if value != ":")

    # removin all periods
    copyaslist[:] = (value for value in copyaslist if value != ".")

    # removin all commas
    copyaslist[:] = (value for value in copyaslist if value != ",")

    # removin all question marks
    copyaslist[:] = (value for value in copyaslist if value != "?")

    # removin all exclamation mark
    copyaslist[:] = (value for value in copyaslist if value != "!")

    # removin all hyphens
    copyaslist[:] = (value for value in copyaslist if value != "-")

    # removin all parerthases
    copyaslist[:] = (value for value in copyaslist if value != "(")

    copyaslist[:] = (value for value in copyaslist if value != ")")

    copyaslist[:] = (value for value in copyaslist if value != "[")

    copyaslist[:] = (value for value in copyaslist if value != "]")

    copyaslist[:] = (value for value in copyaslist if value != "{")

    copyaslist[:] = (value for value in copyaslist if value != "}")

    # removin all newlines
    copyaslist[:] = (value for value in copyaslist if value != "\n")
    #print("after" , copyaslist)



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

