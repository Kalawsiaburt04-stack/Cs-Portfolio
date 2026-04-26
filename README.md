# Cs-Portfolio
Project Reflection – Chada Tech Clocks
Summary of the Project

For this project, I developed a C++ application that displays both a 12-hour and a 24-hour clock at the same time. The user enters an initial time, and then the program allows them to update the time by adding hours, minutes, or seconds using a menu. The goal was to meet the requirements from Chada Tech and follow international standards by displaying both time formats clearly and correctly.

What I Did Well

I think I did well organizing my code into separate functions like twoDigitString, nCharString, formatTime12, formatTime24, printMenu, and getMenuChoice. This kept my main() function simple and made the program easier to follow. I also made sure both clocks stayed synchronized when the user added time, and I paid attention to formatting so the clocks displayed side by side correctly.

Where I Could Improve

One area I could improve is input validation in the getMenuChoice function to better handle invalid user input. I could also improve the design by using classes instead of only functions to make the program more object-oriented. This would make the code more reusable and scalable. Additionally, I could reduce repetition in some parts of the code to make it more efficient.

Challenges and How I Overcame Them

One of the biggest challenges was getting the time formatting correct, especially in the formatTime12 function where I had to handle AM/PM and convert from 24-hour time. I also found it challenging to make sure the menu system worked correctly and called the right functions like addOneHour, addOneMinute, and addOneSecond. I overcame this by testing each function individually and checking my output step by step until everything worked as expected.

Transferable Skills

This project helped me improve my ability to break a problem into smaller pieces and solve it using functions. I also gained experience with formatting output, handling user input, and debugging. These are all skills I can apply to future programming projects and coursework.

Maintainability, Readability, and Adaptability

I made the program maintainable and readable by using clear function names, consistent formatting, and comments to explain what each part of the code does. Functions like twoDigitString and nCharString helped keep the code clean and reusable. Because the program is modular, it would be easy to add new features or make changes without rewriting the entire program.
