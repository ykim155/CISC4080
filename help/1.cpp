#include <iostream>

   using namespace std;

   

   // prototype

   char getDigit(char);

  int main()

  {

          string number;

          int length, i;

          char num, ans;

  

  

          do{

            cout << "Enter a string: ";

            cin >> number;

    

            length = number.length();

    

    

    

            for(i = 0; i < length; i++)

            {

                    num = number.at(i);

                    num = getDigit(num);

    

                    cout << num;

    

            }
            cout << endl;
            cout << "Want to process another phone? y=yes, n=no" << endl;

    

            cin  >> ans;

          }while(ans=='y' || ans=='Y');

          cout << "Have a nice day!" << endl;

          return 0;

  }

  

  // function definition

  

  char getDigit(char num)

  {

          char digit;

  

          switch(num)

          {

            case 'a':

            case 'A':

            case 'b':

            case 'B':

            case 'c':

            case 'C':

  

                  digit = '2';

  

          break;

  

            case 'd':

            case 'D':

            case 'e':

            case 'E':

            case 'f':

            case 'F':

  

                  digit = '3';

  

          break;

            case 'g':

            case 'G':

            case 'h':

            case 'H':

            case 'i':

            case 'I':

  

                  digit = '4';

  

          break;

            case 'j':

            case 'J':

            case 'k':

            case 'K':

            case 'l':

            case 'L':

  

                  digit = '5';

  

          break;

            case 'm':

            case 'M':

            case 'n':

            case 'N':

            case 'o':

            case 'O':

  

                  digit = '6';

 

         break;

           case 'p':

           case 'P':

           case 'q':

           case 'Q':

           case 'r':

           case 'R':

           case 's':

           case 'S':

 

                 digit = '7';

 

         break;

           case 't':

           case 'T':

           case 'u':

           case 'U':

           case 'v':

           case 'V':

 

                 digit = '8';

 

         break;

           case 'w':

           case 'W':

           case 'x':

           case 'X':

           case 'y':

           case 'Y':

           case 'z':

           case 'Z':

 

                 digit = '9';

 

         break;

         default:

                 digit = num;

         break;

         }

 

         return digit;

 

 

 }

