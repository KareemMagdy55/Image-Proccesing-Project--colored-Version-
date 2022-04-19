#include <iostream>
#include <cstring>
#include "bmplib.cpp"
#include "bmplib.h"
using namespace std;


unsigned char image[SIZE][SIZE][RGB];

void loadImage ();
void filterChoice();
void saveImage ();

int main() {
    loadImage();
    while (1) {
        filterChoice();
    }
}


void loadImage () {
    char imageFileName[100];

    // Get Colored image file name
    cout << "Enter the source image file name:";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}


// Add Your filters here, then unComment your filter function in filter choice function or Add it .






void saveImage () {
    char imageFileName[100];

    // Get Colored image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
void filterChoice(){
    bool validInput = false ;

    do {
        int filterChoice = 0;
        cout << "\n-----------------------------------\n"
                "Please Choose a filter to apply it to your image\n"
                "\nPress 1 for Black & White filter "
                "\nPress 2 for Invert image filter"
                "\nPress 3 to rotate image filter"
                "\nPress 4 to flip image filter"
                "\nPress 5 to darken or lighten filter"
                "\nPress 6 to merge filter"
                "\nPress 7 to enlarge the image"
                "\nPress 8 to shuffle the image"
                "\nPress 9 to save the image"
                "\nPress 0 to Exit"
                "\n-----------------------------------\n";


        cin >> filterChoice;

        if (filterChoice >= 0 && filterChoice <= 9 ) {

            switch (filterChoice) {
                case 0 :
                    exit(0);
                case 1:
                    //BW_filter();
                    validInput = true;
                    break;
                case 2 :
                    //invertFilter();
                    validInput = true;
                    break;
                case 3 :
                   // rotateImage();
                    validInput = true;
                    break;
                case 4 :
                    //flipImage();
                    validInput = true;
                    break;
                case 5 :
                    //darken_or_lighten() ;
                    validInput = true;
                    break;
                case 6 :
                    //merge();
                    validInput = true;
                    break;
                case 7 :
                    //enlargeImage();
                    validInput = true;
                    break;
                case 8 :
                    //shuffleImage();
                    validInput = true;
                    break;
                case 9 :
                    saveImage();
                    validInput = true;
                    break;
                default:
                    cout << "\nInvalid input, Please try again...\n";
                    break;
            }
        }
    }while (! validInput);


}

