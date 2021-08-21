# Module 8 - Reponses to questions.

# Summarize the project and what problem it was solving.
The goal of this project was to design a program for Corner Grocer that will list the produce that has that has been purchased and the frequency that it was purchased. The program displays a menu with options where the client is able to choose what to select. The client should be be able to do the following following from the menu: list all the produce from a text file and how many times the same produce shows up, specify a single product and show it's frequency in which it was purchased, show a histogram of all produce in a text file and show their number of times purchased with Asterik. 

# What did you do particularly well?
I was able to combine C++ and Python without much trouble. They were able to talk to each other and also run independantly. 

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I think that I could use more references and pointers. From what I've learned, they could make the software perform faster by reducing the amount of memory required to run the program. I still have a lot to learn in that area. 

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The trickiest part of this project was to create a history with the frequency of the produce being purchased using Asterisks. the goal was to display a certain number of astericks that reflects the number shown in the text file. I saw it as logic based and technique oriented. In order to separate the produce and its frequenye from the same line I used a for loop to iterate through each charater on that line. I then separated the words, space and number using if-else statements. Converting the number to astricks was tricky. Since the number is in 'char' format, it would output something different. I got the idea to take 48 away from a charater from the internet then it would output the number that is shown.

# What skills from this project will be particularly transferable to other projects or course work?
The ability to using multiple languages in one project is valueble. I think it shows deversity and flexibility. Different projects might use different languages. To be able to code in multiple languages and have them talk to each other holds a lot of value, in my opinion. 

# How did you make this program maintainable, readable, and adaptable?
I tried to make my coding as clear and readable as possible to the best of my ability. I used proper indents white spaces, separations and lines. Comments and documentation were added to the coding for both c++ and python ones. I created different classes on separate files so that the coding isn't all on one page, which would be overwhelming for the reader. The purpose of the classes also allows the developer add more things to it easier if neccessary. 